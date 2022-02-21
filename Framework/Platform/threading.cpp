#include "platform-private-pch.h"


#pragma warning( push )
#pragma warning( disable : 4180 )

#ifndef _DEBUG
#pragma comment(lib, "tbb_static.lib")
#endif

#pragma warning( pop )

using namespace tbb;

void parallel_invoke(long start, long end, t_parallel_invoke_long_func parallel_invoke_func, void* userdata)
{
	tbb::parallel_for(start, end, [parallel_invoke_func, userdata](long index) { parallel_invoke_func(userdata, index); });
}

void parallel_invoke(long long start, long long end, t_parallel_invoke_longlong_func parallel_invoke_func, void* userdata)
{
	tbb::parallel_for(start, end, [parallel_invoke_func, userdata](long long index) { parallel_invoke_func(userdata, index); });
}

void parallel_invoke(unsigned long start, unsigned long end, t_parallel_invoke_ulong_func parallel_invoke_func, void* userdata)
{
	tbb::parallel_for(start, end, [parallel_invoke_func, userdata](unsigned long index) { parallel_invoke_func(userdata, index); });
}

void parallel_invoke(unsigned long long start, unsigned long long end, t_parallel_invoke_ulonglong_func parallel_invoke_func, void* userdata)
{
	tbb::parallel_for(start, end, [parallel_invoke_func, userdata](unsigned long long index) { parallel_invoke_func(userdata, index); });
}

BCS_RESULT task_group_create(t_task_group*& task_group)
{
	tbb::task_group*& tbb_task_group = *reinterpret_cast<tbb::task_group**>(&task_group);
	tbb_task_group = new tbb::task_group();
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