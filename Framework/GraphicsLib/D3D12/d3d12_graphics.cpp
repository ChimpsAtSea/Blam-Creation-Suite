#include "graphicslib-private-pch.h"

c_graphics_d3d12::c_graphics_d3d12(bool use_debug_layer) :
	c_graphics(),
	device(),
	descriptor_sizes(),
	command_allocator(nullptr),
	command_queue(nullptr),
	root_signature(nullptr),
	command_list(nullptr),
	fence_event(NULL),
	fence(nullptr),
	fence_value(0),
	debug_interface(nullptr),
	dxgi_debug_interface(nullptr),
	dxgi_factory(nullptr),
	dxgi_adapter(nullptr),
	cbv_srv_uav_descriptor_heap_allocator_gpu(nullptr),
	cbv_srv_uav_descriptor_heap_allocator_cpu(nullptr),
	sampler_descriptor_heap_allocator_gpu(nullptr),
	options(),
	options1(),
	options2(),
	options3(),
	options4(),
	options5(),
	options6(),
	options7(),
	options8()
{
	if (use_debug_layer)
	{
		init_debug_layer();
	}
	init_hardware();
	init_hardware_capabilities();
	init_descriptor_heap_allocator();
	init_command_queue();
	init_command_allocator();
	init_command_list();
	init_root_signature();
	init_synchronization_objects();
	//init_depth_stencil_target();
	//init_default_pipeline();
	//init_debug_geometry();
	//setup_viewport();
}

c_graphics_d3d12::~c_graphics_d3d12()
{
	//deinit_debug_geometry();
	//deinit_default_pipeline();
	//deinit_depth_stencil_target();
	deinit_synchronization_objects();
	deinit_root_signature();
	deinit_command_list();
	deinit_command_allocator();
	deinit_command_queue();
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

void c_graphics_d3d12::init_hardware()
{
	HRESULT create_dxgi_factory_result = CreateDXGIFactory1(IID_PPV_ARGS(&dxgi_factory));
	ASSERT(SUCCEEDED(create_dxgi_factory_result));

	BCS_RESULT get_hardware_adapter_result = get_hardware_adapter(dxgi_factory, D3D_FEATURE_LEVEL_12_1, &dxgi_adapter, &device);
	ASSERT(BCS_SUCCEEDED(get_hardware_adapter_result));
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

void c_graphics_d3d12::init_hardware_capabilities()
{
	for (unsigned long descriptor_heap_type = 0; descriptor_heap_type < D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES; descriptor_heap_type++)
	{
		descriptor_sizes[descriptor_heap_type] = device->GetDescriptorHandleIncrementSize(static_cast<D3D12_DESCRIPTOR_HEAP_TYPE>(descriptor_heap_type));
	}
}

void c_graphics_d3d12::deinit_hardware_capabilities()
{

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

void c_graphics_d3d12::init_descriptor_heap_allocator()
{
	cbv_srv_uav_descriptor_heap_allocator_gpu = new() c_descriptor_heap_allocator_d3d12(
		*this,
		D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV,
		D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE,
		131072,
		L"c_graphics_d3d12::cbv_srv_uav_descriptor_heap_allocator_gpu"
	);
	cbv_srv_uav_descriptor_heap_allocator_cpu = new() c_descriptor_heap_allocator_d3d12(
		*this,
		D3D12_DESCRIPTOR_HEAP_TYPE_CBV_SRV_UAV,
		D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE,
		131072,
		L"c_graphics_d3d12::cbv_srv_uav_descriptor_heap_allocator_cpu"
	);
	sampler_descriptor_heap_allocator_gpu = new() c_descriptor_heap_allocator_d3d12(
		*this,
		D3D12_DESCRIPTOR_HEAP_TYPE_SAMPLER,
		D3D12_DESCRIPTOR_HEAP_FLAG_SHADER_VISIBLE,
		128,
		L"c_graphics_d3d12::cbv_srv_uav_descriptor_heap_allocator_gpu"
	);
}

void c_graphics_d3d12::deinit_descriptor_heap_allocator()
{
	delete cbv_srv_uav_descriptor_heap_allocator_gpu;
	delete cbv_srv_uav_descriptor_heap_allocator_cpu;
	delete sampler_descriptor_heap_allocator_gpu;
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

void c_graphics_d3d12::create_command_list()
{
	command_list->SetGraphicsRootSignature(root_signature);
	command_list->SetDescriptorHeaps(1, &cbv_srv_uav_descriptor_heap_allocator_gpu->descriptor_heap);

	render_callback();
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

void c_graphics_d3d12::render_frame()
{
	ready_command_list();
	create_command_list();
	finish_command_list();
	submit_command_list();
	present_callback();
	wait_for_frame_to_complete_cpu();
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

void c_graphics_d3d12::init_root_signature()
{
	static D3D12_DESCRIPTOR_RANGE descriptor_range_uav_0 = {};
	descriptor_range_uav_0.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
	descriptor_range_uav_0.NumDescriptors = 1;
	descriptor_range_uav_0.BaseShaderRegister = 0;
	descriptor_range_uav_0.RegisterSpace = 0;
	descriptor_range_uav_0.OffsetInDescriptorsFromTableStart = 0;

	static D3D12_DESCRIPTOR_RANGE descriptor_range_uav_1 = {};
	descriptor_range_uav_1.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
	descriptor_range_uav_1.NumDescriptors = 1;
	descriptor_range_uav_1.BaseShaderRegister = 1;
	descriptor_range_uav_1.RegisterSpace = 0;
	descriptor_range_uav_1.OffsetInDescriptorsFromTableStart = 0;

	static D3D12_ROOT_DESCRIPTOR_TABLE descriptor_table_uav_0 = {};
	descriptor_table_uav_0.NumDescriptorRanges = 1;
	descriptor_table_uav_0.pDescriptorRanges = &descriptor_range_uav_0;

	static D3D12_ROOT_DESCRIPTOR_TABLE descriptor_table_uav_1 = {};
	descriptor_table_uav_1.NumDescriptorRanges = 1;
	descriptor_table_uav_1.pDescriptorRanges = &descriptor_range_uav_1;
	
	static D3D12_ROOT_DESCRIPTOR_TABLE* descriptor_tables[] =
	{
		&descriptor_table_uav_0,
		&descriptor_table_uav_1,
	};

	static D3D12_ROOT_PARAMETER root_parameters[_countof(descriptor_tables)] = {};
	for (unsigned long index = 0; index < _countof(descriptor_tables); index++)
	{
		D3D12_ROOT_PARAMETER& root_parameter = root_parameters[index];
		D3D12_ROOT_DESCRIPTOR_TABLE* descriptor_table = descriptor_tables[index];

		root_parameter.ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE; // this is a descriptor table
		root_parameter.DescriptorTable = *descriptor_table; // this is our descriptor table for this root parameter
		root_parameter.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL; // our pixel shader will be the only shader accessing this parameter for now
	}

	CD3DX12_ROOT_SIGNATURE_DESC root_signature_description;
	root_signature_description.Init(
		_countof(root_parameters),
		root_parameters,
		0, 
		nullptr,
		D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT | // we can deny shader stages here for better performance
		D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS |
		D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS |
		D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS);

	ID3DBlob* root_signature_blob = nullptr;
	ID3DBlob* root_signature_error_blob = nullptr;
	HRESULT serialize_root_signature_result = D3D12SerializeRootSignature(&root_signature_description, D3D_ROOT_SIGNATURE_VERSION_1_0, &root_signature_blob, &root_signature_error_blob);
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

void c_graphics_d3d12::transition_resource(
	ID3D12Resource* resource, 
	D3D12_RESOURCE_STATES before, 
	D3D12_RESOURCE_STATES after)
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

BCS_RESULT c_graphics_d3d12::get_hardware_adapter(IDXGIFactory4* dxgi_factory, D3D_FEATURE_LEVEL feature_level, IDXGIAdapter1** dxgi_adapter_out, ID3D12Device8** device_out)
{
	*dxgi_adapter_out = nullptr;
	*device_out = nullptr;
	for (UINT adapter_index = 0; ; ++adapter_index)
	{
		IDXGIAdapter1* dxgi_adapter = nullptr;
		if (DXGI_ERROR_NOT_FOUND == dxgi_factory->EnumAdapters1(adapter_index, &dxgi_adapter))
		{
			// No more adapters to enumerate.
			break;
		}

		DXGI_ADAPTER_DESC1 adapter_description{};
		dxgi_adapter->GetDesc1(&adapter_description);
		console_write_line_verbose("Adapter %u '%S'", adapter_index, adapter_description.Description);

		ID3D12Device8* device = nullptr;
		HRESULT create_device_result = D3D12CreateDevice(
			dxgi_adapter,
			D3D_FEATURE_LEVEL_12_1,
			IID_PPV_ARGS(&device)
		);
		if (SUCCEEDED(create_device_result))
		{
			device->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS, &options, sizeof(options));
			device->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS1, &options1, sizeof(options1));
			device->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS2, &options2, sizeof(options2));
			device->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS3, &options3, sizeof(options3));
			device->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS4, &options4, sizeof(options4));
			device->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS5, &options5, sizeof(options5));
			device->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS6, &options6, sizeof(options6));
			device->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS7, &options7, sizeof(options7));
			device->CheckFeatureSupport(D3D12_FEATURE_D3D12_OPTIONS8, &options8, sizeof(options8));

			bool is_valid_device = true;
			if (is_valid_device)
			{
				*device_out = device;
				*dxgi_adapter_out = dxgi_adapter;
				return BCS_S_OK;
			}
			else
			{
				UINT device_reference_count = device->Release();
				ASSERT(device_reference_count == 0);

				UINT dxgi_adapter_reference_count = dxgi_adapter->Release();
				ASSERT(dxgi_adapter_reference_count == 0);
			}
		}
	}
	return BCS_E_FAIL; // failed to find a suitable device
}

BCS_RESULT graphics_d3d12_create(bool use_debug_layer, c_graphics_d3d12*& graphics)
{
	try
	{
		graphics = new() c_graphics_d3d12(use_debug_layer);
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

BCS_RESULT graphics_d3d12_destroy(c_graphics_d3d12* graphics)
{
	try
	{
		delete graphics;
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

