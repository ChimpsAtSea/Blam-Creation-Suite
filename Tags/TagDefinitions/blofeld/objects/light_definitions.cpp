#include <tagdefinitions-private-pch.h>
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
		{ _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_struct, "Midnight_Light_Parameters", &midnight_light_struct_struct_definition },
		{ _field_terminator },

		// { _field_real, "destroy light after:seconds#automatically destroys the light after it has existed this long (0 to disable)" },

		{ _field_word_flags, "flags", &light_definition_flags }, // #TODO test
		{ _field_short_integer, "unknown" },
		{ _field_long_enum, "Light Type:#Geometry shape of light.", &midnight_light_type_enum_definition }, // #TODO test
		{ _field_real, "Intensity:[0-1+]" }, // #TODO test
		{ _field_real, "Radius or size of light" }, // #TODO test
		{ _field_real, "unknown@", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_explanation, "Shared Spot Parameters", "" },
		{ _field_real, "Inner Cone Angle:[0-160 degrees]#Inner hotspot attenuation end." }, // #TODO test
		{ _field_real, "Outer Cone End:[0-160 degrees]#Angle size of spotlight." }, // #TODO test
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_long_integer, "unknown", },
		{ _field_struct, "color function", &light_color_function_struct_struct_definition }, // #TODO test
		{ _field_struct, "brightness function", &light_scalar_function_struct_struct_definition }, // #TODO test
		{ _field_tag_reference, "gel/gobo map", &global_bitmap_reference },
		{ _field_real, "Rotation:[0-360 degrees]" }, // #TODO test
		{ _field_real, "Aspect Ratio:[-0-1+]#Shape length and width of Gobo." }, // #TODO test
		{ _field_long_integer, "unknown", },
		{ _field_tag_reference, "Lens Flare", &global_lens_flare_reference },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },
		{ _field_real, "unknown", },

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

