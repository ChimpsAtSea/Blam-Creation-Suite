#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define HALF_SH_TERMS_ID { 0x20CD467C, 0x4303458B, 0x9980FCD2, 0x2E473035 }
	TAG_ARRAY(
		half_sh_terms_array,
		"half_sh_terms",
		((3)*(3)),
		"short",
		HALF_SH_TERMS_ID)
	{
		{ _field_short_integer, "coefficient" },
		{ _field_terminator }
	};

	#define HALF_RGB_LIGHTPROBE_STRUCT_ID { 0x101E5B0B, 0xD7614F00, 0x817C8CE0, 0x91BB5C69 }
	TAG_STRUCT(
		half_rgb_lightprobe_struct,
		"half_rgb_lightprobe_struct",
		"half_rgb_lightprobe",
		HALF_RGB_LIGHTPROBE_STRUCT_ID)
	{
		{ _field_array, "red sh terms", &half_sh_terms_array },
		{ _field_array, "green sh terms", &half_sh_terms_array },
		{ _field_array, "blue sh terms", &half_sh_terms_array },
		{ _field_short_integer, "analytical visibility" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

