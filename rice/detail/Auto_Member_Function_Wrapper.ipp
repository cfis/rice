#ifndef Rice__detail__Auto_Member_Function_Wrapper__ipp_
#define Rice__detail__Auto_Member_Function_Wrapper__ipp_

#include "method_data.hpp"
#include "../ruby_try_catch.hpp"
#include "../to_from_ruby.hpp"
#include <typeinfo>
namespace Rice
{

namespace detail
{

template<typename Func_T, typename Ret_T, typename Self_T, typename... Arg_Ts>
Auto_Member_Function_Wrapper<Func_T, Ret_T, Self_T, Arg_Ts...>::
Auto_Member_Function_Wrapper(
    Func_T func,
    Data_Object<Exception_Handler> handler,
    Arguments* arguments)
  : Wrapped_Function(RUBY_METHOD_FUNC(call), sizeof...(Arg_Ts), arguments, handler)
  , func_(func)
{
}

template<typename Func_T, typename Ret_T, typename Self_T, typename... Arg_Ts>
VALUE Auto_Member_Function_Wrapper<Func_T, Ret_T, Self_T, Arg_Ts...>::
call(int argc, VALUE* argv, VALUE self)
{
  Data_Object<Wrapped_Function> data(detail::method_data());
  Auto_Member_Function_Wrapper<Func_T, Ret_T, Self_T, Arg_Ts...>* wrapper = (Auto_Member_Function_Wrapper<Func_T, Ret_T, Self_T, Arg_Ts...>*)data.get();

  try
  {
    // Get the ruby values
    std::vector<VALUE> rubyValues = wrapper->getRubyValues<sizeof...(Arg_Ts)>(argc, argv);

    // Now convert the Ruby values to native values
    auto indices = std::make_index_sequence<sizeof...(Arg_Ts)>{};
    std::tuple<Arg_Ts...> nativeValues = wrapper->getNativeValues<Arg_Ts...>(rubyValues, indices);

    // We need to add self to the start of the tuple list
    Self_T* obj = from_ruby<Self_T*>(self);
    auto selfNativeValues = std::tuple_cat(std::tuple(obj), nativeValues);

    // Finally call the native function
    if constexpr (std::is_void_v<Ret_T>)
    {
      std::apply(wrapper->func_, selfNativeValues);
      return Qnil;
    }
    else
    {
      Ret_T result = std::apply(wrapper->func_, selfNativeValues);
      return to_ruby(result);
    }
  }
  catch(...)
  {
    RUBY_TRY
    {
      if(wrapper)
      {
        return wrapper->handleException();
      }
      else
      {
        throw;
      }
    }
    RUBY_CATCH
  }
}

} // namespace detail

} // namespace Rice


#endif // Rice__detail__Auto_Member_Function_Wrapper__ipp_

