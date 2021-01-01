#ifndef Rice__Exception_Mixin_defn_hpp_
#define Rice__Exception_Mixin_defn_hpp_

#include "detail/Exception_Handler_defn.hpp"

namespace Rice
{

  template <typename Derived_T>
  class Exception_Mixin
  {
  public:
    template<typename Exception_T, typename Functor_T>

    //! Define an exception handler.
    /*! Whenever an exception of type Exception_T is thrown from a
     *  function defined on this class, functor will be called to
     *  translate the exception into a ruby exception.
     *  \param Exception_T a template parameter indicating the type of
     *  exception to be translated.
     *  \param functor a functor to be called to translate the exception
     *  into a ruby exception.  This functor should re-throw the exception
     *  as an Exception.
     *  Example:
     *  \code
     *    class MyException : public std::exception { };
     *    Data_Type<MyException> rb_cMyException;
     *    Class rb_cFoo;
     *
     *    void translate_my_exception(MyException const & ex)
     *    {
     *      Data_Object<MyException> ex_(
     *          new MyException(ex),
     *          rb_cMyException);
     *      throw Exception(ex_);
     *    }
     *
     *    extern "C"
     *    void Init_MyExtension()
     *    {
     *      rb_cMyException = define_class("MyException");
     *      rb_cFoo = define_class("Foo")
     *        .add_handler<MyException>(translate_my_exception);
     *    }
     *  \endcode
     */
    Derived_T& add_handler(Functor_T functor);
    std::shared_ptr<detail::Exception_Handler> handler() const;

  private:
    mutable std::shared_ptr<detail::Exception_Handler> handler_;
  };

}
#endif // Rice__Exception_Mixin__hpp_
