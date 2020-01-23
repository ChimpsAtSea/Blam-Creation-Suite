#pragma once

nicename("creature") struct s_creature_definition
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
	nicename("Dead Sphere Shapes") struct s_dead_sphere_shape_block_definition;
	nicename("Pill Shapes") struct s_pill_shape_block_definition;
	nicename("Sphere Shapes") struct s_sphere_shape_block_definition;
	nicename("Metagame Properties") struct s_metagame_property_block_definition;
	nicename("Unknown") struct s_unknown24_block_definition;

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
	nicename("Motion Sensor Blip Size") signed short motion_sensor_blip_size;
	nicename("Turning Velocity Maximum") float turning_velocity_maximum;
	nicename("Turning Acceleration Maximum") float turning_acceleration_maximum;
	nicename("Casual Turing Modifer") float casual_turing_modifer;
	nicename("Autoaim Width") float autoaim_width;
	nicename("Flags") signed int flags3;
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
	nicename("Unknown") float unknown6;
	nicename("Unknown") float unknown7;
	nicename("Unknown") float unknown8;
	nicename("Unknown") float unknown9;
	nicename("Unknown") float unknown10;
	nicename("Unknown") float unknown11;
	nicename("Unknown") float unknown12;
	nicename("Falling Velocity Scale") float falling_velocity_scale;
	nicename("Unknown") float unknown13;
	nicename("Unknown") float unknown14;
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
	nicename("Unknown") unsigned int unknown15;
	nicename("Impact Damage") TagReference impact_damage;
	nicename("Impact Shield Damage") TagReference impact_shield_damage;
	nicename("Metagame Properties") s_tag_block_definition<s_metagame_property_block_definition> metagame_properties;
	nicename("Destroy After Death Time min") float destroy_after_death_time_min;
	nicename("Destroy After Death Time max") float destroy_after_death_time_max;
	nicename("Unknown") signed int unknown16;
	nicename("Weapon Effect") TagReference weapon_effect;
	nicename("Unknown") unsigned int unknown17;
	nicename("Unknown") unsigned int unknown18;
	nicename("Unknown") unsigned int unknown19;
	nicename("Unknown") TagReference unknown20;
	nicename("Unknown") unsigned int unknown21;
	nicename("Unknown") unsigned int unknown22;
	nicename("Unknown") unsigned int unknown23;
	nicename("Unknown") s_tag_block_definition<s_unknown24_block_definition> unknown25;
	nicename("Firing Effect") TagReference firing_effect;
	nicename("Unknown") unsigned int unknown26;
	nicename("Unknown") unsigned int unknown27;
	nicename("Destruction Effect") TagReference destruction_effect;

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

	nicename("Metagame Property") struct s_metagame_property_definition
	{
		nicename("Flags") unsigned char flags;
		nicename("Unit") signed char unit;
		nicename("Classification") signed char classification;
		nicename("Unknown") signed char unknown;
		nicename("Points") signed short points;
		nicename("Unknown") signed short unknown2;
	};

	nicename("Unknown") struct s_unknown_definition
	{
		nicename("Function") DataReference function;
	};
};
