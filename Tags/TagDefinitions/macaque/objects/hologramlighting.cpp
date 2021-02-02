#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define HOLOGRAMLIGHTINGGLOBALSBLOCK_ID { 0x8E264B3B, 0x9FD14745, 0x83BCD78E, 0x9FBB73AC }
	TAG_BLOCK(
		hologramLightingGlobalsBlock_block,
		"hologramLightingGlobalsBlock",
		1,
		"HologramLightingGlobals",
		HOLOGRAMLIGHTINGGLOBALSBLOCK_ID)
	{
		FIELD_CUSTOM("HOLOGRAM FUNCTIONS", nullptr, _field_id_function_group_begin),
		{ _field_string_id, "Intensity" },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		FIELD_CUSTOM("KEY LIGHT FUNCTIONS", nullptr, _field_id_function_group_begin),
		{ _field_struct, "Key Light Functions", &hologramLightFunctions },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		FIELD_CUSTOM("FILL LIGHT FUNCTIONS", nullptr, _field_id_function_group_begin),
		{ _field_struct, "Fill Light Functions", &hologramLightFunctions },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		FIELD_CUSTOM("RIM LIGHT FUNCTIONS", nullptr, _field_id_function_group_begin),
		{ _field_struct, "Rim Light Functions", &hologramLightFunctions },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		hologramLightingBlock_block,
		"hologramLightingBlock",
		1,
		hologramLightingBlock_struct);

	#define HOLOGRAMLIGHTFUNCTIONS_ID { 0x8A259276, 0xAA5542A4, 0x8927B452, 0x0A50BEB1 }
	TAG_STRUCT(
		hologramLightFunctions,
		"hologramLightFunctions",
		"HologramLightFunctions",
		HOLOGRAMLIGHTFUNCTIONS_ID)
	{
		{ _field_string_id, "Intensity" },
		{ _field_string_id, "Forward" },
		{ _field_string_id, "Right" },
		{ _field_string_id, "Up" },
		{ _field_terminator }
	};

	#define HOLOGRAMLIGHTINGBLOCK_STRUCT_ID { 0xE3E332CA, 0xA5E44DFC, 0x81E9FCB6, 0x6198694A }
	TAG_STRUCT(
		hologramLightingBlock_struct,
		"hologramLightingBlock_struct",
		"HologramLighting",
		HOLOGRAMLIGHTINGBLOCK_STRUCT_ID)
	{
		FIELD_CUSTOM("HOLOGRAM", nullptr, _field_id_function_group_begin),
		FIELD_CUSTOM("Intensity", nullptr, _field_id_slider_editor),
		{ _field_real, "Intensity", _field_id_slider_editor },
		{ _field_real, "Intensity Input" },
		{ _field_char_enum, "Transparency Mode", &hologramTransparencyMode },
		FIELD_PAD("PADDING1", nullptr, 3),
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		FIELD_CUSTOM("KEY LIGHT", nullptr, _field_id_function_group_begin),
		{ _field_struct, "Key Light", &hologramLight },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		FIELD_CUSTOM("FILL LIGHT", nullptr, _field_id_function_group_begin),
		{ _field_struct, "Fill Light", &hologramLight },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		FIELD_CUSTOM("RIM LIGHT", nullptr, _field_id_function_group_begin),
		{ _field_struct, "Rim Light", &hologramLight },
		FIELD_CUSTOM(nullptr, nullptr, _field_id_function_group_end),
		{ _field_terminator }
	};

	#define HOLOGRAMLIGHT_ID { 0x3906DA32, 0xFC3C45A6, 0xADEDC284, 0x1B292C95 }
	TAG_STRUCT(
		hologramLight,
		"hologramLight",
		"HologramLight",
		HOLOGRAMLIGHT_ID)
	{
		FIELD_CUSTOM("Hologram Light", nullptr, _field_id_hologram_light),
		FIELD_CUSTOM("Direction", nullptr, _field_id_slider_editor),
		{ _field_real, "Direction", _field_id_slider_editor },
		FIELD_CUSTOM("Front-Back", nullptr, _field_id_slider_editor),
		{ _field_real, "Front-Back", _field_id_slider_editor },
		FIELD_CUSTOM("Intensity", nullptr, _field_id_slider_editor),
		{ _field_real, "Intensity", _field_id_slider_editor },
		{ _field_real, "Intensity Input" },
		{ _field_real, "Forward Input" },
		{ _field_real, "Right Input" },
		{ _field_real, "Up Input" },
		{ _field_terminator }
	};

	STRINGS(hologramTransparencyMode)
	{
		"cheap",
		"expensive"
	};
	STRING_LIST(hologramTransparencyMode, hologramTransparencyMode_strings, _countof(hologramTransparencyMode_strings));

} // namespace macaque

} // namespace blofeld

