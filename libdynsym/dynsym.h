// Interface

#ifndef DYNSYM_H
#define DYNSYM_H

#include "dynsym-template.h"

// Return 0 on success, negative on failure.
template<typename R, typename... Args>
  int ccall(const char *fun_name, R *ret_val, Args... args);


#endif
