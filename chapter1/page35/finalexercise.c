/**
 * THIS PROGRAM IS DIFFERENT TO THE ONE IN THE BOOK!
 * 
 * We all make mistakes. After the book was published, one keen-eyed
 * spotted that there was a problem with the program published on 
 * page 35/37 in the book.
 *
 * In the original version of the program the while loop
 * checked the value of the card_name[0] *before* anything
 * had been entered into the card_name array. What's the problem 
 * with that? In C, local variables are not set to any specific
 * value when they're first created. That means that
 * that theoretically the card_name[0] might have *any* char
 * value. And that's bad.
 *
 * Instead, we've slightly re-written the code so that instead of 
 * using a while{} loop, it now uses a do-while{} loop.
 *
 * A do-while{} loop checks the lopp condition at the *end* of the
 * loop, and by the time we get to the end of the loop the
 * card_name array has been set to whatever the typed in at the keyboard.
 *
 * The coder responsible for this error has been warned that a
 * terrible vengeance that will be wrought against them.
 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
    char card_name[2];
    int count = 0;
    do {
        puts("Enter the card_name: ");
        scanf("%s", card_name);
        int val = 0;
        switch(card_name[0]) {
        case 'K':
        case 'Q':
        case 'J':
            val = 10;
            break;
        case 'A':
            val = 11;
            break;
        case 'X':
            continue;
        default:
            val = atoi(card_name);
            if ((val < 1) || (val > 10)) {
                puts("I don't understand that value!");
                continue;
            }
        }
        if ((val > 2) && (val < 7)) {
            count++;
        } else if (val == 10) {
            count--;
        }
        printf("Current count: %i\n", count);
    } while (card_name[0] != 'X');
    return 0;
}
