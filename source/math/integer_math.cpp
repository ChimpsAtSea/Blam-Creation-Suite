#include <math/integer_math.h>

s_point2d *set_point2d(
	s_point2d *point,
	short x,
	short y)
{
	blamlib_assert(point);

	point->x = x;
	point->y = y;

	return point;
}

s_point2d *offset_point2d(
	s_point2d *point,
	short x,
	short y)
{
	blamlib_assert(point);

	point->x += x;
	point->y += y;

	return point;
}

s_rectangle2d *set_rectangle2d(
	s_rectangle2d *rectangle,
	short top,
	short left,
	short bottom,
	short right)
{
	blamlib_assert(rectangle);

	rectangle->top = top;
	rectangle->left = left;
	rectangle->bottom = bottom;
	rectangle->right = right;

	return rectangle;
}

short rectangle2d_width(
	s_rectangle2d *rectangle)
{
	blamlib_assert(rectangle);

	return rectangle->right - rectangle->left;
}

short rectangle2d_height(
	s_rectangle2d *rectangle)
{
	blamlib_assert(rectangle);

	return rectangle->bottom - rectangle->top;
}
