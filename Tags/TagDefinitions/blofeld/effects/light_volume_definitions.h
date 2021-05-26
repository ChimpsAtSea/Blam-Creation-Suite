#pragma once

namespace blofeld
{



	constexpr unsigned long LIGHT_VOLUME_SYSTEM_TAG = 'ltvl';
	extern s_tag_group light_volume_system_group; // light_volume_system_block


	extern s_tag_block_definition light_volume_system_block;
	extern s_tag_block_definition light_volume_definition_block;
	extern s_tag_struct_definition light_volume_definition_block_struct_definition; // light_volume_definition_block
	extern s_tag_block_definition light_volume_precompiled_vert_block;
	extern s_tag_struct_definition light_volume_precompiled_vert_block_struct_definition; // light_volume_precompiled_vert_block

	extern s_tag_struct_definition light_volume_system_struct_definition; // tag group
	extern s_tag_struct_definition light_volume_property_real;
	extern s_tag_struct_definition light_volume_property_real_rgb_color;

	extern c_versioned_string_list light_volume_state_input_enum_strings;
	extern s_string_list_definition light_volume_state_input_enum;
	extern c_versioned_string_list output_mod_enum$2_strings;
	extern s_string_list_definition output_mod_enum$2;
	extern c_versioned_string_list light_volume_appearance_flags_strings;
	extern s_string_list_definition light_volume_appearance_flags;
	extern c_versioned_string_list light_volume_flags_strings;
	extern s_string_list_definition light_volume_flags;



} // namespace blofeld

