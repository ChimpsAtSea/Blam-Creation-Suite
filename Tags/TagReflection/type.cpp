#include "tagreflection-private-pch.h"

h_type::h_type(h_type* parent) :
	parent(parent),
	notification_listeners(nullptr)
{

}

h_type::~h_type()
{
	s_notification_listener* notification_listener = notification_listeners;
	while (notification_listener)
	{
		s_notification_listener* next_notification_listener = notification_listener->next;
		delete notification_listener;
		notification_listener = next_notification_listener;
	}
}

void h_type::_set_parent(h_type* _parent)
{
	parent = _parent;
}

void h_type::add_notification_listener(s_notification_listener_func callback, void* userdata)
{
	s_notification_listener** notification_listener = &notification_listeners;
	while (*notification_listener)
	{
		notification_listener = &(*notification_listener)->next;
	}

	*notification_listener = new() s_notification_listener{};
	(*notification_listener)->callback = callback;
	(*notification_listener)->userdata = userdata;
	(*notification_listener)->next = nullptr;
}

void h_type::remove_notification_listener(s_notification_listener_func callback, void* userdata)
{
	s_notification_listener** notification_listener = &notification_listeners;
	while (*notification_listener)
	{
		if ((*notification_listener)->callback == callback && (*notification_listener)->userdata == userdata)
		{
			s_notification_listener* removed_notification_listener = *notification_listener;
			(*notification_listener) = removed_notification_listener->next;
			delete removed_notification_listener;
		}
		else
		{
			notification_listener = &(*notification_listener)->next;
		}
	}
}

void h_type::notify_data_change(const c_data_change_notification& notification)
{
#if 0
	// #TODO: #INVESTIGATE: benchmark how much of an impact that this functionality has

	/*
	This could use a while loop instead of a recursive function call like so
	*/

	/*
	Could add recursive support for c_data_change_notification by using alloca???
	*/

	h_type* current_type = this;
	do
	{
		for (s_notification_listener* notification_listener = current_type->notification_listeners; notification_listener != nullptr; notification_listener = notification_listener->next)
		{
			notification_listener->callback(notification_listener->userdata, notification);
		}
	} while (current_type = current_type->parent);

#else

	for (s_notification_listener* notification_listener = notification_listeners; notification_listener != nullptr; notification_listener = notification_listener->next)
	{
		notification_listener->callback(notification_listener->userdata, notification);
	}
	if (parent != nullptr)
	{
		parent->notify_data_change(notification);
	}

#endif
}
