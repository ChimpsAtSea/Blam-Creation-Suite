#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/math/real_math.h>
#include <blamlib/memory/static_arrays.h>
#include <blamlib/tag_files/tag_groups.h>
#include <blamlib/haloreach/geometry/geometry_definitions.h>
#include <blamlib/haloreach/physics/breakable_surfaces.h>
#include <blamlib/haloreach/physics/collision_bsp.h>
#include <blamlib/haloreach/physics/collision_kd_hierarchy_types.h>
#include <blamlib/haloreach/physics/havok_mopp_code_definitions.h>
#include <blamlib/haloreach/structures/cluster_reference_packed.h>
#include <blamlib/haloreach/structures/structure_seams.h>

namespace blamlib
{

	/* ---------- constants */

	constexpr tag k_structure_bsp_group_tag = 'sbsp';
	constexpr tag k_structure_design_group_tag = 'sddt';

	/* ---------- types */

	struct s_structure_build_identifier
	{
		long manifest_id[4];
		long build_index;
		long structure_importer_version;
	};
	static_assert(sizeof(s_structure_build_identifier) == 0x18);

	struct s_structure_design_physics_definition
	{
		long importer_version;
		s_tag_block soft_ceiling_mopp_code; // TODO
		s_tag_block soft_ceilings;			// TODO
		s_tag_block water_mopp_code;		// TODO
		s_tag_block water_groups;			// TODO
		s_tag_block water_instances;		// TODO
	};
	static_assert(sizeof(s_structure_design_physics_definition) == 0x40);

	struct s_structure_design_planar_fog_set
	{
		s_tag_block planar_fogs; // TODO
		s_tag_block mopp_code; // TODO
	};
	static_assert(sizeof(s_structure_design_planar_fog_set) == 0x18);

	struct s_cubemap_sample
	{
		s_cluster_reference cluster_reference;
		short cluster_cubemap_index;
		short cubemap_point_index;
		short bitmap_index;
	};

	enum e_structure_bsp_definition_flags
	{
		_structure_bsp_has_instance_groups_bit,
		_structure_bsp_surface_to_triangle_mapping_remapped_bit,
		_structure_bsp_external_references_converted_to_io_bit,
		_structure_bsp_structure_mopp_needs_rebuilt_bit,
		_structure_bsp_structure_prefab_materials_need_postprocessing_bit,
		_structure_bsp_serialized_havok_data_converted_to_target_platform_bit,
		_structure_bsp_is_prefab_bit,
		_structure_bsp_collision_geometry_is_over_double_the_budget_bit,
		k_number_of_structure_bsp_definition_flags
	};

	enum e_structure_bsp_content_policy_flags
	{
		_structure_bsp_has_working_pathfinding_bit,
		_structure_bsp_convex_decomposition_enabled_bit,
		k_number_of_structure_bsp_content_policy_flags
	};

	struct s_structure_bsp_cluster;

	struct s_structure_seam_identifier
	{
		long guid[4];
	};
	static_assert(sizeof(s_structure_seam_identifier) == 0x10);

	struct s_structure_seam_edge_mapping
	{
		long structure_edge_index;
	};
	static_assert(sizeof(s_structure_seam_edge_mapping) == 0x4);

	struct s_structure_seam_cluster_mapping
	{
		c_tag_block_index<s_structure_bsp_cluster, long> cluster;
		real_point3d cluster_center;
	};
	static_assert(sizeof(s_structure_seam_cluster_mapping) == 0x10);

	struct s_structure_seam_mapping
	{
		s_structure_seam_identifier seams_identifier;
		c_typed_tag_block<s_structure_seam_edge_mapping> edge_mapping;
		c_typed_tag_block<s_structure_seam_cluster_mapping> cluster_mapping;
	};
	static_assert(sizeof(s_structure_seam_mapping) == 0x28);

	enum e_structure_collision_material_flags
	{
		_structure_collision_material_is_seam_bit,
		k_number_of_structure_collision_material_flags
	};

	struct s_structure_collision_material
	{
		s_tag_reference render_method;
		short global_material; // TODO: block index
		short conveyor_surface; // TODO: block index
		c_tag_block_index<s_structure_seam_mapping, short> seam_mapping;
		c_flags<e_structure_collision_material_flags, word> flags;
	};
	static_assert(sizeof(s_structure_collision_material) == 0x18);

	struct s_structure_bsp_leaf
	{
		c_tag_block_index<s_structure_bsp_cluster, byte> cluster;
	};
	static_assert(sizeof(s_structure_bsp_leaf) == 0x1);

	struct s_structure_super_node_aabb
	{
		s_real_rectangle3d bounds;
	};
	static_assert(sizeof(s_structure_super_node_aabb) == 0x18);

	enum e_structure_super_node_mapping_flags
	{
		_structure_super_node_mapping_above_bit,
		k_number_of_structure_super_node_mapping_flags
	};

	struct s_structure_super_node_traversal_geometry_index
	{
		short index;
	};
	static_assert(sizeof(s_structure_super_node_traversal_geometry_index) == 0x2);

	struct s_structure_super_node_traversal_geometry
	{
		c_typed_tag_block<s_structure_super_node_traversal_geometry_index> portal_indices;
		c_typed_tag_block<s_structure_super_node_traversal_geometry_index> seam_indices;
	};
	static_assert(sizeof(s_structure_super_node_traversal_geometry) == 0x18);

	struct s_structure_super_node_mapping
	{
		short parent_super_node_index;
		char parent_internal_node_index;
		c_flags<e_structure_super_node_mapping_flags, byte> flags;
		dword has_traversal_geometry_mask;
		c_tag_block_index<s_structure_super_node_traversal_geometry_index, short> first_traversal_geometry_index;
		c_tag_block_index<s_structure_super_node_aabb, short> first_aabb_index;
		dword aabb_mask;
		c_tag_block_index<s_structure_super_node_traversal_geometry_index, short> non_terminal_traversal_geometry_index;
		short : 16;
	};
	static_assert(sizeof(s_structure_super_node_mapping) == 0x14);

	struct s_structure_super_node_recursable_mask
	{
		word mask;
	};
	static_assert(sizeof(s_structure_super_node_recursable_mask) == 0x2);

	struct s_structure_bsp_plane
	{
		short unknown;
		c_tag_block_index<s_structure_bsp_cluster, short> cluster;
	};
	static_assert(sizeof(s_structure_bsp_plane) == 0x4);

	struct s_structure_bsp_surface
	{
		c_tag_block_index<s_structure_bsp_plane, long> first_plane;
		long plane_count;
	};
	static_assert(sizeof(s_structure_bsp_surface) == 0x8);

	struct s_structure_bsp_detail_object
	{
		long unknown0;
		long unknown4;
		long unknown8;
		long unknownC;
		long unknown10;
		long unknown14;
		long unknown18;
		long unknown1C;
		long unknown20;
		long unknown24;
		long unknown28;
		long unknown2C;
		long unknown30;
	};
	static_assert(sizeof(s_structure_bsp_detail_object) == 0x34);

	enum e_structure_bsp_cluster_portal_flags
	{
		_structure_bsp_cluster_portal_deafen_ai_bit = 0,
		_structure_bsp_cluster_portal_one_way_bit = 1,
		_structure_bsp_cluster_portal_door_bit = 2,
		_structure_bsp_cluster_portal_no_way_bit = 3,
		_structure_bsp_cluster_portal_one_way_reversed_bit = 4,
		_structure_bsp_cluster_portal_deafen_everything_bit = 5,
		k_number_of_structure_bsp_cluster_portal_flags
	};

	struct s_structure_bsp_cluster_portal_vertex
	{
		real_point3d point;
	};
	static_assert(sizeof(s_structure_bsp_cluster_portal_vertex) == 0xC);

	struct s_oriented_bounds
	{
		real_point3d center;
		real_vector3d extents;
		real_quaternion orientation;
	};
	static_assert(sizeof(s_oriented_bounds) == 0x28);

	struct s_structure_bsp_cluster_portal
	{
		s_oriented_bounds oriented_bounds;
		c_tag_block_index<s_structure_bsp_cluster, short> back_cluster;
		c_tag_block_index<s_structure_bsp_cluster, short> front_cluster;
		c_tag_block_index<s_structure_bsp_plane, long> plane;
		real_point3d centroid;
		real bounding_radius;
		c_flags<e_structure_bsp_cluster_portal_flags, dword> flags;
		c_typed_tag_block<s_structure_bsp_cluster_portal_vertex> vertices;
	};
	static_assert(sizeof(s_structure_bsp_cluster_portal) == 0x50);

	struct s_structure_bsp_cluster_portal_index
	{
		short portal_index; // TODO: block index
	};
	static_assert(sizeof(s_structure_bsp_cluster_portal_index) == 0x2);

	struct s_structure_bsp_cluster_seam_index
	{
		short seam_index; // TODO: block index
	};
	static_assert(sizeof(s_structure_bsp_cluster_seam_index));

	struct s_structure_bsp_cluster
	{
		real_bounds x_bounds;
		real_bounds y_bounds;
		real_bounds z_bounds;
		char unknown1; // TODO: block index
		char sky_index; // TODO: block index
		char camera_effect_index; // TODO: block index
		char unknown2; // TODO: block index
		short unknown3;
		short unknown4;
		short runtime_decal_start_index;
		short runtime_decal_entry_count;
		short unknown5;
		short unknown6;
		short unknown7;
		short unknown8;
		short unknown9;
		short unknown10;
		long unknown11;
		c_typed_tag_block<s_structure_bsp_cluster_portal_index> portals;
		c_tag_block_index<s_mesh, short> mesh;
		short instance_imposter_cluster_mopp_index; // TODO: block index
		c_typed_tag_block<s_structure_bsp_cluster_seam_index> seam_indices;
		// TODO: finish
		s_tag_block decorator_grids;
		long unknown12;
		long unknown13;
		long unknown14;
		long unknown15;
		long unknown16;
		long unknown17;
		s_tag_block unknown18;
		s_tag_block unknown19;
	};
	static_assert(sizeof(s_structure_bsp_cluster) == 0x8C);

	struct s_structure_bsp_sky_owner_cluster
	{
		c_tag_block_index<s_structure_bsp_cluster, short> owner_cluster;
	};
	static_assert(sizeof(s_structure_bsp_sky_owner_cluster) == 0x2);

	struct s_structure_bsp_conveyor_surface
	{
		real_vector3d u;
		real_vector3d v;
	};
	static_assert(sizeof(s_structure_bsp_conveyor_surface) == 0x18);

	struct s_structure_bsp_breakable_surface
	{
		short instanced_geometry_instance; // TODO: block index
		short breakable_surface_index; // TODO: block index
		real_point3d centroid;
		real radius;
		long collision_surface_index; // TODO: block index
	};
	static_assert(sizeof(s_structure_bsp_breakable_surface) == 0x18);

	struct s_structure_bsp_instanced_geometry_name
	{
		string_id name;
	};
	static_assert(sizeof(s_structure_bsp_instanced_geometry_name) == 0x4);

	struct s_structure_bsp_instanced_geometry_name_index
	{
		c_tag_block_index<s_structure_bsp_instanced_geometry_name, short> name;
	};
	static_assert(sizeof(s_structure_bsp_instanced_geometry_name_index) == 0x2);

	struct s_structure_instance_group
	{
		real_point3d center;
		real radius;
		short unknown10;
		short unknown12;
		real unknown14;
		real unknown18;
		c_tag_block_index_list<word> instance_indices;
	};
	static_assert(sizeof(s_structure_instance_group) == 0x28);

	enum e_structure_instance_cluster_flags
	{
		_structure_instance_cluster_optimized_mopp_bit,
		k_number_of_structure_instance_cluster_flags
	};

	struct s_structure_instance_cluster
	{
		c_flags<e_structure_instance_cluster_flags, dword> flags;
		c_tag_block_index_list<word> instance_group_indices;
	};
	static_assert(sizeof(s_structure_instance_cluster) == 0x10);

	struct s_structure_instanced_geometry_definition
	{
		long checksum;
		real_point3d bounding_sphere_offset;
		real bounding_sphere_radius;
		s_collision_bsp collision_bsp;
		s_tag_block unknown1;
		s_tag_block unknown2;
		s_tag_block unknown3;
		s_tag_block unknown4;
		s_tag_block unknown5;
		s_tag_block unknown6;
		s_tag_block unknown7;
		s_tag_block unknown8;
		s_tag_block unknown9;
		s_tag_block unknown10;
		s_tag_block unknown11;
		s_tag_block unknown12;
		s_tag_block unknown13;
		s_tag_block unknown14;
		s_tag_block unknown15;
		s_tag_block unknown16;
		c_tag_block_index<s_mesh, short> mesh;
		c_tag_block_index<s_compression_info, short> compression;
	};
	static_assert(sizeof(s_structure_instanced_geometry_definition) == 0x144);

	enum e_structure_bsp_instance_geometry_instance_flags
	{
		_instanced_geometry_instance_contains_split_lighting_parts_bit,
		_instanced_geometry_instance_render_only_bit,
		_instanced_geometry_instance_does_not_block_aoe_damage_bit,
		_instanced_geometry_instance_collidable_bit,
		_instanced_geometry_instance_contains_decal_parts_bit,
		_instanced_geometry_instance_contains_water_parts_bit,
		_instanced_geometry_instance_negative_scale_bit,
		_instanced_geometry_instance_outside_map_bit,
		_instanced_geometry_instance_seam_colliding_bit,
		_instanced_geometry_instance_contains_deferred_reflections_bit,
		_instanced_geometry_instance_remove_from_shadow_geometry_bit,
		_instanced_geometry_instance_cinema_only_bit,
		_instanced_geometry_instance_exclude_from_cinema_bit,
		_instanced_geometry_instance_disable_fx_bit,
		_instanced_geometry_instance_disable_play_collision_bit,
		_instanced_geometry_instance_disable_bullet_collision_bit,
		k_number_of_structure_bsp_instance_geometry_instance_flags
	};

	struct s_structure_bsp_instanced_geometry_instance
	{
		s_real_matrix4x3 matrix;
		c_tag_block_index<s_structure_instanced_geometry_definition, short> instance_definition;
		c_flags<e_structure_bsp_instance_geometry_instance_flags, word> flags;
		c_tag_block_index<s_mesh, short> mesh;
		c_tag_block_index<s_geometry_compression_info_constant_buffer, short> compression;
		long seam_bitvector[4];
		real_bounds x_bounds;
		real_bounds y_bounds;
		real_bounds z_bounds;
		real_point3d world_bounding_sphere_center;
		real world_bounding_sphere_radius;
		real unknown1;
		real unknown2;
		char unknown3;
		char unknown4;
		char unknown5;
		char unknown6;
		long unknown7;
		long unknown8;
		long unknown9;
		long unknown10;
		long unknown11;
		long unknown12;
		long unknown13;
		string_id name;
	};
	static_assert(sizeof(s_structure_bsp_instanced_geometry_instance) == 0xA0);

	struct s_structure_design_definition
	{
		s_structure_build_identifier build_identifier;
		s_structure_build_identifier parent_build_identifier;
		s_structure_design_physics_definition physics;
		s_structure_design_planar_fog_set planar_fog_set;

		/* ------ rain */

		s_render_geometry render_geometry;
		c_typed_tag_block<s_structure_instanced_geometry_definition> instanced_geometry_definitions;
		c_typed_tag_block<s_structure_bsp_instanced_geometry_instance> instanced_geometry_instances;
		c_typed_tag_block<s_geometry_material> materials;

		long unknown1;
		long unknown2;
		long unknown3;
	};
	static_assert(sizeof(s_structure_design_definition) == 0x160);

	struct s_structure_bsp_obb_volume
	{
		// TODO
	};

	struct s_structure_bsp_resources
	{
		c_typed_tag_block<s_collision_bsp> collision_bsp;
		s_tag_block large_collision_bsp;
		c_typed_tag_block<s_structure_instanced_geometry_definition> instanced_geometry_definitions;
	};
	static_assert(sizeof(s_structure_bsp_resources) == 0x24);

	struct s_instanced_geometry_physics_definition
	{
		// TODO
	};

	struct s_structure_instanced_geometry_instance
	{
		s_real_matrix4x3 matrix;
		c_tag_block_index<s_structure_instanced_geometry_definition, short> instance_definition;
		c_flags<e_structure_bsp_instance_geometry_instance_flags, word> flags;
		c_tag_block_index<s_mesh, short> mesh;
		c_tag_block_index<s_geometry_compression_info_constant_buffer, short> compression;
		long seam_bitvector[4];
		real_bounds x_bounds;
		real_bounds y_bounds;
		real_bounds z_bounds;
		real_point3d world_bounding_sphere_center;
		real world_bounding_sphere_radius;
		real imposter_transition_complete_distance;
		long transform_checksum;
		byte pathfinding_policy;
		byte lightmapping_policy;
		byte imposter_quality_policy;
		byte imposter_flags;
		real lightmap_resolution_scale;
		real single_pass_render_minimum_distance;
		c_typed_tag_block<s_instanced_geometry_physics_definition> physics;
		s_cubemap_sample cubemap_sample;
	};
	static_assert(sizeof(s_structure_instanced_geometry_instance) == 0x9C);

	struct s_structure_bsp_pathfinding_data
	{
		// TODO
	};

	struct s_structure_bsp_pathfinding_edge
	{
		byte midpoint;
	};
	static_assert(sizeof(s_structure_bsp_pathfinding_edge) == 0x1);

	struct s_structure_bsp_cache_file_resources
	{
		c_typed_tag_block<s_structure_bsp_surface> surfaces;
		c_typed_tag_block<s_structure_bsp_plane> planes;
		c_typed_tag_block<s_seam_mapping> edges_to_seams;
		c_typed_tag_block<s_structure_bsp_pathfinding_data> pathfinding_data;
		c_typed_tag_block<s_havok_mopp_code_definition> cluster_to_instance_group_mopps;
		c_typed_tag_block<s_havok_mopp_code_definition> instance_group_to_instance_mopps;
		c_typed_tag_block<s_structure_instanced_geometry_instance> instanced_geometry_instances;
		c_typed_tag_block<s_structure_super_node_mapping> super_node_parent_mappings;
		c_typed_tag_block<s_structure_super_node_recursable_mask> super_node_recursable_masks;
		c_typed_tag_block<s_structure_super_node_traversal_geometry> super_node_traversal_geometry;
		s_collision_kd_hierarchy_static instance_kd_hierarchy;
	};
	static_assert(sizeof(s_structure_bsp_cache_file_resources) == 0xC4);

	class c_structure_bsp_resource_interface
	{
	private:
		c_typed_tag_block<s_structure_bsp_resources> m_raw_resources;
		c_typed_tag_block<s_structure_bsp_cache_file_resources> m_raw_cache_file_resources;
		c_typed_tag_resource<s_structure_bsp_resources> m_tag_resources;
		c_typed_tag_resource<s_structure_bsp_cache_file_resources> m_cache_file_resources;
		long m_use_resource_items;

	public:
		s_structure_bsp_resources* get_resources();
		s_structure_bsp_cache_file_resources* get_cache_file_resources();
		bool are_resources_valid();
	};

	struct s_structure_bsp_definition
	{
		s_structure_build_identifier build_identifier;
		s_structure_build_identifier parent_build_identifier;
		long import_info_checksum;
		long import_version;
		c_flags<e_structure_bsp_definition_flags, word> flags;
		c_flags<e_structure_bsp_content_policy_flags, word> content_policy_flags;
		c_flags<e_structure_bsp_content_policy_flags, word> failed_content_policy_flags;
		short : 16;
		c_typed_tag_block<s_structure_seam_mapping> seam_identifiers;
		c_typed_tag_block<s_seam_mapping> seam_to_edge_mapping;
		c_typed_tag_block<s_structure_collision_material> collision_materials;
		c_typed_tag_block<s_structure_bsp_leaf> leaves;
		c_typed_tag_block<s_structure_super_node_aabb> super_node_aabbs;
		c_typed_tag_block<s_structure_super_node_mapping> super_node_parent_mappings;
		c_typed_tag_block<s_structure_super_node_recursable_mask> super_node_recursable_masks;
		c_typed_tag_block<s_structure_super_node_traversal_geometry> super_node_traversal_geometry;
		s_collision_kd_hierarchy_static instance_kd_hierarchy;
		long : 32;
		real_bounds world_bounds_x;
		real_bounds world_bounds_y;
		real_bounds world_bounds_z;
		c_typed_tag_block<s_structure_bsp_surface> surfaces;
		c_typed_tag_block<s_structure_bsp_plane> planes;
		c_typed_tag_block<s_structure_bsp_cluster_portal> cluster_portals;
		c_typed_tag_block<s_structure_bsp_detail_object> detail_objects;
		c_typed_tag_block<s_structure_bsp_cluster> clusters;
		c_typed_tag_block<s_geometry_material> materials;
		c_typed_tag_block<s_structure_bsp_sky_owner_cluster> sky_owner_cluster;
		c_typed_tag_block<s_structure_bsp_conveyor_surface> conveyor_surfaces;
		c_typed_tag_block<s_structure_bsp_breakable_surface> breakable_surface_sets;
		c_typed_tag_block<s_structure_bsp_pathfinding_data> pathfinding_data;
		c_typed_tag_block<s_structure_bsp_pathfinding_edge> pathfinding_edges;
		s_tag_block cookie_cutters;
		s_tag_block background_sound_environment_palette;
		s_tag_data sound_pas_data;
		s_tag_block markers;
		s_tag_block unknown1;
		s_tag_block unknown2;
		s_tag_block runtime_decals;
		s_tag_block environment_object_palette;
		s_tag_block environment_objects;
		long : 32;
		s_tag_block leaf_map_leaves;
		s_tag_block leaf_map_connections;
		s_tag_block errors;
		c_typed_tag_block<s_havok_mopp_code_definition> cluster_to_instance_group_mopps;
		c_typed_tag_block<s_havok_mopp_code_definition> instance_group_to_instance_mopps;
		c_typed_tag_block<s_structure_instance_cluster> cluster_to_instance_group_spheres;
		c_typed_tag_block<s_structure_instance_group> instance_group_to_instance_spheres;
		c_typed_tag_block<s_structure_bsp_instanced_geometry_instance> instanced_geometry_instances;
		c_typed_tag_block<s_structure_bsp_instanced_geometry_name> instanced_geometry_instance_names;
		s_tag_reference instanced_geometry_imposters;
		s_tag_block decorators;
		s_render_geometry decorator_geometry;
		s_tag_block decals;
		s_tag_block decal_properties;
		s_render_geometry decal_geometry;
		s_tag_block unknown_sound_clusters_a;
		s_tag_block transparent_planes;
		s_tag_block unknown11;
		s_tag_block collision_mopp_codes;
		long unknown12;
		real_bounds collision_bounds_x;
		real_bounds collision_bounds_y;
		real_bounds collision_bounds_z;
		s_tag_block breakable_surface_mopp_codes;
		s_tag_block breakable_surface_key_table;
		s_tag_block unknown13;
		s_render_geometry render_geometry;
		c_typed_tag_block<s_tag_reference> widget_references;
		c_structure_bsp_resource_interface resource_interface;
	};
	static_assert(sizeof(s_structure_bsp_definition) == 0x544);

}
