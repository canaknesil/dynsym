// Template code

#ifndef DYNSYM_TEMPLATE_H
#define DYNSYM_TEMPLATE_H

#include <cstddef>
#include <iostream>

void * find_function(const char *fun_name);

template<typename R, typename... Args>
  void call_fn(R (*fn)(Args...), R *ret_val, Args... args)
{
  *ret_val = fn(args...);
}

template<typename... Args>
void call_fn(void (*fn)(Args...), void *ret_val, Args... args)
{
  fn(args...);
}

// Return 0 on success, negative on failure.
template<typename R, typename... Args>
  int ccall(const char *fun_name, R *ret_val, Args... args)
{
  R (*fn)(Args...);

  fn = (R (*)(Args...)) find_function(fun_name);
  if (!fn) return -1;

  call_fn(fn, ret_val, args...);
  
  return 0;
}
	    

#endif
