#pragma once

class c_graphics;
class c_graphics_vertex_layout;
class c_graphics_buffer;

class c_graphics_geometry
{
protected:
	c_graphics_geometry();
public:
	virtual ~c_graphics_geometry();

	virtual void render_geometry(uint32_t instance_count = 1) = 0;
};

BCS_SHARED BCS_RESULT graphics_geometry_create(
	c_graphics* graphics,
	c_graphics_buffer* index_buffer,
	uint32_t num_primitives,
	c_graphics_buffer** vertex_buffers,
	uint32_t num_vertex_buffers,
	c_graphics_vertex_layout* vertex_layout,
	c_graphics_geometry*& geometry,
	const char* debug_name = nullptr);
BCS_SHARED BCS_RESULT graphics_geometry_destroy(c_graphics_geometry* geometry);
