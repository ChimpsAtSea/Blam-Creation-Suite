#pragma once

struct nicename("sound_environment") group('snde') s_sound_environment_definition
{
	float nicename("Room Intensity dB") room_intensity_db;
	float nicename("Room Intesnity High Frequency dB") room_intesnity_high_frequency_db;
	float nicename("Room Rolloff") room_rolloff;
	float nicename("Decay Time") decay_time;
	float nicename("Decay High Frequency Ration") decay_high_frequency_ration;
	float nicename("Reflections Intensity dB") reflections_intensity_db;
	float nicename("Reflections Delay") reflections_delay;
	float nicename("Reverb Intensity dB") reverb_intensity_db;
	float nicename("Reverb Delay") reverb_delay;
	float nicename("Diffusion") diffusion;
	float nicename("Density") density;
	float nicename("High Frequency Reference Hz") high_frequency_reference_hz;
	Undefined32 __unknown0;
	Undefined32 __unknown1;
};

