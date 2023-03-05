#pragma once

class c_window_render_context :
	public c_render_context
{
public:
	c_window_render_context(
		c_window& window,
		float4 background_color,
		c_graphics* existing_graphics_context);
	BCS_RESULT construct();
	BCS_RESULT destruct();
	~c_window_render_context();

	BCS_RESULT init_graphics();
	BCS_RESULT deinit_graphics();
	BCS_RESULT init_render_context();
	BCS_RESULT deinit_render_context();

	virtual BCS_RESULT render() override;
	virtual BCS_RESULT get_viewport(c_viewport*& viewport) override;
	virtual BCS_RESULT get_window(c_window*& window) override;
	virtual BCS_RESULT get_imgui_context(c_imgui_context*& imgui_context) override;
	virtual BCS_RESULT get_graphics(c_graphics*& graphics) override;
	virtual uint32_t get_width() override;
	virtual uint32_t get_height() override;
	virtual float get_width_float() override;
	virtual float get_height_float() override;

	static constexpr uint32_t swap_chain_frames = 4;

	c_window& window;
	c_graphics* graphics;
	bool is_graphics_owner;
	c_imgui_context* imgui_context;

	c_graphics_render_target* depth_render_target;
	c_graphics_swap_chain* swap_chain;
	c_graphics_render_target* swap_chain_render_targets[swap_chain_frames];
	c_graphics_render_pass* render_pass;

	t_callback_handle window_resize_handle;
	t_callback_handle graphics_render_handle;
	t_callback_handle render_pass_render_handle;
	t_callback_handle render_imgui_handle;
	t_callback_handle graphics_present_handle;
	t_callback_handle swap_chain_resize_finish_handle;

	float4 background_color;

	static void __cdecl window_resize(c_window_render_context& _this, uint32_t width, uint32_t height);
	static void __cdecl graphics_render(c_window_render_context& _this);
	static void __cdecl render_pass_render(c_window_render_context& _this);
	static void __cdecl render_imgui(c_window_render_context& _this);
	static BCS_RESULT __cdecl graphics_present(c_window_render_context& _this);
	static void __cdecl swap_chain_resize_finish(c_window_render_context& _this, uint32_t width, unsigned height);
};

BCS_RESULT window_render_context_window_create(
	c_window& window,
	float4 background_color,
	c_window_render_context*& render_context,
	c_graphics* existing_graphics_context = nullptr);
BCS_RESULT window_render_context_destroy(c_window_render_context* render_context);
