#pragma once

class c_descriptor_heap_allocator_d3d12;
class c_descriptor_heap_d3d12;

class c_graphics_d3d12 :
	public c_graphics
{
public:
	c_graphics_d3d12() = delete;
	c_graphics_d3d12(const c_graphics_d3d12&) = delete;
	c_graphics_d3d12& operator=(const c_graphics_d3d12&) = delete;
	c_graphics_d3d12(bool use_debug_layer, bool force_cpu_rendering);
	virtual ~c_graphics_d3d12();

	BCS_RESULT get_hardware_adapter(
		D3D_FEATURE_LEVEL minimum_feature_level,
		bool prefer_high_performance,
		IDXGIAdapter1** dxgi_adapter_out, 
		ID3D12Device8** device_out);

	BCS_RESULT get_cpu_hardware_adapter(
		D3D_FEATURE_LEVEL feature_level,
		IDXGIAdapter1** dxgi_adapter_out,
		ID3D12Device8** device_out);

	void init_debug_layer();
	void deinit_debug_layer();
	BCS_RESULT init_hardware(bool force_cpu_rendering);
	void deinit_hardware();
	void init_hardware_capabilities();
	void deinit_hardware_capabilities();
	void init_descriptor_heap_allocator();
	void deinit_descriptor_heap_allocator();
	void init_command_queue();
	void deinit_command_queue();
	void init_command_allocator();
	void deinit_command_allocator();
	void init_command_list();
	void deinit_command_list();
	void init_synchronization_objects();
	void deinit_synchronization_objects();
	void init_root_signature();
	void deinit_root_signature();

	static void set_object_debug_name(const wchar_t* debug_name, const wchar_t* internal_name, ID3D12Object* d3d12_object);

	HRESULT last_error;
	BCS_RESULT hresult_to_bcs_result(HRESULT result);

	HRESULT ready_command_list();
	void create_command_list();
	HRESULT finish_command_list();
	void submit_command_list();
	BCS_RESULT wait_for_frame_to_complete_cpu();
	void transition_resource(
		ID3D12Resource* resource, 
		D3D12_RESOURCE_STATES before, 
		D3D12_RESOURCE_STATES after);

	virtual BCS_RESULT render_frame() override;

	ID3D12Device8* device;

	HANDLE fence_event;
	ID3D12Fence* fence;
	UINT64 fence_value;

	ID3D12Debug* debug_interface;
	IDXGIDebug1* dxgi_debug_interface;


	IDXGIFactory6* dxgi_factory6;
	IDXGIFactory5* dxgi_factory5;
	IDXGIFactory4* dxgi_factory;
	IDXGIAdapter1* dxgi_adapter;
	D3D_FEATURE_LEVEL feature_level;

	ID3D12CommandAllocator* command_allocator;
	ID3D12CommandQueue* command_queue;
	ID3D12RootSignature* root_signature;
	ID3D12GraphicsCommandList1* command_list;

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

	c_descriptor_heap_allocator_d3d12* cbv_srv_uav_descriptor_heap_allocator_gpu;
	c_descriptor_heap_allocator_d3d12* cbv_srv_uav_descriptor_heap_allocator_cpu;
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
};

BCS_RESULT graphics_d3d12_create(bool use_debug_layer, bool force_cpu_rendering, c_graphics_d3d12*& graphics);
BCS_RESULT graphics_d3d12_destroy(c_graphics_d3d12* graphics);
