#pragma once

class c_atomic_lock
{
public:
	BCS_SHARED c_atomic_lock();

	BCS_SHARED void lock();
	BCS_SHARED bool try_lock();
	BCS_SHARED void unlock();
private:
	volatile int32_t lock_value;
};

class c_atomic_lock_guard
{
public:
	BCS_SHARED c_atomic_lock_guard(c_atomic_lock& atomic_lock);
	BCS_SHARED ~c_atomic_lock_guard();

private:
	c_atomic_lock& atomic_lock;
};

