#include <stdio.h>

int main()
{
  int contestants[] = {1, 2, 3};
  int choice = contestants[0];
  contestants[0] = 2;
  contestants[1] = contestants[2];
  contestants[2] = choice;
  choice = contestants[1];
  printf("I'm going to pick contestant number %i\n", choice);
  return 0;
}
