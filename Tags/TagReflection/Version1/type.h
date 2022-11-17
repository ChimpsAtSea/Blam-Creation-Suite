#pragma once

class h_type :
	public t_virtual
{
public:
	BCS_SHARED h_type(h_type* parent = nullptr);
	BCS_SHARED virtual ~h_type();

	void add_notification_listener(s_notification_listener_func callback, void* userdata);
	void remove_notification_listener(s_notification_listener_func callback, void* userdata);
	void notify_data_change(const c_data_change_notification& notification);

#ifndef __INTELLISENSE__
	/*
#TODO: I don't think this should be exposed.
Makes more sense if parent is const for the
lifetime of the type and we use move/assignment
on all types to track changes

This has to be exposed currently because h_typed_array has no way
to specify a default value and this has to be called on all elements
*/
	void _set_parent(h_type* parent);
#endif

protected:
	h_type(h_type const&) = default;

	h_type* parent;
	s_notification_listener* notification_listeners;
};
