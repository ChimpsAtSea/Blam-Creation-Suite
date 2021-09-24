#pragma once

class c_descriptor_heap_allocator_d3d12 :
	public c_bitfield_allocator,
	public c_descriptor_heap_d3d12
{
public:
	c_descriptor_heap_allocator_d3d12() = delete;
	c_descriptor_heap_allocator_d3d12(const c_descriptor_heap_allocator_d3d12&) = delete;
	c_descriptor_heap_allocator_d3d12& operator=(const c_descriptor_heap_allocator_d3d12&) = delete;

	c_descriptor_heap_allocator_d3d12(
		c_graphics_d3d12& graphics,
		D3D12_DESCRIPTOR_HEAP_TYPE type,
		D3D12_DESCRIPTOR_HEAP_FLAGS flags,
		UINT num_descriptors,
		const wchar_t* name);
	~c_descriptor_heap_allocator_d3d12();

	D3D12_CPU_DESCRIPTOR_HANDLE allocate_cpu_descriptor_handle();
	D3D12_GPU_DESCRIPTOR_HANDLE allocate_gpu_descriptor_handle();

	void deallocate_cpu_descriptor_handle(D3D12_CPU_DESCRIPTOR_HANDLE handle);
	void deallocate_gpu_descriptor_handle(D3D12_GPU_DESCRIPTOR_HANDLE handle);
};
