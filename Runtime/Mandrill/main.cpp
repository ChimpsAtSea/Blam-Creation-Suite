#include "mandrill-private-pch.h"

#ifdef _DEBUG
static constexpr const char window_title[] = "Mandrill Debug";
#else
static constexpr const char window_title[] = "Mandrill";
#endif

static c_window* window;
static c_render_context* window_render_context;
static c_mandrill_user_interface* mandrill_user_interface;

static float4 graphics_background_color = { 0.16f, 0.10f, 0.16f, 1.0f };
static float4 window_background_color = { 0.130f, 0.141f, 0.167f, 1.0f };

int WINAPI wWinMain(
	_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nShowCmd
)
{
	const wchar_t* launch_filepath_command_line_argument = nullptr; // #TODO: implement this with the command line API

	BCS_FAIL_RETURN(register_process_module_by_pointer(wWinMain));
	BCS_RESULT rs0 = init_command_line(lpCmdLine);
	BCS_RESULT rs1 = init_console();
	if(BCS_SUCCEEDED(rs1)) rs1 = BCS_SUCCEEDED(command_line_has_argument("console")) ? alloc_console("Mandrill") : BCS_S_OK;
	BCS_RESULT rs2 = window_create(window_title, "mandrill", _window_icon_mandrill, ULONG_MAX, ULONG_MAX, window_background_color, window);
	BCS_RESULT rs3 = render_context_window_create(*window, graphics_background_color, window_render_context);

	mandrill_user_interface = new c_mandrill_user_interface(
		*window_render_context,
		false, 
		launch_filepath_command_line_argument);

	window_render_context->render();

	delete mandrill_user_interface;

	if (BCS_SUCCEEDED(rs3)) rs3 = render_context_destroy(window_render_context);
	if (BCS_SUCCEEDED(rs2)) rs2 = window_destroy(window);
	if (BCS_SUCCEEDED(rs1)) rs1 = deinit_console();
	if (BCS_SUCCEEDED(rs0)) rs0 = deinit_command_line();

	BCS_FAIL_RETURN(rs3);
	BCS_FAIL_RETURN(rs2);
	BCS_FAIL_RETURN(rs1);
	BCS_FAIL_RETURN(rs0);
	
	return 0;
}
