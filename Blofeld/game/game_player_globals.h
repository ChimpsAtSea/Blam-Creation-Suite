#pragma once

namespace blofeld
{

	extern const char* MomentumFlag_strings[];
	extern s_string_list_definition MomentumFlag;
	extern const char* player_representation_flags_strings[];
	extern s_string_list_definition player_representation_flags;
	extern const char* FpBodyRegionFlags_strings[];
	extern s_string_list_definition FpBodyRegionFlags;


	extern s_tag_struct player_information_block_block_struct;
	extern s_tag_block_definition player_information_block_block;
	extern s_tag_struct player_momentum_data_block_block_struct;
	extern s_tag_block_definition player_momentum_data_block_block;
	extern s_tag_struct player_representation_block_block_struct;
	extern s_tag_block_definition player_representation_block_block;
	extern s_tag_struct firstPersonpHiddenBodyRegionsBlock_block_struct;
	extern s_tag_block_definition firstPersonpHiddenBodyRegionsBlock_block;


} // namespace blofeld

