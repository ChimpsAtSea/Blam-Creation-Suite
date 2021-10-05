#pragma once

class c_graphics;

class c_graphics_buffer
{
protected:
	c_graphics_buffer();
public:
	virtual ~c_graphics_buffer();
};

BCS_DEBUG_API BCS_RESULT graphics_buffer_create(
	c_graphics* graphics, 
	unsigned long element_size, 
	unsigned long element_count,
	c_graphics_buffer*& buffer,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_buffer_create(
	c_graphics* graphics,
	unsigned long buffer_size,
	c_graphics_buffer*& buffer,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_buffer_destroy(c_graphics_buffer* buffer);
