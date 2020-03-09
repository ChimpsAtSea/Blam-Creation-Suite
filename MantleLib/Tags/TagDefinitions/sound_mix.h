#pragma once

struct nicename("sound_mix") group('snmx') s_sound_mix_definition
{
	float __unknown0;
	float __unknown1;
	float __unknown2;
	float __unknown3;
	// First Person Left Side Mix : 
	float nicename("Left Stereo Gain") left_stereo_gain;
	float nicename("Right Stereo Gain") right_stereo_gain;
	// First Person Middle Mix : 
	float nicename("Left Stereo Gain") left_stereo_gain1;
	float nicename("Right Stereo Gain") right_stereo_gain1;
	// First Person Right Side Mix : 
	float nicename("Left Stereo Gain") left_stereo_gain2;
	float nicename("Right Stereo Gain") right_stereo_gain2;
	// First Person Stereo Mix : 
	float nicename("Front Speaker Gain") front_speaker_gain;
	float nicename("Rear Speaker Gain") rear_speaker_gain;
	// Ambient Stereo Mix : 
	float nicename("Front Speaker Gain") front_speaker_gain1;
	float nicename("Rear Speaker Gain") rear_speaker_gain1;
	// Global Mix : 
	float nicename("Mono Unspatialized Gain") mono_unspatialized_gain;
	float nicename("Stereo To 3D Gain") stereo_to_3d_gain;
	float nicename("Rear Surround To Front Stereo Gain") rear_surround_to_front_stereo_gain;
	// Surround Center Mix : 
	float nicename("Front Speaker Gain") front_speaker_gain2;
	float nicename("Center Speaker Gain") center_speaker_gain;
	// Stereo Center Mix : 
	float __unknown4;
	float __unknown5;
	float __unknown6;
	float __unknown7;
	float __unknown8;
	float __unknown9;
	float __unknown10;
	float __unknown11;
	float nicename("Solo Player Fade Out Delay") solo_player_fade_out_delay;
	float nicename("Solo Player Fade Out Time") solo_player_fade_out_time;
	float nicename("Solo Player Fade In Time") solo_player_fade_in_time;
	float nicename("Game Music Fade Out Time") game_music_fade_out_time;
	TagReference __unknown12;
	float __unknown13;
	float __unknown14;
};

