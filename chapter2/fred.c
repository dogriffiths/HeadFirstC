/* @(#)fred.c
 */

#include <stdio.h>
#include <string.h>

int main()
{
  char s[][3] = {"AB", "CD"};
  char* t[3] = {"AB", "CD"};
  char **fred = s;
  /*  s[0] = s[1];*/
  if (s == s[0])
    puts("Equal????");
  printf("s at %p\n", s);
  printf("sizeof(s) is %i\n", sizeof(s));
  printf("s[0] at %p\n", s[0]);
  printf("s[1] at %p\n", s[1]);
  printf("s[0] is %s\n", s[0]);
  printf("t at %p\n", t);
  printf("sizeof(t) is %i\n", sizeof(t));
  printf("t[0] at %p\n", t[0]);
  printf("t[1] at %p\n", t[1]);
  printf("t[0] is %s\n", t[0]);
  printf("fred at %p\n", fred);
  printf("sizeof(fred) is %i\n", sizeof(fred));
  printf("fred[0] at %p\n", fred[0]);
  printf("fred[1] at %p\n", fred[1]);
  printf("s[0] char is %s\n", s[0]);
  printf("s[1] char is %s\n", s[1]);
  printf("strlen(s[0]) is %i\n", strlen(s[0]));
  return 0;
}
