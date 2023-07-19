#include "platform-private-pch.h"

extern uint32_t max_threads;
extern uint32_t processors_thread_count;
#define MINIMUM_PARALLEL_THREADS 4

template<typename t_index_type>
struct s_parallel_invoke_thread_count_multi_threaded_worker_userdata
{
	t_parallel_invoke_thread_count_func<t_index_type> parallel_invoke_thread_count_func;
	void* userdata;
	volatile t_index_type index;
	t_index_type thread_count;
};

template<typename t_index_type> DWORD WINAPI _parallel_invoke_thread_count_multi_threaded_worker(LPVOID lpThreadParameter);

template<> DWORD WINAPI _parallel_invoke_thread_count_multi_threaded_worker<int32_t>(LPVOID lpThreadParameter)
{
	using t_index_type = int32_t;
	s_parallel_invoke_thread_count_multi_threaded_worker_userdata<t_index_type>* _worker_userdata = static_cast<s_parallel_invoke_thread_count_multi_threaded_worker_userdata<t_index_type>*>(lpThreadParameter);

	t_parallel_invoke_thread_count_func<t_index_type> const parallel_invoke_thread_count_func = _worker_userdata->parallel_invoke_thread_count_func;
	void* const userdata = _worker_userdata->userdata;
	volatile t_index_type* const worker_index = &_worker_userdata->index;
	t_index_type const thread_count = _worker_userdata->thread_count;

#define _parallel_invole_get_index atomic_fetch_inc32(worker_index)
	for (t_index_type index = _parallel_invole_get_index; index < thread_count; index = _parallel_invole_get_index)
	{
		parallel_invoke_thread_count_func(userdata, index, thread_count);
	}
#undef _parallel_invole_get_index
	return 0;
}

template<> DWORD WINAPI _parallel_invoke_thread_count_multi_threaded_worker<int64_t>(LPVOID lpThreadParameter)
{
	using t_index_type = int64_t;
	s_parallel_invoke_thread_count_multi_threaded_worker_userdata<t_index_type>* _worker_userdata = static_cast<s_parallel_invoke_thread_count_multi_threaded_worker_userdata<t_index_type>*>(lpThreadParameter);

	t_parallel_invoke_thread_count_func<t_index_type> const parallel_invoke_thread_count_func = _worker_userdata->parallel_invoke_thread_count_func;
	void* const userdata = _worker_userdata->userdata;
	volatile t_index_type* const worker_index = &_worker_userdata->index;
	t_index_type const thread_count = _worker_userdata->thread_count;

#define _parallel_invole_get_index atomic_fetch_inc64(worker_index)
	for (t_index_type index = _parallel_invole_get_index; index < thread_count; index = _parallel_invole_get_index)
	{
		parallel_invoke_thread_count_func(userdata, index, thread_count);
	}
#undef _parallel_invole_get_index
	return 0;
}

template<> DWORD WINAPI _parallel_invoke_thread_count_multi_threaded_worker<uint32_t>(LPVOID lpThreadParameter)
{
	using t_index_type = uint32_t;
	s_parallel_invoke_thread_count_multi_threaded_worker_userdata<t_index_type>* _worker_userdata = static_cast<s_parallel_invoke_thread_count_multi_threaded_worker_userdata<t_index_type>*>(lpThreadParameter);

	t_parallel_invoke_thread_count_func<t_index_type> const parallel_invoke_thread_count_func = _worker_userdata->parallel_invoke_thread_count_func;
	void* const userdata = _worker_userdata->userdata;
	volatile t_index_type* const worker_index = &_worker_userdata->index;
	t_index_type const thread_count = _worker_userdata->thread_count;

#define _parallel_invole_get_index atomic_fetch_incu32(worker_index)
	for (t_index_type index = _parallel_invole_get_index; index < thread_count; index = _parallel_invole_get_index)
	{
		parallel_invoke_thread_count_func(userdata, index, thread_count);
	}
#undef _parallel_invole_get_index
	return 0;
}

template<> DWORD WINAPI _parallel_invoke_thread_count_multi_threaded_worker<uint64_t>(LPVOID lpThreadParameter)
{
	using t_index_type = uint64_t;
	s_parallel_invoke_thread_count_multi_threaded_worker_userdata<t_index_type>* _worker_userdata = static_cast<s_parallel_invoke_thread_count_multi_threaded_worker_userdata<t_index_type>*>(lpThreadParameter);

	t_parallel_invoke_thread_count_func<t_index_type> const parallel_invoke_thread_count_func = _worker_userdata->parallel_invoke_thread_count_func;
	void* const userdata = _worker_userdata->userdata;
	volatile t_index_type* const worker_index = &_worker_userdata->index;
	t_index_type const thread_count = _worker_userdata->thread_count;

#define _parallel_invole_get_index atomic_fetch_incu64(worker_index)
	for (t_index_type index = _parallel_invole_get_index; index < thread_count; index = _parallel_invole_get_index)
	{
		parallel_invoke_thread_count_func(userdata, index, thread_count);
	}
#undef _parallel_invole_get_index
	return 0;
}

template<typename t_index_type>
static void _parallel_invoke_thread_count_multi_threaded(t_parallel_invoke_thread_count_func<t_index_type> parallel_invoke_thread_count_func, void* userdata)
{
	uint64_t thread_count = UINT64_MAX;
	thread_count = __min(thread_count, processors_thread_count); // don't exceed hardware threads or go too low
	thread_count = __min(thread_count, max_threads); // can't exceet command line max threads
	thread_count = __max(thread_count, MINIMUM_PARALLEL_THREADS); // must have atleast minimum parallel threads to hide sync IO latency
	thread_count = __max(thread_count, 1);

	s_parallel_invoke_thread_count_multi_threaded_worker_userdata<t_index_type> worker_userdata = {};
	worker_userdata.parallel_invoke_thread_count_func = parallel_invoke_thread_count_func;
	worker_userdata.userdata = userdata;
	worker_userdata.index = 0;
	worker_userdata.thread_count = thread_count;

	if (thread_count == 1) // dont bother spawning threads for a single task
	{
		_parallel_invoke_thread_count_multi_threaded_worker<t_index_type>(&worker_userdata);
	}
	else
	{
		HANDLE* threads = new(_alloca(sizeof(HANDLE) * thread_count)) HANDLE[thread_count];
		for (size_t thread_index = 1; thread_index < thread_count; thread_index++)
		{
			threads[thread_index] = CreateThread(NULL, 0, _parallel_invoke_thread_count_multi_threaded_worker<t_index_type>, &worker_userdata, 0, NULL);
		}
		_parallel_invoke_thread_count_multi_threaded_worker<t_index_type>(&worker_userdata);
		for (size_t thread_index = 1; thread_index < thread_count; thread_index++)
		{
			HANDLE thread = threads[thread_index];
			DWORD result = WaitForSingleObject(thread, INFINITE);
			ASSERT(result == WAIT_OBJECT_0);
			DWORD error = GetLastError();
			debug_point;
			// #TODO: Cleanup
		}
	}

	debug_point;
}

static void _parallel_invoke_thread_count_single_threaded(t_parallel_invoke_thread_count_long_func parallel_invoke_thread_count_func, void* userdata)
{
	parallel_invoke_thread_count_func(userdata, 0, 1);
}

static void _parallel_invoke_thread_count_single_threaded(t_parallel_invoke_thread_count_longlong_func parallel_invoke_thread_count_func, void* userdata)
{
	parallel_invoke_thread_count_func(userdata, 0, 1);
}

static void _parallel_invoke_thread_count_single_threaded(t_parallel_invoke_thread_count_ulong_func parallel_invoke_thread_count_func, void* userdata)
{
	parallel_invoke_thread_count_func(userdata, 0, 1);
}

static void _parallel_invoke_thread_count_single_threaded(t_parallel_invoke_thread_count_ulonglong_func parallel_invoke_thread_count_func, void* userdata)
{
	parallel_invoke_thread_count_func(userdata, 0, 1);
}

#define PARALLEL_INVOKE_THREAD_COUNT_FIRST_RUN_FIXUP(target_pointer, single_threaded_function, multi_threaded_function)	\
	processors_thread_count = get_processors_thread_count(); \
	if (BCS_FAILED(command_line_get_argument_ulong("maxthreads", max_threads))) { max_threads = UINT_MAX; } \
	if (BCS_SUCCEEDED(command_line_has_argument_internal("singlethreaded")) || max_threads == 1) target_pointer = single_threaded_function; \
	else target_pointer = multi_threaded_function;



static void _parallel_invoke_thread_count_first_run(t_parallel_invoke_thread_count_long_func parallel_invoke_thread_count_func, void* userdata)
{
	PARALLEL_INVOKE_THREAD_COUNT_FIRST_RUN_FIXUP(parallel_invoke_thread_count_impl0, _parallel_invoke_thread_count_single_threaded, _parallel_invoke_thread_count_multi_threaded<int32_t>);
	return parallel_invoke_thread_count_impl0(parallel_invoke_thread_count_func, userdata);
}

static void _parallel_invoke_thread_count_first_run(t_parallel_invoke_thread_count_longlong_func parallel_invoke_thread_count_func, void* userdata)
{
	PARALLEL_INVOKE_THREAD_COUNT_FIRST_RUN_FIXUP(parallel_invoke_thread_count_impl1, _parallel_invoke_thread_count_single_threaded, _parallel_invoke_thread_count_multi_threaded<int64_t>);
	return parallel_invoke_thread_count_impl1(parallel_invoke_thread_count_func, userdata);
}

static void _parallel_invoke_thread_count_first_run(t_parallel_invoke_thread_count_ulong_func parallel_invoke_thread_count_func, void* userdata)
{
	PARALLEL_INVOKE_THREAD_COUNT_FIRST_RUN_FIXUP(parallel_invoke_thread_count_impl2, _parallel_invoke_thread_count_single_threaded, _parallel_invoke_thread_count_multi_threaded<uint32_t>);
	return parallel_invoke_thread_count_impl2(parallel_invoke_thread_count_func, userdata);
}

static void _parallel_invoke_thread_count_first_run(t_parallel_invoke_thread_count_ulonglong_func parallel_invoke_thread_count_func, void* userdata)
{
	PARALLEL_INVOKE_THREAD_COUNT_FIRST_RUN_FIXUP(parallel_invoke_thread_count_impl3, _parallel_invoke_thread_count_single_threaded, _parallel_invoke_thread_count_multi_threaded<uint64_t>);
	return parallel_invoke_thread_count_impl3(parallel_invoke_thread_count_func, userdata);
}

void (*parallel_invoke_thread_count_impl0)(t_parallel_invoke_thread_count_long_func parallel_invoke_thread_count_func, void* userdata) = _parallel_invoke_thread_count_first_run;
void (*parallel_invoke_thread_count_impl1)(t_parallel_invoke_thread_count_longlong_func parallel_invoke_thread_count_func, void* userdata) = _parallel_invoke_thread_count_first_run;
void (*parallel_invoke_thread_count_impl2)(t_parallel_invoke_thread_count_ulong_func parallel_invoke_thread_count_func, void* userdata) = _parallel_invoke_thread_count_first_run;
void (*parallel_invoke_thread_count_impl3)(t_parallel_invoke_thread_count_ulonglong_func parallel_invoke_thread_count_func, void* userdata) = _parallel_invoke_thread_count_first_run;

void parallel_invoke_thread_count(t_parallel_invoke_thread_count_long_func parallel_invoke_thread_count_func, void* userdata)
{
	parallel_invoke_thread_count_impl0(parallel_invoke_thread_count_func, userdata);
}

void parallel_invoke_thread_count(t_parallel_invoke_thread_count_longlong_func parallel_invoke_thread_count_func, void* userdata)
{
	parallel_invoke_thread_count_impl1(parallel_invoke_thread_count_func, userdata);
}

void parallel_invoke_thread_count(t_parallel_invoke_thread_count_ulong_func parallel_invoke_thread_count_func, void* userdata)
{
	parallel_invoke_thread_count_impl2(parallel_invoke_thread_count_func, userdata);
}

void parallel_invoke_thread_count(t_parallel_invoke_thread_count_ulonglong_func parallel_invoke_thread_count_func, void* userdata)
{
	parallel_invoke_thread_count_impl3(parallel_invoke_thread_count_func, userdata);
}

void barrier(unsigned int thread_index, unsigned int thread_count, unsigned int volatile& barrier)
{
	unsigned int barrier_value = atomic_inc_fetchu32(&barrier);
	unsigned int barrier_end = ROUND_UP_VALUE(barrier_value, thread_count);
	unsigned int iterations = 0;
	while (barrier < barrier_end)
	{
		unsigned int sleep_miliseconds = __popcnt(iterations++);
		Sleep(sleep_miliseconds);
	}
}

BCS_RESULT barrier_result_sync(unsigned int thread_index, unsigned int thread_count, unsigned int volatile& barrier, BCS_RESULT volatile& storage, BCS_RESULT rs)
{
	bcs_atomic_result(storage, rs); // store the result
	unsigned int barrier_value = atomic_inc_fetchu32(&barrier);
	unsigned int barrier_end = ROUND_UP_VALUE(barrier_value, thread_count);
	unsigned int iterations = 0;
	while (barrier < barrier_end)
	{
		unsigned int sleep_miliseconds = __popcnt(iterations++);
		Sleep(sleep_miliseconds);
	}
	return bcs_atomic_result(storage, rs); // retrieve the result
}
