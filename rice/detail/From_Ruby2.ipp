#ifndef Rice__detail__From_Ruby2__ipp_
#define Rice__detail__From_Ruby2__ipp_

#include <ruby.h>
#include <string>
#include <stdexcept>

namespace Rice
{

namespace detail
{
  template<>
  class From_Ruby<short>: public FromRubyAbstract<short>
  {
    short convert(VALUE x) override
    {
      return NUM2SHORT(x);
    }
  };

  template<>
  class From_Ruby<int>: public FromRubyAbstract<int>
  {
    int convert(VALUE x) override
    {
      return NUM2INT(x);
    }
  };

  template<>
  class From_Ruby<long>: public FromRubyAbstract<long>
  {
    long convert(VALUE x) override
    {
      return (long)NUM2LONG(x);
    }
  };

  template<>
  class From_Ruby<long long>: public FromRubyAbstract<long long>
  {
    long long convert(VALUE x) override
    {
      return RB_NUM2LL(x);
    }
  };

  template<>
  class From_Ruby<unsigned short>: public FromRubyAbstract<unsigned short>
  {
    unsigned short convert(VALUE x) override
    {
      return NUM2USHORT(x);
    }
  };

  template<>
  class From_Ruby<unsigned int>: public FromRubyAbstract<unsigned int>
  {
    unsigned int convert(VALUE x) override
    {
      return NUM2UINT(x);
    }
  };

  template<>
  class From_Ruby<unsigned long>: public FromRubyAbstract<unsigned long>
  {
    unsigned long convert(VALUE x) override
    {
      return (unsigned long)RB_NUM2ULONG(x);
    }
  };

  template<>
  class From_Ruby<unsigned long long>: public FromRubyAbstract<unsigned long long>
  {
    unsigned long long convert(VALUE x) override
    {
      return RB_NUM2ULL(x);
    }
  };

  template<>
  class From_Ruby<bool>: public FromRubyAbstract<bool>
  {
    bool convert(VALUE x) override
    {
      return RTEST(x);
    }
  };

  template<>
  class From_Ruby<float>: public FromRubyAbstract<float>
  {
    float convert(VALUE x) override
    {
      return (float)NUM2DBL(x);
    }
  }; 

  template<>
  class From_Ruby<double>: public FromRubyAbstract<double>
  {
    double convert(VALUE x) override
    {
      return NUM2DBL(x);
    }
  };

  template<>
  class From_Ruby<char>: public FromRubyAbstract<char>
  {
    char convert(VALUE x) override
    {
      if (rb_type(x) == T_STRING)
      {
        if (RSTRING_LEN(x) == 1)
        {
          return RSTRING_PTR(x)[0];
            }
        else
        {
          throw std::invalid_argument("from_ruby: string must have length 1");
            }
          }
      else
      {
        return From_Ruby<int>().nativeValue(x) & 0xff;
      }
    }
  };

  template<>
  class From_Ruby<const char*>: public FromRubyAbstract<const char*, const char*>
  {
    const char* convert(VALUE x) override
    {
      return RSTRING_PTR(x);
    }
  };

  template<>
  class From_Ruby<unsigned char>: public FromRubyAbstract<unsigned char>
  {
    unsigned char convert(VALUE x) override
    {
      return From_Ruby<char>().nativeValue(x);
    }
  };

  template<>
  class From_Ruby<std::string>: public FromRubyAbstract<std::string>
  {
    std::string convert(VALUE x) override
    {
      return std::string(RSTRING_PTR(x), RSTRING_LEN(x));
    }
  };

} // detail
} // Rice

#endif Rice__detail__From_Ruby2__ipp_