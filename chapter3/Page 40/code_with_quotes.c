 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 int main(int argc, char* args[])
 {
   char line[80];
   if (argc != 6) {
     fprintf(stderr, "You need to give 5 arguments\n");
     return 1;
   }
   FILE* in = fopen("gpsdata.data", "r");
   FILE* file1 = fopen(args[2], "w");
   FILE* file2 = fopen(args[4], "w");
   FILE* file3 = fopen(args[5], "w");
   while (fscanf(in, "%79[^\n]\n", line) == 1) {
     if (strstr(line, args[1]))
       fprintf(file1, "%s\n", line);
     else if (strstr(line, args[3]))
       fprintf(file2, "%s\n", line);
     else
       fprintf(file3, "%s\n", line);
   }
   fclose(file1);
   fclose(file2);
   fclose(file3);
   return 0;
 }
 5
