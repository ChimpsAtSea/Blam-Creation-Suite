#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(platform_sound_playback, 128)
{
	FIELD( _field_string_id, "name^" ),
	FIELD( _field_struct, "playback" ),
	FIELD( _field_terminator )
};

TAG_GROUP(sound_effect_collection, SOUND_EFFECT_COLLECTION_TAG)
{
	FIELD( _field_block, "sound effects", &platform_sound_playback_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

