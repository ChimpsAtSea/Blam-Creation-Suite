#pragma once

class h_type;

namespace blofeld
{
	struct s_tag_field;
}

class h_notification_system
{
private:
	h_notification_system() = delete;
	h_notification_system(h_notification_system const&) = delete;

	static constexpr int32_t stack_size = 1024;
	static void* stack[stack_size];
	static int32_t index;

public:
	static void push_value(void* userdata);
	static void pop_value();
	static void* get_value();
};

class c_data_change_notification
{
public:
	c_data_change_notification();
	c_data_change_notification(void* userdata);

	h_type* type;
	blofeld::s_tag_field const* field;
	void* userdata;
};

using s_notification_listener_func = void (*)(void* userdata, const c_data_change_notification& notification);

struct s_notification_listener
{
	s_notification_listener_func callback;
	void* userdata;
	s_notification_listener* next;
};
