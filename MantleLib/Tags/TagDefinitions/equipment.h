#pragma once

struct nicename("Equipment") group('eqip') s_equipment_definition
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
	struct nicename("Equipment Camera") s_equipment_camera_block_definition;
	struct nicename("Powerup") s_powerup_block_definition;
	struct nicename("Object Creation") s_object_creation_block_definition;
	struct nicename("Destruction") s_destruction_block_definition;
	struct nicename("Radar Manipulation") s_radar_manipulation_block_definition;
	struct nicename("Armor Lockup") s_armor_lockup_block_definition;
	struct nicename("Regenerator") s_regenerator_block_definition;
	struct nicename("Runtime") s_runtime_block_definition;
	struct nicename("Invisibility Unknown") s_invisibility_unknown_block_definition;
	struct nicename("Jetpack") s_jetpack_block_definition;
	struct nicename("Hologram Properties") s_hologram_property_block_definition;
	struct nicename("Evade") s_evade_block_definition;
	struct nicename("Sprint") s_sprint_block_definition;

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
	signed short nicename("OLD Message Index") old_message_index; 
	signed short nicename("Sort Order") sort_order; 
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
	float nicename("Use Delay") use_delay; 
	float nicename("Use Duration") use_duration; 
	float __unknown5; 
	Unknown32 __unknown6; 
	float nicename("Recharge Delay") recharge_delay; 
	float nicename("Minimum Charge Fraction") minimum_charge_fraction; 
	float nicename("Initial Energy Use Amount") initial_energy_use_amount; 
	float nicename("Final Energy Use Amount") final_energy_use_amount; 
	float nicename("Active Energy Use Amount") active_energy_use_amount; 
	float nicename("Recharge Rate") recharge_rate; 
	DataReference nicename("Dynamic Charge Function") dynamic_charge_function_data_reference; 
	float nicename("Dynamic Charge Rate") dynamic_charge_rate; 
	signed int nicename("Flags") flags3; 
	signed short nicename("Equipment Type") equipment_type; 
	signed char nicename("Activation Type") activation_type; 
	signed char __unknown7; 
	string_id nicename("Biped Stow Marker") biped_stow_marker; 
	float nicename("Primary Color r") primary_color_r; 
	float nicename("Primary Color g") primary_color_g; 
	float nicename("Primary Color b") primary_color_b; 
	float nicename("Primary Color a") primary_color_a; 
	float nicename("Secondary Color r") secondary_color_r; 
	float nicename("Secondary Color g") secondary_color_g; 
	float nicename("Secondary Color b") secondary_color_b; 
	float nicename("Secondary Color a") secondary_color_a; 
	Unknown32 __unknown8; 
	Unknown32 __unknown9; 
	float __unknown10; 
	string_id __unknown11; 
	s_tag_block_definition<s_equipment_camera_block_definition> nicename("Equipment Camera") equipment_camera_block; 
	s_tag_block_definition<s_powerup_block_definition> nicename("Powerup") powerup_block; 
	s_tag_block_definition<s_object_creation_block_definition> nicename("Object Creation") object_creation_block; 
	s_tag_block_definition<s_destruction_block_definition> nicename("Destruction") destruction_block; 
	s_tag_block_definition<s_radar_manipulation_block_definition> nicename("Radar Manipulation") radar_manipulation_block; 
	Unknown32 __unknown12; 
	Unknown32 __unknown13; 
	Unknown32 __unknown14; 
	s_tag_block_definition<s_armor_lockup_block_definition> nicename("Armor Lockup") armor_lockup_block; 
	s_tag_block_definition<s_regenerator_block_definition> nicename("Regenerator") regenerator_block; 
	Unknown32 __unknown15; 
	Unknown32 __unknown16; 
	Unknown32 __unknown17; 
	s_tag_block_definition<s_runtime_block_definition> nicename("Runtime") runtime_block; 
	s_tag_block_definition<s_invisibility_unknown_block_definition> nicename("Invisibility Unknown") invisibility_unknown_block; 
	Unknown32 __unknown18; 
	Unknown32 __unknown19; 
	Unknown32 __unknown20; 
	Unknown32 __unknown21; 
	Unknown32 __unknown22; 
	Unknown32 __unknown23; 
	Unknown32 __unknown24; 
	Unknown32 __unknown25; 
	Unknown32 __unknown26; 
	Unknown32 __unknown27; 
	Unknown32 __unknown28; 
	Unknown32 __unknown29; 
	Unknown32 __unknown30; 
	Unknown32 __unknown31; 
	Unknown32 __unknown32; 
	Unknown32 __unknown33; 
	Unknown32 __unknown34; 
	Unknown32 __unknown35; 
	Unknown32 __unknown36; 
	Unknown32 __unknown37; 
	Unknown32 __unknown38; 
	s_tag_block_definition<s_jetpack_block_definition> nicename("Jetpack") jetpack_block; 
	s_tag_block_definition<s_hologram_property_block_definition> nicename("Hologram Properties") hologram_properties_block; 
	Unknown32 __unknown39; 
	Unknown32 __unknown40; 
	Unknown32 __unknown41; 
	s_tag_block_definition<s_evade_block_definition> nicename("Evade") evade_block; 
	Unknown32 __unknown42; 
	Unknown32 __unknown43; 
	Unknown32 __unknown44; 
	s_tag_block_definition<s_sprint_block_definition> nicename("Sprint") sprint_block; 
	signed char nicename("Damage Reporting Type") damage_reporting_type; 
	signed char __unknown45; 
	signed char __unknown46; 
	signed char __unknown47; 
	TagReference nicename("HUD Interface") hud_interface_reference; 
	TagReference nicename("Pickup Sound") pickup_sound_reference; 
	TagReference nicename("Empty Sound") empty_sound_reference; 
	TagReference nicename("Activation Effect") activation_effect_reference; 
	TagReference nicename("Active Effect") active_effect_reference; 
	TagReference nicename("Deactivation Effect") deactivation_effect_reference; 
	TagReference __unknown48_reference; 
	string_id nicename("Enter Animation") enter_animation; 
	string_id nicename("Idle Animation") idle_animation; 
	string_id nicename("Exit Animation") exit_animation; 
	Unknown32 __unknown49; 

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

	struct nicename("predicted_bitmap") s_predicted_bitmap_block_definition
	{
		TagReference nicename("Bitmap") bitmap_reference; 
	};

	struct nicename("equipment_camera") s_equipment_camera_block_definition
	{
		struct nicename("Camera Tracks") s_camera_track_block_definition;
		struct s_unknown_block_definition;
		struct s_unknown2_block_definition;
		struct nicename("Space Fighter Camera") s_space_fighter_camera_block_definition;

		unsigned char nicename("Camera Flags") camera_flags; 
		signed char __unknown; 
		signed char __unknown2; 
		signed char __unknown3; 
		string_id nicename("Camera Marker") camera_marker; 
		float nicename("Pitch Auto-Level") pitch_auto_level; 
		float nicename("Pitch Range min") pitch_range_min; 
		float nicename("Pitch Range max") pitch_range_max; 
		s_tag_block_definition<s_camera_track_block_definition> nicename("Camera Tracks") camera_tracks_block; 
		float nicename("Camera Stiffness min") camera_stiffness_min; 
		float nicename("Camera Stiffness max") camera_stiffness_max; 
		float __unknown4; 
		float nicename("Camera Acceleration Speed") camera_acceleration_speed; 
		float nicename("Camera Deceleration Speed") camera_deceleration_speed; 
		float __unknown5; 
		float nicename("Camera Field Of View") camera_field_of_view; 
		Unknown32 __unknown6; 
		Unknown32 __unknown7; 
		Unknown32 __unknown8; 
		Unknown32 __unknown9; 
		Unknown32 __unknown10; 
		Unknown32 __unknown11; 
		s_tag_block_definition<s_unknown_block_definition> __unknown12_block; 
		s_tag_block_definition<s_unknown2_block_definition> __unknown13_block; 
		s_tag_block_definition<s_space_fighter_camera_block_definition> nicename("Space Fighter Camera") space_fighter_camera_block; 

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
	};

	struct nicename("powerup") s_powerup_block_definition
	{
		signed int nicename("Powerup Trait Set") powerup_trait_set; 
	};

	struct nicename("object_creation") s_object_creation_block_definition
	{
		TagReference nicename("Object") object_reference; 
		TagReference __unknown_reference; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float nicename("Object Force") object_force; 
		signed short __unknown5; 
		signed short __unknown6; 
	};

	struct nicename("destruction") s_destruction_block_definition
	{
		TagReference nicename("Destroy Effect") destroy_effect_reference; 
		TagReference nicename("Destroy Damage Effect") destroy_damage_effect_reference; 
		float __unknown; 
		float nicename("Self Destruction Time") self_destruction_time; 
		float __unknown2; 
		signed short __unknown3; 
		signed short __unknown4; 
	};

	struct nicename("radar_manipulation") s_radar_manipulation_block_definition
	{
		float __unknown; 
		float nicename("Fake Blip Radius") fake_blip_radius; 
		signed int nicename("Fake Blip Count") fake_blip_count; 
		float __unknown2; 
	};

	struct nicename("armor_lockup") s_armor_lockup_block_definition
	{
		struct nicename("EMP Discharge Levels") s_emp_discharge_level_block_definition;

		string_id nicename("Material Name") material_name; 
		signed short nicename("Global Material Index") global_material_index; 
		signed short __unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		TagReference nicename("Collision Damage") collision_damage_reference; 
		TagReference nicename("AI Reflection Damage") ai_reflection_damage_reference; 
		TagReference nicename("Player Reflection Damage") player_reflection_damage_reference; 
		string_id nicename("Biped Active Damage Section") biped_active_damage_section; 
		string_id nicename("Biped Deactivated Damage Section") biped_deactivated_damage_section; 
		DataReference nicename("Function") function_data_reference; 
		Unknown32 __unknown4; 
		DataReference nicename("Function") function2_data_reference; 
		s_tag_block_definition<s_emp_discharge_level_block_definition> nicename("EMP Discharge Levels") emp_discharge_levels_block; 

		struct nicename("emp_discharge_level") s_emp_discharge_level_block_definition
		{
			float nicename("Charge Level") charge_level; 
			float __unknown; 
			TagReference nicename("Discharge Effect") discharge_effect_reference; 
		};
	};

	struct nicename("regenerator") s_regenerator_block_definition
	{
		signed int nicename("Flags") flags; 
		string_id nicename("Center Marker") center_marker; 
		float __unknown; 
	};

	struct nicename("runtime") s_runtime_block_definition
	{
		struct nicename("Traits When Active") s_traits_when_active_block_definition;
		struct nicename("Traits When Inactive") s_traits_when_inactive_block_definition;

		Unknown32 __unknown; 
		s_tag_block_definition<s_traits_when_active_block_definition> nicename("Traits When Active") traits_when_active_block; 
		s_tag_block_definition<s_traits_when_inactive_block_definition> nicename("Traits When Inactive") traits_when_inactive_block; 

		struct nicename("traits_when_active") s_traits_when_active_block_definition
		{
			struct nicename("Shields and Health") s_shields_and_health_block_definition;
			struct nicename("Weapons and Damage") s_weapons_and_damage_block_definition;
			struct nicename("Movement") s_movement_block_definition;
			struct nicename("Appearance") s_appearance_block_definition;
			struct nicename("HUD") s_hud_block_definition;

			s_tag_block_definition<s_shields_and_health_block_definition> nicename("Shields and Health") shields_and_health_block; 
			s_tag_block_definition<s_weapons_and_damage_block_definition> nicename("Weapons and Damage") weapons_and_damage_block; 
			s_tag_block_definition<s_movement_block_definition> nicename("Movement") movement_block; 
			s_tag_block_definition<s_appearance_block_definition> nicename("Appearance") appearance_block; 
			s_tag_block_definition<s_hud_block_definition> nicename("HUD") hud_block; 

			struct nicename("shields_and_health") s_shields_and_health_block_definition
			{
				signed char nicename("Damage Resistance") damage_resistance; 
				signed char nicename("Health Multiplier") health_multiplier; 
				signed char nicename("Health Recharge Rate") health_recharge_rate; 
				signed char nicename("Shield Multiplier") shield_multiplier; 
				signed char nicename("Shield Recharge Rate") shield_recharge_rate; 
				signed char nicename("Shield Recharge Rate 2") shield_recharge_rate_2; 
				signed char nicename("Headshot Immunity") headshot_immunity; 
				signed char nicename("Shield Vampirism") shield_vampirism; 
				signed char nicename("Assassination Immunity") assassination_immunity; 
				signed char nicename("Deathless") deathless; 
				signed char __unknown; 
				signed char __unknown2; 
			};

			struct nicename("weapons_and_damage") s_weapons_and_damage_block_definition
			{
				signed char nicename("Damage Modifier") damage_modifier; 
				signed char nicename("Melee Damage Modifier") melee_damage_modifier; 
				signed char nicename("Grenade Regeneration") grenade_regeneration; 
				signed char nicename("Weapon Pickup") weapon_pickup; 
				signed char nicename("Grenade Count") grenade_count; 
				signed char nicename("Infinite Ammo") infinite_ammo; 
				signed char nicename("Equipment Usage") equipment_usage; 
				signed char nicename("Equipment Drop") equipment_drop; 
				signed char nicename("Infinite Equipment") infinite_equipment; 
				signed char __unknown; 
				signed char __unknown2; 
				signed char __unknown3; 
				string_id nicename("Primary Weapon") primary_weapon; 
				string_id nicename("Secondary Weapon") secondary_weapon; 
				string_id nicename("Equipment") equipment; 
			};

			struct nicename("movement") s_movement_block_definition
			{
				signed char nicename("Player Speed") player_speed; 
				signed char nicename("Player Gravity") player_gravity; 
				signed char nicename("Vehicle Use") vehicle_use; 
				signed char nicename("Double Jump") double_jump; 
				// comment
				signed int nicename("Jump Height") jump_height; 
			};

			struct nicename("appearance") s_appearance_block_definition
			{
				signed char nicename("Active Camo") active_camo; 
				signed char nicename("Waypoint") waypoint; 
				signed char nicename("Visible Name") visible_name; 
				signed char nicename("Aura") aura; 
				signed char nicename("Forced Color") forced_color; 
				signed char __unknown; 
				signed char __unknown2; 
				signed char __unknown3; 
			};

			struct nicename("hud") s_hud_block_definition
			{
				signed char nicename("Motion Tracker Mode") motion_tracker_mode; 
				signed char nicename("Motion Tracker Range") motion_tracker_range; 
				signed char nicename("Directional Damage Indicator") directional_damage_indicator; 
				signed char __unknown; 
			};
		};

		struct nicename("traits_when_inactive") s_traits_when_inactive_block_definition
		{
			struct nicename("Shields and Health") s_shields_and_health_block_definition;
			struct nicename("Weapons and Damage") s_weapons_and_damage_block_definition;
			struct nicename("Movement") s_movement_block_definition;
			struct nicename("Appearance") s_appearance_block_definition;
			struct nicename("HUD") s_hud_block_definition;

			s_tag_block_definition<s_shields_and_health_block_definition> nicename("Shields and Health") shields_and_health_block; 
			s_tag_block_definition<s_weapons_and_damage_block_definition> nicename("Weapons and Damage") weapons_and_damage_block; 
			s_tag_block_definition<s_movement_block_definition> nicename("Movement") movement_block; 
			s_tag_block_definition<s_appearance_block_definition> nicename("Appearance") appearance_block; 
			s_tag_block_definition<s_hud_block_definition> nicename("HUD") hud_block; 

			struct nicename("shields_and_health") s_shields_and_health_block_definition
			{
				signed char nicename("Damage Resistance") damage_resistance; 
				signed char nicename("Health Multiplier") health_multiplier; 
				signed char nicename("Health Recharge Rate") health_recharge_rate; 
				signed char nicename("Shield Multiplier") shield_multiplier; 
				signed char nicename("Shield Recharge Rate") shield_recharge_rate; 
				signed char nicename("Shield Recharge Rate 2") shield_recharge_rate_2; 
				signed char nicename("Headshot Immunity") headshot_immunity; 
				signed char nicename("Shield Vampirism") shield_vampirism; 
				signed char nicename("Assassination Immunity") assassination_immunity; 
				signed char nicename("Deathless") deathless; 
				signed char __unknown; 
				signed char __unknown2; 
			};

			struct nicename("weapons_and_damage") s_weapons_and_damage_block_definition
			{
				signed char nicename("Damage Modifier") damage_modifier; 
				signed char nicename("Melee Damage Modifier") melee_damage_modifier; 
				signed char nicename("Grenade Regeneration") grenade_regeneration; 
				signed char nicename("Weapon Pickup") weapon_pickup; 
				signed char nicename("Grenade Count") grenade_count; 
				signed char nicename("Infinite Ammo") infinite_ammo; 
				signed char nicename("Equipment Usage") equipment_usage; 
				signed char nicename("Equipment Drop") equipment_drop; 
				signed char nicename("Infinite Equipment") infinite_equipment; 
				signed char __unknown; 
				signed char __unknown2; 
				signed char __unknown3; 
				string_id nicename("Primary Weapon") primary_weapon; 
				string_id nicename("Secondary Weapon") secondary_weapon; 
				string_id nicename("Equipment") equipment; 
			};

			struct nicename("movement") s_movement_block_definition
			{
				signed char nicename("Player Speed") player_speed; 
				signed char nicename("Player Gravity") player_gravity; 
				signed char nicename("Vehicle Use") vehicle_use; 
				signed char nicename("Double Jump") double_jump; 
				// comment
				signed int nicename("Jump Height") jump_height; 
			};

			struct nicename("appearance") s_appearance_block_definition
			{
				signed char nicename("Active Camo") active_camo; 
				signed char nicename("Waypoint") waypoint; 
				signed char nicename("Visible Name") visible_name; 
				signed char nicename("Aura") aura; 
				signed char nicename("Forced Color") forced_color; 
				signed char __unknown; 
				signed char __unknown2; 
				signed char __unknown3; 
			};

			struct nicename("hud") s_hud_block_definition
			{
				signed char nicename("Motion Tracker Mode") motion_tracker_mode; 
				signed char nicename("Motion Tracker Range") motion_tracker_range; 
				signed char nicename("Directional Damage Indicator") directional_damage_indicator; 
				signed char __unknown; 
			};
		};
	};

	struct nicename("invisibility_unknown") s_invisibility_unknown_block_definition
	{
		struct s_unknown_block_definition;
		struct s_unknown2_block_definition;

		s_tag_block_definition<s_unknown_block_definition> __unknown_block; 
		s_tag_block_definition<s_unknown2_block_definition> __unknown2_block; 

		struct s_unknown_block_definition
		{
			struct s_unknown2_block_definition;

			s_tag_block_definition<s_unknown2_block_definition> __unknown_block; 

			struct s_unknown2_block_definition
			{
				signed char __unknown; 
				signed char __unknown2; 
				signed char __unknown3; 
				signed char __unknown4; 
			};
		};

		struct s_unknown2_block_definition
		{
			struct s_unknown_block_definition;

			s_tag_block_definition<s_unknown_block_definition> __unknown_block; 

			struct s_unknown_block_definition
			{
				signed char __unknown; 
				signed char __unknown2; 
				signed char __unknown3; 
				signed char __unknown4; 
			};
		};
	};

	struct nicename("jetpack") s_jetpack_block_definition
	{
		DataReference nicename("Function") function_data_reference; 
		float nicename("Downforce When Falling") downforce_when_falling; 
		float nicename("Airtime") airtime; 
		float nicename("Falling Velocity Defuse") falling_velocity_defuse; 
		Unknown32 __unknown; 
		float nicename("Vertical Force") vertical_force; 
		float nicename("Terminal Velocity Time") terminal_velocity_time; 
	};

	struct nicename("hologram_property") s_hologram_property_block_definition
	{
		float nicename("Time Active") time_active; 
		signed int nicename("Flags") flags; 
		TagReference nicename("Create Effect") create_effect_reference; 
		TagReference nicename("Active Effect") active_effect_reference; 
		Unknown32 __unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		TagReference nicename("Destruction Effect") destruction_effect_reference; 
		float nicename("Stability min") stability_min; 
		float nicename("Stability max") stability_max; 
		DataReference nicename("Function") function_data_reference; 
	};

	struct nicename("evade") s_evade_block_definition
	{
		string_id nicename("Forward Animation") forward_animation; 
		string_id nicename("Left Animation") left_animation; 
		string_id nicename("Back Animation") back_animation; 
		string_id nicename("Right Animation") right_animation; 
	};

	struct nicename("sprint") s_sprint_block_definition
	{
		signed char __unknown; 
		signed char __unknown2; 
		signed char __unknown3; 
		signed char __unknown4; 
	};
};
