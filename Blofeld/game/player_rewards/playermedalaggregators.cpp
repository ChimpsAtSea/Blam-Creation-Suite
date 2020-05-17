#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(medal_challenge_aggregator_list, MEDAL_CHALLENGE_AGGREGATOR_LIST_TAG, medal_challenge_aggregator_list_block_block );

	TAG_GROUP_FROM_BLOCK(medal_commendation_aggregator_list, MEDAL_COMMENDATION_AGGREGATOR_LIST_TAG, medal_commendation_aggregator_list_block_block );

	TAG_BLOCK(medalAggregatorEntry, MedalAggregatorEntry::k_medalAggregatorEntryMaxCount)
	{
		FIELD( _field_string_id, "medal name^" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(medalChallengeAggregator, MedalChallengeAggregator::k_medalChallengeAggregatorMaxCount)
	{
		FIELD( _field_string_id, "challenge to increment^" ),
		FIELD( _field_struct, "medals", &medalAggregator_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(medal_challenge_aggregator_list_block, 1, medal_challenge_aggregator_list_struct_definition_struct_definition );

	TAG_BLOCK(medalCommendationAggregator, MedalCommendationAggregator::k_medalCommendationAggregatorMaxCount)
	{
		FIELD( _field_string_id, "commendation to award^" ),
		FIELD( _field_struct, "medals", &medalAggregator_struct_definition ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(medal_commendation_aggregator_list_block, 1, medal_commendation_aggregator_list_struct_definition_struct_definition );

	TAG_STRUCT(medal_challenge_aggregator_list_struct_definition)
	{
		FIELD( _field_block, "lists", &medalChallengeAggregator_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(medalAggregator)
	{
		FIELD( _field_string_id, "display name^" ),
		FIELD( _field_custom, "allowed game modes" ),
		FIELD( _field_struct, "allowed game modes", &game_mode_flags_struct_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_block, "contributing medals", &medalAggregatorEntry_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(medal_commendation_aggregator_list_struct_definition)
	{
		FIELD( _field_block, "lists", &medalCommendationAggregator_block ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

