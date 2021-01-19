#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(hologramLightingGlobalsBlock, 1)
	{
		{ _field_custom, "HOLOGRAM FUNCTIONS" },
		{ _field_string_id, "Intensity" },
		{ _field_custom },
		{ _field_custom, "KEY LIGHT FUNCTIONS" },
		{ _field_struct, "Key Light Functions", &hologramLightFunctions_struct_definition },
		{ _field_custom },
		{ _field_custom, "FILL LIGHT FUNCTIONS" },
		{ _field_struct, "Fill Light Functions", &hologramLightFunctions_struct_definition },
		{ _field_custom },
		{ _field_custom, "RIM LIGHT FUNCTIONS" },
		{ _field_struct, "Rim Light Functions", &hologramLightFunctions_struct_definition },
		{ _field_custom },
		{ _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(hologramLightingBlock, 1, hologramLightingBlock_struct_struct_definition );

	V5_TAG_STRUCT(hologramLightFunctions)
	{
		{ _field_string_id, "Intensity" },
		{ _field_string_id, "Forward" },
		{ _field_string_id, "Right" },
		{ _field_string_id, "Up" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(hologramLightingBlock_struct)
	{
		{ _field_custom, "HOLOGRAM" },
		{ _field_custom, "Intensity" },
		{ _field_real, "Intensity" },
		{ _field_real, "Intensity Input!" },
		{ _field_char_enum, "Transparency Mode", &hologramTransparencyMode },
		{ _field_pad, "PADDING1", 3 },
		{ _field_custom },
		{ _field_custom, "KEY LIGHT" },
		{ _field_struct, "Key Light", &hologramLight_struct_definition },
		{ _field_custom },
		{ _field_custom, "FILL LIGHT" },
		{ _field_struct, "Fill Light", &hologramLight_struct_definition },
		{ _field_custom },
		{ _field_custom, "RIM LIGHT" },
		{ _field_struct, "Rim Light", &hologramLight_struct_definition },
		{ _field_custom },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(hologramLight)
	{
		{ _field_custom, "Hologram Light" },
		{ _field_custom, "Direction" },
		{ _field_real, "Direction" },
		{ _field_custom, "Front-Back" },
		{ _field_real, "Front-Back" },
		{ _field_custom, "Intensity" },
		{ _field_real, "Intensity" },
		{ _field_real, "Intensity Input!" },
		{ _field_real, "Forward Input!" },
		{ _field_real, "Right Input!" },
		{ _field_real, "Up Input!" },
		{ _field_terminator }
	};

	STRINGS(hologramTransparencyMode)
	{
		"cheap",
		"expensive"
	};
	STRING_LIST(hologramTransparencyMode, hologramTransparencyMode_strings, _countof(hologramTransparencyMode_strings));

} // namespace blofeld

