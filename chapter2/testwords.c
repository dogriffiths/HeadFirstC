#include <stdio.h>

int main()
{
  char line[80];
  char line2[80];
  printf("Big text: ");
  scanf("%79[^\n]%*\n", line);
  /*  scanf("%79[^\n]", line);*/
      printf("Line: %s\n", line);
  printf("Big text2: ");
  scanf("%79[^\n]%*[\n]", line2);
  /*  scanf("%*[ \n\t]%79[^\n]", line2);*/
  /*  scanf("%79[^\n]", line2);*/
  printf("Line: %s\n", line2);
  return 0;
}
