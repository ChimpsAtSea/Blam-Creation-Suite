#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(structure_lighting_generic_light_definition, SHORT_MAX)
{
	{ _field_int64_integer, "Definition Identifier!" },
	{ _field_struct, "Midnight_Light_Parameters" },
	{ _field_long_integer, "Source File Identifier!" },
	{ _field_explanation, "Static Only Parameters" },
	{ _field_real, "indirect amplification factor" },
	{ _field_real, "jitter sphere radius" },
	{ _field_real, "jitter angle" },
	{ _field_enum, "jitter quality" },
	{ _field_char_enum, "sun" },
	{ _field_char_enum, "indirect only" },
	{ _field_long_flags, "flags" },
	{ _field_char_enum, "static analytic" },
	{ _field_pad, "pdd", 3 },
	{ _field_terminator },
};

TAG_BLOCK(structure_lighting_generic_light_instance, SHORT_MAX)
{
	{ _field_int64_integer, "Light Definition ID!" },
	{ _field_int64_integer, "Light Instance ID!" },
	{ _field_long_integer, "Light Definition Index!" },
	{ _field_long_integer, "Maya Source Hash!" },
	{ _field_tag_reference, "runtime definition!" },
	{ _field_long_enum, "light mode" },
	{ _field_real_point_3d, "origin" },
	{ _field_real_vector_3d, "forward" },
	{ _field_real_vector_3d, "up" },
	{ _field_real, "fade out distance" },
	{ _field_real, "fade start distance" },
	{ _field_long_integer, "Shadow Geometry Checksum" },
	{ _field_pad, "pdd", 4 },
	{ _field_terminator },
};

TAG_BLOCK(screen_space_light_shader_override, SHORT_MAX)
{
	{ _field_real_rgb_color, "specular color normal" },
	{ _field_real, "specular steepness" },
	{ _field_real_rgb_color, "specular color gazing" },
	{ _field_real, "specular coeff" },
	{ _field_real, "diffuse coeff" },
	{ _field_real, "roughness offset" },
	{ _field_real, "albedo blend" },
	{ _field_terminator },
};

TAG_BLOCK(structureLightingCinematicLightInstanceBlock, SHORT_MAX)
{
	{ _field_int64_integer, "Light Instance ID!" },
	{ _field_long_block_index, "Light Definition Index" },
	{ _field_long_block_index, "Light Instance Index" },
	{ _field_array, "Active Shots" },
	{ _field_block, "Linked Objects", &structureLightingCinematicObjectBlock_block },
	{ _field_pad, "padding", 4 },
	{ _field_terminator },
};

TAG_BLOCK(structureLightingCinematicObjectBlock, SHORT_MAX)
{
	{ _field_string_id, "name" },
	{ _field_terminator },
};

TAG_GROUP(scenario_structure_lighting_info, SCENARIO_STRUCTURE_LIGHTING_INFO_TAG)
{
	{ _field_long_integer, "import info checksum" },
	{ _field_block, "generic light definitions", &structure_lighting_generic_light_definition_block },
	{ _field_block, "generic light instances", &structure_lighting_generic_light_instance_block },
	{ _field_block, "screen space light shader override", &screen_space_light_shader_override_block },
	{ _field_block, "cinematic light instances", &structureLightingCinematicLightInstanceBlock_block },
	{ _field_struct, "Sun Intensity Multiplier" },
	{ _field_terminator },
};

} // namespace blofeld

