#pragma once

nicename("model") struct s_model_definition
{
	nicename("Variants") struct s_variant_block_definition;
	nicename("Unknown") struct s_unknown3_block_definition;
	nicename("Instance Groups") struct s_instance_group_block_definition;
	nicename("Materials") struct s_material_block_definition;
	nicename("Omaha Materials") struct s_omaha_material_block_definition;
	nicename("New Damage Info") struct s_new_damage_info_block_definition;
	nicename("Omaha Damage Sections") struct s_omaha_damage_section_block_definition;
	nicename("Omaha Damage Constraints") struct s_omaha_damage_constraint_block_definition;
	nicename("Omaha Nodes") struct s_omaha_node_block_definition;
	nicename("Targets") struct s_target_block_definition;
	nicename("Omaha Targets") struct s_omaha_target_block_definition;
	nicename("Collision Regions") struct s_collision_region_block_definition;
	nicename("Nodes") struct s_node_block_definition;
	nicename("Unknown 12") struct s_unknown_12_block_definition;
	nicename("Unknown 13") struct s_unknown_13_block_definition;
	nicename("Unknown 14") struct s_unknown_14_block_definition;

	nicename("Model") TagReference model2;
	nicename("Collision Model") TagReference collision_model;
	nicename("Animation") TagReference animation;
	nicename("Physics Model") TagReference physics_model;
	nicename("Imposter Model") TagReference imposter_model;
	nicename("Model Checksum") signed int model_checksum;
	nicename("Collision Model Checksum") signed int collision_model_checksum;
	nicename("Reduce To L1 (super low)") float reduce_to_l1_super_low;
	nicename("Reduce To L2 (low)") float reduce_to_l2_low;
	nicename("Reduce To L3 (medium)") float reduce_to_l3_medium;
	nicename("Reduce To L4 (high)") float reduce_to_l4_high;
	nicename("Reduce To L5 (super high)") float reduce_to_l5_super_high;
	nicename("Unknown") signed short unknown;
	nicename("Unknown") signed short unknown2;
	nicename("Decal Reduce To L1 (super low)") float decal_reduce_to_l1_super_low;
	nicename("Decal Reduce To L2 (low)") float decal_reduce_to_l2_low;
	nicename("Decal Reduce To L3 (medium)") float decal_reduce_to_l3_medium;
	nicename("Decal Reduce To L4 (high)") float decal_reduce_to_l4_high;
	nicename("Decal Reduce To L5 (super high)") float decal_reduce_to_l5_super_high;
	nicename("Variants") s_tag_block_definition<s_variant_block_definition> variants;
	nicename("Unknown") s_tag_block_definition<s_unknown3_block_definition> unknown4;
	nicename("Instance Groups") s_tag_block_definition<s_instance_group_block_definition> instance_groups;
	nicename("Materials") s_tag_block_definition<s_material_block_definition> materials;
	nicename("Omaha Materials") s_tag_block_definition<s_omaha_material_block_definition> omaha_materials;
	nicename("New Damage Info") s_tag_block_definition<s_new_damage_info_block_definition> new_damage_info2;
	nicename("Flags") signed int flags;
	nicename("Base Vitality") float base_vitality;
	nicename("Base Global Material") string_id base_global_material;
	nicename("Unknown") signed short unknown5;
	nicename("Unknown") signed short unknown6;
	nicename("Collision Damage Reporting Type") signed char collision_damage_reporting_type;
	nicename("Response Damage Reporting Type") signed char response_damage_reporting_type;
	nicename("Unknown") signed short unknown7;
	nicename("Omaha Damage Sections") s_tag_block_definition<s_omaha_damage_section_block_definition> omaha_damage_sections;
	nicename("Omaha Damage Constraints") s_tag_block_definition<s_omaha_damage_constraint_block_definition> omaha_damage_constraints;
	nicename("Omaha Nodes") s_tag_block_definition<s_omaha_node_block_definition> omaha_nodes;
	nicename("Base Global Materal Index") signed short base_global_materal_index;
	nicename("Unknown") signed short unknown8;
	nicename("Targets") s_tag_block_definition<s_target_block_definition> targets;
	nicename("Omaha Targets") s_tag_block_definition<s_omaha_target_block_definition> omaha_targets;
	nicename("Collision Regions") s_tag_block_definition<s_collision_region_block_definition> collision_regions;
	nicename("Nodes") s_tag_block_definition<s_node_block_definition> nodes;
	nicename("Unknown") unsigned int unknown9;
	nicename("Primary Dialogue") TagReference primary_dialogue;
	nicename("Secondary Dialogue") TagReference secondary_dialogue;
	nicename("Flags") signed int flags2;
	nicename("Default Dialogue Effect") string_id default_dialogue_effect;
	nicename("Render-Only Node Flags 1") signed int render_only_node_flags_1;
	nicename("Render-Only Node Flags 2") signed int render_only_node_flags_2;
	nicename("Render-Only Node Flags 3") signed int render_only_node_flags_3;
	nicename("Render-Only Node Flags 4") signed int render_only_node_flags_4;
	nicename("Render-Only Node Flags 5") signed int render_only_node_flags_5;
	nicename("Render-Only Node Flags 6") signed int render_only_node_flags_6;
	nicename("Render-Only Node Flags 7") signed int render_only_node_flags_7;
	nicename("Render-Only Node Flags 8") signed int render_only_node_flags_8;
	nicename("Render-Only Section Flags 1") signed int render_only_section_flags_1;
	nicename("Render-Only Section Flags 2") signed int render_only_section_flags_2;
	nicename("Render-Only Section Flags 3") signed int render_only_section_flags_3;
	nicename("Render-Only Section Flags 4") signed int render_only_section_flags_4;
	nicename("Render-Only Section Flags 5") signed int render_only_section_flags_5;
	nicename("Render-Only Section Flags 6") signed int render_only_section_flags_6;
	nicename("Render-Only Section Flags 7") signed int render_only_section_flags_7;
	nicename("Render-Only Section Flags 8") signed int render_only_section_flags_8;
	nicename("Runtime Flags") signed int runtime_flags;
	nicename("Scenario Load Parameters Block") unsigned int scenario_load_parameters_block;
	nicename("Scenario Load Parameters Block") unsigned int scenario_load_parameters_block2;
	nicename("Scenario Load Parameters Block") unsigned int scenario_load_parameters_block3;
	nicename("Unknown") unsigned int unknown10;
	nicename("Unknown") float unknown11;
	nicename("Unknown") float unknown12;
	nicename("Unknown") float unknown13;
	nicename("Unknown") float unknown14;
	nicename("Unknown") signed short unknown15;
	nicename("Unknown") signed short unknown16;
	nicename("Unknown 12") s_tag_block_definition<s_unknown_12_block_definition> unknown_12_2;
	nicename("Unknown 13") s_tag_block_definition<s_unknown_13_block_definition> unknown_13_2;
	nicename("Unknown 14") s_tag_block_definition<s_unknown_14_block_definition> unknown_14_2;
	nicename("Shield Impact Third Person") TagReference shield_impact_third_person;
	nicename("Shield Impact First Person") TagReference shield_impact_first_person;
	nicename("Radius") float radius;
	nicename("Offset X") float offset_x;
	nicename("Offset Y") float offset_y;
	nicename("Offset Z") float offset_z;

	nicename("Variant") struct s_variant_definition
	{
		nicename("Regions") struct s_region_block_definition;
		nicename("Objects") struct s_object_block_definition;

		nicename("Name") string_id name;
		nicename("Model Region 0 Index") signed char model_region_0_index;
		nicename("Model Region 1 Index") signed char model_region_1_index;
		nicename("Model Region 2 Index") signed char model_region_2_index;
		nicename("Model Region 3 Index") signed char model_region_3_index;
		nicename("Model Region 4 Index") signed char model_region_4_index;
		nicename("Model Region 5 Index") signed char model_region_5_index;
		nicename("Model Region 6 Index") signed char model_region_6_index;
		nicename("Model Region 7 Index") signed char model_region_7_index;
		nicename("Model Region 8 Index") signed char model_region_8_index;
		nicename("Model Region 9 Index") signed char model_region_9_index;
		nicename("Model Region 10 Index") signed char model_region_10_index;
		nicename("Model Region 11 Index") signed char model_region_11_index;
		nicename("Model Region 12 Index") signed char model_region_12_index;
		nicename("Model Region 13 Index") signed char model_region_13_index;
		nicename("Model Region 14 Index") signed char model_region_14_index;
		nicename("Model Region 15 Index") signed char model_region_15_index;
		nicename("Regions") s_tag_block_definition<s_region_block_definition> regions;
		nicename("Objects") s_tag_block_definition<s_object_block_definition> objects;
		nicename("Instance Group Index") signed int instance_group_index;
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;

		nicename("Region") struct s_region_definition
		{
			nicename("Permutation") struct s_permutation_block_definition;

			nicename("Name") string_id name;
			nicename("Model Region Index") signed char model_region_index;
			nicename("Unknown") signed char unknown;
			nicename("Parent Variant Index") signed short parent_variant_index;
			nicename("Permutation") s_tag_block_definition<s_permutation_block_definition> permutation2;
			nicename("Sort Order") signed int sort_order;

			nicename("Permutation") struct s_permutation_definition
			{
				nicename("States") struct s_state_block_definition;

				nicename("Name") string_id name;
				nicename("Model Permutation Index") signed char model_permutation_index;
				nicename("Flags") unsigned char flags;
				nicename("Unknown") signed char unknown;
				nicename("Unknown") signed char unknown2;
				nicename("Probability") float probability;
				nicename("States") s_tag_block_definition<s_state_block_definition> states;
				nicename("Unknown") unsigned int unknown3;
				nicename("Unknown") unsigned int unknown4;
				nicename("Unknown") unsigned int unknown5;

				nicename("State") struct s_state_definition
				{
					nicename("Name") string_id name;
					nicename("Model Permutation Index") signed char model_permutation_index;
					nicename("Property Flags") unsigned char property_flags;
					nicename("State") signed short state2;
					nicename("Initial Probability") float initial_probability;
				};
			};
		};

		nicename("Object") struct s_object_definition
		{
			nicename("Parent Marker") string_id parent_marker;
			nicename("Child Marker") string_id child_marker;
			nicename("Object Variant") string_id object_variant;
			nicename("Child Object") TagReference child_object;
			nicename("Unknown") signed short unknown;
			nicename("Unknown") signed char unknown2;
			nicename("Unknown") signed char unknown3;
		};
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") string_id unknown2;
	};

	nicename("Instance Group") struct s_instance_group_definition
	{
		nicename("Name") string_id name;
		nicename("Unknown") signed int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Probability") float probability;
	};

	nicename("Material") struct s_material_definition
	{
		nicename("Material Name") string_id material_name;
		nicename("Unknown") signed short unknown;
		nicename("Damage Section Index") signed short damage_section_index;
		nicename("Unknown") signed short unknown2;
		nicename("Unknown") signed short unknown3;
		nicename("Material Name") string_id material_name2;
		nicename("Global Material Index") signed short global_material_index;
		nicename("Unknown") signed short unknown4;
	};

	nicename("Omaha Material") struct s_omaha_material_definition
	{
		nicename("Material Name") string_id material_name;
		nicename("Unknown") signed short unknown;
		nicename("Damage Section Index") signed short damage_section_index;
		nicename("Unknown") signed short unknown2;
		nicename("Unknown") signed short unknown3;
		nicename("Material Name") string_id material_name2;
		nicename("Global Material Index") signed short global_material_index;
		nicename("Unknown") signed short unknown4;
	};

	nicename("New Damage Info") struct s_new_damage_info_definition
	{
		nicename("Damage Sections") struct s_damage_section_block_definition;
		nicename("Nodes") struct s_node_block_definition;
		nicename("Damage Seats") struct s_damage_seat_block_definition;
		nicename("Damage Constraints") struct s_damage_constraint_block_definition;

		nicename("Flags") signed int flags;
		nicename("Global Indirect Material") string_id global_indirect_material;
		nicename("Indirect Damage Section") signed short indirect_damage_section;
		nicename("Unknown") signed short unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Collision Damage Reporting Type") signed char collision_damage_reporting_type;
		nicename("Response Damage Reporting Type") signed char response_damage_reporting_type;
		nicename("Unknown") signed short unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;
		nicename("Maximum Vitality") float maximum_vitality;
		nicename("Minimum Stun Damage") float minimum_stun_damage;
		nicename("Stun Time") float stun_time;
		nicename("Recharge Time") float recharge_time;
		nicename("Recharge Fraction") float recharge_fraction;
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
		nicename("Unknown") unsigned int unknown21;
		nicename("Unknown") unsigned int unknown22;
		nicename("Unknown") unsigned int unknown23;
		nicename("Unknown") unsigned int unknown24;
		nicename("Maximum Shield Vitality") float maximum_shield_vitality;
		nicename("Global Shield Material Name") string_id global_shield_material_name;
		nicename("Minimum Stun Damage") float minimum_stun_damage2;
		nicename("Stun Time") float stun_time2;
		nicename("Recharge Time") float recharge_time2;
		nicename("Unknown") unsigned int unknown25;
		nicename("Unknown") unsigned int unknown26;
		nicename("Unknown") unsigned int unknown27;
		nicename("Shield Damaged Effect") TagReference shield_damaged_effect;
		nicename("Shield Depletion Effect") TagReference shield_depletion_effect;
		nicename("Shield Recharge Effect") TagReference shield_recharge_effect;
		nicename("Damage Sections") s_tag_block_definition<s_damage_section_block_definition> damage_sections;
		nicename("Nodes") s_tag_block_definition<s_node_block_definition> nodes;
		nicename("Global Shield Material Index") signed short global_shield_material_index;
		nicename("Global Indirect Material Index") signed short global_indirect_material_index;
		nicename("Unknown") float unknown28;
		nicename("Unknown") unsigned int unknown29;
		nicename("Unknown") unsigned int unknown30;
		nicename("Damage Seats") s_tag_block_definition<s_damage_seat_block_definition> damage_seats;
		nicename("Damage Constraints") s_tag_block_definition<s_damage_constraint_block_definition> damage_constraints;

		nicename("Damage Section") struct s_damage_section_definition
		{
			nicename("Instant Responses") struct s_instant_respons_block_definition;

			nicename("Name") string_id name;
			nicename("Flags") signed int flags;
			nicename("Vitality Percentage") float vitality_percentage;
			nicename("Instant Responses") s_tag_block_definition<s_instant_respons_block_definition> instant_responses;
			nicename("Unknown") unsigned int unknown;
			nicename("Unknown") unsigned int unknown2;
			nicename("Unknown") unsigned int unknown3;
			nicename("Unknown") unsigned int unknown4;
			nicename("Unknown") unsigned int unknown5;
			nicename("Unknown") unsigned int unknown6;
			nicename("Stun Time") float stun_time;
			nicename("Recharge Time") float recharge_time;
			nicename("Unknown") float unknown7;
			nicename("Resurrection Region Name") string_id resurrection_region_name;
			nicename("Ressurection Region Runtime Index") signed short ressurection_region_runtime_index;
			nicename("Unknown") signed short unknown8;

			nicename("Instant Respons") struct s_instant_respons_definition
			{
				nicename("Response Type") signed short response_type;
				nicename("Constraint Damage Type") signed short constraint_damage_type;
				nicename("Trigger") string_id trigger;
				nicename("Flags") signed int flags;
				nicename("Damage Threshold") float damage_threshold;
				nicename("Unknown") signed int unknown;
				nicename("Unknown") float unknown2;
				nicename("Primary Transition Effect") TagReference primary_transition_effect;
				nicename("Secondary Transition Effect") TagReference secondary_transition_effect;
				nicename("Transition Damage Effect") TagReference transition_damage_effect;
				nicename("Region") string_id region;
				nicename("New State") signed short new_state;
				nicename("Runtime Region Index") signed short runtime_region_index;
				nicename("Secondary Region") string_id secondary_region;
				nicename("Secondary New State") signed short secondary_new_state;
				nicename("Secondary Runtime Region Index") signed short secondary_runtime_region_index;
				nicename("Unknown") signed short unknown3;
				nicename("Unknown Special Damage") signed short unknown_special_damage;
				nicename("Special Damage Case") string_id special_damage_case;
				nicename("Effect Marker Name") string_id effect_marker_name;
				nicename("Damage Effect Marker Name") string_id damage_effect_marker_name;
				nicename("Response Delay") float response_delay;
				nicename("Delay Effect") TagReference delay_effect;
				nicename("Delay Effect Marker Name") string_id delay_effect_marker_name;
				nicename("Ejecting Seat Label") string_id ejecting_seat_label;
				nicename("Skip Fraction") float skip_fraction;
				nicename("Destroyed Child Object Marker Name") string_id destroyed_child_object_marker_name;
				nicename("Total Damage Threshold") float total_damage_threshold;
			};
		};

		nicename("Node") struct s_node_definition
		{
			nicename("Unknown") signed short unknown;
			nicename("Unknown") signed short unknown2;
			nicename("Unknown") unsigned int unknown3;
			nicename("Unknown") unsigned int unknown4;
			nicename("Unknown") unsigned int unknown5;
		};

		nicename("Damage Seat") struct s_damage_seat_definition
		{
			nicename("Unknown") struct s_unknown_block_definition;

			nicename("Seat Label") string_id seat_label;
			nicename("Direct Damage Scale") float direct_damage_scale;
			nicename("Damage Transfer Fall-Off Radius") float damage_transfer_fall_off_radius;
			nicename("Maximum Transfer Damage Scale") float maximum_transfer_damage_scale;
			nicename("Minimum Transfer-Damage Scale") float minimum_transfer_damage_scale;
			nicename("Unknown") s_tag_block_definition<s_unknown_block_definition> unknown2;

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Node") string_id node;
				nicename("Unknown") signed short unknown2;
				nicename("Unknown") signed short unknown3;
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
		};

		nicename("Damage Constraint") struct s_damage_constraint_definition
		{
			nicename("Physics Model Constraint Name") string_id physics_model_constraint_name;
			nicename("Damage Constraint Name") string_id damage_constraint_name;
			nicename("Damage Constraint Group Name") string_id damage_constraint_group_name;
			nicename("Group Probability Scale") float group_probability_scale;
			nicename("Type") signed short type;
			nicename("Index") signed short index;
		};
	};

	nicename("Omaha Damage Section") struct s_omaha_damage_section_definition
	{
		nicename("Health Functions") struct s_health_function_block_definition;
		nicename("Health Levels") struct s_health_level_block_definition;
		nicename("Omaha Instant Responses") struct s_omaha_instant_respons_block_definition;
		nicename("Unknown") struct s_unknown12_block_definition;
		nicename("Unknown") struct s_unknown14_block_definition;
		nicename("Shield Impact") struct s_shield_impact_block_definition;

		nicename("Name") string_id name;
		nicename("Flags") signed int flags;
		nicename("Vitality Percentage") float vitality_percentage;
		nicename("Global Material") string_id global_material;
		nicename("Health Recharge Delay") float health_recharge_delay;
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") float unknown2;
		nicename("Health Functions") s_tag_block_definition<s_health_function_block_definition> health_functions;
		nicename("Health Levels") s_tag_block_definition<s_health_level_block_definition> health_levels;
		nicename("Recharge Effect") TagReference recharge_effect;
		nicename("Unknown") float unknown3;
		nicename("Precharge Effect") TagReference precharge_effect;
		nicename("Unknown") float unknown4;
		nicename("Unknown") TagReference unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") float unknown9;
		nicename("Unknown") float unknown10;
		nicename("Unknown") unsigned int unknown11;
		nicename("Omaha Instant Responses") s_tag_block_definition<s_omaha_instant_respons_block_definition> omaha_instant_responses;
		nicename("Unknown") s_tag_block_definition<s_unknown12_block_definition> unknown13;
		nicename("Unknown") s_tag_block_definition<s_unknown14_block_definition> unknown15;
		nicename("Shield Impact") s_tag_block_definition<s_shield_impact_block_definition> shield_impact2;
		nicename("Recharge Time") float recharge_time;
		nicename("Resurrection Region Name") string_id resurrection_region_name;
		nicename("Ressurection Region Runtime Index") signed short ressurection_region_runtime_index;
		nicename("Global Material Index") signed short global_material_index;

		nicename("Health Function") struct s_health_function_definition
		{
			nicename("Function") DataReference function;
		};

		nicename("Health Level") struct s_health_level_definition
		{
			nicename("Percentage") float percentage;
		};

		nicename("Omaha Instant Respons") struct s_omaha_instant_respons_definition
		{
			nicename("Region State Changes") struct s_region_state_change_block_definition;
			nicename("Unknown") struct s_unknown_block_definition;
			nicename("Seat Ejaculation") struct s_seat_ejaculation_block_definition;

			nicename("Flags") signed int flags;
			nicename("Trigger") string_id trigger;
			nicename("Damage Threshold") float damage_threshold;
			nicename("Primary Transition Effect") TagReference primary_transition_effect;
			nicename("Primary Transition Effect Marker Name") string_id primary_transition_effect_marker_name;
			nicename("Secondary Transition Effect") TagReference secondary_transition_effect;
			nicename("Secondary Transition Effect Marker Name") string_id secondary_transition_effect_marker_name;
			nicename("Transition Damage Effect") TagReference transition_damage_effect;
			nicename("Transition Damage Effect Marker Name") string_id transition_damage_effect_marker_name;
			nicename("Constant Effect") TagReference constant_effect;
			nicename("Region State Changes") s_tag_block_definition<s_region_state_change_block_definition> region_state_changes;
			nicename("Unknown") s_tag_block_definition<s_unknown_block_definition> unknown2;
			nicename("Unknown") signed short unknown3;
			nicename("Unknown Special Damage") signed short unknown_special_damage;
			nicename("Special Damage Case") string_id special_damage_case;
			nicename("Response Delay") float response_delay;
			nicename("Delay Effect") TagReference delay_effect;
			nicename("Delay Effect Marker Name") string_id delay_effect_marker_name;
			nicename("Seat Ejaculation") s_tag_block_definition<s_seat_ejaculation_block_definition> seat_ejaculation2;
			nicename("Skip Fraction") float skip_fraction;
			nicename("Destroyed Child Object Marker Name") string_id destroyed_child_object_marker_name;
			nicename("Total Damage Threshold") float total_damage_threshold;
			nicename("Constraint Group Name") string_id constraint_group_name;
			nicename("Constraint Damage Type") signed short constraint_damage_type;
			nicename("Unknown") signed short unknown4;

			nicename("Region State Change") struct s_region_state_change_definition
			{
				nicename("Region") string_id region;
				nicename("New State") signed short new_state;
				nicename("Runtime Region Index") signed short runtime_region_index;
			};

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Unknown") signed int unknown2;
				nicename("Unknown") float unknown3;
				nicename("Unknown") signed short unknown4;
				nicename("Unknown") signed short unknown5;
				nicename("Seat Label") string_id seat_label;
			};

			nicename("Seat Ejaculation") struct s_seat_ejaculation_definition
			{
				nicename("Ejecting Seat Label") string_id ejecting_seat_label;
			};
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") signed int unknown2;
			nicename("Unknown") float unknown3;
			nicename("Unknown") signed short unknown4;
			nicename("Unknown") signed short unknown5;
			nicename("Seat Label") string_id seat_label;
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") signed int unknown2;
			nicename("Unknown") float unknown3;
			nicename("Unknown") signed short unknown4;
			nicename("Unknown") signed short unknown5;
			nicename("Seat Label") string_id seat_label;
		};

		nicename("Shield Impact") struct s_shield_impact_definition
		{
			nicename("Third Person") TagReference third_person;
			nicename("First Person") TagReference first_person;
		};
	};

	nicename("Omaha Damage Constraint") struct s_omaha_damage_constraint_definition
	{
		nicename("Physics Model Constraint Name") string_id physics_model_constraint_name;
		nicename("Damage Constraint Name") string_id damage_constraint_name;
		nicename("Damage Constraint Group Name") string_id damage_constraint_group_name;
		nicename("Group Probability Scale") float group_probability_scale;
		nicename("Type") signed short type;
		nicename("Index") signed short index;
	};

	nicename("Omaha Node") struct s_omaha_node_definition
	{
		nicename("Unknown") signed short unknown;
		nicename("Unknown") signed short unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
	};

	nicename("Target") struct s_target_definition
	{
		nicename("Marker Name") string_id marker_name;
		nicename("Size") float size;
		nicename("Cone Angle") float cone_angle;
		nicename("Damage Section") signed short damage_section;
		nicename("Variant") signed short variant;
		nicename("Targeting Relevance") float targeting_relevance;
		nicename("Unknown") unsigned int unknown;
		nicename("Flags") signed int flags;
		nicename("Lock-On Distance") float lock_on_distance;
		nicename("Target Filter") string_id target_filter;
	};

	nicename("Omaha Target") struct s_omaha_target_definition
	{
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("Unknown") signed char unknown4;
		nicename("Marker Name") string_id marker_name;
		nicename("Size") float size;
		nicename("Cone Angle") float cone_angle;
		nicename("Damage Section") signed short damage_section;
		nicename("Variant") signed short variant;
		nicename("Targeting Relevance") float targeting_relevance;
		nicename("Unknown") unsigned int unknown5;
		nicename("Flags") signed int flags;
		nicename("Lock-On Distance") float lock_on_distance;
		nicename("Target Filter") string_id target_filter;
	};

	nicename("Collision Region") struct s_collision_region_definition
	{
		nicename("Permutations") struct s_permutation_block_definition;

		nicename("Name") string_id name;
		nicename("Collision Region Index") signed char collision_region_index;
		nicename("Physics Region Index") signed char physics_region_index;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Permutations") s_tag_block_definition<s_permutation_block_definition> permutations;

		nicename("Permutation") struct s_permutation_definition
		{
			nicename("Name") string_id name;
			nicename("Flags") unsigned char flags;
			nicename("Collision Permutation Index") signed char collision_permutation_index;
			nicename("Physics Permutation Index") signed char physics_permutation_index;
			nicename("Unknown") signed char unknown;
		};
	};

	nicename("Node") struct s_node_definition
	{
		nicename("Name") string_id name;
		nicename("Parent Node") signed short parent_node;
		nicename("First Child Node") signed short first_child_node;
		nicename("Next Sibling Node") signed short next_sibling_node;
		nicename("Import Node Index") signed short import_node_index;
		nicename("Default Translation x") float default_translation_x;
		nicename("Default Translation y") float default_translation_y;
		nicename("Default Translation z") float default_translation_z;
		nicename("Default Rotation i") float default_rotation_i;
		nicename("Default Rotation j") float default_rotation_j;
		nicename("Default Rotation k") float default_rotation_k;
		nicename("Default Rotation w") float default_rotation_w;
		nicename("Default Scale") float default_scale;
		nicename("Inverse Forward i") float inverse_forward_i;
		nicename("Inverse Forward j") float inverse_forward_j;
		nicename("Inverse Forward k") float inverse_forward_k;
		nicename("Inverse Left i") float inverse_left_i;
		nicename("Inverse Left j") float inverse_left_j;
		nicename("Inverse Left k") float inverse_left_k;
		nicename("Inverse Up i") float inverse_up_i;
		nicename("Inverse Up j") float inverse_up_j;
		nicename("Inverse Up k") float inverse_up_k;
		nicename("Inverse Position x") float inverse_position_x;
		nicename("Inverse Position y") float inverse_position_y;
		nicename("Inverse Position z") float inverse_position_z;
	};

	nicename("Unknown 12") struct s_unknown_12_definition
	{
		nicename("Region") string_id region;
		nicename("Permutation") string_id permutation;
	};

	nicename("Unknown 13") struct s_unknown_13_definition
	{
		nicename("Unknown") string_id unknown;
		nicename("Unknown") signed int unknown2;
	};

	nicename("Unknown 14") struct s_unknown_14_definition
	{
		nicename("Marker") string_id marker;
		nicename("Unknown") unsigned int unknown;
		nicename("Marker") string_id marker2;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
	};
};
