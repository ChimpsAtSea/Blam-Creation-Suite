#pragma once

#include <cseries/cseries.h>
#include <datatypes/flags.h>
#include <math/real_math.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_camera_fx_settings_group_tag = 'cfxs';

/* ---------- classes */

class c_camera_fx_settings
{
	enum e_parameter_flags
	{
		_parameter_use_default_bit,
		_parameter_maximum_change_is_relative_bit,
		_parameter_auto_adjust_target_bit,
		_parameter_unused3_bit,
		_parameter_fixed_bit,
		_parameter_unused5_bit,
		_parameter_fixed2_bit,
		k_number_of_parameter_flags
	};

	struct s_parameter
	{
		c_flags<e_parameter_flags, word> flags;
	};
	static_assert(sizeof(s_parameter) == 0x2);

	struct s_word_parameter : s_parameter
	{
		word absolute_value;
	};
	static_assert(sizeof(s_word_parameter) == 0x4);

	struct s_real_instant_parameter : s_parameter
	{
		real absolute_value;
	};
	static_assert(sizeof(s_real_instant_parameter) == 0x8);

	struct s_real_parameter : s_real_instant_parameter
	{
		real maximum_change;
		real blend_speed;
	};
	static_assert(sizeof(s_real_parameter) == 0x10);

	struct s_real_exposure_parameter : s_real_parameter
	{
		s_real_bounds range; // the absolute target exposure is clamped to this range
		real auto_exposure_screen_brightness; // [0.0001-1] how bright you want the screen to be - auto-exposure will make it happen
		real auto_exposure_delay; // [0.1-1] seconds; how long to wait before auto-exposure kicks in to adjust the exposure
	};
	static_assert(sizeof(s_real_exposure_parameter) == 0x20);

	struct s_color_parameter : s_parameter
	{
		s_real_rgb_color color;
	};
	static_assert(sizeof(s_color_parameter) == 0x10);

private:
	// Controls the brightness of the scene, like exposure time on your camera.
	// The actual exposure always blends towards the target exposure.
	// With auto-exposure on, the target exposure is calculated relative to the brightness of what is on screen.
	s_real_exposure_parameter m_exposure;

	// How sensitive auto exposure is to small bright patches on the screen (like the sun)
	s_real_instant_parameter m_auto_exposure_sensitivity;

	// These parameters control bloom off the highlights (really bright stuff)
	s_real_parameter m_bloom_highlight;

	// These parameters control bloom off everything (bright and dark)
	s_real_parameter m_bloom_inherent;

	// These parameters control how bright the bloom is, relative to the underlying scene
	s_real_parameter m_bloom_intensity;

	s_color_parameter m_bloom_large_color;
	s_color_parameter m_bloom_medium_color;
	s_color_parameter m_bloom_small_color;

	s_real_parameter m_bling_intensity;
	s_real_parameter m_bling_size;
	s_real_parameter m_bling_angle;
	s_word_parameter m_bling_count;

	// These parameters control the self-illumination exposure
	// preferred is the preferred exposure, and scale controls
	// how much it varies from the preferred exposure
	s_real_parameter m_self_illum_exposure;

	// How much self illum exposure is allowed to change
	// 0 means no change at all, 1 means it will
	// equal the normal exposure
	s_real_parameter m_self_illum_change;
};
static_assert(sizeof(c_camera_fx_settings) == 0xDC);
