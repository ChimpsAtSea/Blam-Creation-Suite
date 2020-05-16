#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/math/real_math.h>
#include <blamlib/memory/static_arrays.h>
#include <blamlib/tag_files/tag_groups.h>
#include <blamlib/tag_files/tag_resource_internals.h>
#include <blamlib/haloreach/geometry/vertex_definitions.h>

/* ---------- constants */

constexpr int k_number_of_node_indices_per_vertex = 4;
constexpr int k_number_of_node_weights_per_vertex = 3;
constexpr int k_maximum_number_of_vertex_buffers_per_mesh = 8;
constexpr int k_maximum_number_of_index_buffers_per_mesh = 2;
constexpr int k_maximum_number_of_materials_per_geometry = 10240;
constexpr int k_maximum_number_of_part_sorting_positions_per_mesh = 65535;
constexpr int k_maximum_number_of_parts_per_mesh = 255;
constexpr int k_maximum_number_of_subparts_per_mesh = 65535;
constexpr int k_maximum_number_of_instance_bucket_instances_per_geometry = 65535;
constexpr int k_maximum_number_of_instance_buckets_per_geometry = 2048;
constexpr int k_maximum_number_of_water_indices_per_geometry = 2621400;
constexpr int k_maximum_number_of_meshes_per_geometry = 8191;
constexpr int k_maximum_number_of_compressions_per_geometry = 65536;

/* ---------- types */

struct s_geometry_material
{
	s_tag_reference render_method;
	long unknown10;
	real unknown14;
	real unknown18;
	char unknown1C;
	char unknown1D;
	char unknown1E;
	char unknown1F;
	real unknown20;
	real unknown24;
	char unknown28;
	char unknown29;
	char unknown2A;
	char unknown2B;
};
static_assert(sizeof(s_geometry_material) == 0x2C);

struct s_sorting_position
{
	real_plane3d plane;
	real_point3d position;
	real radius;
	byte node_indices[k_number_of_node_indices_per_vertex];
	real node_weights[k_number_of_node_weights_per_vertex];
};
static_assert(sizeof(s_sorting_position) == 0x30);

enum e_part_type
{
	_part_not_drawn,
	_part_opaque_shadow_only,
	_part_opaque_shadow_casting,
	_part_opaque_nonshadowing,
	_part_transparent,
	_part_lightmap_only,
	k_number_of_part_types
};

enum e_specialized_render_type
{
	_specialized_render_none,
	_specialized_render_fail,
	_specialized_render_fur,
	_specialized_render_fur_stencil,
	_specialized_render_decal,
	_specialized_render_shield,
	_specialized_render_water,
	_specialized_render_hologram,
	_specialized_render_split_lighting,
	_specialized_render_deferred_reflection,
	k_number_of_specialized_render_types
};

enum e_part_flags
{
	_part_is_water_surface_bit,
	_part_per_vertex_lightmap_part_bit,
	_part_render_in_z_prepass_bit,
	_part_can_be_rendered_in_draw_bundles_bit,
	_part_draw_cull_distance_medium_bit,
	_part_draw_cull_distance_close_bit,
	_part_draw_cull_rendering_shields_bit,
	_part_unused3_bit,
	_part_unused4_bit,
	_part_unused5_bit,
	_part_transparent_should_output_depth_for_dof_bit,
	_part_do_not_include_in_static_lightmap_bit,
	_part_do_not_include_in_pvs_generation_bit,
	_part_draw_cull_rendering_active_camo_bit,
	k_number_of_part_flags
};

struct s_part
{
	c_tag_block_index<s_geometry_material, short> material_index;
	c_tag_block_index<s_sorting_position, short> transparent_sorting_index;
	long index_start;
	long index_count;
	short subpart_start;
	short subpart_count;
	c_enum<e_part_type, char> part_type;
	c_enum<e_specialized_render_type, char> specialized_render;
	c_flags<e_part_flags, word> part_flags;
	word budget_vertex_count;
	short : 16;
};
static_assert(sizeof(s_part) == 0x18);

struct s_subpart
{
	long index_start;
	long index_count;
	c_tag_block_index<s_part, short> part_index;
	word budget_vertex_count;
	dword analytical_light_index;
};
static_assert(sizeof(s_subpart) == 0x10);

struct s_instance_bucket_instance
{
	short instance_index;
};
static_assert(sizeof(s_instance_bucket_instance) == 0x2);

struct s_instance_bucket
{
	c_tag_block_index<struct s_mesh, short> mesh;
	short definition_index; // TODO: appropriate c_tag_block_index
	c_typed_tag_block<s_instance_bucket_instance> instances;
};
static_assert(sizeof(s_instance_bucket) == 0x10);

struct s_water_instance_start
{
	short value;
};
static_assert(sizeof(s_water_instance_start) == 0x2);

enum e_mesh_flags
{
	_mesh_has_vertex_color_bit,
	_mesh_use_region_index_for_sorting_bit,
	_mesh_can_be_rendered_in_draw_bundles_bit,
	_mesh_is_custom_shadow_caster_bit,
	_mesh_is_unindexed_bit,
	_mesh_mash_should_render_in_z_prepass_bit,
	_mesh_has_water_bit,
	_mesh_has_decal_bit,
	k_number_of_mesh_flags
};

enum e_prt_type
{
	_prt_type_none,
	_prt_type_ambient,
	_prt_type_linear,
	_prt_type_quadratic,
	k_number_of_prt_types
};

enum e_vertex_buffer_type
{	// TODO: verify
	_vertex_buffer_type_invalid,
	_vertex_buffer_type_world,
	_vertex_buffer_type_rigid,
	_vertex_buffer_type_skinned,
	_vertex_buffer_type_static_per_pixel,
	_vertex_buffer_type_unknown_5,
	_vertex_buffer_type_static_per_vertex,
	_vertex_buffer_type_unknown_7,
	_vertex_buffer_type_unused_8,
	_vertex_buffer_type_ambient_prt,
	_vertex_buffer_type_linear_prt,
	_vertex_buffer_type_quadratic_prt,
	_vertex_buffer_type_unknown_c,
	_vertex_buffer_type_unknown_d,
	_vertex_buffer_type_static_per_vertex_color,
	_vertex_buffer_type_unknown_f,
	_vertex_buffer_type_unused_10,
	_vertex_buffer_type_unused_11,
	_vertex_buffer_type_unused_12,
	_vertex_buffer_type_unused_13,
	_vertex_buffer_type_tiny_position,
	_vertex_buffer_type_unknown_15,
	_vertex_buffer_type_unknown_16,
	_vertex_buffer_type_unknown_17,
	_vertex_buffer_type_decorator,
	_vertex_buffer_type_particle_model,
	_vertex_buffer_type_unknown_1a,
	_vertex_buffer_type_unknown_1b,
	_vertex_buffer_type_unknown_1c,
	_vertex_buffer_type_unused_1d,
	_vertex_buffer_type_world2,
	k_number_of_vertex_buffer_types
};

enum e_index_buffer_type
{
	_index_buffer_type_default,
	_index_buffer_type_line_list,
	_index_buffer_type_line_strip,
	_index_buffer_type_triangle_list,
	_index_buffer_type_triangle_patch,
	_index_buffer_type_triangle_strip,
	_index_buffer_type_quad_list,
	_index_buffer_type_rect_list,
	k_number_of_index_buffer_types
};

struct s_mesh
{
	c_typed_tag_block<s_part> parts;
	c_typed_tag_block<s_subpart> subparts;
	short vertex_buffer_indices[k_maximum_number_of_vertex_buffers_per_mesh];
	short index_buffer_indices[k_maximum_number_of_index_buffers_per_mesh];
	c_flags<e_mesh_flags, byte> mesh_flags;
	char rigid_node_index;
	c_enum<e_vertex_type, char> vertex_type;
	char use_dual_quat;
	c_enum<e_prt_type, char> prt_type;
	c_enum<e_index_buffer_type, char> index_buffer_type;
	char unknown33;
	char unknown34;
	c_typed_tag_block<s_instance_bucket> instance_buckets;
	c_typed_tag_block<s_water_instance_start> water_instance_start;
	long unknown4C;
	long unknown50;
	long unknown54;
	long unknown58;
};
static_assert(sizeof(s_mesh) == 0x5C);

enum e_compression_flags
{
	_compressed_position_bit,
	_compressed_texcoord_bit,
	_compression_optimized_bit,
	k_number_of_compression_flags
};

struct s_compression_info
{
	c_flags<e_compression_flags, word> flags;
	short : 16;
	real_bounds position_x;
	real_bounds position_y;
	real_bounds position_z;
	real_bounds texcoord_u;
	real_bounds texcoord_v;
	long : 32;
	long : 32;
};
static_assert(sizeof(s_compression_info) == 0x34);

struct s_geometry_unknown1
{
	short unknown0;
	short unknown2;
	s_tag_data unknown4;
};
static_assert(sizeof(s_geometry_unknown1) == 0x18);

struct s_geometry_unknown3
{
	short unknown0;
};
static_assert(sizeof(s_geometry_unknown3) == 0x2);

struct s_geometry_unknown2
{
	s_tag_data unknown0;
	c_typed_tag_block<s_geometry_unknown3> unknown14;
};
static_assert(sizeof(s_geometry_unknown2) == 0x20);

struct s_node_map_char
{
	char node_index;
};
static_assert(sizeof(s_node_map_char) == 0x1);

struct s_per_mesh_node_map
{
	c_typed_tag_block<s_node_map_char> node_map;
};
static_assert(sizeof(s_per_mesh_node_map) == 0xC);

struct s_per_mesh_subpart_visibility
{
	c_typed_tag_block<s_sorting_position> bounding_sphere;
};
static_assert(sizeof(s_per_mesh_subpart_visibility) == 0xC);

struct s_per_instance_lod_datum_index
{
	long index;
};
static_assert(sizeof(s_per_instance_lod_datum_index) == 0x4);

struct s_per_instance_lod_data
{
	c_typed_tag_block<s_per_instance_lod_datum_index> indices;
	short vertex_buffer_index;
	short char_definition_index;
};
static_assert(sizeof(s_per_instance_lod_data) == 0x10);

struct s_geometry_unknown4
{
	long index;
};
static_assert(sizeof(s_geometry_unknown4) == 0x4);

struct s_water_bounding_box
{
	c_tag_block_index<s_mesh, short> mesh;
	c_tag_block_index<s_part, short> part;
	real_point3d position_lower;
	real_point3d position_upper;
};
static_assert(sizeof(s_water_bounding_box) == 0x1C);

struct s_geometry_compression_info_constant_buffer
{
	c_typed_tag_interop<void> polyart_asset;
};
static_assert(sizeof(s_geometry_compression_info_constant_buffer) == 0xC);

enum e_render_geometry_runtime_flags
{
	_render_geometry_processed_bit,
	_render_geometry_available_bit,
	_render_geometry_has_valid_budgets_bit,
	_render_geometry_manual_resource_creation_bit,
	_render_geometry_keep_raw_geometry_bit,
	_render_geometry_dont_use_compressed_vertex_positions_bit,
	_render_geometry_pca_animation_table_sorted_bit,
	_render_geometry_has_dual_quat_bit,
	k_number_of_render_geometry_runtime_flags
};

struct s_render_geometry
{
	c_flags<e_render_geometry_runtime_flags, long> runtime_flags;
	c_typed_tag_block<s_mesh> meshes;
	c_typed_tag_block<s_compression_info> compression_info;
	c_typed_tag_block<s_sorting_position> part_sorting_position;
	c_typed_tag_block<s_geometry_unknown1> unknown28;
	s_tag_block unknown34; // ???
	c_typed_tag_block<s_geometry_unknown2> unknown40;
	c_typed_tag_block<s_per_mesh_node_map> per_mesh_node_map;
	c_typed_tag_block<s_per_mesh_subpart_visibility> per_mesh_subpart_visibility;
	s_tag_block unknown64; // ???
	c_typed_tag_block<s_per_instance_lod_data> per_instance_lod_data;
	c_typed_tag_block<s_geometry_unknown4> unknown7C;
	c_typed_tag_block<s_water_bounding_box> water_bounding_box;
	s_tag_resource resource;
	c_typed_tag_block<s_geometry_compression_info_constant_buffer> compression_info_constant_buffers;
};
static_assert(sizeof(s_render_geometry) == 0xA8);

struct s_render_geometry_api_vertex_buffer
{
	long count;
	c_enum<e_vertex_buffer_type, short> format;
	short vertex_size;
	s_tag_data data;
};
static_assert(sizeof(s_render_geometry_api_vertex_buffer) == 0x1C);

struct s_render_geometry_api_vertex_buffer_reference
{
	c_typed_tag_interop<s_render_geometry_api_vertex_buffer> vertex_buffer;
};
static_assert(sizeof(s_render_geometry_api_vertex_buffer_reference) == 0xC);

struct s_render_geometry_api_index_buffer
{
	c_enum<e_index_buffer_type, long> format;
	long unknown;
	s_tag_data data;
};
static_assert(sizeof(s_render_geometry_api_index_buffer) == 0x1C);

struct s_render_geometry_api_index_buffer_reference
{
	c_typed_tag_interop<s_render_geometry_api_index_buffer> index_buffer;
};
static_assert(sizeof(s_render_geometry_api_index_buffer_reference) == 0xC);

struct s_render_geometry_api_resource_definition
{
	s_tag_block unused1;
	s_tag_block unused2;
	c_typed_tag_block<s_render_geometry_api_vertex_buffer_reference> vertex_buffers;
	c_typed_tag_block<s_render_geometry_api_index_buffer_reference> index_buffers;
};
static_assert(sizeof(s_render_geometry_api_resource_definition) == 0x30);
