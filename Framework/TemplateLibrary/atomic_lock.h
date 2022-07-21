#pragma once

class c_atomic_lock
{
public:
	BCS_DEBUG_API c_atomic_lock();

	BCS_DEBUG_API void lock();
	BCS_DEBUG_API bool try_lock();
	BCS_DEBUG_API void unlock();
private:
	volatile int32_t lock_value;
};

class c_atomic_lock_guard
{
public:
	BCS_DEBUG_API c_atomic_lock_guard(c_atomic_lock& atomic_lock);
	BCS_DEBUG_API ~c_atomic_lock_guard();

private:
	c_atomic_lock& atomic_lock;
};

