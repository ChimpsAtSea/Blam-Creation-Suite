#pragma once

struct nicename("sound_looping") tag_group('lsnd') s_sound_looping_definition
{
	enum nicename("Sound Class") e_sound_class : uint16_t
	{
		/*nicename("projectile_impact")*/ _sound_class_projectile_impact = 1ui16,
		/*nicename("projectile_detonation")*/ _sound_class_projectile_detonation = 2ui16,
		/*nicename("projectile_flyby")*/ _sound_class_projectile_flyby = 3ui16,
		/*nicename("projectile_detonation_lod")*/ _sound_class_projectile_detonation_lod = 4ui16,
		/*nicename("weapon_fire")*/ _sound_class_weapon_fire = 5ui16,
		/*nicename("weapon_ready")*/ _sound_class_weapon_ready = 6ui16,
		/*nicename("weapon_reload")*/ _sound_class_weapon_reload = 7ui16,
		/*nicename("weapon_empty")*/ _sound_class_weapon_empty = 8ui16,
		/*nicename("weapon_charge")*/ _sound_class_weapon_charge = 9ui16,
		/*nicename("weapon_overheat")*/ _sound_class_weapon_overheat = 10ui16,
		/*nicename("weapon_idle")*/ _sound_class_weapon_idle = 11ui16,
		/*nicename("weapon_melee")*/ _sound_class_weapon_melee = 12ui16,
		/*nicename("weapon_animation")*/ _sound_class_weapon_animation = 13ui16,
		/*nicename("object_impacts")*/ _sound_class_object_impacts = 14ui16,
		/*nicename("particle_impacts")*/ _sound_class_particle_impacts = 15ui16,
		/*nicename("weapon_fire_lod")*/ _sound_class_weapon_fire_lod = 16ui16,
		/*nicename("water_transitions")*/ _sound_class_water_transitions = 17ui16,
		/*nicename("lowpass_effects")*/ _sound_class_lowpass_effects = 18ui16,
		/*nicename("unit_footsteps")*/ _sound_class_unit_footsteps = 19ui16,
		/*nicename("unit_dialog")*/ _sound_class_unit_dialog = 20ui16,
		/*nicename("unit_animation")*/ _sound_class_unit_animation = 21ui16,
		/*nicename("unit_unused!")*/ _sound_class_unit_unused = 22ui16,
		/*nicename("vehicle_collision")*/ _sound_class_vehicle_collision = 23ui16,
		/*nicename("vehicle_engine")*/ _sound_class_vehicle_engine = 24ui16,
		/*nicename("vehicle_animation")*/ _sound_class_vehicle_animation = 25ui16,
		/*nicename("vehicle_engine_lod")*/ _sound_class_vehicle_engine_lod = 26ui16,
		/*nicename("device_door")*/ _sound_class_device_door = 27ui16,
		/*nicename("device_unused0!")*/ _sound_class_device_unused0 = 28ui16,
		/*nicename("device_machinery")*/ _sound_class_device_machinery = 29ui16,
		/*nicename("device_stationary")*/ _sound_class_device_stationary = 30ui16,
		/*nicename("device_unused1!")*/ _sound_class_device_unused1 = 31ui16,
		/*nicename("device_unused2!")*/ _sound_class_device_unused2 = 32ui16,
		/*nicename("music")*/ _sound_class_music = 33ui16,
		/*nicename("ambient_nature")*/ _sound_class_ambient_nature = 34ui16,
		/*nicename("ambient_machinery")*/ _sound_class_ambient_machinery = 35ui16,
		/*nicename("ambient_stationary")*/ _sound_class_ambient_stationary = 36ui16,
		/*nicename("huge_ass")*/ _sound_class_huge_ass = 37ui16,
		/*nicename("object_looping")*/ _sound_class_object_looping = 38ui16,
		/*nicename("cinematic_music")*/ _sound_class_cinematic_music = 39ui16,
		/*nicename("unknown_unused0!")*/ _sound_class_unknown_unused0 = 40ui16,
		/*nicename("unknown_unused1!")*/ _sound_class_unknown_unused1 = 41ui16,
		/*nicename("ambient_flock")*/ _sound_class_ambient_flock = 42ui16,
		/*nicename("no_pad")*/ _sound_class_no_pad = 43ui16,
		/*nicename("no_pad_stationary")*/ _sound_class_no_pad_stationary = 44ui16,
		/*nicename("equipment_effect")*/ _sound_class_equipment_effect = 45ui16,
		/*nicename("mission_dialog")*/ _sound_class_mission_dialog = 46ui16,
		/*nicename("cinematic_dialog")*/ _sound_class_cinematic_dialog = 47ui16,
		/*nicename("scripted_cinematic_foley")*/ _sound_class_scripted_cinematic_foley = 48ui16,
		/*nicename("game_event")*/ _sound_class_game_event = 49ui16,
		/*nicename("ui")*/ _sound_class_ui = 50ui16,
		/*nicename("test")*/ _sound_class_test = 51ui16,
		/*nicename("multiplayer_dialog")*/ _sound_class_multiplayer_dialog = 52ui16,
		/*nicename("ambient_nature_details")*/ _sound_class_ambient_nature_details = 53ui16,
		/*nicename("ambient_machinery_details")*/ _sound_class_ambient_machinery_details = 54ui16,
		/*nicename("inside_surround_tail")*/ _sound_class_inside_surround_tail = 55ui16,
		/*nicename("outside_surround_tail")*/ _sound_class_outside_surround_tail = 56ui16,
		/*nicename("vehicle_detonation")*/ _sound_class_vehicle_detonation = 57ui16,
		/*nicename("ambient_detonation")*/ _sound_class_ambient_detonation = 58ui16,
		/*nicename("first_person_inside")*/ _sound_class_first_person_inside = 59ui16,
		/*nicename("first_person_outside")*/ _sound_class_first_person_outside = 60ui16,
		/*nicename("first_person_anywhere")*/ _sound_class_first_person_anywhere = 61ui16,
		/*nicename("space_projectile_detonation")*/ _sound_class_space_projectile_detonation = 62ui16,
		/*nicename("space_projectile_flyby")*/ _sound_class_space_projectile_flyby = 63ui16,
		/*nicename("space_vehicle_engine")*/ _sound_class_space_vehicle_engine = 64ui16,
		/*nicename("space_weapon_fire")*/ _sound_class_space_weapon_fire = 65ui16,
		/*nicename("player_voice_team")*/ _sound_class_player_voice_team = 66ui16,
		/*nicename("player_voice_proxy")*/ _sound_class_player_voice_proxy = 67ui16,
		/*nicename("projectile_impact_postpone")*/ _sound_class_projectile_impact_postpone = 68ui16,
		/*nicename("unit_footsteps_postpone")*/ _sound_class_unit_footsteps_postpone = 69ui16,
		/*nicename("weapon_ready_third_person")*/ _sound_class_weapon_ready_third_person = 70ui16,
		/*nicename("ui_music")*/ _sound_class_ui_music = 71ui16,
	};

	enum nicename("Flags") b_flags : uint32_t /* bitfield */
	{
		/*nicename("Deafening to AIs")*/ _flags_deafening_to_ais = 1ui32 << 0ui32,
		/*nicename("Not A Loop")*/ _flags_not_a_loop = 1ui32 << 1ui32,
		/*nicename("Stops Music")*/ _flags_stops_music = 1ui32 << 2ui32,
		/*nicename("Always Spatialize")*/ _flags_always_spatialize = 1ui32 << 3ui32,
		/*nicename("Synchronize Playback")*/ _flags_synchronize_playback = 1ui32 << 4ui32,
		/*nicename("Synchronize Tracks")*/ _flags_synchronize_tracks = 1ui32 << 5ui32,
		/*nicename("Fake Spatialization With Distance")*/ _flags_fake_spatialization_with_distance = 1ui32 << 6ui32,
		/*nicename("Combine All 3D Playback")*/ _flags_combine_all_3d_playback = 1ui32 << 7ui32,
		/*nicename("Bit 8")*/ _flags_bit_8 = 1ui32 << 8ui32,
		/*nicename("Bit 9")*/ _flags_bit_9 = 1ui32 << 9ui32,
		/*nicename("Bit 10")*/ _flags_bit_10 = 1ui32 << 10ui32,
		/*nicename("Bit 11")*/ _flags_bit_11 = 1ui32 << 11ui32,
		/*nicename("Bit 12")*/ _flags_bit_12 = 1ui32 << 12ui32,
		/*nicename("Bit 13")*/ _flags_bit_13 = 1ui32 << 13ui32,
		/*nicename("Bit 14")*/ _flags_bit_14 = 1ui32 << 14ui32,
		/*nicename("Bit 15")*/ _flags_bit_15 = 1ui32 << 15ui32,
		/*nicename("Bit 16")*/ _flags_bit_16 = 1ui32 << 16ui32,
		/*nicename("Bit 17")*/ _flags_bit_17 = 1ui32 << 17ui32,
		/*nicename("Bit 18")*/ _flags_bit_18 = 1ui32 << 18ui32,
		/*nicename("Bit 19")*/ _flags_bit_19 = 1ui32 << 19ui32,
		/*nicename("Bit 20")*/ _flags_bit_20 = 1ui32 << 20ui32,
		/*nicename("Bit 21")*/ _flags_bit_21 = 1ui32 << 21ui32,
		/*nicename("Bit 22")*/ _flags_bit_22 = 1ui32 << 22ui32,
		/*nicename("Bit 23")*/ _flags_bit_23 = 1ui32 << 23ui32,
		/*nicename("Bit 24")*/ _flags_bit_24 = 1ui32 << 24ui32,
		/*nicename("Bit 25")*/ _flags_bit_25 = 1ui32 << 25ui32,
		/*nicename("Bit 26")*/ _flags_bit_26 = 1ui32 << 26ui32,
		/*nicename("Bit 27")*/ _flags_bit_27 = 1ui32 << 27ui32,
		/*nicename("Bit 28")*/ _flags_bit_28 = 1ui32 << 28ui32,
		/*nicename("Bit 29")*/ _flags_bit_29 = 1ui32 << 29ui32,
		/*nicename("Bit 30")*/ _flags_bit_30 = 1ui32 << 30ui32,
		/*nicename("Bit 31")*/ _flags_bit_31 = 1ui32 << 31ui32,
	};

	struct nicename("Tracks") s_tracks_definition
	{
		enum nicename("Output Effect") e_output_effect : uint16_t
		{
			/*nicename("None")*/ _output_effect_none = 1ui16,
			/*nicename("Output Front Speakers")*/ _output_effect_output_front_speakers = 2ui16,
			/*nicename("Output Rear Speakers")*/ _output_effect_output_rear_speakers = 3ui16,
			/*nicename("Output Center Speakers")*/ _output_effect_output_center_speakers = 4ui16,
		};

		enum nicename("Flags") b_flags1 : uint16_t /* bitfield */
		{
			/*nicename("Fade In At Start")*/ _flags1_fade_in_at_start = 1ui16 << 0ui16,
			/*nicename("Fade Out At Stop")*/ _flags1_fade_out_at_stop = 1ui16 << 1ui16,
			/*nicename("Bit 2")*/ _flags1_bit_2 = 1ui16 << 2ui16,
			/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _flags1_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _flags1_bit_6 = 1ui16 << 6ui16,
			/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui16 << 15ui16,
		};

		DEPRECATED_string_id nicename("Name") name;
		b_flags1 nicename("Flags") flags;
		e_output_effect nicename("Output Effect") output_effect;
		float nicename("Gain") gain;
		TagReference nicename("In") in_reference;
		TagReference nicename("Loop") loop_reference;
		TagReference nicename("Out") out_reference;
		TagReference nicename("Alternate Loop") alternate_loop_reference;
		TagReference nicename("Alternate Out") alternate_out_reference;
		TagReference nicename("Alternate Transition In") alternate_transition_in_reference;
		TagReference nicename("Alternate Transition Out") alternate_transition_out_reference;
		float nicename("Fade In Duration") fade_in_duration;
		Undefined32 __unknown0;
		float nicename("Fade Out Duration") fade_out_duration;
		int16_t __unknown1;
		int16_t __unknown2;
		float nicename("Alt Crossfade Duration") alt_crossfade_duration;
		Undefined32 __unknown3;
		float nicename("Alternate Fade Out Duration") alternate_fade_out_duration;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
		Undefined32 __unknown9;
	};

	struct nicename("Detail Sounds") s_detail_sounds_definition
	{
		enum nicename("Flags") b_flags1 : uint32_t /* bitfield */
		{
			/*nicename("Don't Play With Alternate")*/ _flags1_dont_play_with_alternate = 1ui32 << 0ui32,
			/*nicename("Don't Play Without Alternate")*/ _flags1_dont_play_without_alternate = 1ui32 << 1ui32,
			/*nicename("Start Immediately With Loop")*/ _flags1_start_immediately_with_loop = 1ui32 << 2ui32,
			/*nicename("Bit 3")*/ _flags1_bit_3 = 1ui32 << 3ui32,
			/*nicename("Bit 4")*/ _flags1_bit_4 = 1ui32 << 4ui32,
			/*nicename("Bit 5")*/ _flags1_bit_5 = 1ui32 << 5ui32,
			/*nicename("Bit 6")*/ _flags1_bit_6 = 1ui32 << 6ui32,
			/*nicename("Bit 7")*/ _flags1_bit_7 = 1ui32 << 7ui32,
			/*nicename("Bit 8")*/ _flags1_bit_8 = 1ui32 << 8ui32,
			/*nicename("Bit 9")*/ _flags1_bit_9 = 1ui32 << 9ui32,
			/*nicename("Bit 10")*/ _flags1_bit_10 = 1ui32 << 10ui32,
			/*nicename("Bit 11")*/ _flags1_bit_11 = 1ui32 << 11ui32,
			/*nicename("Bit 12")*/ _flags1_bit_12 = 1ui32 << 12ui32,
			/*nicename("Bit 13")*/ _flags1_bit_13 = 1ui32 << 13ui32,
			/*nicename("Bit 14")*/ _flags1_bit_14 = 1ui32 << 14ui32,
			/*nicename("Bit 15")*/ _flags1_bit_15 = 1ui32 << 15ui32,
			/*nicename("Bit 16")*/ _flags1_bit_16 = 1ui32 << 16ui32,
			/*nicename("Bit 17")*/ _flags1_bit_17 = 1ui32 << 17ui32,
			/*nicename("Bit 18")*/ _flags1_bit_18 = 1ui32 << 18ui32,
			/*nicename("Bit 19")*/ _flags1_bit_19 = 1ui32 << 19ui32,
			/*nicename("Bit 20")*/ _flags1_bit_20 = 1ui32 << 20ui32,
			/*nicename("Bit 21")*/ _flags1_bit_21 = 1ui32 << 21ui32,
			/*nicename("Bit 22")*/ _flags1_bit_22 = 1ui32 << 22ui32,
			/*nicename("Bit 23")*/ _flags1_bit_23 = 1ui32 << 23ui32,
			/*nicename("Bit 24")*/ _flags1_bit_24 = 1ui32 << 24ui32,
			/*nicename("Bit 25")*/ _flags1_bit_25 = 1ui32 << 25ui32,
			/*nicename("Bit 26")*/ _flags1_bit_26 = 1ui32 << 26ui32,
			/*nicename("Bit 27")*/ _flags1_bit_27 = 1ui32 << 27ui32,
			/*nicename("Bit 28")*/ _flags1_bit_28 = 1ui32 << 28ui32,
			/*nicename("Bit 29")*/ _flags1_bit_29 = 1ui32 << 29ui32,
			/*nicename("Bit 30")*/ _flags1_bit_30 = 1ui32 << 30ui32,
			/*nicename("Bit 31")*/ _flags1_bit_31 = 1ui32 << 31ui32,
		};

		DEPRECATED_string_id nicename("Name") name;
		TagReference nicename("Sound") sound_reference;
		Undefined32 __unknown0;
		// Frequency Of Play : 
		float nicename("Random Period Bounds min") random_period_bounds_min;
		float nicename("Random Period Bounds max") random_period_bounds_max;
		float __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		b_flags1 nicename("Flags") flags;
		// Random Spatialization : 
		float nicename("Yaw Bounds min") yaw_bounds_min;
		float nicename("Yaw Bounds max") yaw_bounds_max;
		float nicename("Pitch Bounds min") pitch_bounds_min;
		float nicename("Pitch Bounds max") pitch_bounds_max;
		float nicename("Distance Bounds min") distance_bounds_min;
		float nicename("Distance Bounds max") distance_bounds_max;
	};

	b_flags nicename("Flags") flags;
	float __unknown0;
	float __unknown1;
	float __unknown2;
	float __unknown3;
	float __unknown4;
	e_sound_class nicename("Sound Class") sound_class;
	int16_t __unknown5;
	Undefined32 __unknown6;
	s_tag_block_definition<s_tracks_definition> nicename("Tracks") tracks_block;
	s_tag_block_definition<s_detail_sounds_definition> nicename("Detail Sounds") detail_sounds_block;
};

