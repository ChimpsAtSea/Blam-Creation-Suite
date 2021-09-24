#pragma once

namespace blofeld
{



	constexpr unsigned long SSAO_DEFINITION_TAG = 'ssao';
	extern s_tag_group ssao_definition_group; // ssao_definition_block


	extern s_tag_block_definition ssao_definition_block;

	extern s_tag_struct_definition ssao_definition_struct_definition; // tag group

	extern s_string_list_definition ssao_downsample_enum_definition;
	extern s_string_list_definition ssao_type_enum_definition;

	extern s_tag_reference_definition global_ssao_definition_reference;



} // namespace blofeld

