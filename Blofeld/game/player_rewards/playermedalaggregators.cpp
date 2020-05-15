#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(medalChallengeAggregator, MedalChallengeAggregator::k_medalChallengeAggregatorMaxCount)
{
	{ _field_string_id, "challenge to increment^" },
	{ _field_struct, "medals" },
	{ _field_terminator },
};

TAG_BLOCK(medalCommendationAggregator, MedalCommendationAggregator::k_medalCommendationAggregatorMaxCount)
{
	{ _field_string_id, "commendation to award^" },
	{ _field_struct, "medals" },
	{ _field_terminator },
};

TAG_GROUP(medal_challenge_aggregator_list, MEDAL_CHALLENGE_AGGREGATOR_LIST_TAG)
{
	{ _field_block, "lists", &medalChallengeAggregator_block },
	{ _field_terminator },
};

TAG_GROUP(medal_commendation_aggregator_list, MEDAL_COMMENDATION_AGGREGATOR_LIST_TAG)
{
	{ _field_block, "lists", &medalCommendationAggregator_block },
	{ _field_terminator },
};

} // namespace blofeld

