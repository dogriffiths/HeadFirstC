#include <stdio.h>

char * get_message() {
  char * msg = "Aren't pointers fun?";
  printf("msg address = %p\n", msg);
  return msg;
}

int main() {
  char * string = get_message();
  printf("Address = %p\n", string);
  printf("Address = %p\n", "Aren't pointers fun?");
  char * s0 = "Aren't pointers fun?";
  char s1[] = "Aren't pointers fun?";
  if (s0 == "Aren't pointers fun?") {
    puts("The C compiler reused the string");
  }
  if (s1 == "Aren't pointers fun?") {
    puts("The C compiler reused the string in an array - I DON'T BELIEVE IT!");
  }
  puts(string);
  return 0;
}
