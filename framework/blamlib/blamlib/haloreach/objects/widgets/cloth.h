#pragma once

#include <blamlib/cseries/cseries.h>
#include <blamlib/datatypes/flags.h>
#include <blamlib/math/real_math.h>
#include <blamlib/tag_files/string_ids.h>
#include <blamlib/tag_files/tag_groups.h>

/* ---------- constants */

constexpr tag k_cloth_group_tag = 'clwd';

/* ---------- types */

enum e_cloth_definition_flags
{
	_cloth_does_not_use_wind_bit,
	_cloth_uses_grid_attach_top_bit,
	k_number_of_cloth_definition_flags
};

struct s_cloth_collision_sphere
{
	string_id object_marker_name;
	real radius;
};

enum e_cloth_integration_type
{
	_cloth_integration_type_verlet,
	k_number_of_cloth_integration_types
};

struct s_cloth_properties
{
	c_enum<e_cloth_integration_type, short> integration_type;
	short number_interations; // [1-8] sug 1
	real weight; // [-10.0 - 10.0] sug 1.0
	real drag; // [0.0 - 0.5] sug 0.07
	real wind_scale; // [0.0 - 3.0] sug 1.0
	real wind_flappiness_scale; // [0.0 - 1.0] sug 0.75
	real longest_rod; // [1.0 - 10.0] sug 3.5
	char unused[24];
};
static_assert(sizeof(s_cloth_properties) == 0x30);

struct s_cloth_vertex
{
	real_point3d initial_position;
	real_vector2d uv;
};
static_assert(sizeof(s_cloth_vertex) == 0x14);

struct s_cloth_link
{
	real default_distance;
	int indices[2];
	int : 32;
};
static_assert(sizeof(s_cloth_link) == 0x10);

struct s_cloth_definition
{
	c_flags<e_cloth_definition_flags, dword, k_number_of_cloth_definition_flags> flags;

	string_id marker_attachment_name;
	string_id secondary_axis_attachment_name;

	s_tag_reference shader; // 'rm  '

	/* ------ default cloth vertices:
		if not importing from a render model, type a grid size */

	short grid_x_dimension;
	short grid_y_dimension;

	real grid_spacing_x;
	real grid_spacing_y;

	c_typed_tag_block<s_cloth_collision_sphere> collision_spheres;

	/* ------ cloth properties */

	s_cloth_properties properties;

	/* ------ import or grid data */

	c_typed_tag_block<s_cloth_vertex> vertices;
	c_typed_tag_block<short> indices;
	c_typed_tag_block<short> strip_indices;
	c_typed_tag_block<s_cloth_link> links;

	int : 32;
};
static_assert(sizeof(s_cloth_definition) == 0x98);
