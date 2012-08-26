#include <stdio.h>


void print_reverse(char* s)
{
  size_t len = strlen(s);
  char* t = s + len - 1;
  while (t >= s) {
    printf("%c", *t);
    t = t - 1;
  }
  puts("");
}

void fred()
{
  int x = 2;
  /*  return 1;*/
}

void dummy0(int* b)
{
  printf("dummy0 sizeof(b) = %li\n", sizeof(b));
}

void dummy1(int b[])
{
  printf("dummy1 sizeof(b) = %li\n", sizeof(b));
}

void print_me(char s[13])
{
  char* t;
  printf("I've been told: %s\nsize = %i\nt size = %i", s, sizeof(s), sizeof(t));
  printf("Location = %p\n", s);
}

void fortune_cookie(char msg[]) 
{
  printf("Message reads: %s\n", msg);
  printf("msg occupies %i bytes\n", sizeof(msg));
}

void dosizeof(void* p)
{
  printf("p has size %i\n", sizeof(p));
}

void skip(char* msg)
{
  puts(msg + 6);
}

char food[10];


int global0 = 1;
int main()
{
  int local0 = 4;
  float local1 = 2.0f;
  int local2 = 4;
  float local3 = 2.0f;
  printf("local0 lives at %p, global0 lives at %p, local1 lives at %p, local2 lives at %p, local3 lives at %p\n", 
         &local0, &global0, &local1, &local2, &local3);
  int int0;
  int* int_pointer = &int0;
  double double0;
  double* double_pointer = &double0;
  char char0;
  char* char_pointer = &char0;
  void* void_pointer = &int0;
  printf("int0 is at %p\n", int_pointer);
  printf("double0 is at %p\n", double_pointer);
  printf("char0 is at %p\n", char_pointer);
  printf("void_pointer is at %p\n", void_pointer);
  int_pointer = int_pointer + 1;
  double_pointer = double_pointer + 1;
  char_pointer = char_pointer + 1;
  void_pointer = void_pointer + 1;
  printf("int0 is at %p\n", int_pointer);
  printf("double0 is at %p\n", double_pointer);
  printf("char0 is at %p\n", char_pointer);
  printf("void_pointer is at %p\n", void_pointer);
  int arr[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  int* a = arr;
  printf("Item 2 = %i\n", arr[2]);
  printf("Item 2 = %i\n", a[2]);
  printf("Item 2 = %i\n", *(arr + 2));
  printf("Item 2 = %i\n", *(a + 2));
  arr[2] = 99;
  printf("Item 2 = %i\n", arr[2]);
  printf("Item 2 = %i\n", a[2]);
  printf("Item 2 = %i\n", *(arr + 2));
  printf("Item 2 = %i\n", *(a + 2));
  *(arr + 1) = 98;
  printf("Item 1 = %i\n", arr[1]);
  printf("Item 1 = %i\n", a[1]);
  printf("Item 1 = %i\n", *(arr + 1));
  printf("Item 1 = %i\n", *(a + 1));
  *(a + 1) = 97;
  printf("Item 1 = %i\n", 1[arr]);
  printf("Item 1 = %i\n", 1[a]);
  printf("Item 1 = %i\n", *(arr + 1));
  printf("Item 1 = %i\n", *(a + 1));
  printf("a  = %p\n", a);
  printf("a + 1 = %p\n", (a + 1));
  printf("a  = %li\n", a);
  printf("a + 1 = %li\n", (a + 1));
  printf("sizeof(a) = %li\n", sizeof(a));
  printf("sizeof(arr) = %li\n", sizeof(arr));
  printf("a = %li, &a = %li\n", a, &a);
  printf("arr = %li, &arr = %li\n", arr, &arr);
  long fred = (long)a;
  printf("fred = %li\n", fred);
  dummy0(arr);
  dummy1(arr);
  printf("Location of original string: %p\n", "Hello world!");
  printf("Location of original string: %p\n", "Hello world!1");
  printf("A long has size %i\n", sizeof(long));
  printf("A int has size %i\n", sizeof(int));
  printf("Turtles has size %i\n", sizeof("Turtles!"));
  print_me("Hello world!");
  fortune_cookie("To have a friend, learn to be a friend");
  char shoes[] = "sneakers";
  printf("The shoes string is stored at: %p\n", shoes);
  dosizeof(&fred);
  dosizeof(shoes);
  char s[] ="How big is it?";
  char* t = s;
  printf("s is %i\n", sizeof(s));
  printf("t is %i\n", sizeof(t));
  /*  char anarray[] = "I am some array";
  char achar = 'a';
  char* p1;
  p1 = &achar;*/
  /* anarray = &achar;*/


  char* msg_from_amy = "Don't call me";
  skip(msg_from_amy);

  int nums[] = {1, 2, 3};
  printf("nums is at %li\n", nums);
  printf("nums + 1 is at %li\n", nums + 1);

  /* char name[40];
     printf("Enter your name: ");
     scanf("%39s", name);

     char surname[40];
     printf("\nEnter your surname: ");
     scanf("%39s", surname);
     printf("\nYour name: %s %s\n", name, surname);

     char first_name[20];
     char last_name[20];
     printf("Enter first and last name: ");
     scanf("%19s %19s", first_name, last_name);

     printf("%s-%s\n", first_name, last_name);*/
  /* int courses;
     printf("Enter favorite food: ");
     scanf("%s", food);
     printf("Enter meal courses: ");
     scanf("%i", &courses);
     printf("Favorite food: %s", food);
     printf("\nCourses: %i", courses);*/

  char s0 = "Hello";
  char * s1 = s0;
  // char s2[];
  printf("s0 is at %p\n", s0);
  printf("s1 is at %p\n", s1);
  //  printf("s2 is at %p\n", s2);

  print_reverse("Never odd or even");

  char *s1000, t1000;
  printf("size of s1000 is %i\n", sizeof(s1000));
  printf("size of t1000 is %i\n", sizeof(t1000));

  return 0;
}
