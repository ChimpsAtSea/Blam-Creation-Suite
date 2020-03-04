#include "shared-private-pch.h"

class thread_subroutine_task_impl : 
	public tbb::task 
{
	c_thread_subroutine& thread_subroutine;

	tbb::task* execute()
	{
		do
		{
			thread_subroutine.subroutine();
		} 
		while (thread_subroutine.run_count.fetch_and(0u)); // run this task while is it queued

		return NULL;
	}

public:
	thread_subroutine_task_impl(c_thread_subroutine& thread_subroutine) : thread_subroutine(thread_subroutine) {}
};

tbb::task* thread_subroutine_task(c_thread_subroutine& thread_subroutine)
{
	return new(tbb::task::allocate_root()) thread_subroutine_task_impl(thread_subroutine);
}

void c_thread_subroutine::run()
{
	uint32_t previous_run_count = run_count.fetch_add(1);
	if (previous_run_count == 0)
	{
		tbb::task::enqueue(*thread_subroutine_task(*this));
	}
}
