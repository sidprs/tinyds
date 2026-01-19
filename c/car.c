
#include <stdio.h>
#include <stdlib.h>

typedef struct{
  int speed;
  
}Car;

void carAccelerate(Car *car){
  car->speed++;
  printf("%d is the car speed", car->speed);
}

int main(int argc, char *argv[])
{
  Car car = {0};
  carAccelerate(&car);
  return EXIT_SUCCESS;
}
