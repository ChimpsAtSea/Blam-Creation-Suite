#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(commendation_aggregator_list, COMMENDATION_AGGREGATOR_LIST_TAG, commendation_aggregator_list_block_block );

	TAG_GROUP_FROM_BLOCK(commendation_globals_definition, COMMENDATION_GLOBALS_DEFINITION_TAG, commendation_globals_definition_block_block );

	TAG_BLOCK(commendationRewardBlock, eCT_count)
	{
		FIELD( _field_char_enum, "currency type#Type of currency given by this reward.", &currencyTypeEnumDefinition ),
		FIELD( _field_pad, "CRB_PAD1", 1 ),
		FIELD( _field_short_integer, "reward value" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(commendationAggregatorDependent, CommendationAggregatorDependent::k_commendationDependentMaxCount, commendationAggregatorDependent_struct_struct_definition );

	TAG_BLOCK(commendationAggregator, CommendationAggregator::k_commendationAggregatorMaxCount)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_string_id, "description text" ),
		FIELD( _field_block, "rewards", &commendationRewardBlock_block ),
		FIELD( _field_char_integer, "sequence index" ),
		FIELD( _field_pad, "CA_PAD1", 3 ),
		FIELD( _field_short_integer, "medal sprite index" ),
		FIELD( _field_short_integer, "game type sprite index" ),
		FIELD( _field_block, "prerequisites{contributing commendations}", &commendationAggregatorDependent_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(commendation_aggregator_list_block, 1, commendation_aggregator_list_struct_definition_struct_definition );

	TAG_BLOCK(commendationLevelBlock, CommendationLevel::k_maximumCommendationLevels)
	{
		FIELD( _field_string_id, "level name^" ),
		FIELD( _field_short_integer, "progress ticks to level#number of ticks to reach this level" ),
		FIELD( _field_short_integer, "progress display interval#number of ticks between displaying progress toast; 0=never display progress, 1=display every tick, 2=every other, etc." ),
		FIELD( _field_string_id, "achievement" ),
		FIELD( _field_block, "level up rewards#rewards given for reaching this level", &commendationRewardBlock_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(commendationBlock, CommendationDefinition::k_maximumCommendationDefinitions)
	{
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_string_id, "description" ),
		FIELD( _field_byte_flags, "flags", &commendationFlags ),
		FIELD( _field_pad, "CB_PAD0", 3 ),
		FIELD( _field_char_enum, "category", &commendationCategoryEnum ),
		FIELD( _field_char_enum, "subcategory", &commendationSubcategoryEnum ),
		FIELD( _field_char_integer, "sequence index" ),
		FIELD( _field_pad, "CB_PAD1", 1 ),
		FIELD( _field_short_integer, "medal sprite index" ),
		FIELD( _field_short_integer, "game type sprite index" ),
		FIELD( _field_custom, "unlock prerequisites" ),
		FIELD( _field_struct, "prerequisites", &PurchasePrerequisitesUnifiedDefinitionBlock_struct_definition ),
		FIELD( _field_custom ),
		FIELD( _field_block, "levels", &commendationLevelBlock_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK_FROM_STRUCT(commendation_globals_definition_block, 1, commendation_globals_definition_struct_definition_struct_definition );

	TAG_STRUCT(commendation_aggregator_list_struct_definition)
	{
		FIELD( _field_block, "lists", &commendationAggregator_block ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(commendationAggregatorDependent_struct)
	{
		FIELD( _field_char_enum, "type", &aggregatorDependentTypeEnumDefinition ),
		FIELD( _field_pad, "PAD1", 3 ),
		FIELD( _field_string_id, "name^" ),
		FIELD( _field_terminator )
	};

	TAG_STRUCT(commendation_globals_definition_struct_definition)
	{
		FIELD( _field_tag_reference, "commendation aggregators" ),
		FIELD( _field_tag_reference, "medal aggregators" ),
		FIELD( _field_tag_reference, "commendation text" ),
		FIELD( _field_short_integer, "progress display time{progression display time}:seconds" ),
		FIELD( _field_short_integer, "complete display time{callout display time}:seconds" ),
		FIELD( _field_block, "commendations", &commendationBlock_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(commendationCategoryEnum, 10)
	{
		OPTION("default"),
		OPTION("weapons"),
		OPTION("ordnance"),
		OPTION("enemies"),
		OPTION("vehicles"),
		OPTION("player"),
		OPTION("armor abilities"),
		OPTION("objectives"),
		OPTION("customs"),
		OPTION("UGC"),
	};

	TAG_ENUM(commendationFlags, 1)
	{
		OPTION("hidden"),
	};

	TAG_ENUM(commendationSubcategoryEnum, 16)
	{
		OPTION("default"),
		OPTION("unsc"),
		OPTION("covenant"),
		OPTION("forerunner"),
		OPTION("Covenant Enemy"),
		OPTION("Forerunner Enemy"),
		OPTION("Campaign"),
		OPTION("War Games"),
		OPTION("Slayer"),
		OPTION("Regicide"),
		OPTION("CTF"),
		OPTION("Extraction"),
		OPTION("Oddball"),
		OPTION("King of the Hill"),
		OPTION("Dominion"),
		OPTION("Flood"),
	};

	TAG_ENUM(aggregatorDependentTypeEnumDefinition, 2)
	{
		OPTION("commendation"),
		OPTION("aggregator"),
	};

} // namespace blofeld

