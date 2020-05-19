#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(light, LIGHT_TAG, light_block_block );

	TAG_BLOCK_FROM_STRUCT(light_block, 1, light_struct_definition_struct_definition );

	TAG_STRUCT(light_color_function_struct)
	{
		{ _field_string_id, "Input Variable!" },
		{ _field_string_id, "Range Variable!" },
		{ _field_enum, "Output Modifier!", &output_mod_enum },
		{ _field_pad, "BVCG", 2 },
		{ _field_string_id, "Output Modifier Input!" },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(light_scalar_function_struct)
	{
		{ _field_string_id, "Input Variable!" },
		{ _field_string_id, "Range Variable!" },
		{ _field_enum, "Output Modifier!", &output_mod_enum },
		{ _field_pad, "BVCG", 2 },
		{ _field_string_id, "Output Modifier Input!" },
		{ _field_custom },
		{ _field_struct, "Mapping", &mapping_function_struct_definition },
		{ _field_terminator }
	};

	TAG_STRUCT(light_struct_definition)
	{
		{ _field_struct, "Midnight_Light_Parameters", &midnight_light_struct_struct_definition },
		{ _field_terminator }
	};

	STRINGS(output_mod_enum$4)
	{
		" ",
		"Plus",
		"Times"
	};
	STRING_LIST(output_mod_enum$4, output_mod_enum$4_strings, _countof(output_mod_enum$4_strings));

} // namespace blofeld

