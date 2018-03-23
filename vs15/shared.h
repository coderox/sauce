#include "sauce/sauce.h"

using ::sauce::Binder;

class C {};
class D {};

class Singleton {
public:
	bool operator==(Singleton const & other) {
		return this == &other;
	}
};

class Session {
public:
	bool operator==(Session const & other) {
		return this == &other;
	}
};

class Request {
public:
	bool operator==(Request const & other) {
		return this == &other;
	}
};

class MyScope {};

class FrameworkModule : public sauce::AbstractModule {
	void configure() const {
		bind<Singleton>().in<sauce::SingletonScope>().to<Singleton()>();
		//bind<Session>().in<sauce::SessionScope>().to<Session()>();
		//bind<Request>().in<sauce::RequestScope>().to<Request()>();
		//bind<C>().in<MyScope>().to<C()>();
		//bind<D>().to<D()>();
	}
};