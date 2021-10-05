#include "graphicslib-private-pch.h"

using namespace DirectX;

c_graphics_d3d12::c_graphics_d3d12(c_viewport* viewport) :
	device(),
	descriptor_sizes(),
	on_render_scene(nullptr),
	d3d12_viewport(),
	scissor_rectangle(),
#if 0
	dxgi_swap_chain(),
#endif
	depth_stencil_buffer(nullptr),
	render_targets(),
	command_allocator(nullptr),
	command_queue(nullptr),
	root_signature(nullptr),
	command_list(nullptr),
#if 0
	swap_chain_description(),
#endif
	depth_stencil_view_description(),
	current_frame_index(0),
	fence_event(NULL),
	fence(nullptr),
	fence_value(0),
	viewport(viewport),
	debug_interface(nullptr),
	dxgi_debug_interface(nullptr),
	dxgi_factory(nullptr),
	dxgi_adapter(nullptr),
	cbv_srv_uav_descriptor_heap_allocator_gpu(nullptr),
	cbv_srv_uav_descriptor_heap_allocator_cpu(nullptr),
	sampler_descriptor_heap_allocator_gpu(nullptr),
	rtv_descriptor_heap_cpu(nullptr),
	dsv_descriptor_heap_cpu(nullptr),
	tiled_texture_manager(nullptr),
	imgui_srv_descriptor_index(-1),
	imgui_srv_cpu_descriptor_handle(),
	imgui_srv_gpu_descriptor_handle(),
	options(),
	options1(),
	options2(),
	options3(),
	options4(),
	options5(),
	options6(),
	options7(),
	//options8(),
	vertex_shaders(),
	default_pipeline_signature(nullptr),
	debug_geometry_pipeline_signature(nullptr),
	wireframe_box_geometry(nullptr),
	solid_box_geometry(nullptr),
	sphere_geometry(nullptr),
	debug_pixel_shader(nullptr),
	debug_geometry_pipeline(nullptr),
	debug_boxes_temp(),
	debug_spheres_temp(),
	debug_meshes_temp(),
	debug_box_buffer(),
	debug_sphere_buffer(nullptr),
	debug_mesh_buffer(nullptr)
{
#if defined(_DEBUG)
	init_debug_layer();
#endif
	init_hardware();
	init_hardware_capabilities();
	init_descriptor_heap_allocator();
	init_vertex_shaders();
	init_command_queue();
	init_swapchain();
	init_render_target_views();
	init_command_allocator();
	init_root_signature();
	init_command_list();
	init_synchronization_objects();
	init_depth_buffer();
	init_tiled_texture_manager();
	init_default_pipeline();
	init_debug_geometry();
	setup_viewport();
	init_imgui();
}

c_graphics_d3d12::~c_graphics_d3d12()
{
	deinit_imgui();
	deinit_debug_geometry();
	deinit_default_pipeline();
	deinit_tiled_texture_manager();
	deinit_depth_buffer();
	deinit_synchronization_objects();
	deinit_command_list();
	deinit_root_signature();
	deinit_command_allocator();
	deinit_render_target_views();
	deinit_swapchain();
	deinit_command_queue();
	deinit_vertex_shaders();
	deinit_descriptor_heap_allocator();
	deinit_hardware_capabilities();
	deinit_hardware();
	deinit_debug_layer();
}

void c_graphics_d3d12::init_debug_layer()
{
	// Enable the D3D12 debug layer.
	if (SUCCEEDED(D3D12GetDebugInterface(IID_PPV_ARGS(&debug_interface))))
	{
		debug_interface->EnableDebugLayer();
	}

	if (SUCCEEDED(DXGIGetDebugInterface1(0, IID_PPV_ARGS(&dxgi_debug_interface))))
	{
		dxgi_debug_interface->EnableLeakTrackingForThread();
	}
}

void c_graphics_d3d12::deinit_debug_layer()
{
	if (debug_interface)
	{
		ULONG debug_interface_reference_count = debug_interface->Release();
		ASSERT(debug_interface_reference_count == 0);
	}
	if (dxgi_debug_interface)
	{
		dxgi_debug_interface->ReportLiveObjects(DXGI_DEBUG_ALL, DXGI_DEBUG_RLO_ALL);
		if (dxgi_debug_interface->IsLeakTrackingEnabledForThread())
		{
			dxgi_debug_interface->DisableLeakTrackingForThread();
		}

		ULONG dxgi_debug_interface_reference_count = dxgi_debug_interface->Release();
		//ASSERT(dxgi_debug_interface_reference_count == 0);
	}
}

void c_graphics_d3d12::init_hardware_capabilities()
{
	//cbv_srv_uav_descriptor_size = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV);
	//sampler_descriptor_size = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER);
	//rtv_descriptor_size = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);
	//dsv_descriptor_size = device->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_DSV);

	for (unsigned long descriptor_heap_type = 0; descriptor_heap_type < D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES; descriptor_heap_type++)
	{
		descriptor_sizes[descriptor_heap_type] = device->GetDescriptorHandleIncrementSize(static_cast<D3D12_DESCRIPTOR_HEAP_TYPE>(descriptor_heap_type));
	}
}

void c_graphics_d3d12::deinit_hardware_capabilities()
{

}

void c_graphics_d3d12::init_hardware()
{
	HRESULT create_dxgi_factory_result = CreateDXGIFactory1(IID_PPV_ARGS(&dxgi_factory));
	ASSERT(SUCCEEDED(create_dxgi_factory_result));

	get_hardware_adapter(dxgi_factory, D3D_FEATURE_LEVEL_12_1, &dxgi_adapter, &device);
	ASSERT(dxgi_adapter != nullptr);
	ASSERT(device != nullptr);
}

void c_graphics_d3d12::deinit_hardware()
{
	ULONG dxgi_adapter_reference_count = dxgi_adapter->Release();
	ASSERT(dxgi_adapter_reference_count == 0);

	ULONG device_reference_count = device->Release();
	if (device_reference_count > 0)
	{
		dxgi_debug_interface->ReportLiveObjects(DXGI_DEBUG_ALL, DXGI_DEBUG_RLO_ALL);
	}
	ASSERT(device_reference_count == 0);

	ULONG dxgi_factory_reference_count = dxgi_factory->Release();
	ASSERT(dxgi_factory_reference_count == 0);
}

void c_graphics_d3d12::init_descriptor_heap_allocator()
{
	cbv_srv_uav_descriptor_heap_allocator_gpu = new c_descriptor_heap_allocator_d3d12(
		*this,
		D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV,
		D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE,
		1024,
		L"c_graphics_d3d12::cbv_srv_uav_descriptor_heap_allocator_gpu"
	);
	cbv_srv_uav_descriptor_heap_allocator_cpu = new c_descriptor_heap_allocator_d3d12(
		*this,
		D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV,
		D3D12_DESCRIPTOR_HEAP_FLAG_NONE,
		512,
		L"c_graphics_d3d12::cbv_srv_uav_descriptor_heap_allocator_cpu"
	);
	sampler_descriptor_heap_allocator_gpu = new c_descriptor_heap_allocator_d3d12(
		*this,
		D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER,
		D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE,
		128,
		L"c_graphics_d3d12::cbv_srv_uav_descriptor_heap_allocator_gpu"
	);
	rtv_descriptor_heap_cpu = new c_descriptor_heap_d3d12(
		*this,
		D3D12_DESCRIPTOR_HEAP_TYPE_RTV,
		D3D12_DESCRIPTOR_HEAP_FLAG_NONE,
		k_frame_count,
		L"c_graphics_d3d12::rtv_descriptor_heap_allocator_cpu"
	);
	dsv_descriptor_heap_cpu = new c_descriptor_heap_d3d12(
		*this,
		D3D12_DESCRIPTOR_HEAP_TYPE_DSV,
		D3D12_DESCRIPTOR_HEAP_FLAG_NONE,
		k_frame_count,
		L"c_graphics_d3d12::dsv_descriptor_heap_allocator_cpu"
	);
}

void c_graphics_d3d12::deinit_descriptor_heap_allocator()
{
	delete cbv_srv_uav_descriptor_heap_allocator_gpu;
	delete cbv_srv_uav_descriptor_heap_allocator_cpu;
	delete sampler_descriptor_heap_allocator_gpu;
	delete rtv_descriptor_heap_cpu;
	delete dsv_descriptor_heap_cpu;
}

void c_graphics_d3d12::init_command_queue()
{
	// Describe and create the command queue.
	D3D12_COMMAND_QUEUE_DESC command_queue_description = {};
	command_queue_description.Flags = D3D12_COMMAND_QUEUE_FLAG_DISABLE_GPU_TIMEOUT;
	command_queue_description.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;

	HRESULT create_command_queue_result = device->CreateCommandQueue(&command_queue_description, IID_PPV_ARGS(&command_queue));
	ASSERT(SUCCEEDED(create_command_queue_result));
}

void c_graphics_d3d12::deinit_command_queue()
{
	ULONG command_queue_reference_count = command_queue->Release();
	ASSERT(command_queue_reference_count == 0);
}

void c_graphics_d3d12::init_depth_buffer()
{
	depth_stencil_view_description.Format = DXGI_FORMAT_D32_FLOAT;
	depth_stencil_view_description.ViewDimension = D3D12_DSV_DIMENSION_TEXTURE2D;
	depth_stencil_view_description.Flags = D3D12_DSV_FLAG_NONE;

	D3D12_CLEAR_VALUE depth_clear_value = {};
	depth_clear_value.Format = DXGI_FORMAT_D32_FLOAT;
	depth_clear_value.DepthStencil.Depth = 0.0f;
	depth_clear_value.DepthStencil.Stencil = 0;

	CD3DX12_HEAP_PROPERTIES const default_heap_properties(D3D12_HEAP_TYPE_DEFAULT);
	CD3DX12_RESOURCE_DESC const resource_description = CD3DX12_RESOURCE_DESC::Tex2D(DXGI_FORMAT_D32_FLOAT, viewport->get_width(), viewport->get_height(), 1, 0, 1, 0, D3D12_RESOURCE_FLAG_ALLOW_DEPTH_STENCIL);
	HRESULT create_committed_resource_result = device->CreateCommittedResource(
		&default_heap_properties,
		D3D12_HEAP_FLAG_NONE,
		&resource_description,
		D3D12_RESOURCE_STATE_DEPTH_WRITE,
		&depth_clear_value,
		IID_PPV_ARGS(&depth_stencil_buffer)
	);
	ASSERT(SUCCEEDED(create_committed_resource_result));
	depth_stencil_buffer->SetName(L"c_graphics_d3d12::depth_stencil_buffer");

	D3D12_CPU_DESCRIPTOR_HANDLE dsv_cpu_descriptor_handle = dsv_descriptor_heap_cpu->get_cpu_descriptor_handle(0);
	device->CreateDepthStencilView(depth_stencil_buffer, &depth_stencil_view_description, dsv_cpu_descriptor_handle);
}

void c_graphics_d3d12::deinit_depth_buffer()
{
	ULONG depth_stencil_buffer_reference_count = depth_stencil_buffer->Release();
	ASSERT(depth_stencil_buffer_reference_count == 0);
}

void c_graphics_d3d12::init_swapchain()
{
#if 0
	// Describe and create the swap chain.
	swap_chain_description.BufferCount = k_frame_count;
	swap_chain_description.BufferDesc.Width = __max(1u, viewport->get_width());
	swap_chain_description.BufferDesc.Height = __max(1u, viewport->get_height());
	swap_chain_description.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	swap_chain_description.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
	swap_chain_description.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
	swap_chain_description.OutputWindow = viewport->get_handle();
	swap_chain_description.SampleDesc.Count = 1;
	swap_chain_description.Windowed = TRUE;

	IDXGISwapChain* dxgi_swap_chain_base = nullptr;
	dxgi_factory->CreateSwapChain(
		command_queue,        // Swap chain needs the queue so that it can force a flush on it.
		&swap_chain_description,
		&dxgi_swap_chain_base
	);
	dxgi_swap_chain = interface_cast<IDXGISwapChain3*>(dxgi_swap_chain_base);
	ASSERT(dxgi_swap_chain != nullptr);
	ULONG dxgi_swap_chain_base_reference_count = dxgi_swap_chain_base->Release();
	ASSERT(dxgi_swap_chain_base_reference_count == 1); // the reference to the swapchain should now be held in dxgi_swap_chain

	// #TODO: Support fullscreen transitions
	// disable fullscreen transitions
	HRESULT make_window_association_result = dxgi_factory->MakeWindowAssociation(viewport->get_handle(), DXGI_MWA_NO_ALT_ENTER);
	ASSERT(SUCCEEDED(make_window_association_result));

	current_frame_index = dxgi_swap_chain->GetCurrentBackBufferIndex();
#endif
	current_frame_index = (current_frame_index + 1) % k_frame_count;
}

void c_graphics_d3d12::deinit_swapchain()
{
#if 0
	ULONG dxgi_swap_chain_reference_count = dxgi_swap_chain->Release();
	ASSERT(dxgi_swap_chain_reference_count == 0);
#endif
}

void c_graphics_d3d12::init_render_target_views()
{
#if 0
	// Create a RTV for each frame.
	for (unsigned long buffer_index = 0; buffer_index < k_frame_count; buffer_index++)
	{
		D3D12_CPU_DESCRIPTOR_HANDLE rtv_cpu_descriptor_handle = rtv_descriptor_heap_cpu->get_cpu_descriptor_handle(buffer_index);

		HRESULT get_buffer_result = dxgi_swap_chain->GetBuffer(buffer_index, IID_PPV_ARGS(&render_targets[buffer_index]));
		ASSERT(SUCCEEDED(get_buffer_result));
		device->CreateRenderTargetView(render_targets[buffer_index], nullptr, rtv_cpu_descriptor_handle);
	}
#endif

	D3D12_CLEAR_VALUE color_clear_value = {};
	color_clear_value.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	color_clear_value.Color[0] = 0.16f;
	color_clear_value.Color[1] = 0.10f;
	color_clear_value.Color[2] = 0.16f;
	color_clear_value.Color[3] = 1.0f;

	CD3DX12_HEAP_PROPERTIES const default_heap_properties(D3D12_HEAP_TYPE_DEFAULT);
	D3D12_RESOURCE_DESC render_target_resource_description = CD3DX12_RESOURCE_DESC::Tex2D(
		DXGI_FORMAT_R8G8B8A8_UNORM,
		static_cast<UINT64>(viewport->get_width()),
		static_cast<UINT>(viewport->get_height()),
		1,
		1,
		1,
		0,
		D3D12_RESOURCE_FLAG_ALLOW_RENDER_TARGET);

	// Create RT for each frame.
	for (unsigned long buffer_index = 0; buffer_index < k_frame_count; buffer_index++)
	{
		HRESULT create_committed_resource_result = device->CreateCommittedResource(
			&default_heap_properties,
			D3D12_HEAP_FLAG_ALLOW_ALL_BUFFERS_AND_TEXTURES | D3D12_HEAP_FLAG_SHARED,
			&render_target_resource_description,
			D3D12_RESOURCE_STATE_RENDER_TARGET,
			&color_clear_value,
			IID_PPV_ARGS(&render_targets[buffer_index])
		);
		ASSERT(SUCCEEDED(create_committed_resource_result));
		render_targets[buffer_index]->SetName(L"c_graphics_d3d12::render_targets");
	}

	// Create a RTV for each frame.
	for (unsigned long buffer_index = 0; buffer_index < k_frame_count; buffer_index++)
	{
		D3D12_CPU_DESCRIPTOR_HANDLE rtv_cpu_descriptor_handle = rtv_descriptor_heap_cpu->get_cpu_descriptor_handle(buffer_index);
		device->CreateRenderTargetView(render_targets[buffer_index], nullptr, rtv_cpu_descriptor_handle);
	}

	// Create D3D11 Interop Handles
	D3D11_RENDER_TARGET_VIEW_DESC render_target_view_description;
	render_target_view_description.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	render_target_view_description.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
	render_target_view_description.Texture2D.MipSlice = 0;
	for (unsigned long buffer_index = 0; buffer_index < k_frame_count; buffer_index++)
	{
		HRESULT create_shared_handle_result = device->CreateSharedHandle(render_targets[0], NULL, GENERIC_ALL, NULL, &render_targets_share_handles[buffer_index]);
		ASSERT(SUCCEEDED(create_shared_handle_result));

		//HRESULT open_shared_handle_result = c_render::s_device1->OpenSharedResource1(render_targets_share_handles[buffer_index], IID_PPV_ARGS(&d3d11_render_targets[buffer_index]));
		//ASSERT(SUCCEEDED(open_shared_handle_result));
		//debug_point;

		//HRESULT create_render_target_view_result = c_render::s_device->CreateRenderTargetView(d3d11_render_targets[buffer_index], &render_target_view_description, &d3d11_render_target_views[buffer_index]);
		//ASSERT(SUCCEEDED(create_render_target_view_result));
		//ASSERT(d3d11_render_target_views[buffer_index] != nullptr);

		//HRESULT render_target_shader_resource_view_result = c_render::s_device->CreateShaderResourceView(d3d11_render_targets[buffer_index], NULL, &d3d11_render_target_shader_resource_views[buffer_index]);
		//ASSERT(SUCCEEDED(render_target_shader_resource_view_result));
		//ASSERT(d3d11_render_target_shader_resource_views[buffer_index] != nullptr);
	}
}

void c_graphics_d3d12::deinit_render_target_views()
{
	// Destroy D3D11 Interop Handles
	for (unsigned long buffer_index = 0; buffer_index < k_frame_count; buffer_index++)
	{
		ULONG render_target_shader_resource_view_reference_count = d3d11_render_target_shader_resource_views[buffer_index]->Release();
		ASSERT(render_target_shader_resource_view_reference_count == 0);

		ULONG render_target_view_reference_count = d3d11_render_target_views[buffer_index]->Release();
		ASSERT(render_target_view_reference_count == 0);

		ULONG render_target_reference_count = d3d11_render_targets[buffer_index]->Release();
		ASSERT(render_target_reference_count == 0);

		BOOL close_rendter_target_view_share_handle = CloseHandle(render_targets_share_handles[buffer_index]);
		ASSERT(close_rendter_target_view_share_handle != FALSE);
		
		debug_point;
	}

	for (unsigned long buffer_index = 0; buffer_index < k_frame_count; buffer_index++)
	{
		ULONG render_target_reference_count = render_targets[buffer_index]->Release();
		ASSERT(render_target_reference_count <= 1); // swapchain may own this resource
	}
}

void c_graphics_d3d12::init_command_allocator()
{
	HRESULT create_command_allocator_result = device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(&command_allocator));
	ASSERT(SUCCEEDED(create_command_allocator_result));
}

void c_graphics_d3d12::deinit_command_allocator()
{
	ULONG command_allocator_reference_count = command_allocator->Release();
	ASSERT(command_allocator_reference_count == 0);
}

void c_graphics_d3d12::init_root_signature()
{
	CD3DX12_ROOT_SIGNATURE_DESC root_signature_description;
	root_signature_description.Init(0, nullptr, 0, nullptr, D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT);

	ID3DBlob* root_signature_blob = nullptr;
	ID3DBlob* root_signature_error_blob = nullptr;
	HRESULT serialize_root_signature_result = D3D12SerializeRootSignature(&root_signature_description, D3D_ROOT_SIGNATURE_VERSION_1, &root_signature_blob, &root_signature_error_blob);
	if (root_signature_error_blob)
	{
		// #TODO: Handle the error
		root_signature_error_blob->Release();
	}
	ASSERT(SUCCEEDED(serialize_root_signature_result));
	HRESULT create_root_signature_result = device->CreateRootSignature(0, root_signature_blob->GetBufferPointer(), root_signature_blob->GetBufferSize(), IID_PPV_ARGS(&root_signature));
	ASSERT(SUCCEEDED(create_root_signature_result));
	root_signature_blob->Release();
}

void c_graphics_d3d12::deinit_root_signature()
{
	ULONG root_signature_reference_count = root_signature->Release();
	ASSERT(root_signature_reference_count == 0);
}

void c_graphics_d3d12::init_command_list()
{
	// Create the command list.
	HRESULT create_command_list_result = device->CreateCommandList(0, D3D12_COMMAND_LIST_TYPE_DIRECT, command_allocator, nullptr, IID_PPV_ARGS(&command_list));
	ASSERT(SUCCEEDED(create_command_list_result));
	ASSERT(command_list != nullptr);

	// Command lists are created in the recording state, but there is nothing
	// to record yet. The main loop expects it to be closed, so close it now.
	command_list->Close();
}

void c_graphics_d3d12::deinit_command_list()
{
	ULONG command_list_reference_count = command_list->Release();
	ASSERT(command_list_reference_count == 0);
}

void c_graphics_d3d12::wait_for_frame_to_complete_cpu()
{
	// WAITING FOR THE FRAME TO COMPLETE BEFORE CONTINUING IS NOT BEST PRACTICE.
	// This is code implemented as such for simplicity. More advanced samples 
	// illustrate how to use fences for efficient resource usage.

	// Signal and increment the fence value.
	const UINT64 current_fence_value = fence_value;
	HRESULT command_queue_signal_result = command_queue->Signal(fence, current_fence_value);
	ASSERT(SUCCEEDED(command_queue_signal_result));
	fence_value++;

	// Wait until the previous frame is finished.
	if (fence->GetCompletedValue() < current_fence_value)
	{
		HRESULT command_queue_set_event_on_completion_result = fence->SetEventOnCompletion(current_fence_value, fence_event);
		ASSERT(SUCCEEDED(command_queue_set_event_on_completion_result));
		WaitForSingleObject(fence_event, INFINITE);
	}

#if 0
	current_frame_index = dxgi_swap_chain->GetCurrentBackBufferIndex();
#endif
	current_frame_index = (current_frame_index + 1) % k_frame_count;
}

void c_graphics_d3d12::init_synchronization_objects()
{
	HRESULT create_fence_result = device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(&fence));
	ASSERT(SUCCEEDED(create_fence_result));
	fence_value = 1;

	// Create an event handle to use for frame synchronization.
	fence_event = CreateEvent(nullptr, FALSE, FALSE, nullptr);
	if (fence_event == nullptr)
	{
		HRESULT last_error = HRESULT_FROM_WIN32(GetLastError());
		ASSERT(SUCCEEDED(last_error));
	}

	// Wait for the command list to execute; we are reusing the same command 
	// list in our main loop but for now, we just want to wait for setup to 
	// complete before continuing.
	wait_for_frame_to_complete_cpu();
}

void c_graphics_d3d12::deinit_synchronization_objects()
{
	fence->Release();
}

void c_graphics_d3d12::init_tiled_texture_manager()
{
	tiled_texture_manager = new c_tiled_texture_manager_d3d12(*this);
}

void c_graphics_d3d12::deinit_tiled_texture_manager()
{
	delete tiled_texture_manager;
}

void c_graphics_d3d12::ready_command_list()
{
	// Command list allocators can only be reset when the associated 
	// command lists have finished execution on the GPU; apps should use 
	// fences to determine GPU execution progress.

	HRESULT command_allocator_reset_result = command_allocator->Reset();
	ASSERT(SUCCEEDED(command_allocator_reset_result));

	// However, when ExecuteCommandList() is called on a particular command 
	// list, that command list can then be reset at any time and must be before 
	// re-recording.
	HRESULT command_list_reset_result = command_list->Reset(command_allocator, nullptr);
	ASSERT(SUCCEEDED(command_list_reset_result));
}

void c_graphics_d3d12::populate_command_list()
{
	tiled_texture_manager->render();

	// Set necessary state.
	command_list->SetGraphicsRootSignature(root_signature);
	command_list->RSSetViewports(1, &d3d12_viewport);
	command_list->RSSetScissorRects(1, &scissor_rectangle);

	// Indicate that the back buffer will be used as a render target.
	CD3DX12_RESOURCE_BARRIER const resource_barrier = CD3DX12_RESOURCE_BARRIER::Transition(render_targets[current_frame_index], D3D12_RESOURCE_STATE_PRESENT, D3D12_RESOURCE_STATE_RENDER_TARGET);
	command_list->ResourceBarrier(1, &resource_barrier);

	// get a handle to the depth/stencil buffer

	D3D12_CPU_DESCRIPTOR_HANDLE dsv_descriptor_handle_cpu = dsv_descriptor_heap_cpu->get_cpu_descriptor_handle(0);
	D3D12_CPU_DESCRIPTOR_HANDLE rtv_descriptor_handle_cpu = rtv_descriptor_heap_cpu->get_cpu_descriptor_handle(current_frame_index);

	command_list->OMSetRenderTargets(1, &rtv_descriptor_handle_cpu, FALSE, &dsv_descriptor_handle_cpu);

	// Record commands.
	const float clearColor[] = { 0.16f, 0.10f, 0.16f, 1.0f };
	command_list->ClearRenderTargetView(rtv_descriptor_handle_cpu, clearColor, 0, nullptr);
	command_list->ClearDepthStencilView(dsv_descriptor_handle_cpu, D3D12_CLEAR_FLAG_DEPTH, 0.0f, 0, 0, nullptr); // #NOTE: Clear to zero because depth is inverted

	command_list->SetDescriptorHeaps(1, &cbv_srv_uav_descriptor_heap_allocator_gpu->descriptor_heap);

	render_imgui_begin();

	if (on_render_scene) on_render_scene(command_list);

	render_imgui_end();

	// Indicate that the back buffer will now be used to present.
	CD3DX12_RESOURCE_BARRIER const resource_barrier2 = CD3DX12_RESOURCE_BARRIER::Transition(render_targets[current_frame_index], D3D12_RESOURCE_STATE_RENDER_TARGET, D3D12_RESOURCE_STATE_PRESENT);
	command_list->ResourceBarrier(1, &resource_barrier2);
}

void c_graphics_d3d12::finish_command_list()
{
	HRESULT command_list_close_result = command_list->Close();
	ASSERT(SUCCEEDED(command_list_close_result));
}

void c_graphics_d3d12::submit_command_list()
{
	// Execute the command list.
	ID3D12CommandList* command_lists[] = { command_list };
	command_queue->ExecuteCommandLists(_countof(command_lists), command_lists);
}

void c_graphics_d3d12::update(float delta)
{
	tiled_texture_manager->update(delta);
}

void c_graphics_d3d12::render()
{
	ready_command_list();
	populate_command_list();
	finish_command_list();
	submit_command_list();

#if 0
	dxgi_swap_chain->Present(1, 0);
#endif

	wait_for_frame_to_complete_cpu();
}

void c_graphics_d3d12::resize_render_targets()
{
	// resize swapchain and deinit/init the render target views
	{
		deinit_depth_buffer();
		deinit_render_target_views();
		wait_for_frame_to_complete_cpu();

#if 0
		HRESULT resize_buffers_result = dxgi_swap_chain->ResizeBuffers(k_frame_count, viewport->get_width(), viewport->get_height(), DXGI_FORMAT_UNKNOWN, 0);
		ASSERT(SUCCEEDED(resize_buffers_result));
#endif

		init_render_target_views();
		init_depth_buffer();
		wait_for_frame_to_complete_cpu();
	}

	setup_viewport();
}

void c_graphics_d3d12::setup_viewport()
{
	d3d12_viewport = {};
	d3d12_viewport.Width = viewport->get_width_float();
	d3d12_viewport.Height = viewport->get_height_float();
	d3d12_viewport.MaxDepth = 1.0f;

	scissor_rectangle = {};
	scissor_rectangle.right = viewport->get_width();
	scissor_rectangle.bottom = viewport->get_height();
}

void c_graphics_d3d12::init_imgui()
{
#if 0
	viewport->register_window_procedure_callback(on_window_procedure_callback, this);

	imgui_srv_descriptor_index = cbv_srv_uav_descriptor_heap_allocator_gpu->allocate();
	imgui_srv_cpu_descriptor_handle = cbv_srv_uav_descriptor_heap_allocator_gpu->get_cpu_descriptor_handle(imgui_srv_descriptor_index);
	imgui_srv_gpu_descriptor_handle = cbv_srv_uav_descriptor_heap_allocator_gpu->get_gpu_descriptor_handle(imgui_srv_descriptor_index);

	ImGui::CreateContext();
	ImGui::StyleColorsDark();

	ImGui_ImplWin32_Init(viewport->get_handle());
	ImGui_ImplDX12_Init(
		device, 
		1, 
		DXGI_FORMAT_R8G8B8A8_UNORM, 
		cbv_srv_uav_descriptor_heap_allocator_gpu->descriptor_heap, 
		imgui_srv_cpu_descriptor_handle, 
		imgui_srv_gpu_descriptor_handle);
#endif
}

bool c_graphics_d3d12::on_window_procedure_callback(void* userdata, HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam)
{
#if 0
	c_graphics_d3d12* graphics = static_cast<c_graphics_d3d12*>(userdata);

	if (ImGui_ImplWin32_WndProcHandler(window_handle, message, wparam, lparam))
	{
		return false;
	}

	ImGuiContext* context = ImGui::GetCurrentContext();
	if (context->NavId != 0)
	{
		return false;
	}

#endif
	return true;
}

void c_graphics_d3d12::render_imgui_begin()
{
#if 0
	ImGui_ImplDX12_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();
#endif
}

void c_graphics_d3d12::render_imgui_end()
{
#if 0
	ImGui::Render();

	ImGui_ImplDX12_RenderDrawData(ImGui::GetDrawData(), command_list);
#endif
}

void c_graphics_d3d12::deinit_imgui()
{
#if 0
	ImGui_ImplDX12_Shutdown();
	ImGui_ImplWin32_Shutdown();
	ImGui::DestroyContext();
#endif
}

void c_graphics_d3d12::init_vertex_shaders()
{
#if 0
	static const wchar_t* vertex_shader_paths[] =
	{
		L"vertex_layout_p.cso",
		L"vertex_layout_pc.cso",
		L"vertex_layout_ptcn.cso",
	};
	static_assert(_countof(vertex_shader_paths) == k_number_of_vertex_layout_types);
	for (unsigned long vertex_shader_index = 0; vertex_shader_index < k_number_of_vertex_layout_types; vertex_shader_index++)
	{
		vertex_shaders[vertex_shader_index] = new c_hlsl_shader_d3d12(vertex_shader_paths[vertex_shader_index]);
	}
#endif
	static e_bcs_resource_type vertex_shader_resource_types[] =
	{
		_bcs_resource_type_viewport_p_vertex_shader,
		_bcs_resource_type_viewport_pc_vertex_shader,
		_bcs_resource_type_viewport_ptcn_vertex_shader
	};
	static_assert(_countof(vertex_shader_resource_types) == k_number_of_vertex_layout_types);
	for (unsigned long vertex_shader_index = 0; vertex_shader_index < k_number_of_vertex_layout_types; vertex_shader_index++)
	{
		vertex_shaders[vertex_shader_index] = new c_hlsl_shader_d3d12(vertex_shader_resource_types[vertex_shader_index]);
	}
}

void c_graphics_d3d12::deinit_vertex_shaders()
{
	for (unsigned long vertex_shader_index = 0; vertex_shader_index < k_number_of_vertex_layout_types; vertex_shader_index++)
	{
		delete vertex_shaders[vertex_shader_index];
	}
}

void c_graphics_d3d12::init_default_pipeline()
{
	default_pipeline_signature = new c_default_pipeline_signature_d3d12(*this, L"c_graphics_d3d12::default_pipeline_signature");
	debug_geometry_pipeline_signature = new c_debug_geometry_pipeline_signature_d3d12(*this, L"c_graphics_d3d12::debug_geometry_pipeline_signature");
}

void c_graphics_d3d12::deinit_default_pipeline()
{
	delete default_pipeline_signature;
	delete debug_geometry_pipeline_signature;
}

void c_graphics_d3d12::init_debug_geometry()
{
	::init_debug_geometry(this);

	wireframe_box_geometry = new c_wireframe_box_geometry_d3d12(*this);
	solid_box_geometry = new c_solid_box_geometry_d3d12(*this);
	sphere_geometry = new c_sphere_geometry_d3d12(*this);
	line_geometry = new c_line_geometry_d3d12(*this);
#if 0
	debug_pixel_shader = new c_hlsl_shader_d3d12(L"debug_shader.cso");
#endif
	debug_pixel_shader = new c_hlsl_shader_d3d12(_bcs_resource_type_viewport_debug_pixel_shader);
	debug_geometry_pipeline = new c_geometry_pipeline_d3d12(*this, *debug_geometry_pipeline_signature, debug_pixel_shader);

	debug_box_buffer = new c_unordered_access_view_buffer_d3d12(*this, sizeof(r_instance), k_max_debug_boxes, L"c_graphics_d3d12::debug_box_buffer");
	debug_sphere_buffer = new c_unordered_access_view_buffer_d3d12(*this, sizeof(r_instance), k_max_debug_spheres, L"c_graphics_d3d12::debug_sphere_buffer");
	debug_line_buffer = new c_unordered_access_view_buffer_d3d12(*this, sizeof(r_instance), k_max_debug_lines, L"c_graphics_d3d12::debug_line_buffer");
	debug_mesh_buffer = new c_unordered_access_view_buffer_d3d12(*this, sizeof(r_instance), k_max_debug_meshes, L"c_graphics_d3d12::debug_mesh_buffer");
}

void c_graphics_d3d12::deinit_debug_geometry()
{
	delete wireframe_box_geometry;
	delete solid_box_geometry;
	delete sphere_geometry;
	delete line_geometry;
	delete debug_pixel_shader;
	delete debug_geometry_pipeline;

	delete debug_box_buffer;
	delete debug_sphere_buffer;
	delete debug_line_buffer;
	delete debug_mesh_buffer;
}

void c_graphics_d3d12::render_debug_geometry(c_camera* camera)
{
	unsigned long total_debug_geometry = 0;
	unsigned long box_index = 0;
	unsigned long sphere_index = 0;
	unsigned long line_index = 0;
	unsigned long mesh_index = 0;
	s_debug_geometry_union data;
	while (debug_pop_geometry(this, &data))
	{
		using namespace DirectX;

		total_debug_geometry++;

		switch (data.type)
		{
		case _debug_geometry_type_box:
			if (box_index < k_max_debug_boxes)
			{
				//float4x4 translate = XMMatrixTranslation(data.box.position.x, data.box.position.y, data.box.position.z);
				//float4x4 scale = XMMatrixTranslation(data.box.scale.x, data.box.scale.y, data.box.scale.z);
				//debug_boxes_temp[box_index].transform = XMMatrixTranspose(translate * scale);
				debug_boxes_temp[box_index].transform = data.box.transform;
				debug_boxes_temp[box_index].color = data.box.color;
				//debug_boxes_temp[box_index].thickness = 1.0f;
				box_index++;
			}
			break;
		case _debug_geometry_type_sphere:
			if (sphere_index < k_max_debug_spheres)
			{
				//float4x4 translate = XMMatrixTranslation(data.sphere.position.x, data.sphere.position.y, data.sphere.position.z);
				//float4x4 scale = XMMatrixTranslation(data.sphere.scale.x, data.sphere.scale.y, data.sphere.scale.z);
				//debug_spheres_temp[sphere_index].transform = XMMatrixTranspose(translate * scale);
				debug_spheres_temp[sphere_index].transform = data.sphere.transform;
				debug_spheres_temp[sphere_index].color = data.sphere.color;
				//debug_spheres_temp[sphere_index].thickness = 1.0f;
				sphere_index++;
			}
			break;
		case _debug_geometry_type_line:
			if (line_index < k_max_debug_lines)
			{
				debug_lines_temp[line_index].transform = data.line.transform;
				debug_lines_temp[line_index].color = data.line.color;
				//debug_lines_temp[line_index].thickness = data.line.thickness;
				line_index++;
			}
			break;
	}
	}

	if (total_debug_geometry > 0)
	{
		command_list->SetGraphicsRootSignature(debug_geometry_pipeline_signature->root_signature);
		command_list->SetGraphicsRootDescriptorTable(0, camera->constant_buffer->get_gpu_descriptor_handle(current_frame_index));

		command_list->SetPipelineState(debug_geometry_pipeline->get_pipeline_state(_pipeline_mode_wireframe_line, _vertex_layout_type_p));

		// draw boxes
		if (box_index > 0)
		{
			debug_box_buffer->update_resource(/*current_frame_index, */debug_boxes_temp, 0, sizeof(debug_boxes_temp[0]) * box_index);
			command_list->SetGraphicsRootDescriptorTable(1, debug_box_buffer->get_gpu_descriptor_handle(/*current_frame_index*/));
			wireframe_box_geometry->draw_instanced(box_index);
		}

		// draw spheres
		if (sphere_index > 0)
		{
			debug_sphere_buffer->update_resource(/*current_frame_index, */debug_spheres_temp, 0, sizeof(debug_spheres_temp[0]) * sphere_index);
			command_list->SetGraphicsRootDescriptorTable(1, debug_sphere_buffer->get_gpu_descriptor_handle(/*current_frame_index*/));
			sphere_geometry->draw_instanced(sphere_index);
		}

		// draw lines
		if (line_index > 0)
		{
			debug_line_buffer->update_resource(/*current_frame_index, */debug_lines_temp, 0, sizeof(debug_lines_temp[0]) * line_index);
			command_list->SetGraphicsRootDescriptorTable(1, debug_line_buffer->get_gpu_descriptor_handle(/*current_frame_index*/));
			line_geometry->draw_instanced(line_index);
		}
	}
}

void c_graphics_d3d12::transition_resource(ID3D12GraphicsCommandList1* command_list, ID3D12Resource* resource, D3D12_RESOURCE_STATES before, D3D12_RESOURCE_STATES after)
{
	D3D12_RESOURCE_BARRIER readback_barrier{};
	readback_barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
	readback_barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
	readback_barrier.Transition.pResource = resource;
	readback_barrier.Transition.Subresource = 0;
	readback_barrier.Transition.StateBefore = before;
	readback_barrier.Transition.StateAfter = after;

	command_list->ResourceBarrier(1, &readback_barrier);
}

const char* vertex_layout_type_to_string(e_vertex_layout_type vertex_layout_type)
{
	switch(vertex_layout_type)
	{
	case _vertex_layout_type_p:			return "vertex_layout_type_p";
	case _vertex_layout_type_pc:		return "vertex_layout_type_pc";
	case _vertex_layout_type_ptcn:		return "vertex_layout_type_ptcn";
	}
	return nullptr;
}
