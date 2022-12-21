#include <stdio.h>

void fun(int);

void fun1();
void fun2();
void wrapper(void (*fun)());

int main()
{

  // fun_ptr is a pointer to function fun()
  void (*fun_ptr)(int) = &fun;
  // void (*fun_ptr)(int) = fun;

  /*
  The above line is equivalent of following two:
  void (*fun_ptr)(int);
  fun_ptr = &fun;
  */

  // Invoking fun() using fun_ptr
  (*fun_ptr)(10);
  printf("%llu\n", sizeof(*fun_ptr));

  wrapper(fun1);
  wrapper(fun2);

  return 0;
}

void fun(int a)
{
  printf("Value : %d\n", a);
}

void fun1()
{
  printf("Fun 1\n");
}
void fun2()
{
  printf("Fun 2\n");
}
void wrapper(void (*fun)())
{
  printf("Wrapper\n");
  fun();
}