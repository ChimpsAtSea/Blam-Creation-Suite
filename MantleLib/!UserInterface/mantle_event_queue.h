#pragma once

class c_mantle_event
{
public:
	virtual void run() = 0;
};

class c_mantle_event_queue
{
protected:
	void run_events();
	void enqueue(c_mantle_event* event);
	void enqueue(std::function<void(void)> event);

	ThreadSafeQueue<c_mantle_event*> thread_safe_queue;
};

