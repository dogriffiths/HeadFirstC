 Q: If the <tt>island</tt> struct had a name '''array''' rather than a character pointer, would we need to use strdup() here?
 A: No. Each island <tt>struct</tt> would store it's own copy, so you wouldn't need to make your own copy.
 Q: So why would I want to use char pointers rather than char arrays in my data structures?
 A: Char pointers won't limit the amount of space you need to set aside for strings. If you use char arrays, you will need to decide in advance exactly how long your strings might need to be.
 const int NUM_ADS = 7;
 char* ADS[] = {
   "William: SBM GSOH likes sports, TV, dining",
   "Matt: SWM NS likes art, movies, theater",
   "Luis: SLM ND likes books, theater, art",
   "Mike: DWM DS likes trucks, sports and bieber",
   "Peter: SAM likes chess, working out and art",
   "Josh: SJM likes sports, movies and theater",
   "Jed: DBM likes theater, books and dining"
 };
 
 void find()
 {
   int i;
   puts("Search results:");
   puts("------------------------------------");
   for (i = 0; i ___ _________; i++) {
     if (________(________, __________)
         ____ ___ ________(________, __________)) {
       printf("%s\n", ADS[i]);
     }
   }
   puts("------------------------------------");
 }
 <
 NUM_ADS
 strstr
 strstr
 !
 &&
 ADS[i]
 ADS[i]
 "sports"
 "bieber"
 ||
 strcmp
 strcmp
 void find()
 {
   int i;
   print("Search results:\n");
   print("------------------------------------\n");
   for (i = 0; i < NUM_ADS; i++) {
     if (strstr(ADS[i], "sports")
         && !strstr(ADS[i], "bieber")) {
       printf("%s\n", ADS[i]);
     }
   }
   print("------------------------------------\n");
 }
 ||
 strcmp
 strcmp
 > gcc find.c -o find && ./find
 Search results:
 ------------------------------------
 William: SBM GSOH likes sports, TV, dining
 Josh: SJM likes sports, movies and theater
 ------------------------------------
 >
 int sports_no_bieber(char* s)
 {
   return strstr(s, "sports") && !strstr(s, "bieber");
 }
 void find(      function-name match      )
 {
   int i;
   puts("Search results:");
   puts("------------------------------------");
   for (i = 0; i < NUM_ADS; i++) {
     if (    call-the-match-function    (ADS[i])) {
       printf("%s\n", ADS[i]);
     }
   }
   puts("------------------------------------");
 }
 find(sports_no_bieber);
 find(sports_or_workout);
 find(ns_theater);
 find(arts_theater_or_dining);
 int go_to_warp_speed(int speed)
 {
   dilithium_crystals(ENGAGE);
   warp = speed;
   reactor_core(c, 125000 * speed, PI);
   clutch(DISENGAGE);
   return 0;
 }
 go_to_warp_speed(4);
 int* a;
 function* f;
 int go_to_warp_speed(int speed)
 {
   ...
 }
 char** album_names(char* artist, int year)
 {
   ...
 }
 int (*warp_fn)(int);
 warp_pointer = go_to_warp_speed;
 warp_fn(4);
 char** (*names_fn)(char*,int);
 names_fn = album_names;
 char** results = names_fn("Sacha Distel", 1972);
 |-------------+----+------------------+----+-------------+---|
 | RETURN TYPE | (* | POINTER VARIABLE | )( | PARAM TYPES | ) |
 | char**      | (* | names_fn         | )( | char*,int   |   |
 |-------------+----+------------------+----+-------------+---|
 int sports_no_bieber(char* s)
 {
   return strstr(s, "sports") && !strstr(s, "bieber");
 }
 int sports_or_workout(char* s)
 {
   ________________________________________________________
 }
 int ns_theater(char* s)
 {
   _________________________________________________________
 }
 int arts_theater_or_dining(char* s)
 {
   ________________________________________________________________________
 }
 void find(____________________________)
 {
   int i;
   puts("Search results:");
   puts("------------------------------------");
   for (i = 0; i < NUM_ADS; i++) {
     if (match(ADS[i])) {
       printf("%s\n", ADS[i]);
     }
   }
   puts("------------------------------------");
 }
 int sports_no_bieber(char* s)
 {
   return strstr(s, "sports") && !strstr(s, "bieber");
 }
 int sports_or_workout(char* s)
 {
   return strstr(s, "sports") || strstr(s, "working out");
 }
 int ns_theater(char* s)
 {
   return strstr(s, "NS") && strstr(s, "theater");
 }
 int arts_theater_or_dining(char* s)
 {
   return strstr(s, "arts") || strstr(s, "theater") || strstr(s, "dining");
 }
 void find(int (*match)(char*))
 {
   int i;
   puts("Search results:");
   puts("------------------------------------");
   for (i = 0; i < NUM_ADS; i++) {
     if (match(ADS[i])) {
       printf("%s\n", ADS[i]);
     }
   }
   puts("------------------------------------");
 }
 int main()
 {
   find(sports_no_bieber);
   find(sports_or_workout);
   find(ns_theater);
   find(arts_theater_or_dining);
   return 0;
 }
 > ./find
 Search results:
 ------------------------------------
 William: SBM GSOH likes sports, TV, dining
 Josh: SJM likes sports, movies and theater
 ------------------------------------
 Search results:
 ------------------------------------
 William: SBM GSOH likes sports, TV, dining
 Mike: DWM DS likes trucks, sports and bieber
 Peter: SAM likes chess, working out and art
 Josh: SJM likes sports, movies and theater
 ------------------------------------
 Search results:
 ------------------------------------
 Matt: SWM NS likes art, movies, theater
 ------------------------------------
 Search results:
 ------------------------------------
 William: SBM GSOH likes sports, TV, dining
 Matt: SWM NS likes art, movies, theater
 Luis: SLM ND likes books, theater, art
 Josh: SJM likes sports, movies and theater
 Jed: DBM likes theater, books and dining
 ------------------------------------
 >
 Q: If function pointers are just pointers, why don't you need to prefix them with a '*' when you call the function?
 A: You can. In the program, instead of writing "match(ADS[i])", you could have written "(*match)(ADS[i])".
 Q: And could we have used "&" to get the address of a method?
 A: Yes. Instead of "find(sports_or_workout)" you could have written "find(&sports_or_workout)".
 Q: Then why didn't we?
 A: Because it's very elegant to read code that way. If you skip the "*" and "&" then C will still understand what you're saying.
 Q: But for every ''other'' type of pointer we'll have to use the "*" and "&" operators?
 A: Yes. Function pointers are the only ones that don't need * and &.
  qsort(void *array, size_t length, size_t item_size, int (*compar)(const void *, const void *));
 int scores[] = {543,323,32,554,11,3,112};
 int compare_scores(void* score_a, void* score_b)
 {
   ...
 }
 int a = *(int*)score_a;
 int b = *(int*)score_b;
 return a - b;
 qsort(scores, 7, sizeof(int), compare_scores);
 int compare_scores(void* score_a, void* score_b)
 {
   int a = *(int*)score_a;
   int b = *(int*)score_b;
   return a - b;
 }
 int compare_scores_desc(void* score_a, void* score_b)
 {
   ______________________________________
   ______________________________________
   ______________________________________
   ______________________________________
 }
 typedef struct {
   int width;
   int height;
 } rectangle;
 int compare_areas(void* a, void* b)
 {
   _________________________________________
   _________________________________________
   _________________________________________
   _________________________________________
   _________________________________________
   _________________________________________
 }
 int compare_names(void* a, void* b)
 {
   ___________________________
   ___________________________
   ___________________________
   ___________________________
 }
 int compare_areas_desc(void* a, void* b)
 {
   _____________________________
   _____________________________
 }
 int compare_names_desc(void* a, void* b)
 {
   _____________________________
   _____________________________
 }
 int compare_scores(void* score_a, void* score_b)
 {
   int a = *(int*)score_a;
   int b = *(int*)score_b;
   return a - b;
 }
 int compare_scores_desc(void* score_a, void* score_b)
 {
   int a = *(int*)score_a;
   int b = *(int*)score_b;
   return b - a;
 }
 typedef struct {
   int width;
   int height;
 } rectangle;
 int compare_areas(void* a, void* b)
 {
   rectangle* ra = (rectangle*)a;
   rectangle* rb = (rectangle*)b;
   int area_a = (ra->width * ra->height);
   int area_b = (rb->width * rb->height);
   return area_a - area_b;
 }
 int compare_names(void* a, void* b)
 {
   char** sa = (char**)a;
   char** sb = (char**)b;
   return strcmp(*sa, *sb);
 }
 int compare_areas_desc(void* a, void* b)
 {
   return compare_areas(b, a);
 }
 int compare_names_desc(void* a, void* b)
 {
   return compare_names(b, a);
 }
 #include <stdio.h>
 #include <string.h>
 ...
 int main()
 {
   int scores[] = {543,323,32,554,11,3,112};
   int i;
   qsort(scores, 7, sizeof(int), compare_scores_desc);
   puts("These are the scores in order:");
   for (i = 0; i < 7; i++) {
     printf("Score = %i\n", scores[i]);
   }
   char* names[] = {"Karen", "Mark", "Brett", "Molly"};
   qsort(names, 4, sizeof(char*), compare_names);
   puts("These are the names in order:");
   for (i = 0; i < 4; i++) {
     printf("%s\n", names[i]);
   }
   return 0;
 }
 > ./test_drive
 These are the scores in order:
 Score = 554
 Score = 543
 Score = 323
 Score = 112
 Score = 32
 Score = 11
 Score = 3
 These are the names in order:
 Brett
 Karen
 Mark
 Molly
 > 
 Q: Which is the best sort to use? The quicksort, mergesort or heapsort?
 A: It depends on how ''unsorted'' the data is. Most of the time the different sorts will perform about the same.
 Q: I don't understand the comparator function for the array of strings. What does "char**" mean?
 A: Each item in a string array is a char-pointer (char*). When quicksort calls the comparator function, it sends pointers to 2 elements in the arrays. That means the comparator receives two pointers-to-pointers-to-char. In C notation, each value is a char**.
 Q: OK, but when we call the strcmp function, why does the code say strcmp(*a, *b)? Why not strcmp(a, b)?
 A: a and b are of type char**. The strcmp function needs values of type char*.
 Q: Why does my head hurt?
 A: Don't worry about it. Pointers are really difficult to use sometimes. If you don't find them a little confusing, it probably means you are thinking enough about them.
 enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};
 
 typedef struct {
   char* name;
   enum response_type type;
 } response;
 void dump(response r)
 {
   printf("Dear %s,\n", r.name);
   puts("Unfortunately your last date contacted us to");
   puts("say that they will not be seeing you again");
 }
 void second_chance(response r)
 {
   printf("Dear %s,\n", r.name);
   puts("Good news: your last date has asked us to");
   puts("arrange another meeting. Please call ASAP.");
 }
 void marriage(response r)
 {
   printf("Dear %s,\n", r.name);
   puts("Congratulations! Your last date has contacted");
   puts("us with a proposal of marriage");
 }
 int main()
 {
   response r[] = {
     {"Mike", DUMP}, {"Luis", SECOND_CHANCE},
     {"Matt", SECOND_CHANCE}, {"William", MARRIAGE}
   };
   int i;
   for (i = 0; i < 4; i++) {
     switch(___________) {
     case _______________:
       dump(________);
       break;
     case ___________________:
       second_chance(_________);
       break;
     default:
       marriage(___________);
     }
   }
   return 0;
 }
 r[i].type
 DUMP
 SECOND_CHANCE
 r[i]
 r[i]
 r[i]
 r[i].name
 r[i].name
 r[i].name
 dump
 second_chance
 int main()
 {
   response r[] = {
     {"Mike", DUMP}, {"Luis", SECOND_CHANCE},
     {"Matt", SECOND_CHANCE}, {"William", MARRIAGE}
   };
   int i;
   for (i = 0; i < 4; i++) {
     switch(r[i].type) {
     case DUMP:
       dump(r[i]);
       break;
     case SECOND_CHANCE:
       second_chance(r[i]);
       break;
     default:
       marriage(r[i]);
     }
   }
   return 0;
 }
 r[i].name
 r[i].name
 r[i].name
 dump
 second_chance
 ./send_dear_johns
 Dear Mike,
 Unfortunately your last date contacted us to
 say that they will not be seeing you again
 Dear Luis,
 Good news: your last date has asked us to
 arrange another meeting. Please call ASAP.
 Dear Matt,
 Good news: your last date has asked us to
 arrange another meeting. Please call ASAP.
 Dear William,
 Congratulations! Your last date has contacted
 us with a proposal of marriage
 >
    switch(r.type) {
    case DUMP:
      dump(r);
      break;
    case SECOND_CHANCE:
      second_chance(r);
      break;
    default:
      marriage(r);
    }
 replies[] = {dump, second_chance, marriage};
 void (*replies[])(response) = {dump, second_chance, marriage};
 |------+----+---------+----+---+---+----------+---|
 | void | (* | replies | [] | ) | ( | response | ) |
 |------+----+---------+----+---+---+----------+---|
 enum response_type {DUMP, SECOND_CHANCE, MARRIAGE};
 replies[SECOND_CHANCE] == second_chance
 void (*replies[])(response) = {dump, second_chance, marriage};
 
 int main()
 {
   response r[] = {
     {"Mike", DUMP}, {"Luis", SECOND_CHANCE},
     {"Matt", SECOND_CHANCE}, {"William", MARRIAGE}
   };
   int i;
   for (i = 0; i < 4; i++) {
     ___________________________________
   }
   return 0;
 }
 void (*replies[])(response) = {dump, second_chance, marriage};
 
 int main()
 {
   response r[] = {
     {"Mike", DUMP}, {"Luis", SECOND_CHANCE},
     {"Matt", SECOND_CHANCE}, {"William", MARRIAGE}
   };
   int i;
   for (i = 0; i < 4; i++) {
     (replies[r[i].type])(r[i]);
   }
   return 0;
 }
 |---+----------+-----------+---+----+------+----|
 | ( | replies[ | r[i].type | ] | )( | r[i] | ); |
 |---+----------+-----------+---+----+------+----|
 > ./dear_johns
 Dear Mike,
 Unfortunately your last date contacted us to
 say that they will not be seeing you again
 Dear Luis,
 Good news: your last date has asked us to
 arrange another meeting. Please call ASAP.
 Dear Matt,
 Good news: your last date has asked us to
 arrange another meeting. Please call ASAP.
 Dear William,
 Congratulations! Your last date has contacted
 us with a proposal of marriage
 > 
     (replies[r[i].type])(r[i]);
 enum response_type {DUMP, SECOND_CHANCE, MARRIAGE, LAW_SUIT};
 void (*replies[])(response) = {dump, second_chance, marriage, law_suit};
 Q: Why is the function pointer array syntax so complex?
 A: Because when you declare a function pointer you need say what the return and parameter types. That's why there are so many parentheses.
 Q: This looks a little like the sort of object-oriented code in other languages. Is it?
 A: It's similar. Object-oriented languages associate a set of functions (called methods) with pieces of data. In the same way, you can use function pointers so associate functions with pieces of data.
 Q: Hey - so does that mean that C is object-oriented? Wow - that's awesome.
 A: No. C is not object-oriented, but other languages that are built on C, like Objective-C and C++, create a lot of their object-oriented features by using function pointers under the covers.
 printf("%i bottles of beer on the wall, %i bottles of beer\n", 99, 99);
 printf("Take one down and pass it around, ");
 printf("%i bottles of beer on the wall\n", 98);
 enum drink {
   MUDSLIDE, FUZZY_NAVEL, MONKEY_GLAND, ZOMBIE
 };
 double price(enum drink d)
 {
   switch(d) {
   case MUDSLIDE:
     return 6.79;
   case FUZZY_NAVEL:
     return 5.31;
   case MONKEY_GLAND:
     return 4.82;
   case ZOMBIE:
     return 5.89;
   }
   return 0;
 }
 price(ZOMBIE)
 total(3, ZOMBIE, MONKEY_GLAND, FUZZY_NAVEL)
  print_ints(3, 79, 101, 32);
 #include <stdarg.h>
 void print_ints(int args, ...)
 {
 va_list ap;
 va_start(ap, args);
  int i;
  for (i = 0; i < args; i++) {
    printf("argument: %i\n", va_arg(ap, int));
  }
  va_end(ap);
 }
  print_ints(3, 79, 101, 32);
 Q: Wait - why are va_end() and va_start() called "macros"? Aren't they just normal functions.
 A: No - they are designed to look like ordinary functions, but actually they are replaced by the precompiler with other code.
 Q: And the precompiler is...?
 A: The precompiler runs just before the compilation step. Amongst other things, the precompiler includes the headers into the code.
 Q: Can I have a function with *just* variable arguments - and no variable arguments at all?
 A: No. You need to have at least one fixed argument in order to pass its name to va_start().
 Q: What happens if I try to read more arguments from va_arg() than have been passed in.
 A: Random errors will occur.
 Q: That sounds bad.
 A: Pretty bad.
 Q: What if I try to read an int argument as a double, or something?
 A: Random errors will occur.
   printf("Price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
 double total(int args, ...)
 {
   double total = 0;
   ____________________________________________
   ____________________________________________
   ____________________________________________
   ____________________________________________
   ____________________________________________
   ____________________________________________
   ____________________________________________
   ____________________________________________
   return total;
 }
   printf("Price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
 double total(int args, ...)
 {
   double total = 0;
   va_list ap;
   va_start(ap, args);
   int i;
   for(i = 0; i < args; i++) {
     enum drink d = va_arg(ap, enum drink);
     total += price(d);
   }
   va_end(ap);
   return total;
 }
 main(){
   printf("Price is %.2f\n", total(2, MONKEY_GLAND, MUDSLIDE));
   printf("Price is %.2f\n", total(3, MONKEY_GLAND, MUDSLIDE, FUZZY_NAVEL));
   printf("Price is %.2f\n", total(1, ZOMBIE));
   return 0;
 }
 > ./price_drinks
 Price is 11.61
 Price is 16.92
 Price is 5.89
 > 
