#pragma once

extern BCSAPI volatile uint32_t g_debug_point_value;

#define debug_point (void)(g_debug_point_value++)

enum e_debug_log_mode
{
	_debug_log_mode_nothing,
	_debug_log_mode_verbose,
	_debug_log_mode_everything,
};
extern e_debug_log_mode g_debug_log_mode;

void write_stack_back_trace(LPCWSTR calling_function, DWORD depth = 0, DWORD size = 1024);

class c_stopwatch
{
public:
	c_stopwatch();
	void start();
	void stop();
	float get_seconds();
	float get_miliseconds();

private:
	std::chrono::high_resolution_clock::time_point time_point_start;
	std::chrono::high_resolution_clock::time_point time_point_stop;
	std::chrono::high_resolution_clock::duration _duration;
};

class c_task_timer
{
public:
	c_task_timer(const char* task_name);
	~c_task_timer();

protected:
	c_stopwatch stopwatch;
	char task_name[128];
};

#ifdef __INTELLISENSE__
#define TASK_TIMER(name)
#else
#define TASK_TIMER(name) c_task_timer CONCAT(__task_timer, __LINE__) (name)
#endif
