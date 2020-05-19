#pragma once

class c_semaphore
{
public:
	c_semaphore() :
		mutex(),
		condition(),
		count(0)
	{

	}

	void notify() 
	{
		std::lock_guard<std::mutex> lock(mutex);
		count++;
		condition.notify_one();
	}

	void wait() 
	{
		std::unique_lock<std::mutex> lock(mutex);
		while (count == 0)
		{
			condition.wait(lock);
		}
		count--;
	}

	bool try_wait() 
	{
		std::lock_guard<std::mutex> lock(mutex);
		if (count != 0)
		{
			count--;
			return true;
		}
		return false;
	}

private:
	std::mutex mutex; // #TODO: replace with tbb::mutex
	std::condition_variable condition;
	unsigned long count;
};

