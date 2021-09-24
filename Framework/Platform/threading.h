#pragma once

typedef void(*t_parallel_invoke_long_func)(void* userdata, long index);
BCS_DEBUG_API void parallel_invoke(long start, long end, t_parallel_invoke_long_func parallel_invoke_func, void* userdata);

typedef void(*t_parallel_invoke_longlong_func)(void* userdata, long long index);
BCS_DEBUG_API void parallel_invoke(long long start, long long end, t_parallel_invoke_longlong_func parallel_invoke_func, void* userdata);

typedef void(*t_parallel_invoke_ulong_func)(void* userdata, unsigned long index);
BCS_DEBUG_API void parallel_invoke(unsigned long start, unsigned long end, t_parallel_invoke_ulong_func parallel_invoke_func, void* userdata);

typedef void(*t_parallel_invoke_ulonglong_func)(void* userdata, unsigned long long index);
BCS_DEBUG_API void parallel_invoke(unsigned long long start, unsigned long long end, t_parallel_invoke_ulonglong_func parallel_invoke_func, void* userdata);

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

