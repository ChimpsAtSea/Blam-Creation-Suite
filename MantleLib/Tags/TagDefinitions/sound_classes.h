#pragma once

struct nicename("Sound Classes") group('sncl') s_sound_classes_definition
{
	struct nicename("Sound Classes") s_sound_class_block_definition;

	// comment
	s_tag_block_definition<s_sound_class_block_definition> nicename("Sound Classes") sound_classes_block; 

	struct nicename("sound_class") s_sound_class_block_definition
	{
		signed short nicename("Max Sounds Per Tag") max_sounds_per_tag; 
		signed short nicename("Max Sounds Per Object") max_sounds_per_object; 
		signed int __unknown; 
		signed int nicename("Preemption Time") preemption_time; 
		unsigned short nicename("Internal Flags") internal_flags; 
		unsigned short nicename("Flags") flags; 
		signed short nicename("Priority") priority; 
		signed char nicename("Cache Miss Mode") cache_miss_mode; 
		signed char __unknown2; 
		signed char __unknown3; 
		signed char __unknown4; 
		signed char __unknown5; 
		signed char __unknown6; 
		float nicename("Reverb Gain") reverb_gain; 
		Unknown32 __unknown7; 
		Unknown32 __unknown8; 
		Unknown32 __unknown9; 
		float __unknown10; 
		float __unknown11; 
		Unknown32 __unknown12; 
		Unknown32 __unknown13; 
		float __unknown14; 
		Unknown32 __unknown15; 
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
		Unknown32 __unknown24; 
		float __unknown25; 
		float __unknown26; 
		float __unknown27; 
		Unknown32 __unknown28; 
		float __unknown29; 
		float __unknown30; 
		float __unknown31; 
		Unknown32 __unknown32; 
		float __unknown33; 
		float nicename("Doppler Factor") doppler_factor; 
		signed char nicename("Stereo Playback Type") stereo_playback_type; 
		signed char __unknown34; 
		signed char __unknown35; 
		signed char __unknown36; 
		float nicename("Transmission Multiplier") transmission_multiplier; 
		Unknown32 __unknown37; 
		signed int __unknown38; 
		float __unknown39; 
		Unknown32 __unknown40; 
		signed int __unknown41; 
		Unknown32 __unknown42; 
	};
};
