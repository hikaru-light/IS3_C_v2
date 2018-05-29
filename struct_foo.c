#include <stdio.h>
#include <stdlib.h>

  struct foo {
    int i;
    float f;
    char s[16];
  };

  int main () {
    struct foo *ptr;
    ptr = malloc(sizeof(struct foo));

    (*ptr).i = 100;
    ptr -> f = 3.14;
    ptr -> s[0] = 'a';
    ptr -> s[1] = 'b';
    ptr -> s[2] = 'c';
    ptr -> s[3] = 0;

    printf( "%d\n" , ptr -> i );
    printf( "%f\n" , ptr -> f );
    printf( "%s\n" , ptr -> s );
  }
