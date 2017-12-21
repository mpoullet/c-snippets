/* for cstd in c89 c90 c99 c11; do gcc -std=${cstd} -Wall -Wextra -pedantic -o
 * array_len array_len.c && ./array_len ; done */

#include <stdio.h>

int main(void) {
  int array[] = {0, 0, 0};
  int array_len = sizeof(array) / sizeof(array[0]);

  printf("array_len=%d\n", array_len);
  return 0;
}
