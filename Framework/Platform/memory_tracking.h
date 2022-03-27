#pragma once

#pragma warning( push )
#pragma warning( disable : 4595 )

struct s_tracked_memory_stats
{
	const char* name;
	s_tracked_memory_stats* parent;
	volatile long long allocated_memory;
	volatile long long tracked_allocated_memory;
	volatile long allocation_count;
};

struct s_tracked_memory_entry
{
	s_tracked_memory_entry* next;
	s_tracked_memory_entry* previous;
	void* tracked_memory;
	void* memory;
	size_t stack_trace_size;
	size_t tracking_memory_size;
	size_t tracking_memory_aligned_size;
	size_t allocated_memory_aligned_size;
	size_t total_memory_aligned_size;
	char* stack_trace;
	const char* filepath;
	long line;
};

BCS_DEBUG_API void* tracked_aligned_malloc(size_t size, size_t alignment, const char* filepath = __builtin_FILE(), long line = __builtin_LINE());
BCS_DEBUG_API void tracked_aligned_free(void* allocated_memory);
BCS_DEBUG_API void* tracked_malloc(size_t size, const char* filepath = __builtin_FILE(), long line = __builtin_LINE());
BCS_DEBUG_API void tracked_free(const void* allocated_memory);
BCS_DEBUG_API void untracked_free(const void* allocated_memory);
BCS_DEBUG_API void print_memory_allocations();
BCS_DEBUG_API void write_memory_allocations();

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
	return tracked_malloc(size, filepath, line);
}

inline void* operator new[](size_t size, const char* filepath, int line)
{
	return tracked_malloc(size, filepath, line);
}

inline void* operator new(size_t size)
{
	return tracked_malloc(size, nullptr, 0);
}

inline void* operator new[](size_t size)
{
	return tracked_malloc(size, nullptr, 0);
}

inline void operator delete(void* data, const char* filepath, int line, void* _data)
{
	
}

inline void operator delete[](void* data, const char* filepath, int line, void* _data)
{

}

inline void operator delete(void* data, const char* filepath, int line)
{
	return tracked_free(data);
}

inline void operator delete[](void* data, const char* filepath, int line)
{
	return tracked_free(data);
}

inline void operator delete(void* data)
{
	return tracked_free(data);
}

inline void operator delete[](void* data)
{
	return tracked_free(data);
}

#define new(...) new(__FILE__, __LINE__, __VA_ARGS__ )

void* __cdecl _alloca(size_t _Size);
#define tracked_malloca(size) tracked_malloc(size, __FILE__, __LINE__)
#define tracked_freea tracked_free

#pragma warning( pop )
