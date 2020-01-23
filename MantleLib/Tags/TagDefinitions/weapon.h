#pragma once

struct nicename("Weapon") group('weap') s_weapon_definition
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
	struct nicename("Predicted Bitmaps") s_predicted_bitmap_block_definition;
	struct nicename("Melee Damage") s_melee_damage_block_definition;
	struct nicename("Target Tracking") s_target_tracking_block_definition;
	struct nicename("First Person") s_first_person_block_definition;
	struct nicename("Predicted Resources") s_predicted_resource2_block_definition;
	struct nicename("Magazines") s_magazine_block_definition;
	struct nicename("New Triggers") s_new_trigger_block_definition;
	struct nicename("Barrels") s_barrel_block_definition;
	struct nicename("Weapon Screen Effect") s_weapon_screen_effect_block_definition;

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
	int16_t nicename("OLD Message Index") old_message_index; 
	int16_t nicename("Sort Order") sort_order; 
	float nicename("OLD Multiplayer On-Ground Scale") old_multiplayer_on_ground_scale; 
	float nicename("OLD Campaign On-Ground Scale") old_campaign_on_ground_scale; 
	string_id nicename("Pickup Message") pickup_message; 
	string_id nicename("Swap Message") swap_message; 
	string_id nicename("Pickup Or Dual Wield Message") pickup_or_dual_wield_message; 
	string_id nicename("Swap Or Dual Wield Message") swap_or_dual_wield_message; 
	string_id nicename("Picked Up Message") picked_up_message; 
	string_id nicename("Switch-To Message") switch_to_message; 
	string_id nicename("Switch-To From AI Message") switch_to_from_ai_message; 
	string_id nicename("All Weapons Empty Message") all_weapons_empty_message; 
	string_id nicename("Overheated Message") overheated_message; 
	TagReference nicename("Collision Sound") collision_sound_reference; 
	s_tag_block_definition<s_predicted_bitmap_block_definition> nicename("Predicted Bitmaps") predicted_bitmaps_block; 
	TagReference nicename("Detonation Damage Effect") detonation_damage_effect_reference; 
	float nicename("Detonation Delay min") detonation_delay_min; 
	float nicename("Detonation Delay max") detonation_delay_max; 
	TagReference nicename("Detonating Effect") detonating_effect_reference; 
	TagReference nicename("Detonation Effect") detonation_effect_reference; 
	float nicename("Global Ground Scale") global_ground_scale; 
	float nicename("Small Hold Scale") small_hold_scale; 
	float nicename("Small Holster Scale") small_holster_scale; 
	float nicename("Large Hold Scale") large_hold_scale; 
	float nicename("Large Holster Scale") large_holster_scale; 
	float nicename("Medium Hold Scale") medium_hold_scale; 
	float nicename("Medium Holster Scale") medium_holster_scale; 
	float nicename("Huge Hold Scale") huge_hold_scale; 
	float nicename("Huge Holster Scale") huge_holster_scale; 
	TagReference nicename("Grounded Friction") grounded_friction_reference; 
	// comment
	int32_t nicename("Flags") flags3; 
	int32_t nicename("More Flags") more_flags; 
	string_id __unknown5; 
	int16_t nicename("Secondary Trigger Mode") secondary_trigger_mode; 
	int16_t nicename("Maximum Alternate Shots Loaded") maximum_alternate_shots_loaded; 
	float nicename("Turn On Time") turn_on_time; 
	float nicename("Ready Time") ready_time; 
	TagReference nicename("Ready Effect") ready_effect_reference; 
	TagReference nicename("Ready Damage Effect") ready_damage_effect_reference; 
	float nicename("Heat Recovery Threshold") heat_recovery_threshold; 
	float nicename("Overheated Threshold") overheated_threshold; 
	float nicename("Heat Detonation Threshold") heat_detonation_threshold; 
	float nicename("Heat Detonation Fraction") heat_detonation_fraction; 
	float nicename("Heat Loss Per Second") heat_loss_per_second; 
	string_id nicename("Heat Loss Function") heat_loss_function; 
	string_id nicename("Custom Function 1") custom_function_1; 
	float nicename("Custom Function Value") custom_function_value; 
	Undefined32 __unknown6; 
	float __unknown7; 
	float nicename("Heat Illumination") heat_illumination; 
	float nicename("Overheated Heat Loss Per Second") overheated_heat_loss_per_second; 
	string_id nicename("Custom Function 2") custom_function_2; 
	TagReference nicename("Overheated") overheated_reference; 
	TagReference nicename("Overheat Damage Effect") overheat_damage_effect_reference; 
	TagReference nicename("Detonation") detonation_reference; 
	TagReference nicename("Detonation Damage Effect") detonation_damage_effect2_reference; 
	s_tag_block_definition<s_melee_damage_block_definition> nicename("Melee Damage") melee_damage_block; 
	TagReference nicename("Clash Effect") clash_effect_reference; 
	int8_t nicename("Melee Damage Reporting Type") melee_damage_reporting_type; 
	int8_t __unknown8; 
	int16_t nicename("Magnification Levels") magnification_levels; 
	float nicename("Magnification Range min") magnification_range_min; 
	float nicename("Magnification Range max") magnification_range_max; 
	// comment
	float nicename("Autoaim Angle") autoaim_angle; 
	float nicename("Autoaim Range Long") autoaim_range_long; 
	float nicename("Autoaim Range Short") autoaim_range_short; 
	float nicename("Autoaim Safe Radius") autoaim_safe_radius; 
	float nicename("Magnetism Angle") magnetism_angle; 
	float nicename("Magnetism Range Long") magnetism_range_long; 
	float nicename("Magnetism Range Short") magnetism_range_short; 
	float nicename("Magnetism Safe Radius") magnetism_safe_radius; 
	float nicename("Deviation Angle") deviation_angle; 
	Undefined32 __unknown9; 
	Undefined32 __unknown10; 
	Undefined32 __unknown11; 
	Undefined32 __unknown12; 
	Undefined32 __unknown13; 
	Undefined32 __unknown14; 
	s_tag_block_definition<s_target_tracking_block_definition> nicename("Target Tracking") target_tracking_block; 
	Undefined32 __unknown15; 
	Undefined32 __unknown16; 
	Undefined32 __unknown17; 
	Undefined32 __unknown18; 
	int16_t nicename("Movement Penalized") movement_penalized; 
	int16_t __unknown19; 
	float nicename("Forwards Movement Penalty") forwards_movement_penalty; 
	float nicename("Sideways Movement Penalty") sideways_movement_penalty; 
	float nicename("AI Scariness") ai_scariness; 
	float nicename("Weapon Power-On Time") weapon_power_on_time; 
	float nicename("Weapon Power-Off Time") weapon_power_off_time; 
	TagReference nicename("Weapon Power-On Effect") weapon_power_on_effect_reference; 
	TagReference nicename("Weapon Power-Off Effect") weapon_power_off_effect_reference; 
	float nicename("Age Heat Recovery Penalty") age_heat_recovery_penalty; 
	float nicename("Age Rate of Fire Penalty") age_rate_of_fire_penalty; 
	float nicename("Age Misfire Start") age_misfire_start; 
	float nicename("Age Misfire Chance") age_misfire_chance; 
	TagReference nicename("Pickup Sound") pickup_sound_reference; 
	TagReference nicename("Zoom-In Sound") zoom_in_sound_reference; 
	TagReference nicename("Zoom-Out Sound") zoom_out_sound_reference; 
	float nicename("Active Camo Ding") active_camo_ding; 
	string_id nicename("Handle Node") handle_node; 
	string_id nicename("Weapon Class") weapon_class; 
	string_id nicename("Weapon Name") weapon_name; 
	int16_t nicename("Weapon Type") weapon_type; 
	int16_t __unknown20; 
	Undefined32 __unknown21; 
	Undefined32 __unknown22; 
	Undefined32 __unknown23; 
	Undefined32 __unknown24; 
	s_tag_block_definition<s_first_person_block_definition> nicename("First Person") first_person_block; 
	TagReference nicename("HUD Interface") hud_interface_reference; 
	TagReference __unknown25_reference; 
	s_tag_block_definition<s_predicted_resource2_block_definition> nicename("Predicted Resources") predicted_resources2_block; 
	s_tag_block_definition<s_magazine_block_definition> nicename("Magazines") magazines_block; 
	s_tag_block_definition<s_new_trigger_block_definition> nicename("New Triggers") new_triggers_block; 
	s_tag_block_definition<s_barrel_block_definition> nicename("Barrels") barrels_block; 
	float __unknown26; 
	float __unknown27; 
	float nicename("Maximum Movement Acceleration") maximum_movement_acceleration; 
	float nicename("Maximum Movement Velocity") maximum_movement_velocity; 
	float nicename("Maximum Turning Acceleration") maximum_turning_acceleration; 
	float nicename("Maximum Turning Velocity") maximum_turning_velocity; 
	TagReference nicename("Deployed Vehicle") deployed_vehicle_reference; 
	TagReference nicename("Deployed Weapon") deployed_weapon_reference; 
	TagReference nicename("Age Model") age_model_reference; 
	TagReference nicename("Age Weapon") age_weapon_reference; 
	TagReference nicename("Aged Material Effects") aged_material_effects_reference; 
	float nicename("Hammer Age Per Use MP") hammer_age_per_use_mp; 
	float nicename("Hammer Age Per Use SP") hammer_age_per_use_sp; 
	Undefined32 __unknown28; 
	float nicename("First Person Weapon Offset i") first_person_weapon_offset_i; 
	float nicename("First Person Weapon Offset j") first_person_weapon_offset_j; 
	float nicename("First Person Weapon Offset k") first_person_weapon_offset_k; 
	float nicename("First Person Scope Size i") first_person_scope_size_i; 
	float nicename("First Person Scope Size j") first_person_scope_size_j; 
	float nicename("Third Person Pitch Bounds min") third_person_pitch_bounds_min; 
	float nicename("Third Person Pitch Bounds max") third_person_pitch_bounds_max; 
	float nicename("Zoom Transition Time") zoom_transition_time; 
	float nicename("Melee Weapon Delay") melee_weapon_delay; 
	string_id nicename("Weapon Holster Marker") weapon_holster_marker; 
	s_tag_block_definition<s_weapon_screen_effect_block_definition> nicename("Weapon Screen Effect") weapon_screen_effect_block; 

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

	struct nicename("predicted_bitmap") s_predicted_bitmap_block_definition
	{
		TagReference nicename("Bitmap") bitmap_reference; 
	};

	struct nicename("melee_damage") s_melee_damage_block_definition
	{
		float nicename("Damage Pyramid Angles y") damage_pyramid_angles_y; 
		float nicename("Damage Pyramid Angles p") damage_pyramid_angles_p; 
		float nicename("Damage Pyramid Depth") damage_pyramid_depth; 
		float __unknown; 
		Undefined32 __unknown2; 
		float __unknown3; 
		TagReference nicename("__1st Hit Damage") __1st_hit_damage_reference; 
		TagReference nicename("__1st Hit Response") __1st_hit_response_reference; 
		TagReference nicename("__2nd Hit Damage") __2nd_hit_damage_reference; 
		TagReference nicename("__2nd Hit Response") __2nd_hit_response_reference; 
		TagReference nicename("__3rd Hit Damage") __3rd_hit_damage_reference; 
		TagReference nicename("__3rd Hit Response") __3rd_hit_response_reference; 
		TagReference nicename("Gun/Gun Clang Damage") gun_gun_clang_damage_reference; 
		TagReference nicename("Gun/Gun Clang Response") gun_gun_clang_response_reference; 
		TagReference nicename("Gun/Sword Clang Damage") gun_sword_clang_damage_reference; 
		TagReference nicename("Gun/Sword Clang Response") gun_sword_clang_response_reference; 
		TagReference nicename("Melee Effect") melee_effect_reference; 
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

	struct nicename("first_person") s_first_person_block_definition
	{
		TagReference nicename("First Person Model") first_person_model_reference; 
		TagReference nicename("First Person Animations") first_person_animations_reference; 
	};

	struct nicename("predicted_resource2") s_predicted_resource2_block_definition
	{
		int16_t nicename("Type") type; 
		int16_t nicename("Resource Index") resource_index; 
		unsigned int nicename("Tag Index") tag_index; 
	};

	struct nicename("magazine") s_magazine_block_definition
	{
		struct nicename("Magazine Equipment") s_magazine_equipment_block_definition;

		int32_t nicename("Flags") flags; 
		int16_t nicename("Rounds Recharged") rounds_recharged; 
		int16_t nicename("Rounds Total Initial") rounds_total_initial; 
		int16_t nicename("Rounds Total Maximum") rounds_total_maximum; 
		int16_t nicename("Rounds Total Loaded Maximum") rounds_total_loaded_maximum; 
		int16_t nicename("Maximum Rounds Held") maximum_rounds_held; 
		int16_t __unknown; 
		float nicename("Reload Time") reload_time; 
		int16_t nicename("Rounds Reloaded") rounds_reloaded; 
		int16_t __unknown2; 
		float nicename("Chamber Time") chamber_time; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		TagReference nicename("Reloading Effect") reloading_effect_reference; 
		TagReference nicename("Reloading Damage Effect") reloading_damage_effect_reference; 
		TagReference nicename("Chambering Effect") chambering_effect_reference; 
		TagReference nicename("Chambering Damage Effect") chambering_damage_effect_reference; 
		s_tag_block_definition<s_magazine_equipment_block_definition> nicename("Magazine Equipment") magazine_equipment_block; 

		struct nicename("magazine_equipment") s_magazine_equipment_block_definition
		{
			int16_t nicename("Rounds (0 for Max)") rounds_0_for_max; 
			int16_t __unknown; 
			TagReference nicename("Equipment") equipment_reference; 
		};
	};

	struct nicename("new_trigger") s_new_trigger_block_definition
	{
		struct nicename("Charge Levels") s_charge_level_block_definition;

		int32_t nicename("Flags") flags; 
		int16_t nicename("Button Used") button_used; 
		int16_t nicename("Behavior") behavior; 
		int16_t nicename("Primary Barrel") primary_barrel; 
		int16_t nicename("Secondary Barrel") secondary_barrel; 
		int16_t nicename("Prediction") prediction; 
		int16_t __unknown; 
		float nicename("Autofire Time") autofire_time; 
		float nicename("Autofire Throw") autofire_throw; 
		int16_t nicename("Secondary Action") secondary_action; 
		int16_t nicename("Primary Action") primary_action; 
		float nicename("Charging Time") charging_time; 
		float nicename("Charged Time") charged_time; 
		int8_t nicename("Overcharge Action") overcharge_action; 
		int8_t nicename("Charge Projectiles") charge_projectiles; 
		uint16_t nicename("Charge Flags") charge_flags; 
		float nicename("Charged Illumination") charged_illumination; 
		TagReference nicename("Charging Effect") charging_effect_reference; 
		TagReference nicename("Charging Damage Effect") charging_damage_effect_reference; 
		TagReference nicename("Charging Response") charging_response_reference; 
		float nicename("Charging Age Degeneration") charging_age_degeneration; 
		TagReference nicename("Discharging Effect") discharging_effect_reference; 
		TagReference nicename("Discharging Damage Effect") discharging_damage_effect_reference; 
		s_tag_block_definition<s_charge_level_block_definition> nicename("Charge Levels") charge_levels_block; 

		struct nicename("charge_level") s_charge_level_block_definition
		{
			float nicename("Percentage") percentage; 
		};
	};

	struct nicename("barrel") s_barrel_block_definition
	{
		struct nicename("Firing Penalty Function") s_firing_penalty_function_block_definition;
		struct nicename("Firing Crouched Penalty Function") s_firing_crouched_penalty_function_block_definition;
		struct nicename("Moving Penalty Function") s_moving_penalty_function_block_definition;
		struct nicename("Turning Penalty Function") s_turning_penalty_function_block_definition;
		struct nicename("Dual Firing Penalty Function") s_dual_firing_penalty_function_block_definition;
		struct nicename("Dual Firing Crouched Penalty Function") s_dual_firing_crouched_penalty_function_block_definition;
		struct nicename("Dual Moving Penalty Function") s_dual_moving_penalty_function_block_definition;
		struct nicename("Dual Turning Penalty Function") s_dual_turning_penalty_function_block_definition;
		struct nicename("First Person Offsets") s_first_person_offset_block_definition;
		struct nicename("Firing Effects") s_firing_effect_block_definition;

		int32_t nicename("Flags") flags; 
		float nicename("Rounds Per Second min") rounds_per_second_min; 
		float nicename("Rounds Per Second max") rounds_per_second_max; 
		string_id nicename("Acceleration Time Function") acceleration_time_function; 
		float nicename("Acceleration Time") acceleration_time; 
		string_id nicename("Deceleration Time Function") deceleration_time_function; 
		float nicename("Deceleration Time") deceleration_time; 
		float nicename("Barrel Spin Scale") barrel_spin_scale; 
		float nicename("Blurred Rate of Fire") blurred_rate_of_fire; 
		int16_t nicename("Shots Per Fire min") shots_per_fire_min; 
		int16_t nicename("Shots Per Fire max") shots_per_fire_max; 
		float nicename("Fire Recovery Time") fire_recovery_time; 
		float nicename("Soft Recovery Fraction") soft_recovery_fraction; 
		Undefined32 __unknown; 
		Undefined32 __unknown2; 
		int16_t nicename("Magazine") magazine; 
		int16_t nicename("Rounds Per Shot") rounds_per_shot; 
		int16_t nicename("Minimum Rounds Loaded") minimum_rounds_loaded; 
		int16_t nicename("Rounds Between Tracers") rounds_between_tracers; 
		string_id nicename("Optional Barrel Marker Name") optional_barrel_marker_name; 
		int16_t nicename("Prediction Type") prediction_type; 
		int16_t nicename("Firing Noise") firing_noise; 
		float __unknown3; 
		// comment
		float nicename("Acceleration Time") acceleration_time2; 
		float nicename("Deceleration Time") deceleration_time2; 
		float nicename("Damage Error min") damage_error_min; 
		float nicename("Damage Error max") damage_error_max; 
		// comment
		float nicename("Base Turning Speed") base_turning_speed; 
		float nicename("Dynamic Turning Speed min") dynamic_turning_speed_min; 
		float nicename("Dynamic Turning Speed max") dynamic_turning_speed_max; 
		// comment
		int16_t nicename("Distribution Function") distribution_function; 
		int16_t nicename("Projectiles Per Shot") projectiles_per_shot; 
		float nicename("Distribution Angle") distribution_angle; 
		float nicename("Minimum Error") minimum_error; 
		float nicename("Error Angle min") error_angle_min; 
		float nicename("Error Angle max") error_angle_max; 
		float nicename("Reload Penalty") reload_penalty; 
		float nicename("Switch Penalty") switch_penalty; 
		float nicename("Zoom Penalty") zoom_penalty; 
		float nicename("Jump Penalty") jump_penalty; 
		s_tag_block_definition<s_firing_penalty_function_block_definition> nicename("Firing Penalty Function") firing_penalty_function_block; 
		s_tag_block_definition<s_firing_crouched_penalty_function_block_definition> nicename("Firing Crouched Penalty Function") firing_crouched_penalty_function_block; 
		s_tag_block_definition<s_moving_penalty_function_block_definition> nicename("Moving Penalty Function") moving_penalty_function_block; 
		s_tag_block_definition<s_turning_penalty_function_block_definition> nicename("Turning Penalty Function") turning_penalty_function_block; 
		float nicename("Error Angle Maximum Rotation") error_angle_maximum_rotation; 
		s_tag_block_definition<s_dual_firing_penalty_function_block_definition> nicename("Dual Firing Penalty Function") dual_firing_penalty_function_block; 
		s_tag_block_definition<s_dual_firing_crouched_penalty_function_block_definition> nicename("Dual Firing Crouched Penalty Function") dual_firing_crouched_penalty_function_block; 
		s_tag_block_definition<s_dual_moving_penalty_function_block_definition> nicename("Dual Moving Penalty Function") dual_moving_penalty_function_block; 
		s_tag_block_definition<s_dual_turning_penalty_function_block_definition> nicename("Dual Turning Penalty Function") dual_turning_penalty_function_block; 
		float nicename("Dual Error Angle Maximum Rotation") dual_error_angle_maximum_rotation; 
		s_tag_block_definition<s_first_person_offset_block_definition> nicename("First Person Offsets") first_person_offsets_block; 
		int8_t nicename("Damage Reporting Type") damage_reporting_type; 
		int8_t __unknown4; 
		int16_t __unknown5; 
		TagReference nicename("Initial Projectile") initial_projectile_reference; 
		TagReference nicename("Trailing Projectile") trailing_projectile_reference; 
		TagReference nicename("Damage Effect") damage_effect_reference; 
		TagReference nicename("Crate Projectile") crate_projectile_reference; 
		float nicename("Crate Projectile Speed") crate_projectile_speed; 
		float nicename("Ejection Port Recovery Time") ejection_port_recovery_time; 
		float nicename("Illumination Recovery Time") illumination_recovery_time; 
		float nicename("Heat Generated Per Round") heat_generated_per_round; 
		string_id nicename("Heat Per Round Function") heat_per_round_function; 
		float nicename("Age Generated Per Round MP") age_generated_per_round_mp; 
		float nicename("Age Generated Per Round SP") age_generated_per_round_sp; 
		float nicename("Overload Time") overload_time; 
		float nicename("Firing Effect Deceleration Time") firing_effect_deceleration_time; 
		float __unknown6; 
		float nicename("Rate Of Fire Acceleration Time") rate_of_fire_acceleration_time; 
		float nicename("Rate Of Fire Deceleration Time") rate_of_fire_deceleration_time; 
		float nicename("Bloom Rate of Decay") bloom_rate_of_decay; 
		s_tag_block_definition<s_firing_effect_block_definition> nicename("Firing Effects") firing_effects_block; 

		struct nicename("firing_penalty_function") s_firing_penalty_function_block_definition
		{
			DataReference nicename("Function") function_data_reference; 
		};

		struct nicename("firing_crouched_penalty_function") s_firing_crouched_penalty_function_block_definition
		{
			DataReference nicename("Function") function_data_reference; 
		};

		struct nicename("moving_penalty_function") s_moving_penalty_function_block_definition
		{
			DataReference nicename("Function") function_data_reference; 
		};

		struct nicename("turning_penalty_function") s_turning_penalty_function_block_definition
		{
			DataReference nicename("Function") function_data_reference; 
		};

		struct nicename("dual_firing_penalty_function") s_dual_firing_penalty_function_block_definition
		{
			DataReference nicename("Function") function_data_reference; 
		};

		struct nicename("dual_firing_crouched_penalty_function") s_dual_firing_crouched_penalty_function_block_definition
		{
			DataReference nicename("Function") function_data_reference; 
		};

		struct nicename("dual_moving_penalty_function") s_dual_moving_penalty_function_block_definition
		{
			DataReference nicename("Function") function_data_reference; 
		};

		struct nicename("dual_turning_penalty_function") s_dual_turning_penalty_function_block_definition
		{
			DataReference nicename("Function") function_data_reference; 
		};

		struct nicename("first_person_offset") s_first_person_offset_block_definition
		{
			float nicename("First Person Offset x") first_person_offset_x; 
			float nicename("First Person Offset y") first_person_offset_y; 
			float nicename("First Person Offset z") first_person_offset_z; 
		};

		struct nicename("firing_effect") s_firing_effect_block_definition
		{
			int16_t nicename("Shot Count Lower Bound") shot_count_lower_bound; 
			int16_t nicename("Shot Count Upper Bound") shot_count_upper_bound; 
			TagReference nicename("Firing Effect") firing_effect_reference; 
			TagReference nicename("Misfire Effect") misfire_effect_reference; 
			TagReference nicename("Empty Effect") empty_effect_reference; 
			TagReference __unknown_effect_reference; 
			TagReference nicename("Firing Response") firing_response_reference; 
			TagReference nicename("Misfire Response") misfire_response_reference; 
			TagReference nicename("Empty Response") empty_response_reference; 
			TagReference __unknown_response_reference; 
			TagReference nicename("Rider Firing Response") rider_firing_response_reference; 
			TagReference nicename("Rider Misfire Response") rider_misfire_response_reference; 
			TagReference nicename("Rider Empty Response") rider_empty_response_reference; 
			TagReference nicename("Rider Unknown Response") rider_unknown_response_reference; 
		};
	};

	struct nicename("weapon_screen_effect") s_weapon_screen_effect_block_definition
	{
		uint8_t nicename("Flags") flags; 
		int8_t __unknown; 
		int16_t __unknown2; 
		TagReference nicename("Screen Effect") screen_effect_reference; 
	};
};
