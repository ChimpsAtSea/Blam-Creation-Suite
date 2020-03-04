#pragma once

template<typename T>
class c_atomic_temp_value
{
public:
	void operator=(const T& new_value)
	{
		std::lock_guard<std::mutex> lock(mutex);
		value = new_value;
		atomic = 1;
	}

	bool get(T& output)
	{
		if (atomic)
		{
			std::lock_guard<std::mutex> lock(mutex);
			atomic = 0;
			output = value;
			value = {};
			return true;
		}
		return false;
	}

private:
	std::atomic<bool> atomic;
	std::mutex mutex; // #TODO: Remove this for a spin lock
	T value;
};
