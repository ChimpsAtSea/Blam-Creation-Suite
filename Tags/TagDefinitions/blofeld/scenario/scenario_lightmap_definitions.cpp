#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{
	#define SCENARIO_LIGHTMAP_BSP_DATA_STRUCT_DEFINITION_ID { 0x750464BE, 0xDF6E4973, 0x8B70B0DD, 0xDB7F6F3D }
	TAG_BLOCK(
		scenario_lightmap_bsp_data_block,
		"scenario_lightmap_bsp_data_block",
		1,
		"s_scenario_lightmap_bsp_data",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_HAS_RESOURCES | 
		SET_UNKNOWN14 | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_BSP_DATA_STRUCT_DEFINITION_ID)
	{
		{ _field_word_flags, "flags", &scenario_lightmap_bsp_flags },
		{ _field_short_integer, "bsp reference index" },
		{ _field_long_integer, "Checksum from Structure BSP" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 6 },
		{ _field_legacy, _field_tag_reference, "unknown", &lightmap_bitmap_reference },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_tag_reference, "vMF dual probe data direction", &lightmap_bitmap_reference },
		{ _field_legacy, _field_tag_reference, "vMF dual probe data intensity", &lightmap_bitmap_reference },
		{ _field_legacy, _field_block, "unknown", &g_null_block },
		{ _field_legacy, _field_block, "unknown", &scenario_lightmap_bsp_data_unknown0_block }, // #TODO

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 17 },
		{ _field_long_integer, "general structure lighting import checksum" },
		{ _field_long_integer, "skydome structure lighting import checksum" },
		{ _field_long_integer, "combined extra structure lighting import checksum" },
		{ _field_real, "perpixel compression scalar direct" },
		{ _field_real, "perpixel compression scalar indirect new" },
		{ _field_real, "pervertex compression scalar direct" },
		{ _field_real, "pervertex compression scalar indirect" },
		{ _field_real_vector_3d, "floating shadow light direction" },
		{ _field_real_vector_3d, "floating shadow light intensity" },
		{ _field_tag_reference, "hybrid probe data per-pixel color", &lightmap_bitmap_reference },
		{ _field_tag_reference, "hybrid probe data per-pixel direction", &lightmap_bitmap_reference },
		{ _field_tag_reference, "hybrid probe data per-pixel analytic", &lightmap_bitmap_reference },
		{ _field_tag_reference, "hybrid probe data per-pixel overlay micro", &lightmap_bitmap_reference },
		{ _field_tag_reference, "hybrid probe data per-pixel overlay macro", &lightmap_bitmap_reference },
		{ _field_tag_reference, "hybrid probe data per-pixel refinement dxt3a", &lightmap_bitmap_reference },
		{ _field_tag_reference, "hybrid vMF probe data per-vertex 565", &lightmap_bitmap_reference },
		{ _field_tag_reference, "hybrid vMF probe data per-vertex lite 565", &lightmap_bitmap_reference },
		
		{ _field_block, "clusters", &scenario_lightmap_cluster_data_block },
		{ _field_block, "instances", &scenario_lightmap_instance_data_block },
		{ _field_block, "probes", &scenario_lightmap_lightprobe_value_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 12 },
		{ _field_block, "shadow geometry excluded instance indices", &scenario_lightmap_instance_index_block },
		{ _field_block, "per-pixel padding", FIELD_FLAG_UNKNOWN0, &scenario_lightmap_global_perpixel_padding_data_block },
		{ _field_block, "per-pixel rasterized charts", FIELD_FLAG_UNKNOWN0, &scenario_lightmap_rasterized_chart_data_block },
		{ _field_block, "New AO Data", FIELD_FLAG_UNKNOWN0, &scenario_lightmap_new_ao_data_block },
		{ _field_block, "Adjacent Bounce Vertices", FIELD_FLAG_UNKNOWN0, &scenario_lightmap_adjacent_bounce_vertex_block },
		{ _field_block, "Adjacent Bounce Indices", FIELD_FLAG_UNKNOWN0, &scenario_lightmap_adjacent_bounce_index_block },
		{ _field_long_integer, "Parameterization Method Checksum", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "New AO checksum", FIELD_FLAG_UNKNOWN0 },
		{ _field_long_integer, "Material Count" },
		{ _field_long_integer, "Mesh Count" },
		{ _field_short_integer, "lightmap parameterization width" },
		{ _field_short_integer, "lightmap parameterization height" },
		
		{ _field_struct, "imported geometry", FIELD_FLAG_READ_ONLY, &global_render_geometry_struct },
		{ _field_block, "per mesh triangle mapping", &triangle_mapping_per_mesh_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 1 },
		{ _field_struct, "shadow geometry", FIELD_FLAG_READ_ONLY, &global_render_geometry_struct },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 6 },
		{ _field_struct, "Dynamic Light Shadow Geometry", FIELD_FLAG_READ_ONLY, &global_render_geometry_struct },
		{ _field_block, "light instance data", &scenario_lightmap_dynamic_light_instance_block },
		{ _field_block, "structure light instance data", &scenario_lightmap_structure_light_instance_block },
		{ _field_block, "extruded silhouette vertices", &s_scenario_lightmap_silhouette_vertex_block },
		{ _field_block, "extruded silhouette edges", &s_scenario_lightmap_silhouette_edge_block },
		{ _field_block, "extruded silhouette groups", &s_scenario_lightmap_silhouette_group_block },
		
		{ _field_block, "airprobes", &scenario_lightmap_airprobe_value_block },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc_64bit, 3 },
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_block, "unknown", &scenario_lightmap_bsp_data_unknown1_block },
		{ _field_legacy, _field_block, "unknown", &scenario_lightmap_bsp_data_unknown2_block },
		
		{ _field_block, "errors", FIELD_FLAG_READ_ONLY, &global_error_report_categories_block },
		{ _field_block, "self_track", &global_self_track_block },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_tag_reference, "forge per-pixel color", &lightmap_bitmap_reference },
		{ _field_tag_reference, "forge per-pixel sun", &lightmap_bitmap_reference },
		{ _field_real, "world scale ratio" },
		
		{ _field_terminator }
	};

	TAG_GROUP(
		scenario_lightmap_bsp_data_group,
		SCENARIO_LIGHTMAP_BSP_DATA_TAG,
		nullptr,
		INVALID_TAG,
		scenario_lightmap_bsp_data_block );

	#define SCENARIO_LIGHTMAP_STRUCT_DEFINITION_ID { 0xD871C433, 0xD2864E9F, 0xB2E8B245, 0x76BE82ED }
	TAG_BLOCK(
		scenario_lightmap_block,
		"scenario_lightmap_block",
		1,
		"s_scenario_lightmap",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_STRUCT_DEFINITION_ID)
	{
		{ _field_long_integer, "job guid" },
		{ _field_block, "lightmap BSP references", &scenario_lightmap_bsp_data_reference_block },
		{ _field_terminator }
	};

	TAG_GROUP(
		scenario_lightmap_group,
		SCENARIO_LIGHTMAP_TAG,
		nullptr,
		INVALID_TAG,
		scenario_lightmap_block );

	TAG_GROUP(
		scenario_wetness_bsp_data_group,
		SCENARIO_WETNESS_BSP_DATA_TAG,
		nullptr,
		INVALID_TAG,
		scenario_wetness_bsp_data_block );

	TAG_BLOCK_FROM_STRUCT(
		scenario_wetness_bsp_data_block,
		"scenario_wetness_bsp_data_block",
		1,
		scenario_wetness_bsp_data_struct_definition);

	#define SCENARIO_LIGHTMAP_CLUSTER_DATA_ID { 0x103A0755, 0xE4ED4051, 0x96CE9FBE, 0x00A61E8F }
	TAG_BLOCK(
		scenario_lightmap_cluster_data_block,
		"scenario_lightmap_cluster_data",
		UNSIGNED_SHORT_MAX,
		"s_scenario_lightmap_cluster_data",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_CLUSTER_DATA_ID)
	{
		{ _field_short_integer, "lightprobe texture array index" },
		{ _field_short_integer, "pervertex block index" },
		{ _field_long_integer, "pervertex block offset" },
		{ _field_terminator }
	};

	#define SCENARIO_LIGHTMAP_INSTANCE_DATA_ID { 0x02B9848C, 0x68E0495A, 0x8BAAD777, 0x64AF9F2F }
	TAG_BLOCK(
		scenario_lightmap_instance_data_block,
		"scenario_lightmap_instance_data",
		UNSIGNED_SHORT_MAX,
		"s_scenario_lightmap_instance_data",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_INSTANCE_DATA_ID)
	{
		{ _field_short_integer, "lightprobe texture array index" },
		{ _field_short_integer, "pervertex block index" },
		{ _field_short_integer, "probe block index" },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_legacy, _field_short_integer, "unknown@" }, // padding?
		{ _field_legacy, _field_long_integer, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 7 },
		{ _field_char_integer, "analytical light collision warning" },
		{ _field_char_enum, "lightmap debug uv policy", FIELD_FLAG_READ_ONLY, &lightmapDebugUVPolicyDefinition },
		{ _field_long_integer, "analytical light index" },
		{ _field_long_integer, "per-vertex lightprobe texture offset" },
		{ _field_dword_integer, "matching flags" },
		{ _field_dword_integer, "mesh index" },
		{ _field_real_point_3d, "instance world-space position" },
		
		{ _field_terminator }
	};

	#define SCENARIO_LIGHTMAP_LIGHTPROBE_VALUE_ID { 0x8A43FCFC, 0x348747AA, 0xBBFC7C0A, 0xC425DD0C }
	TAG_BLOCK(
		scenario_lightmap_lightprobe_value_block,
		"scenario_lightmap_lightprobe_value",
		UNSIGNED_SHORT_MAX,
		"s_scenario_lightmap_bsp_single_probe",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_LIGHTPROBE_VALUE_ID)
	{
		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 10 },
		{ _field_legacy, _field_real_quaternion, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown@" },
		{ _field_legacy, _field_short_integer, "unknown@" },
		{ _field_legacy, _field_short_integer, "unknown@" },
		{ _field_legacy, _field_short_block_index, "unknown" },
		{ _field_legacy, _field_short_block_index, "unknown" },
		{ _field_legacy, _field_short_block_index, "unknown" },
		{ _field_legacy, _field_short_block_index, "unknown" },
		{ _field_legacy, _field_pad, "pad", 2 }, // assumed
		{ _field_legacy, _field_long_integer, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_array, "vmf terms", &dual_vmf_terms_array },
		{ _field_dword_integer, "analytical light index" },
		{ _field_struct, "sh terms", &half_rgb_lightprobe_struct },
		{ _field_terminator }
	};

	#define SCENARIO_LIGHTMAP_INSTANCE_INDEX_BLOCK_ID { 0xDDF00598, 0x22CF4CB8, 0x9B3480FE, 0x9B200429 }
	TAG_BLOCK(
		scenario_lightmap_instance_index_block,
		"scenario_lightmap_instance_index_block",
		UNSIGNED_SHORT_MAX,
		"s_scenario_lightmap_instance_index",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_INSTANCE_INDEX_BLOCK_ID)
	{
		{ _field_long_integer, "Indices" },
		{ _field_terminator }
	};

	#define SCENARIO_LIGHTMAP_GLOBAL_PERPIXEL_PADDING_DATA_ID { 0x7C5AFB2C, 0xDFCC46D2, 0x8154B1BB, 0xB65DA7A1 }
	TAG_BLOCK(
		scenario_lightmap_global_perpixel_padding_data_block,
		"scenario_lightmap_global_perpixel_padding_data",
		1024 * 1024,
		"s_scenario_lightmap_perpixel_padding_data",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_GLOBAL_PERPIXEL_PADDING_DATA_ID)
	{
		{ _field_long_integer, "x" },
		{ _field_long_integer, "y" },
		{ _field_long_integer, "source_x" },
		{ _field_long_integer, "source_y" },
		{ _field_terminator }
	};

	#define SCENARIO_LIGHTMAP_RASTERIZED_CHART_DATA_ID { 0x1E27169B, 0xDA19459D, 0xA70E48BC, 0x6FC9E7B2 }
	TAG_BLOCK(
		scenario_lightmap_rasterized_chart_data_block,
		"scenario_lightmap_rasterized_chart_data",
		1024 * 1024,
		"s_scenario_lightmap_rasterized_chart_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_RASTERIZED_CHART_DATA_ID)
	{
		{ _field_long_integer, "width" },
		{ _field_long_integer, "height" },
		{ _field_long_integer, "flipX" },
		{ _field_long_integer, "chartRotation" },
		{ _field_long_integer, "atlasX" },
		{ _field_long_integer, "atlasY" },
		{ _field_real_vector_2d, "roundedSize" },
		{ _field_block, "sourceVertices", &scenario_lightmap_rasterized_chart_source_block },
		{ _field_block, "chartBitmap", &scenario_lightmap_rasterized_chart_element_block },
		{ _field_terminator }
	};

	#define SCENARIO_LIGHTMAP_RASTERIZED_CHART_SOURCE_ID { 0xE4891E2B, 0xA707B19D, 0x71DAE6BC, 0x4596FC92 }
	TAG_BLOCK(
		scenario_lightmap_rasterized_chart_source_block,
		"scenario_lightmap_rasterized_chart_source",
		2147483647L,
		"s_scenario_lightmap_rasterized_chart_source",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_RASTERIZED_CHART_SOURCE_ID)
	{
		{ _field_long_integer, "streamIndex" },
		{ _field_long_integer, "vertexIndex" },
		{ _field_terminator }
	};

	#define SCENARIO_LIGHTMAP_RASTERIZED_CHART_ELEMENT_ID { 0x67BEAC2F, 0xF8234C79, 0xA076F4AE, 0x387C111B }
	TAG_BLOCK(
		scenario_lightmap_rasterized_chart_element_block,
		"scenario_lightmap_rasterized_chart_element",
		1024 * 1024 * 4,
		"s_scenario_lightmap_rasterized_chart_element",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_RASTERIZED_CHART_ELEMENT_ID)
	{
		{ _field_byte_integer, "composite" },
		{ _field_terminator }
	};

	#define SCENARIO_LIGHTMAP_NEW_AO_DATA_BLOCK_ID { 0xEA09AAC0, 0xA28F11E0, 0x82640800, 0x200C9A66 }
	TAG_BLOCK(
		scenario_lightmap_new_ao_data_block,
		"scenario_lightmap_new_ao_data_block",
		2147483647L,
		"s_scenario_lightmap_new_ao_data",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_NEW_AO_DATA_BLOCK_ID)
	{
		{ _field_char_integer, "value" },
		{ _field_terminator }
	};

	#define SCENARIO_LIGHTMAP_ADJACENT_BOUNCE_VERTEX_BLOCK_ID { 0xBA6402C0, 0xA8F0CAE0, 0xAA891800, 0x20902066 }
	TAG_BLOCK(
		scenario_lightmap_adjacent_bounce_vertex_block,
		"scenario_lightmap_adjacent_bounce_vertex_block",
		2147483647L,
		"s_scenario_lightmap_adjacent_bounce_vertex",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_ADJACENT_BOUNCE_VERTEX_BLOCK_ID)
	{
		{ _field_real_vector_3d, "position" },
		{ _field_short_integer, "color_r" },
		{ _field_short_integer, "color_g" },
		{ _field_short_integer, "color_b" },
		{ _field_short_integer, "color_a" },
		{ _field_terminator }
	};

	#define SCENARIO_LIGHTMAP_ADJACENT_BOUNCE_INDEX_BLOCK_ID { 0xBA643456, 0x8F0CAAE0, 0xA2091880, 0x220A9066 }
	TAG_BLOCK(
		scenario_lightmap_adjacent_bounce_index_block,
		"scenario_lightmap_adjacent_bounce_index_block",
		2147483647L,
		"unsigned long",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_ADJACENT_BOUNCE_INDEX_BLOCK_ID)
	{
		{ _field_long_integer, "index" },
		{ _field_terminator }
	};

	#define TRIANGLE_MAPPING_PER_MESH_BLOCK_ID { 0x662F1A28, 0xCF484602, 0x8BA6B022, 0x563BAA22 }
	TAG_BLOCK(
		triangle_mapping_per_mesh_block,
		"triangle_mapping_per_mesh_block",
		(8*1024-1),
		"s_reordered_triangle",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		TRIANGLE_MAPPING_PER_MESH_BLOCK_ID)
	{
		{ _field_legacy, _field_version_platform_include, _platform_type_pc_64bit },
		{ _field_legacy, _field_version_greater_or_equal, _engine_type_halo4 },
		{ _field_legacy, _field_api_interop, "mesh" },

		{ _field_legacy, _field_version_platform_include, _platform_type_pc_64bit, 2 },
		{ _field_legacy, _field_version_not_equal, _engine_type_groundhog, 2 },
		{ _field_legacy, _field_version_not_equal, _engine_type_halo4 },
		{ _field_block, "mesh", &triangle_mapping_block },
		
		{ _field_terminator }
	};

	#define TRIANGLE_MAPPING_BLOCK_ID { 0xE555CA90, 0xD7984A4D, 0xA70E7F34, 0xD97143EE }
	TAG_BLOCK(
		triangle_mapping_block,
		"triangle_mapping_block",
		2147483647L,
		"dword",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		TRIANGLE_MAPPING_BLOCK_ID)
	{
		{ _field_long_integer, "word", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define SCENARIO_LIGHTMAP_DYNAMIC_LIGHT_INSTANCE_ID { 0x87D6DA6F, 0xDA944097, 0x80689C17, 0xEB382949 }
	TAG_BLOCK(
		scenario_lightmap_dynamic_light_instance_block,
		"scenario_lightmap_dynamic_light_instance",
		2147483647L,
		"s_scenario_lightmap_dynamic_light_instance",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_DYNAMIC_LIGHT_INSTANCE_ID)
	{
		{ _field_real, "Min Depth" },
		{ _field_long_integer, "Light Instance Checksum" },
		{ _field_block, "instance indices", &scenario_lightmap_dynamic_light_instance_data_block },
		{ _field_terminator }
	};

	#define SCENARIO_LIGHTMAP_DYNAMIC_LIGHT_INSTANCE_DATA_BLOCK_ID { 0xDDB34898, 0x22CF0048, 0x90FF005E, 0x9B24CB29 }
	TAG_BLOCK(
		scenario_lightmap_dynamic_light_instance_data_block,
		"scenario_lightmap_dynamic_light_instance_data_block",
		UNSIGNED_SHORT_MAX,
		"s_scenario_lightmap_dynamic_light_instance_data",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_DYNAMIC_LIGHT_INSTANCE_DATA_BLOCK_ID)
	{
		{ _field_long_integer, "Index" },
		{ _field_long_integer, "Shadow Geometry Mesh Index" },
		{ _field_terminator }
	};

	#define SCENARIO_LIGHTMAP_STRUCTURE_LIGHT_INSTANCE_ID { 0xDA68A94F, 0x4EB8D6D7, 0x99C80617, 0x09782349 }
	TAG_BLOCK(
		scenario_lightmap_structure_light_instance_block,
		"scenario_lightmap_structure_light_instance",
		2147483647L,
		"s_scenario_lightmap_structure_light_instance",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_STRUCTURE_LIGHT_INSTANCE_ID)
	{
		{ _field_long_integer, "Shadow Geometry Mesh Index" },
		{ _field_terminator }
	};

	#define S_SCENARIO_LIGHTMAP_SILHOUETTE_VERTEX_ID { 0xB6061A2F, 0x5DAD41D4, 0x81C1BD29, 0xC20C8CEE }
	TAG_BLOCK(
		s_scenario_lightmap_silhouette_vertex_block,
		"s_scenario_lightmap_silhouette_vertex",
		UNSIGNED_SHORT_MAX,
		"s_scenario_lightmap_silhouette_vertex",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		S_SCENARIO_LIGHTMAP_SILHOUETTE_VERTEX_ID)
	{
		{ _field_real_point_3d, "position" },
		{ _field_terminator }
	};

	#define S_SCENARIO_LIGHTMAP_SILHOUETTE_EDGE_ID { 0x49FD0680, 0x27CF4DB4, 0xB00C2B82, 0x3FA77F66 }
	TAG_BLOCK(
		s_scenario_lightmap_silhouette_edge_block,
		"s_scenario_lightmap_silhouette_edge",
		UNSIGNED_SHORT_MAX,
		"s_scenario_lightmap_silhouette_edge",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		S_SCENARIO_LIGHTMAP_SILHOUETTE_EDGE_ID)
	{
		{ _field_long_integer, "First index" },
		{ _field_long_integer, "Second index" },
		{ _field_terminator }
	};

	#define S_SCENARIO_LIGHTMAP_SILHOUETTE_GROUP_ID { 0x87979F29, 0x51A74613, 0xBB149BB5, 0x80E554C9 }
	TAG_BLOCK(
		s_scenario_lightmap_silhouette_group_block,
		"s_scenario_lightmap_silhouette_group",
		UNSIGNED_SHORT_MAX,
		"s_scenario_lightmap_silhouette_group",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		S_SCENARIO_LIGHTMAP_SILHOUETTE_GROUP_ID)
	{
		{ _field_long_integer, "First edge" },
		{ _field_long_integer, "Edge count" },
		{ _field_real_vector_3d, "direction" },
		{ _field_real, "attenuation factor" },
		{ _field_real, "attenuation distance" },
		{ _field_real, "shaft intensity" },
		{ _field_terminator }
	};

	#define SCENARIO_LIGHTMAP_AIRPROBE_VALUE_ID { 0x51851D4A, 0x54A64B69, 0xA6B0BA23, 0xAE40825D }
	TAG_BLOCK(
		scenario_lightmap_airprobe_value_block,
		"scenario_lightmap_airprobe_value",
		k_max_airprobes_per_scenario,
		"s_scenario_lightmap_airprobe",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_AIRPROBE_VALUE_ID)
	{
		{ _field_real_point_3d, "airprobe position" },
		{ _field_string_id, "airprobe name", FIELD_FLAG_INDEX },

		{ _field_legacy, _field_version_less_or_equal, _engine_type_haloreach, 12 },
		{ _field_legacy, _field_short_integer, "bsp index^" },
		{ _field_legacy, _field_pad, "post-bsp-index-pad", 2 },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },

		{ _field_legacy, _field_version_greater, _engine_type_haloreach, 3 },
		{ _field_long_integer, "BSP index", FIELD_FLAG_INDEX },
		{ _field_dword_integer, "analytical light index" },
		{ _field_struct, "sh terms", &half_rgb_lightprobe_struct },
		
		{ _field_terminator }
	};

	#define SCENARIO_LIGHTMAP_BSP_DATA_REFERENCE_BLOCK_ID { 0xFFDC5A33, 0x248B4BA2, 0xBC16903E, 0xABBC58E9 }
	TAG_BLOCK(
		scenario_lightmap_bsp_data_reference_block,
		"scenario_lightmap_bsp_data_reference_block",
		LONG_BITS,
		"s_scenario_lightmap_bsp_data_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_LIGHTMAP_BSP_DATA_REFERENCE_BLOCK_ID)
	{
		{ _field_tag_reference, "lightmap bsp data reference", &scenario_lightmap_bsp_data_reference },
		{ _field_tag_reference, "wetness bsp reference", &scenario_wetness_bsp_data_reference },
		{ _field_terminator }
	};

	#define WENTNESS_BIT_VECTOR_ID { 0x7D96F927, 0xE3BA4ED9, 0x854824AB, 0xE8BD309C }
	TAG_BLOCK(
		wentness_bit_vector_block,
		"wentness_bit_vector",
		UNSIGNED_SHORT_MAX,
		"long",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		WENTNESS_BIT_VECTOR_ID)
	{
		{ _field_long_integer, "bits" },
		{ _field_terminator }
	};

	#define WENTNESS_BYTE_VECTOR_ID { 0x3CA1F30D, 0xBE644E28, 0x9BA62C05, 0xF671C6DB }
	TAG_BLOCK(
		wentness_byte_vector_block,
		"wentness_byte_vector",
		UNSIGNED_SHORT_MAX,
		"byte",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		WENTNESS_BYTE_VECTOR_ID)
	{
		{ _field_char_integer, "bytes" },
		{ _field_terminator }
	};

	#define CLUSTER_WETNESS_OFFSET_BLOCK_ID { 0x34C4130F, 0x9F824EFA, 0xA1ED71C7, 0x2FFB56DE }
	TAG_BLOCK(
		cluster_wetness_offset_block,
		"cluster_wetness_offset_block",
		UNSIGNED_SHORT_MAX,
		"long",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		CLUSTER_WETNESS_OFFSET_BLOCK_ID)
	{
		{ _field_long_integer, "cluster offset" },
		{ _field_terminator }
	};

	#define INSTANCE_WETNESS_INSTANCE_BLOCK_ID { 0x6AD8A521, 0xBB2C42CF, 0x8CD61432, 0x47116636 }
	TAG_BLOCK(
		instance_wetness_instance_block,
		"instance_wetness_instance_block",
		UNSIGNED_SHORT_MAX,
		"s_instance_wetness_info",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		INSTANCE_WETNESS_INSTANCE_BLOCK_ID)
	{
		{ _field_long_integer, "cluster offset" },
		{ _field_char_integer, "single probe" },
		FIELD_PAD("LHWCHFX", nullptr, FIELD_FLAG_NONE, 1),
		FIELD_PAD("DWCIEFG", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_terminator }
	};

	#define DUAL_VMF_TERMS_ID { 0x0E0FABA4, 0x51F74A05, 0x852BD2AC, 0xDA03B75B }
	TAG_ARRAY(
		dual_vmf_terms_array,
		"dual_vmf_terms",
		k_dual_vmf_basis_real_coefficients_count,
		"short",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		DUAL_VMF_TERMS_ID)
	{
		{ _field_short_integer, "dual vmf coefficient", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define SCENARIO_WETNESS_BSP_DATA_STRUCT_DEFINITION_ID { 0xC4FBE9A5, 0x725F4AAB, 0xADC5FCB1, 0x1319CF80 }
	TAG_STRUCT(
		scenario_wetness_bsp_data_struct_definition,
		"scenario_wetness_bsp_data_struct_definition",
		"s_scenario_wetness_bsp_data",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCENARIO_WETNESS_BSP_DATA_STRUCT_DEFINITION_ID)
	{
		{ _field_short_integer, "bsp reference index" },
		FIELD_PAD("LHWCHFX", nullptr, FIELD_FLAG_NONE, 2),
		{ _field_long_integer, "structure BSP import checksum" },
		{ _field_long_integer, "lightmap BSP import checksum" },
		{ _field_long_integer, "design BSP checksum" },
		{ _field_long_integer, "air_probe offset" },
		{ _field_long_integer, "senary_probe offset" },
		{ _field_long_integer, "machinery_offset" },
		{ _field_tag_reference, "wetness pervertrex texture reference", &lightmap_bitmap_reference },
		{ _field_block, "wetness", &wentness_bit_vector_block },
		{ _field_block, "wetness in bytes", &wentness_byte_vector_block },
		{ _field_block, "cluster_offset", &cluster_wetness_offset_block },
		{ _field_block, "instance_offset", &instance_wetness_instance_block },
		{ _field_terminator }
	};
	V5_TAG_BLOCK(scenario_lightmap_bsp_data_unknown2_block, 65536)
	{
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_block, "unknown", &scenario_lightmap_bsp_data_unknown3_block },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(scenario_lightmap_bsp_data_unknown3_block, 65536)
	{
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_terminator }
	};


	V5_TAG_BLOCK(scenario_lightmap_bsp_data_unknown1_block, 65536)
	{
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_real, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_long_integer, "unknown" },
		{ _field_legacy, _field_terminator }
	};

	V5_TAG_BLOCK(scenario_lightmap_bsp_data_unknown0_block, 65536)
	{
		{ _field_legacy, _field_short_integer, "vertex buffer index" },
		{ _field_legacy, _field_short_integer, "unknown" },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(lightmapDebugUVPolicyDefinition)
	{
		"None",
		"Probe",
		"Vertex",
		"Vertex AO",
		"Supplied UV",
		"Auto UV",
		"Diffuse UV",
		"Auto/Diffuse"
	};
	STRING_LIST(lightmapDebugUVPolicyDefinition, lightmapDebugUVPolicyDefinition_strings, _countof(lightmapDebugUVPolicyDefinition_strings));

	STRINGS(scenario_lightmap_bsp_flags)
	{
		"compressed",
		"xsynced geometry*!",
		"relightmapped",
		"generate fake small lightmaps",
		"generated from match data",
		"only a checker board",
		"surface to triangle mapping pruned{surface to tirnalge mapping pruned}",
		"faked lightmap tag for cache build",
		"Optimized for less dp all",
		"Floating shadows enabled",
		"Atlas unrefined packing",
		"Atlas repacked",
		"Using simplified irradiance lighting",
		"Disable Shadow Geometry",
		"Disable Hybrid Refinement"
	};
	STRING_LIST(scenario_lightmap_bsp_flags, scenario_lightmap_bsp_flags_strings, _countof(scenario_lightmap_bsp_flags_strings));

	TAG_REFERENCE(scenario_lightmap_bsp_data_reference, SCENARIO_LIGHTMAP_BSP_DATA_TAG);



} // namespace blofeld

