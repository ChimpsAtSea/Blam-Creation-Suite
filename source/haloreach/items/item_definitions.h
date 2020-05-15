#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>
#include <memory/static_arrays.h>
#include <haloreach/objects/object_definitions.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_item_group_tag = 'item';

constexpr int k_maximum_number_of_item_predicted_bitmaps = 8;

/* ---------- types */

enum e_item_definition_flags
{
    _item_always_maintains_z_up_bit,
    _item_blocks_headshots_bit,
    _item_use_ground_scale_for_all_unspecified_attachments_bit,
    _item_fixup_position_upon_detaching_from_parent_bit,
    _item_fixup_position_after_attaching_to_parent_bit,
    _item_item_considered_high_value_bit,
    _item_item_requires_a_child_to_be_a_pickup_item_bit,
	k_number_of_item_definition_flags
};

struct s_item_predicted_bitmap
{
	s_tag_reference bitmap;
};
static_assert(sizeof(s_item_predicted_bitmap) == 0x10);

struct s_item_definition : s_object_definition
{
	c_flags<e_item_definition_flags, long> item_flags;
	short old_message_index;
	short sort_order;
	real old_multiplayer_on_ground_scale;
	real old_campaign_on_ground_scale;
	string_id pickup_message;
	string_id swap_message;
	string_id pickup_or_dual_wield_message;
	string_id swap_or_dual_wield_message;
	string_id picked_up_message;
	string_id switch_to_message;
	string_id switch_to_from_ai_message;
	string_id notify_empty_message;
	string_id notify_overheated_message;
	s_tag_reference collision_sound;
	c_typed_tag_block<s_item_predicted_bitmap> predicted_bitmaps;
	s_tag_reference detonation_damage_effect;
	real_bounds detonation_delay;
	s_tag_reference detonating_effect;
	s_tag_reference detonation_effect;
	real ground_scale;
	real human_hold_scale;
	real human_holster_scale;
	real player_hold_scale;
	real player_holster_scale;
	real covenant_hold_scale;
	real covenant_holster_scale;
	real boss_hold_scale;
	real boss_holster_scale;
	s_tag_reference grounded_friction_settings;
};
static_assert(sizeof(s_item_definition) == sizeof(s_object_definition) + 0xBC);
