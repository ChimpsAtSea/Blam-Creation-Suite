#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(platform_sound_playback, 128)
{
	{ _field_string_id, "name^" },
	{ _field_struct, "playback" },
	{ _field_terminator },
};

TAG_GROUP(sound_effect_collection, SOUND_EFFECT_COLLECTION_TAG)
{
	{ _field_block, "sound effects", &platform_sound_playback_block },
	{ _field_terminator },
};

} // namespace blofeld

