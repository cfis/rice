#ifndef Rice__detail__Convert_defn__hpp_
#define Rice__detail__Convert_defn__hpp_

#include "ruby.hpp"

namespace Rice
{
  namespace detail
  {
    template<typename T>
    struct Convert
    {
      static T from_ruby(VALUE x);
      static VALUE to_ruby(const T& x);
    };

    template <typename T>
    struct Convert<T&>
    {
      static T& from_ruby(VALUE x)
      {
        return *Convert<T*>::from_ruby(x);
      }

      static VALUE to_ruby(T& x)
      {
        return Convert<T>::to_ruby(x);
      }
    };

    template <typename T>
    struct Convert<const T&>
    {
      static const T& from_ruby(VALUE x)
      {
        return *Convert<T*>::from_ruby(x);
      }

      static VALUE to_ruby(const T& x)
      {
        return Convert<T>::to_ruby(x);
      }
    };
  } // detail
} // Rice

#endif // Rice__detail__Convert_defn__hpp_
