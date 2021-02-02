#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GLOBAL_MESH_BLOCK_ID { 0xEBB348BB, 0xA7C04CC8, 0xA6E51515, 0xA5A99C7C }
	TAG_BLOCK(
		global_mesh_block,
		"mesh",
		(8*1024-1),
		"s_mesh",
		GLOBAL_MESH_BLOCK_ID)
	{
		{ _field_block, "parts", &part_block },
		{ _field_block, "subparts", &subpart_block },
		{ _field_array, "vertex buffer indices", &vertex_buffer_indices_word_array },
		{ _field_short_integer, "index buffer index" },
		{ _field_short_integer, "index buffer tessellation" },
		{ _field_word_flags, "mesh flags", &mesh_flags },
		{ _field_char_integer, "rigid node index" },
		{ _field_char_enum, "vertex type", &mesh_vertex_type_definition },
		{ _field_char_enum, "PRT vertex type", &mesh_transfer_vertex_type_definition },
		{ _field_char_enum, "lighting policy", &mesh_lighting_policy_type_definition },
		{ _field_char_enum, "index buffer type", &mesh_index_buffer_type_definition },
		FIELD_PAD("BAASDFIR", nullptr, 1),
		{ _field_short_integer, "pca mesh index" },
		{ _field_block, "instance buckets", &global_instance_bucket_block },
		{ _field_block, "water indices start", &indices_word_block },
		{ _field_real, "runtime bounding radius", "world units" },
		{ _field_real_point_3d, "runtime bounding offset" },
		{ _field_block, "vertex keys", &vertexKeyBlock_block },
		{ _field_short_block_index, "clone index", &global_mesh_block },
		{ _field_short_integer, "cumulative part count (initialized by PVS building code)" },
		{ _field_terminator }
	};

	#define PART_BLOCK_ID { 0x4A81849D, 0xFBEE42B4, 0xA3C956AC, 0xE6530F18 }
	TAG_BLOCK(
		part_block,
		"part_block",
		BYTE_MAX,
		"s_part",
		PART_BLOCK_ID)
	{
		{ _field_short_block_index, "render method index", &global_geometry_material_block },
		{ _field_short_block_index, "transparent sorting index", &sorting_position_block },
		{ _field_long_integer, "index start" },
		{ _field_long_integer, "index count" },
		{ _field_short_integer, "subpart start" },
		{ _field_short_integer, "subpart count" },
		{ _field_char_integer, "part type" },
		{ _field_char_enum, "specialized render", &specialized_render_definition },
		{ _field_word_flags, "part flags", &part_flags },
		{ _field_word_integer, "budget vertex count" },
		{ _field_enum, "tessellation", &tessellation_mode_definition },
		{ _field_terminator }
	};

	#define SORTING_POSITION_BLOCK_ID { 0x684EF46D, 0xB52E4111, 0x8E20FEFB, 0xEEFB1C9E }
	TAG_BLOCK(
		sorting_position_block,
		"sorting_position_block",
		UNSIGNED_SHORT_MAX,
		"s_positioning",
		SORTING_POSITION_BLOCK_ID)
	{
		{ _field_real_plane_3d, "plane" },
		{ _field_real_point_3d, "position" },
		{ _field_real, "radius" },
		{ _field_array, "node indices", &node_indices_array },
		{ _field_array, "node weights", &node_weights_implicit_array },
		{ _field_terminator }
	};

	#define SUBPART_BLOCK_ID { 0x09109A33, 0x9C27436F, 0xB438BFBA, 0xB6971BAE }
	TAG_BLOCK(
		subpart_block,
		"subpart_block",
		UNSIGNED_SHORT_MAX,
		"s_subpart",
		SUBPART_BLOCK_ID)
	{
		{ _field_long_integer, "index start" },
		{ _field_long_integer, "index count" },
		{ _field_short_block_index, "part index", &part_block },
		{ _field_word_integer, "budget vertex count" },
		{ _field_dword_integer, "analytical light index" },
		{ _field_terminator }
	};

	#define GLOBAL_INSTANCE_BUCKET_BLOCK_ID { 0x0C556069, 0xC7904BAA, 0xA39F96E0, 0xD9B27120 }
	TAG_BLOCK(
		global_instance_bucket_block,
		"global_instance_bucket_block",
		(2*1024),
		"s_instance_bucket",
		GLOBAL_INSTANCE_BUCKET_BLOCK_ID)
	{
		{ _field_short_integer, "mesh index" },
		{ _field_short_integer, "definition index" },
		{ _field_block, "instances", &instance_index_word_block },
		{ _field_terminator }
	};

	#define INSTANCE_INDEX_WORD_BLOCK_ID { 0xBB11BC2A, 0x52524BAC, 0x993757BE, 0x8027853E }
	TAG_BLOCK(
		instance_index_word_block,
		"instance_index_word_block",
		UNSIGNED_SHORT_MAX,
		"word",
		INSTANCE_INDEX_WORD_BLOCK_ID)
	{
		{ _field_short_integer, "instance index" },
		{ _field_terminator }
	};

	#define INDICES_WORD_BLOCK_ID { 0x92F5E99B, 0xFC5B45B5, 0xA594973C, 0x688E96A8 }
	TAG_BLOCK(
		indices_word_block,
		"indices_word_block",
		2147483647L,
		"word",
		INDICES_WORD_BLOCK_ID)
	{
		{ _field_short_integer, "word" },
		{ _field_terminator }
	};

	#define VERTEXKEYBLOCK_ID { 0xDAD1C118, 0x570F4E4E, 0xAF86840B, 0x860BB1E0 }
	TAG_BLOCK(
		vertexKeyBlock_block,
		"vertexKeyBlock",
		MAXIMUM_VERTICES_PER_GEOMETRY_SECTION,
		"s_mesh::VertexKey",
		VERTEXKEYBLOCK_ID)
	{
		{ _field_long_integer, "key1" },
		{ _field_long_integer, "key2" },
		{ _field_terminator }
	};

	#define PCAMESHINDEXBLOCK_ID { 0x47C61323, 0x1F274D16, 0x97CD4802, 0xCCA9FFA4 }
	TAG_BLOCK(
		PCAMeshIndexBlock_block,
		"PCAMeshIndexBlock",
		(8*1024-1),
		"long",
		PCAMESHINDEXBLOCK_ID)
	{
		{ _field_long_block_index, "mesh index", &global_mesh_block },
		{ _field_terminator }
	};

	#define COMPRESSION_INFO_BLOCK_ID { 0xFE51FDAC, 0x62FF4778, 0xA8C33054, 0xA023A96C }
	TAG_BLOCK(
		compression_info_block,
		"compression_info_block",
		1+UNSIGNED_SHORT_MAX,
		"s_compression_info",
		COMPRESSION_INFO_BLOCK_ID)
	{
		{ _field_word_flags, "compression flags", &compression_flags },
		FIELD_PAD("JOJOBOMO", nullptr, 2),
		{ _field_explanation, "WARNING", "The following fields are mislabeled for legacy reasons.The actual order is:\nposition_bounds.x0 position_bounds.x1 position_bounds.y0\nposition_bounds.y1 position_bounds.z0 position_bounds.z1\n\ntexcoord_bounds.x0 texcoord_bounds.x1\ntexcoord_bounds.y0 texcoord_bounds.y1\n" },
		{ _field_real_point_3d, "position bounds 0" },
		{ _field_real_point_3d, "position bounds 1" },
		{ _field_real_point_2d, "texcoord bounds 0" },
		{ _field_real_point_2d, "texcoord bounds 1" },
		{ _field_real, "unused0" },
		{ _field_real, "unused1" },
		{ _field_terminator }
	};

	#define USER_DATA_BLOCK_ID { 0x3BBE7E4E, 0x475949EF, 0xBDD01F25, 0x7C2F2589 }
	TAG_BLOCK(
		user_data_block,
		"user_data_block",
		64,
		"s_render_geometry_user_data",
		USER_DATA_BLOCK_ID)
	{
		{ _field_struct, "user data header", &global_render_geometry_user_data_header_struct },
		{ _field_data, "user data" },
		{ _field_terminator }
	};

	#define PER_MESH_RAW_DATA_BLOCK_ID { 0x52900AB0, 0x23054B64, 0xBA861C13, 0x2CC95C01 }
	TAG_BLOCK(
		per_mesh_raw_data_block,
		"per_mesh_raw_data_block",
		(8*1024-1),
		"s_per_mesh_raw_data",
		PER_MESH_RAW_DATA_BLOCK_ID)
	{
		{ _field_block, "raw vertices", &raw_vertex_block },
		{ _field_block, "raw indices", &indices_word_block },
		{ _field_block, "raw indices32", &indices_dword_block },
		{ _field_block, "raw water data", &raw_water_block },
		{ _field_block, "raw imposter data", &raw_imposter_brdf_block },
		{ _field_block, "raw instance imposter verts", &raw_instance_imposter_block },
		{ _field_block, "raw blendshapes", &raw_blendshape_block },
		{ _field_long_integer, "per vertex lighting vertex size" },
		{ _field_short_integer, "parameterized texture width" },
		{ _field_short_integer, "parameterized texture height" },
		{ _field_long_flags, "flags", &per_mesh_raw_data_flags },
		{ _field_terminator }
	};

	#define RAW_VERTEX_BLOCK_ID { 0x98F6C836, 0xCD9343C5, 0xBA313188, 0x05BDBA77 }
	TAG_BLOCK(
		raw_vertex_block,
		"raw_vertex_block",
		MAXIMUM_VERTICES_PER_GEOMETRY_SECTION,
		"s_raw_vertex",
		RAW_VERTEX_BLOCK_ID)
	{
		{ _field_real_point_3d, "position" },
		{ _field_real_point_2d, "texcoord" },
		{ _field_real_point_3d, "normal" },
		{ _field_real_point_3d, "binormal" },
		{ _field_real_point_3d, "tangent" },
		{ _field_real_point_2d, "lightmap texcoord" },
		{ _field_array, "node indices", &node_indices_array },
		{ _field_array, "node weights", &node_weights_complete_array },
		{ _field_real_point_3d, "vertex color" },
		{ _field_real_point_2d, "texcoord1" },
		{ _field_terminator }
	};

	#define INDICES_DWORD_BLOCK_ID { 0x73514B8E, 0x5EA54978, 0x8AAA440D, 0x39E1C24C }
	TAG_BLOCK(
		indices_dword_block,
		"indices_dword_block",
		2147483647L,
		"dword",
		INDICES_DWORD_BLOCK_ID)
	{
		{ _field_long_integer, "dword" },
		{ _field_terminator }
	};

	#define RAW_WATER_BLOCK_ID { 0x4F09C644, 0x93ED4F12, 0xA9D754E1, 0x6E7054C7 }
	TAG_BLOCK(
		raw_water_block,
		"raw_water_block",
		1024,
		"s_raw_water_data",
		RAW_WATER_BLOCK_ID)
	{
		{ _field_block, "raw water indices", &indices_word_block },
		{ _field_block, "raw water vertices", &raw_water_append_block },
		{ _field_terminator }
	};

	#define RAW_WATER_APPEND_BLOCK_ID { 0xB6F83085, 0xC99A41B1, 0xB7F454A8, 0x5AE2008E }
	TAG_BLOCK(
		raw_water_append_block,
		"raw_water_append_block",
		UNSIGNED_SHORT_MAX,
		"s_raw_water_append",
		RAW_WATER_APPEND_BLOCK_ID)
	{
		{ _field_real_point_2d, "base texcoord" },
		{ _field_terminator }
	};

	#define RAW_IMPOSTER_BRDF_BLOCK_ID { 0xC248C753, 0x679B4873, 0x82D2CC05, 0xBB8A57A9 }
	TAG_BLOCK(
		raw_imposter_brdf_block,
		"raw_imposter_brdf_block",
		UNSIGNED_SHORT_MAX,
		"s_raw_imposter_brdf",
		RAW_IMPOSTER_BRDF_BLOCK_ID)
	{
		{ _field_real_rgb_color, "diffuse" },
		{ _field_real_rgb_color, "ambient" },
		{ _field_real_rgb_color, "specular" },
		{ _field_real, "shininess" },
		{ _field_real, "alpha" },
		{ _field_real_argb_color, "change color tint of diffuse" },
		{ _field_real_argb_color, "change color tint of specular" },
		{ _field_terminator }
	};

	#define RAW_INSTANCE_IMPOSTER_BLOCK_ID { 0x22CF4DD4, 0xFDE8470E, 0x83FA52AB, 0x7303B0CC }
	TAG_BLOCK(
		raw_instance_imposter_block,
		"raw_instance_imposter_block",
		UNSIGNED_SHORT_MAX,
		"s_raw_instance_imposter_vertex",
		RAW_INSTANCE_IMPOSTER_BLOCK_ID)
	{
		{ _field_real_vector_3d, "position" },
		{ _field_dword_integer, "color" },
		{ _field_real, "HDR scaler" },
		{ _field_terminator }
	};

	#define RAW_BLENDSHAPE_BLOCK_ID { 0x7D5E5593, 0xF97E4DB9, 0x8E97BC00, 0x72EC5CE9 }
	TAG_BLOCK(
		raw_blendshape_block,
		"raw_blendshape_block",
		MAXIMUM_VERTICES_PER_GEOMETRY_SECTION,
		"RawBlendshapeVertex",
		RAW_BLENDSHAPE_BLOCK_ID)
	{
		{ _field_real_vector_3d, "position" },
		{ _field_real_vector_3d, "normal" },
		{ _field_real_argb_color, "tension and ambient occlusion" },
		{ _field_terminator }
	};

	#define PER_MESH_NODE_MAP_BLOCK_ID { 0xC23B2003, 0x2AA6450C, 0x8B2497D9, 0x6C50810F }
	TAG_BLOCK(
		per_mesh_node_map_block,
		"per_mesh_node_map_block",
		(8*1024-1),
		"s_per_mesh_node_map",
		PER_MESH_NODE_MAP_BLOCK_ID)
	{
		{ _field_block, "node map", &node_map_byte_block },
		{ _field_terminator }
	};

	#define NODE_MAP_BYTE_BLOCK_ID { 0x77DB2A4A, 0x0EC6490D, 0x822EA727, 0x3026F880 }
	TAG_BLOCK(
		node_map_byte_block,
		"node_map_byte_block",
		BYTE_MAX,
		"byte",
		NODE_MAP_BYTE_BLOCK_ID)
	{
		{ _field_char_integer, "node index" },
		{ _field_terminator }
	};

	#define PER_MESH_SUBPART_VISIBILITY_BLOCK_ID { 0x06360432, 0x14BE47E0, 0x818AB223, 0xA6DB06A2 }
	TAG_BLOCK(
		per_mesh_subpart_visibility_block,
		"per_mesh_subpart_visibility_block",
		64,
		"s_per_mesh_subpart_visibility",
		PER_MESH_SUBPART_VISIBILITY_BLOCK_ID)
	{
		{ _field_block, "bounding_sphere", &sorting_position_block },
		{ _field_terminator }
	};

	#define PER_MESH_PRT_DATA_BLOCK_ID { 0x7ECBA5AF, 0x689D4385, 0xBE237733, 0x820D7068 }
	TAG_BLOCK(
		per_mesh_prt_data_block,
		"per_mesh_prt_data_block",
		(8*1024-1),
		"s_per_mesh_prt_data",
		PER_MESH_PRT_DATA_BLOCK_ID)
	{
		{ _field_data, "mesh pca data" },
		{ _field_block, "per instance prt data", &per_instance_prt_data_block },
		{ _field_terminator }
	};

	#define PER_INSTANCE_PRT_DATA_BLOCK_ID { 0x836CA33D, 0x37D944DB, 0xBBEFF22E, 0x6F5D159B }
	TAG_BLOCK(
		per_instance_prt_data_block,
		"per_instance_prt_data_block",
		UNSIGNED_SHORT_MAX,
		"s_per_instance_prt_data",
		PER_INSTANCE_PRT_DATA_BLOCK_ID)
	{
		{ _field_data, "mesh pca data" },
		{ _field_terminator }
	};

	#define PER_INSTANCE_LIGHTMAP_TEXCOORDS_BLOCK_ID { 0xF880A4D0, 0xF9F848AE, 0x99B436D5, 0xC2C552E5 }
	TAG_BLOCK(
		per_instance_lightmap_texcoords_block,
		"per_instance_lightmap_texcoords_block",
		UNSIGNED_SHORT_MAX,
		"s_per_instance_lightmap_texcoords",
		PER_INSTANCE_LIGHTMAP_TEXCOORDS_BLOCK_ID)
	{
		{ _field_block, "texture coordinates", &raw_vertex_block },
		{ _field_block, "texture coordinates (concise)", &raw_texcoord_block },
		{ _field_short_integer, "vertex buffer index" },
		FIELD_PAD("HTJIAHA", nullptr, 2),
		{ _field_terminator }
	};

	#define RAW_TEXCOORD_BLOCK_ID { 0x6E3D7633, 0x56F5492D, 0x84F0F79E, 0x0E70CD1A }
	TAG_BLOCK(
		raw_texcoord_block,
		"raw_texcoord_block",
		MAXIMUM_VERTICES_PER_GEOMETRY_SECTION,
		"s_raw_texcoord",
		RAW_TEXCOORD_BLOCK_ID)
	{
		{ _field_real_point_2d, "texcoord" },
		{ _field_terminator }
	};

	#define WATER_BOUNDING_BOX_BLOCK_ID { 0xF28EACD0, 0xF1FF41A9, 0x96B930D0, 0xC2A5A259 }
	TAG_BLOCK(
		water_bounding_box_block,
		"water_bounding_box_block",
		(8*1024-1),
		"s_water_bounding_box",
		WATER_BOUNDING_BOX_BLOCK_ID)
	{
		{ _field_short_integer, "mesh index" },
		{ _field_short_integer, "part index" },
		{ _field_real_point_3d, "position bounds 0" },
		{ _field_real_point_3d, "position bounds 1" },
		{ _field_terminator }
	};

	#define VERTEX_BUFFERS_BLOCK_ID { 0x10DD7329, 0xE07F4880, 0xBC8BB79A, 0x253227EE }
	TAG_BLOCK(
		vertex_buffers_block,
		"vertex_buffers_block",
		UNSIGNED_SHORT_MAX,
		"c_rasterizer_vertex_buffer",
		VERTEX_BUFFERS_BLOCK_ID)
	{
		{ _field_byte_integer, "declaration type" },
		{ _field_byte_integer, "stride" },
		FIELD_PAD("vertex buffer pad", nullptr, 2),
		{ _field_dword_integer, "count" },
		{ _field_long_integer, "d3d hardware format" },
		{ _field_terminator }
	};

	#define INDEX_BUFFERS_BLOCK_ID { 0xC747C29E, 0x88D1483B, 0x9336EC15, 0xF00BDD09 }
	TAG_BLOCK(
		index_buffers_block,
		"index_buffers_block",
		(8*1024-1),
		"c_rasterizer_index_buffer",
		INDEX_BUFFERS_BLOCK_ID)
	{
		{ _field_byte_integer, "declaration type" },
		{ _field_byte_integer, "stride" },
		FIELD_PAD("vertex buffer pad", nullptr, 2),
		{ _field_dword_integer, "count" },
		{ _field_long_integer, "d3d hardware format" },
		{ _field_terminator }
	};

	#define RENDER_VERTEX_BUFFER_BLOCK_ID { 0xFB026490, 0xD41E4141, 0xA8A023BE, 0x06497B4E }
	TAG_BLOCK(
		render_vertex_buffer_block,
		"render_vertex_buffer_block",
		UNSIGNED_SHORT_MAX,
		"s_tag_interop",
		RENDER_VERTEX_BUFFER_BLOCK_ID)
	{
		{ _field_api_interop, "vertex buffer interop", &render_vertex_buffer_descriptor_struct },
		{ _field_terminator }
	};

	#define RENDER_INDEX_BUFFER_BLOCK_ID { 0x034F8376, 0xE6BB4E0E, 0x8039CB4B, 0xE53EC97C }
	TAG_BLOCK(
		render_index_buffer_block,
		"render_index_buffer_block",
		(8*1024-1),
		"s_tag_interop",
		RENDER_INDEX_BUFFER_BLOCK_ID)
	{
		{ _field_api_interop, "index buffer interop", &render_index_buffer_descriptor_struct },
		{ _field_terminator }
	};

	#define RENDER_GEOMETRY_PVS_DATA_BLOCK_ID { 0x00401E2C, 0x6BD94BE6, 0xAA5D6719, 0xC5566AFD }
	TAG_BLOCK(
		render_geometry_pvs_data_block,
		"render_geometry_pvs_data_block",
		16,
		"s_render_geometry_pvs_data",
		RENDER_GEOMETRY_PVS_DATA_BLOCK_ID)
	{
		{ _field_block, "Visibility array", &render_geometry_pvs_data_visibility_value_block },
		{ _field_block, "Per-block visibility offset array", &render_geometry_pvs_data_visibility_index_block },
		{ _field_long_integer, "Bits per block" },
		{ _field_real_point_3d, "Object space grid AABB min" },
		{ _field_real_point_3d, "Object space grid AABB max" },
		{ _field_real_vector_3d, "Block Size" },
		{ _field_long_integer, "Num blocks X" },
		{ _field_long_integer, "Num blocks Y" },
		{ _field_long_integer, "Num blocks Z" },
		{ _field_terminator }
	};

	#define RENDER_GEOMETRY_PVS_DATA_VISIBILITY_VALUE_BLOCK_ID { 0xCDAA41DE, 0xDEE94EC6, 0x9E9B798E, 0x24E8F6F7 }
	TAG_BLOCK(
		render_geometry_pvs_data_visibility_value_block,
		"render_geometry_pvs_data_visibility_value_block",
		UNSIGNED_SHORT_MAX,
		"dword",
		RENDER_GEOMETRY_PVS_DATA_VISIBILITY_VALUE_BLOCK_ID)
	{
		{ _field_dword_integer, "Value" },
		{ _field_terminator }
	};

	#define RENDER_GEOMETRY_PVS_DATA_VISIBILITY_INDEX_BLOCK_ID { 0x00CB84FF, 0xD9574E41, 0xA4708748, 0x921E2594 }
	TAG_BLOCK(
		render_geometry_pvs_data_visibility_index_block,
		"render_geometry_pvs_data_visibility_index_block",
		UNSIGNED_SHORT_MAX,
		"word",
		RENDER_GEOMETRY_PVS_DATA_VISIBILITY_INDEX_BLOCK_ID)
	{
		{ _field_word_integer, "Index" },
		{ _field_terminator }
	};

	#define SHAPENAMEBLOCK_ID { 0x398CE67C, 0x3A7E4F70, 0xB41443F0, 0x73D6FB49 }
	TAG_BLOCK(
		shapeNameBlock_block,
		"shapeNameBlock",
		8192,
		"s_render_geometry::ShapeName",
		SHAPENAMEBLOCK_ID)
	{
		{ _field_long_integer, "key" },
		{ _field_long_string, "name" },
		{ _field_terminator }
	};

	#define NODE_INDICES_ARRAY_ID { 0x96D9B877, 0x7D854A1A, 0x94447B36, 0x3D993ECB }
	TAG_ARRAY(
		node_indices_array,
		"node_indices_array",
		4,
		"byte",
		NODE_INDICES_ARRAY_ID)
	{
		{ _field_byte_integer, "node index" },
		{ _field_terminator }
	};

	#define NODE_WEIGHTS_IMPLICIT_ARRAY_ID { 0x688AC376, 0x93AA40C8, 0xB49A447E, 0x88C1B821 }
	TAG_ARRAY(
		node_weights_implicit_array,
		"node_weights_implicit_array",
		4-1,
		"real",
		NODE_WEIGHTS_IMPLICIT_ARRAY_ID)
	{
		{ _field_real, "node weight" },
		{ _field_terminator }
	};

	#define VERTEX_BUFFER_INDICES_WORD_ARRAY_ID { 0x5E95A6C9, 0x37604276, 0xBD4EEEA3, 0x52D11A95 }
	TAG_ARRAY(
		vertex_buffer_indices_word_array,
		"vertex_buffer_indices_word_array",
		((sizeof(*numberof_sizeof_proxy<(sizeof(((((s_mesh *)0)->vertex_buffer_indices)))/sizeof(((((s_mesh *)0)->vertex_buffer_indices))[0]))>(((((s_mesh *)0)->vertex_buffer_indices)))))),
		"(((s_mesh *",
		VERTEX_BUFFER_INDICES_WORD_ARRAY_ID)
	{
		{ _field_word_integer, "vertex buffer index" },
		{ _field_terminator }
	};

	#define NODE_WEIGHTS_COMPLETE_ARRAY_ID { 0x93F6CB70, 0x935C4824, 0xAFBCAA80, 0x199C0BA7 }
	TAG_ARRAY(
		node_weights_complete_array,
		"node_weights_complete_array",
		4,
		"real",
		NODE_WEIGHTS_COMPLETE_ARRAY_ID)
	{
		{ _field_real, "node weight" },
		{ _field_terminator }
	};

	#define GLOBAL_RENDER_GEOMETRY_STRUCT_ID { 0x25CE2A94, 0x081545BA, 0x9E9A2690, 0xEFDBE832 }
	TAG_STRUCT(
		global_render_geometry_struct,
		"global_render_geometry_struct",
		"s_render_geometry",
		GLOBAL_RENDER_GEOMETRY_STRUCT_ID)
	{
		{ _field_explanation, "Render Geometry", "\nAll new Halo 3 render geometry definitions!\n\n" },
		{ _field_long_flags, "runtime flags", &render_geometry_flags },
		{ _field_block, "meshes", &global_mesh_block },
		{ _field_block, "PCA Mesh Indices", &PCAMeshIndexBlock_block },
		{ _field_block, "compression info", &compression_info_block },
		{ _field_block, "part sorting position", &sorting_position_block },
		{ _field_block, "user data", &user_data_block },
		{ _field_block, "per mesh temporary", &per_mesh_raw_data_block },
		FIELD_PAD("pad3", nullptr, 12),
		{ _field_block, "per mesh node map", &per_mesh_node_map_block },
		{ _field_block, "per mesh subpart visibility", &per_mesh_subpart_visibility_block },
		{ _field_block, "per_mesh_prt_data", &per_mesh_prt_data_block },
		{ _field_block, "per_instance_lightmap_texcoords", &per_instance_lightmap_texcoords_block },
		{ _field_block, "water bounding box block", &water_bounding_box_block },
		{ _field_pageable, "api resource", &render_geometry_api_resource_definition_struct },
		{ _field_block, "Optional PVS data", &render_geometry_pvs_data_block },
		{ _field_block, "shapeNames", &shapeNameBlock_block },
		{ _field_terminator }
	};

	#define GLOBAL_RENDER_GEOMETRY_USER_DATA_HEADER_STRUCT_ID { 0x90ADB30A, 0xC06E4FA8, 0x96F092C1, 0x020E847F }
	TAG_STRUCT(
		global_render_geometry_user_data_header_struct,
		"global_render_geometry_user_data_header_struct",
		"s_render_geometry_user_data_header",
		GLOBAL_RENDER_GEOMETRY_USER_DATA_HEADER_STRUCT_ID)
	{
		{ _field_char_enum, "data type", &render_geometry_user_data_type_definition },
		{ _field_char_integer, "data count" },
		{ _field_word_integer, "data size" },
		{ _field_terminator }
	};

	#define RENDER_GEOMETRY_API_RESOURCE_DEFINITION_STRUCT_ID { 0x8AEB8021, 0xF60A4164, 0x970C7091, 0x23365545 }
	TAG_STRUCT(
		render_geometry_api_resource_definition_struct,
		"render_geometry_api_resource_definition_struct",
		"s_render_geometry_api_resource",
		RENDER_GEOMETRY_API_RESOURCE_DEFINITION_STRUCT_ID)
	{
		{ _field_block, "pc vertex buffers", &vertex_buffers_block },
		{ _field_block, "pc index buffers", &index_buffers_block },
		{ _field_block, "xenon vertex buffers", &render_vertex_buffer_block },
		{ _field_block, "xenon index buffers", &render_index_buffer_block },
		{ _field_terminator }
	};

	STRINGS(part_flags)
	{
		"is water surface",
		"per vertex lightmap part",
		"debug flag instance part",
		"subparts has uberlights info",
		"draw cull distance medium",
		"draw cull distance close",
		"draw cull rendering shields",
		"cannot single pass render",
		"is transparent",
		"cannot two pass",
		"transparent should output depth for DoF#expensive",
		"do not include in static lightmap",
		"do not include in PVS generation",
		"draw cull rendering active camo"
	};
	STRING_LIST(part_flags, part_flags_strings, _countof(part_flags_strings));

	STRINGS(tessellation_mode_definition)
	{
		"none",
		"fixed x4 faces",
		"fixed x9 faces",
		"fixed x36 faces"
	};
	STRING_LIST(tessellation_mode_definition, tessellation_mode_definition_strings, _countof(tessellation_mode_definition_strings));

	STRINGS(specialized_render_definition)
	{
		"none",
		"fail",
		"fur",
		"fur_stencil",
		"decal",
		"shield",
		"water",
		"lightmap_only",
		"hologram"
	};
	STRING_LIST(specialized_render_definition, specialized_render_definition_strings, _countof(specialized_render_definition_strings));

	STRINGS(compression_flags)
	{
		"compressed position",
		"compressed texcoord",
		"compression optimized"
	};
	STRING_LIST(compression_flags, compression_flags_strings, _countof(compression_flags_strings));

	STRINGS(mesh_flags)
	{
		"mesh has vertex color",
		"use region index for sorting",
		"use vertex buffers for indices",
		"mesh has per-instance lighting (do not modify)",
		"mesh is unindexed (do not modify)",
		"subpart were merged",
		"mesh has fur",
		"mesh has decal",
		"mesh doesnt use compressed position",
		"use uncompressed vertex format",
		"mesh is PCA",
		"mesh compression determined",
		"mesh has authored lightmap texture coords",
		"mesh has a useful set of second texture coords",
		"mesh has no lightmap",
		"per vertex lighting"
	};
	STRING_LIST(mesh_flags, mesh_flags_strings, _countof(mesh_flags_strings));

	STRINGS(mesh_vertex_type_definition)
	{
		"world",
		"rigid",
		"skinned",
		"particle_model",
		"flat world",
		"flat rigid",
		"flat skinned",
		"screen",
		"debug",
		"transparent",
		"particle",
		"unused0",
		"light_volume",
		"chud_simple",
		"chud_fancy",
		"decorator",
		"position only",
		"patchy_fog",
		"water",
		"ripple",
		"implicit geometry",
		"unused1",
		"world_tessellated",
		"rigid_tessellated",
		"skinned_tessellated",
		"shader_cache",
		"structure_instance_imposter",
		"object_instance_imposter",
		"rigid compressed",
		"skinned uncompressed",
		"light volume precompiled",
		"blendshape_rigid",
		"blendshape_rigid_blendshaped",
		"rigid_blendshaped",
		"blendshape_skinned",
		"blendshape_skinned_blendshaped",
		"skinned_blendshaped",
		"VirtualGeometryHWtess",
		"VirtualGeometryMemexport",
		"position_only",
		"VirtualGeometryDebug",
		"blendshapeRigidCompressed",
		"skinnedUncompressedBlendshaped",
		"blendshapeSkinnedCompressed",
		"tracer",
		"polyart",
		"vectorart",
		"rigid_boned",
		"rigid_boned_2uv",
		"blendshape_skinned_2uv",
		"blendshape_skinned_2uv_blendshaped",
		"skinned_2uv_blendshaped",
		"polyartUV",
		"blendshape_skinned_uncompressed_blendshaped"
	};
	STRING_LIST(mesh_vertex_type_definition, mesh_vertex_type_definition_strings, _countof(mesh_vertex_type_definition_strings));

	STRINGS(mesh_transfer_vertex_type_definition)
	{
		"No PRT",
		"PRT Ambient",
		"PRT Linear",
		"PRT Quadratic"
	};
	STRING_LIST(mesh_transfer_vertex_type_definition, mesh_transfer_vertex_type_definition_strings, _countof(mesh_transfer_vertex_type_definition_strings));

	STRINGS(mesh_lighting_policy_type_definition)
	{
		"vertex color",
		"single probe",
		"prt ambient"
	};
	STRING_LIST(mesh_lighting_policy_type_definition, mesh_lighting_policy_type_definition_strings, _countof(mesh_lighting_policy_type_definition_strings));

	STRINGS(mesh_index_buffer_type_definition)
	{
		"DEFAULT",
		"line list",
		"line strip",
		"triangle list",
		"triangle fan",
		"triangle strip",
		"quad list",
		"rect list"
	};
	STRING_LIST(mesh_index_buffer_type_definition, mesh_index_buffer_type_definition_strings, _countof(mesh_index_buffer_type_definition_strings));

	STRINGS(per_mesh_raw_data_flags)
	{
		"indices are triangle strips",
		"indices are triangle lists",
		"indices are quad lists"
	};
	STRING_LIST(per_mesh_raw_data_flags, per_mesh_raw_data_flags_strings, _countof(per_mesh_raw_data_flags_strings));

	STRINGS(render_geometry_user_data_type_definition)
	{
		"PRT Info"
	};
	STRING_LIST(render_geometry_user_data_type_definition, render_geometry_user_data_type_definition_strings, _countof(render_geometry_user_data_type_definition_strings));

	STRINGS(render_geometry_flags)
	{
		"processed*!",
		"available*!",
		"has valid budgets (really)*!",
		"manual resource creation*!",
		"keep raw geometry*!",
		"dont use compressed vertex positions*!",
		"pca animation table sorted*!",
		"needs no lightmap uvs*!",
		"always needs lightmap uvs*!"
	};
	STRING_LIST(render_geometry_flags, render_geometry_flags_strings, _countof(render_geometry_flags_strings));

} // namespace macaque

} // namespace blofeld

