#pragma once

class c_descriptor_heap_allocator_d3d12;
class c_descriptor_heap_d3d12;

enum e_graphics_raytracing_mode_d3d12
{
	_graphics_raytracing_mode_d3d12_unsupported [[maybe_unused]],
	_graphics_raytracing_mode_d3d12_native [[maybe_unused]],
	_graphics_raytracing_mode_d3d12_fallback [[maybe_unused]],
};

class c_graphics_d3d12 :
	public c_graphics
{
public:
	c_graphics_d3d12() = delete;
	c_graphics_d3d12(const c_graphics_d3d12&) = delete;
	c_graphics_d3d12& operator=(const c_graphics_d3d12&) = delete;
	c_graphics_d3d12(bool use_debug_layer, bool force_cpu_rendering, bool require_ray_tracing_support);
	BCS_RESULT construct();
	BCS_RESULT destruct();
	virtual ~c_graphics_d3d12();

	BCS_RESULT get_hardware_adapter(
		D3D_FEATURE_LEVEL minimum_feature_level,
		bool prefer_high_performance,
		bool require_ray_tracing_support,
		bool require_shader_model_6_2_support,
		IDXGIAdapter1*& dxgi_adapter_out,
		DXGI_ADAPTER_DESC1& adapter_description_out,
		ID3D12Device8*& device_out);

	BCS_RESULT get_cpu_hardware_adapter(
		D3D_FEATURE_LEVEL feature_level,
		IDXGIAdapter1*& dxgi_adapter_out,
		DXGI_ADAPTER_DESC1& adapter_description_out,
		ID3D12Device8*& device_out);

	BCS_RESULT init_debug_layer();
	BCS_RESULT deinit_debug_layer();
	static HRESULT init_experimental_features();
	BCS_RESULT init_hardware(bool force_cpu_rendering, bool require_ray_tracing_support);
	BCS_RESULT deinit_hardware();
#ifdef BCS_DX12_RAY_TRACING_FALLBACK
	BCS_RESULT init_raytracing_fallback_layer();
	BCS_RESULT deinit_raytracing_fallback_layer();
#endif
	BCS_RESULT init_hardware_capabilities();
	BCS_RESULT deinit_hardware_capabilities();
	BCS_RESULT init_descriptor_heap_allocator();
	BCS_RESULT deinit_descriptor_heap_allocator();
	BCS_RESULT init_command_queue();
	BCS_RESULT deinit_command_queue();
	BCS_RESULT init_command_allocator();
	BCS_RESULT deinit_command_allocator();
	BCS_RESULT init_command_list();
	BCS_RESULT deinit_command_list();
	BCS_RESULT init_synchronization_objects();
	BCS_RESULT deinit_synchronization_objects();

	static void set_object_debug_name(const wchar_t* debug_name, const wchar_t* internal_name, ID3D12Object* d3d12_object);

	BCS_RESULT hresult_to_bcs_result(HRESULT result);
	BCS_RESULT reference_count_to_bcs_result(ULONG reference_count);

	HRESULT ready_command_list();
	void create_command_list();
	HRESULT finish_command_list();
	void submit_command_list();
	BCS_RESULT wait_for_frame_to_complete_cpu();
	void transition_resource(
		ID3D12Resource* resource, 
		D3D12_RESOURCE_STATES before, 
		D3D12_RESOURCE_STATES after);
	bool should_debug_reference_counts() const;

	virtual BCS_RESULT begin() override;
	virtual BCS_RESULT end() override;
	virtual BCS_RESULT execute() override;
	virtual BCS_RESULT start_debug_capture() override;
	virtual BCS_RESULT end_debug_capture() override;
	virtual BCS_RESULT start_debug_event(const char* event_name) override;
	virtual BCS_RESULT start_debug_event_ex(const char* event_name_format, ...) override;
	virtual BCS_RESULT start_debug_event_vargs(const char* event_name_format, va_list& virtual_argument_list) override;
	virtual BCS_RESULT end_debug_event() override;

	ID3D12Device8* device;

	bool use_debug_layer;
	bool force_cpu_rendering;
	bool require_ray_tracing_support;

	// raytracing fallback layer
	bool experimental_shader_models_enabled;
	e_graphics_raytracing_mode_d3d12 raytracing_mode;
#ifdef BCS_DX12_RAY_TRACING_FALLBACK
	ID3D12RaytracingFallbackDevice* d3d12_raytracing_fallback_device;
	ID3D12RaytracingFallbackCommandList* d3d12_raytracing_command_list;
#endif

	HANDLE fence_event;
	ID3D12Fence* fence;
	UINT64 fence_value;

	ID3D12Debug* debug_interface;
	IDXGIDebug1* dxgi_debug_interface;
	DXGI_ADAPTER_DESC1 adapter_description;

	IDXGIFactory6* dxgi_factory6;
	IDXGIFactory5* dxgi_factory5;
	IDXGIFactory4* dxgi_factory;
	IDXGIAdapter1* dxgi_adapter;
	D3D_FEATURE_LEVEL feature_level;

	ID3D12CommandAllocator* command_allocator;
	ID3D12CommandQueue* command_queue;
	ID3D12GraphicsCommandList4* command_list;

	union
	{
		UINT descriptor_sizes[D3D12_DESCRIPTOR_HEAP_TYPE_NUM_TYPES];
		struct
		{
			UINT cbv_srv_uav_descriptor_size;
			UINT sampler_descriptor_size;
			UINT rtv_descriptor_size;
			UINT dsv_descriptor_size;
		};
	};

	c_descriptor_heap_allocator_d3d12* cbv_srv_uav_descriptor_heap_allocator;
	c_descriptor_heap_allocator_d3d12* sampler_descriptor_heap_allocator_gpu;

	D3D12_FEATURE_DATA_D3D12_OPTIONS options;
	D3D12_FEATURE_DATA_D3D12_OPTIONS1 options1;
	D3D12_FEATURE_DATA_D3D12_OPTIONS2 options2;
	D3D12_FEATURE_DATA_D3D12_OPTIONS3 options3;
	D3D12_FEATURE_DATA_D3D12_OPTIONS4 options4;
	D3D12_FEATURE_DATA_D3D12_OPTIONS5 options5;
	D3D12_FEATURE_DATA_D3D12_OPTIONS6 options6;
	D3D12_FEATURE_DATA_D3D12_OPTIONS7 options7;
	D3D12_FEATURE_DATA_D3D12_OPTIONS8 options8;
	D3D12_FEATURE_DATA_SHADER_MODEL shader_model;

	HRESULT last_error;

	// binding tracking
	c_graphics_shader_pipeline_d3d12* bound_shader_pipeline;
};

BCS_RESULT graphics_d3d12_create(bool use_debug_layer, bool force_cpu_rendering, bool require_ray_tracing_support, c_graphics_d3d12*& graphics);
BCS_RESULT graphics_d3d12_destroy(c_graphics_d3d12* graphics);
