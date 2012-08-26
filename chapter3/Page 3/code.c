 #include <stdio.h>
 int main()
 {
   float latitude;
   float longitude;
   char info[80];
   int started = ____;
   puts("data=[");
   while (scanf("%f,%f,%79[^\n]", __________, __________, __________) == 3) {
     if (started)
       printf(",\n");
     else
       started = ____;
     printf("{latitude: %f, longitude: %f, info: '%s'}", _________, ________, _______);
   }
   puts("\n]");
   return 0;
 }
