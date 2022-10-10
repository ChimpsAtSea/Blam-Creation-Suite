#include "graphicslib-private-pch.h"

c_graphics_d3d12::c_graphics_d3d12(bool use_debug_layer, bool force_cpu_rendering, bool require_ray_tracing_support) :
	c_graphics(),
	device(),
	raytracing_fallback_layer_supported(),
	raytracing_fallback_layer_native_supported(),
	raytracing_fallback_layer_fallback_supported(),
	raytracing_fallback_layer_initialized(),
	d3d12_raytracing_fallback_device(),
	d3d12_raytracing_command_list(),
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
	dxgi_factory6(nullptr),
	dxgi_factory5(nullptr),
	dxgi_factory(nullptr),
	dxgi_adapter(nullptr),
	feature_level(),
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
	options8(),
	shader_model()
{
	if (use_debug_layer)
	{
		init_debug_layer();
	}
	BCS_RESULT init_hardware_result = init_hardware(force_cpu_rendering, require_ray_tracing_support);
	BCS_FAIL_THROW(init_hardware_result);
	init_hardware_capabilities();
	init_descriptor_heap_allocator();
	init_command_queue();
	init_command_allocator();
	init_command_list();
	init_root_signature();
	init_synchronization_objects();
	init_raytracing_fallback_layer();
}

c_graphics_d3d12::~c_graphics_d3d12()
{
	deinit_raytracing_fallback_layer();
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

BCS_RESULT c_graphics_d3d12::init_hardware(bool force_cpu_rendering, bool require_ray_tracing_support)
{
	HRESULT create_dxgi_factory_result = S_OK;

	create_dxgi_factory_result = CreateDXGIFactory1(IID_PPV_ARGS(&dxgi_factory6));
	if (SUCCEEDED(create_dxgi_factory_result))
	{
		// get factory5 interface
		if (FAILED(create_dxgi_factory_result = dxgi_factory6->QueryInterface(IID_PPV_ARGS(&dxgi_factory5))))
		{
			return hresult_to_bcs_result(create_dxgi_factory_result);
		}
		// get factory4 interface
		if (FAILED(create_dxgi_factory_result = dxgi_factory6->QueryInterface(IID_PPV_ARGS(&dxgi_factory))))
		{
			return hresult_to_bcs_result(create_dxgi_factory_result);
		}
		goto create_dxgi_factory_succeeded;
	}
	else create_dxgi_factory_result = CreateDXGIFactory1(IID_PPV_ARGS(&dxgi_factory5));
	if (SUCCEEDED(create_dxgi_factory_result))
	{
		// get factory4 interface
		if (FAILED(create_dxgi_factory_result = dxgi_factory5->QueryInterface(IID_PPV_ARGS(&dxgi_factory))))
		{
			return hresult_to_bcs_result(create_dxgi_factory_result);
		}
		goto create_dxgi_factory_succeeded;
	}
	else create_dxgi_factory_result = CreateDXGIFactory1(IID_PPV_ARGS(&dxgi_factory));
	if (FAILED(create_dxgi_factory_result))
	{
		return hresult_to_bcs_result(create_dxgi_factory_result);
	}
create_dxgi_factory_succeeded:
	ASSERT(dxgi_factory != nullptr);

	BCS_RESULT get_hardware_adapter_result;
	if (force_cpu_rendering)
	{
		get_hardware_adapter_result = get_cpu_hardware_adapter(
			D3D_FEATURE_LEVEL_12_0,
			&dxgi_adapter,
			&device);
	}
	else
	{
		get_hardware_adapter_result = get_hardware_adapter(
			D3D_FEATURE_LEVEL_12_0,
			true,
			require_ray_tracing_support,
			false,
			&dxgi_adapter,
			&device);
		if (require_ray_tracing_support)
		{
			if (BCS_SUCCEEDED(get_hardware_adapter_result))
			{
				raytracing_fallback_layer_supported = true;
				raytracing_fallback_layer_native_supported = true;
			}
			else if (BCS_SUCCEEDED(get_hardware_adapter_result = get_hardware_adapter(
				D3D_FEATURE_LEVEL_12_0,
				true,
				false,
				true,
				&dxgi_adapter,
				&device)))
			{
				raytracing_fallback_layer_supported = true;
				raytracing_fallback_layer_fallback_supported = true;
			}
			else
			{
				raytracing_fallback_layer_supported = false;
			}
		}
		else
		{
			raytracing_fallback_layer_supported = false;
		}
	}


	if (BCS_FAILED(get_hardware_adapter_result))
	{
		return get_hardware_adapter_result;
	}

	ASSERT(dxgi_adapter != nullptr);
	ASSERT(device != nullptr);
}

void c_graphics_d3d12::deinit_hardware()
{
	if (raytracing_fallback_layer_initialized)
	{

	}

	ULONG dxgi_adapter_reference_count = dxgi_adapter->Release();
	ASSERT(dxgi_adapter_reference_count == 0);

	ULONG device_reference_count = device->Release();
	if (device_reference_count > 0)
	{
		dxgi_debug_interface->ReportLiveObjects(DXGI_DEBUG_ALL, DXGI_DEBUG_RLO_ALL);
	}
	ASSERT(device_reference_count == 0);

	if (dxgi_factory6 != nullptr)
	{
		dxgi_factory6->Release();
	}
	if (dxgi_factory5 != nullptr)
	{
		dxgi_factory5->Release();
	}
	ULONG dxgi_factory_reference_count = dxgi_factory->Release();
	ASSERT(dxgi_factory_reference_count == 0);
}


BCS_RESULT c_graphics_d3d12::init_raytracing_fallback_layer()
{
	if (!raytracing_fallback_layer_supported)
	{
		return BCS_S_OK;
	}

	console_write_line_verbose("Using ray tracing fallback layer");

	CreateRaytracingFallbackDeviceFlags create_raytracing_fallback_device_flags = CreateRaytracingFallbackDeviceFlags::None;

	bool force_compute_fallback = command_line_has_argument("forceraytracingcomputefallback");
	if (force_compute_fallback)
	{
		create_raytracing_fallback_device_flags = CreateRaytracingFallbackDeviceFlags::ForceComputeFallback;
	}

	try
	{
		HRESULT d3d12_create_raytracing_fallback_device = D3D12CreateRaytracingFallbackDevice(device, create_raytracing_fallback_device_flags, 0, IID_PPV_ARGS(&d3d12_raytracing_fallback_device));
		if (FAILED(d3d12_create_raytracing_fallback_device))
		{
			return BCS_E_GRAPHICS_HRESULT_ERROR;
		}
	}
	catch (HRESULT hrs)
	{
		return BCS_E_GRAPHICS_HRESULT_ERROR;
	}
	catch (...)
	{
		return BCS_E_FATAL;
	}

	return BCS_S_OK;
}

void c_graphics_d3d12::deinit_raytracing_fallback_layer()
{
	ULONG d3d12_raytracing_fallback_device_reference_count = d3d12_raytracing_fallback_device->Release();
	ASSERT(d3d12_raytracing_fallback_device_reference_count == 0);
}

void c_graphics_d3d12::init_hardware_capabilities()
{
	for (uint32_t descriptor_heap_type = 0; descriptor_heap_type < D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES; descriptor_heap_type++)
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

BCS_RESULT c_graphics_d3d12::hresult_to_bcs_result(HRESULT result)
{
	if (FAILED(result))
	{
		last_error = result;
		switch (result)
		{
		case DXGI_ERROR_DEVICE_REMOVED:
		case DXGI_ERROR_DEVICE_RESET:
			return BCS_E_GRAPHICS_DEVICE_LOST;
		default:
			return BCS_E_GRAPHICS_HRESULT_ERROR;
		}
	}
	return BCS_S_GRAPHICS_HRESULT_OK;
}

HRESULT c_graphics_d3d12::ready_command_list()
{
	// Command list allocators can only be reset when the associated 
	// command lists have finished execution on the GPU; apps should use 
	// fences to determine GPU execution progress.
	HRESULT command_allocator_reset_result = command_allocator->Reset();
	if (FAILED(command_allocator_reset_result))
	{
		return command_allocator_reset_result;
	}

	// However, when ExecuteCommandList() is called on a particular command 
	// list, that command list can then be reset at any time and must be before 
	// re-recording.
	HRESULT command_list_reset_result = command_list->Reset(command_allocator, nullptr);
	if (FAILED(command_allocator_reset_result))
	{
		return command_allocator_reset_result;
	}
}

void c_graphics_d3d12::create_command_list()
{
	command_list->SetGraphicsRootSignature(root_signature);
	command_list->SetDescriptorHeaps(1, &cbv_srv_uav_descriptor_heap_allocator_gpu->descriptor_heap);

	render_callback();
}

HRESULT c_graphics_d3d12::finish_command_list()
{
	HRESULT command_list_close_result = command_list->Close();
	if (FAILED(command_list_close_result))
	{
		return command_list_close_result;
	}

	return S_OK;
}

void c_graphics_d3d12::submit_command_list()
{
	// Execute the command list.
	ID3D12CommandList* command_lists[] = { command_list };
	command_queue->ExecuteCommandLists(_countof(command_lists), command_lists);
}

BCS_RESULT c_graphics_d3d12::render_frame()
{
	BCS_RESULT rs = BCS_S_OK;

	HRESULT ready_command_list_result = ready_command_list();
	if (FAILED(ready_command_list_result))
	{
		return hresult_to_bcs_result(ready_command_list_result);
	}

	create_command_list();

	HRESULT finish_command_list_result = finish_command_list();
	if (FAILED(finish_command_list_result))
	{
		return hresult_to_bcs_result(finish_command_list_result);
	}

	submit_command_list();

	if (BCS_FAILED(rs = present_callback.call<BCS_RESULT>()))
	{
		return rs;
	}

	if (BCS_FAILED(rs = wait_for_frame_to_complete_cpu()))
	{
		return rs;
	}
}

BCS_RESULT c_graphics_d3d12::wait_for_frame_to_complete_cpu()
{
	BCS_RESULT rs = BCS_S_OK;

	// WAITING FOR THE FRAME TO COMPLETE BEFORE CONTINUING IS NOT BEST PRACTICE.
	// This is code implemented as such for simplicity. More advanced samples 
	// illustrate how to use fences for efficient resource usage.

	// Signal and increment the fence value.
	const UINT64 current_fence_value = fence_value;
	HRESULT command_queue_signal_result = command_queue->Signal(fence, current_fence_value);
	if (FAILED(command_queue_signal_result))
	{
		return hresult_to_bcs_result(command_queue_signal_result);
	}
	fence_value++;

	// Wait until the previous frame is finished.
	if (fence->GetCompletedValue() < current_fence_value)
	{
		HRESULT command_queue_set_event_on_completion_result = fence->SetEventOnCompletion(current_fence_value, fence_event);
		if (FAILED(command_queue_signal_result))
		{
			return hresult_to_bcs_result(command_queue_set_event_on_completion_result);
		}
		WaitForSingleObject(fence_event, INFINITE);
	}

	return rs;
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
	BCS_RESULT wait_for_frame_to_complete_result = wait_for_frame_to_complete_cpu();
	ASSERT(BCS_SUCCEEDED(wait_for_frame_to_complete_result));
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
	for (uint32_t index = 0; index < _countof(descriptor_tables); index++)
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

void c_graphics_d3d12::set_object_debug_name(const wchar_t* debug_name, const wchar_t* internal_name, ID3D12Object* d3d12_object)
{
	if (debug_name == nullptr || *debug_name == 0)
	{
		d3d12_object->SetName(internal_name);
	}
	else if (debug_name != nullptr && internal_name == nullptr)
	{
		d3d12_object->SetName(debug_name);
	}
	else
	{
		int characters = _snwprintf(nullptr, 0, L"%s (%s)", debug_name, internal_name);
		int buffer_length = characters + 1;
		wchar_t* name_buffer = new(alloca(sizeof(wchar_t) * buffer_length)) wchar_t[buffer_length];
		int characters_written = _snwprintf(name_buffer, buffer_length, L"%s (%s)", debug_name, internal_name);
		name_buffer[characters_written] = 0; // ensure null terminated
		ASSERT(characters == characters_written);
		d3d12_object->SetName(name_buffer);
	}
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

BCS_RESULT c_graphics_d3d12::get_hardware_adapter(
	D3D_FEATURE_LEVEL minimum_feature_level,
	bool prefer_high_performance,
	bool require_ray_tracing_support,
	bool require_shader_model_6_2_support,
	IDXGIAdapter1** dxgi_adapter_out,
	ID3D12Device8** device_out)
{
	*dxgi_adapter_out = nullptr;
	*device_out = nullptr;
	for (UINT adapter_index = 0; ; adapter_index++)
	{
		IDXGIAdapter1* dxgi_adapter = nullptr;

		HRESULT enum_adapters_result = DXGI_ERROR_NOT_FOUND;
		if (dxgi_factory6 != nullptr)
		{
			DXGI_GPU_PREFERENCE gpu_preference = DXGI_GPU_PREFERENCE_HIGH_PERFORMANCE;
			// #TODO: Read setting for minimum performance gpu
			// #NOTE: Prefer an onboard GPU to prevent nuking main GPU performance
			// #NOTE: COMPUTE will need to be aware of the avilable adapter interfaces
			//			and user should be able to configure workload adapter indices
			if (!prefer_high_performance)
			{
				gpu_preference = DXGI_GPU_PREFERENCE_MINIMUM_POWER;
			}

			enum_adapters_result = dxgi_factory6->EnumAdapterByGpuPreference(adapter_index, gpu_preference, IID_PPV_ARGS(&dxgi_adapter));
		}
		else
		{
			enum_adapters_result = dxgi_factory->EnumAdapters1(adapter_index, &dxgi_adapter);
		}

		if (enum_adapters_result == DXGI_ERROR_NOT_FOUND)
		{
			// No more adapters to enumerate.
			break;
		}

		DXGI_ADAPTER_DESC1 adapter_description{};
		dxgi_adapter->GetDesc1(&adapter_description);
		console_write_verbose("Adapter %u '%S'", adapter_index, adapter_description.Description);

		ID3D12Device8* device = nullptr;

		HRESULT create_device_result = E_FAIL;

		static constexpr D3D_FEATURE_LEVEL requested_feature_levels[] =
		{
			D3D_FEATURE_LEVEL_12_2,
			D3D_FEATURE_LEVEL_12_1,
			D3D_FEATURE_LEVEL_12_0
		};
		for (D3D_FEATURE_LEVEL request_feature_level : requested_feature_levels)
		{
			if (FAILED(create_device_result) && request_feature_level >= minimum_feature_level)
			{
				create_device_result = D3D12CreateDevice(dxgi_adapter, request_feature_level, IID_PPV_ARGS(&device));
				if (SUCCEEDED(create_device_result))
				{
					int major = request_feature_level >> 12 & 0xF;
					int minor = request_feature_level >> 8 & 0xF;
					console_write_line_verbose(" using D3D_FEATURE_LEVEL_%i_%i", major, minor);
					feature_level = request_feature_level;
					break;
				}
			}
		}
		if (FAILED(create_device_result))
		{
			console_write_line_verbose(" unsupported");
		}
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

			shader_model.HighestShaderModel = D3D_HIGHEST_SHADER_MODEL;
			device->CheckFeatureSupport(D3D12_FEATURE_SHADER_MODEL, &shader_model, sizeof(shader_model));

			bool is_valid_device = true;

			if (require_ray_tracing_support)
			{
				is_valid_device &= options5.RaytracingTier >= D3D12_RAYTRACING_TIER_1_0;
			}

			if (require_shader_model_6_2_support)
			{
				is_valid_device &= shader_model.HighestShaderModel >= D3D_SHADER_MODEL_6_2;
			}

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
			}
		}

		UINT dxgi_adapter_reference_count = dxgi_adapter->Release();
		ASSERT(dxgi_adapter_reference_count == 0);

	}
	return BCS_E_FAIL; // failed to find a suitable device
}

BCS_RESULT c_graphics_d3d12::get_cpu_hardware_adapter(D3D_FEATURE_LEVEL requested_feature_level, IDXGIAdapter1** dxgi_adapter_out, ID3D12Device8** device_out)
{
	*dxgi_adapter_out = nullptr;
	*device_out = nullptr;
	for (UINT adapter_index = 0; ; ++adapter_index)
	{
		IDXGIAdapter1* dxgi_adapter = nullptr;

		HRESULT enum_adapters_result = dxgi_factory->EnumAdapters1(adapter_index, &dxgi_adapter);

		DXGI_ADAPTER_DESC1 adapter_description{};
		dxgi_adapter->GetDesc1(&adapter_description);

		bool is_microsoft_basic_render_device = adapter_description.VendorId == 0x1414 && adapter_description.DeviceId == 0x008c;
		if (is_microsoft_basic_render_device)
		{
			console_write_verbose("Adapter %u '%S'", adapter_index, adapter_description.Description);

			HRESULT create_device_result = D3D12CreateDevice(dxgi_adapter, requested_feature_level, IID_PPV_ARGS(&device));
			if (FAILED(create_device_result))
			{
				console_write_line_verbose(" unsupported");
			}
			if (SUCCEEDED(create_device_result))
			{
				int major = requested_feature_level >> 12 & 0xF;
				int minor = requested_feature_level >> 8 & 0xF;
				console_write_line_verbose(" using D3D_FEATURE_LEVEL_%i_%i", major, minor);
				feature_level = requested_feature_level;

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
				}
			}
		}

		UINT dxgi_adapter_reference_count = dxgi_adapter->Release();
		ASSERT(dxgi_adapter_reference_count == 0);
	}
	return BCS_E_FAIL;
}

BCS_RESULT graphics_d3d12_create(bool use_debug_layer, bool force_cpu_rendering, bool require_ray_tracing_support, c_graphics_d3d12*& graphics)
{
	try
	{
		graphics = new() c_graphics_d3d12(use_debug_layer, force_cpu_rendering, require_ray_tracing_support);
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

