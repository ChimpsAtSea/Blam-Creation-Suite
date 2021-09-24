#pragma once

class c_graphics;

class c_graphics_texture
{
protected:
	c_graphics_texture();
public:
	virtual ~c_graphics_texture();
};

BCS_DEBUG_API BCS_RESULT graphics_texture_create(
	c_graphics* graphics,
	e_bcs_resource_type resource_type,
	c_graphics_texture*& texture,
	const char* debug_name = nullptr
);
BCS_DEBUG_API BCS_RESULT graphics_texture_create(
	c_graphics* graphics,
	const char* texture_filepath,
	c_graphics_texture*& texture,
	const char* debug_name = nullptr
);
BCS_DEBUG_API BCS_RESULT graphics_texture_create(
	c_graphics* graphics,
	const wchar_t* texture_filepath,
	c_graphics_texture*& texture,
	const char* debug_name = nullptr
);
BCS_DEBUG_API BCS_RESULT graphics_texture_create(
	c_graphics* graphics,
	void* texture_binary, 
	unsigned long* texture_binary_size,
	e_graphics_data_format pixel_format,
	unsigned long width,
	unsigned long height,
	c_graphics_texture*& texture,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_texture_destroy(c_graphics_texture* texture);
