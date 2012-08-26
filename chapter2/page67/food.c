#include <stdio.h>

int main()
{
    char food[5];
    printf("Enter favorite food: ");
    fgets(food, sizeof(food), stdin);
    printf("Favorite food: %s", food);
    return 0;
}
