#pragma once

class c_graphics;

class c_graphics_shader_binary
{
protected:
	c_graphics_shader_binary();
public:
	virtual ~c_graphics_shader_binary();
};

BCS_DEBUG_API BCS_RESULT graphics_shader_create(
	c_graphics* graphics,
	e_bcs_resource_type resource_type,
	c_graphics_shader_binary*& shader_binary,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_shader_create(
	c_graphics* graphics,
	void* shader_binary_data, 
	unsigned long shader_binary_data_size,
	c_graphics_shader_binary*& shader_binary,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_shader_create(
	c_graphics* graphics,
	const char* filepath,
	c_graphics_shader_binary*& shader_binary,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_shader_destroy(c_graphics_shader_binary* shader_binary);
