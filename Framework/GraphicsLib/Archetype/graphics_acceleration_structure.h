#pragma once

class c_graphics;
class c_graphics_geometry;
class c_graphics_buffer;

class c_graphics_bottom_level_acceleration_structure;

struct s_graphics_acceleration_structure_instance
{
	float4x3 transform;
	c_graphics_bottom_level_acceleration_structure* bottom_level_acceleration_structure;
};

class c_graphics_top_level_acceleration_structure
{
protected:
	c_graphics_top_level_acceleration_structure();
	c_graphics_top_level_acceleration_structure(const c_graphics_top_level_acceleration_structure&) = delete;
	c_graphics_top_level_acceleration_structure& operator=(const c_graphics_top_level_acceleration_structure&) = delete;
public:
	virtual ~c_graphics_top_level_acceleration_structure();

	virtual BCS_RESULT acceleration_structure_build(
		s_graphics_acceleration_structure_instance const* instances,
		unsigned int num_instances) = 0;
	virtual BCS_RESULT get_buffer(c_graphics_buffer*& acceleration_structure_buffer) const = 0;
};

class c_graphics_bottom_level_acceleration_structure
{
protected:
	c_graphics_bottom_level_acceleration_structure();
	c_graphics_bottom_level_acceleration_structure(const c_graphics_bottom_level_acceleration_structure&) = delete;
	c_graphics_bottom_level_acceleration_structure& operator=(const c_graphics_bottom_level_acceleration_structure&) = delete;
public:
	virtual ~c_graphics_bottom_level_acceleration_structure();
};

BCS_SHARED BCS_RESULT graphics_top_level_acceleration_structure_create(
	c_graphics* graphics,
	c_graphics_top_level_acceleration_structure*& top_level_acceleration_structure,
	const char* debug_name = nullptr);
BCS_SHARED BCS_RESULT graphics_top_level_acceleration_structure_destroy(c_graphics_top_level_acceleration_structure* geometry);

BCS_SHARED BCS_RESULT graphics_bottom_level_acceleration_structure_create(
	c_graphics* graphics,
	c_graphics_geometry* geometry,
	c_graphics_bottom_level_acceleration_structure*& bottom_level_acceleration_structure,
	const char* debug_name = nullptr);
BCS_SHARED BCS_RESULT graphics_bottom_level_acceleration_structure_destroy(c_graphics_bottom_level_acceleration_structure* geometry);
