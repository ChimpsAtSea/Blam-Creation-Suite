#include <cseries/events/event_handler.h>
#include <cseries/cseries_asserts.h>

/* ---------- globals */

c_event_handler *c_event_handler_hook::g_event_handler = nullptr;

/* ---------- public code */

void c_event_handler_hook::attach_handler(c_event_handler *handler)
{
	blamlib_assert(g_event_handler == nullptr);
	blamlib_assert(handler);

	g_event_handler = handler;
}

void c_event_handler_hook::detach_handler(c_event_handler *handler)
{
	blamlib_assert(g_event_handler == handler);

	g_event_handler = nullptr;
}

bool c_event_handler_hook::active()
{
	return g_event_handler != nullptr;
}

c_event_handler *c_event_handler_hook::get_handler()
{
	return g_event_handler;
}
