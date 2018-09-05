#ifndef BSWAP_H
#define BSWAP_H

/* clang-format off */

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdint.h>

#ifdef __GNUC__ /* GCC and Clang */
#include <byteswap.h>
uint64_t bswap64 (uint64_t x) { return bswap_64 (x); }
uint32_t bswap32 (uint32_t x) { return bswap_32 (x); }
uint16_t bswap16 (uint16_t x) { return bswap_16 (x); }
#elif _MSC_VER
#include <stdlib.h>
uint64_t bswap64 (uint64_t x) { return _byteswap_uint64 (x); }
uint32_t bswap32 (uint32_t x) { return _byteswap_ulong (x); }
uint16_t bswap16 (uint16_t x) { return _byteswap_ushort (x); }
#else
#define bswap16(x) (((x) << 8) & 0xff00)
                 | (((x) >> 8) & 0x00ff)
#define bswap32(x) (((x) << 24) & 0xff000000) \
                 | (((x) << 8)  & 0x00ff0000) \
                 | (((x) >> 8)  & 0x0000ff00) \
                 | (((x) >> 24) & 0x000000ff)
#define bswap64(x) ((((x) & 0xff00000000000000ull) >> 56) \
                  | (((x) & 0x00ff000000000000ull) >> 40) \
                  | (((x) & 0x0000ff0000000000ull) >> 24) \
                  | (((x) & 0x000000ff00000000ull) >> 8)  \
                  | (((x) & 0x00000000ff000000ull) << 8)  \
                  | (((x) & 0x0000000000ff0000ull) << 24) \
                  | (((x) & 0x000000000000ff00ull) << 40) \
                  | (((x) & 0x00000000000000ffull) << 56))
#endif

#ifdef __cplusplus
}
#endif

#endif /* BSWAP_H */
