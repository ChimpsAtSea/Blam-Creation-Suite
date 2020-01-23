#pragma once

struct nicename("Sound Classes") group('sncl') s_sound_classes_definition
{
	struct nicename("Sound Classes") s_sound_class_block_definition;

	// comment
	s_tag_block_definition<s_sound_class_block_definition> nicename("Sound Classes") sound_classes_block; 

	struct nicename("sound_class") s_sound_class_block_definition
	{
		int16_t nicename("Max Sounds Per Tag") max_sounds_per_tag; 
		int16_t nicename("Max Sounds Per Object") max_sounds_per_object; 
		int32_t __unknown; 
		int32_t nicename("Preemption Time") preemption_time; 
		uint16_t nicename("Internal Flags") internal_flags; 
		uint16_t nicename("Flags") flags; 
		int16_t nicename("Priority") priority; 
		int8_t nicename("Cache Miss Mode") cache_miss_mode; 
		int8_t __unknown2; 
		int8_t __unknown3; 
		int8_t __unknown4; 
		int8_t __unknown5; 
		int8_t __unknown6; 
		float nicename("Reverb Gain") reverb_gain; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		float __unknown10; 
		float __unknown11; 
		Undefined32 __unknown12; 
		Undefined32 __unknown13; 
		float __unknown14; 
		Undefined32 __unknown15; 
		float __unknown16; 
		float __unknown17; 
		float nicename("Distance Bounds min") distance_bounds_min; 
		float __unknown18; 
		float __unknown19; 
		float nicename("Distance Bounds max") distance_bounds_max; 
		float __unknown20; 
		float nicename("Gain Bounds min") gain_bounds_min; 
		float nicename("Gain Bounds max") gain_bounds_max; 
		float __unknown21; 
		float __unknown22; 
		float __unknown23; 
		float nicename("Cutscene Ducking") cutscene_ducking; 
		float nicename("Cutscene Ducking Fade In Time") cutscene_ducking_fade_in_time; 
		float nicename("Cutscene Ducking Sustain") cutscene_ducking_sustain; 
		float nicename("Cutscene Ducking Fade Out Time") cutscene_ducking_fade_out_time; 
		float nicename("Scripted Dialog Ducking") scripted_dialog_ducking; 
		float nicename("Scripted Dialog Ducking Fade In") scripted_dialog_ducking_fade_in; 
		Undefined32 __unknown24; 
		float __unknown25; 
		float __unknown26; 
		float __unknown27; 
		Undefined32 __unknown28; 
		float __unknown29; 
		float __unknown30; 
		float __unknown31; 
		Undefined32 __unknown32; 
		float __unknown33; 
		float nicename("Doppler Factor") doppler_factor; 
		int8_t nicename("Stereo Playback Type") stereo_playback_type; 
		int8_t __unknown34; 
		int8_t __unknown35; 
		int8_t __unknown36; 
		float nicename("Transmission Multiplier") transmission_multiplier; 
		Undefined32 __unknown37; 
		int32_t __unknown38; 
		float __unknown39; 
		Undefined32 __unknown40; 
		int32_t __unknown41; 
		Undefined32 __unknown42; 
	};
};
