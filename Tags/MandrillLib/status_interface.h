#pragma once

enum e_status_interface_priority
{
	_status_interface_priority_high,
	_status_interface_priority_medium,
	_status_interface_priority_low,
};

class c_status_interface
{
public:
	virtual const char* get_status_bar_text() = 0;
	virtual void set_status_bar_status(e_status_interface_priority priority, float time, const char* status, ...) = 0;
	virtual void wait_status_bar_idle() = 0;
};
