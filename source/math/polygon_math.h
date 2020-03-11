#pragma once

#include <cseries/cseries.h>
#include <math/real_math.h>

/* ---------- prototypes/POLYGON_MATH.CPP */

bool point_in_polygon2d(
	s_real_point2d *point,
	long polygon_point_count,
	s_real_point2d *polygon_points);

bool polygon2d_find_closest_point(
	s_real_point2d *,
	short,
	s_real_point2d *,
	s_real_point2d *,
	short *,
	float *);

bool triangle_is_cw(
	s_real_point3d *,
	s_real_point3d *,
	s_real_point3d *,
	s_real_vector3d *);

bool triangle_is_cw2d(
	s_real_point2d *,
	s_real_point2d *,
	s_real_point2d *);

void enlarge_polygon3d(
	s_real_point3d *,
	s_real_point3d *,
	short,
	s_real_vector3d *,
	float);

long find_ear(
	s_real_point2d *,
	short,
	short *,
	short,
	bool);

bool vector_intersects_polygon3d(
	s_real_point3d *,
	s_real_vector3d *,
	s_real_point3d *,
	short,
	s_real_vector3d *,
	s_real_point3d *,
	float *);

bool polygon2d_line_segment_intersection(
	s_real_point2d *,
	long,
	s_real_point2d *,
	s_real_point2d *,
	float *);

bool point_in_polygon2d_with_epsilon(
	s_real_point2d *,
	float,
	long,
	s_real_point2d *);

bool point_in_polygon2d_with_stride(
	s_real_point2d *point,
	float epsilon,
	long polygon_point_count,
	void *polygon_points_address,
	long polygon_point_stride);

float is_left(
	s_real_point2d *,
	s_real_point2d *,
	s_real_point2d *);

bool polygon2d_circle_intersection(
	s_real_point2d *,
	long,
	s_real_point2d *,
	float);

float point_to_ray_distance2d(
	s_real_point2d *,
	s_real_point2d *,
	s_real_vector2d *);

float point_to_line_distance2d(
	s_real_point2d *,
	s_real_point2d *,
	s_real_vector2d *);

bool point_in_circle(
	s_real_point2d *point,
	s_real_point2d *circle_offset,
	float circle_radius);

bool point_in_rectangle3d(
	s_real_point3d *point,
	s_real_rectangle3d *rectangle);
