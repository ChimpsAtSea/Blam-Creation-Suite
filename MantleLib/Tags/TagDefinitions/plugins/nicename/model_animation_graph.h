#pragma once

nicename("model_animation_graph") struct s_model_animation_graph_definition
{
	nicename("Unknown") struct s_unknown3_block_definition;
	nicename("Aim Blending") struct s_aim_blending_block_definition;
	nicename("Pain") struct s_pain_block_definition;
	nicename("Variant Mode Substitution") struct s_variant_mode_substitution_block_definition;
	nicename("Skeleton Nodes") struct s_skeleton_node_block_definition;
	nicename("Sound References") struct s_sound_reference_block_definition;
	nicename("Effect References") struct s_effect_reference_block_definition;
	nicename("Blend Screens") struct s_blend_screen_block_definition;
	nicename("Legs") struct s_leg_block_definition;
	nicename("Animations") struct s_animation_block_definition;
	nicename("Animations 2") struct s_animations_2_block_definition;
	nicename("Trigger Animations") struct s_trigger_animation_block_definition;
	nicename("Animation Groups") struct s_animation_group_block_definition;
	nicename("Locomotion") struct s_locomotion_block_definition;
	nicename("Movement Groups") struct s_movement_group_block_definition;
	nicename("Limb ik") struct s_limb_ik_block_definition;
	nicename("Limb ik Groups") struct s_limb_ik_group_block_definition;
	nicename("Limb Positioning") struct s_limb_positioning_block_definition;
	nicename("Modes") struct s_mode_block_definition;
	nicename("Vehicle Suspension") struct s_vehicle_suspension_block_definition;
	nicename("Object Overlays") struct s_object_overlay_block_definition;
	nicename("Inheritance List") struct s_inheritance_list_block_definition;
	nicename("New Inheritance List") struct s_new_inheritance_list_block_definition;
	nicename("Weapon List") struct s_weapon_list_block_definition;
	nicename("Raw Information Groups") struct s_raw_information_group_block_definition;

	nicename("Parent Animation Graph") TagReference parent_animation_graph;
	nicename("Inheritance Flags") unsigned char inheritance_flags;
	nicename("Private Flags") unsigned char private_flags;
	nicename("Animation Codec Pack") signed short animation_codec_pack;
	nicename("Unknown") signed short unknown;
	nicename("Unknown") signed short unknown2;
	nicename("Unknown") s_tag_block_definition<s_unknown3_block_definition> unknown4;
	nicename("Aim Blending") s_tag_block_definition<s_aim_blending_block_definition> aim_blending2;
	nicename("Pain") s_tag_block_definition<s_pain_block_definition> pain2;
	nicename("Variant Mode Substitution") s_tag_block_definition<s_variant_mode_substitution_block_definition> variant_mode_substitution2;
	nicename("Skeleton Nodes") s_tag_block_definition<s_skeleton_node_block_definition> skeleton_nodes;
	nicename("Sound References") s_tag_block_definition<s_sound_reference_block_definition> sound_references;
	nicename("Effect References") s_tag_block_definition<s_effect_reference_block_definition> effect_references;
	nicename("Blend Screens") s_tag_block_definition<s_blend_screen_block_definition> blend_screens;
	nicename("Legs") s_tag_block_definition<s_leg_block_definition> legs;
	nicename("Frame Events") TagReference frame_events;
	nicename("Animations") s_tag_block_definition<s_animation_block_definition> animations;
	nicename("Animations 2") s_tag_block_definition<s_animations_2_block_definition> animations_2_2;
	nicename("Trigger Animations") s_tag_block_definition<s_trigger_animation_block_definition> trigger_animations;
	nicename("Animation Groups") s_tag_block_definition<s_animation_group_block_definition> animation_groups;
	nicename("Locomotion") s_tag_block_definition<s_locomotion_block_definition> locomotion2;
	nicename("Movement Groups") s_tag_block_definition<s_movement_group_block_definition> movement_groups;
	nicename("Limb ik") s_tag_block_definition<s_limb_ik_block_definition> limb_ik2;
	nicename("Limb ik Groups") s_tag_block_definition<s_limb_ik_group_block_definition> limb_ik_groups;
	nicename("Limb Positioning") s_tag_block_definition<s_limb_positioning_block_definition> limb_positioning2;
	nicename("Unknown") signed short unknown5;
	nicename("Unknown") signed short unknown6;
	nicename("Modes") s_tag_block_definition<s_mode_block_definition> modes;
	nicename("Vehicle Suspension") s_tag_block_definition<s_vehicle_suspension_block_definition> vehicle_suspension2;
	nicename("Object Overlays") s_tag_block_definition<s_object_overlay_block_definition> object_overlays;
	nicename("Inheritance List") s_tag_block_definition<s_inheritance_list_block_definition> inheritance_list2;
	nicename("New Inheritance List") s_tag_block_definition<s_new_inheritance_list_block_definition> new_inheritance_list2;
	nicename("Weapon List") s_tag_block_definition<s_weapon_list_block_definition> weapon_list2;
	nicename("Unknown Arm Nodes 1") signed int unknown_arm_nodes_1;
	nicename("Unknown Arm Nodes 2") signed int unknown_arm_nodes_2;
	nicename("Unknown Arm Nodes 3") signed int unknown_arm_nodes_3;
	nicename("Unknown Arm Nodes 4") signed int unknown_arm_nodes_4;
	nicename("Unknown Arm Nodes 5") signed int unknown_arm_nodes_5;
	nicename("Unknown Arm Nodes 6") signed int unknown_arm_nodes_6;
	nicename("Unknown Arm Nodes 7") signed int unknown_arm_nodes_7;
	nicename("Unknown Arm Nodes 8") signed int unknown_arm_nodes_8;
	nicename("Unknown Nodes 1") signed int unknown_nodes_1;
	nicename("Unknown Nodes 2") signed int unknown_nodes_2;
	nicename("Unknown Nodes 3") signed int unknown_nodes_3;
	nicename("Unknown Nodes 4") signed int unknown_nodes_4;
	nicename("Unknown Nodes 5") signed int unknown_nodes_5;
	nicename("Unknown Nodes 6") signed int unknown_nodes_6;
	nicename("Unknown Nodes 7") signed int unknown_nodes_7;
	nicename("Unknown Nodes 8") signed int unknown_nodes_8;
	nicename("Last Import Results") DataReference last_import_results;
	nicename("Unknown") unsigned int unknown7;
	nicename("Unknown") unsigned int unknown8;
	nicename("Unknown") unsigned int unknown9;
	nicename("Raw Information Groups") s_tag_block_definition<s_raw_information_group_block_definition> raw_information_groups;

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") signed short unknown2;
		nicename("Unknown") signed short unknown3;
	};

	nicename("Aim Blending") struct s_aim_blending_definition
	{
		nicename("Bones") struct s_bone_block_definition;

		nicename("Name") string_id name;
		nicename("Bones") s_tag_block_definition<s_bone_block_definition> bones;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("Unknown") signed char unknown4;
		nicename("Unknown") signed char unknown5;
		nicename("Unknown") signed char unknown6;
		nicename("Unknown") signed char unknown7;
		nicename("Unknown") signed char unknown8;
		nicename("Unknown") signed char unknown9;
		nicename("Unknown") signed char unknown10;
		nicename("Unknown") signed char unknown11;
		nicename("Unknown") signed char unknown12;
		nicename("Unknown") signed char unknown13;
		nicename("Unknown") signed char unknown14;
		nicename("Unknown") signed char unknown15;
		nicename("Unknown") signed char unknown16;
		nicename("Unknown") signed char unknown17;
		nicename("Unknown") signed char unknown18;
		nicename("Unknown") signed char unknown19;
		nicename("Unknown") signed char unknown20;
		nicename("Unknown") signed char unknown21;
		nicename("Unknown") signed char unknown22;
		nicename("Unknown") signed char unknown23;
		nicename("Unknown") signed char unknown24;
		nicename("Unknown") signed char unknown25;
		nicename("Unknown") signed char unknown26;
		nicename("Unknown") signed char unknown27;
		nicename("Unknown") signed char unknown28;
		nicename("Unknown") signed char unknown29;
		nicename("Unknown") signed char unknown30;
		nicename("Unknown") signed char unknown31;
		nicename("Unknown") signed char unknown32;

		nicename("Bone") struct s_bone_definition
		{
			nicename("Bone") signed short bone2;
			nicename("Unknown") signed short unknown;
		};
	};

	nicename("Pain") struct s_pain_definition
	{
		nicename("Name") string_id name;
		nicename("Function") DataReference function;
	};

	nicename("Variant Mode Substitution") struct s_variant_mode_substitution_definition
	{
		nicename("Modes") struct s_mode_block_definition;

		nicename("Variant Name") string_id variant_name;
		nicename("Unknown") signed int unknown;
		nicename("Modes") s_tag_block_definition<s_mode_block_definition> modes;

		nicename("Mode") struct s_mode_definition
		{
			nicename("Original Mode") string_id original_mode;
			nicename("New Mode") string_id new_mode;
		};
	};

	nicename("Skeleton Node") struct s_skeleton_node_definition
	{
		nicename("Name") string_id name;
		nicename("Next Sibling Node Index") signed short next_sibling_node_index;
		nicename("First Child Node Index") signed short first_child_node_index;
		nicename("Parent Node Index") signed short parent_node_index;
		nicename("Model Flags") unsigned char model_flags;
		nicename("Node Joint Flags") unsigned char node_joint_flags;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed short unknown3;
		nicename("Base Vector i") float base_vector_i;
		nicename("Base Vector j") float base_vector_j;
		nicename("Base Vector k") float base_vector_k;
		nicename("Vector Range") float vector_range;
		nicename("z Position") float z_position;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
	};

	nicename("Sound Reference") struct s_sound_reference_definition
	{
		nicename("Sound") TagReference sound;
		nicename("Flags") unsigned short flags;
		nicename("Unknown") signed short unknown;
	};

	nicename("Effect Reference") struct s_effect_reference_definition
	{
		nicename("Effect") TagReference effect;
		nicename("Flags") unsigned short flags;
		nicename("Unknown") signed short unknown;
	};

	nicename("Blend Screen") struct s_blend_screen_definition
	{
		nicename("Label") string_id label;
		nicename("Right Yaw Per Frame") float right_yaw_per_frame;
		nicename("Left Yaw Per Frame") float left_yaw_per_frame;
		nicename("Right Frame Count") signed short right_frame_count;
		nicename("Left Frame Count") signed short left_frame_count;
		nicename("Down Pitch Per Frame") float down_pitch_per_frame;
		nicename("Up Pitch Per Frame") float up_pitch_per_frame;
		nicename("Down Pitch Frame Count") signed short down_pitch_frame_count;
		nicename("Up Pitch Frame Count") signed short up_pitch_frame_count;
	};

	nicename("Leg") struct s_leg_definition
	{
		nicename("Foot Marker") string_id foot_marker;
		nicename("Foot min") float foot_min;
		nicename("Foot max") float foot_max;
		nicename("Ankle Marker") string_id ankle_marker;
		nicename("Ankle min") float ankle_min;
		nicename("Ankle max") float ankle_max;
		nicename("Anchors") signed short anchors;
		nicename("Unknown") signed short unknown;
	};

	nicename("Animation") struct s_animation_definition
	{
		nicename("Animation Definition") struct s_animation_definition_block_definition;

		nicename("Name") string_id name;
		nicename("Weight") float weight;
		nicename("Loop Frame Index") signed short loop_frame_index;
		nicename("Playback Flags") unsigned short playback_flags;
		nicename("Unknown") float unknown;
		nicename("Unknown") float unknown2;
		nicename("Previous Variant Sibling") signed short previous_variant_sibling;
		nicename("Next Variant Sibling") signed short next_variant_sibling;
		nicename("Production Flags") unsigned short production_flags;
		nicename("Blend Screen") signed char blend_screen;
		nicename("Unknown") signed char unknown3;
		nicename("Parent") TagReference parent;
		nicename("Parent Index") signed short parent_index;
		nicename("Unknown") signed short unknown4;
		nicename("Animation Definition") s_tag_block_definition<s_animation_definition_block_definition> animation_definition2;

		nicename("Animation Definition") struct s_animation_definition_definition
		{
			nicename("Frame Events") struct s_frame_event_block_definition;
			nicename("Sound Events") struct s_sound_event_block_definition;
			nicename("Effect Events") struct s_effect_event_block_definition;
			nicename("Unknown 14") struct s_unknown_14_block_definition;
			nicename("Object-Space Parent Nodes") struct s_object_space_parent_node_block_definition;
			nicename("Leg Anchoring") struct s_leg_anchoring_block_definition;
			nicename("Unknown") struct s_unknown17_block_definition;
			nicename("Unknown") struct s_unknown19_block_definition;
			nicename("New Mode ik") struct s_new_mode_ik_block_definition;
			nicename("Unknown") struct s_unknown24_block_definition;
			nicename("Unknown") struct s_unknown26_block_definition;
			nicename("Unknown") struct s_unknown28_block_definition;

			nicename("Node Count") signed char node_count;
			nicename("Unknown") signed char unknown;
			nicename("Frame Count") signed short frame_count;
			nicename("Unknown") signed char unknown2;
			nicename("Unknown") signed char unknown3;
			nicename("Unknown") signed char unknown4;
			nicename("Unknown") signed char unknown5;
			nicename("Unknown") signed short unknown6;
			nicename("Unknown") signed char unknown7;
			nicename("Unknown") signed char unknown8;
			nicename("Production Checksum") signed int production_checksum;
			nicename("Import Path") string_id import_path;
			nicename("Node List Checksum") signed int node_list_checksum;
			nicename("Unknown") signed int unknown9;
			nicename("Unknown") signed short unknown10;
			nicename("Unknown") signed short unknown11;
			nicename("Raw Information Group Index") signed short raw_information_group_index;
			nicename("Raw Information Member Index") signed short raw_information_member_index;
			nicename("Unknown") float unknown12;
			nicename("Unknown") float unknown13;
			nicename("Unknown") float unknown14;
			nicename("Unknown") float unknown15;
			nicename("Unknown") float unknown16;
			nicename("Frame Events") s_tag_block_definition<s_frame_event_block_definition> frame_events;
			nicename("Sound Events") s_tag_block_definition<s_sound_event_block_definition> sound_events;
			nicename("Effect Events") s_tag_block_definition<s_effect_event_block_definition> effect_events;
			nicename("Unknown 14") s_tag_block_definition<s_unknown_14_block_definition> unknown_14_2;
			nicename("Object-Space Parent Nodes") s_tag_block_definition<s_object_space_parent_node_block_definition> object_space_parent_nodes;
			nicename("Leg Anchoring") s_tag_block_definition<s_leg_anchoring_block_definition> leg_anchoring2;
			nicename("Unknown") s_tag_block_definition<s_unknown17_block_definition> unknown18;
			nicename("Unknown") s_tag_block_definition<s_unknown19_block_definition> unknown20;
			nicename("New Mode ik") s_tag_block_definition<s_new_mode_ik_block_definition> new_mode_ik2;
			nicename("Unknown") unsigned int unknown21;
			nicename("Unknown") unsigned int unknown22;
			nicename("Unknown") unsigned int unknown23;
			nicename("Unknown") s_tag_block_definition<s_unknown24_block_definition> unknown25;
			nicename("Unknown") s_tag_block_definition<s_unknown26_block_definition> unknown27;
			nicename("Unknown") s_tag_block_definition<s_unknown28_block_definition> unknown29;

			nicename("Frame Event") struct s_frame_event_definition
			{
				nicename("Type") signed short type;
				nicename("Frame") signed short frame;
			};

			nicename("Sound Event") struct s_sound_event_definition
			{
				nicename("Sound") signed short sound;
				nicename("Frame") signed short frame;
				nicename("Marker Name") string_id marker_name;
			};

			nicename("Effect Event") struct s_effect_event_definition
			{
				nicename("Effect") signed short effect;
				nicename("Frame") signed short frame;
				nicename("Marker Name") string_id marker_name;
				nicename("Damage Reporting Type") signed char damage_reporting_type;
				nicename("Unknown") signed char unknown;
				nicename("Unknown") signed char unknown2;
				nicename("Unknown") signed char unknown3;
			};

			nicename("Unknown 14") struct s_unknown_14_definition
			{
				nicename("Unknown") signed short unknown;
				nicename("Unknown") signed short unknown2;
			};

			nicename("Object-Space Parent Node") struct s_object_space_parent_node_definition
			{
				nicename("Node Index") signed short node_index;
				nicename("Component Flags") unsigned short component_flags;
				nicename("Rotation x") signed short rotation_x;
				nicename("Rotation y") signed short rotation_y;
				nicename("Rotation z") signed short rotation_z;
				nicename("Rotation w") signed short rotation_w;
				nicename("Default Translation x") float default_translation_x;
				nicename("Default Translation y") float default_translation_y;
				nicename("Default Translation z") float default_translation_z;
				nicename("Default Scale") float default_scale;
			};

			nicename("Leg Anchoring") struct s_leg_anchoring_definition
			{
				nicename("Unknown") struct s_unknown2_block_definition;

				nicename("Leg Index") signed short leg_index;
				nicename("Unknown") signed short unknown;
				nicename("Unknown") s_tag_block_definition<s_unknown2_block_definition> unknown3;

				nicename("Unknown") struct s_unknown_definition
				{
					nicename("Frame 1a") signed short frame_1a;
					nicename("Frame 2a") signed short frame_2a;
					nicename("Frame 1b") signed short frame_1b;
					nicename("Frame 2b") signed short frame_2b;
					nicename("Unknown") unsigned int unknown2;
					nicename("Unknown") unsigned int unknown3;
					nicename("Unknown") unsigned int unknown4;
				};
			};

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") signed short unknown2;
				nicename("Unknown") signed short unknown3;
			};

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") signed short unknown2;
				nicename("Unknown") signed short unknown3;
			};

			nicename("New Mode ik") struct s_new_mode_ik_definition
			{
				nicename("Marker") string_id marker;
				nicename("Unknown") signed short unknown;
				nicename("Bone A") signed short bone_a;
				nicename("Bone B") signed short bone_b;
				nicename("Unknown") signed short unknown2;
				nicename("Attach To Marker") string_id attach_to_marker;
				nicename("Unknown") signed int unknown3;
				nicename("Unknown") signed char unknown4;
				nicename("Unknown") signed char unknown5;
				nicename("Unknown") signed char unknown6;
				nicename("Unknown") signed char unknown7;
				nicename("Unknown") signed char unknown8;
				nicename("Unknown") signed char unknown9;
				nicename("Unknown") signed char unknown10;
				nicename("Unknown") signed char unknown11;
			};

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") string_id unknown2;
				nicename("Unknown") signed char unknown3;
				nicename("Unknown") signed char unknown4;
				nicename("Unknown") signed char unknown5;
				nicename("Unknown") signed char unknown6;
				nicename("Unknown") signed short unknown7;
				nicename("Unknown") signed short unknown8;
				nicename("Unknown") signed char unknown9;
				nicename("Unknown") signed char unknown10;
				nicename("Unknown") signed char unknown11;
				nicename("Unknown") signed char unknown12;
				nicename("Unknown") signed short unknown13;
				nicename("Unknown") signed char unknown14;
				nicename("Unknown") signed char unknown15;
			};

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") string_id unknown2;
				nicename("Unknown") signed int unknown3;
				nicename("Unknown") float unknown4;
				nicename("Unknown") signed short unknown5;
				nicename("Unknown") signed short unknown6;
			};

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") unsigned int unknown2;
				nicename("Unknown") unsigned int unknown3;
				nicename("Unknown") unsigned int unknown4;
				nicename("Unknown") DataReference unknown5;
			};
		};
	};

	nicename("Animations 2") struct s_animations_2_definition
	{
		nicename("Label") string_id label;
		nicename("Unknown") signed int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") signed short unknown4;
		nicename("Unknown") signed short unknown5;
		nicename("Unknown") signed short unknown6;
		nicename("Unknown") signed short unknown7;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Function") string_id function;
		nicename("Pain Index") signed short pain_index;
		nicename("Unknown") signed short unknown10;
		nicename("Graph Index") signed short graph_index;
		nicename("Animation") signed short animation;
	};

	nicename("Trigger Animation") struct s_trigger_animation_definition
	{
		nicename("Label") string_id label;
		nicename("Unknown") signed int unknown;
		nicename("Function") string_id function;
		nicename("Function") string_id function2;
		nicename("Function") string_id function3;
		nicename("Graph Index") signed short graph_index;
		nicename("Animation") signed short animation;
	};

	nicename("Animation Group") struct s_animation_group_definition
	{
		nicename("Animations 2") struct s_animations_2_block_definition;
		nicename("Trigger Animations") struct s_trigger_animation_block_definition;

		nicename("Name") string_id name;
		nicename("Animations 2") s_tag_block_definition<s_animations_2_block_definition> animations_2_2;
		nicename("Trigger Animations") s_tag_block_definition<s_trigger_animation_block_definition> trigger_animations;

		nicename("Animations 2") struct s_animations_2_definition
		{
			nicename("Animations 2 Index") signed short animations_2_index;
			nicename("Unknown") signed short unknown;
			nicename("Unknown") signed short unknown2;
			nicename("Unknown") signed short unknown3;
		};

		nicename("Trigger Animation") struct s_trigger_animation_definition
		{
			nicename("Trigger Animation Index") signed short trigger_animation_index;
			nicename("Unknown") signed short unknown;
		};
	};

	nicename("Locomotion") struct s_locomotion_definition
	{
		nicename("Full Name") string_id full_name;
		nicename("Low Speed") string_id low_speed;
		nicename("Mid Speed") string_id mid_speed;
		nicename("High Speed") string_id high_speed;
		nicename("Unknown") signed short unknown;
		nicename("Unknown") signed short unknown2;
	};

	nicename("Movement Group") struct s_movement_group_definition
	{
		nicename("Locomotion") struct s_locomotion_block_definition;

		nicename("Name") string_id name;
		nicename("Locomotion") s_tag_block_definition<s_locomotion_block_definition> locomotion2;

		nicename("Locomotion") struct s_locomotion_definition
		{
			nicename("Locomotion Index") signed short locomotion_index;
			nicename("Unknown") signed short unknown;
		};
	};

	nicename("Limb ik") struct s_limb_ik_definition
	{
		nicename("Name") string_id name;
		nicename("Marker") string_id marker;
		nicename("Unknown") signed int unknown;
		nicename("Marker") string_id marker2;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
	};

	nicename("Limb ik Group") struct s_limb_ik_group_definition
	{
		nicename("Limb ik") struct s_limb_ik_block_definition;

		nicename("Name") string_id name;
		nicename("Limb ik") s_tag_block_definition<s_limb_ik_block_definition> limb_ik2;

		nicename("Limb ik") struct s_limb_ik_definition
		{
			nicename("Limb ik Index") signed short limb_ik_index;
			nicename("Unknown") signed short unknown;
		};
	};

	nicename("Limb Positioning") struct s_limb_positioning_definition
	{
		nicename("Limb") string_id limb;
		nicename("Unknown") unsigned int unknown;
		nicename("Bone A") signed short bone_a;
		nicename("Bone B") signed short bone_b;
		nicename("Unknown") signed short unknown2;
		nicename("Unknown") signed short unknown3;
	};

	nicename("Mode") struct s_mode_definition
	{
		nicename("Weapon Class") struct s_weapon_class_block_definition;
		nicename("Mode ik") struct s_mode_ik_block_definition;

		nicename("Label") string_id label;
		nicename("Animation Group") signed short animation_group;
		nicename("Limb ik Group") signed short limb_ik_group;
		nicename("Unknown") signed int unknown;
		nicename("Weapon Class") s_tag_block_definition<s_weapon_class_block_definition> weapon_class2;
		nicename("Mode ik") s_tag_block_definition<s_mode_ik_block_definition> mode_ik2;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;

		nicename("Weapon Class") struct s_weapon_class_definition
		{
			nicename("Weapon Type") struct s_weapon_type_block_definition;
			nicename("Weapon ik") struct s_weapon_ik_block_definition;
			nicename("Ranged Actions") struct s_ranged_action_block_definition;
			nicename("Sync Actions") struct s_sync_action_block_definition;

			nicename("Label") string_id label;
			nicename("Animation Group") signed short animation_group;
			nicename("Limb ik Group") signed short limb_ik_group;
			nicename("Weapon Type") s_tag_block_definition<s_weapon_type_block_definition> weapon_type2;
			nicename("Weapon ik") s_tag_block_definition<s_weapon_ik_block_definition> weapon_ik2;
			nicename("Ranged Actions") s_tag_block_definition<s_ranged_action_block_definition> ranged_actions;
			nicename("Sync Actions") s_tag_block_definition<s_sync_action_block_definition> sync_actions;

			nicename("Weapon Type") struct s_weapon_type_definition
			{
				nicename("Action Type") struct s_action_type_block_definition;

				nicename("Label") string_id label;
				nicename("Animation Group") signed short animation_group;
				nicename("Limb ik Group") signed short limb_ik_group;
				nicename("Action Type") s_tag_block_definition<s_action_type_block_definition> action_type2;

				nicename("Action Type") struct s_action_type_definition
				{
					nicename("Actions") struct s_action_block_definition;
					nicename("Overlays") struct s_overlay_block_definition;
					nicename("Death And Damage") struct s_death_and_damage_block_definition;
					nicename("Transitions") struct s_transition_block_definition;
					nicename("Unknown") struct s_unknown2_block_definition;

					nicename("Label") string_id label;
					nicename("Animation Group") signed short animation_group;
					nicename("Limb ik Group") signed short limb_ik_group;
					nicename("Movement Group") signed short movement_group;
					nicename("Unknown") signed short unknown;
					nicename("Actions") s_tag_block_definition<s_action_block_definition> actions;
					nicename("Overlays") s_tag_block_definition<s_overlay_block_definition> overlays;
					nicename("Death And Damage") s_tag_block_definition<s_death_and_damage_block_definition> death_and_damage2;
					nicename("Transitions") s_tag_block_definition<s_transition_block_definition> transitions;
					nicename("Unknown") s_tag_block_definition<s_unknown2_block_definition> unknown3;

					nicename("Action") struct s_action_definition
					{
						nicename("Label") string_id label;
						nicename("Animation Group") signed short animation_group;
						nicename("Limb ik Group") signed short limb_ik_group;
						nicename("Graph Index") signed short graph_index;
						nicename("Animation") signed short animation;
					};

					nicename("Overlay") struct s_overlay_definition
					{
						nicename("Label") string_id label;
						nicename("Animation Group") signed short animation_group;
						nicename("Limb ik Group") signed short limb_ik_group;
						nicename("Graph Index") signed short graph_index;
						nicename("Animation") signed short animation;
					};

					nicename("Death And Damage") struct s_death_and_damage_definition
					{
						nicename("Directions") struct s_direction_block_definition;

						nicename("Label") string_id label;
						nicename("Directions") s_tag_block_definition<s_direction_block_definition> directions;

						nicename("Direction") struct s_direction_definition
						{
							nicename("Regions") struct s_region_block_definition;

							nicename("Regions") s_tag_block_definition<s_region_block_definition> regions;

							nicename("Region") struct s_region_definition
							{
								nicename("Graph Index") signed short graph_index;
								nicename("Animation") signed short animation;
							};
						};
					};

					nicename("Transition") struct s_transition_definition
					{
						nicename("Destinations") struct s_destination_block_definition;

						nicename("State Name") string_id state_name;
						nicename("Destinations") s_tag_block_definition<s_destination_block_definition> destinations;

						nicename("Destination") struct s_destination_definition
						{
							nicename("Mode Name") string_id mode_name;
							nicename("State Name") string_id state_name;
							nicename("Graph Index") signed short graph_index;
							nicename("Animation") signed short animation;
						};
					};

					nicename("Unknown") struct s_unknown_definition
					{
						nicename("Unknown") float unknown2;
						nicename("Unknown") float unknown3;
						nicename("Unknown") float unknown4;
						nicename("Unknown") float unknown5;
						nicename("Unknown") float unknown6;
						nicename("Unknown") float unknown7;
						nicename("Unknown") float unknown8;
						nicename("Unknown") float unknown9;
					};
				};
			};

			nicename("Weapon ik") struct s_weapon_ik_definition
			{
				nicename("Marker") string_id marker;
				nicename("Attach To Marker") string_id attach_to_marker;
			};

			nicename("Ranged Action") struct s_ranged_action_definition
			{
				nicename("Unknown") struct s_unknown_block_definition;
				nicename("Unknown") struct s_unknown3_block_definition;

				nicename("Label") string_id label;
				nicename("Unknown") s_tag_block_definition<s_unknown_block_definition> unknown2;
				nicename("Unknown") s_tag_block_definition<s_unknown3_block_definition> unknown4;
				nicename("Unknown") signed short unknown5;
				nicename("Unknown") signed short unknown6;
				nicename("Unknown") signed short unknown7;
				nicename("Unknown") signed short unknown8;

				nicename("Unknown") struct s_unknown_definition
				{
					nicename("Unknown") signed int unknown2;
					nicename("Graph Index") signed short graph_index;
					nicename("Animation") signed short animation;
					nicename("Unknown") float unknown3;
					nicename("Unknown") unsigned int unknown4;
				};

				nicename("Unknown") struct s_unknown_definition
				{
					nicename("Unknown") struct s_unknown2_block_definition;
					nicename("Unknown") struct s_unknown4_block_definition;

					nicename("Unknown") s_tag_block_definition<s_unknown2_block_definition> unknown3;
					nicename("Unknown") s_tag_block_definition<s_unknown4_block_definition> unknown5;

					nicename("Unknown") struct s_unknown_definition
					{
						nicename("Unknown") float unknown2;
						nicename("Unknown") float unknown3;
					};

					nicename("Unknown") struct s_unknown_definition
					{
						nicename("Unknown") signed char unknown2;
						nicename("Unknown") signed char unknown3;
						nicename("Unknown") signed char unknown4;
						nicename("Unknown") signed char unknown5;
						nicename("Unknown") signed char unknown6;
						nicename("Unknown") signed char unknown7;
						nicename("Unknown") signed char unknown8;
						nicename("Unknown") signed char unknown9;
					};
				};
			};

			nicename("Sync Action") struct s_sync_action_definition
			{
				nicename("Class") struct s_class_block_definition;

				nicename("Label") string_id label;
				nicename("Class") s_tag_block_definition<s_class_block_definition> class2;

				nicename("Class") struct s_class_definition
				{
					nicename("Unknown") struct s_unknown_block_definition;
					nicename("Sync Biped") struct s_sync_biped_block_definition;

					nicename("Label") string_id label;
					nicename("Unknown") s_tag_block_definition<s_unknown_block_definition> unknown2;
					nicename("Sync Biped") s_tag_block_definition<s_sync_biped_block_definition> sync_biped2;

					nicename("Unknown") struct s_unknown_definition
					{
						nicename("Unknown") signed int unknown2;
						nicename("Graph Index") signed short graph_index;
						nicename("Animation") signed short animation;
						nicename("Unknown") unsigned int unknown3;
						nicename("Unknown") unsigned int unknown4;
						nicename("Unknown") unsigned int unknown5;
						nicename("Unknown") unsigned int unknown6;
						nicename("Unknown") unsigned int unknown7;
						nicename("Unknown") unsigned int unknown8;
						nicename("Unknown") unsigned int unknown9;
						nicename("Unknown") unsigned int unknown10;
						nicename("Unknown") unsigned int unknown11;
						nicename("Unknown") unsigned int unknown12;
					};

					nicename("Sync Biped") struct s_sync_biped_definition
					{
						nicename("Unknown") signed int unknown;
						nicename("Biped") TagReference biped;
					};
				};
			};
		};

		nicename("Mode ik") struct s_mode_ik_definition
		{
			nicename("Marker") string_id marker;
			nicename("Attach To Marker") string_id attach_to_marker;
		};
	};

	nicename("Vehicle Suspension") struct s_vehicle_suspension_definition
	{
		nicename("Label") string_id label;
		nicename("Graph Index") signed short graph_index;
		nicename("Animation") signed short animation;
		nicename("Function") string_id function;
		nicename("Marker Name") string_id marker_name;
		nicename("Unknown Marker Name") string_id unknown_marker_name;
		nicename("Mass Point Offset") float mass_point_offset;
		nicename("Full Extension Ground Depth") float full_extension_ground_depth;
		nicename("Full Compression Ground Depth") float full_compression_ground_depth;
		nicename("Region Name") string_id region_name;
		nicename("Mass Point Offset") float mass_point_offset2;
		nicename("Full Extension Ground Depth") float full_extension_ground_depth2;
		nicename("Full Compression Ground Depth") float full_compression_ground_depth2;
	};

	nicename("Object Overlay") struct s_object_overlay_definition
	{
		nicename("Label") string_id label;
		nicename("Graph Index") signed short graph_index;
		nicename("Animation") signed short animation;
		nicename("Unknown") signed short unknown;
		nicename("Function Controls") signed short function_controls;
		nicename("Function") string_id function;
		nicename("Unknown") unsigned int unknown2;
	};

	nicename("Inheritance List") struct s_inheritance_list_definition
	{
		nicename("Node Map") struct s_node_map_block_definition;
		nicename("Node Map Flags") struct s_node_map_flag_block_definition;

		nicename("Inherited Graph") TagReference inherited_graph;
		nicename("Node Map") s_tag_block_definition<s_node_map_block_definition> node_map2;
		nicename("Node Map Flags") s_tag_block_definition<s_node_map_flag_block_definition> node_map_flags;
		nicename("Unknown") unsigned int unknown;

		nicename("Node Map") struct s_node_map_definition
		{
			nicename("Local Node") signed short local_node;
		};

		nicename("Node Map Flag") struct s_node_map_flag_definition
		{
			nicename("Local Node Flags") signed int local_node_flags;
		};
	};

	nicename("New Inheritance List") struct s_new_inheritance_list_definition
	{
		nicename("Node Map") struct s_node_map_block_definition;
		nicename("Node Map Flags") struct s_node_map_flag_block_definition;

		nicename("Inherited Graph") TagReference inherited_graph;
		nicename("Node Map") s_tag_block_definition<s_node_map_block_definition> node_map2;
		nicename("Node Map Flags") s_tag_block_definition<s_node_map_flag_block_definition> node_map_flags;
		nicename("Unknown") unsigned int unknown;

		nicename("Node Map") struct s_node_map_definition
		{
			nicename("Local Node") signed short local_node;
		};

		nicename("Node Map Flag") struct s_node_map_flag_definition
		{
			nicename("Local Node Flags") signed int local_node_flags;
		};
	};

	nicename("Weapon List") struct s_weapon_list_definition
	{
		nicename("Weapon Name") string_id weapon_name;
		nicename("Weapon Class") string_id weapon_class;
	};

	nicename("Raw Information Group") struct s_raw_information_group_definition
	{
		nicename("Member Count") signed int member_count;
		nicename("[zone] Asset Datum") unsigned int zone_asset_datum;
		nicename("[easy read] Index") unsigned short easy_read_index;
		nicename("[easy read] Salt") unsigned short easy_read_salt;
		nicename("Useless Padding") signed int useless_padding;
	};
};
