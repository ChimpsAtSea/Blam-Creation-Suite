#include "graphicslib-private-pch.h"

c_graphics_render_pass_d3d12::c_graphics_render_pass_d3d12(
	c_graphics_d3d12& graphics,
	c_viewport& viewport,
	c_graphics_render_target_d3d12** _color_render_targets,
	c_graphics_render_target_d3d12** _depth_render_targets,
	uint32_t num_color_render_targets,
	uint32_t num_depth_render_targets,
	uint32_t num_render_target_per_frame,
	uint32_t num_render_target_frames,
	const wchar_t* debug_name) :
	graphics(graphics),
	color_render_targets(),
	depth_render_targets(),
	num_color_render_targets(num_color_render_targets),
	num_depth_render_targets(num_depth_render_targets),
	num_render_target_per_frame(num_render_target_per_frame),
	num_render_target_frames(num_render_target_frames),
	current_render_target_swap_index(0),
	current_render_target_start_index(0),
	current_depth_stencil_swap_index(0),
	viewport(viewport),
	d3d12_viewport(),
	scissor_rectangle()
{
	uint32_t expected_num_color_render_targets = num_render_target_per_frame * num_render_target_frames;

	BCS_VALIDATE_ARGUMENT_THROW(_color_render_targets);
	BCS_VALIDATE_ARGUMENT_THROW(num_render_target_frames > 0);
	BCS_VALIDATE_ARGUMENT_THROW(num_render_target_per_frame > 0);
	BCS_VALIDATE_ARGUMENT_THROW(num_render_target_frames > 0);
	BCS_VALIDATE_ARGUMENT_THROW(num_color_render_targets >= expected_num_color_render_targets);

	color_render_targets = new() c_graphics_render_target_d3d12 * [num_color_render_targets];
	for (uint32_t color_render_target_index = 0; color_render_target_index < num_color_render_targets; color_render_target_index++)
	{
		c_graphics_render_target_d3d12* color_render_target = _color_render_targets[color_render_target_index];

		if (color_render_target == nullptr)
		{
			throw BCS_E_INVALID_ARGUMENT;
		}

		color_render_targets[color_render_target_index] = color_render_target;
	}

	if (num_depth_render_targets > 0)
	{
		depth_render_targets = new() c_graphics_render_target_d3d12 * [num_depth_render_targets];
		for (uint32_t depth_render_target_index = 0; depth_render_target_index < num_depth_render_targets; depth_render_target_index++)
		{
			c_graphics_render_target_d3d12* depth_render_target = _depth_render_targets[depth_render_target_index];

			if (depth_render_target == nullptr)
			{
				throw BCS_E_INVALID_ARGUMENT;
			}

			depth_render_targets[depth_render_target_index] = depth_render_target;
		}
	}
	else
	{
		depth_render_targets = nullptr;
	}

	init_descriptor_handles();
	setup_viewport();
}

c_graphics_render_pass_d3d12::~c_graphics_render_pass_d3d12()
{
	deinit_descriptor_handles();
	delete color_render_targets;
	delete depth_render_targets;
}

void c_graphics_render_pass_d3d12::setup_viewport()
{
	d3d12_viewport = {};
	scissor_rectangle = {};

	d3d12_viewport.MaxDepth = 1.0f;
	d3d12_viewport.Width = viewport.width_float;
	d3d12_viewport.Height = viewport.height_float;
	scissor_rectangle.right = viewport.width;
	scissor_rectangle.bottom = viewport.height;
}

BCS_RESULT c_graphics_render_pass_d3d12::init_descriptor_handles()
{
	color_render_target_cpu_handles = new() D3D12_CPU_DESCRIPTOR_HANDLE[num_color_render_targets];
	for (uint32_t color_render_target_index = 0; color_render_target_index < num_color_render_targets; color_render_target_index++)
	{
		c_graphics_render_target_d3d12* color_render_target = color_render_targets[color_render_target_index];

		if (color_render_target == nullptr)
		{
			return BCS_E_INVALID_ARGUMENT;
		}

		color_render_target_cpu_handles[color_render_target_index] = color_render_target->descriptor_heap_cpu->cpu_descriptor_handle;
	}

	if (num_depth_render_targets > 0)
	{
		depth_render_target_cpu_handles = new() D3D12_CPU_DESCRIPTOR_HANDLE[num_depth_render_targets];
		for (uint32_t depth_render_target_index = 0; depth_render_target_index < num_depth_render_targets; depth_render_target_index++)
		{
			c_graphics_render_target_d3d12* depth_render_target = depth_render_targets[depth_render_target_index];

			if (depth_render_target == nullptr)
			{
				return BCS_E_INVALID_ARGUMENT;
			}

			depth_render_target_cpu_handles[depth_render_target_index] = depth_render_target->descriptor_heap_cpu->cpu_descriptor_handle;
		}
	}
	else
	{
		depth_render_target_cpu_handles = nullptr;
	}

	return BCS_S_OK;
}

BCS_RESULT c_graphics_render_pass_d3d12::deinit_descriptor_handles()
{
	delete color_render_target_cpu_handles;
	delete depth_render_target_cpu_handles;

	return BCS_S_OK;
}

BCS_RESULT c_graphics_render_pass_d3d12::resize(uint32_t width, unsigned height)
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = deinit_descriptor_handles()))
	{
		return rs;
	}
	if (BCS_FAILED(rs = init_descriptor_handles()))
	{
		return rs;
	}
	return rs;
}

void c_graphics_render_pass_d3d12::transition_color_render_targets(D3D12_RESOURCE_STATES before, D3D12_RESOURCE_STATES after)
{
	for (uint32_t render_target_offset = 0; render_target_offset < num_render_target_per_frame; render_target_offset++)
	{
		c_graphics_render_target_d3d12* color_render_target = color_render_targets[current_render_target_start_index + render_target_offset];

		graphics.transition_resource(color_render_target->resource, before, after);
	}
}

void c_graphics_render_pass_d3d12::bind_render_targets()
{
	D3D12_CPU_DESCRIPTOR_HANDLE* current_color_render_target_cpu_handles = color_render_target_cpu_handles + current_render_target_start_index;
	D3D12_CPU_DESCRIPTOR_HANDLE* current_depth_render_target_cpu_handles = nullptr;

	if (num_depth_render_targets > 0)
	{
		current_depth_render_target_cpu_handles = depth_render_target_cpu_handles + current_depth_stencil_swap_index;
	}

	ID3D12GraphicsCommandList1* command_list = graphics.command_list;
	command_list->OMSetRenderTargets(num_render_target_per_frame, current_color_render_target_cpu_handles, FALSE, current_depth_render_target_cpu_handles);
}

void c_graphics_render_pass_d3d12::render(c_graphics_swap_chain* swap_chain)
{
	c_graphics_swap_chain_d3d12* swap_chain_d3d12 = dynamic_cast<c_graphics_swap_chain_d3d12*>(swap_chain);

	ID3D12GraphicsCommandList1* command_list = graphics.command_list;

	setup_viewport();
	command_list->RSSetViewports(1, &d3d12_viewport);
	command_list->RSSetScissorRects(1, &scissor_rectangle);

	current_render_target_swap_index = (current_render_target_swap_index) % num_render_target_frames;
	if (swap_chain_d3d12 != nullptr)
	{
		current_render_target_swap_index = swap_chain_d3d12->get_current_back_buffer_index();
	}
	current_render_target_start_index = current_render_target_swap_index * num_render_target_per_frame;
	if (num_depth_render_targets > 0)
	{
		current_depth_stencil_swap_index = (current_depth_stencil_swap_index) % num_depth_render_targets;
	}
	else
	{
		current_depth_stencil_swap_index = 0;
	}

	if (swap_chain_d3d12 && swap_chain_d3d12->dxgi_swap_chain)
	{
		transition_color_render_targets(D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
	}

	bind_render_targets();

	for (uint32_t render_target_offset = 0; render_target_offset < num_render_target_per_frame; render_target_offset++)
	{
		c_graphics_render_target_d3d12* color_render_target = color_render_targets[current_render_target_start_index + render_target_offset];

		color_render_target->clear_render_target();
	}
	if (num_depth_render_targets > 0)
	{
		depth_render_targets[current_depth_stencil_swap_index]->clear_render_target();
	}

	render_callback();

	if (swap_chain_d3d12 && swap_chain_d3d12->dxgi_swap_chain)
	{
		transition_color_render_targets(D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
	}

	current_render_target_swap_index++;
	current_depth_stencil_swap_index++;
}

BCS_RESULT graphics_d3d12_render_pass_create(
	c_graphics_d3d12* graphics,
	c_viewport* viewport,
	c_graphics_render_target_d3d12** color_render_targets,
	c_graphics_render_target_d3d12** depth_render_targets,
	uint32_t num_color_render_targets,
	uint32_t num_depth_render_targets,
	uint32_t num_render_target_per_frame,
	uint32_t num_render_target_frames,
	c_graphics_render_pass_d3d12*& render_pass,
	const char* debug_name)
{
	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		render_pass = new() c_graphics_render_pass_d3d12(
			*graphics,
			*viewport,
			color_render_targets,
			depth_render_targets,
			num_color_render_targets,
			num_depth_render_targets,
			num_render_target_per_frame,
			num_render_target_frames,
			debug_name_wc
		);
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

BCS_RESULT graphics_d3d12_render_pass_destroy(c_graphics_render_pass_d3d12* render_pass)
{
	try
	{
		delete render_pass;
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}
