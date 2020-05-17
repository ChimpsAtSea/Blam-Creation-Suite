#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP(dialogue, DIALOGUE_TAG)
	{
		FIELD( _field_tag_reference, "global dialogue info" ),
		FIELD( _field_long_flags, "flags", &dialogue_flags ),
		FIELD( _field_block, "vocalizations", &sound_references_block_block ),
		FIELD( _field_string_id, "mission dialogue designator#3-letter mission dialogue designator name" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(vocalization_stimuli_block_definition, 6)
	{
		FIELD( _field_word_flags, "flags", &vocalization_stimulus_flags ),
		FIELD( _field_pad, "AN", 2 ),
		FIELD( _field_string_id, "stimulus^" ),
		FIELD( _field_tag_reference, "sound" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(sound_references_block, 500)
	{
		FIELD( _field_string_id, "vocalization^" ),
		FIELD( _field_block, "stimuli", &vocalization_stimuli_block_definition_block ),
		FIELD( _field_terminator )
	};

	TAG_ENUM(vocalization_stimulus_flags, 2)
	{
		OPTION("additive#this stimulus should add to the default vocalization instead of replacing it"),
		OPTION("don\'t suppress#this stimulus cannot be suppressed"),
	};

	TAG_ENUM(dialogue_flags, 1)
	{
		OPTION("female"),
	};

} // namespace blofeld

