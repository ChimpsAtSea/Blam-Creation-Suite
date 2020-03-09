#pragma once

struct nicename("camera_shake") group('csdt') s_camera_shake_definition
{
	enum nicename("Wobble Function") e_wobble_function : uint16_t
	{
		/*nicename("One")*/ _wobble_function_one = 1ui16,
		/*nicename("Zero")*/ _wobble_function_zero = 2ui16,
		/*nicename("Cosine")*/ _wobble_function_cosine = 3ui16,
		/*nicename("Cosine (Variable Period)")*/ _wobble_function_cosine_variable_period = 4ui16,
		/*nicename("Diagonal Wave")*/ _wobble_function_diagonal_wave = 5ui16,
		/*nicename("Diagonal Wave (Variable Period)")*/ _wobble_function_diagonal_wave_variable_period = 6ui16,
		/*nicename("Slide")*/ _wobble_function_slide = 7ui16,
		/*nicename("Slide (Variable Period)")*/ _wobble_function_slide_variable_period = 8ui16,
		/*nicename("Noise")*/ _wobble_function_noise = 9ui16,
		/*nicename("Jitter")*/ _wobble_function_jitter = 10ui16,
		/*nicename("Wander")*/ _wobble_function_wander = 11ui16,
		/*nicename("Spark")*/ _wobble_function_spark = 12ui16,
	};

	// Temporary Camera Impulse : 
	float nicename("Duration") duration;
	DataReference nicename("Fade Function") fade_function_data_reference;
	float nicename("Rotation") rotation;
	float nicename("Pushback") pushback;
	float nicename("Jitter min") jitter_min;
	float nicename("Jitter max") jitter_max;
	// Camera Shaking : 
	float nicename("Duration") duration1;
	DataReference nicename("Falloff Function") falloff_function_data_reference;
	float nicename("Random Translation") random_translation;
	float nicename("Random Rotation") random_rotation;
	float nicename("Wobble Function Period") wobble_function_period;
	float nicename("Wobble Weight") wobble_weight;
	e_wobble_function nicename("Wobble Function") wobble_function;
	int16_t __unknown0;
	TagReference __unknown1;
	Undefined32 __unknown2;
};

