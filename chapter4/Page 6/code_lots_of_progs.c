 #include <stdio.h>
 '''_______''' total = 0.0;
 '''_______''' count = 0;
 '''_______''' tax_percent = 6;
 '''_______''' add_with_tax(float f)
 {
   '''_______''' tax_rate = 1 + tax_percent / 100'''____''';
   total = total + (f * tax_rate);
   count = count + 1;
   return total;
 }
 int main()
 {
   '''________''' val;
   printf("Price of item: ");
   while (scanf("%f", &val) == 1) {
     printf("Total so far: %.2f\n", add_with_tax(val));
     printf("Price of item: ");
   }
   printf("\nFinal total: %.2f\n", total);
   printf("Number of items: %i\n", count);
   return 0;
 }
 #include <stdio.h>
 '''float''' total = 0.0;
 '''short''' count = 0;
 '''short''' tax_percent = 6;
 '''float''' add_with_tax(float f)
 {
   '''float''' tax_rate = 1 + tax_percent / 100'''.0''';
   total = total + (f * tax_rate);
   count = count + 1;
   return total;
 }
 int main()
 {
   '''float''' val;
   printf("Price of item: ");
   while (scanf("%f", &val) == 1) {
     printf("Total so far: %.2f\n", add_with_tax(val));
     printf("Price of item: ");
   }
   printf("\nFinal total: %.2f\n", total);
   printf("Number of items: %i\n", count);
   return 0;
 }
   float tax_rate = 1 + tax_percent / 100.0;
 1 + tax_percent / 100;
 #include <stdio.h>
 #include <limits.h>
 #include <float.h>
 int main()
 {
   printf("The value of INT_MAX is %i\n", INT_MAX);
   printf("The value of INT_MIN is %i\n", INT_MIN);
   printf("An int takes %li bytes\n", sizeof(int));
   printf("The value of FLT_MAX is %f\n", FLT_MAX);
   printf("The value of FLT_MIN is %.50f\n", FLT_MIN);
   printf("A float takes %li bytes\n", sizeof(float));
   return 0;
 }
 The value of INT_MAX is 2147483647
 The value of INT_MIN is -2147483648
 An int takes 4 bytes
 The value of FLT_MAX is 340282346638528859811704183484516925440.000000
 The value of FLT_MIN is 0.00000000000000000000000000000000000001175494350822
 A float takes 4 bytes
 Q: Why are data typs different on different operating systems? Wouldn't it be less confusing to make them all the same?
 A: C uses different data types of different operating systems and processors because it allows it to make the most out of the hardware.
 Q: In what way?
 A: When C was first created, most machines were 8 bit. Now most machines are 32 or 64 bit. Because C doesn't specify the exact size of its data-types, it's been able to adapt over time. And as newer machines are created C will be able to make the most of them as well.
 Q: What does 8 bit? and 64 bit actually mean?
 A: Technically the bit size of a computer can refer to several things - such as the size of its CPU instructions, or the amount of data the CPU can read from memory. The bit-size is really the favored size of numbers that the computer can deal with.
 Q: So what does that have to do with the size of ints and doubles?
 A: If a computer is optimized best to work with 32 bit numbers, it makes sense if the basic data-type - the int - is set at 32 bits.
 Q: I understand how whole numbers like ints work, but how are floats and numbers stored? How does the computer represent a number with a decimal point?
 A: It's complicated. Most computers used a standard published by the IEEE (http://tinyurl.com/6defkv6).
 Q: Do I really need to understand how floating point numbers work?
 A: No. The vast majority of developers use floats and doubles without worrying about the details.
 #include <stdio.h>
 float total = 0.0;
 short count = 0;
 '''/* This is 6%. Which is a lot less than my agent takes...*/'''
 short tax_percent = 6;
 int main()
 {
   '''/* Hey - I was up for a movie with Val Kilmer */'''
   float val;
   printf("Price of item: ");
   while (scanf("%f", &val) == 1) {
     printf("Total so far: %.2f\n", add_with_tax(val));
     printf("Price of item: ");
   }
   printf("\nFinal total: %.2f\n", total);
   printf("Number of items: %i\n", count);
   return 0;
 }
 float add_with_tax(float f)
 {
   float tax_rate = 1 + tax_percent / 100.0;
   '''/* And what about the tip? Voice lessons ain't free */'''
   total = total + (f * tax_rate);
   count = count + 1;
   return total;
 }
 $ gcc totalling_broken.c -o totalling_broken && ./totalling_broken
 totalling_broken.c: In function ��main��:
 totalling_broken.c:14: warning: format ��%.2f�� expects type ��double��, but argument 2 has type ��int��
 totalling_broken.c: At top level:
 totalling_broken.c:23: error: conflicting types for ��add_with_tax��
 totalling_broken.c:14: error: previous implicit declaration of ��add_with_tax�� was here
    printf("Total so far: %.2f\n", add_with_tax(val));
    float add_with_tax(float f)
 int do_whatever(){...}
 float do_something_fantastic(int awesome_level) {...}
 int do_stuff() {
   do_something_fantastic(11);
 }
 float ping() {
   ...
   pong();
   ...
 }
 float pong() {
   ...
   ping();
   ...
 }
 float add_with_tax();
 float do_something_fantastic();
 double awesomeness_2_dot_0();
 int stinky_pete();
 char make_maguerita(int count);
 #include <stdio.h>
 float add_with_tax(float f);
 #include <stdio.h>
 #include "totaller.h"
 > gcc totaller.c -o totaller
 > ./totalling_fixed
 Price of item: 1.23
 Total so far: 1.30
 Price of item: 4.57
 Total so far: 6.15
 Price of item: 11.92
 Total so far: 18.78
 Price of item: ^D
 Final total: 18.78
 Number of items: 3
 Q: So I don't need to have declarations for int functions?
 A; Not necessaarily - unless you are sharing code. We'll see more about this soon.
 Q: I'm confused. You talk about the compiler ''precompiling''? Why does the ''compiler'' do that?
 A: Strictly speaking the compiler just does the compilation step - it converts the C source code into assembly code. But in a looser sense, all of the stages that convert the C source code into the final executable are normally called ''compilation'', and the <tt>gcc</tt> tool allows you to control those stages. The gcc tool does precompilation ''and'' compilation.
 Q: What is the precompiler?
 A: Precompilation is the first stage i coverting the raw C source code into a working executable. Precompilation creates a modified version of the source just before the ''proper' compilation begins. In our code the precompilation step read the contents of the header file into the main file.
 Q: Does the preompiler create an actual file?
 A: No - compilers normally just use pipes to sending the stuff through the phases of the compiler to make things more efficient.
 Q: Why do some headers have quotes and other have angle brackets?
 A: Quotes mean to simply look for a file using a ''relative'' path. So if you just include the name of a file, without including a directory name, the compiler will look in the current directory. If the thing uses angle brackets it will search for the file along a path of directories.
 Q: What directories will the compiler search when it is looking for header files?
 A: The <tt>gcc</tt> compiler knows where the standard headers are stored. On a Unix-style operating system, the header files are normally in places like <tt>/usr/local/include</tt>, <tt>/usr/include</tt> and a few others.
 Q: So that's how it works for standard headers like <tt>stdio.h</tt>?
 A: Yes. You can read through the <tt>stdio.h</tt> on a Unix-style machine in <tt>/usr/include/stdio.h</tt>. If you have the MingW compiler on Windows, it will probably be in <tt>C:\MingW\include\stdio.h</tt>.
 Q: Can I create my own libraries?
 A: Yes - we'll show you how to do that later in the book.
