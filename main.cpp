#include <assert.h>
#include <stdint.h>
#include <iostream>
#include "libdynsym/dynsym.h"

using namespace std;

void ccall_error()
{
  cout << "ccall unsuccessfull." << endl;
  exit(-1);
}

int main()
{
  int ret;

  ret = ccall("print_hello", (void *) nullptr, "Can");
  if (ret < 0)
    ccall_error();

  int a;
  ret = ccall("make_double", &a, 3);
  if (ret < 0)
    ccall_error();
  cout << a << endl;

  ret = ccall("printf", (void *) nullptr,
	      "Printing this number: %d\n", 4);
  if (ret < 0)
    ccall_error();
      
  return 0;
}
