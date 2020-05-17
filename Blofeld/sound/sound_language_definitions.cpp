#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(sound_permutation_language_info, UNSIGNED_SHORT_MAX)
	{
		FIELD( _field_short_integer, "duration in hs ticks" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(sound_pitch_range_language_info, UNSIGNED_SHORT_MAX)
	{
		FIELD( _field_short_block_index, "first permutation language index" ),
		FIELD( _field_short_integer, "permutation count" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(sound_language_info_block, k_language_count)
	{
		FIELD( _field_long_enum, "language", &sound_language_enum_definition ),
		FIELD( _field_block, "permutation durations", &sound_permutation_language_info_block ),
		FIELD( _field_block, "pitch range durations", &sound_pitch_range_language_info_block ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

