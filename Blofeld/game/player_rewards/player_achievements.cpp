#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(single_achievement_definition, k_maximum_achievements)
{
	{ _field_string_id, "name^" },
	{ _field_char_enum, "type" },
	{ _field_byte_flags, "difficulty" },
	{ _field_pad, "VJNOSNJER", 2 },
	{ _field_block, "restricted levels", &single_achievement_restricted_level_block },
	{ _field_terminator },
};

TAG_BLOCK(single_achievement_restricted_level, s_single_achivement_restricted_level_definition::k_maximum_count)
{
	{ _field_string_id, "level name^#Compared to map name in scenario" },
	{ _field_terminator },
};

TAG_GROUP(achievements, ACHIEVEMENTS_TAG)
{
	{ _field_block, "achievement", &single_achievement_definition_block },
	{ _field_terminator },
};

} // namespace blofeld

