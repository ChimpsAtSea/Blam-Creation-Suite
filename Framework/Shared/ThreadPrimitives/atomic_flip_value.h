#pragma once

template<typename T>
class c_atomic_flip_value
{
public:
	c_atomic_flip_value(T& new_value)
		:value(value)
	{

	}

	void operator=(const T& value)
	{
		std::lock_guard<std::mutex> lock(mutex);
		pending_value = value;
		atomic = 1;
	}

	operator const T& ()
	{
		if (atomic)
		{
			std::lock_guard<std::mutex> lock(mutex);
			value = pending_value;
			atomic = 0;
		}
		return value;
	}

private:
	std::atomic<bool> atomic;
	std::mutex mutex; // #TODO: Remove this for a spin lock
	T pending_value;
	T value;
};
