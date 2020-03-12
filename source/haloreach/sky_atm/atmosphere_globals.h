#pragma once

#include <cseries/cseries.h>
#include <datatypes/enum.h>
#include <datatypes/flags.h>
#include <math/real_math.h>
#include <tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_atmosphere_globals_group_tag = 'atgf';

/* ---------- types */

enum e_transparent_sort_layer
{
	_transparent_sort_layer_invalid,
	_transparent_sort_layer_pre_pass,
	_transparent_sort_layer_normal,
	_transparent_sort_layer_post_pass,
	k_number_of_transparent_sort_layers
};

enum e_volume_texture_fog_flags
{
	_volume_texture_fog_disable_texture_rotation_bit, // fog texture's up direction will always match the camera's up direction
	k_number_of_volume_texture_fog_flags
};

struct s_volume_texture_fog_color
{
	string_id name;
	s_real_argb_color color;
};
static_assert(sizeof(s_volume_texture_fog_color) == 0x14);

struct s_volume_texture_fog_globals
{
	using t_transparent_sort_layer = c_enum<e_transparent_sort_layer, char>;
	using t_flags = c_flags<e_volume_texture_fog_flags, byte, k_number_of_volume_texture_fog_flags>;

	/*
	NOTE: The parameters below do not interpolate across lighting volumes. If you do not fade out
		the volume texture fog to 0, and do not transition from 0 to a new value in a different lighting
		volume but rather simply specify a different value directly, you will see a pop
	*/

	s_tag_reference fog_bitmap; // noise texture to use on the screen-aligned sheets of fog
	real texture_repeat_rate; // scaling factor to apply to fog UV coordinates
	real distance_between_sheets; // separating distance between sheets of fog
	real depth_fade_factor; // lower values (approaching 0) cause a smoother fade at scene boundaries, larger values (1 or more) make for a sharp transition
	real transparent_sort_distance; // distance from the camera where we sort the patchy fog effect (default: 100)
	t_transparent_sort_layer transparent_sort_layer;
	t_flags flags;
	c_typed_tag_block<s_volume_texture_fog_color> colors;
};
static_assert(sizeof(s_volume_texture_fog_globals) == 0x30);

struct s_atmosphere_globals
{
	s_volume_texture_fog_globals volume_texture_fog;
};
static_assert(sizeof(s_atmosphere_globals) == 0x30);
