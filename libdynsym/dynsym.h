#ifndef DYNSYM_H
#define DYNSYM_H

#include <stdlib.h>

// Return 0 on success, negative on failure.
int ccall(const char *fun_name,
	  void *ret_val, size_t ret_byte_len, ...);
	    

#endif
