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

	Undefined32 __unknown; 
	Undefined32 __unknown2; 
	float nicename("Mass") mass; 
	float nicename("Low Frequency Decativation Scale") low_frequency_decativation_scale; 
	float nicename("High Frequency Decativation Scale") high_frequency_decativation_scale; 
	Undefined32 __unknown3; 
	Undefined32 __unknown4; 
	int8_t __unknown5; 
	int8_t __unknown6; 
	int8_t __unknown7; 
	int8_t __unknown8; 
	s_tag_block_definition<s_unknown_block_definition> __unknown9_block; 
	s_tag_block_definition<s_unknown2_block_definition> __unknown10_block; 
	s_tag_block_definition<s_phantom_type_block_definition> nicename("Phantom Types") phantom_types_block; 
	s_tag_block_definition<s_unknown_12_block_definition> __unknown_12_block; 
	s_tag_block_definition<s_node_edge_block_definition> nicename("Node Edges") node_edges_block; 
	s_tag_block_definition<s_rigid_body_block_definition> nicename("Rigid Bodies") rigid_bodies_block; 
	s_tag_block_definition<s_material_block_definition> nicename("Materials") materials_block; 
	s_tag_block_definition<s_sphere_block_definition> nicename("Spheres") spheres_block; 
	Undefined32 __multi_spheres_block_here; 
	Undefined32 __multi_spheres_block_here2; 
	Undefined32 __multi_spheres_block_here3; 
	s_tag_block_definition<s_pill_block_definition> nicename("Pills") pills_block; 
	s_tag_block_definition<s_box_block_definition> nicename("Boxes") boxes_block; 
	Undefined32 __triangles_block_here; 
	Undefined32 __triangles_block_here2; 
	Undefined32 __triangles_block_here3; 
	s_tag_block_definition<s_polyhedron_block_definition> nicename("Polyhedra") polyhedra_block; 
	s_tag_block_definition<s_polyhedron_four_vector_block_definition> nicename("Polyhedron Four Vectors") polyhedron_four_vectors_block; 
	s_tag_block_definition<s_polyhedron_plane_equation_block_definition> nicename("Polyhedron Plane Equations") polyhedron_plane_equations_block; 
	Undefined32 __mass_distributions_block_here; 
	Undefined32 __mass_distributions_block_here2; 
	Undefined32 __mass_distributions_block_here3; 
	s_tag_block_definition<s_list_block_definition> nicename("Lists") lists_block; 
	s_tag_block_definition<s_list_shape_block_definition> nicename("List Shapes") list_shapes_block; 
	s_tag_block_definition<s_mopp_block_definition> nicename("MOPPs") mopps_block; 
	DataReference nicename("MOPP Codes") mopp_codes_data_reference; 
	s_tag_block_definition<s_hinge_constraint_block_definition> nicename("Hinge Constraints") hinge_constraints_block; 
	s_tag_block_definition<s_ragdoll_constraint_block_definition> nicename("Ragdoll Constraints") ragdoll_constraints_block; 
	s_tag_block_definition<s_region_block_definition> nicename("Regions") regions_block; 
	s_tag_block_definition<s_node_block_definition> nicename("Nodes") nodes_block; 
	Undefined32 __unknown11; 
	Undefined32 __unknown12; 
	Undefined32 __unknown13; 
	Undefined32 __unknown14; 
	Undefined32 __unknown15; 
	Undefined32 __unknown16; 
	s_tag_block_definition<s_limited_hinge_constraint_block_definition> nicename("Limited Hinge Constraints") limited_hinge_constraints_block; 
	Undefined32 __ball_and_socket_constraint_block; 
	Undefined32 __ball_and_socket_constraint_block2; 
	Undefined32 __ball_and_socket_constraint_block3; 
	Undefined32 __stiff_spring_constraint_block; 
	Undefined32 __stiff_spring_constraint_block2; 
	Undefined32 __stiff_spring_constraint_block3; 
	Undefined32 __prismatic_constraint_block; 
	Undefined32 __prismatic_constraint_block2; 
	Undefined32 __prismatic_constraint_block3; 
	s_tag_block_definition<s_phantom_block_definition> nicename("Phantoms") phantoms_block; 

	struct s_unknown_block_definition
	{
		string_id __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		Undefined32 __unknown6; 
	};

	struct s_unknown2_block_definition
	{
		string_id nicename("Name") name; 
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
	};

	struct nicename("phantom_type") s_phantom_type_block_definition
	{
		int32_t nicename("Flags") flags; 
		Undefined32 __unknown; 
		int8_t nicename("Minimum Size") minimum_size; 
		int8_t nicename("Maximum Size") maximum_size; 
		int16_t __unknown2; 
		string_id nicename("Marker Name") marker_name; 
		string_id nicename("Alignment Marker Name") alignment_marker_name; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		float nicename("Hooke's Law 'E'") hooke_s_law__e_; 
		float nicename("Linear Dead Radius") linear_dead_radius; 
		float nicename("Center Acceleration") center_acceleration; 
		float nicename("Center Max Velocity") center_max_velocity; 
		float nicename("Axis Acceleration") axis_acceleration; 
		float nicename("Axis Max Velocity") axis_max_velocity; 
		float nicename("Direction Acceleration") direction_acceleration; 
		float nicename("Direction Max Velocity") direction_max_velocity; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
		Undefined32 __unknown15; 
		Undefined32 __unknown16; 
	};

	struct s_unknown_12_block_definition
	{
		struct s_unknown_1_block_definition;
		struct s_unknown_1_2_block_definition;

		s_tag_block_definition<s_unknown_1_block_definition> __unknown_1_block; 
		s_tag_block_definition<s_unknown_1_2_block_definition> __unknown_1_2_block; 

		struct s_unknown_1_block_definition
		{
			int16_t __unknown; 
		};

		struct s_unknown_1_2_block_definition
		{
			Undefined32 __unknown; 
			Undefined32 __unknown2; 
			Undefined32 __unknown3; 
			Undefined32 __unknown4; 
		};
	};

	struct nicename("node_edge") s_node_edge_block_definition
	{
		struct nicename("Constraints") s_constraint_block_definition;

		int16_t nicename("Node A Global Material Index") node_a_global_material_index; 
		int16_t nicename("Node B Global Material Index") node_b_global_material_index; 
		int16_t nicename("Node A") node_a; 
		int16_t nicename("Node B") node_b; 
		s_tag_block_definition<s_constraint_block_definition> nicename("Constraints") constraints_block; 
		string_id nicename("Node A Material") node_a_material; 
		string_id nicename("Node B Material") node_b_material; 

		struct nicename("constraint") s_constraint_block_definition
		{
			struct s_unknown_block_definition;
			struct s_unknown2_block_definition;

			int16_t nicename("Type") type; 
			int16_t nicename("Index") index; 
			int32_t nicename("Flags") flags; 
			float nicename("Friction") friction; 
			s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
			s_tag_block_definition<s_unknown2_block_definition> __unknown2_block; 

			struct s_unknown_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
				int16_t __unknown3; 
				int16_t __unknown4; 
				int16_t __unknown5; 
				int16_t __unknown6; 
			};

			struct s_unknown2_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
			};
		};
	};

	struct nicename("rigid_body") s_rigid_body_block_definition
	{
		int16_t nicename("Node") node; 
		int16_t nicename("Region") region; 
		int16_t nicename("Permutations") permutations; 
		int16_t __unknown; 
		float nicename("Bounding Sphere Offset x") bounding_sphere_offset_x; 
		float nicename("Bounding Sphere Offset y") bounding_sphere_offset_y; 
		float nicename("Bounding Sphere Offset z") bounding_sphere_offset_z; 
		float nicename("Bounding Sphere Radius") bounding_sphere_radius; 
		uint16_t nicename("Flags") flags; 
		int16_t __unknown2; 
		int8_t nicename("Motion Type") motion_type; 
		int8_t __unknown3; 
		int16_t nicename("Size") size; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
		Undefined32 __inertia_tensor_scale; 
		Undefined32 __linear_dampening; 
		Undefined32 __angular_dampening; 
		Undefined32 __center_of_mass_offset_x; 
		Undefined32 __center_of_mass_offset_y; 
		Undefined32 __center_of_mass_offset_z; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
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
		int32_t __unknown_interaction; 
		Undefined32 __unknown14; 
		int16_t nicename("Shape Type") shape_type; 
		int16_t nicename("Shape Index") shape_index; 
		int32_t __unknown15; 
		float nicename("Mass") mass; 
		Undefined32 __unknown16; 
		int16_t nicename("Interaction A") interaction_a; 
		int16_t nicename("Interaction B") interaction_b; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		Undefined32 __unknown21; 
	};

	struct nicename("material") s_material_block_definition
	{
		string_id nicename("Name") name; 
		Undefined32 __unknown; 
		string_id nicename("Material Name") material_name; 
		int16_t nicename("Phantom Type Index") phantom_type_index; 
		int8_t __unknown2; 
		int8_t __unknown3; 
	};

	struct nicename("sphere") s_sphere_block_definition
	{
		string_id nicename("Name") name; 
		int8_t nicename("Material Index") material_index; 
		int8_t __unknown; 
		int16_t nicename("Global Material Index") global_material_index; 
		float nicename("Relative Mass Scale") relative_mass_scale; 
		float nicename("Friction") friction; 
		float nicename("Restitution") restitution; 
		float nicename("Volume") volume; 
		float nicename("Mass") mass; 
		int16_t nicename("Overall Shape Index") overall_shape_index; 
		int8_t nicename("Phantom Index") phantom_index; 
		int8_t nicename("Interaction Unknown") interaction_unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		int16_t nicename("Size") size; 
		int16_t nicename("Count") count; 
		Undefined32 __unknown4; 
		int32_t nicename("Offset") offset; 
		Undefined32 __unknown5; 
		int32_t __unknown6; 
		Undefined32 __unknown7; 
		float nicename("Radius") radius; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
		Undefined32 __unknown15; 
		Undefined32 __unknown16; 
		int16_t nicename("Size") size2; 
		int16_t nicename("Count") count2; 
		Undefined32 __unknown17; 
		int32_t nicename("Offset") offset2; 
		Undefined32 __unknown18; 
		int32_t __unknown19; 
		Undefined32 __unknown20; 
		float nicename("Radius") radius2; 
		Undefined32 __unknown21; 
		Undefined32 __unknown22; 
		Undefined32 __unknown23; 
		Undefined32 __unknown24; 
		Undefined32 __unknown25; 
		Undefined32 __unknown26; 
		Undefined32 __unknown27; 
		float nicename("Translation i") translation_i; 
		float nicename("Translation j") translation_j; 
		float nicename("Translation k") translation_k; 
		float nicename("Translation Radius") translation_radius; 
	};

	struct nicename("pill") s_pill_block_definition
	{
		string_id nicename("Name") name; 
		int8_t nicename("Material Index") material_index; 
		int8_t __unknown; 
		int16_t nicename("Global Material Index") global_material_index; 
		float nicename("Relative Mass Scale") relative_mass_scale; 
		float nicename("Friction") friction; 
		float nicename("Restitution") restitution; 
		float nicename("Volume") volume; 
		float nicename("Mass") mass; 
		int16_t nicename("Overall Shape Index") overall_shape_index; 
		int8_t nicename("Phantom Index") phantom_index; 
		int8_t nicename("Interaction Unknown") interaction_unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		int16_t nicename("Size") size; 
		int16_t nicename("Count") count; 
		Undefined32 __unknown4; 
		int32_t nicename("Offset") offset; 
		Undefined32 __unknown5; 
		int32_t __unknown6; 
		Undefined32 __unknown7; 
		float nicename("Radius") radius; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
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
		int8_t nicename("Material Index") material_index; 
		int8_t __unknown; 
		int16_t nicename("Global Material Index") global_material_index; 
		float nicename("Relative Mass Scale") relative_mass_scale; 
		float nicename("Friction") friction; 
		float nicename("Restitution") restitution; 
		float nicename("Volume") volume; 
		float nicename("Mass") mass; 
		int16_t nicename("Overall Shape Index") overall_shape_index; 
		int8_t nicename("Phantom Index") phantom_index; 
		int8_t nicename("Interaction Unknown") interaction_unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		int16_t nicename("Size") size; 
		int16_t nicename("Count") count; 
		Undefined32 __unknown4; 
		int32_t nicename("Offset") offset; 
		Undefined32 __unknown5; 
		int32_t __unknown6; 
		Undefined32 __unknown7; 
		float nicename("Radius") radius; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		float nicename("Half Extents i") half_extents_i; 
		float nicename("Half Extents j") half_extents_j; 
		float nicename("Half Extents k") half_extents_k; 
		float nicename("Half Extents Radius") half_extents_radius; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		int16_t nicename("Size") size2; 
		int16_t nicename("Count") count2; 
		Undefined32 __unknown13; 
		int32_t nicename("Offset") offset2; 
		Undefined32 __unknown14; 
		int32_t __unknown15; 
		Undefined32 __unknown16; 
		float nicename("Radius") radius2; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		Undefined32 __unknown21; 
		Undefined32 __unknown22; 
		Undefined32 __unknown23; 
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
		int8_t nicename("Material Index") material_index; 
		int8_t __unknown; 
		int16_t nicename("Global Material Index") global_material_index; 
		float nicename("Relative Mass Scale") relative_mass_scale; 
		float nicename("Friction") friction; 
		float nicename("Restitution") restitution; 
		float nicename("Volume") volume; 
		float nicename("Mass") mass; 
		int16_t nicename("Overall Shape Index") overall_shape_index; 
		int8_t nicename("Phantom Index") phantom_index; 
		int8_t nicename("Interaction Unknown") interaction_unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		int16_t nicename("Size") size; 
		int16_t nicename("Count") count; 
		Undefined32 __unknown4; 
		int32_t nicename("Offset") offset; 
		Undefined32 __unknown5; 
		int32_t __unknown6; 
		Undefined32 __unknown7; 
		float nicename("Radius") radius; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		float nicename("AABB Half Extents i") aabb_half_extents_i; 
		float nicename("AABB Half Extents j") aabb_half_extents_j; 
		float nicename("AABB Half Extents k") aabb_half_extents_k; 
		float nicename("AABB Half Extents Radius") aabb_half_extents_radius; 
		float nicename("AABB Center i") aabb_center_i; 
		float nicename("AABB Center j") aabb_center_j; 
		float nicename("AABB Center k") aabb_center_k; 
		float nicename("AABB Center Radius") aabb_center_radius; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		int32_t nicename("Four Vectors Size") four_vectors_size; 
		uint32_t nicename("Four Vectors Capacity") four_vectors_capacity; 
		int32_t __unknown13; 
		Undefined32 __unknown14; 
		Undefined32 __unknown15; 
		Undefined32 __unknown16; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 
		int32_t nicename("Plane Equations Size") plane_equations_size; 
		uint32_t nicename("Plane Equations Capacity") plane_equations_capacity; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		Undefined32 __unknown21; 
		Undefined32 __unknown22; 
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
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		int16_t nicename("Size") size; 
		int16_t nicename("Count") count; 
		Undefined32 __unknown3; 
		int32_t nicename("Offset") offset; 
		Undefined32 __unknown4; 
		int32_t __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		int32_t nicename("Child Shapes Size") child_shapes_size; 
		uint32_t nicename("Child Shapes Capacity") child_shapes_capacity; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
		Undefined32 __unknown15; 
		float __unknown16; 
		float __unknown17; 
		float __unknown18; 
		float __unknown19; 
		float __unknown20; 
		float __unknown21; 
		float __unknown22; 
		float __unknown23; 
		float __unknown24; 
		int32_t __unknown25; 
		int32_t __unknown26; 
		int32_t __unknown27; 
		int32_t __unknown28; 
		int32_t __unknown29; 
		int32_t __unknown30; 
		int32_t __unknown31; 
		int32_t __unknown32; 
	};

	struct nicename("list_shape") s_list_shape_block_definition
	{
		int16_t nicename("Shape Type") shape_type; 
		int16_t nicename("Shape Index") shape_index; 
		int32_t __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		int32_t __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
	};

	struct nicename("mopp") s_mopp_block_definition
	{
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		int16_t nicename("Size") size; 
		int16_t nicename("Count") count; 
		Undefined32 __unknown3; 
		int32_t nicename("Offset") offset; 
		Undefined32 __unknown4; 
		int32_t __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
		Undefined32 __unknown14; 
		Undefined32 __unknown15; 
		Undefined32 __unknown16; 
		Undefined32 __unknown17; 
		Undefined32 __unknown18; 
		Undefined32 __unknown19; 
		Undefined32 __unknown20; 
		int16_t nicename("Shape Type") shape_type; 
		int16_t nicename("Shape Index") shape_index; 
		int32_t __unknown21; 
		Undefined32 __unknown22; 
		Undefined32 __unknown23; 
		Undefined32 __unknown24; 
		Undefined32 __unknown25; 
		Undefined32 __unknown26; 
		Undefined32 __unknown27; 
		Undefined32 __unknown28; 
		Undefined32 __unknown29; 
	};

	struct nicename("hinge_constraint") s_hinge_constraint_block_definition
	{
		string_id nicename("Name") name; 
		int16_t nicename("Node A") node_a; 
		int16_t nicename("Node B") node_b; 
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
		int16_t nicename("Edge Index") edge_index; 
		int16_t __unknown; 
		Undefined32 __unknown2; 
	};

	struct nicename("ragdoll_constraint") s_ragdoll_constraint_block_definition
	{
		string_id nicename("Name") name; 
		int16_t nicename("Node A") node_a; 
		int16_t nicename("Node B") node_b; 
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
		int16_t nicename("Edge Index") edge_index; 
		int16_t __unknown; 
		Undefined32 __unknown2; 
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
				int16_t nicename("Rigid Body Index") rigid_body_index; 
			};
		};
	};

	struct nicename("node") s_node_block_definition
	{
		string_id nicename("Name") name; 
		uint16_t nicename("Flags") flags; 
		int16_t nicename("Parent") parent; 
		int16_t nicename("Sibling") sibling; 
		int16_t nicename("Child") child; 
	};

	struct nicename("limited_hinge_constraint") s_limited_hinge_constraint_block_definition
	{
		string_id nicename("Name") name; 
		int16_t nicename("Node A") node_a; 
		int16_t nicename("Node B") node_b; 
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
		int16_t nicename("Edge Index") edge_index; 
		int16_t __unknown; 
		Undefined32 __unknown2; 
		float nicename("Limit Friction") limit_friction; 
		float nicename("Limit Min Angle") limit_min_angle; 
		float nicename("Limit Max Angle") limit_max_angle; 
	};

	struct nicename("phantom") s_phantom_block_definition
	{
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		int16_t nicename("Size") size; 
		int16_t nicename("Count") count; 
		Undefined32 __unknown3; 
		int32_t nicename("Offset") offset; 
		Undefined32 __unknown4; 
		int32_t __unknown5; 
		Undefined32 __unknown6; 
		int16_t nicename("Shape Type") shape_type; 
		int16_t nicename("Shape Index") shape_index; 
		int32_t __unknown7; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
		int16_t nicename("Size") size2; 
		int16_t nicename("Count") count2; 
		Undefined32 __unknown14; 
		int32_t nicename("Offset") offset2; 
		Undefined32 __unknown15; 
		int32_t __unknown16; 
		Undefined32 __unknown17; 
	};
};
