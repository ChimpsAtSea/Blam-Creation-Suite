#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(rumble, RUMBLE_TAG, rumble_block_block );

	TAG_BLOCK_FROM_STRUCT(rumble_block, 1, rumble_struct_definition_struct_definition );

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

} // namespace blofeld

