#include "imguiuiprototype-private-pch.h"

#ifdef _DEBUG
static constexpr const char window_title[] = "Mandrill Debug";
#else
static constexpr const char window_title[] = "Mandrill";
#endif

static c_window* window;
static c_render_context* window_render_context;

static float4 graphics_background_color = { 0.16f, 0.10f, 0.16f, 1.0f };
static float4 window_background_color = { 0.130f, 0.141f, 0.167f, 1.0f };

void mandrill(c_window& window);
void mandrill_tag_explorer_prototype(c_window& window);
void validation_memory_explorer_prototype(c_window& window);

static t_callback_handle imgui_draw_callback_handle;

extern "C" int bcs_main()
{
	BCS_RESULT rs1 = BCS_SUCCEEDED(command_line_has_argument_internal("commandline")) ? init_console() : BCS_S_OK;
	BCS_RESULT rs2 = window_create(window_title, "mandrill", _window_icon_mandrill, ULONG_MAX, ULONG_MAX, window_background_color, true, false, window);
	BCS_RESULT rs3 = render_context_window_create(*window, graphics_background_color, window_render_context);

	ASSERT(BCS_SUCCEEDED(window_render_context->on_render_foreground.add_callback(validation_memory_explorer_prototype, window, imgui_draw_callback_handle)));
	window_render_context->render();
	ASSERT(BCS_SUCCEEDED(window_render_context->on_render_foreground.remove_callback(imgui_draw_callback_handle)));

	if (BCS_SUCCEEDED(rs3)) rs3 = render_context_destroy(window_render_context);
	if (BCS_SUCCEEDED(rs2)) rs2 = window_destroy(window);
	if (BCS_SUCCEEDED(rs1)) rs1 = deinit_console();

	BCS_FAIL_RETURN(rs3);
	BCS_FAIL_RETURN(rs2);
	BCS_FAIL_RETURN(rs1);

	return 0;
}
