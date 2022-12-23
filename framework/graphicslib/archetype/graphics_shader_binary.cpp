#include "graphicslib-private-pch.h"

c_graphics_shader_binary::c_graphics_shader_binary()
{

}

c_graphics_shader_binary::~c_graphics_shader_binary()
{

}

BCS_RESULT graphics_shader_binary_create(
	c_graphics* graphics,
	e_bcs_resource_type resource_type,
	c_graphics_shader_binary*& shader_binary,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_shader_binary_create(
			graphics_d3d12, 
			resource_type, 
			*reinterpret_cast<c_graphics_shader_binary_d3d12**>(&shader_binary), 
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_shader_binary_create(
	c_graphics* graphics,
	void* shader_binary_data,
	uint32_t shader_binary_data_size,
	c_graphics_shader_binary*& shader_binary,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_shader_binary_create(
			graphics_d3d12, 
			shader_binary_data, 
			shader_binary_data_size, 
			*reinterpret_cast<c_graphics_shader_binary_d3d12**>(&shader_binary), 
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_shader_binary_create(
	c_graphics* graphics,
	const char* filepath,
	c_graphics_shader_binary*& shader_binary,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_shader_binary_create(
			graphics_d3d12, 
			filepath, 
			*reinterpret_cast<c_graphics_shader_binary_d3d12**>(&shader_binary), 
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_shader_binary_destroy(c_graphics_shader_binary* shader_binary)
{
	BCS_VALIDATE_ARGUMENT(shader_binary != nullptr);

	if (c_graphics_shader_binary_d3d12* shader_binary_d3d12 = dynamic_cast<c_graphics_shader_binary_d3d12*>(shader_binary))
	{
		return graphics_d3d12_shader_binary_destroy(shader_binary_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}
