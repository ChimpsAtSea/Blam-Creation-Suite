#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(camo, CAMO_TAG, camo_block_block );

	TAG_BLOCK_FROM_STRUCT(camo_block, 1, camo_struct_definition_struct_definition );

	TAG_STRUCT(camo_struct_definition)
	{
		{ _field_explanation, "Active Camo Controls" },
		{ _field_word_flags, "Flags", &camo_flags },
		{ _field_pad, "KKHKKHKKL", 2 },
		{ _field_struct, "Active Camo Amount", &camo_scalar_function_struct_struct_definition },
		{ _field_struct, "Shadow Amount", &camo_scalar_function_struct_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(camo_scalar_function_struct)
	{
		{ _field_string_id, "Input Variable!" },
		{ _field_string_id, "Range Variable!" },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	STRINGS(camo_flags)
	{
		"also apply to object children"
	};
	STRING_LIST(camo_flags, camo_flags_strings, _countof(camo_flags_strings));

} // namespace blofeld

