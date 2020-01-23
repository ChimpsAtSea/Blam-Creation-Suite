#pragma once

struct nicename("Crate") group('bloc') s_crate_definition
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
	uint16_t nicename("Flags") flags2; 
	int16_t __unknown5; 
	s_tag_block_definition<s_metagame_property_block_definition> nicename("Metagame Properties") metagame_properties_block; 
	int8_t __unknown6; 
	int8_t __unknown7; 
	int8_t __unknown8; 
	int8_t __unknown9; 

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
};
