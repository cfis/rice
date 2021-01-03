#include "unittest.hpp"
#include "embed_ruby.hpp"
#include "rice/detail/Convert.hpp"
#include "rice/String.hpp"
#include "rice/Array.hpp"
#include "rice/Hash.hpp"
#include <limits>
#include <cmath>

using namespace Rice;

TESTSUITE(To_From_Ruby);

SETUP(To_From_Ruby)
{
  embed_ruby();
}

TESTCASE(object_to_ruby)
{
  Object o(rb_str_new2("foo"));
  ASSERT_EQUAL(o.value(), detail::Convert<Object>::to_ruby(o));
}

TESTCASE(object_from_ruby)
{
  Object o(rb_str_new2("foo"));
  ASSERT_EQUAL(o, detail::Convert<Object>::from_ruby(o));
}

TESTCASE(short_to_ruby)
{
  ASSERT_EQUAL(INT2NUM(0), detail::Convert<short>::to_ruby(0));
  ASSERT_EQUAL(INT2NUM(-1), detail::Convert<short>::to_ruby(-1));
  ASSERT_EQUAL(INT2NUM(1), detail::Convert<short>::to_ruby(1));
  ASSERT_EQUAL(INT2NUM(std::numeric_limits<short>::min()),
               detail::Convert<short>::to_ruby(std::numeric_limits<short>::min()));
  ASSERT_EQUAL(INT2NUM(std::numeric_limits<short>::max()),
               detail::Convert<short>::to_ruby(std::numeric_limits<short>::max()));
}

TESTCASE(short_from_ruby)
{
  ASSERT_EQUAL(0, detail::Convert<short>::from_ruby(INT2NUM(0)));
  ASSERT_EQUAL(-1, detail::Convert<short>::from_ruby(INT2NUM(-1)));
  ASSERT_EQUAL(1, detail::Convert<short>::from_ruby(INT2NUM(1)));
  ASSERT_EQUAL(
      std::numeric_limits<short>::min(),
      detail::Convert<short>::from_ruby(INT2NUM(std::numeric_limits<short>::min())));
  ASSERT_EQUAL(
      std::numeric_limits<short>::max(),
      detail::Convert<short>::from_ruby(INT2NUM(std::numeric_limits<short>::max())));
}

TESTCASE(int_to_ruby)
{
  ASSERT(rb_equal(INT2NUM(0), detail::Convert<int>::to_ruby(0)));
  ASSERT(rb_equal(INT2NUM(-1), detail::Convert<int>::to_ruby(-1)));
  ASSERT(rb_equal(INT2NUM(1), detail::Convert<int>::to_ruby(1)));
  ASSERT(rb_equal(INT2NUM(std::numeric_limits<int>::min()), detail::Convert<int>::to_ruby(std::numeric_limits<int>::min())));
  ASSERT(rb_equal(INT2NUM(std::numeric_limits<int>::max()), detail::Convert<int>::to_ruby(std::numeric_limits<int>::max())));
}

TESTCASE(int_from_ruby)
{
  ASSERT_EQUAL(0, detail::Convert<int>::from_ruby(INT2NUM(0)));
  ASSERT_EQUAL(-1, detail::Convert<int>::from_ruby(INT2NUM(-1)));
  ASSERT_EQUAL(1, detail::Convert<int>::from_ruby(INT2NUM(1)));
  ASSERT_EQUAL(
      std::numeric_limits<int>::min(),
      detail::Convert<int>::from_ruby(INT2NUM(std::numeric_limits<int>::min())));
  ASSERT_EQUAL(
      std::numeric_limits<int>::max(),
      detail::Convert<int>::from_ruby(INT2NUM(std::numeric_limits<int>::max())));
}

TESTCASE(long_to_ruby)
{
  ASSERT(rb_equal(LONG2NUM(0), detail::Convert<long>::to_ruby(0)));
  ASSERT(rb_equal(LONG2NUM(-1), detail::Convert<long>::to_ruby(-1)));
  ASSERT(rb_equal(LONG2NUM(1), detail::Convert<long>::to_ruby(1)));
  ASSERT(rb_equal(LONG2NUM(FIXNUM_MAX), detail::Convert<long>::to_ruby(FIXNUM_MAX)));
  ASSERT(rb_equal(LONG2NUM(FIXNUM_MIN), detail::Convert<long>::to_ruby(FIXNUM_MIN)));
  ASSERT(rb_equal(LONG2NUM(std::numeric_limits<long>::min()), detail::Convert<long>::to_ruby(std::numeric_limits<long>::min())));
  ASSERT(rb_equal(LONG2NUM(std::numeric_limits<long>::max()), detail::Convert<long>::to_ruby(std::numeric_limits<long>::max())));
}

TESTCASE(long_from_ruby)
{
  ASSERT_EQUAL(0, detail::Convert<long>::from_ruby(LONG2NUM(0)));
  ASSERT_EQUAL(-1, detail::Convert<long>::from_ruby(LONG2NUM(-1)));
  ASSERT_EQUAL(1, detail::Convert<long>::from_ruby(LONG2NUM(1)));
  ASSERT_EQUAL(
      FIXNUM_MIN,
      detail::Convert<long>::from_ruby(LONG2NUM(FIXNUM_MIN)));
  ASSERT_EQUAL(
      FIXNUM_MAX,
      detail::Convert<long>::from_ruby(LONG2NUM(FIXNUM_MAX)));
  ASSERT_EQUAL(
      std::numeric_limits<long>::min(),
      detail::Convert<long>::from_ruby(LONG2NUM(std::numeric_limits<long>::min())));
  ASSERT_EQUAL(
      std::numeric_limits<long>::max(),
      detail::Convert<long>::from_ruby(LONG2NUM(std::numeric_limits<long>::max())));
}

TESTCASE(long_long_to_ruby)
{
  ASSERT(rb_equal(LL2NUM(0), detail::Convert<long long>::to_ruby(0)));
  ASSERT(rb_equal(LL2NUM(-1), detail::Convert<long long>::to_ruby(-1)));
  ASSERT(rb_equal(LL2NUM(1), detail::Convert<long long>::to_ruby(1)));
  ASSERT(rb_equal(LL2NUM(std::numeric_limits<long long>::min()), 
         detail::Convert<long long>::to_ruby(std::numeric_limits<long long>::min())));
  ASSERT(rb_equal(LL2NUM(std::numeric_limits<long long>::max()), 
         detail::Convert<long long>::to_ruby(std::numeric_limits<long long>::max())));
}

TESTCASE(long_long_from_ruby)
{
  ASSERT_EQUAL(0, detail::Convert<long long>::from_ruby(LL2NUM(0)));
  ASSERT_EQUAL(-1, detail::Convert<long long>::from_ruby(LL2NUM(-1)));
  ASSERT_EQUAL(1, detail::Convert<long long>::from_ruby(LL2NUM(1)));
  ASSERT_EQUAL(
      std::numeric_limits<long long>::min(),
      detail::Convert<long long>::from_ruby(LL2NUM(std::numeric_limits<long long>::min())));
  ASSERT_EQUAL(
      std::numeric_limits<long long>::max(),
      detail::Convert<long long>::from_ruby(LL2NUM(std::numeric_limits<long long>::max())));
}

TESTCASE(unsigned_short_to_ruby)
{
  ASSERT(rb_equal(UINT2NUM(0), detail::Convert<unsigned short>::to_ruby(0)));
  ASSERT(rb_equal(UINT2NUM(1), detail::Convert<unsigned short>::to_ruby(1)));
  ASSERT(rb_equal(UINT2NUM(std::numeric_limits<unsigned short>::min()), 
         detail::Convert<unsigned short>::to_ruby(std::numeric_limits<unsigned short>::min())));
  ASSERT(rb_equal(UINT2NUM(std::numeric_limits<unsigned short>::max()), 
         detail::Convert<unsigned short>::to_ruby(std::numeric_limits<unsigned short>::max())));
}

TESTCASE(unsigned_short_from_ruby)
{
  ASSERT_EQUAL(0u, detail::Convert<unsigned short>::from_ruby(UINT2NUM(0)));
  ASSERT_EQUAL(1u, detail::Convert<unsigned short>::from_ruby(UINT2NUM(1)));
  ASSERT_EQUAL(
      std::numeric_limits<unsigned short>::min(),
      detail::Convert<unsigned short>::from_ruby(UINT2NUM(std::numeric_limits<unsigned short>::min())));
  ASSERT_EQUAL(
      std::numeric_limits<unsigned short>::max(),
      detail::Convert<unsigned short>::from_ruby(UINT2NUM(std::numeric_limits<unsigned short>::max())));
}

TESTCASE(unsigned_int_to_ruby)
{
  ASSERT(rb_equal(UINT2NUM(0), detail::Convert<unsigned int>::to_ruby(0)));
  ASSERT(rb_equal(UINT2NUM(1), detail::Convert<unsigned int>::to_ruby(1)));
  ASSERT(rb_equal(UINT2NUM(std::numeric_limits<unsigned int>::min()), 
         detail::Convert<unsigned int>::to_ruby(std::numeric_limits<unsigned int>::min())));
  ASSERT(rb_equal(UINT2NUM(std::numeric_limits<unsigned int>::max()), 
         detail::Convert<unsigned int>::to_ruby(std::numeric_limits<unsigned int>::max())));
}

TESTCASE(unsigned_int_from_ruby)
{
  ASSERT_EQUAL(0u, detail::Convert<unsigned int>::from_ruby(UINT2NUM(0)));
  ASSERT_EQUAL(1u, detail::Convert<unsigned int>::from_ruby(UINT2NUM(1)));
  ASSERT_EQUAL(
      std::numeric_limits<unsigned int>::min(),
      detail::Convert<unsigned int>::from_ruby(UINT2NUM(std::numeric_limits<unsigned int>::min())));
  ASSERT_EQUAL(
      std::numeric_limits<unsigned int>::max(),
      detail::Convert<unsigned int>::from_ruby(UINT2NUM(std::numeric_limits<unsigned int>::max())));
}

TESTCASE(unsigned_long_to_ruby)
{
  ASSERT(rb_equal(ULONG2NUM(0), detail::Convert<unsigned long>::to_ruby(0)));
  ASSERT(rb_equal(ULONG2NUM(1), detail::Convert<unsigned long>::to_ruby(1)));
  ASSERT(rb_equal(ULONG2NUM(FIXNUM_MAX), detail::Convert<unsigned long>::to_ruby(FIXNUM_MAX)));
  ASSERT(rb_equal(ULONG2NUM(std::numeric_limits<unsigned long>::min()), 
         detail::Convert<unsigned long>::to_ruby(std::numeric_limits<unsigned long>::min())));
  ASSERT(rb_equal(ULONG2NUM(std::numeric_limits<unsigned long>::max()), 
         detail::Convert<unsigned long>::to_ruby(std::numeric_limits<unsigned long>::max())));
}

TESTCASE(unsigned_long_from_ruby)
{
  ASSERT_EQUAL(0u, detail::Convert<unsigned long>::from_ruby(ULONG2NUM(0)));
  ASSERT_EQUAL(1u, detail::Convert<unsigned long>::from_ruby(ULONG2NUM(1)));
  ASSERT_EQUAL(
      static_cast<unsigned long>(FIXNUM_MIN),
      detail::Convert<unsigned long>::from_ruby(ULONG2NUM(FIXNUM_MIN)));
  ASSERT_EQUAL(
      std::numeric_limits<unsigned long>::min(),
      detail::Convert<unsigned long>::from_ruby(ULONG2NUM(std::numeric_limits<unsigned long>::min())));
  ASSERT_EQUAL(
      std::numeric_limits<unsigned long>::max(),
      detail::Convert<unsigned long>::from_ruby(ULONG2NUM(std::numeric_limits<unsigned long>::max())));
}

TESTCASE(unsigned_long_long_to_ruby)
{
  ASSERT(rb_equal(ULL2NUM(0), detail::Convert<unsigned long long>::to_ruby(0)));
  ASSERT(rb_equal(ULL2NUM(1), detail::Convert<unsigned long long>::to_ruby(1)));
  ASSERT(rb_equal(ULL2NUM(std::numeric_limits<unsigned long long>::min()), \
         detail::Convert<unsigned long long>::to_ruby(std::numeric_limits<unsigned long long>::min())));
  ASSERT(rb_equal(ULL2NUM(std::numeric_limits<unsigned long long>::max()), 
         detail::Convert<unsigned long long>::to_ruby(std::numeric_limits<unsigned long long>::max())));
}

TESTCASE(unsigned_long_long_from_ruby)
{
  ASSERT_EQUAL(0u, detail::Convert<unsigned long>::from_ruby(ULL2NUM(0)));
  ASSERT_EQUAL(1u, detail::Convert<unsigned long>::from_ruby(ULL2NUM(1)));
  ASSERT_EQUAL(
      std::numeric_limits<unsigned long long>::min(),
      detail::Convert<unsigned long long>::from_ruby(ULL2NUM(std::numeric_limits<unsigned long long>::min())));
  ASSERT_EQUAL(
      std::numeric_limits<unsigned long long>::max(),
      detail::Convert<unsigned long long>::from_ruby(ULL2NUM(std::numeric_limits<unsigned long long>::max())));
}

TESTCASE(bool_to_ruby)
{
  ASSERT(rb_equal(Qfalse, detail::Convert<bool>::to_ruby(false)));
  ASSERT(rb_equal(Qtrue, detail::Convert<bool>::to_ruby(true)));
}

TESTCASE(bool_from_ruby)
{
  ASSERT_EQUAL(false, detail::Convert<bool>::from_ruby(Object(Qfalse)));
  ASSERT_EQUAL(true, detail::Convert<bool>::from_ruby(Object(Qtrue)));
}

TESTCASE(float_to_ruby)
{
  ASSERT(rb_equal(rb_float_new(0.0f), detail::Convert<float>::to_ruby(0.0)));
  ASSERT(rb_equal(rb_float_new(-1.0f), detail::Convert<float>::to_ruby(-1.0)));
  ASSERT(rb_equal(rb_float_new(1.0f), detail::Convert<float>::to_ruby(1.0)));
  ASSERT(rb_equal(rb_float_new(0.5f), detail::Convert<float>::to_ruby(0.5)));
  ASSERT(rb_equal(rb_float_new(std::numeric_limits<float>::min()), detail::Convert<float>::to_ruby(std::numeric_limits<float>::min())));
  ASSERT(rb_equal(rb_float_new(std::numeric_limits<float>::max()), detail::Convert<float>::to_ruby(std::numeric_limits<float>::max())));
  ASSERT(
      Object(detail::Convert<float>::to_ruby(std::numeric_limits<float>::quiet_NaN())).call("nan?"));
  ASSERT(
      Object(detail::Convert<float>::to_ruby(std::numeric_limits<float>::signaling_NaN())).call("nan?"));
  ASSERT_EQUAL(
      rb_float_new(std::numeric_limits<float>::epsilon()),
      detail::Convert<float>::to_ruby(std::numeric_limits<float>::epsilon()));
}

TESTCASE(float_from_ruby)
{
  ASSERT_EQUAL(0.0f, detail::Convert<float>::from_ruby(rb_float_new(0.0f)));
  ASSERT_EQUAL(-1.0f, detail::Convert<float>::from_ruby(rb_float_new(-1.0f)));
  ASSERT_EQUAL(1.0f, detail::Convert<float>::from_ruby(rb_float_new(1.0f)));
  ASSERT_EQUAL(
      std::numeric_limits<float>::min(),
      detail::Convert<float>::from_ruby(rb_float_new(std::numeric_limits<float>::min())));
  ASSERT_EQUAL(
      std::numeric_limits<float>::max(),
      detail::Convert<float>::from_ruby(rb_float_new(std::numeric_limits<float>::max())));
  ASSERT(
      std::isnan(detail::Convert<float>::from_ruby(rb_float_new(std::numeric_limits<float>::quiet_NaN()))));
  ASSERT(
      std::isnan(detail::Convert<float>::from_ruby(rb_float_new(std::numeric_limits<float>::signaling_NaN()))));
  ASSERT_EQUAL(
      std::numeric_limits<float>::epsilon(),
      detail::Convert<float>::from_ruby(rb_float_new(std::numeric_limits<float>::epsilon())));
}

TESTCASE(double_to_ruby)
{
  ASSERT(rb_equal(rb_float_new(0.0f), detail::Convert<double>::to_ruby(0.0)));
  ASSERT(rb_equal(rb_float_new(-1.0f), detail::Convert<double>::to_ruby(-1.0)));
  ASSERT(rb_equal(rb_float_new(1.0f), detail::Convert<double>::to_ruby(1.0)));
  ASSERT(rb_equal(rb_float_new(0.5f), detail::Convert<double>::to_ruby(0.5)));
  ASSERT(rb_equal(rb_float_new(std::numeric_limits<double>::min()), detail::Convert<double>::to_ruby(std::numeric_limits<double>::min())));
  ASSERT(rb_equal(rb_float_new(std::numeric_limits<double>::max()), detail::Convert<double>::to_ruby(std::numeric_limits<double>::max())));
  ASSERT(Object(detail::Convert<double>::to_ruby(std::numeric_limits<double>::quiet_NaN())).call("nan?"));
  ASSERT(Object(detail::Convert<double>::to_ruby(std::numeric_limits<double>::signaling_NaN())).call("nan?"));
  ASSERT(rb_equal(rb_float_new(std::numeric_limits<double>::epsilon()), detail::Convert<double>::to_ruby(std::numeric_limits<double>::epsilon())));
}

TESTCASE(double_from_ruby)
{
  ASSERT_EQUAL(0.0f, detail::Convert<double>::from_ruby(rb_float_new(0.0f)));
  ASSERT_EQUAL(-1.0f, detail::Convert<double>::from_ruby(rb_float_new(-1.0f)));
  ASSERT_EQUAL(1.0f, detail::Convert<double>::from_ruby(rb_float_new(1.0f)));
  ASSERT_EQUAL(
      std::numeric_limits<double>::min(),
      detail::Convert<double>::from_ruby(rb_float_new(std::numeric_limits<double>::min())));
  ASSERT_EQUAL(
      std::numeric_limits<double>::max(),
      detail::Convert<double>::from_ruby(rb_float_new(std::numeric_limits<double>::max())));
  ASSERT(
      std::isnan(detail::Convert<double>::from_ruby(rb_float_new(std::numeric_limits<double>::quiet_NaN()))));
  ASSERT(
      std::isnan(detail::Convert<double>::from_ruby(rb_float_new(std::numeric_limits<double>::signaling_NaN()))));
  ASSERT_EQUAL(
      std::numeric_limits<double>::epsilon(),
      detail::Convert<double>::from_ruby(rb_float_new(std::numeric_limits<double>::epsilon())));
}

TESTCASE(char_const_ptr_to_ruby)
{
  ASSERT(rb_equal(String("").value(), detail::Convert<char const *>::to_ruby("")));
  ASSERT(rb_equal(String("foo").value(), detail::Convert<char const *>::to_ruby("foo")));
}

TESTCASE(char_const_ptr_from_ruby)
{
  char const* foo = "foo";
  ASSERT_EQUAL("", detail::Convert<char const *>::from_ruby(rb_str_new2("")));
  ASSERT_EQUAL(foo, detail::Convert<char const *>::from_ruby(rb_str_new2("foo")));
}

TESTCASE(char_from_ruby_single_character_string)
{
  ASSERT_EQUAL('x', detail::Convert<char>::from_ruby(rb_str_new2("x")));
}

TESTCASE(char_from_ruby_longer_string)
{
  ASSERT_EXCEPTION(
    std::invalid_argument,
    detail::Convert<char>::from_ruby(rb_str_new2("xy"))
  );
}

TESTCASE(char_from_ruby_fixnum)
{
  ASSERT_EQUAL('1', detail::Convert<char>::from_ruby(INT2NUM(49)));
}

TESTCASE(char_star_from_ruby)
{
  const char* expected = "my string";
  ASSERT_EQUAL(expected, detail::Convert<const char*>::from_ruby(rb_str_new2("my string")));
}

TESTCASE(std_string_to_ruby)
{
  ASSERT(rb_equal(String("").value(), detail::Convert<std::string>::to_ruby(std::string(""))));
  ASSERT(rb_equal(String("foo").value(), detail::Convert<std::string>::to_ruby(std::string("foo"))));
}

TESTCASE(std_string_from_ruby)
{
  ASSERT_EQUAL(std::string(""), detail::Convert<std::string>::from_ruby(rb_str_new2("")));
  ASSERT_EQUAL(std::string("foo"), detail::Convert<std::string>::from_ruby(rb_str_new2("foo")));
}

TESTCASE(std_string_to_ruby_with_binary)
{
  Rice::String got = detail::Convert<std::string>::to_ruby(std::string("\000test", 5));

  ASSERT_EQUAL(String(std::string("\000test", 5)), got);
  ASSERT_EQUAL(5, got.length());
}

TESTCASE(std_string_from_ruby_with_binary)
{
  std::string got = detail::Convert<std::string>::from_ruby(rb_str_new("\000test", 5));
  ASSERT_EQUAL(5, got.length());
  ASSERT_EQUAL(std::string("\000test", 5), got);
}

TESTCASE(array_to_ruby)
{
  Array a(rb_ary_new());
  ASSERT(rb_equal(a.value(), detail::Convert<Array>::to_ruby(a)));
}

TESTCASE(array_from_ruby)
{
  Array a(rb_ary_new());
  ASSERT_EQUAL(a, detail::Convert<Array>::from_ruby(a));
}

TESTCASE(hash_to_ruby)
{
  Hash h(rb_hash_new());
  ASSERT(rb_equal(h.value(), detail::Convert<Hash>::to_ruby(h)));
}

TESTCASE(hash_from_ruby)
{
  Hash h(rb_hash_new());
  ASSERT_EQUAL(h, detail::Convert<Hash>::from_ruby(h));
}
