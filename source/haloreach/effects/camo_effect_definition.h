#pragma once

#include <cseries/cseries.h>
#include <datatypes/flags.h>
#include <math/real_math.h>
#include <memory/data.h>
#include <tag_files/string_ids.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_camo_effect_group_tag = 'cmoe';

/* ---------- types */

struct s_camo_function_state
{
	c_datum_handle object_handle;
	real input_scalar;
	real range_scalar;
};
static_assert(sizeof(s_camo_function_state) == 0xC);

struct s_camo_function
{
	string_id input_variable;
	string_id range_variable;
	s_tag_function mapping;
};
static_assert(sizeof(s_camo_function) == 0x1C);

enum e_camo_effect_definition_flags
{
	_camo_effect_apply_to_object_children_bit,
	k_number_of_camo_effect_definition_flags
};

struct s_camo_effect_definition
{
	c_flags<e_camo_effect_definition_flags, word, k_number_of_camo_effect_definition_flags> flags;
	
	short : 16;

	s_camo_function active_camo_amount;
	s_camo_function shadow_amount;
};
static_assert(sizeof(s_camo_effect_definition) == 0x3C);
