/*
INTEGER_MATH.H
Wednesday, February 26, 2020 1:01:25 PM
*/

#pragma once

/* ---------- types */

union short_bounds
{
	struct
	{
		short lower;
		short upper;
	};
};

union short_point2d
{
	struct
	{
		short x;
		short y;
	};
};

union short_rectangle2d
{
	struct
	{
		short top;
		short left;
		short bottom;
		short right;
	};
};

/* ---------- globals */

extern const short_point2d global_short_origin2d;

/* ---------- prototypes/INTEGER_MATH.CPP */

short_bounds *set_short_bounds(
	short_bounds *bounds,
	short lower,
	short upper);

short_point2d *set_short_point2d(
	short_point2d *point,
	short x,
	short y);

short_point2d *offset_short_point2d(
	short_point2d *point,
	short x,
	short y);

short short_rectangle2d_width(
	const short_rectangle2d *rectangle);

short short_rectangle2d_height(
	const short_rectangle2d *rectangle);

short short_rectangle2d_area(
	const short_rectangle2d *rectangle);

short_rectangle2d *set_short_rectangle2d(
	short_rectangle2d *rectangle,
	short top,
	short left,
	short bottom,
	short right);
