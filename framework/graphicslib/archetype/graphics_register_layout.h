#pragma once

enum e_graphics_register_layout_semantic
{
	// Sampler | https://learn.microsoft.com/en-us/windows/uwp/graphics-concepts/sampler
	_graphics_register_layout_sampler,
	// Shader resource view (SRV) and Unordered Access view (UAV) | https://learn.microsoft.com/en-us/windows/uwp/graphics-concepts/shader-resource-view--srv-
	_graphics_register_layout_shader_resource,
	_graphics_register_layout_acceleration_structure,
	_graphics_register_layout_unordered_access,
	// Constant Buffer View | https://learn.microsoft.com/en-us/windows/uwp/graphics-concepts/constant-buffer-view--cbv-
	_graphics_register_layout_constant_buffer,
	_graphics_register_layout_32bit_constant,
	num_graphics_register_layouts [[maybe_unused]]
};

BCS_SHARED const char* register_layout_semantic_to_string(e_graphics_register_layout_semantic register_layout_semantic);

enum e_graphics_register_layout_type : unsigned char
{
	_graphics_register_layout_type_graphics,
	_graphics_register_layout_type_compute,
	_graphics_register_layout_type_global_raytracing,
	_graphics_register_layout_type_local_raytracing,
};

enum e_graphics_sampler_filter : unsigned char
{
	_graphics_sampler_filter_min_mag_mip_point,
	_graphics_sampler_filter_min_mag_point_mip_linear,
	_graphics_sampler_filter_min_point_mag_linear_mip_point,
	_graphics_sampler_filter_min_point_mag_mip_linear,
	_graphics_sampler_filter_min_linear_mag_mip_point,
	_graphics_sampler_filter_min_linear_mag_point_mip_linear,
	_graphics_sampler_filter_min_mag_linear_mip_point,
	_graphics_sampler_filter_min_mag_mip_linear,
	_graphics_sampler_filter_anisotropic,
};

enum e_graphics_texture_address : unsigned char
{
	_graphics_texture_address_mode_wrap,
	_graphics_texture_address_mode_mirror,
	_graphics_texture_address_mode_clamp,
	_graphics_texture_address_mode_border,
	_graphics_texture_address_mode_mirror_once
};

struct s_graphics_sampler_layout_description
{
	e_graphics_sampler_filter filter;
	e_graphics_texture_address texture_adress_u;
	e_graphics_texture_address texture_adress_v;
	e_graphics_texture_address texture_adress_w;
	unsigned char anisotropy;
	float minimum_mip;
	float maximum_mip;
};

struct s_graphics_register_layout_description
{
	e_graphics_register_layout_semantic semantic;
	uint16_t register_index;
	uint16_t register_count;
	uint16_t register_space;
	uint8_t num_32_bit_values;
	bool use_table;
	s_graphics_sampler_layout_description* sampler_layout_description;
};

class c_graphics;
class c_graphics_buffer;

class c_graphics_register_layout
{
protected:
	c_graphics_register_layout();
public:
	virtual ~c_graphics_register_layout();

	virtual BCS_RESULT bind() const = 0;

	virtual BCS_RESULT bind_buffer(
		unsigned int register_layout_description_index,
		unsigned int register_layout_offset,
		c_graphics_buffer& graphics_buffer) const = 0;
	virtual BCS_RESULT bind_buffer(
		e_graphics_register_layout_semantic semantic,
		unsigned int register_index,
		unsigned int register_space,
		c_graphics_buffer& graphics_buffer) const = 0;
};

BCS_SHARED BCS_RESULT graphics_register_layout_create(
	c_graphics* graphics,
	e_graphics_register_layout_type root_signature_type,
	s_graphics_register_layout_description const* register_layout_descriptions,
	uint32_t num_layout_descriptions,
	c_graphics_register_layout*& register_layout,
	const char* debug_name = nullptr);
BCS_SHARED BCS_RESULT graphics_register_layout_destroy(c_graphics_register_layout* register_layout);
