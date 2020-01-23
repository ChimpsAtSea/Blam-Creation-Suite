#pragma once

struct nicename("Effect") group('effe') s_effect_definition
{
	struct nicename("Locations") s_location_block_definition;
	struct nicename("Events") s_event_block_definition;
	struct nicename("Looping Sounds") s_looping_sound_block_definition;

	signed int nicename("Flags") flags; 
	signed int __unknown; 
	float __unknown2; 
	Unknown32 __unknown3; 
	float __unknown4; 
	signed char __unknown5; 
	signed char __unknown6; 
	signed char __unknown7; 
	signed char __unknown8; 
	signed short __unknown9; 
	signed short __unknown10; 
	Unknown32 __unknown11; 
	s_tag_block_definition<s_location_block_definition> nicename("Locations") locations_block; 
	s_tag_block_definition<s_event_block_definition> nicename("Events") events_block; 
	s_tag_block_definition<s_looping_sound_block_definition> nicename("Looping Sounds") looping_sounds_block; 
	float nicename("Always Play Distance") always_play_distance; 
	float nicename("Never Play Distance") never_play_distance; 
	float __unknown12; 
	float __unknown13; 
	Unknown32 __unknown14; 
	Unknown32 __unknown15; 
	Unknown32 __unknown16; 

	struct nicename("location") s_location_block_definition
	{
		string_id nicename("Marker Name") marker_name; 
		signed char __unknown; 
		signed char __unknown2; 
		signed char __unknown3; 
		signed char __unknown4; 
	};

	struct nicename("event") s_event_block_definition
	{
		struct nicename("Parts") s_part_block_definition;
		struct nicename("Accelerations") s_acceleration_block_definition;
		struct nicename("Particle Systems") s_particle_system_block_definition;

		string_id nicename("Name") name; 
		signed char __unknown; 
		signed char __unknown2; 
		signed char __unknown3; 
		signed char __unknown4; 
		float nicename("Skip Fraction") skip_fraction; 
		float nicename("Delay Bounds min") delay_bounds_min; 
		float nicename("Delay Bounds max") delay_bounds_max; 
		float nicename("Duration Bounds min") duration_bounds_min; 
		float nicename("Duration Bounds max") duration_bounds_max; 
		s_tag_block_definition<s_part_block_definition> nicename("Parts") parts_block; 
		s_tag_block_definition<s_acceleration_block_definition> nicename("Accelerations") accelerations_block; 
		s_tag_block_definition<s_particle_system_block_definition> nicename("Particle Systems") particle_systems_block; 

		struct nicename("part") s_part_block_definition
		{
			signed short nicename("Create In Environment") create_in_environment; 
			signed short nicename("Create In Disposition") create_in_disposition; 
			signed short nicename("Location Index") location_index; 
			signed short __unknown; 
			signed short __unknown2; 
			signed char __unknown3; 
			signed char nicename("Camera Mode") camera_mode; 
			// comment
			char nicename("Anticipated Tag Class") anticipated_tag_class[4];
			signed char nicename("Damage Reporting Type") damage_reporting_type; 
			signed char __unknown4; 
			signed char __unknown5; 
			signed char __unknown6; 
			TagReference nicename("Spawned Tag") spawned_tag_reference; 
			float nicename("Velocity Bounds min") velocity_bounds_min; 
			float nicename("Velocity Bounds max") velocity_bounds_max; 
			float __unknown7; 
			float __unknown8; 
			float nicename("Velocity Cone Angle") velocity_cone_angle; 
			float nicename("Angular Velocity Bounds min") angular_velocity_bounds_min; 
			float nicename("Angular Velocity Bounds max") angular_velocity_bounds_max; 
			float nicename("Radius Modifier Bounds min") radius_modifier_bounds_min; 
			float nicename("Radius Modifier Bounds max") radius_modifier_bounds_max; 
			float nicename("Origin Offset X") origin_offset_x; 
			float nicename("Origin Offset Y") origin_offset_y; 
			float nicename("Origin Offset Z") origin_offset_z; 
			float nicename("Origin Rotation i") origin_rotation_i; 
			float nicename("Origin Rotation j") origin_rotation_j; 
			signed int nicename("A Scales Values") a_scales_values; 
			signed int nicename("B Scales Values") b_scales_values; 
		};

		struct nicename("acceleration") s_acceleration_block_definition
		{
			signed short nicename("Create In Environment") create_in_environment; 
			signed short nicename("Create In Disposition") create_in_disposition; 
			signed short nicename("Location Index") location_index; 
			signed short __unknown; 
			float nicename("Acceleration") acceleration; 
			float nicename("Inner Cone Angle") inner_cone_angle; 
			float nicename("Outer Cone Angle") outer_cone_angle; 
		};

		struct nicename("particle_system") s_particle_system_block_definition
		{
			struct nicename("Emitters") s_emitter_block_definition;

			signed char __unknown; 
			signed char __unknown2; 
			signed char __unknown3; 
			signed char __unknown4; 
			TagReference nicename("Particle") particle_reference; 
			signed short __unknown5; 
			signed short nicename("Location Index") location_index; 
			signed short nicename("Coordinate System") coordinate_system; 
			signed short nicename("Environment") environment; 
			signed short nicename("Disposition") disposition; 
			signed short nicename("Camera Mode") camera_mode; 
			signed short nicename("Sort Bias") sort_bias; 
			unsigned short nicename("Flags") flags; 
			signed short __unknown6; 
			signed short __unknown7; 
			float __unknown8; 
			float __unknown9; 
			float __unknown10; 
			float __unknown11; 
			float nicename("Minimum View Distance 1") minimum_view_distance_1; 
			float nicename("Minimum View Distance 2") minimum_view_distance_2; 
			float __unknown12; 
			float __unknown13; 
			float __unknown14; 
			float nicename("Maximum Viewing Distance") maximum_viewing_distance; 
			float nicename("LOD In Distance") lod_in_distance; 
			float nicename("LOD Feather In Delta") lod_feather_in_delta; 
			float __unknown15; 
			s_tag_block_definition<s_emitter_block_definition> nicename("Emitters") emitters_block; 
			float __unknown16; 
			float __unknown17; 

			struct nicename("emitter") s_emitter_block_definition
			{
				struct s_unknown_block_definition;

				string_id nicename("Name") name; 
				unsigned short __unknown; 
				signed short __unknown2; 
				Unknown32 __unknown3; 
				TagReference nicename("Custom Emitter Points") custom_emitter_points_reference; 
				TagReference __unknown4_reference; 
				Unknown32 __unknown5; 
				Unknown32 __unknown6; 
				Unknown32 __unknown7; 
				Unknown32 __unknown8; 
				Unknown32 __unknown9; 
				Unknown32 __unknown10; 
				Unknown32 __unknown11; 
				signed char nicename("Input") input; 
				signed char nicename("Input Range") input_range; 
				signed char nicename("Output Kind") output_kind; 
				signed char nicename("Output") output; 
				DataReference __unknown12_data_reference; 
				Unknown32 __unknown13; 
				Unknown32 __unknown14; 
				Unknown32 __unknown15; 
				Unknown32 __unknown16; 
				Unknown32 __unknown17; 
				Unknown32 __unknown18; 
				Unknown32 __unknown19; 
				Unknown32 __unknown20; 
				signed char nicename("Input") input2; 
				signed char nicename("Input Range") input_range2; 
				signed char nicename("Output Kind") output_kind2; 
				signed char nicename("Output") output2; 
				DataReference __unknown21_data_reference; 
				Unknown32 __unknown22; 
				Unknown32 __unknown23; 
				Unknown32 __unknown24; 
				Unknown32 __unknown25; 
				Unknown32 __unknown26; 
				Unknown32 __unknown27; 
				Unknown32 __unknown28; 
				Unknown32 __unknown29; 
				signed char nicename("Input") input3; 
				signed char nicename("Input Range") input_range3; 
				signed char nicename("Output Kind") output_kind3; 
				signed char nicename("Output") output3; 
				DataReference __unknown30_data_reference; 
				Unknown32 __unknown31; 
				Unknown32 __unknown32; 
				signed char nicename("Input") input4; 
				signed char nicename("Input Range") input_range4; 
				signed char nicename("Output Kind") output_kind4; 
				signed char nicename("Output") output4; 
				DataReference __unknown33_data_reference; 
				Unknown32 __unknown34; 
				Unknown32 __unknown35; 
				signed char nicename("Input") input5; 
				signed char nicename("Input Range") input_range5; 
				signed char nicename("Output Kind") output_kind5; 
				signed char nicename("Output") output5; 
				DataReference __unknown36_data_reference; 
				Unknown32 __unknown37; 
				Unknown32 __unknown38; 
				signed char nicename("Input") input6; 
				signed char nicename("Input Range") input_range6; 
				signed char nicename("Output Kind") output_kind6; 
				signed char nicename("Output") output6; 
				DataReference __unknown39_data_reference; 
				Unknown32 __unknown40; 
				Unknown32 __unknown41; 
				signed char nicename("Input") input7; 
				signed char nicename("Input Range") input_range7; 
				signed char nicename("Output Kind") output_kind7; 
				signed char nicename("Output") output7; 
				DataReference __unknown42_data_reference; 
				Unknown32 __unknown43; 
				Unknown32 __unknown44; 
				signed char nicename("Input") input8; 
				signed char nicename("Input Range") input_range8; 
				signed char nicename("Output Kind") output_kind8; 
				signed char nicename("Output") output8; 
				DataReference __unknown45_data_reference; 
				Unknown32 __unknown46; 
				Unknown32 __unknown47; 
				signed char nicename("Input") input9; 
				signed char nicename("Input Range") input_range9; 
				signed char nicename("Output Kind") output_kind9; 
				signed char nicename("Output") output9; 
				DataReference __unknown48_data_reference; 
				Unknown32 __unknown49; 
				Unknown32 __unknown50; 
				TagReference nicename("Particle Physics") particle_physics_reference; 
				Unknown32 __unknown51; 
				s_tag_block_definition<s_unknown_block_definition> __unknown52_block; 
				TagReference nicename("Displacement Map") displacement_map_reference; 
				signed char nicename("Input") input10; 
				signed char nicename("Input Range") input_range10; 
				signed char nicename("Output Kind") output_kind10; 
				signed char nicename("Output") output10; 
				DataReference __unknown53_data_reference; 
				Unknown32 __unknown54; 
				Unknown32 __unknown55; 
				Unknown32 __unknown56; 
				Unknown32 __unknown57; 
				Unknown32 __unknown58; 
				Unknown32 __unknown59; 
				Unknown32 __unknown60; 
				Unknown32 __unknown61; 
				signed char nicename("Input") input11; 
				signed char nicename("Input Range") input_range11; 
				signed char nicename("Output Kind") output_kind11; 
				signed char nicename("Output") output11; 
				DataReference __unknown62_data_reference; 
				Unknown32 __unknown63; 
				Unknown32 __unknown64; 
				signed char nicename("Input") input12; 
				signed char nicename("Input Range") input_range12; 
				signed char nicename("Output Kind") output_kind12; 
				signed char nicename("Output") output12; 
				DataReference __unknown65_data_reference; 
				Unknown32 __unknown66; 
				Unknown32 __unknown67; 
				signed char nicename("Input") input13; 
				signed char nicename("Input Range") input_range13; 
				signed char nicename("Output Kind") output_kind13; 
				signed char nicename("Output") output13; 
				DataReference __unknown68_data_reference; 
				Unknown32 __unknown69; 
				Unknown32 __unknown70; 
				signed char nicename("Input") input14; 
				signed char nicename("Input Range") input_range14; 
				signed char nicename("Output Kind") output_kind14; 
				signed char nicename("Output") output14; 
				DataReference __unknown71_data_reference; 
				Unknown32 __unknown72; 
				Unknown32 __unknown73; 
				signed char nicename("Input") input15; 
				signed char nicename("Input Range") input_range15; 
				signed char nicename("Output Kind") output_kind15; 
				signed char nicename("Output") output15; 
				DataReference nicename("Particle Scale") particle_scale_data_reference; 
				Unknown32 __unknown74; 
				Unknown32 __unknown75; 
				signed char nicename("Input") input16; 
				signed char nicename("Input Range") input_range16; 
				signed char nicename("Output Kind") output_kind16; 
				signed char nicename("Output") output16; 
				DataReference nicename("Particle Tint") particle_tint_data_reference; 
				Unknown32 __unknown76; 
				Unknown32 __unknown77; 
				signed char nicename("Input") input17; 
				signed char nicename("Input Range") input_range17; 
				signed char nicename("Output Kind") output_kind17; 
				signed char nicename("Output") output17; 
				DataReference nicename("Particle Alpha") particle_alpha_data_reference; 
				Unknown32 __unknown78; 
				Unknown32 __unknown79; 
				signed char nicename("Input") input18; 
				signed char nicename("Input Range") input_range18; 
				signed char nicename("Output Kind") output_kind18; 
				signed char nicename("Output") output18; 
				DataReference nicename("Particle Alpha Black Point") particle_alpha_black_point_data_reference; 
				Unknown32 __unknown80; 
				Unknown32 __unknown81; 
				signed int __unknown82; 
				signed int __unknown83; 
				signed int __unknown84; 
				signed int nicename("Compiled Scenario Index") compiled_scenario_index; 
				Unknown32 __unknown85; 
				Unknown32 __unknown86; 
				Unknown32 __unknown87; 

				struct s_unknown_block_definition
				{
					struct s_unknown2_block_definition;

					signed int __unknown; 
					s_tag_block_definition<s_unknown2_block_definition> __unknown2_block; 
					Unknown32 __unknown3; 
					Unknown32 __unknown4; 

					struct s_unknown2_block_definition
					{
						Unknown32 __unknown; 
						signed char nicename("Input") input; 
						signed char nicename("Input Range") input_range; 
						signed char nicename("Output Kind") output_kind; 
						signed char nicename("Output") output; 
						DataReference __unknown2_data_reference; 
						Unknown32 __unknown3; 
						Unknown32 __unknown4; 
					};
				};
			};
		};
	};

	struct nicename("looping_sound") s_looping_sound_block_definition
	{
		TagReference nicename("Looping Sound") looping_sound_reference; 
		signed short nicename("Location Index") location_index; 
		signed short nicename("Event Index") event_index; 
	};
};
