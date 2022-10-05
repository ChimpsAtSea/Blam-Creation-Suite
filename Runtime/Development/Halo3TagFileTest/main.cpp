#include "halo3tagfiletest-private-pch.h"

#include <Generated/high_level_halo3_pc64/highlevel-halo3-pc64-public-pch.h>

static int32_t _depth = -1;

int main()
{
	const wchar_t* launch_filepath_command_line_argument = nullptr; // #TODO: implement this with the command line API

	BCS_FAIL_RETURN(register_process_module_by_pointer(main));
	BCS_RESULT rs0 = init_command_line();
	BCS_RESULT rs1 = init_console();
	if (BCS_SUCCEEDED(rs1)) rs1 = BCS_SUCCEEDED(command_line_has_argument_internal("commandline")) ? alloc_console("Halo 3 Tag File Test Console") : BCS_S_OK;

	const wchar_t* project_filepath;
	const char* tag_filepath;
	if (BCS_SUCCEEDED(command_line_get_argument(L"filesystemprojectfilepath", project_filepath)))
	{
		s_engine_platform_build engine_platform_build = { _engine_type_halo3, _platform_type_pc_64bit, _build_halo3_guerilla };
		c_filesystem_tag_project tag_project = c_filesystem_tag_project(project_filepath, engine_platform_build, nullptr);

		debug_point;
	}
	else if (BCS_SUCCEEDED(command_line_get_argument("tagfilepath", tag_filepath)))
	{
		s_engine_platform_build engine_platform_build = { _engine_type_halo3, _platform_type_pc_64bit, _build_halo3_guerilla };
		c_tag_file_high_level_transplant high_level_transplant = c_tag_file_high_level_transplant(tag_filepath, engine_platform_build);
		h_tag* tag = high_level_transplant.parse_tag();

		debug_point;

		const char* output_filepath;
		if (BCS_SUCCEEDED(command_line_get_argument("outputtagfilepath", output_filepath)))
		{
			c_high_level_tag_file_writer tag_file_writer(engine_platform_build, output_filepath, *tag);

			debug_point;
		}

		delete tag;
	}

	if (BCS_SUCCEEDED(rs1)) rs1 = deinit_console();
	if (BCS_SUCCEEDED(rs0)) rs0 = deinit_command_line();

	BCS_FAIL_RETURN(rs1);
	BCS_FAIL_RETURN(rs0);

	return 0;
}
