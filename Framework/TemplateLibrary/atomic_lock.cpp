#include "templatelibrary-private-pch.h"

c_atomic_lock::c_atomic_lock() :
	lock_value(0)
{

}

void c_atomic_lock::lock()
{
	while (atomic_cmpxchg32(&lock_value, 1l, 0l) != 0l) {};
}

bool c_atomic_lock::try_lock()
{
	return atomic_cmpxchg32(&lock_value, 1l, 0l) == 0;
}

void c_atomic_lock::unlock()
{
	atomic_dec32(&lock_value);
}

c_atomic_lock_guard::c_atomic_lock_guard(c_atomic_lock& atomic_lock) :
	atomic_lock(atomic_lock)
{
	atomic_lock.lock();
}

c_atomic_lock_guard::~c_atomic_lock_guard()
{
	atomic_lock.unlock();
}
