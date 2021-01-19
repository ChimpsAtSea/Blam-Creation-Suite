#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		new_cinematic_lighting_group,
		NEW_CINEMATIC_LIGHTING_TAG,
		nullptr,
		INVALID_TAG,
		new_cinematic_lighting_block );

	TAG_BLOCK_FROM_STRUCT(
		new_cinematic_lighting_block,
		"new_cinematic_lighting_block",
		1,
		new_cinematic_lighting_struct_definition);

	#define CINEMATIC_DYNAMIC_LIGHT_BLOCK_ID { 0x6D9568FD, 0x448D4F36, 0x9C5940F5, 0x15B39D09 }
	TAG_BLOCK(
		cinematic_dynamic_light_block,
		"cinematic_dynamic_light_block",
		16,
		"s_cinematic_dynamic_light",
		CINEMATIC_DYNAMIC_LIGHT_BLOCK_ID)
	{
		{ _field_long_flags, "Flags", &cinematic_dynamic_light_flags },
		FIELD_CUSTOM("Dynamic Light", _custom_field_cinematic_dynamic_light),
		FIELD_CUSTOM("Direction", _custom_field_slider_editor),
		{ _field_real, "Direction", nullptr, 'sled' },
		FIELD_CUSTOM("Front-Back", _custom_field_slider_editor),
		{ _field_real, "Front-Back", nullptr, 'sled' },
		{ _field_real, "Distance:world units" },
		{ _field_tag_reference, "light", &global_light_definition_reference },
		{ _field_terminator }
	};

	#define NEW_CINEMATIC_LIGHTING_STRUCT_DEFINITION_ID { 0x6E8A26A1, 0xE0954B7C, 0xA1044895, 0x5B59B00D }
	TAG_STRUCT(
		new_cinematic_lighting_struct_definition,
		"new_cinematic_lighting_struct_definition",
		"s_cinematic_lighting",
		NEW_CINEMATIC_LIGHTING_STRUCT_DEFINITION_ID)
	{
		FIELD_CUSTOM("Cinematic Lighting", _custom_field_function_group_begin),
		FIELD_CUSTOM("Cinema Lighting", _custom_field_cinematic_version),
		{ _field_long_integer, "version!" },
		FIELD_CUSTOM("Direction&Direction(D)", _custom_field_slider_editor),
		{ _field_real, "Direction&Direction(D)", nullptr, 'sled' },
		FIELD_CUSTOM("Front-Back&Front-Back(D)", _custom_field_slider_editor),
		{ _field_real, "Front-Back&Front-Back(D)", nullptr, 'sled' },
		FIELD_CUSTOM("Shadow Interpolation", _custom_field_slider_editor),
		{ _field_real, "Shadow Interpolation", nullptr, 'sled' },
		FIELD_CUSTOM("Overall weight", _custom_field_slider_editor),
		{ _field_real, "Overall weight", nullptr, 'sled' },
		FIELD_CUSTOM("Direct weight", _custom_field_slider_editor),
		{ _field_real, "Direct weight", nullptr, 'sled' },
		FIELD_CUSTOM("Indirect weight", _custom_field_slider_editor),
		{ _field_real, "Indirect weight", nullptr, 'sled' },
		FIELD_CUSTOM("Airprobe weight", _custom_field_slider_editor),
		{ _field_real, "Airprobe weight", nullptr, 'sled' },
		FIELD_CUSTOM("Sun weight", _custom_field_slider_editor),
		{ _field_real, "Sun weight", nullptr, 'sled' },
		{ _field_real_rgb_color, "Direct color" },
		FIELD_CUSTOM("Direct intensity", _custom_field_slider_editor),
		{ _field_real, "Direct intensity", nullptr, 'sled' },
		{ _field_real_rgb_color, "Indirect color" },
		FIELD_CUSTOM("Indirect intensity", _custom_field_slider_editor),
		{ _field_real, "Indirect intensity", nullptr, 'sled' },
		FIELD_CUSTOM("Interpolation", _custom_field_slider_editor),
		{ _field_real, "Interpolation", nullptr, 'sled' },
		FIELD_CUSTOM(nullptr, _custom_field_function_group_end),
		{ _field_block, "Authored Light Probe", &authored_light_probe_block },
		{ _field_block, "Cortana Lighting", &hologramLightingBlock_block },
		{ _field_block, "dynamic lights!", &cinematic_dynamic_light_block },
		{ _field_terminator }
	};

	STRINGS(cinematic_dynamic_light_flags)
	{
		"debug this light",
		"follow object",
		"position at marker"
	};
	STRING_LIST(cinematic_dynamic_light_flags, cinematic_dynamic_light_flags_strings, _countof(cinematic_dynamic_light_flags_strings));

	TAG_REFERENCE(global_new_cinematic_lighting_reference, NEW_CINEMATIC_LIGHTING_TAG);

	TAG_REFERENCE(global_light_definition_reference, LIGHT_TAG);

} // namespace macaque

} // namespace blofeld

