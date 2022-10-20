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
		const wchar_t* debug_name);
	~c_descriptor_heap_allocator_d3d12();

	BCS_RESULT allocate_descriptor_handle_cpu(
		unsigned int& descriptor_handle_index,
		D3D12_CPU_DESCRIPTOR_HANDLE& cpu_descriptor_handle);
	BCS_RESULT allocate_descriptor_handle_gpu(
		unsigned int& descriptor_handle_index,
		D3D12_GPU_DESCRIPTOR_HANDLE& gpu_descriptor_handle);
	BCS_RESULT deallocate_descriptor_handle(unsigned int descriptor_handle_index);
};
