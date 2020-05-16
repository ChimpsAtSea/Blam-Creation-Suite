#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(rumble_struct_definition)
{
	FIELD( _field_struct, "rumble", &rumble_definition_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(rumble_definition_struct)
{
	FIELD( _field_explanation, "low frequency rumble" ),
	FIELD( _field_struct, "low frequency rumble", &rumble_frequency_definition_struct_struct_definition ),
	FIELD( _field_explanation, "high frequency rumble" ),
	FIELD( _field_struct, "high frequency rumble", &rumble_frequency_definition_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(rumble_frequency_definition_struct)
{
	FIELD( _field_real, "duration:seconds" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "dirty whore", &mapping_function_struct_definition ),
	FIELD( _field_useless_pad ),
	FIELD( _field_terminator )
};

TAG_GROUP(rumble_block, RUMBLE_TAG)
{
	FIELD( _field_struct, "rumble", &rumble_definition_struct_struct_definition ),
	FIELD( _field_terminator )
};

} // namespace blofeld

