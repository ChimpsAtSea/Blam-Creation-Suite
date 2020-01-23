#pragma once

struct s_model_definition
{
	struct s_variant_block_definition;
	struct s_unknown3_block_definition;
	struct s_instance_group_block_definition;
	struct s_material_block_definition;
	struct s_omaha_material_block_definition;
	struct s_new_damage_info_block_definition;
	struct s_omaha_damage_section_block_definition;
	struct s_omaha_damage_constraint_block_definition;
	struct s_omaha_node_block_definition;
	struct s_target_block_definition;
	struct s_omaha_target_block_definition;
	struct s_collision_region_block_definition;
	struct s_node_block_definition;
	struct s_unknown_12_block_definition;
	struct s_unknown_13_block_definition;
	struct s_unknown_14_block_definition;

	TagReference model2;
	TagReference collision_model;
	TagReference animation;
	TagReference physics_model;
	TagReference imposter_model;
	signed int model_checksum;
	signed int collision_model_checksum;
	float reduce_to_l1_super_low;
	float reduce_to_l2_low;
	float reduce_to_l3_medium;
	float reduce_to_l4_high;
	float reduce_to_l5_super_high;
	signed short unknown;
	signed short unknown2;
	float decal_reduce_to_l1_super_low;
	float decal_reduce_to_l2_low;
	float decal_reduce_to_l3_medium;
	float decal_reduce_to_l4_high;
	float decal_reduce_to_l5_super_high;
	s_tag_block_definition<s_variant_block_definition> variants;
	s_tag_block_definition<s_unknown3_block_definition> unknown4;
	s_tag_block_definition<s_instance_group_block_definition> instance_groups;
	s_tag_block_definition<s_material_block_definition> materials;
	s_tag_block_definition<s_omaha_material_block_definition> omaha_materials;
	s_tag_block_definition<s_new_damage_info_block_definition> new_damage_info2;
	signed int flags;
	float base_vitality;
	string_id base_global_material;
	signed short unknown5;
	signed short unknown6;
	signed char collision_damage_reporting_type;
	signed char response_damage_reporting_type;
	signed short unknown7;
	s_tag_block_definition<s_omaha_damage_section_block_definition> omaha_damage_sections;
	s_tag_block_definition<s_omaha_damage_constraint_block_definition> omaha_damage_constraints;
	s_tag_block_definition<s_omaha_node_block_definition> omaha_nodes;
	signed short base_global_materal_index;
	signed short unknown8;
	s_tag_block_definition<s_target_block_definition> targets;
	s_tag_block_definition<s_omaha_target_block_definition> omaha_targets;
	s_tag_block_definition<s_collision_region_block_definition> collision_regions;
	s_tag_block_definition<s_node_block_definition> nodes;
	unsigned int unknown9;
	TagReference primary_dialogue;
	TagReference secondary_dialogue;
	signed int flags2;
	string_id default_dialogue_effect;
	signed int render_only_node_flags_1;
	signed int render_only_node_flags_2;
	signed int render_only_node_flags_3;
	signed int render_only_node_flags_4;
	signed int render_only_node_flags_5;
	signed int render_only_node_flags_6;
	signed int render_only_node_flags_7;
	signed int render_only_node_flags_8;
	signed int render_only_section_flags_1;
	signed int render_only_section_flags_2;
	signed int render_only_section_flags_3;
	signed int render_only_section_flags_4;
	signed int render_only_section_flags_5;
	signed int render_only_section_flags_6;
	signed int render_only_section_flags_7;
	signed int render_only_section_flags_8;
	signed int runtime_flags;
	unsigned int scenario_load_parameters_block;
	unsigned int scenario_load_parameters_block2;
	unsigned int scenario_load_parameters_block3;
	unsigned int unknown10;
	float unknown11;
	float unknown12;
	float unknown13;
	float unknown14;
	signed short unknown15;
	signed short unknown16;
	s_tag_block_definition<s_unknown_12_block_definition> unknown_12_2;
	s_tag_block_definition<s_unknown_13_block_definition> unknown_13_2;
	s_tag_block_definition<s_unknown_14_block_definition> unknown_14_2;
	TagReference shield_impact_third_person;
	TagReference shield_impact_first_person;
	float radius;
	float offset_x;
	float offset_y;
	float offset_z;

	struct s_variant_definition
	{
		struct s_region_block_definition;
		struct s_object_block_definition;

		string_id name;
		signed char model_region_0_index;
		signed char model_region_1_index;
		signed char model_region_2_index;
		signed char model_region_3_index;
		signed char model_region_4_index;
		signed char model_region_5_index;
		signed char model_region_6_index;
		signed char model_region_7_index;
		signed char model_region_8_index;
		signed char model_region_9_index;
		signed char model_region_10_index;
		signed char model_region_11_index;
		signed char model_region_12_index;
		signed char model_region_13_index;
		signed char model_region_14_index;
		signed char model_region_15_index;
		s_tag_block_definition<s_region_block_definition> regions;
		s_tag_block_definition<s_object_block_definition> objects;
		signed int instance_group_index;
		unsigned int unknown;
		unsigned int unknown2;

		struct s_region_definition
		{
			struct s_permutation_block_definition;

			string_id name;
			signed char model_region_index;
			signed char unknown;
			signed short parent_variant_index;
			s_tag_block_definition<s_permutation_block_definition> permutation2;
			signed int sort_order;

			struct s_permutation_definition
			{
				struct s_state_block_definition;

				string_id name;
				signed char model_permutation_index;
				unsigned char flags;
				signed char unknown;
				signed char unknown2;
				float probability;
				s_tag_block_definition<s_state_block_definition> states;
				unsigned int unknown3;
				unsigned int unknown4;
				unsigned int unknown5;

				struct s_state_definition
				{
					string_id name;
					signed char model_permutation_index;
					unsigned char property_flags;
					signed short state2;
					float initial_probability;
				};
			};
		};

		struct s_object_definition
		{
			string_id parent_marker;
			string_id child_marker;
			string_id object_variant;
			TagReference child_object;
			signed short unknown;
			signed char unknown2;
			signed char unknown3;
		};
	};

	struct s_unknown_definition
	{
		string_id unknown2;
	};

	struct s_instance_group_definition
	{
		string_id name;
		signed int unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		float probability;
	};

	struct s_material_definition
	{
		string_id material_name;
		signed short unknown;
		signed short damage_section_index;
		signed short unknown2;
		signed short unknown3;
		string_id material_name2;
		signed short global_material_index;
		signed short unknown4;
	};

	struct s_omaha_material_definition
	{
		string_id material_name;
		signed short unknown;
		signed short damage_section_index;
		signed short unknown2;
		signed short unknown3;
		string_id material_name2;
		signed short global_material_index;
		signed short unknown4;
	};

	struct s_new_damage_info_definition
	{
		struct s_damage_section_block_definition;
		struct s_node_block_definition;
		struct s_damage_seat_block_definition;
		struct s_damage_constraint_block_definition;

		signed int flags;
		string_id global_indirect_material;
		signed short indirect_damage_section;
		signed short unknown;
		unsigned int unknown2;
		signed char collision_damage_reporting_type;
		signed char response_damage_reporting_type;
		signed short unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		unsigned int unknown6;
		unsigned int unknown7;
		unsigned int unknown8;
		float maximum_vitality;
		float minimum_stun_damage;
		float stun_time;
		float recharge_time;
		float recharge_fraction;
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
		unsigned int unknown21;
		unsigned int unknown22;
		unsigned int unknown23;
		unsigned int unknown24;
		float maximum_shield_vitality;
		string_id global_shield_material_name;
		float minimum_stun_damage2;
		float stun_time2;
		float recharge_time2;
		unsigned int unknown25;
		unsigned int unknown26;
		unsigned int unknown27;
		TagReference shield_damaged_effect;
		TagReference shield_depletion_effect;
		TagReference shield_recharge_effect;
		s_tag_block_definition<s_damage_section_block_definition> damage_sections;
		s_tag_block_definition<s_node_block_definition> nodes;
		signed short global_shield_material_index;
		signed short global_indirect_material_index;
		float unknown28;
		unsigned int unknown29;
		unsigned int unknown30;
		s_tag_block_definition<s_damage_seat_block_definition> damage_seats;
		s_tag_block_definition<s_damage_constraint_block_definition> damage_constraints;

		struct s_damage_section_definition
		{
			struct s_instant_respons_block_definition;

			string_id name;
			signed int flags;
			float vitality_percentage;
			s_tag_block_definition<s_instant_respons_block_definition> instant_responses;
			unsigned int unknown;
			unsigned int unknown2;
			unsigned int unknown3;
			unsigned int unknown4;
			unsigned int unknown5;
			unsigned int unknown6;
			float stun_time;
			float recharge_time;
			float unknown7;
			string_id resurrection_region_name;
			signed short ressurection_region_runtime_index;
			signed short unknown8;

			struct s_instant_respons_definition
			{
				signed short response_type;
				signed short constraint_damage_type;
				string_id trigger;
				signed int flags;
				float damage_threshold;
				signed int unknown;
				float unknown2;
				TagReference primary_transition_effect;
				TagReference secondary_transition_effect;
				TagReference transition_damage_effect;
				string_id region;
				signed short new_state;
				signed short runtime_region_index;
				string_id secondary_region;
				signed short secondary_new_state;
				signed short secondary_runtime_region_index;
				signed short unknown3;
				signed short unknown_special_damage;
				string_id special_damage_case;
				string_id effect_marker_name;
				string_id damage_effect_marker_name;
				float response_delay;
				TagReference delay_effect;
				string_id delay_effect_marker_name;
				string_id ejecting_seat_label;
				float skip_fraction;
				string_id destroyed_child_object_marker_name;
				float total_damage_threshold;
			};
		};

		struct s_node_definition
		{
			signed short unknown;
			signed short unknown2;
			unsigned int unknown3;
			unsigned int unknown4;
			unsigned int unknown5;
		};

		struct s_damage_seat_definition
		{
			struct s_unknown_block_definition;

			string_id seat_label;
			float direct_damage_scale;
			float damage_transfer_fall_off_radius;
			float maximum_transfer_damage_scale;
			float minimum_transfer_damage_scale;
			s_tag_block_definition<s_unknown_block_definition> unknown2;

			struct s_unknown_definition
			{
				string_id node;
				signed short unknown2;
				signed short unknown3;
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
		};

		struct s_damage_constraint_definition
		{
			string_id physics_model_constraint_name;
			string_id damage_constraint_name;
			string_id damage_constraint_group_name;
			float group_probability_scale;
			signed short type;
			signed short index;
		};
	};

	struct s_omaha_damage_section_definition
	{
		struct s_health_function_block_definition;
		struct s_health_level_block_definition;
		struct s_omaha_instant_respons_block_definition;
		struct s_unknown12_block_definition;
		struct s_unknown14_block_definition;
		struct s_shield_impact_block_definition;

		string_id name;
		signed int flags;
		float vitality_percentage;
		string_id global_material;
		float health_recharge_delay;
		unsigned int unknown;
		float unknown2;
		s_tag_block_definition<s_health_function_block_definition> health_functions;
		s_tag_block_definition<s_health_level_block_definition> health_levels;
		TagReference recharge_effect;
		float unknown3;
		TagReference precharge_effect;
		float unknown4;
		TagReference unknown5;
		float unknown6;
		unsigned int unknown7;
		unsigned int unknown8;
		float unknown9;
		float unknown10;
		unsigned int unknown11;
		s_tag_block_definition<s_omaha_instant_respons_block_definition> omaha_instant_responses;
		s_tag_block_definition<s_unknown12_block_definition> unknown13;
		s_tag_block_definition<s_unknown14_block_definition> unknown15;
		s_tag_block_definition<s_shield_impact_block_definition> shield_impact2;
		float recharge_time;
		string_id resurrection_region_name;
		signed short ressurection_region_runtime_index;
		signed short global_material_index;

		struct s_health_function_definition
		{
			DataReference function;
		};

		struct s_health_level_definition
		{
			float percentage;
		};

		struct s_omaha_instant_respons_definition
		{
			struct s_region_state_change_block_definition;
			struct s_unknown_block_definition;
			struct s_seat_ejaculation_block_definition;

			signed int flags;
			string_id trigger;
			float damage_threshold;
			TagReference primary_transition_effect;
			string_id primary_transition_effect_marker_name;
			TagReference secondary_transition_effect;
			string_id secondary_transition_effect_marker_name;
			TagReference transition_damage_effect;
			string_id transition_damage_effect_marker_name;
			TagReference constant_effect;
			s_tag_block_definition<s_region_state_change_block_definition> region_state_changes;
			s_tag_block_definition<s_unknown_block_definition> unknown2;
			signed short unknown3;
			signed short unknown_special_damage;
			string_id special_damage_case;
			float response_delay;
			TagReference delay_effect;
			string_id delay_effect_marker_name;
			s_tag_block_definition<s_seat_ejaculation_block_definition> seat_ejaculation2;
			float skip_fraction;
			string_id destroyed_child_object_marker_name;
			float total_damage_threshold;
			string_id constraint_group_name;
			signed short constraint_damage_type;
			signed short unknown4;

			struct s_region_state_change_definition
			{
				string_id region;
				signed short new_state;
				signed short runtime_region_index;
			};

			struct s_unknown_definition
			{
				signed int unknown2;
				float unknown3;
				signed short unknown4;
				signed short unknown5;
				string_id seat_label;
			};

			struct s_seat_ejaculation_definition
			{
				string_id ejecting_seat_label;
			};
		};

		struct s_unknown_definition
		{
			signed int unknown2;
			float unknown3;
			signed short unknown4;
			signed short unknown5;
			string_id seat_label;
		};

		struct s_unknown_definition
		{
			signed int unknown2;
			float unknown3;
			signed short unknown4;
			signed short unknown5;
			string_id seat_label;
		};

		struct s_shield_impact_definition
		{
			TagReference third_person;
			TagReference first_person;
		};
	};

	struct s_omaha_damage_constraint_definition
	{
		string_id physics_model_constraint_name;
		string_id damage_constraint_name;
		string_id damage_constraint_group_name;
		float group_probability_scale;
		signed short type;
		signed short index;
	};

	struct s_omaha_node_definition
	{
		signed short unknown;
		signed short unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
	};

	struct s_target_definition
	{
		string_id marker_name;
		float size;
		float cone_angle;
		signed short damage_section;
		signed short variant;
		float targeting_relevance;
		unsigned int unknown;
		signed int flags;
		float lock_on_distance;
		string_id target_filter;
	};

	struct s_omaha_target_definition
	{
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char unknown4;
		string_id marker_name;
		float size;
		float cone_angle;
		signed short damage_section;
		signed short variant;
		float targeting_relevance;
		unsigned int unknown5;
		signed int flags;
		float lock_on_distance;
		string_id target_filter;
	};

	struct s_collision_region_definition
	{
		struct s_permutation_block_definition;

		string_id name;
		signed char collision_region_index;
		signed char physics_region_index;
		signed char unknown;
		signed char unknown2;
		s_tag_block_definition<s_permutation_block_definition> permutations;

		struct s_permutation_definition
		{
			string_id name;
			unsigned char flags;
			signed char collision_permutation_index;
			signed char physics_permutation_index;
			signed char unknown;
		};
	};

	struct s_node_definition
	{
		string_id name;
		signed short parent_node;
		signed short first_child_node;
		signed short next_sibling_node;
		signed short import_node_index;
		float default_translation_x;
		float default_translation_y;
		float default_translation_z;
		float default_rotation_i;
		float default_rotation_j;
		float default_rotation_k;
		float default_rotation_w;
		float default_scale;
		float inverse_forward_i;
		float inverse_forward_j;
		float inverse_forward_k;
		float inverse_left_i;
		float inverse_left_j;
		float inverse_left_k;
		float inverse_up_i;
		float inverse_up_j;
		float inverse_up_k;
		float inverse_position_x;
		float inverse_position_y;
		float inverse_position_z;
	};

	struct s_unknown_12_definition
	{
		string_id region;
		string_id permutation;
	};

	struct s_unknown_13_definition
	{
		string_id unknown;
		signed int unknown2;
	};

	struct s_unknown_14_definition
	{
		string_id marker;
		unsigned int unknown;
		string_id marker2;
		unsigned int unknown2;
		unsigned int unknown3;
	};
};
