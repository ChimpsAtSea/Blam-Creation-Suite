#pragma once

template<typename t_index_type>
using t_parallel_invoke_func = void(*)(void* userdata, t_index_type index);
using t_parallel_invoke_long_func = t_parallel_invoke_func<long>;
using t_parallel_invoke_longlong_func = t_parallel_invoke_func<long long>;
using t_parallel_invoke_ulong_func = t_parallel_invoke_func<unsigned long>;
using t_parallel_invoke_ulonglong_func = t_parallel_invoke_func<unsigned long long>;

#ifndef __INTELLISENSE__
BCS_DEBUG_API extern void (*parallel_invoke_impl0)(long start, long end, t_parallel_invoke_long_func parallel_invoke_func, void* userdata);
BCS_DEBUG_API extern void (*parallel_invoke_impl1)(long long start, long long end, t_parallel_invoke_longlong_func parallel_invoke_func, void* userdata);
BCS_DEBUG_API extern void (*parallel_invoke_impl2)(unsigned long start, unsigned long end, t_parallel_invoke_ulong_func parallel_invoke_func, void* userdata);
BCS_DEBUG_API extern void (*parallel_invoke_impl3)(unsigned long long start, unsigned long long end, t_parallel_invoke_ulonglong_func parallel_invoke_func, void* userdata);
#endif

BCS_DEBUG_API extern void parallel_invoke(long start, long end, t_parallel_invoke_long_func parallel_invoke_func, void* userdata);
BCS_DEBUG_API extern void parallel_invoke(long long start, long long end, t_parallel_invoke_longlong_func parallel_invoke_func, void* userdata);
BCS_DEBUG_API extern void parallel_invoke(unsigned long start, unsigned long end, t_parallel_invoke_ulong_func parallel_invoke_func, void* userdata);
BCS_DEBUG_API extern void parallel_invoke(unsigned long long start, unsigned long long end, t_parallel_invoke_ulonglong_func parallel_invoke_func, void* userdata);

struct t_task_group;
BCS_DEBUG_API BCS_RESULT task_group_create(t_task_group*& task_group);

BCS_DEBUG_API BCS_RESULT task_group_destroy(t_task_group* task_group);

typedef void(*t_task_func1)(void* userdata);
BCS_DEBUG_API BCS_RESULT task_group_run(t_task_group* task_group, t_task_func1 task_func, void* userdata);
BCS_DEBUG_API BCS_RESULT task_group_run_and_wait(t_task_group* task_group, t_task_func1 task_func, void* userdata);
typedef void(*t_task_func2)(void* userdata0, void* userdata1);
BCS_DEBUG_API BCS_RESULT task_group_run(t_task_group* task_group, t_task_func2 task_func, void* userdata0, void* userdata1);
BCS_DEBUG_API BCS_RESULT task_group_run_and_wait(t_task_group* task_group, t_task_func2 task_func, void* userdata0, void* userdata1);

BCS_DEBUG_API BCS_RESULT task_group_wait(t_task_group* task_group);
BCS_DEBUG_API BCS_RESULT task_group_cancel(t_task_group* task_group);

BCS_DEBUG_API extern unsigned long get_processors_thread_count();