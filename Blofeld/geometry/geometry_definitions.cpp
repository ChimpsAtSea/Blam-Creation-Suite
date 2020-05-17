#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(part_flags, 14)
	{
		OPTION("is water surface"),
		OPTION("per vertex lightmap part"),
		OPTION("debug flag instance part"),
		OPTION("subparts has uberlights info"),
		OPTION("draw cull distance medium"),
		OPTION("draw cull distance close"),
		OPTION("draw cull rendering shields"),
		OPTION("cannot single pass render"),
		OPTION("is transparent"),
		OPTION("cannot two pass"),
		OPTION("transparent should output depth for DoF#expensive"),
		OPTION("do not include in static lightmap"),
		OPTION("do not include in PVS generation"),
		OPTION("draw cull rendering active camo"),
	};

	TAG_ENUM(tessellation_mode_definition, 4)
	{
		OPTION("none"),
		OPTION("fixed x4 faces"),
		OPTION("fixed x9 faces"),
		OPTION("fixed x36 faces"),
	};

	TAG_ENUM(specialized_render_definition, 9)
	{
		OPTION("none"),
		OPTION("fail"),
		OPTION("fur"),
		OPTION("fur_stencil"),
		OPTION("decal"),
		OPTION("shield"),
		OPTION("water"),
		OPTION("lightmap_only"),
		OPTION("hologram"),
	};

	TAG_ENUM(compression_flags, 3)
	{
		OPTION("compressed position"),
		OPTION("compressed texcoord"),
		OPTION("compression optimized"),
	};

	TAG_ENUM(mesh_flags, 16)
	{
		OPTION("mesh has vertex color"),
		OPTION("use region index for sorting"),
		OPTION("use vertex buffers for indices"),
		OPTION("mesh has per-instance lighting (do not modify)"),
		OPTION("mesh is unindexed (do not modify)"),
		OPTION("subpart were merged"),
		OPTION("mesh has fur"),
		OPTION("mesh has decal"),
		OPTION("mesh doesnt use compressed position"),
		OPTION("use uncompressed vertex format"),
		OPTION("mesh is PCA"),
		OPTION("mesh compression determined"),
		OPTION("mesh has authored lightmap texture coords"),
		OPTION("mesh has a useful set of second texture coords"),
		OPTION("mesh has no lightmap"),
		OPTION("per vertex lighting"),
	};

	TAG_ENUM(mesh_vertex_type_definition, 54)
	{
		OPTION("world"),
		OPTION("rigid"),
		OPTION("skinned"),
		OPTION("particle_model"),
		OPTION("flat world"),
		OPTION("flat rigid"),
		OPTION("flat skinned"),
		OPTION("screen"),
		OPTION("debug"),
		OPTION("transparent"),
		OPTION("particle"),
		OPTION("unused0"),
		OPTION("light_volume"),
		OPTION("chud_simple"),
		OPTION("chud_fancy"),
		OPTION("decorator"),
		OPTION("position only"),
		OPTION("patchy_fog"),
		OPTION("water"),
		OPTION("ripple"),
		OPTION("implicit geometry"),
		OPTION("unused1"),
		OPTION("world_tessellated"),
		OPTION("rigid_tessellated"),
		OPTION("skinned_tessellated"),
		OPTION("shader_cache"),
		OPTION("structure_instance_imposter"),
		OPTION("object_instance_imposter"),
		OPTION("rigid compressed"),
		OPTION("skinned uncompressed"),
		OPTION("light volume precompiled"),
		OPTION("blendshape_rigid"),
		OPTION("blendshape_rigid_blendshaped"),
		OPTION("rigid_blendshaped"),
		OPTION("blendshape_skinned"),
		OPTION("blendshape_skinned_blendshaped"),
		OPTION("skinned_blendshaped"),
		OPTION("VirtualGeometryHWtess"),
		OPTION("VirtualGeometryMemexport"),
		OPTION("position_only"),
		OPTION("VirtualGeometryDebug"),
		OPTION("blendshapeRigidCompressed"),
		OPTION("skinnedUncompressedBlendshaped"),
		OPTION("blendshapeSkinnedCompressed"),
		OPTION("tracer"),
		OPTION("polyart"),
		OPTION("vectorart"),
		OPTION("rigid_boned"),
		OPTION("rigid_boned_2uv"),
		OPTION("blendshape_skinned_2uv"),
		OPTION("blendshape_skinned_2uv_blendshaped"),
		OPTION("skinned_2uv_blendshaped"),
		OPTION("polyartUV"),
		OPTION("blendshape_skinned_uncompressed_blendshaped"),
	};

	TAG_ENUM(mesh_transfer_vertex_type_definition, 4)
	{
		OPTION("No PRT"),
		OPTION("PRT Ambient"),
		OPTION("PRT Linear"),
		OPTION("PRT Quadratic"),
	};

	TAG_ENUM(mesh_lighting_policy_type_definition, 3)
	{
		OPTION("vertex color"),
		OPTION("single probe"),
		OPTION("prt ambient"),
	};

	TAG_ENUM(mesh_index_buffer_type_definition, 8)
	{
		OPTION("DEFAULT"),
		OPTION("line list"),
		OPTION("line strip"),
		OPTION("triangle list"),
		OPTION("triangle fan"),
		OPTION("triangle strip"),
		OPTION("quad list"),
		OPTION("rect list"),
	};

	TAG_ENUM(per_mesh_raw_data_flags, 3)
	{
		OPTION("indices are triangle strips"),
		OPTION("indices are triangle lists"),
		OPTION("indices are quad lists"),
	};

	TAG_ENUM(render_geometry_user_data_type_definition, 1)
	{
		OPTION("PRT Info"),
	};

	TAG_ENUM(render_geometry_flags, 9)
	{
		OPTION("processed*!"),
		OPTION("available*!"),
		OPTION("has valid budgets (really)*!"),
		OPTION("manual resource creation*!"),
		OPTION("keep raw geometry*!"),
		OPTION("dont use compressed vertex positions*!"),
		OPTION("pca animation table sorted*!"),
		OPTION("needs no lightmap uvs*!"),
		OPTION("always needs lightmap uvs*!"),
	};

	TAG_BLOCK(global_mesh_block, (8*1024-1))
	{
		FIELD( _field_block, "parts*", &part_block_block ),
		FIELD( _field_block, "subparts*", &subpart_block_block ),
		FIELD( _field_array, "vertex buffer indices*" ),
		FIELD( _field_short_integer, "index buffer index*" ),
		FIELD( _field_short_integer, "index buffer tessellation*" ),
		FIELD( _field_word_flags, "mesh flags*", &mesh_flags ),
		FIELD( _field_char_integer, "rigid node index*" ),
		FIELD( _field_char_enum, "vertex type*", &mesh_vertex_type_definition ),
		FIELD( _field_char_enum, "PRT vertex type*", &mesh_transfer_vertex_type_definition ),
		FIELD( _field_char_enum, "lighting policy", &mesh_lighting_policy_type_definition ),
		FIELD( _field_char_enum, "index buffer type*", &mesh_index_buffer_type_definition ),
		FIELD( _field_pad, "BAASDFIR", 1 ),
		FIELD( _field_short_integer, "pca mesh index*" ),
		FIELD( _field_block, "instance buckets*", &global_instance_bucket_block_block ),
		FIELD( _field_block, "water indices start", &indices_word_block_block ),
		FIELD( _field_real, "runtime bounding radius:world units*!" ),
		FIELD( _field_real_point_3d, "runtime bounding offset*!" ),
		FIELD( _field_block, "vertex keys*", &vertexKeyBlock_block ),
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
		FIELD( _field_char_enum, "specialized render", &specialized_render_definition ),
		FIELD( _field_word_flags, "part flags*", &part_flags ),
		FIELD( _field_word_integer, "budget vertex count" ),
		FIELD( _field_enum, "tessellation", &tessellation_mode_definition ),
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
		FIELD( _field_block, "instances", &instance_index_word_block_block ),
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
		FIELD( _field_word_flags, "compression flags*", &compression_flags ),
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
		FIELD( _field_block, "raw vertices*", &raw_vertex_block_block ),
		FIELD( _field_block, "raw indices*", &indices_word_block_block ),
		FIELD( _field_block, "raw indices32*", &indices_dword_block_block ),
		FIELD( _field_block, "raw water data", &raw_water_block_block ),
		FIELD( _field_block, "raw imposter data", &raw_imposter_brdf_block_block ),
		FIELD( _field_block, "raw instance imposter verts", &raw_instance_imposter_block_block ),
		FIELD( _field_block, "raw blendshapes*", &raw_blendshape_block_block ),
		FIELD( _field_long_integer, "per vertex lighting vertex size" ),
		FIELD( _field_short_integer, "parameterized texture width" ),
		FIELD( _field_short_integer, "parameterized texture height" ),
		FIELD( _field_long_flags, "flags", &per_mesh_raw_data_flags ),
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
		FIELD( _field_block, "raw water indices*", &indices_word_block_block ),
		FIELD( _field_block, "raw water vertices*", &raw_water_append_block_block ),
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
		FIELD( _field_block, "node map*", &node_map_byte_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(node_map_byte_block, BYTE_MAX)
	{
		FIELD( _field_char_integer, "node index*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(per_mesh_subpart_visibility_block, 64)
	{
		FIELD( _field_block, "bounding_sphere*", &sorting_position_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(per_mesh_prt_data_block, (8*1024-1))
	{
		FIELD( _field_data, "mesh pca data*" ),
		FIELD( _field_block, "per instance prt data", &per_instance_prt_data_block_block ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(per_instance_prt_data_block, UNSIGNED_SHORT_MAX)
	{
		FIELD( _field_data, "mesh pca data*" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(per_instance_lightmap_texcoords_block, UNSIGNED_SHORT_MAX)
	{
		FIELD( _field_block, "texture coordinates", &raw_vertex_block_block ),
		FIELD( _field_block, "texture coordinates (concise)", &raw_texcoord_block_block ),
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
		FIELD( _field_block, "Visibility array", &render_geometry_pvs_data_visibility_value_block_block ),
		FIELD( _field_block, "Per-block visibility offset array", &render_geometry_pvs_data_visibility_index_block_block ),
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

TAG_STRUCT(global_render_geometry_struct)
{
		FIELD( _field_explanation, "Render Geometry" ),
		FIELD( _field_long_flags, "runtime flags*!", &render_geometry_flags ),
		FIELD( _field_block, "meshes*", &global_mesh_block_block ),
		FIELD( _field_block, "PCA Mesh Indices*", &PCAMeshIndexBlock_block ),
		FIELD( _field_block, "compression info*", &compression_info_block_block ),
		FIELD( _field_block, "part sorting position*", &sorting_position_block_block ),
		FIELD( _field_block, "user data*", &user_data_block_block ),
		FIELD( _field_block, "per mesh temporary*", &per_mesh_raw_data_block_block ),
		FIELD( _field_pad, "pad3", 12 ),
		FIELD( _field_block, "per mesh node map*", &per_mesh_node_map_block_block ),
		FIELD( _field_block, "per mesh subpart visibility*", &per_mesh_subpart_visibility_block_block ),
		FIELD( _field_block, "per_mesh_prt_data*", &per_mesh_prt_data_block_block ),
		FIELD( _field_block, "per_instance_lightmap_texcoords*", &per_instance_lightmap_texcoords_block_block ),
		FIELD( _field_block, "water bounding box block*", &water_bounding_box_block_block ),
		FIELD( _field_pageable, "api resource" ),
		FIELD( _field_block, "Optional PVS data", &render_geometry_pvs_data_block_block ),
		FIELD( _field_block, "shapeNames*", &shapeNameBlock_block ),
		FIELD( _field_terminator )
};

TAG_STRUCT(global_render_geometry_user_data_header_struct)
{
		FIELD( _field_char_enum, "data type^*", &render_geometry_user_data_type_definition ),
		FIELD( _field_char_integer, "data count*" ),
		FIELD( _field_word_integer, "data size*" ),
		FIELD( _field_terminator )
};

} // namespace blofeld

