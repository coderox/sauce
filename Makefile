GMOCK = vendor/gmock-1.5.0
GTEST = vendor/gmock-1.5.0/gtest

CPPFLAGS = -Iinclude -Werror

HEADER_TEMPLATES = $(shell find include -type f -name "*.h.pump")
GENERATED_HEADERS = $(patsubst %.h.pump,%.h,$(HEADER_TEMPLATES))
HANDMADE_HEADERS = $(shell find include -type f -name "*.h" | \
	grep -v -E "`echo $(GENERATED_HEADERS) | tr ' ' '|'`")
HEADERS = \
	$(HANDMADE_HEADERS) \
	$(GENERATED_HEADERS)

# Do not delete generated headers, even though they are make intermediates
.SECONDARY: $(GENERATED_HEADERS)

UNCRUSTIFY_INPUT = \
	$(HANDMADE_HEADERS) \
	$(TEST_SOURCES)
UNCRUSTIFY_OUTPUT = $(patsubst %,build/uncrustify/%,$(UNCRUSTIFY_INPUT))

TEST_SOURCES = $(shell find test -type f -name "*.cc")
TEST_OBJECTS = \
	$(patsubst test/%.cc,build/%.o,$(TEST_SOURCES)) \
	$(GMOCK)/src/gmock-all.o                        \
	$(GMOCK)/src/gmock_main.o                       \
	$(GTEST)/src/gtest-all.o

all: precommit

precommit: test-style run-cppcheck test

$(GMOCK)/src/gmock-all.o $(GMOCK)/src/gmock_main.o $(GTEST)/src/gtest-all.o:
	cd $(GMOCK) && ./configure && make

run-uncrustify:
	mkdir -p build/uncrustify
	uncrustify -c uncrustify.cfg --prefix build/uncrustify --suffix '' -l CPP \
		$(UNCRUSTIFY_INPUT)
	echo $(UNCRUSTIFY_INPUT) | tr ' ' '\n' > build/uncrustify-in
	echo $(UNCRUSTIFY_OUTPUT) | tr ' ' '\n' > build/uncrustify-out
	paste build/uncrustify-in build/uncrustify-out > build/uncrustify-in-out

test-style: run-uncrustify
	cat build/uncrustify-in-out |                               \
	xargs -n 2 git diff --exit-code --no-index >/dev/null || (  \
	echo "\nYou have style violations, please run one of:";     \
	echo "  make diff-style\n  make accept-style\n";            \
	false                                                       \
	)

diff-style: run-uncrustify
	cat build/uncrustify-in-out | \
	xargs -n 2 git --no-pager diff --color --no-index | less -FRSX

accept-style: run-uncrustify
	cp -r build/uncrustify .

run-cppcheck:
	cppcheck -q --enable=all --error-exitcode=1 include test

include/%.h: include/%.h.pump
	vendor/pump.py $+

build/%.o: test/%.cc $(HEADERS)
	mkdir -p build/sauce
	$(CXX) $(CPPFLAGS) -I$(GMOCK)/include -I$(GTEST)/include $< -c -o $@

build/tests: $(TEST_OBJECTS)
	mkdir -p build/sauce && $(CXX) $(CPPFLAGS) $+ -o $@

clean:
	rm -rf build/*

distclean: clean
	cd $(GMOCK) && make distclean

test: build/tests
	cd build && ./tests
