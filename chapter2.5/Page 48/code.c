 int main()
 {
   char search_for[80];
   printf("Search for: ");
   fgets(search_for, 80, stdin);
   find_track(search_for);
   return 0;
 }
 char *names_for_dog[] = {"Bowser", "Bonza", "Snodgrass"};
