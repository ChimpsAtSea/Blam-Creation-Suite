#pragma once

#include <cseries/cseries.h>
#include <memory/static_arrays.h>
#include <tag_files/tag_groups.h>

/* ---------- types */

enum e_ai_equipment_trait_appearance_active_camo_choices
{
	_ai_equipment_trait_appearance_active_camo_unchanged,
	_ai_equipment_trait_appearance_active_camo_off,
	_ai_equipment_trait_appearance_active_camo_poor,
	_ai_equipment_trait_appearance_active_camo_good,
	_ai_equipment_trait_appearance_active_camo_excellent,
	_ai_equipment_trait_appearance_active_camo_invisible,
	k_number_of_ai_equipment_trait_appearance_active_camo_choices
};

struct s_ai_equipment_trait_appearance
{
	c_enum<e_ai_equipment_trait_appearance_active_camo_choices, char> active_camo;
	char : 8;
	char : 8;
	char : 8;
};
static_assert(sizeof(s_ai_equipment_trait_appearance) == 0x4);

struct s_ai_equipment_traits
{
	c_typed_tag_block<s_ai_equipment_trait_appearance> appearance_traits;
};
static_assert(sizeof(s_ai_equipment_traits) == 0xC);
