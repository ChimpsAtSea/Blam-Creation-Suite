#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(cinematic_dynamic_light, 16)
{
	{ _field_long_flags, "Flags" },
	{ _field_custom, "Dynamic Light" },
	{ _field_custom, "Direction" },
	{ _field_real, "Direction" },
	{ _field_custom, "Front-Back" },
	{ _field_real, "Front-Back" },
	{ _field_real, "Distance:world units" },
	{ _field_tag_reference, "light" },
	{ _field_terminator },
};

TAG_GROUP(new_cinematic_lighting, NEW_CINEMATIC_LIGHTING_TAG)
{
	{ _field_custom, "Cinematic Lighting" },
	{ _field_custom, "Cinema Lighting" },
	{ _field_long_integer, "version!" },
	{ _field_custom, "Direction&Direction(D)" },
	{ _field_real, "Direction&Direction(D)" },
	{ _field_custom, "Front-Back&Front-Back(D)" },
	{ _field_real, "Front-Back&Front-Back(D)" },
	{ _field_custom, "Shadow Interpolation" },
	{ _field_real, "Shadow Interpolation" },
	{ _field_custom, "Overall weight" },
	{ _field_real, "Overall weight" },
	{ _field_custom, "Direct weight" },
	{ _field_real, "Direct weight" },
	{ _field_custom, "Indirect weight" },
	{ _field_real, "Indirect weight" },
	{ _field_custom, "Airprobe weight" },
	{ _field_real, "Airprobe weight" },
	{ _field_custom, "Sun weight" },
	{ _field_real, "Sun weight" },
	{ _field_real_rgb_color, "Direct color" },
	{ _field_custom, "Direct intensity" },
	{ _field_real, "Direct intensity" },
	{ _field_real_rgb_color, "Indirect color" },
	{ _field_custom, "Indirect intensity" },
	{ _field_real, "Indirect intensity" },
	{ _field_custom, "Interpolation" },
	{ _field_real, "Interpolation" },
	{ _field_custom },
	{ _field_block, "Authored Light Probe", &authored_light_probe_block },
	{ _field_block, "Cortana Lighting", &hologramLightingBlock_block },
	{ _field_block, "dynamic lights!", &cinematic_dynamic_light_block },
	{ _field_terminator },
};

} // namespace blofeld

