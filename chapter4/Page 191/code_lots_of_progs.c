 /* Print out the catalog entry */
 void catalog(const char* name, const char* species, int teeth, int age)
 {
   printf("%s is a %s with %i teeth. He is %i\n",
     name, species, teeth, age);
 }
 
 /* Print the label for the tank */
 void label(const char* name, const char* species, int teeth, int age)
 {
   printf("Name:%s\nSpecies:%s\n%i years old, %i teeth\n",
     name, species, teeth, age);
 }
 int main()
 {
   catalog("Snappy", "Piranha", 69, 4);
   label("Snappy", "Piranha", 69, 4);
   return 0;
 }
 struct fish {
   const char* name;
   const char* species;
   int teeth;
   int age;
 };
 struct fish snappy = {"Snappy", "Piranha", 69, 4};
 /* Print out the catalog entry */
 void catalog(struct fish f)
 {
   ...
 }
 
 /* Print the label for the tank */
 void label(struct fish f)
 {
   ...
 }
 struct fish snappy = {"Snappy", "Piranha", 69, 4};
 catalog(snappy);
 label(snappy);
 struct fish snappy = {"Snappy", "piranha", 69, 4};
 printf("Name = %s\n", snappy[0]);
 $ gcc fish.c -o fish
 fish.c: In function ��main��:
 fish.c:12: error: subscripted value is neither array nor pointer
 $
  struct fish snappy = {"Snappy", "piranha", 69, 4};
  printf("Name = %s\n", snappy.name);
 $ gcc fish.c -o fish
 $ ./fish
 Name = Snappy
 $
 void catalog(struct fish f)
 {
   printf("%s is a %s with %i teeth. He is %i\n",
     ___.________, ___.___________, ___.________, ___._______);
 }
 
 int main()
 {
   struct fish snappy = {"Snappy", "Piranha", 69, 4};
   catalog(snappy);
   /* We're skipping calling label for now */
   return 0;
 }
 name
 species
 teeth
 age
 f
 f
 f
 f
 fish
 fish
 fish
 fish
 *
 *
 void catalog(struct fish f)
 {
   printf("%s is a %s with %i teeth. He is %i\n",
     '''a'''.'''name''', '''a'''.'''species''', '''a'''.'''teeth''', '''a'''.'''age''');
 }
 
 int main()
 {
   struct fish snappy = {"Snappy", "Piranha", 69, 4};
   catalog(snappy);
   /* We're skipping calling label for now */
   return 0;
 }
 fish
 fish
 fish
 fish
 *
 *
 $ make pool_puzzle && ./pool_puzzle
 gcc pool_puzzle.c -o pool_puzzle
 Snappy is a Piranha with 69 teeth. He is 4
 Name:Snappy
 Species:Piranha
 4 years old, 69 teeth
 $ 
 label(snappy);
 catalog(snappy);
 Q:So is a struct just an array?
 A:No - but like an array it groups a number of pieces of data together.
 Q:An array variable is just a pointer to the array. Is a struct variable a pointer to a struct?
 A:No. A struct variable is a name for the struct itself.
 Q:I know I don't have to, but ''could'' I use [0], [1],... to access the fields of a struct?
 A:No - you can only access fields by name.
 Q:Are structs like classes in other languages?
 A:They are similar, but it's not so easy to add methods to structs.
 struct fish {
   const char* name;
   const char* species;
   int teeth;
   int age;
 };
 struct fish snappy = {"Snappy", "Piranha", 69, 4};
 |-------+----------+----+---|
 | *name | *species | 69 | 4 |
 |-------+----------+----+---|
 "Snappy"
 "Piranha"
 struct fish snappy = {"Snappy", "Piranha", 69, 4};
 struct fish gnasher = snappy;
 |-------+----------+----+---|
 | *name | *species | 69 | 4 |
 |-------+----------+----+---|
 |-------+----------+----+---|
 | *name | *species | 69 | 4 |
 |-------+----------+----+---|
 "Snappy"
 "Piranha"
 struct preferences {
   const char* food;
   float exercise_hours;
 };
 
 struct fish {
   const char* name;
   const char* species;
   int teeth;
   int age;
   struct preferences care;
 };
 struct fish snappy = {"Snappy", "Piranha", 69, 4, {"Meat", 7.5}};
 printf("Snappy likes to eat %s", snappy.care.food);
 printf("Snappy likes to exercise for %f hours", snappy.care.exercise_hours);
 struct exercise {
   const char* description;
   float duration;
 };
 
 struct meal {
   const char* ingredients;
   float weight;
 };
 
 struct preferences {
   struct meal food;
   struct exercise exercise;
 };
 
 struct fish {
   const char* name;
   const char* species;
   int teeth;
   int age;
   struct preferences care;
 };
  Name: Snappy
  Species: Piranha
  Food ingredients: meat
  Food weight: 0.2 lbs
  Exercise description: swim in the jacuzzi
  Exercise duration 7.5 hours
   struct fish snappy = _____________________________________________________
 Name:Snappy
 Species:Piranha
 4 years old, 69 teeth
 Feed with 0.20 lbs of meat and allow to swim in the jacuzzi for 7.50 hours
 void label(struct fish a)
 {
   printf("Name:%s\nSpecies:%s\n%i years old, %i teeth\n",
          a.name, a.species, a.teeth, a.age);
   printf("Feed with %2.2f lbs of %s and allow to %s for %2.2f hours\n",
          __________________, _____________________,
          _____________________, ____________________);
 }
 struct exercise {
   const char* description;
   float duration;
 };
 
 struct meal {
   const char* ingredients;
   float weight;
 };
 
 struct preferences {
   struct meal food;
   struct exercise exercise;
 };
 
 struct fish {
   const char* name;
   const char* species;
   int teeth;
   int age;
   struct preferences care;
 };
  Name: Snappy
  Species: Piranha
  Food ingredients: meat
  Food weight: 0.2 lbs
  Exercise description: swim in the jacuzzi
  Exercise duration 7.5 hours
   struct fish snappy = ''{"Snappy", "Piranha", 69, 4, {{"meat", 0.2}, {"swim in the jacuzzi", 7.5}}};''
 Name:Snappy
 Species:Piranha
 4 years old, 69 teeth
 Feed with 0.20 lbs of meat and allow to swim in the jacuzzi for 7.50 hours
 void label(struct fish a)
 {
   printf("Name:%s\nSpecies:%s\n%i years old, %i teeth\n",
          a.name, a.species, a.age, a.teeth);
   printf("Feed with %2.2f lbs of %s and allow to %s for %2.2f hours\n",
          ''a.care.food.weight'', ''a.care.food.ingredients'',
          ''a.care.exercise.description'', ''a.care.exercise.duration);''
 }
 struct cell_phone {
   int cell_no;
   const char * wallpaper;
   float minutes_of_charge;
 };
 ...
 struct cell_phone p = {5557879, "sinatra.png", 1.35};
 typedef struct cell_phone {
   int cell_no;
   const char * wallpaper;
   float minutes_of_charge;
 } phone;
 ...
 phone p = {5557879, "sinatra.png", 1.35};
 typedef struct {
   int cell_no;
   const char * wallpaper;
   float minutes_of_charge;
 } '''phone''';
 phone p = {5557879, "sinatra.png", 1.35};
 #include <stdio.h>
  
 _________ struct {
   float tank_capacity;
   int tank_psi;
   const char* suit_material;
 } ___________;
  
 _________ struct scuba {
   const char* name;
   equipment kit;
 } diver;
  
 void badge(_____ d)
 {
   printf("Name: %s Tank: %2.2f(%i) Suit: %s\n",
     d.name, d.kit.tank_capacity, d.kit.tank_psi, d.kit.suit_material);
 }
  
 int main()
 {
   _______ randy = {"Randy", {5.5, 3500, "Neoprene"}};
   badge(randy);
   return 0;
 }
 #include <stdio.h>
  
 typedef struct {
   float tank_capacity;
   int tank_psi;
   const char* suit_material;
 } equipment;
  
 typedef struct scuba {
   const char* name;
   equipment kit;
 } diver;
  
 void badge(diver d)
 {
   printf("Name: %s Tank: %2.2f(%i) Suit: %s\n",
     d.name, d.kit.tank_capacity, d.kit.tank_psi, d.kit.suit_material);
 }
  
 int main()
 {
   diver randy = {"Randy", {5.5, 3500, "Neoprene"}};
   badge(randy);
   return 0;
 }
