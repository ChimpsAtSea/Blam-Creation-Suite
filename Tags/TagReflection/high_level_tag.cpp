#include "tagreflection-private-pch.h"

h_tag::h_tag(h_group* group, const char* tag_filepath) :
	h_object(nullptr),
	tag_filepath(),
	tag_filename(),
	group(group)
{
	if (group != nullptr)
	{
		DEBUG_ASSERT(tag_filepath != nullptr);
		this->tag_filepath = tag_filepath;
		const char* tag_filename = filesystem_extract_filepath_filename(tag_filepath);
		this->tag_filename = tag_filename;
	}
}

h_tag::h_tag(h_type* parent) :
	h_object(parent),
	tag_filepath(),
	tag_filename(),
	group(nullptr)
{
}

h_tag::~h_tag()
{

}

h_object::h_object(h_type* parent) :
	h_type(parent)
{

}

h_object::~h_object()
{

}

h_group::h_group(s_engine_platform_build engine_platform_build, const blofeld::s_tag_group& tag_group) :
	tags(),
	engine_platform_build(engine_platform_build),
	tag_group(tag_group)
{

}

h_group::~h_group()
{

}

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

h_block::h_block(h_type* parent) :
	h_enumerable(parent)
{

}

h_enumerable::h_enumerable(h_type* parent) :
	h_type(parent)
{

}

h_resource::h_resource(h_type* parent) :
	h_type(parent),
	object(nullptr)
{

}

h_resource::~h_resource()
{

}

h_interop::h_interop() :
	h_type(nullptr)
{

}

h_interop::~h_interop()
{

}
