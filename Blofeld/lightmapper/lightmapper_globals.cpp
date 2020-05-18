#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(lightmap_model_globals, LIGHTMAP_MODEL_GLOBALS_TAG, lightmap_model_globals_block_block );

	TAG_GROUP_FROM_BLOCK(lightmapper_globals, LIGHTMAPPER_GLOBALS_TAG, lightmapper_globals_block_block );

	TAG_BLOCK(lightmap_model_reference_block, SHORT_MAX)
	{
		{ _field_tag_reference, "Model Reference", &model_reference },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(lightmap_model_globals_block, 1, lightmap_model_globals_struct_definition_struct_definition );

	TAG_BLOCK_FROM_STRUCT(lightmapper_globals_block, 1, lightmapper_globals_struct_definition_struct_definition );

	TAG_STRUCT(lightmap_model_globals_struct_definition)
	{
		{ _field_block, "Lightmapped Models", &lightmap_model_reference_block_block },
		{ _field_terminator }
	};

	TAG_STRUCT(lightmapper_globals_struct_definition)
	{
		{ _field_long_integer, "Version!" },
		{ _field_custom, "GLOBAL QUALITY SETTINGS" },
		{ _field_struct, "Global lightmapper settings", &global_lightmap_global_settings_struct_struct_definition },
		{ _field_custom },
		{ _field_custom, "LOCAL SETTINGS" },
		{ _field_struct, "Local lightmapper settings", &global_lightmap_local_settings_struct_struct_definition },
		{ _field_custom },
		{ _field_terminator }
	};

	TAG_STRUCT(global_lightmap_global_settings_struct)
	{
		{ _field_long_flags, "Global flags", &lightmap_global_flags },
		{ _field_long_enum, "Mode", &lightmap_mode_enum },
		{ _field_long_enum, "Hemicube resolution", &lightmap_hemicube_resolution_enum },
		{ _field_long_enum, "DXT compression quality", &lightmap_dxt_quality_enum },
		{ _field_long_enum, "Indirect quality", &lightmap_indirect_quality_enum },
		{ _field_long_enum, "Direct shadow map resolution", &lightmap_direct_shadow_map_resolution_enum },
		{ _field_long_enum, "Super-sampling factor", &lightmap_supersampling_factor_enum },
		{ _field_long_enum, "AO Sample Quality", &lightmap_ao_quality_enum },
		{ _field_real_vector_3d, "Indirect Restrict AABB Min!" },
		{ _field_real_vector_3d, "Indirect Restrict AABB Max!" },
		{ _field_terminator }
	};

	TAG_STRUCT(global_lightmap_local_settings_struct)
	{
		{ _field_long_flags, "Local flags", &lightmap_local_flags },
		{ _field_real, "Skydome amplification factor" },
		{ _field_real, "Indirect amplification factor" },
		{ _field_real, "Lightmap Compression Maximum" },
		{ _field_real, "Per Vertex AO Auto Threshold" },
		{ _field_custom, "Ambient occlusion settings" },
		{ _field_struct, "AO settings", &global_lightmap_ao_settings_struct_struct_definition },
		{ _field_custom },
		{ _field_custom, "Global illumination falloff settings" },
		{ _field_struct, "Global illumination falloff settings", &global_lightmap_global_illumination_falloff_settings_struct_struct_definition },
		{ _field_custom },
		{ _field_custom, "Quality Overrides" },
		{ _field_struct, "Local lightmapper override settings", &global_lightmap_local_override_settings_struct_struct_definition },
		{ _field_custom },
		{ _field_long_enum, "Forge Lightmap Size Class (if enabled)", &scenario_structure_size_enum },
		{ _field_terminator }
	};

	TAG_STRUCT(global_lightmap_ao_settings_struct)
	{
		{ _field_real, "Radius{Offset}" },
		{ _field_real, "Falloff Power" },
		{ _field_real, "Multiplier" },
		{ _field_real, "MaxThreadCount" },
		{ _field_terminator }
	};

	TAG_STRUCT(global_lightmap_global_illumination_falloff_settings_struct)
	{
		{ _field_real, "Falloff Begin" },
		{ _field_real, "Falloff End" },
		{ _field_real_rgb_color, "Far Lighting Color" },
		{ _field_real, "Far Lighting Scalar" },
		{ _field_tag_reference, "Far Lighting Texture", &Tag::Reference<struct bitmap_group>::s_defaultDefinition },
		{ _field_terminator }
	};

	TAG_STRUCT(global_lightmap_local_override_settings_struct)
	{
		{ _field_long_integer, "High Quality Average Jitter Samples" },
		{ _field_long_integer, "Per Vertex Supersample Count" },
		{ _field_long_integer, "Indirect Quality Offset" },
		{ _field_terminator }
	};

	STRINGS(lightmap_mode_enum)
	{
		"Direct only",
		"One bounce",
		"Two bounce"
	};
	STRING_LIST(lightmap_mode_enum, lightmap_mode_enum_strings, _countof(lightmap_mode_enum_strings));

	STRINGS(lightmap_hemicube_resolution_enum)
	{
		"64 x 64",
		"128 x 128",
		"256 x 256",
		"512 x 512",
		"32 x 32",
		"16 x 16"
	};
	STRING_LIST(lightmap_hemicube_resolution_enum, lightmap_hemicube_resolution_enum_strings, _countof(lightmap_hemicube_resolution_enum_strings));

	STRINGS(lightmap_ao_quality_enum)
	{
		"Off",
		"1x",
		"2x",
		"4x"
	};
	STRING_LIST(lightmap_ao_quality_enum, lightmap_ao_quality_enum_strings, _countof(lightmap_ao_quality_enum_strings));

	STRINGS(lightmap_dxt_quality_enum)
	{
		"Draft",
		"High"
	};
	STRING_LIST(lightmap_dxt_quality_enum, lightmap_dxt_quality_enum_strings, _countof(lightmap_dxt_quality_enum_strings));

	STRINGS(lightmap_indirect_quality_enum)
	{
		"Low",
		"Medium",
		"High",
		"Very High"
	};
	STRING_LIST(lightmap_indirect_quality_enum, lightmap_indirect_quality_enum_strings, _countof(lightmap_indirect_quality_enum_strings));

	STRINGS(lightmap_direct_shadow_map_resolution_enum)
	{
		"1X",
		"2X",
		"4X"
	};
	STRING_LIST(lightmap_direct_shadow_map_resolution_enum, lightmap_direct_shadow_map_resolution_enum_strings, _countof(lightmap_direct_shadow_map_resolution_enum_strings));

	STRINGS(lightmap_supersampling_factor_enum)
	{
		"1X",
		"2X",
		"4X",
		"8X"
	};
	STRING_LIST(lightmap_supersampling_factor_enum, lightmap_supersampling_factor_enum_strings, _countof(lightmap_supersampling_factor_enum_strings));

	STRINGS(lightmap_local_flags)
	{
		"Enable floating shadows",
		"Replace sun with brightest directional",
		"Use legacy magic light scalars",
		"Remove lights outside target bsp",
		"Include Skydome",
		"Include Sun",
		"Perform bad pixel analysis",
		"Enable AO",
		"Generate New AO",
		"Ignore sun solid angle",
		"Override AO only",
		"Perform analysis",
		"Global Illumination Falloff",
		"Generate BVH AO (GPU) ",
		"Generate BVH AO (CPU) ",
		"Build packing lightmaps (for lighting forge objects)",
		"Attempt to Use Diffuse UVs",
		"Corrected Light Linking",
		"Burn simplified irradiance lighting",
		"Disable Floating Shadow Geometry",
		"Disable Hybrid Refinement",
		"Burn Probe AO Lighting",
		"Opt Out Per-Vertex Lighting Fix",
		"Generate Adjacent Bounce Info",
		"No Shadow No AO Fix",
		"Allow Spot Suns",
		"Probes Ignore Shadow Linking"
	};
	STRING_LIST(lightmap_local_flags, lightmap_local_flags_strings, _countof(lightmap_local_flags_strings));

	STRINGS(lightmap_global_flags)
	{
		"Force draft lighting",
		"Perform sun multisampling",
		"Perform sky multisampling",
		"Use high resolution point shadows",
		"Use new atlaser",
		"Use high quality packing",
		"Include geometry from adjacent bsps",
		"Use 32-bit precision for direct pass",
		"Enable subsampling indirect acceleration",
		"Restrict lightmap samples to Maya regions",
		"Perform Repack",
		"Is Farm Burn"
	};
	STRING_LIST(lightmap_global_flags, lightmap_global_flags_strings, _countof(lightmap_global_flags_strings));

} // namespace blofeld

