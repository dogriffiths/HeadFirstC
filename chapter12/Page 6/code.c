 void* does_not()
 {
   int i = 0;
   for (i = 0; i < 5; i++) {
     sleep(1);
     puts("Does not!");
   }
   return NULL;
 }
 void* does_too()
 {
   int i = 0;
   for (i = 0; i < 5; i++) {
     sleep(1);
     puts("Does too!");
   }
   return NULL;
 }
                                                       +----------------------+
                                                       |                      |
                                                       |  does_not() function |
                                                     /-+                      |
                    +-----------------+        /-----  |                      |
                    |                 |  /-----        +----------------------+
                    |                 +--
                    |   Main program  |
                    |                 |
                    |                 +--
                    +-----------------+  \---           +--------------------+
                                             \----      |                    |
                                                  \---  | does_too() function|
                                                      \-+                    |
                                                        |                    |
                                                        +--------------------+
