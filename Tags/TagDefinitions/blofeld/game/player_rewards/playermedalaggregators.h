#pragma once

namespace blofeld
{

	constexpr unsigned long MEDAL_CHALLENGE_AGGREGATOR_LIST_TAG = 'mech';

	extern s_tag_group medal_challenge_aggregator_list_group;
	constexpr unsigned long MEDAL_COMMENDATION_AGGREGATOR_LIST_TAG = 'meco';

	extern s_tag_group medal_commendation_aggregator_list_group;

	extern s_tag_struct_definition medalAggregatorEntry_block_struct;
	extern s_tag_block_definition medalAggregatorEntry_block;
	extern s_tag_struct_definition medalChallengeAggregator_block_struct;
	extern s_tag_block_definition medalChallengeAggregator_block;
	extern s_tag_block_definition medal_challenge_aggregator_list_block_block;
	extern s_tag_struct_definition medalCommendationAggregator_block_struct;
	extern s_tag_block_definition medalCommendationAggregator_block;
	extern s_tag_block_definition medal_commendation_aggregator_list_block_block;

	extern s_tag_struct_definition medal_challenge_aggregator_list_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition medalAggregator_struct_definition;
	extern s_tag_struct_definition medal_commendation_aggregator_list_struct_definition_struct_definition; // tag group

} // namespace blofeld

