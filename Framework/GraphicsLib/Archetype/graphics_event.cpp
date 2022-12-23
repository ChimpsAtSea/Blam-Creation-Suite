#include "graphicslib-private-pch.h"

c_graphics_event::c_graphics_event(c_graphics& _graphics, const char* event_name) :
	graphics(_graphics)
{
	graphics.start_debug_event(event_name);
}

c_graphics_event::~c_graphics_event()
{
	graphics.end_debug_event();
}

c_graphics_event_ex::c_graphics_event_ex(c_graphics& _graphics, const char* event_name_format, ...) :
	graphics(_graphics)
{
	va_list virtual_argument_list;
	va_start(virtual_argument_list, event_name_format);
	graphics.start_debug_event_vargs(event_name_format, virtual_argument_list);
	va_end(virtual_argument_list);
}

c_graphics_event_ex::~c_graphics_event_ex()
{
	graphics.end_debug_event();
}
