#include "halo2cachefilebuildertest-private-pch.h"

extern "C" int bcs_main()
{
	const wchar_t* launch_filepath_command_line_argument = nullptr; // #TODO: implement this with the command line API

	BCS_RESULT rs1 = BCS_SUCCEEDED(command_line_has_argument_internal("commandline")) ? alloc_console("Halo 2 Cache File Builder Test Console") : BCS_S_OK;

	BCS_RESULT rs = BCS_S_OK;

	const wchar_t* project_directory;
	if (BCS_FAILED(rs = command_line_get_argument(L"projectdirectory", project_directory)))
	{
		return rs;
	}

	BCS_RESULT rs2 = BCS_S_OK;
	try
	{
		s_engine_platform_build engine_platform_build = { _engine_type_halo2, _platform_type_pc_64bit };
		c_filesystem_tag_project tag_project = c_filesystem_tag_project(project_directory, engine_platform_build, nullptr);

		debug_point;
	}
	catch (BCS_RESULT rs)
	{
		rs2 = rs;
	}
	catch (...)
	{
		rs2 = BCS_E_FATAL;
	}

	BCS_FAIL_RETURN(rs1);

	return rs2;
}
