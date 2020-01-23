#pragma once

struct s_biped_definition
{
	struct s_early_mover_property_block_definition;
	struct s_ai_property_block_definition;
	struct s_function_block_definition;
	struct s_function_related_block_definition;
	struct s_attachment_block_definition;
	struct s_material_respons_block_definition;
	struct s_jet_wash_block_definition;
	struct s_widget_block_definition;
	struct s_change_color_block_definition;
	struct s_predicted_resource_block_definition;
	struct s_multiplayer_object_property_block_definition;
	struct s_unknown4_block_definition;
	struct s_metagame_property_block_definition;
	struct s_unit_screen_effect_block_definition;
	struct s_camera_track_block_definition;
	struct s_unknown18_block_definition;
	struct s_unknown20_block_definition;
	struct s_space_fighter_camera_block_definition;
	struct s_camera_track2_block_definition;
	struct s_unknown33_block_definition;
	struct s_unknown35_block_definition;
	struct s_space_fighter_camera3_block_definition;
	struct s_posture_block_definition;
	struct s_hud_interface_block_definition;
	struct s_dialogue_variant_block_definition;
	struct s_powered_seat_block_definition;
	struct s_weapon_block_definition;
	struct s_target_tracking_block_definition;
	struct s_seat_block_definition;
	struct s_trick_block_definition;
	struct s_weapon_camera_height_block_definition;
	struct s_unknown71_block_definition;
	struct s_unknown73_block_definition;
	struct s_unknown75_block_definition;
	struct s_dead_sphere_shape_block_definition;
	struct s_pill_shape_block_definition;
	struct s_sphere_shape_block_definition;
	struct s_contact_point_block_definition;

	signed short object_type;
	signed short unknown;
	signed int flags;
	float bounding_radius;
	float bounding_offset_x;
	float bounding_offset_y;
	float bounding_offset_z;
	float horizontal_acceleration_scale;
	float vertical_acceleration_scale;
	float angular_acceleration_scale;
	signed short lightmap_shadow_mode_size;
	signed char sweetener_size;
	signed char water_density;
	signed int unknown2;
	float dynamic_light_sphere_radius;
	float dynamic_light_sphere_x_offset;
	float dynamic_light_sphere_y_offset;
	float dynamic_light_sphere_z_offset;
	string_id generic_hud_text;
	TagReference generic_name_list;
	TagReference generic_service_tag_list;
	string_id default_variant;
	TagReference model;
	TagReference crate_object;
	TagReference collision_damage;
	TagReference brittle_collision_damage;
	s_tag_block_definition<s_early_mover_property_block_definition> early_mover_properties;
	TagReference creation_effect;
	TagReference material_effects;
	TagReference melee_impact;
	s_tag_block_definition<s_ai_property_block_definition> ai_properties;
	s_tag_block_definition<s_function_block_definition> functions;
	s_tag_block_definition<s_function_related_block_definition> function_related2;
	signed short hud_text_message_index;
	signed short unknown3;
	s_tag_block_definition<s_attachment_block_definition> attachments;
	s_tag_block_definition<s_material_respons_block_definition> material_responses;
	s_tag_block_definition<s_jet_wash_block_definition> jet_wash2;
	s_tag_block_definition<s_widget_block_definition> widgets;
	s_tag_block_definition<s_change_color_block_definition> change_color2;
	s_tag_block_definition<s_predicted_resource_block_definition> predicted_resources;
	s_tag_block_definition<s_multiplayer_object_property_block_definition> multiplayer_object_properties;
	TagReference simulation_interpolation;
	s_tag_block_definition<s_unknown4_block_definition> unknown5;
	signed int flags2;
	signed short team;
	signed short constant_sound_volume;
	TagReference hologram_unit;
	s_tag_block_definition<s_metagame_property_block_definition> metagame_properties;
	s_tag_block_definition<s_unit_screen_effect_block_definition> unit_screen_effects;
	signed int unknown6;
	unsigned char camera_flags;
	signed char unknown7;
	signed char unknown8;
	signed char unknown9;
	string_id camera_marker;
	float pitch_auto_level;
	float pitch_range_min;
	float pitch_range_max;
	s_tag_block_definition<s_camera_track_block_definition> camera_tracks;
	float camera_stiffness_min;
	float camera_stiffness_max;
	float unknown10;
	float camera_acceleration_speed;
	float camera_deceleration_speed;
	float unknown11;
	float camera_field_of_view;
	unsigned int unknown12;
	unsigned int unknown13;
	unsigned int unknown14;
	unsigned int unknown15;
	unsigned int unknown16;
	unsigned int unknown17;
	s_tag_block_definition<s_unknown18_block_definition> unknown19;
	s_tag_block_definition<s_unknown20_block_definition> unknown21;
	s_tag_block_definition<s_space_fighter_camera_block_definition> space_fighter_camera2;
	unsigned char camera_flags2;
	signed char unknown22;
	signed char unknown23;
	signed char unknown24;
	string_id camera_marker2;
	float pitch_auto_level2;
	float pitch_range_min2;
	float pitch_range_max2;
	s_tag_block_definition<s_camera_track2_block_definition> camera_tracks2;
	float camera_stiffness_min2;
	float camera_stiffness_max2;
	float unknown25;
	float camera_acceleration_speed2;
	float camera_deceleration_speed2;
	float unknown26;
	float camera_field_of_view2;
	unsigned int unknown27;
	unsigned int unknown28;
	unsigned int unknown29;
	unsigned int unknown30;
	unsigned int unknown31;
	unsigned int unknown32;
	s_tag_block_definition<s_unknown33_block_definition> unknown34;
	s_tag_block_definition<s_unknown35_block_definition> unknown36;
	s_tag_block_definition<s_space_fighter_camera3_block_definition> space_fighter_camera4;
	TagReference assassination_response;
	TagReference assassination_tool;
	string_id assassination_tool_marker;
	string_id assassination_tool_hand_marker;
	string_id assassination_tool_stow_anchor;
	TagReference spring_acceleration;
	float soft_ping_threshold;
	float soft_ping_interrupt_time;
	float hard_ping_threshold;
	float hard_ping_interrupt_time;
	float unknown37;
	float feign_death_threshold;
	float feign_death_time;
	float distance_of_evade_animation;
	float distance_of_dive_animation;
	float unknown38;
	float unknown39;
	float unknown40;
	float unknown41;
	unsigned int unknown42;
	unsigned int unknown43;
	float unknown44;
	unsigned int unknown45;
	float unknown46;
	float unknown47;
	float unknown48;
	unsigned int unknown49;
	float unknown50;
	float feign_death_chance;
	float feign_repeat_chance;
	TagReference spawned_turret_character;
	signed short spawned_actor_count_min;
	signed short spawned_actor_count_max;
	float spawned_velocity;
	string_id aiming_pivot_marker;
	float aiming_velocity_maximum;
	float aiming_acceleration_maximum;
	float casual_aiming_modifier;
	float looking_velocity_maximum;
	float looking_acceleration_maximum;
	unsigned int unknown51;
	string_id right_hand_node;
	string_id left_hand_node;
	string_id preferred_gun_node;
	string_id preferred_grenade_node;
	unsigned int unknown52;
	TagReference ai_melee_damage;
	TagReference melee_damage;
	TagReference boarding_melee_damage;
	TagReference boarding_melee_response;
	TagReference ejection_melee_damage;
	TagReference ejection_melee_response;
	TagReference landing_melee_damage;
	TagReference flurry_melee_damage;
	TagReference obstacle_smash_melee_damage;
	TagReference assassination_damage;
	signed short motion_sensor_blip_size;
	signed short item_scale;
	string_id equipment_variant;
	string_id dropped_equipment_variant;
	s_tag_block_definition<s_posture_block_definition> postures;
	s_tag_block_definition<s_hud_interface_block_definition> hud_interfaces;
	s_tag_block_definition<s_dialogue_variant_block_definition> dialogue_variants;
	float grenade_arc;
	float grenade_force;
	float grenade_angle;
	float grenade_velocity;
	signed short grenade_type;
	signed short grenade_count;
	s_tag_block_definition<s_powered_seat_block_definition> powered_seats;
	s_tag_block_definition<s_weapon_block_definition> weapons;
	s_tag_block_definition<s_target_tracking_block_definition> target_tracking2;
	s_tag_block_definition<s_seat_block_definition> seats;
	float unknown53;
	float unknown54;
	float emp_radius;
	TagReference emp_effect;
	TagReference boost_collision_damage;
	unsigned char boost_flags;
	signed char unknown55;
	signed char unknown56;
	signed char unknown57;
	float boost_peak_power;
	float boost_rise_power;
	float boost_fall_power;
	float boost_gauge_decay_rate;
	float boost_gauge_recharge_delay;
	float boost_gauge_recharge_rate;
	DataReference boost_function;
	float lipsync_attack_weight;
	float lipsync_decay_weight;
	TagReference detach_damage;
	TagReference detached_weapon;
	float moving_turning_speed;
	signed int flags3;
	float stationary_turning_speed;
	TagReference death_program;
	string_id unknown58;
	string_id assassination_string;
	float jump_velocity;
	s_tag_block_definition<s_trick_block_definition> tricks;
	unsigned int unknown59;
	unsigned int unknown60;
	unsigned int unknown61;
	float maximum_soft_landing_time;
	float maximum_hard_landing_time;
	float minimum_soft_landing_velocity;
	float minimum_hard_landing_velocity;
	float maximum_hard_landing_velocity;
	float stun_duration;
	float stationary_standing_camera_height;
	float moving_standing_camera_height;
	float stationary_crouching_camera_height;
	float moving_crouching_camera_height;
	float crouch_transition_time;
	DataReference crouching_camera_function;
	s_tag_block_definition<s_weapon_camera_height_block_definition> weapon_camera_height2;
	float camera_interpolation_start;
	float camera_interpolation_end;
	float unknown62;
	float unknown63;
	float unknown64;
	float unknown65;
	float unknown66;
	float autoaim_width;
	signed short physics_control_node_index;
	signed short unknown67;
	float unknown68;
	float unknown69;
	float unknown70;
	signed short pelvis_node_index;
	signed short head_node_index;
	s_tag_block_definition<s_unknown71_block_definition> unknown72;
	TagReference area_damage_effect;
	TagReference health_pickup_effect;
	s_tag_block_definition<s_unknown73_block_definition> unknown74;
	s_tag_block_definition<s_unknown75_block_definition> unknown76;
	float unknown77;
	float unknown78;
	float unknown79;
	float unknown80;
	float unknown81;
	float unknown82;
	signed int flags4;
	float height_standing;
	float height_crouching;
	float radius;
	float mass;
	string_id living_material_name;
	string_id dead_material_name;
	signed short living_global_material_index;
	signed short dead_global_material_index;
	s_tag_block_definition<s_dead_sphere_shape_block_definition> dead_sphere_shapes;
	s_tag_block_definition<s_pill_shape_block_definition> pill_shapes;
	s_tag_block_definition<s_sphere_shape_block_definition> sphere_shapes;
	float maximum_slope_angle;
	float downhill_falloff_angle;
	float downhill_cutoff_angle;
	float uphill_falloff_angle;
	float uphill_cutoff_angle;
	float downhill_velocity_scale;
	float uphill_velocity_scale;
	float unknown83;
	float unknown84;
	float unknown85;
	float unknown86;
	float unknown87;
	float unknown88;
	float unknown89;
	float falling_velocity_scale;
	float unknown90;
	float unknown91;
	float bank_angle;
	float bank_apply_time;
	float bank_decay_time;
	float pitch_ratio;
	float maximum_velocity;
	float maximum_sidestep_velocity;
	float acceleration;
	float deceleration;
	float angular_velocity_maximum;
	float angular_acceleration_maximum;
	float crouch_velocity_modifier;
	unsigned int unknown92;
	s_tag_block_definition<s_contact_point_block_definition> contact_points;
	TagReference reanimation_character;
	TagReference transformation_muffin;
	TagReference death_spawn_character;
	signed short death_spawn_count;
	signed short unknown93;
	unsigned int unknown94;
	float unknown95;
	float unknown96;
	float unknown97;
	float unknown98;
	float unknown99;
	float unknown100;
	unsigned int unknown101;
	unsigned int unknown102;
	unsigned int unknown103;
	unsigned int unknown104;
	unsigned int unknown105;
	signed int unknown106;
	float unknown107;
	float unknown108;
	float unknown109;
	float unknown110;
	float unknown111;
	float unknown112;
	float unknown113;
	float unknown114;
	float unknown115;
	float unknown116;
	float unknown117;
	float unknown118;
	float unknown119;
	float unknown120;
	float unknown121;
	float unknown122;
	float unknown123;
	float unknown124;
	float unknown125;
	float unknown126;
	float unknown127;
	float unknown128;
	float unknown129;
	float unknown130;
	float unknown131;
	float unknown132;
	float unknown133;
	float unknown134;
	float unknown135;

	struct s_early_mover_property_definition
	{
		string_id name;
		unsigned int unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		unsigned int unknown4;
		unsigned int unknown5;
		unsigned int unknown6;
		unsigned int unknown7;
		unsigned int unknown8;
		unsigned int unknown9;
		unsigned int unknown10;
	};

	struct s_ai_property_definition
	{
		signed int flags;
		string_id ai_type_name;
		unsigned int unknown;
		signed short size;
		signed short leap_jump_speed;
	};

	struct s_function_definition
	{
		struct s_unknown2_block_definition;

		signed int flags;
		string_id import_name;
		string_id export_name;
		string_id turn_off_with;
		string_id unknown;
		float minimum_value;
		DataReference default_function;
		string_id scale_by;
		s_tag_block_definition<s_unknown2_block_definition> unknown3;
		signed int _function_related__index;

		struct s_unknown_definition
		{
			signed int unknown2;
			float unknown3;
			float unknown4;
			unsigned int unknown5;
			float unknown6;
			float unknown7;
		};
	};

	struct s_function_related_definition
	{
		signed int function_index;
	};

	struct s_attachment_definition
	{
		TagReference attachment2;
		string_id marker;
		signed short change_color;
		signed short unknown;
		string_id primary_scale;
		string_id secondary_scale;
	};

	struct s_material_respons_definition
	{
		struct s_unknown4_block_definition;

		unsigned int unknown;
		unsigned int unknown2;
		unsigned int unknown3;
		s_tag_block_definition<s_unknown4_block_definition> unknown5;

		struct s_unknown_definition
		{
			string_id material;
			DataReference unknown2;
			float unknown3;
			DataReference unknown4;
			float unknown5;
			unsigned int unknown6;
			unsigned int unknown7;
		};
	};

	struct s_jet_wash_definition
	{
		string_id marker;
		float unknown;
		unsigned int unknown2;
		float unknown3;
		float unknown4;
		float unknown5;
		float unknown6;
		float unknown7;
		float unknown8;
	};

	struct s_widget_definition
	{
		TagReference type;
	};

	struct s_change_color_definition
	{
		struct s_initial_permutation_block_definition;
		struct s_function_block_definition;

		s_tag_block_definition<s_initial_permutation_block_definition> initial_permutations;
		s_tag_block_definition<s_function_block_definition> functions;

		struct s_initial_permutation_definition
		{
			float weight;
			float color_lower_bound_r;
			float color_lower_bound_g;
			float color_lower_bound_b;
			float color_upper_bound_r;
			float color_upper_bound_g;
			float color_upper_bound_b;
			string_id variant_name;
		};

		struct s_function_definition
		{
			signed int scale_flags;
			float color_lower_bound_r;
			float color_lower_bound_g;
			float color_lower_bound_b;
			float color_upper_bound_r;
			float color_upper_bound_g;
			float color_upper_bound_b;
			string_id darken_by;
			string_id scale_by;
		};
	};

	struct s_predicted_resource_definition
	{
		signed short type;
		signed short resource_index;
		unsigned int tag_index;
	};

	struct s_multiplayer_object_property_definition
	{
		signed char unknown;
		signed char object_type;
		unsigned char teleporter_flags;
		signed char unknown2;
		float radius_width;
		float length;
		float top;
		float bottom;
		signed char shape;
		signed char spawn_timer_mode;
		signed short spawn_time;
		signed short abandon_time;
		unsigned short flags;
		float unknown3;
		signed int unknown4;
		signed int unknown5;
		TagReference child_object;
		signed int unknown6;
		TagReference shape_shader;
		TagReference shader_2;
		TagReference unknown7;
		TagReference unknown8;
		TagReference secondary_shader;
		TagReference unknown9;
		TagReference unknown10;
		TagReference unknown11;
	};

	struct s_unknown_definition
	{
		TagReference unknown2;
		TagReference unknown3;
		TagReference unknown4;
	};

	struct s_metagame_property_definition
	{
		unsigned char flags;
		signed char unit;
		signed char classification;
		signed char unknown;
		signed short points;
		signed short unknown2;
	};

	struct s_unit_screen_effect_definition
	{
		TagReference screen_effect;
	};

	struct s_camera_track_definition
	{
		TagReference track;
		TagReference screen_effect;
	};

	struct s_unknown_definition
	{
		float unknown2;
		unsigned int unknown3;
		DataReference unknown4;
		float unknown5;
		float unknown6;
		float unknown7;
		signed short unknown8;
		signed short unknown9;
		DataReference unknown10;
		float unknown11;
		float unknown12;
		float unknown13;
		signed short unknown14;
		signed short unknown15;
		DataReference unknown16;
		float unknown17;
		float unknown18;
		float unknown19;
	};

	struct s_unknown_definition
	{
		struct s_unknown12_block_definition;

		signed char unknown2;
		signed char unknown3;
		signed char unknown4;
		signed char unknown5;
		float unknown6;
		float unknown7;
		float unknown8;
		float unknown9;
		float unknown10;
		float unknown11;
		s_tag_block_definition<s_unknown12_block_definition> unknown13;

		struct s_unknown_definition
		{
			DataReference function;
		};
	};

	struct s_space_fighter_camera_definition
	{
		struct s_unknown11_block_definition;

		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char unknown4;
		float unknown5;
		float unknown6;
		float unknown7;
		float unknown8;
		float unknown9;
		float unknown10;
		s_tag_block_definition<s_unknown11_block_definition> unknown12;

		struct s_unknown_definition
		{
			DataReference function;
		};
	};

	struct s_camera_track_definition
	{
		TagReference track;
		TagReference screen_effect;
	};

	struct s_unknown_definition
	{
		float unknown2;
		unsigned int unknown3;
		DataReference unknown4;
		float unknown5;
		float unknown6;
		float unknown7;
		signed short unknown8;
		signed short unknown9;
		DataReference unknown10;
		float unknown11;
		float unknown12;
		float unknown13;
		signed short unknown14;
		signed short unknown15;
		DataReference unknown16;
		float unknown17;
		float unknown18;
		float unknown19;
	};

	struct s_unknown_definition
	{
		struct s_unknown12_block_definition;

		signed char unknown2;
		signed char unknown3;
		signed char unknown4;
		signed char unknown5;
		float unknown6;
		float unknown7;
		float unknown8;
		float unknown9;
		float unknown10;
		float unknown11;
		s_tag_block_definition<s_unknown12_block_definition> unknown13;

		struct s_unknown_definition
		{
			DataReference function;
		};
	};

	struct s_space_fighter_camera_definition
	{
		struct s_unknown11_block_definition;

		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char unknown4;
		float unknown5;
		float unknown6;
		float unknown7;
		float unknown8;
		float unknown9;
		float unknown10;
		s_tag_block_definition<s_unknown11_block_definition> unknown12;

		struct s_unknown_definition
		{
			DataReference function;
		};
	};

	struct s_posture_definition
	{
		string_id name;
		float pill_offset_i;
		float pill_offset_j;
		float pill_offset_k;
	};

	struct s_hud_interface_definition
	{
		TagReference unit_hud_interface;
	};

	struct s_dialogue_variant_definition
	{
		signed short variant_number;
		signed short unknown;
		TagReference dialogue;
	};

	struct s_powered_seat_definition
	{
		float driver_powerup_time;
		float driver_powerdown_time;
	};

	struct s_weapon_definition
	{
		TagReference weapon2;
		string_id parent_marker;
	};

	struct s_target_tracking_definition
	{
		struct s_tracking_type_block_definition;

		s_tag_block_definition<s_tracking_type_block_definition> tracking_types;
		float acquire_time;
		float grace_time;
		float decay_time;
		TagReference tracking_sound;
		TagReference locked_sound;

		struct s_tracking_type_definition
		{
			string_id tracking_type2;
		};
	};

	struct s_seat_definition
	{
		struct s_camera_track_block_definition;
		struct s_unknown13_block_definition;
		struct s_unknown15_block_definition;
		struct s_space_fighter_camera_block_definition;
		struct s_unit_hud_interface_block_definition;

		signed int flags;
		string_id seat_animation;
		string_id seat_marker_name;
		string_id entry_markers_name;
		string_id boarding_grenade_marker;
		string_id boarding_grenade_string;
		string_id boarding_melee_string;
		string_id detach_weapon_string;
		float ping_scale;
		float turnover_time;
		TagReference spring_acceleration;
		float ai_scariness;
		signed short ai_seat_type;
		signed short boarding_seat;
		unsigned int block_here;
		unsigned int block_here2;
		unsigned int block_here3;
		float listener_interpolation_factor;
		float yaw_rate_bounds_min;
		float yaw_rate_bounds_max;
		float pitch_rate_bounds_min;
		float pitch_rate_bounds_max;
		float unknown;
		float minimum_speed_reference;
		float maximum_speed_reference;
		float speed_exponent;
		unsigned char camera_flags;
		signed char unknown2;
		signed char unknown3;
		signed char unknown4;
		string_id camera_marker;
		float pitch_auto_level;
		float pitch_range_min;
		float pitch_range_max;
		s_tag_block_definition<s_camera_track_block_definition> camera_tracks;
		float camera_stiffness_min;
		float camera_stiffness_max;
		float unknown5;
		float camera_acceleration_speed;
		float camera_deceleration_speed;
		float unknown6;
		float camera_field_of_view;
		unsigned int unknown7;
		unsigned int unknown8;
		unsigned int unknown9;
		unsigned int unknown10;
		unsigned int unknown11;
		unsigned int unknown12;
		s_tag_block_definition<s_unknown13_block_definition> unknown14;
		s_tag_block_definition<s_unknown15_block_definition> unknown16;
		s_tag_block_definition<s_space_fighter_camera_block_definition> space_fighter_camera2;
		s_tag_block_definition<s_unit_hud_interface_block_definition> unit_hud_interface2;
		string_id enter_seat_string;
		float yaw_range_min;
		float yaw_range_max;
		TagReference built_in_gunner;
		float entry_radius;
		float entry_marker_cone_angle;
		float entry_marker_facing_angle;
		float maximum_relative_velocity;
		float powered_off_animation_speed;
		float powered_on_animation_speed;
		string_id open_animation;
		string_id opening_animation;
		string_id closing_animation;
		string_id invisible_seat_region;
		signed int runtime_invisible_seat_region_index;

		struct s_camera_track_definition
		{
			TagReference track;
			TagReference screen_effect;
		};

		struct s_unknown_definition
		{
			float unknown2;
			unsigned int unknown3;
			DataReference unknown4;
			float unknown5;
			float unknown6;
			float unknown7;
			signed short unknown8;
			signed short unknown9;
			DataReference unknown10;
			float unknown11;
			float unknown12;
			float unknown13;
			signed short unknown14;
			signed short unknown15;
			DataReference unknown16;
			float unknown17;
			float unknown18;
			float unknown19;
		};

		struct s_unknown_definition
		{
			struct s_unknown12_block_definition;

			signed char unknown2;
			signed char unknown3;
			signed char unknown4;
			signed char unknown5;
			float unknown6;
			float unknown7;
			float unknown8;
			float unknown9;
			float unknown10;
			float unknown11;
			s_tag_block_definition<s_unknown12_block_definition> unknown13;

			struct s_unknown_definition
			{
				DataReference function;
			};
		};

		struct s_space_fighter_camera_definition
		{
			struct s_unknown11_block_definition;

			signed char unknown;
			signed char unknown2;
			signed char unknown3;
			signed char unknown4;
			float unknown5;
			float unknown6;
			float unknown7;
			float unknown8;
			float unknown9;
			float unknown10;
			s_tag_block_definition<s_unknown11_block_definition> unknown12;

			struct s_unknown_definition
			{
				DataReference function;
			};
		};

		struct s_unit_hud_interface_definition
		{
			TagReference unit_hud_interface2;
		};
	};

	struct s_trick_definition
	{
		string_id name;
		signed char initiate_direction;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		float unknown4;
		unsigned int distance_traveled;
		float unknown5;
		float unknown6;
		float unknown7;
		unsigned int cooldown_time;
	};

	struct s_weapon_camera_height_definition
	{
		string_id class;
		float standing_height_fraction;
		float crouching_height_fraction;
	};

	struct s_unknown_definition
	{
		string_id unknown2;
		float unknown3;
		float unknown4;
		float unknown5;
		unsigned int unknown6;
		string_id unknown7;
	};

	struct s_unknown_definition
	{
		float unknown2;
		float unknown3;
		float unknown4;
		float unknown5;
		float unknown6;
		DataReference function;
	};

	struct s_unknown_definition
	{
		float unknown2;
		float unknown3;
		float unknown4;
		float unknown5;
		float unknown6;
		DataReference function;
	};

	struct s_dead_sphere_shape_definition
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

	struct s_pill_shape_definition
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

	struct s_sphere_shape_definition
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

	struct s_contact_point_definition
	{
		string_id marker_name;
	};
};
