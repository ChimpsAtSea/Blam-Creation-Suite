#include "graphicslib-private-pch.h"

c_graphics_render_target_d3d12::c_graphics_render_target_d3d12(
	c_graphics_d3d12& graphics,
	c_graphics_swap_chain_d3d12& swap_chain,
	unsigned long swap_chain_buffer_index,
	float4 clear_color,
	const char* debug_name) :
	render_target_type(_graphics_render_target_type_d3d12_swapchain),
	graphics(graphics),
	resource(),
	swap_chain(&swap_chain),
	swap_chain_buffer_index(swap_chain_buffer_index),
	descriptor_heap_cpu(),
	clear_value(),
	depth_stencil_view_description(),
	dxgi_format(),
	heap_flags(),
	heap_properties(),
	resource_state(),
	resource_description()
{
	descriptor_heap_cpu = new c_descriptor_heap_d3d12(
		graphics,
		D3D12_DESCRIPTOR_HEAP_TYPE_RTV,
		D3D12_DESCRIPTOR_HEAP_FLAG_NONE,
		1,
		L"c_graphics_d3d12::rtv_descriptor_heap_allocator_cpu"
	);

	dxgi_format = swap_chain.swap_chain_description.BufferDesc.Format;
	clear_value.Format = dxgi_format;
	clear_value.Color[0] = clear_color.x;
	clear_value.Color[1] = clear_color.y;
	clear_value.Color[2] = clear_color.z;
	clear_value.Color[3] = clear_color.w;

	swap_chain.on_resize_start.add_callback(swap_chain_resize_start, this, swap_chain_resize_start_handle);
	swap_chain.on_resize_finish.add_callback(swap_chain_resize_finish, this, swap_chain_resize_finish_handle);
	init_resource();
}

c_graphics_render_target_d3d12::c_graphics_render_target_d3d12(
	c_graphics_d3d12& graphics,
	unsigned long width,
	unsigned long height,
	e_graphics_data_format format,
	float4 clear_color,
	const char* debug_name,
	bool shared) :
	render_target_type(_graphics_render_target_type_d3d12_color),
	graphics(graphics),
	resource(),
	swap_chain(),
	descriptor_heap_cpu(),
	clear_value(),
	depth_stencil_view_description(),
	dxgi_format(),
	heap_flags(),
	heap_properties(),
	resource_state(),
	resource_description()
{
	descriptor_heap_cpu = new c_descriptor_heap_d3d12(
		graphics,
		D3D12_DESCRIPTOR_HEAP_TYPE_RTV,
		D3D12_DESCRIPTOR_HEAP_FLAG_NONE,
		1,
		L"c_graphics_d3d12::rtv_descriptor_heap_allocator_cpu"
	);

	dxgi_format = DXGI_FORMAT_R8G8B8A8_UNORM;
	clear_value.Format = dxgi_format;
	clear_value.Color[0] = clear_color.x;
	clear_value.Color[1] = clear_color.y;
	clear_value.Color[2] = clear_color.z;
	clear_value.Color[3] = clear_color.w;

	resource_state = D3D12_RESOURCE_STATE_RENDER_TARGET;

	heap_properties.Type = D3D12_HEAP_TYPE_DEFAULT;
	heap_properties.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
	heap_properties.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
	heap_properties.CreationNodeMask = 1;
	heap_properties.VisibleNodeMask = 1;

	resource_description.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
	resource_description.Alignment = 0;
	resource_description.Width = width;
	resource_description.Height = height;
	resource_description.DepthOrArraySize = 1;
	resource_description.MipLevels = 0;
	resource_description.Format = dxgi_format;
	resource_description.SampleDesc.Count = 1;
	resource_description.SampleDesc.Quality = 0;
	resource_description.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;
	resource_description.Flags = D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET;

	init_resource();
}

c_graphics_render_target_d3d12::c_graphics_render_target_d3d12(
	c_graphics_d3d12& graphics,
	unsigned long width,
	unsigned long height,
	e_graphics_data_format format,
	float clear_depth,
	unsigned char stencil_value,
	const char* debug_name,
	bool shared) :
	render_target_type(_graphics_render_target_type_d3d12_depth_stencil),
	graphics(graphics),
	resource(),
	swap_chain(),
	descriptor_heap_cpu(),
	clear_value(),
	depth_stencil_view_description(),
	dxgi_format(),
	heap_flags(),
	heap_properties(),
	resource_state(),
	resource_description()
{
	descriptor_heap_cpu = new c_descriptor_heap_d3d12(
		graphics,
		D3D12_DESCRIPTOR_HEAP_TYPE_DSV,
		D3D12_DESCRIPTOR_HEAP_FLAG_NONE,
		1,
		L"c_graphics_d3d12::rtv_descriptor_heap_allocator_cpu"
	);

	dxgi_format = DXGI_FORMAT_D32_FLOAT;

	depth_stencil_view_description.Format = dxgi_format;
	depth_stencil_view_description.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D;
	depth_stencil_view_description.Flags = D3D12_DSV_FLAG_NONE;

	clear_value.Format = dxgi_format;
	clear_value.DepthStencil.Depth = clear_depth;
	clear_value.DepthStencil.Stencil = stencil_value;

	heap_flags = D3D12_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES;
	if (shared)
	{
		heap_flags |= D3D12_HEAP_FLAG_SHARED;
	}

	resource_state = D3D12_RESOURCE_STATE_DEPTH_WRITE;

	heap_properties.Type = D3D12_HEAP_TYPE_DEFAULT;
	heap_properties.CPUPageProperty = D3D12_CPU_PAGE_PROPERTY_UNKNOWN;
	heap_properties.MemoryPoolPreference = D3D12_MEMORY_POOL_UNKNOWN;
	heap_properties.CreationNodeMask = 1;
	heap_properties.VisibleNodeMask = 1;

	resource_description.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;
	resource_description.Alignment = 0;
	resource_description.Width = width;
	resource_description.Height = height;
	resource_description.DepthOrArraySize = 1;
	resource_description.MipLevels = 0;
	resource_description.Format = dxgi_format;
	resource_description.SampleDesc.Count = 1;
	resource_description.SampleDesc.Quality = 0;
	resource_description.Layout = D3D12_TEXTURE_LAYOUT_UNKNOWN;
	resource_description.Flags = D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL;

	init_resource();
}

c_graphics_render_target_d3d12::~c_graphics_render_target_d3d12()
{
	deinit_resource();
	delete descriptor_heap_cpu;

	if (swap_chain)
	{
		swap_chain->on_resize_start.remove_callback(swap_chain_resize_start_handle);
		swap_chain->on_resize_finish.remove_callback(swap_chain_resize_finish_handle);
	}
}

void c_graphics_render_target_d3d12::init_resource()
{
	if (render_target_type == _graphics_render_target_type_d3d12_swapchain)
	{
		console_write_line("swap_chain_buffer_index %u ", swap_chain_buffer_index);
		HRESULT get_buffer_result = swap_chain->dxgi_swap_chain->GetBuffer(swap_chain_buffer_index, IID_PPV_ARGS(&resource));
		ASSERT(SUCCEEDED(get_buffer_result));

		wchar_t name_buffer[512];
		_snwprintf(name_buffer, 512, L"swap chain buffer %u", swap_chain_buffer_index);
		resource->SetName(name_buffer);

	}
	else
	{
		HRESULT create_committed_resource_result = graphics.device->CreateCommittedResource(
			&heap_properties,
			D3D12_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES,
			&resource_description,
			D3D12_RESOURCE_STATE_DEPTH_WRITE,
			&clear_value,
			IID_PPV_ARGS(&resource)
		);
		ASSERT(SUCCEEDED(create_committed_resource_result));
		resource->SetName(L"c_graphics_render_target_d3d12::resource");
	}

	switch (render_target_type)
	{
	case _graphics_render_target_type_d3d12_swapchain:
	case _graphics_render_target_type_d3d12_color:
	{
		D3D12_CPU_DESCRIPTOR_HANDLE rtv_cpu_descriptor_handle = descriptor_heap_cpu->get_cpu_descriptor_handle(0);
		graphics.device->CreateRenderTargetView(resource, nullptr, rtv_cpu_descriptor_handle);
		break;
	}
	case _graphics_render_target_type_d3d12_depth_stencil:
	{
		D3D12_CPU_DESCRIPTOR_HANDLE dsv_cpu_descriptor_handle = descriptor_heap_cpu->get_cpu_descriptor_handle(0);
		graphics.device->CreateDepthStencilView(resource, &depth_stencil_view_description, dsv_cpu_descriptor_handle);
		break;
	}
	}
}

void c_graphics_render_target_d3d12::deinit_resource()
{
	ULONG resource_reference_count = resource->Release();
	if (render_target_type == _graphics_render_target_type_d3d12_swapchain)
	{
		ASSERT(resource_reference_count <= swap_chain->num_back_buffers);
	}
	else
	{
		ASSERT(resource_reference_count == 0);
	}
}

BCS_RESULT c_graphics_render_target_d3d12::resize(unsigned long width, unsigned long height)
{
	deinit_resource();
	resource_description.Width = width;
	resource_description.Height = height;
	init_resource();

	return BCS_S_OK;
}

void c_graphics_render_target_d3d12::swap_chain_resize_start(c_graphics_render_target_d3d12& _this, unsigned long width, unsigned long height)
{
	console_write_line(__FUNCTION__);
	_this.deinit_resource();
}

void c_graphics_render_target_d3d12::swap_chain_resize_finish(c_graphics_render_target_d3d12& _this, unsigned long width, unsigned long height)
{
	console_write_line(__FUNCTION__);
	_this.resource_description.Width = width;
	_this.resource_description.Height = height;
	_this.init_resource();
}

void c_graphics_render_target_d3d12::clear_render_target()
{
	switch (render_target_type)
	{
	case _graphics_render_target_type_d3d12_color:
	case _graphics_render_target_type_d3d12_swapchain:
		graphics.command_list->ClearRenderTargetView(
			descriptor_heap_cpu->cpu_descriptor_handle, 
			clear_value.Color, 
			0, 
			nullptr);
		break;
	case _graphics_render_target_type_d3d12_depth_stencil:
		graphics.command_list->ClearDepthStencilView(
			descriptor_heap_cpu->cpu_descriptor_handle, 
			D3D12_CLEAR_FLAG_DEPTH, 
			clear_value.DepthStencil.Depth, 
			clear_value.DepthStencil.Stencil,
			0, 
			nullptr); // #NOTE: Clear to zero because depth is inverted
		break;
	}
}
BCS_RESULT graphics_d3d12_swapchain_color_render_target_create(
	c_graphics_d3d12* graphics,
	c_graphics_swap_chain_d3d12* swap_chain,
	unsigned long swap_chain_buffer_index,
	float4 clear_color,
	c_graphics_render_target_d3d12*& render_target,
	const char* debug_name)
{
	try
	{
		render_target = new c_graphics_render_target_d3d12(
			*graphics,
			*swap_chain,
			swap_chain_buffer_index,
			clear_color,
			debug_name);
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
BCS_RESULT graphics_d3d12_color_render_target_create(
	c_graphics_d3d12* graphics,
	unsigned long width,
	unsigned long height,
	e_graphics_data_format format,
	float4 clear_color,
	c_graphics_render_target_d3d12*& render_target,
	const char* debug_name,
	bool shared)
{
	try
	{
		render_target = new c_graphics_render_target_d3d12(
			*graphics,
			width,
			height,
			format,
			clear_color,
			debug_name,
			shared);
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

BCS_RESULT graphics_d3d12_depth_stencil_render_target_create(
	c_graphics_d3d12* graphics,
	unsigned long width,
	unsigned long height,
	e_graphics_data_format format,
	float clear_depth,
	unsigned char stencil_value,
	c_graphics_render_target_d3d12*& render_target,
	const char* debug_name,
	bool shared)
{
	try
	{
		render_target = new c_graphics_render_target_d3d12(
			*graphics,
			width,
			height,
			format,
			clear_depth,
			stencil_value,
			debug_name,
			shared);
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

BCS_RESULT graphics_d3d12_render_target_destroy(c_graphics_render_target_d3d12* render_target)
{
	try
	{
		delete render_target;
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

