#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(commendation_aggregator_list_struct_definition)
{
	FIELD( _field_block, "lists", &commendationAggregator ),
	FIELD( _field_terminator )
};

TAG_STRUCT(commendation_globals_definition_struct_definition)
{
	FIELD( _field_tag_reference, "commendation aggregators" ),
	FIELD( _field_tag_reference, "medal aggregators" ),
	FIELD( _field_tag_reference, "commendation text" ),
	FIELD( _field_short_integer, "progress display time{progression display time}:seconds" ),
	FIELD( _field_short_integer, "complete display time{callout display time}:seconds" ),
	FIELD( _field_block, "commendations", &commendationBlock ),
	FIELD( _field_terminator )
};

TAG_STRUCT(commendationAggregatorDependent_struct)
{
	FIELD( _field_char_enum, "type" ),
	FIELD( _field_pad, "PAD1", 3 ),
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(commendationAggregator, CommendationAggregator::k_commendationAggregatorMaxCount)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_string_id, "description text" ),
	FIELD( _field_block, "rewards", &commendationRewardBlock ),
	FIELD( _field_char_integer, "sequence index" ),
	FIELD( _field_pad, "CA_PAD1", 3 ),
	FIELD( _field_short_integer, "medal sprite index" ),
	FIELD( _field_short_integer, "game type sprite index" ),
	FIELD( _field_block, "prerequisites{contributing commendations}", &commendationAggregatorDependent ),
	FIELD( _field_terminator )
};

TAG_BLOCK(commendationRewardBlock, eCT_count)
{
	FIELD( _field_char_enum, "currency type#Type of currency given by this reward." ),
	FIELD( _field_pad, "CRB_PAD1", 1 ),
	FIELD( _field_short_integer, "reward value" ),
	FIELD( _field_terminator )
};

TAG_BLOCK_FROM_STRUCT(commendationAggregatorDependent, CommendationAggregatorDependent::k_commendationDependentMaxCount, commendationAggregatorDependent_struct_struct_definition );

TAG_BLOCK(commendationBlock, CommendationDefinition::k_maximumCommendationDefinitions)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_string_id, "description" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_pad, "CB_PAD0", 3 ),
	FIELD( _field_char_enum, "category" ),
	FIELD( _field_char_enum, "subcategory" ),
	FIELD( _field_char_integer, "sequence index" ),
	FIELD( _field_pad, "CB_PAD1", 1 ),
	FIELD( _field_short_integer, "medal sprite index" ),
	FIELD( _field_short_integer, "game type sprite index" ),
	FIELD( _field_custom, "unlock prerequisites" ),
	FIELD( _field_struct, "prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_block, "levels", &commendationLevelBlock ),
	FIELD( _field_terminator )
};

TAG_BLOCK(commendationLevelBlock, CommendationLevel::k_maximumCommendationLevels)
{
	FIELD( _field_string_id, "level name^" ),
	FIELD( _field_short_integer, "progress ticks to level#number of ticks to reach this level" ),
	FIELD( _field_short_integer, "progress display interval#number of ticks between displaying progress toast; 0=never display progress, 1=display every tick, 2=every other, etc." ),
	FIELD( _field_string_id, "achievement" ),
	FIELD( _field_block, "level up rewards#rewards given for reaching this level", &commendationRewardBlock ),
	FIELD( _field_terminator )
};

TAG_GROUP(commendation_aggregator_list_block, COMMENDATION_AGGREGATOR_LIST_TAG)
{
	FIELD( _field_block, "lists", &commendationAggregator ),
	FIELD( _field_terminator )
};

TAG_GROUP(commendation_globals_definition_block, COMMENDATION_GLOBALS_DEFINITION_TAG)
{
	FIELD( _field_tag_reference, "commendation aggregators" ),
	FIELD( _field_tag_reference, "medal aggregators" ),
	FIELD( _field_tag_reference, "commendation text" ),
	FIELD( _field_short_integer, "progress display time{progression display time}:seconds" ),
	FIELD( _field_short_integer, "complete display time{callout display time}:seconds" ),
	FIELD( _field_block, "commendations", &commendationBlock ),
	FIELD( _field_terminator )
};

} // namespace blofeld

