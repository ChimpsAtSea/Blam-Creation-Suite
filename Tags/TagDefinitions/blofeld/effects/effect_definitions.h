#pragma once

namespace blofeld
{

	constexpr unsigned long EFFECT_TAG = 'effe';

	extern s_tag_struct_definition effect_block_struct;
	extern s_tag_block_definition effect_block;
	extern s_tag_group effect_group;

	extern s_tag_struct_definition effect_locations_block_block_struct;
	extern s_tag_block_definition effect_locations_block_block;
	extern s_tag_struct_definition effect_part_block_block_struct;
	extern s_tag_block_definition effect_part_block_block;
	extern s_tag_struct_definition effect_accelerations_block_block_struct;
	extern s_tag_block_definition effect_accelerations_block_block;
	extern s_tag_struct_definition effect_event_block_block_struct;
	extern s_tag_block_definition effect_event_block_block;
	extern s_tag_struct_definition effect_looping_sound_block_block_struct;
	extern s_tag_block_definition effect_looping_sound_block_block;
	extern s_tag_struct_definition effect_conical_distribution_block_block_struct;
	extern s_tag_block_definition effect_conical_distribution_block_block;


	extern const char* effect_dispositions_strings[];
	extern s_string_list_definition effect_dispositions;
	extern const char* effect_environments_strings[];
	extern s_string_list_definition effect_environments;
	extern const char* effect_camera_modes_strings[];
	extern s_string_list_definition effect_camera_modes;
	extern const char* effect_location_flags_strings[];
	extern s_string_list_definition effect_location_flags;
	extern const char* effect_part_scaleable_values_strings[];
	extern s_string_list_definition effect_part_scaleable_values;
	extern const char* effect_part_flags_strings[];
	extern s_string_list_definition effect_part_flags;
	extern const char* effectPartGameModeDefinition_strings[];
	extern s_string_list_definition effectPartGameModeDefinition;
	extern const char* event_flags_strings[];
	extern s_string_list_definition event_flags;
	extern const char* effect_flags_strings[];
	extern s_string_list_definition effect_flags;

	extern s_tag_reference_definition global_effect_reference;
	extern s_tag_reference_definition globalEffectReferenceNonResourceDependency;

} // namespace blofeld

