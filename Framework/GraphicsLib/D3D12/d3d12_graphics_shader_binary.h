#pragma once

class c_graphics;

class c_graphics_shader_binary_d3d12 :
	public c_graphics_shader_binary
{
public:
	c_graphics_shader_binary_d3d12(
		c_graphics_d3d12& graphics,
		void* shader_binary_data,
		uint32_t shader_binary_data_size,
		const char* debug_name);
	virtual ~c_graphics_shader_binary_d3d12();

	c_graphics_d3d12& graphics;
	void* shader_binary_data;
	uint32_t shader_binary_data_size;
};

BCS_RESULT graphics_d3d12_shader_binary_create(
	c_graphics_d3d12* graphics,
	e_bcs_resource_type resource_type,
	c_graphics_shader_binary_d3d12*& shader_binary,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_shader_binary_create(
	c_graphics_d3d12* graphics,
	const char* filepath,
	c_graphics_shader_binary_d3d12*& shader_binary,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_shader_binary_create(
	c_graphics_d3d12* graphics,
	void* shader_binary_data,
	uint32_t shader_binary_data_size,
	c_graphics_shader_binary_d3d12*& shader_binary,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_shader_binary_destroy(c_graphics_shader_binary_d3d12* shader_binary);
