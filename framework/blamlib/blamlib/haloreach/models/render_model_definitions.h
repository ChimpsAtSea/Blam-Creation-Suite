#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/math/real_math.h>
#include <blamlib/tag_files/tag_groups.h>
#include <blamlib/haloreach/geometry/geometry_definitions.h>

namespace blamlib
{

	/* ---------- constants */

	constexpr tag k_render_model_group_tag = 'mode';

	constexpr int k_maximum_number_of_render_model_regions = 32;
	constexpr int k_maximum_number_of_render_model_permutations = 1023;
	constexpr int k_number_of_render_model_permutation_instance_bitvectors = 4;
	constexpr int k_maximum_number_of_render_model_instance_placements = 128;
	constexpr int k_maximum_number_of_render_model_nodes = 255;
	constexpr int k_maximum_number_of_render_model_marker_groups = 4096;
	constexpr int k_maximum_number_of_render_model_markers = 4096;

	/* ---------- types */

	enum e_render_model_flags
	{
		_render_model_is_hologram_bit,
		_render_model_has_water_bit,
		_render_model_has_node_maps_bit,
		_render_model_lod_regions_enabled_bit,
		_render_model_has_split_lighting_bit,
		_render_model_has_depth_peeling_bit,
		_render_model_has_custom_shadow_meshes_bit,
		_render_model_has_deferred_reflections_bit,
		_render_model_is_hologram_lofi_bit,
		_render_model_has_mid_distance_cull_parts_bit,
		_render_model_has_close_distance_cull_parts_bit,
		k_number_of_render_model_flags
	};

	enum e_render_model_marker_flags
	{
		_render_model_marker_has_node_relative_direction_bit,
		k_number_of_render_model_marker_flags
	};

	struct s_render_model_permutation
	{
		string_id name;
		c_tag_block_index<s_mesh, short> first_mesh;
		short mesh_count;
		int instance_masks[k_number_of_render_model_permutation_instance_bitvectors];
	};
	static_assert(sizeof(s_render_model_permutation) == 0x18);

	struct s_render_model_region
	{
		string_id name;
		c_typed_tag_block<s_render_model_permutation> permutations;
	};
	static_assert(sizeof(s_render_model_region) == 0x10);

	struct s_render_model_node
	{
		string_id name;
		c_tag_block_index<s_render_model_node, short> parent_node;
		c_tag_block_index<s_render_model_node, short> first_child_node;
		c_tag_block_index<s_render_model_node, short> next_sibling_node;
		c_tag_block_index<s_render_model_node, short> import_node;
		real_point3d default_translation;
		real_quaternion default_rotation;
		s_real_matrix4x3 inverse_matrix;
		real distance_from_parent;
	};
	static_assert(sizeof(s_render_model_node) == 0x60);

	struct s_render_model_instance_placement
	{
		string_id name;
		c_tag_block_index<s_render_model_node, long> node;
		s_real_matrix4x3 inverse_matrix;
	};
	static_assert(sizeof(s_render_model_instance_placement) == 0x3C);

	struct s_render_model_marker
	{
		c_tag_block_index<s_render_model_region, char> region;
		c_tag_block_index<s_render_model_permutation, char> permutation;
		c_tag_block_index<s_render_model_node, char> node;
		c_flags<e_render_model_marker_flags, byte> flags;
		real_point3d translation;
		real_quaternion rotation;
		real scale;
		real_vector3d direction;
	};
	static_assert(sizeof(s_render_model_marker) == 0x30);

	struct s_render_model_marker_group
	{
		string_id name;
		c_typed_tag_block<s_render_model_marker> markers;
	};
	static_assert(sizeof(s_render_model_marker_group) == 0x10);

	struct s_instance_node_map_mapping
	{
		short instance_node_map_region_node_index;
	};
	static_assert(sizeof(s_instance_node_map_mapping) == 0x2);

	struct s_render_model_unknown1
	{
		real unknown0;
		real unknown4;
		real unknown8;
		real unknownC;
		real unknown10;
		real unknown14;
		real unknown18;
	};
	static_assert(sizeof(s_render_model_unknown1) == 0x1C);

	struct s_render_model_unknown2
	{
		real unknown0;
		real unknown4;
		real unknown8;
		real unknownC;
		real unknown10;
		real unknown14;
		real unknown18;
		real unknown1C;
		real unknown20;
		real unknown24;
		real unknown28;
		real unknown2C;
		real unknown30;
		real unknown34;
		real unknown38;
		real unknown3C;
		real unknown40;
		real unknown44;
		real unknown48;
		real unknown4C;
		real unknown50;
		real unknown54;
		real unknown58;
		real unknown5C;
		real unknown60;
		real unknown64;
		real unknown68;
		real unknown6C;
		real unknown70;
		real unknown74;
		real unknown78;
		real unknown7C;
		real unknown80;
		real unknown84;
		real unknown88;
		real unknown8C;
		real unknown90;
		real unknown94;
		real unknown98;
		real unknown9C;
		real unknownA0;
		real unknownA4;
		real unknownA8;
		real unknownAC;
		real unknownB0;
		real unknownB4;
		real unknownB8;
		real unknownBC;
		real unknownC0;
		real unknownC4;
		real unknownC8;
		real unknownCC;
		real unknownD0;
		real unknownD4;
		real unknownD8;
		real unknownDC;
		real unknownE0;
		real unknownE4;
		real unknownE8;
		real unknownEC;
		real unknownF0;
		real unknownF4;
		real unknownF8;
		real unknownFC;
		real unknown100;
		real unknown104;
		real unknown108;
		real unknown10C;
		real unknown110;
		real unknown114;
		real unknown118;
		real unknown11C;
		real unknown120;
		real unknown124;
		real unknown128;
		real unknown12C;
		real unknown130;
		real unknown134;
		real unknown138;
		real unknown13C;
		real unknown140;
		real unknown144;
		real unknown148;
		real unknown14C;
	};
	static_assert(sizeof(s_render_model_unknown2) == 0x150);

	struct s_default_node_orientation
	{
		real_quaternion default_rotation;
		real_point3d default_translation;
		real default_scale;
	};
	static_assert(sizeof(s_default_node_orientation) == 0x20);

	struct s_render_model_definition
	{
		string_id name;
		c_flags<e_render_model_flags, word> flags;
		word version;
		int runtime_import_info_checksum;
		c_typed_tag_block<s_render_model_region> regions;
		int unknown18;
		c_tag_block_index<s_mesh, long> instance_mesh;
		c_typed_tag_block<s_render_model_instance_placement> instance_placements;
		int node_list_checksum;
		c_typed_tag_block<s_render_model_node> nodes;
		c_typed_tag_block<s_render_model_marker_group> marker_groups;
		c_typed_tag_block<s_geometry_material> materials;
		s_tag_block errors;
		real dont_draw_over_camera_cosine_angle;
		s_render_geometry geometry;
		c_typed_tag_block<s_instance_node_map_mapping> node_map_mapping;
		c_typed_tag_block<s_render_model_unknown1> unknown1;
		real unknowns[74];
		c_typed_tag_block<s_render_model_unknown2> unknown2;
		c_typed_tag_block<s_default_node_orientation> runtime_node_orientations;
	};
	static_assert(sizeof(s_render_model_definition) == 0x264);

}
