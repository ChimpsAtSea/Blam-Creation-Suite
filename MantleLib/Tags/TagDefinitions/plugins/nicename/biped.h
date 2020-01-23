#pragma once

nicename("biped") struct s_biped_definition
{
	nicename("Early Mover Properties") struct s_early_mover_property_block_definition;
	nicename("AI Properties") struct s_ai_property_block_definition;
	nicename("Functions") struct s_function_block_definition;
	nicename("Function Related") struct s_function_related_block_definition;
	nicename("Attachments") struct s_attachment_block_definition;
	nicename("Material Responses") struct s_material_respons_block_definition;
	nicename("Jet Wash") struct s_jet_wash_block_definition;
	nicename("Widgets") struct s_widget_block_definition;
	nicename("Change Color") struct s_change_color_block_definition;
	nicename("Predicted Resources") struct s_predicted_resource_block_definition;
	nicename("Multiplayer Object Properties") struct s_multiplayer_object_property_block_definition;
	nicename("Unknown") struct s_unknown4_block_definition;
	nicename("Metagame Properties") struct s_metagame_property_block_definition;
	nicename("Unit Screen Effects") struct s_unit_screen_effect_block_definition;
	nicename("Camera Tracks") struct s_camera_track_block_definition;
	nicename("Unknown") struct s_unknown18_block_definition;
	nicename("Unknown") struct s_unknown20_block_definition;
	nicename("Space Fighter Camera") struct s_space_fighter_camera_block_definition;
	nicename("Camera Tracks") struct s_camera_track2_block_definition;
	nicename("Unknown") struct s_unknown33_block_definition;
	nicename("Unknown") struct s_unknown35_block_definition;
	nicename("Space Fighter Camera") struct s_space_fighter_camera3_block_definition;
	nicename("Postures") struct s_posture_block_definition;
	nicename("HUD Interfaces") struct s_hud_interface_block_definition;
	nicename("Dialogue Variants") struct s_dialogue_variant_block_definition;
	nicename("Powered Seats") struct s_powered_seat_block_definition;
	nicename("Weapons") struct s_weapon_block_definition;
	nicename("Target Tracking") struct s_target_tracking_block_definition;
	nicename("Seats") struct s_seat_block_definition;
	nicename("Tricks") struct s_trick_block_definition;
	nicename("Weapon Camera Height") struct s_weapon_camera_height_block_definition;
	nicename("Unknown") struct s_unknown71_block_definition;
	nicename("Unknown") struct s_unknown73_block_definition;
	nicename("Unknown") struct s_unknown75_block_definition;
	nicename("Dead Sphere Shapes") struct s_dead_sphere_shape_block_definition;
	nicename("Pill Shapes") struct s_pill_shape_block_definition;
	nicename("Sphere Shapes") struct s_sphere_shape_block_definition;
	nicename("Contact Points") struct s_contact_point_block_definition;

	nicename("Object Type") signed short object_type;
	nicename("Unknown") signed short unknown;
	nicename("Flags") signed int flags;
	nicename("Bounding Radius") float bounding_radius;
	nicename("Bounding Offset X") float bounding_offset_x;
	nicename("Bounding Offset Y") float bounding_offset_y;
	nicename("Bounding Offset Z") float bounding_offset_z;
	nicename("Horizontal Acceleration Scale") float horizontal_acceleration_scale;
	nicename("Vertical Acceleration Scale") float vertical_acceleration_scale;
	nicename("Angular Acceleration Scale") float angular_acceleration_scale;
	nicename("Lightmap Shadow Mode Size") signed short lightmap_shadow_mode_size;
	nicename("Sweetener Size") signed char sweetener_size;
	nicename("Water Density") signed char water_density;
	nicename("Unknown") signed int unknown2;
	nicename("Dynamic Light Sphere Radius") float dynamic_light_sphere_radius;
	nicename("Dynamic Light Sphere X Offset") float dynamic_light_sphere_x_offset;
	nicename("Dynamic Light Sphere Y Offset") float dynamic_light_sphere_y_offset;
	nicename("Dynamic Light Sphere Z Offset") float dynamic_light_sphere_z_offset;
	nicename("Generic HUD Text") string_id generic_hud_text;
	nicename("Generic Name List") TagReference generic_name_list;
	nicename("Generic Service Tag List") TagReference generic_service_tag_list;
	nicename("Default Variant") string_id default_variant;
	nicename("Model") TagReference model;
	nicename("Crate Object") TagReference crate_object;
	nicename("Collision Damage") TagReference collision_damage;
	nicename("Brittle Collision Damage") TagReference brittle_collision_damage;
	nicename("Early Mover Properties") s_tag_block_definition<s_early_mover_property_block_definition> early_mover_properties;
	nicename("Creation Effect") TagReference creation_effect;
	nicename("Material Effects") TagReference material_effects;
	nicename("Melee Impact") TagReference melee_impact;
	nicename("AI Properties") s_tag_block_definition<s_ai_property_block_definition> ai_properties;
	nicename("Functions") s_tag_block_definition<s_function_block_definition> functions;
	nicename("Function Related") s_tag_block_definition<s_function_related_block_definition> function_related2;
	nicename("HUD Text Message Index") signed short hud_text_message_index;
	nicename("Unknown") signed short unknown3;
	nicename("Attachments") s_tag_block_definition<s_attachment_block_definition> attachments;
	nicename("Material Responses") s_tag_block_definition<s_material_respons_block_definition> material_responses;
	nicename("Jet Wash") s_tag_block_definition<s_jet_wash_block_definition> jet_wash2;
	nicename("Widgets") s_tag_block_definition<s_widget_block_definition> widgets;
	nicename("Change Color") s_tag_block_definition<s_change_color_block_definition> change_color2;
	nicename("Predicted Resources") s_tag_block_definition<s_predicted_resource_block_definition> predicted_resources;
	nicename("Multiplayer Object Properties") s_tag_block_definition<s_multiplayer_object_property_block_definition> multiplayer_object_properties;
	nicename("Simulation Interpolation") TagReference simulation_interpolation;
	nicename("Unknown") s_tag_block_definition<s_unknown4_block_definition> unknown5;
	nicename("Flags") signed int flags2;
	nicename("Team") signed short team;
	nicename("Constant Sound Volume") signed short constant_sound_volume;
	nicename("Hologram Unit") TagReference hologram_unit;
	nicename("Metagame Properties") s_tag_block_definition<s_metagame_property_block_definition> metagame_properties;
	nicename("Unit Screen Effects") s_tag_block_definition<s_unit_screen_effect_block_definition> unit_screen_effects;
	nicename("Unknown") signed int unknown6;
	nicename("Camera Flags") unsigned char camera_flags;
	nicename("Unknown") signed char unknown7;
	nicename("Unknown") signed char unknown8;
	nicename("Unknown") signed char unknown9;
	nicename("Camera Marker") string_id camera_marker;
	nicename("Pitch Auto-Level") float pitch_auto_level;
	nicename("Pitch Range min") float pitch_range_min;
	nicename("Pitch Range max") float pitch_range_max;
	nicename("Camera Tracks") s_tag_block_definition<s_camera_track_block_definition> camera_tracks;
	nicename("Camera Stiffness min") float camera_stiffness_min;
	nicename("Camera Stiffness max") float camera_stiffness_max;
	nicename("Unknown") float unknown10;
	nicename("Camera Acceleration Speed") float camera_acceleration_speed;
	nicename("Camera Deceleration Speed") float camera_deceleration_speed;
	nicename("Unknown") float unknown11;
	nicename("Camera Field Of View") float camera_field_of_view;
	nicename("Unknown") unsigned int unknown12;
	nicename("Unknown") unsigned int unknown13;
	nicename("Unknown") unsigned int unknown14;
	nicename("Unknown") unsigned int unknown15;
	nicename("Unknown") unsigned int unknown16;
	nicename("Unknown") unsigned int unknown17;
	nicename("Unknown") s_tag_block_definition<s_unknown18_block_definition> unknown19;
	nicename("Unknown") s_tag_block_definition<s_unknown20_block_definition> unknown21;
	nicename("Space Fighter Camera") s_tag_block_definition<s_space_fighter_camera_block_definition> space_fighter_camera2;
	nicename("Camera Flags") unsigned char camera_flags2;
	nicename("Unknown") signed char unknown22;
	nicename("Unknown") signed char unknown23;
	nicename("Unknown") signed char unknown24;
	nicename("Camera Marker") string_id camera_marker2;
	nicename("Pitch Auto-Level") float pitch_auto_level2;
	nicename("Pitch Range min") float pitch_range_min2;
	nicename("Pitch Range max") float pitch_range_max2;
	nicename("Camera Tracks") s_tag_block_definition<s_camera_track2_block_definition> camera_tracks2;
	nicename("Camera Stiffness min") float camera_stiffness_min2;
	nicename("Camera Stiffness max") float camera_stiffness_max2;
	nicename("Unknown") float unknown25;
	nicename("Camera Acceleration Speed") float camera_acceleration_speed2;
	nicename("Camera Deceleration Speed") float camera_deceleration_speed2;
	nicename("Unknown") float unknown26;
	nicename("Camera Field Of View") float camera_field_of_view2;
	nicename("Unknown") unsigned int unknown27;
	nicename("Unknown") unsigned int unknown28;
	nicename("Unknown") unsigned int unknown29;
	nicename("Unknown") unsigned int unknown30;
	nicename("Unknown") unsigned int unknown31;
	nicename("Unknown") unsigned int unknown32;
	nicename("Unknown") s_tag_block_definition<s_unknown33_block_definition> unknown34;
	nicename("Unknown") s_tag_block_definition<s_unknown35_block_definition> unknown36;
	nicename("Space Fighter Camera") s_tag_block_definition<s_space_fighter_camera3_block_definition> space_fighter_camera4;
	nicename("Assassination Response") TagReference assassination_response;
	nicename("Assassination Tool") TagReference assassination_tool;
	nicename("Assassination Tool Marker") string_id assassination_tool_marker;
	nicename("Assassination Tool Hand Marker") string_id assassination_tool_hand_marker;
	nicename("Assassination Tool Stow Anchor") string_id assassination_tool_stow_anchor;
	nicename("Spring Acceleration") TagReference spring_acceleration;
	nicename("Soft Ping Threshold") float soft_ping_threshold;
	nicename("Soft Ping Interrupt Time") float soft_ping_interrupt_time;
	nicename("Hard Ping Threshold") float hard_ping_threshold;
	nicename("Hard Ping Interrupt Time") float hard_ping_interrupt_time;
	nicename("Unknown") float unknown37;
	nicename("Feign Death Threshold") float feign_death_threshold;
	nicename("Feign Death Time") float feign_death_time;
	nicename("Distance of Evade Animation") float distance_of_evade_animation;
	nicename("Distance of Dive Animation") float distance_of_dive_animation;
	nicename("Unknown") float unknown38;
	nicename("Unknown") float unknown39;
	nicename("Unknown") float unknown40;
	nicename("Unknown") float unknown41;
	nicename("Unknown") unsigned int unknown42;
	nicename("Unknown") unsigned int unknown43;
	nicename("Unknown") float unknown44;
	nicename("Unknown") unsigned int unknown45;
	nicename("Unknown") float unknown46;
	nicename("Unknown") float unknown47;
	nicename("Unknown") float unknown48;
	nicename("Unknown") unsigned int unknown49;
	nicename("Unknown") float unknown50;
	nicename("Feign Death Chance") float feign_death_chance;
	nicename("Feign Repeat Chance") float feign_repeat_chance;
	nicename("Spawned Turret Character") TagReference spawned_turret_character;
	nicename("Spawned Actor Count min") signed short spawned_actor_count_min;
	nicename("Spawned Actor Count max") signed short spawned_actor_count_max;
	nicename("Spawned Velocity") float spawned_velocity;
	nicename("Aiming Pivot Marker") string_id aiming_pivot_marker;
	nicename("Aiming Velocity Maximum") float aiming_velocity_maximum;
	nicename("Aiming Acceleration Maximum") float aiming_acceleration_maximum;
	nicename("Casual Aiming Modifier") float casual_aiming_modifier;
	nicename("Looking Velocity Maximum") float looking_velocity_maximum;
	nicename("Looking Acceleration Maximum") float looking_acceleration_maximum;
	nicename("Unknown") unsigned int unknown51;
	nicename("Right Hand Node") string_id right_hand_node;
	nicename("Left Hand Node") string_id left_hand_node;
	nicename("Preferred Gun Node") string_id preferred_gun_node;
	nicename("Preferred Grenade Node") string_id preferred_grenade_node;
	nicename("Unknown") unsigned int unknown52;
	nicename("AI Melee Damage") TagReference ai_melee_damage;
	nicename("Melee Damage") TagReference melee_damage;
	nicename("Boarding Melee Damage") TagReference boarding_melee_damage;
	nicename("Boarding Melee Response") TagReference boarding_melee_response;
	nicename("Ejection Melee Damage") TagReference ejection_melee_damage;
	nicename("Ejection Melee Response") TagReference ejection_melee_response;
	nicename("Landing Melee Damage") TagReference landing_melee_damage;
	nicename("Flurry Melee Damage") TagReference flurry_melee_damage;
	nicename("Obstacle Smash Melee Damage") TagReference obstacle_smash_melee_damage;
	nicename("Assassination Damage") TagReference assassination_damage;
	nicename("Motion Sensor Blip Size") signed short motion_sensor_blip_size;
	nicename("Item Scale") signed short item_scale;
	nicename("Equipment Variant") string_id equipment_variant;
	nicename("Dropped Equipment Variant") string_id dropped_equipment_variant;
	nicename("Postures") s_tag_block_definition<s_posture_block_definition> postures;
	nicename("HUD Interfaces") s_tag_block_definition<s_hud_interface_block_definition> hud_interfaces;
	nicename("Dialogue Variants") s_tag_block_definition<s_dialogue_variant_block_definition> dialogue_variants;
	nicename("Grenade Arc") float grenade_arc;
	nicename("Grenade Force") float grenade_force;
	nicename("Grenade Angle") float grenade_angle;
	nicename("Grenade Velocity") float grenade_velocity;
	nicename("Grenade Type") signed short grenade_type;
	nicename("Grenade Count") signed short grenade_count;
	nicename("Powered Seats") s_tag_block_definition<s_powered_seat_block_definition> powered_seats;
	nicename("Weapons") s_tag_block_definition<s_weapon_block_definition> weapons;
	nicename("Target Tracking") s_tag_block_definition<s_target_tracking_block_definition> target_tracking2;
	nicename("Seats") s_tag_block_definition<s_seat_block_definition> seats;
	nicename("Unknown") float unknown53;
	nicename("Unknown") float unknown54;
	nicename("EMP Radius") float emp_radius;
	nicename("EMP Effect") TagReference emp_effect;
	nicename("Boost Collision Damage") TagReference boost_collision_damage;
	nicename("Boost Flags") unsigned char boost_flags;
	nicename("Unknown") signed char unknown55;
	nicename("Unknown") signed char unknown56;
	nicename("Unknown") signed char unknown57;
	nicename("Boost Peak Power") float boost_peak_power;
	nicename("Boost Rise Power") float boost_rise_power;
	nicename("Boost Fall Power") float boost_fall_power;
	nicename("Boost Gauge Decay Rate") float boost_gauge_decay_rate;
	nicename("Boost Gauge Recharge Delay") float boost_gauge_recharge_delay;
	nicename("Boost Gauge Recharge Rate") float boost_gauge_recharge_rate;
	nicename("Boost Function") DataReference boost_function;
	nicename("Lipsync Attack Weight") float lipsync_attack_weight;
	nicename("Lipsync Decay Weight") float lipsync_decay_weight;
	nicename("Detach Damage") TagReference detach_damage;
	nicename("Detached Weapon") TagReference detached_weapon;
	nicename("Moving Turning Speed") float moving_turning_speed;
	nicename("Flags") signed int flags3;
	nicename("Stationary Turning Speed") float stationary_turning_speed;
	nicename("Death Program") TagReference death_program;
	nicename("Unknown") string_id unknown58;
	nicename("Assassination String") string_id assassination_string;
	nicename("Jump Velocity") float jump_velocity;
	nicename("Tricks") s_tag_block_definition<s_trick_block_definition> tricks;
	nicename("Unknown") unsigned int unknown59;
	nicename("Unknown") unsigned int unknown60;
	nicename("Unknown") unsigned int unknown61;
	nicename("Maximum Soft Landing Time") float maximum_soft_landing_time;
	nicename("Maximum Hard Landing Time") float maximum_hard_landing_time;
	nicename("Minimum Soft Landing Velocity") float minimum_soft_landing_velocity;
	nicename("Minimum Hard Landing Velocity") float minimum_hard_landing_velocity;
	nicename("Maximum Hard Landing Velocity") float maximum_hard_landing_velocity;
	nicename("Stun Duration") float stun_duration;
	nicename("Stationary Standing Camera Height") float stationary_standing_camera_height;
	nicename("Moving Standing Camera Height") float moving_standing_camera_height;
	nicename("Stationary Crouching Camera Height") float stationary_crouching_camera_height;
	nicename("Moving Crouching Camera Height") float moving_crouching_camera_height;
	nicename("Crouch Transition Time") float crouch_transition_time;
	nicename("Crouching Camera Function") DataReference crouching_camera_function;
	nicename("Weapon Camera Height") s_tag_block_definition<s_weapon_camera_height_block_definition> weapon_camera_height2;
	nicename("Camera Interpolation Start") float camera_interpolation_start;
	nicename("Camera Interpolation End") float camera_interpolation_end;
	nicename("Unknown") float unknown62;
	nicename("Unknown") float unknown63;
	nicename("Unknown") float unknown64;
	nicename("Unknown") float unknown65;
	nicename("Unknown") float unknown66;
	nicename("Autoaim Width") float autoaim_width;
	nicename("Physics Control Node Index") signed short physics_control_node_index;
	nicename("Unknown") signed short unknown67;
	nicename("Unknown") float unknown68;
	nicename("Unknown") float unknown69;
	nicename("Unknown") float unknown70;
	nicename("Pelvis Node Index") signed short pelvis_node_index;
	nicename("Head Node Index") signed short head_node_index;
	nicename("Unknown") s_tag_block_definition<s_unknown71_block_definition> unknown72;
	nicename("Area Damage Effect") TagReference area_damage_effect;
	nicename("Health Pickup Effect") TagReference health_pickup_effect;
	nicename("Unknown") s_tag_block_definition<s_unknown73_block_definition> unknown74;
	nicename("Unknown") s_tag_block_definition<s_unknown75_block_definition> unknown76;
	nicename("Unknown") float unknown77;
	nicename("Unknown") float unknown78;
	nicename("Unknown") float unknown79;
	nicename("Unknown") float unknown80;
	nicename("Unknown") float unknown81;
	nicename("Unknown") float unknown82;
	nicename("Flags") signed int flags4;
	nicename("Height Standing") float height_standing;
	nicename("Height Crouching") float height_crouching;
	nicename("Radius") float radius;
	nicename("Mass") float mass;
	nicename("Living Material Name") string_id living_material_name;
	nicename("Dead Material Name") string_id dead_material_name;
	nicename("Living Global Material Index") signed short living_global_material_index;
	nicename("Dead Global Material Index") signed short dead_global_material_index;
	nicename("Dead Sphere Shapes") s_tag_block_definition<s_dead_sphere_shape_block_definition> dead_sphere_shapes;
	nicename("Pill Shapes") s_tag_block_definition<s_pill_shape_block_definition> pill_shapes;
	nicename("Sphere Shapes") s_tag_block_definition<s_sphere_shape_block_definition> sphere_shapes;
	nicename("Maximum Slope Angle") float maximum_slope_angle;
	nicename("Downhill Falloff Angle") float downhill_falloff_angle;
	nicename("Downhill Cutoff Angle") float downhill_cutoff_angle;
	nicename("Uphill Falloff Angle") float uphill_falloff_angle;
	nicename("Uphill Cutoff Angle") float uphill_cutoff_angle;
	nicename("Downhill Velocity Scale") float downhill_velocity_scale;
	nicename("Uphill Velocity Scale") float uphill_velocity_scale;
	nicename("Unknown") float unknown83;
	nicename("Unknown") float unknown84;
	nicename("Unknown") float unknown85;
	nicename("Unknown") float unknown86;
	nicename("Unknown") float unknown87;
	nicename("Unknown") float unknown88;
	nicename("Unknown") float unknown89;
	nicename("Falling Velocity Scale") float falling_velocity_scale;
	nicename("Unknown") float unknown90;
	nicename("Unknown") float unknown91;
	nicename("Bank Angle") float bank_angle;
	nicename("Bank Apply Time") float bank_apply_time;
	nicename("Bank Decay Time") float bank_decay_time;
	nicename("Pitch Ratio") float pitch_ratio;
	nicename("Maximum Velocity") float maximum_velocity;
	nicename("Maximum Sidestep Velocity") float maximum_sidestep_velocity;
	nicename("Acceleration") float acceleration;
	nicename("Deceleration") float deceleration;
	nicename("Angular Velocity Maximum") float angular_velocity_maximum;
	nicename("Angular Acceleration Maximum") float angular_acceleration_maximum;
	nicename("Crouch Velocity Modifier") float crouch_velocity_modifier;
	nicename("Unknown") unsigned int unknown92;
	nicename("Contact Points") s_tag_block_definition<s_contact_point_block_definition> contact_points;
	nicename("Reanimation Character") TagReference reanimation_character;
	nicename("Transformation Muffin") TagReference transformation_muffin;
	nicename("Death Spawn Character") TagReference death_spawn_character;
	nicename("Death Spawn Count") signed short death_spawn_count;
	nicename("Unknown") signed short unknown93;
	nicename("Unknown") unsigned int unknown94;
	nicename("Unknown") float unknown95;
	nicename("Unknown") float unknown96;
	nicename("Unknown") float unknown97;
	nicename("Unknown") float unknown98;
	nicename("Unknown") float unknown99;
	nicename("Unknown") float unknown100;
	nicename("Unknown") unsigned int unknown101;
	nicename("Unknown") unsigned int unknown102;
	nicename("Unknown") unsigned int unknown103;
	nicename("Unknown") unsigned int unknown104;
	nicename("Unknown") unsigned int unknown105;
	nicename("Unknown") signed int unknown106;
	nicename("Unknown") float unknown107;
	nicename("Unknown") float unknown108;
	nicename("Unknown") float unknown109;
	nicename("Unknown") float unknown110;
	nicename("Unknown") float unknown111;
	nicename("Unknown") float unknown112;
	nicename("Unknown") float unknown113;
	nicename("Unknown") float unknown114;
	nicename("Unknown") float unknown115;
	nicename("Unknown") float unknown116;
	nicename("Unknown") float unknown117;
	nicename("Unknown") float unknown118;
	nicename("Unknown") float unknown119;
	nicename("Unknown") float unknown120;
	nicename("Unknown") float unknown121;
	nicename("Unknown") float unknown122;
	nicename("Unknown") float unknown123;
	nicename("Unknown") float unknown124;
	nicename("Unknown") float unknown125;
	nicename("Unknown") float unknown126;
	nicename("Unknown") float unknown127;
	nicename("Unknown") float unknown128;
	nicename("Unknown") float unknown129;
	nicename("Unknown") float unknown130;
	nicename("Unknown") float unknown131;
	nicename("Unknown") float unknown132;
	nicename("Unknown") float unknown133;
	nicename("Unknown") float unknown134;
	nicename("Unknown") float unknown135;

	nicename("Early Mover Property") struct s_early_mover_property_definition
	{
		nicename("Name") string_id name;
		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") unsigned int unknown4;
		nicename("Unknown") unsigned int unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") unsigned int unknown10;
	};

	nicename("AI Property") struct s_ai_property_definition
	{
		nicename("Flags") signed int flags;
		nicename("AI Type Name") string_id ai_type_name;
		nicename("Unknown") unsigned int unknown;
		nicename("Size") signed short size;
		nicename("Leap Jump Speed") signed short leap_jump_speed;
	};

	nicename("Function") struct s_function_definition
	{
		nicename("Unknown") struct s_unknown2_block_definition;

		nicename("Flags") signed int flags;
		nicename("Import Name") string_id import_name;
		nicename("Export Name") string_id export_name;
		nicename("Turn Off With") string_id turn_off_with;
		nicename("Unknown") string_id unknown;
		nicename("Minimum Value") float minimum_value;
		nicename("Default Function") DataReference default_function;
		nicename("Scale By") string_id scale_by;
		nicename("Unknown") s_tag_block_definition<s_unknown2_block_definition> unknown3;
		nicename("'Function Related' Index") signed int _function_related__index;

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") signed int unknown2;
			nicename("Unknown") float unknown3;
			nicename("Unknown") float unknown4;
			nicename("Unknown") unsigned int unknown5;
			nicename("Unknown") float unknown6;
			nicename("Unknown") float unknown7;
		};
	};

	nicename("Function Related") struct s_function_related_definition
	{
		nicename("Function Index") signed int function_index;
	};

	nicename("Attachment") struct s_attachment_definition
	{
		nicename("Attachment") TagReference attachment2;
		nicename("Marker") string_id marker;
		nicename("Change Color") signed short change_color;
		nicename("Unknown") signed short unknown;
		nicename("Primary Scale") string_id primary_scale;
		nicename("Secondary Scale") string_id secondary_scale;
	};

	nicename("Material Respons") struct s_material_respons_definition
	{
		nicename("Unknown") struct s_unknown4_block_definition;

		nicename("Unknown") unsigned int unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") s_tag_block_definition<s_unknown4_block_definition> unknown5;

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Material") string_id material;
			nicename("Unknown") DataReference unknown2;
			nicename("Unknown") float unknown3;
			nicename("Unknown") DataReference unknown4;
			nicename("Unknown") float unknown5;
			nicename("Unknown") unsigned int unknown6;
			nicename("Unknown") unsigned int unknown7;
		};
	};

	nicename("Jet Wash") struct s_jet_wash_definition
	{
		nicename("Marker") string_id marker;
		nicename("Unknown") float unknown;
		nicename("Unknown") unsigned int unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
	};

	nicename("Widget") struct s_widget_definition
	{
		nicename("Type") TagReference type;
	};

	nicename("Change Color") struct s_change_color_definition
	{
		nicename("Initial Permutations") struct s_initial_permutation_block_definition;
		nicename("Functions") struct s_function_block_definition;

		nicename("Initial Permutations") s_tag_block_definition<s_initial_permutation_block_definition> initial_permutations;
		nicename("Functions") s_tag_block_definition<s_function_block_definition> functions;

		nicename("Initial Permutation") struct s_initial_permutation_definition
		{
			nicename("Weight") float weight;
			nicename("Color Lower Bound r") float color_lower_bound_r;
			nicename("Color Lower Bound g") float color_lower_bound_g;
			nicename("Color Lower Bound b") float color_lower_bound_b;
			nicename("Color Upper Bound r") float color_upper_bound_r;
			nicename("Color Upper Bound g") float color_upper_bound_g;
			nicename("Color Upper Bound b") float color_upper_bound_b;
			nicename("Variant Name") string_id variant_name;
		};

		nicename("Function") struct s_function_definition
		{
			nicename("Scale Flags") signed int scale_flags;
			nicename("Color Lower Bound r") float color_lower_bound_r;
			nicename("Color Lower Bound g") float color_lower_bound_g;
			nicename("Color Lower Bound b") float color_lower_bound_b;
			nicename("Color Upper Bound r") float color_upper_bound_r;
			nicename("Color Upper Bound g") float color_upper_bound_g;
			nicename("Color Upper Bound b") float color_upper_bound_b;
			nicename("Darken By...") string_id darken_by;
			nicename("Scale By...") string_id scale_by;
		};
	};

	nicename("Predicted Resource") struct s_predicted_resource_definition
	{
		nicename("Type") signed short type;
		nicename("Resource Index") signed short resource_index;
		nicename("Tag Index") unsigned int tag_index;
	};

	nicename("Multiplayer Object Property") struct s_multiplayer_object_property_definition
	{
		nicename("Unknown") signed char unknown;
		nicename("Object Type") signed char object_type;
		nicename("Teleporter Flags") unsigned char teleporter_flags;
		nicename("Unknown") signed char unknown2;
		nicename("Radius/Width") float radius_width;
		nicename("Length") float length;
		nicename("Top") float top;
		nicename("Bottom") float bottom;
		nicename("Shape") signed char shape;
		nicename("Spawn Timer Mode") signed char spawn_timer_mode;
		nicename("Spawn Time") signed short spawn_time;
		nicename("Abandon Time") signed short abandon_time;
		nicename("Flags") unsigned short flags;
		nicename("Unknown") float unknown3;
		nicename("Unknown") signed int unknown4;
		nicename("Unknown") signed int unknown5;
		nicename("Child Object") TagReference child_object;
		nicename("Unknown") signed int unknown6;
		nicename("Shape Shader") TagReference shape_shader;
		nicename("Shader 2") TagReference shader_2;
		nicename("Unknown") TagReference unknown7;
		nicename("Unknown") TagReference unknown8;
		nicename("Secondary Shader") TagReference secondary_shader;
		nicename("Unknown") TagReference unknown9;
		nicename("Unknown") TagReference unknown10;
		nicename("Unknown") TagReference unknown11;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") TagReference unknown2;
		nicename("Unknown") TagReference unknown3;
		nicename("Unknown") TagReference unknown4;
	};

	nicename("Metagame Property") struct s_metagame_property_definition
	{
		nicename("Flags") unsigned char flags;
		nicename("Unit") signed char unit;
		nicename("Classification") signed char classification;
		nicename("Unknown") signed char unknown;
		nicename("Points") signed short points;
		nicename("Unknown") signed short unknown2;
	};

	nicename("Unit Screen Effect") struct s_unit_screen_effect_definition
	{
		nicename("Screen Effect") TagReference screen_effect;
	};

	nicename("Camera Track") struct s_camera_track_definition
	{
		nicename("Track") TagReference track;
		nicename("Screen Effect") TagReference screen_effect;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") float unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") DataReference unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") signed short unknown8;
		nicename("Unknown") signed short unknown9;
		nicename("Unknown") DataReference unknown10;
		nicename("Unknown") float unknown11;
		nicename("Unknown") float unknown12;
		nicename("Unknown") float unknown13;
		nicename("Unknown") signed short unknown14;
		nicename("Unknown") signed short unknown15;
		nicename("Unknown") DataReference unknown16;
		nicename("Unknown") float unknown17;
		nicename("Unknown") float unknown18;
		nicename("Unknown") float unknown19;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") struct s_unknown12_block_definition;

		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("Unknown") signed char unknown4;
		nicename("Unknown") signed char unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
		nicename("Unknown") float unknown9;
		nicename("Unknown") float unknown10;
		nicename("Unknown") float unknown11;
		nicename("Unknown") s_tag_block_definition<s_unknown12_block_definition> unknown13;

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Function") DataReference function;
		};
	};

	nicename("Space Fighter Camera") struct s_space_fighter_camera_definition
	{
		nicename("Unknown") struct s_unknown11_block_definition;

		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("Unknown") signed char unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
		nicename("Unknown") float unknown9;
		nicename("Unknown") float unknown10;
		nicename("Unknown") s_tag_block_definition<s_unknown11_block_definition> unknown12;

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Function") DataReference function;
		};
	};

	nicename("Camera Track") struct s_camera_track_definition
	{
		nicename("Track") TagReference track;
		nicename("Screen Effect") TagReference screen_effect;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") float unknown2;
		nicename("Unknown") unsigned int unknown3;
		nicename("Unknown") DataReference unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") signed short unknown8;
		nicename("Unknown") signed short unknown9;
		nicename("Unknown") DataReference unknown10;
		nicename("Unknown") float unknown11;
		nicename("Unknown") float unknown12;
		nicename("Unknown") float unknown13;
		nicename("Unknown") signed short unknown14;
		nicename("Unknown") signed short unknown15;
		nicename("Unknown") DataReference unknown16;
		nicename("Unknown") float unknown17;
		nicename("Unknown") float unknown18;
		nicename("Unknown") float unknown19;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") struct s_unknown12_block_definition;

		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("Unknown") signed char unknown4;
		nicename("Unknown") signed char unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
		nicename("Unknown") float unknown9;
		nicename("Unknown") float unknown10;
		nicename("Unknown") float unknown11;
		nicename("Unknown") s_tag_block_definition<s_unknown12_block_definition> unknown13;

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Function") DataReference function;
		};
	};

	nicename("Space Fighter Camera") struct s_space_fighter_camera_definition
	{
		nicename("Unknown") struct s_unknown11_block_definition;

		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("Unknown") signed char unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Unknown") float unknown8;
		nicename("Unknown") float unknown9;
		nicename("Unknown") float unknown10;
		nicename("Unknown") s_tag_block_definition<s_unknown11_block_definition> unknown12;

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Function") DataReference function;
		};
	};

	nicename("Posture") struct s_posture_definition
	{
		nicename("Name") string_id name;
		nicename("Pill Offset I") float pill_offset_i;
		nicename("Pill Offset J") float pill_offset_j;
		nicename("Pill Offset K") float pill_offset_k;
	};

	nicename("HUD Interface") struct s_hud_interface_definition
	{
		nicename("Unit HUD Interface") TagReference unit_hud_interface;
	};

	nicename("Dialogue Variant") struct s_dialogue_variant_definition
	{
		nicename("Variant Number") signed short variant_number;
		nicename("Unknown") signed short unknown;
		nicename("Dialogue") TagReference dialogue;
	};

	nicename("Powered Seat") struct s_powered_seat_definition
	{
		nicename("Driver Powerup Time") float driver_powerup_time;
		nicename("Driver Powerdown Time") float driver_powerdown_time;
	};

	nicename("Weapon") struct s_weapon_definition
	{
		nicename("Weapon") TagReference weapon2;
		nicename("Parent Marker") string_id parent_marker;
	};

	nicename("Target Tracking") struct s_target_tracking_definition
	{
		nicename("Tracking Types") struct s_tracking_type_block_definition;

		nicename("Tracking Types") s_tag_block_definition<s_tracking_type_block_definition> tracking_types;
		nicename("Acquire Time") float acquire_time;
		nicename("Grace Time") float grace_time;
		nicename("Decay Time") float decay_time;
		nicename("Tracking Sound") TagReference tracking_sound;
		nicename("Locked Sound") TagReference locked_sound;

		nicename("Tracking Type") struct s_tracking_type_definition
		{
			nicename("Tracking Type") string_id tracking_type2;
		};
	};

	nicename("Seat") struct s_seat_definition
	{
		nicename("Camera Tracks") struct s_camera_track_block_definition;
		nicename("Unknown") struct s_unknown13_block_definition;
		nicename("Unknown") struct s_unknown15_block_definition;
		nicename("Space Fighter Camera") struct s_space_fighter_camera_block_definition;
		nicename("Unit HUD Interface") struct s_unit_hud_interface_block_definition;

		nicename("Flags") signed int flags;
		nicename("Seat Animation") string_id seat_animation;
		nicename("Seat Marker Name") string_id seat_marker_name;
		nicename("Entry Marker(s) Name") string_id entry_markers_name;
		nicename("Boarding Grenade Marker") string_id boarding_grenade_marker;
		nicename("Boarding Grenade String") string_id boarding_grenade_string;
		nicename("Boarding Melee String") string_id boarding_melee_string;
		nicename("Detach Weapon String") string_id detach_weapon_string;
		nicename("Ping Scale") float ping_scale;
		nicename("Turnover Time") float turnover_time;
		nicename("Spring Acceleration") TagReference spring_acceleration;
		nicename("AI Scariness") float ai_scariness;
		nicename("AI Seat Type") signed short ai_seat_type;
		nicename("Boarding Seat") signed short boarding_seat;
		nicename("block here") unsigned int block_here;
		nicename("block here") unsigned int block_here2;
		nicename("block here") unsigned int block_here3;
		nicename("Listener Interpolation Factor") float listener_interpolation_factor;
		nicename("Yaw Rate Bounds min") float yaw_rate_bounds_min;
		nicename("Yaw Rate Bounds max") float yaw_rate_bounds_max;
		nicename("Pitch Rate Bounds min") float pitch_rate_bounds_min;
		nicename("Pitch Rate Bounds max") float pitch_rate_bounds_max;
		nicename("Unknown") float unknown;
		nicename("Minimum Speed Reference") float minimum_speed_reference;
		nicename("Maximum Speed Reference") float maximum_speed_reference;
		nicename("Speed Exponent") float speed_exponent;
		nicename("Camera Flags") unsigned char camera_flags;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("Unknown") signed char unknown4;
		nicename("Camera Marker") string_id camera_marker;
		nicename("Pitch Auto-Level") float pitch_auto_level;
		nicename("Pitch Range min") float pitch_range_min;
		nicename("Pitch Range max") float pitch_range_max;
		nicename("Camera Tracks") s_tag_block_definition<s_camera_track_block_definition> camera_tracks;
		nicename("Camera Stiffness min") float camera_stiffness_min;
		nicename("Camera Stiffness max") float camera_stiffness_max;
		nicename("Unknown") float unknown5;
		nicename("Camera Acceleration Speed") float camera_acceleration_speed;
		nicename("Camera Deceleration Speed") float camera_deceleration_speed;
		nicename("Unknown") float unknown6;
		nicename("Camera Field Of View") float camera_field_of_view;
		nicename("Unknown") unsigned int unknown7;
		nicename("Unknown") unsigned int unknown8;
		nicename("Unknown") unsigned int unknown9;
		nicename("Unknown") unsigned int unknown10;
		nicename("Unknown") unsigned int unknown11;
		nicename("Unknown") unsigned int unknown12;
		nicename("Unknown") s_tag_block_definition<s_unknown13_block_definition> unknown14;
		nicename("Unknown") s_tag_block_definition<s_unknown15_block_definition> unknown16;
		nicename("Space Fighter Camera") s_tag_block_definition<s_space_fighter_camera_block_definition> space_fighter_camera2;
		nicename("Unit HUD Interface") s_tag_block_definition<s_unit_hud_interface_block_definition> unit_hud_interface2;
		nicename("Enter Seat String") string_id enter_seat_string;
		nicename("Yaw Range min") float yaw_range_min;
		nicename("Yaw Range max") float yaw_range_max;
		nicename("Built-In Gunner") TagReference built_in_gunner;
		nicename("Entry Radius") float entry_radius;
		nicename("Entry Marker Cone Angle") float entry_marker_cone_angle;
		nicename("Entry Marker Facing Angle") float entry_marker_facing_angle;
		nicename("Maximum Relative Velocity") float maximum_relative_velocity;
		nicename("Powered Off Animation Speed") float powered_off_animation_speed;
		nicename("Powered On Animation Speed") float powered_on_animation_speed;
		nicename("Open Animation") string_id open_animation;
		nicename("Opening Animation") string_id opening_animation;
		nicename("Closing Animation") string_id closing_animation;
		nicename("Invisible Seat Region") string_id invisible_seat_region;
		nicename("Runtime Invisible Seat Region Index") signed int runtime_invisible_seat_region_index;

		nicename("Camera Track") struct s_camera_track_definition
		{
			nicename("Track") TagReference track;
			nicename("Screen Effect") TagReference screen_effect;
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") float unknown2;
			nicename("Unknown") unsigned int unknown3;
			nicename("Unknown") DataReference unknown4;
			nicename("Unknown") float unknown5;
			nicename("Unknown") float unknown6;
			nicename("Unknown") float unknown7;
			nicename("Unknown") signed short unknown8;
			nicename("Unknown") signed short unknown9;
			nicename("Unknown") DataReference unknown10;
			nicename("Unknown") float unknown11;
			nicename("Unknown") float unknown12;
			nicename("Unknown") float unknown13;
			nicename("Unknown") signed short unknown14;
			nicename("Unknown") signed short unknown15;
			nicename("Unknown") DataReference unknown16;
			nicename("Unknown") float unknown17;
			nicename("Unknown") float unknown18;
			nicename("Unknown") float unknown19;
		};

		nicename("Unknown") struct s_unknown_definition
		{
			nicename("Unknown") struct s_unknown12_block_definition;

			nicename("Unknown") signed char unknown2;
			nicename("Unknown") signed char unknown3;
			nicename("Unknown") signed char unknown4;
			nicename("Unknown") signed char unknown5;
			nicename("Unknown") float unknown6;
			nicename("Unknown") float unknown7;
			nicename("Unknown") float unknown8;
			nicename("Unknown") float unknown9;
			nicename("Unknown") float unknown10;
			nicename("Unknown") float unknown11;
			nicename("Unknown") s_tag_block_definition<s_unknown12_block_definition> unknown13;

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Function") DataReference function;
			};
		};

		nicename("Space Fighter Camera") struct s_space_fighter_camera_definition
		{
			nicename("Unknown") struct s_unknown11_block_definition;

			nicename("Unknown") signed char unknown;
			nicename("Unknown") signed char unknown2;
			nicename("Unknown") signed char unknown3;
			nicename("Unknown") signed char unknown4;
			nicename("Unknown") float unknown5;
			nicename("Unknown") float unknown6;
			nicename("Unknown") float unknown7;
			nicename("Unknown") float unknown8;
			nicename("Unknown") float unknown9;
			nicename("Unknown") float unknown10;
			nicename("Unknown") s_tag_block_definition<s_unknown11_block_definition> unknown12;

			nicename("Unknown") struct s_unknown_definition
			{
				nicename("Function") DataReference function;
			};
		};

		nicename("Unit HUD Interface") struct s_unit_hud_interface_definition
		{
			nicename("Unit HUD Interface") TagReference unit_hud_interface2;
		};
	};

	nicename("Trick") struct s_trick_definition
	{
		nicename("Name") string_id name;
		nicename("Initiate Direction") signed char initiate_direction;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("Unknown") float unknown4;
		nicename("Distance Traveled") unsigned int distance_traveled;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Unknown") float unknown7;
		nicename("Cooldown Time") unsigned int cooldown_time;
	};

	nicename("Weapon Camera Height") struct s_weapon_camera_height_definition
	{
		nicename("Class") string_id class;
		nicename("Standing Height Fraction") float standing_height_fraction;
		nicename("Crouching Height Fraction") float crouching_height_fraction;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") string_id unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") unsigned int unknown6;
		nicename("Unknown") string_id unknown7;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Function") DataReference function;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Unknown") float unknown2;
		nicename("Unknown") float unknown3;
		nicename("Unknown") float unknown4;
		nicename("Unknown") float unknown5;
		nicename("Unknown") float unknown6;
		nicename("Function") DataReference function;
	};

	nicename("Dead Sphere Shape") struct s_dead_sphere_shape_definition
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

	nicename("Pill Shape") struct s_pill_shape_definition
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

	nicename("Sphere Shape") struct s_sphere_shape_definition
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

	nicename("Contact Point") struct s_contact_point_definition
	{
		nicename("Marker Name") string_id marker_name;
	};
};
