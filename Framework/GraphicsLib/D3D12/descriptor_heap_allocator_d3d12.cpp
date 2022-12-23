#include "graphicslib-private-pch.h"

c_descriptor_heap_allocator_d3d12::c_descriptor_heap_allocator_d3d12(
	c_graphics_d3d12& graphics,
	D3D12_DESCRIPTOR_HEAP_TYPE type,
	D3D12_DESCRIPTOR_HEAP_FLAGS flags,
	UINT num_descriptors,
	const wchar_t* debug_name) :
	c_bitfield_allocator(num_descriptors),
	c_descriptor_heap_d3d12(graphics, type, flags, num_descriptors, debug_name)
{
}

c_descriptor_heap_allocator_d3d12::~c_descriptor_heap_allocator_d3d12()
{
}

BCS_RESULT c_descriptor_heap_allocator_d3d12::allocate_descriptor_handle_gpu(
	unsigned int& descriptor_handle_index,
	D3D12_GPU_DESCRIPTOR_HANDLE& gpu_descriptor_handle)
{
	descriptor_handle_index = allocate();
	gpu_descriptor_handle = get_gpu_descriptor_handle(descriptor_handle_index);
	return BCS_S_OK; // #TODO: Error handling
}

BCS_RESULT c_descriptor_heap_allocator_d3d12::allocate_descriptor_handle_cpu(
	unsigned int& descriptor_handle_index,
	D3D12_CPU_DESCRIPTOR_HANDLE& cpu_descriptor_handle)
{
	descriptor_handle_index = allocate();
	cpu_descriptor_handle = get_cpu_descriptor_handle(descriptor_handle_index);
	return BCS_S_OK; // #TODO: Error handling
}

BCS_RESULT c_descriptor_heap_allocator_d3d12::deallocate_descriptor_handle(unsigned int descriptor_handle_index)
{
	deallocate(descriptor_handle_index);
	return BCS_S_OK; // #TODO: Error handling
}
