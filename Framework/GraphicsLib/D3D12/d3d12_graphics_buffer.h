#pragma once

class c_graphics;

class c_graphics_unordered_access_view_buffer_d3d12 :
	public c_graphics_buffer
{
public:
	c_graphics_unordered_access_view_buffer_d3d12() = delete;
	c_graphics_unordered_access_view_buffer_d3d12(const c_graphics_unordered_access_view_buffer_d3d12&) = delete;
	c_graphics_unordered_access_view_buffer_d3d12& operator=(const c_graphics_unordered_access_view_buffer_d3d12&) = delete;
	explicit c_graphics_unordered_access_view_buffer_d3d12(
		c_graphics_d3d12& graphics, 
		unsigned long element_size, 
		unsigned long element_count, 
		const wchar_t* name = nullptr);
	virtual ~c_graphics_unordered_access_view_buffer_d3d12();

	D3D12_GPU_DESCRIPTOR_HANDLE get_gpu_descriptor_handle() const;
	ID3D12Resource* get_resource() const;
	unsigned long get_data_size() const;
	virtual BCS_RESULT write_data(const void* buffer, unsigned long buffer_size) override;
	virtual BCS_RESULT read_data(void* buffer, unsigned long buffer_size) override;
	unsigned long get_gpu_descriptor_heap_index() const;
	void update_resource(void* data, size_t offset, size_t size);

protected:
	void init_unordered_access_view_buffer(const wchar_t* name);
	void deinit_unordered_access_view_buffer();
	void init_descriptor_heap();
	void deinit_descriptor_heap();

	D3D12_GPU_DESCRIPTOR_HANDLE gpu_descriptor_handle;
	ID3D12Resource* upload_heap;
	ID3D12Resource* uav_resource;
	c_graphics_d3d12& graphics;
	unsigned long shader_visible_descriptor_heap_index;
	unsigned long element_size;
	unsigned long element_count;
	unsigned long data_size;
};

BCS_RESULT graphics_d3d12_buffer_create(
	c_graphics_d3d12* graphics,
	unsigned long element_size, 
	unsigned long element_count,
	c_graphics_unordered_access_view_buffer_d3d12*& buffer,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_buffer_create(
	c_graphics_d3d12* graphics,
	unsigned long buffer_size,
	c_graphics_unordered_access_view_buffer_d3d12*& buffer,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_buffer_destroy(c_graphics_unordered_access_view_buffer_d3d12* buffer);
