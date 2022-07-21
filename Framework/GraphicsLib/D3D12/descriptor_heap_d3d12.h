#pragma once

class c_constant_buffer_d3d12;

class c_descriptor_heap_d3d12
{
public:
	c_descriptor_heap_d3d12() = delete;
	c_descriptor_heap_d3d12(const c_descriptor_heap_d3d12&) = delete;
	c_descriptor_heap_d3d12& operator=(const c_descriptor_heap_d3d12&) = delete;

	c_descriptor_heap_d3d12(
		c_graphics_d3d12& graphics,
		D3D12_DESCRIPTOR_HEAP_TYPE type,
		D3D12_DESCRIPTOR_HEAP_FLAGS flags,
		UINT num_descriptors,
		const wchar_t* name);
	~c_descriptor_heap_d3d12();

	D3D12_CPU_DESCRIPTOR_HANDLE get_cpu_descriptor_handle(UINT index);
	D3D12_GPU_DESCRIPTOR_HANDLE get_gpu_descriptor_handle(UINT index);

	void init_srv(
		c_graphics_d3d12& graphics,
		ID3D12Resource* resource,
		DXGI_FORMAT format,
		uint32_t mip_levels,
		uint32_t descriptor_heap_index);
	//void init_sampler_feedback_uav(
	//	c_graphics_d3d12& graphics,
	//	uint32_t descriptor_heap_index,
	//	ID3D12Resource* texture_resource,
	//	ID3D12Resource* feedback_resource);
	//void init_tiled_texture_descriptor_heap(
	//	c_graphics_d3d12& graphics,
	//	c_tiled_texture_d3d12* tiled_texture,
	//	uint32_t texture_descriptor_heap_index,
	//	uint32_t residency_descriptor_heap_index,
	//	uint32_t feedback_descriptor_heap_index);


	c_graphics_d3d12& graphics;
	ID3D12DescriptorHeap* descriptor_heap;
	D3D12_DESCRIPTOR_HEAP_TYPE type;
	D3D12_DESCRIPTOR_HEAP_FLAGS flags;
	UINT descriptor_size;
	UINT num_descriptors;
	D3D12_CPU_DESCRIPTOR_HANDLE cpu_descriptor_handle;
	D3D12_GPU_DESCRIPTOR_HANDLE gpu_descriptor_handle;
};
