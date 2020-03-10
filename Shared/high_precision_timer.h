#pragma once

class c_high_precision_timer
{
public:
	c_high_precision_timer() :
		start_time_point(),
		stop_time_point()
	{}

	void start()
	{ 
		start_time_point = std::chrono::high_resolution_clock::now(); 
		stop_time_point = start_time_point;
	}
	void stop() 
	{
		stop_time_point = std::chrono::high_resolution_clock::now(); 
	}

	template<typename T>
	T get_duration() const
	{
		if (start_time_point.time_since_epoch().count() == 0) return static_cast<T>(0);
		std::chrono::high_resolution_clock::duration duration = stop_time_point - start_time_point;
		return static_cast<T>(static_cast<double>(duration.count()) / static_cast<double>(decltype(duration)::period::den));
	}

	template<typename T>
	T get_duration_ms() const
	{
		if (start_time_point.time_since_epoch().count() == 0) return static_cast<T>(0);
		std::chrono::high_resolution_clock::duration duration = stop_time_point - start_time_point;
		return static_cast<T>(static_cast<double>(duration.count()) / (static_cast<double>(decltype(duration)::period::den) / 1000.0f));
	}
protected:
	bool is_started;
	std::chrono::high_resolution_clock::time_point start_time_point;
	std::chrono::high_resolution_clock::time_point stop_time_point;
};

