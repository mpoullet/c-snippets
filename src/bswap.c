#include <inttypes.h>
#include <stdio.h>

#include "bswap.h"

int main (void)
{
    const uint32_t data_little_endian = 67305985;
    const uint32_t data_big_endian = 16909060;

    printf ("bswap32(%" PRIu32 ")=%" PRIu32 "\n", data_little_endian, bswap32 (data_little_endian));
    printf ("bswap32(%" PRIu32 ")=%" PRIu32 "\n", data_big_endian, bswap32 (data_big_endian));
}