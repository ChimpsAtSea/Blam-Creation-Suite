#pragma once

#if defined(BCS_WIN32) || defined(_WIN32)

BCS_SHARED int32_t atomic_cmpxchg32(int32_t volatile* destination, int32_t exchange, int32_t comparand);
BCS_SHARED int64_t atomic_cmpxchg64(int64_t volatile* destination, int64_t exchange, int64_t comparand);
BCS_SHARED int32_t atomic_xchg32(int32_t volatile* destination, int32_t exchange);
BCS_SHARED int64_t atomic_xchg64(int64_t volatile* destination, int64_t exchange);
BCS_SHARED int32_t atomic_add32(int32_t volatile* addend, int32_t value);
BCS_SHARED int64_t atomic_add64(int64_t volatile* addend, int64_t value);
BCS_SHARED int32_t atomic_inc32(int32_t volatile* value);
BCS_SHARED int64_t atomic_inc64(int64_t volatile* value);
BCS_SHARED int32_t atomic_dec32(int32_t volatile* value);
BCS_SHARED int64_t atomic_dec64(int64_t volatile* value);

BCS_SHARED uint32_t atomic_cmpxchgu32(uint32_t volatile* destination, uint32_t exchange, uint32_t comparand);
BCS_SHARED uint64_t atomic_cmpxchgu64(uint64_t volatile* destination, uint64_t exchange, uint64_t comparand);
BCS_SHARED uint32_t atomic_xchgu32(uint32_t volatile* destination, uint32_t exchange);
BCS_SHARED uint64_t atomic_xchgu64(uint64_t volatile* destination, uint64_t exchange);
BCS_SHARED uint32_t atomic_addu32(uint32_t volatile* addend, uint32_t value);
BCS_SHARED uint64_t atomic_addu64(uint64_t volatile* addend, uint64_t value);
BCS_SHARED uint32_t atomic_incu32(uint32_t volatile* value);
BCS_SHARED uint64_t atomic_incu64(uint64_t volatile* value);
BCS_SHARED uint32_t atomic_decu32(uint32_t volatile* value);
BCS_SHARED uint64_t atomic_decu64(uint64_t volatile* value);

#elif defined(__GNUC__) || defined(__clang__)

static inline int32_t atomic_cmpxchg32(
	int32_t volatile* destination,
	int32_t exchange,
	int32_t comparand)
{
	return __sync_val_compare_and_swap(destination, exchange, comparand);
}

static inline int64_t atomic_cmpxchg64(
	int64_t volatile* destination,
	int64_t exchange,
	int64_t comparand)
{
	return __sync_val_compare_and_swap(destination, exchange, comparand);
}

static inline int32_t atomic_xchg32(
	int32_t volatile* destination,
	int32_t exchange)
{
	return  __sync_lock_test_and_set(destination, exchange);
}

static inline int64_t atomic_xchg64(
	int64_t volatile* destination,
	int64_t exchange)
{
	return  __sync_lock_test_and_set(destination, exchange);
}

static inline int32_t atomic_add32(
	int32_t volatile* addend,
	int32_t value)
{
	return __sync_add_and_fetch(addend, value);
}

static inline int64_t atomic_add64(
	int64_t volatile* addend,
	int64_t value)
{
	return __sync_add_and_fetch(addend, value);
}

static inline int32_t atomic_inc32(int32_t volatile* value)
{
	return __sync_add_and_fetch(value, 1);
}

static inline int64_t atomic_inc64(int64_t volatile* value)
{
	return __sync_add_and_fetch(value, 1);
}

static inline int32_t atomic_dec32(int32_t volatile* value)
{
	return __sync_sub_and_fetch(value, 1);
}

static inline int64_t atomic_dec64(int64_t volatile* value)
{
	return __sync_sub_and_fetch(value, 1);
}

static inline uint32_t atomic_cmpxchgu32(
	uint32_t volatile* destination,
	uint32_t exchange,
	uint32_t comparand)
{
	return __sync_val_compare_and_swap(destination, exchange, comparand);
}

static inline uint64_t atomic_cmpxchgu64(
	uint64_t volatile* destination,
	uint64_t exchange,
	uint64_t comparand)
{
	return __sync_val_compare_and_swap(destination, exchange, comparand);
}

static inline uint32_t atomic_xchgu32(
	uint32_t volatile* destination,
	uint32_t exchange)
{
	return  __sync_lock_test_and_set(destination, exchange);
}

static inline uint64_t atomic_xchgu64(
	uint64_t volatile* destination,
	uint64_t exchange)
{
	return  __sync_lock_test_and_set(destination, exchange);
}

static inline uint32_t atomic_addu32(
	uint32_t volatile* addend,
	uint32_t value)
{
	return __sync_add_and_fetch(addend, value);
}

static inline uint64_t atomic_addu64(
	uint64_t volatile* addend,
	uint64_t value)
{
	return __sync_add_and_fetch(addend, value);
}

static inline uint32_t atomic_incu32(uint32_t volatile* value)
{
	return __sync_add_and_fetch(value, 1);
}

static inline uint64_t atomic_incu64(uint64_t volatile* value)
{
	return __sync_add_and_fetch(value, 1);
}

static inline uint32_t atomic_decu32(uint32_t volatile* value)
{
	return __sync_sub_and_fetch(value, 1);
}

static inline uint64_t atomic_decu64(uint64_t volatile* value)
{
	return __sync_sub_and_fetch(value, 1);
}

#endif
