#pragma once

namespace blofeld
{

	extern const char* light_volume_state_input_enum_strings[];
	extern s_string_list_definition light_volume_state_input_enum;
	extern const char* output_mod_enum$2_strings[];
	extern s_string_list_definition output_mod_enum$2;
	extern const char* light_volume_appearance_flags_strings[];
	extern s_string_list_definition light_volume_appearance_flags;
	extern const char* light_volume_flags_strings[];
	extern s_string_list_definition light_volume_flags;

	constexpr unsigned long LIGHT_VOLUME_SYSTEM_TAG = 'ltvl';

	extern s_tag_group light_volume_system_group;

	extern s_tag_block_definition light_volume_system_block_block;
	extern s_tag_struct light_volume_definition_block_block_struct;
	extern s_tag_block_definition light_volume_definition_block_block;
	extern s_tag_struct light_volume_precompiled_vert_block_block_struct;
	extern s_tag_block_definition light_volume_precompiled_vert_block_block;

	extern s_tag_struct light_volume_system_struct_definition_struct_definition; // tag group
	extern s_tag_struct light_volume_property_real_struct_definition;
	extern s_tag_struct light_volume_property_real_rgb_color_struct_definition;

} // namespace blofeld

