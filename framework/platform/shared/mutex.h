#pragma once

// #TODO: This is a placeholder design for the mutex with acts as a pointer to implementation of std::mutex

class c_mutex
{
public:
	BCS_SHARED c_mutex();
	c_mutex(c_mutex const&) = delete;
	BCS_SHARED ~c_mutex();

	BCS_SHARED void lock();
	BCS_SHARED bool try_lock();
	BCS_SHARED void unlock();

protected:
	void* implementation;
};
