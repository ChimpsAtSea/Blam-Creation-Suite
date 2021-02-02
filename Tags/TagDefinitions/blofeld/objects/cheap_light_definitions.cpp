#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(cheap_light, CHEAP_LIGHT_TAG, cheap_light_block_block );

	V5_TAG_BLOCK_FROM_STRUCT(cheap_light_block, 1, cheap_light_struct_definition_struct_definition );

	V5_TAG_STRUCT(cheap_light_struct_definition)
	{
		{ _field_legacy, _field_explanation, "Cheap Lights", "These are the cheapest light possible. They are spherical, have a color with an intensity and a radius - and that\'s it. They should be small: 0.5 or smaller if you can get close to them. That\'s why they are so cheap." },
		
		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_char_enum, "function input", &cheapLightFunctionInputEnum },
		{ _field_legacy, _field_pad, "clblah", 3 },

		{ _field_legacy, _field_explanation, "COLOR", "color and intensity of the light" },
		{ _field_legacy, _field_struct, "color", &light_color_function_struct_struct_definition },
		{ _field_legacy, _field_struct, "intensity", &light_scalar_function_struct_struct_definition },
		{ _field_legacy, _field_explanation, "SIZE", "radius of the spherical light" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 3 },
		{ _field_legacy, _field_struct, "radius", &light_scalar_function_struct_struct_definition },
		{ _field_legacy, _field_real, "falloff begin ratio:[0-1]#Ratio of falloff start to falloff end" },
		{ _field_legacy, _field_real, "closeup fading distance" }, // #TODO: unconfirmed

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 5 },
		{ _field_legacy, _field_struct, "Falloff End{radius}", &light_scalar_function_struct_struct_definition },
		{ _field_legacy, _field_real, "Falloff Begin Ratio:[0-1]#Ratio of falloff start to falloff end" },
		{ _field_legacy, _field_real, "near fade distance{closeup fading distance}:world units" },
		{ _field_legacy, _field_real, "far fade begin:world units" },
		{ _field_legacy, _field_real, "far fade cutoff:world units" },

		{ _field_legacy, _field_terminator }
	};

	STRINGS(cheapLightFunctionInputEnum)
	{
		"time/age",
		"scale A",
		"scale B"
	};
	STRING_LIST(cheapLightFunctionInputEnum, cheapLightFunctionInputEnum_strings, _countof(cheapLightFunctionInputEnum_strings));

} // namespace blofeld

