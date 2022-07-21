#pragma once

class c_graphics;

class c_graphics_texture_d3d12 :
	public c_graphics_texture
{
protected:
	c_graphics_texture_d3d12();
public:
	virtual ~c_graphics_texture_d3d12();
};

BCS_RESULT graphics_d3d12_texture_create(
	c_graphics* graphics,
	e_bcs_resource_type resource_type,
	c_graphics_texture_d3d12*& texture,
	const char* debug_name = nullptr
);
BCS_RESULT graphics_d3d12_texture_create(
	c_graphics* graphics,
	const char* texture_filepath,
	c_graphics_texture_d3d12*& texture,
	const char* debug_name = nullptr
);
BCS_RESULT graphics_d3d12_texture_create(
	c_graphics* graphics,
	const wchar_t* texture_filepath,
	c_graphics_texture_d3d12*& texture,
	const char* debug_name = nullptr
);
BCS_RESULT graphics_d3d12_texture_create(
	c_graphics* graphics,
	void* texture_binary, 
	uint32_t* texture_binary_size,
	e_graphics_data_format pixel_format,
	uint32_t width,
	uint32_t height,
	c_graphics_texture_d3d12*& texture,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_texture_destroy(c_graphics_texture_d3d12* texture);
