#pragma once

struct nicename("Physics Model") group('phmo') s_physics_model_definition
{
	struct s_unknown_block_definition;
	struct s_unknown2_block_definition;
	struct nicename("Phantom Types") s_phantom_type_block_definition;
	struct s_unknown_12_block_definition;
	struct nicename("Node Edges") s_node_edge_block_definition;
	struct nicename("Rigid Bodies") s_rigid_body_block_definition;
	struct nicename("Materials") s_material_block_definition;
	struct nicename("Spheres") s_sphere_block_definition;
	struct nicename("Pills") s_pill_block_definition;
	struct nicename("Boxes") s_box_block_definition;
	struct nicename("Polyhedra") s_polyhedron_block_definition;
	struct nicename("Polyhedron Four Vectors") s_polyhedron_four_vector_block_definition;
	struct nicename("Polyhedron Plane Equations") s_polyhedron_plane_equation_block_definition;
	struct nicename("Lists") s_list_block_definition;
	struct nicename("List Shapes") s_list_shape_block_definition;
	struct nicename("MOPPs") s_mopp_block_definition;
	struct nicename("Hinge Constraints") s_hinge_constraint_block_definition;
	struct nicename("Ragdoll Constraints") s_ragdoll_constraint_block_definition;
	struct nicename("Regions") s_region_block_definition;
	struct nicename("Nodes") s_node_block_definition;
	struct nicename("Limited Hinge Constraints") s_limited_hinge_constraint_block_definition;
	struct nicename("Phantoms") s_phantom_block_definition;

	Unknown32 __unknown; 
	Unknown32 __unknown2; 
	float nicename("Mass") mass; 
	float nicename("Low Frequency Decativation Scale") low_frequency_decativation_scale; 
	float nicename("High Frequency Decativation Scale") high_frequency_decativation_scale; 
	Unknown32 __unknown3; 
	Unknown32 __unknown4; 
	signed char __unknown5; 
	signed char __unknown6; 
	signed char __unknown7; 
	signed char __unknown8; 
	s_tag_block_definition<s_unknown_block_definition> __unknown9_block; 
	s_tag_block_definition<s_unknown2_block_definition> __unknown10_block; 
	s_tag_block_definition<s_phantom_type_block_definition> nicename("Phantom Types") phantom_types_block; 
	s_tag_block_definition<s_unknown_12_block_definition> __unknown_12_block; 
	s_tag_block_definition<s_node_edge_block_definition> nicename("Node Edges") node_edges_block; 
	s_tag_block_definition<s_rigid_body_block_definition> nicename("Rigid Bodies") rigid_bodies_block; 
	s_tag_block_definition<s_material_block_definition> nicename("Materials") materials_block; 
	s_tag_block_definition<s_sphere_block_definition> nicename("Spheres") spheres_block; 
	Unknown32 __multi_spheres_block_here; 
	Unknown32 __multi_spheres_block_here2; 
	Unknown32 __multi_spheres_block_here3; 
	s_tag_block_definition<s_pill_block_definition> nicename("Pills") pills_block; 
	s_tag_block_definition<s_box_block_definition> nicename("Boxes") boxes_block; 
	Unknown32 __triangles_block_here; 
	Unknown32 __triangles_block_here2; 
	Unknown32 __triangles_block_here3; 
	s_tag_block_definition<s_polyhedron_block_definition> nicename("Polyhedra") polyhedra_block; 
	s_tag_block_definition<s_polyhedron_four_vector_block_definition> nicename("Polyhedron Four Vectors") polyhedron_four_vectors_block; 
	s_tag_block_definition<s_polyhedron_plane_equation_block_definition> nicename("Polyhedron Plane Equations") polyhedron_plane_equations_block; 
	Unknown32 __mass_distributions_block_here; 
	Unknown32 __mass_distributions_block_here2; 
	Unknown32 __mass_distributions_block_here3; 
	s_tag_block_definition<s_list_block_definition> nicename("Lists") lists_block; 
	s_tag_block_definition<s_list_shape_block_definition> nicename("List Shapes") list_shapes_block; 
	s_tag_block_definition<s_mopp_block_definition> nicename("MOPPs") mopps_block; 
	DataReference nicename("MOPP Codes") mopp_codes_data_reference; 
	s_tag_block_definition<s_hinge_constraint_block_definition> nicename("Hinge Constraints") hinge_constraints_block; 
	s_tag_block_definition<s_ragdoll_constraint_block_definition> nicename("Ragdoll Constraints") ragdoll_constraints_block; 
	s_tag_block_definition<s_region_block_definition> nicename("Regions") regions_block; 
	s_tag_block_definition<s_node_block_definition> nicename("Nodes") nodes_block; 
	Unknown32 __unknown11; 
	Unknown32 __unknown12; 
	Unknown32 __unknown13; 
	Unknown32 __unknown14; 
	Unknown32 __unknown15; 
	Unknown32 __unknown16; 
	s_tag_block_definition<s_limited_hinge_constraint_block_definition> nicename("Limited Hinge Constraints") limited_hinge_constraints_block; 
	Unknown32 __ball_and_socket_constraint_block; 
	Unknown32 __ball_and_socket_constraint_block2; 
	Unknown32 __ball_and_socket_constraint_block3; 
	Unknown32 __stiff_spring_constraint_block; 
	Unknown32 __stiff_spring_constraint_block2; 
	Unknown32 __stiff_spring_constraint_block3; 
	Unknown32 __prismatic_constraint_block; 
	Unknown32 __prismatic_constraint_block2; 
	Unknown32 __prismatic_constraint_block3; 
	s_tag_block_definition<s_phantom_block_definition> nicename("Phantoms") phantoms_block; 

	struct s_unknown_block_definition
	{
		string_id __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		Unknown32 __unknown6; 
	};

	struct s_unknown2_block_definition
	{
		string_id nicename("Name") name; 
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		Unknown32 __unknown6; 
		Unknown32 __unknown7; 
	};

	struct nicename("phantom_type") s_phantom_type_block_definition
	{
		signed int nicename("Flags") flags; 
		Unknown32 __unknown; 
		signed char nicename("Minimum Size") minimum_size; 
		signed char nicename("Maximum Size") maximum_size; 
		signed short __unknown2; 
		string_id nicename("Marker Name") marker_name; 
		string_id nicename("Alignment Marker Name") alignment_marker_name; 
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
		float nicename("Hooke's Law 'E'") hooke_s_law__e_; 
		float nicename("Linear Dead Radius") linear_dead_radius; 
		float nicename("Center Acceleration") center_acceleration; 
		float nicename("Center Max Velocity") center_max_velocity; 
		float nicename("Axis Acceleration") axis_acceleration; 
		float nicename("Axis Max Velocity") axis_max_velocity; 
		float nicename("Direction Acceleration") direction_acceleration; 
		float nicename("Direction Max Velocity") direction_max_velocity; 
		Unknown32 __unknown5; 
		Unknown32 __unknown6; 
		Unknown32 __unknown7; 
		Unknown32 __unknown8; 
		Unknown32 __unknown9; 
		Unknown32 __unknown10; 
		Unknown32 __unknown11; 
		Unknown32 __unknown12; 
		Unknown32 __unknown13; 
		Unknown32 __unknown14; 
		Unknown32 __unknown15; 
		Unknown32 __unknown16; 
	};

	struct s_unknown_12_block_definition
	{
		struct s_unknown_1_block_definition;
		struct s_unknown_1_2_block_definition;

		s_tag_block_definition<s_unknown_1_block_definition> __unknown_1_block; 
		s_tag_block_definition<s_unknown_1_2_block_definition> __unknown_1_2_block; 

		struct s_unknown_1_block_definition
		{
			signed short __unknown; 
		};

		struct s_unknown_1_2_block_definition
		{
			Unknown32 __unknown; 
			Unknown32 __unknown2; 
			Unknown32 __unknown3; 
			Unknown32 __unknown4; 
		};
	};

	struct nicename("node_edge") s_node_edge_block_definition
	{
		struct nicename("Constraints") s_constraint_block_definition;

		signed short nicename("Node A Global Material Index") node_a_global_material_index; 
		signed short nicename("Node B Global Material Index") node_b_global_material_index; 
		signed short nicename("Node A") node_a; 
		signed short nicename("Node B") node_b; 
		s_tag_block_definition<s_constraint_block_definition> nicename("Constraints") constraints_block; 
		string_id nicename("Node A Material") node_a_material; 
		string_id nicename("Node B Material") node_b_material; 

		struct nicename("constraint") s_constraint_block_definition
		{
			struct s_unknown_block_definition;
			struct s_unknown2_block_definition;

			signed short nicename("Type") type; 
			signed short nicename("Index") index; 
			signed int nicename("Flags") flags; 
			float nicename("Friction") friction; 
			s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
			s_tag_block_definition<s_unknown2_block_definition> __unknown2_block; 

			struct s_unknown_block_definition
			{
				signed short __unknown; 
				signed short __unknown2; 
				signed short __unknown3; 
				signed short __unknown4; 
				signed short __unknown5; 
				signed short __unknown6; 
			};

			struct s_unknown2_block_definition
			{
				signed short __unknown; 
				signed short __unknown2; 
			};
		};
	};

	struct nicename("rigid_body") s_rigid_body_block_definition
	{
		signed short nicename("Node") node; 
		signed short nicename("Region") region; 
		signed short nicename("Permutations") permutations; 
		signed short __unknown; 
		float nicename("Bounding Sphere Offset x") bounding_sphere_offset_x; 
		float nicename("Bounding Sphere Offset y") bounding_sphere_offset_y; 
		float nicename("Bounding Sphere Offset z") bounding_sphere_offset_z; 
		float nicename("Bounding Sphere Radius") bounding_sphere_radius; 
		unsigned short nicename("Flags") flags; 
		signed short __unknown2; 
		signed char nicename("Motion Type") motion_type; 
		signed char __unknown3; 
		signed short nicename("Size") size; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
		Unknown32 __inertia_tensor_scale; 
		Unknown32 __linear_dampening; 
		Unknown32 __angular_dampening; 
		Unknown32 __center_of_mass_offset_x; 
		Unknown32 __center_of_mass_offset_y; 
		Unknown32 __center_of_mass_offset_z; 
		Unknown32 __unknown7; 
		Unknown32 __unknown8; 
		Unknown32 __unknown9; 
		Unknown32 __unknown10; 
		Unknown32 __unknown11; 
		Unknown32 __unknown12; 
		Unknown32 __unknown13; 
		float nicename("Center of Mass i") center_of_mass_i; 
		float nicename("Center of Mass j") center_of_mass_j; 
		float nicename("Center of Mass k") center_of_mass_k; 
		float nicename("Center of Mass Radius") center_of_mass_radius; 
		float nicename("Inertia Tensor x i") inertia_tensor_x_i; 
		float nicename("Inertia Tensor x j") inertia_tensor_x_j; 
		float nicename("Inertia Tensor x k") inertia_tensor_x_k; 
		float nicename("Inertia Tensor x Radius") inertia_tensor_x_radius; 
		float nicename("Inertia Tensor y i") inertia_tensor_y_i; 
		float nicename("Inertia Tensor y j") inertia_tensor_y_j; 
		float nicename("Inertia Tensor y k") inertia_tensor_y_k; 
		float nicename("Inertia Tensor y Radius") inertia_tensor_y_radius; 
		float nicename("Inertia Tensor z i") inertia_tensor_z_i; 
		float nicename("Inertia Tensor z j") inertia_tensor_z_j; 
		float nicename("Inertia Tensor z k") inertia_tensor_z_k; 
		float nicename("Inertia Tensor z Radius") inertia_tensor_z_radius; 
		signed int __unknown_interaction; 
		Unknown32 __unknown14; 
		signed short nicename("Shape Type") shape_type; 
		signed short nicename("Shape Index") shape_index; 
		signed int __unknown15; 
		float nicename("Mass") mass; 
		Unknown32 __unknown16; 
		signed short nicename("Interaction A") interaction_a; 
		signed short nicename("Interaction B") interaction_b; 
		Unknown32 __unknown17; 
		Unknown32 __unknown18; 
		Unknown32 __unknown19; 
		Unknown32 __unknown20; 
		Unknown32 __unknown21; 
	};

	struct nicename("material") s_material_block_definition
	{
		string_id nicename("Name") name; 
		Unknown32 __unknown; 
		string_id nicename("Material Name") material_name; 
		signed short nicename("Phantom Type Index") phantom_type_index; 
		signed char __unknown2; 
		signed char __unknown3; 
	};

	struct nicename("sphere") s_sphere_block_definition
	{
		string_id nicename("Name") name; 
		signed char nicename("Material Index") material_index; 
		signed char __unknown; 
		signed short nicename("Global Material Index") global_material_index; 
		float nicename("Relative Mass Scale") relative_mass_scale; 
		float nicename("Friction") friction; 
		float nicename("Restitution") restitution; 
		float nicename("Volume") volume; 
		float nicename("Mass") mass; 
		signed short nicename("Overall Shape Index") overall_shape_index; 
		signed char nicename("Phantom Index") phantom_index; 
		signed char nicename("Interaction Unknown") interaction_unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		signed short nicename("Size") size; 
		signed short nicename("Count") count; 
		Unknown32 __unknown4; 
		signed int nicename("Offset") offset; 
		Unknown32 __unknown5; 
		signed int __unknown6; 
		Unknown32 __unknown7; 
		float nicename("Radius") radius; 
		Unknown32 __unknown8; 
		Unknown32 __unknown9; 
		Unknown32 __unknown10; 
		Unknown32 __unknown11; 
		Unknown32 __unknown12; 
		Unknown32 __unknown13; 
		Unknown32 __unknown14; 
		Unknown32 __unknown15; 
		Unknown32 __unknown16; 
		signed short nicename("Size") size2; 
		signed short nicename("Count") count2; 
		Unknown32 __unknown17; 
		signed int nicename("Offset") offset2; 
		Unknown32 __unknown18; 
		signed int __unknown19; 
		Unknown32 __unknown20; 
		float nicename("Radius") radius2; 
		Unknown32 __unknown21; 
		Unknown32 __unknown22; 
		Unknown32 __unknown23; 
		Unknown32 __unknown24; 
		Unknown32 __unknown25; 
		Unknown32 __unknown26; 
		Unknown32 __unknown27; 
		float nicename("Translation i") translation_i; 
		float nicename("Translation j") translation_j; 
		float nicename("Translation k") translation_k; 
		float nicename("Translation Radius") translation_radius; 
	};

	struct nicename("pill") s_pill_block_definition
	{
		string_id nicename("Name") name; 
		signed char nicename("Material Index") material_index; 
		signed char __unknown; 
		signed short nicename("Global Material Index") global_material_index; 
		float nicename("Relative Mass Scale") relative_mass_scale; 
		float nicename("Friction") friction; 
		float nicename("Restitution") restitution; 
		float nicename("Volume") volume; 
		float nicename("Mass") mass; 
		signed short nicename("Overall Shape Index") overall_shape_index; 
		signed char nicename("Phantom Index") phantom_index; 
		signed char nicename("Interaction Unknown") interaction_unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		signed short nicename("Size") size; 
		signed short nicename("Count") count; 
		Unknown32 __unknown4; 
		signed int nicename("Offset") offset; 
		Unknown32 __unknown5; 
		signed int __unknown6; 
		Unknown32 __unknown7; 
		float nicename("Radius") radius; 
		Unknown32 __unknown8; 
		Unknown32 __unknown9; 
		Unknown32 __unknown10; 
		float nicename("Bottom i") bottom_i; 
		float nicename("Bottom j") bottom_j; 
		float nicename("Bottom k") bottom_k; 
		float nicename("Bottom Radius") bottom_radius; 
		float nicename("Top i") top_i; 
		float nicename("Top j") top_j; 
		float nicename("Top k") top_k; 
		float nicename("Top Radius") top_radius; 
	};

	struct nicename("box") s_box_block_definition
	{
		string_id nicename("Name") name; 
		signed char nicename("Material Index") material_index; 
		signed char __unknown; 
		signed short nicename("Global Material Index") global_material_index; 
		float nicename("Relative Mass Scale") relative_mass_scale; 
		float nicename("Friction") friction; 
		float nicename("Restitution") restitution; 
		float nicename("Volume") volume; 
		float nicename("Mass") mass; 
		signed short nicename("Overall Shape Index") overall_shape_index; 
		signed char nicename("Phantom Index") phantom_index; 
		signed char nicename("Interaction Unknown") interaction_unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		signed short nicename("Size") size; 
		signed short nicename("Count") count; 
		Unknown32 __unknown4; 
		signed int nicename("Offset") offset; 
		Unknown32 __unknown5; 
		signed int __unknown6; 
		Unknown32 __unknown7; 
		float nicename("Radius") radius; 
		Unknown32 __unknown8; 
		Unknown32 __unknown9; 
		Unknown32 __unknown10; 
		float nicename("Half Extents i") half_extents_i; 
		float nicename("Half Extents j") half_extents_j; 
		float nicename("Half Extents k") half_extents_k; 
		float nicename("Half Extents Radius") half_extents_radius; 
		Unknown32 __unknown11; 
		Unknown32 __unknown12; 
		signed short nicename("Size") size2; 
		signed short nicename("Count") count2; 
		Unknown32 __unknown13; 
		signed int nicename("Offset") offset2; 
		Unknown32 __unknown14; 
		signed int __unknown15; 
		Unknown32 __unknown16; 
		float nicename("Radius") radius2; 
		Unknown32 __unknown17; 
		Unknown32 __unknown18; 
		Unknown32 __unknown19; 
		Unknown32 __unknown20; 
		Unknown32 __unknown21; 
		Unknown32 __unknown22; 
		Unknown32 __unknown23; 
		float nicename("Rotation i i") rotation_i_i; 
		float nicename("Rotation i j") rotation_i_j; 
		float nicename("Rotation i k") rotation_i_k; 
		float nicename("Rotation i Radius") rotation_i_radius; 
		float nicename("Rotation j i") rotation_j_i; 
		float nicename("Rotation j j") rotation_j_j; 
		float nicename("Rotation j k") rotation_j_k; 
		float nicename("Rotation j Radius") rotation_j_radius; 
		float nicename("Rotation k i") rotation_k_i; 
		float nicename("Rotation k j") rotation_k_j; 
		float nicename("Rotation k k") rotation_k_k; 
		float nicename("Rotation k Radius") rotation_k_radius; 
		float nicename("Translation i") translation_i; 
		float nicename("Translation j") translation_j; 
		float nicename("Translation k") translation_k; 
		float nicename("Translation Radius") translation_radius; 
	};

	struct nicename("polyhedron") s_polyhedron_block_definition
	{
		string_id nicename("Name") name; 
		signed char nicename("Material Index") material_index; 
		signed char __unknown; 
		signed short nicename("Global Material Index") global_material_index; 
		float nicename("Relative Mass Scale") relative_mass_scale; 
		float nicename("Friction") friction; 
		float nicename("Restitution") restitution; 
		float nicename("Volume") volume; 
		float nicename("Mass") mass; 
		signed short nicename("Overall Shape Index") overall_shape_index; 
		signed char nicename("Phantom Index") phantom_index; 
		signed char nicename("Interaction Unknown") interaction_unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		signed short nicename("Size") size; 
		signed short nicename("Count") count; 
		Unknown32 __unknown4; 
		signed int nicename("Offset") offset; 
		Unknown32 __unknown5; 
		signed int __unknown6; 
		Unknown32 __unknown7; 
		float nicename("Radius") radius; 
		Unknown32 __unknown8; 
		Unknown32 __unknown9; 
		Unknown32 __unknown10; 
		float nicename("AABB Half Extents i") aabb_half_extents_i; 
		float nicename("AABB Half Extents j") aabb_half_extents_j; 
		float nicename("AABB Half Extents k") aabb_half_extents_k; 
		float nicename("AABB Half Extents Radius") aabb_half_extents_radius; 
		float nicename("AABB Center i") aabb_center_i; 
		float nicename("AABB Center j") aabb_center_j; 
		float nicename("AABB Center k") aabb_center_k; 
		float nicename("AABB Center Radius") aabb_center_radius; 
		Unknown32 __unknown11; 
		Unknown32 __unknown12; 
		signed int nicename("Four Vectors Size") four_vectors_size; 
		unsigned int nicename("Four Vectors Capacity") four_vectors_capacity; 
		signed int __unknown13; 
		Unknown32 __unknown14; 
		Unknown32 __unknown15; 
		Unknown32 __unknown16; 
		Unknown32 __unknown17; 
		Unknown32 __unknown18; 
		signed int nicename("Plane Equations Size") plane_equations_size; 
		unsigned int nicename("Plane Equations Capacity") plane_equations_capacity; 
		Unknown32 __unknown19; 
		Unknown32 __unknown20; 
		Unknown32 __unknown21; 
		Unknown32 __unknown22; 
	};

	struct nicename("polyhedron_four_vector") s_polyhedron_four_vector_block_definition
	{
		float nicename("Four Vectors x i") four_vectors_x_i; 
		float nicename("Four Vectors x j") four_vectors_x_j; 
		float nicename("Four Vectors x k") four_vectors_x_k; 
		float nicename("Four Vectors x Radius") four_vectors_x_radius; 
		float nicename("Four Vectors y i") four_vectors_y_i; 
		float nicename("Four Vectors y j") four_vectors_y_j; 
		float nicename("Four Vectors y k") four_vectors_y_k; 
		float nicename("Four Vectors y Radius") four_vectors_y_radius; 
		float nicename("Four Vectors z i") four_vectors_z_i; 
		float nicename("Four Vectors z j") four_vectors_z_j; 
		float nicename("Four Vectors z k") four_vectors_z_k; 
		float nicename("Four Vectors z Radius") four_vectors_z_radius; 
	};

	struct nicename("polyhedron_plane_equation") s_polyhedron_plane_equation_block_definition
	{
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
	};

	struct nicename("list") s_list_block_definition
	{
		Unknown32 __unknown; 
		Unknown32 __unknown2; 
		signed short nicename("Size") size; 
		signed short nicename("Count") count; 
		Unknown32 __unknown3; 
		signed int nicename("Offset") offset; 
		Unknown32 __unknown4; 
		signed int __unknown5; 
		Unknown32 __unknown6; 
		Unknown32 __unknown7; 
		Unknown32 __unknown8; 
		Unknown32 __unknown9; 
		Unknown32 __unknown10; 
		Unknown32 __unknown11; 
		Unknown32 __unknown12; 
		signed int nicename("Child Shapes Size") child_shapes_size; 
		unsigned int nicename("Child Shapes Capacity") child_shapes_capacity; 
		Unknown32 __unknown13; 
		Unknown32 __unknown14; 
		Unknown32 __unknown15; 
		float __unknown16; 
		float __unknown17; 
		float __unknown18; 
		float __unknown19; 
		float __unknown20; 
		float __unknown21; 
		float __unknown22; 
		float __unknown23; 
		float __unknown24; 
		signed int __unknown25; 
		signed int __unknown26; 
		signed int __unknown27; 
		signed int __unknown28; 
		signed int __unknown29; 
		signed int __unknown30; 
		signed int __unknown31; 
		signed int __unknown32; 
	};

	struct nicename("list_shape") s_list_shape_block_definition
	{
		signed short nicename("Shape Type") shape_type; 
		signed short nicename("Shape Index") shape_index; 
		signed int __unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		signed int __unknown4; 
		Unknown32 __unknown5; 
		Unknown32 __unknown6; 
		Unknown32 __unknown7; 
	};

	struct nicename("mopp") s_mopp_block_definition
	{
		Unknown32 __unknown; 
		Unknown32 __unknown2; 
		signed short nicename("Size") size; 
		signed short nicename("Count") count; 
		Unknown32 __unknown3; 
		signed int nicename("Offset") offset; 
		Unknown32 __unknown4; 
		signed int __unknown5; 
		Unknown32 __unknown6; 
		Unknown32 __unknown7; 
		Unknown32 __unknown8; 
		Unknown32 __unknown9; 
		Unknown32 __unknown10; 
		Unknown32 __unknown11; 
		Unknown32 __unknown12; 
		Unknown32 __unknown13; 
		Unknown32 __unknown14; 
		Unknown32 __unknown15; 
		Unknown32 __unknown16; 
		Unknown32 __unknown17; 
		Unknown32 __unknown18; 
		Unknown32 __unknown19; 
		Unknown32 __unknown20; 
		signed short nicename("Shape Type") shape_type; 
		signed short nicename("Shape Index") shape_index; 
		signed int __unknown21; 
		Unknown32 __unknown22; 
		Unknown32 __unknown23; 
		Unknown32 __unknown24; 
		Unknown32 __unknown25; 
		Unknown32 __unknown26; 
		Unknown32 __unknown27; 
		Unknown32 __unknown28; 
		Unknown32 __unknown29; 
	};

	struct nicename("hinge_constraint") s_hinge_constraint_block_definition
	{
		string_id nicename("Name") name; 
		signed short nicename("Node A") node_a; 
		signed short nicename("Node B") node_b; 
		float nicename("A Scale") a_scale; 
		float nicename("A Forward i") a_forward_i; 
		float nicename("A Forward j") a_forward_j; 
		float nicename("A Forward k") a_forward_k; 
		float nicename("A Left i") a_left_i; 
		float nicename("A Left j") a_left_j; 
		float nicename("A Left k") a_left_k; 
		float nicename("A Up i") a_up_i; 
		float nicename("A Up j") a_up_j; 
		float nicename("A Up k") a_up_k; 
		float nicename("A Position x") a_position_x; 
		float nicename("A Position y") a_position_y; 
		float nicename("A Position z") a_position_z; 
		float nicename("B Scale") b_scale; 
		float nicename("B Forward i") b_forward_i; 
		float nicename("B Forward j") b_forward_j; 
		float nicename("B Forward k") b_forward_k; 
		float nicename("B Left i") b_left_i; 
		float nicename("B Left j") b_left_j; 
		float nicename("B Left k") b_left_k; 
		float nicename("B Up i") b_up_i; 
		float nicename("B Up j") b_up_j; 
		float nicename("B Up k") b_up_k; 
		float nicename("B Position i") b_position_i; 
		float nicename("B Position j") b_position_j; 
		float nicename("B Position k") b_position_k; 
		signed short nicename("Edge Index") edge_index; 
		signed short __unknown; 
		Unknown32 __unknown2; 
	};

	struct nicename("ragdoll_constraint") s_ragdoll_constraint_block_definition
	{
		string_id nicename("Name") name; 
		signed short nicename("Node A") node_a; 
		signed short nicename("Node B") node_b; 
		float nicename("A Scale") a_scale; 
		float nicename("A Forward i") a_forward_i; 
		float nicename("A Forward j") a_forward_j; 
		float nicename("A Forward k") a_forward_k; 
		float nicename("A Left i") a_left_i; 
		float nicename("A Left j") a_left_j; 
		float nicename("A Left k") a_left_k; 
		float nicename("A Up i") a_up_i; 
		float nicename("A Up j") a_up_j; 
		float nicename("A Up k") a_up_k; 
		float nicename("A Position x") a_position_x; 
		float nicename("A Position y") a_position_y; 
		float nicename("A Position z") a_position_z; 
		float nicename("B Scale") b_scale; 
		float nicename("B Forward i") b_forward_i; 
		float nicename("B Forward j") b_forward_j; 
		float nicename("B Forward k") b_forward_k; 
		float nicename("B Left i") b_left_i; 
		float nicename("B Left j") b_left_j; 
		float nicename("B Left k") b_left_k; 
		float nicename("B Up i") b_up_i; 
		float nicename("B Up j") b_up_j; 
		float nicename("B Up k") b_up_k; 
		float nicename("B Position x") b_position_x; 
		float nicename("B Position y") b_position_y; 
		float nicename("B Position z") b_position_z; 
		signed short nicename("Edge Index") edge_index; 
		signed short __unknown; 
		Unknown32 __unknown2; 
		float nicename("Min Twist") min_twist; 
		float nicename("Max Twist") max_twist; 
		float nicename("Min Cone") min_cone; 
		float nicename("Max Cone") max_cone; 
		float nicename("Min Plane") min_plane; 
		float nicename("Max Plane") max_plane; 
		float nicename("Max Friction Torque") max_friction_torque; 
	};

	struct nicename("region") s_region_block_definition
	{
		struct nicename("Permutations") s_permutation_block_definition;

		string_id nicename("Name") name; 
		s_tag_block_definition<s_permutation_block_definition> nicename("Permutations") permutations_block; 

		struct nicename("permutation") s_permutation_block_definition
		{
			struct nicename("Rigid Bodies") s_rigid_body_block_definition;

			string_id nicename("Name") name; 
			s_tag_block_definition<s_rigid_body_block_definition> nicename("Rigid Bodies") rigid_bodies_block; 

			struct nicename("rigid_body") s_rigid_body_block_definition
			{
				signed short nicename("Rigid Body Index") rigid_body_index; 
			};
		};
	};

	struct nicename("node") s_node_block_definition
	{
		string_id nicename("Name") name; 
		unsigned short nicename("Flags") flags; 
		signed short nicename("Parent") parent; 
		signed short nicename("Sibling") sibling; 
		signed short nicename("Child") child; 
	};

	struct nicename("limited_hinge_constraint") s_limited_hinge_constraint_block_definition
	{
		string_id nicename("Name") name; 
		signed short nicename("Node A") node_a; 
		signed short nicename("Node B") node_b; 
		float nicename("A Scale") a_scale; 
		float nicename("A Forward i") a_forward_i; 
		float nicename("A Forward j") a_forward_j; 
		float nicename("A Forward k") a_forward_k; 
		float nicename("A Left i") a_left_i; 
		float nicename("A Left j") a_left_j; 
		float nicename("A Left k") a_left_k; 
		float nicename("A Up i") a_up_i; 
		float nicename("A Up j") a_up_j; 
		float nicename("A Up k") a_up_k; 
		float nicename("A Position x") a_position_x; 
		float nicename("A Position y") a_position_y; 
		float nicename("A Position z") a_position_z; 
		float nicename("B Scale") b_scale; 
		float nicename("B Forward i") b_forward_i; 
		float nicename("B Forward j") b_forward_j; 
		float nicename("B Forward k") b_forward_k; 
		float nicename("B Left i") b_left_i; 
		float nicename("B Left j") b_left_j; 
		float nicename("B Left k") b_left_k; 
		float nicename("B Up i") b_up_i; 
		float nicename("B Up j") b_up_j; 
		float nicename("B Up k") b_up_k; 
		float nicename("B Position x") b_position_x; 
		float nicename("B Position y") b_position_y; 
		float nicename("B Position z") b_position_z; 
		signed short nicename("Edge Index") edge_index; 
		signed short __unknown; 
		Unknown32 __unknown2; 
		float nicename("Limit Friction") limit_friction; 
		float nicename("Limit Min Angle") limit_min_angle; 
		float nicename("Limit Max Angle") limit_max_angle; 
	};

	struct nicename("phantom") s_phantom_block_definition
	{
		Unknown32 __unknown; 
		Unknown32 __unknown2; 
		signed short nicename("Size") size; 
		signed short nicename("Count") count; 
		Unknown32 __unknown3; 
		signed int nicename("Offset") offset; 
		Unknown32 __unknown4; 
		signed int __unknown5; 
		Unknown32 __unknown6; 
		signed short nicename("Shape Type") shape_type; 
		signed short nicename("Shape Index") shape_index; 
		signed int __unknown7; 
		Unknown32 __unknown8; 
		Unknown32 __unknown9; 
		Unknown32 __unknown10; 
		Unknown32 __unknown11; 
		Unknown32 __unknown12; 
		Unknown32 __unknown13; 
		signed short nicename("Size") size2; 
		signed short nicename("Count") count2; 
		Unknown32 __unknown14; 
		signed int nicename("Offset") offset2; 
		Unknown32 __unknown15; 
		signed int __unknown16; 
		Unknown32 __unknown17; 
	};
};
