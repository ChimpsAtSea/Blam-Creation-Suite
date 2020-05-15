#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(sound_references, 500)
{
	FIELD( _field_string_id, "vocalization^" ),
	FIELD( _field_block, "stimuli", &vocalization_stimuli_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(vocalization_stimuli, 6)
{
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_pad, "AN", 2 ),
	FIELD( _field_string_id, "stimulus^" ),
	FIELD( _field_tag_reference, "sound" ),
	FIELD( _field_terminator )
};

TAG_GROUP(dialogue, DIALOGUE_TAG)
{
	FIELD( _field_tag_reference, "global dialogue info" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_block, "vocalizations", &sound_references_block ),
	FIELD( _field_string_id, "mission dialogue designator#3-letter mission dialogue designator name" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

