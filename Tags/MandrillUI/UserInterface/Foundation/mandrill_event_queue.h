#pragma once

class c_mandrill_event
{
public:
	virtual void run() = 0;
};

class c_mandrill_event_queue
{
protected:
	void run_events();
	void enqueue(c_mandrill_event* event);
	void enqueue(std::function<void(void)> event);

	c_thread_safe_queue<c_mandrill_event*> thread_safe_queue;
};

