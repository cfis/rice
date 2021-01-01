
template<typename Derived_T>
template<typename Exception_T, typename Functor_T>
inline Derived_T&
Rice::Exception_Mixin<Derived_T>::add_handler(Functor_T functor)
{
  // Create a new exception handler and pass ownership of the current handler to it (they
  // get chained togehter). Then take ownership of the new handler.
  this->handler_ = std::make_shared<detail::Functor_Exception_Handler<Exception_T, Functor_T>>(
    functor, std::move(this->handler_));
  return (Derived_T&)*this;
}

template<typename Derived_T>
inline std::shared_ptr<Rice::detail::Exception_Handler>
Rice::Exception_Mixin<Derived_T>::handler() const
{
  return this->handler_;
}