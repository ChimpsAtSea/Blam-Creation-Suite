#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(lightmap_model_globals_struct_definition)
{
	FIELD( _field_block, "Lightmapped Models", &lightmap_model_reference_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(lightmapper_globals_struct_definition)
{
	FIELD( _field_long_integer, "Version!" ),
	FIELD( _field_custom, "GLOBAL QUALITY SETTINGS" ),
	FIELD( _field_struct, "Global lightmapper settings", &global_lightmap_global_settings_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "LOCAL SETTINGS" ),
	FIELD( _field_struct, "Local lightmapper settings", &global_lightmap_local_settings_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(global_lightmap_global_settings_struct)
{
	FIELD( _field_long_flags, "Global flags" ),
	FIELD( _field_long_enum, "Mode" ),
	FIELD( _field_long_enum, "Hemicube resolution" ),
	FIELD( _field_long_enum, "DXT compression quality" ),
	FIELD( _field_long_enum, "Indirect quality" ),
	FIELD( _field_long_enum, "Direct shadow map resolution" ),
	FIELD( _field_long_enum, "Super-sampling factor" ),
	FIELD( _field_long_enum, "AO Sample Quality" ),
	FIELD( _field_real_vector_3d, "Indirect Restrict AABB Min!" ),
	FIELD( _field_real_vector_3d, "Indirect Restrict AABB Max!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(global_lightmap_local_settings_struct)
{
	FIELD( _field_long_flags, "Local flags" ),
	FIELD( _field_real, "Skydome amplification factor" ),
	FIELD( _field_real, "Indirect amplification factor" ),
	FIELD( _field_real, "Lightmap Compression Maximum" ),
	FIELD( _field_real, "Per Vertex AO Auto Threshold" ),
	FIELD( _field_custom, "Ambient occlusion settings" ),
	FIELD( _field_struct, "AO settings", &global_lightmap_ao_settings_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Global illumination falloff settings" ),
	FIELD( _field_struct, "Global illumination falloff settings", &global_lightmap_global_illumination_falloff_settings_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Quality Overrides" ),
	FIELD( _field_struct, "Local lightmapper override settings", &global_lightmap_local_override_settings_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_long_enum, "Forge Lightmap Size Class (if enabled)" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(global_lightmap_ao_settings_struct)
{
	FIELD( _field_real, "Radius{Offset}" ),
	FIELD( _field_real, "Falloff Power" ),
	FIELD( _field_real, "Multiplier" ),
	FIELD( _field_real, "MaxThreadCount" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(global_lightmap_global_illumination_falloff_settings_struct)
{
	FIELD( _field_real, "Falloff Begin" ),
	FIELD( _field_real, "Falloff End" ),
	FIELD( _field_real_rgb_color, "Far Lighting Color" ),
	FIELD( _field_real, "Far Lighting Scalar" ),
	FIELD( _field_tag_reference, "Far Lighting Texture" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(global_lightmap_local_override_settings_struct)
{
	FIELD( _field_long_integer, "High Quality Average Jitter Samples" ),
	FIELD( _field_long_integer, "Per Vertex Supersample Count" ),
	FIELD( _field_long_integer, "Indirect Quality Offset" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(lightmap_model_reference_block, SHORT_MAX)
{
	FIELD( _field_tag_reference, "Model Reference" ),
	FIELD( _field_terminator )
};

TAG_GROUP(lightmap_model_globals_block, LIGHTMAP_MODEL_GLOBALS_TAG)
{
	FIELD( _field_block, "Lightmapped Models", &lightmap_model_reference_block ),
	FIELD( _field_terminator )
};

TAG_GROUP(lightmapper_globals_block, LIGHTMAPPER_GLOBALS_TAG)
{
	FIELD( _field_long_integer, "Version!" ),
	FIELD( _field_custom, "GLOBAL QUALITY SETTINGS" ),
	FIELD( _field_struct, "Global lightmapper settings", &global_lightmap_global_settings_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "LOCAL SETTINGS" ),
	FIELD( _field_struct, "Local lightmapper settings", &global_lightmap_local_settings_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

