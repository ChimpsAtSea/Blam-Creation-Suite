#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(particleman_struct_definition)
{
	FIELD( _field_explanation, "Particleize Settings" ),
	FIELD( _field_enum, "Shape" ),
	FIELD( _field_word_flags, "Flags" ),
	FIELD( _field_real, "Duration:sec" ),
	FIELD( _field_real, "Density" ),
	FIELD( _field_real, "Size:world units" ),
	FIELD( _field_struct, "Curve", &particleize_scalar_function_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(particleize_scalar_function_struct)
{
	FIELD( _field_custom ),
	FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

TAG_GROUP(particleman_block, PARTICLEMAN_TAG)
{
	FIELD( _field_explanation, "Particleize Settings" ),
	FIELD( _field_enum, "Shape" ),
	FIELD( _field_word_flags, "Flags" ),
	FIELD( _field_real, "Duration:sec" ),
	FIELD( _field_real, "Density" ),
	FIELD( _field_real, "Size:world units" ),
	FIELD( _field_struct, "Curve", &particleize_scalar_function_struct_struct_definition ),
	FIELD( _field_terminator )
};

} // namespace blofeld

