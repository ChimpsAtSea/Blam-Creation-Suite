#pragma once

namespace blofeld
{



	constexpr unsigned long DAMAGE_EFFECT_TAG = 'jpt!';
	extern s_tag_group damage_effect_group; // damage_effect_block


	extern s_tag_block_definition damage_effect_block;
	extern s_tag_block_definition custom_damage_response_label_block;
	extern s_tag_struct_definition custom_damage_response_label_block_struct_definition; // custom_damage_response_label_block
	extern s_tag_block_definition damage_effect_sound_block;
	extern s_tag_struct_definition damage_effect_sound_block_struct_definition; // damage_effect_sound_block

	extern s_tag_struct_definition damage_effect_struct_definition; // tag group
	extern s_tag_struct_definition damage_outer_cone_angle_struct;

	extern s_string_list_definition damage_side_effects;
	extern s_string_list_definition damage_categories;
	extern s_string_list_definition damage_death_vocalizations;
	extern s_string_list_definition damage_flags;
	extern s_string_list_definition damageSecondaryFlags;
	extern s_string_list_definition damage_effect_sound_type_flags;
	extern s_string_list_definition damage_effect_flags;

	extern s_tag_reference_definition global_damage_reference;



} // namespace blofeld

