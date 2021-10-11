#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define AI_SPAWN_CONDITIONS_STRUCT_ID { 0xF95BF66A, 0x46764415, 0xB6C52F11, 0xEFDE15CF }
	TAG_STRUCT(
		ai_spawn_conditions_struct,
		"ai_spawn_conditions_struct",
		"s_ai_spawn_conditions",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AI_SPAWN_CONDITIONS_STRUCT_ID)
	{
		{ _field_word_flags, "difficulty flags", &global_campaign_difficulty_enum },
		FIELD_PAD_EX("post-difficulty-flags-padding", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};



} // namespace blofeld

