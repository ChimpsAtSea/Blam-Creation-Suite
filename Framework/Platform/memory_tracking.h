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
	s_tracked_memory_stats* stats;
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

BCS_DEBUG_API void* _tracked_aligned_malloc(s_tracked_memory_stats& stats, size_t size, size_t alignment, const char* filepath, long line);
BCS_DEBUG_API void tracked_aligned_free(void* allocated_memory);
BCS_DEBUG_API void* _tracked_malloc(s_tracked_memory_stats& stats, size_t size, const char* filepath, long line);
BCS_DEBUG_API void tracked_free(void* allocated_memory);
BCS_DEBUG_API void print_memory_allocations(s_tracked_memory_stats* stats);

BCS_DEBUG_API extern s_tracked_memory_stats unknown_tracked_memory;
BCS_DEBUG_API extern s_tracked_memory_stats platform_tracked_memory;
BCS_DEBUG_API extern s_tracked_memory_stats malloca_tracked_memory;
extern s_tracked_memory_stats& _library_tracked_memory;

inline void* operator new (
	size_t size,
	const char* filepath,
	int line,
	void* data)
{
	return data;
}

inline void* operator new (
	size_t size,
	const char* filepath,
	int line,
	s_tracked_memory_stats& stats)
{
	return _tracked_malloc(stats, size, filepath, line);
}

inline void* operator new[](
	size_t size,
	const char* filepath,
	int line,
	s_tracked_memory_stats& stats)
{
	return _tracked_malloc(stats, size, filepath, line);
}

inline void* operator new (
	size_t size,
	const char* filepath,
	int line)
{
	return _tracked_malloc(_library_tracked_memory, size, filepath, line);
}

inline void* operator new(
	size_t size)
{
	return _tracked_malloc(_library_tracked_memory, size, nullptr, 0);
}

inline void* operator new[](
	size_t size,
	const char* filepath,
	int line)
{
	return _tracked_malloc(_library_tracked_memory, size, filepath, line);
}

inline void* operator new[](
	size_t size)
{
	return _tracked_malloc(_library_tracked_memory, size, nullptr, 0);
}

inline void operator delete (void* data)
{
	return tracked_free(data);
}

inline void operator delete[](void* data)
{
	return tracked_free(data);
}

#define tracked_aligned_malloc(stats, size, alignment) _tracked_aligned_malloc(stats, size, alignment, __FILE__, __LINE__)
#define tracked_malloc(stats, size) _tracked_malloc(stats, size, __FILE__, __LINE__)

#define new(...) new(__FILE__, __LINE__, __VA_ARGS__ )

void* __cdecl _alloca(size_t _Size);

#define tracked_malloca(size) tracked_malloc(malloca_tracked_memory, size)
#define tracked_freea tracked_free

#pragma warning( pop )
