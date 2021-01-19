#pragma once

namespace blofeld
{

namespace macaque
{

	constexpr unsigned long PLAYER_ENLISTMENT_GLOBALS_DEFINITION_TAG = 'pegd';
	extern s_tag_group player_enlistment_globals_definition_group; // player_enlistment_globals_definition_block


	extern s_tag_block_definition player_enlistment_globals_definition_block;
	extern s_tag_block_definition playerEnlistmentDefinitionBlock_block;
	extern s_tag_struct_definition playerEnlistmentDefinitionBlock_block_struct_definition; // playerEnlistmentDefinitionBlock_block

	extern s_tag_struct_definition player_enlistment_globals_definition_struct_definition; // tag group

	extern c_versioned_string_list playerEnlistmentFlags_strings;
	extern s_string_list_definition playerEnlistmentFlags;

} // namespace macaque

} // namespace blofeld

