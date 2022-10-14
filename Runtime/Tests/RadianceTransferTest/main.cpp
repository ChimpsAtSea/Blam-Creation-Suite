#include "radiancetransfertest-private-pch.h"

BCS_RESULT graphics_radiance_transfer_test_result = BCS_E_NOT_RUN;

BCS_RESULT graphics_radiance_transfer_test()
{
	const char* model_path;
	BCS_RESULT get_command_line_argument_result = command_line_get_argument("modelpath", model_path);
	BCS_FAIL_THROW(get_command_line_argument_result);

	c_geometry_scene* geometry_scene;
	BCS_RESULT load_geometry_scene_from_file_result = load_geometry_scene_from_file(model_path, geometry_scene);
	BCS_FAIL_THROW(load_geometry_scene_from_file_result);

	c_radiance_transfer_engine* radiance_transfer_engine;
	BCS_RESULT radiance_transfer_create_result = radiance_transfer_create(
		_radiance_transfer_engine_gpu,
		2,
		32,
		false,
		false,
		radiance_transfer_engine);
	ASSERT(BCS_SUCCEEDED(radiance_transfer_create_result));

	unsigned int num_meshes = geometry_scene->get_num_meshes();
	for (unsigned int mesh_index = 0; mesh_index < num_meshes; mesh_index++)
	{
		c_geometry_mesh* geometry_mesh = geometry_scene->get_mesh(mesh_index);

		BCS_RESULT radiance_transfer_add_mesh_result = radiance_transfer_add_mesh(radiance_transfer_engine, geometry_mesh);
		ASSERT(BCS_SUCCEEDED(radiance_transfer_add_mesh_result));

		debug_point;
	}

	BCS_RESULT radiance_transfer_bake_result = radiance_transfer_bake(radiance_transfer_engine);
	ASSERT(BCS_SUCCEEDED(radiance_transfer_bake_result));

	for (unsigned int mesh_index = 0; mesh_index < num_meshes; mesh_index++)
	{
		c_geometry_mesh* geometry_mesh = geometry_scene->get_mesh(mesh_index);

		float const* const* surface_coefficient_planes;
		float const* const* subsurface_coefficient_planes;
		unsigned int num_coefficient_planes;
		BCS_RESULT radiance_transfer_read_result = radiance_transfer_read(
			radiance_transfer_engine,
			geometry_mesh,
			surface_coefficient_planes,
			subsurface_coefficient_planes,
			num_coefficient_planes);
		ASSERT(BCS_SUCCEEDED(radiance_transfer_read_result));
		ASSERT(num_coefficient_planes == 9);

		debug_point;
	}

	BCS_RESULT radiance_transfer_destroy_result = radiance_transfer_destroy(radiance_transfer_engine);
	ASSERT(BCS_SUCCEEDED(radiance_transfer_destroy_result));

	BCS_RESULT geometry_scene_destroy_result = geometry_scene_destroy(geometry_scene);
	BCS_FAIL_THROW(geometry_scene_destroy_result);

	return BCS_S_OK;
}

int main()
{
	BCS_RESULT register_process_module_by_pointer_result = BCS_E_NOT_RUN;
	BCS_RESULT init_command_line_result = BCS_E_NOT_RUN;
	BCS_RESULT init_console_result = BCS_E_NOT_RUN;

	if (BCS_SUCCEEDED(register_process_module_by_pointer_result = register_process_module_by_pointer(main)))
	{
		if (BCS_SUCCEEDED(init_command_line_result = init_command_line()))
		{
			if (BCS_SUCCEEDED(init_console_result = init_console()))
			{
				graphics_radiance_transfer_test_result = graphics_radiance_transfer_test();
			}
		}
	}

	BCS_FAIL_RETURN(init_console_result);
	BCS_FAIL_RETURN(init_command_line_result);
	BCS_FAIL_RETURN(register_process_module_by_pointer_result);

	BCS_RESULT deinit_console_result = deinit_console();
	BCS_RESULT deinit_command_line_result = deinit_command_line();

	BCS_FAIL_RETURN(deinit_console_result);
	BCS_FAIL_RETURN(deinit_command_line_result);

	return graphics_radiance_transfer_test_result;
}
