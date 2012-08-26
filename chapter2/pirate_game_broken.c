#include <stdio.h>

void go_south_east(int lat, int lon)
{
  lat = lat - 1;
  lon = lon + 1;
}

int main()
{
  int latitude = 32;
  int longitude = -64;
  go_south_east(latitude, longitude);
  printf("Avast! Now at: [%i, %i]\n", latitude, longitude);
  return 0;
}
