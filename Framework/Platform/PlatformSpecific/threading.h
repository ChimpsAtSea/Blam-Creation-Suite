#pragma once

template<typename t_index_type>
using t_parallel_invoke_func = void(*)(void* userdata, t_index_type index);
using t_parallel_invoke_long_func = t_parallel_invoke_func<int32_t>;
using t_parallel_invoke_longlong_func = t_parallel_invoke_func<int64_t>;
using t_parallel_invoke_ulong_func = t_parallel_invoke_func<uint32_t>;
using t_parallel_invoke_ulonglong_func = t_parallel_invoke_func<uint64_t>;

template<typename t_index_type>
using t_parallel_invoke_thread_count_func = void(*)(void* userdata, t_index_type index, t_index_type thread_count);
using t_parallel_invoke_thread_count_long_func = t_parallel_invoke_thread_count_func<int32_t>;
using t_parallel_invoke_thread_count_longlong_func = t_parallel_invoke_thread_count_func<int64_t>;
using t_parallel_invoke_thread_count_ulong_func = t_parallel_invoke_thread_count_func<uint32_t>;
using t_parallel_invoke_thread_count_ulonglong_func = t_parallel_invoke_thread_count_func<uint64_t>;

#ifndef __INTELLISENSE__
BCS_SHARED extern void (*parallel_invoke_impl0)(int32_t start, int32_t end, t_parallel_invoke_long_func parallel_invoke_func, void* userdata);
BCS_SHARED extern void (*parallel_invoke_impl1)(int64_t start, int64_t end, t_parallel_invoke_longlong_func parallel_invoke_func, void* userdata);
BCS_SHARED extern void (*parallel_invoke_impl2)(uint32_t start, uint32_t end, t_parallel_invoke_ulong_func parallel_invoke_func, void* userdata);
BCS_SHARED extern void (*parallel_invoke_impl3)(uint64_t start, uint64_t end, t_parallel_invoke_ulonglong_func parallel_invoke_func, void* userdata);
#endif

BCS_SHARED extern void parallel_invoke(int32_t start, int32_t end, t_parallel_invoke_long_func parallel_invoke_func, void* userdata);
BCS_SHARED extern void parallel_invoke(int64_t start, int64_t end, t_parallel_invoke_longlong_func parallel_invoke_func, void* userdata);
BCS_SHARED extern void parallel_invoke(uint32_t start, uint32_t end, t_parallel_invoke_ulong_func parallel_invoke_func, void* userdata);
BCS_SHARED extern void parallel_invoke(uint64_t start, uint64_t end, t_parallel_invoke_ulonglong_func parallel_invoke_func, void* userdata);


#ifndef __INTELLISENSE__
BCS_SHARED extern void (*parallel_invoke_thread_count_impl0)(t_parallel_invoke_thread_count_long_func parallel_invoke_thread_count_func, void* userdata);
BCS_SHARED extern void (*parallel_invoke_thread_count_impl1)(t_parallel_invoke_thread_count_longlong_func parallel_invoke_thread_count_func, void* userdata);
BCS_SHARED extern void (*parallel_invoke_thread_count_impl2)(t_parallel_invoke_thread_count_ulong_func parallel_invoke_thread_count_func, void* userdata);
BCS_SHARED extern void (*parallel_invoke_thread_count_impl3)(t_parallel_invoke_thread_count_ulonglong_func parallel_invoke_thread_count_func, void* userdata);
#endif

BCS_SHARED extern void parallel_invoke_thread_count(t_parallel_invoke_thread_count_long_func parallel_invoke_func, void* userdata);
BCS_SHARED extern void parallel_invoke_thread_count(t_parallel_invoke_thread_count_longlong_func parallel_invoke_func, void* userdata);
BCS_SHARED extern void parallel_invoke_thread_count(t_parallel_invoke_thread_count_ulong_func parallel_invoke_func, void* userdata);
BCS_SHARED extern void parallel_invoke_thread_count(t_parallel_invoke_thread_count_ulonglong_func parallel_invoke_func, void* userdata);

struct t_task_group;
BCS_SHARED BCS_RESULT task_group_create(t_task_group*& task_group);

BCS_SHARED BCS_RESULT task_group_destroy(t_task_group* task_group);

typedef void(*t_task_func1)(void* userdata);
BCS_SHARED BCS_RESULT task_group_run(t_task_group* task_group, t_task_func1 task_func, void* userdata);
BCS_SHARED BCS_RESULT task_group_run_and_wait(t_task_group* task_group, t_task_func1 task_func, void* userdata);
typedef void(*t_task_func2)(void* userdata0, void* userdata1);
BCS_SHARED BCS_RESULT task_group_run(t_task_group* task_group, t_task_func2 task_func, void* userdata0, void* userdata1);
BCS_SHARED BCS_RESULT task_group_run_and_wait(t_task_group* task_group, t_task_func2 task_func, void* userdata0, void* userdata1);

BCS_SHARED BCS_RESULT task_group_wait(t_task_group* task_group);
BCS_SHARED BCS_RESULT task_group_cancel(t_task_group* task_group);

BCS_SHARED extern uint32_t get_processors_thread_count();