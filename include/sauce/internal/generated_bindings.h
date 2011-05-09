// This file was GENERATED by command:
//     pump.py generated_bindings.h.pump
// DO NOT EDIT BY HAND!!!

#ifndef SAUCE_SAUCE_INTERNAL_GENERATED_BINDINGS_H_
#define SAUCE_SAUCE_INTERNAL_GENERATED_BINDINGS_H_

namespace sauce { namespace internal { namespace bindings {

  template<typename Injector>
  class Binding;

  template<typename Injector, class Iface, typename Constructor>
  class New;

  template<typename Injector, class Iface, class Impl>
  class New<Injector, Iface, Impl()>: public Binding<Injector> {
  public:
    static Impl * provide(Injector & injector) {
      return new_delete(injector).template _new<Impl>();
    };

    static void dispose(Injector & injector, Iface * iface) {
      new_delete(injector).template _delete<Iface>(iface);
    };
  };

  template<typename Injector, class Iface, class Impl, typename A1>
  class New<Injector, Iface, Impl(A1)>: public Binding<Injector> {
  public:
    static Impl * provide(Injector & injector) {
      return new_delete(injector).template _new<Impl,
          A1>(injector.template provide<A1>());
    };

    static void dispose(Injector & injector, Iface * iface) {
      new_delete(injector).template _delete<Iface>(iface);
    };
  };

  template<typename Injector, class Iface, class Impl, typename A1, typename A2>
  class New<Injector, Iface, Impl(A1, A2)>: public Binding<Injector> {
  public:
    static Impl * provide(Injector & injector) {
      return new_delete(injector).template _new<Impl, A1,
          A2>(injector.template provide<A1>(),
          injector.template provide<A2>());
    };

    static void dispose(Injector & injector, Iface * iface) {
      new_delete(injector).template _delete<Iface>(iface);
    };
  };

  template<typename Injector, class Iface, class Impl, typename A1,
      typename A2, typename A3>
  class New<Injector, Iface, Impl(A1, A2, A3)>: public Binding<Injector> {
  public:
    static Impl * provide(Injector & injector) {
      return new_delete(injector).template _new<Impl, A1, A2,
          A3>(injector.template provide<A1>(), injector.template provide<A2>(),
          injector.template provide<A3>());
    };

    static void dispose(Injector & injector, Iface * iface) {
      new_delete(injector).template _delete<Iface>(iface);
    };
  };

  template<typename Injector, class Iface, class Impl, typename A1,
      typename A2, typename A3, typename A4>
  class New<Injector, Iface, Impl(A1, A2, A3, A4)>: public Binding<Injector> {
  public:
    static Impl * provide(Injector & injector) {
      return new_delete(injector).template _new<Impl, A1, A2, A3,
          A4>(injector.template provide<A1>(), injector.template provide<A2>(),
          injector.template provide<A3>(), injector.template provide<A4>());
    };

    static void dispose(Injector & injector, Iface * iface) {
      new_delete(injector).template _delete<Iface>(iface);
    };
  };

  template<typename Injector, class Iface, class Impl, typename A1,
      typename A2, typename A3, typename A4, typename A5>
  class New<Injector, Iface, Impl(A1, A2, A3, A4,
      A5)>: public Binding<Injector> {
  public:
    static Impl * provide(Injector & injector) {
      return new_delete(injector).template _new<Impl, A1, A2, A3, A4,
          A5>(injector.template provide<A1>(), injector.template provide<A2>(),
          injector.template provide<A3>(), injector.template provide<A4>(),
          injector.template provide<A5>());
    };

    static void dispose(Injector & injector, Iface * iface) {
      new_delete(injector).template _delete<Iface>(iface);
    };
  };

  template<typename Injector, class Iface, class Impl, typename A1,
      typename A2, typename A3, typename A4, typename A5, typename A6>
  class New<Injector, Iface, Impl(A1, A2, A3, A4, A5,
      A6)>: public Binding<Injector> {
  public:
    static Impl * provide(Injector & injector) {
      return new_delete(injector).template _new<Impl, A1, A2, A3, A4, A5,
          A6>(injector.template provide<A1>(), injector.template provide<A2>(),
          injector.template provide<A3>(), injector.template provide<A4>(),
          injector.template provide<A5>(), injector.template provide<A6>());
    };

    static void dispose(Injector & injector, Iface * iface) {
      new_delete(injector).template _delete<Iface>(iface);
    };
  };

  template<typename Injector, class Iface, class Impl, typename A1,
      typename A2, typename A3, typename A4, typename A5, typename A6,
      typename A7>
  class New<Injector, Iface, Impl(A1, A2, A3, A4, A5, A6,
      A7)>: public Binding<Injector> {
  public:
    static Impl * provide(Injector & injector) {
      return new_delete(injector).template _new<Impl, A1, A2, A3, A4, A5, A6,
          A7>(injector.template provide<A1>(), injector.template provide<A2>(),
          injector.template provide<A3>(), injector.template provide<A4>(),
          injector.template provide<A5>(), injector.template provide<A6>(),
          injector.template provide<A7>());
    };

    static void dispose(Injector & injector, Iface * iface) {
      new_delete(injector).template _delete<Iface>(iface);
    };
  };

  template<typename Injector, class Iface, class Impl, typename A1,
      typename A2, typename A3, typename A4, typename A5, typename A6,
      typename A7, typename A8>
  class New<Injector, Iface, Impl(A1, A2, A3, A4, A5, A6, A7,
      A8)>: public Binding<Injector> {
  public:
    static Impl * provide(Injector & injector) {
      return new_delete(injector).template _new<Impl, A1, A2, A3, A4, A5, A6,
          A7, A8>(injector.template provide<A1>(),
          injector.template provide<A2>(), injector.template provide<A3>(),
          injector.template provide<A4>(), injector.template provide<A5>(),
          injector.template provide<A6>(), injector.template provide<A7>(),
          injector.template provide<A8>());
    };

    static void dispose(Injector & injector, Iface * iface) {
      new_delete(injector).template _delete<Iface>(iface);
    };
  };

  template<typename Injector, class Iface, class Impl, typename A1,
      typename A2, typename A3, typename A4, typename A5, typename A6,
      typename A7, typename A8, typename A9>
  class New<Injector, Iface, Impl(A1, A2, A3, A4, A5, A6, A7, A8,
      A9)>: public Binding<Injector> {
  public:
    static Impl * provide(Injector & injector) {
      return new_delete(injector).template _new<Impl, A1, A2, A3, A4, A5, A6,
          A7, A8, A9>(injector.template provide<A1>(),
          injector.template provide<A2>(), injector.template provide<A3>(),
          injector.template provide<A4>(), injector.template provide<A5>(),
          injector.template provide<A6>(), injector.template provide<A7>(),
          injector.template provide<A8>(), injector.template provide<A9>());
    };

    static void dispose(Injector & injector, Iface * iface) {
      new_delete(injector).template _delete<Iface>(iface);
    };
  };

  template<typename Injector, class Iface, class Impl, typename A1,
      typename A2, typename A3, typename A4, typename A5, typename A6,
      typename A7, typename A8, typename A9, typename A10>
  class New<Injector, Iface, Impl(A1, A2, A3, A4, A5, A6, A7, A8, A9,
      A10)>: public Binding<Injector> {
  public:
    static Impl * provide(Injector & injector) {
      return new_delete(injector).template _new<Impl, A1, A2, A3, A4, A5, A6,
          A7, A8, A9, A10>(injector.template provide<A1>(),
          injector.template provide<A2>(), injector.template provide<A3>(),
          injector.template provide<A4>(), injector.template provide<A5>(),
          injector.template provide<A6>(), injector.template provide<A7>(),
          injector.template provide<A8>(), injector.template provide<A9>(),
          injector.template provide<A10>());
    };

    static void dispose(Injector & injector, Iface * iface) {
      new_delete(injector).template _delete<Iface>(iface);
    };
  };

} } } // namespace bindings, namespace internal, namespace sauce

#endif