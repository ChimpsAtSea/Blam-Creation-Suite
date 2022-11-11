#include "graphicslib-private-pch.h"

c_imgui_context::c_imgui_context() :
	render_callback(),
	current_file_dialog_handle()
{

}

c_imgui_context::~c_imgui_context()
{

}

ImGuiContext* c_imgui_context::imgui_create_context_with_userdata(ImFontAtlas* shared_font_atlas, void* userdata)
{
	using namespace ImGui;
#undef new

	ImGuiContext* prev_ctx = GetCurrentContext();

	void** context_memory = static_cast<void**>(ImGui::MemAlloc(sizeof(void*) + sizeof(ImGuiContext)));
	context_memory[0] = userdata;
	ImGuiContext* ctx = new(ImNewWrapper(), context_memory + 1) ImGuiContext(shared_font_atlas);

	SetCurrentContext(ctx);
	Initialize();
	if (prev_ctx != NULL)
		SetCurrentContext(prev_ctx); // Restore previous context if any, else keep new one.
	return ctx;
}

static void* imgui_malloc(size_t sz, void* user_data)
{
	return tracked_malloc(sz);
}

static void imgui_free(void* ptr, void* user_data)
{
	tracked_free(ptr);
}

BCS_RESULT graphics_imgui_context_create(
	c_window* window,
	c_graphics* graphics,
	c_imgui_context*& imgui_context)
{
	ImGui::SetAllocatorFunctions(imgui_malloc, imgui_free, nullptr);

	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		c_window_windows* window_windows = dynamic_cast<c_window_windows*>(window);
		if (window_windows == nullptr)
		{
			return BCS_E_INVALID_ARGUMENT;
		}
		return graphics_d3d12_imgui_context_create(
			window_windows,
			graphics_d3d12,
			*reinterpret_cast<c_imgui_context_d3d12**>(&imgui_context));
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_imgui_context_destroy(c_imgui_context* imgui_context)
{
	if (c_imgui_context_d3d12* imgui_context_d3d12 = dynamic_cast<c_imgui_context_d3d12*>(imgui_context))
	{
		return graphics_d3d12_imgui_context_destroy(imgui_context_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}
