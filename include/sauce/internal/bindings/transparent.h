#ifndef SAUCE_SAUCE_INTERNAL_BINDINGS_TRANSPARENT_H_
#define SAUCE_SAUCE_INTERNAL_BINDINGS_TRANSPARENT_H_

#include <sauce/injector.h>
#include <sauce/memory.h>
#include <sauce/internal/binding.h>

namespace sauce {
namespace internal {
namespace bindings {

template<typename Iface, typename Impl>
class TransparentBinding;

/**
 * A smart pointer deleter that diposes with a given binding.
 */
template<typename Iface, typename Impl>
class BindingDeleter {

  friend class TransparentBinding<Iface, Impl>;

  TransparentBinding<Iface, Impl> * binding;

  BindingDeleter(TransparentBinding<Iface, Impl> * binding):
    binding(binding) {}

public:

  /**
   * Cast and dispose the given Iface instance.
   */
  void operator()(Iface * iface) const {
    binding->dispose(static_cast<Impl *>(iface));
  }

};

/**
 * A binding for a specific interface and implementation.
 */
template<typename Iface, typename Impl>
class TransparentBinding:
  public ResolvedBinding<Iface> {
public:

  friend class BindingDeleter<Iface, Impl>;

  /**
   * The BindKey of the Iface template parameter.
   */
  virtual BindKey getKey() {
    return BindKeyOf<Iface>();
  }

  /**
   * Provide an instance of Iface.
   *
   * Derived classes should not override this but provide().
   */
  SAUCE_SHARED_PTR<Iface> get(Injector & injector) {
    // TODO: reuse deleter, but don't inject 'this' in TransparentBinding constructor
    BindingDeleter<Iface, Impl> deleter(this);
    SAUCE_SHARED_PTR<Iface> smartPointer(provide(injector), deleter);
    return smartPointer;
  }

private:

  /**
   * Provide an instance of Impl.
   *
   * The strategy used is left to derived types.
   */
  virtual Impl * provide(Injector & injector) = 0;

  /**
   * Dispose of an instance of Iface provided by this binding.
   *
   * The strategy used is left to derived types.
   */
  virtual void dispose(Impl * impl) = 0;

};

}
}

namespace i = ::sauce::internal;
namespace b = ::sauce::internal::bindings;

}

#endif // SAUCE_SAUCE_INTERNAL_BINDINGS_TRANSPARENT_H_