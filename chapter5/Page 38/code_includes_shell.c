 typedef union {
   float weight;
   int count;
 } cupcake;
 
 int main()
 {
   cupcake order = {2};
   printf("Cupcakes quantity: %i\n",
     order.count);
   return 0;
 }
 $ gcc badunion.c -o badunion && ./badunion
 Cupcakes quantity: 1073741824
 $ 
