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
		char* tag_filename = PathFindFileNameA(tag_filepath);
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

namespace blofeld
{
	namespace halo1
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
	}
	namespace stubbs
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
	}
	namespace halo2
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
	}
	namespace halo3
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
	}
	namespace halo3odst
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
	}
	namespace haloreach
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
	}
	namespace halo4
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
	}
	namespace groundhog
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
	}
	namespace xbox360_gen3
	{
		h_tag* create_high_level_tag(h_group& tag_group, const char* tag_filepath);
	}
}

h_tag& h_group::create_tag_instance(const char* filepath)
{
	h_tag* tag = nullptr;
	switch (engine_platform_build.engine_type)
	{
	case _engine_type_halo1:
		tag = blofeld::halo1::create_high_level_tag(*this, filepath);
		break;
	case _engine_type_stubbs:
		tag = blofeld::stubbs::create_high_level_tag(*this, filepath);
		break;
	case _engine_type_halo2:
		tag = blofeld::halo2::create_high_level_tag(*this, filepath);
		break;
	case _engine_type_halo3:			
		tag = blofeld::halo3::create_high_level_tag(*this, filepath);
		break;
	case _engine_type_halo3odst:		
		tag = blofeld::halo3odst::create_high_level_tag(*this, filepath);
		break;
	case _engine_type_haloreach:		
		tag = blofeld::haloreach::create_high_level_tag(*this, filepath);
		break;
	case _engine_type_halo4:			
		tag = blofeld::halo4::create_high_level_tag(*this, filepath);
		break;
	case _engine_type_groundhog:		
		tag = blofeld::groundhog::create_high_level_tag(*this, filepath);
		break;
	case _engine_type_gen3_xbox360:
		tag = blofeld::xbox360_gen3::create_high_level_tag(*this, filepath);
		break;
	default: FATAL_ERROR(L"Unsupported engine type");
	}

	ASSERT(tag != nullptr);

	tags.push_back(tag);

	return *tag;
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

	*notification_listener = new s_notification_listener{};
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
	h_type(parent)
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
