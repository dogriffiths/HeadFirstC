 #include <stdio.h>
 #include <signal.h>
 #include <stdlib.h>
 void diediedie(int sig)
 {
   puts ("Goodbye cruel world....\n");
   exit(1);
 }
 int catch_signal(int sig, void (*handler)(int))
 {
   struct sigaction action;
   action.sa_handler = handler;
   sigemptyset(&action.sa_mask);
   action.sa_flags = 0;
   return sigaction (sig, &action, NULL);
 }
 int main()
 {
   if (catch_signal(SIGINT, handle_interrupt) == -1) {
     fprintf(stderr, "Can't map the handler");
     exit(2);
   }
   char name[30];
   printf("Enter your name: ");
   fgets(name, 30, stdin);
   printf("Hello %s\n", name);
   return 0;
 }
 http://alleg.sourceforge.net/
 typedef struct {
   float sx;
   float sy;
   float heading;
   float speed;
   int gone;
   ALLEGRO_COLOR color;
 } Spaceship;
  al_draw_line(-8, 9, 0, -11, s->color, 3.0f);
  al_draw_line(0, -11, 8, 9, s->color, 3.0f);
  al_draw_line(-6, 4, -1, 4, s->color, 3.0f);
  al_draw_line(6, 4, 1, 4, s->color, 3.0f);
 typedef struct {
   float sx;
   float sy;
   float heading;
   float twist;
   float speed;
   float rot_velocity;
   float scale;
   int gone;
   ALLEGRO_COLOR color;
 } Asteroid;
  al_draw_line(-20, 20, -25, 5, a->color, 2.0f);
  al_draw_line(-25, 5, -25, -10, a->color, 2.0f);
  al_draw_line(-25, -10, -5, -10, a->color, 2.0f);
  al_draw_line(-5, -10, -10, -20, a->color, 2.0f);
  al_draw_line(-10, -20, 5, -20, a->color, 2.0f);
  al_draw_line(5, -20, 20, -10, a->color, 2.0f);
  al_draw_line(20, -10, 20, -5, a->color, 2.0f);
  al_draw_line(20, -5, 0, 0, a->color, 2.0f);
  al_draw_line(0, 0, 20, 10, a->color, 2.0f);
  al_draw_line(20, 10, 10, 20, a->color, 2.0f);
  al_draw_line(10, 20, 0, 15, a->color, 2.0f);
  al_draw_line(0, 15, -20, 20, a->color, 2.0f);
 Q:
 export PATH=/Developer/usr/bin:$PATH
 export CC=clang
 mkdir Build
 cd Build
 cmake ..
 make
 sudo make install
 sudo apt-get install cmake
 rm -r Build
 mkdir Build
 cd Build
 cmake ..
 --- No. Having all sorts of trouble. Can't find the Xcursor library.
