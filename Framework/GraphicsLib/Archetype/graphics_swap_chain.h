#pragma once

class c_graphics;
class c_window;
class c_imgui_viewport_render_context;

class c_graphics_swap_chain
{
protected:
	c_graphics_swap_chain();
public:
	virtual ~c_graphics_swap_chain();

	virtual BCS_RESULT present() = 0;
	virtual uint32_t get_current_back_buffer_index() = 0;

	using t_graphics_resize_event = void(uint32_t width, uint32_t height);
	c_typed_callback<t_graphics_resize_event> on_resize_start;
	c_typed_callback<t_graphics_resize_event> on_resize_finish;
};

BCS_DEBUG_API BCS_RESULT graphics_swap_chain_create(
	c_graphics* graphics,
	c_window* window,
	uint32_t num_back_buffers,
	c_graphics_swap_chain*& swap_chain,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_swap_chain_create(
	c_graphics* graphics,
	c_imgui_viewport_render_context* imgui_viewport_render_context,
	uint32_t num_back_buffers,
	c_graphics_swap_chain*& swap_chain,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_swap_chain_destroy(c_graphics_swap_chain* swap_chain);
