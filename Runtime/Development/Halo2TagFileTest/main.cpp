#include "halo2tagfiletest-private-pch.h"

extern "C" int bcs_main()
{
	const wchar_t* launch_filepath_command_line_argument = nullptr; // #TODO: implement this with the command line API

	BCS_RESULT rs1 = BCS_SUCCEEDED(command_line_has_argument_internal("commandline")) ? alloc_console("Halo 2 Tag File Test Console") : BCS_S_OK;

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

	s_engine_platform_build	engine_platform_build = { _engine_type_halo2, _platform_type_pc_64bit, _build_halo2_guerilla };

	h_tag_instance* tag_instance;
	BCS_RESULT rs2 = c_gen2_tag_file_parse_context::parse_gen2_tag_file_data(tag_instance, tag_file_path, engine_platform_build);
	debug_point;

	BCS_FAIL_RETURN(rs1);

	return rs2;
}
