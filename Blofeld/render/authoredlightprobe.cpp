#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(authored_light_probe_lights_block, 1)
{
	FIELD( _field_custom, "Authored Light Probe" ),
	FIELD( _field_custom, "Direction 1&Direction(D)" ),
	FIELD( _field_real, "Direction 1&Direction(D)" ),
	FIELD( _field_custom, "Front-Back 1&Front-Back(D)" ),
	FIELD( _field_real, "Front-Back 1&Front-Back(D)" ),
	FIELD( _field_real_rgb_color, "Direct color 1" ),
	FIELD( _field_custom, "Direct intensity 1" ),
	FIELD( _field_real, "Direct intensity 1" ),
	FIELD( _field_custom, "Direction 2&Direction(D)" ),
	FIELD( _field_real, "Direction 2&Direction(D)" ),
	FIELD( _field_custom, "Front-Back 2&Front-Back(D)" ),
	FIELD( _field_real, "Front-Back 2&Front-Back(D)" ),
	FIELD( _field_real_rgb_color, "Direct color 2" ),
	FIELD( _field_custom, "Direct intensity 2" ),
	FIELD( _field_real, "Direct intensity 2" ),
	FIELD( _field_custom, "Authored Light Probe Intensity Scale" ),
	FIELD( _field_real, "Authored Light Probe Intensity Scale" ),
	FIELD( _field_custom, "Generated Air Probe Intensity Scale" ),
	FIELD( _field_real, "Generated Air Probe Intensity Scale" ),
	FIELD( _field_terminator )
};

TAG_GROUP(authored_light_probe_block, AUTHORED_LIGHT_PROBE_TAG)
{
	FIELD( _field_explanation, "Character Lighting" ),
	FIELD( _field_block, "Lights*", &authored_light_probe_lights_block ),
	FIELD( _field_custom, "Authored Light Probe Intensity Scale!" ),
	FIELD( _field_real, "Authored Light Probe Intensity Scale!" ),
	FIELD( _field_custom, "Generated Air Probe Intensity Scale!" ),
	FIELD( _field_real, "Generated Air Probe Intensity Scale!" ),
	FIELD( _field_array, "raw sh data!" ),
	FIELD( _field_char_enum, "Is Camera-space" ),
	FIELD( _field_char_enum, "Apply to First Person Geometry" ),
	FIELD( _field_pad, "pdd", 2 ),
	FIELD( _field_explanation, "Object Shadows (all objects, not just characters)" ),
	FIELD( _field_custom, "IO Direct Lighting Minimum Percentage (When in Shadow)" ),
	FIELD( _field_real, "IO Direct Lighting Minimum Percentage (When in Shadow)" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

