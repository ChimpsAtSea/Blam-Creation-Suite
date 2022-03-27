#pragma once

#include <blamlib/cseries/cseries_asserts.h>
#include <blamlib/cseries/cseries_memory.h>
#include <blamlib/cseries/cseries_string.h>
#include <blamlib/cseries/cseries_traits.h>

#include <guiddef.h>

/* ---------- constants */

enum : signed char
{
	k_int8_max = 127i8,
	k_int8_min = -k_int8_max - 1i8,
	k_int8_bits = 8i8,
};

enum : unsigned char
{
	k_uint8_max = 255Ui8,
	k_uint8_bits = 8Ui8,
};

enum : short
{
	k_int16_max = 32767i16,
	k_int16_min = -k_int16_max - 1i16,
	k_int16_bits = 16i16,
};

enum : unsigned short
{
	k_uint16_max = 65535Ui16,
	k_uint16_bits = 16Ui16,
};

enum : long
{
	k_int32_max = 2147483647i32,
	k_int32_min = -k_int32_max - 1i32,
	k_int32_bits = 32i32,
};

enum : unsigned long
{
	k_uint32_max = 4294967295Ui32,
	k_uint32_bits = 32Ui32,
};

enum : long long
{
	k_int64_max = 9223372036854775807i64,
	k_int64_min = -k_int64_max - 1i64,
	k_int64_bits = 64i64,
};

enum : unsigned long long
{
	k_uint64_max = 18446744073709551615Ui64,
	k_uint64_bits = 64Ui64,
};

/* ---------- types */

enum e_none_sentinel
{
	NONE = -1
};

typedef unsigned char byte;
static_assert(sizeof(byte) == 0x1);

typedef unsigned short word;
static_assert(sizeof(word) == 0x2);

typedef unsigned long dword;
static_assert(sizeof(dword) == 0x4);

typedef unsigned long long qword;
static_assert(sizeof(qword) == 0x8);

typedef unsigned long tag;
static_assert(sizeof(tag) == 0x4);

typedef long intptr32_t;
static_assert(sizeof(intptr32_t) == 0x4);

typedef long long intptr64_t;
static_assert(sizeof(intptr64_t) == 0x8);

typedef unsigned long uintptr32_t;
static_assert(sizeof(intptr32_t) == 0x4);

typedef unsigned long long uintptr64_t;
static_assert(sizeof(intptr64_t) == 0x8);

/* ---------- macros */

#define NUMBEROF(xs) \
	(sizeof((xs)) / sizeof((xs)[0]))

#define IN_RANGE_INCLUSIVE(value, min, max) \
	(((value) >= (min)) && ((value) <= (max)))

#define MAX_INDEX_WITH_BITS(bits) \
	__pragma(warning(suppress: 4307)) \
	((1 << (bits)) - 1)

#define FLAG(bit) \
	(1U << (bit))

#define TEST_BIT(flags, bit) \
	((flags) & FLAG(bit))

#define SET_FLAG(flags, bit, value) \
	((flags) = ((value) ? ((flags) | FLAG(bit)) : ((flags) & ~FLAG(bit))))

#define VALID_INDEX(index, max_count) \
	__pragma(warning(suppress: 4296)) \
	(((index) >= 0) && ((index) < (max_count)))

#define BIT_VECTOR_SIZE_IN_LONGS(bit_count) \
	(((bit_count) + 31) >> 5)

#define BIT_VECTOR_SIZE_IN_BYTES(bit_count) \
	(BIT_VECTOR_SIZE_IN_LONGS(bit_count) * sizeof(long))

#define BIT_VECTOR_WORD_INDEX(bit) \
	((bit) >> 5)

#define BIT_VECTOR_WORD(vector, bit) \
	((vector)[BIT_VECTOR_WORD_INDEX(bit)])

#define BIT_VECTOR_TEST_FLAG(vector, bit) \
	TEST_BIT(BIT_VECTOR_WORD(vector, bit), (bit) % (sizeof(long) * k_uint8_bits))

#define BIT_VECTOR_SET_FLAG(vector, bit, value) \
	SET_FLAG(BIT_VECTOR_WORD(vector, bit), ((bit) % (sizeof(long) * k_uint8_bits)), value)

#ifdef _WIN64
#define static_assert_64 static_assert
#define static_assert_32(...)
#else
#define static_assert_64(...)
#define static_assert_32 static_assert
#endif


/* ---------- prototypes/CSERIES.CPP */

char *tag_to_string(tag m_value, char *string);
tag string_to_tag(char const *string);
