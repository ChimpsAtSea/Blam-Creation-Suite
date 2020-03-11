#pragma once

#include <cseries/cseries.h>
#include <tag_files/tag_groups.h>
#include <haloreach/motor/mover.h>

/* ---------- types */

enum e_object_type
{
	_object_type_biped,
	_object_type_vehicle,
	_object_type_weapon,
	_object_type_equipment,
	_object_type_terminal,
	_object_type_projectile,
	_object_type_scenery,
	_object_type_machine,
	_object_type_control,
	_object_type_sound_scenery,
	_object_type_crate,
	_object_type_creature,
	_object_type_giant,
	_object_type_effect_scenery,
	k_number_of_object_types
};

struct s_object_placement_data
{
	// TODO
};

struct s_object_type_definition
{
	const char *name;
	tag group_tag;
	unsigned short datum_size;
	unsigned short placement_block_offset;
	unsigned short palette_block_offset;
	unsigned short placement_block_size;
	unsigned short flags;
	short : 16;
	long : 32;
	long : 32;
	c_mover_definition_data *mover_definition;
	void(*initialize)();
	void(*dispose)();
	void(*initialize_for_new_map)();
	void(*dispose_from_old_map)();
	void(*initialize_for_new_structure_bsp)(short structure_bsp_index);
	void(*dispose_from_old_structure_bsp)(short structure_bsp_index);
	void(*adjust_placement)(s_object_placement_data *placement);

	// TODO
};

/* ---------- globals */

extern s_enum_definition g_object_type_enum;
