#include "platform-private-pch.h"

#if defined(__clang__)

#elif defined(_MSC_VER)

#define COERCE_FUNCTION3(function, type, a, b, c) function(reinterpret_cast<volatile type*>(a), static_cast<type>(b), static_cast<type>(c))
#define COERCE_FUNCTION2(function, type, a, b) function(reinterpret_cast<volatile type*>(a), static_cast<type>(b))
#define COERCE_FUNCTION1(function, type, a) function(reinterpret_cast<volatile type*>(a))

int32_t atomic_cmpxchg32(int32_t volatile* destination, int32_t exchange, int32_t comparand)
{
	return COERCE_FUNCTION3(InterlockedCompareExchange, LONG, destination, exchange, comparand);
}
int64_t atomic_cmpxchg64(int64_t volatile* destination, int64_t exchange, int64_t comparand)
{
	return COERCE_FUNCTION3(InterlockedCompareExchange64, LONG64, destination, exchange, comparand);
}
void* atomic_cmpxchgptr(void* volatile* destination, void* exchange, void* comparand)
{
	return InterlockedCompareExchangePointer(destination, exchange, comparand);
}
int32_t atomic_xchg32(int32_t volatile* destination, int32_t exchange)
{
	return COERCE_FUNCTION2(InterlockedExchange, LONG, destination, exchange);
}
int64_t atomic_xchg64(int64_t volatile* destination, int64_t exchange)
{
	return COERCE_FUNCTION2(InterlockedExchange64, LONG64, destination, exchange);
}
void* atomic_xchgptr(void* volatile* destination, void* exchange)
{
	return InterlockedExchangePointer(destination, exchange);
}
int32_t atomic_add32(int32_t volatile* addend, int32_t value)
{
	return COERCE_FUNCTION2(InterlockedExchangeAdd, LONG, addend, value);
}
int64_t atomic_add64(int64_t volatile* addend, int64_t value)
{
	return COERCE_FUNCTION2(InterlockedExchangeAdd64, LONG64, addend, value);
}

void* atomic_addptr(void* volatile* addend, intptr_t count, size_t element_size)
{
	LONG64 value = count * static_cast<LONG64>(element_size);
	LONG64 result = InterlockedExchangeAdd64((LONG64 volatile*)addend, value);
	return reinterpret_cast<void*>(result);
}

int32_t atomic_sub32(int32_t volatile* addend, int32_t value)
{
	return COERCE_FUNCTION2(InterlockedExchangeAdd, LONG, addend, -value);
}

int64_t atomic_sub64(int64_t volatile* addend, int64_t value)
{
	return COERCE_FUNCTION2(InterlockedExchangeAdd64, LONG64, addend, -value);
}

void* atomic_subptr(void* volatile* addend, intptr_t count, size_t element_size)
{
	LONG64 value = count * static_cast<LONG64>(element_size);
	LONG64 result = InterlockedExchangeAdd64((LONG64 volatile*)addend, -value);
	return reinterpret_cast<void*>(result);
}

int32_t atomic_inc32(int32_t volatile* value)
{
	return COERCE_FUNCTION1(InterlockedIncrement, LONG, value) - 1;
}
int64_t atomic_inc64(int64_t volatile* value)
{
	return COERCE_FUNCTION1(InterlockedIncrement64, LONG64, value) - 1;
}
int32_t atomic_dec32(int32_t volatile* value)
{
	return COERCE_FUNCTION1(InterlockedDecrement, LONG, value);
}
int64_t atomic_dec64(int64_t volatile* value)
{
	return COERCE_FUNCTION1(InterlockedDecrement64, LONG64, value);
}

uint32_t atomic_cmpxchgu32(uint32_t volatile* destination, uint32_t exchange, uint32_t comparand)
{
	return COERCE_FUNCTION3(InterlockedCompareExchange, ULONG, destination, exchange, comparand);
}
uint64_t atomic_cmpxchgu64(uint64_t volatile* destination, uint64_t exchange, uint64_t comparand)
{
	return COERCE_FUNCTION3(InterlockedCompareExchange64, LONG64, destination, exchange, comparand);
}
uint32_t atomic_xchgu32(uint32_t volatile* destination, uint32_t exchange)
{
	return COERCE_FUNCTION2(InterlockedExchange, ULONG, destination, exchange);
}
uint64_t atomic_xchgu64(uint64_t volatile* destination, uint64_t exchange)
{
	return COERCE_FUNCTION2(InterlockedExchange64, LONG64, destination, exchange);
}
uint32_t atomic_addu32(uint32_t volatile* addend, uint32_t value)
{
	return COERCE_FUNCTION2(InterlockedExchangeAdd, LONG, addend, value);
}
uint64_t atomic_addu64(uint64_t volatile* addend, uint64_t value)
{
	return COERCE_FUNCTION2(InterlockedExchangeAdd64, LONG64, addend, value);
}
uint32_t atomic_subu32(uint32_t volatile* addend, uint32_t value)
{
	return COERCE_FUNCTION2(InterlockedExchangeAdd, LONG, addend, -value);
}
uint64_t atomic_subu64(uint64_t volatile* addend, uint64_t value)
{
	return COERCE_FUNCTION2(InterlockedExchangeAdd64, LONG64, addend, -value);
}
uint32_t atomic_incu32(uint32_t volatile* value)
{
	return COERCE_FUNCTION1(InterlockedIncrement, ULONG, value) - 1;
}
uint64_t atomic_incu64(uint64_t volatile* value)
{
	return COERCE_FUNCTION1(InterlockedIncrement64, LONG64, value) - 1;
}
uint32_t atomic_decu32(uint32_t volatile* value)
{
	return COERCE_FUNCTION1(InterlockedDecrement, ULONG, value);
}
uint64_t atomic_decu64(uint64_t volatile* value)
{
	return COERCE_FUNCTION1(InterlockedDecrement64, LONG64, value);
}

#undef COERCE_FUNCTION3
#undef COERCE_FUNCTION2
#undef COERCE_FUNCTION1

#else
#error Compiler not supported
#endif

int atomic_bittestandreset32(volatile int32_t* p, int32_t i)
{
	int32_t mask = 1i32 << (i % 32); // Compute the mask for the bit to test and reset
	int32_t old_val = atomic_and32(p, ~mask); // Clear the bit and get the old value
	int bit_set = (old_val & mask) != 0; // Check if the bit was set before clearing it
	return bit_set; // Return the old value of the bit
}

int atomic_bittestandset32(volatile int32_t* p, int32_t i)
{
	int32_t mask = 1i32 << (i % 32); // Compute the mask for the bit to test and set
	int32_t old_val = atomic_or32(p, mask); // Set the bit and get the old value
	int bit_set = (old_val & mask) != 0; // Check if the bit was set before setting it
	return bit_set; // Return the old value of the bit
}

int atomic_bittestandreset64(volatile int64_t* p, int64_t i)
{
	int64_t mask = 1i64 << (i % 64); // Compute the mask for the bit to test and reset
	int64_t old_val = atomic_and64(p, ~mask); // Clear the bit and get the old value
	int bit_set = (old_val & mask) != 0; // Check if the bit was set before clearing it
	return bit_set; // Return the old value of the bit
}

int atomic_bittestandset64(volatile int64_t* p, int64_t i)
{
	int64_t mask = 1i64 << (i % 64); // Compute the mask for the bit to test and set
	int64_t old_val = atomic_or64(p, mask); // Set the bit and get the old value
	int bit_set = (old_val & mask) != 0; // Check if the bit was set before setting it
	return bit_set; // Return the old value of the bit
}

int32_t atomic_max32(int32_t volatile* target, int32_t value)
{
	int32_t expected_target_value = *target;
	while (atomic_cmpxchg32(target, __max(expected_target_value, value), expected_target_value) != expected_target_value)
	{
		expected_target_value = *target;
	}
	return expected_target_value;
}

int64_t atomic_max64(int64_t volatile* target, int64_t value)
{
	int64_t expected_target_value = *target;
	while (atomic_cmpxchg64(target, __max(expected_target_value, value), expected_target_value) != expected_target_value)
	{
		expected_target_value = *target;
	}
	return expected_target_value;
}

int32_t atomic_min32(int32_t volatile* target, int32_t value)
{
	int32_t expected_target_value = *target;
	while (atomic_cmpxchg32(target, __min(expected_target_value, value), expected_target_value) != expected_target_value)
	{
		expected_target_value = *target;
	}
	return expected_target_value;
}

int64_t atomic_min64(int64_t volatile* target, int64_t value)
{
	int64_t expected_target_value = *target;
	while (atomic_cmpxchg64(target, __min(expected_target_value, value), expected_target_value) != expected_target_value)
	{
		expected_target_value = *target;
	}
	return expected_target_value;
}

uint32_t atomic_maxu32(uint32_t volatile* target, uint32_t value)
{
	uint32_t expected_target_value = *target;
	while (atomic_cmpxchgu32(target, __max(expected_target_value, value), expected_target_value) != expected_target_value)
	{
		expected_target_value = *target;
	}
	return expected_target_value;
}

uint64_t atomic_maxu64(uint64_t volatile* target, uint64_t value)
{
	uint64_t expected_target_value = *target;
	while (atomic_cmpxchgu64(target, __max(expected_target_value, value), expected_target_value) != expected_target_value)
	{
		expected_target_value = *target;
	}
	return expected_target_value;
}

uint32_t atomic_minu32(uint32_t volatile* target, uint32_t value)
{
	uint32_t expected_target_value = *target;
	while (atomic_cmpxchgu32(target, __min(expected_target_value, value), expected_target_value) != expected_target_value)
	{
		expected_target_value = *target;
	}
	if (*target == UINT_MAX)
	{
		debug_point;
	}
	return expected_target_value;
}

uint64_t atomic_minu64(uint64_t volatile* target, uint64_t value)
{
	uint64_t expected_target_value = *target;
	while (atomic_cmpxchgu64(target, __min(expected_target_value, value), expected_target_value) != expected_target_value)
	{
		expected_target_value = *target;
	}
	return expected_target_value;
}

void* atomic_maxuptr(void* volatile* target, void* value)
{
	void* expected_target_value = *target;
	while (atomic_cmpxchgptr(target, __max(expected_target_value, value), expected_target_value) != expected_target_value)
	{
		expected_target_value = *target;
	}
	return expected_target_value;
}

void* atomic_minuptr(void* volatile* target, void* value)
{
	void* expected_target_value = *target;
	while (atomic_cmpxchgptr(target, __min(expected_target_value, value), expected_target_value) != expected_target_value)
	{
		expected_target_value = *target;
	}
	return expected_target_value;
}

void* atomic_incptr(void* volatile* addend, size_t value_size)
{
	return atomic_addptr(addend, 1, value_size);
}

void* atomic_decptr(void* volatile* addend, size_t value_size)
{
	return atomic_subptr(addend, 1, value_size);
}
