 Sale today:
 6 apples
 1.5 lb strawberries
 0.5 pint orange juice
 typedef struct {
   ...
   short count;
   float weight;
   float volume;
   ...
 } fruit;
 * It will take up more space in memory.
 * Someone might set more than one value.
 * There's nothing called "quantity".
 |------------+---------+-------------|
 | char* name | int age | float wight |
 |------------+---------+-------------|
 Dog d = {"Buff", 2, 98.5};
 |---------------------------------------|
 | quantity (might be a float or a short) |
 |---------------------------------------|
 typedef union {
   short count;
   float weight;
   float volume;
 } quantity;
 quantity q = {4};
 quantity q = {.weight=1.5};
 quantity q;
 q.float = 3.7;
 typedef struct {
   const char * color;
   int gears;
   int height;
 } bike;
 bike b = {.height=17, .gears=21};
 typedef struct {
   const char* name;
   const char* country;
   quantity amount;
 } fruit_order;
 fruit_order apples = {"apples", "England", .amount.weight=4.2};
 printf("This order contains %2.2f lbs of %s\n", apples.amount.weight, apples.name);
 typedef union {
   float lemon;
   int lime_pieces;
 } lemon_lime;
 
 typedef struct {
   float tequila;
   float cointreau;
   lemon_lime citrus;
 } margarita;
  margarita m = {2.0, 1.0, {0.5}};
  margarita m = {2.0, 1.0, .citrus.lemon=2};
  margarita m = {2.0, 1.0, 0.5};
  margarita m = {2.0, 1.0, {.lime_pieces=1}};
  margarita m = {2.0, 1.0, {1}};
  margarita m = {2.0, 1.0, {2}};
  Name: The Juicy, Juicy
  ______________________________________________________
  printf("%2.1f measures of tequila\n%2.1f measures of cointreau\n%2.1f measures of juice\n",
         m.tequila, m.cointreau, m.citrus.lemon);
 
  2.0 measures of tequila
  1.0 measures of cointreau
  2.0 measures of juice
  Name: The I Can't Feel My Legs
  ______________________________________________________
  printf("%2.1f measures of tequila\n%2.1f measures of cointreau\n%2.1f measures of juice\n",
         m.tequila, m.cointreau, m.citrus.lemon);
 
  2.0 measures of tequila
  1.0 measures of cointreau
  0.5 measures of juice
  Name: The Don't Suck On This
  ______________________________________________________
  printf("%2.1f measures of tequila\n%2.1f measures of cointreau\n%i pieces of lime\n",
         m.tequila, m.cointreau, m.citrus.lime_pieces);
 
  2.0 measures of tequila
  1.0 measures of cointreau
  1 pieces of lime
 margarita m = {2.0, 1.0, {0.5}};
 margarita m;
 m = {2.0, 1.0, {0.5}};
 __________________________________________________________________________________________________________________
 __________________________________________________________________________________________________________________
 __________________________________________________________________________________________________________________
 typedef union {
   float lemon;
   int lime_pieces;
 } lemon_lime;
 
 typedef struct {
   float tequila;
   float cointreau;
   lemon_lime citrus;
 } margarita;
  margarita m = {2.0, 1.0, .citrus.lemon=2};
  margarita m = {2.0, 1.0, 0.5};
  margarita m = {2.0, 1.0, {1}};
  Name: The Juicy, Juicy
  '''margarita m = {2.0, 1.0, {2}};'''
  printf("%2.1f measures of tequila\n%2.1f measures of cointreau\n%2.1f measures of juice\n",
         m.tequila, m.cointreau, m.citrus.lemon);
 
  2.0 measures of tequila
  1.0 measures of cointreau
  2.0 measures of juice
  Name: The I Can't Feel My Legs
  '''margarita m = {2.0, 1.0, {0.5}};'''
  printf("%2.1f measures of tequila\n%2.1f measures of cointreau\n%2.1f measures of juice\n",
         m.tequila, m.cointreau, m.citrus.lemon);
 
  2.0 measures of tequila
  1.0 measures of cointreau
  0.5 measures of juice
  Name: The Don't Suck On This
  '''margarita m = {2.0, 1.0, {.lime_pieces=1}};'''
  printf("%2.1f measures of tequila\n%2.1f measures of cointreau\n%i pieces of lime\n",
         m.tequila, m.cointreau, m.citrus.lime_pieces);
 
  2.0 measures of tequila
  1.0 measures of cointreau
  1 pieces of lime
 margarita m = {2.0, 1.0, {0.5}};
 margarita m;
 m = {2.0, 1.0, {0.5}};
 It doesn't compile because the compiler will only know that {2.0, 1.0, {0.5}} represents a struct if it's use
 on the same line that a struct is declared. When it's on a separate line the compiler thinks it's an '''array'''.
 typedef union {
   float weight;
   int count;
 } muffin;
 
 int main()
 {
   muffin order = {2};
   printf("Muffins quantity: %i\n",
     order.count);
   return 0;
 }
 $ gcc badunion.c -o badunion && ./badunion
 Muffins quantity: 1073741824
 $ 
 enum colors {RED, GREEN, PUCE};
 enum colors favorite = PUCE;
 enum colors favorite = PUSE;
 #include <stdio.h>
 
 typedef enum {
   COUNT, POUNDS, PINTS
 } unit_of_measure;
 
 typedef union {
   short count;
   float weight;
   float volume;
 } quantity;
 
 typedef struct {
   const char* name;
   const char* country;
   quantity amount;
   unit_of_measure units;
 } fruit_order;
 
 void display(fruit_order order)
 {
   printf("This order contains ");
   if (_____________ == PINTS)
     printf("%2.2f pints of %s\n", order.amount.________, order.name);
   else if (_____________ == _______)
     printf("%2.2f lbs of %s\n", order.amount.weight, order.name);
   else
     printf("%i %s\n", order.amount._______, order.name);
 }
 
 int main()
 {
   fruit_order apples = {"apples", "England", .amount.count=144, _______};
   fruit_order strawberries = {"strawberries", "Spain", .amount.________=17.6, POUNDS};
   fruit_order oj = {"orange juice", "U.S.A.", .amount.volume=10.5, _______};
   display(apples);
   display(strawberries);
   display(oj);
   return 0;
 }
 PINTS
 weight
 COUNT
 order.units
 order.units
 volume
 POUNDS
 count
 #include <stdio.h>
 
 typedef enum {
   COUNT, POUNDS, PINTS
 } unit_of_measure;
 
 typedef union {
   short count;
   float weight;
   float volume;
 } quantity;
 
 typedef struct {
   const char* name;
   const char* country;
   quantity amount;
   unit_of_measure units;
 } fruit_order;
 
 void display(fruit_order order)
 {
   printf("This order contains ");
   if ('''order.units''' == PINTS)
     printf("%2.2f pints of %s\n", order.amount.'''volume''', order.name);
   else if ('''order.units''' == '''POUNDS''')
     printf("%2.2f lbs of %s\n", order.amount.weight, order.name);
   else
     printf("%i %s\n", order.amount.'''count''', order.name);
 }
 
 int main()
 {
   fruit_order apples = {"apples", "England", .amount.'''count'''=144, COUNT};
   fruit_order strawberries = {"strawberries", "Spain", .amount.'''weight'''=17.6, POUNDS};
   fruit_order oj = {"orange juice", "U.S.A.", .amount.'''volume'''=10.5, PINTS};
   display(apples);
   display(strawberries);
   display(oj);
   return 0;
 }
 $ gcc enumtest.c -o enumtest
 This order contains 144 apples
 This order contains 17.60 lbs of strawberries
 This order contains 10.50 pints of orange juice
 $ 
