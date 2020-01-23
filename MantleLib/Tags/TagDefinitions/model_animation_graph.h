#pragma once

struct nicename("Model Animation Graph") group('jmad') s_model_animation_graph_definition
{
	struct s_unknown_block_definition;
	struct nicename("Aim Blending") s_aim_blending_block_definition;
	struct nicename("Pain") s_pain_block_definition;
	struct nicename("Variant Mode Substitution") s_variant_mode_substitution_block_definition;
	struct nicename("Skeleton Nodes") s_skeleton_node_block_definition;
	struct nicename("Sound References") s_sound_reference_block_definition;
	struct nicename("Effect References") s_effect_reference_block_definition;
	struct nicename("Blend Screens") s_blend_screen_block_definition;
	struct nicename("Legs") s_leg_block_definition;
	struct nicename("Animations") s_animation_block_definition;
	struct nicename("Animations 2") s_animations_2_block_definition;
	struct nicename("Trigger Animations") s_trigger_animation_block_definition;
	struct nicename("Animation Groups") s_animation_group_block_definition;
	struct nicename("Locomotion") s_locomotion_block_definition;
	struct nicename("Movement Groups") s_movement_group_block_definition;
	struct nicename("Limb ik") s_limb_ik_block_definition;
	struct nicename("Limb ik Groups") s_limb_ik_group_block_definition;
	struct nicename("Limb Positioning") s_limb_positioning_block_definition;
	struct nicename("Modes") s_mode_block_definition;
	struct nicename("Vehicle Suspension") s_vehicle_suspension_block_definition;
	struct nicename("Object Overlays") s_object_overlay_block_definition;
	struct nicename("Inheritance List") s_inheritance_list_block_definition;
	struct nicename("New Inheritance List") s_new_inheritance_list_block_definition;
	struct nicename("Weapon List") s_weapon_list_block_definition;
	struct nicename("Raw Information Groups") s_raw_information_group_block_definition;

	TagReference nicename("Parent Animation Graph") parent_animation_graph_reference; 
	uint8_t nicename("Inheritance Flags") inheritance_flags; 
	uint8_t nicename("Private Flags") private_flags; 
	int16_t nicename("Animation Codec Pack") animation_codec_pack; 
	int16_t __unknown; 
	int16_t __unknown2; 
	s_tag_block_definition<s_unknown_block_definition> __unknown3_block; 
	s_tag_block_definition<s_aim_blending_block_definition> nicename("Aim Blending") aim_blending_block; 
	s_tag_block_definition<s_pain_block_definition> nicename("Pain") pain_block; 
	s_tag_block_definition<s_variant_mode_substitution_block_definition> nicename("Variant Mode Substitution") variant_mode_substitution_block; 
	s_tag_block_definition<s_skeleton_node_block_definition> nicename("Skeleton Nodes") skeleton_nodes_block; 
	s_tag_block_definition<s_sound_reference_block_definition> nicename("Sound References") sound_references_block; 
	s_tag_block_definition<s_effect_reference_block_definition> nicename("Effect References") effect_references_block; 
	s_tag_block_definition<s_blend_screen_block_definition> nicename("Blend Screens") blend_screens_block; 
	s_tag_block_definition<s_leg_block_definition> nicename("Legs") legs_block; 
	TagReference nicename("Frame Events") frame_events_reference; 
	s_tag_block_definition<s_animation_block_definition> nicename("Animations") animations_block; 
	s_tag_block_definition<s_animations_2_block_definition> nicename("Animations 2") animations_2_block; 
	s_tag_block_definition<s_trigger_animation_block_definition> nicename("Trigger Animations") trigger_animations_block; 
	s_tag_block_definition<s_animation_group_block_definition> nicename("Animation Groups") animation_groups_block; 
	s_tag_block_definition<s_locomotion_block_definition> nicename("Locomotion") locomotion_block; 
	s_tag_block_definition<s_movement_group_block_definition> nicename("Movement Groups") movement_groups_block; 
	s_tag_block_definition<s_limb_ik_block_definition> nicename("Limb ik") limb_ik_block; 
	s_tag_block_definition<s_limb_ik_group_block_definition> nicename("Limb ik Groups") limb_ik_groups_block; 
	s_tag_block_definition<s_limb_positioning_block_definition> nicename("Limb Positioning") limb_positioning_block; 
	int16_t __unknown4; 
	int16_t __unknown5; 
	s_tag_block_definition<s_mode_block_definition> nicename("Modes") modes_block; 
	s_tag_block_definition<s_vehicle_suspension_block_definition> nicename("Vehicle Suspension") vehicle_suspension_block; 
	s_tag_block_definition<s_object_overlay_block_definition> nicename("Object Overlays") object_overlays_block; 
	// comment
	s_tag_block_definition<s_inheritance_list_block_definition> nicename("Inheritance List") inheritance_list_block; 
	s_tag_block_definition<s_new_inheritance_list_block_definition> nicename("New Inheritance List") new_inheritance_list_block; 
	s_tag_block_definition<s_weapon_list_block_definition> nicename("Weapon List") weapon_list_block; 
	int32_t __unknown_arm_nodes_1; 
	int32_t __unknown_arm_nodes_2; 
	int32_t __unknown_arm_nodes_3; 
	int32_t __unknown_arm_nodes_4; 
	int32_t __unknown_arm_nodes_5; 
	int32_t __unknown_arm_nodes_6; 
	int32_t __unknown_arm_nodes_7; 
	int32_t __unknown_arm_nodes_8; 
	int32_t __unknown_nodes_1; 
	int32_t __unknown_nodes_2; 
	int32_t __unknown_nodes_3; 
	int32_t __unknown_nodes_4; 
	int32_t __unknown_nodes_5; 
	int32_t __unknown_nodes_6; 
	int32_t __unknown_nodes_7; 
	int32_t __unknown_nodes_8; 
	DataReference nicename("Last Import Results") last_import_results_data_reference; 
	Undefined32 __unknown6; 
	Undefined32 __unknown7; 
	Undefined32 __unknown8; 
	s_tag_block_definition<s_raw_information_group_block_definition> nicename("Raw Information Groups") raw_information_groups_block; 

	struct s_unknown_block_definition
	{
		int16_t __unknown; 
		int16_t __unknown2; 
	};

	struct nicename("aim_blending") s_aim_blending_block_definition
	{
		struct nicename("Bones") s_bone_block_definition;

		string_id nicename("Name") name; 
		s_tag_block_definition<s_bone_block_definition> nicename("Bones") bones_block; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t __unknown4; 
		int8_t __unknown5; 
		int8_t __unknown6; 
		int8_t __unknown7; 
		int8_t __unknown8; 
		int8_t __unknown9; 
		int8_t __unknown10; 
		int8_t __unknown11; 
		int8_t __unknown12; 
		int8_t __unknown13; 
		int8_t __unknown14; 
		int8_t __unknown15; 
		int8_t __unknown16; 
		int8_t __unknown17; 
		int8_t __unknown18; 
		int8_t __unknown19; 
		int8_t __unknown20; 
		int8_t __unknown21; 
		int8_t __unknown22; 
		int8_t __unknown23; 
		int8_t __unknown24; 
		int8_t __unknown25; 
		int8_t __unknown26; 
		int8_t __unknown27; 
		int8_t __unknown28; 
		int8_t __unknown29; 
		int8_t __unknown30; 
		int8_t __unknown31; 
		int8_t __unknown32; 

		struct nicename("bone") s_bone_block_definition
		{
			int16_t nicename("Bone") bone; 
			int16_t __unknown; 
		};
	};

	struct nicename("pain") s_pain_block_definition
	{
		string_id nicename("Name") name; 
		DataReference nicename("Function") function_data_reference; 
	};

	struct nicename("variant_mode_substitution") s_variant_mode_substitution_block_definition
	{
		struct nicename("Modes") s_mode_block_definition;

		string_id nicename("Variant Name") variant_name; 
		int32_t __unknown; 
		s_tag_block_definition<s_mode_block_definition> nicename("Modes") modes_block; 

		struct nicename("mode") s_mode_block_definition
		{
			string_id nicename("Original Mode") original_mode; 
			string_id nicename("New Mode") new_mode; 
		};
	};

	struct nicename("skeleton_node") s_skeleton_node_block_definition
	{
		string_id nicename("Name") name; 
		int16_t nicename("Next Sibling Node Index") next_sibling_node_index; 
		int16_t nicename("First Child Node Index") first_child_node_index; 
		int16_t nicename("Parent Node Index") parent_node_index; 
		uint8_t nicename("Model Flags") model_flags; 
		uint8_t nicename("Node Joint Flags") node_joint_flags; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int16_t __unknown3; 
		float nicename("Base Vector i") base_vector_i; 
		float nicename("Base Vector j") base_vector_j; 
		float nicename("Base Vector k") base_vector_k; 
		float nicename("Vector Range") vector_range; 
		float nicename("z Position") z_position; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
	};

	struct nicename("sound_reference") s_sound_reference_block_definition
	{
		TagReference nicename("Sound") sound_reference; 
		uint16_t nicename("Flags") flags; 
		int16_t __unknown; 
	};

	struct nicename("effect_reference") s_effect_reference_block_definition
	{
		TagReference nicename("Effect") effect_reference; 
		uint16_t nicename("Flags") flags; 
		int16_t __unknown; 
	};

	struct nicename("blend_screen") s_blend_screen_block_definition
	{
		string_id nicename("Label") label; 
		float nicename("Right Yaw Per Frame") right_yaw_per_frame; 
		float nicename("Left Yaw Per Frame") left_yaw_per_frame; 
		int16_t nicename("Right Frame Count") right_frame_count; 
		int16_t nicename("Left Frame Count") left_frame_count; 
		float nicename("Down Pitch Per Frame") down_pitch_per_frame; 
		float nicename("Up Pitch Per Frame") up_pitch_per_frame; 
		int16_t nicename("Down Pitch Frame Count") down_pitch_frame_count; 
		int16_t nicename("Up Pitch Frame Count") up_pitch_frame_count; 
	};

	struct nicename("leg") s_leg_block_definition
	{
		string_id nicename("Foot Marker") foot_marker; 
		float nicename("Foot min") foot_min; 
		float nicename("Foot max") foot_max; 
		string_id nicename("Ankle Marker") ankle_marker; 
		float nicename("Ankle min") ankle_min; 
		float nicename("Ankle max") ankle_max; 
		int16_t nicename("Anchors") anchors; 
		int16_t __unknown; 
	};

	struct nicename("animation") s_animation_block_definition
	{
		struct nicename("Animation Definition") s_animation_definition_block_definition;

		string_id nicename("Name") name; 
		float nicename("Weight") weight; 
		int16_t nicename("Loop Frame Index") loop_frame_index; 
		uint16_t nicename("Playback Flags") playback_flags; 
		float __unknown; 
		float __unknown2; 
		int16_t nicename("Previous Variant Sibling") previous_variant_sibling; 
		int16_t nicename("Next Variant Sibling") next_variant_sibling; 
		uint16_t nicename("Production Flags") production_flags; 
		int8_t nicename("Blend Screen") blend_screen; 
		int8_t __unknown3; 
		TagReference nicename("Parent") parent_reference; 
		int16_t nicename("Parent Index") parent_index; 
		int16_t __unknown4; 
		s_tag_block_definition<s_animation_definition_block_definition> nicename("Animation Definition") animation_definition_block; 

		struct nicename("animation_definition") s_animation_definition_block_definition
		{
			struct nicename("Frame Events") s_frame_event_block_definition;
			struct nicename("Sound Events") s_sound_event_block_definition;
			struct nicename("Effect Events") s_effect_event_block_definition;
			struct s_unknown_14_block_definition;
			struct nicename("Object-Space Parent Nodes") s_object_space_parent_node_block_definition;
			struct nicename("Leg Anchoring") s_leg_anchoring_block_definition;
			struct s_unknown_block_definition;
			struct s_unknown2_block_definition;
			struct nicename("New Mode ik") s_new_mode_ik_block_definition;
			struct s_unknown3_block_definition;
			struct s_unknown4_block_definition;
			struct s_unknown5_block_definition;

			int8_t nicename("Node Count") node_count; 
			int8_t __unknown; 
			int16_t nicename("Frame Count") frame_count; 
			int8_t __unknown2; 
			int8_t __unknown3; 
			int8_t __unknown4; 
			int8_t __unknown5; 
			int16_t __unknown6; 
			int8_t __unknown7; 
			int8_t __unknown8; 
			int32_t nicename("Production Checksum") production_checksum; 
			string_id nicename("Import Path") import_path; 
			int32_t nicename("Node List Checksum") node_list_checksum; 
			int32_t __unknown9; 
			int16_t __unknown10; 
			int16_t __unknown11; 
			int16_t nicename("Raw Information Group Index") raw_information_group_index; 
			int16_t nicename("Raw Information Member Index") raw_information_member_index; 
			float __unknown12; 
			float __unknown13; 
			float __unknown14; 
			float __unknown15; 
			float __unknown16; 
			s_tag_block_definition<s_frame_event_block_definition> nicename("Frame Events") frame_events_block; 
			s_tag_block_definition<s_sound_event_block_definition> nicename("Sound Events") sound_events_block; 
			s_tag_block_definition<s_effect_event_block_definition> nicename("Effect Events") effect_events_block; 
			s_tag_block_definition<s_unknown_14_block_definition> __unknown_14_block; 
			s_tag_block_definition<s_object_space_parent_node_block_definition> nicename("Object-Space Parent Nodes") object_space_parent_nodes_block; 
			s_tag_block_definition<s_leg_anchoring_block_definition> nicename("Leg Anchoring") leg_anchoring_block; 
			s_tag_block_definition<s_unknown_block_definition> __unknown17_block; 
			s_tag_block_definition<s_unknown2_block_definition> __unknown18_block; 
			s_tag_block_definition<s_new_mode_ik_block_definition> nicename("New Mode ik") new_mode_ik_block; 
			Undefined32 __unknown19; 
			Undefined32 __unknown20; 
			Undefined32 __unknown21; 
			s_tag_block_definition<s_unknown3_block_definition> __unknown22_block; 
			s_tag_block_definition<s_unknown4_block_definition> __unknown23_block; 
			s_tag_block_definition<s_unknown5_block_definition> __unknown24_block; 

			struct nicename("frame_event") s_frame_event_block_definition
			{
				int16_t nicename("Type") type; 
				int16_t nicename("Frame") frame; 
			};

			struct nicename("sound_event") s_sound_event_block_definition
			{
				int16_t nicename("Sound") sound; 
				int16_t nicename("Frame") frame; 
				string_id nicename("Marker Name") marker_name; 
			};

			struct nicename("effect_event") s_effect_event_block_definition
			{
				int16_t nicename("Effect") effect; 
				int16_t nicename("Frame") frame; 
				string_id nicename("Marker Name") marker_name; 
				int8_t nicename("Damage Reporting Type") damage_reporting_type; 
				int8_t __unknown; 
				int8_t __unknown2; 
				int8_t __unknown3; 
			};

			struct s_unknown_14_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
			};

			struct nicename("object_space_parent_node") s_object_space_parent_node_block_definition
			{
				int16_t nicename("Node Index") node_index; 
				uint16_t nicename("Component Flags") component_flags; 
				int16_t nicename("Rotation x") rotation_x; 
				int16_t nicename("Rotation y") rotation_y; 
				int16_t nicename("Rotation z") rotation_z; 
				int16_t nicename("Rotation w") rotation_w; 
				float nicename("Default Translation x") default_translation_x; 
				float nicename("Default Translation y") default_translation_y; 
				float nicename("Default Translation z") default_translation_z; 
				float nicename("Default Scale") default_scale; 
			};

			struct nicename("leg_anchoring") s_leg_anchoring_block_definition
			{
				struct s_unknown_block_definition;

				int16_t nicename("Leg Index") leg_index; 
				int16_t __unknown; 
				s_tag_block_definition<s_unknown_block_definition> __unknown2_block; 

				struct s_unknown_block_definition
				{
					int16_t nicename("Frame 1a") frame_1a; 
					int16_t nicename("Frame 2a") frame_2a; 
					int16_t nicename("Frame 1b") frame_1b; 
					int16_t nicename("Frame 2b") frame_2b; 
					Undefined32 __unknown; 
					Undefined32 __unknown2; 
					Undefined32 __unknown3; 
				};
			};

			struct s_unknown_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
			};

			struct s_unknown2_block_definition
			{
				int16_t __unknown; 
				int16_t __unknown2; 
			};

			struct nicename("new_mode_ik") s_new_mode_ik_block_definition
			{
				string_id nicename("Marker") marker; 
				int16_t __unknown; 
				int16_t nicename("Bone A") bone_a; 
				int16_t nicename("Bone B") bone_b; 
				int16_t __unknown2; 
				string_id nicename("Attach To Marker") attach_to_marker; 
				int32_t __unknown3; 
				int8_t __unknown4; 
				int8_t __unknown5; 
				int8_t __unknown6; 
				int8_t __unknown7; 
				int8_t __unknown8; 
				int8_t __unknown9; 
				int8_t __unknown10; 
				int8_t __unknown11; 
			};

			struct s_unknown3_block_definition
			{
				string_id __unknown; 
				int8_t __unknown2; 
				int8_t __unknown3; 
				int8_t __unknown4; 
				int8_t __unknown5; 
				int16_t __unknown6; 
				int16_t __unknown7; 
				int8_t __unknown8; 
				int8_t __unknown9; 
				int8_t __unknown10; 
				int8_t __unknown11; 
				int16_t __unknown12; 
				int8_t __unknown13; 
				int8_t __unknown14; 
			};

			struct s_unknown4_block_definition
			{
				string_id __unknown; 
				int32_t __unknown2; 
				float __unknown3; 
				int16_t __unknown4; 
				int16_t __unknown5; 
			};

			struct s_unknown5_block_definition
			{
				Undefined32 __unknown; 
				Undefined32 __unknown2; 
				Undefined32 __unknown3; 
				DataReference __unknown4_data_reference; 
			};
		};
	};

	struct nicename("animations_2") s_animations_2_block_definition
	{
		string_id nicename("Label") label; 
		int32_t __unknown; 
		Undefined32 __unknown2; 
		float __unknown3; 
		int16_t __unknown4; 
		int16_t __unknown5; 
		int16_t __unknown6; 
		int16_t __unknown7; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		string_id nicename("Function") function; 
		int16_t nicename("Pain Index") pain_index; 
		int16_t __unknown10; 
		int16_t nicename("Graph Index") graph_index; 
		int16_t nicename("Animation") animation; 
	};

	struct nicename("trigger_animation") s_trigger_animation_block_definition
	{
		string_id nicename("Label") label; 
		int32_t __unknown; 
		string_id nicename("Function") function; 
		string_id nicename("Function") function2; 
		string_id nicename("Function") function3; 
		int16_t nicename("Graph Index") graph_index; 
		int16_t nicename("Animation") animation; 
	};

	struct nicename("animation_group") s_animation_group_block_definition
	{
		struct nicename("Animations 2") s_animations_2_block_definition;
		struct nicename("Trigger Animations") s_trigger_animation_block_definition;

		string_id nicename("Name") name; 
		s_tag_block_definition<s_animations_2_block_definition> nicename("Animations 2") animations_2_block; 
		s_tag_block_definition<s_trigger_animation_block_definition> nicename("Trigger Animations") trigger_animations_block; 

		struct nicename("animations_2") s_animations_2_block_definition
		{
			int16_t nicename("Animations 2 Index") animations_2_index; 
			int16_t __unknown; 
			int16_t __unknown2; 
			int16_t __unknown3; 
		};

		struct nicename("trigger_animation") s_trigger_animation_block_definition
		{
			int16_t nicename("Trigger Animation Index") trigger_animation_index; 
			int16_t __unknown; 
		};
	};

	struct nicename("locomotion") s_locomotion_block_definition
	{
		string_id nicename("Full Name") full_name; 
		string_id nicename("Low Speed") low_speed; 
		string_id nicename("Mid Speed") mid_speed; 
		string_id nicename("High Speed") high_speed; 
		int16_t __unknown; 
		int16_t __unknown2; 
	};

	struct nicename("movement_group") s_movement_group_block_definition
	{
		struct nicename("Locomotion") s_locomotion_block_definition;

		string_id nicename("Name") name; 
		s_tag_block_definition<s_locomotion_block_definition> nicename("Locomotion") locomotion_block; 

		struct nicename("locomotion") s_locomotion_block_definition
		{
			int16_t nicename("Locomotion Index") locomotion_index; 
			int16_t __unknown; 
		};
	};

	struct nicename("limb_ik") s_limb_ik_block_definition
	{
		string_id nicename("Name") name; 
		string_id nicename("Marker") marker; 
		int32_t __unknown; 
		string_id nicename("Marker") marker2; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
	};

	struct nicename("limb_ik_group") s_limb_ik_group_block_definition
	{
		struct nicename("Limb ik") s_limb_ik_block_definition;

		string_id nicename("Name") name; 
		s_tag_block_definition<s_limb_ik_block_definition> nicename("Limb ik") limb_ik_block; 

		struct nicename("limb_ik") s_limb_ik_block_definition
		{
			int16_t nicename("Limb ik Index") limb_ik_index; 
			int16_t __unknown; 
		};
	};

	struct nicename("limb_positioning") s_limb_positioning_block_definition
	{
		string_id nicename("Limb") limb; 
		Undefined32 __unknown; 
		int16_t nicename("Bone A") bone_a; 
		int16_t nicename("Bone B") bone_b; 
		int16_t __unknown2; 
		int16_t __unknown3; 
	};

	struct nicename("mode") s_mode_block_definition
	{
		struct nicename("Weapon Class") s_weapon_class_block_definition;
		struct nicename("Mode ik") s_mode_ik_block_definition;

		string_id nicename("Label") label; 
		int16_t nicename("Animation Group") animation_group; 
		int16_t nicename("Limb ik Group") limb_ik_group; 
		int32_t __unknown; 
		s_tag_block_definition<s_weapon_class_block_definition> nicename("Weapon Class") weapon_class_block; 
		s_tag_block_definition<s_mode_ik_block_definition> nicename("Mode ik") mode_ik_block; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 

		struct nicename("weapon_class") s_weapon_class_block_definition
		{
			struct nicename("Weapon Type") s_weapon_type_block_definition;
			struct nicename("Weapon ik") s_weapon_ik_block_definition;
			struct nicename("Ranged Actions") s_ranged_action_block_definition;
			struct nicename("Sync Actions") s_sync_action_block_definition;

			string_id nicename("Label") label; 
			int16_t nicename("Animation Group") animation_group; 
			int16_t nicename("Limb ik Group") limb_ik_group; 
			s_tag_block_definition<s_weapon_type_block_definition> nicename("Weapon Type") weapon_type_block; 
			s_tag_block_definition<s_weapon_ik_block_definition> nicename("Weapon ik") weapon_ik_block; 
			s_tag_block_definition<s_ranged_action_block_definition> nicename("Ranged Actions") ranged_actions_block; 
			s_tag_block_definition<s_sync_action_block_definition> nicename("Sync Actions") sync_actions_block; 

			struct nicename("weapon_type") s_weapon_type_block_definition
			{
				struct nicename("Action Type") s_action_type_block_definition;

				string_id nicename("Label") label; 
				int16_t nicename("Animation Group") animation_group; 
				int16_t nicename("Limb ik Group") limb_ik_group; 
				s_tag_block_definition<s_action_type_block_definition> nicename("Action Type") action_type_block; 

				struct nicename("action_type") s_action_type_block_definition
				{
					struct nicename("Actions") s_action_block_definition;
					struct nicename("Overlays") s_overlay_block_definition;
					struct nicename("Death And Damage") s_death_and_damage_block_definition;
					struct nicename("Transitions") s_transition_block_definition;
					struct s_unknown_block_definition;

					string_id nicename("Label") label; 
					int16_t nicename("Animation Group") animation_group; 
					int16_t nicename("Limb ik Group") limb_ik_group; 
					int16_t nicename("Movement Group") movement_group; 
					int16_t __unknown; 
					s_tag_block_definition<s_action_block_definition> nicename("Actions") actions_block; 
					s_tag_block_definition<s_overlay_block_definition> nicename("Overlays") overlays_block; 
					s_tag_block_definition<s_death_and_damage_block_definition> nicename("Death And Damage") death_and_damage_block; 
					s_tag_block_definition<s_transition_block_definition> nicename("Transitions") transitions_block; 
					s_tag_block_definition<s_unknown_block_definition> __unknown2_block; 

					struct nicename("action") s_action_block_definition
					{
						string_id nicename("Label") label; 
						int16_t nicename("Animation Group") animation_group; 
						int16_t nicename("Limb ik Group") limb_ik_group; 
						int16_t nicename("Graph Index") graph_index; 
						int16_t nicename("Animation") animation; 
					};

					struct nicename("overlay") s_overlay_block_definition
					{
						string_id nicename("Label") label; 
						int16_t nicename("Animation Group") animation_group; 
						int16_t nicename("Limb ik Group") limb_ik_group; 
						int16_t nicename("Graph Index") graph_index; 
						int16_t nicename("Animation") animation; 
					};

					struct nicename("death_and_damage") s_death_and_damage_block_definition
					{
						struct nicename("Directions") s_direction_block_definition;

						string_id nicename("Label") label; 
						s_tag_block_definition<s_direction_block_definition> nicename("Directions") directions_block; 

						struct nicename("direction") s_direction_block_definition
						{
							struct nicename("Regions") s_region_block_definition;

							s_tag_block_definition<s_region_block_definition> nicename("Regions") regions_block; 

							struct nicename("region") s_region_block_definition
							{
								int16_t nicename("Graph Index") graph_index; 
								int16_t nicename("Animation") animation; 
							};
						};
					};

					struct nicename("transition") s_transition_block_definition
					{
						struct nicename("Destinations") s_destination_block_definition;

						string_id nicename("State Name") state_name; 
						s_tag_block_definition<s_destination_block_definition> nicename("Destinations") destinations_block; 

						struct nicename("destination") s_destination_block_definition
						{
							string_id nicename("Mode Name") mode_name; 
							string_id nicename("State Name") state_name; 
							int16_t nicename("Graph Index") graph_index; 
							int16_t nicename("Animation") animation; 
						};
					};

					struct s_unknown_block_definition
					{
						float __unknown; 
						float __unknown2; 
						float __unknown3; 
						float __unknown4; 
						float __unknown5; 
						float __unknown6; 
						float __unknown7; 
						float __unknown8; 
					};
				};
			};

			struct nicename("weapon_ik") s_weapon_ik_block_definition
			{
				string_id nicename("Marker") marker; 
				string_id nicename("Attach To Marker") attach_to_marker; 
			};

			struct nicename("ranged_action") s_ranged_action_block_definition
			{
				struct s_unknown_block_definition;
				struct s_unknown2_block_definition;

				string_id nicename("Label") label; 
				s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
				s_tag_block_definition<s_unknown2_block_definition> __unknown2_block; 
				int16_t __unknown3; 
				int16_t __unknown4; 
				int16_t __unknown5; 
				int16_t __unknown6; 

				struct s_unknown_block_definition
				{
					int32_t __unknown; 
					int16_t nicename("Graph Index") graph_index; 
					int16_t nicename("Animation") animation; 
					float __unknown2; 
					Undefined32 __unknown3; 
				};

				struct s_unknown2_block_definition
				{
					struct s_unknown_block_definition;
					struct s_unknown2_2_block_definition;

					s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
					s_tag_block_definition<s_unknown2_2_block_definition> __unknown2_block; 

					struct s_unknown_block_definition
					{
						float __unknown; 
						float __unknown2; 
					};

					struct s_unknown2_2_block_definition
					{
						int8_t __unknown; 
						int8_t __unknown2; 
						int8_t __unknown3; 
						int8_t __unknown4; 
						int8_t __unknown5; 
						int8_t __unknown6; 
						int8_t __unknown7; 
						int8_t __unknown8; 
					};
				};
			};

			struct nicename("sync_action") s_sync_action_block_definition
			{
				struct nicename("Class") s_$class_block_definition;

				string_id nicename("Label") label; 
				s_tag_block_definition<s_$class_block_definition> nicename("Class") class_block; 

				struct nicename("$class") s_$class_block_definition
				{
					struct s_unknown_block_definition;
					struct nicename("Sync Biped") s_sync_biped_block_definition;

					string_id nicename("Label") label; 
					s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
					s_tag_block_definition<s_sync_biped_block_definition> nicename("Sync Biped") sync_biped_block; 

					struct s_unknown_block_definition
					{
						int32_t __unknown; 
						int16_t nicename("Graph Index") graph_index; 
						int16_t nicename("Animation") animation; 
						Undefined32 __unknown2; 
						Undefined32 __unknown3; 
						Undefined32 __unknown4; 
						Undefined32 __unknown5; 
						Undefined32 __unknown6; 
						Undefined32 __unknown7; 
						Undefined32 __unknown8; 
						Undefined32 __unknown9; 
						Undefined32 __unknown10; 
						Undefined32 __unknown11; 
					};

					struct nicename("sync_biped") s_sync_biped_block_definition
					{
						int32_t __unknown; 
						TagReference nicename("Biped") biped_reference; 
					};
				};
			};
		};

		struct nicename("mode_ik") s_mode_ik_block_definition
		{
			string_id nicename("Marker") marker; 
			string_id nicename("Attach To Marker") attach_to_marker; 
		};
	};

	struct nicename("vehicle_suspension") s_vehicle_suspension_block_definition
	{
		string_id nicename("Label") label; 
		int16_t nicename("Graph Index") graph_index; 
		int16_t nicename("Animation") animation; 
		string_id nicename("Function") function; 
		string_id nicename("Marker Name") marker_name; 
		string_id __unknown_marker_name; 
		float nicename("Mass Point Offset") mass_point_offset; 
		float nicename("Full Extension Ground Depth") full_extension_ground_depth; 
		float nicename("Full Compression Ground Depth") full_compression_ground_depth; 
		// comment
		string_id nicename("Region Name") region_name; 
		float nicename("Mass Point Offset") mass_point_offset2; 
		float nicename("Full Extension Ground Depth") full_extension_ground_depth2; 
		float nicename("Full Compression Ground Depth") full_compression_ground_depth2; 
	};

	struct nicename("object_overlay") s_object_overlay_block_definition
	{
		string_id nicename("Label") label; 
		int16_t nicename("Graph Index") graph_index; 
		int16_t nicename("Animation") animation; 
		int16_t __unknown; 
		int16_t nicename("Function Controls") function_controls; 
		string_id nicename("Function") function; 
		Undefined32 __unknown2; 
	};

	struct nicename("inheritance_list") s_inheritance_list_block_definition
	{
		struct nicename("Node Map") s_node_map_block_definition;
		struct nicename("Node Map Flags") s_node_map_flag_block_definition;

		TagReference nicename("Inherited Graph") inherited_graph_reference; 
		s_tag_block_definition<s_node_map_block_definition> nicename("Node Map") node_map_block; 
		s_tag_block_definition<s_node_map_flag_block_definition> nicename("Node Map Flags") node_map_flags_block; 
		Undefined32 __unknown; 

		struct nicename("node_map") s_node_map_block_definition
		{
			int16_t nicename("Local Node") local_node; 
		};

		struct nicename("node_map_flag") s_node_map_flag_block_definition
		{
			int32_t nicename("Local Node Flags") local_node_flags; 
		};
	};

	struct nicename("new_inheritance_list") s_new_inheritance_list_block_definition
	{
		struct nicename("Node Map") s_node_map_block_definition;
		struct nicename("Node Map Flags") s_node_map_flag_block_definition;

		TagReference nicename("Inherited Graph") inherited_graph_reference; 
		s_tag_block_definition<s_node_map_block_definition> nicename("Node Map") node_map_block; 
		s_tag_block_definition<s_node_map_flag_block_definition> nicename("Node Map Flags") node_map_flags_block; 
		Undefined32 __unknown; 

		struct nicename("node_map") s_node_map_block_definition
		{
			int16_t nicename("Local Node") local_node; 
		};

		struct nicename("node_map_flag") s_node_map_flag_block_definition
		{
			int32_t nicename("Local Node Flags") local_node_flags; 
		};
	};

	struct nicename("weapon_list") s_weapon_list_block_definition
	{
		string_id nicename("Weapon Name") weapon_name; 
		string_id nicename("Weapon Class") weapon_class; 
	};

	struct nicename("raw_information_group") s_raw_information_group_block_definition
	{
		int32_t nicename("Member Count") member_count; 
		int32_t nicename("[zone] Asset Datum") zone_asset_datum; 
		uint16_t nicename("[easy read] Index") easy_read_index; 
		uint16_t nicename("[easy read] Salt") easy_read_salt; 
		int32_t nicename("Useless Padding") useless_padding; 
	};
};
