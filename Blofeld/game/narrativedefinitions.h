#pragma once

namespace blofeld
{

	extern const char* NarrativeFlagTypeEnum_strings[];
	extern s_string_list_definition NarrativeFlagTypeEnum;

	constexpr unsigned long NARRATIVEGLOBALS_TAG = 'narg';

	extern s_tag_group NarrativeGlobals_group;

	extern s_tag_block_definition NarrativeGlobals_block_block;
	extern s_tag_struct NarrativeFlagDefinitionBlock_block_struct;
	extern s_tag_block_definition NarrativeFlagDefinitionBlock_block;

	extern s_tag_struct NarrativeGlobals_struct_definition_struct_definition; // tag group

} // namespace blofeld

