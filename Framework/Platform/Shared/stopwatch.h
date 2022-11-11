#pragma once

class c_stopwatch
{
public:
	BCS_SHARED c_stopwatch();
	BCS_SHARED void start();
	BCS_SHARED void stop();
	BCS_SHARED float get_seconds() const;
	BCS_SHARED float get_miliseconds() const;

private:
	int64_t time_point_start;
	int64_t time_point_stop;
};
