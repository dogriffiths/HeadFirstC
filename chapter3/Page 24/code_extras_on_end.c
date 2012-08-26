 #include <stdio.h>
 
 int main()
 {
   char word[10];
   int i = 0;
   while (scanf("%9s", word) == 1) {
     i = i + 1;
     if (i % 2)
       fprintf(stdout, "%s\n", word);
     else
       fprintf(stderr, "%s\n", word);
   }
   return 0;
 }
 Run with:
 secret_messages < secret.txt > message1.txt 2> message2.txt
 THE
 SUBMARINE
 WILL
 SURFACE
 AT
 NINE
 PM
 BUY
 SIX
 EGGS
 AND
 SOME
 MILK
