#pragma once

class c_graphics_d3d12;
class c_descriptor_heap_d3d12;
class c_graphics_swap_chain_d3d12;

enum c_graphics_render_target_type_d3d12
{
	_graphics_render_target_type_d3d12_color,
	_graphics_render_target_type_d3d12_depth_stencil,
	_graphics_render_target_type_d3d12_swapchain
};

class c_graphics_render_target_d3d12 :
	public c_graphics_render_target
{
public:
	c_graphics_render_target_d3d12() = delete;
	c_graphics_render_target_d3d12(const c_graphics_render_target_d3d12&) = delete;
	c_graphics_render_target_d3d12& operator=(const c_graphics_render_target_d3d12&) = delete;
	c_graphics_render_target_d3d12(
		c_graphics_d3d12& graphics,
		c_graphics_swap_chain_d3d12& swap_chain,
		unsigned long swap_chain_buffer_index,
		float4 clear_color,
		const char* debug_name);
	c_graphics_render_target_d3d12(
		c_graphics_d3d12& graphics,
		unsigned long width,
		unsigned long height,
		e_graphics_data_format format,
		float4 clear_color,
		const char* debug_name,
		bool shared);
	c_graphics_render_target_d3d12(
		c_graphics_d3d12& graphics,
		unsigned long width,
		unsigned long height,
		e_graphics_data_format format,
		float clear_depth,
		unsigned char stencil_value,
		const char* debug_name,
		bool shared);
	virtual ~c_graphics_render_target_d3d12();

	void clear_render_target();
	void init_resource();
	void deinit_resource();
	virtual BCS_RESULT resize(unsigned long width, unsigned long height) override;

	static void swap_chain_resize_start(c_graphics_render_target_d3d12& _this, unsigned long width, unsigned long height);
	static void swap_chain_resize_finish(c_graphics_render_target_d3d12& _this, unsigned long width, unsigned long height);

	c_graphics_render_target_type_d3d12 render_target_type;
	c_graphics_d3d12& graphics;
	ID3D12Resource* resource;
	c_graphics_swap_chain_d3d12* swap_chain;
	unsigned long swap_chain_buffer_index;
	c_descriptor_heap_d3d12* descriptor_heap_cpu;

	D3D12_CLEAR_VALUE clear_value;
	D3D12_DEPTH_STENCIL_VIEW_DESC depth_stencil_view_description;

	DXGI_FORMAT dxgi_format;
	D3D12_HEAP_FLAGS heap_flags;
	D3D12_HEAP_PROPERTIES heap_properties;
	D3D12_RESOURCE_STATES resource_state;
	D3D12_RESOURCE_DESC resource_description;

	t_callback_handle swap_chain_resize_start_handle;
	t_callback_handle swap_chain_resize_finish_handle;
};

BCS_DEBUG_API BCS_RESULT graphics_d3d12_swapchain_color_render_target_create(
	c_graphics_d3d12* graphics,
	c_graphics_swap_chain_d3d12* swap_chain,
	unsigned long swap_chain_buffer_index,
	float4 clear_color,
	c_graphics_render_target_d3d12*& render_target,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_d3d12_color_render_target_create(
	c_graphics_d3d12* graphics,
	unsigned long width,
	unsigned long height,
	e_graphics_data_format format,
	float4 clear_color,
	c_graphics_render_target_d3d12*& render_target,
	const char* debug_name = nullptr,
	bool shared = false);
BCS_DEBUG_API BCS_RESULT graphics_d3d12_depth_stencil_render_target_create(
	c_graphics_d3d12* graphics,
	unsigned long width,
	unsigned long height,
	e_graphics_data_format format,
	float clear_depth,
	unsigned char stencil_value,
	c_graphics_render_target_d3d12*& render_target,
	const char* debug_name = nullptr,
	bool shared = false);
BCS_DEBUG_API BCS_RESULT graphics_d3d12_render_target_destroy(c_graphics_render_target_d3d12* render_target);
