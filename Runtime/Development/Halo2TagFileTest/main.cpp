#include "halo2tagfiletest-private-pch.h"

int main()
{
	const wchar_t* launch_filepath_command_line_argument = nullptr; // #TODO: implement this with the command line API

	BCS_FAIL_RETURN(register_process_module_by_pointer(main));
	BCS_RESULT rs0 = init_command_line();
	BCS_RESULT rs1 = init_console();
	if (BCS_SUCCEEDED(rs1)) rs1 = BCS_SUCCEEDED(command_line_has_argument_internal("commandline")) ? alloc_console("Halo 2 Tag File Test Console") : BCS_S_OK;

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

	h_tag* tag_prototype;
	BCS_RESULT rs2 = c_gen2_tag_file_parse_context::parse_gen2_tag_file_data(tag_prototype, tag_file_path, engine_platform_build);
	debug_point;

	if (BCS_SUCCEEDED(rs1)) rs1 = deinit_console();
	if (BCS_SUCCEEDED(rs0)) rs0 = deinit_command_line();

	BCS_FAIL_RETURN(rs1);
	BCS_FAIL_RETURN(rs0);

	return rs2;
}
