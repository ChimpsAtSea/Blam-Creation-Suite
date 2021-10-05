#pragma once

namespace blofeld
{



	constexpr unsigned long PLAYER_MODEL_CUSTOMIZATION_GLOBALS_TAG = 'pmcg';
	extern s_tag_group player_model_customization_globals_group; // player_model_customization_globals_block


	extern s_tag_block_definition player_model_customization_globals_block;
	extern s_tag_block_definition customized_model_selection_block;
	extern s_tag_struct_definition customized_model_selection_block_struct_definition; // customized_model_selection_block
	extern s_tag_block_definition customized_model_player_bits_block;
	extern s_tag_struct_definition customized_model_player_bits_block_struct_definition; // customized_model_player_bits_block

	extern s_tag_struct_definition player_model_customization_globals_struct_definition; // tag group

	extern s_string_list_definition model_customization_player_permutation_flags;

	extern s_tag_reference_definition global_player_model_customization_globals_reference;



} // namespace blofeld

