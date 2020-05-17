#pragma once

namespace blofeld
{

	extern const char* vocalization_stimulus_flags_strings[];
	extern s_string_list_definition vocalization_stimulus_flags;
	extern const char* dialogue_flags_strings[];
	extern s_string_list_definition dialogue_flags;

	constexpr unsigned long DIALOGUE_TAG = 'udlg';

	extern s_tag_struct dialogue_block_struct;
	extern s_tag_block_definition dialogue_block;
	extern s_tag_group dialogue_group;

	extern s_tag_struct sound_references_block_block_struct;
	extern s_tag_block_definition sound_references_block_block;
	extern s_tag_struct vocalization_stimuli_block_definition_block_struct;
	extern s_tag_block_definition vocalization_stimuli_block_definition_block;


} // namespace blofeld

