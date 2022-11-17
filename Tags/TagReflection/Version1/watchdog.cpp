#include "tagreflection-private-pch.h"

void* h_notification_system::stack[h_notification_system::stack_size] = {};
int32_t h_notification_system::index = 0;

void h_notification_system::push_value(void* userdata)
{
	index++;
	ASSERT(index < stack_size);
	stack[index] = userdata;
}

void h_notification_system::pop_value()
{
	index--;
	ASSERT(index >= 0);
}

void* h_notification_system::get_value()
{
	return stack[index];
}

c_data_change_notification::c_data_change_notification() :
	c_data_change_notification(h_notification_system::get_value())
{

}

c_data_change_notification::c_data_change_notification(void* userdata) :
	type(nullptr),
	field(nullptr),
	userdata(userdata)
{

}
