#pragma once

class c_window;
class c_viewport;
class c_imgui_context;

class c_render_context
{
protected:
	c_render_context();
public:
	virtual ~c_render_context();

	virtual void render() = 0;
	virtual BCS_RESULT get_viewport(c_viewport*& viewport) = 0;
	virtual BCS_RESULT get_window(c_window*& _window) = 0;
	virtual BCS_RESULT get_imgui_context(c_imgui_context*& imgui_context) = 0;
	virtual BCS_RESULT get_graphics(c_graphics*& graphics) = 0;
	virtual unsigned long get_width() = 0;
	virtual unsigned long get_height() = 0;
	virtual float get_width_float() = 0;
	virtual float get_height_float() = 0;

	using t_on_render_callback = void();
	c_typed_callback<t_on_render_callback> on_render_background;
	c_typed_callback<t_on_render_callback> on_render_foreground;
};

BCS_DEBUG_API BCS_RESULT render_context_window_create(
	c_window& window,
	float4 background_color,
	c_render_context*& render_context);
BCS_DEBUG_API BCS_RESULT render_context_imgui_create(
	c_render_context& parent_render_context,
	c_viewport& viewport,
	float4 background_color,
	c_render_context*& render_context);
BCS_DEBUG_API BCS_RESULT render_context_destroy(c_render_context* render_context);
