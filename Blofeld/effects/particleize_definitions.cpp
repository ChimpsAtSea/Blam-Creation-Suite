#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(particleman, PARTICLEMAN_TAG, particleman_block_block );

TAG_BLOCK_FROM_STRUCT(particleman_block, 1, particleman_struct_definition_struct_definition );

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

} // namespace blofeld

