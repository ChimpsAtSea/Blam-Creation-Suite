#pragma once

namespace blofeld
{



	constexpr unsigned long EFFECT_TAG = 'effe';
	extern s_tag_group effect_group; // effect_block
	extern s_tag_block_definition effect_block;
	extern s_tag_struct_definition effect_block_struct_definition; // effect_block


	extern s_tag_block_definition effect_locations_block;
	extern s_tag_struct_definition effect_locations_block_struct_definition; // effect_locations_block
	extern s_tag_block_definition effect_event_block;
	extern s_tag_struct_definition effect_event_block_struct_definition; // effect_event_block
	extern s_tag_block_definition effect_part_block;
	extern s_tag_struct_definition effect_part_block_struct_definition; // effect_part_block
	extern s_tag_block_definition effect_accelerations_block;
	extern s_tag_struct_definition effect_accelerations_block_struct_definition; // effect_accelerations_block
	extern s_tag_block_definition effect_looping_sound_block;
	extern s_tag_struct_definition effect_looping_sound_block_struct_definition; // effect_looping_sound_block
	extern s_tag_block_definition effect_conical_distribution_block;
	extern s_tag_struct_definition effect_conical_distribution_block_struct_definition; // effect_conical_distribution_block


	extern c_versioned_string_list effect_dispositions_strings;
	extern s_string_list_definition effect_dispositions;
	extern c_versioned_string_list effect_environments_strings;
	extern s_string_list_definition effect_environments;
	extern c_versioned_string_list effect_camera_modes_strings;
	extern s_string_list_definition effect_camera_modes;
	extern c_versioned_string_list effect_location_flags_strings;
	extern s_string_list_definition effect_location_flags;
	extern c_versioned_string_list effect_part_scaleable_values_strings;
	extern s_string_list_definition effect_part_scaleable_values;
	extern c_versioned_string_list effect_part_flags_strings;
	extern s_string_list_definition effect_part_flags;
	extern c_versioned_string_list effectPartGameModeDefinition_strings;
	extern s_string_list_definition effectPartGameModeDefinition;
	extern c_versioned_string_list event_flags_strings;
	extern s_string_list_definition event_flags;
	extern c_versioned_string_list effect_flags_strings;
	extern s_string_list_definition effect_flags;

	extern s_tag_reference_definition global_effect_reference;
	extern s_tag_reference_definition globalEffectReferenceNonResourceDependency;



} // namespace blofeld

