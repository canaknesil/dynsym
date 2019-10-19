#include <assert.h>
#include <stdint.h>
#include "libdynsym/dynsym.h"

int main()
{
  ccall("print_hello", NULL, 0);
  
  // f4 = find_function("make_double");
  // int a = f4(-1);
  // printf("%d\n", a);
  // 
  // f4 = find_function("printf");
  // f4("%s %d\n", "This is a number: ", 5);

  return 0;
}
