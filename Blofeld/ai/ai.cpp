#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_STRUCT(ai_spawn_conditions_struct)
	{
		FIELD( _field_word_flags, "difficulty flags", &global_campaign_difficulty_enum ),
		FIELD( _field_pad, "post-difficulty-flags-padding", 2 ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

