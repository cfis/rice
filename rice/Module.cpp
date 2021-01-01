#include "Module_defn.hpp"
#include "Exception.hpp"
#include "Array.hpp"

Rice::Module::
Module()
  : Object(rb_cObject)
{
}

Rice::Module::
Module(VALUE v)
  : Object(v)
{
  if(::rb_type(v) != T_CLASS && ::rb_type(v) != T_MODULE)
  {
    throw Exception(
        rb_eTypeError,
        "Expected a Module but got a %s",
        rb_class2name(CLASS_OF(v))); // TODO: might raise an exception
  }
}

Rice::String Rice::Module::
name() const
{
  Object name = rb_mod_name(*this);
  if(name.is_nil())
  {
    // 1.9
    return String("");
  }
  else
  {
    return name;
  }
}

Rice::Module Rice::
define_module_under(
    Rice::Object module,
    char const * name)
{
  VALUE v = rb_define_module_under(module, name);
  return Module(v);
}

Rice::Module Rice::
define_module(
    char const * name)
{
  VALUE v = rb_define_module(name);
  return Module(v);
}

Rice::Module Rice::
anonymous_module()
{
  return Module(protect(rb_module_new));
}