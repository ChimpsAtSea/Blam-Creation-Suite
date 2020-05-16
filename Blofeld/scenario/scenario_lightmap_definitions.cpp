#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP(scenario_lightmap_bsp_data, SCENARIO_LIGHTMAP_BSP_DATA_TAG)
{
	FIELD( _field_word_flags, "flags" ),
	FIELD( _field_short_integer, "bsp reference index" ),
	FIELD( _field_long_integer, "Checksum from Structure BSP" ),
	FIELD( _field_long_integer, "general structure lighting import checksum" ),
	FIELD( _field_long_integer, "skydome structure lighting import checksum" ),
	FIELD( _field_long_integer, "combined extra structure lighting import checksum" ),
	FIELD( _field_real, "perpixel compression scalar direct" ),
	FIELD( _field_real, "perpixel compression scalar indirect new" ),
	FIELD( _field_real, "pervertex compression scalar direct" ),
	FIELD( _field_real, "pervertex compression scalar indirect" ),
	FIELD( _field_real_vector_3d, "floating shadow light direction" ),
	FIELD( _field_real_vector_3d, "floating shadow light intensity" ),
	FIELD( _field_tag_reference, "hybrid probe data per-pixel color" ),
	FIELD( _field_tag_reference, "hybrid probe data per-pixel direction" ),
	FIELD( _field_tag_reference, "hybrid probe data per-pixel analytic" ),
	FIELD( _field_tag_reference, "hybrid probe data per-pixel overlay micro" ),
	FIELD( _field_tag_reference, "hybrid probe data per-pixel overlay macro" ),
	FIELD( _field_tag_reference, "hybrid probe data per-pixel refinement dxt3a" ),
	FIELD( _field_tag_reference, "hybrid vMF probe data per-vertex 565" ),
	FIELD( _field_tag_reference, "hybrid vMF probe data per-vertex lite 565" ),
	FIELD( _field_block, "clusters", &scenario_lightmap_cluster_data_block ),
	FIELD( _field_block, "instances", &scenario_lightmap_instance_data_block ),
	FIELD( _field_block, "probes", &scenario_lightmap_lightprobe_value_block ),
	FIELD( _field_block, "shadow geometry excluded instance indices", &scenario_lightmap_instance_index_block_block ),
	FIELD( _field_block, "per-pixel padding!", &scenario_lightmap_global_perpixel_padding_data_block ),
	FIELD( _field_block, "per-pixel rasterized charts!", &scenario_lightmap_rasterized_chart_data_block ),
	FIELD( _field_block, "New AO Data!", &scenario_lightmap_new_ao_data_block_block ),
	FIELD( _field_block, "Adjacent Bounce Vertices!", &scenario_lightmap_adjacent_bounce_vertex_block_block ),
	FIELD( _field_block, "Adjacent Bounce Indices!", &scenario_lightmap_adjacent_bounce_index_block_block ),
	FIELD( _field_long_integer, "Parameterization Method Checksum!" ),
	FIELD( _field_long_integer, "New AO checksum!" ),
	FIELD( _field_long_integer, "Material Count" ),
	FIELD( _field_long_integer, "Mesh Count" ),
	FIELD( _field_short_integer, "lightmap parameterization width" ),
	FIELD( _field_short_integer, "lightmap parameterization height" ),
	FIELD( _field_struct, "imported geometry*", &global_render_geometry_struct_struct_definition ),
	FIELD( _field_block, "per mesh triangle mapping", &triangle_mapping_per_mesh_block_block ),
	FIELD( _field_struct, "shadow geometry*", &global_render_geometry_struct_struct_definition ),
	FIELD( _field_struct, "Dynamic Light Shadow Geometry*", &global_render_geometry_struct_struct_definition ),
	FIELD( _field_block, "light instance data", &scenario_lightmap_dynamic_light_instance_block ),
	FIELD( _field_block, "structure light instance data", &scenario_lightmap_structure_light_instance_block ),
	FIELD( _field_block, "extruded silhouette vertices", &s_scenario_lightmap_silhouette_vertex_block ),
	FIELD( _field_block, "extruded silhouette edges", &s_scenario_lightmap_silhouette_edge_block ),
	FIELD( _field_block, "extruded silhouette groups", &s_scenario_lightmap_silhouette_group_block ),
	FIELD( _field_block, "airprobes", &scenario_lightmap_airprobe_value_block ),
	FIELD( _field_block, "errors*", &global_error_report_categories_block_block ),
	FIELD( _field_block, "self_track", &global_self_track_block_block ),
	FIELD( _field_tag_reference, "forge per-pixel color" ),
	FIELD( _field_tag_reference, "forge per-pixel sun" ),
	FIELD( _field_real, "world scale ratio" ),
	FIELD( _field_terminator )
};

TAG_GROUP(scenario_lightmap, SCENARIO_LIGHTMAP_TAG)
{
	FIELD( _field_long_integer, "job guid" ),
	FIELD( _field_block, "lightmap BSP references", &scenario_lightmap_bsp_data_reference_block_block ),
	FIELD( _field_terminator )
};

TAG_GROUP_FROM_BLOCK(scenario_wetness_bsp_data, SCENARIO_WETNESS_BSP_DATA_TAG, scenario_wetness_bsp_data_block_block )

TAG_BLOCK_FROM_STRUCT(scenario_wetness_bsp_data_block, 1, scenario_wetness_bsp_data_struct_definition_struct_definition );

TAG_BLOCK(scenario_lightmap_cluster_data, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_short_integer, "lightprobe texture array index" ),
	FIELD( _field_short_integer, "pervertex block index" ),
	FIELD( _field_long_integer, "pervertex block offset" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_lightmap_instance_data, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_short_integer, "lightprobe texture array index" ),
	FIELD( _field_short_integer, "pervertex block index" ),
	FIELD( _field_short_integer, "probe block index" ),
	FIELD( _field_char_integer, "analytical light collision warning" ),
	FIELD( _field_char_enum, "lightmap debug uv policy*" ),
	FIELD( _field_long_integer, "analytical light index" ),
	FIELD( _field_long_integer, "per-vertex lightprobe texture offset" ),
	FIELD( _field_dword_integer, "matching flags" ),
	FIELD( _field_dword_integer, "mesh index" ),
	FIELD( _field_real_point_3d, "instance world-space position" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_lightmap_lightprobe_value, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_array, "vmf terms" ),
	FIELD( _field_dword_integer, "analytical light index" ),
	FIELD( _field_struct, "sh terms", &half_rgb_lightprobe_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_lightmap_instance_index_block, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_long_integer, "Indices" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_lightmap_global_perpixel_padding_data, 1024 * 1024)
{
	FIELD( _field_long_integer, "x" ),
	FIELD( _field_long_integer, "y" ),
	FIELD( _field_long_integer, "source_x" ),
	FIELD( _field_long_integer, "source_y" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_lightmap_rasterized_chart_data, 1024 * 1024)
{
	FIELD( _field_long_integer, "width" ),
	FIELD( _field_long_integer, "height" ),
	FIELD( _field_long_integer, "flipX" ),
	FIELD( _field_long_integer, "chartRotation" ),
	FIELD( _field_long_integer, "atlasX" ),
	FIELD( _field_long_integer, "atlasY" ),
	FIELD( _field_real_vector_2d, "roundedSize" ),
	FIELD( _field_block, "sourceVertices", &scenario_lightmap_rasterized_chart_source_block ),
	FIELD( _field_block, "chartBitmap", &scenario_lightmap_rasterized_chart_element_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_lightmap_rasterized_chart_source, 2147483647L)
{
	FIELD( _field_long_integer, "streamIndex" ),
	FIELD( _field_long_integer, "vertexIndex" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_lightmap_rasterized_chart_element, 1024 * 1024 * 4)
{
	FIELD( _field_byte_integer, "composite" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_lightmap_new_ao_data_block, 2147483647L)
{
	FIELD( _field_char_integer, "value" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_lightmap_adjacent_bounce_vertex_block, 2147483647L)
{
	FIELD( _field_real_vector_3d, "position" ),
	FIELD( _field_short_integer, "color_r" ),
	FIELD( _field_short_integer, "color_g" ),
	FIELD( _field_short_integer, "color_b" ),
	FIELD( _field_short_integer, "color_a" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_lightmap_adjacent_bounce_index_block, 2147483647L)
{
	FIELD( _field_long_integer, "index" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(triangle_mapping_per_mesh_block, (8*1024-1))
{
	FIELD( _field_block, "mesh", &triangle_mapping_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(triangle_mapping_block, 2147483647L)
{
	FIELD( _field_long_integer, "word*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_lightmap_dynamic_light_instance, 2147483647L)
{
	FIELD( _field_real, "Min Depth" ),
	FIELD( _field_long_integer, "Light Instance Checksum" ),
	FIELD( _field_block, "instance indices", &scenario_lightmap_dynamic_light_instance_data_block_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_lightmap_dynamic_light_instance_data_block, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_long_integer, "Index" ),
	FIELD( _field_long_integer, "Shadow Geometry Mesh Index" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_lightmap_structure_light_instance, 2147483647L)
{
	FIELD( _field_long_integer, "Shadow Geometry Mesh Index" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(s_scenario_lightmap_silhouette_vertex, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_real_point_3d, "position" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(s_scenario_lightmap_silhouette_edge, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_long_integer, "First index" ),
	FIELD( _field_long_integer, "Second index" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(s_scenario_lightmap_silhouette_group, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_long_integer, "First edge" ),
	FIELD( _field_long_integer, "Edge count" ),
	FIELD( _field_real_vector_3d, "direction" ),
	FIELD( _field_real, "attenuation factor" ),
	FIELD( _field_real, "attenuation distance" ),
	FIELD( _field_real, "shaft intensity" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_lightmap_airprobe_value, k_max_airprobes_per_scenario)
{
	FIELD( _field_real_point_3d, "airprobe position" ),
	FIELD( _field_string_id, "airprobe name^" ),
	FIELD( _field_long_integer, "BSP index^" ),
	FIELD( _field_dword_integer, "analytical light index" ),
	FIELD( _field_struct, "sh terms", &half_rgb_lightprobe_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_BLOCK(scenario_lightmap_bsp_data_reference_block, LONG_BITS)
{
	FIELD( _field_tag_reference, "lightmap bsp data reference" ),
	FIELD( _field_tag_reference, "wetness bsp reference" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(wentness_bit_vector, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_long_integer, "bits" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(wentness_byte_vector, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_char_integer, "bytes" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(cluster_wetness_offset_block, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_long_integer, "cluster offset" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(instance_wetness_instance_block, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_long_integer, "cluster offset" ),
	FIELD( _field_char_integer, "single probe" ),
	FIELD( _field_pad, "LHWCHFX", 1 ),
	FIELD( _field_pad, "DWCIEFG", 2 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(scenario_wetness_bsp_data_struct_definition)
{
	FIELD( _field_short_integer, "bsp reference index" ),
	FIELD( _field_pad, "LHWCHFX", 2 ),
	FIELD( _field_long_integer, "structure BSP import checksum" ),
	FIELD( _field_long_integer, "lightmap BSP import checksum" ),
	FIELD( _field_long_integer, "design BSP checksum" ),
	FIELD( _field_long_integer, "air_probe offset" ),
	FIELD( _field_long_integer, "senary_probe offset" ),
	FIELD( _field_long_integer, "machinery_offset" ),
	FIELD( _field_tag_reference, "wetness pervertrex texture reference" ),
	FIELD( _field_block, "wetness", &wentness_bit_vector_block ),
	FIELD( _field_block, "wetness in bytes", &wentness_byte_vector_block ),
	FIELD( _field_block, "cluster_offset", &cluster_wetness_offset_block_block ),
	FIELD( _field_block, "instance_offset", &instance_wetness_instance_block_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

