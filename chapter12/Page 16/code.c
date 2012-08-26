 pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;
 void* drink_lots()
 {
   int i;
   pthread_mutex_lock(&beers_lock);
   for (i = 0; i < 100000; i++) {
     beers = beers - 1;
   }
   pthread_mutex_unlock(&beers_lock);
   printf("beers = %i\n", beers);
   return NULL;
 }
 pthread_mutex_t beers_lock = PTHREAD_MUTEX_INITIALIZER;
 void* drink_lots()
 {
   int i;
   for (i = 0; i < 100000; i++) {
     pthread_mutex_lock(&beers_lock);
     beers = beers - 1;
     pthread_mutex_unlock(&beers_lock);
   }
   printf("beers = %i\n", beers);
   return NULL;
 }
