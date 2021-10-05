#pragma once

namespace blofeld
{



	constexpr unsigned long NARRATIVEGLOBALS_TAG = 'narg';
	extern s_tag_group NarrativeGlobals_group; // NarrativeGlobals_block


	extern s_tag_block_definition NarrativeGlobals_block;
	extern s_tag_block_definition NarrativeFlagDefinitionBlock_block;
	extern s_tag_struct_definition NarrativeFlagDefinitionBlock_block_struct_definition; // NarrativeFlagDefinitionBlock_block

	extern s_tag_struct_definition NarrativeGlobals_struct_definition; // tag group

	extern s_string_list_definition NarrativeFlagTypeEnum;

	extern s_tag_reference_definition NarrativeGlobalsReference;



} // namespace blofeld

