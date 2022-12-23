#pragma once

class c_graphics;

class c_graphics_event
{
public:
	BCS_SHARED c_graphics_event(c_graphics& graphics, const char* event_name);
	c_graphics_event(c_graphics_event const&) = delete;
	BCS_SHARED ~c_graphics_event();

protected:
	c_graphics& graphics;
};

class c_graphics_event_ex
{
public:
	BCS_SHARED c_graphics_event_ex(c_graphics& graphics, const char* event_name_format, ...);
	c_graphics_event_ex(c_graphics_event const&) = delete;
	BCS_SHARED ~c_graphics_event_ex();

protected:
	c_graphics& graphics;
};

#define GRAPHICS_EVENT(graphics, event_name) c_graphics_event __graphics_event_##__LINE__((graphics), event_name)
#define GRAPHICS_EVENT_EX(graphics, event_name_format, ...) c_graphics_event_ex __graphics_event_ex_##__LINE__((graphics), event_name_format, __VA_ARGS__)
