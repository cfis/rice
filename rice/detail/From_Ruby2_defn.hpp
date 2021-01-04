#ifndef Rice__detail__From_Ruby2_defn__hpp_
#define Rice__detail__From_Ruby2_defn__hpp_

#include "ruby.hpp"

namespace Rice
{
  namespace detail
  {
    template <typename T>
    T from_ruby(VALUE value);

  } // detail
} // Rice

#endif // Rice__detail__From_Ruby2_defn__hpp_
