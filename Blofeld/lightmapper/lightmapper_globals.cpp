#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(lightmap_mode_enum, 3)
	{
		OPTION("Direct only"),
		OPTION("One bounce"),
		OPTION("Two bounce"),
	};

	TAG_ENUM(lightmap_hemicube_resolution_enum, 6)
	{
		OPTION("64 x 64"),
		OPTION("128 x 128"),
		OPTION("256 x 256"),
		OPTION("512 x 512"),
		OPTION("32 x 32"),
		OPTION("16 x 16"),
	};

	TAG_ENUM(lightmap_ao_quality_enum, 4)
	{
		OPTION("Off"),
		OPTION("1x"),
		OPTION("2x"),
		OPTION("4x"),
	};

	TAG_ENUM(lightmap_dxt_quality_enum, 2)
	{
		OPTION("Draft"),
		OPTION("High"),
	};

	TAG_ENUM(lightmap_indirect_quality_enum, 4)
	{
		OPTION("Low"),
		OPTION("Medium"),
		OPTION("High"),
		OPTION("Very High"),
	};

	TAG_ENUM(lightmap_direct_shadow_map_resolution_enum, 3)
	{
		OPTION("1X"),
		OPTION("2X"),
		OPTION("4X"),
	};

	TAG_ENUM(lightmap_supersampling_factor_enum, 4)
	{
		OPTION("1X"),
		OPTION("2X"),
		OPTION("4X"),
		OPTION("8X"),
	};

	TAG_ENUM(lightmap_local_flags, 27)
	{
		OPTION("Enable floating shadows"),
		OPTION("Replace sun with brightest directional"),
		OPTION("Use legacy magic light scalars"),
		OPTION("Remove lights outside target bsp"),
		OPTION("Include Skydome"),
		OPTION("Include Sun"),
		OPTION("Perform bad pixel analysis"),
		OPTION("Enable AO"),
		OPTION("Generate New AO"),
		OPTION("Ignore sun solid angle"),
		OPTION("Override AO only"),
		OPTION("Perform analysis"),
		OPTION("Global Illumination Falloff"),
		OPTION("Generate BVH AO (GPU) "),
		OPTION("Generate BVH AO (CPU) "),
		OPTION("Build packing lightmaps (for lighting forge objects)"),
		OPTION("Attempt to Use Diffuse UVs"),
		OPTION("Corrected Light Linking"),
		OPTION("Burn simplified irradiance lighting"),
		OPTION("Disable Floating Shadow Geometry"),
		OPTION("Disable Hybrid Refinement"),
		OPTION("Burn Probe AO Lighting"),
		OPTION("Opt Out Per-Vertex Lighting Fix"),
		OPTION("Generate Adjacent Bounce Info"),
		OPTION("No Shadow No AO Fix"),
		OPTION("Allow Spot Suns"),
		OPTION("Probes Ignore Shadow Linking"),
	};

	TAG_ENUM(lightmap_global_flags, 12)
	{
		OPTION("Force draft lighting"),
		OPTION("Perform sun multisampling"),
		OPTION("Perform sky multisampling"),
		OPTION("Use high resolution point shadows"),
		OPTION("Use new atlaser"),
		OPTION("Use high quality packing"),
		OPTION("Include geometry from adjacent bsps"),
		OPTION("Use 32-bit precision for direct pass"),
		OPTION("Enable subsampling indirect acceleration"),
		OPTION("Restrict lightmap samples to Maya regions"),
		OPTION("Perform Repack"),
		OPTION("Is Farm Burn"),
	};

	TAG_GROUP_FROM_BLOCK(lightmap_model_globals, LIGHTMAP_MODEL_GLOBALS_TAG, lightmap_model_globals_block_block );

	TAG_GROUP_FROM_BLOCK(lightmapper_globals, LIGHTMAPPER_GLOBALS_TAG, lightmapper_globals_block_block );

	TAG_BLOCK_FROM_STRUCT(lightmap_model_globals_block, 1, lightmap_model_globals_struct_definition_struct_definition );

	TAG_BLOCK_FROM_STRUCT(lightmapper_globals_block, 1, lightmapper_globals_struct_definition_struct_definition );

	TAG_BLOCK(lightmap_model_reference_block, SHORT_MAX)
	{
		FIELD( _field_tag_reference, "Model Reference" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(lightmap_model_globals_struct_definition)
{
		FIELD( _field_block, "Lightmapped Models", &lightmap_model_reference_block_block ),
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
		FIELD( _field_long_flags, "Global flags", &lightmap_global_flags ),
		FIELD( _field_long_enum, "Mode", &lightmap_mode_enum ),
		FIELD( _field_long_enum, "Hemicube resolution", &lightmap_hemicube_resolution_enum ),
		FIELD( _field_long_enum, "DXT compression quality", &lightmap_dxt_quality_enum ),
		FIELD( _field_long_enum, "Indirect quality", &lightmap_indirect_quality_enum ),
		FIELD( _field_long_enum, "Direct shadow map resolution", &lightmap_direct_shadow_map_resolution_enum ),
		FIELD( _field_long_enum, "Super-sampling factor", &lightmap_supersampling_factor_enum ),
		FIELD( _field_long_enum, "AO Sample Quality", &lightmap_ao_quality_enum ),
		FIELD( _field_real_vector_3d, "Indirect Restrict AABB Min!" ),
		FIELD( _field_real_vector_3d, "Indirect Restrict AABB Max!" ),
		FIELD( _field_terminator )
};

TAG_STRUCT(global_lightmap_local_settings_struct)
{
		FIELD( _field_long_flags, "Local flags", &lightmap_local_flags ),
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
		FIELD( _field_long_enum, "Forge Lightmap Size Class (if enabled)", &scenario_structure_size_enum ),
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

} // namespace blofeld

