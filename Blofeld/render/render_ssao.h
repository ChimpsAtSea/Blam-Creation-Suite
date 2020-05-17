#pragma once

namespace blofeld
{

	constexpr unsigned long SSAO_DEFINITION_TAG = 'ssao';

	extern s_tag_group ssao_definition_group;

	extern s_tag_block_definition ssao_definition_block_block;


	extern s_tag_struct_definition ssao_definition_struct_definition_struct_definition; // tag group

	extern const char* ssao_downsample_enum_definition_strings[];
	extern s_string_list_definition ssao_downsample_enum_definition;
	extern const char* ssao_type_enum_definition_strings[];
	extern s_string_list_definition ssao_type_enum_definition;

} // namespace blofeld

