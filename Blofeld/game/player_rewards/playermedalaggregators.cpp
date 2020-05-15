#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(medalChallengeAggregator, MedalChallengeAggregator::k_medalChallengeAggregatorMaxCount)
{
	FIELD( _field_string_id, "challenge to increment^" ),
	FIELD( _field_struct, "medals" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(medalCommendationAggregator, MedalCommendationAggregator::k_medalCommendationAggregatorMaxCount)
{
	FIELD( _field_string_id, "commendation to award^" ),
	FIELD( _field_struct, "medals" ),
	FIELD( _field_terminator )
};

TAG_GROUP(medal_challenge_aggregator_list, MEDAL_CHALLENGE_AGGREGATOR_LIST_TAG)
{
	FIELD( _field_block, "lists", &medalChallengeAggregator_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(medal_commendation_aggregator_list, MEDAL_COMMENDATION_AGGREGATOR_LIST_TAG)
{
	FIELD( _field_block, "lists", &medalCommendationAggregator_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

