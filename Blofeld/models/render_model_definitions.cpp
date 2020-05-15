#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(imposter_mode_node, k_kilo)
{
	{ _field_string_id, "name" },
	{ _field_short_integer, "base node index" },
	{ _field_pad, "WAXI", 2 },
	{ _field_terminator },
};

TAG_BLOCK(render_model_region, MAXIMUM_REGIONS_PER_MODEL)
{
	{ _field_string_id, "name^*" },
	{ _field_block, "permutations*", &render_model_permutation_block },
	{ _field_terminator },
};

TAG_BLOCK(render_model_permutation, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
{
	{ _field_string_id, "name^*" },
	{ _field_short_integer, "mesh index*" },
	{ _field_short_integer, "mesh count*" },
	{ _field_string_id, "clone name*" },
	{ _field_long_flags, "instance mask 0-31*" },
	{ _field_long_flags, "instance mask 32-63*" },
	{ _field_long_flags, "instance mask 64-95*" },
	{ _field_long_flags, "instance mask 96-127*" },
	{ _field_terminator },
};

TAG_BLOCK(render_model_node, MAXIMUM_NODES_PER_MODEL)
{
	{ _field_string_id, "name^*" },
	{ _field_short_block_index, "parent node*" },
	{ _field_short_block_index, "first child node*" },
	{ _field_short_block_index, "next sibling node*" },
	{ _field_pad, "RELFLFLLE", 2 },
	{ _field_real_point_3d, "default translation*" },
	{ _field_real_quaternion, "default rotation*" },
	{ _field_real_vector_3d, "inverse forward*" },
	{ _field_real_vector_3d, "inverse left*" },
	{ _field_real_vector_3d, "inverse up*" },
	{ _field_real_point_3d, "inverse position*" },
	{ _field_real, "inverse scale*" },
	{ _field_real, "distance from parent*" },
	{ _field_custom, "Procedural Joint" },
	{ _field_char_enum, "procedure" },
	{ _field_char_enum, "procedure axis" },
	{ _field_pad, "pad", 2 },
	{ _field_short_block_index, "procedure node A" },
	{ _field_short_block_index, "procedure node B" },
	{ _field_real, "procedure var 1" },
	{ _field_real, "procedure var 2" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_BLOCK(render_model_marker_group, MAXIMUM_MARKER_GROUPS_PER_RENDER_MODEL)
{
	{ _field_string_id, "name^*" },
	{ _field_block, "markers*", &render_model_marker_block },
	{ _field_terminator },
};

TAG_BLOCK(render_model_marker, MAXIMUM_MARKERS_PER_RENDER_MODEL_MARKER_GROUP)
{
	{ _field_char_integer, "region index*" },
	{ _field_char_integer, "permutation index*" },
	{ _field_byte_integer, "node index*" },
	{ _field_byte_flags, "flags" },
	{ _field_real_point_3d, "translation*" },
	{ _field_real_quaternion, "rotation*" },
	{ _field_real, "scale" },
	{ _field_real_vector_3d, "direction*" },
	{ _field_terminator },
};

TAG_BLOCK(instance_node_map_mapping, MAXIMUM_NODES_PER_MODEL)
{
	{ _field_short_integer, "instance_node map region node index*" },
	{ _field_terminator },
};

TAG_BLOCK(volume_samples, k_max_volume_samples_per_render_model)
{
	{ _field_real_vector_3d, "position" },
	{ _field_array, "radiance transfer matrix*" },
	{ _field_terminator },
};

TAG_BLOCK(default_node_orientations, MAXIMUM_NODES_PER_MODEL)
{
	{ _field_real_quaternion, "rotation*" },
	{ _field_real_point_3d, "translation*" },
	{ _field_real, "scale*" },
	{ _field_terminator },
};

TAG_BLOCK(RenderModelBoneGroupBlock, MAXIMUM_BONE_GROUPS_PER_MODEL)
{
	{ _field_string_id, "name^*" },
	{ _field_block, "bones*", &RenderModelNodeIndexBlock_block },
	{ _field_terminator },
};

TAG_BLOCK(RenderModelNodeIndexBlock, MAXIMUM_NODES_PER_MODEL)
{
	{ _field_short_block_index, "node index^*" },
	{ _field_terminator },
};

TAG_GROUP(imposter_model, IMPOSTER_MODEL_TAG)
{
	{ _field_string_id, "name*" },
	{ _field_short_integer, "quality" },
	{ _field_pad, "NBOML", 2 },
	{ _field_real, "brightness adjustment" },
	{ _field_block, "node maps", &imposter_mode_node_block },
	{ _field_block, "regions*", &render_model_region_block },
	{ _field_custom, "render geometry" },
	{ _field_struct, "geometry*" },
	{ _field_custom },
	{ _field_terminator },
};

TAG_GROUP(render_model, RENDER_MODEL_TAG)
{
	{ _field_string_id, "name*" },
	{ _field_word_flags, "flags*" },
	{ _field_word_integer, "version!" },
	{ _field_custom },
	{ _field_long_integer, "runtime import info checksum!" },
	{ _field_custom },
	{ _field_block, "regions*", &render_model_region_block },
	{ _field_char_integer, "L1 section group index*:(low)" },
	{ _field_char_integer, "L2 section group index*:(high)" },
	{ _field_pad, "PUJJ", 2 },
	{ _field_long_block_index, "instance mesh index*" },
	{ _field_block, "instance placements", &global_render_model_instance_placement_block },
	{ _field_long_integer, "node list checksum*" },
	{ _field_block, "nodes*", &render_model_node_block },
	{ _field_block, "marker groups*", &render_model_marker_group_block },
	{ _field_block, "materials", &global_geometry_material_block },
	{ _field_block, "errors*", &global_error_report_categories_block },
	{ _field_real, "don\'t draw over camera cosine angle#dont draw fp model when camera > this angle cosine (-1,1) Sugg. -0.2. 0 disables." },
	{ _field_struct, "render geometry*" },
	{ _field_block, "node map mapping*", &instance_node_map_mapping_block },
	{ _field_block, "volume samples", &volume_samples_block },
	{ _field_block, "runtime node orientations!", &default_node_orientations_block },
	{ _field_block, "bone groups", &RenderModelBoneGroupBlock_block },
	{ _field_explanation, "Static Lightmap" },
	{ _field_tag_reference, "structure meta data*" },
	{ _field_tag_reference, "lightmap bsp data reference" },
	{ _field_tag_reference, "forge lightmap atlases" },
	{ _field_terminator },
};

TAG_GROUP(render_model_lightmap_atlas, RENDER_MODEL_LIGHTMAP_ATLAS_TAG)
{
	{ _field_struct, "atlas geometry*" },
	{ _field_real, "world scale ratio" },
	{ _field_terminator },
};

} // namespace blofeld

