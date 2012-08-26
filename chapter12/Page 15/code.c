 void* do_stuff(void* param)
 {
   long thread_no = (long)param;
   printf("Thread number %ld\n", thread_no);
   return (void*)(thread_no + 1);
 }
  
 int main()
 {
   pthread_t threads[20];
   long t; 
   for (t = 0; t < 3; t++) {
     pthread_create(&threads[t], NULL, do_stuff, (void*)t);
   }
   void* result;
   for (t = 0; t < 3; t++) {
     pthread_join(threads[t], &result);
     printf("Thread %ld returned %ld\n", t, (long)result);
   }
   return 0;
 }
 > ./param_test
 Thread number 0
 Thread 0 returned 1
 Thread number 1
 Thread number 2
 Thread 1 returned 2
 Thread 2 returned 3
 >
