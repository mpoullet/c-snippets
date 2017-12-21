/* See: https://stackoverflow.com/a/19487645/496459 */

#include <stddef.h>

#define UNUSED(x) (void)(x)

void *get_pointer() { return NULL; }

int main(int argc, char *argv[]) {
  UNUSED(argc);
  UNUSED(argv);

  void *(*function_pointer_1)();
  void *(*function_pointer_2)();

  /* warning: ISO C forbids assignment between function pointer and ‘void *’
   * [-Wpedantic] */
  UNUSED(function_pointer_1);
  // function_pointer_1 = get_pointer();
  /* no warning: as seen in Kerrisk's The Linux Programming Interface: */
  /* 42.1.3 Obtaining the Address of a Symbol dlsym() pp. 865 */
  *(void **)(&function_pointer_2) = get_pointer();
}
