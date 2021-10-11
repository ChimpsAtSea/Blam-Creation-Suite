#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		sound_response_group,
		SOUND_RESPONSE_TAG,
		nullptr,
		INVALID_TAG,
		sound_response_block );

	TAG_GROUP(
		sound_incident_response_group,
		SOUND_INCIDENT_RESPONSE_TAG,
		nullptr,
		INVALID_TAG,
		sound_incident_response_block );

	TAG_BLOCK_FROM_STRUCT(
		sound_response_block,
		"sound_response_block",
		1,
		sound_response_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		sound_incident_response_block,
		"sound_incident_response_block",
		1,
		sound_incident_response_struct_definition);

	#define SOUND_RESPONSE_DATA_BLOCK_STRUCT_ID { 0xFE59D7D1, 0x8B344910, 0x91A59CF1, 0x932B62A0 }
	TAG_BLOCK(
		sound_response_data_block,
		"sound_response_data_block",
		10,
		"SoundResponseDefinition",
		SET_UNKNOWN0 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_RESPONSE_DATA_BLOCK_STRUCT_ID)
	{
		{ _field_string_id, "name" },
		{ _field_string_id, "channel" },
		{ _field_string_id, "category" },
		{ _field_long_integer, "category priority" },
		{ _field_real, "queue timeout" },
		{ _field_real, "consideration time" },
		{ _field_real, "gap after sound" },
		{ _field_byte_flags, "queue behavior", &sound_response_queue_flags },
		FIELD_PAD_EX("SRBQXEK", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_block, "potential responses", &sound_response_permutation_block },
		{ _field_block, "combiners", &sound_combine_response_block },
		{ _field_terminator }
	};

	#define SOUND_RESPONSE_PERMUTATION_BLOCK_ID { 0x4EFF1491, 0x3FFD46FB, 0xBCB2BA66, 0x32D82AD5 }
	TAG_BLOCK(
		sound_response_permutation_block,
		"sound_response_permutation_block",
		10,
		"SoundResponsePermutationDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_RESPONSE_PERMUTATION_BLOCK_ID)
	{
		{ _field_tag_reference, "sound", &global_sound_reference },
		{ _field_terminator }
	};

	#define SOUND_COMBINE_RESPONSE_BLOCK_ID { 0x79470448, 0x0E27470F, 0x974CFBF3, 0x8EC2CA95 }
	TAG_BLOCK(
		sound_combine_response_block,
		"sound_combine_response_block",
		10,
		"SoundCombineResponseDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_COMBINE_RESPONSE_BLOCK_ID)
	{
		{ _field_string_id, "name" },
		{ _field_byte_flags, "response behavior", &sound_combine_response_flags },
		FIELD_PAD_EX("SRBQXEK", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_tag_reference, "response", &sound_response_group_reference },
		{ _field_terminator }
	};

	#define SOUND_INCIDENT_RESPONSE_DATA_BLOCK_ID { 0x73567E85, 0xA1DD41EE, 0xB91F166A, 0x5D246C98 }
	TAG_BLOCK(
		sound_incident_response_data_block,
		"sound_incident_response_data_block",
		10,
		"SoundIncidentResponseDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_INCIDENT_RESPONSE_DATA_BLOCK_ID)
	{
		{ _field_byte_flags, "audience", &sound_audience_flags },
		{ _field_byte_flags, "excluded audience", &sound_audience_flags },
		{ _field_byte_flags, "split screen flags", &sound_splitscreen_flags },
		FIELD_PAD_EX("RMPES", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_tag_reference, "response", &sound_response_group_reference },
		{ _field_terminator }
	};

	#define SOUND_RESPONSE_STRUCT_DEFINITION_ID { 0x048F8E35, 0x6C774DA7, 0xA440224B, 0x2E123BAB }
	TAG_STRUCT(
		sound_response_struct_definition,
		"sound_response_struct_definition",
		"SoundResponseGroupDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_RESPONSE_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "responses", &sound_response_data_block },
		{ _field_terminator }
	};

	#define SOUND_INCIDENT_RESPONSE_STRUCT_DEFINITION_ID { 0x96ADAD4E, 0xA6074EC6, 0xA626867A, 0x6DE314EF }
	TAG_STRUCT(
		sound_incident_response_struct_definition,
		"sound_incident_response_struct_definition",
		"SoundIncidentResponseGroupDefinition",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SOUND_INCIDENT_RESPONSE_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "responses", &sound_incident_response_data_block },
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

