#include <gtest/gtest.h>

#include <sauce/sauce.h>

using ::sauce::Binder;

namespace sauce {
namespace test {

struct C {};
struct D {};

struct Singleton {
  bool operator==(Singleton const & other) {
    return this == &other;
  }
};

struct Session {
  bool operator==(Session const & other) {
    return this == &other;
  }
};

struct Request {
  bool operator==(Request const & other) {
    return this == &other;
  }
};

struct MyScope {};

void ScopedModule(Binder & binder) {
  binder.bind<Singleton>().in<SingletonScope>().to<Singleton()>();
  binder.bind<Session>().in<SessionScope>().to<Session()>();
  binder.bind<Request>().in<RequestScope>().to<Request()>();
  binder.bind<C>().in<MyScope>().to<C()>();
  binder.bind<D>().to<D()>();
}

struct ScopeTest:
  public ::testing::Test {

  Modules modules;

  ScopeTest():
    modules() {}

  virtual void SetUp() {
    modules.add(&ScopedModule);
  }
};

TEST_F(ScopeTest, shouldScopeSingletonDependenciesByDefault) {
  SAUCE_SHARED_PTR<Singleton> aSingleton;
  SAUCE_SHARED_PTR<Singleton> theSameSingleton;
  SAUCE_SHARED_PTR<Singleton> aNewSingleton;

  {
    SAUCE_SHARED_PTR<Injector> injector(modules.createInjector());
    aSingleton = injector->get<Singleton>();
    theSameSingleton = injector->get<Singleton>();
  }
  EXPECT_EQ(aSingleton, theSameSingleton);

  {
    SAUCE_SHARED_PTR<Injector> injector(modules.createInjector());
    aNewSingleton = injector->get<Singleton>();
  }
  EXPECT_NE(aSingleton, aNewSingleton);
}

TEST_F(ScopeTest, shouldScopeSessionDependenciesIfAsked) {
  SAUCE_SHARED_PTR<Injector> injector(modules.createInjector());

  SAUCE_SHARED_PTR<Session> aSession;
  SAUCE_SHARED_PTR<Session> theSameSession;
  SAUCE_SHARED_PTR<Session> aNewSession;

  {
    SAUCE_SHARED_PTR<Injector> sessionScoped = injector->enter<SessionScope>();
    aSession = sessionScoped->get<Session>();
    theSameSession = sessionScoped->get<Session>();
  }
  EXPECT_EQ(aSession, theSameSession);

  {
    SAUCE_SHARED_PTR<Injector> sessionScoped = injector->enter<SessionScope>();
    aNewSession = sessionScoped->get<Session>();
  }
  EXPECT_NE(aSession, aNewSession);
}

TEST_F(ScopeTest, shouldScopeRequestDependenciesIfAsked) {
  SAUCE_SHARED_PTR<Injector> injector(modules.createInjector());

  SAUCE_SHARED_PTR<Request> aRequest;
  SAUCE_SHARED_PTR<Request> theSameRequest;
  SAUCE_SHARED_PTR<Request> aNewRequest;

  {
    SAUCE_SHARED_PTR<Injector> requestScoped = injector->enter<RequestScope>();
    aRequest = requestScoped->get<Request>();
    theSameRequest = requestScoped->get<Request>();
  }
  EXPECT_EQ(aRequest, theSameRequest);

  {
    SAUCE_SHARED_PTR<Injector> requestScoped = injector->enter<RequestScope>();
    aNewRequest = requestScoped->get<Request>();
  }
  EXPECT_NE(aRequest, aNewRequest);
}

TEST_F(ScopeTest, shouldScopeCustomScopedDependenciesIfAsked) {
  SAUCE_SHARED_PTR<Injector> injector(modules.createInjector());

  SAUCE_SHARED_PTR<C> aC;
  SAUCE_SHARED_PTR<C> theSameC;
  SAUCE_SHARED_PTR<C> aNewC;

  {
    SAUCE_SHARED_PTR<Injector> scoped = injector->enter<RequestScope>();
    aC = scoped->get<C>();
    theSameC = scoped->get<C>();
  }
  EXPECT_EQ(aC, theSameC);

  {
    SAUCE_SHARED_PTR<Injector> scoped = injector->enter<RequestScope>();
    aNewC = scoped->get<C>();
  }
  EXPECT_NE(aC, aNewC);
}

TEST_F(ScopeTest, shouldNotScopeUnscopedDependencies) {
  SAUCE_SHARED_PTR<Injector> injector(modules.createInjector());
  SAUCE_SHARED_PTR<D> aD = injector->get<D>();
  SAUCE_SHARED_PTR<D> aNewD = injector->get<D>();
  EXPECT_NE(aD, aNewD);
}

struct CrankyConstructorException: public std::runtime_error {
  CrankyConstructorException():
    std::runtime_error("Can't connect to something-er-other!") {}
};

struct CrankyConstructor {
  CrankyConstructor() {
    throw CrankyConstructorException();
  }
};

void EagerlyScopedModule(Binder & binder) {
  binder.bind<CrankyConstructor>().in<SingletonScope>().to<CrankyConstructor()>();
}

TEST_F(ScopeTest, shouldProvidedScopedDependenciesEagerlyIfAsked) {
  SAUCE_SHARED_PTR<Injector> injector =
    Modules().add(&EagerlyScopedModule).createInjector();
  ASSERT_THROW(injector->eagerlyProvide<SingletonScope>(), CrankyConstructorException);
}

}
}