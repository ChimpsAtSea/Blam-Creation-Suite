#include "graphicslib-private-pch.h"

c_graphics_buffer::c_graphics_buffer()
{

}

c_graphics_buffer::~c_graphics_buffer()
{

}

BCS_RESULT graphics_buffer_create(
	c_graphics* graphics,
	e_graphics_buffer_type buffer_type,
	uint32_t element_size,
	uint32_t element_count,
	c_graphics_buffer*& buffer,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_buffer_create(
			graphics_d3d12,
			buffer_type,
			element_size,
			element_count, 
			*reinterpret_cast<c_graphics_buffer_d3d12**>(&buffer), 
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_buffer_create(
	c_graphics* graphics,
	e_graphics_buffer_type buffer_type,
	uint32_t buffer_size,
	c_graphics_buffer*& buffer,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_buffer_create(
			graphics_d3d12,
			buffer_type,
			buffer_size, 
			*reinterpret_cast<c_graphics_buffer_d3d12**>(&buffer), 
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_buffer_destroy(c_graphics_buffer* buffer)
{
	if (c_graphics_buffer_d3d12* buffer_d3d12 = dynamic_cast<c_graphics_buffer_d3d12*>(buffer))
	{
		return graphics_d3d12_buffer_destroy(buffer_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}
