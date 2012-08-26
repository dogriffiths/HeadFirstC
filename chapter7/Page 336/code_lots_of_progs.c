 #include <stdarg.h>
 void print_ints(int args, ...)
 {
   va_list ap;
   va_start(ap, args);
   int i;
   for (i = 0; i < args; i++) {
     printf("argument: %i\n", va_arg(ap, int));
   }
   va_end(ap);
 }
 void encrypt(char* message);
 #include "encrypt.h"
 void encrypt(char* message)
 {
   while (*message) {
     *message *message ^ 31;
     message++;
   }
 }
 int checksum(char* message);
 #include "checksum.h"
 int checksum(char* message)
 {
   int c = 0;
   while (*message) {
     c += c ^ (int)(*message);
     message++;
   }
   return c;
 }
                              +----------------------------------------------+
                              |                                              |
                              |                  THE FIRST-                  |
                              |                                              |
                              |                 BANK OF-                     |
                              |                                              |
                              |                 HEAD FIRST-                  |
                              |                                              |
                              +--------------------+----+--------------------+
                                                   |    |
                     +-----------------------------+----+-------------------------------+
                     |    Safer than keeping your cash at home. Probably.-              |
                     |                                                                  |
                     +-----------------------------+----+-------------------------------+
                                                   |    |
                              +--------------------+----+-------------------+
                              |   3 days of security-problem free-          |
                              |   banking                                   |
                              +--------------------+----+-------------------+
                                                   |    |
                                                   |    |
                                                   |    |
                                                   +----+
 gcc -c encrypt.c -o encrypt.o
 gcc -c checksum.c -o checksum.o
 #include <stdio.h>
 #include <encrypt.h>
 #include <checksum.h>
 int main()
 {
   char s[] = "Speak friend and enter";
   encrypt(s);
   printf("Encrypted to '%s'\n", s);
   printf("Checksum is %i\n", checksum(s));
   encrypt(s);
   printf("Decrypted back to '%s'\n", s);
   printf("Checksum is %i\n", checksum(s));
   return 0;
 }
 > gcc test_code.c encrypt.o checksum.o -o test_code
 test_code.c:2:21: error: encrypt.h: No such file or directory
 test_code.c:3:22: error: checksum.h: No such file or directory
 >
 #include <stdio.h>
 #include <encrypt.h>
 #include <checksum.h>
 int main()
 {
   char s[] = "Speak friend and enter";
   encrypt(s);
   printf("Encrypted to '%s'\n", s);
   printf("Checksum is %i\n", checksum(s));
   encrypt(s);
   printf("Decrypted back to '%s'\n", s);
   printf("Checksum is %i\n", checksum(s));
   return 0;
 }
 #include <stdio.h>
 #include "encrypt.h"
 #include "checksum.h"
 > gcc test_code.c encrypt.o checksum.o -o test_code
 > ./test_code
 Encrypted to 'Loz~t?ymvzq{?~q{?zqkzm'
 Checksum is 89561741
 Decrypted back to 'Speak friend and enter'
 Checksum is 89548156
 >
 /usr/local/include
 /usr/include
 C:\MinGW\include
 #include <encrypt.h>
 / Root directory
 |
 +- my_header_files
    |
    +- encrypt.o
    |
    +- checksum.o
 #include "/my_header_files/encrypt.h"
 gcc -I/my_header_files test_code.c ... -o test_code
 / Root directory
 |
 +- my_object_files
    |
    +- encrypt.o
    |
    +- checksum.o
 gcc -I/my_header_files test_code.c /my_object_files/encrypt.o /my_object_files/checksum.o -o test_code
 $ nm libl.a
 libl.a(libmain.o):
 00000000000003a8 s EH_frame0
                  U _exit
 0000000000000000 T _main
 00000000000003c0 S _main.eh
                  U _yylex
 libl.a(libyywrap.o):
 0000000000000350 s EH_frame0
 0000000000000000 T _yywrap
 0000000000000368 S _yywrap.eh
 $
                                                   libl.a
               +-------------------------------------------------------------------------------------+
               |                                                                                     |
               |   +-------------------------------+      +--------------------------------------+   |
               |   |                               |      |                                      |   |
               |   |                               |      |                                      |   |
               |   |                               |      |                                      |   |
               |   |                               |      |                                      |   |
               |   |                               |      |                                      |   |
               |   |      libmain.o                |      |              libyywrap.o             |   |
               |   |                               |      |                                      |   |
               |   |                               |      |                                      |   |
               |   |                               |      |                                      |   |
               |   |                               |      |                                      |   |
               |   |                               |      |                                      |   |
               |   |                               |      |                                      |   |
               |   |                               |      |                                      |   |
               |   +-------------------------------+      +--------------------------------------+   |
               |                                                                                     |
               +-------------------------------------------------------------------------------------+
 0000000000000000 T _yywrap
 ar -rcs libhfsecurity.a encrypt.o checksum.o
 gcc test_code.c -lhfsecurity -o test_code
 gcc test_code.c -L/my_lib -lhfsecurity -o test_code
 #include <encrypt.h>
 #include <checksum.h>
 encrypt.o: encrypt.c
 	gcc _____ encrypt.c -o encrypt.o
 
 checksum.o: checksum.c
 	gcc _____ checksum.c -o checksum.o
 
 libhfsecurity.a: encrypt.o _______________
 	ar -rcs ___________________ encrypt.o ____________
 
 bank_vault: bank_vault.c _________________
 	gcc ______________ -I__________ -L__________ ________________ -o bank_vault
 bank_vault.c
 .
 .
 -lhfsecurity
 libhfsecurity.a
 checksum.o
 checksum.o
 libhfsecurity.a
 -c
 -c
 /usr/lib
 /usr/local/include
 /usr/local/lib
 -rcs
 -rcs
 #include <encrypt.h>
 #include <checksum.h>
 encrypt.o: encrypt.c
 	gcc -c encrypt.c -o encrypt.o
 
 checksum.o: checksum.c
 	gcc -c checksum.c -o checksum.o
 
 libhfsecurity.a: encrypt.o checksum.o
 	ar -rcs libhfsecurity.a encrypt.o checksum.o
 
 bank_vault: bank_vault.c libhfsecurity.a
 	gcc bank_vault.c -I. -L. -lhfsecurity -o bank_vault
 /usr/lib
 /usr/local/include
 /usr/local/lib
 -rcs
 -rcs
 Q: How do I know what the standard library directories are on my machine?
 A: You need to check the documentation for your compiler. On most Unix-style machines, the library directories include /usr/lib and /usr/local/lib.
 Q: When I try to put a library archive into my /usr/lib directory it won't let me. Why is that?
 A: Almost certainly security. Many operating systems will prevent you writing files to the standard directories in case you accidentally break one of the existing libraries.
 Q: Is the ar format the same on all systems?
 A: No. Different platforms can have slightly different archive formats. And the object code the archive contains will be completely different for different operating systems.
 Q: If I've created a library archive, can I see what's inside it?
 A: Yes. "ar -t <filename>" will list the contents of the archive.
 Q: Are the object files in the archive linked together like an executable?
 A: No. The object files are stored in the archive as distinct files. 
 Q: Can I put any kind of file in a library archive?
 A: No. The "ar" command will check the file type before including it.
 Q: Can I extract a single object file from an archive?
 A: Yes. To extract the encrypt.o file from libhfsecurity.a use "ar -x libhfsecurity.a encrypt.o"
 Q: Why is static linking called "static" linking?
 A: Because it can't change once it's been done. When two files are linked together statically, it's like mixing coffee with milk - you can't separate them afterwards.
 Q: Should I use the HF Security library to secure the data at my bank?
 A: That is probably not a good idea.
 HF: Linker - thank you so much for making time for us today.
 Linker: It's a pleasure.
 HF: I'd like to begin by asking if you ever feel overlooked by developers? They perhaps don't understand exactly what it is you do?
 Linker: I'm a very quiet person. A lot of people don't talk to me directly with the "ld" command.
 HF: ld?
 Linker: Yes - that's my name. Type in "ld --help" at the command line.
 HF: ld.
 Linker: Yes? See - that's me.
 HF: That's a lot of options on my screen.
 Linker: Exactly. I have a lot of options. A lot of ways of joining programs together. That's why some people just use the gcc command.
 HF: So the compiler can link files together?
 Linker: The compiler works out what needs to be done to join some files together and then calls me. And I do it. Quietly. You'd never know I was there.
 HF: I do have another question... 
 Linker:Yes?
 HF:I hate to sound foolish, but what exactly is it you do?
 Linker:That's not a foolish question. I stitch pieces of compiled code together. It's like a carburettor.
 HF: I don't follow.
 Linker: A carburettor has leads coming out of it that need to be plugged into some places in the engine so the two can talk. An object file is like that.
 HF: How so? 
 Linker: An object file might need to call a function that's stored in some other file. I link together the point in one file where the function call is made to the point in another file where the function lives.
 HF: You must have a lot of patience.
 Linker: It is. I like that kind of thing. I make lace in my spare time.
 HF: Really?
 Linker: No.
 HF: Linker - thank you.
 #include <stdio.h>
 #include <hfcal.h>
 
 void display_calories(float weight, float distance, float coeff)
 {
   printf("Weight: %3.2f lbs\n", weight);
   printf("Distance: %3.2f miles\n", distance);
   printf("Calories burned: %4.2f cal\n", coeff * weight * distance);
 }
 #include <stdio.h>
 #include <hfcal.h>
 
 int main()
 {
   display_calories(115.2, 11.3, 0.79);
   return 0;
 }
 Weight: 115.20 lbs
 Distance: 11.30 miles
 Calories burned: 1028.39 cal
 _______________________________________________
 _______________________________________________
 _______________________________________________
 _______________________________________________
 gcc -I/includes -c hfcal.c -o hfcal.o
 gcc -I/includes -c elliptical.c -o elliptical.o
 ar -rcs /libs/libhfcal.a hfcal.o
 gcc elliptical.o -L/libs -lhfcal -o elliptical
 > ./elliptical 
 Weight: 115.20 lbs
 Distance: 11.30 miles
 Calories burned: 1028.39 cal
 > 
 Weight: 52.25 kg
 Distance: 18.19 km
 Calories burned: 750.72 cal
 gcc -I/includes -fPIC -c hfcal.c -o hfcal.o
                           C:\libs\hfcal.dll
 
                           /libs/libhfcal.dll.a
 gcc -shared hfcal.o -o 
                           /libs/libhfcal.so
 
                           /libs/libhfcal.dylib
 gcc -I\include -c elliptical.c -o elliptical.o
 gcc elliptical.o -L\libs -lhfcal -o elliptical
 $ ./elliptical
 Weight: 115.20 lbs
 Distance: 11.30 miles
 Calories burned: 1028.39 cal
 $ 
 $ export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/libs
 $ ./elliptical
 Weight: 115.20 lbs
 Distance: 11.30 miles
 Calories burned: 1028.39 cal
 $
 $ PATH="$PATH:/libs"
 $ ./elliptical
 Weight: 115.20 lbs
 Distance: 11.30 miles
 Calories burned: 1028.39 cal
 $
 C:\code> PATH="%PATH%:C:\libs"
 C:\code> ./elliptical
 Weight: 115.20 lbs
 Distance: 11.30 miles
 Calories burned: 1028.39 cal
 C:\code>
 (Directory)common-lisp
 (Directory)python2.7
 (Directory)python4.2
 (Directory)site_ruby
 libfluxcap.a
 libfluxcap.la
 libhfcal.so
 libmrfusion.so
 ...
 (Directory)python2.7
 (Directory)python4.2
 fluxcap.h
 hfcal.h
 mrfusion.h
 bwanalyze.h
 ...
 #include <stdio.h>
 #include <hfcal.h>
 
 void display_calories(float weight, float distance, float coeff)
 {
   printf("Weight: %3.2f kg\n", weight / 2.2046);
   printf("Distance: %3.2f km\n", distance * 1.609344);
   printf("Calories burned: %4.2f cal\n", coeff * weight * distance);
 }
 __________________________________________________
 __________________________________________________
 __________________________________________________
 __________________________________________________
 __________________________________________________
 #include <stdio.h>
 #include <hfcal.h>
 
 void display_calories(float weight, float distance, float coeff)
 {
   printf("Weight: %3.2f kg\n", weight / 2.2046);
   printf("Distance: %3.2f km\n", distance * 1.609344);
   printf("Calories burned: %4.2f cal\n", coeff * weight * distance);
 }
 gcc -c -fPIC hfcal_UK.c -o hfcal.o
 gcc -shared hfcal.o -o /usr/local/lib/libhfcal.so
 /opt/apps/treadmill
 Weight: 117.40 lbs
 Distance: 9.40 miles
 Calories burned: 750.42 cal
 Weight: 53.25 kg
 Distance: 15.13 km
 Calories burned: 750.42 cal
 Q: Why are dynamic libraries so different on different operating systems?
 A: Operating systems like to optimize the way they load dynamic libraries so they've each evolved different requirements for dynamic libraries.
 Q: I tried to change the name of my library by renaming the file but the compiler couldn't find it any more. Why not?
 A: When the compiler creates a dynamic library it stores the name of the library inside the file. If you rename the file, it will then have the wrong name inside the file and the compiler will get confused. If you want to change its name, you should recompile the library.
 Q: Why does Cygwin support so many different naming conventions for dynamic library files?
 A: Cygwin makes it easy to compile Unix software on a Windows machine. Because Cygwin creates a Unix-style environment, it borrows a lot of Unix-conventions. So it prefers to give libraries .a extensions, even if they're dynamic DLLs.
 Q: Are Cygwin dynamic libraries real DLLs?
 A: Yes. But because they depend on the Cygwin system, you'll need to do a little work before non-Cygwin code can use them.
 Q: Why does the MinGW compiler support the same dynamic library name format as Cygwin?
 A: Because the two projects are closely associated and share a lot of code. The big difference is that MinGW programs can run on machines that don't have Cygwin installed.
 Q: Why doesn't Linux just store library path-names in executables? That way you wouldn't need to set LD_LIBRARY_PATH.
 A: It was a design choice. By '''not''' storing the path name, it means you have a lot more control over which version of a library a program can use. Which is great when you're developing new libraries.
 Q: Why doesn't Cygwin use LD_LIBRARY_PATH to find libraries?
 A: Because it needs to use Windows DLLs. Windows DLLs are loaded using the PATH variable.
 Q: Which is better? Static or dynamic linking?
 A: It depends. Static linking means you get a small, fast executable file that is easier to move from machine to machine. Dynamic linking means that you can configure the program at runtime more.
 Q: If different programs use the same dynamic library, does it get loaded more than once? Or is it shared in memory?
 A: That's down to the operating system. Some operating systems will load separate copies for each process. Others load shared copies to save memory.
 system("dir D:");
 system("gedit");
 system("say 'End of line'");
 #include <stdio.h>
 #include <time.h>
 char* now()
 {
   time_t t;
   time (&t);
   return asctime(localtime (&t));
 }
 /* Master Control Program utility.
    Records guard patrol check-ins. */
 int main()
 {
   char comment[80];
   char cmd[120];
   ______(_________, ____, _______);
   __________(__________,
          ________________________________,
          __________, ________);
   system(cmd);
   return 0;
 }
 "echo '%s %s' >> reports.log"
 comment
 now()
 cmd
 sprintf
 fgets
 comment
 80
 stdin
 120
 stdout
 printf
 scanf
 #include <stdio.h>
 #include <time.h>
 char* now()
 {
   time_t t;
   time (&t);
   return asctime(localtime (&t));
 }
 /* Master Control Program utility.
    Records guard patrol check-ins. */
 int main()
 {
   char comment[80];
   char cmd[120];
   fgets(comment, 80, stdin);
   sprintf(cmd,
           "echo '%s %s' >> reports.log",
           comment, now());
   system(cmd);
  return 0;
 }
 120
 stdout
 printf
 scanf
 > gcc guard_log.c -o guard_log
 > ./guard_log
 Checked in Crom - a compound interest program.
 > ./guard_log
 Blue Leader reports breach in jet walls.
 >
 Checked in Crom - a compound interest program.
  Thu Oct 29 11:25:53 2015
 Blue Leader reports breach in jet walls.
  Thu Oct 29 11:26:06 2015
 Q: So does the system() function get compiled into my program?
 A: No. The system() function -- like all system calls -- ''doesn't'' live in your program. It lives in the main operating system.
 Q: So when I make a system call, I'm making a call to some external piece of code, like a library?
 A: Kind of. But the details depends upon the operating system. On some operating systems the code for a system call lives inside the ''kernel'' of the operating system. On some other operating systems it might simply be stored in some dynamic library.
 |--------+-----------+---+-------------+----------------|
 | echo ' | <comment> |   | <timestamp> |' >> reports.log |
 |--------+-----------+---+-------------+----------------|
 |--------+---------------------+---+-------------+------------------|
 | echo ' | ' && ls / && echo ' |   | <timestamp> | ' >> reports.log |
 |--------+---------------------+---+-------------+------------------|
 > ./guard_log
 ' && ls / && echo '
 Applications            System   dev          private
 Developer               Users    etc          sbin
 Library                 Volumes  home         tmp
 Network                 bin      mach_kernel  usr
 Space Paranoids Source  cores    net          var
 >
 execl("/home/flynn/clu", "/home/flynn/clu", "paranoids", "contract", NULL)
 execlp("clu", "clu", "paranoids", "contract", NULL)
 execle("/home/flynn/clu", "/home/flynn/clu", "paranoids", "contract", NULL, env_vars)
 execv("/home/flynn/clu", my_args);
 execvp("clu", my_args)
 #include <stdio.h>
 #include <stdlib.h>
 int main(int argc, char* argv[])
 {
   printf("Diners: %s\n", argv[1]);
   printf("Juice: %s\n", getenv("JUICE"));
   return 0;
 }
 char* my_env[] = {"JUICE=peach and apple", NULL};
 execle("diner_info", "diner_info", "4", NULL, my_env);
 > ./my_exec_program
 Diners: 4
 Juice: peach and apple
 >
 execle("diner_info", "diner_info", "4", NULL, my_env);
 puts("Dude - the diner_info code must be busted");
 * <s>Release an acoustic album</s>
 * Tidy up as much as you can
 * Set the errno variable to an error value
 * Return -1
 |------------+---------------------------|
 | EPERM=1    | Operation not permitted   |
 | ENOENT=2   | No such file or directory |
 | ESRCH=3    | No such process           |
 | EMULLET=81 | Bad haircut               |
 | ...        |                           |
 |------------+---------------------------|
 puts(strerror(errno));
 No such file or directory
 #include <stdio.h>
 _____________________
 _____________________
 _____________________
 int main()
 {
   if (________________________________________________________)
     if (execlp(_________________________________________________) {
       fprintf(stderr, "Cannot run ipconfig: %s", __________________);
       return 1;
     }
   return 0;
 }
 #include <stdio.h>
 #include <unistd.h>
 #include <errno.h>
 #include <string.h>
 int main()
 {
   if (execl("/sbin/ifconfig", "/sbin/ifconfig", NULL) == -1)
     if (execlp("ipconfig", "ipconfig", NULL) == -1) {
       fprintf(stderr, "Cannot run ipconfig: %s", strerror(errno));
       return 1;
     }
   return 0;
 }
 Q: Isn't system() just easier to use than exec()?
 A: Yes. But because the operating system needs to interpret the string you pass to system(), it can be a buggy. Particularly if you create the command string dynamically.
 Q: Why are there so many exec() functions?
 A: Over time people wanted to create processes in different ways. The different versions of exec() were created because people need them.
 Q: Do I always have to check the return value of a system call? Doesn't it make the program really long?
 A: If you make system calls and don't check for errors, your code will be shorter. But it will probably also have more bugs. It is better to think about errors when you first write code. It will make it '''much''' easier to catch bugs later on.
 Q: If I run an exec() command, can I do anything afterwards?
 A: No. The exec() command will change the process so that it runs the new program instead of your program. That means the program containing the exec() call will stop as soon as it runs the exec() function.
 #include <stdio.h>
 #include <stdlib.h>
 int main(int argc, char* argv[])
 {
   char* w = getenv("EXTRA");
   if (!w)
     w = getenv("FOOD");
   if (!w)
     w = argv[argc - 1];
   char* c = getenv("EXTRA");
   if (!c)
     c = argv[argc - 1];
   printf("%s with %s\n", c, w);
   return 0;
 }
  int main(int argc, char* argv[]){
      _____________________________________________________________
      _____________________________________________________________
      _____________________________________________________________
      _____________________________________________________________
      fprintf(stderr,"Can't create order: %s\n", strerror(errno));
      return 1;
    }
    return 0;
  }
  char* my_env[] = {"FOOD=coffee", NULL};
  if(execle("./coffee", "./coffee", "donuts", NULL, my_env) == -1){
    fprintf(stderr,"Can't run process 0: %s\n", strerror(errno));
    return 1;
  }
  char* my_env[] = {"FOOD=donuts", NULL};
  if(execle("./coffee", "./coffee", "cream", NULL, my_env) == -1){
    fprintf(stderr,"Can't run process 0: %s\n", strerror(errno));
    return 1;
  }
  if(execl("./coffee", "coffee", NULL) == -1){
    fprintf(stderr,"Can't run process 0: %s\n", strerror(errno));
    return 1;
  }
  char* my_env[] = {"FOOD=donuts", NULL};
  if(execle("./coffee", "coffee", NULL, my_env) == -1){
    fprintf(stderr,"Can't run process 0: %s\n", strerror(errno));
    return 1;
  }
 coffee with donuts
 cream with donuts
 donuts with coffee
 coffee with coffee
 #include <stdio.h>
 #include <stdlib.h>
 int main(int argc, char* argv[])
 {
   char* w = getenv("EXTRA");
   if (!w)
     w = getenv("FOOD");
   if (!w)
     w = argv[argc - 1];
   char* c = getenv("EXTRA");
   if (!c)
     c = argv[argc - 1];
   printf("%s with %s\n", c, w);
   return 0;
 }
  int main(int argc, char* argv[]){
      _____________________________________________________________
      _____________________________________________________________
      _____________________________________________________________
      _____________________________________________________________
      fprintf(stderr,"Can't create order: %s\n", strerror(errno));
      return 1;
    }
    return 0;
  }
  char* my_env[] = {"FOOD=coffee", NULL};
  if(execle("./coffee", "./coffee", "donuts", NULL, my_env) == -1){
    fprintf(stderr,"Can't run process 0: %s\n", strerror(errno));
    return 1;
  }
 donuts with coffee
  char* my_env[] = {"FOOD=donuts", NULL};
  if(execle("./coffee", "./coffee", "cream", NULL, my_env) == -1){
    fprintf(stderr,"Can't run process 0: %s\n", strerror(errno));
    return 1;
  }
 cream with donuts
  if(execl("./coffee", "coffee", NULL) == -1){
    fprintf(stderr,"Can't run process 0: %s\n", strerror(errno));
    return 1;
  }
 coffee with coffee
  char* my_env[] = {"FOOD=donuts", NULL};
  if(execle("./coffee", "coffee", NULL, my_env) == -1){
    fprintf(stderr,"Can't run process 0: %s\n", strerror(errno));
    return 1;
  }
 coffee with donuts
 > export RSS_FEED=http://www.cnn.com/rss/celebs.xml
 > python rssgossip.py 'pajama death'
 Pajama Death launch own range of kitchen appliances.
 Lead singer of Pajama Death has new love interest.
 "I never ate the bat" says Pajama Death's Hancock.
 int main(int argc, char* argv[])
 {
   char* feeds[] = {"http://www.cnn.com/rss/celebs.xml",
                    "http://www.rollingstone.com/rock.xml",
                    "http://eonline.com/gossip.xml"};
   int times = 3;
   char* phrase = argv[1];
   int i;
   for (i = 0; i < times; i++) {
     char var[255];
     sprintf(var, "RSS_FEED=%s", feeds[i]);
     char* vars[] = {var, NULL};
     if (___________("/usr/bin/python", "/usr/bin/python", _____________________) == -1) {
       fprintf(stderr, "Can't run script: %s\n", strerror(errno));
       return 1;
     }
   }
   return 0;
 }
 int main(int argc, char* argv[])
 {
   char* feeds[] = {"http://www.cnn.com/rss/celebs.xml",
                    "http://www.rollingstone.com/rock.xml",
                    "http://eonline.com/gossip.xml"};
   int times = 3;
   char* phrase = argv[1];
   int i;
   for (i = 0; i < times; i++) {
     char var[255];
     sprintf(var, "RSS_FEED=%s", feeds[i]);
     char* vars[] = {var, NULL};
     if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1) {
       fprintf(stderr, "Can't run script: %s\n", strerror(errno));
       return 1;
     }
   }
   return 0;
 }
 > ./newshound 'pajama death'
 Pajama Death ex-drummer tells all.
 New Pajama Death album due next month.
   for (i = 0; i < times; i++) {
     ...
     if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1) {
       ...
     }
   }
 pid_t pid = fork();
 for (i = 0; i < times; i++) {
   char var[255];
   sprintf(var, "RSS_FEED=%s", feeds[i]);
   char* vars[] = {var, NULL};
   ___________________________________________________________________________________________
   ___________________________________________________________________________________________
   ___________________________________________________________________________________________
   ___________________________________________________________________________________________
   ___________________________________________________________________________________________
   ___________________________________________________________________________________________
   ___________________________________________________________________________________________
   ___________________________________________________________________________________________
   ___________________________________________________________________________________________
   ___________________________________________________________________________________________
   ___________________________________________________________________________________________
 }
 }
 }
 }
 if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1) {
 pid_t pid = fork();
 if (pid == -1) {
 return 1;
 return 1;
 if (!pid) {
 fprintf(stderr, "Can't run script: %s\n", strerror(errno));
 fprintf(stderr, "Can't fork process: %s\n", strerror(errno));
 for (i = 0; i < times; i++) {
   char var[255];
   sprintf(var, "RSS_FEED=%s", feeds[i]);
   char* vars[] = {var, NULL};
   pid_t pid = fork();
   if (pid == -1) {
     fprintf(stderr, "Can't fork process: %s\n", strerror(errno));
     return 1;
   }
   if (!pid) {
     if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1) {
       fprintf(stderr, "Can't run script: %s\n", strerror(errno));
       return 1;
     }
   }
 }
 > ./newshound 'pajama death'
 Pajama Death ex-drummer tells all.
 New Pajama Death album due next month.
 Photos from the surprise Pajama Death concert.
 Official Pajama Death pajamas go on sale.
 "When Pajama Death jumped the shark" by HenryW.
 Breaking News: Pajama Death attend premiere.
 Q: Does system() run programs in a separate process?
 A: Yes. But system() gives you less control over exactly how the program runs.
 Q: Isn't fork-ing processes really inefficient? I mean, it copies an entire process and then a moment later we replace the child process by doing an exec()?
 A: Operating systems use lots of tricks to make fork-ing processes really quick. For example, the operating system cheats and avoids making an actual copy of the parent process' data. Instead both the child and parent processes share the same data.
 Q: But what if one of the processes changes some data in memory? Won't that screw things up?
 A: It would, but the operating system will catch that a piece of memory is going to change, and '''then''' it will make a separate copy of that piece of memory for the child process.
 Q: That technique sounds quite cool. Does it have a name?
 A: Yes - it's called "Copy-on-write".
 Q: Is a pid_t just an int?
 A: It depends on the platform. The only thing you know is that it will be some integer type.
 Q: I stored the result of a fork() call in an int and it worked just fine.
 A: It's best to always use pid_t to store process ids. If you don't you might cause problems with other system calls or if your ode is compiled on another machine.
 Q: Why doesn't Windows support the fork() system call?
 A: Windows manages processes very differently from other operating systems and the kinds of tricks fork() needs to do in order to work efficiently are very hard to do on Windows. This may be why there isn't a version of fork() built in.
 Q: But Cygwin lets me do fork()s on Windows, right?
 A: Yes. The gurus who work on Cygwin did a lot of work to make Windows processes look like processes that are used on Unix, Linux and the Mac. But because they still need to rely on Windows to create the underlying processes, fork() on Cygwin can be a little slower than fork() on other platforms.
 Q: So if I'm just interested in writing code to work on Windows, is there something else I should use instead?
 A: Yes. There's a function called CreateProcess() that's like an enhanced version of system(). To find out more go to http://msdn.microsoft.com and search for "CreateProcess".
 pid_t pid = fork();
 if (pid == -1) {
   fprintf(stderr, "Can't fork process: %s\n", strerror(errno));
   return 1;
 }
 if (execle(...) == -1) {
   fprintf(stderr, "Can't run script: %s\n", strerror(errno));
   return 1;
 }
 void error(char* msg)
 {
   fprintf(stderr, "%s: %s\n", msg, strerror(errno));
   exit(1);
 }
 pid_t pid = fork();
 if (pid == -1) {
   error("Can't fork process");
 }
 if (execle(...) == -1) {
   error("Can't run script");
 }
 ./rssgossip.py Snooki > stories.txt
 |-----+---------------------------|
 |   # | Data stream               |
 |-----+---------------------------|
 |   0 | The keyboard              |
 |   1 | The screen                |
 |   2 | The screen                |
 |   3 | Database connection       |
 |   4 | MP3 music stream          |
 | ... |                           |
 |-----+---------------------------|
 |-----+-------------------------------------|
 |   # | Data stream                         |
 |-----+-------------------------------------|
 |   0 | The keyboard                        |
 |   1 | <s>The screen</s>  File auction.txt |
 |   2 | The screen                          |
 |   3 | Database connection                 |
 | ... |                                     |
 |-----+-------------------------------------|
 ./myprog > output.txt 2> errors.log
 ./myprog 2>&1
 FILE* my_file = fopen("guitar.mp3", "r");
 |-----+---------------------------|
 |   # | Data stream               |
 |-----+---------------------------|
 |   0 | The keyboard              |
 |   1 | The screen                |
 |   2 | The screen                |
 |   3 | Database connection       |
 |   4 | File guitar.mp3           |
 | ... |                           |
 |-----+---------------------------|
 int descriptor = fileno(my_file);
 dup2(4, 3);
 |-----+--------------------------------------------|
 |   # | Data stream                                |
 |-----+--------------------------------------------|
 |   0 | The keyboard                               |
 |   1 | The screen                                 |
 |   2 | The screen                                 |
 |   3 | <s>Database connection</s> File guitar.mp3 |
 |   4 | File guitar.mp3                            |
 | ... |                                            |
 |-----+--------------------------------------------|
 int main(int argc, char* argv[])
 {
   char* phrase = argv[1];
   char* vars[] = {"RSS_FEED=http://www.cnn.com/rss/celebs.xml", NULL};
   FILE* f = fopen("stories.txt", "w");
   if (!f) {
     error("Can't open stories.txt");
   }
   pid_t pid = fork();
   if (pid == -1) {
     error("Can't fork process");
   }
   if (!pid) {
     if (________________________________) {
       error("Can't redirect Standard Output");
     }
     if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1) {
       error("Can't run script");
     }
   }
   return 0;
 }
 int main(int argc, char* argv[])
 {
   char* phrase = argv[1];
   char* vars[] = {"RSS_FEED=http://www.cnn.com/rss/celebs.xml", NULL};
   FILE* f = fopen("stories.txt", "w");
   if (!f) {
     error("Can't open stories.txt");
   }
   pid_t pid = fork();
   if (pid == -1) {
     error("Can't fork process");
   }
   if (!pid) {
     if (dup2(fileno(f), 1) == -1) {
       error("Can't redirect Standard Output");
     }
     if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", phrase, NULL, vars) == -1) {
       error("Can't run script");
     }
   }
   return 0;
 }
 |-----+------------------|
 |   # | Data stream      |
 |-----+------------------|
 |   0 | The keyboard     |
 |   1 | File stories.txt |
 |   2 | The screen       |
 |   3 | File stories.txt |
 |-----+------------------|
 > ./newshound2 'pajama death'
 > cat stories.txt
 Pajama Death ex-drummer tells all.
 New Pajama Death album due next month.
 > ./newshound2 'pajama death'
 > cat stories.txt
 >
   ...
   int pid_status;
   if (waitpid(pid, &pid_status, 0) == -1) {
     error("Error waiting for child process");
   }
   return 0;
 }
 if (WEXITSTATUS(pid_status))
   puts("Error status non-zero");
 > ./newshound2 'pajama death'
 > cat stories.txt
 Pajama Death ex-drummer tells all.
 New Pajama Death album due next month.
 Q: So does exit() end the program faster than just returning from main()?
 A: No. But if you call exit() you don't need to structure your code to get back to the main() function. As soon as you call exit(), you're program is dead.
 Q: Should I check for -1 when I call exit(), in case it doesn't work?
 A: No. exit() doesn't return a value, because exit() never fails. exit() is the only function that is guaranteed never to return and never to fail.
 Q: Is the number I pass to exit the exit status?
 A: Yes.
 Q: Are the Standard Input, Output and Error always in slots 0, 1 and 2 of the descriptor table?
 A: Yes they are.
 Q: So if I open a new data-stream to something like a file, it is automatically added to the descriptor table?
 A: Yes.
 Q: Is there a rule about which slot it gets?
 A: New data-streams are always added to the available slot with the lowest number. So if slot number 4 is the first available one, that's the one your new data stream will use.
 Q: Are all data-streams connected to files?
 A: No. You can open data-streams to the network, or to other processes.
 Q: How big is the descriptor table?
 A: It has slots from 0 to 255.
 Q: The descriptor seems kinda complicated. Why is it there?
 A: Because it allows you re-wire the way a program works. Without the descriptor table, redirection isn't possible.
 Q: Is there a way of sending data to the screen without using the Standard Output?
 A: On some systems. For example, on Unix-based machines if you open a file stream to '/dev/tty', it will send data directly to the terminal.
 Q: If I replace a data-stream in the table using dup2(), what happens to the old data-stream?
 A: If the data-stream was open, the operating system will close it.
 Q: Can I use waitpid() to wait for any process? Or just the processes I started?
 A: You can use waitpid() to wait for any process.
 Q: Why isn't the pid_status in waitpid(..., &pid_status, ...) just an exit status?
 A: Because the pid_status contains other information.
 Q: Such as...?
 A: For example, WIFSIGNALED(pid_status) will be false if a process ended naturally or true if something killed it off.
 Q: How can an integer variable like pid_status contain several pieces of information?
 A: It stores different things in different bits. The first 8 bits store the exit status. The other information is stored in the other bits.
 Q: So if I can extract the first 8 bits of the pid_status value, I don't have to use WEXITSTATUS()?
 A: It is always best to use WEXITSTATUS(). It's easier to read and it will on whatever the native int size is on the platform.
 Q: Why is WEXITSTATUS() in upper-case?
 A: Because it is a macro rather than a function. The compiler replaces macro-statements with small pieces of code at runtime.
 > python rssgossip.py -u 'pajama death'
 Pajama Death ex-drummer tells all.
     http://www.rock-news.com/exclusive/24.html
 New Pajama Death album due next month.
     http://www.rolling-stone.com/pdalbum.html
 python rssgossip.py -u 'pajama death' | grep 'http'
     http://www.rock-news.com/exclusive/24.html
     http://www.rolling-stone.com/pdalbum.html
  int fd[2];
  if (pipe(fd) == -1) {
    error("Can't create the pipe");
  }
 close(fd[0]);
 close(fd[1]);
 void open_url(char* url)
 {
   char launch[255];
   sprintf(launch, "cmd /c start %s", url);
   system(launch);
   sprintf(launch, "x-www-browser '%s' &", url);
   system(launch);
   sprintf(launch, "open '%s'", url);
   system(launch);
 }
 int main(int argc, char* argv[])
 {
   char* phrase = argv[1];
   char* vars[] = {"RSS_FEED=http://www.cnn.com/rss/celebs.xml", NULL};
   int fd[2];
   ________________________________
   ________________________________
   ________________________________
   pid_t pid = fork();
   if (pid == -1) {
     error("Can't fork process");
   }
   if (!pid) {
     _____________________________
     _____________________________
     if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", "-u", phrase, NULL, vars) == -1) {
       error("Can't run script");
     }
   }
   ___________________________
   ___________________________
   char line[255];
   while (fgets(line, 255, _______________)) {
     if (line[0] == '\t')
       open_url(line + 1);
   }
   return 0;
 }
 int main(int argc, char* argv[])
 {
   char* phrase = argv[1];
   char* vars[] = {"RSS_FEED=http://www.cnn.com/rss/celebs.xml", NULL};
   int fd[2];
   if (pipe(fd) == -1) {
     error("Can't create the pipe");
   }
   pid_t pid = fork();
   if (pid == -1) {
     error("Can't fork process");
   }
   if (!pid) {
     dup2(fd[1], 1);
     close(fd[0]);
     if (execle("/usr/bin/python", "/usr/bin/python", "./rssgossip.py", "-u", phrase, NULL, vars) == -1) {
       error("Can't run script");
     }
   }
   dup2(fd[0], 0);
   close(fd[1]);
   char line[255];
   while (fgets(line,255,stdin)) {
     if (line[0] == '\t')
       open_url(line + 1);
   }
   return 0;
 }
 > ./news_opener 'pajama death'
 Q: Is a pipe a file?
 A: It's up to the operating system how it creates pipes, but pipes created with the <tt>pipe()</tt> are not normally files.
 Q: So pipes ''might'' be files?
 A: It is possible to create pipes based on files, which are normally called ''named pipes'' or '''FIFO''' (''First-In/First-Out'') files.
 Q: Why would anyone want a pipe that uses a file?
 A: Pipes based on files have ''names''. That means they are useful if two processes need to talk to each other and they are not parent-and-child processes. As long as both processes known the name of the pipe, they can talk with it.
 Q: Great! So how do I use named pipes?
 A: Using the <tt>mkfifo()</tt> system call. For more information see http://tinyurl.com/cdf6ve5
 Q: If most pipes are not files, what are they?
 A: Usually they are just pieces of memory. Data is written at one point and read at another.
 Q: What happens if I try to read from a pipe and there's nothing in there?
 A: Your program will wait until something '''is''' there.
 Q: How does the parent know when the child is finished?
 A: When the child process dies, the pipe is closed and the <tt>fgets()</tt> command receives an ''End-of-file'', which means the <tt>fgets()</tt> function returns 0, and the loop ends.
 Q: Can parents speak to children?
 A: Absolutely. There is no reason why you can't connect your pipes the other way round, so that the parent sends data to the child process.
 Q: Can you have a pipe that works in both directions at once? That way my parent and child processes could have a two way conversation.
 A: No - you can't do that. Pipes always work in only one direction. But you '''can''' create '''two''' pipes: one from the parent to the child and one from the child to the parent.
 #include <stdio.h>
 int main()
 {
   char name[30];
   printf("Enter your name: ");
   fgets(name, 30, stdin);
   printf("Hello %s\n", name);
   return 0;
 }
 > ./greetings
 Enter your name: ^C
 >
                                            +----------------+
                                            |                |
                                            |                |
                                            |                |                      ---------------
                                            |    Operating   |                 ----/               \----
       +----------------------+             |      System    | interrupt      /                         \
       |    Keyboard          +-------------+                +----------------       greetings program    )
       +----------------------+             |                |  signal        \                         /
                                            |                |                 ----\               /----
                                            |                |                      ---------------
                                            |                |
                                            |                |
                                            +----------------+
 |--------+-------------|
 | Signal | Handler     |
 |--------+-------------|
 | SIGURG | Do nothing  |
 | SIGINT | Call exit() |
 | ...    | ...         |
 #include <stdio.h>
 #include <signal.h>
 #include <stdlib.h>
 void handle_interrupt(int sig)
 {
   puts ("Goodbye cruel world....\n");
   exit(1);
 }
 int main()
 {
   if (signal(SIGINT, handle_interrupt) == SIG_ERR) {
     fprintf(stderr, "Can't map the handler");
     exit(2);
   }
   char name[30];
   printf("Enter your name: ");
   fgets(name, 30, stdin);
   printf("Hello %s\n", name);
   return 0;
 }
 > ./greetings
 Enter your name: ^CGoodbye cruel world....
 >
 Q: If the interrupt handler didn't call exit(), would the program still have ended?
 A: No.
 Q: So I could write a program that completely ignores interrupts?
 A: You could, but it's not a good idea. In general if your program receives an error signal it's best to exit with an error, even if your run some of your own code first.
 SIGINT
 SIGQUIT
 SIGFPE
 SIGTRAP
 SIGSEGV
 SIGWINCH
 SIGTERM
 SIGPIPE
 > ps
 77868 ttys003    0:00.02 bash
 78222 ttys003    0:00.01 ./testprog
 > kill 78222
 > kill -INT 78222
 > kill -SEGV 78222
 > kill -KILL 78222
 raise(SIGTERM);
 alarm(120);
 do_important_busy_work();
 do_more_busy_work();
 signal(SIGALRM, pour_coffee);
 alarm(120);
 ...
 Q: Can I set an alarm for '''less than a second'''?
 A: Yes - but it's a little more complicated. You need to use a different function called setitimer(). It lets you set the process' interval timer directly in either seconds or fractions of a second.
 Q: How do I do that?
 A: Type in <tt>http://tinyurl.com/3o7hzbm</tt> for more details.
 Q: Why is there only one timer for a process?
 A: The timers have to be managed by the operating system kernel and if processes had lots of timers, the kernel would go slower and slower. To prevent this happening the operating system limits each process to one timer.
 Q: Timers let me multi-task?! Great - so I can use them to do lots of things at once?
 A: No. Remember - your process will always ''stop whatever it's doing'' when it handles a signal. That means it is still only doing one thing at a time. We'll see later how you can ''really'' make your code do more than one thing at a time.
 Q: What happens if I set one timer and it had already been set.
 A: Whenever you call the <tt>alarm()</tt> function you reset the timer. That means if you set the alarm for 10 seconds, then a moment later you set it for 10 minutes, the alarm won't fire until 10 minutes are up. The original 10 second timer will be lost.
 signal(SIGTERM, SIG_DFL);
 signal(SIGINT, SIG_IGN);
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/time.h>
 #include <string.h>
 #include <errno.h>
 #include <signal.h>
 int score = 0;
 void end_game(int sig)
 {
   printf("\nFinal score: %i\n", score);
   ______________________________________
 }
 void times_up(int sig)
 {
   puts("\nTIME'S UP!");
   raise(________________);
 }
 void error(char* msg)
 {
   fprintf(stderr, "%s: %s\n", msg, strerror(errno));
   exit(1);
 }
 int main()
 {
   signal(SIGALRM, ____________);
   signal(SIGINT, ___________);
   srandom (time (0));
   while(1) {
     int a = random() % 11;
     int b = random() % 11;
     char txt[4];
     ____________________
     printf("\nWhat is %i times %i? ", a, b);
     fgets(txt, 4, stdin);
     int answer = atoi(txt);
     if (answer == a * b)
       score++;
     else
       printf("\nWrong! Score: %i\n", score);
   }
   return 0;
 }
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/time.h>
 #include <string.h>
 #include <errno.h>
 #include <signal.h>
 int score = 0;
 void end_game(int sig)
 {
   printf("\nFinal score: %i\n", score);
   exit(0);
 }
 void times_up(int sig)
 {
   puts("\nTIME'S UP!");
   raise(SIGINT);
 }
 void error(char* msg)
 {
   fprintf(stderr, "%s: %s\n", msg, strerror(errno));
   exit(1);
 }
 int main()
 {
   signal(SIGALRM, times_up);
   signal(SIGINT, end_game);
   srandom (time (0));
   while(1) {
     int a = random() % 11;
     int b = random() % 11;
     char txt[4];
     alarm(5);
     printf("\nWhat is %i times %i? ", a, b);
     fgets(txt, 4, stdin);
     int answer = atoi(txt);
     if (answer == a * b)
       score++;
     else
       printf("\nWrong! Score: %i\n", score);
   }
   return 0;
 }
 > ./math_master
 What is 0 times 1? 0
 What is 6 times 1? 6
 What is 4 times 10? 40
 What is 2 times 3? 6
 What is 7 times 4? 28
 What is 4 times 10? ^C
 Final score: 5
 >
 > ./math_master
 What is 5 times 9? 45
 What is 2 times 8? 16
 What is 9 times 1? 9
 What is 9 times 3?
 TIME'S UP!
 Final score: 3
 >
 Q: Are signals always received in the same order they are sent?
 A: Not if they are sent very close together. The operating system might choose to reorder the signals if it thinks one is more important than the others.
 Q: Is that always true?
 A: It depends on the platform. On most versions of Cygwin, for example, the signals will always be sent and received in the same order. But in general, you shouldn't rely on it.
 Q: If I send the same signal twice, will it be received twice by the process?
 A: Again - it depends. On Linux and the Mac, if same signal is repeated very quickly, the kernel might choose to only send the signal once to the process. On Cygwin it will always send both signals. But again - you should not assume that just because you sent the same signal twice, that it will be received twice.
