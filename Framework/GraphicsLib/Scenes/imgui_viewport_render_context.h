#pragma once

class c_imgui_viewport_render_context :
	public c_render_context
{
public:
	c_imgui_viewport_render_context(c_imgui_context& imgui_context);
	~c_imgui_viewport_render_context();

	virtual void render() override;
	virtual BCS_RESULT get_window(c_window*& window) override;
	virtual BCS_RESULT get_imgui_context(c_imgui_context*& imgui_context) override;
	virtual BCS_RESULT get_graphics(c_graphics*& graphics) override;
	virtual unsigned long get_width() override;
	virtual unsigned long get_height() override;
	virtual float get_width_float() override;
	virtual float get_height_float() override;
};

BCS_RESULT imgui_viewport_render_context_window_create(
	c_imgui_context& imgui_context,
	c_imgui_viewport_render_context*& render_context);
BCS_RESULT imgui_viewport_render_context_destroy(c_imgui_viewport_render_context* render_context);
