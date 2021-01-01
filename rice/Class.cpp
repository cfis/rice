#include "Class.hpp"
#include "Exception.hpp"
#include "detail/creation_funcs.hpp"

Rice::Class::
Class(VALUE v)
  : Object(v)
{
  if(::rb_type(v) != T_CLASS)
  {
    throw Exception(
        rb_eTypeError,
        "Expected a Class but got a %s",
        rb_class2name(CLASS_OF(v))); // TODO: might raise an exception
  }
}

Rice::String Rice::Class::
name() const
{
  return rb_class_name(*this);
}

Rice::Class
Rice::Class::
singleton_class() const
{
  return CLASS_OF(value());
}

Rice::Class & Rice::Class::
undef_creation_funcs()
{
  detail::undef_creation_funcs(*this);
  return *this;
}

Rice::Class Rice::
define_class_under(
    Rice::Object module,
    char const * name,
    Rice::Object superclass)
{
  VALUE v = rb_define_class_under(module, name, superclass);
  return Class(v);
}

Rice::Class Rice::
define_class(
    char const * name,
    Rice::Object superclass)
{
  VALUE v = rb_define_class(name, superclass);
  return Class(v);
}

Rice::Class Rice::
anonymous_class(
    Rice::Object superclass)
{
  VALUE v = Class(rb_cClass).call("new");
  return Class(v);
}

