
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    char *p3 = (char *)malloc(0);
    strcpy(p3, "hello");
    p3[0] = 'h\0';  //  OK
    printf("p3 points to heap: %s\n", p3);
    free(p3);

  return EXIT_SUCCESS;
}

