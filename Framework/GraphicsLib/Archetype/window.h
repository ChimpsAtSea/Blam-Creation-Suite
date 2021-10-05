#pragma once

class c_window :
	public c_viewport
{
public:
	//c_window() = delete;
	c_window(const c_window&) = delete;
	c_window& operator=(const c_window&) = delete;
protected:
	c_window();
public:
	virtual ~c_window();
	virtual bool update() = 0;
};

BCS_DEBUG_API BCS_RESULT window_create(
	const char* window_title,
	const char* window_id,
	unsigned long width, 
	unsigned long height, 
	c_window*& window,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT window_destroy(c_window* window);
