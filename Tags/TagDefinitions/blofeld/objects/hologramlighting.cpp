#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define HOLOGRAMLIGHTINGGLOBALSBLOCK_ID { 0x8E264B3B, 0x9FD14745, 0x83BCD78E, 0x9FBB73AC }
	TAG_BLOCK(
		hologramLightingGlobalsBlock_block,
		"hologramLightingGlobalsBlock",
		1,
		"HologramLightingGlobals",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		HOLOGRAMLIGHTINGGLOBALSBLOCK_ID)
	{
		FIELD_CUSTOM_EX("HOLOGRAM FUNCTIONS", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_string_id, "Intensity" },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM_EX("KEY LIGHT FUNCTIONS", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "Key Light Functions", &hologramLightFunctions },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM_EX("FILL LIGHT FUNCTIONS", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "Fill Light Functions", &hologramLightFunctions },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM_EX("RIM LIGHT FUNCTIONS", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "Rim Light Functions", &hologramLightFunctions },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(
		hologramLightingBlock_block,
		"hologramLightingBlock",
		1,
		hologramLightingBlock_struct);

	#define HOLOGRAMLIGHTFUNCTIONS_ID { 0x8A259276, 0xAA5542A4, 0x8927B452, 0x0A50BEB1 }
	TAG_STRUCT_V6(
		hologramLightFunctions,
		"hologramLightFunctions",
		"HologramLightFunctions",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		HOLOGRAMLIGHTFUNCTIONS_ID)
	{
		{ _field_string_id, "Intensity" },
		{ _field_string_id, "Forward" },
		{ _field_string_id, "Right" },
		{ _field_string_id, "Up" },
		{ _field_terminator }
	};

	#define HOLOGRAMLIGHTINGBLOCK_STRUCT_ID { 0xE3E332CA, 0xA5E44DFC, 0x81E9FCB6, 0x6198694A }
	TAG_STRUCT_V6(
		hologramLightingBlock_struct,
		"hologramLightingBlock_struct",
		"HologramLighting",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		HOLOGRAMLIGHTINGBLOCK_STRUCT_ID)
	{
		FIELD_CUSTOM_EX("HOLOGRAM", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_CUSTOM_EX("Intensity", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Intensity", _field_id_slider_editor },
		{ _field_real, "Intensity Input", FIELD_FLAG_UNKNOWN0 },
		{ _field_char_enum, "Transparency Mode", &hologramTransparencyMode },
		FIELD_PAD_EX("PADDING1", nullptr, FIELD_FLAG_NONE, 3),
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM_EX("KEY LIGHT", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "Key Light", &hologramLight },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM_EX("FILL LIGHT", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "Fill Light", &hologramLight },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM_EX("RIM LIGHT", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "Rim Light", &hologramLight },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define HOLOGRAMLIGHT_ID { 0x3906DA32, 0xFC3C45A6, 0xADEDC284, 0x1B292C95 }
	TAG_STRUCT_V6(
		hologramLight,
		"hologramLight",
		"HologramLight",
		SET_POSTPROCESS_RECURSIVELY | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		HOLOGRAMLIGHT_ID)
	{
		FIELD_CUSTOM_EX("Hologram Light", nullptr, FIELD_FLAG_NONE, _field_id_hologram_light),
		FIELD_CUSTOM_EX("Direction", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Direction", _field_id_slider_editor },
		FIELD_CUSTOM_EX("Front-Back", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Front-Back", _field_id_slider_editor },
		FIELD_CUSTOM_EX("Intensity", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Intensity", _field_id_slider_editor },
		{ _field_real, "Intensity Input", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "Forward Input", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "Right Input", FIELD_FLAG_UNKNOWN0 },
		{ _field_real, "Up Input", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	STRINGS(hologramTransparencyMode)
	{
		"cheap",
		"expensive"
	};
	STRING_LIST(hologramTransparencyMode, hologramTransparencyMode_strings, _countof(hologramTransparencyMode_strings));



} // namespace blofeld

