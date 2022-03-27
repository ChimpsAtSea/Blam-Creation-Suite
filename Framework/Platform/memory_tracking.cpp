#include "platform-private-pch.h"

#undef _aligned_malloc
#undef _aligned_free
#undef malloc
#undef free

#define ROUNDUP(n , width) (((n) + (width) - 1) & ~((width) - 1))

static volatile LONG tracked_memory_entries_spin_lock;
static s_tracked_memory_entry* tracked_memory_entries;

volatile long long allocated_memory;
volatile long long tracked_allocated_memory;
volatile long allocation_count;

s_tracked_memory_stats platform_tracked_memory = { "platform" };
s_tracked_memory_stats malloca_tracked_memory = { "malloca" };
s_tracked_memory_stats& _library_tracked_memory = platform_tracked_memory;

s_tracked_memory_stats tracked_memory_stats;

void* tracked_aligned_malloc(size_t size, size_t alignment, const char* filepath, long line)
{
	const char* stack_trace = "hello world hello world hello world";
	size_t stack_trace_size = strlen(stack_trace) + 1;
	size_t tracking_memory_size = sizeof(s_tracked_memory_entry) + stack_trace_size;
	size_t tracking_memory_aligned_size = ROUNDUP(tracking_memory_size, __max(16, alignment)) + 16;
	size_t allocated_memory_aligned_size = ROUNDUP(size, alignment);
	size_t total_memory_aligned_size = allocated_memory_aligned_size + tracking_memory_aligned_size;

	void* tracked_memory = _aligned_malloc(total_memory_aligned_size, __max(16, alignment));
	memset(tracked_memory, 'T', tracking_memory_aligned_size);
	char* stack_trace_memory = static_cast<char*>(tracked_memory);
	void* memory = static_cast<void*>(stack_trace_memory + tracking_memory_aligned_size);
	s_tracked_memory_entry* tracked_memory_entry = static_cast<s_tracked_memory_entry*>(memory) - 1;

	tracked_memory_entry->next = nullptr;
	tracked_memory_entry->previous = nullptr;
	tracked_memory_entry->tracked_memory = tracked_memory;
	tracked_memory_entry->memory = memory;
	tracked_memory_entry->stack_trace_size = stack_trace_size;
	tracked_memory_entry->tracking_memory_size = tracking_memory_size;
	tracked_memory_entry->tracking_memory_aligned_size = tracking_memory_aligned_size;
	tracked_memory_entry->allocated_memory_aligned_size = allocated_memory_aligned_size;
	tracked_memory_entry->total_memory_aligned_size = total_memory_aligned_size;
	tracked_memory_entry->stack_trace = stack_trace_memory;
	memcpy(tracked_memory_entry->stack_trace, stack_trace, stack_trace_size);
	tracked_memory_entry->filepath = filepath;
	tracked_memory_entry->line = line;

	DWORD thread_id = GetCurrentThreadId();
	while (InterlockedCompareExchange(&tracked_memory_entries_spin_lock, thread_id, 0));
	s_tracked_memory_entry* previous = tracked_memory_entries;
	tracked_memory_entries = tracked_memory_entry;
	tracked_memory_entry->previous = previous;
	if (previous)
	{
		previous->next = tracked_memory_entry;
	}

	InterlockedAdd64(&tracked_memory_stats.allocated_memory, allocated_memory_aligned_size);
	InterlockedAdd64(&tracked_memory_stats.tracked_allocated_memory, tracking_memory_aligned_size);
	InterlockedIncrement(&tracked_memory_stats.allocation_count);

	InterlockedAdd64(&allocated_memory, allocated_memory_aligned_size);
	InterlockedAdd64(&tracked_allocated_memory, tracking_memory_aligned_size);
	InterlockedIncrement(&allocation_count);

	LONG lock_release_result = InterlockedExchange(&tracked_memory_entries_spin_lock, 0);
	if (lock_release_result != thread_id) throw;

	return memory;
}

void tracked_aligned_free(void* pointer)
{
	if (pointer)
	{
		s_tracked_memory_entry* tracked_memory_entry = static_cast<s_tracked_memory_entry*>(pointer) - 1;

		DWORD thread_id = GetCurrentThreadId();
		while (InterlockedCompareExchange(&tracked_memory_entries_spin_lock, thread_id, 0));
		if (tracked_memory_entry->previous)
		{
			tracked_memory_entry->previous->next = tracked_memory_entry->next;
		}
		if (tracked_memory_entry->next)
		{
			tracked_memory_entry->next->previous = tracked_memory_entry->previous;
		}
		if (tracked_memory_entries == tracked_memory_entry)
		{
			tracked_memory_entries = tracked_memory_entry->previous;
		}

		InterlockedAdd64(&tracked_memory_stats.allocated_memory, -static_cast<LONG64>(tracked_memory_entry->allocated_memory_aligned_size));
		InterlockedAdd64(&tracked_memory_stats.tracked_allocated_memory, -static_cast<LONG64>(tracked_memory_entry->tracking_memory_aligned_size));
		InterlockedAdd(&tracked_memory_stats.allocation_count, -1);

		InterlockedAdd64(&allocated_memory, -static_cast<LONG64>(tracked_memory_entry->allocated_memory_aligned_size));
		InterlockedAdd64(&tracked_allocated_memory, -static_cast<LONG64>(tracked_memory_entry->tracking_memory_aligned_size));
		InterlockedAdd(&allocation_count, -1);

		LONG lock_release_result = InterlockedCompareExchange(&tracked_memory_entries_spin_lock, 0, thread_id);
		if (lock_release_result != thread_id) throw;

		_aligned_free(tracked_memory_entry->tracked_memory);

		debug_point;
	}
}

void* tracked_malloc(size_t size, const char* filepath, long line)
{
	size_t alignment = 1;
	const char* stack_trace = "hello world hello world hello world";
	size_t stack_trace_size = strlen(stack_trace) + 1;
	size_t tracking_memory_size = sizeof(s_tracked_memory_entry) + stack_trace_size;
	size_t tracking_memory_aligned_size = ROUNDUP(tracking_memory_size, __max(16, alignment)) + 16;
	size_t allocated_memory_aligned_size = ROUNDUP(size, alignment);
	size_t total_memory_aligned_size = allocated_memory_aligned_size + tracking_memory_aligned_size;

	void* tracked_memory = malloc(total_memory_aligned_size);
	memset(tracked_memory, 'T', tracking_memory_aligned_size);
	char* stack_trace_memory = static_cast<char*>(tracked_memory);
	void* memory = static_cast<void*>(stack_trace_memory + tracking_memory_aligned_size);
	s_tracked_memory_entry* tracked_memory_entry = static_cast<s_tracked_memory_entry*>(memory) - 1;

	tracked_memory_entry->next = nullptr;
	tracked_memory_entry->previous = nullptr;
	tracked_memory_entry->tracked_memory = tracked_memory;
	tracked_memory_entry->memory = memory;
	tracked_memory_entry->stack_trace_size = stack_trace_size;
	tracked_memory_entry->tracking_memory_size = tracking_memory_size;
	tracked_memory_entry->tracking_memory_aligned_size = tracking_memory_aligned_size;
	tracked_memory_entry->allocated_memory_aligned_size = allocated_memory_aligned_size;
	tracked_memory_entry->total_memory_aligned_size = total_memory_aligned_size;
	tracked_memory_entry->stack_trace = stack_trace_memory;
	memcpy(tracked_memory_entry->stack_trace, stack_trace, stack_trace_size);
	tracked_memory_entry->filepath = filepath;
	tracked_memory_entry->line = line;

	DWORD thread_id = GetCurrentThreadId();
	while (InterlockedCompareExchange(&tracked_memory_entries_spin_lock, thread_id, 0));
	s_tracked_memory_entry* previous = tracked_memory_entries;
	tracked_memory_entries = tracked_memory_entry;
	tracked_memory_entry->previous = previous;
	if (previous)
	{
		previous->next = tracked_memory_entry;
	}

	InterlockedAdd64(&tracked_memory_stats.allocated_memory, allocated_memory_aligned_size);
	InterlockedAdd64(&tracked_memory_stats.tracked_allocated_memory, tracking_memory_aligned_size);
	InterlockedIncrement(&tracked_memory_stats.allocation_count);

	InterlockedAdd64(&allocated_memory, allocated_memory_aligned_size);
	InterlockedAdd64(&tracked_allocated_memory, tracking_memory_aligned_size);
	InterlockedIncrement(&allocation_count);

	LONG lock_release_result = InterlockedExchange(&tracked_memory_entries_spin_lock, 0);
	if (lock_release_result != thread_id) throw;

	return memory;
}

void tracked_free(const void* pointer)
{
	if (pointer)
	{
		const s_tracked_memory_entry* tracked_memory_entry = static_cast<const s_tracked_memory_entry*>(pointer) - 1;

		DWORD thread_id = GetCurrentThreadId();
		while (InterlockedCompareExchange(&tracked_memory_entries_spin_lock, thread_id, 0));
		if (tracked_memory_entry->previous)
		{
			tracked_memory_entry->previous->next = tracked_memory_entry->next;
		}
		if (tracked_memory_entry->next)
		{
			tracked_memory_entry->next->previous = tracked_memory_entry->previous;
		}
		if (tracked_memory_entries == tracked_memory_entry)
		{
			tracked_memory_entries = tracked_memory_entry->previous;
		}

		InterlockedAdd64(&tracked_memory_stats.allocated_memory, -static_cast<LONG64>(tracked_memory_entry->allocated_memory_aligned_size));
		InterlockedAdd64(&tracked_memory_stats.tracked_allocated_memory, -static_cast<LONG64>(tracked_memory_entry->tracking_memory_aligned_size));
		InterlockedAdd(&tracked_memory_stats.allocation_count, -1);

		InterlockedAdd64(&allocated_memory, -static_cast<LONG64>(tracked_memory_entry->allocated_memory_aligned_size));
		InterlockedAdd64(&tracked_allocated_memory, -static_cast<LONG64>(tracked_memory_entry->tracking_memory_aligned_size));
		InterlockedAdd(&allocation_count, -1);

		LONG lock_release_result = InterlockedCompareExchange(&tracked_memory_entries_spin_lock, 0, thread_id);
		if (lock_release_result != thread_id) throw;

		free(tracked_memory_entry->tracked_memory);

		debug_point;
	}
}

void untracked_free(const void* pointer)
{
	free(const_cast<void*>(pointer));
}

void print_memory_allocations()
{
	DWORD thread_id = GetCurrentThreadId();
	while (InterlockedCompareExchange(&tracked_memory_entries_spin_lock, thread_id, 0));
	console_write_line("Global memory stats");
	console_write_line("\t allocated_memory:         %lli", allocated_memory);
	console_write_line("\t tracked_allocated_memory: %lli", tracked_allocated_memory);
	console_write_line("\t allocation_count:         %i", allocation_count);

	unsigned long output_count = 0;
	for (s_tracked_memory_entry* tracked_memory_entry = tracked_memory_entries; tracked_memory_entry; tracked_memory_entry = tracked_memory_entry->previous)
	{
		if (tracked_memory_entry->filepath)
		{
			console_write_line("%s(%i): warning MLEAK: memory leak detected", tracked_memory_entry->filepath, tracked_memory_entry->line);

			debug_point;
			if (++output_count > 10)
			{
				break;
			}
		}
	}
	LONG lock_release_result = InterlockedCompareExchange(&tracked_memory_entries_spin_lock, 0, thread_id);
	if (lock_release_result != thread_id) throw;
}

void write_memory_allocations()
{
	FILE* output = fopen("memory_allocations.txt", "w");
#define file_write_line(file, format, ...) fprintf(file, format "\n", __VA_ARGS__);

	DWORD thread_id = GetCurrentThreadId();
	while (InterlockedCompareExchange(&tracked_memory_entries_spin_lock, thread_id, 0));
	file_write_line(output, "Global memory stats");
	file_write_line(output, "\t allocated_memory:         %lli", allocated_memory);
	file_write_line(output, "\t tracked_allocated_memory: %lli", tracked_allocated_memory);
	file_write_line(output, "\t allocation_count:         %i", allocation_count);

	unsigned long missed_output_entries = 0;
	for (s_tracked_memory_entry* tracked_memory_entry = tracked_memory_entries; tracked_memory_entry; tracked_memory_entry = tracked_memory_entry->previous)
	{
		if (tracked_memory_entry->filepath)
		{
			file_write_line(output, "%s(%i): warning MLEAK: memory leak detected", tracked_memory_entry->filepath, tracked_memory_entry->line);

			debug_point;
		}
		else missed_output_entries++;
	}
	LONG lock_release_result = InterlockedCompareExchange(&tracked_memory_entries_spin_lock, 0, thread_id);
	if (lock_release_result != thread_id) throw;

	if(missed_output_entries > 0)
	{
		file_write_line(output, "%u entries had no file/line data", missed_output_entries);
	}

	fclose(output);

#undef file_write_line
}
