 int beers = 2000000;
 void* drink_lots()
 {
   int i;
   for (i = 0; i < 100000; i++) {
     beers = beers - 1;
   }
   return NULL;
 }
 int main()
 {
   pthread_t threads[20];
   int t;
   printf("%i bottles of beer on the wall\n%i bottles of beer\n", beers, beers);
   for (t = 0; t < 20; t++) {
     _________________(_______________, NULL, _______________, NULL);
   }
   void* result;
   for (t = 0; t < 20; t++) {
     ________________(threads[t], &result);
   }
   printf("There are now %i bottles of beer on the wall\n", beers);
   return 0;
 }
 pthread_join
 pthread_create
 drink_lots
 &threads[t]
 threads[t]
 threads
