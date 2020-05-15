#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(sound_references, 500)
{
	{ _field_string_id, "vocalization^" },
	{ _field_block, "stimuli", &vocalization_stimuli_block },
	{ _field_terminator },
};

TAG_BLOCK(vocalization_stimuli, 6)
{
	{ _field_word_flags, "flags" },
	{ _field_pad, "AN", 2 },
	{ _field_string_id, "stimulus^" },
	{ _field_tag_reference, "sound" },
	{ _field_terminator },
};

TAG_GROUP(dialogue, DIALOGUE_TAG)
{
	{ _field_tag_reference, "global dialogue info" },
	{ _field_long_flags, "flags" },
	{ _field_block, "vocalizations", &sound_references_block },
	{ _field_string_id, "mission dialogue designator#3-letter mission dialogue designator name" },
	{ _field_terminator },
};

} // namespace blofeld

