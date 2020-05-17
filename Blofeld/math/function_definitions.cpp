#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(function_type_enum_definition, 11)
	{
		OPTION("identity"),
		OPTION("constant"),
		OPTION("transition"),
		OPTION("periodic"),
		OPTION("linear"),
		OPTION("linear key"),
		OPTION("multi linear key"),
		OPTION("spline"),
		OPTION("multi spline"),
		OPTION("exponent"),
		OPTION("spline2"),
	};

	TAG_ENUM(color_graph_type_enum_definition, 5)
	{
		OPTION("scalar (intensity)"),
		OPTION("constant"),
		OPTION("2-color"),
		OPTION("3-color"),
		OPTION("4-color"),
	};

	TAG_GROUP_FROM_BLOCK(curve_scalar, CURVE_SCALAR_TAG, curve_scalar_block_block );

	TAG_BLOCK_FROM_STRUCT(curve_scalar_block, 1, curve_scalar_struct_definition_struct_definition );

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

} // namespace blofeld

