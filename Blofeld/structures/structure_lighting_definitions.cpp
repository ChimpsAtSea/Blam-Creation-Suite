#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(scenario_structure_lighting_info, SCENARIO_STRUCTURE_LIGHTING_INFO_TAG, scenario_structure_lighting_info_block_block )

TAG_BLOCK_FROM_STRUCT(scenario_structure_lighting_info_block, 1, scenario_structure_lighting_info_struct_definition_struct_definition );

TAG_BLOCK(structure_lighting_generic_light_definition_block, SHORT_MAX)
{
	FIELD( _field_int64_integer, "Definition Identifier!" ),
	FIELD( _field_struct, "Midnight_Light_Parameters", &midnight_light_struct_struct_definition ),
	FIELD( _field_long_integer, "Source File Identifier!" ),
	FIELD( _field_explanation, "Static Only Parameters" ),
	FIELD( _field_real, "indirect amplification factor" ),
	FIELD( _field_real, "jitter sphere radius" ),
	FIELD( _field_real, "jitter angle" ),
	FIELD( _field_enum, "jitter quality" ),
	FIELD( _field_char_enum, "sun" ),
	FIELD( _field_char_enum, "indirect only" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_char_enum, "static analytic" ),
	FIELD( _field_pad, "pdd", 3 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(structure_lighting_generic_light_instance_block, SHORT_MAX)
{
	FIELD( _field_int64_integer, "Light Definition ID!" ),
	FIELD( _field_int64_integer, "Light Instance ID!" ),
	FIELD( _field_long_integer, "Light Definition Index!" ),
	FIELD( _field_long_integer, "Maya Source Hash!" ),
	FIELD( _field_tag_reference, "runtime definition!" ),
	FIELD( _field_long_enum, "light mode" ),
	FIELD( _field_real_point_3d, "origin" ),
	FIELD( _field_real_vector_3d, "forward" ),
	FIELD( _field_real_vector_3d, "up" ),
	FIELD( _field_real, "fade out distance" ),
	FIELD( _field_real, "fade start distance" ),
	FIELD( _field_long_integer, "Shadow Geometry Checksum" ),
	FIELD( _field_pad, "pdd", 4 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(screen_space_light_shader_override_block, SHORT_MAX)
{
	FIELD( _field_real_rgb_color, "specular color normal" ),
	FIELD( _field_real, "specular steepness" ),
	FIELD( _field_real_rgb_color, "specular color gazing" ),
	FIELD( _field_real, "specular coeff" ),
	FIELD( _field_real, "diffuse coeff" ),
	FIELD( _field_real, "roughness offset" ),
	FIELD( _field_real, "albedo blend" ),
	FIELD( _field_terminator )
};

TAG_BLOCK_FROM_STRUCT(structureLightingCinematicLightInstanceBlock, SHORT_MAX, structureLightingCinematicLightInstanceBlock_struct_struct_definition );

TAG_BLOCK(structureLightingCinematicObjectBlock, SHORT_MAX)
{
	FIELD( _field_string_id, "name" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(scenario_structure_lighting_info_struct_definition)
{
	FIELD( _field_long_integer, "import info checksum" ),
	FIELD( _field_block, "generic light definitions", &structure_lighting_generic_light_definition_block_block ),
	FIELD( _field_block, "generic light instances", &structure_lighting_generic_light_instance_block_block ),
	FIELD( _field_block, "screen space light shader override", &screen_space_light_shader_override_block_block ),
	FIELD( _field_block, "cinematic light instances", &structureLightingCinematicLightInstanceBlock_block ),
	FIELD( _field_struct, "Sun Intensity Multiplier", &light_scalar_function_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(structureLightingCinematicLightInstanceBlock_struct)
{
	FIELD( _field_int64_integer, "Light Instance ID!" ),
	FIELD( _field_long_block_index, "Light Definition Index" ),
	FIELD( _field_long_block_index, "Light Instance Index" ),
	FIELD( _field_array, "Active Shots" ),
	FIELD( _field_block, "Linked Objects", &structureLightingCinematicObjectBlock_block ),
	FIELD( _field_pad, "padding", 4 ),
	FIELD( _field_terminator )
};

} // namespace blofeld

