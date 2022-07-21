#include "platform-private-pch.h"

#if defined(BCS_WIN32) || defined(_WIN32)

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
int32_t atomic_xchg32(int32_t volatile* destination, int32_t exchange)
{
	return COERCE_FUNCTION2(InterlockedExchange, LONG, destination, exchange);
}
int64_t atomic_xchg64(int64_t volatile* destination, int64_t exchange)
{
	return COERCE_FUNCTION2(InterlockedExchange64, LONG64, destination, exchange);
}
int32_t atomic_add32(int32_t volatile* addend, int32_t value)
{
	return COERCE_FUNCTION2(InterlockedAdd, LONG, addend, value);
}
int64_t atomic_add64(int64_t volatile* addend, int64_t value)
{
	return COERCE_FUNCTION2(InterlockedAdd64, LONG64, addend, value);
}
int32_t atomic_inc32(int32_t volatile* value)
{
	return COERCE_FUNCTION1(InterlockedIncrement, LONG, value);
}
int64_t atomic_inc64(int64_t volatile* value)
{
	return COERCE_FUNCTION1(InterlockedIncrement64, LONG64, value);
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
	return COERCE_FUNCTION2(InterlockedAdd, LONG, addend, value);
}
uint64_t atomic_addu64(uint64_t volatile* addend, uint64_t value)
{
	return COERCE_FUNCTION2(InterlockedAdd64, LONG64, addend, value);
}
uint32_t atomic_incu32(uint32_t volatile* value)
{
	return COERCE_FUNCTION1(InterlockedIncrement, ULONG, value);
}
uint64_t atomic_incu64(uint64_t volatile* value)
{
	return COERCE_FUNCTION1(InterlockedIncrement64, LONG64, value);
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

#endif
