#include "graphicslib-private-pch.h"

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

#include <imgui\backends\imgui_impl_win32.h>
#include <imgui\backends\imgui_impl_dx12.h>

c_imgui_context_d3d12::c_imgui_context_d3d12(
	c_window_windows& window,
	c_graphics_d3d12& graphics) :
	window(window),
	graphics(graphics),
	imgui_context(nullptr),
	imgui_font(nullptr),
	imgui_srv_descriptor_index(),
	imgui_srv_cpu_descriptor_handle(),
	imgui_srv_gpu_descriptor_handle(),
	window_procedure_callback_handle()
{
	init_imgui_context();
	init_imgui_font();
	init_imgui_impl();

	window.on_window_procedure.add_callback(on_window_procedure_callback, window_procedure_callback_handle);
}

c_imgui_context_d3d12::~c_imgui_context_d3d12()
{
	window.on_window_procedure.remove_callback(window_procedure_callback_handle);

	deinit_imgui_impl();
	deinit_imgui_font();
	deinit_imgui_context();
}

void c_imgui_context_d3d12::init_imgui_context()
{
	imgui_context = ImGui::CreateContext();
}

void c_imgui_context_d3d12::deinit_imgui_context()
{
	ImGui::DestroyContext(imgui_context);
}

void c_imgui_context_d3d12::init_imgui_font()
{
	float font_scale = calculate_font_scale_factor();
	float default_font_size = 15.0f * font_scale;
	float font_awesome_font_size = 13.0f * font_scale;

	ImGuiIO& imgui_io = ImGui::GetIO();

	imgui_io.Fonts->Clear();

	ImFontConfig default_font_configuration = {};
	default_font_configuration.MergeMode = false;
	//font_awesome_font_configuration.GlyphMinAdvanceX = font_size; // Use if you want to make the icon monospaced
	default_font_configuration.PixelSnapH = true;

	void* default_font_resource_data;
	unsigned long long default_font_resource_data_size;
	resources_read_resource_to_memory(_bcs_resource_type_font_cousine_regular, default_font_resource_data, default_font_resource_data_size);

	imgui_font = imgui_io.Fonts->AddFontFromMemoryTTF(default_font_resource_data, static_cast<int>(default_font_resource_data_size), default_font_size, &default_font_configuration, imgui_io.Fonts->GetGlyphRangesDefault());


	ImFontConfig font_awesome_font_configuration;
	font_awesome_font_configuration.MergeMode = true;
	font_awesome_font_configuration.GlyphMinAdvanceX = font_awesome_font_size * 1.25f; // Use if you want to make the icon monospaced
	font_awesome_font_configuration.PixelSnapH = true;

	void* font_awesome_font_resource_data;
	unsigned long long font_awesome_font_resource_data_size;
	resources_read_resource_to_memory(_bcs_resource_type_font_font_awesome, font_awesome_font_resource_data, font_awesome_font_resource_data_size);

	static const ImWchar icon_ranges[] = { ICON_MIN_FA, ICON_MAX_FA, 0 };
	imgui_font = imgui_io.Fonts->AddFontFromMemoryTTF(font_awesome_font_resource_data, static_cast<int>(font_awesome_font_resource_data_size), font_awesome_font_size, &font_awesome_font_configuration, icon_ranges);

	imgui_io.Fonts->Build();
	ImGui::SetCurrentFont(imgui_font);

	//delete default_font_resource_data;
	//delete font_awesome_font_resource_data;
}

void c_imgui_context_d3d12::deinit_imgui_font()
{

}

void c_imgui_context_d3d12::init_imgui_impl()
{
	imgui_srv_descriptor_index = graphics.cbv_srv_uav_descriptor_heap_allocator_gpu->allocate();
	imgui_srv_cpu_descriptor_handle = graphics.cbv_srv_uav_descriptor_heap_allocator_gpu->get_cpu_descriptor_handle(imgui_srv_descriptor_index);
	imgui_srv_gpu_descriptor_handle = graphics.cbv_srv_uav_descriptor_heap_allocator_gpu->get_gpu_descriptor_handle(imgui_srv_descriptor_index);

	ImGui_ImplWin32_Init(window.window_handle);
	ImGui_ImplDX12_Init(
		graphics.device,
		1,
		DXGI_FORMAT_R8G8B8A8_UNORM,
		graphics.cbv_srv_uav_descriptor_heap_allocator_gpu->descriptor_heap,
		imgui_srv_cpu_descriptor_handle,
		imgui_srv_gpu_descriptor_handle);
}

void c_imgui_context_d3d12::deinit_imgui_impl()
{
	ImGui_ImplWin32_Shutdown();
	ImGui_ImplDX12_Shutdown();
}

void __cdecl c_imgui_context_d3d12::on_window_procedure_callback(HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam)
{
	ImGui_ImplWin32_WndProcHandler(window_handle, message, wparam, lparam);
}

void c_imgui_context_d3d12::render()
{
	ImGui_ImplDX12_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	render_callback();

	ImGui::Render();
	ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), graphics.command_list);
}

BCS_RESULT c_imgui_context_d3d12::get_context(ImGuiContext*& out_imgui_context)
{
	out_imgui_context = imgui_context;
	return BCS_S_OK;
}

static BOOL CALLBACK monitor_enum_procedure(HMONITOR monitor_handle, HDC device_context_handle, LPRECT rectangle, LPARAM userdata)
{
	HMONITOR& result = *reinterpret_cast<HMONITOR*>(userdata);

	result = monitor_handle;

	return false;
}

float c_imgui_context_d3d12::calculate_font_scale_factor()
{
	HMONITOR monitor;
	EnumDisplayMonitors(NULL, NULL, monitor_enum_procedure, reinterpret_cast<LPARAM>(&monitor));
	

	UINT monitor_dpi_raw[2];
	GetDpiForMonitor(monitor, MDT_EFFECTIVE_DPI, &monitor_dpi_raw[0], &monitor_dpi_raw[1]);

	float monitor_dpi_x = static_cast<float>(monitor_dpi_raw[0]);
	float monitor_dpi_y = static_cast<float>(monitor_dpi_raw[1]);
	float monitor_dpi = (monitor_dpi_x + monitor_dpi_y) / 2.0f;

	float default_monitor_dpi = 96.0f;

	float scaling_factor = __max(1.0f, monitor_dpi / default_monitor_dpi);

	return scaling_factor;
}

BCS_RESULT graphics_d3d12_imgui_context_create(
	c_window_windows* window,
	c_graphics_d3d12* graphics, 
	c_imgui_context_d3d12*& imgui_context)
{
	try
	{
		imgui_context = new c_imgui_context_d3d12(
			*window,
			*graphics);
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

BCS_RESULT graphics_d3d12_imgui_context_destroy(c_imgui_context_d3d12* imgui_context)
{
	try
	{
		delete imgui_context;
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}
