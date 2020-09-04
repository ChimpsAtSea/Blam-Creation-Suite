#pragma once

#ifndef NO_TBB
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

#define this_invoke(function, ...) ([&]() { this->function(##__VA_ARGS__); })

#endif


class c_atomic_lock
{
public:
	void Lock()
	{
		while (InterlockedCompareExchange(&lock, 1ul, 0ul) != 0ul) {};
	}

	bool TryLock()
	{
		return InterlockedCompareExchange(&lock, 1ul, 0ul) == 0;
	}

	void Unlock()
	{
		InterlockedDecrement(&lock);
	}
private:
	volatile unsigned long lock;
};

class c_atomic_lock_guard
{
public:
	c_atomic_lock_guard(c_atomic_lock& rLock)
		:atomic_lock(rLock)
	{
		atomic_lock.Lock();
	}

	~c_atomic_lock_guard()
	{
		atomic_lock.Unlock();
	}

private:
	c_atomic_lock& atomic_lock;
};

