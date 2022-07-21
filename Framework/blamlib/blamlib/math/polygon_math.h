#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/math/real_math.h>

/* ---------- prototypes/POLYGON_MATH.CPP */

bool point_in_polygon2d(
	real_point2d *point,
	int polygon_point_count,
	real_point2d *polygon_points);

bool polygon2d_find_closest_point(
	real_point2d *,
	short,
	real_point2d *,
	real_point2d *,
	short *,
	float *);

bool triangle_is_cw(
	real_point3d *,
	real_point3d *,
	real_point3d *,
	real_vector3d *);

bool triangle_is_cw2d(
	real_point2d *,
	real_point2d *,
	real_point2d *);

void enlarge_polygon3d(
	real_point3d *,
	real_point3d *,
	short,
	real_vector3d *,
	float);

int find_ear(
	real_point2d *,
	short,
	short *,
	short,
	bool);

bool vector_intersects_polygon3d(
	real_point3d *,
	real_vector3d *,
	real_point3d *,
	short,
	real_vector3d *,
	real_point3d *,
	float *);

bool polygon2d_line_segment_intersection(
	real_point2d *,
	int,
	real_point2d *,
	real_point2d *,
	float *);

bool point_in_polygon2d_with_epsilon(
	real_point2d *,
	float,
	int,
	real_point2d *);

bool point_in_polygon2d_with_stride(
	real_point2d *point,
	float epsilon,
	int polygon_point_count,
	void *polygon_points_address,
	int polygon_point_stride);

float is_left(
	real_point2d *,
	real_point2d *,
	real_point2d *);

bool polygon2d_circle_intersection(
	real_point2d *,
	int,
	real_point2d *,
	float);

float point_to_ray_distance2d(
	real_point2d *,
	real_point2d *,
	real_vector2d *);

float point_to_line_distance2d(
	real_point2d *,
	real_point2d *,
	real_vector2d *);

bool point_in_circle(
	real_point2d *point,
	real_point2d *circle_offset,
	float circle_radius);

bool point_in_rectangle3d(
	real_point3d *point,
	s_real_rectangle3d *rectangle);
