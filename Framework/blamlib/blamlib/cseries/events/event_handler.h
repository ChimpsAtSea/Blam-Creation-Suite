#pragma once

/* ---------- classes */

class __declspec(novtable) c_event_handler
{
public:
	virtual bool handle_event() = 0;
};

class c_event_handler_hook final
{
public:
	c_event_handler_hook() = delete;

	static void attach_handler(c_event_handler *handler);
	static void detach_handler(c_event_handler *handler);

	static bool active();

	static c_event_handler *get_handler();

private:
	static c_event_handler *g_event_handler;
};
