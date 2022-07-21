#include "graphicslib-private-pch.h"

c_graphics_geometry::c_graphics_geometry()
{

}

c_graphics_geometry::~c_graphics_geometry()
{

}

BCS_RESULT graphics_geometry_create(
	c_graphics* graphics,
	c_graphics_buffer* index_buffer,
	uint32_t num_primitives,
	c_graphics_buffer** vertex_buffers,
	uint32_t num_vertex_buffers,
	c_graphics_vertex_layout* vertex_layout,
	c_graphics_geometry*& geometry,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_geometry_create(
			graphics_d3d12,
			dynamic_cast<c_graphics_buffer_d3d12*>(index_buffer),
			num_primitives,
			reinterpret_cast<c_graphics_buffer_d3d12**>(vertex_buffers),
			num_vertex_buffers,
			dynamic_cast<c_graphics_vertex_layout_d3d12*>(vertex_layout),
			*reinterpret_cast<c_graphics_geometry_d3d12**>(&geometry),
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_geometry_destroy(c_graphics_geometry* geometry)
{
	if (c_graphics_geometry_d3d12* geometry_d3d12 = dynamic_cast<c_graphics_geometry_d3d12*>(geometry))
	{
		return graphics_d3d12_geometry_destroy(geometry_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}
