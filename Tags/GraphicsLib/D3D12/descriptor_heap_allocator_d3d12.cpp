#include "graphicslib-private-pch.h"

c_descriptor_heap_allocator_d3d12::c_descriptor_heap_allocator_d3d12(
	c_graphics_d3d12& graphics,
	D3D12_DESCRIPTOR_HEAP_TYPE type,
	D3D12_DESCRIPTOR_HEAP_FLAGS flags,
	UINT num_descriptors,
	const wchar_t* name) :
	c_bitfield_allocator(num_descriptors),
	c_descriptor_heap_d3d12(graphics, type, flags, num_descriptors, name)
{
}

c_descriptor_heap_allocator_d3d12::~c_descriptor_heap_allocator_d3d12()
{
}

D3D12_CPU_DESCRIPTOR_HANDLE c_descriptor_heap_allocator_d3d12::allocate_cpu_descriptor_handle()
{
	unsigned long index = allocate();
	return get_cpu_descriptor_handle(index);
}

D3D12_GPU_DESCRIPTOR_HANDLE c_descriptor_heap_allocator_d3d12::allocate_gpu_descriptor_handle()
{
	unsigned long index = allocate();
	return get_gpu_descriptor_handle(index);
}

void c_descriptor_heap_allocator_d3d12::deallocate_cpu_descriptor_handle(D3D12_CPU_DESCRIPTOR_HANDLE cpu_handle)
{
	SIZE_T index = (cpu_handle.ptr - cpu_descriptor_handle.ptr) / static_cast<SIZE_T>(descriptor_size);
	deallocate(static_cast<unsigned long>(index));
}

void c_descriptor_heap_allocator_d3d12::deallocate_gpu_descriptor_handle(D3D12_GPU_DESCRIPTOR_HANDLE gpu_handle)
{
	UINT64 index = (gpu_handle.ptr - gpu_descriptor_handle.ptr) / static_cast<UINT64>(descriptor_size);
	deallocate(static_cast<unsigned long>(index));
}
