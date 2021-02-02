#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define AI_SPAWN_CONDITIONS_STRUCT_ID { 0xF95BF66A, 0x46764415, 0xB6C52F11, 0xEFDE15CF }
	TAG_STRUCT(
		ai_spawn_conditions_struct,
		"ai_spawn_conditions_struct",
		"s_ai_spawn_conditions",
		AI_SPAWN_CONDITIONS_STRUCT_ID)
	{
		{ _field_word_flags, "difficulty flags", &global_campaign_difficulty_enum },
		FIELD_PAD("post-difficulty-flags-padding", nullptr, 2),
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

