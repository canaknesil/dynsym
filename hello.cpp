#include <stdio.h>

extern "C" {
  void print_hello(const char *str)
  {
    printf("Hello, %s!\n", str);
  }
  
  int make_double(int a)
  {
    return a * 2;
  }
}
