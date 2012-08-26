#include <stdio.h>
#include <limits.h>

#define DAYS_OF_THE_WEEK 7

#define ADD_ONE(x) ((x) + 1)

#define ADD_ITSELF(a) ((a) + (a))
#ifdef SPANISH
char *greeting = "Hola";
#else
char *greeting = "Hello";
#endif

int counter()
{
  static int count = 0;
  return ++count;
}

int main()
{
  char *s, t;
  s = "HELLO";
  t = 'a';
  printf("There are %i days of the week\n", DAYS_OF_THE_WEEK);
  printf("The answer is %i\n", ADD_ONE(3));
  int i = 2;
  printf("The answer is %i\n", ADD_ITSELF(++i));
  printf("Say '%s'\n", greeting);
  printf("Count = %i\n", counter());
  printf("Count = %i\n", counter());
   printf("On this machine an int takes up %lu bytes\n", sizeof(int));
   printf("And ints can store values from %i to %i\n", INT_MIN, INT_MAX);
   printf("And shorts can store values from %i to %i\n", SHRT_MIN, SHRT_MAX);
   return 0;
}
