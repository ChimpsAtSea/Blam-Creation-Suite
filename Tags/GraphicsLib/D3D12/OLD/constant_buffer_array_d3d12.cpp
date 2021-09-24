#include "graphicslib-private-pch.h"

c_constant_buffer_array_d3d12::c_constant_buffer_array_d3d12(c_graphics_d3d12& graphics, unsigned long data_size, unsigned long array_count, const wchar_t* name) :
	//gpu_descriptor_handle(),
	upload_heaps(),
	graphics(graphics),
	shader_visible_descriptor_heap_index(ULONG_MAX),
	data_size(data_size),
	array_count(array_count)
{
	init_constant_buffer(name);
	init_descriptor_heap();
}

c_constant_buffer_array_d3d12::~c_constant_buffer_array_d3d12()
{
	deinit_constant_buffer();
	deinit_descriptor_heap();
}

D3D12_GPU_DESCRIPTOR_HANDLE c_constant_buffer_array_d3d12::get_gpu_descriptor_handle(unsigned long index) const
{
	// #TODO: is caching this value more efficient and worth the memory cost?
	return graphics.cbv_srv_uav_descriptor_heap_allocator_gpu->get_gpu_descriptor_handle(shader_visible_descriptor_heap_index + index);
}

ID3D12Resource* c_constant_buffer_array_d3d12::get_resource(unsigned long index) const
{
	ASSERT(index < array_count);
	return upload_heaps[index];
}

unsigned long c_constant_buffer_array_d3d12::get_data_size() const
{
	return data_size;
}

unsigned long c_constant_buffer_array_d3d12::get_array_count() const
{
	return array_count;
}

unsigned long c_constant_buffer_array_d3d12::get_gpu_descriptor_heap_index() const
{
	return shader_visible_descriptor_heap_index;
}

void c_constant_buffer_array_d3d12::update_resource(unsigned long index, void* data, size_t offset, size_t size)
{
	ASSERT(size <= data_size);
	ASSERT(size + offset <= data_size);

	// constant buffer
	ID3D12Resource* upload_heap = get_resource(index);

	void* constant_buffer_data;
	CD3DX12_RANGE read_range(0, 0);	// We do not intend to read from this resource on the CPU.
	HRESULT map_result = upload_heap->Map(0, &read_range, &constant_buffer_data);
	ASSERT(SUCCEEDED(map_result));

	if (SUCCEEDED(map_result))
	{
		memcpy(constant_buffer_data, data, size);
		upload_heap->Unmap(0, nullptr);
	}
}

void c_constant_buffer_array_d3d12::init_constant_buffer(const wchar_t* name)
{
	for (unsigned long upload_heap_index = 0; upload_heap_index < array_count; upload_heap_index++)
	{
		CD3DX12_HEAP_PROPERTIES const upload_heap_properties(D3D12_HEAP_TYPE_UPLOAD);
		CD3DX12_RESOURCE_DESC const resource_description = CD3DX12_RESOURCE_DESC::Buffer(ALIGN(data_size, 256));
		HRESULT create_commited_resource_result = graphics.device->CreateCommittedResource(
			&upload_heap_properties, // this heap will be used to upload the constant buffer data
			D3D12_HEAP_FLAG_NONE, // no flags
			&resource_description, // size of the resource heap. Must be a multiple of 64KB for single-textures and constant buffers
			D3D12_RESOURCE_STATE_GENERIC_READ, // will be data that is read from so we keep it in the generic read state
			nullptr, // we do not have use an optimized clear value for constant buffers
			IID_PPV_ARGS(&upload_heaps[upload_heap_index]));
		ASSERT(SUCCEEDED(create_commited_resource_result));
		upload_heaps[upload_heap_index]->SetName(name);
	}
}

void c_constant_buffer_array_d3d12::deinit_constant_buffer()
{
	for (unsigned long upload_heap_index = 0; upload_heap_index < array_count; upload_heap_index++)
	{
		ID3D12Resource* upload_heap = upload_heaps[upload_heap_index];
		UINT upload_heap_reference_count = upload_heap->Release();
		ASSERT(upload_heap_reference_count == 0);
	}
}

void c_constant_buffer_array_d3d12::init_descriptor_heap()
{
	shader_visible_descriptor_heap_index = graphics.cbv_srv_uav_descriptor_heap_allocator_gpu->allocate(array_count);

	for (unsigned long index = 0; index < array_count; index++)
	{
		D3D12_CPU_DESCRIPTOR_HANDLE cbv_srv_uav_cpu_descriptor_handle = graphics.cbv_srv_uav_descriptor_heap_allocator_gpu->get_cpu_descriptor_handle(shader_visible_descriptor_heap_index + index);

		D3D12_CONSTANT_BUFFER_VIEW_DESC constant_buffer_view_description = {};
		constant_buffer_view_description.BufferLocation = upload_heaps[index]->GetGPUVirtualAddress();
		constant_buffer_view_description.SizeInBytes = ALIGN(data_size, 256); // CB size is required to be 256-byte aligned.
		graphics.device->CreateConstantBufferView(&constant_buffer_view_description, cbv_srv_uav_cpu_descriptor_handle);
	}
}

void c_constant_buffer_array_d3d12::deinit_descriptor_heap()
{
	graphics.cbv_srv_uav_descriptor_heap_allocator_gpu->deallocate(shader_visible_descriptor_heap_index);
}