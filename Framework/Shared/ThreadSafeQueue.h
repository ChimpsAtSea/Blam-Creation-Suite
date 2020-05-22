#pragma once

template <class T>
class ThreadSafeQueue
{
public:
	ThreadSafeQueue()
		: m_queue()
		, m_lock()
	{}

	void Enqueue(T value)
	{
		AtomicLockGuard lockGuard(m_lock);
		m_queue.push(value);
	}

	bool Dequeue(T& rResult)
	{
		AtomicLockGuard lockGuard(m_lock);
		if (m_queue.empty())
		{
			return false;
		}
		rResult = m_queue.front();
		m_queue.pop();
		return true;
	}

private:
	std::queue<T> m_queue;
	AtomicLock m_lock;
};
