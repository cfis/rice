#ifndef Rice__Module_Mixin_defn__hpp_
#define Rice__Module_Mixin_defn__hpp_

namespace Rice
{

  class Module;
 // class Class;
  //template<typename T> class Data_Type;
}

#include "detail/Arguments.hpp"
#include "detail/define_method_and_auto_wrap.hpp"
#include "Array.hpp"

namespace Rice
{

template<typename Derived_T>
class Module_Mixin
{
public:
  //! Return an array containing the Module's ancestors.
  /*! You will need to include Array.hpp to use this function.
   */
  Array ancestors() const;

  //! Define an instance method.
  /*! The method's implementation can be any function or member
   *  function.  A wrapper will be generated which will use from_ruby<>
   *  to convert the arguments from ruby types to C++ types before
   *  calling the function.  The return value will be converted back to
   *  ruby by using to_ruby().
   *  \param name the name of the method
   *  \param func the implementation of the function, either a function
   *  pointer or a member function pointer.
   *  \param arguments the list of arguments of this function, used for
   *  defining default parameters (optional)
   *  \return *this
   */
  template<typename Func_T>
  Derived_T & define_method(
      Identifier name,
      Func_T func,
      Arguments* arguments = 0);

  // FIXME There's GOT to be a better way to
  // do this. Handles the case where there is a single
  // argument defined for this method
  template<typename Func_T>
  Derived_T & define_method(
      Identifier name,
      Func_T func,
      Arg const& arg);

  //! Define a singleton method.
  /*! The method's implementation can be any function or member
   *  function.  A wrapper will be generated which will use from_ruby<>
   *  to convert the arguments from ruby types to C++ types before
   *  calling the function.  The return value will be converted back to
   *  ruby by using to_ruby().
   *  \param name the name of the method
   *  \param func the implementation of the function, either a function
   *  pointer or a member function pointer.
   *  \param arguments the list of arguments of this function, used for
   *  defining default parameters (optional)
   *  \return *this
   */
  template<typename Func_T>
  Derived_T & define_singleton_method(
      Identifier name,
      Func_T func,
      Arguments* arguments = 0);

  // FIXME: See define_method with Arg above
  template<typename Func_T>
  Derived_T & define_singleton_method(
      Identifier name,
      Func_T func,
      Arg const& arg);

  //! Define a module function.
  /*! A module function is a function that can be accessed either as a
   *  singleton method or as an instance method.
   *  The method's implementation can be any function or member
   *  function.  A wrapper will be generated which will use from_ruby<>
   *  to convert the arguments from ruby types to C++ types before
   *  calling the function.  The return value will be converted back to
   *  ruby by using to_ruby().
   *  \param name the name of the method
   *  \param func the implementation of the function, either a function
   *  pointer or a member function pointer.
   *  \param arguments the list of arguments of this function, used for
   *  defining default parameters (optional)
   *  \return *this
   */
  template<typename Func_T>
  Derived_T & define_module_function(
      Identifier name,
      Func_T func,
      Arguments* arguments = 0);

  // FIXME: See define_method with Arg above
  template<typename Func_T>
  Derived_T & define_module_function(
      Identifier name,
      Func_T func,
      Arg const& arg);

  //! Define an iterator.
  /*! Essentially this is a conversion from a C++-style begin/end
   *  iterator to a Ruby-style \#each iterator.
   *  \param begin a member function pointer to a function that returns
   *  an iterator to the beginning of the sequence.
   *  \param end a member function pointer to a function that returns an
   *  iterator to the end of the sequence.
   *  \param name the name of the iterator.
   *  \return *this
   */
  /*template<typename T, typename Iterator_T>
  Derived_T & define_iterator(
      Iterator_T (T::*begin)(),
      Iterator_T (T::*end)(),
      Identifier name = "each");

  //! Include a module.
  /*! \param inc the module to be included.
   *  \return *this
   */
  Derived_T & include_module(
      Module const & inc);

  //! Set a constant.
  /*! \param name the name of the constant to set.
   *  \param value the value of the constant.
   *  \return *this
   */
  Derived_T & const_set(
      Identifier name,
      Object value);

  //! Get a constant.
  /*! \param name the name of the constant to get.
   *  \return the value of the constant.
   */
  Object const_get(
      Identifier name) const;

  //! Determine whether a constant is defined.
  /*! \param name the name of the constant to check.
   *  \return true if the constant is defined in this module or false
   *  otherwise.
   */
  bool const_defined(
      Identifier name) const;

  //! Remove a constant.
  /*! \param name the name of the constant to remove.
   */
  void remove_const(
      Identifier name);

  //! Define a module under this module.
  /*! \param name the name of the module.
   *  \return the new class.
   */
  Module define_module(
      char const * name);

  //! Define a class under this module.
  /*! \param name the name of the class.
   *  \param superclass the base class to use.
   *  \return the new class.
   */
  Class define_class(char const * name, Object superclass = rb_cObject);

  //! Define a new data class under this module.
  /*! The class will have a base class of Object.
   *  \param T the C++ type of the wrapped class.
   *  \return the new class.
   */
  template<typename T>
  Data_Type<T> define_class(char const* name);

  //! Define a new data class under this module.
  /*! The class with have a base class determined by Base_T (specifically,
   *  Data_Type<Base_T>::klass).  Therefore, the type Base_T must already
   *  have been registered using define_class<> or define_class_under<>.
   *  \param T the C++ type of the wrapped class.
   *  \return the new class.
   */
  template<typename T, typename Base_T>
  Data_Type<T> define_class(char const * name);

private:
  Derived_T& derived();
  template<typename T>
  Data_Type<T>
  define_class_with_object_as_base(char const * name);
};

} // namespace Rice

#endif // Rice__Module_Mixin__hpp_