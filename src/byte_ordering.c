// https://stackoverflow.com/a/10346064/496459
// https://commandcenter.blogspot.com/2012/04/byte-order-fallacy.html

#include <stdint.h>
#include <stdio.h>
// https://stackoverflow.com/a/3168298/496459
#include <inttypes.h>

// These macros are GNU extensions.
#include <byteswap.h>

uint32_t read_from_little_endian (uint32_t value)
{
    const uint8_t* p_data = (uint8_t*)&value;
    return (p_data[0] << 0) | (p_data[1] << 8) | (p_data[2] << 16) | (p_data[3] << 24);
}

uint32_t read_from_big_endian (uint32_t value)
{
    const uint8_t* p_data = (uint8_t*)&value;
    return (p_data[3] << 0) | (p_data[2] << 8) | (p_data[1] << 16) | (p_data[0] << 24);
}

int main (void)
{
    // 4 bytes: 0x01 0x02 0x03 0x04
    // little endian: 0x04 0x03 0x02 0x01 = 67305985
    // big endian:    0x01 0x02 0x03 0x04 = 16909060
    const uint32_t data_little_endian = 67305985;
    const uint32_t data_big_endian = 16909060;

    {
        const uint8_t* p_data = (uint8_t*)&data_little_endian;
        printf ("data[0]=0x%02x\n", p_data[0]);
        printf ("data[0]=0x%02x\n", p_data[1]);
        printf ("data[0]=0x%02x\n", p_data[2]);
        printf ("data[0]=0x%02x\n", p_data[3]);
    }
    printf ("read_from_little_endian (%" PRIu32 ")=%" PRIu32 "\n", data_little_endian, read_from_little_endian (data_little_endian));
    printf ("read_from_little_endian (%" PRIu32 ")=%" PRIu32 "\n", data_big_endian, read_from_little_endian (data_big_endian));

    {
        const uint8_t* p_data = (uint8_t*)&data_big_endian;
        printf ("data[0]=0x%02x\n", p_data[0]);
        printf ("data[0]=0x%02x\n", p_data[1]);
        printf ("data[0]=0x%02x\n", p_data[2]);
        printf ("data[0]=0x%02x\n", p_data[3]);
    }
    printf ("read_from_big_endian (%" PRIu32 ")=%" PRIu32 "\n", data_little_endian, read_from_big_endian (data_little_endian));
    printf ("read_from_big_endian (%" PRIu32 ")=%" PRIu32 "\n", data_big_endian, read_from_big_endian (data_big_endian));

    printf ("bswap_32(%" PRIu32 ")=%" PRIu32 "\n", data_little_endian, bswap_32 (data_little_endian));
    printf ("bswap_32(%" PRIu32 ")=%" PRIu32 "\n", data_big_endian, bswap_32 (data_big_endian));
}
