#include "platform-private-pch.h"

extern uint32_t max_threads;
extern uint32_t processors_thread_count;
#define MINIMUM_PARALLEL_THREADS 4

template<typename t_index_type>
struct s_parallel_invoke_multi_threaded_worker_userdata
{
	t_parallel_invoke_func<t_index_type> parallel_invoke_func;
	void* userdata;
	volatile t_index_type index;
	t_index_type end;
};

template<typename t_index_type> DWORD WINAPI _parallel_invoke_multi_threaded_worker(LPVOID lpThreadParameter);

template<> DWORD WINAPI _parallel_invoke_multi_threaded_worker<int32_t>(LPVOID lpThreadParameter)
{
	using t_index_type = int32_t;
	s_parallel_invoke_multi_threaded_worker_userdata<t_index_type>* _worker_userdata = static_cast<s_parallel_invoke_multi_threaded_worker_userdata<t_index_type>*>(lpThreadParameter);

	t_parallel_invoke_func<t_index_type> const parallel_invoke_func = _worker_userdata->parallel_invoke_func;
	void* const userdata = _worker_userdata->userdata;
	volatile t_index_type* const worker_index = &_worker_userdata->index;
	t_index_type const end = _worker_userdata->end;

#define _parallel_invole_get_index (atomic_inc32(worker_index) - 1)
	for (t_index_type index = _parallel_invole_get_index; index < end; index = _parallel_invole_get_index)
	{
		parallel_invoke_func(userdata, index);
	}
#undef _parallel_invole_get_index
	return 0;
}

template<> DWORD WINAPI _parallel_invoke_multi_threaded_worker<int64_t>(LPVOID lpThreadParameter)
{
	using t_index_type = int64_t;
	s_parallel_invoke_multi_threaded_worker_userdata<t_index_type>* _worker_userdata = static_cast<s_parallel_invoke_multi_threaded_worker_userdata<t_index_type>*>(lpThreadParameter);

	t_parallel_invoke_func<t_index_type> const parallel_invoke_func = _worker_userdata->parallel_invoke_func;
	void* const userdata = _worker_userdata->userdata;
	volatile t_index_type* const worker_index = &_worker_userdata->index;
	t_index_type const end = _worker_userdata->end;

#define _parallel_invole_get_index (InterlockedIncrement64(worker_index) - 1)
	for (t_index_type index = _parallel_invole_get_index; index < end; index = _parallel_invole_get_index)
	{
		parallel_invoke_func(userdata, index);
	}
#undef _parallel_invole_get_index
	return 0;
}

template<> DWORD WINAPI _parallel_invoke_multi_threaded_worker<uint32_t>(LPVOID lpThreadParameter)
{
	using t_index_type = uint32_t;
	s_parallel_invoke_multi_threaded_worker_userdata<t_index_type>* _worker_userdata = static_cast<s_parallel_invoke_multi_threaded_worker_userdata<t_index_type>*>(lpThreadParameter);

	t_parallel_invoke_func<t_index_type> const parallel_invoke_func = _worker_userdata->parallel_invoke_func;
	void* const userdata = _worker_userdata->userdata;
	volatile t_index_type* const worker_index = &_worker_userdata->index;
	t_index_type const end = _worker_userdata->end;

#define _parallel_invole_get_index (atomic_incu32(worker_index) - 1)
	for (t_index_type index = _parallel_invole_get_index; index < end; index = _parallel_invole_get_index)
	{
		parallel_invoke_func(userdata, index);
	}
#undef _parallel_invole_get_index
	return 0;
}

template<> DWORD WINAPI _parallel_invoke_multi_threaded_worker<uint64_t>(LPVOID lpThreadParameter)
{
	using t_index_type = uint64_t;
	s_parallel_invoke_multi_threaded_worker_userdata<t_index_type>* _worker_userdata = static_cast<s_parallel_invoke_multi_threaded_worker_userdata<t_index_type>*>(lpThreadParameter);

	t_parallel_invoke_func<t_index_type> const parallel_invoke_func = _worker_userdata->parallel_invoke_func;
	void* const userdata = _worker_userdata->userdata;
	volatile t_index_type* const worker_index = &_worker_userdata->index;
	t_index_type const end = _worker_userdata->end;

#define _parallel_invole_get_index (InterlockedIncrement64(reinterpret_cast<volatile LONG64*>(worker_index)) - 1)
	for (t_index_type index = _parallel_invole_get_index; index < end; index = _parallel_invole_get_index)
	{
		parallel_invoke_func(userdata, index);
	}
#undef _parallel_invole_get_index
	return 0;
}

template<typename t_index_type>
static void _parallel_invoke_multi_threaded(t_index_type start, t_index_type end, t_parallel_invoke_func<t_index_type> parallel_invoke_func, void* userdata)
{
	ASSERT(end >= start);
	t_index_type job_count = end - start;
	if (job_count == 0)
	{
		return;
	}

	s_parallel_invoke_multi_threaded_worker_userdata<t_index_type> worker_userdata = {};
	worker_userdata.parallel_invoke_func = parallel_invoke_func;
	worker_userdata.userdata = userdata;
	worker_userdata.index = start;
	worker_userdata.end = end;

	if (job_count == 1) // dont bother spawning threads for a single task
	{
		_parallel_invoke_multi_threaded_worker<t_index_type>(&worker_userdata);
	}
	else
	{
		// #TODO: Create a task system for this and queue jobs

		uint32_t thread_count = job_count;
		thread_count = __min(thread_count, processors_thread_count); // don't exceed hardware threads or go too low
		thread_count = __min(thread_count, max_threads); // can't exceet command line max threads
		thread_count = __max(thread_count, MINIMUM_PARALLEL_THREADS); // must have atleast minimum parallel threads to hide sync IO latency

		HANDLE* threads = new(_alloca(sizeof(HANDLE) * thread_count)) HANDLE[thread_count];
		for (size_t thread_index = 0; thread_index < thread_count; thread_index++)
		{
			threads[thread_index] = CreateThread(NULL, 0, _parallel_invoke_multi_threaded_worker<t_index_type>, &worker_userdata, 0, NULL);
		}
		_parallel_invoke_multi_threaded_worker<t_index_type>(&worker_userdata);
		for (uint32_t wait_index = 0, wait_amount = __min(MAXIMUM_WAIT_OBJECTS, thread_count); wait_index < thread_count; wait_index -= wait_amount)
		{
			DWORD result = WaitForMultipleObjects(wait_amount, threads + wait_index, TRUE, INFINITE);
			ASSERT(result == WAIT_OBJECT_0);
			DWORD error = GetLastError();
			debug_point;
		}
	}

	debug_point;
}

static void _parallel_invoke_single_threaded(int32_t start, int32_t end, t_parallel_invoke_long_func parallel_invoke_func, void* userdata)
{
	for (decltype(start) index = start; index < end; index++) parallel_invoke_func(userdata, index);
}

static void _parallel_invoke_single_threaded(int64_t start, int64_t end, t_parallel_invoke_longlong_func parallel_invoke_func, void* userdata)
{
	for (decltype(start) index = start; index < end; index++) parallel_invoke_func(userdata, index);
}

static void _parallel_invoke_single_threaded(uint32_t start, uint32_t end, t_parallel_invoke_ulong_func parallel_invoke_func, void* userdata)
{
	for (decltype(start) index = start; index < end; index++) parallel_invoke_func(userdata, index);
}

static void _parallel_invoke_single_threaded(uint64_t start, uint64_t end, t_parallel_invoke_ulonglong_func parallel_invoke_func, void* userdata)
{
	for (decltype(start) index = start; index < end; index++) parallel_invoke_func(userdata, index);
}

#define PARALLEL_INVOKE_FIRST_RUN_FIXUP(target_pointer, single_threaded_function, multi_threaded_function)	\
	processors_thread_count = get_processors_thread_count(); \
	if (BCS_FAILED(command_line_get_argument_ulong("maxthreads", max_threads))) { max_threads = UINT_MAX; } \
	if (BCS_SUCCEEDED(command_line_has_argument_internal("singlethreaded")) || max_threads == 1) target_pointer = single_threaded_function; \
	else target_pointer = multi_threaded_function;

static void _parallel_invoke_first_run(int32_t start, int32_t end, t_parallel_invoke_long_func parallel_invoke_func, void* userdata)
{
	PARALLEL_INVOKE_FIRST_RUN_FIXUP(parallel_invoke_impl0, _parallel_invoke_single_threaded, _parallel_invoke_multi_threaded<int32_t>);
	return parallel_invoke_impl0(start, end, parallel_invoke_func, userdata);
}

static void _parallel_invoke_first_run(int64_t start, int64_t end, t_parallel_invoke_longlong_func parallel_invoke_func, void* userdata)
{
	PARALLEL_INVOKE_FIRST_RUN_FIXUP(parallel_invoke_impl1, _parallel_invoke_single_threaded, _parallel_invoke_multi_threaded<int64_t>);
	return parallel_invoke_impl1(start, end, parallel_invoke_func, userdata);
}

static void _parallel_invoke_first_run(uint32_t start, uint32_t end, t_parallel_invoke_ulong_func parallel_invoke_func, void* userdata)
{
	PARALLEL_INVOKE_FIRST_RUN_FIXUP(parallel_invoke_impl2, _parallel_invoke_single_threaded, _parallel_invoke_multi_threaded<uint32_t>);
	return parallel_invoke_impl2(start, end, parallel_invoke_func, userdata);
}

static void _parallel_invoke_first_run(uint64_t start, uint64_t end, t_parallel_invoke_ulonglong_func parallel_invoke_func, void* userdata)
{
	PARALLEL_INVOKE_FIRST_RUN_FIXUP(parallel_invoke_impl3, _parallel_invoke_single_threaded, _parallel_invoke_multi_threaded<uint64_t>);
	return parallel_invoke_impl3(start, end, parallel_invoke_func, userdata);
}

void (*parallel_invoke_impl0)(int32_t start, int32_t end, t_parallel_invoke_long_func parallel_invoke_func, void* userdata) = _parallel_invoke_first_run;
void (*parallel_invoke_impl1)(int64_t start, int64_t end, t_parallel_invoke_longlong_func parallel_invoke_func, void* userdata) = _parallel_invoke_first_run;
void (*parallel_invoke_impl2)(uint32_t start, uint32_t end, t_parallel_invoke_ulong_func parallel_invoke_func, void* userdata) = _parallel_invoke_first_run;
void (*parallel_invoke_impl3)(uint64_t start, uint64_t end, t_parallel_invoke_ulonglong_func parallel_invoke_func, void* userdata) = _parallel_invoke_first_run;

void parallel_invoke(int32_t start, int32_t end, t_parallel_invoke_long_func parallel_invoke_func, void* userdata)
{
	parallel_invoke_impl0(start, end, parallel_invoke_func, userdata);
}

void parallel_invoke(int64_t start, int64_t end, t_parallel_invoke_longlong_func parallel_invoke_func, void* userdata)
{
	parallel_invoke_impl1(start, end, parallel_invoke_func, userdata);
}

void parallel_invoke(uint32_t start, uint32_t end, t_parallel_invoke_ulong_func parallel_invoke_func, void* userdata)
{
	parallel_invoke_impl2(start, end, parallel_invoke_func, userdata);
}

void parallel_invoke(uint64_t start, uint64_t end, t_parallel_invoke_ulonglong_func parallel_invoke_func, void* userdata)
{
	parallel_invoke_impl3(start, end, parallel_invoke_func, userdata);
}
