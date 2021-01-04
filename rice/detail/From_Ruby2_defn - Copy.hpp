#ifndef Rice__detail__From_Ruby2_defn__hpp_
#define Rice__detail__From_Ruby2_defn__hpp_

#include "ruby.hpp"

namespace Rice
{
  namespace detail
  {
    template <typename T, typename Base_Type = std::decay_t<std::remove_pointer_t<T>>>
    class FromRubyAbstract
    {
    public:
      T nativeValue(VALUE value)
      {
        this->nativeValue_ = convert(value);
        return this->nativeValue_;
      }

      /*  if (std::is_pointer_v(T))
        {
          return &this->nativeValue_;
        }
        else if constexpr (std::is_reference_v(T))
        {
          return &this->nativeValue_;
        }
        else
        {
          return this->nativeValue_;
        }
      }*/

    protected:
      virtual T convert(VALUE value) = 0;

    private:
      Base_Type nativeValue_;
    };

    template <typename T>
    class From_Ruby : public FromRubyAbstract<T>
    {

    };
  } // detail
} // Rice

#endif // Rice__detail__From_Ruby2_defn__hpp_
