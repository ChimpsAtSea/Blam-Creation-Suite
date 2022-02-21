#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/datatypes/enum.h>
#include <blamlib/datatypes/flags.h>
#include <blamlib/math/real_math.h>
#include <blamlib/tag_files/string_ids.h>
#include <blamlib/tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_chud_group_tag = 'chdt';
constexpr tag k_chud_animation_group_tag = 'chad';
constexpr tag k_chud_globals_group_tag = 'chgd';

/* ---------- types */

enum e_chud_animation_flags
{
	_chud_animation_unknown0_bit,
	_chud_animation_loops_bit,
	_chud_animation_oscillates_bit,
	_chud_animation_unknown3_bit,
	_chud_animation_unknown4_bit,
	_chud_animation_unknown5_bit,
	_chud_animation_unknown6_bit,
	_chud_animation_unknown7_bit,
	k_number_of_chud_animation_flags
};

struct s_chud_animation_position_frame
{
	real frame_number;
	real_point3d position;
};
static_assert(sizeof(s_chud_animation_position_frame) == 0x10);

struct s_chud_animation_position_definition
{
	c_typed_tag_block<s_chud_animation_position_frame> frames;
	s_tag_function function;
};
static_assert(sizeof(s_chud_animation_position_definition) == 0x20);

struct s_chud_animation_rotation_frame
{
	real frame_number;
	real_euler_angles3d rotation;
};
static_assert(sizeof(s_chud_animation_rotation_frame) == 0x10);

struct s_chud_animation_rotation_definition
{
	c_typed_tag_block<s_chud_animation_rotation_frame> frames;
	s_tag_function function;
};
static_assert(sizeof(s_chud_animation_rotation_definition) == 0x20);

struct s_chud_animation_size_frame
{
	real frame_number;
	real width;
	real height;
};
static_assert(sizeof(s_chud_animation_size_frame) == 0xC);

struct s_chud_animation_size_definition
{
	c_typed_tag_block<s_chud_animation_size_frame> frames;
	s_tag_function function;
};
static_assert(sizeof(s_chud_animation_size_definition) == 0x20);

struct s_chud_animation_color_frame
{
	real frame_number;
};
static_assert(sizeof(s_chud_animation_color_frame) == 0x4);

struct s_chud_animation_color_definition
{
	c_typed_tag_block<s_chud_animation_color_frame> frames;
	s_tag_function function;
};
static_assert(sizeof(s_chud_animation_color_definition) == 0x20);

struct s_chud_animation_alpha_frame
{
	real frame_number;
	real alpha;
};
static_assert(sizeof(s_chud_animation_alpha_frame) == 0x8);

struct s_chud_animation_alpha_definition
{
	c_typed_tag_block<s_chud_animation_alpha_frame> frames;
	s_tag_function function;
};
static_assert(sizeof(s_chud_animation_alpha_definition) == 0x20);

struct s_chud_animation_texture_coordinate_frame
{
	real frame_number;
	real_point2d coordinate1;
	real_point2d coordinate2;
};
static_assert(sizeof(s_chud_animation_texture_coordinate_frame) == 0x14);

struct s_chud_animation_texture_coordinate_definition
{
	c_typed_tag_block<s_chud_animation_texture_coordinate_frame> frames;
	s_tag_function function;
};
static_assert(sizeof(s_chud_animation_texture_coordinate_definition) == 0x20);

struct s_chud_animation_ammo_counter_frame
{
	real frame_number;
	real ammo_counter;
};
static_assert(sizeof(s_chud_animation_ammo_counter_frame) == 0x8);

struct s_chud_animation_ammo_counter_definition
{
	c_typed_tag_block<s_chud_animation_ammo_counter_frame> frames;
	s_tag_function function;
};
static_assert(sizeof(s_chud_animation_ammo_counter_definition) == 0x20);

struct s_chud_animation_definition
{
	c_flags<e_chud_animation_flags, byte> flags;
	char : 8;
	short : 16;
	c_typed_tag_block<s_chud_animation_position_definition> position;
	c_typed_tag_block<s_chud_animation_rotation_definition> rotation;
	c_typed_tag_block<s_chud_animation_size_definition> size;
	c_typed_tag_block<s_chud_animation_color_definition> color;
	c_typed_tag_block<s_chud_animation_alpha_definition> alpha;
	c_typed_tag_block<s_chud_animation_alpha_definition> alpha_unknown;
	c_typed_tag_block<s_chud_animation_texture_coordinate_definition> texture_coordinate;
	c_typed_tag_block<s_chud_animation_ammo_counter_definition> ammo_counter;
	s_tag_block unknown;
	real number_of_frames;
};
static_assert(sizeof(s_chud_animation_definition) == 0x74);

enum e_motion_tracker_noise
{
	_motion_tracker_noise_edge,
	_motion_tracker_noise_inner,
	_motion_tracker_noise_silent,
	k_motion_tracker_noise_count
};

struct s_chud_definition
{
	// TODO
};

struct s_chud_globals_definition
{
	// TODO
};
