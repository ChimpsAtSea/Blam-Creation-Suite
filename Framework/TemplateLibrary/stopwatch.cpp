#include "templatelibrary-private-pch.h"

c_stopwatch::c_stopwatch() :
	time_point_start(),
	time_point_stop()
{

}

void c_stopwatch::start()
{
	std::chrono::steady_clock::time_point now = std::chrono::high_resolution_clock::now();
	time_point_start = now.time_since_epoch().count();
}

void c_stopwatch::stop()
{
	std::chrono::steady_clock::time_point now = std::chrono::high_resolution_clock::now();
	time_point_stop = now.time_since_epoch().count();
}

float c_stopwatch::get_seconds() const
{
	long long duration = time_point_stop - time_point_start;
	double nanoseconds = static_cast<double>(duration);
	double seconds = nanoseconds / static_cast<double>(std::chrono::nanoseconds::period::den);
	return static_cast<float>(seconds);
}

float c_stopwatch::get_miliseconds() const
{
	long long duration = time_point_stop - time_point_start;
	double nanoseconds = static_cast<double>(duration);
	double miliseconds = nanoseconds / static_cast<double>(std::chrono::nanoseconds::period::den / std::chrono::milliseconds::period::den);
	return static_cast<float>(miliseconds);
}
