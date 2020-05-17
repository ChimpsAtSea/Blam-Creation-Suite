#pragma once

namespace blofeld
{

	extern const char* g_silentAssistFlags_strings[];
	extern s_string_list_definition g_silentAssistFlags;

	constexpr unsigned long SILENT_ASSIST_GLOBALS_TAG = 'slag';

	extern s_tag_group silent_assist_globals_group;

	extern s_tag_block_definition silent_assist_globals_block_block;
	extern s_tag_struct silentAssistLevelBlock_block_struct;
	extern s_tag_block_definition silentAssistLevelBlock_block;

	extern s_tag_struct silent_assist_globals_struct_definition_struct_definition; // tag group

} // namespace blofeld

