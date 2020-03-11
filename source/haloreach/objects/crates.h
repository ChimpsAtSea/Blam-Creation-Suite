#pragma once

#include <cseries/cseries.h>
#include <tag_files/tag_groups.h>
#include <haloreach/game/campaign_metagame.h>
#include <haloreach/objects/object_definitions.h>

/* ---------- constants */

enum
{
	k_crate_group_tag = 'bloc'
};

/* ---------- types */

enum e_crate_flags
{
	_crate_does_not_block_aoe_bit,
	_crate_attach_texture_camera_hack_bit,
	_crate_targetable_bit,
	_crate_walls_block_aoe_bit,
	_crate_blocks_damage_flash_damage_response_bit,
	_crate_blocks_rumble_damage_response_bit,
	_crate_takes_top_level_aoe_damage_bit,
	_crate_blocks_forced_projectile_overpenetration_bit,
	_crate_unimportant_bit,
	_crate_always_check_children_collision_bit,
	_crate_allow_friendly_team_to_pass_through_inside_bit,
	_crate_allow_ally_team_to_pass_through_inside_bit,
	_crate_allow_friendly_team_to_pass_through_outside_bit,
	_crate_allow_ally_team_to_pass_through_outside_bit,
	_crate_reject_all_contact_points_inside_bit,
	_crate_reject_all_contact_points_outside_bit,
	k_number_of_crate_flags
};

struct s_crate_definition : s_object_definition
{
	c_flags<e_crate_flags, word> crate_flags;
	short : 16;
	c_typed_tag_block<s_campaign_metagame_bucket> campaign_metagame_bucket;
	long self_destruction_timer;
};
static_assert(sizeof(s_crate_definition) == sizeof(s_object_definition) + 0x14);

/* ---------- globals */

extern s_tag_group g_crate_group;
