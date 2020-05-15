#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(cinematic_dynamic_light, 16)
{
	FIELD( _field_long_flags, "Flags" ),
	FIELD( _field_custom, "Dynamic Light" ),
	FIELD( _field_custom, "Direction" ),
	FIELD( _field_real, "Direction" ),
	FIELD( _field_custom, "Front-Back" ),
	FIELD( _field_real, "Front-Back" ),
	FIELD( _field_real, "Distance:world units" ),
	FIELD( _field_tag_reference, "light" ),
	FIELD( _field_terminator )
};

TAG_GROUP(new_cinematic_lighting, NEW_CINEMATIC_LIGHTING_TAG)
{
	FIELD( _field_custom, "Cinematic Lighting" ),
	FIELD( _field_custom, "Cinema Lighting" ),
	FIELD( _field_long_integer, "version!" ),
	FIELD( _field_custom, "Direction&Direction(D)" ),
	FIELD( _field_real, "Direction&Direction(D)" ),
	FIELD( _field_custom, "Front-Back&Front-Back(D)" ),
	FIELD( _field_real, "Front-Back&Front-Back(D)" ),
	FIELD( _field_custom, "Shadow Interpolation" ),
	FIELD( _field_real, "Shadow Interpolation" ),
	FIELD( _field_custom, "Overall weight" ),
	FIELD( _field_real, "Overall weight" ),
	FIELD( _field_custom, "Direct weight" ),
	FIELD( _field_real, "Direct weight" ),
	FIELD( _field_custom, "Indirect weight" ),
	FIELD( _field_real, "Indirect weight" ),
	FIELD( _field_custom, "Airprobe weight" ),
	FIELD( _field_real, "Airprobe weight" ),
	FIELD( _field_custom, "Sun weight" ),
	FIELD( _field_real, "Sun weight" ),
	FIELD( _field_real_rgb_color, "Direct color" ),
	FIELD( _field_custom, "Direct intensity" ),
	FIELD( _field_real, "Direct intensity" ),
	FIELD( _field_real_rgb_color, "Indirect color" ),
	FIELD( _field_custom, "Indirect intensity" ),
	FIELD( _field_real, "Indirect intensity" ),
	FIELD( _field_custom, "Interpolation" ),
	FIELD( _field_real, "Interpolation" ),
	FIELD( _field_custom ),
	FIELD( _field_block, "Authored Light Probe", &authored_light_probe_block ),
	FIELD( _field_block, "Cortana Lighting", &hologramLightingBlock_block ),
	FIELD( _field_block, "dynamic lights!", &cinematic_dynamic_light_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

