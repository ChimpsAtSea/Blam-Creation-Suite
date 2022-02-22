#pragma once

class c_window;
class c_graphics;

struct ImGuiContext;

class c_imgui_context
{
protected:
	c_imgui_context();
public:
	virtual ~c_imgui_context();

	virtual void render() = 0;
	virtual BCS_RESULT get_context(ImGuiContext*& imgui_context) = 0;

	using t_render_callback_d3d12 = void();
	c_typed_callback<t_render_callback_d3d12> render_callback;
};

BCS_DEBUG_API BCS_RESULT graphics_imgui_context_create(
	c_window* window,
	c_graphics* graphics, 
	c_imgui_context*& imgui_context);
BCS_DEBUG_API BCS_RESULT graphics_imgui_context_destroy(c_imgui_context* imgui_context);
