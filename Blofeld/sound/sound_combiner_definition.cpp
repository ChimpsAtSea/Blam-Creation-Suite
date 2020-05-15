#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(sound_combiner_definition_entry, k_maximum_sound_combiner_defintion_entry_count)
{
	FIELD( _field_tag_reference, "sound^" ),
	FIELD( _field_real_bounds, "delay bounds:seconds#delay before this sound is played" ),
	FIELD( _field_terminator )
};

TAG_GROUP(sound_combiner, SOUND_COMBINER_TAG)
{
	FIELD( _field_block, "entries", &sound_combiner_definition_entry_block ),
	FIELD( _field_real, "maximum play seconds!#this is determined at post process time" ),
	FIELD( _field_real, "minimum distance default!#this is determined at post process time" ),
	FIELD( _field_real, "maximum distance default!#this is determined at post process time" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

