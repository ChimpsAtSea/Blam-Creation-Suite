#pragma once

#include <cseries/cseries.h>

/* ---------- types */

using real = float;

struct s_real_bounds
{
	real lower;
	real upper;
};

struct s_real_point2d
{
	real x;
	real y;
};

struct s_real_point3d
{
	real x;
	real y;
	real z;
};

struct s_real_vector2d
{
	real i;
	real j;
};

struct s_real_vector3d
{
	real i;
	real j;
	real k;
};

struct s_real_vector4d
{
	real i;
	real j;
	real k;
	real w;
};

struct s_real_quaternion
{
	real i;
	real j;
	real k;
	real w;
};

struct s_real_euler_angles2d
{
	real yaw;
	real pitch;
};

struct s_real_euler_angles3d
{
	real yaw;
	real pitch;
	real roll;
};

struct s_real_plane2d
{
	s_real_vector2d normal;
	real distance;
};

struct s_real_plane3d
{
	s_real_vector3d normal;
	real distance;
};

struct s_real_matrix3x3
{
	s_real_vector3d forward;
	s_real_vector3d left;
	s_real_vector3d up;
};

struct s_real_matrix4x3
{
	s_real_vector3d forward;
	s_real_vector3d left;
	s_real_vector3d up;
	s_real_point3d position;
	real scale;
};

struct s_real_orientation
{
	s_real_quaternion rotation;
	s_real_point3d translation;
	real scale;
};

struct s_real_rectangle2d
{
	s_real_bounds x;
	s_real_bounds y;
};

struct s_real_rectangle3d
{
	s_real_bounds x;
	s_real_bounds y;
	s_real_bounds z;
};

struct s_real_rgb_color
{
	real red;
	real green;
	real blue;
};

struct s_real_argb_color
{
	real alpha;
	real red;
	real green;
	real blue;
};

struct s_real_hsv_color
{
	real hue;
	real saturation;
	real value;
};

struct s_real_ahsv_color
{
	real alpha;
	real hue;
	real saturation;
	real value;
};

/* ---------- prototypes/REAL_MATH.CPP */
