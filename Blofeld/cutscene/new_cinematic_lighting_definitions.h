#pragma once

namespace blofeld
{

	constexpr unsigned long NEW_CINEMATIC_LIGHTING_TAG = 'nclt';

	extern s_tag_group new_cinematic_lighting_group;

	extern s_tag_struct_definition cinematic_dynamic_light_block_block_struct;
	extern s_tag_block_definition cinematic_dynamic_light_block_block;
	extern s_tag_block_definition new_cinematic_lighting_block_block;


	extern s_tag_struct_definition new_cinematic_lighting_struct_definition_struct_definition; // tag group

	extern const char* cinematic_dynamic_light_flags_strings[];
	extern s_string_list_definition cinematic_dynamic_light_flags;

} // namespace blofeld

