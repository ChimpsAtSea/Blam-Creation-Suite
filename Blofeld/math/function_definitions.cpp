#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(curve_scalar_struct_definition)
{
	FIELD( _field_struct, "function", &scalar_function_named_struct_default_one_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(mapping_function)
{
	FIELD( _field_custom ),
	FIELD( _field_data, "data" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(scalar_function_named_struct_default_one)
{
	FIELD( _field_custom ),
	FIELD( _field_struct, "function", &mapping_function_default_one_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(mapping_function_default_one)
{
	FIELD( _field_custom ),
	FIELD( _field_data, "data" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(scalar_function_named_struct)
{
	FIELD( _field_custom ),
	FIELD( _field_struct, "function", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(color_function_named_struct)
{
	FIELD( _field_custom ),
	FIELD( _field_struct, "function", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

TAG_GROUP(curve_scalar_block, CURVE_SCALAR_TAG)
{
	FIELD( _field_struct, "function", &scalar_function_named_struct_default_one_struct_definition ),
	FIELD( _field_terminator )
};

} // namespace blofeld

