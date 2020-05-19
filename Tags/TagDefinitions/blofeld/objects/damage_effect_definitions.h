#pragma once

namespace blofeld
{

	constexpr unsigned long DAMAGE_EFFECT_TAG = 'jpt!';

	extern s_tag_group damage_effect_group;

	extern s_tag_struct_definition custom_damage_response_label_block_block_struct;
	extern s_tag_block_definition custom_damage_response_label_block_block;
	extern s_tag_struct_definition damage_effect_sound_block_block_struct;
	extern s_tag_block_definition damage_effect_sound_block_block;
	extern s_tag_block_definition damage_effect_block_block;

	extern s_tag_struct_definition damage_effect_group_struct_definition; // tag group
	extern s_tag_struct_definition damage_outer_cone_angle_struct_struct_definition;

	extern const char* damage_side_effects_strings[];
	extern s_string_list_definition damage_side_effects;
	extern const char* damage_categories_strings[];
	extern s_string_list_definition damage_categories;
	extern const char* damage_death_vocalizations_strings[];
	extern s_string_list_definition damage_death_vocalizations;
	extern const char* damage_flags_strings[];
	extern s_string_list_definition damage_flags;
	extern const char* damageSecondaryFlags_strings[];
	extern s_string_list_definition damageSecondaryFlags;
	extern const char* damage_effect_sound_type_flags_strings[];
	extern s_string_list_definition damage_effect_sound_type_flags;
	extern const char* damage_effect_flags_strings[];
	extern s_string_list_definition damage_effect_flags;

	extern s_tag_reference_definition global_damage_reference;

} // namespace blofeld

