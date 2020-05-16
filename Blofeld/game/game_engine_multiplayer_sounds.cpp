#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(sound_response, SOUND_RESPONSE_TAG, sound_response_block_block )

TAG_GROUP_FROM_BLOCK(sound_incident_response, SOUND_INCIDENT_RESPONSE_TAG, sound_incident_response_block_block )

TAG_BLOCK_FROM_STRUCT(sound_response_block, 1, sound_response_struct_definition_struct_definition );

TAG_BLOCK_FROM_STRUCT(sound_incident_response_block, 1, sound_incident_response_struct_definition_struct_definition );

TAG_BLOCK(sound_response_data_block, 10)
{
	FIELD( _field_string_id, "name" ),
	FIELD( _field_string_id, "channel" ),
	FIELD( _field_string_id, "category" ),
	FIELD( _field_long_integer, "category priority" ),
	FIELD( _field_real, "queue timeout" ),
	FIELD( _field_real, "consideration time" ),
	FIELD( _field_real, "gap after sound" ),
	FIELD( _field_byte_flags, "queue behavior" ),
	FIELD( _field_pad, "SRBQXEK", 3 ),
	FIELD( _field_block, "potential responses", &sound_response_permutation_block_block ),
	FIELD( _field_block, "combiners", &sound_combine_response_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_response_permutation_block, 10)
{
	FIELD( _field_tag_reference, "sound" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_combine_response_block, 10)
{
	FIELD( _field_string_id, "name" ),
	FIELD( _field_byte_flags, "response behavior" ),
	FIELD( _field_pad, "SRBQXEK", 3 ),
	FIELD( _field_tag_reference, "response" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sound_incident_response_data_block, 10)
{
	FIELD( _field_byte_flags, "audience" ),
	FIELD( _field_byte_flags, "excluded audience" ),
	FIELD( _field_byte_flags, "split screen flags" ),
	FIELD( _field_pad, "RMPES", 1 ),
	FIELD( _field_tag_reference, "response" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(sound_response_struct_definition)
{
	FIELD( _field_block, "responses", &sound_response_data_block_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(sound_incident_response_struct_definition)
{
	FIELD( _field_block, "responses", &sound_incident_response_data_block_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

