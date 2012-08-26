 #include <stdio.h>
 #include <string.h>
 #include <errno.h>
 #include <stdlib.h>
 #include <sys/socket.h>
 #include <arpa/inet.h>
 #include <unistd.h>
 #include <signal.h>
 ....
 int listener_d;
 void handle_shutdown(int sig)
 {
   if (listener_d)
     close(listener_d);
   fprintf(stderr, "Bye!\n");
   exit(0);
 }
