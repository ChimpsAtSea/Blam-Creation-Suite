#include "computetest-private-pch.h"

#define USE_PIX

#include <Windows.h>
#include <pix3.h>

BCS_RESULT graphics_compute_test()
{
	BCS_RESULT register_process_module_by_pointer_result = register_process_module_by_pointer(graphics_compute_test);
	BCS_FAIL_RETURN(register_process_module_by_pointer_result);
	BCS_RESULT init_command_line_result = init_command_line();
	BCS_FAIL_RETURN(init_command_line_result);
	BCS_RESULT init_console_result = init_console();
	BCS_FAIL_RETURN(init_console_result);

	s_graphics_register_layout_description compute_register_layouts[1];
	compute_register_layouts[0].semantic = _graphics_register_layout_unordered_access;
	compute_register_layouts[0].register_index = 0;
	compute_register_layouts[0].register_count = 1;
	compute_register_layouts[0].register_space = 0;
	compute_register_layouts[0].num_32_bit_values = 0;
	compute_register_layouts[0].use_table = true;
	compute_register_layouts[0].sampler_layout_description = 0;

	c_graphics* graphics;
	BCS_RESULT graphics_create_result = graphics_create(_graphics_architecture_d3d12_raytracing, true, graphics);
	BCS_FAIL_RETURN(graphics_create_result);

	void* compute_shader_binary_data;
	uint64_t compute_shader_binary_size;
	BCS_RESULT read_file_result = resources_read_local_resource_to_memory("computeshader.cso", compute_shader_binary_data, compute_shader_binary_size);
	BCS_FAIL_RETURN(read_file_result);

	c_graphics_shader_binary* compute_test_shader_binary;
	BCS_RESULT compute_test_shader_binary_result = graphics_shader_binary_create(
		graphics,
		compute_shader_binary_data,
		compute_shader_binary_size,
		compute_test_shader_binary);
	BCS_FAIL_RETURN(compute_test_shader_binary_result);

	c_graphics_register_layout* compute_register_layout;
	BCS_RESULT compute_register_layout_result = graphics_register_layout_create(
		graphics,
		_graphics_register_layout_type_compute,
		compute_register_layouts,
		_countof(compute_register_layouts),
		compute_register_layout,
		"compute_register_layout");
	BCS_FAIL_RETURN(compute_register_layout_result);

	c_graphics_shader_pipeline* compute_test_shader_pipeline;
	BCS_RESULT compute_test_shader_pipeline_result = graphics_shader_pipeline_compute_create(
		graphics,
		compute_register_layout,
		compute_test_shader_binary,
		compute_test_shader_pipeline);
	BCS_FAIL_RETURN(compute_test_shader_pipeline_result);

	unsigned int dispatch_size = 512;

	c_graphics_buffer* read_write_buffer;
	BCS_RESULT read_write_buffer_create_result = graphics_buffer_create(
		graphics, 
		_graphics_buffer_type_unordered_access_view, 
		512 * sizeof(float4), 
		read_write_buffer,
		"read_write_buffer");
	BCS_FAIL_RETURN(read_write_buffer_create_result);

	PIXBeginCapture(PIX_CAPTURE_GPU, 0);
	graphics->begin();

	unsigned int base_value = 0xDEADBEEF;
	unsigned int* initial_values = trivial_alloca(unsigned int, dispatch_size);
	for (unsigned int dispatch_index = 0; dispatch_index < dispatch_size; dispatch_index++)
	{
		initial_values[dispatch_index] = base_value;
	}

	BCS_RESULT write_data_result = read_write_buffer->write_data(initial_values, sizeof(*initial_values) * dispatch_size, 0);
	BCS_FAIL_RETURN(write_data_result);

	compute_register_layout->bind();
	compute_test_shader_pipeline->bind();
	compute_register_layout->bind_buffer(0, 0, *read_write_buffer);
	graphics->dispatch(dispatch_size);

	read_write_buffer->copy_readback();

	graphics->end();
	PIXEndCapture(false);

	unsigned int valid_data_points = 0;
	unsigned int* final_values = trivial_alloca(unsigned int, dispatch_size);
	BCS_RESULT read_data_result = read_write_buffer->read_data(final_values, sizeof(*final_values) * dispatch_size, 0);
	BCS_FAIL_RETURN(read_data_result);
	for (unsigned int dispatch_index = 0; dispatch_index < dispatch_size; dispatch_index++)
	{
		unsigned int final_value = final_values[dispatch_index];
		if (final_value == (base_value + dispatch_index))
		{
			valid_data_points++;
		}
	}
	
	BCS_RESULT test_result = valid_data_points == dispatch_size ? BCS_S_OK : BCS_E_FAIL;

	BCS_RESULT graphics_buffer_destroy_result = graphics_buffer_destroy(read_write_buffer);
	BCS_FAIL_RETURN(graphics_buffer_destroy_result);
	BCS_RESULT graphics_shader_pipeline_destroy_result = graphics_shader_pipeline_destroy(compute_test_shader_pipeline);
	BCS_FAIL_RETURN(graphics_shader_pipeline_destroy_result);
	BCS_RESULT graphics_register_layout_destroy_result = graphics_register_layout_destroy(compute_register_layout);
	BCS_FAIL_RETURN(graphics_register_layout_destroy_result);
	BCS_RESULT graphics_shader_binary_destroy_result = graphics_shader_binary_destroy(compute_test_shader_binary);
	BCS_FAIL_RETURN(graphics_shader_binary_destroy_result);
	tracked_free(compute_shader_binary_data);
	BCS_RESULT graphics_destroy_result = graphics_destroy(graphics);
	BCS_FAIL_RETURN(graphics_destroy_result);

	BCS_RESULT deinit_console_result = deinit_console();
	BCS_FAIL_RETURN(deinit_console_result);
	BCS_RESULT deinit_command_line_result = deinit_command_line();
	BCS_FAIL_RETURN(deinit_command_line_result);

	return test_result;
}

int main()
{
	BCS_RESULT result = graphics_compute_test();
	return result;
}
