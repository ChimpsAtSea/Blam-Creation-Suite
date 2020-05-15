#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(scenario_lightmap_cluster_data, UNSIGNED_SHORT_MAX)
{
	{ _field_short_integer, "lightprobe texture array index" },
	{ _field_short_integer, "pervertex block index" },
	{ _field_long_integer, "pervertex block offset" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_lightmap_instance_data, UNSIGNED_SHORT_MAX)
{
	{ _field_short_integer, "lightprobe texture array index" },
	{ _field_short_integer, "pervertex block index" },
	{ _field_short_integer, "probe block index" },
	{ _field_char_integer, "analytical light collision warning" },
	{ _field_char_enum, "lightmap debug uv policy*" },
	{ _field_long_integer, "analytical light index" },
	{ _field_long_integer, "per-vertex lightprobe texture offset" },
	{ _field_dword_integer, "matching flags" },
	{ _field_dword_integer, "mesh index" },
	{ _field_real_point_3d, "instance world-space position" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_lightmap_lightprobe_value, UNSIGNED_SHORT_MAX)
{
	{ _field_array, "vmf terms" },
	{ _field_dword_integer, "analytical light index" },
	{ _field_struct, "sh terms" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_lightmap_instance_index, UNSIGNED_SHORT_MAX)
{
	{ _field_long_integer, "Indices" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_lightmap_global_perpixel_padding_data, 1024 * 1024)
{
	{ _field_long_integer, "x" },
	{ _field_long_integer, "y" },
	{ _field_long_integer, "source_x" },
	{ _field_long_integer, "source_y" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_lightmap_rasterized_chart_data, 1024 * 1024)
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
	{ _field_terminator },
};

TAG_BLOCK(scenario_lightmap_rasterized_chart_source, 2147483647L)
{
	{ _field_long_integer, "streamIndex" },
	{ _field_long_integer, "vertexIndex" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_lightmap_rasterized_chart_element, 1024 * 1024 * 4)
{
	{ _field_byte_integer, "composite" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_lightmap_new_ao_data, 2147483647L)
{
	{ _field_char_integer, "value" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_lightmap_adjacent_bounce_vertex, 2147483647L)
{
	{ _field_real_vector_3d, "position" },
	{ _field_short_integer, "color_r" },
	{ _field_short_integer, "color_g" },
	{ _field_short_integer, "color_b" },
	{ _field_short_integer, "color_a" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_lightmap_adjacent_bounce_index, 2147483647L)
{
	{ _field_long_integer, "index" },
	{ _field_terminator },
};

TAG_BLOCK(triangle_mapping_per_mesh, (8*1024-1))
{
	{ _field_block, "mesh", &triangle_mapping_block },
	{ _field_terminator },
};

TAG_BLOCK(triangle_mapping, 2147483647L)
{
	{ _field_long_integer, "word*" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_lightmap_dynamic_light_instance, 2147483647L)
{
	{ _field_real, "Min Depth" },
	{ _field_long_integer, "Light Instance Checksum" },
	{ _field_block, "instance indices", &scenario_lightmap_dynamic_light_instance_data_block },
	{ _field_terminator },
};

TAG_BLOCK(scenario_lightmap_dynamic_light_instance_data, UNSIGNED_SHORT_MAX)
{
	{ _field_long_integer, "Index" },
	{ _field_long_integer, "Shadow Geometry Mesh Index" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_lightmap_structure_light_instance, 2147483647L)
{
	{ _field_long_integer, "Shadow Geometry Mesh Index" },
	{ _field_terminator },
};

TAG_BLOCK(s_scenario_lightmap_silhouette_vertex, UNSIGNED_SHORT_MAX)
{
	{ _field_real_point_3d, "position" },
	{ _field_terminator },
};

TAG_BLOCK(s_scenario_lightmap_silhouette_edge, UNSIGNED_SHORT_MAX)
{
	{ _field_long_integer, "First index" },
	{ _field_long_integer, "Second index" },
	{ _field_terminator },
};

TAG_BLOCK(s_scenario_lightmap_silhouette_group, UNSIGNED_SHORT_MAX)
{
	{ _field_long_integer, "First edge" },
	{ _field_long_integer, "Edge count" },
	{ _field_real_vector_3d, "direction" },
	{ _field_real, "attenuation factor" },
	{ _field_real, "attenuation distance" },
	{ _field_real, "shaft intensity" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_lightmap_airprobe_value, k_max_airprobes_per_scenario)
{
	{ _field_real_point_3d, "airprobe position" },
	{ _field_string_id, "airprobe name^" },
	{ _field_long_integer, "BSP index^" },
	{ _field_dword_integer, "analytical light index" },
	{ _field_struct, "sh terms" },
	{ _field_terminator },
};

TAG_BLOCK(scenario_lightmap_bsp_data_reference, LONG_BITS)
{
	{ _field_tag_reference, "lightmap bsp data reference" },
	{ _field_tag_reference, "wetness bsp reference" },
	{ _field_terminator },
};

TAG_BLOCK(wentness_bit_vector, UNSIGNED_SHORT_MAX)
{
	{ _field_long_integer, "bits" },
	{ _field_terminator },
};

TAG_BLOCK(wentness_byte_vector, UNSIGNED_SHORT_MAX)
{
	{ _field_char_integer, "bytes" },
	{ _field_terminator },
};

TAG_BLOCK(cluster_wetness_offset, UNSIGNED_SHORT_MAX)
{
	{ _field_long_integer, "cluster offset" },
	{ _field_terminator },
};

TAG_BLOCK(instance_wetness_instance, UNSIGNED_SHORT_MAX)
{
	{ _field_long_integer, "cluster offset" },
	{ _field_char_integer, "single probe" },
	{ _field_pad, "LHWCHFX", 1 },
	{ _field_pad, "DWCIEFG", 2 },
	{ _field_terminator },
};

TAG_GROUP(scenario_lightmap_bsp_data, SCENARIO_LIGHTMAP_BSP_DATA_TAG)
{
	{ _field_word_flags, "flags" },
	{ _field_short_integer, "bsp reference index" },
	{ _field_long_integer, "Checksum from Structure BSP" },
	{ _field_long_integer, "general structure lighting import checksum" },
	{ _field_long_integer, "skydome structure lighting import checksum" },
	{ _field_long_integer, "combined extra structure lighting import checksum" },
	{ _field_real, "perpixel compression scalar direct" },
	{ _field_real, "perpixel compression scalar indirect new" },
	{ _field_real, "pervertex compression scalar direct" },
	{ _field_real, "pervertex compression scalar indirect" },
	{ _field_real_vector_3d, "floating shadow light direction" },
	{ _field_real_vector_3d, "floating shadow light intensity" },
	{ _field_tag_reference, "hybrid probe data per-pixel color" },
	{ _field_tag_reference, "hybrid probe data per-pixel direction" },
	{ _field_tag_reference, "hybrid probe data per-pixel analytic" },
	{ _field_tag_reference, "hybrid probe data per-pixel overlay micro" },
	{ _field_tag_reference, "hybrid probe data per-pixel overlay macro" },
	{ _field_tag_reference, "hybrid probe data per-pixel refinement dxt3a" },
	{ _field_tag_reference, "hybrid vMF probe data per-vertex 565" },
	{ _field_tag_reference, "hybrid vMF probe data per-vertex lite 565" },
	{ _field_block, "clusters", &scenario_lightmap_cluster_data_block },
	{ _field_block, "instances", &scenario_lightmap_instance_data_block },
	{ _field_block, "probes", &scenario_lightmap_lightprobe_value_block },
	{ _field_block, "shadow geometry excluded instance indices", &scenario_lightmap_instance_index_block },
	{ _field_block, "per-pixel padding!", &scenario_lightmap_global_perpixel_padding_data_block },
	{ _field_block, "per-pixel rasterized charts!", &scenario_lightmap_rasterized_chart_data_block },
	{ _field_block, "New AO Data!", &scenario_lightmap_new_ao_data_block },
	{ _field_block, "Adjacent Bounce Vertices!", &scenario_lightmap_adjacent_bounce_vertex_block },
	{ _field_block, "Adjacent Bounce Indices!", &scenario_lightmap_adjacent_bounce_index_block },
	{ _field_long_integer, "Parameterization Method Checksum!" },
	{ _field_long_integer, "New AO checksum!" },
	{ _field_long_integer, "Material Count" },
	{ _field_long_integer, "Mesh Count" },
	{ _field_short_integer, "lightmap parameterization width" },
	{ _field_short_integer, "lightmap parameterization height" },
	{ _field_struct, "imported geometry*" },
	{ _field_block, "per mesh triangle mapping", &triangle_mapping_per_mesh_block },
	{ _field_struct, "shadow geometry*" },
	{ _field_struct, "Dynamic Light Shadow Geometry*" },
	{ _field_block, "light instance data", &scenario_lightmap_dynamic_light_instance_block },
	{ _field_block, "structure light instance data", &scenario_lightmap_structure_light_instance_block },
	{ _field_block, "extruded silhouette vertices", &s_scenario_lightmap_silhouette_vertex_block },
	{ _field_block, "extruded silhouette edges", &s_scenario_lightmap_silhouette_edge_block },
	{ _field_block, "extruded silhouette groups", &s_scenario_lightmap_silhouette_group_block },
	{ _field_block, "airprobes", &scenario_lightmap_airprobe_value_block },
	{ _field_block, "errors*", &global_error_report_categories_block },
	{ _field_block, "self_track", &global_self_track_block },
	{ _field_tag_reference, "forge per-pixel color" },
	{ _field_tag_reference, "forge per-pixel sun" },
	{ _field_real, "world scale ratio" },
	{ _field_terminator },
};

TAG_GROUP(scenario_lightmap, SCENARIO_LIGHTMAP_TAG)
{
	{ _field_long_integer, "job guid" },
	{ _field_block, "lightmap BSP references", &scenario_lightmap_bsp_data_reference_block },
	{ _field_terminator },
};

TAG_GROUP(scenario_wetness_bsp_data, SCENARIO_WETNESS_BSP_DATA_TAG)
{
	{ _field_short_integer, "bsp reference index" },
	{ _field_pad, "LHWCHFX", 2 },
	{ _field_long_integer, "structure BSP import checksum" },
	{ _field_long_integer, "lightmap BSP import checksum" },
	{ _field_long_integer, "design BSP checksum" },
	{ _field_long_integer, "air_probe offset" },
	{ _field_long_integer, "senary_probe offset" },
	{ _field_long_integer, "machinery_offset" },
	{ _field_tag_reference, "wetness pervertrex texture reference" },
	{ _field_block, "wetness", &wentness_bit_vector_block },
	{ _field_block, "wetness in bytes", &wentness_byte_vector_block },
	{ _field_block, "cluster_offset", &cluster_wetness_offset_block },
	{ _field_block, "instance_offset", &instance_wetness_instance_block },
	{ _field_terminator },
};

} // namespace blofeld

