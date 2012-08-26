            -----------                  -------------                 -------------
         --/           \--            --/             \--           --/             \--
        /                 \          /                   \         /                   \
       (                   )        (                     )       (                     )
        \                 /          \                   /         \                   /
         --\           /--            --\             /--           --\             /--
            -----+-----                  ------+------                 ------+------
                 |                             |                             |
                 V                             V                             V
       +---------+----------+     +------------+-----------+    +------------+------------+
       |                    |     |                        |    |                         |
       |                    |     |                        |    |                         |
       |                    |     |                        |    |                         |
       |                    |     |                        |    |                         |
       |                    |     |                        |    |                         |
       +--------------------+     +------------------------+    +-------------------------+
       +---------------------+      +---------------------+      +----------------------+
       |                     |      |                     |      |                      |
       |                     +----->|                     +----->|                      |
       |                     |      |                     |      |                      |
       |                     |<-----+                     |<-----+                      |
       |                     |      |                     |      |                      |
       +---------------------+      +---------------------+      +----------------------+
       +---------------------+      +---------------------+      +----------------------+
       |                     |      |                     |      |                      |
       |                     +----->|                     +----->|                      |
       |                     |      |                     |      |                      |
       +---------------------+      +---------------------+      +----------------------+
                                       +--------+
                                       |        |
                                       |        |
                                       |        |
                                       /------\-+
                                     -/        \-
                                   -/            \
                           +------/+           +--\----+
                           |       |           |       |
                           |       |           |       |
                           |       |           |       |
                           +-/---\-+           +-------+
                            /     \-
                            |       \
                      +----/-+    +--\---+
                      |      |    |      |
                      |      |    |      |
                      |      |    |      |
                      +------+    +------+
            -----------                  -------------                 -------------
         --/           \--            --/             \--           --/             \--
        /                 \          /                   \         /                   \
       (                   )        (                     )       (                     )
        \                 /          \                   /         \                   /
         --\           /--            --\             /--           --\             /--
            -----+-----                  ------+------                 ------+------
                 |                             |                             |
                 V                             V                             V
       +---------+----------+     +------------+-----------+    +------------+------------+
       |                    |     |                        |    |                         |
       |                    |     |                        |    |                         |
       |                    |     |                        |    |                         |
       |                    |     |                        |    |                         |
       |                    |     |                        |    |                         |
       +--------------------+     +------------------------+    +-------------------------+
       +---------------------+      +---------------------+      +----------------------+
       |                     |      |                     |      |                      |
       |                     +----->|                     +----->|                      |
       |                     |      |                     |      |                      |
       |                     |<-----+                     |<-----+                      |
       |                     |      |                     |      |                      |
       +---------------------+      +---------------------+      +----------------------+
       +---------------------+      +---------------------+      +----------------------+
       |                     |      |                     |      |                      |
       |                     +----->|                     +----->|                      |
       |                     |      |                     |      |                      |
       +---------------------+      +---------------------+      +----------------------+
                                       +--------+
                                       |        |
                                       |        |
                                       |        |
                                       /------\-+
                                     -/        \-
                                   -/            \
                           +------/+           +--\----+
                           |       |           |       |
                           |       |           |       |
                           |       |           |       |
                           +-/---\-+           +-------+
                            /     \-
                            |       \
                      +----/-+    +--\---+
                      |      |    |      |
                      |      |    |      |
                      |      |    |      |
                      +------+    +------+
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 
 typedef struct node {
   char* question;
   struct node * no;
   struct node * yes;
 } node;
 
 int yes_no(char* question)
 {
   char answer[3];
   printf("%s? (y/n): ", question);
   fgets(answer, 3, stdin);
   return answer[0] == 'y';
 }
 
 node* create(char* question)
 {
   node* n = (node*)malloc(sizeof(node));
   n->question = strdup(question);
   n->no = NULL;
   n->yes = NULL;
   return n;
 }
 
 void release(node* n)
 {
   if (n) {
     if (n->no)
       release(n->no);
     if (n->yes)
       release(n->yes);
     if (n->question)
       free(n->question);
     free(n);
   }
 }
 
 int main()
 {
   char question[80];
   char suspect[20];
   node* start_node = create("Does suspect have a mustache");
   start_node->no = create("Loretta Barnsworth");
   start_node->yes = create("Vinny the Spoon");
 
   node* current;
   do {
     current = start_node;
     for (;;) {
       if (yes_no(current->question))
       {
         if (current->yes) {
           current = current->yes;
         } else {
           printf("SUSPECT IDENTIFIED\n");
           break;
         }
       } else if (current->no) {
         current = current->no;
       } else {
 
          /* Make the yes-node the new suspect name */
          printf("Who's the suspect? ");
          fgets(suspect, 20, stdin);
          node* yes_node = create(suspect);
          current->yes = yes_node;
 
          /* Make the no-node a copy of this question */
          node* no_node = create(current->question);
          current->no = no_node;
 
          /* Then replace this question with the new question */
          printf("Give me a question that is TRUE for %s but not for %s? ", suspect, current->question);
          fgets(question, 80, stdin);
          current->question = strdup(question);
 
          break;
       }
     }
   } while(yes_no("Run again"));
   release(start_node);
   return 0;
 }
                                                      +---------------+
                                                      |   Has a       |
                                                      |   Mustache?  |
                                                      +---------------+
                                                   ---/               \---
                                               ---/                       \---
                                   +----------/----+                    +-----\---------+
                                   |  Vinny the    |                    |  Loretta      |
                                   |  Spoon        |                    |  Barnsworth   |
                                   +---------------+                    +---------------+
                                                      +---------------+
                                                      |   Has a       |
                                                      |   Mustache?   |
                                                      +---------------+
                                                   ---/               \---
                                               ---/                       \---
                                   +----------/----+                    +-----\---------+
                                   |  One gold     |                    |  Facial scar? |
                                   |  tooth?       |                    |               |
                                   +----------\----+                    +----/----------+
                                    ---/       \                           -/        \---
                                ---/            \-                        /              \---
                            ---/                  \                     -/                   \---
                 +---------/-----+           +-----\-------+      +----/---------+        +------\---------+
                 |  Cliffy       |           | Vinny the   |      |  Hayden      |        | Loretta        |
                 |  Five Fingers |           | Spoon       |      |  Fantucci    |        | Barnsworth     |
                 +---------------+           +-------------+      +--------------+        +----------------+
 > gcc spies.c -o spies && ./spies
 Does suspect have a moustache? (y/n): n
 Loretta Barnsworth? (y/n): n
 Who's the suspect? Hayden Fantucci
 Give me a question that is TRUE for Hayden Fantucci
  but not for Loretta Barnsworth? Has a facial scar
 Run again? (y/n): y
 Does suspect have a moustache? (y/n): n
 Has a facial scar
 ? (y/n): y
 Hayden Fantucci
 ? (y/n): y
 SUSPECT IDENTIFIED
 Run again? (y/n): n
 >
 gcc -g spies.c -o spies
 $ valgrind --leak-check=full ./spies
 ==1754== Copyright (C) 2002-2010, and GNU GPL'd, by Julian Seward et al.
 Does suspect have a mustache? (y/n): y
 Vinny the Spoon? (y/n): y
 SUSPECT IDENTIFIED
 Run again? (y/n): n
 ==1754== All heap blocks were freed -- no leaks are possible
 $ valgrind --leak-check=full ./spies
 ==2750== Copyright (C) 2002-2010, and GNU GPL'd, by Julian Seward et al.
 Does suspect have a mustache? (y/n): n
 Loretta Barnsworth? (y/n): n
 Who's the suspect? Hayden Fantucci
 Give me a question that is TRUE for Hayden Fantucci
  but not for Loretta Barnsworth? Has a facial scar
 Run again? (y/n): n
 ==2750== HEAP SUMMARY:
 ==2750==     in use at exit: 19 bytes in 1 blocks
 ==2750==   total heap usage: 11 allocs, 10 frees, 154 bytes allocated
 ==2750== 19 bytes in 1 blocks are definitely lost in loss record 1 of 1
 ==2750==    at 0x4026864: malloc (vg_replace_malloc.c:236)
 ==2750==    by 0x40B3A9F: strdup (strdup.c:43)
 ==2750==    by 0x8048587: create (spies.c:22)
 ==2750==    by 0x804863D: main (spies.c:46)
 ==2750== LEAK SUMMARY:
 ==2750==    definitely lost: 19 bytes in 1 blocks
 $
 } else if (current->no) {
   current = current->no;
 } else {
    /* Make the yes-node the new suspect name */
    printf("Who's the suspect? ");
    fgets(suspect, 20, stdin);
    node* yes_node = create(suspect);
    current->yes = yes_node;
    /* Make the no-node a copy of this question */
    node* no_node = create(current->question);
    current->no = no_node;
    /* Then replace this question with the new question */
    printf("Give me a question that is TRUE for %s but not for %s? ", suspect, current->question);
    fgets(question, 80, stdin);
    current->question = strdup(question);
    break;
 }
 ==2750== 19 bytes in 1 blocks are definitely lost in loss record 1 of 1
 ==2750==    at 0x4026864: malloc (vg_replace_malloc.c:236)
 ==2750==    by 0x40B3A9F: strdup (strdup.c:43)
 ==2750==    by 0x8048587: create (spies.c:22)
 ==2750==    by 0x804863D: main (spies.c:46)
 _________________________________________________________________
 _________________________________________________________________
 _________________________________________________________________
 _________________________________________________________________
 _________________________________________________________________
 _________________________________________________________________
 _________________________________________________________________
 _________________________________________________________________
 There is 1 piece of data
 The string "Loretta Barnsworth" - it's 18 characters with a string terminator.
 We know the create() functions themselves don't cause leaks because they didn't on the first pass,
 so it must be this strdup() line:
   current->question = strdup(question);
 If current->question is already pointing to something on the heap, we need to free
 that before allocated a new question:
   if (current->question)
     free(current->question);
   current->question = strdup(question);
 $ valgrind --leak-check=full ./spies
 ==1800== Copyright (C) 2002-2010, and GNU GPL'd, by Julian Seward et al.
 Does suspect have a mustache? (y/n): n
 Loretta Barnsworth? (y/n): n
 Who's the suspect? Hayden Fantucci
 Give me a question that is TRUE for Hayden Fantucci
  but not for Loretta Barnsworth? Has a facial scar
 Run again? (y/n): n
 ==1800== All heap blocks were freed -- no leaks are possible
 $
