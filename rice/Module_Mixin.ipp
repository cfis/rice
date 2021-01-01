template<typename Derived_T>
inline
Derived_T&
Rice::Module_Mixin<Derived_T>::
derived()
{
  return (Derived_T&)*this;
}

template<typename Derived_T>
inline
Rice::Array
Rice::Module_Mixin<Derived_T>::
ancestors() const
{
  return protect(rb_mod_ancestors, this->derived());
}

template<typename Derived_T>
template<typename Func_T>
inline
Derived_T &
Rice::Module_Mixin<Derived_T>::
define_method(
    Identifier name,
    Func_T func,
    Arguments* arguments)
{
  detail::define_method_and_auto_wrap(
      this->derived(), name, func, this->derived().handler(), arguments);
  return this->derived();
}

template<typename Derived_T>
template<typename Func_T>
inline
Derived_T &
Rice::Module_Mixin<Derived_T>::
define_method(
    Identifier name,
    Func_T func,
    Arg const& arg)
{
  Arguments* args = new Arguments();
  args->add(arg);
  return define_method(name, func, args);
}

template<typename Derived_T>
template<typename Func_T>
inline
Derived_T &
Rice::Module_Mixin<Derived_T>::
define_singleton_method(
    Identifier name,
    Func_T func,
    Arguments* arguments)
{
  detail::define_method_and_auto_wrap(
      rb_singleton_class(this->derived()), name, func, this->derived().handler(), arguments);
  return this->derived();
}

template<typename Derived_T>
template<typename Func_T>
inline
Derived_T &
Rice::Module_Mixin<Derived_T>::
define_singleton_method(
    Identifier name,
    Func_T func,
    Arg const& arg)
{
  Arguments* args = new Arguments();
  args->add(arg);
  return define_singleton_method(name, func, args);
}

template<typename Derived_T>
template<typename Func_T>
inline
Derived_T &
Rice::Module_Mixin<Derived_T>::
define_module_function(
    Identifier name,
    Func_T func,
    Arguments* arguments)
{
  if(this->derived().rb_type() != T_MODULE)
  {
    throw std::runtime_error("can only define module functions for modules");
  }

  define_method(name, func, arguments);
  define_singleton_method(name, func, arguments);
  return this->derived();
}

template<typename Derived_T>
template<typename Func_T>
inline
Derived_T &
Rice::Module_Mixin<Derived_T>::
define_module_function(
    Identifier name,
    Func_T func,
    Arg const& arg)
{
  Arguments* args = new Arguments();
  args->add(arg);
  return define_module_function(name, func, args);
}

/*template<typename Derived_T>
template<typename T, typename Iterator_T>
inline
Derived_T &
Rice::Module_Mixin<Derived_T>::
define_iterator(
    Iterator_T (T::*begin)(),
    Iterator_T (T::*end)(),
    Identifier name)
{
  detail::define_iterator(this->derived(), name, begin, end);
  return this->derived();
}
*/
namespace Rice
{

namespace detail
{

inline VALUE
  include_module(VALUE mod, VALUE inc)
{
  rb_include_module(mod, inc);
  return Qnil;
}

inline VALUE
const_set(VALUE mod, ID name, VALUE value)
{
  rb_const_set(mod, name, value);
  return Qnil;
}

} // namespace detail

} // namespace Rice

template<typename Derived_T>
inline
Derived_T &
Rice::Module_Mixin<Derived_T>::
include_module(
    Module const & inc)
{
  protect(detail::include_module, this->derived(), inc);
  return this->derived();
}

template<typename Derived_T>
inline
Derived_T &
Rice::Module_Mixin<Derived_T>::
const_set(
    Identifier name,
    Object value)
{
  protect(detail::const_set, this->derived(), name, value);
  return this->derived();
}

template<typename Derived_T>
inline
Rice::Object
Rice::Module_Mixin<Derived_T>::
const_get(
    Identifier name) const
{
  return protect(rb_const_get, this->derived(), name);
}

template<typename Derived_T>
inline
bool
Rice::Module_Mixin<Derived_T>::
const_defined(Identifier name) const
{
  size_t result = protect(rb_const_defined, this->derived(), name);
  return bool(result);
}

template<typename Derived_T>
inline
void
Rice::Module_Mixin<Derived_T>::
remove_const(Identifier name)
{
  protect(rb_mod_remove_const, this->derived(), name.to_sym());
}
/*
template<typename Derived_T>
inline
Rice::Module
Rice::Module_Mixin<Derived_T>::
define_module(
    char const * name)
{
  return Rice::define_module_under(this->derived(), name);
}
*/
/*template<typename Derived_T>
inline
Rice::Class
Rice::Module_Mixin<Derived_T>::
define_class(
    char const * name,
    Object superclass)
{
  return Rice::define_class_under(this->derived(), name, superclass);
}*/
/*
template<typename Derived_T>
template<typename T>
inline
Rice::Data_Type<T>
Rice::Module_Mixin<Derived_T>::
define_class_with_object_as_base(
    char const * name)
{
  return Rice::define_class_under<T>(this->derived(), name);
}*/

/*template<typename Derived_T>
template<typename T, typename T_Base_T>
inline
Rice::Data_Type<T>
Rice::Module_Mixin<Derived_T>::
define_class(
    char const * name)
{
  return Rice::define_class_under<T, T_Base_T>(
      this->derived(),
      name);
}*/