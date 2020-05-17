#pragma once

namespace blofeld
{

	constexpr unsigned long PLAYER_MODEL_CUSTOMIZATION_GLOBALS_TAG = 'pmcg';

	extern s_tag_group player_model_customization_globals_group;

	extern s_tag_struct_definition customized_model_player_bits_block_block_struct;
	extern s_tag_block_definition customized_model_player_bits_block_block;
	extern s_tag_struct_definition customized_model_selection_block_block_struct;
	extern s_tag_block_definition customized_model_selection_block_block;
	extern s_tag_block_definition player_model_customization_globals_block_block;


	extern s_tag_struct_definition player_model_customization_globals_struct_definition_struct_definition; // tag group

	extern const char* model_customization_player_permutation_flags_strings[];
	extern s_string_list_definition model_customization_player_permutation_flags;

} // namespace blofeld

