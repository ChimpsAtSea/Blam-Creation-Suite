#include "platform-private-pch.h"

#include <mimalloc.h>

#undef _aligned_malloc
#undef _aligned_free
#undef malloc
#undef free

#define ROUNDUP(n , width) (((n) + (width) - 1) & ~((width) - 1))
#define SHOULD_TRACK_HACK (strstr(GetCommandLineA(), "-trackmemory") != nullptr) // terrible shitty awful hack tastic spazz

#define MEMORY_TRACKING_FIRST_RUN_FIXUP(target_pointer, tracked_function, untracked_function)	\
DWORD thread_id = GetCurrentThreadId();                                                         \
if (atomic_cmpxchg32(&tracked_memory_entries_spin_lock, thread_id, 0) == 0)           \
{																								\
	if (SHOULD_TRACK_HACK)																		\
	{																							\
		target_pointer = tracked_function;														\
	}																							\
	else																						\
	{																							\
		target_pointer = reinterpret_cast<decltype(target_pointer)>(untracked_function);		\
	}																							\
}																								\
else																							\
{																								\
	while (atomic_cmpxchg32(&tracked_memory_entries_spin_lock, thread_id, 0));		\
}																								\
int32_t lock_release_result = atomic_xchg32(&tracked_memory_entries_spin_lock, 0);			\
if (lock_release_result != thread_id) throw;

struct s_tracked_memory_stats
{
	volatile int64_t allocated_memory;
	volatile int64_t tracked_allocated_memory;
	volatile int32_t allocation_count;
};

struct s_tracked_memory_entry
{
	s_tracked_memory_entry* next;
	s_tracked_memory_entry* previous;
	void* tracked_memory;
	void* memory;
	size_t tracking_memory_size;
	size_t tracking_memory_aligned_size;
	size_t allocated_memory_aligned_size;
	size_t total_memory_aligned_size;
	void** stack_frames;
	const char* filepath;
	int32_t line;
	uint32_t num_stack_frames;
};

static volatile int32_t tracked_memory_entries_spin_lock;
static s_tracked_memory_entry* tracked_memory_entries;

volatile int64_t allocated_memory;
volatile int64_t tracked_allocated_memory;
volatile int32_t allocation_count;

s_tracked_memory_stats tracked_memory_stats;

void* tracked_aligned_malloc_firstrun(size_t size, size_t alignment, const char* filepath, int32_t line)
{
	MEMORY_TRACKING_FIRST_RUN_FIXUP(tracked_aligned_malloc_ptr, _tracked_aligned_malloc, mi_aligned_alloc);
	return tracked_aligned_malloc_ptr(size, alignment, filepath, line);
}

void  tracked_aligned_free_firstrun(void* allocated_memory)
{
	MEMORY_TRACKING_FIRST_RUN_FIXUP(tracked_aligned_free_ptr, _tracked_aligned_free, mi_free);
	return tracked_aligned_free_ptr(allocated_memory);
}

void* tracked_malloc_firstrun(size_t size, const char* filepath, int32_t line)
{
	MEMORY_TRACKING_FIRST_RUN_FIXUP(tracked_malloc_ptr, _tracked_malloc, mi_malloc);
	return tracked_malloc_ptr(size, filepath, line);
}

void  tracked_free_firstrun(const void* allocated_memory)
{
	MEMORY_TRACKING_FIRST_RUN_FIXUP(tracked_free_ptr, _tracked_free, mi_free);
	return tracked_free_ptr(allocated_memory);
}

void  untracked_free_firstrun(const void* allocated_memory)
{
	MEMORY_TRACKING_FIRST_RUN_FIXUP(untracked_free_ptr, _untracked_free, free);
	return untracked_free_ptr(allocated_memory);
}

void* (*tracked_aligned_malloc_ptr)(size_t size, size_t alignment, const char* filepath, int32_t line) = tracked_aligned_malloc_firstrun;
void  (*tracked_aligned_free_ptr)(void* allocated_memory) = tracked_aligned_free_firstrun;
void* (*tracked_malloc_ptr)(size_t size, const char* filepath, int32_t line) = tracked_malloc_firstrun;
void  (*tracked_free_ptr)(const void* allocated_memory) = tracked_free_firstrun;
void  (*untracked_free_ptr)(const void* allocated_memory) = untracked_free_firstrun;

void* _tracked_aligned_malloc(size_t size, size_t alignment, const char* filepath, int32_t line)
{
	PVOID stack_frames[USHRT_MAX];
	unsigned short num_stack_frames = CaptureStackBackTrace(1, USHRT_MAX, stack_frames, NULL);

	size_t stack_trace_size = sizeof(PVOID) * num_stack_frames;
	size_t tracking_memory_size = sizeof(s_tracked_memory_entry) + stack_trace_size;
	size_t tracking_memory_aligned_size = ROUNDUP(tracking_memory_size, __max(16, alignment)) + 16;
	size_t allocated_memory_aligned_size = ROUNDUP(size, alignment);
	size_t total_memory_aligned_size = allocated_memory_aligned_size + tracking_memory_aligned_size;

	void* tracked_memory = mi_aligned_alloc(total_memory_aligned_size, __max(16, alignment));
	memset(tracked_memory, 'T', tracking_memory_aligned_size);
	PVOID* stack_frames_memory = static_cast<PVOID*>(tracked_memory);
	void* memory = static_cast<void*>(reinterpret_cast<char*>(stack_frames_memory) + tracking_memory_aligned_size);
	s_tracked_memory_entry* tracked_memory_entry = static_cast<s_tracked_memory_entry*>(memory) - 1;

	tracked_memory_entry->next = nullptr;
	tracked_memory_entry->previous = nullptr;
	tracked_memory_entry->tracked_memory = tracked_memory;
	tracked_memory_entry->memory = memory;
	tracked_memory_entry->tracking_memory_size = tracking_memory_size;
	tracked_memory_entry->tracking_memory_aligned_size = tracking_memory_aligned_size;
	tracked_memory_entry->allocated_memory_aligned_size = allocated_memory_aligned_size;
	tracked_memory_entry->total_memory_aligned_size = total_memory_aligned_size;
	tracked_memory_entry->stack_frames = stack_frames_memory;
	tracked_memory_entry->num_stack_frames = num_stack_frames;
	memcpy(tracked_memory_entry->stack_frames, stack_frames, sizeof(PVOID) * num_stack_frames);
	tracked_memory_entry->filepath = filepath;
	tracked_memory_entry->line = line;

	DWORD thread_id = GetCurrentThreadId();
	while (atomic_cmpxchg32(&tracked_memory_entries_spin_lock, thread_id, 0));
	s_tracked_memory_entry* previous = tracked_memory_entries;
	tracked_memory_entries = tracked_memory_entry;
	tracked_memory_entry->previous = previous;
	if (previous)
	{
		previous->next = tracked_memory_entry;
	}

	int32_t lock_release_result = atomic_xchg32(&tracked_memory_entries_spin_lock, 0);
	if (lock_release_result != thread_id) throw;

	atomic_add64(&tracked_memory_stats.allocated_memory, allocated_memory_aligned_size);
	atomic_add64(&tracked_memory_stats.tracked_allocated_memory, tracking_memory_aligned_size);
	atomic_inc32(&tracked_memory_stats.allocation_count);

	atomic_add64(&allocated_memory, allocated_memory_aligned_size);
	atomic_add64(&tracked_allocated_memory, tracking_memory_aligned_size);
	atomic_inc32(&allocation_count);

	return memory;
}

void _tracked_aligned_free(void* pointer)
{
	if (pointer)
	{
		s_tracked_memory_entry* tracked_memory_entry = static_cast<s_tracked_memory_entry*>(pointer) - 1;

		DWORD thread_id = GetCurrentThreadId();
		while (atomic_cmpxchg32(&tracked_memory_entries_spin_lock, thread_id, 0));
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

		int32_t lock_release_result = atomic_cmpxchg32(&tracked_memory_entries_spin_lock, 0, thread_id);
		if (lock_release_result != thread_id) throw;

		atomic_add64(&tracked_memory_stats.allocated_memory, -static_cast<LONG64>(tracked_memory_entry->allocated_memory_aligned_size));
		atomic_add64(&tracked_memory_stats.tracked_allocated_memory, -static_cast<LONG64>(tracked_memory_entry->tracking_memory_aligned_size));
		atomic_add32(&tracked_memory_stats.allocation_count, -1);

		atomic_add64(&allocated_memory, -static_cast<LONG64>(tracked_memory_entry->allocated_memory_aligned_size));
		atomic_add64(&tracked_allocated_memory, -static_cast<LONG64>(tracked_memory_entry->tracking_memory_aligned_size));
		atomic_add32(&allocation_count, -1);

		mi_free(tracked_memory_entry->tracked_memory);
		
		debug_point;
	}
}

void* _tracked_malloc(size_t size, const char* filepath, int32_t line)
{
	size_t alignment = 1;

	PVOID stack_frames[USHRT_MAX];
	unsigned short num_stack_frames = CaptureStackBackTrace(1, USHRT_MAX, stack_frames, NULL);

	size_t stack_trace_size = sizeof(PVOID) * num_stack_frames;
	size_t tracking_memory_size = sizeof(s_tracked_memory_entry) + stack_trace_size;
	size_t tracking_memory_aligned_size = ROUNDUP(tracking_memory_size, __max(16, alignment)) + 16;
	size_t allocated_memory_aligned_size = ROUNDUP(size, alignment);
	size_t total_memory_aligned_size = allocated_memory_aligned_size + tracking_memory_aligned_size;

	void* tracked_memory = mi_malloc(total_memory_aligned_size);
	memset(tracked_memory, 'T', tracking_memory_aligned_size);
	PVOID* stack_frames_memory = static_cast<PVOID*>(tracked_memory);
	void* memory = static_cast<void*>(reinterpret_cast<char*>(stack_frames_memory) + tracking_memory_aligned_size);
	s_tracked_memory_entry* tracked_memory_entry = static_cast<s_tracked_memory_entry*>(memory) - 1;

	tracked_memory_entry->next = nullptr;
	tracked_memory_entry->previous = nullptr;
	tracked_memory_entry->tracked_memory = tracked_memory;
	tracked_memory_entry->memory = memory;
	tracked_memory_entry->tracking_memory_size = tracking_memory_size;
	tracked_memory_entry->tracking_memory_aligned_size = tracking_memory_aligned_size;
	tracked_memory_entry->allocated_memory_aligned_size = allocated_memory_aligned_size;
	tracked_memory_entry->total_memory_aligned_size = total_memory_aligned_size;
	tracked_memory_entry->stack_frames = stack_frames_memory;
	tracked_memory_entry->num_stack_frames = num_stack_frames;
	memcpy(tracked_memory_entry->stack_frames, stack_frames, stack_trace_size);
	tracked_memory_entry->filepath = filepath;
	tracked_memory_entry->line = line;

	DWORD thread_id = GetCurrentThreadId();
	uint64_t spins = 0;
	static uint64_t max_spins = 0;
	while (atomic_cmpxchg32(&tracked_memory_entries_spin_lock, thread_id, 0)) spins++;
	max_spins = __max(max_spins, spins);

	s_tracked_memory_entry* previous = tracked_memory_entries;
	tracked_memory_entries = tracked_memory_entry;
	tracked_memory_entry->previous = previous;
	if (previous)
	{
		previous->next = tracked_memory_entry;
	}

	int32_t lock_release_result = atomic_xchg32(&tracked_memory_entries_spin_lock, 0);
	if (lock_release_result != thread_id) throw;

	atomic_add64(&tracked_memory_stats.allocated_memory, allocated_memory_aligned_size);
	atomic_add64(&tracked_memory_stats.tracked_allocated_memory, tracking_memory_aligned_size);
	atomic_inc32(&tracked_memory_stats.allocation_count);

	atomic_add64(&allocated_memory, allocated_memory_aligned_size);
	atomic_add64(&tracked_allocated_memory, tracking_memory_aligned_size);
	atomic_inc32(&allocation_count);


	return memory;
}

void _tracked_free(const void* pointer)
{
	if (pointer)
	{
		const s_tracked_memory_entry* tracked_memory_entry = static_cast<const s_tracked_memory_entry*>(pointer) - 1;

		DWORD thread_id = GetCurrentThreadId();
		while (atomic_cmpxchg32(&tracked_memory_entries_spin_lock, thread_id, 0));
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

		int32_t lock_release_result = atomic_cmpxchg32(&tracked_memory_entries_spin_lock, 0, thread_id);
		if (lock_release_result != thread_id) throw;

		atomic_add64(&tracked_memory_stats.allocated_memory, -static_cast<LONG64>(tracked_memory_entry->allocated_memory_aligned_size));
		atomic_add64(&tracked_memory_stats.tracked_allocated_memory, -static_cast<LONG64>(tracked_memory_entry->tracking_memory_aligned_size));
		atomic_add32(&tracked_memory_stats.allocation_count, -1);

		atomic_add64(&allocated_memory, -static_cast<LONG64>(tracked_memory_entry->allocated_memory_aligned_size));
		atomic_add64(&tracked_allocated_memory, -static_cast<LONG64>(tracked_memory_entry->tracking_memory_aligned_size));
		atomic_add32(&allocation_count, -1);

		mi_free(tracked_memory_entry->tracked_memory);

		debug_point;
	}
}

void _untracked_free(const void* pointer)
{
	free(const_cast<void*>(pointer));
}

void print_memory_allocations()
{
	DWORD thread_id = GetCurrentThreadId();
	while (atomic_cmpxchg32(&tracked_memory_entries_spin_lock, thread_id, 0));
	console_write_line("Global memory stats");
	console_write_line("\t allocated_memory:         %lli", allocated_memory);
	console_write_line("\t tracked_allocated_memory: %lli", tracked_allocated_memory);
	console_write_line("\t allocation_count:         %i", allocation_count);

	uint32_t output_count = 0;
	for (s_tracked_memory_entry* tracked_memory_entry = tracked_memory_entries; tracked_memory_entry; tracked_memory_entry = tracked_memory_entry->previous)
	{
		if (tracked_memory_entry->filepath)
		{
			console_write_line("%s(%i): warning MLEAK: memory leak detected 0x%p", tracked_memory_entry->filepath, tracked_memory_entry->line, tracked_memory_entry->memory);

			debug_point;
			if (++output_count > 10)
			{
				break;
			}
		}
	}
	int32_t lock_release_result = atomic_cmpxchg32(&tracked_memory_entries_spin_lock, 0, thread_id);
	if (lock_release_result != thread_id) throw;
}

uint32_t write_stack_trace(PVOID * frames, uint32_t num_frames, char* buffer, uint32_t buffer_length)
{
	uint32_t buffer_length_used = 0;
	char* buffer_position = buffer;
	char* buffer_end = buffer + buffer_length;

	HANDLE current_process = GetCurrentProcess();
	HMODULE* modules_buffer = nullptr;
	DWORD bytes_required = 0;
	BOOL enum_process_modules_result0 = EnumProcessModules(current_process, modules_buffer, 0, &bytes_required);
	if (enum_process_modules_result0 == FALSE)
	{
		throw;
	}
	modules_buffer = static_cast<HMODULE*>(_alloca(bytes_required));
	BOOL enum_process_modules_result1 = EnumProcessModules(current_process, modules_buffer, 0, &bytes_required);
	if (enum_process_modules_result1 == FALSE)
	{
		throw;
	}

	IMAGEHLP_SYMBOL64* symbol = static_cast<IMAGEHLP_SYMBOL64*>(_alloca(sizeof(IMAGEHLP_SYMBOL64) + MAX_SYM_NAME * sizeof(CHAR) + 1024));
	symbol->SizeOfStruct = sizeof(IMAGEHLP_SYMBOL64);
	symbol->MaxNameLength = MAX_SYM_NAME;

	for (uint32_t frame_index = 0; frame_index < num_frames; frame_index++)
	{
		PVOID frame = frames[frame_index];

		HMODULE module;
		BOOL get_module_handle_result = GetModuleHandleExA(GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS | GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT, static_cast<LPCSTR>(frame), &module);
		if (get_module_handle_result == FALSE)
		{
			throw;
		}

		char module_filepath[0x10000];
		DWORD get_module_filename_result = GetModuleFileNameExA(current_process, module, module_filepath, _countof(module_filepath));
		if (get_module_filename_result == 0)
		{
			strcpy_s(module_filepath, "<unknown>");
		}
		char* module_filename = PathFindFileNameA(module_filepath);

		DWORD64 address = (DWORD64)frame;
		BOOL symbol_from_address_result = SymGetSymFromAddr(current_process, address, NULL, symbol);
		if (symbol_from_address_result != FALSE)
		{
			IMAGEHLP_LINE64 line;
			line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);
			DWORD displacement;
			BOOL symbol_line_from_address_result = SymGetLineFromAddr64(current_process, address, &displacement, &line);

			if (buffer)
			{
				buffer_position += snprintf(buffer_position, buffer_end - buffer_position, "\t%s!%s()", module_filename, symbol->Name);
				if (symbol_line_from_address_result)
				{
					buffer_position += snprintf(buffer_position, buffer_end - buffer_position, " Line %i", line.LineNumber);
				}
				if (frame_index != (num_frames - 1))
				{
					buffer_position += snprintf(buffer_position, buffer_end - buffer_position, "\n");
				}
			}
			else
			{
				buffer_length_used += snprintf(nullptr, 0, "\t%s!%s()", module_filename, symbol->Name);
				if (symbol_line_from_address_result)
				{
					buffer_length_used += snprintf(nullptr, 0, " Line %i", line.LineNumber);
				}
				if (frame_index != (num_frames - 1))
				{
					buffer_length_used += snprintf(nullptr, 0, "\n");
				}
			}
		}
		else
		{
			if (buffer)
			{
				buffer_position += snprintf(buffer_position, buffer_end - buffer_position, "\t%s!%p()", module_filename, frame);
				if (frame_index != (num_frames - 1))
				{
					buffer_position += snprintf(buffer_position, buffer_end - buffer_position, "\n");
				}
			}
			else
			{
				buffer_length_used += snprintf(nullptr, 0, "\t%s!%p()", module_filename, frame);
				if (frame_index != (num_frames - 1))
				{
					buffer_length_used += snprintf(nullptr, 0, "\n");
				}
			}
		}

		debug_point;
	}

	debug_point;

	if (buffer && buffer_length > 0)
	{
		buffer[buffer_length - 1] = 0;
		return static_cast<unsigned long>(buffer_position - buffer);
	}
	else
	{
		return buffer_length_used;
	}
}

void write_stack_trace_to_file(FILE* output, s_tracked_memory_entry* tracked_memory_entry)
{
#define file_write_line(file, format, ...) fprintf(file, format, __VA_ARGS__); fprintf(file, "\n")

	uint32_t stack_trace_size = write_stack_trace(tracked_memory_entry->stack_frames, tracked_memory_entry->num_stack_frames, nullptr, 0) + 1;
	char* stack_trace = static_cast<char*>(_alloca(stack_trace_size));
	uint32_t stack_trace_size1 = write_stack_trace(tracked_memory_entry->stack_frames, tracked_memory_entry->num_stack_frames, stack_trace, stack_trace_size);
	debug_point;

	file_write_line(output, stack_trace);
}

void write_memory_allocations()
{
	FILE* output = fopen("memory_allocations.txt", "w");

	DWORD thread_id = GetCurrentThreadId();
	while (atomic_cmpxchg32(&tracked_memory_entries_spin_lock, thread_id, 0));
	file_write_line(output, "Global memory stats");
	file_write_line(output, "\t allocated_memory:         %lli", allocated_memory);
	file_write_line(output, "\t tracked_allocated_memory: %lli", tracked_allocated_memory);
	file_write_line(output, "\t allocation_count:         %i", allocation_count);

	HANDLE current_process = GetCurrentProcess();
	DWORD sym_current_options_mask = SymGetOptions();
	sym_current_options_mask |= SYMOPT_LOAD_LINES;
	sym_current_options_mask |= SYMOPT_UNDNAME;
	DWORD sym_old_options_mask = SymSetOptions(sym_current_options_mask);

	BOOL sym_initialize_result = SymInitialize(current_process, NULL, TRUE);
	if (sym_initialize_result == FALSE)
	{
		throw;
	}

	uint32_t missed_output_entries = 0;
	for (s_tracked_memory_entry* tracked_memory_entry = tracked_memory_entries; tracked_memory_entry; tracked_memory_entry = tracked_memory_entry->previous)
	{
		if (tracked_memory_entry->filepath)
		{
			file_write_line(output, "%s(%i): warning MLEAK: memory leak detected 0x%p", tracked_memory_entry->filepath, tracked_memory_entry->line, tracked_memory_entry->memory);

			debug_point;
		}
		else
		{
			file_write_line(output, "(unknown): warning MLEAK: memory leak detected");
		}
		fflush(output);
		if (tracked_memory_entry->num_stack_frames > 0)
		{
			write_stack_trace_to_file(output, tracked_memory_entry);
		}
		fflush(output);
	}
	int32_t lock_release_result = atomic_cmpxchg32(&tracked_memory_entries_spin_lock, 0, thread_id);
	if (lock_release_result != thread_id) throw;

	if (missed_output_entries > 0)
	{
		file_write_line(output, "%u entries had no file/line data", missed_output_entries);
	}

	BOOL sym_cleanup_result = SymCleanup(current_process);
	if (sym_cleanup_result == FALSE)
	{
		throw;
	}

	fclose(output);

#undef file_write_line
}

void memory_collect()
{
	mi_collect(true);
}
