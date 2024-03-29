#include "halo1tagfiletest-private-pch.h"

static c_window* window;
static c_render_context* window_render_context;

static float4 graphics_background_color = { 0.16f, 0.10f, 0.16f, 1.0f };
static float4 window_background_color = { 0.130f, 0.141f, 0.167f, 1.0f };

extern "C" int bcs_main()
{
	const wchar_t* launch_filepath_command_line_argument = nullptr; // #TODO: implement this with the command line API
	BCS_RESULT rs1 = BCS_SUCCEEDED(command_line_has_argument_internal("commandline")) ? alloc_console("Halo 1 Tag File Test Console") : BCS_S_OK;

	BCS_RESULT rs = BCS_S_OK;

	const wchar_t* tag_file_path;
	if (BCS_FAILED(rs = command_line_get_argument(L"tagfilepath", tag_file_path)))
	{
		return rs;
	}

	const char* output_tag_file_path;
	if (BCS_FAILED(rs = command_line_get_argument("outputtagfilepath", output_tag_file_path)))
	{
		return rs;
	}

	s_engine_platform_build	engine_platform_build = { _engine_type_halo1, _platform_type_pc_64bit, _build_halo1_guerilla };

	h_prototype* tag_prototype;
	blofeld::s_tag_group const* tag_group_definition;
	BCS_RESULT rs2 = c_gen1_tag_file_parse_context::parse_gen1_tag_file_data(tag_prototype, tag_group_definition, tag_file_path, engine_platform_build);
	debug_point;

	BCS_FAIL_RETURN(rs1);

	return rs2;
}
