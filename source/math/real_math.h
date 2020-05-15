#pragma once

#include <cseries/cseries.h>

/* ---------- types */

using real = float;
using angle = real;
using real_fraction = real;

struct real_bounds
{
	real lower;
	real upper;
};

struct angle_bounds
{
	angle lower;
	angle upper;
};

struct real_fraction_bounds
{
	real_fraction lower;
	real_fraction upper;
};

struct real_point2d
{
	real x;
	real y;
};

struct real_point3d
{
	real x;
	real y;
	real z;
};

struct real_vector2d
{
	real i;
	real j;
};

struct real_vector3d
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

struct real_quaternion
{
	real i;
	real j;
	real k;
	real w;
};

struct real_euler_angles2d
{
	real yaw;
	real pitch;
};

struct real_euler_angles3d
{
	real yaw;
	real pitch;
	real roll;
};

struct real_plane2d
{
	real_vector2d normal;
	real distance;
};

struct real_plane3d
{
	real_vector3d normal;
	real distance;
};

struct s_real_matrix3x3
{
	real_vector3d forward;
	real_vector3d left;
	real_vector3d up;
};

struct s_real_matrix4x3
{
	real_vector3d forward;
	real_vector3d left;
	real_vector3d up;
	real_point3d position;
	real scale;
};

struct s_real_orientation
{
	real_quaternion rotation;
	real_point3d translation;
	real scale;
};

struct s_real_rectangle2d
{
	real_bounds x;
	real_bounds y;
};

struct s_real_rectangle3d
{
	real_bounds x;
	real_bounds y;
	real_bounds z;
};

struct rgb_color
{
	real red;
	real green;
	real blue;
};

struct argb_color
{
	real alpha;
	real red;
	real green;
	real blue;
};

struct real_hsv_color
{
	real hue;
	real saturation;
	real value;
};

struct real_ahsv_color
{
	real alpha;
	real hue;
	real saturation;
	real value;
};

/* ---------- prototypes/REAL_MATH.CPP */
