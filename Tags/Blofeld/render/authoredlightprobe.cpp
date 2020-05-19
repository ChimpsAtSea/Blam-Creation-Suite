#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP(authored_light_probe, AUTHORED_LIGHT_PROBE_TAG)
	{
		{ _field_explanation, "Character Lighting" },
		{ _field_block, "Lights*", &authored_light_probe_lights_block_block },
		{ _field_custom, "Authored Light Probe Intensity Scale!" },
		{ _field_real, "Authored Light Probe Intensity Scale!" },
		{ _field_custom, "Generated Air Probe Intensity Scale!" },
		{ _field_real, "Generated Air Probe Intensity Scale!" },
		{ _field_array, "raw sh data!", &real_rgb_lightprobe_array_array },
		{ _field_char_enum, "Is Camera-space", &midnight_boolean_enum_definition },
		{ _field_char_enum, "Apply to First Person Geometry", &midnight_boolean_enum_definition },
		{ _field_pad, "pdd", 2 },
		{ _field_explanation, "Object Shadows (all objects, not just characters)" },
		{ _field_custom, "IO Direct Lighting Minimum Percentage (When in Shadow)" },
		{ _field_real, "IO Direct Lighting Minimum Percentage (When in Shadow)" },
		{ _field_terminator }
	};

	TAG_BLOCK(authored_light_probe_lights_block, 1)
	{
		{ _field_custom, "Authored Light Probe" },
		{ _field_custom, "Direction 1&Direction(D)" },
		{ _field_real, "Direction 1&Direction(D)" },
		{ _field_custom, "Front-Back 1&Front-Back(D)" },
		{ _field_real, "Front-Back 1&Front-Back(D)" },
		{ _field_real_rgb_color, "Direct color 1" },
		{ _field_custom, "Direct intensity 1" },
		{ _field_real, "Direct intensity 1" },
		{ _field_custom, "Direction 2&Direction(D)" },
		{ _field_real, "Direction 2&Direction(D)" },
		{ _field_custom, "Front-Back 2&Front-Back(D)" },
		{ _field_real, "Front-Back 2&Front-Back(D)" },
		{ _field_real_rgb_color, "Direct color 2" },
		{ _field_custom, "Direct intensity 2" },
		{ _field_real, "Direct intensity 2" },
		{ _field_custom, "Authored Light Probe Intensity Scale" },
		{ _field_real, "Authored Light Probe Intensity Scale" },
		{ _field_custom, "Generated Air Probe Intensity Scale" },
		{ _field_real, "Generated Air Probe Intensity Scale" },
		{ _field_terminator }
	};

	TAG_ARRAY(real_rgb_lightprobe_array, ((3)*(3)) * 3)
	{
		{ _field_real, "sh data" },
		{ _field_terminator }
	};

	TAG_REFERENCE(AuthoredLightProbeReference, AUTHORED_LIGHT_PROBE_TAG);

} // namespace blofeld

