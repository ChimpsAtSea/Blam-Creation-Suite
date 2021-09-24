#include "graphicslib-private-pch.h"

c_descriptor_heap_d3d12::c_descriptor_heap_d3d12(c_graphics_d3d12& graphics, D3D12_DESCRIPTOR_HEAP_TYPE type, D3D12_DESCRIPTOR_HEAP_FLAGS flags, UINT num_descriptors, const wchar_t* name) :
	graphics(graphics),
	descriptor_heap(nullptr),
	type(type),
	flags(flags),
	descriptor_size(graphics.descriptor_sizes[type]),
	num_descriptors(num_descriptors),
	cpu_descriptor_handle(),
	gpu_descriptor_handle()
{
	ASSERT(descriptor_size > 0);

	// Describe and create a render target view (RTV) descriptor heap.
	D3D12_DESCRIPTOR_HEAP_DESC render_target_view_heap_descriptor = {};
	render_target_view_heap_descriptor.NumDescriptors = num_descriptors;
	render_target_view_heap_descriptor.Type = type;
	render_target_view_heap_descriptor.Flags = flags;
	HRESULT create_desctiptor_heap_result = graphics.device->CreateDescriptorHeap(&render_target_view_heap_descriptor, IID_PPV_ARGS(&descriptor_heap));
	ASSERT(SUCCEEDED(create_desctiptor_heap_result));
	descriptor_heap->SetName(name);

	cpu_descriptor_handle = descriptor_heap->GetCPUDescriptorHandleForHeapStart();;
	gpu_descriptor_handle = descriptor_heap->GetGPUDescriptorHandleForHeapStart();;
}

c_descriptor_heap_d3d12::~c_descriptor_heap_d3d12()
{
	ULONG heap_reference_count = descriptor_heap->Release();
	ASSERT(heap_reference_count == 0);
}

D3D12_CPU_DESCRIPTOR_HANDLE c_descriptor_heap_d3d12::get_cpu_descriptor_handle(UINT index)
{
	return { cpu_descriptor_handle.ptr + static_cast<SIZE_T>(descriptor_size) * static_cast<SIZE_T>(index) };
}

D3D12_GPU_DESCRIPTOR_HANDLE c_descriptor_heap_d3d12::get_gpu_descriptor_handle(UINT index)
{
	return { gpu_descriptor_handle.ptr + static_cast<UINT64>(descriptor_size) * static_cast<UINT64>(index) };
}

void c_descriptor_heap_d3d12::init_srv(
	c_graphics_d3d12& graphics,
	ID3D12Resource* resource,
	DXGI_FORMAT format,
	unsigned long mip_levels,
	unsigned long descriptor_heap_index)
{
	D3D12_CPU_DESCRIPTOR_HANDLE cbv_srv_uav_cpu_descriptor_handle = get_cpu_descriptor_handle(descriptor_heap_index);

	// Describe and create a SRV for the texture.
	D3D12_SHADER_RESOURCE_VIEW_DESC shader_resource_view = {};
	shader_resource_view.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;
	shader_resource_view.Format = format;
	shader_resource_view.ViewDimension = D3D12_SRV_DIMENSION_TEXTURE2D;
	shader_resource_view.Texture2D.MipLevels = mip_levels;
	graphics.device->CreateShaderResourceView(resource, &shader_resource_view, cbv_srv_uav_cpu_descriptor_handle);
}

//void c_descriptor_heap_d3d12::init_sampler_feedback_uav(
//	c_graphics_d3d12& graphics,
//	unsigned long descriptor_heap_index,
//	ID3D12Resource* texture_resource,
//	ID3D12Resource* feedback_resource
//)
//{
//	D3D12_CPU_DESCRIPTOR_HANDLE cbv_srv_uav_cpu_descriptor_handle = get_cpu_descriptor_handle(descriptor_heap_index);
//
//	graphics.device->CreateSamplerFeedbackUnorderedAccessView(texture_resource, feedback_resource, cbv_srv_uav_cpu_descriptor_handle);
//}
//
//void c_descriptor_heap_d3d12::init_tiled_texture_descriptor_heap(
//	c_graphics_d3d12& graphics,
//	c_tiled_texture_d3d12* tiled_texture,
//	unsigned long texture_descriptor_heap_index,
//	unsigned long residency_descriptor_heap_index,
//	unsigned long feedback_descriptor_heap_index)
//{
//	init_srv(
//		graphics,
//		tiled_texture->texture_gpu,
//		tiled_texture->texture_resource_description.Format,
//		tiled_texture->texture_resource_description.MipLevels,
//		texture_descriptor_heap_index);
//	init_srv(
//		graphics,
//		tiled_texture->redisency_texture_gpu,
//		tiled_texture->residency_texture_resource_description.Format,
//		tiled_texture->residency_texture_resource_description.MipLevels,
//		residency_descriptor_heap_index);
//	init_sampler_feedback_uav(
//		graphics,
//		feedback_descriptor_heap_index,
//		tiled_texture->texture_gpu,
//		tiled_texture->feedback_texture_gpu
//	);
//}
