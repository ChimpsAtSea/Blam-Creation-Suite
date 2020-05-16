#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(light_struct_definition)
{
	FIELD( _field_struct, "Midnight_Light_Parameters", &midnight_light_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(light_color_function_struct)
{
	FIELD( _field_string_id, "Input Variable!" ),
	FIELD( _field_string_id, "Range Variable!" ),
	FIELD( _field_enum, "Output Modifier!" ),
	FIELD( _field_pad, "BVCG", 2 ),
	FIELD( _field_string_id, "Output Modifier Input!" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(light_scalar_function_struct)
{
	FIELD( _field_string_id, "Input Variable!" ),
	FIELD( _field_string_id, "Range Variable!" ),
	FIELD( _field_enum, "Output Modifier!" ),
	FIELD( _field_pad, "BVCG", 2 ),
	FIELD( _field_string_id, "Output Modifier Input!" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

TAG_GROUP(light_block, LIGHT_TAG)
{
	FIELD( _field_struct, "Midnight_Light_Parameters", &midnight_light_struct_struct_definition ),
	FIELD( _field_terminator )
};

} // namespace blofeld

