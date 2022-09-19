#include "geometrytest-private-pch.h"

static float4 graphics_background_color = { 0.16f, 0.10f, 0.16f, 1.0f };
static float4 window_background_color = { 0.130f, 0.141f, 0.167f, 1.0f };

static c_window* window;
static c_render_context* window_render_context;

int main()
{
	const wchar_t* launch_filepath_command_line_argument = nullptr; // #TODO: implement this with the command line API

	BCS_FAIL_RETURN(register_process_module_by_pointer(main));
	BCS_RESULT rs2 = window_create("Geometry Test", "geometrytest", _window_icon_mandrill, ULONG_MAX, ULONG_MAX, window_background_color, false, window);
	BCS_RESULT rs3 = render_context_window_create(*window, graphics_background_color, window_render_context);

	window_render_context->render();

	if (BCS_SUCCEEDED(rs3)) rs3 = render_context_destroy(window_render_context);
	if (BCS_SUCCEEDED(rs2)) rs2 = window_destroy(window);

	BCS_FAIL_RETURN(rs3);
	BCS_FAIL_RETURN(rs2);

	return 0;
}

#include <Windows.h>
int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	return main();
}
