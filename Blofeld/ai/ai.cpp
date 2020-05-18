#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_STRUCT(ai_spawn_conditions_struct)
	{
		{ _field_word_flags, "difficulty flags", &global_campaign_difficulty_enum },
		{ _field_pad, "post-difficulty-flags-padding", 2 },
		{ _field_terminator }
	};

} // namespace blofeld

