#pragma once

class AtomicLock
{
public:
	void Lock()
	{
		while (InterlockedCompareExchange(&m_lock, 1ul, 0ul) != 0ul) {};
	}

	bool TryLock()
	{
		return InterlockedCompareExchange(&m_lock, 1ul, 0ul) == 0;
	}

	void Unlock()
	{
		InterlockedDecrement(&m_lock);
	}
private:
	volatile unsigned long m_lock;
};

class AtomicLockGuard
{
public:
	AtomicLockGuard(AtomicLock& rLock)
		:m_rLock(rLock)
	{
		m_rLock.Lock();
	}

	~AtomicLockGuard()
	{
		m_rLock.Unlock();
	}

private:
	AtomicLock& m_rLock;
};
