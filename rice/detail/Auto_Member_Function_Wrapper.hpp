#ifndef Rice__detail__Auto_Member_Function_Wrapper__hpp_
#define Rice__detail__Auto_Member_Function_Wrapper__hpp_

namespace Rice
{

namespace detail
{

template<typename Func_T, typename Ret_T, typename Self_T, typename... Arg_Ts>
class Auto_Member_Function_Wrapper
  : public Wrapped_Function
{
public:
  Auto_Member_Function_Wrapper(
      Func_T func,
      Data_Object<Exception_Handler> handler,
      Arguments* arguments = 0);

  static VALUE call(int argc, VALUE* argv, VALUE self);

private:
  Func_T func_;
};

} // namespace detail

} // namespace Rice

#include "Auto_Member_Function_Wrapper.ipp"

#endif // Rice__detail__Auto_Member_Function_Wrapper__hpp_

