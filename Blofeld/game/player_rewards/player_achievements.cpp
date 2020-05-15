#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(single_achievement_definition, k_maximum_achievements)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_char_enum, "type" ),
	FIELD( _field_byte_flags, "difficulty" ),
	FIELD( _field_pad, "VJNOSNJER", 2 ),
	FIELD( _field_block, "restricted levels", &single_achievement_restricted_level_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(single_achievement_restricted_level, s_single_achivement_restricted_level_definition::k_maximum_count)
{
	FIELD( _field_string_id, "level name^#Compared to map name in scenario" ),
	FIELD( _field_terminator )
};

TAG_GROUP(achievements, ACHIEVEMENTS_TAG)
{
	FIELD( _field_block, "achievement", &single_achievement_definition_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

