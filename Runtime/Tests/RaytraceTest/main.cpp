#include "raytracetest-private-pch.h"

constexpr unsigned int k_dispatch_width = 32;
constexpr unsigned int k_dispatch_height = 32;
unsigned int k_default_value = 0xDEADBEEF;

using t_buffer_type = uint4;

c_graphics* graphics;
void* raytracing_shader_binary_data;
uint64_t raytracing_shader_binary_size;
c_graphics_shader_binary* raytracing_test_shader_binary;
c_graphics_register_layout* raytracing_global_register_layout;
c_graphics_register_layout* raytracing_local_register_layout;
c_graphics_shader_pipeline* raytracing_test_shader_pipeline;
c_graphics_buffer* read_write_buffer;

BCS_RESULT graphics_create_result = BCS_E_NOT_RUN;
BCS_RESULT graphics_start_debug_capture_result = BCS_E_NOT_RUN;
BCS_RESULT read_raytracing_shader_binary_result = BCS_E_NOT_RUN;
BCS_RESULT raytracing_test_shader_binary_result = BCS_E_NOT_RUN;
BCS_RESULT raytracing_global_register_layout_create_result = BCS_E_NOT_RUN;
BCS_RESULT raytracing_local_register_layout_create_result = BCS_E_NOT_RUN;
BCS_RESULT raytracing_test_shader_pipeline_result = BCS_E_NOT_RUN;
BCS_RESULT read_write_buffer_create_result = BCS_E_NOT_RUN;
BCS_RESULT graphics_begin_result = BCS_E_NOT_RUN;
BCS_RESULT raytracing_register_layout_bind_result = BCS_E_NOT_RUN;
BCS_RESULT raytracing_register_layout_bind_buffers_result = BCS_E_NOT_RUN;
BCS_RESULT graphics_end_result = BCS_E_NOT_RUN;
BCS_RESULT read_write_buffer_read_data_result = BCS_E_NOT_RUN;
BCS_RESULT buffer_destroy_result = BCS_E_NOT_RUN;
BCS_RESULT shader_pipeline_destroy_result = BCS_E_NOT_RUN;
BCS_RESULT global_register_layout_destroy_result = BCS_E_NOT_RUN;
BCS_RESULT local_register_layout_destroy_result = BCS_E_NOT_RUN;
BCS_RESULT shader_binary_destroy_result = BCS_E_NOT_RUN;
BCS_RESULT graphics_destroy_result = BCS_E_NOT_RUN;
BCS_RESULT raytracing_test_result = BCS_E_NOT_RUN;

void bcs_test_validate(BCS_RESULT rs, const char* name)
{
	const char* result_string;
	if (BCS_FAILED(bcs_result_to_string_mb(rs, result_string)))
	{
		result_string = "<unknown>";
	}

	if (BCS_SUCCEEDED(rs))
	{
		console_write_line("%s success %s", name, result_string);
	}
	else
	{
		console_write_line("%s failed %s", name, result_string);
	}
}
#define BCS_TEST_VALIDATE(bcs_result) bcs_test_validate(bcs_result, #bcs_result); BCS_FAIL_RETURN(bcs_result)


BCS_RESULT graphics_raytracing_test_init()
{
	if (BCS_SUCCEEDED(graphics_create_result = graphics_create(_graphics_architecture_d3d12_raytracing, true, graphics)))
	{
		if (BCS_SUCCEEDED(graphics_start_debug_capture_result = graphics->start_debug_capture()))
		{
			console_write_line("Signaling debug frame");
		}

		if (BCS_SUCCEEDED(read_raytracing_shader_binary_result = resources_read_local_resource_to_memory(
			"raytracetest_shader.cso",
			raytracing_shader_binary_data,
			raytracing_shader_binary_size)))
		{
			if (BCS_SUCCEEDED(raytracing_test_shader_binary_result = graphics_shader_binary_create(
				graphics,
				raytracing_shader_binary_data,
				raytracing_shader_binary_size,
				raytracing_test_shader_binary)))
			{
				s_graphics_register_layout_description raytracing_global_register_layouts[1];
				raytracing_global_register_layouts[0].semantic = _graphics_register_layout_unordered_access;
				raytracing_global_register_layouts[0].register_index = 0;
				raytracing_global_register_layouts[0].register_count = 1;
				raytracing_global_register_layouts[0].register_space = 0;
				raytracing_global_register_layouts[0].num_32_bit_values = 0;
				raytracing_global_register_layouts[0].use_table = true;
				raytracing_global_register_layouts[0].sampler_layout_description = nullptr;

				if (BCS_SUCCEEDED(raytracing_global_register_layout_create_result = graphics_register_layout_create(
					graphics,
					_graphics_register_layout_type_global_raytracing,
					raytracing_global_register_layouts,
					_countof(raytracing_global_register_layouts),
					raytracing_global_register_layout,
					"raytracing_global_register_layout")))
				{
					s_graphics_register_layout_description raytracing_local_register_layouts[1];
					raytracing_local_register_layouts[0].semantic = _graphics_register_layout_unordered_access;
					raytracing_local_register_layouts[0].register_index = 0;
					raytracing_local_register_layouts[0].register_count = 1;
					raytracing_local_register_layouts[0].register_space = 1;
					raytracing_local_register_layouts[0].num_32_bit_values = 0;
					raytracing_local_register_layouts[0].use_table = true;
					raytracing_local_register_layouts[0].sampler_layout_description = nullptr;

					if (BCS_SUCCEEDED(raytracing_local_register_layout_create_result = graphics_register_layout_create(
						graphics,
						_graphics_register_layout_type_local_raytracing,
						raytracing_local_register_layouts,
						_countof(raytracing_local_register_layouts),
						raytracing_local_register_layout,
						"raytracing_local_register_layout")))
					{
						if (BCS_SUCCEEDED(raytracing_test_shader_pipeline_result = graphics_shader_pipeline_raytracing_create(
							graphics,
							raytracing_global_register_layout,
							raytracing_local_register_layout,
							raytracing_test_shader_binary,
							L"RaygenShader",
							L"ClosestHitShader",
							L"MissShader",
							L"HitGroup",
							raytracing_test_shader_pipeline,
							"raytracing_pipeline")))
						{
							if (BCS_SUCCEEDED(read_write_buffer_create_result = graphics_buffer_create(
								graphics,
								_graphics_buffer_type_unordered_access_view,
								k_dispatch_width * k_dispatch_height * sizeof(t_buffer_type),
								read_write_buffer,
								"read_write_buffer")))
							{
								// finished
							}
						}
					}
				}
			}
		}
	}

	BCS_TEST_VALIDATE(graphics_create_result);
	BCS_TEST_VALIDATE(read_raytracing_shader_binary_result);
	BCS_TEST_VALIDATE(raytracing_test_shader_binary_result);
	BCS_TEST_VALIDATE(raytracing_local_register_layout_create_result);
	BCS_TEST_VALIDATE(raytracing_global_register_layout_create_result);
	BCS_TEST_VALIDATE(raytracing_test_shader_pipeline_result);
	BCS_TEST_VALIDATE(read_write_buffer_create_result);

	return BCS_S_OK;
}

BCS_RESULT graphics_raytracing_test_execute()
{
	if (BCS_SUCCEEDED(graphics_begin_result = graphics->begin()))
	{
		if (BCS_SUCCEEDED(raytracing_register_layout_bind_result = raytracing_global_register_layout->bind()))
		{
			raytracing_test_shader_pipeline->bind();

			if (BCS_SUCCEEDED(raytracing_register_layout_bind_buffers_result = raytracing_global_register_layout->bind_buffer(0, 0, *read_write_buffer)))
			{
				raytracing_test_shader_pipeline->dispatch_rays(k_dispatch_width, k_dispatch_height);

				read_write_buffer->copy_readback();

				if (BCS_SUCCEEDED(graphics_end_result = graphics->end()))
				{
					// finished
				}
			}

			raytracing_test_shader_pipeline->unbind();
		}
	}

	BCS_TEST_VALIDATE(graphics_begin_result);
	BCS_TEST_VALIDATE(raytracing_register_layout_bind_result);
	BCS_TEST_VALIDATE(raytracing_register_layout_bind_buffers_result);
	BCS_TEST_VALIDATE(graphics_end_result);

	return BCS_S_OK;
}

BCS_RESULT graphics_raytracing_test_validate()
{
	unsigned int valid_data_points = 0;
	t_buffer_type* final_values = trivial_alloca(t_buffer_type, k_dispatch_width * k_dispatch_height);
	if (BCS_SUCCEEDED(read_write_buffer_read_data_result = read_write_buffer->read_data(final_values, sizeof(*final_values) * k_dispatch_width * k_dispatch_height, 0)))
	{
		for (unsigned int y = 0; y < k_dispatch_height; y++)
		{
			for (unsigned int x = 0; x < k_dispatch_width; x++)
			{
				unsigned int buffer_index = y * k_dispatch_width + x;
				t_buffer_type& final_value = final_values[buffer_index];
				if (final_value.x == x && final_value.y == y && final_value.z == buffer_index)
				{
					valid_data_points++;
				}
			}
		}
	}

	BCS_TEST_VALIDATE(read_write_buffer_read_data_result);

	if (valid_data_points != k_dispatch_width * k_dispatch_height)
	{
		return BCS_E_FAIL;
	}

	return BCS_S_OK;
}

BCS_RESULT graphics_raytracing_test_deinit()
{
	buffer_destroy_result = graphics_buffer_destroy(read_write_buffer);
	shader_pipeline_destroy_result = graphics_shader_pipeline_destroy(raytracing_test_shader_pipeline);
	global_register_layout_destroy_result = graphics_register_layout_destroy(raytracing_global_register_layout);
	local_register_layout_destroy_result = graphics_register_layout_destroy(raytracing_local_register_layout);
	shader_binary_destroy_result = graphics_shader_binary_destroy(raytracing_test_shader_binary);
	tracked_free(raytracing_shader_binary_data);
	graphics_destroy_result = graphics_destroy(graphics);


	BCS_TEST_VALIDATE(buffer_destroy_result);
	BCS_TEST_VALIDATE(shader_pipeline_destroy_result);
	BCS_TEST_VALIDATE(global_register_layout_destroy_result);
	BCS_TEST_VALIDATE(local_register_layout_destroy_result);
	BCS_TEST_VALIDATE(shader_binary_destroy_result);
	BCS_TEST_VALIDATE(graphics_destroy_result);

	return BCS_S_OK;
}

BCS_RESULT graphics_raytracing_test()
{
	BCS_RESULT graphics_raytracing_test_init_result = BCS_E_NOT_RUN;
	BCS_RESULT graphics_raytracing_test_execute_result = BCS_E_NOT_RUN;
	BCS_RESULT graphics_raytracing_test_validate_result = BCS_E_NOT_RUN;

	if (BCS_SUCCEEDED(graphics_raytracing_test_init_result = graphics_raytracing_test_init()))
	{
		console_write_line("Successfully initialised");
		if (BCS_SUCCEEDED(graphics_raytracing_test_execute_result = graphics_raytracing_test_execute()))
		{
			console_write_line("Successfully executed");
			if (BCS_SUCCEEDED(graphics_raytracing_test_validate_result = graphics_raytracing_test_validate()))
			{
				console_write_line("Successfully validated");
			}
		}
	}

	BCS_RESULT graphics_raytracing_test_deinit_result = BCS_E_NOT_RUN;
	if (BCS_SUCCEEDED(graphics_raytracing_test_deinit_result = graphics_raytracing_test_deinit()))
	{
		console_write_line("Successfully deinitialised");
	}

	BCS_TEST_VALIDATE(graphics_raytracing_test_init_result);
	BCS_TEST_VALIDATE(graphics_raytracing_test_execute_result);
	BCS_TEST_VALIDATE(graphics_raytracing_test_validate_result);
	BCS_TEST_VALIDATE(graphics_raytracing_test_deinit_result);

	return BCS_S_OK;
}

extern "C" int bcs_main()
{
	raytracing_test_result = graphics_raytracing_test();

	return raytracing_test_result;
}
