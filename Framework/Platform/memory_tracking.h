#pragma once

struct s_tracked_memory_stats
{
	const char* name;
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
};

BCS_DEBUG_API void* tracked_aligned_malloc(s_tracked_memory_stats* stats, size_t size, size_t alignment);
BCS_DEBUG_API void tracked_aligned_free(void* allocated_memory);
BCS_DEBUG_API void* tracked_malloc(s_tracked_memory_stats* stats, size_t size);
BCS_DEBUG_API void tracked_free(void* allocated_memory);
BCS_DEBUG_API void print_memory_allocations(s_tracked_memory_stats* stats);

BCS_DEBUG_API extern s_tracked_memory_stats platform_tracked_memory;
BCS_DEBUG_API extern s_tracked_memory_stats malloca_tracked_memory;
extern s_tracked_memory_stats library_tracked_memory;

void* __cdecl _alloca(size_t _Size);

#define tracked_malloca(size) tracked_malloc(&malloca_tracked_memory, size)
#define tracked_freea tracked_free
