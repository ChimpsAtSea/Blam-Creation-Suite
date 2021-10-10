#pragma once

class c_graphics;

enum e_graphics_buffer_type
{
	_graphics_buffer_type_generic,
	_graphics_buffer_type_unordered_access_view,
};

class c_graphics_buffer
{
protected:
	c_graphics_buffer();
public:
	virtual ~c_graphics_buffer();
	virtual BCS_RESULT write_data(const void* buffer, unsigned long buffer_size) = 0;
	virtual BCS_RESULT read_data(void* buffer, unsigned long buffer_size) = 0;
	virtual void bind(unsigned long index) = 0;
};

BCS_DEBUG_API BCS_RESULT graphics_buffer_create(
	c_graphics* graphics, 
	e_graphics_buffer_type buffer_type,
	unsigned long element_size, 
	unsigned long element_count,
	c_graphics_buffer*& buffer,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_buffer_create(
	c_graphics* graphics,
	e_graphics_buffer_type buffer_type,
	unsigned long buffer_size,
	c_graphics_buffer*& buffer,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_buffer_destroy(c_graphics_buffer* buffer);
