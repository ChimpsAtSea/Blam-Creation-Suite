#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(sound_response, SOUND_RESPONSE_TAG, sound_response_block_block );

	TAG_GROUP_FROM_BLOCK(sound_incident_response, SOUND_INCIDENT_RESPONSE_TAG, sound_incident_response_block_block );

	TAG_BLOCK(sound_response_permutation_block, 10)
	{
		{ _field_tag_reference, "sound", &global_sound_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_combine_response_block, 10)
	{
		{ _field_string_id, "name" },
		{ _field_byte_flags, "response behavior", &sound_combine_response_flags },
		{ _field_pad, "SRBQXEK", 3 },
		{ _field_tag_reference, "response", &sound_response_group_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(sound_response_data_block, 10)
	{
		{ _field_string_id, "name" },
		{ _field_string_id, "channel" },
		{ _field_string_id, "category" },
		{ _field_long_integer, "category priority" },
		{ _field_real, "queue timeout" },
		{ _field_real, "consideration time" },
		{ _field_real, "gap after sound" },
		{ _field_byte_flags, "queue behavior", &sound_response_queue_flags },
		{ _field_pad, "SRBQXEK", 3 },
		{ _field_block, "potential responses", &sound_response_permutation_block_block },
		{ _field_block, "combiners", &sound_combine_response_block_block },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(sound_response_block, 1, sound_response_struct_definition_struct_definition );

	TAG_BLOCK(sound_incident_response_data_block, 10)
	{
		{ _field_byte_flags, "audience", &sound_audience_flags },
		{ _field_byte_flags, "excluded audience", &sound_audience_flags },
		{ _field_byte_flags, "split screen flags", &sound_splitscreen_flags },
		{ _field_pad, "RMPES", 1 },
		{ _field_tag_reference, "response", &sound_response_group_reference },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(sound_incident_response_block, 1, sound_incident_response_struct_definition_struct_definition );

	TAG_STRUCT(sound_response_struct_definition)
	{
		{ _field_block, "responses", &sound_response_data_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(sound_incident_response_struct_definition)
	{
		{ _field_block, "responses", &sound_incident_response_data_block_block },
		{ _field_terminator }
	};

	STRINGS(sound_combine_response_flags)
	{
		"cancel queued",
		"cancel active",
		"cancel new"
	};
	STRING_LIST(sound_combine_response_flags, sound_combine_response_flags_strings, _countof(sound_combine_response_flags_strings));

	STRINGS(sound_response_queue_flags)
	{
		"bypass queue",
		"clear queue",
		"stop active sound",
		"do not track"
	};
	STRING_LIST(sound_response_queue_flags, sound_response_queue_flags_strings, _countof(sound_response_queue_flags_strings));

	STRINGS(sound_audience_flags)
	{
		"cause player",
		"cause team",
		"effect player",
		"effect team",
		"everyone"
	};
	STRING_LIST(sound_audience_flags, sound_audience_flags_strings, _countof(sound_audience_flags_strings));

	STRINGS(sound_splitscreen_flags)
	{
		"disable if split screen",
		"disable if not split screen",
		"disable if split screen on different teams",
		"disable if split screen all on same team"
	};
	STRING_LIST(sound_splitscreen_flags, sound_splitscreen_flags_strings, _countof(sound_splitscreen_flags_strings));

	TAG_REFERENCE(sound_response_group_reference, SOUND_RESPONSE_TAG);

	TAG_REFERENCE(sound_incident_response_group_reference, SOUND_INCIDENT_RESPONSE_TAG);

} // namespace blofeld

