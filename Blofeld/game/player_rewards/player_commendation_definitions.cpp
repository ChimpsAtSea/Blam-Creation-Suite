#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(commendationAggregator, CommendationAggregator::k_commendationAggregatorMaxCount)
{
	{ _field_string_id, "name^" },
	{ _field_string_id, "description text" },
	{ _field_block, "rewards", &commendationRewardBlock_block },
	{ _field_char_integer, "sequence index" },
	{ _field_pad, "CA_PAD1", 3 },
	{ _field_short_integer, "medal sprite index" },
	{ _field_short_integer, "game type sprite index" },
	{ _field_block, "prerequisites{contributing commendations}", &commendationAggregatorDependent_block },
	{ _field_terminator },
};

TAG_BLOCK(commendationRewardBlock, eCT_count)
{
	{ _field_char_enum, "currency type#Type of currency given by this reward." },
	{ _field_pad, "CRB_PAD1", 1 },
	{ _field_short_integer, "reward value" },
	{ _field_terminator },
};

TAG_BLOCK(commendationAggregatorDependent, CommendationAggregatorDependent::k_commendationDependentMaxCount)
{
	{ _field_char_enum, "type" },
	{ _field_pad, "PAD1", 3 },
	{ _field_string_id, "name^" },
	{ _field_terminator },
};

TAG_BLOCK(commendationBlock, CommendationDefinition::k_maximumCommendationDefinitions)
{
	{ _field_string_id, "name^" },
	{ _field_string_id, "description" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "CB_PAD0", 3 },
	{ _field_char_enum, "category" },
	{ _field_char_enum, "subcategory" },
	{ _field_char_integer, "sequence index" },
	{ _field_pad, "CB_PAD1", 1 },
	{ _field_short_integer, "medal sprite index" },
	{ _field_short_integer, "game type sprite index" },
	{ _field_custom, "unlock prerequisites" },
	{ _field_struct, "prerequisites" },
	{ _field_custom },
	{ _field_block, "levels", &commendationLevelBlock_block },
	{ _field_terminator },
};

TAG_BLOCK(commendationLevelBlock, CommendationLevel::k_maximumCommendationLevels)
{
	{ _field_string_id, "level name^" },
	{ _field_short_integer, "progress ticks to level#number of ticks to reach this level" },
	{ _field_short_integer, "progress display interval#number of ticks between displaying progress toast; 0=never display progress, 1=display every tick, 2=every other, etc." },
	{ _field_string_id, "achievement" },
	{ _field_block, "level up rewards#rewards given for reaching this level", &commendationRewardBlock_block },
	{ _field_terminator },
};

TAG_GROUP(commendation_aggregator_list, COMMENDATION_AGGREGATOR_LIST_TAG)
{
	{ _field_block, "lists", &commendationAggregator_block },
	{ _field_terminator },
};

TAG_GROUP(commendation_globals_definition, COMMENDATION_GLOBALS_DEFINITION_TAG)
{
	{ _field_tag_reference, "commendation aggregators" },
	{ _field_tag_reference, "medal aggregators" },
	{ _field_tag_reference, "commendation text" },
	{ _field_short_integer, "progress display time{progression display time}:seconds" },
	{ _field_short_integer, "complete display time{callout display time}:seconds" },
	{ _field_block, "commendations", &commendationBlock_block },
	{ _field_terminator },
};

} // namespace blofeld

