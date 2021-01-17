#ifndef Rice__detail__to_ruby_defn__hpp_
#define Rice__detail__to_ruby_defn__hpp_

#include "rice_traits.hpp"

namespace Rice
{
  namespace detail
  {
    //! Convert a C++ object to Ruby.
    /*! If x is a pointer, wraps the pointee as a Ruby object.  If x is an
     *  Object, returns x.
     *
     *  If no conversion exists a compile-time error is generated.
     *
     *  \param x the object to convert.
     *  \return a Ruby representation of the C++ object.
     *
     *  Example:
     *  \code
     *    rb_p(to_ruby(42));
     *
     *    Foo * p_foo = new Foo();
     *    rb_p(to_ruby(p_foo));
     *  \endcode
     */
    template <typename T, typename = void>
    struct To_Ruby;

    // Supports int&, bool&, std::string&, etc but *NOT* any C++ structs/classes
    template<typename T>
    struct Rice::detail::To_Ruby<T&, std::enable_if_t<is_primitive_v<T>>>
    {
      static VALUE convert(T const& x)
      {
        return To_Ruby<base_type<T>>::convert(x);
      }
    };

    // Supports int*, bool*, std::string*, etc but *NOT* any C++ structs/classes
    template<typename T>
    struct Rice::detail::To_Ruby<T*, std::enable_if_t<is_primitive_v<T>>>
    {
      static VALUE convert(T const* x)
      {
        return To_Ruby<base_type<T>>::convert(*x);
      }
    };

    // Helper template function that let's users avoid having to specify the template type - its deduced
    template <typename T>
    VALUE to_ruby(T&& x)
    {
      return To_Ruby<T>::convert(std::forward<T>(x));
    }

    // Helper template function that let's users avoid having to specify the template type - its deduced
    template <typename T>
    VALUE to_ruby(T* x)
    {
      return To_Ruby<T*>::convert(x);
    }

  } // detail
} // Rice

#endif // Rice__detail__to_ruby_defn__hpp_
