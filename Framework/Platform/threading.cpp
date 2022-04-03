#include "platform-private-pch.h"

using namespace tbb;

#define MINIMUM_PARALLEL_THREADS 4

unsigned long get_processors_thread_count()
{
	SYSTEM_INFO system_info;
	GetSystemInfo(&system_info);
	return system_info.dwNumberOfProcessors;
}

template<typename t_index_type>
struct s_parallel_invoke_multi_threaded_worker_userdata
{
	t_parallel_invoke_func<t_index_type> parallel_invoke_func;
	void* userdata;
	volatile t_index_type index;
	t_index_type end;
};

template<typename t_index_type> DWORD WINAPI _parallel_invoke_multi_threaded_worker(LPVOID lpThreadParameter);

template<> DWORD WINAPI _parallel_invoke_multi_threaded_worker<long>(LPVOID lpThreadParameter)
{
	using t_index_type = long;
	s_parallel_invoke_multi_threaded_worker_userdata<t_index_type>* _worker_userdata = static_cast<s_parallel_invoke_multi_threaded_worker_userdata<t_index_type>*>(lpThreadParameter);

	t_parallel_invoke_func<t_index_type> const parallel_invoke_func = _worker_userdata->parallel_invoke_func;
	void* const userdata = _worker_userdata->userdata;
	volatile t_index_type* const worker_index = &_worker_userdata->index;
	t_index_type const end = _worker_userdata->end;

#define _paralle_invole_get_index (_InterlockedIncrement(worker_index) - 1)
	for (t_index_type index = _paralle_invole_get_index; index < end; index = _paralle_invole_get_index)
	{
		parallel_invoke_func(userdata, index);
	}
#undef _paralle_invole_get_index
	console_write_line("Thread finished");
	return 0;
}

template<> DWORD WINAPI _parallel_invoke_multi_threaded_worker<long long>(LPVOID lpThreadParameter)
{
	using t_index_type = long long;
	s_parallel_invoke_multi_threaded_worker_userdata<t_index_type>* _worker_userdata = static_cast<s_parallel_invoke_multi_threaded_worker_userdata<t_index_type>*>(lpThreadParameter);

	t_parallel_invoke_func<t_index_type> const parallel_invoke_func = _worker_userdata->parallel_invoke_func;
	void* const userdata = _worker_userdata->userdata;
	volatile t_index_type* const worker_index = &_worker_userdata->index;
	t_index_type const end = _worker_userdata->end;

#define _paralle_invole_get_index (InterlockedIncrement64(worker_index) - 1)
	for (t_index_type index = _paralle_invole_get_index; index < end; index = _paralle_invole_get_index)
	{
		parallel_invoke_func(userdata, index);
	}
#undef _paralle_invole_get_index
	console_write_line("Thread finished");
	return 0;
}

template<> DWORD WINAPI _parallel_invoke_multi_threaded_worker<unsigned long>(LPVOID lpThreadParameter)
{
	using t_index_type = unsigned long;
	s_parallel_invoke_multi_threaded_worker_userdata<t_index_type>* _worker_userdata = static_cast<s_parallel_invoke_multi_threaded_worker_userdata<t_index_type>*>(lpThreadParameter);

	t_parallel_invoke_func<t_index_type> const parallel_invoke_func = _worker_userdata->parallel_invoke_func;
	void* const userdata = _worker_userdata->userdata;
	volatile t_index_type* const worker_index = &_worker_userdata->index;
	t_index_type const end = _worker_userdata->end;

#define _paralle_invole_get_index (InterlockedIncrement(worker_index) - 1)
	for (t_index_type index = _paralle_invole_get_index; index < end; index = _paralle_invole_get_index)
	{
		parallel_invoke_func(userdata, index);
	}
#undef _paralle_invole_get_index
	console_write_line("Thread finished");
	return 0;
}

template<> DWORD WINAPI _parallel_invoke_multi_threaded_worker<unsigned long long>(LPVOID lpThreadParameter)
{
	using t_index_type = unsigned long long;
	s_parallel_invoke_multi_threaded_worker_userdata<t_index_type>* _worker_userdata = static_cast<s_parallel_invoke_multi_threaded_worker_userdata<t_index_type>*>(lpThreadParameter);

	t_parallel_invoke_func<t_index_type> const parallel_invoke_func = _worker_userdata->parallel_invoke_func;
	void* const userdata = _worker_userdata->userdata;
	volatile t_index_type* const worker_index = &_worker_userdata->index;
	t_index_type const end = _worker_userdata->end;

#define _paralle_invole_get_index (InterlockedIncrement64(reinterpret_cast<volatile LONG64*>(worker_index)) - 1)
	for (t_index_type index = _paralle_invole_get_index; index < end; index = _paralle_invole_get_index)
	{
		parallel_invoke_func(userdata, index);
	}
#undef _paralle_invole_get_index
	console_write_line("Thread finished");
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

	// #TODO: Create a task system for this and queue jobs

	unsigned long processors_thread_count = get_processors_thread_count();
	unsigned long thread_count = static_cast<unsigned long>(__min(static_cast<unsigned long long>(job_count), __max(processors_thread_count, MINIMUM_PARALLEL_THREADS))) - 1;

	if (job_count <= 1)
	{
		_parallel_invoke_multi_threaded_worker<t_index_type>(&worker_userdata);
	}
	else
	{
		HANDLE* threads = new(alloca(sizeof(HANDLE) * thread_count)) HANDLE[thread_count];
		for (size_t thread_index = 0; thread_index < thread_count; thread_index++)
		{
			threads[thread_index] = CreateThread(NULL, 0, _parallel_invoke_multi_threaded_worker<t_index_type>, &worker_userdata, 0, NULL);
		}
		_parallel_invoke_multi_threaded_worker<t_index_type>(&worker_userdata);
		for (unsigned long wait_index = 0, wait_amount = __min(MAXIMUM_WAIT_OBJECTS, thread_count); wait_index < thread_count; wait_index -= wait_amount)
		{
			DWORD result = WaitForMultipleObjects(wait_amount, threads + wait_index, TRUE, INFINITE);
			ASSERT(result == WAIT_OBJECT_0);
			DWORD error = GetLastError();
			debug_point;
		}
	}

	debug_point;
}

static void _parallel_invoke_single_threaded(long start, long end, t_parallel_invoke_long_func parallel_invoke_func, void* userdata)
{
	for (decltype(start) index = start; index < end; index++) parallel_invoke_func(userdata, index);
}

static void _parallel_invoke_single_threaded(long long start, long long end, t_parallel_invoke_longlong_func parallel_invoke_func, void* userdata)
{
	for (decltype(start) index = start; index < end; index++) parallel_invoke_func(userdata, index);
}

static void _parallel_invoke_single_threaded(unsigned long start, unsigned long end, t_parallel_invoke_ulong_func parallel_invoke_func, void* userdata)
{
	for (decltype(start) index = start; index < end; index++) parallel_invoke_func(userdata, index);
}

static void _parallel_invoke_single_threaded(unsigned long long start, unsigned long long end, t_parallel_invoke_ulonglong_func parallel_invoke_func, void* userdata)
{
	for (decltype(start) index = start; index < end; index++) parallel_invoke_func(userdata, index);
}

#define PARALLEL_INVOKE_FIRST_RUN_FIXUP(target_pointer, single_threaded_function, multi_threaded_function)	\
	if (BCS_SUCCEEDED(command_line_has_argument("singlethreaded"))) target_pointer = single_threaded_function; \
	else target_pointer = multi_threaded_function;

static void _parallel_invoke_first_run(long start, long end, t_parallel_invoke_long_func parallel_invoke_func, void* userdata)
{
	PARALLEL_INVOKE_FIRST_RUN_FIXUP(parallel_invoke_impl0, _parallel_invoke_single_threaded, _parallel_invoke_multi_threaded<long>);
	return parallel_invoke_impl0(start, end, parallel_invoke_func, userdata);
}

static void _parallel_invoke_first_run(long long start, long long end, t_parallel_invoke_longlong_func parallel_invoke_func, void* userdata)
{
	PARALLEL_INVOKE_FIRST_RUN_FIXUP(parallel_invoke_impl1, _parallel_invoke_single_threaded, _parallel_invoke_multi_threaded<long long>);
	return parallel_invoke_impl1(start, end, parallel_invoke_func, userdata);
}

static void _parallel_invoke_first_run(unsigned long start, unsigned long end, t_parallel_invoke_ulong_func parallel_invoke_func, void* userdata)
{
	PARALLEL_INVOKE_FIRST_RUN_FIXUP(parallel_invoke_impl2, _parallel_invoke_single_threaded, _parallel_invoke_multi_threaded<unsigned long>);
	return parallel_invoke_impl2(start, end, parallel_invoke_func, userdata);
}

static void _parallel_invoke_first_run(unsigned long long start, unsigned long long end, t_parallel_invoke_ulonglong_func parallel_invoke_func, void* userdata)
{
	PARALLEL_INVOKE_FIRST_RUN_FIXUP(parallel_invoke_impl3, _parallel_invoke_single_threaded, _parallel_invoke_multi_threaded<unsigned long long>);
	return parallel_invoke_impl3(start, end, parallel_invoke_func, userdata);
}

void (*parallel_invoke_impl0)(long start, long end, t_parallel_invoke_long_func parallel_invoke_func, void* userdata) = _parallel_invoke_first_run;
void (*parallel_invoke_impl1)(long long start, long long end, t_parallel_invoke_longlong_func parallel_invoke_func, void* userdata) = _parallel_invoke_first_run;
void (*parallel_invoke_impl2)(unsigned long start, unsigned long end, t_parallel_invoke_ulong_func parallel_invoke_func, void* userdata) = _parallel_invoke_first_run;
void (*parallel_invoke_impl3)(unsigned long long start, unsigned long long end, t_parallel_invoke_ulonglong_func parallel_invoke_func, void* userdata) = _parallel_invoke_first_run;

void parallel_invoke(long start, long end, t_parallel_invoke_long_func parallel_invoke_func, void* userdata)
{
	parallel_invoke_impl0(start, end, parallel_invoke_func, userdata);
}

void parallel_invoke(long long start, long long end, t_parallel_invoke_longlong_func parallel_invoke_func, void* userdata)
{
	parallel_invoke_impl1(start, end, parallel_invoke_func, userdata);
}

void parallel_invoke(unsigned long start, unsigned long end, t_parallel_invoke_ulong_func parallel_invoke_func, void* userdata)
{
	parallel_invoke_impl2(start, end, parallel_invoke_func, userdata);
}

void parallel_invoke(unsigned long long start, unsigned long long end, t_parallel_invoke_ulonglong_func parallel_invoke_func, void* userdata)
{
	parallel_invoke_impl3(start, end, parallel_invoke_func, userdata);
}

BCS_RESULT task_group_create(t_task_group*& task_group)
{
	tbb::task_group*& tbb_task_group = *reinterpret_cast<tbb::task_group**>(&task_group);
	tbb_task_group = new() tbb::task_group();
	return BCS_S_OK;
}

BCS_RESULT task_group_destroy(t_task_group* task_group)
{
	BCS_VALIDATE_ARGUMENT(task_group);
	tbb::task_group* tbb_task_group = reinterpret_cast<tbb::task_group*>(task_group);
	delete tbb_task_group;
	return BCS_S_OK;
}

BCS_RESULT task_group_run(t_task_group* task_group, t_task_func1 task_func, void* userdata)
{
	BCS_VALIDATE_ARGUMENT(task_group);
	tbb::task_group* tbb_task_group = reinterpret_cast<tbb::task_group*>(task_group);
	tbb_task_group->run([task_func, userdata]() { task_func(userdata); });
	return BCS_S_OK;
}

BCS_RESULT task_group_run_and_wait(t_task_group* task_group, t_task_func1 task_func, void* userdata)
{
	BCS_VALIDATE_ARGUMENT(task_group);
	tbb::task_group* tbb_task_group = reinterpret_cast<tbb::task_group*>(task_group);
	tbb_task_group->run_and_wait([task_func, userdata]() { task_func(userdata); });
	return BCS_S_OK;
}

BCS_RESULT task_group_run(t_task_group* task_group, t_task_func2 task_func, void* userdata0, void* userdata1)
{
	BCS_VALIDATE_ARGUMENT(task_group);
	tbb::task_group* tbb_task_group = reinterpret_cast<tbb::task_group*>(task_group);
	tbb_task_group->run([task_func, userdata0, userdata1]() { task_func(userdata0, userdata1); });
	return BCS_S_OK;
}

BCS_RESULT task_group_run_and_wait(t_task_group* task_group, t_task_func2 task_func, void* userdata0, void* userdata1)
{
	BCS_VALIDATE_ARGUMENT(task_group);
	tbb::task_group* tbb_task_group = reinterpret_cast<tbb::task_group*>(task_group);
	tbb_task_group->run_and_wait([task_func, userdata0, userdata1]() { task_func(userdata0, userdata1); });
	return BCS_S_OK;
}

BCS_RESULT task_group_wait(t_task_group* task_group)
{
	tbb::task_group* tbb_task_group = reinterpret_cast<tbb::task_group*>(task_group);
	tbb_task_group->wait();
	return BCS_S_OK;
}

BCS_RESULT task_group_cancel(t_task_group* task_group)
{
	tbb::task_group* tbb_task_group = reinterpret_cast<tbb::task_group*>(task_group);
	tbb_task_group->cancel();
	return BCS_S_OK;
}