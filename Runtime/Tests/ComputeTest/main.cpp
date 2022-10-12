#include "computetest-private-pch.h"

constexpr unsigned int k_dispatch_size = 512;
unsigned int k_default_value = 0xDEADBEEF;

c_graphics* graphics;
void* compute_shader_binary_data;
uint64_t compute_shader_binary_size;
c_graphics_shader_binary* compute_test_shader_binary;
c_graphics_register_layout* compute_register_layout;
c_graphics_shader_pipeline* compute_test_shader_pipeline;
c_graphics_buffer* read_write_buffer;

BCS_RESULT graphics_create_result = BCS_E_NOT_RUN;
BCS_RESULT graphics_start_debug_capture_result = BCS_E_NOT_RUN;
BCS_RESULT read_compute_shader_binary_result = BCS_E_NOT_RUN;
BCS_RESULT compute_test_shader_binary_result = BCS_E_NOT_RUN;
BCS_RESULT compute_register_layout_result = BCS_E_NOT_RUN;
BCS_RESULT compute_test_shader_pipeline_result = BCS_E_NOT_RUN;
BCS_RESULT read_write_buffer_create_result = BCS_E_NOT_RUN;
BCS_RESULT graphics_begin_result = BCS_E_NOT_RUN;
BCS_RESULT write_data_result = BCS_E_NOT_RUN;
BCS_RESULT compute_register_layout_bind_result = BCS_E_NOT_RUN;
BCS_RESULT compute_register_layout_bind_buffers_result = BCS_E_NOT_RUN;
BCS_RESULT graphics_end_result = BCS_E_NOT_RUN;
BCS_RESULT read_write_buffer_read_data_result = BCS_E_NOT_RUN;
BCS_RESULT graphics_buffer_destroy_result = BCS_E_NOT_RUN;
BCS_RESULT graphics_shader_pipeline_destroy_result = BCS_E_NOT_RUN;
BCS_RESULT graphics_register_layout_destroy_result = BCS_E_NOT_RUN;
BCS_RESULT graphics_shader_binary_destroy_result = BCS_E_NOT_RUN;
BCS_RESULT graphics_destroy_result = BCS_E_NOT_RUN;
BCS_RESULT graphics_compute_test_result = BCS_E_NOT_RUN;

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


BCS_RESULT graphics_compute_test_init()
{
	if (BCS_SUCCEEDED(graphics_create_result = graphics_create(_graphics_architecture_d3d12, true, graphics)))
	{
		if (BCS_SUCCEEDED(graphics_start_debug_capture_result = graphics->start_debug_capture()))
		{
			console_write_line("Signaling debug frame");
		}

		if (BCS_SUCCEEDED(read_compute_shader_binary_result = resources_read_local_resource_to_memory(
			"computeshader.cso",
			compute_shader_binary_data,
			compute_shader_binary_size)))
		{
			if (BCS_SUCCEEDED(compute_test_shader_binary_result = graphics_shader_binary_create(
				graphics,
				compute_shader_binary_data,
				compute_shader_binary_size,
				compute_test_shader_binary)))
			{
				s_graphics_register_layout_description compute_register_layouts[1];
				compute_register_layouts[0].semantic = _graphics_register_layout_unordered_access;
				compute_register_layouts[0].register_index = 0;
				compute_register_layouts[0].register_count = 1;
				compute_register_layouts[0].register_space = 0;
				compute_register_layouts[0].num_32_bit_values = 0;
				compute_register_layouts[0].use_table = true;
				compute_register_layouts[0].sampler_layout_description = nullptr;

				if (BCS_SUCCEEDED(compute_register_layout_result = graphics_register_layout_create(
					graphics,
					_graphics_register_layout_type_compute,
					compute_register_layouts,
					_countof(compute_register_layouts),
					compute_register_layout,
					"compute_register_layout")))
				{
					if (BCS_SUCCEEDED(compute_test_shader_pipeline_result = graphics_shader_pipeline_compute_create(
						graphics,
						compute_register_layout,
						compute_test_shader_binary,
						compute_test_shader_pipeline)))
					{
						if (BCS_SUCCEEDED(read_write_buffer_create_result = graphics_buffer_create(
							graphics,
							_graphics_buffer_type_unordered_access_view,
							k_dispatch_size * sizeof(unsigned int),
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

	BCS_TEST_VALIDATE(graphics_create_result);
	BCS_TEST_VALIDATE(read_compute_shader_binary_result);
	BCS_TEST_VALIDATE(compute_test_shader_binary_result);
	BCS_TEST_VALIDATE(compute_register_layout_result);
	BCS_TEST_VALIDATE(compute_test_shader_pipeline_result);
	BCS_TEST_VALIDATE(read_write_buffer_create_result);

	return BCS_S_OK;
}

BCS_RESULT graphics_compute_test_execute()
{
	if (BCS_SUCCEEDED(graphics_begin_result = graphics->begin()))
	{
		unsigned int* initial_values = trivial_alloca(unsigned int, k_dispatch_size);
		for (unsigned int dispatch_index = 0; dispatch_index < k_dispatch_size; dispatch_index++)
		{
			initial_values[dispatch_index] = k_default_value;
		}

		if (BCS_SUCCEEDED(write_data_result = read_write_buffer->write_data(initial_values, sizeof(*initial_values) * k_dispatch_size, 0)))
		{
			if (BCS_SUCCEEDED(compute_register_layout_bind_result = compute_register_layout->bind()))
			{
				compute_test_shader_pipeline->bind();

				if (BCS_SUCCEEDED(compute_register_layout_bind_buffers_result = compute_register_layout->bind_buffer(0, 0, *read_write_buffer)))
				{
					compute_test_shader_pipeline->dispatch(k_dispatch_size);

					read_write_buffer->copy_readback();

					if (BCS_SUCCEEDED(graphics_end_result = graphics->end()))
					{
						// finished
					}
				}

				compute_test_shader_pipeline->unbind();
			}
		}
	}

	BCS_TEST_VALIDATE(graphics_begin_result);
	BCS_TEST_VALIDATE(write_data_result);
	BCS_TEST_VALIDATE(compute_register_layout_bind_result);
	BCS_TEST_VALIDATE(compute_register_layout_bind_buffers_result);
	BCS_TEST_VALIDATE(graphics_end_result);

	return BCS_S_OK;
}

BCS_RESULT graphics_compute_test_validate()
{
	unsigned int valid_data_points = 0;
	unsigned int* final_values = trivial_alloca(unsigned int, k_dispatch_size);
	if (BCS_SUCCEEDED(read_write_buffer_read_data_result = read_write_buffer->read_data(final_values, sizeof(*final_values) * k_dispatch_size, 0)))
	{
		for (unsigned int dispatch_index = 0; dispatch_index < k_dispatch_size; dispatch_index++)
		{
			unsigned int final_value = final_values[dispatch_index];
			if (final_value == (k_default_value + dispatch_index))
			{
				valid_data_points++;
			}
		}
	}

	BCS_TEST_VALIDATE(read_write_buffer_read_data_result);

	if (valid_data_points != k_dispatch_size)
	{
		return BCS_E_FAIL;
	}

	return BCS_S_OK;
}

BCS_RESULT graphics_compute_test_deinit()
{
	graphics_buffer_destroy_result = graphics_buffer_destroy(read_write_buffer);
	graphics_shader_pipeline_destroy_result = graphics_shader_pipeline_destroy(compute_test_shader_pipeline);
	graphics_register_layout_destroy_result = graphics_register_layout_destroy(compute_register_layout);
	graphics_shader_binary_destroy_result = graphics_shader_binary_destroy(compute_test_shader_binary);
	tracked_free(compute_shader_binary_data);
	graphics_destroy_result = graphics_destroy(graphics);


	BCS_TEST_VALIDATE(graphics_buffer_destroy_result);
	BCS_TEST_VALIDATE(graphics_shader_pipeline_destroy_result);
	BCS_TEST_VALIDATE(graphics_register_layout_destroy_result);
	BCS_TEST_VALIDATE(graphics_shader_binary_destroy_result);
	BCS_TEST_VALIDATE(graphics_destroy_result);

	return BCS_S_OK;
}

BCS_RESULT graphics_compute_test()
{
	BCS_RESULT graphics_compute_test_init_result = BCS_E_NOT_RUN;
	BCS_RESULT graphics_compute_test_execute_result = BCS_E_NOT_RUN;
	BCS_RESULT graphics_compute_test_validate_result = BCS_E_NOT_RUN;

	if (BCS_SUCCEEDED(graphics_compute_test_init_result = graphics_compute_test_init()))
	{
		console_write_line("Successfully initialised");
		if (BCS_SUCCEEDED(graphics_compute_test_execute_result = graphics_compute_test_execute()))
		{
			console_write_line("Successfully executed");
			if (BCS_SUCCEEDED(graphics_compute_test_validate_result = graphics_compute_test_validate()))
			{
				console_write_line("Successfully validated");
			}
		}
	}

	BCS_RESULT graphics_compute_test_deinit_result = BCS_E_NOT_RUN;
	if (BCS_SUCCEEDED(graphics_compute_test_deinit_result = graphics_compute_test_deinit()))
	{
		console_write_line("Successfully deinitialised");
	}

	BCS_TEST_VALIDATE(graphics_compute_test_init_result);
	BCS_TEST_VALIDATE(graphics_compute_test_execute_result);
	BCS_TEST_VALIDATE(graphics_compute_test_validate_result);
	BCS_TEST_VALIDATE(graphics_compute_test_deinit_result);

	return BCS_S_OK;
}

int main()
{
	BCS_RESULT register_process_module_by_pointer_result = BCS_E_NOT_RUN;
	BCS_RESULT init_command_line_result = BCS_E_NOT_RUN;
	BCS_RESULT init_console_result = BCS_E_NOT_RUN;

	if (BCS_SUCCEEDED(register_process_module_by_pointer_result = register_process_module_by_pointer(graphics_compute_test)))
	{
		if (BCS_SUCCEEDED(init_command_line_result = init_command_line()))
		{
			if (BCS_SUCCEEDED(init_console_result = init_console()))
			{
				graphics_compute_test_result = graphics_compute_test();
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

	return graphics_compute_test_result;
}
