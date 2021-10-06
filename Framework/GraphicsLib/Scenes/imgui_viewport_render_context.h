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
	virtual BCS_RESULT get_viewport(c_viewport*& viewport) override;
	virtual BCS_RESULT get_window(c_window*& window) override;
	virtual BCS_RESULT get_imgui_context(c_imgui_context*& imgui_context) override;
	virtual BCS_RESULT get_graphics(c_graphics*& graphics) override;
	virtual unsigned long get_width() override;
	virtual unsigned long get_height() override;
	virtual float get_width_float() override;
	virtual float get_height_float() override;

	static void __cdecl viewport_size_changed(c_imgui_viewport_render_context& _this, unsigned long width, unsigned long height);

	c_render_context& parent_render_context;
	c_viewport& viewport;
	c_graphics_render_target* render_target;
	t_callback_handle viewport_size_changed_handle;
};

BCS_RESULT render_context_imgui_viewport_create(
	c_render_context& parent_render_context,
	c_viewport& viewport,
	float4 clear_color,
	c_imgui_viewport_render_context*& render_context);
BCS_RESULT render_context_imgui_viewport_destroy(c_imgui_viewport_render_context* render_context);
