#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(camo_struct_definition)
{
	FIELD( _field_explanation, "Active Camo Controls" ),
	FIELD( _field_word_flags, "Flags" ),
	FIELD( _field_pad, "KKHKKHKKL", 2 ),
	FIELD( _field_struct, "Active Camo Amount", &camo_scalar_function_struct_struct_definition ),
	FIELD( _field_struct, "Shadow Amount", &camo_scalar_function_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camo_scalar_function_struct)
{
	FIELD( _field_string_id, "Input Variable!" ),
	FIELD( _field_string_id, "Range Variable!" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "Mapping", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

TAG_GROUP(camo_block, CAMO_TAG)
{
	FIELD( _field_explanation, "Active Camo Controls" ),
	FIELD( _field_word_flags, "Flags" ),
	FIELD( _field_pad, "KKHKKHKKL", 2 ),
	FIELD( _field_struct, "Active Camo Amount", &camo_scalar_function_struct_struct_definition ),
	FIELD( _field_struct, "Shadow Amount", &camo_scalar_function_struct_struct_definition ),
	FIELD( _field_terminator )
};

} // namespace blofeld

