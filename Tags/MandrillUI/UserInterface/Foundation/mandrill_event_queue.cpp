#include "mandrillui-private-pch.h"

class c_mandrill_lambda_event :
	public c_mandrill_event
{
public:
	c_mandrill_lambda_event(std::function<void(void)> event) :
		c_mandrill_event(),
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

void c_mandrill_event_queue::run_events()
{
	c_mandrill_event* event = nullptr;
	while (thread_safe_queue.Dequeue(event))
	{
		event->run();
		delete event;
	}
}

void c_mandrill_event_queue::enqueue(c_mandrill_event* event)
{
	thread_safe_queue.Enqueue(event);
}

void c_mandrill_event_queue::enqueue(std::function<void(void)> event)
{
	thread_safe_queue.Enqueue(new c_mandrill_lambda_event(event));
}
