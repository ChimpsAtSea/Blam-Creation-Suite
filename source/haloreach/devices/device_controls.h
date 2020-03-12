#pragma once

#include <cseries/cseries.h>
#include <tag_files/tag_groups.h>
#include <haloreach/devices/devices.h>
#include <haloreach/objects/scenery.h>

/* ---------- constants */

constexpr tag k_control_group_tag = 'ctrl';

/* ---------- types */

enum e_control_type
{
	_control_type_toggle,
	_control_type_on,
	_control_type_off,
	_control_type_call,
	_control_type_generator,
	k_number_of_control_types
};

enum e_control_trigger
{
	_control_triggers_when_touched_by_player,
	_control_triggers_when_destroyed,
	k_number_of_control_triggers
};

struct s_control_definition : s_device_definition
{
	c_enum<e_control_type, short> control_type;
	c_enum<e_control_trigger, short> triggers_when;
	real call_value;
	string_id action_string;
	s_tag_reference on;
	s_tag_reference off;
	s_tag_reference deny;
};
static_assert(sizeof(s_control_definition) == sizeof(s_device_definition) + 0x3C);

/* ---------- globals */

extern s_tag_group g_control_group;
