#pragma once

struct nicename("Effect") group('effe') s_effect_definition
{
	struct nicename("Locations") s_location_block_definition;
	struct nicename("Events") s_event_block_definition;
	struct nicename("Looping Sounds") s_looping_sound_block_definition;

	int32_t nicename("Flags") flags; 
	int32_t __unknown; 
	float __unknown2; 
	Undefined32 __unknown3; 
	float __unknown4; 
	int8_t __unknown5; 
	int8_t __unknown6; 
	int8_t __unknown7; 
	int8_t __unknown8; 
	int16_t __unknown9; 
	int16_t __unknown10; 
	Undefined32 __unknown11; 
	s_tag_block_definition<s_location_block_definition> nicename("Locations") locations_block; 
	s_tag_block_definition<s_event_block_definition> nicename("Events") events_block; 
	s_tag_block_definition<s_looping_sound_block_definition> nicename("Looping Sounds") looping_sounds_block; 
	float nicename("Always Play Distance") always_play_distance; 
	float nicename("Never Play Distance") never_play_distance; 
	float __unknown12; 
	float __unknown13; 
	Undefined32 __unknown14; 
	Undefined32 __unknown15; 
	Undefined32 __unknown16; 

	struct nicename("location") s_location_block_definition
	{
		string_id nicename("Marker Name") marker_name; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t __unknown4; 
	};

	struct nicename("event") s_event_block_definition
	{
		struct nicename("Parts") s_part_block_definition;
		struct nicename("Accelerations") s_acceleration_block_definition;
		struct nicename("Particle Systems") s_particle_system_block_definition;

		string_id nicename("Name") name; 
		int8_t __unknown; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t __unknown4; 
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
			int16_t nicename("Create In Environment") create_in_environment; 
			int16_t nicename("Create In Disposition") create_in_disposition; 
			int16_t nicename("Location Index") location_index; 
			int16_t __unknown; 
			int16_t __unknown2; 
			int8_t __unknown3; 
			int8_t nicename("Camera Mode") camera_mode; 
			// comment
			char nicename("Anticipated Tag Class") anticipated_tag_class[4];
			int8_t nicename("Damage Reporting Type") damage_reporting_type; 
			int8_t __unknown4; 
			int8_t __unknown5; 
			int8_t __unknown6; 
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
			int32_t nicename("A Scales Values") a_scales_values; 
			int32_t nicename("B Scales Values") b_scales_values; 
		};

		struct nicename("acceleration") s_acceleration_block_definition
		{
			int16_t nicename("Create In Environment") create_in_environment; 
			int16_t nicename("Create In Disposition") create_in_disposition; 
			int16_t nicename("Location Index") location_index; 
			int16_t __unknown; 
			float nicename("Acceleration") acceleration; 
			float nicename("Inner Cone Angle") inner_cone_angle; 
			float nicename("Outer Cone Angle") outer_cone_angle; 
		};

		struct nicename("particle_system") s_particle_system_block_definition
		{
			struct nicename("Emitters") s_emitter_block_definition;

			int8_t __unknown; 
			int8_t __unknown2; 
			int8_t __unknown3; 
			int8_t __unknown4; 
			TagReference nicename("Particle") particle_reference; 
			int16_t __unknown5; 
			int16_t nicename("Location Index") location_index; 
			int16_t nicename("Coordinate System") coordinate_system; 
			int16_t nicename("Environment") environment; 
			int16_t nicename("Disposition") disposition; 
			int16_t nicename("Camera Mode") camera_mode; 
			int16_t nicename("Sort Bias") sort_bias; 
			uint16_t nicename("Flags") flags; 
			int16_t __unknown6; 
			int16_t __unknown7; 
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
				uint16_t __unknown; 
				int16_t __unknown2; 
				Undefined32 __unknown3; 
				TagReference nicename("Custom Emitter Points") custom_emitter_points_reference; 
				TagReference __unknown4_reference; 
				Undefined32 __unknown5; 
				Undefined32 __unknown6; 
				Undefined32 __unknown7; 
				Undefined32 __unknown8; 
				Undefined32 __unknown9; 
				Undefined32 __unknown10; 
				Undefined32 __unknown11; 
				int8_t nicename("Input") input; 
				int8_t nicename("Input Range") input_range; 
				int8_t nicename("Output Kind") output_kind; 
				int8_t nicename("Output") output; 
				DataReference __unknown12_data_reference; 
				Undefined32 __unknown13; 
				Undefined32 __unknown14; 
				Undefined32 __unknown15; 
				Undefined32 __unknown16; 
				Undefined32 __unknown17; 
				Undefined32 __unknown18; 
				Undefined32 __unknown19; 
				Undefined32 __unknown20; 
				int8_t nicename("Input") input2; 
				int8_t nicename("Input Range") input_range2; 
				int8_t nicename("Output Kind") output_kind2; 
				int8_t nicename("Output") output2; 
				DataReference __unknown21_data_reference; 
				Undefined32 __unknown22; 
				Undefined32 __unknown23; 
				Undefined32 __unknown24; 
				Undefined32 __unknown25; 
				Undefined32 __unknown26; 
				Undefined32 __unknown27; 
				Undefined32 __unknown28; 
				Undefined32 __unknown29; 
				int8_t nicename("Input") input3; 
				int8_t nicename("Input Range") input_range3; 
				int8_t nicename("Output Kind") output_kind3; 
				int8_t nicename("Output") output3; 
				DataReference __unknown30_data_reference; 
				Undefined32 __unknown31; 
				Undefined32 __unknown32; 
				int8_t nicename("Input") input4; 
				int8_t nicename("Input Range") input_range4; 
				int8_t nicename("Output Kind") output_kind4; 
				int8_t nicename("Output") output4; 
				DataReference __unknown33_data_reference; 
				Undefined32 __unknown34; 
				Undefined32 __unknown35; 
				int8_t nicename("Input") input5; 
				int8_t nicename("Input Range") input_range5; 
				int8_t nicename("Output Kind") output_kind5; 
				int8_t nicename("Output") output5; 
				DataReference __unknown36_data_reference; 
				Undefined32 __unknown37; 
				Undefined32 __unknown38; 
				int8_t nicename("Input") input6; 
				int8_t nicename("Input Range") input_range6; 
				int8_t nicename("Output Kind") output_kind6; 
				int8_t nicename("Output") output6; 
				DataReference __unknown39_data_reference; 
				Undefined32 __unknown40; 
				Undefined32 __unknown41; 
				int8_t nicename("Input") input7; 
				int8_t nicename("Input Range") input_range7; 
				int8_t nicename("Output Kind") output_kind7; 
				int8_t nicename("Output") output7; 
				DataReference __unknown42_data_reference; 
				Undefined32 __unknown43; 
				Undefined32 __unknown44; 
				int8_t nicename("Input") input8; 
				int8_t nicename("Input Range") input_range8; 
				int8_t nicename("Output Kind") output_kind8; 
				int8_t nicename("Output") output8; 
				DataReference __unknown45_data_reference; 
				Undefined32 __unknown46; 
				Undefined32 __unknown47; 
				int8_t nicename("Input") input9; 
				int8_t nicename("Input Range") input_range9; 
				int8_t nicename("Output Kind") output_kind9; 
				int8_t nicename("Output") output9; 
				DataReference __unknown48_data_reference; 
				Undefined32 __unknown49; 
				Undefined32 __unknown50; 
				TagReference nicename("Particle Physics") particle_physics_reference; 
				Undefined32 __unknown51; 
				s_tag_block_definition<s_unknown_block_definition> __unknown52_block; 
				TagReference nicename("Displacement Map") displacement_map_reference; 
				int8_t nicename("Input") input10; 
				int8_t nicename("Input Range") input_range10; 
				int8_t nicename("Output Kind") output_kind10; 
				int8_t nicename("Output") output10; 
				DataReference __unknown53_data_reference; 
				Undefined32 __unknown54; 
				Undefined32 __unknown55; 
				Undefined32 __unknown56; 
				Undefined32 __unknown57; 
				Undefined32 __unknown58; 
				Undefined32 __unknown59; 
				Undefined32 __unknown60; 
				Undefined32 __unknown61; 
				int8_t nicename("Input") input11; 
				int8_t nicename("Input Range") input_range11; 
				int8_t nicename("Output Kind") output_kind11; 
				int8_t nicename("Output") output11; 
				DataReference __unknown62_data_reference; 
				Undefined32 __unknown63; 
				Undefined32 __unknown64; 
				int8_t nicename("Input") input12; 
				int8_t nicename("Input Range") input_range12; 
				int8_t nicename("Output Kind") output_kind12; 
				int8_t nicename("Output") output12; 
				DataReference __unknown65_data_reference; 
				Undefined32 __unknown66; 
				Undefined32 __unknown67; 
				int8_t nicename("Input") input13; 
				int8_t nicename("Input Range") input_range13; 
				int8_t nicename("Output Kind") output_kind13; 
				int8_t nicename("Output") output13; 
				DataReference __unknown68_data_reference; 
				Undefined32 __unknown69; 
				Undefined32 __unknown70; 
				int8_t nicename("Input") input14; 
				int8_t nicename("Input Range") input_range14; 
				int8_t nicename("Output Kind") output_kind14; 
				int8_t nicename("Output") output14; 
				DataReference __unknown71_data_reference; 
				Undefined32 __unknown72; 
				Undefined32 __unknown73; 
				int8_t nicename("Input") input15; 
				int8_t nicename("Input Range") input_range15; 
				int8_t nicename("Output Kind") output_kind15; 
				int8_t nicename("Output") output15; 
				DataReference nicename("Particle Scale") particle_scale_data_reference; 
				Undefined32 __unknown74; 
				Undefined32 __unknown75; 
				int8_t nicename("Input") input16; 
				int8_t nicename("Input Range") input_range16; 
				int8_t nicename("Output Kind") output_kind16; 
				int8_t nicename("Output") output16; 
				DataReference nicename("Particle Tint") particle_tint_data_reference; 
				Undefined32 __unknown76; 
				Undefined32 __unknown77; 
				int8_t nicename("Input") input17; 
				int8_t nicename("Input Range") input_range17; 
				int8_t nicename("Output Kind") output_kind17; 
				int8_t nicename("Output") output17; 
				DataReference nicename("Particle Alpha") particle_alpha_data_reference; 
				Undefined32 __unknown78; 
				Undefined32 __unknown79; 
				int8_t nicename("Input") input18; 
				int8_t nicename("Input Range") input_range18; 
				int8_t nicename("Output Kind") output_kind18; 
				int8_t nicename("Output") output18; 
				DataReference nicename("Particle Alpha Black Point") particle_alpha_black_point_data_reference; 
				Undefined32 __unknown80; 
				Undefined32 __unknown81; 
				int32_t __unknown82; 
				int32_t __unknown83; 
				int32_t __unknown84; 
				int32_t nicename("Compiled Scenario Index") compiled_scenario_index; 
				Undefined32 __unknown85; 
				Undefined32 __unknown86; 
				Undefined32 __unknown87; 

				struct s_unknown_block_definition
				{
					struct s_unknown2_block_definition;

					int32_t __unknown; 
					s_tag_block_definition<s_unknown2_block_definition> __unknown2_block; 
					Undefined32 __unknown3; 
					Undefined32 __unknown4; 

					struct s_unknown2_block_definition
					{
						Undefined32 __unknown; 
						int8_t nicename("Input") input; 
						int8_t nicename("Input Range") input_range; 
						int8_t nicename("Output Kind") output_kind; 
						int8_t nicename("Output") output; 
						DataReference __unknown2_data_reference; 
						Undefined32 __unknown3; 
						Undefined32 __unknown4; 
					};
				};
			};
		};
	};

	struct nicename("looping_sound") s_looping_sound_block_definition
	{
		TagReference nicename("Looping Sound") looping_sound_reference; 
		int16_t nicename("Location Index") location_index; 
		int16_t nicename("Event Index") event_index; 
	};
};
