#pragma once

BCS_SHARED int32_t atomic_max32(int32_t volatile* target, int32_t value);
BCS_SHARED int64_t atomic_max64(int64_t volatile* target, int64_t value);
BCS_SHARED int32_t atomic_min32(int32_t volatile* target, int32_t value);
BCS_SHARED int64_t atomic_min64(int64_t volatile* target, int64_t value);

BCS_SHARED uint32_t atomic_maxu32(uint32_t volatile* target, uint32_t value);
BCS_SHARED uint64_t atomic_maxu64(uint64_t volatile* target, uint64_t value);
BCS_SHARED uint32_t atomic_minu32(uint32_t volatile* target, uint32_t value);
BCS_SHARED uint64_t atomic_minu64(uint64_t volatile* target, uint64_t value);

BCS_SHARED void* atomic_maxptr(void* volatile* target, void* value);
BCS_SHARED void* atomic_minptr(void* volatile* target, void* value);
BCS_SHARED void* atomic_incptr(void* volatile* addend, size_t element_size);
BCS_SHARED void* atomic_decptr(void* volatile* addend, size_t element_size);

BCS_SHARED int atomic_bittestandreset32(volatile int32_t* p, int32_t i);
BCS_SHARED int atomic_bittestandset32(volatile int32_t* p, int32_t i);
BCS_SHARED int atomic_bittestandreset64(volatile int64_t* p, int64_t i);
BCS_SHARED int atomic_bittestandset64(volatile int64_t* p, int64_t i);

#if defined(__clang__)

static inline int32_t atomic_cmpxchg32(
	int32_t volatile* destination,
	int32_t exchange,
	int32_t comparand)
{
	return __sync_val_compare_and_swap(destination, comparand, exchange);
}

static inline int64_t atomic_cmpxchg64(
	int64_t volatile* destination,
	int64_t exchange,
	int64_t comparand)
{
	return __sync_val_compare_and_swap(destination, comparand, exchange);
}

static inline void* atomic_cmpxchgptr(void* volatile* destination, void* exchange, void* comparand)
{
	return __sync_val_compare_and_swap(destination, comparand, exchange);
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

static inline void* atomic_addptr(void* volatile* addend, intptr_t count, size_t element_size)
{
	intptr_t value = count * static_cast<intptr_t>(element_size);
	return reinterpret_cast<void*>(__sync_add_and_fetch(reinterpret_cast<volatile intptr_t*>(addend), value));
}

static inline int32_t atomic_inc32(int32_t volatile* value)
{
	return __sync_add_and_fetch(value, 1);
}

static inline int64_t atomic_inc64(int64_t volatile* value)
{
	return __sync_add_and_fetch(value, 1);
}

static inline void* atomic_subptr(void* volatile* addend, intptr_t count, size_t element_size)
{
	intptr_t value = count * static_cast<intptr_t>(element_size);
	return reinterpret_cast<void*>(__sync_sub_and_fetch(reinterpret_cast<volatile intptr_t*>(addend), value));
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
	return __sync_val_compare_and_swap(destination, comparand, exchange);
}

static inline uint64_t atomic_cmpxchgu64(
	uint64_t volatile* destination,
	uint64_t exchange,
	uint64_t comparand)
{
	return __sync_val_compare_and_swap(destination, comparand, exchange);
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

static inline int32_t atomic_and32(
	int32_t volatile* addend,
	int32_t value)
{
	return __sync_and_and_fetch(addend, value);
}

static inline int64_t atomic_and64(
	int64_t volatile* addend,
	int64_t value)
{
	return __sync_and_and_fetch(addend, value);
}

static inline uint32_t atomic_andu32(
	int32_t volatile* addend,
	int32_t value)
{
	return __sync_and_and_fetch(addend, value);
}

static inline uint64_t atomic_andu64(
	int64_t volatile* addend,
	int64_t value)
{
	return __sync_and_and_fetch(addend, value);
}

static inline int32_t atomic_or32(
	int32_t volatile* addend,
	int32_t value)
{
	return __sync_or_and_fetch(addend, value);
}

static inline int64_t atomic_or64(
	int64_t volatile* addend,
	int64_t value)
{
	return __sync_or_and_fetch(addend, value);
}

static inline uint32_t atomic_oru32(
	int32_t volatile* addend,
	int32_t value)
{
	return __sync_or_and_fetch(addend, value);
}

static inline uint64_t atomic_oru64(
	int64_t volatile* addend,
	int64_t value)
{
	return __sync_or_and_fetch(addend, value);
}

#elif defined(_MSC_VER)

BCS_SHARED int32_t atomic_cmpxchg32(int32_t volatile* destination, int32_t exchange, int32_t comparand);
BCS_SHARED int64_t atomic_cmpxchg64(int64_t volatile* destination, int64_t exchange, int64_t comparand);
BCS_SHARED void* atomic_cmpxchgptr(void* volatile* destination, void* exchange, void* comparand);
BCS_SHARED int32_t atomic_xchg32(int32_t volatile* destination, int32_t exchange);
BCS_SHARED int64_t atomic_xchg64(int64_t volatile* destination, int64_t exchange);
BCS_SHARED void* atomic_xchgptr(void* volatile* destination, void* exchange);
BCS_SHARED int32_t atomic_add32(int32_t volatile* addend, int32_t value);
BCS_SHARED int64_t atomic_add64(int64_t volatile* addend, int64_t value);
BCS_SHARED void* atomic_addptr(void* volatile* addend, intptr_t count, size_t element_size);
BCS_SHARED int32_t atomic_sub32(int32_t volatile* addend, int32_t value);
BCS_SHARED int64_t atomic_sub64(int64_t volatile* addend, int64_t value);
BCS_SHARED void* atomic_subptr(void* volatile* addend, intptr_t count, size_t element_size);
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
BCS_SHARED uint32_t atomic_subu32(uint32_t volatile* addend, uint32_t value);
BCS_SHARED uint64_t atomic_subu64(uint64_t volatile* addend, uint64_t value);
BCS_SHARED uint32_t atomic_incu32(uint32_t volatile* value);
BCS_SHARED uint64_t atomic_incu64(uint64_t volatile* value);
BCS_SHARED uint32_t atomic_decu32(uint32_t volatile* value);
BCS_SHARED uint64_t atomic_decu64(uint64_t volatile* value);

BCS_SHARED int32_t atomic_and32(int32_t volatile* addend, int32_t value);
BCS_SHARED int64_t atomic_and64(int64_t volatile* addend, int64_t value);
BCS_SHARED uint32_t atomic_andu32(int32_t volatile* addend, int32_t value);
BCS_SHARED uint64_t atomic_andu64(int64_t volatile* addend, int64_t value);
BCS_SHARED int32_t atomic_or32(int32_t volatile* addend, int32_t value);
BCS_SHARED int64_t atomic_or64(int64_t volatile* addend, int64_t value);
BCS_SHARED uint32_t atomic_oru32(int32_t volatile* addend, int32_t value);
BCS_SHARED uint64_t atomic_oru64(int64_t volatile* addend, int64_t value);

#else
#error Compiler not supported
#endif

template<typename t_pointer, typename t_count>
t_pointer* atomic_addptr(t_pointer volatile** pointer, t_count&& count)
{
	return static_cast<t_pointer*>(atomic_addptr((void* volatile*)pointer, static_cast<intptr_t>(count), sizeof(t_pointer)));
}

template<typename t_pointer, typename t_count>
t_pointer* atomic_subptr(t_pointer volatile** pointer, t_count&& count)
{
	return static_cast<t_pointer*>(atomic_subptr((void* volatile*)pointer, static_cast<intptr_t>(count), sizeof(t_pointer)));
}

template<typename t_pointer>
t_pointer* atomic_incptr(t_pointer volatile** pointer)
{
	return static_cast<t_pointer*>(atomic_incptr((void* volatile*)pointer, sizeof(t_pointer)));
}

template<typename t_pointer>
t_pointer* atomic_decptr(t_pointer volatile** pointer)
{
	return static_cast<t_pointer*>(atomic_decptr((void* volatile*)pointer, sizeof(t_pointer)));
}
