#include <stdio.h>

int main()
{
  char food[50];
  char food2[50];
  printf("Enter favorite food: ");
    scanf("%s", food);
    scanf("%s", food2);
    /*  fgets(food, sizeof(food), stdin);*/
  printf("Favorite food: %s and length = %i\n", food, sizeof(food));
  printf("Favorite food2: %s and length = %i\n", food2, sizeof(food2));
  printf("And the mad value is %li\n", food * 2);
  return 0;
}
