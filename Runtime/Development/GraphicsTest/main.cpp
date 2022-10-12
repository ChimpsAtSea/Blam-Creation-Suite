#include "graphicstest-private-pch.h"

static float4 graphics_background_color = { 0.16f, 0.10f, 0.16f, 1.0f };
static float4 window_background_color = { 0.130f, 0.141f, 0.167f, 1.0f };

static c_window* window;
static c_render_context* window_render_context;

int main()
{
	BCS_FAIL_RETURN(register_process_module_by_pointer(main));
	BCS_RESULT rs2 = window_create("Graphics Test", "graphicstest", _window_icon_mandrill, ULONG_MAX, ULONG_MAX, window_background_color, true, false, window);
	BCS_RESULT rs3 = render_context_window_create(*window, graphics_background_color, window_render_context);

	window_render_context->render();

	if (BCS_SUCCEEDED(rs3)) rs3 = render_context_destroy(window_render_context);
	if (BCS_SUCCEEDED(rs2)) rs2 = window_destroy(window);

	BCS_FAIL_RETURN(rs3);
	BCS_FAIL_RETURN(rs2);

	return 0;
}

struct HINSTANCE__;
int __stdcall wWinMain(
	void* hInstance,
	void* hPrevInstance,
	const wchar_t* lpCmdLine,
	int nShowCmd
)
{
	return main();
}
