#pragma once

class c_graphics_d3d12;

enum e_graphics_buffer_type_d3d12
{
#ifdef BCS_DX12_RAY_TRACING_FALLBACK
	_graphics_buffer_type_d3d12_raytracing_instance_descriptions = -2,
	_graphics_buffer_type_d3d12_raytracing_acceleration_structure = -1,
#endif
	_graphics_buffer_type_d3d12_generic = _graphics_buffer_type_generic,
	_graphics_buffer_type_d3d12_unordered_access_view = _graphics_buffer_type_unordered_access_view,
};

class c_graphics_buffer_d3d12 :
	public c_graphics_buffer
{
public:
	c_graphics_buffer_d3d12() = delete;
	c_graphics_buffer_d3d12(const c_graphics_buffer_d3d12&) = delete;
	c_graphics_buffer_d3d12& operator=(const c_graphics_buffer_d3d12&) = delete;
	explicit c_graphics_buffer_d3d12(
		c_graphics_d3d12& graphics,
		e_graphics_buffer_type_d3d12 buffer_type,
		uint32_t element_size,
		uint32_t element_count,
		const wchar_t* debug_name = nullptr);
	virtual ~c_graphics_buffer_d3d12();

	D3D12_GPU_DESCRIPTOR_HANDLE get_gpu_descriptor_handle() const;
	ID3D12Resource* get_resource() const;
	uint32_t get_data_size() const;
	virtual BCS_RESULT write_data(const void* buffer, uint32_t buffer_size, uint32_t buffer_offset) override;
	virtual BCS_RESULT write_data(const void* buffer, uint32_t element_size, uint32_t element_count, uint32_t element_offset) override;
	virtual BCS_RESULT read_data(void* buffer, uint32_t buffer_size, uint32_t buffer_offset) override;
	virtual BCS_RESULT read_data(void* buffer, uint32_t element_size, uint32_t element_count, uint32_t element_offset) override;
	virtual BCS_RESULT map_data_read_begin(void*& gpu_buffer_data) override;
	virtual BCS_RESULT map_data_read_end(void* gpu_buffer_data) override;
	virtual BCS_RESULT map_data_write_begin(void*& gpu_buffer_data) override;
	virtual BCS_RESULT map_data_write_end(void* gpu_buffer_data) override;
	virtual void copy_readback() override;
	uint32_t get_gpu_descriptor_heap_index() const;

protected:
	void init_buffer(const wchar_t* debug_name);
	void deinit_buffer();
	void init_descriptor_heap();
	void deinit_descriptor_heap();

public:
	c_graphics_d3d12& graphics;
	e_graphics_buffer_type_d3d12 buffer_type;

	ID3D12Resource* upload_heap; // #WARN: Can be same resource as gpu_resource
	ID3D12Resource* readback_heap; // #WARN: Can be same resource as gpu_resource
	ID3D12Resource* gpu_resource; // #WARN: Can be same resource as upload_heap

	D3D12_RESOURCE_STATES gpu_resource_state;
	D3D12_GPU_DESCRIPTOR_HANDLE gpu_descriptor_handle;
	D3D12_CPU_DESCRIPTOR_HANDLE cpu_descriptor_handle;
	D3D12_GPU_VIRTUAL_ADDRESS gpu_virtual_address;

	uint32_t descriptor_heap_index;
	uint32_t element_size;
	uint32_t element_count;
	uint32_t data_size;
};

BCS_RESULT graphics_d3d12_buffer_create(
	c_graphics_d3d12* graphics,
	e_graphics_buffer_type_d3d12 buffer_type,
	uint32_t element_size,
	uint32_t element_count,
	c_graphics_buffer_d3d12*& buffer,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_buffer_create(
	c_graphics_d3d12* graphics,
	e_graphics_buffer_type_d3d12 buffer_type,
	uint32_t buffer_size,
	c_graphics_buffer_d3d12*& buffer,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_buffer_destroy(c_graphics_buffer_d3d12* buffer);
