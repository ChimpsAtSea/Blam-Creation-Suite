#pragma once

nicename("effect") struct s_effect_definition
{
	nicename("Locations") struct s_location_block_definition;
	nicename("Events") struct s_event_block_definition;
	nicename("Looping Sounds") struct s_looping_sound_block_definition;

	nicename("Flags") signed int flags;
	nicename("Unknown") signed int unknown;
	nicename("Unknown") float unknown2;
	nicename("Unknown") unsigned int unknown3;
	nicename("Unknown") float unknown4;
	nicename("Unknown") signed char unknown5;
	nicename("Unknown") signed char unknown6;
	nicename("Unknown") signed char unknown7;
	nicename("Unknown") signed char unknown8;
	nicename("Unknown") signed short unknown9;
	nicename("Unknown") signed short unknown10;
	nicename("Unknown") unsigned int unknown11;
	nicename("Locations") s_tag_block_definition<s_location_block_definition> locations;
	nicename("Events") s_tag_block_definition<s_event_block_definition> events;
	nicename("Looping Sounds") s_tag_block_definition<s_looping_sound_block_definition> looping_sounds;
	nicename("Always Play Distance") float always_play_distance;
	nicename("Never Play Distance") float never_play_distance;
	nicename("Unknown") float unknown12;
	nicename("Unknown") float unknown13;
	nicename("Unknown") unsigned int unknown14;
	nicename("Unknown") unsigned int unknown15;
	nicename("Unknown") unsigned int unknown16;

	nicename("Location") struct s_location_definition
	{
		nicename("Marker Name") string_id marker_name;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("Unknown") signed char unknown4;
	};

	nicename("Event") struct s_event_definition
	{
		nicename("Parts") struct s_part_block_definition;
		nicename("Accelerations") struct s_acceleration_block_definition;
		nicename("Particle Systems") struct s_particle_system_block_definition;

		nicename("Name") string_id name;
		nicename("Unknown") signed char unknown;
		nicename("Unknown") signed char unknown2;
		nicename("Unknown") signed char unknown3;
		nicename("Unknown") signed char unknown4;
		nicename("Skip Fraction") float skip_fraction;
		nicename("Delay Bounds min") float delay_bounds_min;
		nicename("Delay Bounds max") float delay_bounds_max;
		nicename("Duration Bounds min") float duration_bounds_min;
		nicename("Duration Bounds max") float duration_bounds_max;
		nicename("Parts") s_tag_block_definition<s_part_block_definition> parts;
		nicename("Accelerations") s_tag_block_definition<s_acceleration_block_definition> accelerations;
		nicename("Particle Systems") s_tag_block_definition<s_particle_system_block_definition> particle_systems;

		nicename("Part") struct s_part_definition
		{
			nicename("Create In Environment") signed short create_in_environment;
			nicename("Create In Disposition") signed short create_in_disposition;
			nicename("Location Index") signed short location_index;
			nicename("Unknown") signed short unknown;
			nicename("Unknown") signed short unknown2;
			nicename("Unknown") signed char unknown3;
			nicename("Camera Mode") signed char camera_mode;
			nicename("Anticipated Tag Class") char anticipated_tag_class[4];
			nicename("Damage Reporting Type") signed char damage_reporting_type;
			nicename("Unknown") signed char unknown4;
			nicename("Unknown") signed char unknown5;
			nicename("Unknown") signed char unknown6;
			nicename("Spawned Tag") TagReference spawned_tag;
			nicename("Velocity Bounds min") float velocity_bounds_min;
			nicename("Velocity Bounds max") float velocity_bounds_max;
			nicename("Unknown") float unknown7;
			nicename("Unknown") float unknown8;
			nicename("Velocity Cone Angle") float velocity_cone_angle;
			nicename("Angular Velocity Bounds min") float angular_velocity_bounds_min;
			nicename("Angular Velocity Bounds max") float angular_velocity_bounds_max;
			nicename("Radius Modifier Bounds min") float radius_modifier_bounds_min;
			nicename("Radius Modifier Bounds max") float radius_modifier_bounds_max;
			nicename("Origin Offset X") float origin_offset_x;
			nicename("Origin Offset Y") float origin_offset_y;
			nicename("Origin Offset Z") float origin_offset_z;
			nicename("Origin Rotation i") float origin_rotation_i;
			nicename("Origin Rotation j") float origin_rotation_j;
			nicename("A Scales Values") signed int a_scales_values;
			nicename("B Scales Values") signed int b_scales_values;
		};

		nicename("Acceleration") struct s_acceleration_definition
		{
			nicename("Create In Environment") signed short create_in_environment;
			nicename("Create In Disposition") signed short create_in_disposition;
			nicename("Location Index") signed short location_index;
			nicename("Unknown") signed short unknown;
			nicename("Acceleration") float acceleration2;
			nicename("Inner Cone Angle") float inner_cone_angle;
			nicename("Outer Cone Angle") float outer_cone_angle;
		};

		nicename("Particle System") struct s_particle_system_definition
		{
			nicename("Emitters") struct s_emitter_block_definition;

			nicename("Unknown") signed char unknown;
			nicename("Unknown") signed char unknown2;
			nicename("Unknown") signed char unknown3;
			nicename("Unknown") signed char unknown4;
			nicename("Particle") TagReference particle;
			nicename("Unknown") signed short unknown5;
			nicename("Location Index") signed short location_index;
			nicename("Coordinate System") signed short coordinate_system;
			nicename("Environment") signed short environment;
			nicename("Disposition") signed short disposition;
			nicename("Camera Mode") signed short camera_mode;
			nicename("Sort Bias") signed short sort_bias;
			nicename("Flags") unsigned short flags;
			nicename("Unknown") signed short unknown6;
			nicename("Unknown") signed short unknown7;
			nicename("Unknown") float unknown8;
			nicename("Unknown") float unknown9;
			nicename("Unknown") float unknown10;
			nicename("Unknown") float unknown11;
			nicename("Minimum View Distance 1") float minimum_view_distance_1;
			nicename("Minimum View Distance 2") float minimum_view_distance_2;
			nicename("Unknown") float unknown12;
			nicename("Unknown") float unknown13;
			nicename("Unknown") float unknown14;
			nicename("Maximum Viewing Distance") float maximum_viewing_distance;
			nicename("LOD In Distance") float lod_in_distance;
			nicename("LOD Feather In Delta") float lod_feather_in_delta;
			nicename("Unknown") float unknown15;
			nicename("Emitters") s_tag_block_definition<s_emitter_block_definition> emitters;
			nicename("Unknown") float unknown16;
			nicename("Unknown") float unknown17;

			nicename("Emitter") struct s_emitter_definition
			{
				nicename("Unknown") struct s_unknown52_block_definition;

				nicename("Name") string_id name;
				nicename("Unknown") unsigned short unknown;
				nicename("Unknown") signed short unknown2;
				nicename("Unknown") unsigned int unknown3;
				nicename("Custom Emitter Points") TagReference custom_emitter_points;
				nicename("Unknown") TagReference unknown4;
				nicename("Unknown") unsigned int unknown5;
				nicename("Unknown") unsigned int unknown6;
				nicename("Unknown") unsigned int unknown7;
				nicename("Unknown") unsigned int unknown8;
				nicename("Unknown") unsigned int unknown9;
				nicename("Unknown") unsigned int unknown10;
				nicename("Unknown") unsigned int unknown11;
				nicename("Input") signed char input;
				nicename("Input Range") signed char input_range;
				nicename("Output Kind") signed char output_kind;
				nicename("Output") signed char output;
				nicename("Unknown") DataReference unknown12;
				nicename("Unknown") unsigned int unknown13;
				nicename("Unknown") unsigned int unknown14;
				nicename("Unknown") unsigned int unknown15;
				nicename("Unknown") unsigned int unknown16;
				nicename("Unknown") unsigned int unknown17;
				nicename("Unknown") unsigned int unknown18;
				nicename("Unknown") unsigned int unknown19;
				nicename("Unknown") unsigned int unknown20;
				nicename("Input") signed char input2;
				nicename("Input Range") signed char input_range2;
				nicename("Output Kind") signed char output_kind2;
				nicename("Output") signed char output2;
				nicename("Unknown") DataReference unknown21;
				nicename("Unknown") unsigned int unknown22;
				nicename("Unknown") unsigned int unknown23;
				nicename("Unknown") unsigned int unknown24;
				nicename("Unknown") unsigned int unknown25;
				nicename("Unknown") unsigned int unknown26;
				nicename("Unknown") unsigned int unknown27;
				nicename("Unknown") unsigned int unknown28;
				nicename("Unknown") unsigned int unknown29;
				nicename("Input") signed char input3;
				nicename("Input Range") signed char input_range3;
				nicename("Output Kind") signed char output_kind3;
				nicename("Output") signed char output3;
				nicename("Unknown") DataReference unknown30;
				nicename("Unknown") unsigned int unknown31;
				nicename("Unknown") unsigned int unknown32;
				nicename("Input") signed char input4;
				nicename("Input Range") signed char input_range4;
				nicename("Output Kind") signed char output_kind4;
				nicename("Output") signed char output4;
				nicename("Unknown") DataReference unknown33;
				nicename("Unknown") unsigned int unknown34;
				nicename("Unknown") unsigned int unknown35;
				nicename("Input") signed char input5;
				nicename("Input Range") signed char input_range5;
				nicename("Output Kind") signed char output_kind5;
				nicename("Output") signed char output5;
				nicename("Unknown") DataReference unknown36;
				nicename("Unknown") unsigned int unknown37;
				nicename("Unknown") unsigned int unknown38;
				nicename("Input") signed char input6;
				nicename("Input Range") signed char input_range6;
				nicename("Output Kind") signed char output_kind6;
				nicename("Output") signed char output6;
				nicename("Unknown") DataReference unknown39;
				nicename("Unknown") unsigned int unknown40;
				nicename("Unknown") unsigned int unknown41;
				nicename("Input") signed char input7;
				nicename("Input Range") signed char input_range7;
				nicename("Output Kind") signed char output_kind7;
				nicename("Output") signed char output7;
				nicename("Unknown") DataReference unknown42;
				nicename("Unknown") unsigned int unknown43;
				nicename("Unknown") unsigned int unknown44;
				nicename("Input") signed char input8;
				nicename("Input Range") signed char input_range8;
				nicename("Output Kind") signed char output_kind8;
				nicename("Output") signed char output8;
				nicename("Unknown") DataReference unknown45;
				nicename("Unknown") unsigned int unknown46;
				nicename("Unknown") unsigned int unknown47;
				nicename("Input") signed char input9;
				nicename("Input Range") signed char input_range9;
				nicename("Output Kind") signed char output_kind9;
				nicename("Output") signed char output9;
				nicename("Unknown") DataReference unknown48;
				nicename("Unknown") unsigned int unknown49;
				nicename("Unknown") unsigned int unknown50;
				nicename("Particle Physics") TagReference particle_physics;
				nicename("Unknown") unsigned int unknown51;
				nicename("Unknown") s_tag_block_definition<s_unknown52_block_definition> unknown53;
				nicename("Displacement Map") TagReference displacement_map;
				nicename("Input") signed char input10;
				nicename("Input Range") signed char input_range10;
				nicename("Output Kind") signed char output_kind10;
				nicename("Output") signed char output10;
				nicename("Unknown") DataReference unknown54;
				nicename("Unknown") unsigned int unknown55;
				nicename("Unknown") unsigned int unknown56;
				nicename("Unknown") unsigned int unknown57;
				nicename("Unknown") unsigned int unknown58;
				nicename("Unknown") unsigned int unknown59;
				nicename("Unknown") unsigned int unknown60;
				nicename("Unknown") unsigned int unknown61;
				nicename("Unknown") unsigned int unknown62;
				nicename("Input") signed char input11;
				nicename("Input Range") signed char input_range11;
				nicename("Output Kind") signed char output_kind11;
				nicename("Output") signed char output11;
				nicename("Unknown") DataReference unknown63;
				nicename("Unknown") unsigned int unknown64;
				nicename("Unknown") unsigned int unknown65;
				nicename("Input") signed char input12;
				nicename("Input Range") signed char input_range12;
				nicename("Output Kind") signed char output_kind12;
				nicename("Output") signed char output12;
				nicename("Unknown") DataReference unknown66;
				nicename("Unknown") unsigned int unknown67;
				nicename("Unknown") unsigned int unknown68;
				nicename("Input") signed char input13;
				nicename("Input Range") signed char input_range13;
				nicename("Output Kind") signed char output_kind13;
				nicename("Output") signed char output13;
				nicename("Unknown") DataReference unknown69;
				nicename("Unknown") unsigned int unknown70;
				nicename("Unknown") unsigned int unknown71;
				nicename("Input") signed char input14;
				nicename("Input Range") signed char input_range14;
				nicename("Output Kind") signed char output_kind14;
				nicename("Output") signed char output14;
				nicename("Unknown") DataReference unknown72;
				nicename("Unknown") unsigned int unknown73;
				nicename("Unknown") unsigned int unknown74;
				nicename("Input") signed char input15;
				nicename("Input Range") signed char input_range15;
				nicename("Output Kind") signed char output_kind15;
				nicename("Output") signed char output15;
				nicename("Particle Scale") DataReference particle_scale;
				nicename("Unknown") unsigned int unknown75;
				nicename("Unknown") unsigned int unknown76;
				nicename("Input") signed char input16;
				nicename("Input Range") signed char input_range16;
				nicename("Output Kind") signed char output_kind16;
				nicename("Output") signed char output16;
				nicename("Particle Tint") DataReference particle_tint;
				nicename("Unknown") unsigned int unknown77;
				nicename("Unknown") unsigned int unknown78;
				nicename("Input") signed char input17;
				nicename("Input Range") signed char input_range17;
				nicename("Output Kind") signed char output_kind17;
				nicename("Output") signed char output17;
				nicename("Particle Alpha") DataReference particle_alpha;
				nicename("Unknown") unsigned int unknown79;
				nicename("Unknown") unsigned int unknown80;
				nicename("Input") signed char input18;
				nicename("Input Range") signed char input_range18;
				nicename("Output Kind") signed char output_kind18;
				nicename("Output") signed char output18;
				nicename("Particle Alpha Black Point") DataReference particle_alpha_black_point;
				nicename("Unknown") unsigned int unknown81;
				nicename("Unknown") unsigned int unknown82;
				nicename("Unknown") signed int unknown83;
				nicename("Unknown") signed int unknown84;
				nicename("Unknown") signed int unknown85;
				nicename("Compiled Scenario Index") signed int compiled_scenario_index;
				nicename("Unknown") unsigned int unknown86;
				nicename("Unknown") unsigned int unknown87;
				nicename("Unknown") unsigned int unknown88;

				nicename("Unknown") struct s_unknown_definition
				{
					nicename("Unknown") struct s_unknown3_block_definition;

					nicename("Unknown") signed int unknown2;
					nicename("Unknown") s_tag_block_definition<s_unknown3_block_definition> unknown4;
					nicename("Unknown") unsigned int unknown5;
					nicename("Unknown") unsigned int unknown6;

					nicename("Unknown") struct s_unknown_definition
					{
						nicename("Unknown") unsigned int unknown2;
						nicename("Input") signed char input;
						nicename("Input Range") signed char input_range;
						nicename("Output Kind") signed char output_kind;
						nicename("Output") signed char output;
						nicename("Unknown") DataReference unknown3;
						nicename("Unknown") unsigned int unknown4;
						nicename("Unknown") unsigned int unknown5;
					};
				};
			};
		};
	};

	nicename("Looping Sound") struct s_looping_sound_definition
	{
		nicename("Looping Sound") TagReference looping_sound2;
		nicename("Location Index") signed short location_index;
		nicename("Event Index") signed short event_index;
	};
};
