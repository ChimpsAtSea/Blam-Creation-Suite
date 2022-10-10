#pragma once

enum e_graphics_register_layout_semantic
{
	// Sampler | https://learn.microsoft.com/en-us/windows/uwp/graphics-concepts/sampler
	_graphics_register_layout_sampler,
	// Shader resource view (SRV) and Unordered Access view (UAV) | https://learn.microsoft.com/en-us/windows/uwp/graphics-concepts/shader-resource-view--srv-
	_graphics_register_layout_shader_resource,
	_graphics_register_layout_unordered_access,
	// Constant Buffer View | https://learn.microsoft.com/en-us/windows/uwp/graphics-concepts/constant-buffer-view--cbv-
	_graphics_register_layout_constant_buffer,
	_graphics_register_layout_32bit_constant,
	num_graphics_register_layouts
};

BCS_DEBUG_API const char* register_layout_semantic_to_string(e_graphics_register_layout_semantic register_layout_semantic);

struct s_graphics_register_layout_description
{
	e_graphics_register_layout_semantic semantic;
	uint16_t register_index;
	uint16_t register_count;
	uint16_t register_space;
	uint8_t num_32_bit_values;
	bool use_table;
};

class c_graphics;

class c_graphics_register_layout
{
protected:
	c_graphics_register_layout();
public:
	virtual ~c_graphics_register_layout();
};

BCS_DEBUG_API BCS_RESULT graphics_register_layout_create(
	c_graphics* graphics,
	s_graphics_register_layout_description* descriptions,
	uint32_t num_layout_descriptions,
	c_graphics_register_layout*& register_layout,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_register_layout_destroy(c_graphics_register_layout* register_layout);
