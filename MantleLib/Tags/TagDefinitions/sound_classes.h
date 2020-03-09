#pragma once

struct nicename("sound_classes") group('sncl') s_sound_classes_definition
{
	struct nicename("Sound Classes") s_sound_classes1_definition
	{
		enum nicename("Cache Miss Mode") e_cache_miss_mode : uint8_t
		{
			/*nicename("Discard")*/ _cache_miss_mode_discard = 1ui8,
			/*nicename("Postpone")*/ _cache_miss_mode_postpone = 2ui8,
		};

		enum nicename("Stereo Playback Type") e_stereo_playback_type : uint8_t
		{
			/*nicename("First Person")*/ _stereo_playback_type_first_person = 1ui8,
			/*nicename("Ambient")*/ _stereo_playback_type_ambient = 2ui8,
		};

		enum nicename("Internal Flags") b_internal_flags : uint16_t /* bitfield */
		{
			/*nicename("Valid")*/ _internal_flags_valid = 1ui16 << 0ui16,
			/*nicename("Is Speech")*/ _internal_flags_is_speech = 1ui16 << 1ui16,
			/*nicename("Scripted")*/ _internal_flags_scripted = 1ui16 << 2ui16,
			/*nicename("Stops With Object")*/ _internal_flags_stops_with_object = 1ui16 << 3ui16,
			/*nicename("Bit 4")*/ _internal_flags_bit_4 = 1ui16 << 4ui16,
			/*nicename("Bit 5")*/ _internal_flags_bit_5 = 1ui16 << 5ui16,
			/*nicename("Bit 6")*/ _internal_flags_bit_6 = 1ui16 << 6ui16,
			/*nicename("Multilingual")*/ _internal_flags_multilingual = 1ui16 << 7ui16,
			/*nicename("Bit 8")*/ _internal_flags_bit_8 = 1ui16 << 8ui16,
			/*nicename("Bit 9")*/ _internal_flags_bit_9 = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _internal_flags_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _internal_flags_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _internal_flags_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _internal_flags_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _internal_flags_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _internal_flags_bit_15 = 1ui16 << 15ui16,
		};

		enum nicename("Flags") b_flags : uint16_t /* bitfield */
		{
			/*nicename("Plays During Pause")*/ _flags_plays_during_pause = 1ui16 << 0ui16,
			/*nicename("Dry Stereo Mix")*/ _flags_dry_stereo_mix = 1ui16 << 1ui16,
			/*nicename("No Object Obstruction")*/ _flags_no_object_obstruction = 1ui16 << 2ui16,
			/*nicename("Use Center Speaker Unspatialized")*/ _flags_use_center_speaker_unspatialized = 1ui16 << 3ui16,
			/*nicename("Send (mono) to LFE")*/ _flags_send_mono_to_lfe = 1ui16 << 4ui16,
			/*nicename("Deterministic")*/ _flags_deterministic = 1ui16 << 5ui16,
			/*nicename("Use Huge Transmission")*/ _flags_use_huge_transmission = 1ui16 << 6ui16,
			/*nicename("Always Use Speakers")*/ _flags_always_use_speakers = 1ui16 << 7ui16,
			/*nicename("Don't Strip From Mainmenu")*/ _flags_dont_strip_from_mainmenu = 1ui16 << 8ui16,
			/*nicename("Ignore Stereo Headroom")*/ _flags_ignore_stereo_headroom = 1ui16 << 9ui16,
			/*nicename("Bit 10")*/ _flags_bit_10 = 1ui16 << 10ui16,
			/*nicename("Bit 11")*/ _flags_bit_11 = 1ui16 << 11ui16,
			/*nicename("Bit 12")*/ _flags_bit_12 = 1ui16 << 12ui16,
			/*nicename("Bit 13")*/ _flags_bit_13 = 1ui16 << 13ui16,
			/*nicename("Bit 14")*/ _flags_bit_14 = 1ui16 << 14ui16,
			/*nicename("Bit 15")*/ _flags_bit_15 = 1ui16 << 15ui16,
		};

		int16_t nicename("Max Sounds Per Tag") max_sounds_per_tag;
		int16_t nicename("Max Sounds Per Object") max_sounds_per_object;
		int32_t __unknown0;
		int32_t nicename("Preemption Time") preemption_time;
		b_internal_flags nicename("Internal Flags") internal_flags;
		b_flags nicename("Flags") flags;
		int16_t nicename("Priority") priority;
		e_cache_miss_mode nicename("Cache Miss Mode") cache_miss_mode;
		int8_t __unknown1;
		int8_t __unknown2;
		int8_t __unknown3;
		int8_t __unknown4;
		int8_t __unknown5;
		float nicename("Reverb Gain") reverb_gain;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
		Undefined32 __unknown8;
		float __unknown9;
		float __unknown10;
		Undefined32 __unknown11;
		Undefined32 __unknown12;
		float __unknown13;
		Undefined32 __unknown14;
		float __unknown15;
		float __unknown16;
		float nicename("Distance Bounds min") distance_bounds_min;
		float __unknown17;
		float __unknown18;
		float nicename("Distance Bounds max") distance_bounds_max;
		float __unknown19;
		float nicename("Gain Bounds min") gain_bounds_min;
		float nicename("Gain Bounds max") gain_bounds_max;
		float __unknown20;
		float __unknown21;
		float __unknown22;
		float nicename("Cutscene Ducking") cutscene_ducking;
		float nicename("Cutscene Ducking Fade In Time") cutscene_ducking_fade_in_time;
		float nicename("Cutscene Ducking Sustain") cutscene_ducking_sustain;
		float nicename("Cutscene Ducking Fade Out Time") cutscene_ducking_fade_out_time;
		float nicename("Scripted Dialog Ducking") scripted_dialog_ducking;
		float nicename("Scripted Dialog Ducking Fade In") scripted_dialog_ducking_fade_in;
		Undefined32 __unknown23;
		float __unknown24;
		float __unknown25;
		float __unknown26;
		Undefined32 __unknown27;
		float __unknown28;
		float __unknown29;
		float __unknown30;
		Undefined32 __unknown31;
		float __unknown32;
		float nicename("Doppler Factor") doppler_factor;
		e_stereo_playback_type nicename("Stereo Playback Type") stereo_playback_type;
		int8_t __unknown33;
		int8_t __unknown34;
		int8_t __unknown35;
		float nicename("Transmission Multiplier") transmission_multiplier;
		Undefined32 __unknown36;
		int32_t __unknown37;
		float __unknown38;
		Undefined32 __unknown39;
		int32_t __unknown40;
		Undefined32 __unknown41;
	};

	/* Index Names : Ripped from the executable:
	   0 - projectile_impact
	   1 - projectile_detonation
	   2 - projectile_flyby
	   3 - projectile_detonation_lod
	   4 - weapon_fire
	   5 - weapon_ready
	   6 - weapon_reload
	   7 - weapon_empty
	   8 - weapon_charge
	   9 - weapon_overheat
	   10 - weapon_idle
	   11 - weapon_melee
	   12 - weapon_animation
	   13 - object_impacts
	   14 - particle_impacts
	   15 - weapon_fire_lod
	   16 - water_transitions
	   17 - lowpass_effects
	   18 - unit_footsteps
	   19 - unit_dialog
	   20 - unit_animation
	   21 - unit_unused!
	   22 - vehicle_collision
	   23 - vehicle_engine
	   24 - vehicle_animation
	   25 - vehicle_engine_lod
	   26 - device_door
	   27 - device_unused0!
	   28 - device_machinery
	   29 - device_stationary
	   30 - device_unused1!
	   31 - device_unused2!
	   32 - music
	   33 - ambient_nature
	   34 - ambient_machinery
	   35 - ambient_stationary
	   36 - huge_ass
	   37 - object_looping
	   38 - cinematic_music
	   39 - unknown_unused0!
	   40 - unknown_unused1!
	   41 - ambient_flock
	   42 - no_pad
	   43 - no_pad_stationary
	   44 - equipment_effect
	   45 - mission_dialog
	   46 - cinematic_dialog
	   47 - scripted_cinematic_foley
	   48 - game_event
	   49 - ui
	   50 - test
	   51 - multiplayer_dialog
	   52 - ambient_nature_details
	   53 - ambient_machinery_details
	   54 - inside_surround_tail
	   55 - outside_surround_tail
	   56 - vehicle_detonation
	   57 - ambient_detonation
	   58 - first_person_inside
	   59 - first_person_outside
	   60 - first_person_anywhere
	   61 - space_projectile_detonation
	   62 - space_projectile_flyby
	   63 - space_vehicle_engine
	   64 - space_weapon_fire
	   65 - player_voice_team
	   66 - player_voice_proxy
	   67 - projectile_impact_postpone
	   68 - unit_footsteps_postpone
	   69 - weapon_ready_third_person
	   70 - ui_music */
	s_tag_block_definition<s_sound_classes1_definition> nicename("Sound Classes") sound_classes_block;
};

