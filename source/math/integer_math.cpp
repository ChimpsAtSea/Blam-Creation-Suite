/*
INTEGER_MATH.CPP
Wednesday, February 26, 2020 1:07:45 PM
*/

#include <assert.h>

#include <math/integer_math.h>

/* ---------- globals */

const short_point2d global_short_origin2d = { 0, 0 };

/* ---------- code */

short_bounds *set_short_bounds(
	short_bounds *bounds,
	short lower,
	short upper)
{
	assert(bounds);

	bounds->lower = lower;
	bounds->upper = upper;

	return bounds;
}

short_point2d *set_short_point2d(
	short_point2d *point,
	short x,
	short y)
{
	assert(point);

	point->x = x;
	point->y = y;

	return point;
}

short_point2d *offset_short_point2d(
	short_point2d *point,
	short x,
	short y)
{
	assert(point);

	point->x += x;
	point->y += y;

	return point;
}

short short_rectangle2d_width(
	const short_rectangle2d *rectangle)
{
	assert(rectangle);

	return rectangle->right - rectangle->left;
}

short short_rectangle2d_height(
	const short_rectangle2d *rectangle)
{
	assert(rectangle);

	return rectangle->bottom - rectangle->top;
}

short short_rectangle2d_area(
	const short_rectangle2d *rectangle)
{
	assert(rectangle);

	short width = short_rectangle2d_width(rectangle);
	short height = short_rectangle2d_height(rectangle);

	return width * height;
}

short_rectangle2d *set_short_rectangle2d(
	short_rectangle2d *rectangle,
	short top,
	short left,
	short bottom,
	short right)
{
	assert(rectangle);

	rectangle->top = top;
	rectangle->left = left;
	rectangle->bottom = bottom;
	rectangle->right = right;

	return rectangle;
}
