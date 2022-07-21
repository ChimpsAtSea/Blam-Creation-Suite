#pragma once

class c_graphics_render_target;

class c_imgui_viewport_render_context :
	public c_render_context
{
public:
	c_imgui_viewport_render_context(
		c_render_context& parent_render_context,
		c_viewport& viewport,
		float4 clear_color);
	~c_imgui_viewport_render_context();

	virtual void render() override;
	virtual void present();
	virtual BCS_RESULT get_viewport(c_viewport*& viewport) override;
	virtual BCS_RESULT get_window(c_window*& window) override;
	virtual BCS_RESULT get_imgui_context(c_imgui_context*& imgui_context) override;
	virtual BCS_RESULT get_graphics(c_graphics*& graphics) override;
	virtual uint32_t get_width() override;
	virtual uint32_t get_height() override;
	virtual float get_width_float() override;
	virtual float get_height_float() override;

	static void __cdecl viewport_size_changed(c_imgui_viewport_render_context& _this, uint32_t width, uint32_t height);
	static void __cdecl render_pass_render(c_imgui_viewport_render_context& _this);
	static void __cdecl swap_chain_resize_finish(c_imgui_viewport_render_context& _this, uint32_t width, uint32_t height);
	

	static constexpr uint32_t swap_chain_frames = 4;

	c_render_context& parent_render_context;
	c_viewport& viewport;
	t_callback_handle viewport_size_changed_handle;
	t_callback_handle render_pass_render_handle;
	t_callback_handle swap_chain_resize_finish_handle;

	c_graphics_render_target* depth_render_target;
	c_graphics_swap_chain* swap_chain;
	c_graphics_render_target* swap_chain_render_targets[swap_chain_frames];
	c_graphics_render_pass* render_pass;

};

BCS_RESULT render_context_imgui_viewport_create(
	c_render_context& parent_render_context,
	c_viewport& viewport,
	float4 clear_color,
	c_imgui_viewport_render_context*& render_context);
BCS_RESULT render_context_imgui_viewport_destroy(c_imgui_viewport_render_context* render_context);
