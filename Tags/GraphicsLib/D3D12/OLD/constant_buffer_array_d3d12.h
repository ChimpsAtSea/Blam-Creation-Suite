#pragma once

class c_constant_buffer_array_d3d12
{
public:
	static size_t constexpr k_max_upload_heaps = 8;

	c_constant_buffer_array_d3d12() = delete;
	c_constant_buffer_array_d3d12(const c_constant_buffer_array_d3d12&) = delete;
	c_constant_buffer_array_d3d12& operator=(const c_constant_buffer_array_d3d12&) = delete;
	explicit c_constant_buffer_array_d3d12(c_graphics_d3d12& graphics, unsigned long data_size, unsigned long array_count, const wchar_t* name = nullptr);
	~c_constant_buffer_array_d3d12();

	D3D12_GPU_DESCRIPTOR_HANDLE get_gpu_descriptor_handle(unsigned long index) const;
	ID3D12Resource* get_resource(unsigned long index) const;
	unsigned long get_data_size() const;
	unsigned long get_array_count() const;
	unsigned long get_gpu_descriptor_heap_index() const;
	void update_resource(unsigned long index, void* data, size_t offset, size_t size);

protected:
	void init_constant_buffer(const wchar_t* name);
	void deinit_constant_buffer();
	void init_descriptor_heap();
	void deinit_descriptor_heap();

	//D3D12_GPU_DESCRIPTOR_HANDLE gpu_descriptor_handle[k_max_upload_heaps];
	ID3D12Resource* upload_heaps[k_max_upload_heaps];
	c_graphics_d3d12& graphics;
	unsigned long shader_visible_descriptor_heap_index;
	unsigned long data_size;
	unsigned long array_count;
};
