#include "platform-private-pch.h"

using namespace tbb;

uint32_t max_threads = UINT_MAX;
uint32_t processors_thread_count = 1;
#define MINIMUM_PARALLEL_THREADS 4

uint32_t get_processors_thread_count()
{
	SYSTEM_INFO system_info;
	GetSystemInfo(&system_info);
	return system_info.dwNumberOfProcessors;
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