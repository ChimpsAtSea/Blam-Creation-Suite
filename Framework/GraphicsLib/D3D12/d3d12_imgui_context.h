#pragma once

class c_window_windows;
class c_graphics_d3d12;

struct ImGuiContext;

class c_imgui_context_d3d12 :
	public c_imgui_context
{
public:
	c_imgui_context_d3d12(
		c_window_windows& window,
		c_graphics_d3d12& graphics);
	~c_imgui_context_d3d12();

	c_window_windows& window;
	c_graphics_d3d12& graphics;

	ImGuiContext* imgui_context;
	ImFont* imgui_font;
	uint32_t imgui_srv_descriptor_index;
	D3D12_CPU_DESCRIPTOR_HANDLE imgui_srv_cpu_descriptor_handle;
	D3D12_GPU_DESCRIPTOR_HANDLE imgui_srv_gpu_descriptor_handle;
	t_callback_handle window_procedure_callback_handle;

	void init_imgui_context();
	void deinit_imgui_context();
	void init_imgui_font();
	void deinit_imgui_font();
	void init_imgui_impl();
	void deinit_imgui_impl();

	static void __cdecl on_window_procedure_callback(HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam);

	virtual void render() override;
	virtual BCS_RESULT get_context(ImGuiContext*& imgui_context) override;

	static float calculate_font_scale_factor();
};

BCS_SHARED BCS_RESULT graphics_d3d12_imgui_context_create(
	c_window_windows* window,
	c_graphics_d3d12* graphics, 
	c_imgui_context_d3d12*& imgui_context);
BCS_SHARED BCS_RESULT graphics_d3d12_imgui_context_destroy(c_imgui_context_d3d12* imgui_context);
