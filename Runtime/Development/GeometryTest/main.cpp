#include "geometrytest-private-pch.h"

static float4 graphics_background_color = { 0.16f, 0.10f, 0.16f, 1.0f };
static float4 window_background_color = { 0.130f, 0.141f, 0.167f, 1.0f };

static c_window* window;
static c_render_context* window_render_context;

int main()
{
	const wchar_t* launch_filepath_command_line_argument = nullptr; // #TODO: implement this with the command line API

	BCS_FAIL_RETURN(register_process_module_by_pointer(main));
	BCS_RESULT rs0 = init_command_line();
	BCS_RESULT rs1 = init_console();
	if (BCS_SUCCEEDED(rs1)) rs1 = BCS_SUCCEEDED(command_line_has_argument_internal("commandline")) ? alloc_console("GeometryTest") : BCS_S_OK;

	s_engine_platform_build engine_platform_build = { _engine_type_halo3, _platform_type_pc_64bit, _build_halo3_guerilla };

	const blofeld::s_tag_group* model_tag_group = blofeld::get_tag_group_by_group_tag(engine_platform_build, blofeld::halo3::pc64::MODEL_TAG);
	h_group* model_high_level_group = new() h_group(engine_platform_build, *model_tag_group);

	const blofeld::s_tag_group* render_model_tag_group = blofeld::get_tag_group_by_group_tag(engine_platform_build, blofeld::halo3::pc64::RENDER_MODEL_TAG);
	h_group* render_model_high_level_group = new() h_group(engine_platform_build, *render_model_tag_group);
	
	h_tag& model_tag = model_high_level_group->create_tag_instance("geometrytest");
	h_tag& render_model_tag = render_model_high_level_group->create_tag_instance("geometrytest");

	blofeld::halo3::pc64::h_model_block_struct* model = dynamic_cast<decltype(model)>(&model_tag);
	blofeld::halo3::pc64::h_render_model_block_struct* render_model = dynamic_cast<decltype(render_model)>(&render_model_tag);

	model->render_model.set_tag(render_model);



	const char* model_path;
	BCS_RESULT get_command_line_argument_result = command_line_get_argument("modelpath", model_path);
	BCS_FAIL_THROW(get_command_line_argument_result);

	c_geometry_scene* geometry_scene;
	BCS_RESULT load_geometry_scene_from_file_result = load_geometry_scene_from_file(model_path, geometry_scene);
	BCS_FAIL_THROW(load_geometry_scene_from_file_result);


	auto& runtime_region = model->runtime_regions_block.emplace_back();


	using namespace blofeld::halo3::pc64;

	render_model->name = "test";
	auto& region = render_model->regions_block.emplace_back();
	region.name = "hello world";
	render_model->flags.set(_render_model_flags_definition_unused2, true);
	render_model->render_geometry.runtime_flags.set(_render_geometry_flags_processed, true);
	render_model->render_geometry.runtime_flags.set(_render_geometry_flags_available, true);
	render_model->default_lightprobe_r[0].coefficient = 200.0f;






	c_high_level_tag_file_writer tag_file_writer(engine_platform_build, "C:\\Program Files (x86)\\Steam\\steamapps\\common\\H3EK\\tags\\geometrytest.model", model_tag);
	c_high_level_tag_file_writer tag_file_writer2(engine_platform_build, "C:\\Program Files (x86)\\Steam\\steamapps\\common\\H3EK\\tags\\geometrytest.render_model", render_model_tag);

	BCS_RESULT geometry_scene_destroy_result = geometry_scene_destroy(geometry_scene);
	BCS_FAIL_THROW(geometry_scene_destroy_result);

	debug_point;

	if (BCS_SUCCEEDED(rs1)) rs1 = deinit_console();
	if (BCS_SUCCEEDED(rs0)) rs0 = deinit_command_line();

	BCS_FAIL_RETURN(rs1);
	BCS_FAIL_RETURN(rs0);

	return 0;
}
