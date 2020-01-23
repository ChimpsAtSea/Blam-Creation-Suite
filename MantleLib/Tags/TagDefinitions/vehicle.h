#pragma once

struct nicename("Vehicle") group('vehi') s_vehicle_definition
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
	struct nicename("Tank Engine Motion Properties") s_tank_engine_motion_property_block_definition;
	struct nicename("Engine Motion Properties") s_engine_motion_property_block_definition;
	struct nicename("Dropship Motion Properties") s_dropship_motion_property_block_definition;
	struct nicename("Antigravity Motion Properties") s_antigravity_motion_property_block_definition;
	struct nicename("Jet Engine Motion Properties") s_jet_engine_motion_property_block_definition;
	struct nicename("Turret Properties") s_turret_property_block_definition;
	struct nicename("Helicopter Motion Properties") s_helicopter_motion_property_block_definition;
	struct nicename("Space Fighter Motion Properties") s_space_fighter_motion_property_block_definition;
	struct nicename("Anti Gravity Points") s_anti_gravity_point_block_definition;
	struct nicename("Friction Points") s_friction_point_block_definition;
	struct nicename("Tricks") s_trick_block_definition;

	signed short nicename("Object Type") object_type; 
	signed short __unknown; 
	signed int nicename("Flags") flags; 
	float nicename("Bounding Radius") bounding_radius; 
	float nicename("Bounding Offset X") bounding_offset_x; 
	float nicename("Bounding Offset Y") bounding_offset_y; 
	float nicename("Bounding Offset Z") bounding_offset_z; 
	float nicename("Horizontal Acceleration Scale") horizontal_acceleration_scale; 
	float nicename("Vertical Acceleration Scale") vertical_acceleration_scale; 
	float nicename("Angular Acceleration Scale") angular_acceleration_scale; 
	signed short nicename("Lightmap Shadow Mode Size") lightmap_shadow_mode_size; 
	signed char nicename("Sweetener Size") sweetener_size; 
	signed char nicename("Water Density") water_density; 
	signed int __unknown2; 
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
	signed short nicename("HUD Text Message Index") hud_text_message_index; 
	signed short __unknown3; 
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
	signed int nicename("Flags") flags2; 
	signed short nicename("Team") team; 
	signed short nicename("Constant Sound Volume") constant_sound_volume; 
	TagReference nicename("Hologram Unit") hologram_unit_reference; 
	s_tag_block_definition<s_metagame_property_block_definition> nicename("Metagame Properties") metagame_properties_block; 
	s_tag_block_definition<s_unit_screen_effect_block_definition> nicename("Unit Screen Effects") unit_screen_effects_block; 
	signed int __unknown5; 
	// comment
	unsigned char nicename("Camera Flags") camera_flags; 
	signed char __unknown6; 
	signed char __unknown7; 
	signed char __unknown8; 
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
	Unknown32 __unknown11; 
	Unknown32 __unknown12; 
	Unknown32 __unknown13; 
	Unknown32 __unknown14; 
	Unknown32 __unknown15; 
	Unknown32 __unknown16; 
	s_tag_block_definition<s_unknown2_block_definition> __unknown17_block; 
	s_tag_block_definition<s_unknown3_block_definition> __unknown18_block; 
	s_tag_block_definition<s_space_fighter_camera_block_definition> nicename("Space Fighter Camera") space_fighter_camera_block; 
	// comment
	unsigned char nicename("Camera Flags") camera_flags2; 
	signed char __unknown19; 
	signed char __unknown20; 
	signed char __unknown21; 
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
	Unknown32 __unknown24; 
	Unknown32 __unknown25; 
	Unknown32 __unknown26; 
	Unknown32 __unknown27; 
	Unknown32 __unknown28; 
	Unknown32 __unknown29; 
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
	Unknown32 __unknown37; 
	Unknown32 __unknown38; 
	float __unknown39; 
	Unknown32 __unknown40; 
	float __unknown41; 
	float __unknown42; 
	float __unknown43; 
	Unknown32 __unknown44; 
	float __unknown45; 
	float nicename("Feign Death Chance") feign_death_chance; 
	float nicename("Feign Repeat Chance") feign_repeat_chance; 
	TagReference nicename("Spawned Turret Character") spawned_turret_character_reference; 
	signed short nicename("Spawned Actor Count min") spawned_actor_count_min; 
	signed short nicename("Spawned Actor Count max") spawned_actor_count_max; 
	float nicename("Spawned Velocity") spawned_velocity; 
	string_id nicename("Aiming Pivot Marker") aiming_pivot_marker; 
	float nicename("Aiming Velocity Maximum") aiming_velocity_maximum; 
	float nicename("Aiming Acceleration Maximum") aiming_acceleration_maximum; 
	float nicename("Casual Aiming Modifier") casual_aiming_modifier; 
	float nicename("Looking Velocity Maximum") looking_velocity_maximum; 
	float nicename("Looking Acceleration Maximum") looking_acceleration_maximum; 
	Unknown32 __unknown46; 
	string_id nicename("Right Hand Node") right_hand_node; 
	string_id nicename("Left Hand Node") left_hand_node; 
	string_id nicename("Preferred Gun Node") preferred_gun_node; 
	string_id nicename("Preferred Grenade Node") preferred_grenade_node; 
	Unknown32 __unknown47; 
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
	signed short nicename("Motion Sensor Blip Size") motion_sensor_blip_size; 
	signed short nicename("Item Scale") item_scale; 
	string_id nicename("Equipment Variant") equipment_variant; 
	string_id nicename("Dropped Equipment Variant") dropped_equipment_variant; 
	s_tag_block_definition<s_posture_block_definition> nicename("Postures") postures_block; 
	s_tag_block_definition<s_hud_interface_block_definition> nicename("HUD Interfaces") hud_interfaces_block; 
	s_tag_block_definition<s_dialogue_variant_block_definition> nicename("Dialogue Variants") dialogue_variants_block; 
	float nicename("Grenade Arc") grenade_arc; 
	float nicename("Grenade Force") grenade_force; 
	float nicename("Grenade Angle") grenade_angle; 
	float nicename("Grenade Velocity") grenade_velocity; 
	signed short nicename("Grenade Type") grenade_type; 
	signed short nicename("Grenade Count") grenade_count; 
	s_tag_block_definition<s_powered_seat_block_definition> nicename("Powered Seats") powered_seats_block; 
	s_tag_block_definition<s_weapon_block_definition> nicename("Weapons") weapons_block; 
	s_tag_block_definition<s_target_tracking_block_definition> nicename("Target Tracking") target_tracking_block; 
	s_tag_block_definition<s_seat_block_definition> nicename("Seats") seats_block; 
	float __unknown48; 
	float __unknown49; 
	float nicename("EMP Radius") emp_radius; 
	TagReference nicename("EMP Effect") emp_effect_reference; 
	TagReference nicename("Boost Collision Damage") boost_collision_damage_reference; 
	unsigned char nicename("Boost Flags") boost_flags; 
	signed char __unknown50; 
	signed char __unknown51; 
	signed char __unknown52; 
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
	signed int nicename("Flags") flags3; 
	s_tag_block_definition<s_tank_engine_motion_property_block_definition> nicename("Tank Engine Motion Properties") tank_engine_motion_properties_block; 
	s_tag_block_definition<s_engine_motion_property_block_definition> nicename("Engine Motion Properties") engine_motion_properties_block; 
	s_tag_block_definition<s_dropship_motion_property_block_definition> nicename("Dropship Motion Properties") dropship_motion_properties_block; 
	Unknown32 __unknown53; 
	Unknown32 __unknown54; 
	Unknown32 __unknown55; 
	s_tag_block_definition<s_antigravity_motion_property_block_definition> nicename("Antigravity Motion Properties") antigravity_motion_properties_block; 
	s_tag_block_definition<s_jet_engine_motion_property_block_definition> nicename("Jet Engine Motion Properties") jet_engine_motion_properties_block; 
	s_tag_block_definition<s_turret_property_block_definition> nicename("Turret Properties") turret_properties_block; 
	Unknown32 __unknown56; 
	Unknown32 __unknown57; 
	Unknown32 __unknown58; 
	s_tag_block_definition<s_helicopter_motion_property_block_definition> nicename("Helicopter Motion Properties") helicopter_motion_properties_block; 
	Unknown32 __unknown59; 
	Unknown32 __unknown60; 
	Unknown32 __unknown61; 
	Unknown32 __unknown62; 
	Unknown32 __unknown63; 
	Unknown32 __unknown64; 
	Unknown32 __unknown65; 
	Unknown32 __unknown66; 
	Unknown32 __unknown67; 
	Unknown32 __unknown68; 
	Unknown32 __unknown69; 
	Unknown32 __unknown70; 
	s_tag_block_definition<s_space_fighter_motion_property_block_definition> nicename("Space Fighter Motion Properties") space_fighter_motion_properties_block; 
	Unknown32 __unknown71; 
	Unknown32 __unknown72; 
	Unknown32 __unknown73; 
	// comment
	signed int nicename("Flags") flags4; 
	float nicename("Ground Friction") ground_friction; 
	float nicename("Ground Depth") ground_depth; 
	float nicename("Ground Damp Factor") ground_damp_factor; 
	float nicename("Ground Moving Friction") ground_moving_friction; 
	float nicename("Ground Maximum Slope 0") ground_maximum_slope_0; 
	float nicename("Ground Maximum Slope 1 (Less Than Slope 0)") ground_maximum_slope_1_less_than_slope_0; 
	float __unknown74; 
	float nicename("Anti Gravity Bank Lift") anti_gravity_bank_lift; 
	float nicename("Steering Bank Reaction Scale") steering_bank_reaction_scale; 
	float nicename("Gravity Scale") gravity_scale; 
	signed short __unknown75; 
	signed short __unknown76; 
	signed int nicename("Flags 2") flags_2; 
	signed int __unknown77; 
	s_tag_block_definition<s_anti_gravity_point_block_definition> nicename("Anti Gravity Points") anti_gravity_points_block; 
	s_tag_block_definition<s_friction_point_block_definition> nicename("Friction Points") friction_points_block; 
	Unknown32 __unknown78; 
	s_tag_block_definition<s_trick_block_definition> nicename("Tricks") tricks_block; 
	signed char nicename("Player Training Vehicle Type") player_training_vehicle_type; 
	signed char nicename("Vehicle Size") vehicle_size; 
	signed char __unknown79; 
	signed char __unknown80; 
	float nicename("Minimum Flipping Angular Velocity") minimum_flipping_angular_velocity; 
	float nicename("Maximum Flipping Angular Velocity") maximum_flipping_angular_velocity; 
	Unknown32 __unknown81; 
	float __unknown82; 
	float nicename("Seat Entrance Acceleration Scale") seat_entrance_acceleration_scale; 
	float nicename("Seat Exit Acceleration Scale") seat_exit_acceleration_scale; 
	float nicename("Flip Time") flip_time; 
	string_id nicename("Flip Over Message") flip_over_message; 
	TagReference nicename("Suspension Sound") suspension_sound_reference; 
	TagReference nicename("Running Effect") running_effect_reference; 
	TagReference __unknown_response_reference; 
	TagReference __unknown_response2_reference; 

	struct nicename("early_mover_property") s_early_mover_property_block_definition
	{
		string_id nicename("Name") name; 
		Unknown32 __unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
		Unknown32 __unknown5; 
		Unknown32 __unknown6; 
		Unknown32 __unknown7; 
		Unknown32 __unknown8; 
		Unknown32 __unknown9; 
		Unknown32 __unknown10; 
	};

	struct nicename("ai_property") s_ai_property_block_definition
	{
		signed int nicename("Flags") flags; 
		string_id nicename("AI Type Name") ai_type_name; 
		Unknown32 __unknown; 
		signed short nicename("Size") size; 
		signed short nicename("Leap Jump Speed") leap_jump_speed; 
	};

	struct nicename("function") s_function_block_definition
	{
		struct s_unknown_block_definition;

		signed int nicename("Flags") flags; 
		string_id nicename("Import Name") import_name; 
		string_id nicename("Export Name") export_name; 
		string_id nicename("Turn Off With") turn_off_with; 
		string_id __unknown; 
		float nicename("Minimum Value") minimum_value; 
		DataReference nicename("Default Function") default_function_data_reference; 
		string_id nicename("Scale By") scale_by; 
		s_tag_block_definition<s_unknown_block_definition> __unknown2_block; 
		signed int nicename("'Function Related' Index") _function_related__index; 

		struct s_unknown_block_definition
		{
			signed int __unknown; 
			float __unknown2; 
			float __unknown3; 
			Unknown32 __unknown4; 
			float __unknown5; 
			float __unknown6; 
		};
	};

	struct nicename("function_related") s_function_related_block_definition
	{
		signed int nicename("Function Index") function_index; 
	};

	struct nicename("attachment") s_attachment_block_definition
	{
		TagReference nicename("Attachment") attachment_reference; 
		string_id nicename("Marker") marker; 
		signed short nicename("Change Color") change_color; 
		signed short __unknown; 
		string_id nicename("Primary Scale") primary_scale; 
		string_id nicename("Secondary Scale") secondary_scale; 
	};

	struct nicename("material_respons") s_material_respons_block_definition
	{
		struct s_unknown_block_definition;

		Unknown32 __unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		s_tag_block_definition<s_unknown_block_definition> __unknown4_block; 

		struct s_unknown_block_definition
		{
			string_id nicename("Material") material; 
			DataReference __unknown_data_reference; 
			float __unknown2; 
			DataReference __unknown3_data_reference; 
			float __unknown4; 
			Unknown32 __unknown5; 
			Unknown32 __unknown6; 
		};
	};

	struct nicename("jet_wash") s_jet_wash_block_definition
	{
		string_id nicename("Marker") marker; 
		float __unknown; 
		Unknown32 __unknown2; 
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
			signed int nicename("Scale Flags") scale_flags; 
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
		signed short nicename("Type") type; 
		signed short nicename("Resource Index") resource_index; 
		unsigned int nicename("Tag Index") tag_index; 
	};

	struct nicename("multiplayer_object_property") s_multiplayer_object_property_block_definition
	{
		signed char __unknown; 
		signed char nicename("Object Type") object_type; 
		unsigned char nicename("Teleporter Flags") teleporter_flags; 
		signed char __unknown2; 
		float nicename("Radius/Width") radius_width; 
		float nicename("Length") length; 
		float nicename("Top") top; 
		float nicename("Bottom") bottom; 
		signed char nicename("Shape") shape; 
		signed char nicename("Spawn Timer Mode") spawn_timer_mode; 
		signed short nicename("Spawn Time") spawn_time; 
		signed short nicename("Abandon Time") abandon_time; 
		unsigned short nicename("Flags") flags; 
		float __unknown3; 
		signed int __unknown4; 
		signed int __unknown5; 
		TagReference nicename("Child Object") child_object_reference; 
		signed int __unknown6; 
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
		unsigned char nicename("Flags") flags; 
		signed char nicename("Unit") unit; 
		signed char nicename("Classification") classification; 
		signed char __unknown; 
		signed short nicename("Points") points; 
		signed short __unknown2; 
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
		Unknown32 __unknown2; 
		DataReference __unknown3_data_reference; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
		signed short __unknown7; 
		signed short __unknown8; 
		DataReference __unknown9_data_reference; 
		float __unknown10; 
		float __unknown11; 
		float __unknown12; 
		signed short __unknown13; 
		signed short __unknown14; 
		DataReference __unknown15_data_reference; 
		float __unknown16; 
		float __unknown17; 
		float __unknown18; 
	};

	struct s_unknown3_block_definition
	{
		struct s_unknown_block_definition;

		signed char __unknown; 
		signed char __unknown2; 
		signed char __unknown3; 
		signed char __unknown4; 
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

		signed char __unknown; 
		signed char __unknown2; 
		signed char __unknown3; 
		signed char __unknown4; 
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
		Unknown32 __unknown2; 
		DataReference __unknown3_data_reference; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
		signed short __unknown7; 
		signed short __unknown8; 
		DataReference __unknown9_data_reference; 
		float __unknown10; 
		float __unknown11; 
		float __unknown12; 
		signed short __unknown13; 
		signed short __unknown14; 
		DataReference __unknown15_data_reference; 
		float __unknown16; 
		float __unknown17; 
		float __unknown18; 
	};

	struct s_unknown5_block_definition
	{
		struct s_unknown_block_definition;

		signed char __unknown; 
		signed char __unknown2; 
		signed char __unknown3; 
		signed char __unknown4; 
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

		signed char __unknown; 
		signed char __unknown2; 
		signed char __unknown3; 
		signed char __unknown4; 
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
		signed short nicename("Variant Number") variant_number; 
		signed short __unknown; 
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

		signed int nicename("Flags") flags; 
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
		signed short nicename("AI Seat Type") ai_seat_type; 
		signed short nicename("Boarding Seat") boarding_seat; 
		Unknown32 __block_here; 
		Unknown32 __block_here2; 
		Unknown32 __block_here3; 
		float nicename("Listener Interpolation Factor") listener_interpolation_factor; 
		float nicename("Yaw Rate Bounds min") yaw_rate_bounds_min; 
		float nicename("Yaw Rate Bounds max") yaw_rate_bounds_max; 
		float nicename("Pitch Rate Bounds min") pitch_rate_bounds_min; 
		float nicename("Pitch Rate Bounds max") pitch_rate_bounds_max; 
		float __unknown; 
		float nicename("Minimum Speed Reference") minimum_speed_reference; 
		float nicename("Maximum Speed Reference") maximum_speed_reference; 
		float nicename("Speed Exponent") speed_exponent; 
		unsigned char nicename("Camera Flags") camera_flags; 
		signed char __unknown2; 
		signed char __unknown3; 
		signed char __unknown4; 
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
		Unknown32 __unknown7; 
		Unknown32 __unknown8; 
		Unknown32 __unknown9; 
		Unknown32 __unknown10; 
		Unknown32 __unknown11; 
		Unknown32 __unknown12; 
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
		signed int nicename("Runtime Invisible Seat Region Index") runtime_invisible_seat_region_index; 

		struct nicename("camera_track") s_camera_track_block_definition
		{
			TagReference nicename("Track") track_reference; 
			TagReference nicename("Screen Effect") screen_effect_reference; 
		};

		struct s_unknown_block_definition
		{
			float __unknown; 
			Unknown32 __unknown2; 
			DataReference __unknown3_data_reference; 
			float __unknown4; 
			float __unknown5; 
			float __unknown6; 
			signed short __unknown7; 
			signed short __unknown8; 
			DataReference __unknown9_data_reference; 
			float __unknown10; 
			float __unknown11; 
			float __unknown12; 
			signed short __unknown13; 
			signed short __unknown14; 
			DataReference __unknown15_data_reference; 
			float __unknown16; 
			float __unknown17; 
			float __unknown18; 
		};

		struct s_unknown2_block_definition
		{
			struct s_unknown_block_definition;

			signed char __unknown; 
			signed char __unknown2; 
			signed char __unknown3; 
			signed char __unknown4; 
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

			signed char __unknown; 
			signed char __unknown2; 
			signed char __unknown3; 
			signed char __unknown4; 
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

	struct nicename("tank_engine_motion_property") s_tank_engine_motion_property_block_definition
	{
		struct nicename("Gears") s_gear_block_definition;
		struct nicename("Braking") s_braking_block_definition;

		float nicename("Steering Overdampen Cusp Angle 1") steering_overdampen_cusp_angle_1; 
		float nicename("Steering Overdampen Cusp Angle 2") steering_overdampen_cusp_angle_2; 
		float nicename("Steering Overdamen Exponent") steering_overdamen_exponent; 
		float __unknown; 
		float nicename("Turn Rate") turn_rate; 
		float nicename("Speed Back") speed_back; 
		float nicename("Speed Left") speed_left; 
		float nicename("Speed Right") speed_right; 
		float nicename("Turning Speed Right") turning_speed_right; 
		float nicename("Turning Speed Left") turning_speed_left; 
		float nicename("Speed Left 2") speed_left_2; 
		float nicename("Speed Right 2") speed_right_2; 
		float nicename("Turning Speed Right 2") turning_speed_right_2; 
		float nicename("Turning Speed Left 2") turning_speed_left_2; 
		float nicename("Engine Momentum") engine_momentum; 
		float nicename("Engine Maximum Angular Velocity") engine_maximum_angular_velocity; 
		s_tag_block_definition<s_gear_block_definition> nicename("Gears") gears_block; 
		TagReference nicename("Change Gear Sound") change_gear_sound_reference; 
		s_tag_block_definition<s_braking_block_definition> nicename("Braking") braking_block; 
		float __unknown2; 
		float __unknown3; 

		struct nicename("gear") s_gear_block_definition
		{
			DataReference nicename("Loaded Torque Function") loaded_torque_function_data_reference; 
			Unknown32 __unknown; 
			DataReference nicename("Cruising Torque Function") cruising_torque_function_data_reference; 
			Unknown32 __unknown2; 
			// comment
			float nicename("Min Time to Upshift") min_time_to_upshift; 
			float nicename("Engine Upshift Scale") engine_upshift_scale; 
			float nicename("Gear Ratio") gear_ratio; 
			float nicename("Min Time to Downshift") min_time_to_downshift; 
			float nicename("Engine Downshift Scale") engine_downshift_scale; 
			Unknown32 __unknown3; 
		};

		struct nicename("braking") s_braking_block_definition
		{
			string_id nicename("Name") name; 
			signed int __unknown; 
		};
	};

	struct nicename("engine_motion_property") s_engine_motion_property_block_definition
	{
		struct nicename("Gears") s_gear_block_definition;
		struct nicename("Braking") s_braking_block_definition;

		float nicename("Steering Overdampen Cusp Angle") steering_overdampen_cusp_angle; 
		float nicename("Steering Overdamen Exponent") steering_overdamen_exponent; 
		float nicename("Maximum Left Turn") maximum_left_turn; 
		float nicename("Maximum Right Turn (negative)") maximum_right_turn_negative; 
		float nicename("Turn Rate") turn_rate; 
		float nicename("Engine Momentum") engine_momentum; 
		float nicename("Engine Maximum Angular Velocity") engine_maximum_angular_velocity; 
		s_tag_block_definition<s_gear_block_definition> nicename("Gears") gears_block; 
		TagReference nicename("Change Gear Sound") change_gear_sound_reference; 
		s_tag_block_definition<s_braking_block_definition> nicename("Braking") braking_block; 
		Unknown32 __block_here; 
		Unknown32 __block_here2; 
		Unknown32 __block_here3; 
		float __unknown; 
		float __unknown2; 

		struct nicename("gear") s_gear_block_definition
		{
			DataReference nicename("Loaded Torque Function") loaded_torque_function_data_reference; 
			Unknown32 __unknown; 
			DataReference nicename("Cruising Torque Function") cruising_torque_function_data_reference; 
			Unknown32 __unknown2; 
			// comment
			float nicename("Min Time to Upshift") min_time_to_upshift; 
			float nicename("Engine Upshift Scale") engine_upshift_scale; 
			float nicename("Gear Ratio") gear_ratio; 
			float nicename("Min Time to Downshift") min_time_to_downshift; 
			float nicename("Engine Downshift Scale") engine_downshift_scale; 
			Unknown32 __unknown3; 
		};

		struct nicename("braking") s_braking_block_definition
		{
			string_id nicename("Name") name; 
			signed int __unknown; 
		};
	};

	struct nicename("dropship_motion_property") s_dropship_motion_property_block_definition
	{
		float nicename("Forward Acceleration") forward_acceleration; 
		float nicename("Backward Acceleration") backward_acceleration; 
		float __unknown; 
		float __unknown2; 
		float nicename("Left Strafe Acceleration") left_strafe_acceleration; 
		float nicename("Right Strafe Acceleration") right_strafe_acceleration; 
		float __unknown3; 
		float __unknown4; 
		float nicename("Lift Acceleration") lift_acceleration; 
		float nicename("Drop Acceleration") drop_acceleration; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		float __unknown9; 
		float __unknown10; 
		float __unknown11; 
		float __unknown12; 
		float __unknown13; 
	};

	struct nicename("antigravity_motion_property") s_antigravity_motion_property_block_definition
	{
		float nicename("Steering Overdampen Cusp Angle") steering_overdampen_cusp_angle; 
		float nicename("Steering Overdamen Exponent") steering_overdamen_exponent; 
		float nicename("Maximum Forward Speed") maximum_forward_speed; 
		float nicename("Maximum Reverse Speed") maximum_reverse_speed; 
		float nicename("Speed Acceleration") speed_acceleration; 
		float nicename("Speed Deceleration") speed_deceleration; 
		float nicename("Maximum Left Slide") maximum_left_slide; 
		float nicename("Maximum Right Slide") maximum_right_slide; 
		float nicename("Slide Acceleration") slide_acceleration; 
		float nicename("Slide Deceleration") slide_deceleration; 
		float nicename("Direction Change?") direction_change; 
		signed char __unknown; 
		signed char __unknown2; 
		signed char __unknown3; 
		signed char __unknown4; 
		float nicename("Traction") traction; 
		Unknown32 __unknown5; 
		float nicename("Turning Rate") turning_rate; 
		string_id __unknown6; 
		float __unknown7; 
		float __unknown8; 
		float __unknown9; 
		float __unknown10; 
		string_id __unknown11; 
		float __unknown12; 
		float __unknown13; 
		float __unknown14; 
		float __unknown15; 
		float __unknown16; 
		float __unknown17; 
		float __unknown18; 
		float __unknown19; 
	};

	struct nicename("jet_engine_motion_property") s_jet_engine_motion_property_block_definition
	{
		float nicename("Steering Overdampen Cusp Angle") steering_overdampen_cusp_angle; 
		float nicename("Steering Overdamen Exponent") steering_overdamen_exponent; 
		float nicename("Maximum Left Turn") maximum_left_turn; 
		float nicename("Maximum Right Turn (negative)") maximum_right_turn_negative; 
		float nicename("Turn Rate") turn_rate; 
		float nicename("Flying Speed") flying_speed; 
		float nicename("Acceleration") acceleration; 
		float nicename("Speed Acceleration") speed_acceleration; 
		float nicename("Speed Deceleration") speed_deceleration; 
		float nicename("Pitch Left Speed") pitch_left_speed; 
		float nicename("Pitch Right Speed") pitch_right_speed; 
		float nicename("Pitch Rate") pitch_rate; 
		float nicename("Unpitch Rate") unpitch_rate; 
		float nicename("Flight Stability") flight_stability; 
		Unknown32 __unknown; 
		float nicename("Nose Angle") nose_angle; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float nicename("Falling Speed") falling_speed; 
		float nicename("Falling Speed 2") falling_speed_2; 
		float __unknown5; 
		float __unknown6; 
		float nicename("Idle Rise") idle_rise; 
		float nicename("Idle Forward") idle_forward; 
	};

	struct nicename("turret_property") s_turret_property_block_definition
	{
		signed short __unknown; 
		signed short __unknown2; 
	};

	struct nicename("helicopter_motion_property") s_helicopter_motion_property_block_definition
	{
		struct s_unknown_block_definition;

		float nicename("Max Left Turn") max_left_turn; 
		float nicename("Max Right Turn") max_right_turn; 
		float __unknown; 
		string_id nicename("Thrust Front Left") thrust_front_left; 
		string_id nicename("Thrust Front Right") thrust_front_right; 
		string_id nicename("Thrust") thrust; 
		DataReference nicename("Function") function_data_reference; 
		DataReference nicename("Function") function2_data_reference; 
		float __unknown2; 
		float nicename("Rise Speed") rise_speed; 
		float __unknown3; 
		float __unknown4; 
		Unknown32 __unknown5; 
		float nicename("Pitch min") pitch_min; 
		float nicename("Pitch max") pitch_max; 
		float nicename("Boost Acceleration Time") boost_acceleration_time; 
		DataReference nicename("Function") function3_data_reference; 
		DataReference nicename("Function") function4_data_reference; 
		DataReference nicename("Function") function5_data_reference; 
		s_tag_block_definition<s_unknown_block_definition> __unknown6_block; 
		float __unknown7; 
		float __unknown8; 
		float __unknown9; 
		float __unknown10; 
		float __unknown11; 
		float __unknown12; 
		float __unknown13; 
		float __unknown14; 
		float __unknown15; 
		float __unknown16; 

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

	struct nicename("space_fighter_motion_property") s_space_fighter_motion_property_block_definition
	{
		float nicename("Steering Overdampen Cusp Angle") steering_overdampen_cusp_angle; 
		float nicename("Steering Overdamen Exponent") steering_overdamen_exponent; 
		Unknown32 __unknown; 
		Unknown32 __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		Unknown32 __unknown9; 
		Unknown32 __unknown10; 
		Unknown32 __unknown11; 
		Unknown32 __unknown12; 
		float __unknown13; 
		Unknown32 __unknown14; 
		Unknown32 __unknown15; 
		float __unknown16; 
		float __unknown17; 
		float __unknown18; 
		float __unknown19; 
		float __unknown20; 
		Unknown32 __unknown21; 
		float __unknown22; 
		float __unknown23; 
		float __unknown24; 
		float __unknown25; 
		float __unknown26; 
		float __unknown27; 
		float __unknown28; 
		float __unknown29; 
		float __unknown30; 
		float __unknown31; 
		float __unknown32; 
		float __unknown33; 
		float __unknown34; 
		float __unknown35; 
		float __unknown36; 
		float __unknown37; 
		float __unknown38; 
		float __unknown39; 
		Unknown32 __unknown40; 
		Unknown32 __unknown41; 
		float __unknown42; 
		DataReference nicename("Function") function_data_reference; 
	};

	struct nicename("anti_gravity_point") s_anti_gravity_point_block_definition
	{
		string_id nicename("Marker Name") marker_name; 
		signed int nicename("Flags") flags; 
		float __unknown; 
		float nicename("Antigrav Strength") antigrav_strength; 
		float nicename("Antigrav Height") antigrav_height; 
		float nicename("Antigrav Dump Factor Up") antigrav_dump_factor_up; 
		float nicename("Antigrav Dump Factor Down") antigrav_dump_factor_down; 
		float nicename("Antigrav Normal k1") antigrav_normal_k1; 
		float nicename("Antigrav Normal k0") antigrav_normal_k0; 
		float nicename("Radius") radius; 
		string_id nicename("Material") material; 
		signed short nicename("Global Material Index") global_material_index; 
		signed short nicename("Damage Source Region Index") damage_source_region_index; 
		string_id nicename("Damage Source Region Name") damage_source_region_name; 
		float nicename("Default State Error") default_state_error; 
		float nicename("Minor Damage Error") minor_damage_error; 
		float nicename("Medium Damage Error") medium_damage_error; 
		float nicename("Major Damage Error") major_damage_error; 
		float nicename("Destroyed State Error") destroyed_state_error; 
	};

	struct nicename("friction_point") s_friction_point_block_definition
	{
		string_id nicename("Marker Name") marker_name; 
		signed int nicename("Flags") flags; 
		float nicename("Fraction Of Total Mass") fraction_of_total_mass; 
		float nicename("Radius") radius; 
		float nicename("Damaged Radius") damaged_radius; 
		float nicename("Moving Friction Velocity Diff") moving_friction_velocity_diff; 
		float nicename("E-Brake Moving Friction") e_brake_moving_friction; 
		float nicename("E-Brake Friction") e_brake_friction; 
		float nicename("E-Brake Moving Friction Velocity Diff") e_brake_moving_friction_velocity_diff; 
		string_id nicename("Collision Material Name") collision_material_name; 
		signed short nicename("Collision Global Material Index") collision_global_material_index; 
		signed short nicename("Model State Destroyed") model_state_destroyed; 
		string_id nicename("Region Name") region_name; 
		signed int nicename("Region Index") region_index; 
	};

	struct nicename("trick") s_trick_block_definition
	{
		string_id nicename("Name") name; 
		signed char nicename("Initiate Direction") initiate_direction; 
		signed char __unknown; 
		signed char __unknown2; 
		signed char __unknown3; 
		float __unknown4; 
		Unknown32 __distance_traveled; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		Unknown32 __cooldown_time; 
	};
};
