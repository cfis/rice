#include "../Data_Type_defn.hpp"


inline
VALUE
Rice::detail::Default_Exception_Handler::
handle_exception() const
{
  throw;
}

template <typename Exception_T, typename Functor_T>
inline
Rice::detail::Functor_Exception_Handler<Exception_T, Functor_T>::
Functor_Exception_Handler(
    Functor_T handler,
    std::shared_ptr<Exception_Handler> next_exception_handler)
  : next_exception_handler_(next_exception_handler)
  , handler_(handler)
{
}

template <typename Exception_T, typename Functor_T>
Rice::detail::Functor_Exception_Handler<Exception_T, Functor_T>::
Functor_Exception_Handler(const Functor_Exception_Handler<Exception_T, Functor_T>& other)
  : next_exception_handler_(other.next_exception_handler_->clone())
{
}

template <typename Exception_T, typename Functor_T>
inline
VALUE
Rice::detail::Functor_Exception_Handler<Exception_T, Functor_T>::
handle_exception() const
{
  try
  {
    return this->next_exception_handler_->handle_exception();
  }
  catch(Exception_T const & ex)
  {
    handler_(ex);
    throw;
  }
}