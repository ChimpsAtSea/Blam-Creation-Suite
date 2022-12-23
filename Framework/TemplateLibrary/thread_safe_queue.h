#pragma once

#include <queue> // #TODO: replace this

template <class T>
class c_thread_safe_queue
{
public:
	c_thread_safe_queue()
		: queue()
		, lock()
	{}

	void Enqueue(T value)
	{
		c_atomic_lock_guard lock_guard(lock);
		queue.push(value);
	}

	bool Dequeue(T& result)
	{
		c_atomic_lock_guard lock_guard(lock);
		if (queue.empty())
		{
			return false;
		}
		result = queue.front();
		queue.pop();
		return true;
	}

private:
	std::queue<T> queue;
	c_atomic_lock lock;
};
