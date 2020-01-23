#pragma once

struct s_creature_definition
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
	struct s_dead_sphere_shape_block_definition;
	struct s_pill_shape_block_definition;
	struct s_sphere_shape_block_definition;
	struct s_metagame_property_block_definition;
	struct s_unknown24_block_definition;

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
	signed short motion_sensor_blip_size;
	float turning_velocity_maximum;
	float turning_acceleration_maximum;
	float casual_turing_modifer;
	float autoaim_width;
	signed int flags3;
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
	float unknown6;
	float unknown7;
	float unknown8;
	float unknown9;
	float unknown10;
	float unknown11;
	float unknown12;
	float falling_velocity_scale;
	float unknown13;
	float unknown14;
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
	unsigned int unknown15;
	TagReference impact_damage;
	TagReference impact_shield_damage;
	s_tag_block_definition<s_metagame_property_block_definition> metagame_properties;
	float destroy_after_death_time_min;
	float destroy_after_death_time_max;
	signed int unknown16;
	TagReference weapon_effect;
	unsigned int unknown17;
	unsigned int unknown18;
	unsigned int unknown19;
	TagReference unknown20;
	unsigned int unknown21;
	unsigned int unknown22;
	unsigned int unknown23;
	s_tag_block_definition<s_unknown24_block_definition> unknown25;
	TagReference firing_effect;
	unsigned int unknown26;
	unsigned int unknown27;
	TagReference destruction_effect;

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

	struct s_metagame_property_definition
	{
		unsigned char flags;
		signed char unit;
		signed char classification;
		signed char unknown;
		signed short points;
		signed short unknown2;
	};

	struct s_unknown_definition
	{
		DataReference function;
	};
};
