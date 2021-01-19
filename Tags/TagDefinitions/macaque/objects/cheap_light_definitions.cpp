#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		cheap_light_group,
		CHEAP_LIGHT_TAG,
		nullptr,
		INVALID_TAG,
		cheap_light_block );

	TAG_BLOCK_FROM_STRUCT(
		cheap_light_block,
		"cheap_light_block",
		1,
		cheap_light_struct_definition);

	#define CHEAP_LIGHT_STRUCT_DEFINITION_ID { 0x6A1EB2F2, 0xF6AF4F2D, 0x9C2D7F25, 0xE4B6E5AE }
	TAG_STRUCT(
		cheap_light_struct_definition,
		"cheap_light_struct_definition",
		"s_cheap_light_definition",
		CHEAP_LIGHT_STRUCT_DEFINITION_ID)
	{
		{ _field_explanation, "Cheap Lights", "These are the cheapest light possible. They are spherical, have a color with an intensity and a radius - and that\'s it. They should be small: 0.5 or smaller if you can get close to them. That\'s why they are so cheap." },
		{ _field_char_enum, "function input", &cheapLightFunctionInputEnum },
		{ _field_pad, "clblah", 3 },
		{ _field_explanation, "COLOR", "color and intensity of the light" },
		{ _field_struct, "color", &light_color_function_struct },
		{ _field_struct, "intensity", &light_scalar_function_struct },
		{ _field_explanation, "SIZE", "radius of the spherical light" },
		{ _field_struct, "Falloff End{radius}", &light_scalar_function_struct },
		{ _field_real, "Falloff Begin Ratio:[0-1]#Ratio of falloff start to falloff end" },
		{ _field_real, "near fade distance{closeup fading distance}:world units" },
		{ _field_real, "far fade begin:world units" },
		{ _field_real, "far fade cutoff:world units" },
		{ _field_terminator }
	};

	STRINGS(cheapLightFunctionInputEnum)
	{
		"time/age",
		"scale A",
		"scale B"
	};
	STRING_LIST(cheapLightFunctionInputEnum, cheapLightFunctionInputEnum_strings, _countof(cheapLightFunctionInputEnum_strings));

} // namespace macaque

} // namespace blofeld

