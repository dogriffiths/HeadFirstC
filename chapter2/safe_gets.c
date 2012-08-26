#include <stdio.h>

int main()
{
  char line[80];
  fgets(line, 80, stdin);
  printf("Your quote was: %s", line);
  return 0;
}
