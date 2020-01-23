#pragma once

nicename("physics_model") struct s_physics_model_definition
{
	nicename("Unknown") struct s_unknown9_block_definition;
	nicename("Unknown") struct s_unknown11_block_definition;
	nicename("Phantom Types") struct s_phantom_type_block_definition;
	nicename("Unknown 12") struct s_unknown_12_block_definition;
	nicename("Node Edges") struct s_node_edge_block_definition;
	nicename("Rigid Bodies") struct s_rigid_body_block_definition;
	nicename("Materials") struct s_material_block_definition;
	nicename("Spheres") struct s_sphere_block_definition;
	nicename("Pills") struct s_pill_block_definition;
	nicename("Boxes") struct s_box_block_definition;
	nicename("Polyhedra") struct s_polyhedron_block_definition;
	nicename("Polyhedron Four Vectors") struct s_polyhedron_four_vector_block_definition;
	nicename("Polyhedron Plane Equations") struct s_polyhedron_plane_equation_block_definition;
	nicename("Lists") struct s_list_block_definition;
	nicename("List Shapes") struct s_list_shape_block_definition;
	nicename("MOPPs") struct s_mopp_block_definition;
	nicename("Hinge Constraints") struct s_hinge_constraint_block_definition;
	nicename("Ragdoll Constraints") struct s_ragdoll_constraint_block_definition;
	nicename("Regions") struct s_region_block_definition;
	nicename("Nodes") struct s_node_block_definition;
	nicename("Limited Hinge Constraints") struct s_limited_hinge_constraint_block_definition;
	nicename("Phantoms") struct s_phantom_block_definition;

	nicename("Unknown") unsigned int unknown;
	nicename("Unknown") unsigned int unknown2;
	nicename("Mass") float mass;
	nicename("Low Frequency Decativation Scale") float low_frequency_decativation_scale;
	nicename("High Frequency Decativation Scale") float high_frequency_decativation_scale;
	nicename("Unknown") unsigned int unknown3;
	nicename("Unknown") unsigned int unknown4;
	nicename("Unknown") signed char unknown5;
	nicename("Unknown") signed char unknown6;
	nicename("Unknown") signed char unknown7;
	nicename("Unknown") signed char unknown8;
	nicename("Unknown") s_tag_block_definition<s_unknown9_block_definition> unknown10;
	nicename("Unknown") s_tag_block_definition<s_unknown11_block_definition> unknown12;
	nicename("Phantom Types") s_tag_block_definition<s_phantom_type_block_definition> phantom_types;
	nicename("Unknown 12") s_tag_block_definition<s_unknown_12_block_definition> unknown_12_2;
	nicename("Node Edges") s_tag_block_definition<s_node_edge_block_definition> node_edges;
	nicename("Rigid Bodies") s_tag_block_definition<s_rigid_body_block_definition> rigid_bodies;
	nicename("Materials") s_tag_block_definition<s_material_block_definition> materials;
	nicename("Spheres") s_tag_block_definition<s_sphere_block_definition> spheres;
	nicename("Multi Spheres Block Here") unsigned int multi_spheres_block_here;
	nicename("Multi Spheres Block Here") unsigned int multi_spheres_block_here2;
	nicename("Multi Spheres Block Here") unsigned int multi_spheres_block_here3;
	nicename("Pills") s_tag_block_definition<s_pill_block_definition> pills;
	nicename("Boxes") s_tag_block_definition<s_box_block_definition> boxes;
	nicename("Triangles Block Here") unsigned int triangles_block_here;
	nicename("Triangles Block Here") unsigned int triangles_block_here2;
	nicename("Triangles Block Here") unsigned int triangles_block_here3;
	nicename("Polyhedra") s_tag_block_definition<s_polyhedron_block_definition> polyhedra;
	nicename("Polyhedron Four Vectors") s_tag_block_definition<s_polyhedron_four_vector_block_definition> polyhedron_four_vectors;
	nicename("Polyhedron Plane Equations") s_tag_block_definition<s_polyhedron_plane_equation_block_definition> polyhedron_plane_equations;
	nicename("Mass Distributions Block Here") unsigned int mass_distributions_block_here;
	nicename("Mass Distributions Block Here") unsigned int mass_distributions_block_here2;
	nicename("Mass Distributions Block Here") unsigned int mass_distributions_block_here3;
	nicename("Lists") s_tag_block_definition<s_list_block_definition> lists;
	nicename("List Shapes") s_tag_block_definition<s_list_shape_block_definition> list_shapes;
	nicename("MOPPs") s_tag_block_definition<s_mopp_block_definition> mopps;
	nicename("MOPP Codes") DataReference mopp_codes;
	nicename("Hinge Constraints") s_tag_block_definition<s_hinge_constraint_block_definition> hinge_constraints;
	nicename("Ragdoll Constraints") s_tag_block_definition<s_ragdoll_constraint_block_definition> ragdoll_constraints;
	nicename("Regions") s_tag_block_definition<s_region_block_definition> regions;
	nicename("Nodes") s_tag_block_definition<s_node_block_definition> nodes;
	nicename("Unknown") unsigned int unknown13;
	nicename("Unknown") unsigned int unknown14;
	nicename("Unknown") unsigned int unknown15;
	nicename("Unknown") unsigned int unknown16;
	nicename("Unknown") unsigned int unknown17;
	nicename("Unknown") unsigned int unknown18;
	nicename("Limited Hinge Constraints") s_tag_block_definition<s_limited_hinge_constraint_block_definition> limited_hinge_constraints;
	nicename("Ball And Socket Constraint Block") unsigned int ball_and_socket_constraint_block;
	nicename("Ball And Socket Constraint Block") unsigned int ball_and_socket_constraint_block2;
	nicename("Ball And Socket Constraint Block") unsigned int ball_and_socket_constraint_block3;
	nicename("Stiff Spring Constraint Block") unsigned int stiff_spring_constraint_block;
	nicename("Stiff Spring Constraint Block") unsigned int stiff_spring_constraint_block2;
	nicename("Stiff Spring Constraint Block") unsigned int stiff_spring_constraint_block3;
	nicename("Prismatic Constraint Block") unsigned int prismatic_constraint_block;
	nicename("Prismatic Constraint Block") unsigned int prismatic_constraint_block2;
	nicename("Prismatic Constraint Block") unsigned int prismatic_constraint_block3;
	nicename("Phantoms") s_tag_block_definition<s_phantom_block_definition> phantoms;

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") string_id unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") unsigned int unknown7;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Name") string_id name;
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;
	};

	nicename("Phantom Type") struct s_phantom_type_definition
	{
		nicename("Flags") signed int flags;
		nicename("Unknown") unsigned int unknown;
		nicename("Minimum Size") signed char minimum_size;
		nicename("Maximum Size") signed char maximum_size;
		nicename("Unknown") signed short unknown2;
		nicename("Marker Name") string_id marker_name;
		nicename("Alignment Marker Name") string_id alignment_marker_name;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Hooke's Law 'E'") float hooke_s_law__e_;
		nicename("Linear Dead Radius") float linear_dead_radius;
		nicename("Center Acceleration") float center_acceleration;
		nicename("Center Max Velocity") float center_max_velocity;
		nicename("Axis Acceleration") float axis_acceleration;
		nicename("Axis Max Velocity") float axis_max_velocity;
		nicename("Direction Acceleration") float direction_acceleration;
		nicename("Direction Max Velocity") float direction_max_velocity;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("Unknown") unsigned int unknown11;
		nicename("Unknown") unsigned int unknown12;
		nicename("Unknown") unsigned int unknown13;
		nicename("Unknown") unsigned int unknown14;
		nicename("Unknown") unsigned int unknown15;
		nicename("Unknown") unsigned int unknown16;
	};

	nicename("Unknown 12") struct s_unknown_12_definition
	{
		nicename("Unknown 1") struct s_unknown_1_block_definition;
		nicename("Unknown 1") struct s_unknown_1_3_block_definition;

		nicename("Unknown 1") s_tag_block_definition<s_unknown_1_block_definition> unknown_1_2;
		nicename("Unknown 1") s_tag_block_definition<s_unknown_1_3_block_definition> unknown_1_4;

		nicename("Unknown 1") struct s_unknown_1_definition
		{
			nicename("Unknown") signed short unknown;
		};

		nicename("Unknown 1") struct s_unknown_1_definition
		{
			nicename("Unknown") unsigned int unknown;
			nicename("Unknown") unsigned int unknown2;
			nicename("Unknown") unsigned int unknown3;
			nicename("Unknown") unsigned int unknown4;
		};
	};

	nicename("Node Edge") struct s_node_edge_definition
	{
		nicename("Constraints") struct s_constraint_block_definition;

		nicename("Node A Global Material Index") signed short node_a_global_material_index;
		nicename("Node B Global Material Index") signed short node_b_global_material_index;
		nicename("Node A") signed short node_a;
		nicename("Node B") signed short node_b;
		nicename("Constraints") s_tag_block_definition<s_constraint_block_definition> constraints;
		nicename("Node A Material") string_id node_a_material;
		nicename("Node B Material") string_id node_b_material;

		nicename("Constraint") struct s_constraint_definition
		{
			nicename("Unknown") struct s_unknown_block_definition;
			nicename("Unknown") struct s_unknown3_block_definition;

			nicename("Type") signed short type;
			nicename("Index") signed short index;
			nicename("Flags") signed int flags;
			nicename("Friction") float friction;
			nicename("Unknown") s_tag_block_definition<s_unknown_block_definition> unknown2;
			nicename("Unknown") s_tag_block_definition<s_unknown3_block_definition> unknown4;

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") signed short unknown2;
				nicename("Unknown") signed short unknown3;
				nicename("Unknown") signed short unknown4;
				nicename("Unknown") signed short unknown5;
				nicename("Unknown") signed short unknown6;
				nicename("Unknown") signed short unknown7;
			};

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") signed short unknown2;
				nicename("Unknown") signed short unknown3;
			};
		};
	};

	nicename("Rigid Body") struct s_rigid_body_definition
	{
		nicename("Node") signed short node;
		nicename("Region") signed short region;
		nicename("Permutations") signed short permutations;
		nicename("Unknown") signed short unknown;
		nicename("Bounding Sphere Offset x") float bounding_sphere_offset_x;
		nicename("Bounding Sphere Offset y") float bounding_sphere_offset_y;
		nicename("Bounding Sphere Offset z") float bounding_sphere_offset_z;
		nicename("Bounding Sphere Radius") float bounding_sphere_radius;
		nicename("Flags") unsigned short flags;
		nicename("Unknown") signed short unknown2;
		nicename("Motion Type") signed char motion_type;
		nicename("Unknown") signed char unknown3;
		nicename("Size") signed short size;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Inertia Tensor Scale") unsigned int inertia_tensor_scale;
		nicename("Linear Dampening") unsigned int linear_dampening;
		nicename("Angular Dampening") unsigned int angular_dampening;
		nicename("Center Of Mass Offset x") unsigned int center_of_mass_offset_x;
		nicename("Center Of Mass Offset y") unsigned int center_of_mass_offset_y;
		nicename("Center Of Mass Offset z") unsigned int center_of_mass_offset_z;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("Unknown") unsigned int unknown11;
		nicename("Unknown") unsigned int unknown12;
		nicename("Unknown") unsigned int unknown13;
		nicename("Center of Mass i") float center_of_mass_i;
		nicename("Center of Mass j") float center_of_mass_j;
		nicename("Center of Mass k") float center_of_mass_k;
		nicename("Center of Mass Radius") float center_of_mass_radius;
		nicename("Inertia Tensor x i") float inertia_tensor_x_i;
		nicename("Inertia Tensor x j") float inertia_tensor_x_j;
		nicename("Inertia Tensor x k") float inertia_tensor_x_k;
		nicename("Inertia Tensor x Radius") float inertia_tensor_x_radius;
		nicename("Inertia Tensor y i") float inertia_tensor_y_i;
		nicename("Inertia Tensor y j") float inertia_tensor_y_j;
		nicename("Inertia Tensor y k") float inertia_tensor_y_k;
		nicename("Inertia Tensor y Radius") float inertia_tensor_y_radius;
		nicename("Inertia Tensor z i") float inertia_tensor_z_i;
		nicename("Inertia Tensor z j") float inertia_tensor_z_j;
		nicename("Inertia Tensor z k") float inertia_tensor_z_k;
		nicename("Inertia Tensor z Radius") float inertia_tensor_z_radius;
		nicename("Unknown Interaction") signed int unknown_interaction;
		nicename("Unknown") unsigned int unknown14;
		nicename("Shape Type") signed short shape_type;
		nicename("Shape Index") signed short shape_index;
		nicename("Unknown") signed int unknown15;
		nicename("Mass") float mass;
		nicename("Unknown") unsigned int unknown16;
		nicename("Interaction A") signed short interaction_a;
		nicename("Interaction B") signed short interaction_b;
		nicename("Unknown") unsigned int unknown17;
		nicename("Unknown") unsigned int unknown18;
		nicename("Unknown") unsigned int unknown19;
		nicename("Unknown") unsigned int unknown20;
		nicename("Unknown") unsigned int unknown21;
	};

	nicename("Material") struct s_material_definition
	{
		nicename("Name") string_id name;
		nicename("Unknown") unsigned int unknown;
		nicename("Material Name") string_id material_name;
		nicename("Phantom Type Index") signed short phantom_type_index;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
	};

	nicename("Sphere") struct s_sphere_definition
	{
		nicename("Name") string_id name;
		nicename("Material Index") signed char material_index;
		nicename("Unknown") signed char unknown;
		nicename("Global Material Index") signed short global_material_index;
		nicename("Relative Mass Scale") float relative_mass_scale;
		nicename("Friction") float friction;
		nicename("Restitution") float restitution;
		nicename("Volume") float volume;
		nicename("Mass") float mass;
		nicename("Overall Shape Index") signed short overall_shape_index;
		nicename("Phantom Index") signed char phantom_index;
		nicename("Interaction Unknown") signed char interaction_unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Size") signed short size;
		nicename("Count") signed short count;
		nicename("Unknown") unsigned int unknown4;
		nicename("Offset") signed int offset;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") signed int unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Radius") float radius;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("Unknown") unsigned int unknown11;
		nicename("Unknown") unsigned int unknown12;
		nicename("Unknown") unsigned int unknown13;
		nicename("Unknown") unsigned int unknown14;
		nicename("Unknown") unsigned int unknown15;
		nicename("Unknown") unsigned int unknown16;
		nicename("Size") signed short size2;
		nicename("Count") signed short count2;
		nicename("Unknown") unsigned int unknown17;
		nicename("Offset") signed int offset2;
		nicename("Unknown") unsigned int unknown18;
		nicename("Unknown") signed int unknown19;
		nicename("Unknown") unsigned int unknown20;
		nicename("Radius") float radius2;
		nicename("Unknown") unsigned int unknown21;
		nicename("Unknown") unsigned int unknown22;
		nicename("Unknown") unsigned int unknown23;
		nicename("Unknown") unsigned int unknown24;
		nicename("Unknown") unsigned int unknown25;
		nicename("Unknown") unsigned int unknown26;
		nicename("Unknown") unsigned int unknown27;
		nicename("Translation i") float translation_i;
		nicename("Translation j") float translation_j;
		nicename("Translation k") float translation_k;
		nicename("Translation Radius") float translation_radius;
	};

	nicename("Pill") struct s_pill_definition
	{
		nicename("Name") string_id name;
		nicename("Material Index") signed char material_index;
		nicename("Unknown") signed char unknown;
		nicename("Global Material Index") signed short global_material_index;
		nicename("Relative Mass Scale") float relative_mass_scale;
		nicename("Friction") float friction;
		nicename("Restitution") float restitution;
		nicename("Volume") float volume;
		nicename("Mass") float mass;
		nicename("Overall Shape Index") signed short overall_shape_index;
		nicename("Phantom Index") signed char phantom_index;
		nicename("Interaction Unknown") signed char interaction_unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Size") signed short size;
		nicename("Count") signed short count;
		nicename("Unknown") unsigned int unknown4;
		nicename("Offset") signed int offset;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") signed int unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Radius") float radius;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("Bottom i") float bottom_i;
		nicename("Bottom j") float bottom_j;
		nicename("Bottom k") float bottom_k;
		nicename("Bottom Radius") float bottom_radius;
		nicename("Top i") float top_i;
		nicename("Top j") float top_j;
		nicename("Top k") float top_k;
		nicename("Top Radius") float top_radius;
	};

	nicename("Box") struct s_box_definition
	{
		nicename("Name") string_id name;
		nicename("Material Index") signed char material_index;
		nicename("Unknown") signed char unknown;
		nicename("Global Material Index") signed short global_material_index;
		nicename("Relative Mass Scale") float relative_mass_scale;
		nicename("Friction") float friction;
		nicename("Restitution") float restitution;
		nicename("Volume") float volume;
		nicename("Mass") float mass;
		nicename("Overall Shape Index") signed short overall_shape_index;
		nicename("Phantom Index") signed char phantom_index;
		nicename("Interaction Unknown") signed char interaction_unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Size") signed short size;
		nicename("Count") signed short count;
		nicename("Unknown") unsigned int unknown4;
		nicename("Offset") signed int offset;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") signed int unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Radius") float radius;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("Half Extents i") float half_extents_i;
		nicename("Half Extents j") float half_extents_j;
		nicename("Half Extents k") float half_extents_k;
		nicename("Half Extents Radius") float half_extents_radius;
		nicename("Unknown") unsigned int unknown11;
		nicename("Unknown") unsigned int unknown12;
		nicename("Size") signed short size2;
		nicename("Count") signed short count2;
		nicename("Unknown") unsigned int unknown13;
		nicename("Offset") signed int offset2;
		nicename("Unknown") unsigned int unknown14;
		nicename("Unknown") signed int unknown15;
		nicename("Unknown") unsigned int unknown16;
		nicename("Radius") float radius2;
		nicename("Unknown") unsigned int unknown17;
		nicename("Unknown") unsigned int unknown18;
		nicename("Unknown") unsigned int unknown19;
		nicename("Unknown") unsigned int unknown20;
		nicename("Unknown") unsigned int unknown21;
		nicename("Unknown") unsigned int unknown22;
		nicename("Unknown") unsigned int unknown23;
		nicename("Rotation i i") float rotation_i_i;
		nicename("Rotation i j") float rotation_i_j;
		nicename("Rotation i k") float rotation_i_k;
		nicename("Rotation i Radius") float rotation_i_radius;
		nicename("Rotation j i") float rotation_j_i;
		nicename("Rotation j j") float rotation_j_j;
		nicename("Rotation j k") float rotation_j_k;
		nicename("Rotation j Radius") float rotation_j_radius;
		nicename("Rotation k i") float rotation_k_i;
		nicename("Rotation k j") float rotation_k_j;
		nicename("Rotation k k") float rotation_k_k;
		nicename("Rotation k Radius") float rotation_k_radius;
		nicename("Translation i") float translation_i;
		nicename("Translation j") float translation_j;
		nicename("Translation k") float translation_k;
		nicename("Translation Radius") float translation_radius;
	};

	nicename("Polyhedron") struct s_polyhedron_definition
	{
		nicename("Name") string_id name;
		nicename("Material Index") signed char material_index;
		nicename("Unknown") signed char unknown;
		nicename("Global Material Index") signed short global_material_index;
		nicename("Relative Mass Scale") float relative_mass_scale;
		nicename("Friction") float friction;
		nicename("Restitution") float restitution;
		nicename("Volume") float volume;
		nicename("Mass") float mass;
		nicename("Overall Shape Index") signed short overall_shape_index;
		nicename("Phantom Index") signed char phantom_index;
		nicename("Interaction Unknown") signed char interaction_unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Size") signed short size;
		nicename("Count") signed short count;
		nicename("Unknown") unsigned int unknown4;
		nicename("Offset") signed int offset;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") signed int unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Radius") float radius;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("AABB Half Extents i") float aabb_half_extents_i;
		nicename("AABB Half Extents j") float aabb_half_extents_j;
		nicename("AABB Half Extents k") float aabb_half_extents_k;
		nicename("AABB Half Extents Radius") float aabb_half_extents_radius;
		nicename("AABB Center i") float aabb_center_i;
		nicename("AABB Center j") float aabb_center_j;
		nicename("AABB Center k") float aabb_center_k;
		nicename("AABB Center Radius") float aabb_center_radius;
		nicename("Unknown") unsigned int unknown11;
		nicename("Unknown") unsigned int unknown12;
		nicename("Four Vectors Size") signed int four_vectors_size;
		nicename("Four Vectors Capacity") unsigned int four_vectors_capacity;
		nicename("Unknown") signed int unknown13;
		nicename("Unknown") unsigned int unknown14;
		nicename("Unknown") unsigned int unknown15;
		nicename("Plane Equations Size") signed int plane_equations_size;
		nicename("Plane Equations Capacity") unsigned int plane_equations_capacity;
		nicename("Unknown") unsigned int unknown16;
		nicename("Unknown") unsigned int unknown17;
		nicename("Unknown") unsigned int unknown18;
		nicename("Unknown") unsigned int unknown19;
	};

	nicename("Polyhedron Four Vector") struct s_polyhedron_four_vector_definition
	{
		nicename("Four Vectors x i") float four_vectors_x_i;
		nicename("Four Vectors x j") float four_vectors_x_j;
		nicename("Four Vectors x k") float four_vectors_x_k;
		nicename("Four Vectors x Radius") float four_vectors_x_radius;
		nicename("Four Vectors y i") float four_vectors_y_i;
		nicename("Four Vectors y j") float four_vectors_y_j;
		nicename("Four Vectors y k") float four_vectors_y_k;
		nicename("Four Vectors y Radius") float four_vectors_y_radius;
		nicename("Four Vectors z i") float four_vectors_z_i;
		nicename("Four Vectors z j") float four_vectors_z_j;
		nicename("Four Vectors z k") float four_vectors_z_k;
		nicename("Four Vectors z Radius") float four_vectors_z_radius;
	};

	nicename("Polyhedron Plane Equation") struct s_polyhedron_plane_equation_definition
	{
		nicename("Unknown") float unknown;
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
	};

	nicename("List") struct s_list_definition
	{
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Size") signed short size;
		nicename("Count") signed short count;
		nicename("Unknown") unsigned int unknown3;
		nicename("Offset") signed int offset;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") signed int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("Unknown") unsigned int unknown11;
		nicename("Unknown") unsigned int unknown12;
		nicename("Child Shapes Size") signed int child_shapes_size;
		nicename("Child Shapes Capacity") unsigned int child_shapes_capacity;
		nicename("Unknown") unsigned int unknown13;
		nicename("Unknown") unsigned int unknown14;
		nicename("Unknown") unsigned int unknown15;
		nicename("Unknown") float unknown16;
		nicename("Unknown") float unknown17;
		nicename("Unknown") float unknown18;
		nicename("Unknown") float unknown19;
		nicename("Unknown") float unknown20;
		nicename("Unknown") float unknown21;
		nicename("Unknown") float unknown22;
		nicename("Unknown") float unknown23;
		nicename("Unknown") float unknown24;
		nicename("Unknown") signed int unknown25;
		nicename("Unknown") signed int unknown26;
		nicename("Unknown") signed int unknown27;
		nicename("Unknown") signed int unknown28;
		nicename("Unknown") signed int unknown29;
		nicename("Unknown") signed int unknown30;
		nicename("Unknown") signed int unknown31;
		nicename("Unknown") signed int unknown32;
	};

	nicename("List Shape") struct s_list_shape_definition
	{
		nicename("Shape Type") signed short shape_type;
		nicename("Shape Index") signed short shape_index;
		nicename("Unknown") signed int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") signed int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("Unknown") unsigned int unknown7;
	};

	nicename("MOPP") struct s_mopp_definition
	{
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Size") signed short size;
		nicename("Count") signed short count;
		nicename("Unknown") unsigned int unknown3;
		nicename("Offset") signed int offset;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") signed int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("Unknown") unsigned int unknown11;
		nicename("Unknown") unsigned int unknown12;
		nicename("Unknown") unsigned int unknown13;
		nicename("Unknown") unsigned int unknown14;
		nicename("Unknown") unsigned int unknown15;
		nicename("Unknown") unsigned int unknown16;
		nicename("Unknown") unsigned int unknown17;
		nicename("Unknown") unsigned int unknown18;
		nicename("Unknown") unsigned int unknown19;
		nicename("Unknown") unsigned int unknown20;
		nicename("Shape Type") signed short shape_type;
		nicename("Shape Index") signed short shape_index;
		nicename("Unknown") signed int unknown21;
		nicename("Unknown") unsigned int unknown22;
		nicename("Unknown") unsigned int unknown23;
		nicename("Unknown") unsigned int unknown24;
		nicename("Unknown") unsigned int unknown25;
		nicename("Unknown") unsigned int unknown26;
		nicename("Unknown") unsigned int unknown27;
		nicename("Unknown") unsigned int unknown28;
		nicename("Unknown") unsigned int unknown29;
	};

	nicename("Hinge Constraint") struct s_hinge_constraint_definition
	{
		nicename("Name") string_id name;
		nicename("Node A") signed short node_a;
		nicename("Node B") signed short node_b;
		nicename("A Scale") float a_scale;
		nicename("A Forward i") float a_forward_i;
		nicename("A Forward j") float a_forward_j;
		nicename("A Forward k") float a_forward_k;
		nicename("A Left i") float a_left_i;
		nicename("A Left j") float a_left_j;
		nicename("A Left k") float a_left_k;
		nicename("A Up i") float a_up_i;
		nicename("A Up j") float a_up_j;
		nicename("A Up k") float a_up_k;
		nicename("A Position x") float a_position_x;
		nicename("A Position y") float a_position_y;
		nicename("A Position z") float a_position_z;
		nicename("B Scale") float b_scale;
		nicename("B Forward i") float b_forward_i;
		nicename("B Forward j") float b_forward_j;
		nicename("B Forward k") float b_forward_k;
		nicename("B Left i") float b_left_i;
		nicename("B Left j") float b_left_j;
		nicename("B Left k") float b_left_k;
		nicename("B Up i") float b_up_i;
		nicename("B Up j") float b_up_j;
		nicename("B Up k") float b_up_k;
		nicename("B Position i") float b_position_i;
		nicename("B Position j") float b_position_j;
		nicename("B Position k") float b_position_k;
		nicename("Edge Index") signed short edge_index;
		nicename("Unknown") signed short unknown;
		nicename("Unknown") unsigned int unknown2;
	};

	nicename("Ragdoll Constraint") struct s_ragdoll_constraint_definition
	{
		nicename("Name") string_id name;
		nicename("Node A") signed short node_a;
		nicename("Node B") signed short node_b;
		nicename("A Scale") float a_scale;
		nicename("A Forward i") float a_forward_i;
		nicename("A Forward j") float a_forward_j;
		nicename("A Forward k") float a_forward_k;
		nicename("A Left i") float a_left_i;
		nicename("A Left j") float a_left_j;
		nicename("A Left k") float a_left_k;
		nicename("A Up i") float a_up_i;
		nicename("A Up j") float a_up_j;
		nicename("A Up k") float a_up_k;
		nicename("A Position x") float a_position_x;
		nicename("A Position y") float a_position_y;
		nicename("A Position z") float a_position_z;
		nicename("B Scale") float b_scale;
		nicename("B Forward i") float b_forward_i;
		nicename("B Forward j") float b_forward_j;
		nicename("B Forward k") float b_forward_k;
		nicename("B Left i") float b_left_i;
		nicename("B Left j") float b_left_j;
		nicename("B Left k") float b_left_k;
		nicename("B Up i") float b_up_i;
		nicename("B Up j") float b_up_j;
		nicename("B Up k") float b_up_k;
		nicename("B Position x") float b_position_x;
		nicename("B Position y") float b_position_y;
		nicename("B Position z") float b_position_z;
		nicename("Edge Index") signed short edge_index;
		nicename("Unknown") signed short unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Min Twist") float min_twist;
		nicename("Max Twist") float max_twist;
		nicename("Min Cone") float min_cone;
		nicename("Max Cone") float max_cone;
		nicename("Min Plane") float min_plane;
		nicename("Max Plane") float max_plane;
		nicename("Max Friction Torque") float max_friction_torque;
	};

	nicename("Region") struct s_region_definition
	{
		nicename("Permutations") struct s_permutation_block_definition;

		nicename("Name") string_id name;
		nicename("Permutations") s_tag_block_definition<s_permutation_block_definition> permutations;

		nicename("Permutation") struct s_permutation_definition
		{
			nicename("Rigid Bodies") struct s_rigid_body_block_definition;

			nicename("Name") string_id name;
			nicename("Rigid Bodies") s_tag_block_definition<s_rigid_body_block_definition> rigid_bodies;

			nicename("Rigid Body") struct s_rigid_body_definition
			{
				nicename("Rigid Body Index") signed short rigid_body_index;
			};
		};
	};

	nicename("Node") struct s_node_definition
	{
		nicename("Name") string_id name;
		nicename("Flags") unsigned short flags;
		nicename("Parent") signed short parent;
		nicename("Sibling") signed short sibling;
		nicename("Child") signed short child;
	};

	nicename("Limited Hinge Constraint") struct s_limited_hinge_constraint_definition
	{
		nicename("Name") string_id name;
		nicename("Node A") signed short node_a;
		nicename("Node B") signed short node_b;
		nicename("A Scale") float a_scale;
		nicename("A Forward i") float a_forward_i;
		nicename("A Forward j") float a_forward_j;
		nicename("A Forward k") float a_forward_k;
		nicename("A Left i") float a_left_i;
		nicename("A Left j") float a_left_j;
		nicename("A Left k") float a_left_k;
		nicename("A Up i") float a_up_i;
		nicename("A Up j") float a_up_j;
		nicename("A Up k") float a_up_k;
		nicename("A Position x") float a_position_x;
		nicename("A Position y") float a_position_y;
		nicename("A Position z") float a_position_z;
		nicename("B Scale") float b_scale;
		nicename("B Forward i") float b_forward_i;
		nicename("B Forward j") float b_forward_j;
		nicename("B Forward k") float b_forward_k;
		nicename("B Left i") float b_left_i;
		nicename("B Left j") float b_left_j;
		nicename("B Left k") float b_left_k;
		nicename("B Up i") float b_up_i;
		nicename("B Up j") float b_up_j;
		nicename("B Up k") float b_up_k;
		nicename("B Position x") float b_position_x;
		nicename("B Position y") float b_position_y;
		nicename("B Position z") float b_position_z;
		nicename("Edge Index") signed short edge_index;
		nicename("Unknown") signed short unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Limit Friction") float limit_friction;
		nicename("Limit Min Angle") float limit_min_angle;
		nicename("Limit Max Angle") float limit_max_angle;
	};

	nicename("Phantom") struct s_phantom_definition
	{
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Size") signed short size;
		nicename("Count") signed short count;
		nicename("Unknown") unsigned int unknown3;
		nicename("Offset") signed int offset;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") signed int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("Shape Type") signed short shape_type;
		nicename("Shape Index") signed short shape_index;
		nicename("Unknown") signed int unknown7;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("Unknown") unsigned int unknown11;
		nicename("Unknown") unsigned int unknown12;
		nicename("Unknown") unsigned int unknown13;
		nicename("Size") signed short size2;
		nicename("Count") signed short count2;
		nicename("Unknown") unsigned int unknown14;
		nicename("Offset") signed int offset2;
		nicename("Unknown") unsigned int unknown15;
		nicename("Unknown") signed int unknown16;
		nicename("Unknown") unsigned int unknown17;
	};
};
