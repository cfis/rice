#ifndef Rice__Module_defn__hpp_
#define Rice__Module_defn__hpp_

#include "Object_defn.hpp"
#include "Exception_Mixin.hpp"
#include "Module_Mixin.hpp"
#include "to_from_ruby_defn.hpp"

namespace Rice
{

class Array;
class Class;
class String;

//! A helper for defining a Module and its methods.
/*! This class provides a C++-style interface to ruby's Module class and
 *  for defining methods on that module.
 *
 *  Many of the methods are defined in Module_impl.hpp so that they can
 *  return a reference to the most derived type.
 */
class Module
  // TODO: we can't inherit from Builtin_Object, because Class needs
  // type T_CLASS and Module needs type T_MODULE
  : public Object, public Module_Mixin<Module>, public Exception_Mixin<Module>
{
public:
  //! Default construct a Module and initialize it to rb_cObject.
  Module();

  //! Construct a Module from an existing Module object.
  Module(VALUE v);

  //! Return the name of the module.
  String name() const;
};

//! Define a new module in the namespace given by module.
/*! \param module the module in which to define the new module.
 *  \param name the name of the new module.
 */
Module define_module_under(
    Object module,
    char const * name);

//! Define a new module in the default namespace.
/*! \param name the name of the new module.
 */
Module define_module(
    char const * name);

//! Create a new anonymous module.
/*! \return the new module.
 */
Module anonymous_module();

} // namespace Rice

template<>
inline
Rice::Module from_ruby<Rice::Module>(VALUE x)
{
  return Rice::Module(x);
}

template<>
inline
VALUE to_ruby<Rice::Module>(Rice::Module const & x)
{
  return x.value();
}

#endif // Rice__Module_defn__hpp_
