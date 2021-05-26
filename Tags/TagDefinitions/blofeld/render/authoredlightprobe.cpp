#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	#define AUTHORED_LIGHT_PROBE_STRUCT_DEFINITION_ID { 0x6156E0EA, 0x199B52E8, 0x6AFCC92D, 0xD2FFEBEB }
	TAG_BLOCK(
		authored_light_probe_block,
		"authored_light_probe_block",
		1,
		"AuthoredLightProbe",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | 
		SET_POSTPROCESS_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		AUTHORED_LIGHT_PROBE_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("Character Lighting", nullptr, FIELD_FLAG_NONE, "\n"),
		{ _field_block, "Lights", FIELD_FLAG_READ_ONLY, &authored_light_probe_lights_block },
		FIELD_CUSTOM("Authored Light Probe Intensity Scale", nullptr, FIELD_FLAG_UNKNOWN0, _field_id_slider_editor),
		{ _field_real, "Authored Light Probe Intensity Scale", FIELD_FLAG_UNKNOWN0, _field_id_slider_editor },
		FIELD_CUSTOM("Generated Air Probe Intensity Scale", nullptr, FIELD_FLAG_UNKNOWN0, _field_id_slider_editor),
		{ _field_real, "Generated Air Probe Intensity Scale", FIELD_FLAG_UNKNOWN0, _field_id_slider_editor },
		{ _field_array, "raw sh data", FIELD_FLAG_UNKNOWN0, &real_rgb_lightprobe_array },
		{ _field_char_enum, "Is Camera-space", &midnight_boolean_enum_definition },
		{ _field_char_enum, "Apply to First Person Geometry", &midnight_boolean_enum_definition },
		FIELD_PAD("pdd", nullptr, FIELD_FLAG_NONE, 2),
		FIELD_EXPLANATION("Object Shadows (all objects, not just characters)", nullptr, FIELD_FLAG_NONE, "\n"),
		FIELD_CUSTOM("IO Direct Lighting Minimum Percentage (When in Shadow)", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "IO Direct Lighting Minimum Percentage (When in Shadow)", _field_id_slider_editor },
		{ _field_terminator }
	};

	TAG_GROUP(
		authored_light_probe_group,
		AUTHORED_LIGHT_PROBE_TAG,
		nullptr,
		INVALID_TAG,
		authored_light_probe_block );

	#define AUTHORED_LIGHT_PROBE_LIGHTS_BLOCK_ID { 0xC2EA80AD, 0xE1B9C6AD, 0x667ED3BE, 0x79A6A3FF }
	TAG_BLOCK(
		authored_light_probe_lights_block,
		"authored_light_probe_lights_block",
		1,
		"AuthoredLightProbeLights",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		AUTHORED_LIGHT_PROBE_LIGHTS_BLOCK_ID)
	{
		FIELD_CUSTOM("Authored Light Probe", nullptr, FIELD_FLAG_NONE, _field_id_authored_light_probe),
		FIELD_CUSTOM("Direction 1&Direction(D)", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Direction 1&Direction(D)", _field_id_slider_editor },
		FIELD_CUSTOM("Front-Back 1&Front-Back(D)", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Front-Back 1&Front-Back(D)", _field_id_slider_editor },
		{ _field_real_rgb_color, "Direct color 1" },
		FIELD_CUSTOM("Direct intensity 1", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Direct intensity 1", _field_id_slider_editor },
		FIELD_CUSTOM("Direction 2&Direction(D)", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Direction 2&Direction(D)", _field_id_slider_editor },
		FIELD_CUSTOM("Front-Back 2&Front-Back(D)", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Front-Back 2&Front-Back(D)", _field_id_slider_editor },
		{ _field_real_rgb_color, "Direct color 2" },
		FIELD_CUSTOM("Direct intensity 2", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Direct intensity 2", _field_id_slider_editor },
		FIELD_CUSTOM("Authored Light Probe Intensity Scale", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Authored Light Probe Intensity Scale", _field_id_slider_editor },
		FIELD_CUSTOM("Generated Air Probe Intensity Scale", nullptr, FIELD_FLAG_NONE, _field_id_slider_editor),
		{ _field_real, "Generated Air Probe Intensity Scale", _field_id_slider_editor },
		{ _field_terminator }
	};

	#define REAL_RGB_LIGHTPROBE_ARRAY_ID { 0xE8F85914, 0xE49BA421, 0x1216AB74, 0x0B6D7111 }
	TAG_ARRAY(
		real_rgb_lightprobe_array,
		"real_rgb_lightprobe_array",
		((3)*(3)) * 3,
		"real",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		REAL_RGB_LIGHTPROBE_ARRAY_ID)
	{
		{ _field_real, "sh data" },
		{ _field_terminator }
	};

	TAG_REFERENCE(AuthoredLightProbeReference, AUTHORED_LIGHT_PROBE_TAG);



} // namespace blofeld

