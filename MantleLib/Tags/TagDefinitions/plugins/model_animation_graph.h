#pragma once

struct s_model_animation_graph_definition
{
	struct s_unknown3_block_definition;
	struct s_aim_blending_block_definition;
	struct s_pain_block_definition;
	struct s_variant_mode_substitution_block_definition;
	struct s_skeleton_node_block_definition;
	struct s_sound_reference_block_definition;
	struct s_effect_reference_block_definition;
	struct s_blend_screen_block_definition;
	struct s_leg_block_definition;
	struct s_animation_block_definition;
	struct s_animations_2_block_definition;
	struct s_trigger_animation_block_definition;
	struct s_animation_group_block_definition;
	struct s_locomotion_block_definition;
	struct s_movement_group_block_definition;
	struct s_limb_ik_block_definition;
	struct s_limb_ik_group_block_definition;
	struct s_limb_positioning_block_definition;
	struct s_mode_block_definition;
	struct s_vehicle_suspension_block_definition;
	struct s_object_overlay_block_definition;
	struct s_inheritance_list_block_definition;
	struct s_new_inheritance_list_block_definition;
	struct s_weapon_list_block_definition;
	struct s_raw_information_group_block_definition;

	TagReference parent_animation_graph;
	unsigned char inheritance_flags;
	unsigned char private_flags;
	signed short animation_codec_pack;
	signed short unknown;
	signed short unknown2;
	s_tag_block_definition<s_unknown3_block_definition> unknown4;
	s_tag_block_definition<s_aim_blending_block_definition> aim_blending2;
	s_tag_block_definition<s_pain_block_definition> pain2;
	s_tag_block_definition<s_variant_mode_substitution_block_definition> variant_mode_substitution2;
	s_tag_block_definition<s_skeleton_node_block_definition> skeleton_nodes;
	s_tag_block_definition<s_sound_reference_block_definition> sound_references;
	s_tag_block_definition<s_effect_reference_block_definition> effect_references;
	s_tag_block_definition<s_blend_screen_block_definition> blend_screens;
	s_tag_block_definition<s_leg_block_definition> legs;
	TagReference frame_events;
	s_tag_block_definition<s_animation_block_definition> animations;
	s_tag_block_definition<s_animations_2_block_definition> animations_2_2;
	s_tag_block_definition<s_trigger_animation_block_definition> trigger_animations;
	s_tag_block_definition<s_animation_group_block_definition> animation_groups;
	s_tag_block_definition<s_locomotion_block_definition> locomotion2;
	s_tag_block_definition<s_movement_group_block_definition> movement_groups;
	s_tag_block_definition<s_limb_ik_block_definition> limb_ik2;
	s_tag_block_definition<s_limb_ik_group_block_definition> limb_ik_groups;
	s_tag_block_definition<s_limb_positioning_block_definition> limb_positioning2;
	signed short unknown5;
	signed short unknown6;
	s_tag_block_definition<s_mode_block_definition> modes;
	s_tag_block_definition<s_vehicle_suspension_block_definition> vehicle_suspension2;
	s_tag_block_definition<s_object_overlay_block_definition> object_overlays;
	s_tag_block_definition<s_inheritance_list_block_definition> inheritance_list2;
	s_tag_block_definition<s_new_inheritance_list_block_definition> new_inheritance_list2;
	s_tag_block_definition<s_weapon_list_block_definition> weapon_list2;
	signed int unknown_arm_nodes_1;
	signed int unknown_arm_nodes_2;
	signed int unknown_arm_nodes_3;
	signed int unknown_arm_nodes_4;
	signed int unknown_arm_nodes_5;
	signed int unknown_arm_nodes_6;
	signed int unknown_arm_nodes_7;
	signed int unknown_arm_nodes_8;
	signed int unknown_nodes_1;
	signed int unknown_nodes_2;
	signed int unknown_nodes_3;
	signed int unknown_nodes_4;
	signed int unknown_nodes_5;
	signed int unknown_nodes_6;
	signed int unknown_nodes_7;
	signed int unknown_nodes_8;
	DataReference last_import_results;
	unsigned int unknown7;
	unsigned int unknown8;
	unsigned int unknown9;
	s_tag_block_definition<s_raw_information_group_block_definition> raw_information_groups;

	struct s_unknown_definition
	{
		signed short unknown2;
		signed short unknown3;
	};

	struct s_aim_blending_definition
	{
		struct s_bone_block_definition;

		string_id name;
		s_tag_block_definition<s_bone_block_definition> bones;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char unknown4;
		signed char unknown5;
		signed char unknown6;
		signed char unknown7;
		signed char unknown8;
		signed char unknown9;
		signed char unknown10;
		signed char unknown11;
		signed char unknown12;
		signed char unknown13;
		signed char unknown14;
		signed char unknown15;
		signed char unknown16;
		signed char unknown17;
		signed char unknown18;
		signed char unknown19;
		signed char unknown20;
		signed char unknown21;
		signed char unknown22;
		signed char unknown23;
		signed char unknown24;
		signed char unknown25;
		signed char unknown26;
		signed char unknown27;
		signed char unknown28;
		signed char unknown29;
		signed char unknown30;
		signed char unknown31;
		signed char unknown32;

		struct s_bone_definition
		{
			signed short bone2;
			signed short unknown;
		};
	};

	struct s_pain_definition
	{
		string_id name;
		DataReference function;
	};

	struct s_variant_mode_substitution_definition
	{
		struct s_mode_block_definition;

		string_id variant_name;
		signed int unknown;
		s_tag_block_definition<s_mode_block_definition> modes;

		struct s_mode_definition
		{
			string_id original_mode;
			string_id new_mode;
		};
	};

	struct s_skeleton_node_definition
	{
		string_id name;
		signed short next_sibling_node_index;
		signed short first_child_node_index;
		signed short parent_node_index;
		unsigned char model_flags;
		unsigned char node_joint_flags;
		signed char unknown;
		signed char unknown2;
		signed short unknown3;
		float base_vector_i;
		float base_vector_j;
		float base_vector_k;
		float vector_range;
		float z_position;
		unsigned int unknown4;
		unsigned int unknown5;
	};

	struct s_sound_reference_definition
	{
		TagReference sound;
		unsigned short flags;
		signed short unknown;
	};

	struct s_effect_reference_definition
	{
		TagReference effect;
		unsigned short flags;
		signed short unknown;
	};

	struct s_blend_screen_definition
	{
		string_id label;
		float right_yaw_per_frame;
		float left_yaw_per_frame;
		signed short right_frame_count;
		signed short left_frame_count;
		float down_pitch_per_frame;
		float up_pitch_per_frame;
		signed short down_pitch_frame_count;
		signed short up_pitch_frame_count;
	};

	struct s_leg_definition
	{
		string_id foot_marker;
		float foot_min;
		float foot_max;
		string_id ankle_marker;
		float ankle_min;
		float ankle_max;
		signed short anchors;
		signed short unknown;
	};

	struct s_animation_definition
	{
		struct s_animation_definition_block_definition;

		string_id name;
		float weight;
		signed short loop_frame_index;
		unsigned short playback_flags;
		float unknown;
		float unknown2;
		signed short previous_variant_sibling;
		signed short next_variant_sibling;
		unsigned short production_flags;
		signed char blend_screen;
		signed char unknown3;
		TagReference parent;
		signed short parent_index;
		signed short unknown4;
		s_tag_block_definition<s_animation_definition_block_definition> animation_definition2;

		struct s_animation_definition_definition
		{
			struct s_frame_event_block_definition;
			struct s_sound_event_block_definition;
			struct s_effect_event_block_definition;
			struct s_unknown_14_block_definition;
			struct s_object_space_parent_node_block_definition;
			struct s_leg_anchoring_block_definition;
			struct s_unknown17_block_definition;
			struct s_unknown19_block_definition;
			struct s_new_mode_ik_block_definition;
			struct s_unknown24_block_definition;
			struct s_unknown26_block_definition;
			struct s_unknown28_block_definition;

			signed char node_count;
			signed char unknown;
			signed short frame_count;
			signed char unknown2;
			signed char unknown3;
			signed char unknown4;
			signed char unknown5;
			signed short unknown6;
			signed char unknown7;
			signed char unknown8;
			signed int production_checksum;
			string_id import_path;
			signed int node_list_checksum;
			signed int unknown9;
			signed short unknown10;
			signed short unknown11;
			signed short raw_information_group_index;
			signed short raw_information_member_index;
			float unknown12;
			float unknown13;
			float unknown14;
			float unknown15;
			float unknown16;
			s_tag_block_definition<s_frame_event_block_definition> frame_events;
			s_tag_block_definition<s_sound_event_block_definition> sound_events;
			s_tag_block_definition<s_effect_event_block_definition> effect_events;
			s_tag_block_definition<s_unknown_14_block_definition> unknown_14_2;
			s_tag_block_definition<s_object_space_parent_node_block_definition> object_space_parent_nodes;
			s_tag_block_definition<s_leg_anchoring_block_definition> leg_anchoring2;
			s_tag_block_definition<s_unknown17_block_definition> unknown18;
			s_tag_block_definition<s_unknown19_block_definition> unknown20;
			s_tag_block_definition<s_new_mode_ik_block_definition> new_mode_ik2;
			unsigned int unknown21;
			unsigned int unknown22;
			unsigned int unknown23;
			s_tag_block_definition<s_unknown24_block_definition> unknown25;
			s_tag_block_definition<s_unknown26_block_definition> unknown27;
			s_tag_block_definition<s_unknown28_block_definition> unknown29;

			struct s_frame_event_definition
			{
				signed short type;
				signed short frame;
			};

			struct s_sound_event_definition
			{
				signed short sound;
				signed short frame;
				string_id marker_name;
			};

			struct s_effect_event_definition
			{
				signed short effect;
				signed short frame;
				string_id marker_name;
				signed char damage_reporting_type;
				signed char unknown;
				signed char unknown2;
				signed char unknown3;
			};

			struct s_unknown_14_definition
			{
				signed short unknown;
				signed short unknown2;
			};

			struct s_object_space_parent_node_definition
			{
				signed short node_index;
				unsigned short component_flags;
				signed short rotation_x;
				signed short rotation_y;
				signed short rotation_z;
				signed short rotation_w;
				float default_translation_x;
				float default_translation_y;
				float default_translation_z;
				float default_scale;
			};

			struct s_leg_anchoring_definition
			{
				struct s_unknown2_block_definition;

				signed short leg_index;
				signed short unknown;
				s_tag_block_definition<s_unknown2_block_definition> unknown3;

				struct s_unknown_definition
				{
					signed short frame_1a;
					signed short frame_2a;
					signed short frame_1b;
					signed short frame_2b;
					unsigned int unknown2;
					unsigned int unknown3;
					unsigned int unknown4;
				};
			};

			struct s_unknown_definition
			{
				signed short unknown2;
				signed short unknown3;
			};

			struct s_unknown_definition
			{
				signed short unknown2;
				signed short unknown3;
			};

			struct s_new_mode_ik_definition
			{
				string_id marker;
				signed short unknown;
				signed short bone_a;
				signed short bone_b;
				signed short unknown2;
				string_id attach_to_marker;
				signed int unknown3;
				signed char unknown4;
				signed char unknown5;
				signed char unknown6;
				signed char unknown7;
				signed char unknown8;
				signed char unknown9;
				signed char unknown10;
				signed char unknown11;
			};

			struct s_unknown_definition
			{
				string_id unknown2;
				signed char unknown3;
				signed char unknown4;
				signed char unknown5;
				signed char unknown6;
				signed short unknown7;
				signed short unknown8;
				signed char unknown9;
				signed char unknown10;
				signed char unknown11;
				signed char unknown12;
				signed short unknown13;
				signed char unknown14;
				signed char unknown15;
			};

			struct s_unknown_definition
			{
				string_id unknown2;
				signed int unknown3;
				float unknown4;
				signed short unknown5;
				signed short unknown6;
			};

			struct s_unknown_definition
			{
				unsigned int unknown2;
				unsigned int unknown3;
				unsigned int unknown4;
				DataReference unknown5;
			};
		};
	};

	struct s_animations_2_definition
	{
		string_id label;
		signed int unknown;
		unsigned int unknown2;
		float unknown3;
		signed short unknown4;
		signed short unknown5;
		signed short unknown6;
		signed short unknown7;
		unsigned int unknown8;
		unsigned int unknown9;
		string_id function;
		signed short pain_index;
		signed short unknown10;
		signed short graph_index;
		signed short animation;
	};

	struct s_trigger_animation_definition
	{
		string_id label;
		signed int unknown;
		string_id function;
		string_id function2;
		string_id function3;
		signed short graph_index;
		signed short animation;
	};

	struct s_animation_group_definition
	{
		struct s_animations_2_block_definition;
		struct s_trigger_animation_block_definition;

		string_id name;
		s_tag_block_definition<s_animations_2_block_definition> animations_2_2;
		s_tag_block_definition<s_trigger_animation_block_definition> trigger_animations;

		struct s_animations_2_definition
		{
			signed short animations_2_index;
			signed short unknown;
			signed short unknown2;
			signed short unknown3;
		};

		struct s_trigger_animation_definition
		{
			signed short trigger_animation_index;
			signed short unknown;
		};
	};

	struct s_locomotion_definition
	{
		string_id full_name;
		string_id low_speed;
		string_id mid_speed;
		string_id high_speed;
		signed short unknown;
		signed short unknown2;
	};

	struct s_movement_group_definition
	{
		struct s_locomotion_block_definition;

		string_id name;
		s_tag_block_definition<s_locomotion_block_definition> locomotion2;

		struct s_locomotion_definition
		{
			signed short locomotion_index;
			signed short unknown;
		};
	};

	struct s_limb_ik_definition
	{
		string_id name;
		string_id marker;
		signed int unknown;
		string_id marker2;
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
	};

	struct s_limb_ik_group_definition
	{
		struct s_limb_ik_block_definition;

		string_id name;
		s_tag_block_definition<s_limb_ik_block_definition> limb_ik2;

		struct s_limb_ik_definition
		{
			signed short limb_ik_index;
			signed short unknown;
		};
	};

	struct s_limb_positioning_definition
	{
		string_id limb;
		unsigned int unknown;
		signed short bone_a;
		signed short bone_b;
		signed short unknown2;
		signed short unknown3;
	};

	struct s_mode_definition
	{
		struct s_weapon_class_block_definition;
		struct s_mode_ik_block_definition;

		string_id label;
		signed short animation_group;
		signed short limb_ik_group;
		signed int unknown;
		s_tag_block_definition<s_weapon_class_block_definition> weapon_class2;
		s_tag_block_definition<s_mode_ik_block_definition> mode_ik2;
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;

		struct s_weapon_class_definition
		{
			struct s_weapon_type_block_definition;
			struct s_weapon_ik_block_definition;
			struct s_ranged_action_block_definition;
			struct s_sync_action_block_definition;

			string_id label;
			signed short animation_group;
			signed short limb_ik_group;
			s_tag_block_definition<s_weapon_type_block_definition> weapon_type2;
			s_tag_block_definition<s_weapon_ik_block_definition> weapon_ik2;
			s_tag_block_definition<s_ranged_action_block_definition> ranged_actions;
			s_tag_block_definition<s_sync_action_block_definition> sync_actions;

			struct s_weapon_type_definition
			{
				struct s_action_type_block_definition;

				string_id label;
				signed short animation_group;
				signed short limb_ik_group;
				s_tag_block_definition<s_action_type_block_definition> action_type2;

				struct s_action_type_definition
				{
					struct s_action_block_definition;
					struct s_overlay_block_definition;
					struct s_death_and_damage_block_definition;
					struct s_transition_block_definition;
					struct s_unknown2_block_definition;

					string_id label;
					signed short animation_group;
					signed short limb_ik_group;
					signed short movement_group;
					signed short unknown;
					s_tag_block_definition<s_action_block_definition> actions;
					s_tag_block_definition<s_overlay_block_definition> overlays;
					s_tag_block_definition<s_death_and_damage_block_definition> death_and_damage2;
					s_tag_block_definition<s_transition_block_definition> transitions;
					s_tag_block_definition<s_unknown2_block_definition> unknown3;

					struct s_action_definition
					{
						string_id label;
						signed short animation_group;
						signed short limb_ik_group;
						signed short graph_index;
						signed short animation;
					};

					struct s_overlay_definition
					{
						string_id label;
						signed short animation_group;
						signed short limb_ik_group;
						signed short graph_index;
						signed short animation;
					};

					struct s_death_and_damage_definition
					{
						struct s_direction_block_definition;

						string_id label;
						s_tag_block_definition<s_direction_block_definition> directions;

						struct s_direction_definition
						{
							struct s_region_block_definition;

							s_tag_block_definition<s_region_block_definition> regions;

							struct s_region_definition
							{
								signed short graph_index;
								signed short animation;
							};
						};
					};

					struct s_transition_definition
					{
						struct s_destination_block_definition;

						string_id state_name;
						s_tag_block_definition<s_destination_block_definition> destinations;

						struct s_destination_definition
						{
							string_id mode_name;
							string_id state_name;
							signed short graph_index;
							signed short animation;
						};
					};

					struct s_unknown_definition
					{
						float unknown2;
						float unknown3;
						float unknown4;
						float unknown5;
						float unknown6;
						float unknown7;
						float unknown8;
						float unknown9;
					};
				};
			};

			struct s_weapon_ik_definition
			{
				string_id marker;
				string_id attach_to_marker;
			};

			struct s_ranged_action_definition
			{
				struct s_unknown_block_definition;
				struct s_unknown3_block_definition;

				string_id label;
				s_tag_block_definition<s_unknown_block_definition> unknown2;
				s_tag_block_definition<s_unknown3_block_definition> unknown4;
				signed short unknown5;
				signed short unknown6;
				signed short unknown7;
				signed short unknown8;

				struct s_unknown_definition
				{
					signed int unknown2;
					signed short graph_index;
					signed short animation;
					float unknown3;
					unsigned int unknown4;
				};

				struct s_unknown_definition
				{
					struct s_unknown2_block_definition;
					struct s_unknown4_block_definition;

					s_tag_block_definition<s_unknown2_block_definition> unknown3;
					s_tag_block_definition<s_unknown4_block_definition> unknown5;

					struct s_unknown_definition
					{
						float unknown2;
						float unknown3;
					};

					struct s_unknown_definition
					{
						signed char unknown2;
						signed char unknown3;
						signed char unknown4;
						signed char unknown5;
						signed char unknown6;
						signed char unknown7;
						signed char unknown8;
						signed char unknown9;
					};
				};
			};

			struct s_sync_action_definition
			{
				struct s_class_block_definition;

				string_id label;
				s_tag_block_definition<s_class_block_definition> class2;

				struct s_class_definition
				{
					struct s_unknown_block_definition;
					struct s_sync_biped_block_definition;

					string_id label;
					s_tag_block_definition<s_unknown_block_definition> unknown2;
					s_tag_block_definition<s_sync_biped_block_definition> sync_biped2;

					struct s_unknown_definition
					{
						signed int unknown2;
						signed short graph_index;
						signed short animation;
						unsigned int unknown3;
						unsigned int unknown4;
						unsigned int unknown5;
						unsigned int unknown6;
						unsigned int unknown7;
						unsigned int unknown8;
						unsigned int unknown9;
						unsigned int unknown10;
						unsigned int unknown11;
						unsigned int unknown12;
					};

					struct s_sync_biped_definition
					{
						signed int unknown;
						TagReference biped;
					};
				};
			};
		};

		struct s_mode_ik_definition
		{
			string_id marker;
			string_id attach_to_marker;
		};
	};

	struct s_vehicle_suspension_definition
	{
		string_id label;
		signed short graph_index;
		signed short animation;
		string_id function;
		string_id marker_name;
		string_id unknown_marker_name;
		float mass_point_offset;
		float full_extension_ground_depth;
		float full_compression_ground_depth;
		string_id region_name;
		float mass_point_offset2;
		float full_extension_ground_depth2;
		float full_compression_ground_depth2;
	};

	struct s_object_overlay_definition
	{
		string_id label;
		signed short graph_index;
		signed short animation;
		signed short unknown;
		signed short function_controls;
		string_id function;
		unsigned int unknown2;
	};

	struct s_inheritance_list_definition
	{
		struct s_node_map_block_definition;
		struct s_node_map_flag_block_definition;

		TagReference inherited_graph;
		s_tag_block_definition<s_node_map_block_definition> node_map2;
		s_tag_block_definition<s_node_map_flag_block_definition> node_map_flags;
		unsigned int unknown;

		struct s_node_map_definition
		{
			signed short local_node;
		};

		struct s_node_map_flag_definition
		{
			signed int local_node_flags;
		};
	};

	struct s_new_inheritance_list_definition
	{
		struct s_node_map_block_definition;
		struct s_node_map_flag_block_definition;

		TagReference inherited_graph;
		s_tag_block_definition<s_node_map_block_definition> node_map2;
		s_tag_block_definition<s_node_map_flag_block_definition> node_map_flags;
		unsigned int unknown;

		struct s_node_map_definition
		{
			signed short local_node;
		};

		struct s_node_map_flag_definition
		{
			signed int local_node_flags;
		};
	};

	struct s_weapon_list_definition
	{
		string_id weapon_name;
		string_id weapon_class;
	};

	struct s_raw_information_group_definition
	{
		signed int member_count;
		unsigned int zone_asset_datum;
		unsigned short easy_read_index;
		unsigned short easy_read_salt;
		signed int useless_padding;
	};
};
