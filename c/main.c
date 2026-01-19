#include <stdlib.h>
#include <stdio.h>


int main(int argc, char *argv[])
{
  char *p = "hello";    // p is a pointer variable (can reassign)
                        // "hello" in read-only memory
  p = "world";          // OK
  p[0] = 'H';          // OK: array is modifiable
  printf("%s", p );
  char p1[] = "hello";   // p is an array (fixed location)
                        // "hello" copied to stack
//  p1 = "world";          // ERROR: can't assign to array
  p1[0] = 'H';          // OK: array is modifiable


  return EXIT_SUCCESS;
}

