#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		atmosphere_globals_group,
		ATMOSPHERE_GLOBALS_TAG,
		nullptr,
		INVALID_TAG,
		atmosphere_globals_block );

	TAG_BLOCK_FROM_STRUCT(
		atmosphere_globals_block,
		"atmosphere_globals_block",
		1,
		atmosphere_globals_struct_definition);

	#define UNDERWATER_SETTING_BLOCK_ID { 0x48C345A4, 0xB5F0449A, 0xAA54D20B, 0x1295444A }
	TAG_BLOCK(
		underwater_setting_block,
		"underwater_setting_block",
		k_max_atmosphere_settings,
		"s_underwater_setting",
		UNDERWATER_SETTING_BLOCK_ID)
	{
		{ _field_string_id, "Name" },
		{ _field_real, "Murkiness" },
		{ _field_real_rgb_color, "Fog Color" },
		{ _field_terminator }
	};

	#define ATMOSPHERE_GLOBALS_STRUCT_DEFINITION_ID { 0x3EBF8816, 0xC94C4915, 0xB3C990D2, 0x7039F615 }
	TAG_STRUCT(
		atmosphere_globals_struct_definition,
		"atmosphere_globals_struct_definition",
		"s_atmosphere_globals",
		ATMOSPHERE_GLOBALS_STRUCT_DEFINITION_ID)
	{
		{ _field_explanation, "Patchy Fog Global Parameters", "Fog Bitmap................Noise texture to use on the screen-aligned sheets of fog\nTexture repeat rate.......Scaling factor to apply to fog UV coordinates\nDistance between sheets...Separating distance between sheets of fog\nDepth fade factor.........Lower values (approaching 0) cause a smoother fade at scene boundaries. Larger values (1 or more) make for a sharp transition\n\nFalloff start distance....Distance (in world units) at which to begin fading out patchy fog (default: 5)\nDistance falloff power....Rate at which to begin attenuating patchy fog settings (default: 2)\nTransparent sort distance..Distance from the camera where we sort the patchy fog effect (default: 100)\nwind strength across distance..Multiplies the wind strength based upon distance from player\n\n" },
		{ _field_tag_reference, "Fog Bitmap", &global_bitmap_reference },
		{ _field_real, "Texture repeat rate" },
		{ _field_real, "Distance between sheets" },
		{ _field_real, "Depth fade factor" },
		{ _field_real, "Transparent sort distance" },
		{ _field_char_enum, "Transparent sort layer", &global_sort_layer_enum_defintion },
		FIELD_PAD("UNdfdfdSED", nullptr, 3),
		{ _field_struct, "wind strength across distance", &scalar_function_named_struct_default_one },
		{ _field_block, "underwater settings", &underwater_setting_block },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_atmosphere_globals_reference, ATMOSPHERE_GLOBALS_TAG);

} // namespace macaque

} // namespace blofeld

