#include <ruby.h>
#include <string>
#include <stdexcept>

namespace Rice
{

namespace detail
{
  // This is purely to make MSVCC compiler happy when compiling line
  // 119 in Wrapped_Function.ipp which is code that will never be called
  template<>
  struct Convert<void>
  {
    static VALUE to_ruby()
    {
      return Qnil;
    }
  };

  template<>
  struct Convert<short>
  {
    static short from_ruby(VALUE x)
    {
      return NUM2SHORT(x);
    }

    static VALUE to_ruby(short const& x)
    {
      return INT2NUM(x);
    }
  };

  template<>
  struct Convert<int>
  {
    static int from_ruby(VALUE x)
    {
      return NUM2INT(x);
    }

    static VALUE to_ruby(int const& x)
    {
      return INT2NUM(x);
    }
  };

  template<>
  struct Convert<long>
  {
    static long from_ruby(VALUE x)
    {
      return (long)NUM2LONG(x);
    }

    static VALUE to_ruby(long const& x)
    {
      return LONG2NUM(x);
    }
  };

  template<>
  struct Convert<long long>
  {
    static long long from_ruby(VALUE x)
    {
      return RB_NUM2LL(x);
    }

    static VALUE to_ruby(long long const& x)
    {
      return LL2NUM(x);
    }
  };

  template<>
  struct Convert<unsigned short>
  {
    static unsigned short from_ruby(VALUE x)
    {
      return NUM2USHORT(x);
    }

    static VALUE to_ruby(unsigned short const& x)
    {
      return UINT2NUM(x);
    }
  };

  template<>
  struct Convert<unsigned int>
  {
    static unsigned int from_ruby(VALUE x)
    {
      return NUM2UINT(x);
    }

    static VALUE to_ruby(unsigned int const& x)
    {
      return UINT2NUM(x);
    }
  };

  template<>
  struct Convert<unsigned long>
  {
    static unsigned long from_ruby(VALUE x)
    {
      return (unsigned long)RB_NUM2ULONG(x);
    }

    static VALUE to_ruby(unsigned long const& x)
    {
      return ULONG2NUM(x);
    }
  };

  template<>
  struct Convert<unsigned long long>
  {
    static unsigned long long from_ruby(VALUE x)
    {
      return RB_NUM2ULL(x);
    }

    static VALUE to_ruby(unsigned long long const& x)
    {
      return ULL2NUM(x);
    }
  };

  template<>
  struct Convert<bool>
  {
    static bool from_ruby(VALUE x)
    {
      return RTEST(x);
    }

    static VALUE to_ruby(bool const& x)
    {
      return x ? Qtrue : Qfalse;
    }
  };

  template<>
  struct Convert<float>
  {
    static float from_ruby(VALUE x)
    {
      return (float)NUM2DBL(x);
    }

    static VALUE to_ruby(float const& x)
    {
      return DBL2NUM(x);
    }
  }; 

  template<>
  struct Convert<double>
  {
    static double from_ruby(VALUE x)
    {
      return NUM2DBL(x);
    }

    static VALUE to_ruby(double const& x)
    {
      return DBL2NUM(x);
    }
  };

  template<>
  struct Convert<char>
  {
    static char from_ruby(VALUE x)
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
        return Convert<int>::from_ruby(x) & 0xff;
      }
    }

    static VALUE to_ruby(char const& x)
    {
      return rb_str_new2(&x);
    }
  };

  template<>
  struct Convert<const char*>
  {
    static const char* from_ruby(VALUE x)
    {
      return RSTRING_PTR(x);
    }

    static VALUE to_ruby(const char* x)
    {
      return rb_str_new2(x);
    }
  };

  template<>
  struct Convert<unsigned char>
  {
    static unsigned char from_ruby(VALUE x)
    {
      return Convert<char>::from_ruby(x);
    }

    static VALUE to_ruby(unsigned char const& x)
    {
      return Convert<char>::to_ruby((char)x);
    }
  };

  template<>
  struct Convert<std::string>
  {
    static std::string from_ruby(VALUE x)
    {
      return std::string(RSTRING_PTR(x), RSTRING_LEN(x));
    }

    static VALUE to_ruby(std::string const& x)
    {
      return rb_str_new(x.data(), (long)x.size());
    }
  };
  /*
  template<>
  struct Convert<std::string&>
  {
    static VALUE to_ruby(std::string& x)
    {
      return rb_str_new(x.data(), (long)x.size());
    }
  };

  template<>
  struct Convert<const std::string&>
  {
    static const std::string& from_ruby(VALUE x)
    {
      return std::string(RSTRING_PTR(x), RSTRING_LEN(x));
    }

    static VALUE to_ruby(const std::string& x)
    {
      return rb_str_new(x.data(), (long)x.size());
    }
  };
*/
} // detail
} // Rice
