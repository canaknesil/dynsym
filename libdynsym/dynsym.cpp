#include "dynsym.h"
#include <dlfcn.h>

void * find_function(const char *fun_name)
{
  void *f = dlsym(RTLD_DEFAULT, fun_name);
  return f;
}


