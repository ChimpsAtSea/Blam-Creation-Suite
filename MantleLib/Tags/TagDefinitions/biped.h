#pragma once

struct nicename("Biped") group('bipd') s_biped_definition
{
	struct nicename("Early Mover Properties") s_early_mover_property_block_definition;
	struct nicename("AI Properties") s_ai_property_block_definition;
	struct nicename("Functions") s_function_block_definition;
	struct nicename("Function Related") s_function_related_block_definition;
	struct nicename("Attachments") s_attachment_block_definition;
	struct nicename("Material Responses") s_material_respons_block_definition;
	struct nicename("Jet Wash") s_jet_wash_block_definition;
	struct nicename("Widgets") s_widget_block_definition;
	struct nicename("Change Color") s_change_color_block_definition;
	struct nicename("Predicted Resources") s_predicted_resource_block_definition;
	struct nicename("Multiplayer Object Properties") s_multiplayer_object_property_block_definition;
	struct s_unknown_block_definition;
	struct nicename("Metagame Properties") s_metagame_property_block_definition;
	struct nicename("Unit Screen Effects") s_unit_screen_effect_block_definition;
	struct nicename("Camera Tracks") s_camera_track_block_definition;
	struct s_unknown2_block_definition;
	struct s_unknown3_block_definition;
	struct nicename("Space Fighter Camera") s_space_fighter_camera_block_definition;
	struct nicename("Camera Tracks") s_camera_track2_block_definition;
	struct s_unknown4_block_definition;
	struct s_unknown5_block_definition;
	struct nicename("Space Fighter Camera") s_space_fighter_camera2_block_definition;
	struct nicename("Postures") s_posture_block_definition;
	struct nicename("HUD Interfaces") s_hud_interface_block_definition;
	struct nicename("Dialogue Variants") s_dialogue_variant_block_definition;
	struct nicename("Powered Seats") s_powered_seat_block_definition;
	struct nicename("Weapons") s_weapon_block_definition;
	struct nicename("Target Tracking") s_target_tracking_block_definition;
	struct nicename("Seats") s_seat_block_definition;
	struct nicename("Tricks") s_trick_block_definition;
	struct nicename("Weapon Camera Height") s_weapon_camera_height_block_definition;
	struct s_unknown6_block_definition;
	struct s_unknown7_block_definition;
	struct s_unknown8_block_definition;
	struct nicename("Dead Sphere Shapes") s_dead_sphere_shape_block_definition;
	struct nicename("Pill Shapes") s_pill_shape_block_definition;
	struct nicename("Sphere Shapes") s_sphere_shape_block_definition;
	struct nicename("Contact Points") s_contact_point_block_definition;

	int16_t nicename("Object Type") object_type; 
	int16_t __unknown; 
	int32_t nicename("Flags") flags; 
	float nicename("Bounding Radius") bounding_radius; 
	float nicename("Bounding Offset X") bounding_offset_x; 
	float nicename("Bounding Offset Y") bounding_offset_y; 
	float nicename("Bounding Offset Z") bounding_offset_z; 
	float nicename("Horizontal Acceleration Scale") horizontal_acceleration_scale; 
	float nicename("Vertical Acceleration Scale") vertical_acceleration_scale; 
	float nicename("Angular Acceleration Scale") angular_acceleration_scale; 
	int16_t nicename("Lightmap Shadow Mode Size") lightmap_shadow_mode_size; 
	int8_t nicename("Sweetener Size") sweetener_size; 
	int8_t nicename("Water Density") water_density; 
	int32_t __unknown2; 
	float nicename("Dynamic Light Sphere Radius") dynamic_light_sphere_radius; 
	float nicename("Dynamic Light Sphere X Offset") dynamic_light_sphere_x_offset; 
	float nicename("Dynamic Light Sphere Y Offset") dynamic_light_sphere_y_offset; 
	float nicename("Dynamic Light Sphere Z Offset") dynamic_light_sphere_z_offset; 
	string_id nicename("Generic HUD Text") generic_hud_text; 
	TagReference nicename("Generic Name List") generic_name_list_reference; 
	TagReference nicename("Generic Service Tag List") generic_service_tag_list_reference; 
	string_id nicename("Default Variant") default_variant; 
	TagReference nicename("Model") model_reference; 
	TagReference nicename("Crate Object") crate_object_reference; 
	TagReference nicename("Collision Damage") collision_damage_reference; 
	TagReference nicename("Brittle Collision Damage") brittle_collision_damage_reference; 
	s_tag_block_definition<s_early_mover_property_block_definition> nicename("Early Mover Properties") early_mover_properties_block; 
	TagReference nicename("Creation Effect") creation_effect_reference; 
	TagReference nicename("Material Effects") material_effects_reference; 
	TagReference nicename("Melee Impact") melee_impact_reference; 
	s_tag_block_definition<s_ai_property_block_definition> nicename("AI Properties") ai_properties_block; 
	s_tag_block_definition<s_function_block_definition> nicename("Functions") functions_block; 
	s_tag_block_definition<s_function_related_block_definition> nicename("Function Related") function_related_block; 
	int16_t nicename("HUD Text Message Index") hud_text_message_index; 
	int16_t __unknown3; 
	s_tag_block_definition<s_attachment_block_definition> nicename("Attachments") attachments_block; 
	s_tag_block_definition<s_material_respons_block_definition> nicename("Material Responses") material_responses_block; 
	s_tag_block_definition<s_jet_wash_block_definition> nicename("Jet Wash") jet_wash_block; 
	s_tag_block_definition<s_widget_block_definition> nicename("Widgets") widgets_block; 
	s_tag_block_definition<s_change_color_block_definition> nicename("Change Color") change_color_block; 
	s_tag_block_definition<s_predicted_resource_block_definition> nicename("Predicted Resources") predicted_resources_block; 
	s_tag_block_definition<s_multiplayer_object_property_block_definition> nicename("Multiplayer Object Properties") multiplayer_object_properties_block; 
	TagReference nicename("Simulation Interpolation") simulation_interpolation_reference; 
	s_tag_block_definition<s_unknown_block_definition> __unknown4_block; 
	// comment
	int32_t nicename("Flags") flags2; 
	int16_t nicename("Team") team; 
	int16_t nicename("Constant Sound Volume") constant_sound_volume; 
	TagReference nicename("Hologram Unit") hologram_unit_reference; 
	s_tag_block_definition<s_metagame_property_block_definition> nicename("Metagame Properties") metagame_properties_block; 
	s_tag_block_definition<s_unit_screen_effect_block_definition> nicename("Unit Screen Effects") unit_screen_effects_block; 
	int32_t __unknown5; 
	// comment
	uint8_t nicename("Camera Flags") camera_flags; 
	int8_t __unknown6; 
	int8_t __unknown7; 
	int8_t __unknown8; 
	string_id nicename("Camera Marker") camera_marker; 
	float nicename("Pitch Auto-Level") pitch_auto_level; 
	float nicename("Pitch Range min") pitch_range_min; 
	float nicename("Pitch Range max") pitch_range_max; 
	s_tag_block_definition<s_camera_track_block_definition> nicename("Camera Tracks") camera_tracks_block; 
	float nicename("Camera Stiffness min") camera_stiffness_min; 
	float nicename("Camera Stiffness max") camera_stiffness_max; 
	float __unknown9; 
	float nicename("Camera Acceleration Speed") camera_acceleration_speed; 
	float nicename("Camera Deceleration Speed") camera_deceleration_speed; 
	float __unknown10; 
	float nicename("Camera Field Of View") camera_field_of_view; 
	Undefined32 __unknown11; 
	Undefined32 __unknown12; 
	Undefined32 __unknown13; 
	Undefined32 __unknown14; 
	Undefined32 __unknown15; 
	Undefined32 __unknown16; 
	s_tag_block_definition<s_unknown2_block_definition> __unknown17_block; 
	s_tag_block_definition<s_unknown3_block_definition> __unknown18_block; 
	s_tag_block_definition<s_space_fighter_camera_block_definition> nicename("Space Fighter Camera") space_fighter_camera_block; 
	// comment
	uint8_t nicename("Camera Flags") camera_flags2; 
	int8_t __unknown19; 
	int8_t __unknown20; 
	int8_t __unknown21; 
	string_id nicename("Camera Marker") camera_marker2; 
	float nicename("Pitch Auto-Level") pitch_auto_level2; 
	float nicename("Pitch Range min") pitch_range_min2; 
	float nicename("Pitch Range max") pitch_range_max2; 
	s_tag_block_definition<s_camera_track2_block_definition> nicename("Camera Tracks") camera_tracks2_block; 
	float nicename("Camera Stiffness min") camera_stiffness_min2; 
	float nicename("Camera Stiffness max") camera_stiffness_max2; 
	float __unknown22; 
	float nicename("Camera Acceleration Speed") camera_acceleration_speed2; 
	float nicename("Camera Deceleration Speed") camera_deceleration_speed2; 
	float __unknown23; 
	float nicename("Camera Field Of View") camera_field_of_view2; 
	Undefined32 __unknown24; 
	Undefined32 __unknown25; 
	Undefined32 __unknown26; 
	Undefined32 __unknown27; 
	Undefined32 __unknown28; 
	Undefined32 __unknown29; 
	s_tag_block_definition<s_unknown4_block_definition> __unknown30_block; 
	s_tag_block_definition<s_unknown5_block_definition> __unknown31_block; 
	s_tag_block_definition<s_space_fighter_camera2_block_definition> nicename("Space Fighter Camera") space_fighter_camera2_block; 
	TagReference nicename("Assassination Response") assassination_response_reference; 
	TagReference nicename("Assassination Tool") assassination_tool_reference; 
	string_id nicename("Assassination Tool Marker") assassination_tool_marker; 
	string_id nicename("Assassination Tool Hand Marker") assassination_tool_hand_marker; 
	string_id nicename("Assassination Tool Stow Anchor") assassination_tool_stow_anchor; 
	TagReference nicename("Spring Acceleration") spring_acceleration_reference; 
	float nicename("Soft Ping Threshold") soft_ping_threshold; 
	float nicename("Soft Ping Interrupt Time") soft_ping_interrupt_time; 
	float nicename("Hard Ping Threshold") hard_ping_threshold; 
	float nicename("Hard Ping Interrupt Time") hard_ping_interrupt_time; 
	float __unknown32; 
	float nicename("Feign Death Threshold") feign_death_threshold; 
	float nicename("Feign Death Time") feign_death_time; 
	float nicename("Distance of Evade Animation") distance_of_evade_animation; 
	float nicename("Distance of Dive Animation") distance_of_dive_animation; 
	float __unknown33; 
	float __unknown34; 
	float __unknown35; 
	float __unknown36; 
	Undefined32 __unknown37; 
	Undefined32 __unknown38; 
	float __unknown39; 
	Undefined32 __unknown40; 
	float __unknown41; 
	float __unknown42; 
	float __unknown43; 
	Undefined32 __unknown44; 
	float __unknown45; 
	float nicename("Feign Death Chance") feign_death_chance; 
	float nicename("Feign Repeat Chance") feign_repeat_chance; 
	TagReference nicename("Spawned Turret Character") spawned_turret_character_reference; 
	int16_t nicename("Spawned Actor Count min") spawned_actor_count_min; 
	int16_t nicename("Spawned Actor Count max") spawned_actor_count_max; 
	float nicename("Spawned Velocity") spawned_velocity; 
	string_id nicename("Aiming Pivot Marker") aiming_pivot_marker; 
	float nicename("Aiming Velocity Maximum") aiming_velocity_maximum; 
	float nicename("Aiming Acceleration Maximum") aiming_acceleration_maximum; 
	float nicename("Casual Aiming Modifier") casual_aiming_modifier; 
	float nicename("Looking Velocity Maximum") looking_velocity_maximum; 
	float nicename("Looking Acceleration Maximum") looking_acceleration_maximum; 
	Undefined32 __unknown46; 
	string_id nicename("Right Hand Node") right_hand_node; 
	string_id nicename("Left Hand Node") left_hand_node; 
	string_id nicename("Preferred Gun Node") preferred_gun_node; 
	string_id nicename("Preferred Grenade Node") preferred_grenade_node; 
	Undefined32 __unknown47; 
	TagReference nicename("AI Melee Damage") ai_melee_damage_reference; 
	TagReference nicename("Melee Damage") melee_damage_reference; 
	TagReference nicename("Boarding Melee Damage") boarding_melee_damage_reference; 
	TagReference nicename("Boarding Melee Response") boarding_melee_response_reference; 
	TagReference nicename("Ejection Melee Damage") ejection_melee_damage_reference; 
	TagReference nicename("Ejection Melee Response") ejection_melee_response_reference; 
	TagReference nicename("Landing Melee Damage") landing_melee_damage_reference; 
	TagReference nicename("Flurry Melee Damage") flurry_melee_damage_reference; 
	TagReference nicename("Obstacle Smash Melee Damage") obstacle_smash_melee_damage_reference; 
	TagReference nicename("Assassination Damage") assassination_damage_reference; 
	int16_t nicename("Motion Sensor Blip Size") motion_sensor_blip_size; 
	int16_t nicename("Item Scale") item_scale; 
	string_id nicename("Equipment Variant") equipment_variant; 
	string_id nicename("Dropped Equipment Variant") dropped_equipment_variant; 
	s_tag_block_definition<s_posture_block_definition> nicename("Postures") postures_block; 
	s_tag_block_definition<s_hud_interface_block_definition> nicename("HUD Interfaces") hud_interfaces_block; 
	s_tag_block_definition<s_dialogue_variant_block_definition> nicename("Dialogue Variants") dialogue_variants_block; 
	float nicename("Grenade Arc") grenade_arc; 
	float nicename("Grenade Force") grenade_force; 
	float nicename("Grenade Angle") grenade_angle; 
	float nicename("Grenade Velocity") grenade_velocity; 
	int16_t nicename("Grenade Type") grenade_type; 
	int16_t nicename("Grenade Count") grenade_count; 
	s_tag_block_definition<s_powered_seat_block_definition> nicename("Powered Seats") powered_seats_block; 
	s_tag_block_definition<s_weapon_block_definition> nicename("Weapons") weapons_block; 
	s_tag_block_definition<s_target_tracking_block_definition> nicename("Target Tracking") target_tracking_block; 
	s_tag_block_definition<s_seat_block_definition> nicename("Seats") seats_block; 
	float __unknown48; 
	float __unknown49; 
	float nicename("EMP Radius") emp_radius; 
	TagReference nicename("EMP Effect") emp_effect_reference; 
	TagReference nicename("Boost Collision Damage") boost_collision_damage_reference; 
	uint8_t nicename("Boost Flags") boost_flags; 
	int8_t __unknown50; 
	int8_t __unknown51; 
	int8_t __unknown52; 
	float nicename("Boost Peak Power") boost_peak_power; 
	float nicename("Boost Rise Power") boost_rise_power; 
	float nicename("Boost Fall Power") boost_fall_power; 
	float nicename("Boost Gauge Decay Rate") boost_gauge_decay_rate; 
	float nicename("Boost Gauge Recharge Delay") boost_gauge_recharge_delay; 
	float nicename("Boost Gauge Recharge Rate") boost_gauge_recharge_rate; 
	DataReference nicename("Boost Function") boost_function_data_reference; 
	float nicename("Lipsync Attack Weight") lipsync_attack_weight; 
	float nicename("Lipsync Decay Weight") lipsync_decay_weight; 
	TagReference nicename("Detach Damage") detach_damage_reference; 
	TagReference nicename("Detached Weapon") detached_weapon_reference; 
	// comment
	float nicename("Moving Turning Speed") moving_turning_speed; 
	int32_t nicename("Flags") flags3; 
	float nicename("Stationary Turning Speed") stationary_turning_speed; 
	TagReference nicename("Death Program") death_program_reference; 
	string_id __unknown53; 
	string_id nicename("Assassination String") assassination_string; 
	float nicename("Jump Velocity") jump_velocity; 
	s_tag_block_definition<s_trick_block_definition> nicename("Tricks") tricks_block; 
	Undefined32 __unknown54; 
	Undefined32 __unknown55; 
	Undefined32 __unknown56; 
	float nicename("Maximum Soft Landing Time") maximum_soft_landing_time; 
	float nicename("Maximum Hard Landing Time") maximum_hard_landing_time; 
	float nicename("Minimum Soft Landing Velocity") minimum_soft_landing_velocity; 
	float nicename("Minimum Hard Landing Velocity") minimum_hard_landing_velocity; 
	float nicename("Maximum Hard Landing Velocity") maximum_hard_landing_velocity; 
	float nicename("Stun Duration") stun_duration; 
	float nicename("Stationary Standing Camera Height") stationary_standing_camera_height; 
	float nicename("Moving Standing Camera Height") moving_standing_camera_height; 
	float nicename("Stationary Crouching Camera Height") stationary_crouching_camera_height; 
	float nicename("Moving Crouching Camera Height") moving_crouching_camera_height; 
	float nicename("Crouch Transition Time") crouch_transition_time; 
	DataReference nicename("Crouching Camera Function") crouching_camera_function_data_reference; 
	s_tag_block_definition<s_weapon_camera_height_block_definition> nicename("Weapon Camera Height") weapon_camera_height_block; 
	float nicename("Camera Interpolation Start") camera_interpolation_start; 
	float nicename("Camera Interpolation End") camera_interpolation_end; 
	float __unknown57; 
	float __unknown58; 
	float __unknown59; 
	float __unknown60; 
	float __unknown61; 
	float nicename("Autoaim Width") autoaim_width; 
	int16_t nicename("Physics Control Node Index") physics_control_node_index; 
	int16_t __unknown62; 
	float __unknown63; 
	float __unknown64; 
	float __unknown65; 
	int16_t nicename("Pelvis Node Index") pelvis_node_index; 
	int16_t nicename("Head Node Index") head_node_index; 
	s_tag_block_definition<s_unknown6_block_definition> __unknown66_block; 
	TagReference nicename("Area Damage Effect") area_damage_effect_reference; 
	TagReference nicename("Health Pickup Effect") health_pickup_effect_reference; 
	s_tag_block_definition<s_unknown7_block_definition> __unknown67_block; 
	s_tag_block_definition<s_unknown8_block_definition> __unknown68_block; 
	float __unknown69; 
	float __unknown70; 
	float __unknown71; 
	float __unknown72; 
	float __unknown73; 
	float __unknown74; 
	// comment
	int32_t nicename("Flags") flags4; 
	float nicename("Height Standing") height_standing; 
	float nicename("Height Crouching") height_crouching; 
	float nicename("Radius") radius; 
	float nicename("Mass") mass; 
	string_id nicename("Living Material Name") living_material_name; 
	string_id nicename("Dead Material Name") dead_material_name; 
	int16_t nicename("Living Global Material Index") living_global_material_index; 
	int16_t nicename("Dead Global Material Index") dead_global_material_index; 
	s_tag_block_definition<s_dead_sphere_shape_block_definition> nicename("Dead Sphere Shapes") dead_sphere_shapes_block; 
	s_tag_block_definition<s_pill_shape_block_definition> nicename("Pill Shapes") pill_shapes_block; 
	s_tag_block_definition<s_sphere_shape_block_definition> nicename("Sphere Shapes") sphere_shapes_block; 
	// comment
	float nicename("Maximum Slope Angle") maximum_slope_angle; 
	float nicename("Downhill Falloff Angle") downhill_falloff_angle; 
	float nicename("Downhill Cutoff Angle") downhill_cutoff_angle; 
	float nicename("Uphill Falloff Angle") uphill_falloff_angle; 
	float nicename("Uphill Cutoff Angle") uphill_cutoff_angle; 
	float nicename("Downhill Velocity Scale") downhill_velocity_scale; 
	float nicename("Uphill Velocity Scale") uphill_velocity_scale; 
	float __unknown75; 
	float __unknown76; 
	float __unknown77; 
	float __unknown78; 
	float __unknown79; 
	float __unknown80; 
	float __unknown81; 
	float nicename("Falling Velocity Scale") falling_velocity_scale; 
	float __unknown82; 
	float __unknown83; 
	// comment
	float nicename("Bank Angle") bank_angle; 
	float nicename("Bank Apply Time") bank_apply_time; 
	float nicename("Bank Decay Time") bank_decay_time; 
	float nicename("Pitch Ratio") pitch_ratio; 
	float nicename("Maximum Velocity") maximum_velocity; 
	float nicename("Maximum Sidestep Velocity") maximum_sidestep_velocity; 
	float nicename("Acceleration") acceleration; 
	float nicename("Deceleration") deceleration; 
	float nicename("Angular Velocity Maximum") angular_velocity_maximum; 
	float nicename("Angular Acceleration Maximum") angular_acceleration_maximum; 
	float nicename("Crouch Velocity Modifier") crouch_velocity_modifier; 
	Undefined32 __unknown84; 
	s_tag_block_definition<s_contact_point_block_definition> nicename("Contact Points") contact_points_block; 
	TagReference nicename("Reanimation Character") reanimation_character_reference; 
	TagReference nicename("Transformation Muffin") transformation_muffin_reference; 
	TagReference nicename("Death Spawn Character") death_spawn_character_reference; 
	int16_t nicename("Death Spawn Count") death_spawn_count; 
	int16_t __unknown85; 
	Undefined32 __unknown86; 
	float __unknown87; 
	float __unknown88; 
	float __unknown89; 
	float __unknown90; 
	float __unknown91; 
	float __unknown92; 
	Undefined32 __unknown93; 
	Undefined32 __unknown94; 
	Undefined32 __unknown95; 
	Undefined32 __unknown96; 
	Undefined32 __unknown97; 
	int32_t __unknown98; 
	float __unknown99; 
	float __unknown100; 
	float __unknown101; 
	float __unknown102; 
	float __unknown103; 
	float __unknown104; 
	float __unknown105; 
	float __unknown106; 
	float __unknown107; 
	float __unknown108; 
	float __unknown109; 
	float __unknown110; 
	float __unknown111; 
	float __unknown112; 
	float __unknown113; 
	float __unknown114; 
	float __unknown115; 
	float __unknown116; 
	float __unknown117; 
	float __unknown118; 
	float __unknown119; 
	float __unknown120; 
	float __unknown121; 
	float __unknown122; 
	float __unknown123; 
	float __unknown124; 
	float __unknown125; 
	float __unknown126; 
	float __unknown127; 

	struct nicename("early_mover_property") s_early_mover_property_block_definition
	{
		string_id nicename("Name") name; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
	};

	struct nicename("ai_property") s_ai_property_block_definition
	{
		int32_t nicename("Flags") flags; 
		string_id nicename("AI Type Name") ai_type_name; 
		Undefined32 __unknown; 
		int16_t nicename("Size") size; 
		int16_t nicename("Leap Jump Speed") leap_jump_speed; 
	};

	struct nicename("function") s_function_block_definition
	{
		struct s_unknown_block_definition;

		int32_t nicename("Flags") flags; 
		string_id nicename("Import Name") import_name; 
		string_id nicename("Export Name") export_name; 
		string_id nicename("Turn Off With") turn_off_with; 
		string_id __unknown; 
		float nicename("Minimum Value") minimum_value; 
		DataReference nicename("Default Function") default_function_data_reference; 
		string_id nicename("Scale By") scale_by; 
		s_tag_block_definition<s_unknown_block_definition> __unknown2_block; 
		int32_t nicename("'Function Related' Index") _function_related__index; 

		struct s_unknown_block_definition
		{
			int32_t __unknown; 
			float __unknown2; 
			float __unknown3; 
			Undefined32 __unknown4; 
			float __unknown5; 
			float __unknown6; 
		};
	};

	struct nicename("function_related") s_function_related_block_definition
	{
		int32_t nicename("Function Index") function_index; 
	};

	struct nicename("attachment") s_attachment_block_definition
	{
		TagReference nicename("Attachment") attachment_reference; 
		string_id nicename("Marker") marker; 
		int16_t nicename("Change Color") change_color; 
		int16_t __unknown; 
		string_id nicename("Primary Scale") primary_scale; 
		string_id nicename("Secondary Scale") secondary_scale; 
	};

	struct nicename("material_respons") s_material_respons_block_definition
	{
		struct s_unknown_block_definition;

		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		Undefined32 __unknown3; 
		s_tag_block_definition<s_unknown_block_definition> __unknown4_block; 

		struct s_unknown_block_definition
		{
			string_id nicename("Material") material; 
			DataReference __unknown_data_reference; 
			float __unknown2; 
			DataReference __unknown3_data_reference; 
			float __unknown4; 
			Undefined32 __unknown5; 
			Undefined32 __unknown6; 
		};
	};

	struct nicename("jet_wash") s_jet_wash_block_definition
	{
		string_id nicename("Marker") marker; 
		float __unknown; 
		Undefined32 __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
	};

	struct nicename("widget") s_widget_block_definition
	{
		TagReference nicename("Type") type_reference; 
	};

	struct nicename("change_color") s_change_color_block_definition
	{
		struct nicename("Initial Permutations") s_initial_permutation_block_definition;
		struct nicename("Functions") s_function_block_definition;

		s_tag_block_definition<s_initial_permutation_block_definition> nicename("Initial Permutations") initial_permutations_block; 
		s_tag_block_definition<s_function_block_definition> nicename("Functions") functions_block; 

		struct nicename("initial_permutation") s_initial_permutation_block_definition
		{
			float nicename("Weight") weight; 
			float nicename("Color Lower Bound r") color_lower_bound_r; 
			float nicename("Color Lower Bound g") color_lower_bound_g; 
			float nicename("Color Lower Bound b") color_lower_bound_b; 
			float nicename("Color Upper Bound r") color_upper_bound_r; 
			float nicename("Color Upper Bound g") color_upper_bound_g; 
			float nicename("Color Upper Bound b") color_upper_bound_b; 
			string_id nicename("Variant Name") variant_name; 
		};

		struct nicename("function") s_function_block_definition
		{
			int32_t nicename("Scale Flags") scale_flags; 
			float nicename("Color Lower Bound r") color_lower_bound_r; 
			float nicename("Color Lower Bound g") color_lower_bound_g; 
			float nicename("Color Lower Bound b") color_lower_bound_b; 
			float nicename("Color Upper Bound r") color_upper_bound_r; 
			float nicename("Color Upper Bound g") color_upper_bound_g; 
			float nicename("Color Upper Bound b") color_upper_bound_b; 
			string_id nicename("Darken By...") darken_by; 
			string_id nicename("Scale By...") scale_by; 
		};
	};

	struct nicename("predicted_resource") s_predicted_resource_block_definition
	{
		int16_t nicename("Type") type; 
		int16_t nicename("Resource Index") resource_index; 
		unsigned int nicename("Tag Index") tag_index; 
	};

	struct nicename("multiplayer_object_property") s_multiplayer_object_property_block_definition
	{
		int8_t __unknown; 
		int8_t nicename("Object Type") object_type; 
		uint8_t nicename("Teleporter Flags") teleporter_flags; 
		int8_t __unknown2; 
		float nicename("Radius/Width") radius_width; 
		float nicename("Length") length; 
		float nicename("Top") top; 
		float nicename("Bottom") bottom; 
		int8_t nicename("Shape") shape; 
		int8_t nicename("Spawn Timer Mode") spawn_timer_mode; 
		int16_t nicename("Spawn Time") spawn_time; 
		int16_t nicename("Abandon Time") abandon_time; 
		uint16_t nicename("Flags") flags; 
		float __unknown3; 
		int32_t __unknown4; 
		int32_t __unknown5; 
		TagReference nicename("Child Object") child_object_reference; 
		int32_t __unknown6; 
		TagReference nicename("Shape Shader") shape_shader_reference; 
		TagReference nicename("Shader 2") shader_2_reference; 
		TagReference __unknown7_reference; 
		TagReference __unknown8_reference; 
		TagReference nicename("Secondary Shader") secondary_shader_reference; 
		TagReference __unknown9_reference; 
		TagReference __unknown10_reference; 
		TagReference __unknown11_reference; 
	};

	struct s_unknown_block_definition
	{
		TagReference __unknown_reference; 
		TagReference __unknown2_reference; 
		TagReference __unknown3_reference; 
	};

	struct nicename("metagame_property") s_metagame_property_block_definition
	{
		uint8_t nicename("Flags") flags; 
		int8_t nicename("Unit") unit; 
		int8_t nicename("Classification") classification; 
		int8_t __unknown; 
		int16_t nicename("Points") points; 
		int16_t __unknown2; 
	};

	struct nicename("unit_screen_effect") s_unit_screen_effect_block_definition
	{
		TagReference nicename("Screen Effect") screen_effect_reference; 
	};

	struct nicename("camera_track") s_camera_track_block_definition
	{
		TagReference nicename("Track") track_reference; 
		TagReference nicename("Screen Effect") screen_effect_reference; 
	};

	struct s_unknown2_block_definition
	{
		float __unknown; 
		Undefined32 __unknown2; 
		DataReference __unknown3_data_reference; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
		int16_t __unknown7; 
		int16_t __unknown8; 
		DataReference __unknown9_data_reference; 
		float __unknown10; 
		float __unknown11; 
		float __unknown12; 
		int16_t __unknown13; 
		int16_t __unknown14; 
		DataReference __unknown15_data_reference; 
		float __unknown16; 
		float __unknown17; 
		float __unknown18; 
	};

	struct s_unknown3_block_definition
	{
		struct s_unknown_block_definition;

		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		float __unknown9; 
		float __unknown10; 
		s_tag_block_definition<s_unknown_block_definition> __unknown11_block; 

		struct s_unknown_block_definition
		{
			DataReference nicename("Function") function_data_reference; 
		};
	};

	struct nicename("space_fighter_camera") s_space_fighter_camera_block_definition
	{
		struct s_unknown_block_definition;

		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		float __unknown9; 
		float __unknown10; 
		s_tag_block_definition<s_unknown_block_definition> __unknown11_block; 

		struct s_unknown_block_definition
		{
			DataReference nicename("Function") function_data_reference; 
		};
	};

	struct nicename("camera_track2") s_camera_track2_block_definition
	{
		TagReference nicename("Track") track_reference; 
		TagReference nicename("Screen Effect") screen_effect_reference; 
	};

	struct s_unknown4_block_definition
	{
		float __unknown; 
		Undefined32 __unknown2; 
		DataReference __unknown3_data_reference; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
		int16_t __unknown7; 
		int16_t __unknown8; 
		DataReference __unknown9_data_reference; 
		float __unknown10; 
		float __unknown11; 
		float __unknown12; 
		int16_t __unknown13; 
		int16_t __unknown14; 
		DataReference __unknown15_data_reference; 
		float __unknown16; 
		float __unknown17; 
		float __unknown18; 
	};

	struct s_unknown5_block_definition
	{
		struct s_unknown_block_definition;

		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		float __unknown9; 
		float __unknown10; 
		s_tag_block_definition<s_unknown_block_definition> __unknown11_block; 

		struct s_unknown_block_definition
		{
			DataReference nicename("Function") function_data_reference; 
		};
	};

	struct nicename("space_fighter_camera2") s_space_fighter_camera2_block_definition
	{
		struct s_unknown_block_definition;

		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		float __unknown9; 
		float __unknown10; 
		s_tag_block_definition<s_unknown_block_definition> __unknown11_block; 

		struct s_unknown_block_definition
		{
			DataReference nicename("Function") function_data_reference; 
		};
	};

	struct nicename("posture") s_posture_block_definition
	{
		string_id nicename("Name") name; 
		float nicename("Pill Offset I") pill_offset_i; 
		float nicename("Pill Offset J") pill_offset_j; 
		float nicename("Pill Offset K") pill_offset_k; 
	};

	struct nicename("hud_interface") s_hud_interface_block_definition
	{
		TagReference nicename("Unit HUD Interface") unit_hud_interface_reference; 
	};

	struct nicename("dialogue_variant") s_dialogue_variant_block_definition
	{
		int16_t nicename("Variant Number") variant_number; 
		int16_t __unknown; 
		TagReference nicename("Dialogue") dialogue_reference; 
	};

	struct nicename("powered_seat") s_powered_seat_block_definition
	{
		float nicename("Driver Powerup Time") driver_powerup_time; 
		float nicename("Driver Powerdown Time") driver_powerdown_time; 
	};

	struct nicename("weapon") s_weapon_block_definition
	{
		TagReference nicename("Weapon") weapon_reference; 
		string_id nicename("Parent Marker") parent_marker; 
	};

	struct nicename("target_tracking") s_target_tracking_block_definition
	{
		struct nicename("Tracking Types") s_tracking_type_block_definition;

		s_tag_block_definition<s_tracking_type_block_definition> nicename("Tracking Types") tracking_types_block; 
		float nicename("Acquire Time") acquire_time; 
		float nicename("Grace Time") grace_time; 
		float nicename("Decay Time") decay_time; 
		TagReference nicename("Tracking Sound") tracking_sound_reference; 
		TagReference nicename("Locked Sound") locked_sound_reference; 

		struct nicename("tracking_type") s_tracking_type_block_definition
		{
			string_id nicename("Tracking Type") tracking_type; 
		};
	};

	struct nicename("seat") s_seat_block_definition
	{
		struct nicename("Camera Tracks") s_camera_track_block_definition;
		struct s_unknown_block_definition;
		struct s_unknown2_block_definition;
		struct nicename("Space Fighter Camera") s_space_fighter_camera_block_definition;
		struct nicename("Unit HUD Interface") s_unit_hud_interface_block_definition;

		int32_t nicename("Flags") flags; 
		string_id nicename("Seat Animation") seat_animation; 
		string_id nicename("Seat Marker Name") seat_marker_name; 
		string_id nicename("Entry Marker(s) Name") entry_markers_name; 
		string_id nicename("Boarding Grenade Marker") boarding_grenade_marker; 
		string_id nicename("Boarding Grenade String") boarding_grenade_string; 
		string_id nicename("Boarding Melee String") boarding_melee_string; 
		string_id nicename("Detach Weapon String") detach_weapon_string; 
		float nicename("Ping Scale") ping_scale; 
		float nicename("Turnover Time") turnover_time; 
		TagReference nicename("Spring Acceleration") spring_acceleration_reference; 
		float nicename("AI Scariness") ai_scariness; 
		int16_t nicename("AI Seat Type") ai_seat_type; 
		int16_t nicename("Boarding Seat") boarding_seat; 
		Undefined32 __block_here; 
		Undefined32 __block_here2; 
		Undefined32 __block_here3; 
		float nicename("Listener Interpolation Factor") listener_interpolation_factor; 
		float nicename("Yaw Rate Bounds min") yaw_rate_bounds_min; 
		float nicename("Yaw Rate Bounds max") yaw_rate_bounds_max; 
		float nicename("Pitch Rate Bounds min") pitch_rate_bounds_min; 
		float nicename("Pitch Rate Bounds max") pitch_rate_bounds_max; 
		float __unknown; 
		float nicename("Minimum Speed Reference") minimum_speed_reference; 
		float nicename("Maximum Speed Reference") maximum_speed_reference; 
		float nicename("Speed Exponent") speed_exponent; 
		uint8_t nicename("Camera Flags") camera_flags; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t __unknown4; 
		string_id nicename("Camera Marker") camera_marker; 
		float nicename("Pitch Auto-Level") pitch_auto_level; 
		float nicename("Pitch Range min") pitch_range_min; 
		float nicename("Pitch Range max") pitch_range_max; 
		s_tag_block_definition<s_camera_track_block_definition> nicename("Camera Tracks") camera_tracks_block; 
		float nicename("Camera Stiffness min") camera_stiffness_min; 
		float nicename("Camera Stiffness max") camera_stiffness_max; 
		float __unknown5; 
		float nicename("Camera Acceleration Speed") camera_acceleration_speed; 
		float nicename("Camera Deceleration Speed") camera_deceleration_speed; 
		float __unknown6; 
		float nicename("Camera Field Of View") camera_field_of_view; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
		Undefined32 __unknown11; 
		Undefined32 __unknown12; 
		s_tag_block_definition<s_unknown_block_definition> __unknown13_block; 
		s_tag_block_definition<s_unknown2_block_definition> __unknown14_block; 
		s_tag_block_definition<s_space_fighter_camera_block_definition> nicename("Space Fighter Camera") space_fighter_camera_block; 
		s_tag_block_definition<s_unit_hud_interface_block_definition> nicename("Unit HUD Interface") unit_hud_interface_block; 
		string_id nicename("Enter Seat String") enter_seat_string; 
		float nicename("Yaw Range min") yaw_range_min; 
		float nicename("Yaw Range max") yaw_range_max; 
		TagReference nicename("Built-In Gunner") built_in_gunner_reference; 
		float nicename("Entry Radius") entry_radius; 
		float nicename("Entry Marker Cone Angle") entry_marker_cone_angle; 
		float nicename("Entry Marker Facing Angle") entry_marker_facing_angle; 
		float nicename("Maximum Relative Velocity") maximum_relative_velocity; 
		float nicename("Powered Off Animation Speed") powered_off_animation_speed; 
		float nicename("Powered On Animation Speed") powered_on_animation_speed; 
		string_id nicename("Open Animation") open_animation; 
		string_id nicename("Opening Animation") opening_animation; 
		string_id nicename("Closing Animation") closing_animation; 
		string_id nicename("Invisible Seat Region") invisible_seat_region; 
		int32_t nicename("Runtime Invisible Seat Region Index") runtime_invisible_seat_region_index; 

		struct nicename("camera_track") s_camera_track_block_definition
		{
			TagReference nicename("Track") track_reference; 
			TagReference nicename("Screen Effect") screen_effect_reference; 
		};

		struct s_unknown_block_definition
		{
			float __unknown; 
			Undefined32 __unknown2; 
			DataReference __unknown3_data_reference; 
			float __unknown4; 
			float __unknown5; 
			float __unknown6; 
			int16_t __unknown7; 
			int16_t __unknown8; 
			DataReference __unknown9_data_reference; 
			float __unknown10; 
			float __unknown11; 
			float __unknown12; 
			int16_t __unknown13; 
			int16_t __unknown14; 
			DataReference __unknown15_data_reference; 
			float __unknown16; 
			float __unknown17; 
			float __unknown18; 
		};

		struct s_unknown2_block_definition
		{
			struct s_unknown_block_definition;

			int8_t __unknown; 
			int8_t __unknown2; 
			int8_t __unknown3; 
			int8_t __unknown4; 
			float __unknown5; 
			float __unknown6; 
			float __unknown7; 
			float __unknown8; 
			float __unknown9; 
			float __unknown10; 
			s_tag_block_definition<s_unknown_block_definition> __unknown11_block; 

			struct s_unknown_block_definition
			{
				DataReference nicename("Function") function_data_reference; 
			};
		};

		struct nicename("space_fighter_camera") s_space_fighter_camera_block_definition
		{
			struct s_unknown_block_definition;

			int8_t __unknown; 
			int8_t __unknown2; 
			int8_t __unknown3; 
			int8_t __unknown4; 
			float __unknown5; 
			float __unknown6; 
			float __unknown7; 
			float __unknown8; 
			float __unknown9; 
			float __unknown10; 
			s_tag_block_definition<s_unknown_block_definition> __unknown11_block; 

			struct s_unknown_block_definition
			{
				DataReference nicename("Function") function_data_reference; 
			};
		};

		struct nicename("unit_hud_interface") s_unit_hud_interface_block_definition
		{
			TagReference nicename("Unit HUD Interface") unit_hud_interface_reference; 
		};
	};

	struct nicename("trick") s_trick_block_definition
	{
		string_id nicename("Name") name; 
		int8_t nicename("Initiate Direction") initiate_direction; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		float __unknown4; 
		Undefined32 __distance_traveled; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		Undefined32 __cooldown_time; 
	};

	struct nicename("weapon_camera_height") s_weapon_camera_height_block_definition
	{
		string_id nicename("Class") $class; 
		float nicename("Standing Height Fraction") standing_height_fraction; 
		float nicename("Crouching Height Fraction") crouching_height_fraction; 
	};

	struct s_unknown6_block_definition
	{
		string_id __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		Undefined32 __unknown5; 
		string_id __unknown6; 
	};

	struct s_unknown7_block_definition
	{
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		DataReference nicename("Function") function_data_reference; 
	};

	struct s_unknown8_block_definition
	{
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		DataReference nicename("Function") function_data_reference; 
	};

	struct nicename("dead_sphere_shape") s_dead_sphere_shape_block_definition
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

	struct nicename("pill_shape") s_pill_shape_block_definition
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

	struct nicename("sphere_shape") s_sphere_shape_block_definition
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

	struct nicename("contact_point") s_contact_point_block_definition
	{
		string_id nicename("Marker Name") marker_name; 
	};
};
