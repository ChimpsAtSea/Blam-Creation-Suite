#include "graphicslib-private-pch.h"

c_graphics_shader_binary_d3d12::c_graphics_shader_binary_d3d12(
	c_graphics_d3d12& graphics,
	void* src_shader_binary_data,
	unsigned long src_shader_binary_data_size,
	const char* debug_name) :
	graphics(graphics),
	shader_binary_data(),
	shader_binary_data_size(src_shader_binary_data_size)
{
	shader_binary_data = tracked_malloc(&library_tracked_memory, src_shader_binary_data_size);
	memcpy(shader_binary_data, src_shader_binary_data, shader_binary_data_size);
}

c_graphics_shader_binary_d3d12::~c_graphics_shader_binary_d3d12()
{
	tracked_free(shader_binary_data);
}

BCS_RESULT graphics_d3d12_shader_binary_create(
	c_graphics_d3d12* graphics,
	e_bcs_resource_type resource_type,
	c_graphics_shader_binary_d3d12*& shader_binary,
	const char* debug_name)
{
	BCS_RESULT rs = BCS_S_OK;

	void* shader_binary_data;
	unsigned long long shader_binary_data_size;
	if (BCS_FAILED(rs = resources_read_resource_to_memory(resource_type, shader_binary_data, shader_binary_data_size)))
	{
		return rs;
	}
	AUTO_DELETE(shader_binary_data);

	if (BCS_FAILED(rs = graphics_d3d12_shader_binary_create(
		graphics,
		shader_binary_data,
		static_cast<unsigned long>(shader_binary_data_size),
		shader_binary,
		debug_name)))
	{
		return rs;
	}

	return rs;
}

BCS_RESULT graphics_d3d12_shader_binary_create(
	c_graphics_d3d12* graphics,
	const char* filepath,
	c_graphics_shader_binary_d3d12*& shader_binary,
	const char* debug_name)
{
	BCS_RESULT rs = BCS_S_OK;

	void* shader_binary_data;
	unsigned long long shader_binary_data_size;
	if (BCS_FAILED(rs = filesystem_read_file_to_memory(filepath, shader_binary_data, shader_binary_data_size)))
	{
		return rs;
	}
	AUTO_DELETE(shader_binary_data);

	if (BCS_FAILED(rs = graphics_d3d12_shader_binary_create(
		graphics, 
		shader_binary_data, 
		static_cast<unsigned long>(shader_binary_data_size),
		shader_binary,
		debug_name)))
	{
		return rs;
	}

	return rs;
}

BCS_RESULT graphics_d3d12_shader_binary_create(
	c_graphics_d3d12* graphics,
	void* shader_binary_data,
	unsigned long shader_binary_data_size,
	c_graphics_shader_binary_d3d12*& shader_binary,
	const char* debug_name)
{
	try
	{
		shader_binary = new c_graphics_shader_binary_d3d12(
			*graphics,
			shader_binary_data,
			shader_binary_data_size,
			debug_name);
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

BCS_RESULT graphics_d3d12_shader_binary_destroy(c_graphics_shader_binary_d3d12* shader_binary)
{
	try
	{
		delete shader_binary;
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}
