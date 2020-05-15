#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(sound_language_info, k_language_count)
{
	{ _field_long_enum, "language" },
	{ _field_block, "permutation durations", &sound_permutation_language_info_block },
	{ _field_block, "pitch range durations", &sound_pitch_range_language_info_block },
	{ _field_terminator },
};

TAG_BLOCK(sound_permutation_language_info, UNSIGNED_SHORT_MAX)
{
	{ _field_short_integer, "duration in hs ticks" },
	{ _field_terminator },
};

TAG_BLOCK(sound_pitch_range_language_info, UNSIGNED_SHORT_MAX)
{
	{ _field_short_block_index, "first permutation language index" },
	{ _field_short_integer, "permutation count" },
	{ _field_terminator },
};

} // namespace blofeld

