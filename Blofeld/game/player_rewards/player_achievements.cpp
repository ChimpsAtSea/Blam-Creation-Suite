#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(achievements, ACHIEVEMENTS_TAG, achievements_block_block );

TAG_BLOCK_FROM_STRUCT(achievements_block, 1, achievements_struct_definition_struct_definition );

TAG_BLOCK(single_achievement_definition_block, k_maximum_achievements)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_char_enum, "type" ),
	FIELD( _field_byte_flags, "difficulty" ),
	FIELD( _field_pad, "VJNOSNJER", 2 ),
	FIELD( _field_block, "restricted levels", &single_achievement_restricted_level_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(single_achievement_restricted_level_block, s_single_achivement_restricted_level_definition::k_maximum_count)
{
	FIELD( _field_string_id, "level name^#Compared to map name in scenario" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(achievements_struct_definition)
{
	FIELD( _field_block, "achievement", &single_achievement_definition_block_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

