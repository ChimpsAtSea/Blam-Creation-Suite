#pragma once

class c_graphics_d3d12;
class c_window_windows;

struct IDXGISwapChain3;

class c_graphics_swap_chain_d3d12 :
	public c_graphics_swap_chain
{
public:
	c_graphics_swap_chain_d3d12(
		c_graphics_d3d12& graphics,
		c_window_windows& window,
		unsigned long num_back_buffers,
		const char* debug_name);
	virtual ~c_graphics_swap_chain_d3d12();

	virtual void present() override;
	virtual unsigned long get_current_back_buffer_index() override;

	static void window_resize_event(c_graphics_swap_chain_d3d12& _this, unsigned long width, unsigned long height);

	c_graphics_d3d12& graphics;
	IDXGISwapChain3* dxgi_swap_chain;
	DXGI_SWAP_CHAIN_DESC swap_chain_description;
	unsigned long num_back_buffers;
	unsigned long current_back_buffer_index;
	t_callback_handle window_resize_callback_handle;
};

BCS_DEBUG_API BCS_RESULT graphics_d3d12_swap_chain_create(
	c_graphics_d3d12* graphics,
	c_window_windows* window,
	unsigned long num_back_buffers,
	c_graphics_swap_chain_d3d12*& swap_chain,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_d3d12_swap_chain_destroy(c_graphics_swap_chain_d3d12* swap_chain);
