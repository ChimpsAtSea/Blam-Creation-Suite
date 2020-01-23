#pragma once

struct nicename("Projectile") group('proj') s_projectile_definition
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
	struct nicename("Material Responses") s_material_respons2_block_definition;
	struct s_unknown_material_respons_block_definition;
	struct nicename("Claymore Grenade") s_claymore_grenade_block_definition;
	struct nicename("Firebomb Grenade") s_firebomb_grenade_block_definition;
	struct nicename("Shotgun Properties") s_shotgun_property_block_definition;

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
	signed short nicename("Detonation Timer Starts") detonation_timer_starts; 
	signed short nicename("Impact Noise") impact_noise; 
	float nicename("Collision Radius") collision_radius; 
	float nicename("Arming Time") arming_time; 
	float nicename("Danger Radius") danger_radius; 
	float __unknown5; 
	signed short __unknown6; 
	signed short __unknown7; 
	float nicename("Timer min") timer_min; 
	float nicename("Timer max") timer_max; 
	float nicename("Minimum Velocity") minimum_velocity; 
	float nicename("Maximum Range") maximum_range; 
	Unknown32 __unknown8; 
	Unknown32 __unknown9; 
	float nicename("Detonation Charge Time") detonation_charge_time; 
	signed short nicename("Detonation Noise") detonation_noise; 
	signed short nicename("Super Detonate Projectile Count") super_detonate_projectile_count; 
	float nicename("Super Detonation Delay") super_detonation_delay; 
	TagReference nicename("Detonation Started") detonation_started_reference; 
	TagReference nicename("Airborne Detonation Effect") airborne_detonation_effect_reference; 
	TagReference nicename("Ground Detonation Effect") ground_detonation_effect_reference; 
	TagReference nicename("Detonation Damage") detonation_damage_reference; 
	TagReference nicename("Attached Detonation Damage") attached_detonation_damage_reference; 
	TagReference nicename("Super Detonation") super_detonation_reference; 
	TagReference nicename("Super Detonation Damage") super_detonation_damage_reference; 
	TagReference nicename("Detonation Sound") detonation_sound_reference; 
	signed char nicename("Damage Reporting Type") damage_reporting_type; 
	signed char __unknown10; 
	unsigned short nicename("Super Detonation Object Types") super_detonation_object_types; 
	TagReference nicename("Attached Super Detonation Damage") attached_super_detonation_damage_reference; 
	float nicename("Material Effect Radius") material_effect_radius; 
	TagReference nicename("Flyby Sound") flyby_sound_reference; 
	TagReference nicename("Flyby Response") flyby_response_reference; 
	float nicename("Flyby Effects Range") flyby_effects_range; 
	TagReference nicename("Impact Effect") impact_effect_reference; 
	TagReference __unknown11_reference; 
	TagReference nicename("Impact Damage") impact_damage_reference; 
	float nicename("Boarding Detonation Time") boarding_detonation_time; 
	TagReference nicename("Boarding Detonation Damage") boarding_detonation_damage_reference; 
	TagReference nicename("Boarding Attached Detonation Damage") boarding_attached_detonation_damage_reference; 
	float nicename("Air Gravity") air_gravity; 
	float nicename("Air Damage Range min") air_damage_range_min; 
	float nicename("Air Damage Range max") air_damage_range_max; 
	float nicename("Water Gravity Scale") water_gravity_scale; 
	float nicename("Water Damage min") water_damage_min; 
	float nicename("Water Damage max") water_damage_max; 
	float nicename("Initial Velocity") initial_velocity; 
	float nicename("Final Velocity") final_velocity; 
	Unknown32 __unknown12; 
	float __unknown13; 
	float __unknown14; 
	float __unknown15; 
	Unknown32 __unknown16; 
	Unknown32 __unknown17; 
	float nicename("Guided Angular Velocity Lower") guided_angular_velocity_lower; 
	float nicename("Guided Angular Velocity Upper") guided_angular_velocity_upper; 
	float __unknown18; 
	float nicename("Acceleration Range min") acceleration_range_min; 
	float nicename("Acceleration Range max") acceleration_range_max; 
	float __unknown19; 
	Unknown32 __unknown20; 
	float nicename("Targeted Leading Fraction") targeted_leading_fraction; 
	Unknown32 __unknown21; 
	s_tag_block_definition<s_material_respons2_block_definition> nicename("Material Responses") material_responses2_block; 
	s_tag_block_definition<s_unknown_material_respons_block_definition> __unknown_material_responses_block; 
	s_tag_block_definition<s_claymore_grenade_block_definition> nicename("Claymore Grenade") claymore_grenade_block; 
	s_tag_block_definition<s_firebomb_grenade_block_definition> nicename("Firebomb Grenade") firebomb_grenade_block; 
	s_tag_block_definition<s_shotgun_property_block_definition> nicename("Shotgun Properties") shotgun_properties_block; 
	TagReference nicename("Grounded Friction") grounded_friction_reference; 

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

	struct nicename("material_respons2") s_material_respons2_block_definition
	{
		// comment
		signed short nicename("Response") response; 
		signed short __unknown; 
		string_id nicename("Material Name") material_name; 
		signed short nicename("Global Material Index") global_material_index; 
		signed short __unknown2; 
		// comment
		signed short nicename("Response") response2; 
		unsigned short nicename("Flags") flags; 
		float nicename("Chance Fraction") chance_fraction; 
		float nicename("Between Angle min") between_angle_min; 
		float nicename("Between Angle max") between_angle_max; 
		float nicename("And Velocity min") and_velocity_min; 
		float nicename("And Velocity max") and_velocity_max; 
		signed short nicename("Scale Effects By") scale_effects_by; 
		signed short __unknown3; 
		float nicename("Angular Noise") angular_noise; 
		float nicename("Velocity Noise") velocity_noise; 
		// comment
		float nicename("Initial Friction") initial_friction; 
		// comment
		float nicename("Parallel Friction") parallel_friction; 
		float nicename("Perpendicular Friction") perpendicular_friction; 
	};

	struct s_unknown_material_respons_block_definition
	{
		string_id nicename("Material") material; 
		signed short nicename("Global Material Index") global_material_index; 
		// comment
		unsigned short nicename("Flags") flags; 
		float nicename("Chance Fraction") chance_fraction; 
		float nicename("Between Angle min") between_angle_min; 
		float nicename("Between Angle max") between_angle_max; 
		float nicename("And Velocity min") and_velocity_min; 
		float nicename("And Velocity max") and_velocity_max; 
		signed short nicename("Response") response; 
		signed short nicename("Scale Effects By") scale_effects_by; 
		float nicename("Angular Noise") angular_noise; 
		float nicename("Velocity Noise") velocity_noise; 
		// comment
		float nicename("Penetration Initial Friction") penetration_initial_friction; 
		// comment
		float nicename("Reflection Parallel Friction") reflection_parallel_friction; 
		float nicename("Reflection Perpendicular Friction") reflection_perpendicular_friction; 
	};

	struct nicename("claymore_grenade") s_claymore_grenade_block_definition
	{
		float __unknown; 
		float __unknown2; 
		float __unknown3; 
		float __unknown4; 
		float __unknown5; 
		float __unknown6; 
		float __unknown7; 
		float __unknown8; 
		float __unknown9; 
		float __unknown10; 
		float __unknown11; 
		float __unknown12; 
	};

	struct nicename("firebomb_grenade") s_firebomb_grenade_block_definition
	{
		float __unknown; 
	};

	struct nicename("shotgun_property") s_shotgun_property_block_definition
	{
		signed short nicename("Amount") amount; 
		signed short nicename("Distance") distance; 
		float nicename("Accuracy") accuracy; 
		float nicename("Spread Cone Angle") spread_cone_angle; 
	};
};
