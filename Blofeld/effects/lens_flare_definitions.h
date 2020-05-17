#pragma once

namespace blofeld
{

	extern const char* lens_flare_reflection_flags_definition_strings[];
	extern s_string_list_definition lens_flare_reflection_flags_definition;
	extern const char* lens_flare_flags_definition_strings[];
	extern s_string_list_definition lens_flare_flags_definition;
	extern const char* lens_flare_occlusion_offset_enum_definition_strings[];
	extern s_string_list_definition lens_flare_occlusion_offset_enum_definition;
	extern const char* lens_flare_corona_rotation_function_enum_definition_strings[];
	extern s_string_list_definition lens_flare_corona_rotation_function_enum_definition;
	extern const char* output_mod_enum_strings[];
	extern s_string_list_definition output_mod_enum;
	extern const char* lens_flare_animation_flags_definition_strings[];
	extern s_string_list_definition lens_flare_animation_flags_definition;

	constexpr unsigned long LENS_FLARE_TAG = 'lens';

	extern s_tag_group lens_flare_group;

	extern s_tag_block_definition lens_flare_block_block;
	extern s_tag_struct lens_flare_reflection_block_block_struct;
	extern s_tag_block_definition lens_flare_reflection_block_block;
	extern s_tag_struct lens_flare_scalar_animation_block_block_struct;
	extern s_tag_block_definition lens_flare_scalar_animation_block_block;
	extern s_tag_struct lens_flare_color_animation_block_block_struct;
	extern s_tag_block_definition lens_flare_color_animation_block_block;

	extern s_tag_struct lens_flare_struct_definition_struct_definition; // tag group
	extern s_tag_struct lens_flare_color_function_struct_struct_definition;

} // namespace blofeld

