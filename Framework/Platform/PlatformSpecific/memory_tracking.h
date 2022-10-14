#pragma once

#pragma warning( push )
#pragma warning( disable : 4595 )

BCS_SHARED void print_memory_allocations();
BCS_SHARED void write_memory_allocations();

BCS_SHARED extern void* _tracked_aligned_malloc(size_t size, size_t alignment, const char* filepath = __builtin_FILE(), int32_t line = __builtin_LINE());
BCS_SHARED extern void  _tracked_aligned_free(void* allocated_memory);
BCS_SHARED extern void* _tracked_malloc(size_t size, const char* filepath = __builtin_FILE(), int32_t line = __builtin_LINE());
BCS_SHARED extern void* _tracked_realloc(void* memory, size_t size, const char* filepath = __builtin_FILE(), int32_t line = __builtin_LINE());
BCS_SHARED extern void  _tracked_free(const void* allocated_memory);
BCS_SHARED extern void  _untracked_free(const void* allocated_memory);
BCS_SHARED extern void  memory_collect();

#ifdef __INTELLISENSE__

BCS_SHARED extern void* tracked_aligned_malloc(size_t size, size_t alignment);
BCS_SHARED extern void  tracked_aligned_free(void* allocated_memory);
BCS_SHARED extern void* tracked_malloc(size_t size);
BCS_SHARED extern void* tracked_realloc(void* memory, size_t size);
BCS_SHARED extern void  tracked_free(const void* allocated_memory);
BCS_SHARED extern void  untracked_free(const void* allocated_memory);

#else

BCS_SHARED extern void* (*tracked_aligned_malloc_ptr)(size_t size, size_t alignment, const char* filepath, int32_t line);
BCS_SHARED extern void  (*tracked_aligned_free_ptr)(void* allocated_memory);
BCS_SHARED extern void* (*tracked_malloc_ptr)(size_t size, const char* filepath, int32_t line);
BCS_SHARED extern void* (*tracked_realloc_ptr)(void* memory, size_t size, const char* filepath, int32_t line);
BCS_SHARED extern void  (*tracked_free_ptr)(const void* allocated_memory);
BCS_SHARED extern void  (*untracked_free_ptr)(const void* allocated_memory);

#define tracked_aligned_malloc(size, alignment) tracked_aligned_malloc_ptr(size, alignment, __FILE__, __LINE__)
#define tracked_aligned_free(allocated_memory) tracked_aligned_free_ptr(allocated_memory)
#define tracked_malloc(size) tracked_malloc_ptr(size, __FILE__, __LINE__)
#define tracked_realloc(memory, size) tracked_realloc_ptr(memory, size, __FILE__, __LINE__)
#define tracked_free(allocated_memory) tracked_free_ptr(allocated_memory)
#define untracked_free(allocated_memory) untracked_free_ptr(allocated_memory)

#endif

inline void* operator new(size_t size, const char* filepath, int line, void* data)
{
	return data;
}

inline void* operator new[](size_t size, const char* filepath, int line, void* data)
{
	return data;
}

inline void* operator new(size_t size, const char* filepath, int line)
{
	return tracked_malloc_ptr(size, filepath, line);
}

inline void* operator new[](size_t size, const char* filepath, int line)
{
	return tracked_malloc_ptr(size, filepath, line);
}

inline void* operator new(size_t size)
{
	return tracked_malloc_ptr(size, nullptr, 0);
}

inline void* operator new[](size_t size)
{
	return tracked_malloc_ptr(size, nullptr, 0);
}

inline void operator delete(void* data, const char* filepath, int line, void* _data)
{
	
}

inline void operator delete[](void* data, const char* filepath, int line, void* _data)
{

}

inline void operator delete(void* data, const char* filepath, int line)
{
	return tracked_free_ptr(data);
}

inline void operator delete[](void* data, const char* filepath, int line)
{
	return tracked_free_ptr(data);
}

inline void operator delete(void* data)
{
	return tracked_free_ptr(data);
}

inline void operator delete[](void* data)
{
	return tracked_free_ptr(data);
}

#define new(...) new(__FILE__, __LINE__, __VA_ARGS__ )

void* __cdecl _alloca(size_t _Size);
#define tracked_malloca(size) tracked_malloc(size)
#define tracked_freea tracked_free

#define trivial_malloc(t_type, count) static_cast<t_type*>(tracked_malloc(sizeof(t_type) * static_cast<size_t>(count)))
#define trivial_realloc(t_type, memory, count) static_cast<t_type*>(tracked_realloc(memory, sizeof(t_type) * static_cast<size_t>(count)))

#define trivial_alloca(t_type, count) static_cast<t_type*>(alloca(sizeof(t_type) * static_cast<size_t>(count)))
#define zero_length_array_malloc(t_type, t_array_type, count) static_cast<t_type*>(tracked_malloc(sizeof(t_type) + sizeof(t_array_type) * static_cast<size_t>(count)))
#define trivial_free tracked_free

#pragma warning( pop )
