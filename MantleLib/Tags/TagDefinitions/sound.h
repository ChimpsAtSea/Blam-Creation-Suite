#pragma once

struct nicename("sound") group('snd!') s_sound_definition
{
	enum nicename("Sound Class") e_sound_class : uint8_t
	{
		/*nicename("projectile_impact")*/ _sound_class_projectile_impact = 0ui8,
		/*nicename("projectile_detonation")*/ _sound_class_projectile_detonation = 1ui8,
		/*nicename("projectile_flyby")*/ _sound_class_projectile_flyby = 2ui8,
		/*nicename("projectile_detonation_lod")*/ _sound_class_projectile_detonation_lod = 3ui8,
		/*nicename("weapon_fire")*/ _sound_class_weapon_fire = 4ui8,
		/*nicename("weapon_ready")*/ _sound_class_weapon_ready = 5ui8,
		/*nicename("weapon_reload")*/ _sound_class_weapon_reload = 6ui8,
		/*nicename("weapon_empty")*/ _sound_class_weapon_empty = 7ui8,
		/*nicename("weapon_charge")*/ _sound_class_weapon_charge = 8ui8,
		/*nicename("weapon_overheat")*/ _sound_class_weapon_overheat = 9ui8,
		/*nicename("weapon_idle")*/ _sound_class_weapon_idle = 10ui8,
		/*nicename("weapon_melee")*/ _sound_class_weapon_melee = 11ui8,
		/*nicename("weapon_animation")*/ _sound_class_weapon_animation = 12ui8,
		/*nicename("object_impacts")*/ _sound_class_object_impacts = 13ui8,
		/*nicename("particle_impacts")*/ _sound_class_particle_impacts = 14ui8,
		/*nicename("weapon_fire_lod")*/ _sound_class_weapon_fire_lod = 15ui8,
		/*nicename("water_transitions")*/ _sound_class_water_transitions = 16ui8,
		/*nicename("lowpass_effects")*/ _sound_class_lowpass_effects = 17ui8,
		/*nicename("unit_footsteps")*/ _sound_class_unit_footsteps = 18ui8,
		/*nicename("unit_dialog")*/ _sound_class_unit_dialog = 19ui8,
		/*nicename("unit_animation")*/ _sound_class_unit_animation = 20ui8,
		/*nicename("unit_unused!")*/ _sound_class_unit_unused = 21ui8,
		/*nicename("vehicle_collision")*/ _sound_class_vehicle_collision = 22ui8,
		/*nicename("vehicle_engine")*/ _sound_class_vehicle_engine = 23ui8,
		/*nicename("vehicle_animation")*/ _sound_class_vehicle_animation = 24ui8,
		/*nicename("vehicle_engine_lod")*/ _sound_class_vehicle_engine_lod = 25ui8,
		/*nicename("device_door")*/ _sound_class_device_door = 26ui8,
		/*nicename("device_unused0!")*/ _sound_class_device_unused0 = 27ui8,
		/*nicename("device_machinery")*/ _sound_class_device_machinery = 28ui8,
		/*nicename("device_stationary")*/ _sound_class_device_stationary = 29ui8,
		/*nicename("device_unused1!")*/ _sound_class_device_unused1 = 30ui8,
		/*nicename("device_unused2!")*/ _sound_class_device_unused2 = 31ui8,
		/*nicename("music")*/ _sound_class_music = 32ui8,
		/*nicename("ambient_nature")*/ _sound_class_ambient_nature = 33ui8,
		/*nicename("ambient_machinery")*/ _sound_class_ambient_machinery = 34ui8,
		/*nicename("ambient_stationary")*/ _sound_class_ambient_stationary = 35ui8,
		/*nicename("huge_ass")*/ _sound_class_huge_ass = 36ui8,
		/*nicename("object_looping")*/ _sound_class_object_looping = 37ui8,
		/*nicename("cinematic_music")*/ _sound_class_cinematic_music = 38ui8,
		/*nicename("unknown_unused0!")*/ _sound_class_unknown_unused0 = 39ui8,
		/*nicename("unknown_unused1!")*/ _sound_class_unknown_unused1 = 40ui8,
		/*nicename("ambient_flock")*/ _sound_class_ambient_flock = 41ui8,
		/*nicename("no_pad")*/ _sound_class_no_pad = 42ui8,
		/*nicename("no_pad_stationary")*/ _sound_class_no_pad_stationary = 43ui8,
		/*nicename("equipment_effect")*/ _sound_class_equipment_effect = 44ui8,
		/*nicename("mission_dialog")*/ _sound_class_mission_dialog = 45ui8,
		/*nicename("cinematic_dialog")*/ _sound_class_cinematic_dialog = 46ui8,
		/*nicename("scripted_cinematic_foley")*/ _sound_class_scripted_cinematic_foley = 47ui8,
		/*nicename("game_event")*/ _sound_class_game_event = 48ui8,
		/*nicename("ui")*/ _sound_class_ui = 49ui8,
		/*nicename("test")*/ _sound_class_test = 50ui8,
		/*nicename("multiplayer_dialog")*/ _sound_class_multiplayer_dialog = 51ui8,
		/*nicename("ambient_nature_details")*/ _sound_class_ambient_nature_details = 52ui8,
		/*nicename("ambient_machinery_details")*/ _sound_class_ambient_machinery_details = 53ui8,
		/*nicename("inside_surround_tail")*/ _sound_class_inside_surround_tail = 54ui8,
		/*nicename("outside_surround_tail")*/ _sound_class_outside_surround_tail = 55ui8,
		/*nicename("vehicle_detonation")*/ _sound_class_vehicle_detonation = 56ui8,
		/*nicename("ambient_detonation")*/ _sound_class_ambient_detonation = 57ui8,
		/*nicename("first_person_inside")*/ _sound_class_first_person_inside = 58ui8,
		/*nicename("first_person_outside")*/ _sound_class_first_person_outside = 59ui8,
		/*nicename("first_person_anywhere")*/ _sound_class_first_person_anywhere = 60ui8,
		/*nicename("space_projectile_detonation")*/ _sound_class_space_projectile_detonation = 61ui8,
		/*nicename("space_projectile_flyby")*/ _sound_class_space_projectile_flyby = 62ui8,
		/*nicename("space_vehicle_engine")*/ _sound_class_space_vehicle_engine = 63ui8,
		/*nicename("space_weapon_fire")*/ _sound_class_space_weapon_fire = 64ui8,
		/*nicename("player_voice_team")*/ _sound_class_player_voice_team = 65ui8,
		/*nicename("player_voice_proxy")*/ _sound_class_player_voice_proxy = 66ui8,
		/*nicename("projectile_impact_postpone")*/ _sound_class_projectile_impact_postpone = 67ui8,
		/*nicename("unit_footsteps_postpone")*/ _sound_class_unit_footsteps_postpone = 68ui8,
		/*nicename("weapon_ready_third_person")*/ _sound_class_weapon_ready_third_person = 69ui8,
		/*nicename("ui_music")*/ _sound_class_ui_music = 70ui8,
	};

	enum nicename("Flags") b_flags : uint16_t /* bitfield */
	{
		/*nicename("Fit To ADPCM Blocksize")*/ _flags_fit_to_adpcm_blocksize = 1ui16 << 0ui16,
		/*nicename("Split Long Sound Into Permutations")*/ _flags_split_long_sound_into_permutations = 1ui16 << 1ui16,
		/*nicename("Bit 2")*/ _flags_bit_2 = 1ui16 << 2ui16,
		/*nicename("Bit 3")*/ _flags_bit_3 = 1ui16 << 3ui16,
		/*nicename("Bit 4")*/ _flags_bit_4 = 1ui16 << 4ui16,
		/*nicename("Bit 5")*/ _flags_bit_5 = 1ui16 << 5ui16,
		/*nicename("Bit 6")*/ _flags_bit_6 = 1ui16 << 6ui16,
		/*nicename("Bit 7")*/ _flags_bit_7 = 1ui16 << 7ui16,
		/*nicename("Bit 8")*/ _flags_bit_8 = 1ui16 << 8ui16,
		/*nicename("Bit 9")*/ _flags_bit_9 = 1ui16 << 9ui16,
		/*nicename("Bit 10")*/ _flags_bit_10 = 1ui16 << 10ui16,
		/*nicename("Bit 11")*/ _flags_bit_11 = 1ui16 << 11ui16,
		/*nicename("Bit 12")*/ _flags_bit_12 = 1ui16 << 12ui16,
		/*nicename("Bit 13")*/ _flags_bit_13 = 1ui16 << 13ui16,
		/*nicename("Bit 14")*/ _flags_bit_14 = 1ui16 << 14ui16,
		/*nicename("Bit 15")*/ _flags_bit_15 = 1ui16 << 15ui16,
	};

	struct nicename("Extra Info") s_extra_info_definition
	{
		struct nicename("Unknown") s_unknown_definition
		{
			struct nicename("Unknown") s_unknown1_definition
			{
				int32_t __unknown0;
				int32_t __unknown1;
				int32_t __unknown2;
			};

			Undefined32 __unknown0;
			Undefined32 __unknown1;
			Undefined32 __unknown2;
			Undefined32 __unknown3;
			s_tag_block_definition<s_unknown1_definition> __unknown4;
		};

		s_tag_block_definition<s_unknown_definition> __unknown0;
		DataReference __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		int32_t __unknown4;
	};

	b_flags nicename("Flags") flags;
	e_sound_class nicename("Sound Class") sound_class;
	int8_t __unknown0;
	int16_t nicename("[ugh!] Platform Codec Index") ugh_platform_codec_index;
	int16_t nicename("[ugh!] Pitch Range Index") ugh_pitch_range_index;
	int16_t nicename("[ugh!] Language B Index") ugh_language_b_index;
	int16_t nicename("Unknown ugh! Value") unknown_ugh_value;
	int16_t __unknown1;
	int16_t nicename("[ugh!] Playback Parameter Index") ugh_playback_parameter_index;
	int16_t nicename("[ugh!] Scale Index") ugh_scale_index;
	int8_t nicename("[ugh!] Promotion Index") ugh_promotion_index;
	int8_t nicename("[ugh!] Custom Playback Index") ugh_custom_playback_index;
	int16_t __unknown2;
	int16_t __unknown3;
	int32_t __unknown4;
	int32_t nicename("[zone] Asset Datum") zone_asset_datum;
	uint16_t nicename("[easy read] Index") easy_read_index;
	uint16_t nicename("[easy read] Salt") easy_read_salt;
	int32_t nicename("Useless Padding") useless_padding;
	s_tag_block_definition<s_extra_info_definition> nicename("Extra Info") extra_info_block;
};

