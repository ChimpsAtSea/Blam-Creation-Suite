#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(sound_permutation_language_info, UNSIGNED_SHORT_MAX)
	{
		{ _field_short_integer, "duration in hs ticks" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(sound_pitch_range_language_info, UNSIGNED_SHORT_MAX)
	{
		{ _field_short_block_index, "first permutation language index" },
		{ _field_short_integer, "permutation count" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(sound_language_info_block, k_language_count)
	{
		{ _field_long_enum, "language", &sound_language_enum_definition },
		{ _field_block, "permutation durations", &sound_permutation_language_info_block },
		{ _field_block, "pitch range durations", &sound_pitch_range_language_info_block },
		{ _field_terminator }
	};

} // namespace blofeld

