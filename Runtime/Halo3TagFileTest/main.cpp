#include "halo3tagfiletest-private-pch.h"


#ifdef _DEBUG
static constexpr const char window_title[] = "Halo 3 Tag File Test Debug";
#else
static constexpr const char window_title[] = "Halo 3 Tag File Test";
#endif

static c_window* window;
static c_render_context* window_render_context;
static c_mandrill_user_interface* mandrill_user_interface;

static float4 graphics_background_color = { 0.16f, 0.10f, 0.16f, 1.0f };
static float4 window_background_color = { 0.130f, 0.141f, 0.167f, 1.0f };

// s_tracked_memory_stats halo3tagfiletest_tracked_memory = { "halo3tagfiletest" };
// s_tracked_memory_stats& _library_tracked_memory = halo3tagfiletest_tracked_memory;

#include <HighLevel/high_level_halo3/highlevel-halo3-public-pch.h>

static long _depth = -1;

int main()
{
	const wchar_t* launch_filepath_command_line_argument = nullptr; // #TODO: implement this with the command line API

	BCS_FAIL_RETURN(register_process_module_by_pointer(main));
	BCS_RESULT rs0 = init_command_line();
	BCS_RESULT rs1 = init_console();
	if (BCS_SUCCEEDED(rs1)) rs1 = BCS_SUCCEEDED(command_line_has_argument("commandline")) ? alloc_console("Halo 3 Tag File Test Console") : BCS_S_OK;

	const char* filepath;
	if (BCS_SUCCEEDED(command_line_get_argument("tagfilepath", filepath)))
	{
		const char* output_filepath;
		if (BCS_SUCCEEDED(command_line_get_argument("outputtagfilepath", output_filepath)))
		{
			s_engine_platform_build engine_platform_build = { _engine_type_halo3, _platform_type_pc_64bit, _build_halo3_guerilla };;
			c_tag_file_high_level_transplant high_level_transplant = c_tag_file_high_level_transplant(filepath, engine_platform_build);
			h_tag* tag = high_level_transplant.parse_tag();

			c_high_level_tag_file_writer tag_file_writer(engine_platform_build, output_filepath, *tag);

			debug_point;
		}
	}

	if (BCS_SUCCEEDED(rs1)) rs1 = deinit_console();
	if (BCS_SUCCEEDED(rs0)) rs0 = deinit_command_line();

	BCS_FAIL_RETURN(rs1);
	BCS_FAIL_RETURN(rs0);

	return 0;
}
