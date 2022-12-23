#pragma once

#include <intrin.h>
#include <mmintrin.h>
#include <xmmintrin.h>
#include <emmintrin.h>
#include <pmmintrin.h>
#include <tmmintrin.h>
#include <smmintrin.h>
#include <nmmintrin.h>
//#include <ammintrin.h>
//#include <wmmintrin.h>
#include <immintrin.h>

#define __int128 __m128

#if defined(BCS_WIN32) || defined(_WIN32)

BCS_SHARED bool bit_scan_forward32(int32_t* index, int32_t mask);
BCS_SHARED bool bit_scan_forward64(int32_t* index, int64_t mask);
BCS_SHARED bool bit_scan_forwardu32(uint32_t* index, uint32_t mask);
BCS_SHARED bool bit_scan_forwardu64(uint32_t* index, uint64_t mask);
BCS_SHARED bool bit_scan_reverse32(int32_t* index, int32_t mask);
BCS_SHARED bool bit_scan_reverse64(int32_t* index, int64_t mask);
BCS_SHARED bool bit_scan_reverseu32(uint32_t* index, uint32_t mask);
BCS_SHARED bool bit_scan_reverseu64(uint32_t* index, uint64_t mask);

#pragma intrinsic(_byteswap_ushort)
#pragma intrinsic(_byteswap_ulong)
#pragma intrinsic(_byteswap_uint64)

#elif defined(__GNUC__) || defined(__clang__)

static inline bool bit_scan_forward32(int32_t* index, int32_t mask) { todo; }
static inline bool bit_scan_forward64(int32_t* index, int64_t mask) { todo; }
static inline bool bit_scan_forwardu32(int32_t* index, int32_t mask) { todo; }
static inline bool bit_scan_forwardu64(int32_t* index, int64_t mask) { todo; }
static inline bool bit_scan_reverse32(uint32_t* index, uint32_t mask) { todo; }
static inline bool bit_scan_reverse64(uint32_t* index, uint64_t mask) { todo; }
static inline bool bit_scan_reverseu32(uint32_t* index, uint32_t mask) { todo; }
static inline bool bit_scan_reverseu64(uint32_t* index, uint64_t mask) { todo; }

#define _byteswap_ushort __builtin_bswap16
#define _byteswap_ulong __builtin_bswap32
#define _byteswap_uint64 __builtin_bswap64

#endif
