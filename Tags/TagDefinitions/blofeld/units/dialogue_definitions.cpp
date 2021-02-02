#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP(dialogue, DIALOGUE_TAG)
	{
		{ _field_legacy, _field_tag_reference, "global dialogue info", &global_dialogue_reference },
		{ _field_legacy, _field_long_flags, "flags", &dialogue_flags },
		{ _field_legacy, _field_block, "vocalizations", &sound_references_block_block },
		{ _field_legacy, _field_string_id, "mission dialogue designator#3-letter mission dialogue designator name" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(vocalization_stimuli_block_definition, 6)
	{
		{ _field_legacy, _field_word_flags, "flags", &vocalization_stimulus_flags },
		{ _field_legacy, _field_pad, "AN", 2 },
		{ _field_legacy, _field_string_id, "stimulus^" },
		{ _field_legacy, _field_tag_reference, "sound", &sound_reference$4 },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(sound_references_block, 500)
	{
		{ _field_legacy, _field_string_id, "vocalization^" },
		{ _field_legacy, _field_block, "stimuli", &vocalization_stimuli_block_definition_block },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(vocalization_stimulus_flags)
	{
		"additive#this stimulus should add to the default vocalization instead of replacing it",
		"don\'t suppress#this stimulus cannot be suppressed"
	};
	STRING_LIST(vocalization_stimulus_flags, vocalization_stimulus_flags_strings, _countof(vocalization_stimulus_flags_strings));

	STRINGS(dialogue_flags)
	{
		"female"
	};
	STRING_LIST(dialogue_flags, dialogue_flags_strings, _countof(dialogue_flags_strings));

} // namespace blofeld

