#pragma once

struct s_physics_model_definition
{
	struct s_unknown9_block_definition;
	struct s_unknown11_block_definition;
	struct s_phantom_type_block_definition;
	struct s_unknown_12_block_definition;
	struct s_node_edge_block_definition;
	struct s_rigid_body_block_definition;
	struct s_material_block_definition;
	struct s_sphere_block_definition;
	struct s_pill_block_definition;
	struct s_box_block_definition;
	struct s_polyhedron_block_definition;
	struct s_polyhedron_four_vector_block_definition;
	struct s_polyhedron_plane_equation_block_definition;
	struct s_list_block_definition;
	struct s_list_shape_block_definition;
	struct s_mopp_block_definition;
	struct s_hinge_constraint_block_definition;
	struct s_ragdoll_constraint_block_definition;
	struct s_region_block_definition;
	struct s_node_block_definition;
	struct s_limited_hinge_constraint_block_definition;
	struct s_phantom_block_definition;

	unsigned int unknown;
	unsigned int unknown2;
	float mass;
	float low_frequency_decativation_scale;
	float high_frequency_decativation_scale;
	unsigned int unknown3;
	unsigned int unknown4;
	signed char unknown5;
	signed char unknown6;
	signed char unknown7;
	signed char unknown8;
	s_tag_block_definition<s_unknown9_block_definition> unknown10;
	s_tag_block_definition<s_unknown11_block_definition> unknown12;
	s_tag_block_definition<s_phantom_type_block_definition> phantom_types;
	s_tag_block_definition<s_unknown_12_block_definition> unknown_12_2;
	s_tag_block_definition<s_node_edge_block_definition> node_edges;
	s_tag_block_definition<s_rigid_body_block_definition> rigid_bodies;
	s_tag_block_definition<s_material_block_definition> materials;
	s_tag_block_definition<s_sphere_block_definition> spheres;
	unsigned int multi_spheres_block_here;
	unsigned int multi_spheres_block_here2;
	unsigned int multi_spheres_block_here3;
	s_tag_block_definition<s_pill_block_definition> pills;
	s_tag_block_definition<s_box_block_definition> boxes;
	unsigned int triangles_block_here;
	unsigned int triangles_block_here2;
	unsigned int triangles_block_here3;
	s_tag_block_definition<s_polyhedron_block_definition> polyhedra;
	s_tag_block_definition<s_polyhedron_four_vector_block_definition> polyhedron_four_vectors;
	s_tag_block_definition<s_polyhedron_plane_equation_block_definition> polyhedron_plane_equations;
	unsigned int mass_distributions_block_here;
	unsigned int mass_distributions_block_here2;
	unsigned int mass_distributions_block_here3;
	s_tag_block_definition<s_list_block_definition> lists;
	s_tag_block_definition<s_list_shape_block_definition> list_shapes;
	s_tag_block_definition<s_mopp_block_definition> mopps;
	DataReference mopp_codes;
	s_tag_block_definition<s_hinge_constraint_block_definition> hinge_constraints;
	s_tag_block_definition<s_ragdoll_constraint_block_definition> ragdoll_constraints;
	s_tag_block_definition<s_region_block_definition> regions;
	s_tag_block_definition<s_node_block_definition> nodes;
	unsigned int unknown13;
	unsigned int unknown14;
	unsigned int unknown15;
	unsigned int unknown16;
	unsigned int unknown17;
	unsigned int unknown18;
	s_tag_block_definition<s_limited_hinge_constraint_block_definition> limited_hinge_constraints;
	unsigned int ball_and_socket_constraint_block;
	unsigned int ball_and_socket_constraint_block2;
	unsigned int ball_and_socket_constraint_block3;
	unsigned int stiff_spring_constraint_block;
	unsigned int stiff_spring_constraint_block2;
	unsigned int stiff_spring_constraint_block3;
	unsigned int prismatic_constraint_block;
	unsigned int prismatic_constraint_block2;
	unsigned int prismatic_constraint_block3;
	s_tag_block_definition<s_phantom_block_definition> phantoms;

	struct s_unknown_definition
	{
		string_id unknown2;
		float unknown3;
		float unknown4;
		float unknown5;
		float unknown6;
		unsigned int unknown7;
	};

	struct s_unknown_definition
	{
		string_id name;
		float unknown2;
		float unknown3;
		float unknown4;
		float unknown5;
		float unknown6;
		unsigned int unknown7;
		unsigned int unknown8;
	};

	struct s_phantom_type_definition
	{
		signed int flags;
		unsigned int unknown;
		signed char minimum_size;
		signed char maximum_size;
		signed short unknown2;
		string_id marker_name;
		string_id alignment_marker_name;
		unsigned int unknown3;
		unsigned int unknown4;
		float hooke_s_law__e_;
		float linear_dead_radius;
		float center_acceleration;
		float center_max_velocity;
		float axis_acceleration;
		float axis_max_velocity;
		float direction_acceleration;
		float direction_max_velocity;
		unsigned int unknown5;
		unsigned int unknown6;
		unsigned int unknown7;
		unsigned int unknown8;
		unsigned int unknown9;
		unsigned int unknown10;
		unsigned int unknown11;
		unsigned int unknown12;
		unsigned int unknown13;
		unsigned int unknown14;
		unsigned int unknown15;
		unsigned int unknown16;
	};

	struct s_unknown_12_definition
	{
		struct s_unknown_1_block_definition;
		struct s_unknown_1_3_block_definition;

		s_tag_block_definition<s_unknown_1_block_definition> unknown_1_2;
		s_tag_block_definition<s_unknown_1_3_block_definition> unknown_1_4;

		struct s_unknown_1_definition
		{
			signed short unknown;
		};

		struct s_unknown_1_definition
		{
			unsigned int unknown;
			unsigned int unknown2;
			unsigned int unknown3;
			unsigned int unknown4;
		};
	};

	struct s_node_edge_definition
	{
		struct s_constraint_block_definition;

		signed short node_a_global_material_index;
		signed short node_b_global_material_index;
		signed short node_a;
		signed short node_b;
		s_tag_block_definition<s_constraint_block_definition> constraints;
		string_id node_a_material;
		string_id node_b_material;

		struct s_constraint_definition
		{
			struct s_unknown_block_definition;
			struct s_unknown3_block_definition;

			signed short type;
			signed short index;
			signed int flags;
			float friction;
			s_tag_block_definition<s_unknown_block_definition> unknown2;
			s_tag_block_definition<s_unknown3_block_definition> unknown4;

			struct s_unknown_definition
			{
				signed short unknown2;
				signed short unknown3;
				signed short unknown4;
				signed short unknown5;
				signed short unknown6;
				signed short unknown7;
			};

			struct s_unknown_definition
			{
				signed short unknown2;
				signed short unknown3;
			};
		};
	};

	struct s_rigid_body_definition
	{
		signed short node;
		signed short region;
		signed short permutations;
		signed short unknown;
		float bounding_sphere_offset_x;
		float bounding_sphere_offset_y;
		float bounding_sphere_offset_z;
		float bounding_sphere_radius;
		unsigned short flags;
		signed short unknown2;
		signed char motion_type;
		signed char unknown3;
		signed short size;
		float unknown4;
		float unknown5;
		float unknown6;
		unsigned int inertia_tensor_scale;
		unsigned int linear_dampening;
		unsigned int angular_dampening;
		unsigned int center_of_mass_offset_x;
		unsigned int center_of_mass_offset_y;
		unsigned int center_of_mass_offset_z;
		unsigned int unknown7;
		unsigned int unknown8;
		unsigned int unknown9;
		unsigned int unknown10;
		unsigned int unknown11;
		unsigned int unknown12;
		unsigned int unknown13;
		float center_of_mass_i;
		float center_of_mass_j;
		float center_of_mass_k;
		float center_of_mass_radius;
		float inertia_tensor_x_i;
		float inertia_tensor_x_j;
		float inertia_tensor_x_k;
		float inertia_tensor_x_radius;
		float inertia_tensor_y_i;
		float inertia_tensor_y_j;
		float inertia_tensor_y_k;
		float inertia_tensor_y_radius;
		float inertia_tensor_z_i;
		float inertia_tensor_z_j;
		float inertia_tensor_z_k;
		float inertia_tensor_z_radius;
		signed int unknown_interaction;
		unsigned int unknown14;
		signed short shape_type;
		signed short shape_index;
		signed int unknown15;
		float mass;
		unsigned int unknown16;
		signed short interaction_a;
		signed short interaction_b;
		unsigned int unknown17;
		unsigned int unknown18;
		unsigned int unknown19;
		unsigned int unknown20;
		unsigned int unknown21;
	};

	struct s_material_definition
	{
		string_id name;
		unsigned int unknown;
		string_id material_name;
		signed short phantom_type_index;
		signed char unknown2;
		signed char unknown3;
	};

	struct s_sphere_definition
	{
		string_id name;
		signed char material_index;
		signed char unknown;
		signed short global_material_index;
		float relative_mass_scale;
		float friction;
		float restitution;
		float volume;
		float mass;
		signed short overall_shape_index;
		signed char phantom_index;
		signed char interaction_unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		signed short size;
		signed short count;
		unsigned int unknown4;
		signed int offset;
		unsigned int unknown5;
		signed int unknown6;
		unsigned int unknown7;
		float radius;
		unsigned int unknown8;
		unsigned int unknown9;
		unsigned int unknown10;
		unsigned int unknown11;
		unsigned int unknown12;
		unsigned int unknown13;
		unsigned int unknown14;
		unsigned int unknown15;
		unsigned int unknown16;
		signed short size2;
		signed short count2;
		unsigned int unknown17;
		signed int offset2;
		unsigned int unknown18;
		signed int unknown19;
		unsigned int unknown20;
		float radius2;
		unsigned int unknown21;
		unsigned int unknown22;
		unsigned int unknown23;
		unsigned int unknown24;
		unsigned int unknown25;
		unsigned int unknown26;
		unsigned int unknown27;
		float translation_i;
		float translation_j;
		float translation_k;
		float translation_radius;
	};

	struct s_pill_definition
	{
		string_id name;
		signed char material_index;
		signed char unknown;
		signed short global_material_index;
		float relative_mass_scale;
		float friction;
		float restitution;
		float volume;
		float mass;
		signed short overall_shape_index;
		signed char phantom_index;
		signed char interaction_unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		signed short size;
		signed short count;
		unsigned int unknown4;
		signed int offset;
		unsigned int unknown5;
		signed int unknown6;
		unsigned int unknown7;
		float radius;
		unsigned int unknown8;
		unsigned int unknown9;
		unsigned int unknown10;
		float bottom_i;
		float bottom_j;
		float bottom_k;
		float bottom_radius;
		float top_i;
		float top_j;
		float top_k;
		float top_radius;
	};

	struct s_box_definition
	{
		string_id name;
		signed char material_index;
		signed char unknown;
		signed short global_material_index;
		float relative_mass_scale;
		float friction;
		float restitution;
		float volume;
		float mass;
		signed short overall_shape_index;
		signed char phantom_index;
		signed char interaction_unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		signed short size;
		signed short count;
		unsigned int unknown4;
		signed int offset;
		unsigned int unknown5;
		signed int unknown6;
		unsigned int unknown7;
		float radius;
		unsigned int unknown8;
		unsigned int unknown9;
		unsigned int unknown10;
		float half_extents_i;
		float half_extents_j;
		float half_extents_k;
		float half_extents_radius;
		unsigned int unknown11;
		unsigned int unknown12;
		signed short size2;
		signed short count2;
		unsigned int unknown13;
		signed int offset2;
		unsigned int unknown14;
		signed int unknown15;
		unsigned int unknown16;
		float radius2;
		unsigned int unknown17;
		unsigned int unknown18;
		unsigned int unknown19;
		unsigned int unknown20;
		unsigned int unknown21;
		unsigned int unknown22;
		unsigned int unknown23;
		float rotation_i_i;
		float rotation_i_j;
		float rotation_i_k;
		float rotation_i_radius;
		float rotation_j_i;
		float rotation_j_j;
		float rotation_j_k;
		float rotation_j_radius;
		float rotation_k_i;
		float rotation_k_j;
		float rotation_k_k;
		float rotation_k_radius;
		float translation_i;
		float translation_j;
		float translation_k;
		float translation_radius;
	};

	struct s_polyhedron_definition
	{
		string_id name;
		signed char material_index;
		signed char unknown;
		signed short global_material_index;
		float relative_mass_scale;
		float friction;
		float restitution;
		float volume;
		float mass;
		signed short overall_shape_index;
		signed char phantom_index;
		signed char interaction_unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		signed short size;
		signed short count;
		unsigned int unknown4;
		signed int offset;
		unsigned int unknown5;
		signed int unknown6;
		unsigned int unknown7;
		float radius;
		unsigned int unknown8;
		unsigned int unknown9;
		unsigned int unknown10;
		float aabb_half_extents_i;
		float aabb_half_extents_j;
		float aabb_half_extents_k;
		float aabb_half_extents_radius;
		float aabb_center_i;
		float aabb_center_j;
		float aabb_center_k;
		float aabb_center_radius;
		unsigned int unknown11;
		unsigned int unknown12;
		signed int four_vectors_size;
		unsigned int four_vectors_capacity;
		signed int unknown13;
		unsigned int unknown14;
		unsigned int unknown15;
		signed int plane_equations_size;
		unsigned int plane_equations_capacity;
		unsigned int unknown16;
		unsigned int unknown17;
		unsigned int unknown18;
		unsigned int unknown19;
	};

	struct s_polyhedron_four_vector_definition
	{
		float four_vectors_x_i;
		float four_vectors_x_j;
		float four_vectors_x_k;
		float four_vectors_x_radius;
		float four_vectors_y_i;
		float four_vectors_y_j;
		float four_vectors_y_k;
		float four_vectors_y_radius;
		float four_vectors_z_i;
		float four_vectors_z_j;
		float four_vectors_z_k;
		float four_vectors_z_radius;
	};

	struct s_polyhedron_plane_equation_definition
	{
		float unknown;
		float unknown2;
		float unknown3;
		float unknown4;
	};

	struct s_list_definition
	{
		unsigned int unknown;
		unsigned int unknown2;
		signed short size;
		signed short count;
		unsigned int unknown3;
		signed int offset;
		unsigned int unknown4;
		signed int unknown5;
		unsigned int unknown6;
		unsigned int unknown7;
		unsigned int unknown8;
		unsigned int unknown9;
		unsigned int unknown10;
		unsigned int unknown11;
		unsigned int unknown12;
		signed int child_shapes_size;
		unsigned int child_shapes_capacity;
		unsigned int unknown13;
		unsigned int unknown14;
		unsigned int unknown15;
		float unknown16;
		float unknown17;
		float unknown18;
		float unknown19;
		float unknown20;
		float unknown21;
		float unknown22;
		float unknown23;
		float unknown24;
		signed int unknown25;
		signed int unknown26;
		signed int unknown27;
		signed int unknown28;
		signed int unknown29;
		signed int unknown30;
		signed int unknown31;
		signed int unknown32;
	};

	struct s_list_shape_definition
	{
		signed short shape_type;
		signed short shape_index;
		signed int unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		signed int unknown4;
		unsigned int unknown5;
		unsigned int unknown6;
		unsigned int unknown7;
	};

	struct s_mopp_definition
	{
		unsigned int unknown;
		unsigned int unknown2;
		signed short size;
		signed short count;
		unsigned int unknown3;
		signed int offset;
		unsigned int unknown4;
		signed int unknown5;
		unsigned int unknown6;
		unsigned int unknown7;
		unsigned int unknown8;
		unsigned int unknown9;
		unsigned int unknown10;
		unsigned int unknown11;
		unsigned int unknown12;
		unsigned int unknown13;
		unsigned int unknown14;
		unsigned int unknown15;
		unsigned int unknown16;
		unsigned int unknown17;
		unsigned int unknown18;
		unsigned int unknown19;
		unsigned int unknown20;
		signed short shape_type;
		signed short shape_index;
		signed int unknown21;
		unsigned int unknown22;
		unsigned int unknown23;
		unsigned int unknown24;
		unsigned int unknown25;
		unsigned int unknown26;
		unsigned int unknown27;
		unsigned int unknown28;
		unsigned int unknown29;
	};

	struct s_hinge_constraint_definition
	{
		string_id name;
		signed short node_a;
		signed short node_b;
		float a_scale;
		float a_forward_i;
		float a_forward_j;
		float a_forward_k;
		float a_left_i;
		float a_left_j;
		float a_left_k;
		float a_up_i;
		float a_up_j;
		float a_up_k;
		float a_position_x;
		float a_position_y;
		float a_position_z;
		float b_scale;
		float b_forward_i;
		float b_forward_j;
		float b_forward_k;
		float b_left_i;
		float b_left_j;
		float b_left_k;
		float b_up_i;
		float b_up_j;
		float b_up_k;
		float b_position_i;
		float b_position_j;
		float b_position_k;
		signed short edge_index;
		signed short unknown;
		unsigned int unknown2;
	};

	struct s_ragdoll_constraint_definition
	{
		string_id name;
		signed short node_a;
		signed short node_b;
		float a_scale;
		float a_forward_i;
		float a_forward_j;
		float a_forward_k;
		float a_left_i;
		float a_left_j;
		float a_left_k;
		float a_up_i;
		float a_up_j;
		float a_up_k;
		float a_position_x;
		float a_position_y;
		float a_position_z;
		float b_scale;
		float b_forward_i;
		float b_forward_j;
		float b_forward_k;
		float b_left_i;
		float b_left_j;
		float b_left_k;
		float b_up_i;
		float b_up_j;
		float b_up_k;
		float b_position_x;
		float b_position_y;
		float b_position_z;
		signed short edge_index;
		signed short unknown;
		unsigned int unknown2;
		float min_twist;
		float max_twist;
		float min_cone;
		float max_cone;
		float min_plane;
		float max_plane;
		float max_friction_torque;
	};

	struct s_region_definition
	{
		struct s_permutation_block_definition;

		string_id name;
		s_tag_block_definition<s_permutation_block_definition> permutations;

		struct s_permutation_definition
		{
			struct s_rigid_body_block_definition;

			string_id name;
			s_tag_block_definition<s_rigid_body_block_definition> rigid_bodies;

			struct s_rigid_body_definition
			{
				signed short rigid_body_index;
			};
		};
	};

	struct s_node_definition
	{
		string_id name;
		unsigned short flags;
		signed short parent;
		signed short sibling;
		signed short child;
	};

	struct s_limited_hinge_constraint_definition
	{
		string_id name;
		signed short node_a;
		signed short node_b;
		float a_scale;
		float a_forward_i;
		float a_forward_j;
		float a_forward_k;
		float a_left_i;
		float a_left_j;
		float a_left_k;
		float a_up_i;
		float a_up_j;
		float a_up_k;
		float a_position_x;
		float a_position_y;
		float a_position_z;
		float b_scale;
		float b_forward_i;
		float b_forward_j;
		float b_forward_k;
		float b_left_i;
		float b_left_j;
		float b_left_k;
		float b_up_i;
		float b_up_j;
		float b_up_k;
		float b_position_x;
		float b_position_y;
		float b_position_z;
		signed short edge_index;
		signed short unknown;
		unsigned int unknown2;
		float limit_friction;
		float limit_min_angle;
		float limit_max_angle;
	};

	struct s_phantom_definition
	{
		unsigned int unknown;
		unsigned int unknown2;
		signed short size;
		signed short count;
		unsigned int unknown3;
		signed int offset;
		unsigned int unknown4;
		signed int unknown5;
		unsigned int unknown6;
		signed short shape_type;
		signed short shape_index;
		signed int unknown7;
		unsigned int unknown8;
		unsigned int unknown9;
		unsigned int unknown10;
		unsigned int unknown11;
		unsigned int unknown12;
		unsigned int unknown13;
		signed short size2;
		signed short count2;
		unsigned int unknown14;
		signed int offset2;
		unsigned int unknown15;
		signed int unknown16;
		unsigned int unknown17;
	};
};
