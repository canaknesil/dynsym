#include "dynsym.h"
#include <dlfcn.h>
#include <stdio.h>
#include <stdint.h>

void * find_function(const char *fun_name)
{
  void *f = dlsym(RTLD_DEFAULT, fun_name);
  return f;
}

int ccall(const char *fun_name,
	  void *ret_val, size_t ret_byte_len, ...)
{
  void *fn;

  fn = find_function(fun_name);
  if (!fn) return -1;

  if (ret_byte_len == 0)
    ((void (*)()) fn)(2, 3);
  else if (ret_byte_len == 4)
    *((uint32_t *) ret_val) = ((uint32_t (*)()) fn)(2, 3);
  else
    return -1;
  
  return 0;
}
