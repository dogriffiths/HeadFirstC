 #include <stdio.h>
 #include <unistd.h>
 
 int main(int argc, char* args[])
 {
   char* delivery = "";
   int thick = 0;
   int count = 0;
   char ch;
   while ((ch = getopt(argc, args, "d:t")) != EOF)
     switch (ch) {
     case 'd':
       delivery = optarg;
       break;
     case 't':
       thick = 1;
       break;
     default:
       fprintf(stderr, "Unknown option: '%s'\n", optarg);
       return 1;
     }
 
   argc -= optind;
   args += optind;
 
   if (thick)
     puts("Thick crust.");
 
   if (delivery[0])
     printf("To be delivered %s.\n", delivery);
 
   puts("Ingredients:");
 
   for (count = 0; count < argc; count++)
     puts(args[count]);
   return 0;
 }
