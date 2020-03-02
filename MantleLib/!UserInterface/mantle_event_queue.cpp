#include "mantlelib-private-pch.h"

class c_mantle_lambda_event :
	public c_mantle_event
{
public:
	c_mantle_lambda_event(std::function<void(void)> event) :
		c_mantle_event(),
		event(event)
	{
	}

	virtual void run() override
	{
		event();
	}

protected:
	std::function<void(void)> event;
};

void c_mantle_event_queue::run_events()
{
	c_mantle_event* event = nullptr;
	while (thread_safe_queue.Dequeue(event))
	{
		event->run();
		delete event;
	}
}

void c_mantle_event_queue::enqueue(c_mantle_event* event)
{
	thread_safe_queue.Enqueue(event);
}

void c_mantle_event_queue::enqueue(std::function<void(void)> event)
{
	thread_safe_queue.Enqueue(new c_mantle_lambda_event(event));
}
