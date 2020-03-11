#pragma once

#include <cseries/cseries.h>

/* ---------- types */

struct s_short_bounds
{
	short lower;
	short upper;
};
static_assert(sizeof(s_short_bounds) == 0x4);

struct s_point2d
{
	short x;
	short y;
};
static_assert(sizeof(s_point2d) == 0x4);

struct s_rectangle2d
{
	short top;
	short left;
	short bottom;
	short right;
};
static_assert(sizeof(s_rectangle2d) == 0x8);

/* ---------- prototypes/INTEGER_MATH.CPP */

s_point2d *set_point2d(
	s_point2d *point,
	short x,
	short y);

s_point2d *offset_point2d(
	s_point2d *point,
	short x,
	short y);

s_rectangle2d *set_rectangle2d(
	s_rectangle2d *rectangle,
	short top,
	short left,
	short bottom,
	short right);

short rectangle2d_width(
	s_rectangle2d *rectangle);

short rectangle2d_height(
	s_rectangle2d *rectangle);

s_rectangle2d *scale_rectangle2d(
	s_rectangle2d const *in_rectangle,
	s_rectangle2d const *in_scale,
	s_rectangle2d *out_rectangle);
