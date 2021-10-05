#include "graphicslib-private-pch.h"

c_graphics_shader_pipeline_d3d12::c_graphics_shader_pipeline_d3d12(
	c_graphics_d3d12& graphics,
	c_graphics_shader_binary_d3d12** shader_binaries,
	unsigned long num_shader_binaries,
	const char* debug_name) :
	graphics(graphics)
{

}

c_graphics_shader_pipeline_d3d12::~c_graphics_shader_pipeline_d3d12()
{

}

BCS_RESULT graphics_d3d12_shader_pipeline_create(
	c_graphics_d3d12* graphics,
	c_graphics_shader_binary_d3d12** shader_binaries,
	unsigned long num_shader_binaries,
	c_graphics_shader_pipeline_d3d12*& shader_pipeline,
	const char* debug_name)
{
	try
	{
		shader_pipeline = new c_graphics_shader_pipeline_d3d12(
			*graphics,
			shader_binaries,
			num_shader_binaries,
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

BCS_RESULT graphics_d3d12_shader_pipeline_destroy(c_graphics_shader_pipeline_d3d12* shader_pipeline)
{
	try
	{
		delete shader_pipeline;
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
