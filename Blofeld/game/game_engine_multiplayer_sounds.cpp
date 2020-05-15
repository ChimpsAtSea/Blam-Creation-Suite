#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(sound_response_data, 10)
{
	{ _field_string_id, "name" },
	{ _field_string_id, "channel" },
	{ _field_string_id, "category" },
	{ _field_long_integer, "category priority" },
	{ _field_real, "queue timeout" },
	{ _field_real, "consideration time" },
	{ _field_real, "gap after sound" },
	{ _field_byte_flags, "queue behavior" },
	{ _field_pad, "SRBQXEK", 3 },
	{ _field_block, "potential responses", &sound_response_permutation_block },
	{ _field_block, "combiners", &sound_combine_response_block },
	{ _field_terminator },
};

TAG_BLOCK(sound_response_permutation, 10)
{
	{ _field_tag_reference, "sound" },
	{ _field_terminator },
};

TAG_BLOCK(sound_combine_response, 10)
{
	{ _field_string_id, "name" },
	{ _field_byte_flags, "response behavior" },
	{ _field_pad, "SRBQXEK", 3 },
	{ _field_tag_reference, "response" },
	{ _field_terminator },
};

TAG_BLOCK(sound_incident_response_data, 10)
{
	{ _field_byte_flags, "audience" },
	{ _field_byte_flags, "excluded audience" },
	{ _field_byte_flags, "split screen flags" },
	{ _field_pad, "RMPES", 1 },
	{ _field_tag_reference, "response" },
	{ _field_terminator },
};

TAG_GROUP(sound_response, SOUND_RESPONSE_TAG)
{
	{ _field_block, "responses", &sound_response_data_block },
	{ _field_terminator },
};

TAG_GROUP(sound_incident_response, SOUND_INCIDENT_RESPONSE_TAG)
{
	{ _field_block, "responses", &sound_incident_response_data_block },
	{ _field_terminator },
};

} // namespace blofeld

