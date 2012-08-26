 auto
 if
 break
 int
 case
 long
 char
 register
 continue
 return
 default
 short
 do
 sizeof
 double
 static
 else
 struct
 entry
 switch
 extern
 typedef
 float
 union
 for
 unsigned
 goto
 while
 enum
 void
 const
 signed
 volatile
 Read a series of strings from the standard input and display and encrypted version on the standard output using XOR encryption.
 Read the contents of a file and create an encrypted version using XOR encryption.
 void encrypt(char* message)
 {
   char c;
   while (*message) {
     *message = *message ^ 17;
     message++;
   }
 }
 movq	-24(%rbp), %rax
 movzbl	(%rax), %eax
 movl	%eax, %edx
 10010101 00100101 11010101 01011100 11001010 01100010 01100101
 void encrypt(char* message);
 #include "encrypt.h"
 void encrypt(char* message)
 {
   char c;
   while (*message) {
     *message = *message ^ 17;
     message++;
   }
 }
 #include <stdio.h>
 #include "encrypt.h"
 int main()
 {
   char msg[80];
   while (fgets(msg, 79, stdin)) {
     encrypt(msg);
     printf("%s", msg);
   }
 }
 gcc message_hider.c encrypt.c -o message_hider
 extern int passcode;
