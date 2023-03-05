#pragma once

class c_graphics_d3d12;
class c_window_windows;
class c_imgui_viewport_render_context;

struct IDXGISwapChain3;

class c_graphics_swap_chain_d3d12 :
	public c_graphics_swap_chain
{
public:
	c_graphics_swap_chain_d3d12(
		c_graphics_d3d12& graphics,
		c_window_windows& window,
		uint32_t num_back_buffers,
		const char* debug_name);
	c_graphics_swap_chain_d3d12(
		c_graphics_d3d12& graphics,
		c_imgui_viewport_render_context& imgui_viewport_render_context,
		c_viewport& viewport,
		uint32_t num_back_buffers,
		const char* debug_name);
	BCS_RESULT construct1(c_imgui_viewport_render_context& imgui_viewport_render_context);
	BCS_RESULT construct2(c_window_windows& window);
	BCS_RESULT destruct();
	virtual ~c_graphics_swap_chain_d3d12();

	virtual BCS_RESULT present() override;
	virtual uint32_t get_current_back_buffer_index() override;

	static void window_resize_event(c_graphics_swap_chain_d3d12& _this, uint32_t width, uint32_t height);

	c_graphics_d3d12& graphics;
	c_viewport& viewport;
	c_window_windows* window;
	c_imgui_viewport_render_context* imgui_viewport_render_context;
	IDXGISwapChain3* dxgi_swap_chain;
	DXGI_SWAP_CHAIN_DESC swap_chain_description;
	uint32_t num_back_buffers;
	uint32_t current_back_buffer_index;
	t_callback_handle window_resize_callback_handle;
};

BCS_SHARED BCS_RESULT graphics_d3d12_swap_chain_create(
	c_graphics_d3d12* graphics,
	c_window_windows* window,
	uint32_t num_back_buffers,
	c_graphics_swap_chain_d3d12*& swap_chain,
	const char* debug_name = nullptr);
BCS_SHARED BCS_RESULT graphics_d3d12_swap_chain_create(
	c_graphics_d3d12* graphics,
	c_imgui_viewport_render_context* imgui_viewport_render_context,
	uint32_t num_back_buffers,
	c_graphics_swap_chain_d3d12*& swap_chain,
	const char* debug_name = nullptr);
BCS_SHARED BCS_RESULT graphics_d3d12_swap_chain_destroy(c_graphics_swap_chain_d3d12* swap_chain);
