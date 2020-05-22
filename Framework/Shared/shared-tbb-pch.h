#pragma once

#define __TBB_SOURCE_DIRECTLY_INCLUDED 1
#include <tbb/tbb.h>
#include <tbb/parallel_for.h>
#include <tbb/blocked_range.h>
using namespace tbb;

template<typename F>
tbb::task* lambda_task(const F& f)
{
	class lambda_task_impl : public tbb::task {
		F my_func;
		/*override*/ tbb::task* execute() {
			my_func();
			return NULL;
		}
	public:
		lambda_task_impl(const F& f) : my_func(f) {}
	};

	return new(tbb::task::allocate_root()) lambda_task_impl(f);
}
