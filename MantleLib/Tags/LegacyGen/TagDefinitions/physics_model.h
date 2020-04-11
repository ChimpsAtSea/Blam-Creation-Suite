#pragma once

struct nicename("physics_model") tag_group('phmo') s_physics_model_definition_legacy
{
	struct nicename("Unknown") s_unknown_definition_legacy
	{
		string_id_legacy __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
		float __unknown4;
		s_undefined32_legacy __unknown5;
	};

	struct nicename("Unknown") s_unknown1_definition_legacy
	{
		string_id_legacy nicename("Name") name;
		float __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
		float __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
	};

	struct nicename("Phantom Types") s_phantom_types_definition_legacy
	{
		enum nicename("Minimum Size") e_minimum_size : uint8_t
		{
			/*nicename("Default")*/ _minimum_size_default = 0ui8,
			/*nicename("Tiny")*/ _minimum_size_tiny = 1ui8,
			/*nicename("Small")*/ _minimum_size_small = 2ui8,
			/*nicename("Medium")*/ _minimum_size_medium = 3ui8,
			/*nicename("Large")*/ _minimum_size_large = 4ui8,
			/*nicename("Huge")*/ _minimum_size_huge = 5ui8,
			/*nicename("Extra Huge")*/ _minimum_size_extra_huge = 6ui8,
		};

		enum nicename("Maximum Size") e_maximum_size : uint8_t
		{
			/*nicename("Default")*/ _maximum_size_default = 0ui8,
			/*nicename("Tiny")*/ _maximum_size_tiny = 1ui8,
			/*nicename("Small")*/ _maximum_size_small = 2ui8,
			/*nicename("Medium")*/ _maximum_size_medium = 3ui8,
			/*nicename("Large")*/ _maximum_size_large = 4ui8,
			/*nicename("Huge")*/ _maximum_size_huge = 5ui8,
			/*nicename("Extra Huge")*/ _maximum_size_extra_huge = 6ui8,
		};

		enum nicename("Flags") b_flags : uint32_t /* bitfield */
		{
			/*nicename("Generates Effects")*/ _flags_generates_effects = 1ui32 << 0ui32,
			/*nicename("Use Acceleration As Force")*/ _flags_use_acceleration_as_force = 1ui32 << 1ui32,
			/*nicename("Negates Gravity")*/ _flags_negates_gravity = 1ui32 << 2ui32,
			/*nicename("Ignores Players")*/ _flags_ignores_players = 1ui32 << 3ui32,
			/*nicename("Ignores NonPlayers")*/ _flags_ignores_nonplayers = 1ui32 << 4ui32,
			/*nicename("Ignores Bipeds")*/ _flags_ignores_bipeds = 1ui32 << 5ui32,
			/*nicename("Ignores Vehicles")*/ _flags_ignores_vehicles = 1ui32 << 6ui32,
			/*nicename("Ignores Weapons")*/ _flags_ignores_weapons = 1ui32 << 7ui32,
			/*nicename("Ignores Equipment")*/ _flags_ignores_equipment = 1ui32 << 8ui32,
			/*nicename("Ignores Terminals")*/ _flags_ignores_terminals = 1ui32 << 9ui32,
			/*nicename("Ignores Projectiles")*/ _flags_ignores_projectiles = 1ui32 << 10ui32,
			/*nicename("Ignores Scenery")*/ _flags_ignores_scenery = 1ui32 << 11ui32,
			/*nicename("Ignores Machines")*/ _flags_ignores_machines = 1ui32 << 12ui32,
			/*nicename("Ignores Controls")*/ _flags_ignores_controls = 1ui32 << 13ui32,
			/*nicename("Ignores Sound Scenery")*/ _flags_ignores_sound_scenery = 1ui32 << 14ui32,
			/*nicename("Ignores Crates")*/ _flags_ignores_crates = 1ui32 << 15ui32,
			/*nicename("Ignores Creatures")*/ _flags_ignores_creatures = 1ui32 << 16ui32,
			/*nicename("Ignores Giants")*/ _flags_ignores_giants = 1ui32 << 17ui32,
			/*nicename("Ignores Effect Scenery")*/ _flags_ignores_effect_scenery = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags_bit_31 = 1ui32 << 31ui32,
		};

		b_flags nicename("Flags") flags;
		s_undefined32_legacy __unknown0;
		e_minimum_size nicename("Minimum Size") minimum_size;
		e_maximum_size nicename("Maximum Size") maximum_size;
		int16_t __unknown1;
		string_id_legacy nicename("Marker Name") marker_name;
		string_id_legacy nicename("Alignment Marker Name") alignment_marker_name;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		float nicename("Hooke's Law 'E'") hookes_law_e;
		float nicename("Linear Dead Radius") linear_dead_radius;
		float nicename("Center Acceleration") center_acceleration;
		float nicename("Center Max Velocity") center_max_velocity;
		float nicename("Axis Acceleration") axis_acceleration;
		float nicename("Axis Max Velocity") axis_max_velocity;
		float nicename("Direction Acceleration") direction_acceleration;
		float nicename("Direction Max Velocity") direction_max_velocity;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_undefined32_legacy __unknown12;
		s_undefined32_legacy __unknown13;
		s_undefined32_legacy __unknown14;
		s_undefined32_legacy __unknown15;
	};

	struct nicename("Unknown 12") s_unknown_12_definition_legacy
	{
		struct nicename("Unknown 1") s_unknown_1_definition_legacy
		{
			int16_t __unknown0;
		};

		struct nicename("Unknown 1") s_unknown_11_definition_legacy
		{
			s_undefined32_legacy __unknown0;
			s_undefined32_legacy __unknown1;
			s_undefined32_legacy __unknown2;
			s_undefined32_legacy __unknown3;
		};

		s_tag_block_legacy<s_unknown_1_definition_legacy> nicename("Unknown 1") unknown_1_block;
		s_tag_block_legacy<s_unknown_11_definition_legacy> nicename("Unknown 1") unknown_11_block;
	};

	struct nicename("Node Edges") s_node_edges_definition_legacy
	{
		struct nicename("Constraints") s_constraints_definition_legacy
		{
			enum nicename("Type") e_type : uint16_t
			{
				/*nicename("Hinge")*/ _type_hinge = 0ui16,
				/*nicename("Limited Hinge")*/ _type_limited_hinge = 1ui16,
				/*nicename("Ragdoll")*/ _type_ragdoll = 2ui16,
				/*nicename("Stiff Spring")*/ _type_stiff_spring = 3ui16,
				/*nicename("Ball and Socket")*/ _type_ball_and_socket = 4ui16,
				/*nicename("Prismatic")*/ _type_prismatic = 5ui16,
			};

			enum nicename("Flags") b_flags : uint32_t /* bitfield */
			{
				/*nicename("Bit 0")*/ _flags_bit_0 = 1ui32 << 0ui32,
				/*nicename("Bit 1")*/ _flags_bit_1 = 1ui32 << 1ui32,
				/*nicename("Bit 2")*/ _flags_bit_2 = 1ui32 << 2ui32,
				/*nicename("Bit 3")*/ _flags_bit_3 = 1ui32 << 3ui32,
				/*nicename("Bit 4")*/ _flags_bit_4 = 1ui32 << 4ui32,
				/*nicename("Bit 5")*/ _flags_bit_5 = 1ui32 << 5ui32,
				/*nicename("Bit 6")*/ _flags_bit_6 = 1ui32 << 6ui32,
				/*nicename("Bit 7")*/ _flags_bit_7 = 1ui32 << 7ui32,
				/*nicename("Bit 8")*/ _flags_bit_8 = 1ui32 << 8ui32,
				/*nicename("Bit 9")*/ _flags_bit_9 = 1ui32 << 9ui32,
				/*nicename("Bit 10")*/ _flags_bit_10 = 1ui32 << 10ui32,
				/*nicename("Bit 11")*/ _flags_bit_11 = 1ui32 << 11ui32,
				/*nicename("Bit 12")*/ _flags_bit_12 = 1ui32 << 12ui32,
				/*nicename("Bit 13")*/ _flags_bit_13 = 1ui32 << 13ui32,
				/*nicename("Bit 14")*/ _flags_bit_14 = 1ui32 << 14ui32,
				/*nicename("Bit 15")*/ _flags_bit_15 = 1ui32 << 15ui32,
				/*nicename("Bit 16")*/ _flags_bit_16 = 1ui32 << 16ui32,
				/*nicename("Bit 17")*/ _flags_bit_17 = 1ui32 << 17ui32,
				/*nicename("Bit 18")*/ _flags_bit_18 = 1ui32 << 18ui32,
				/*nicename("Bit 19")*/ _flags_bit_19 = 1ui32 << 19ui32,
				/*nicename("Bit 20")*/ _flags_bit_20 = 1ui32 << 20ui32,
				/*nicename("Bit 21")*/ _flags_bit_21 = 1ui32 << 21ui32,
				/*nicename("Bit 22")*/ _flags_bit_22 = 1ui32 << 22ui32,
				/*nicename("Bit 23")*/ _flags_bit_23 = 1ui32 << 23ui32,
				/*nicename("Bit 24")*/ _flags_bit_24 = 1ui32 << 24ui32,
				/*nicename("Bit 25")*/ _flags_bit_25 = 1ui32 << 25ui32,
				/*nicename("Bit 26")*/ _flags_bit_26 = 1ui32 << 26ui32,
				/*nicename("Bit 27")*/ _flags_bit_27 = 1ui32 << 27ui32,
				/*nicename("Bit 28")*/ _flags_bit_28 = 1ui32 << 28ui32,
				/*nicename("Bit 29")*/ _flags_bit_29 = 1ui32 << 29ui32,
				/*nicename("Bit 30")*/ _flags_bit_30 = 1ui32 << 30ui32,
				/*nicename("Bit 31")*/ _flags_bit_31 = 1ui32 << 31ui32,
			};

			struct nicename("Unknown") s_unknown2_definition_legacy
			{
				int16_t __unknown0;
				int16_t __unknown1;
				int16_t __unknown2;
				int16_t __unknown3;
				int16_t __unknown4;
				int16_t __unknown5;
			};

			struct nicename("Unknown") s_unknown3_definition_legacy
			{
				int16_t __unknown0;
				int16_t __unknown1;
			};

			e_type nicename("Type") type;
			int16_t nicename("Index") index;
			b_flags nicename("Flags") flags;
			float nicename("Friction") friction;
			s_tag_block_legacy<s_unknown2_definition_legacy> __unknown0;
			s_tag_block_legacy<s_unknown3_definition_legacy> __unknown1;
		};

		int16_t nicename("Node A Global Material Index") node_a_global_material_index;
		int16_t nicename("Node B Global Material Index") node_b_global_material_index;
		int16_t nicename("Node A") node_a;
		int16_t nicename("Node B") node_b;
		s_tag_block_legacy<s_constraints_definition_legacy> nicename("Constraints") constraints_block;
		string_id_legacy nicename("Node A Material") node_a_material;
		string_id_legacy nicename("Node B Material") node_b_material;
	};

	struct nicename("Rigid Bodies") s_rigid_bodies_definition_legacy
	{
		enum nicename("Motion Type") e_motion_type : uint8_t
		{
			/*nicename("Sphere")*/ _motion_type_sphere = 0ui8,
			/*nicename("Stabilized Sphere")*/ _motion_type_stabilized_sphere = 1ui8,
			/*nicename("Box")*/ _motion_type_box = 2ui8,
			/*nicename("Stabilized Box")*/ _motion_type_stabilized_box = 3ui8,
			/*nicename("Keyframed")*/ _motion_type_keyframed = 4ui8,
			/*nicename("Fixed")*/ _motion_type_fixed = 5ui8,
		};

		enum nicename("Size") e_size : uint16_t
		{
			/*nicename("Default")*/ _size_default = 0ui16,
			/*nicename("Tiny")*/ _size_tiny = 1ui16,
			/*nicename("Small")*/ _size_small = 2ui16,
			/*nicename("Medium")*/ _size_medium = 3ui16,
			/*nicename("Large")*/ _size_large = 4ui16,
			/*nicename("Huge")*/ _size_huge = 5ui16,
			/*nicename("Extra Huge")*/ _size_extra_huge = 6ui16,
		};

		enum nicename("Shape Type") e_shape_type : uint16_t
		{
			/*nicename("Sphere")*/ _shape_type_sphere = 0ui16,
			/*nicename("Pill")*/ _shape_type_pill = 1ui16,
			/*nicename("Box")*/ _shape_type_box = 2ui16,
			/*nicename("Triangle")*/ _shape_type_triangle = 3ui16,
			/*nicename("Polyhedron")*/ _shape_type_polyhedron = 4ui16,
			/*nicename("Multi-Sphere")*/ _shape_type_multi_sphere = 5ui16,
			/*nicename("Unused 0")*/ _shape_type_unused_0 = 6ui16,
			/*nicename("Unused 1")*/ _shape_type_unused_1 = 7ui16,
			/*nicename("Unused 2")*/ _shape_type_unused_2 = 8ui16,
			/*nicename("Unused 3")*/ _shape_type_unused_3 = 9ui16,
			/*nicename("Unused 4")*/ _shape_type_unused_4 = 10ui16,
			/*nicename("Unused 5")*/ _shape_type_unused_5 = 11ui16,
			/*nicename("Unused 6")*/ _shape_type_unused_6 = 12ui16,
			/*nicename("Unused 7")*/ _shape_type_unused_7 = 13ui16,
			/*nicename("List")*/ _shape_type_list = 14ui16,
			/*nicename("MOPP")*/ _shape_type_mopp = 15ui16,
		};

		enum nicename("Flags") b_flags : uint16_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _flags_bit_0 = 1ui16 << 0ui16,
			/*nicename("Locked In Place")*/ _flags_locked_in_place = 1ui16 << 1ui16,
			/*nicename("Bit 2")*/ _flags_bit_2 = 1ui16 << 2ui16,
			/*nicename("Does Not Interact With Environment")*/ _flags_does_not_interact_with_environment = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _flags_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _flags_bit_5 = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _flags_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _flags_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _flags_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _flags_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _flags_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _flags_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _flags_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _flags_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _flags_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _flags_bit_15 = 1ui16 << 15ui16,
		};

		int16_t nicename("Node") node;
		int16_t nicename("Region") region;
		int16_t nicename("Permutations") permutations;
		int16_t __unknown0;
		float nicename("Bounding Sphere Offset x") bounding_sphere_offset_x;
		float nicename("Bounding Sphere Offset y") bounding_sphere_offset_y;
		float nicename("Bounding Sphere Offset z") bounding_sphere_offset_z;
		float nicename("Bounding Sphere Radius") bounding_sphere_radius;
		b_flags nicename("Flags") flags;
		int16_t __unknown1;
		e_motion_type nicename("Motion Type") motion_type;
		int8_t __unknown2;
		e_size nicename("Size") size;
		float __unknown3;
		float __unknown4;
		float __unknown5;
		s_undefined32_legacy nicename("Inertia Tensor Scale") inertia_tensor_scale;
		s_undefined32_legacy nicename("Linear Dampening") linear_dampening;
		s_undefined32_legacy nicename("Angular Dampening") angular_dampening;
		s_undefined32_legacy nicename("Center Of Mass Offset x") center_of_mass_offset_x;
		s_undefined32_legacy nicename("Center Of Mass Offset y") center_of_mass_offset_y;
		s_undefined32_legacy nicename("Center Of Mass Offset z") center_of_mass_offset_z;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_undefined32_legacy __unknown12;
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
		int32_t nicename("Unknown Interaction") unknown_interaction;
		s_undefined32_legacy __unknown13;
		e_shape_type nicename("Shape Type") shape_type;
		int16_t nicename("Shape Index") shape_index;
		int32_t __unknown14;
		float nicename("Mass") mass;
		s_undefined32_legacy __unknown15;
		int16_t nicename("Interaction A") interaction_a;
		int16_t nicename("Interaction B") interaction_b;
		s_undefined32_legacy __unknown16;
		s_undefined32_legacy __unknown17;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
		s_undefined32_legacy __unknown20;
	};

	struct nicename("Materials") s_materials_definition_legacy
	{
		string_id_legacy nicename("Name") name;
		s_undefined32_legacy __unknown0;
		string_id_legacy nicename("Material Name") material_name;
		int16_t nicename("Phantom Type Index") phantom_type_index;
		int8_t __unknown1;
		int8_t __unknown2;
	};

	struct nicename("Spheres") s_spheres_definition_legacy
	{
		string_id_legacy nicename("Name") name;
		int8_t nicename("Material Index") material_index;
		int8_t __unknown0;
		int16_t nicename("Global Material Index") global_material_index;
		float nicename("Relative Mass Scale") relative_mass_scale;
		float nicename("Friction") friction;
		float nicename("Restitution") restitution;
		float nicename("Volume") volume;
		float nicename("Mass") mass;
		int16_t nicename("Overall Shape Index") overall_shape_index;
		int8_t nicename("Phantom Index") phantom_index;
		int8_t nicename("Interaction Unknown") interaction_unknown;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		int16_t nicename("Size") size;
		int16_t nicename("Count") count;
		s_undefined32_legacy __unknown3;
		int32_t nicename("Offset") offset;
		s_undefined32_legacy __unknown4;
		int32_t __unknown5;
		s_undefined32_legacy __unknown6;
		float nicename("Radius") radius;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_undefined32_legacy __unknown12;
		s_undefined32_legacy __unknown13;
		s_undefined32_legacy __unknown14;
		s_undefined32_legacy __unknown15;
		int16_t nicename("Size") size1;
		int16_t nicename("Count") count1;
		s_undefined32_legacy __unknown16;
		int32_t nicename("Offset") offset1;
		s_undefined32_legacy __unknown17;
		int32_t __unknown18;
		s_undefined32_legacy __unknown19;
		float nicename("Radius") radius1;
		s_undefined32_legacy __unknown20;
		s_undefined32_legacy __unknown21;
		s_undefined32_legacy __unknown22;
		s_undefined32_legacy __unknown23;
		s_undefined32_legacy __unknown24;
		s_undefined32_legacy __unknown25;
		s_undefined32_legacy __unknown26;
		float nicename("Translation i") translation_i;
		float nicename("Translation j") translation_j;
		float nicename("Translation k") translation_k;
		float nicename("Translation Radius") translation_radius;
	};

	struct nicename("Pills") s_pills_definition_legacy
	{
		string_id_legacy nicename("Name") name;
		int8_t nicename("Material Index") material_index;
		int8_t __unknown0;
		int16_t nicename("Global Material Index") global_material_index;
		float nicename("Relative Mass Scale") relative_mass_scale;
		float nicename("Friction") friction;
		float nicename("Restitution") restitution;
		float nicename("Volume") volume;
		float nicename("Mass") mass;
		int16_t nicename("Overall Shape Index") overall_shape_index;
		int8_t nicename("Phantom Index") phantom_index;
		int8_t nicename("Interaction Unknown") interaction_unknown;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		int16_t nicename("Size") size;
		int16_t nicename("Count") count;
		s_undefined32_legacy __unknown3;
		int32_t nicename("Offset") offset;
		s_undefined32_legacy __unknown4;
		int32_t __unknown5;
		s_undefined32_legacy __unknown6;
		float nicename("Radius") radius;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		float nicename("Bottom i") bottom_i;
		float nicename("Bottom j") bottom_j;
		float nicename("Bottom k") bottom_k;
		float nicename("Bottom Radius") bottom_radius;
		float nicename("Top i") top_i;
		float nicename("Top j") top_j;
		float nicename("Top k") top_k;
		float nicename("Top Radius") top_radius;
	};

	struct nicename("Boxes") s_boxes_definition_legacy
	{
		string_id_legacy nicename("Name") name;
		int8_t nicename("Material Index") material_index;
		int8_t __unknown0;
		int16_t nicename("Global Material Index") global_material_index;
		float nicename("Relative Mass Scale") relative_mass_scale;
		float nicename("Friction") friction;
		float nicename("Restitution") restitution;
		float nicename("Volume") volume;
		float nicename("Mass") mass;
		int16_t nicename("Overall Shape Index") overall_shape_index;
		int8_t nicename("Phantom Index") phantom_index;
		int8_t nicename("Interaction Unknown") interaction_unknown;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		int16_t nicename("Size") size;
		int16_t nicename("Count") count;
		s_undefined32_legacy __unknown3;
		int32_t nicename("Offset") offset;
		s_undefined32_legacy __unknown4;
		int32_t __unknown5;
		s_undefined32_legacy __unknown6;
		float nicename("Radius") radius;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		float nicename("Half Extents i") half_extents_i;
		float nicename("Half Extents j") half_extents_j;
		float nicename("Half Extents k") half_extents_k;
		float nicename("Half Extents Radius") half_extents_radius;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		int16_t nicename("Size") size1;
		int16_t nicename("Count") count1;
		s_undefined32_legacy __unknown12;
		int32_t nicename("Offset") offset1;
		s_undefined32_legacy __unknown13;
		int32_t __unknown14;
		s_undefined32_legacy __unknown15;
		float nicename("Radius") radius1;
		s_undefined32_legacy __unknown16;
		s_undefined32_legacy __unknown17;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
		s_undefined32_legacy __unknown20;
		s_undefined32_legacy __unknown21;
		s_undefined32_legacy __unknown22;
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

	struct nicename("Polyhedra") s_polyhedra_definition_legacy
	{
		string_id_legacy nicename("Name") name;
		int8_t nicename("Material Index") material_index;
		int8_t __unknown0;
		int16_t nicename("Global Material Index") global_material_index;
		float nicename("Relative Mass Scale") relative_mass_scale;
		float nicename("Friction") friction;
		float nicename("Restitution") restitution;
		float nicename("Volume") volume;
		float nicename("Mass") mass;
		int16_t nicename("Overall Shape Index") overall_shape_index;
		int8_t nicename("Phantom Index") phantom_index;
		int8_t nicename("Interaction Unknown") interaction_unknown;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		int16_t nicename("Size") size;
		int16_t nicename("Count") count;
		s_undefined32_legacy __unknown3;
		int32_t nicename("Offset") offset;
		s_undefined32_legacy __unknown4;
		int32_t __unknown5;
		s_undefined32_legacy __unknown6;
		float nicename("Radius") radius;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		float nicename("AABB Half Extents i") aabb_half_extents_i;
		float nicename("AABB Half Extents j") aabb_half_extents_j;
		float nicename("AABB Half Extents k") aabb_half_extents_k;
		float nicename("AABB Half Extents Radius") aabb_half_extents_radius;
		float nicename("AABB Center i") aabb_center_i;
		float nicename("AABB Center j") aabb_center_j;
		float nicename("AABB Center k") aabb_center_k;
		float nicename("AABB Center Radius") aabb_center_radius;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		int32_t nicename("Four Vectors Size") four_vectors_size;
		uint32_t nicename("Four Vectors Capacity") four_vectors_capacity;
		int32_t __unknown12;
		s_undefined32_legacy __unknown13;
		s_undefined32_legacy __unknown14;
		s_undefined32_legacy __unknown15;
		s_undefined32_legacy __unknown16;
		s_undefined32_legacy __unknown17;
		int32_t nicename("Plane Equations Size") plane_equations_size;
		uint32_t nicename("Plane Equations Capacity") plane_equations_capacity;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
		s_undefined32_legacy __unknown20;
		s_undefined32_legacy __unknown21;
	};

	struct nicename("Polyhedron Four Vectors") s_polyhedron_four_vectors_definition_legacy
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

	struct nicename("Polyhedron Plane Equations") s_polyhedron_plane_equations_definition_legacy
	{
		float __unknown0;
		float __unknown1;
		float __unknown2;
		float __unknown3;
	};

	struct nicename("Lists") s_lists_definition_legacy
	{
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		int16_t nicename("Size") size;
		int16_t nicename("Count") count;
		s_undefined32_legacy __unknown2;
		int32_t nicename("Offset") offset;
		s_undefined32_legacy __unknown3;
		int32_t __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		int32_t nicename("Child Shapes Size") child_shapes_size;
		uint32_t nicename("Child Shapes Capacity") child_shapes_capacity;
		s_undefined32_legacy __unknown12;
		s_undefined32_legacy __unknown13;
		s_undefined32_legacy __unknown14;
		float __unknown15;
		float __unknown16;
		float __unknown17;
		float __unknown18;
		float __unknown19;
		float __unknown20;
		float __unknown21;
		float __unknown22;
		float __unknown23;
		int32_t __unknown24;
		int32_t __unknown25;
		int32_t __unknown26;
		int32_t __unknown27;
		int32_t __unknown28;
		int32_t __unknown29;
		int32_t __unknown30;
		int32_t __unknown31;
	};

	struct nicename("List Shapes") s_list_shapes_definition_legacy
	{
		enum nicename("Shape Type") e_shape_type : uint16_t
		{
			/*nicename("Sphere")*/ _shape_type_sphere = 0ui16,
			/*nicename("Pill")*/ _shape_type_pill = 1ui16,
			/*nicename("Box")*/ _shape_type_box = 2ui16,
			/*nicename("Triangle")*/ _shape_type_triangle = 3ui16,
			/*nicename("Polyhedron")*/ _shape_type_polyhedron = 4ui16,
			/*nicename("Multi-Sphere")*/ _shape_type_multi_sphere = 5ui16,
			/*nicename("Unknown Shape")*/ _shape_type_unknown_shape = 6ui16,
			/*nicename("Unused 1")*/ _shape_type_unused_1 = 7ui16,
			/*nicename("Unused 2")*/ _shape_type_unused_2 = 8ui16,
			/*nicename("Unused 3")*/ _shape_type_unused_3 = 9ui16,
			/*nicename("Unused 4")*/ _shape_type_unused_4 = 10ui16,
			/*nicename("Unused 5")*/ _shape_type_unused_5 = 11ui16,
			/*nicename("Unused 6")*/ _shape_type_unused_6 = 12ui16,
			/*nicename("Unused 7")*/ _shape_type_unused_7 = 13ui16,
			/*nicename("List")*/ _shape_type_list = 14ui16,
			/*nicename("MOPP")*/ _shape_type_mopp = 15ui16,
		};

		e_shape_type nicename("Shape Type") shape_type;
		int16_t nicename("Shape Index") shape_index;
		int32_t __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		int32_t __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
	};

	struct nicename("MOPPs") s_mopps_definition_legacy
	{
		enum nicename("Shape Type") e_shape_type : uint16_t
		{
			/*nicename("Sphere")*/ _shape_type_sphere = 0ui16,
			/*nicename("Pill")*/ _shape_type_pill = 1ui16,
			/*nicename("Box")*/ _shape_type_box = 2ui16,
			/*nicename("Triangle")*/ _shape_type_triangle = 3ui16,
			/*nicename("Polyhedron")*/ _shape_type_polyhedron = 4ui16,
			/*nicename("Multi-Sphere")*/ _shape_type_multi_sphere = 5ui16,
			/*nicename("Unknown Shape")*/ _shape_type_unknown_shape = 6ui16,
			/*nicename("Unused 1")*/ _shape_type_unused_1 = 7ui16,
			/*nicename("Unused 2")*/ _shape_type_unused_2 = 8ui16,
			/*nicename("Unused 3")*/ _shape_type_unused_3 = 9ui16,
			/*nicename("Unused 4")*/ _shape_type_unused_4 = 10ui16,
			/*nicename("Unused 5")*/ _shape_type_unused_5 = 11ui16,
			/*nicename("Unused 6")*/ _shape_type_unused_6 = 12ui16,
			/*nicename("Unused 7")*/ _shape_type_unused_7 = 13ui16,
			/*nicename("List")*/ _shape_type_list = 14ui16,
			/*nicename("MOPP")*/ _shape_type_mopp = 15ui16,
		};

		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		int16_t nicename("Size") size;
		int16_t nicename("Count") count;
		s_undefined32_legacy __unknown2;
		int32_t nicename("Offset") offset;
		s_undefined32_legacy __unknown3;
		int32_t __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_undefined32_legacy __unknown12;
		s_undefined32_legacy __unknown13;
		s_undefined32_legacy __unknown14;
		s_undefined32_legacy __unknown15;
		s_undefined32_legacy __unknown16;
		s_undefined32_legacy __unknown17;
		s_undefined32_legacy __unknown18;
		s_undefined32_legacy __unknown19;
		e_shape_type nicename("Shape Type") shape_type;
		int16_t nicename("Shape Index") shape_index;
		int32_t __unknown20;
		s_undefined32_legacy __unknown21;
		s_undefined32_legacy __unknown22;
		s_undefined32_legacy __unknown23;
		s_undefined32_legacy __unknown24;
		s_undefined32_legacy __unknown25;
		s_undefined32_legacy __unknown26;
		s_undefined32_legacy __unknown27;
		s_undefined32_legacy __unknown28;
	};

	struct nicename("Hinge Constraints") s_hinge_constraints_definition_legacy
	{
		string_id_legacy nicename("Name") name;
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
		int16_t __unknown0;
		s_undefined32_legacy __unknown1;
	};

	struct nicename("Ragdoll Constraints") s_ragdoll_constraints_definition_legacy
	{
		string_id_legacy nicename("Name") name;
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
		int16_t __unknown0;
		s_undefined32_legacy __unknown1;
		float nicename("Min Twist") min_twist;
		float nicename("Max Twist") max_twist;
		float nicename("Min Cone") min_cone;
		float nicename("Max Cone") max_cone;
		float nicename("Min Plane") min_plane;
		float nicename("Max Plane") max_plane;
		float nicename("Max Friction Torque") max_friction_torque;
	};

	struct nicename("Regions") s_regions_definition_legacy
	{
		struct nicename("Permutations") s_permutations_definition_legacy
		{
			struct nicename("Rigid Bodies") s_rigid_bodies1_definition_legacy
			{
				int16_t nicename("Rigid Body Index") rigid_body_index;
			};

			string_id_legacy nicename("Name") name;
			s_tag_block_legacy<s_rigid_bodies1_definition_legacy> nicename("Rigid Bodies") rigid_bodies_block;
		};

		string_id_legacy nicename("Name") name;
		s_tag_block_legacy<s_permutations_definition_legacy> nicename("Permutations") permutations_block;
	};

	struct nicename("Nodes") s_nodes_definition_legacy
	{
		enum nicename("Flags") b_flags : uint16_t /* bitfield */
		{
			/*nicename("Bit 0")*/ _flags_bit_0 = 1ui16 << 0ui16,
			/*nicename("Bit 1")*/ _flags_bit_1 = 1ui16 << 1ui16,
			/*nicename("Bit 2")*/ _flags_bit_2 = 1ui16 << 2ui16,
			/*nicename("Bit 3")*/ _flags_bit_3 = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _flags_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _flags_bit_5 = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _flags_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _flags_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _flags_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _flags_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _flags_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _flags_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _flags_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _flags_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _flags_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _flags_bit_15 = 1ui16 << 15ui16,
		};

		string_id_legacy nicename("Name") name;
		b_flags nicename("Flags") flags;
		int16_t nicename("Parent") parent;
		int16_t nicename("Sibling") sibling;
		int16_t nicename("Child") child;
	};

	struct nicename("Limited Hinge Constraints") s_limited_hinge_constraints_definition_legacy
	{
		string_id_legacy nicename("Name") name;
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
		int16_t __unknown0;
		s_undefined32_legacy __unknown1;
		float nicename("Limit Friction") limit_friction;
		float nicename("Limit Min Angle") limit_min_angle;
		float nicename("Limit Max Angle") limit_max_angle;
	};

	struct nicename("Phantoms") s_phantoms_definition_legacy
	{
		enum nicename("Shape Type") e_shape_type : uint16_t
		{
			/*nicename("Sphere")*/ _shape_type_sphere = 0ui16,
			/*nicename("Pill")*/ _shape_type_pill = 1ui16,
			/*nicename("Box")*/ _shape_type_box = 2ui16,
			/*nicename("Triangle")*/ _shape_type_triangle = 3ui16,
			/*nicename("Polyhedron")*/ _shape_type_polyhedron = 4ui16,
			/*nicename("Multi-Sphere")*/ _shape_type_multi_sphere = 5ui16,
			/*nicename("Unknown Shape")*/ _shape_type_unknown_shape = 6ui16,
			/*nicename("Unused 1")*/ _shape_type_unused_1 = 7ui16,
			/*nicename("Unused 2")*/ _shape_type_unused_2 = 8ui16,
			/*nicename("Unused 3")*/ _shape_type_unused_3 = 9ui16,
			/*nicename("Unused 4")*/ _shape_type_unused_4 = 10ui16,
			/*nicename("Unused 5")*/ _shape_type_unused_5 = 11ui16,
			/*nicename("Unused 6")*/ _shape_type_unused_6 = 12ui16,
			/*nicename("Unused 7")*/ _shape_type_unused_7 = 13ui16,
			/*nicename("List")*/ _shape_type_list = 14ui16,
			/*nicename("MOPP")*/ _shape_type_mopp = 15ui16,
		};

		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		int16_t nicename("Size") size;
		int16_t nicename("Count") count;
		s_undefined32_legacy __unknown2;
		int32_t nicename("Offset") offset;
		s_undefined32_legacy __unknown3;
		int32_t __unknown4;
		s_undefined32_legacy __unknown5;
		e_shape_type nicename("Shape Type") shape_type;
		int16_t nicename("Shape Index") shape_index;
		int32_t __unknown6;
		s_undefined32_legacy __unknown7;
		s_undefined32_legacy __unknown8;
		s_undefined32_legacy __unknown9;
		s_undefined32_legacy __unknown10;
		s_undefined32_legacy __unknown11;
		s_undefined32_legacy __unknown12;
		int16_t nicename("Size") size1;
		int16_t nicename("Count") count1;
		s_undefined32_legacy __unknown13;
		int32_t nicename("Offset") offset1;
		s_undefined32_legacy __unknown14;
		int32_t __unknown15;
		s_undefined32_legacy __unknown16;
	};

	s_undefined32_legacy __unknown0;
	s_undefined32_legacy __unknown1;
	float nicename("Mass") mass;
	float nicename("Low Frequency Decativation Scale") low_frequency_decativation_scale;
	float nicename("High Frequency Decativation Scale") high_frequency_decativation_scale;
	s_undefined32_legacy __unknown2;
	s_undefined32_legacy __unknown3;
	int8_t __unknown4;
	int8_t __unknown5;
	int8_t __unknown6;
	int8_t __unknown7;
	s_tag_block_legacy<s_unknown_definition_legacy> __unknown8;
	s_tag_block_legacy<s_unknown1_definition_legacy> __unknown9;
	s_tag_block_legacy<s_phantom_types_definition_legacy> nicename("Phantom Types") phantom_types_block;
	s_tag_block_legacy<s_unknown_12_definition_legacy> nicename("Unknown 12") unknown_12_block;
	s_tag_block_legacy<s_node_edges_definition_legacy> nicename("Node Edges") node_edges_block;
	s_tag_block_legacy<s_rigid_bodies_definition_legacy> nicename("Rigid Bodies") rigid_bodies_block;
	s_tag_block_legacy<s_materials_definition_legacy> nicename("Materials") materials_block;
	s_tag_block_legacy<s_spheres_definition_legacy> nicename("Spheres") spheres_block;
	s_undefined32_legacy nicename("Multi Spheres Block Here") multi_spheres_block_here;
	s_undefined32_legacy nicename("Multi Spheres Block Here") multi_spheres_block_here1;
	s_undefined32_legacy nicename("Multi Spheres Block Here") multi_spheres_block_here2;
	s_tag_block_legacy<s_pills_definition_legacy> nicename("Pills") pills_block;
	s_tag_block_legacy<s_boxes_definition_legacy> nicename("Boxes") boxes_block;
	s_undefined32_legacy nicename("Triangles Block Here") triangles_block_here;
	s_undefined32_legacy nicename("Triangles Block Here") triangles_block_here1;
	s_undefined32_legacy nicename("Triangles Block Here") triangles_block_here2;
	s_tag_block_legacy<s_polyhedra_definition_legacy> nicename("Polyhedra") polyhedra_block;
	s_tag_block_legacy<s_polyhedron_four_vectors_definition_legacy> nicename("Polyhedron Four Vectors") polyhedron_four_vectors_block;
	s_tag_block_legacy<s_polyhedron_plane_equations_definition_legacy> nicename("Polyhedron Plane Equations") polyhedron_plane_equations_block;
	s_undefined32_legacy nicename("Mass Distributions Block Here") mass_distributions_block_here;
	s_undefined32_legacy nicename("Mass Distributions Block Here") mass_distributions_block_here1;
	s_undefined32_legacy nicename("Mass Distributions Block Here") mass_distributions_block_here2;
	s_tag_block_legacy<s_lists_definition_legacy> nicename("Lists") lists_block;
	s_tag_block_legacy<s_list_shapes_definition_legacy> nicename("List Shapes") list_shapes_block;
	s_tag_block_legacy<s_mopps_definition_legacy> nicename("MOPPs") mopps_block;
	s_data_reference_legacy nicename("MOPP Codes") mopp_codes_data_reference;
	s_tag_block_legacy<s_hinge_constraints_definition_legacy> nicename("Hinge Constraints") hinge_constraints_block;
	s_tag_block_legacy<s_ragdoll_constraints_definition_legacy> nicename("Ragdoll Constraints") ragdoll_constraints_block;
	s_tag_block_legacy<s_regions_definition_legacy> nicename("Regions") regions_block;
	s_tag_block_legacy<s_nodes_definition_legacy> nicename("Nodes") nodes_block;
	s_undefined32_legacy __unknown10;
	s_undefined32_legacy __unknown11;
	s_undefined32_legacy __unknown12;
	s_undefined32_legacy __unknown13;
	s_undefined32_legacy __unknown14;
	s_undefined32_legacy __unknown15;
	s_tag_block_legacy<s_limited_hinge_constraints_definition_legacy> nicename("Limited Hinge Constraints") limited_hinge_constraints_block;
	s_undefined32_legacy nicename("Ball And Socket Constraint Block") ball_and_socket_constraint_block;
	s_undefined32_legacy nicename("Ball And Socket Constraint Block") ball_and_socket_constraint_block1;
	s_undefined32_legacy nicename("Ball And Socket Constraint Block") ball_and_socket_constraint_block2;
	s_undefined32_legacy nicename("Stiff Spring Constraint Block") stiff_spring_constraint_block;
	s_undefined32_legacy nicename("Stiff Spring Constraint Block") stiff_spring_constraint_block1;
	s_undefined32_legacy nicename("Stiff Spring Constraint Block") stiff_spring_constraint_block2;
	s_undefined32_legacy nicename("Prismatic Constraint Block") prismatic_constraint_block;
	s_undefined32_legacy nicename("Prismatic Constraint Block") prismatic_constraint_block1;
	s_undefined32_legacy nicename("Prismatic Constraint Block") prismatic_constraint_block2;
	s_tag_block_legacy<s_phantoms_definition_legacy> nicename("Phantoms") phantoms_block;
};

