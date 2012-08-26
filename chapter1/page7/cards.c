#include <stdio.h>
#include <stdlib.h>
int main()
{
  char card_name[2];
  puts("Enter the card_name: ");
  scanf("%s", card_name);
  int val = 0;
  if (card_name[0] == 'K') {
    val = 10;
  } else if (card_name[0] == 'Q') {
    val = 10;
  } else if (card_name[0] == 'J') {
    val = 10;
  } else if (card_name[0] == 'A') {
    val = 11;
  } else {
    val = atoi(card_name);
  }
  printf("The card value is: %i\n", val);
  return 0;
}
