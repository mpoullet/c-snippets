/* https://nenadsprojects.wordpress.com/2013/01/05/pahole-shows-data-structures-from-debug-data-in-elf-binaries/ */

#include <stdint.h>

#define UNUSED(x) (void)(x)

/* sudo apt install dwarves */
/* pahole bin/pahole */

struct S
{
    struct S* a;
    struct S* b;
    uint8_t c;
    double d;
    int32_t e;
    int32_t f;
    int32_t g;
    uint16_t h;
    uint16_t i;
    float j;
    int16_t k;
    int8_t l;
    double m;
    int32_t n;
    double o;
    int32_t p;
    double q;
};

int main (void)
{
    struct S s;
    UNUSED (s);
    return 0;
}
