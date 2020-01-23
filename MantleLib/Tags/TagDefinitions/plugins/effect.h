#pragma once

struct s_effect_definition
{
	struct s_location_block_definition;
	struct s_event_block_definition;
	struct s_looping_sound_block_definition;

	signed int flags;
	signed int unknown;
	float unknown2;
	unsigned int unknown3;
	float unknown4;
	signed char unknown5;
	signed char unknown6;
	signed char unknown7;
	signed char unknown8;
	signed short unknown9;
	signed short unknown10;
	unsigned int unknown11;
	s_tag_block_definition<s_location_block_definition> locations;
	s_tag_block_definition<s_event_block_definition> events;
	s_tag_block_definition<s_looping_sound_block_definition> looping_sounds;
	float always_play_distance;
	float never_play_distance;
	float unknown12;
	float unknown13;
	unsigned int unknown14;
	unsigned int unknown15;
	unsigned int unknown16;

	struct s_location_definition
	{
		string_id marker_name;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char unknown4;
	};

	struct s_event_definition
	{
		struct s_part_block_definition;
		struct s_acceleration_block_definition;
		struct s_particle_system_block_definition;

		string_id name;
		signed char unknown;
		signed char unknown2;
		signed char unknown3;
		signed char unknown4;
		float skip_fraction;
		float delay_bounds_min;
		float delay_bounds_max;
		float duration_bounds_min;
		float duration_bounds_max;
		s_tag_block_definition<s_part_block_definition> parts;
		s_tag_block_definition<s_acceleration_block_definition> accelerations;
		s_tag_block_definition<s_particle_system_block_definition> particle_systems;

		struct s_part_definition
		{
			signed short create_in_environment;
			signed short create_in_disposition;
			signed short location_index;
			signed short unknown;
			signed short unknown2;
			signed char unknown3;
			signed char camera_mode;
			char anticipated_tag_class[4];
			signed char damage_reporting_type;
			signed char unknown4;
			signed char unknown5;
			signed char unknown6;
			TagReference spawned_tag;
			float velocity_bounds_min;
			float velocity_bounds_max;
			float unknown7;
			float unknown8;
			float velocity_cone_angle;
			float angular_velocity_bounds_min;
			float angular_velocity_bounds_max;
			float radius_modifier_bounds_min;
			float radius_modifier_bounds_max;
			float origin_offset_x;
			float origin_offset_y;
			float origin_offset_z;
			float origin_rotation_i;
			float origin_rotation_j;
			signed int a_scales_values;
			signed int b_scales_values;
		};

		struct s_acceleration_definition
		{
			signed short create_in_environment;
			signed short create_in_disposition;
			signed short location_index;
			signed short unknown;
			float acceleration2;
			float inner_cone_angle;
			float outer_cone_angle;
		};

		struct s_particle_system_definition
		{
			struct s_emitter_block_definition;

			signed char unknown;
			signed char unknown2;
			signed char unknown3;
			signed char unknown4;
			TagReference particle;
			signed short unknown5;
			signed short location_index;
			signed short coordinate_system;
			signed short environment;
			signed short disposition;
			signed short camera_mode;
			signed short sort_bias;
			unsigned short flags;
			signed short unknown6;
			signed short unknown7;
			float unknown8;
			float unknown9;
			float unknown10;
			float unknown11;
			float minimum_view_distance_1;
			float minimum_view_distance_2;
			float unknown12;
			float unknown13;
			float unknown14;
			float maximum_viewing_distance;
			float lod_in_distance;
			float lod_feather_in_delta;
			float unknown15;
			s_tag_block_definition<s_emitter_block_definition> emitters;
			float unknown16;
			float unknown17;

			struct s_emitter_definition
			{
				struct s_unknown52_block_definition;

				string_id name;
				unsigned short unknown;
				signed short unknown2;
				unsigned int unknown3;
				TagReference custom_emitter_points;
				TagReference unknown4;
				unsigned int unknown5;
				unsigned int unknown6;
				unsigned int unknown7;
				unsigned int unknown8;
				unsigned int unknown9;
				unsigned int unknown10;
				unsigned int unknown11;
				signed char input;
				signed char input_range;
				signed char output_kind;
				signed char output;
				DataReference unknown12;
				unsigned int unknown13;
				unsigned int unknown14;
				unsigned int unknown15;
				unsigned int unknown16;
				unsigned int unknown17;
				unsigned int unknown18;
				unsigned int unknown19;
				unsigned int unknown20;
				signed char input2;
				signed char input_range2;
				signed char output_kind2;
				signed char output2;
				DataReference unknown21;
				unsigned int unknown22;
				unsigned int unknown23;
				unsigned int unknown24;
				unsigned int unknown25;
				unsigned int unknown26;
				unsigned int unknown27;
				unsigned int unknown28;
				unsigned int unknown29;
				signed char input3;
				signed char input_range3;
				signed char output_kind3;
				signed char output3;
				DataReference unknown30;
				unsigned int unknown31;
				unsigned int unknown32;
				signed char input4;
				signed char input_range4;
				signed char output_kind4;
				signed char output4;
				DataReference unknown33;
				unsigned int unknown34;
				unsigned int unknown35;
				signed char input5;
				signed char input_range5;
				signed char output_kind5;
				signed char output5;
				DataReference unknown36;
				unsigned int unknown37;
				unsigned int unknown38;
				signed char input6;
				signed char input_range6;
				signed char output_kind6;
				signed char output6;
				DataReference unknown39;
				unsigned int unknown40;
				unsigned int unknown41;
				signed char input7;
				signed char input_range7;
				signed char output_kind7;
				signed char output7;
				DataReference unknown42;
				unsigned int unknown43;
				unsigned int unknown44;
				signed char input8;
				signed char input_range8;
				signed char output_kind8;
				signed char output8;
				DataReference unknown45;
				unsigned int unknown46;
				unsigned int unknown47;
				signed char input9;
				signed char input_range9;
				signed char output_kind9;
				signed char output9;
				DataReference unknown48;
				unsigned int unknown49;
				unsigned int unknown50;
				TagReference particle_physics;
				unsigned int unknown51;
				s_tag_block_definition<s_unknown52_block_definition> unknown53;
				TagReference displacement_map;
				signed char input10;
				signed char input_range10;
				signed char output_kind10;
				signed char output10;
				DataReference unknown54;
				unsigned int unknown55;
				unsigned int unknown56;
				unsigned int unknown57;
				unsigned int unknown58;
				unsigned int unknown59;
				unsigned int unknown60;
				unsigned int unknown61;
				unsigned int unknown62;
				signed char input11;
				signed char input_range11;
				signed char output_kind11;
				signed char output11;
				DataReference unknown63;
				unsigned int unknown64;
				unsigned int unknown65;
				signed char input12;
				signed char input_range12;
				signed char output_kind12;
				signed char output12;
				DataReference unknown66;
				unsigned int unknown67;
				unsigned int unknown68;
				signed char input13;
				signed char input_range13;
				signed char output_kind13;
				signed char output13;
				DataReference unknown69;
				unsigned int unknown70;
				unsigned int unknown71;
				signed char input14;
				signed char input_range14;
				signed char output_kind14;
				signed char output14;
				DataReference unknown72;
				unsigned int unknown73;
				unsigned int unknown74;
				signed char input15;
				signed char input_range15;
				signed char output_kind15;
				signed char output15;
				DataReference particle_scale;
				unsigned int unknown75;
				unsigned int unknown76;
				signed char input16;
				signed char input_range16;
				signed char output_kind16;
				signed char output16;
				DataReference particle_tint;
				unsigned int unknown77;
				unsigned int unknown78;
				signed char input17;
				signed char input_range17;
				signed char output_kind17;
				signed char output17;
				DataReference particle_alpha;
				unsigned int unknown79;
				unsigned int unknown80;
				signed char input18;
				signed char input_range18;
				signed char output_kind18;
				signed char output18;
				DataReference particle_alpha_black_point;
				unsigned int unknown81;
				unsigned int unknown82;
				signed int unknown83;
				signed int unknown84;
				signed int unknown85;
				signed int compiled_scenario_index;
				unsigned int unknown86;
				unsigned int unknown87;
				unsigned int unknown88;

				struct s_unknown_definition
				{
					struct s_unknown3_block_definition;

					signed int unknown2;
					s_tag_block_definition<s_unknown3_block_definition> unknown4;
					unsigned int unknown5;
					unsigned int unknown6;

					struct s_unknown_definition
					{
						unsigned int unknown2;
						signed char input;
						signed char input_range;
						signed char output_kind;
						signed char output;
						DataReference unknown3;
						unsigned int unknown4;
						unsigned int unknown5;
					};
				};
			};
		};
	};

	struct s_looping_sound_definition
	{
		TagReference looping_sound2;
		signed short location_index;
		signed short event_index;
	};
};
