#pragma once

template <class T>
class ThreadSafeQueue
{
public:
	ThreadSafeQueue()
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
