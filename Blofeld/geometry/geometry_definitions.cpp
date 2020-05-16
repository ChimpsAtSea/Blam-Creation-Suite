#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(global_render_geometry_struct)
{
	FIELD( _field_explanation, "Render Geometry" ),
	FIELD( _field_long_flags, "runtime flags*!" ),
	FIELD( _field_block, "meshes*", &global_mesh_block ),
	FIELD( _field_block, "PCA Mesh Indices*", &PCAMeshIndexBlock ),
	FIELD( _field_block, "compression info*", &compression_info_block ),
	FIELD( _field_block, "part sorting position*", &sorting_position_block ),
	FIELD( _field_block, "user data*", &user_data_block ),
	FIELD( _field_block, "per mesh temporary*", &per_mesh_raw_data_block ),
	FIELD( _field_pad, "pad3", 12 ),
	FIELD( _field_block, "per mesh node map*", &per_mesh_node_map_block ),
	FIELD( _field_block, "per mesh subpart visibility*", &per_mesh_subpart_visibility_block ),
	FIELD( _field_block, "per_mesh_prt_data*", &per_mesh_prt_data_block ),
	FIELD( _field_block, "per_instance_lightmap_texcoords*", &per_instance_lightmap_texcoords_block ),
	FIELD( _field_block, "water bounding box block*", &water_bounding_box_block ),
	FIELD( _field_pageable, "api resource" ),
	FIELD( _field_block, "Optional PVS data", &render_geometry_pvs_data_block ),
	FIELD( _field_block, "shapeNames*", &shapeNameBlock ),
	FIELD( _field_terminator )
};

TAG_STRUCT(global_render_geometry_user_data_header_struct)
{
	FIELD( _field_char_enum, "data type^*" ),
	FIELD( _field_char_integer, "data count*" ),
	FIELD( _field_word_integer, "data size*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(global_mesh_block, (8*1024-1))
{
	FIELD( _field_block, "parts*", &part_block ),
	FIELD( _field_block, "subparts*", &subpart_block ),
	FIELD( _field_array, "vertex buffer indices*" ),
	FIELD( _field_short_integer, "index buffer index*" ),
	FIELD( _field_short_integer, "index buffer tessellation*" ),
	FIELD( _field_word_flags, "mesh flags*" ),
	FIELD( _field_char_integer, "rigid node index*" ),
	FIELD( _field_char_enum, "vertex type*" ),
	FIELD( _field_char_enum, "PRT vertex type*" ),
	FIELD( _field_char_enum, "lighting policy" ),
	FIELD( _field_char_enum, "index buffer type*" ),
	FIELD( _field_pad, "BAASDFIR", 1 ),
	FIELD( _field_short_integer, "pca mesh index*" ),
	FIELD( _field_block, "instance buckets*", &global_instance_bucket_block ),
	FIELD( _field_block, "water indices start", &indices_word_block ),
	FIELD( _field_real, "runtime bounding radius:world units*!" ),
	FIELD( _field_real_point_3d, "runtime bounding offset*!" ),
	FIELD( _field_block, "vertex keys*", &vertexKeyBlock ),
	FIELD( _field_short_block_index, "clone index*" ),
	FIELD( _field_short_integer, "cumulative part count (initialized by PVS building code)" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(part_block, BYTE_MAX)
{
	FIELD( _field_short_block_index, "render method index^*" ),
	FIELD( _field_short_block_index, "transparent sorting index*" ),
	FIELD( _field_long_integer, "index start*" ),
	FIELD( _field_long_integer, "index count*" ),
	FIELD( _field_short_integer, "subpart start*" ),
	FIELD( _field_short_integer, "subpart count*" ),
	FIELD( _field_char_integer, "part type*" ),
	FIELD( _field_char_enum, "specialized render" ),
	FIELD( _field_word_flags, "part flags*" ),
	FIELD( _field_word_integer, "budget vertex count" ),
	FIELD( _field_enum, "tessellation" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(subpart_block, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_long_integer, "index start*" ),
	FIELD( _field_long_integer, "index count*" ),
	FIELD( _field_short_block_index, "part index*" ),
	FIELD( _field_word_integer, "budget vertex count" ),
	FIELD( _field_dword_integer, "analytical light index" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(global_instance_bucket_block, (2*1024))
{
	FIELD( _field_short_integer, "mesh index*" ),
	FIELD( _field_short_integer, "definition index*" ),
	FIELD( _field_block, "instances", &instance_index_word_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(instance_index_word_block, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_short_integer, "instance index*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(indices_word_block, 2147483647L)
{
	FIELD( _field_short_integer, "word*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(vertexKeyBlock, MAXIMUM_VERTICES_PER_GEOMETRY_SECTION)
{
	FIELD( _field_long_integer, "key1*" ),
	FIELD( _field_long_integer, "key2*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(PCAMeshIndexBlock, (8*1024-1))
{
	FIELD( _field_long_block_index, "mesh index" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(compression_info_block, 1+UNSIGNED_SHORT_MAX)
{
	FIELD( _field_word_flags, "compression flags*" ),
	FIELD( _field_pad, "JOJOBOMO", 2 ),
	FIELD( _field_explanation, "WARNING" ),
	FIELD( _field_real_point_3d, "position bounds 0*" ),
	FIELD( _field_real_point_3d, "position bounds 1*" ),
	FIELD( _field_real_point_2d, "texcoord bounds 0*" ),
	FIELD( _field_real_point_2d, "texcoord bounds 1*" ),
	FIELD( _field_real, "unused0*" ),
	FIELD( _field_real, "unused1*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(sorting_position_block, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_real_plane_3d, "plane*" ),
	FIELD( _field_real_point_3d, "position*" ),
	FIELD( _field_real, "radius*" ),
	FIELD( _field_array, "node indices*" ),
	FIELD( _field_array, "node weights*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(user_data_block, 64)
{
	FIELD( _field_struct, "user data header*", &global_render_geometry_user_data_header_struct_struct_definition ),
	FIELD( _field_data, "user data*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(per_mesh_raw_data_block, (8*1024-1))
{
	FIELD( _field_block, "raw vertices*", &raw_vertex_block ),
	FIELD( _field_block, "raw indices*", &indices_word_block ),
	FIELD( _field_block, "raw indices32*", &indices_dword_block ),
	FIELD( _field_block, "raw water data", &raw_water_block ),
	FIELD( _field_block, "raw imposter data", &raw_imposter_brdf_block ),
	FIELD( _field_block, "raw instance imposter verts", &raw_instance_imposter_block ),
	FIELD( _field_block, "raw blendshapes*", &raw_blendshape_block ),
	FIELD( _field_long_integer, "per vertex lighting vertex size" ),
	FIELD( _field_short_integer, "parameterized texture width" ),
	FIELD( _field_short_integer, "parameterized texture height" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(raw_vertex_block, MAXIMUM_VERTICES_PER_GEOMETRY_SECTION)
{
	FIELD( _field_real_point_3d, "position*" ),
	FIELD( _field_real_point_2d, "texcoord*" ),
	FIELD( _field_real_point_3d, "normal*" ),
	FIELD( _field_real_point_3d, "binormal*" ),
	FIELD( _field_real_point_3d, "tangent*" ),
	FIELD( _field_real_point_2d, "lightmap texcoord*" ),
	FIELD( _field_array, "node indices*" ),
	FIELD( _field_array, "node weights*" ),
	FIELD( _field_real_point_3d, "vertex color*" ),
	FIELD( _field_real_point_2d, "texcoord1*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(indices_dword_block, 2147483647L)
{
	FIELD( _field_long_integer, "dword*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(raw_water_block, 1024)
{
	FIELD( _field_block, "raw water indices*", &indices_word_block ),
	FIELD( _field_block, "raw water vertices*", &raw_water_append_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(raw_water_append_block, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_real_point_2d, "base texcoord*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(raw_imposter_brdf_block, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_real_rgb_color, "diffuse" ),
	FIELD( _field_real_rgb_color, "ambient" ),
	FIELD( _field_real_rgb_color, "specular" ),
	FIELD( _field_real, "shininess" ),
	FIELD( _field_real, "alpha" ),
	FIELD( _field_real_argb_color, "change color tint of diffuse" ),
	FIELD( _field_real_argb_color, "change color tint of specular" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(raw_instance_imposter_block, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_real_vector_3d, "position" ),
	FIELD( _field_dword_integer, "color" ),
	FIELD( _field_real, "HDR scaler" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(raw_blendshape_block, MAXIMUM_VERTICES_PER_GEOMETRY_SECTION)
{
	FIELD( _field_real_vector_3d, "position*" ),
	FIELD( _field_real_vector_3d, "normal*" ),
	FIELD( _field_real_argb_color, "tension and ambient occlusion*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(per_mesh_node_map_block, (8*1024-1))
{
	FIELD( _field_block, "node map*", &node_map_byte_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(node_map_byte_block, BYTE_MAX)
{
	FIELD( _field_char_integer, "node index*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(per_mesh_subpart_visibility_block, 64)
{
	FIELD( _field_block, "bounding_sphere*", &sorting_position_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(per_mesh_prt_data_block, (8*1024-1))
{
	FIELD( _field_data, "mesh pca data*" ),
	FIELD( _field_block, "per instance prt data", &per_instance_prt_data_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(per_instance_prt_data_block, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_data, "mesh pca data*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(per_instance_lightmap_texcoords_block, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_block, "texture coordinates", &raw_vertex_block ),
	FIELD( _field_block, "texture coordinates (concise)", &raw_texcoord_block ),
	FIELD( _field_short_integer, "vertex buffer index*" ),
	FIELD( _field_pad, "HTJIAHA", 2 ),
	FIELD( _field_terminator )
};

TAG_BLOCK(raw_texcoord_block, MAXIMUM_VERTICES_PER_GEOMETRY_SECTION)
{
	FIELD( _field_real_point_2d, "texcoord*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(water_bounding_box_block, (8*1024-1))
{
	FIELD( _field_short_integer, "mesh index" ),
	FIELD( _field_short_integer, "part index" ),
	FIELD( _field_real_point_3d, "position bounds 0" ),
	FIELD( _field_real_point_3d, "position bounds 1" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_geometry_pvs_data_block, 16)
{
	FIELD( _field_block, "Visibility array", &render_geometry_pvs_data_visibility_value_block ),
	FIELD( _field_block, "Per-block visibility offset array", &render_geometry_pvs_data_visibility_index_block ),
	FIELD( _field_long_integer, "Bits per block" ),
	FIELD( _field_real_point_3d, "Object space grid AABB min" ),
	FIELD( _field_real_point_3d, "Object space grid AABB max" ),
	FIELD( _field_real_vector_3d, "Block Size" ),
	FIELD( _field_long_integer, "Num blocks X" ),
	FIELD( _field_long_integer, "Num blocks Y" ),
	FIELD( _field_long_integer, "Num blocks Z" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_geometry_pvs_data_visibility_value_block, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_dword_integer, "Value" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(render_geometry_pvs_data_visibility_index_block, UNSIGNED_SHORT_MAX)
{
	FIELD( _field_word_integer, "Index" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(shapeNameBlock, 8192)
{
	FIELD( _field_long_integer, "key*" ),
	FIELD( _field_long_string, "name*" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

