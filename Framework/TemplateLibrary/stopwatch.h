#pragma once

class c_stopwatch
{
public:
	BCS_DEBUG_API c_stopwatch();
	BCS_DEBUG_API void start();
	BCS_DEBUG_API void stop();
	BCS_DEBUG_API float get_seconds() const;
	BCS_DEBUG_API float get_miliseconds() const;

private:
	long long time_point_start;
	long long time_point_stop;
};
