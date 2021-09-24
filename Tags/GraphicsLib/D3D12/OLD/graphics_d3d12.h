#pragma once

using render_scene_callback = void(ID3D12GraphicsCommandList* command_list);

class c_tiled_texture_manager_d3d12;
class c_descriptor_heap_d3d12;
class c_descriptor_heap_allocator_d3d12;
class c_viewport;
class c_hlsl_shader_d3d12;
class c_pipeline_signature_d3d12;
class c_geometry_d3d12;
class c_line_geometry_d3d12;
class c_geometry_pipeline_d3d12;
class c_constant_buffer_array_d3d12;
class c_unordered_access_view_buffer_d3d12;

enum e_vertex_layout_type
{
	_vertex_layout_type_p,
	_vertex_layout_type_pc,
	_vertex_layout_type_ptcn,
	k_number_of_vertex_layout_types
};
const char* vertex_layout_type_to_string(e_vertex_layout_type vertex_layout_type);

class c_graphics_d3d12_v2 :
	public s_debug_geometry
{
public:
	c_graphics_d3d12_v2() = delete;
	c_graphics_d3d12_v2(const c_graphics_d3d12_v2&) = delete;
	c_graphics_d3d12_v2& operator=(const c_graphics_d3d12_v2&) = delete;
	explicit c_graphics_d3d12_v2(c_viewport* viewport);
	~c_graphics_d3d12_v2();

	void get_hardware_adapter(IDXGIFactory4* dxgi_factory, D3D_FEATURE_LEVEL feature_level, IDXGIAdapter1** dxgi_adapter_out, ID3D12Device8** device_out);

	void init_debug_layer();
	void deinit_debug_layer();
	void init_hardware();
	void deinit_hardware();
	void init_hardware_capabilities();
	void deinit_hardware_capabilities();
	void init_descriptor_heap_allocator();
	void deinit_descriptor_heap_allocator();
	void init_command_queue();
	void deinit_command_queue();
	void init_depth_stencil_target();
	void deinit_depth_stencil_target();
	void init_swapchain();
	void deinit_swapchain();
	void init_render_target_views();
	void deinit_render_target_views();
	void init_command_allocator();
	void deinit_command_allocator();
	void init_root_signature();
	void deinit_root_signature();
	void init_command_list();
	void deinit_command_list();
	void wait_for_frame_to_complete_cpu();
	void init_synchronization_objects();
	void deinit_synchronization_objects();
	void init_tiled_texture_manager();
	void deinit_tiled_texture_manager();
	void ready_command_list();
	void populate_command_list();
	void finish_command_list();
	void submit_command_list();
	void update(float delta);
	void render();
	void resize_render_targets();
	void setup_viewport();
	void init_imgui();
	static bool on_window_procedure_callback(void* userdata, HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam);
	void render_imgui_begin();
	void render_imgui_end();
	void deinit_imgui();
	void init_vertex_shaders();
	void deinit_vertex_shaders();

	void init_default_pipeline();
	void deinit_default_pipeline();
	void init_debug_geometry();
	void deinit_debug_geometry();
	void render_debug_geometry(c_camera* camera);

	void transition_resource(ID3D12GraphicsCommandList1* command_list, ID3D12Resource* resource, D3D12_RESOURCE_STATES before, D3D12_RESOURCE_STATES after);

	std::function<render_scene_callback> on_render_scene;

	static constexpr UINT k_frame_count = 2;

	// Device
	ID3D12Device8* device;
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

	// Pipeline objects
	D3D12_VIEWPORT d3d12_viewport;
	D3D12_RECT scissor_rectangle;
#if 0
	IDXGISwapChain3* dxgi_swap_chain;
#endif
	ID3D12Resource* depth_stencil_buffer; // This is the memory for our depth buffer. it will also be used for a stencil buffer in a later tutorial
	ID3D12Resource* render_targets[k_frame_count];
	HANDLE render_targets_share_handles[k_frame_count];
	ID3D11Texture2D* d3d11_render_targets[k_frame_count];
	ID3D11ShaderResourceView* d3d11_render_target_shader_resource_views[k_frame_count];
	ID3D11RenderTargetView* d3d11_render_target_views[k_frame_count];
	ID3D12CommandAllocator* command_allocator;
	ID3D12CommandQueue* command_queue;
	ID3D12RootSignature* root_signature;
	ID3D12GraphicsCommandList1* command_list;

	// Buffers
#if 0
	DXGI_SWAP_CHAIN_DESC swap_chain_description;
#endif
	D3D12_DEPTH_STENCIL_VIEW_DESC depth_stencil_view_description;

	// Synchronization objects
	UINT current_frame_index;
	HANDLE fence_event;
	ID3D12Fence* fence;
	UINT64 fence_value;

	// Application runtime
	c_viewport* viewport;

	// D3D Debug
	ID3D12Debug* debug_interface;
	IDXGIDebug1* dxgi_debug_interface;

	// D3D Runtime
	IDXGIFactory4* dxgi_factory;
	IDXGIAdapter1* dxgi_adapter;

	c_descriptor_heap_allocator_d3d12* cbv_srv_uav_descriptor_heap_allocator_gpu;
	c_descriptor_heap_allocator_d3d12* cbv_srv_uav_descriptor_heap_allocator_cpu;
	c_descriptor_heap_allocator_d3d12* sampler_descriptor_heap_allocator_gpu;
	c_descriptor_heap_d3d12* rtv_descriptor_heap_cpu;
	c_descriptor_heap_d3d12* dsv_descriptor_heap_cpu;
	c_tiled_texture_manager_d3d12* tiled_texture_manager;

	unsigned long imgui_srv_descriptor_index;
	D3D12_CPU_DESCRIPTOR_HANDLE imgui_srv_cpu_descriptor_handle;
	D3D12_GPU_DESCRIPTOR_HANDLE imgui_srv_gpu_descriptor_handle;

	D3D12_FEATURE_DATA_D3D12_OPTIONS options;
	D3D12_FEATURE_DATA_D3D12_OPTIONS1 options1;
	D3D12_FEATURE_DATA_D3D12_OPTIONS2 options2;
	D3D12_FEATURE_DATA_D3D12_OPTIONS3 options3;
	D3D12_FEATURE_DATA_D3D12_OPTIONS4 options4;
	D3D12_FEATURE_DATA_D3D12_OPTIONS5 options5;
	D3D12_FEATURE_DATA_D3D12_OPTIONS6 options6;
	D3D12_FEATURE_DATA_D3D12_OPTIONS7 options7;
	D3D12_FEATURE_DATA_D3D12_OPTIONS8 options8;

	c_hlsl_shader_d3d12* vertex_shaders[k_number_of_vertex_layout_types];
	
	// Pipeline
	c_pipeline_signature_d3d12* default_pipeline_signature;
	c_pipeline_signature_d3d12* debug_geometry_pipeline_signature;

	// Debug Geometry

	static constexpr size_t k_max_debug_boxes = 64 * 1024;
	static constexpr size_t k_max_debug_spheres = 1024;
	static constexpr size_t k_max_debug_lines = 384 * 1024;
	static constexpr size_t k_max_debug_meshes = 1024;

	//static constexpr size_t k_max_debug_boxes = 50000;
	//static constexpr size_t k_max_debug_boxes_per_cb = 65536 / sizeof(r_instance);
	//static constexpr size_t k_debug_boxes_cbs = k_max_debug_boxes / k_max_debug_boxes_per_cb;

	//static constexpr size_t k_max_debug_spheres = 65536 / sizeof(r_instance);

	//static constexpr size_t k_max_debug_meshes = 65536 / sizeof(r_instance);

	//static constexpr size_t k_max_debug_lines = 350000;
	//static constexpr size_t k_max_debug_lines_per_cb = 65536 / sizeof(r_instance);
	//static constexpr size_t k_debug_lines_cbs = k_max_debug_lines / k_max_debug_lines_per_cb;

	c_geometry_d3d12* wireframe_box_geometry;
	c_geometry_d3d12* solid_box_geometry;
	c_geometry_d3d12* sphere_geometry;
	c_geometry_d3d12* line_geometry;
	c_hlsl_shader_d3d12* debug_pixel_shader;
	c_geometry_pipeline_d3d12* debug_geometry_pipeline;

	r_instance debug_boxes_temp[k_max_debug_boxes];
	r_instance debug_spheres_temp[k_max_debug_spheres];
	r_instance debug_lines_temp[k_max_debug_lines];
	r_instance debug_meshes_temp[k_max_debug_meshes];

	c_unordered_access_view_buffer_d3d12* debug_box_buffer;
	c_unordered_access_view_buffer_d3d12* debug_sphere_buffer;
	c_unordered_access_view_buffer_d3d12* debug_line_buffer;
	c_unordered_access_view_buffer_d3d12* debug_mesh_buffer;

	//c_constant_buffer_array_d3d12* debug_box_buffer[k_debug_boxes_cbs];
	//c_constant_buffer_array_d3d12* debug_sphere_buffer;
	//c_constant_buffer_array_d3d12* debug_line_buffer[k_debug_lines_cbs];
	//c_constant_buffer_array_d3d12* debug_mesh_buffer;
};

