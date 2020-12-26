#ifndef Rice__detail__Auto_Constructor_Wrapper__hpp_
#define Rice__detail__Auto_Constructor_Wrapper__hpp_

#include "Exception_Handler_defn.hpp"

namespace Rice
{

namespace detail
{

template<typename Func_T, typename Ret_T, typename... Arg_Ts>
class Auto_Function_Self_Wrapper
  : public Wrapped_Function
{
public:
  Auto_Function_Self_Wrapper(
      Func_T func,
      Data_Object<Exception_Handler> handler,
      Arguments* arguments = 0);

  static VALUE call(int argc, VALUE* args, VALUE self);

private:
  Func_T func_;
};

} // namespace detail

} // namespace Rice

#include "Auto_Function_Self_Wrapper.ipp"

#endif // Rice__detail__Auto_Constructor_Wrapper__hpp_

