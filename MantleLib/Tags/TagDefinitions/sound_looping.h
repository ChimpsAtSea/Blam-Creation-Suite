#pragma once

struct nicename("Sound Looping") group('lsnd') s_sound_looping_definition
{
	struct nicename("Tracks") s_track_block_definition;
	struct nicename("Detail Sounds") s_detail_sound_block_definition;

	int32_t nicename("Flags") flags; 
	float __unknown; 
	float __unknown2; 
	float __unknown3; 
	float __unknown4; 
	float __unknown5; 
	int16_t nicename("Sound Class") sound_class; 
	int16_t __unknown6; 
	Undefined32 __unknown7; 
	s_tag_block_definition<s_track_block_definition> nicename("Tracks") tracks_block; 
	s_tag_block_definition<s_detail_sound_block_definition> nicename("Detail Sounds") detail_sounds_block; 

	struct nicename("track") s_track_block_definition
	{
		string_id nicename("Name") name; 
		uint16_t nicename("Flags") flags; 
		int16_t nicename("Output Effect") output_effect; 
		float nicename("Gain") gain; 
		TagReference nicename("In") in_reference; 
		TagReference nicename("Loop") loop_reference; 
		TagReference nicename("Out") out_reference; 
		TagReference nicename("Alternate Loop") alternate_loop_reference; 
		TagReference nicename("Alternate Out") alternate_out_reference; 
		TagReference nicename("Alternate Transition In") alternate_transition_in_reference; 
		TagReference nicename("Alternate Transition Out") alternate_transition_out_reference; 
		float nicename("Fade In Duration") fade_in_duration; 
		Undefined32 __unknown; 
		float nicename("Fade Out Duration") fade_out_duration; 
		int16_t __unknown2; 
		int16_t __unknown3; 
		float nicename("Alt Crossfade Duration") alt_crossfade_duration; 
		Undefined32 __unknown4; 
		float nicename("Alternate Fade Out Duration") alternate_fade_out_duration; 
		Undefined32 __unknown5; 
		Undefined32 __unknown6; 
		Undefined32 __unknown7; 
		Undefined32 __unknown8; 
		Undefined32 __unknown9; 
		Undefined32 __unknown10; 
	};

	struct nicename("detail_sound") s_detail_sound_block_definition
	{
		string_id nicename("Name") name; 
		TagReference nicename("Sound") sound_reference; 
		Undefined32 __unknown; 
		// comment
		float nicename("Random Period Bounds min") random_period_bounds_min; 
		float nicename("Random Period Bounds max") random_period_bounds_max; 
		float __unknown2; 
		Undefined32 __unknown3; 
		Undefined32 __unknown4; 
		int32_t nicename("Flags") flags; 
		// comment
		float nicename("Yaw Bounds min") yaw_bounds_min; 
		float nicename("Yaw Bounds max") yaw_bounds_max; 
		float nicename("Pitch Bounds min") pitch_bounds_min; 
		float nicename("Pitch Bounds max") pitch_bounds_max; 
		float nicename("Distance Bounds min") distance_bounds_min; 
		float nicename("Distance Bounds max") distance_bounds_max; 
	};
};
