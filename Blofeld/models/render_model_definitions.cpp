#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(imposter_mode_node, k_kilo)
{
	FIELD( _field_string_id, "name" ),
	FIELD( _field_short_integer, "base node index" ),
	FIELD( _field_pad, "WAXI", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_model_region, MAXIMUM_REGIONS_PER_MODEL)
{
	FIELD( _field_string_id, "name^*" ),
	FIELD( _field_block, "permutations*", &render_model_permutation_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_model_permutation, MAXIMUM_PERMUTATIONS_PER_MODEL_REGION)
{
	FIELD( _field_string_id, "name^*" ),
	FIELD( _field_short_integer, "mesh index*" ),
	FIELD( _field_short_integer, "mesh count*" ),
	FIELD( _field_string_id, "clone name*" ),
	FIELD( _field_long_flags, "instance mask 0-31*" ),
	FIELD( _field_long_flags, "instance mask 32-63*" ),
	FIELD( _field_long_flags, "instance mask 64-95*" ),
	FIELD( _field_long_flags, "instance mask 96-127*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_model_node, MAXIMUM_NODES_PER_MODEL)
{
	FIELD( _field_string_id, "name^*" ),
	FIELD( _field_short_block_index, "parent node*" ),
	FIELD( _field_short_block_index, "first child node*" ),
	FIELD( _field_short_block_index, "next sibling node*" ),
	FIELD( _field_pad, "RELFLFLLE", 2 ),
	FIELD( _field_real_point_3d, "default translation*" ),
	FIELD( _field_real_quaternion, "default rotation*" ),
	FIELD( _field_real_vector_3d, "inverse forward*" ),
	FIELD( _field_real_vector_3d, "inverse left*" ),
	FIELD( _field_real_vector_3d, "inverse up*" ),
	FIELD( _field_real_point_3d, "inverse position*" ),
	FIELD( _field_real, "inverse scale*" ),
	FIELD( _field_real, "distance from parent*" ),
	FIELD( _field_custom, "Procedural Joint" ),
	FIELD( _field_char_enum, "procedure" ),
	FIELD( _field_char_enum, "procedure axis" ),
	FIELD( _field_pad, "pad", 2 ),
	FIELD( _field_short_block_index, "procedure node A" ),
	FIELD( _field_short_block_index, "procedure node B" ),
	FIELD( _field_real, "procedure var 1" ),
	FIELD( _field_real, "procedure var 2" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_model_marker_group, MAXIMUM_MARKER_GROUPS_PER_RENDER_MODEL)
{
	FIELD( _field_string_id, "name^*" ),
	FIELD( _field_block, "markers*", &render_model_marker_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_model_marker, MAXIMUM_MARKERS_PER_RENDER_MODEL_MARKER_GROUP)
{
	FIELD( _field_char_integer, "region index*" ),
	FIELD( _field_char_integer, "permutation index*" ),
	FIELD( _field_byte_integer, "node index*" ),
	FIELD( _field_byte_flags, "flags" ),
	FIELD( _field_real_point_3d, "translation*" ),
	FIELD( _field_real_quaternion, "rotation*" ),
	FIELD( _field_real, "scale" ),
	FIELD( _field_real_vector_3d, "direction*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(instance_node_map_mapping, MAXIMUM_NODES_PER_MODEL)
{
	FIELD( _field_short_integer, "instance_node map region node index*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(volume_samples, k_max_volume_samples_per_render_model)
{
	FIELD( _field_real_vector_3d, "position" ),
	FIELD( _field_array, "radiance transfer matrix*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(default_node_orientations, MAXIMUM_NODES_PER_MODEL)
{
	FIELD( _field_real_quaternion, "rotation*" ),
	FIELD( _field_real_point_3d, "translation*" ),
	FIELD( _field_real, "scale*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(RenderModelBoneGroupBlock, MAXIMUM_BONE_GROUPS_PER_MODEL)
{
	FIELD( _field_string_id, "name^*" ),
	FIELD( _field_block, "bones*", &RenderModelNodeIndexBlock_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(RenderModelNodeIndexBlock, MAXIMUM_NODES_PER_MODEL)
{
	FIELD( _field_short_block_index, "node index^*" ),
	FIELD( _field_terminator )
};

TAG_GROUP(imposter_model, IMPOSTER_MODEL_TAG)
{
	FIELD( _field_string_id, "name*" ),
	FIELD( _field_short_integer, "quality" ),
	FIELD( _field_pad, "NBOML", 2 ),
	FIELD( _field_real, "brightness adjustment" ),
	FIELD( _field_block, "node maps", &imposter_mode_node_block ),
	FIELD( _field_block, "regions*", &render_model_region_block ),
	FIELD( _field_custom, "render geometry" ),
	FIELD( _field_struct, "geometry*" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_GROUP(render_model, RENDER_MODEL_TAG)
{
	FIELD( _field_string_id, "name*" ),
	FIELD( _field_word_flags, "flags*" ),
	FIELD( _field_word_integer, "version!" ),
	FIELD( _field_custom ),
	FIELD( _field_long_integer, "runtime import info checksum!" ),
	FIELD( _field_custom ),
	FIELD( _field_block, "regions*", &render_model_region_block ),
	FIELD( _field_char_integer, "L1 section group index*:(low)" ),
	FIELD( _field_char_integer, "L2 section group index*:(high)" ),
	FIELD( _field_pad, "PUJJ", 2 ),
	FIELD( _field_long_block_index, "instance mesh index*" ),
	FIELD( _field_block, "instance placements", &global_render_model_instance_placement_block ),
	FIELD( _field_long_integer, "node list checksum*" ),
	FIELD( _field_block, "nodes*", &render_model_node_block ),
	FIELD( _field_block, "marker groups*", &render_model_marker_group_block ),
	FIELD( _field_block, "materials", &global_geometry_material_block ),
	FIELD( _field_block, "errors*", &global_error_report_categories_block ),
	FIELD( _field_real, "don\'t draw over camera cosine angle#dont draw fp model when camera > this angle cosine (-1,1) Sugg. -0.2. 0 disables." ),
	FIELD( _field_struct, "render geometry*" ),
	FIELD( _field_block, "node map mapping*", &instance_node_map_mapping_block ),
	FIELD( _field_block, "volume samples", &volume_samples_block ),
	FIELD( _field_block, "runtime node orientations!", &default_node_orientations_block ),
	FIELD( _field_block, "bone groups", &RenderModelBoneGroupBlock_block ),
	FIELD( _field_explanation, "Static Lightmap" ),
	FIELD( _field_tag_reference, "structure meta data*" ),
	FIELD( _field_tag_reference, "lightmap bsp data reference" ),
	FIELD( _field_tag_reference, "forge lightmap atlases" ),
	FIELD( _field_terminator )
};

TAG_GROUP(render_model_lightmap_atlas, RENDER_MODEL_LIGHTMAP_ATLAS_TAG)
{
	FIELD( _field_struct, "atlas geometry*" ),
	FIELD( _field_real, "world scale ratio" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

