#include "graphicslib-private-pch.h"

c_graphics_unordered_access_view_buffer_d3d12::c_graphics_unordered_access_view_buffer_d3d12(
	c_graphics_d3d12& graphics, 
	unsigned long element_size, 
	unsigned long element_count, 
	const wchar_t* name) :
	gpu_descriptor_handle(),
	upload_heap(nullptr),
	uav_resource(nullptr),
	graphics(graphics),
	shader_visible_descriptor_heap_index(ULONG_MAX),
	element_size(element_size),
	element_count(element_count),
	data_size(element_size* element_count)
{
	init_unordered_access_view_buffer(name);
	init_descriptor_heap();
}

c_graphics_unordered_access_view_buffer_d3d12::~c_graphics_unordered_access_view_buffer_d3d12()
{
	deinit_descriptor_heap();
	deinit_unordered_access_view_buffer();
}

D3D12_GPU_DESCRIPTOR_HANDLE c_graphics_unordered_access_view_buffer_d3d12::get_gpu_descriptor_handle() const
{
	// #TODO: is caching this value more efficient and worth the memory cost?
	return graphics.cbv_srv_uav_descriptor_heap_allocator_gpu->get_gpu_descriptor_handle(shader_visible_descriptor_heap_index);
}

ID3D12Resource* c_graphics_unordered_access_view_buffer_d3d12::get_resource() const
{
	return uav_resource;
}

unsigned long c_graphics_unordered_access_view_buffer_d3d12::get_data_size() const
{
	return data_size;
}

unsigned long c_graphics_unordered_access_view_buffer_d3d12::get_gpu_descriptor_heap_index() const
{
	return shader_visible_descriptor_heap_index;
}
void c_graphics_unordered_access_view_buffer_d3d12::update_resource(void* data, size_t offset, size_t size)
{
	ASSERT(size <= data_size);
	ASSERT(size + offset <= data_size);

	// constant buffer
	void* constant_buffer_data;
	CD3DX12_RANGE read_range(0, 0);	// We do not intend to read from this resource on the CPU.
	HRESULT map_result = upload_heap->Map(0, &read_range, &constant_buffer_data);
	ASSERT(SUCCEEDED(map_result));

	if (SUCCEEDED(map_result))
	{
		memcpy(constant_buffer_data, data, size);
		upload_heap->Unmap(0, nullptr);
	}

	graphics.transition_resource(uav_resource, D3D12_RESOURCE_STATE_UNORDERED_ACCESS, D3D12_RESOURCE_STATE_COPY_DEST);

	graphics.command_list->CopyResource(uav_resource, upload_heap);

	graphics.transition_resource(uav_resource, D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_UNORDERED_ACCESS);
}

void c_graphics_unordered_access_view_buffer_d3d12::init_unordered_access_view_buffer(const wchar_t* name)
{
	CD3DX12_HEAP_PROPERTIES const upload_heap_properties(D3D12_HEAP_TYPE_UPLOAD);
	CD3DX12_RESOURCE_DESC const upload_heap_resource_description = CD3DX12_RESOURCE_DESC::Buffer(ALIGN(data_size, 256));
	HRESULT create_commited_resource_result = graphics.device->CreateCommittedResource(
		&upload_heap_properties, // this heap will be used to upload the constant buffer data
		D3D12_HEAP_FLAG_NONE, // no flags
		&upload_heap_resource_description, // size of the resource heap. Must be a multiple of 64KB for single-textures and constant buffers
		D3D12_RESOURCE_STATE_GENERIC_READ, // will be data that is read from so we keep it in the generic read state
		nullptr, // we do not have use an optimized clear value for constant buffers
		IID_PPV_ARGS(&upload_heap));
	ASSERT(SUCCEEDED(create_commited_resource_result));
	upload_heap->SetName(L"c_graphics_unordered_access_view_buffer_d3d12::upload_heap");

	CD3DX12_HEAP_PROPERTIES const default_heap_properties(D3D12_HEAP_TYPE_DEFAULT);
	CD3DX12_RESOURCE_DESC const uav_resource_resource_description = CD3DX12_RESOURCE_DESC::Buffer(ALIGN(data_size, 256), D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS);
	HRESULT create_comitted_resource_result = graphics.device->CreateCommittedResource(
		&default_heap_properties,
		D3D12_HEAP_FLAG_NONE,
		&uav_resource_resource_description,
		D3D12_RESOURCE_STATE_UNORDERED_ACCESS,
		nullptr,
		IID_PPV_ARGS(&uav_resource));
	ASSERT(SUCCEEDED(create_comitted_resource_result));
	//uav_resource->SetName(L"c_graphics_unordered_access_view_buffer_d3d12::uav_resource");
	uav_resource->SetName(name);
}

void c_graphics_unordered_access_view_buffer_d3d12::deinit_unordered_access_view_buffer()
{
	UINT upload_heap_reference_count = upload_heap->Release();
	ASSERT(upload_heap_reference_count == 0);
}

void c_graphics_unordered_access_view_buffer_d3d12::init_descriptor_heap()
{
	shader_visible_descriptor_heap_index = graphics.cbv_srv_uav_descriptor_heap_allocator_gpu->allocate();
	D3D12_CPU_DESCRIPTOR_HANDLE cbv_srv_uav_cpu_descriptor_handle = graphics.cbv_srv_uav_descriptor_heap_allocator_gpu->get_cpu_descriptor_handle(shader_visible_descriptor_heap_index);

	D3D12_UNORDERED_ACCESS_VIEW_DESC unordered_access_view_buffer_view_description = {};
	unordered_access_view_buffer_view_description.Format = DXGI_FORMAT_UNKNOWN;
	unordered_access_view_buffer_view_description.ViewDimension = D3D12_UAV_DIMENSION_BUFFER;
	unordered_access_view_buffer_view_description.Buffer.FirstElement = 0;
	unordered_access_view_buffer_view_description.Buffer.NumElements = element_count;
	unordered_access_view_buffer_view_description.Buffer.StructureByteStride = element_size;
	unordered_access_view_buffer_view_description.Buffer.CounterOffsetInBytes = 0;
	unordered_access_view_buffer_view_description.Buffer.Flags = D3D12_BUFFER_UAV_FLAG_NONE;

	graphics.device->CreateUnorderedAccessView(uav_resource, nullptr, &unordered_access_view_buffer_view_description, cbv_srv_uav_cpu_descriptor_handle);
}

void c_graphics_unordered_access_view_buffer_d3d12::deinit_descriptor_heap()
{
	graphics.cbv_srv_uav_descriptor_heap_allocator_gpu->deallocate(shader_visible_descriptor_heap_index);
}

BCS_RESULT graphics_d3d12_buffer_create(
	c_graphics_d3d12* graphics,
	unsigned long element_size,
	unsigned long element_count,
	c_graphics_unordered_access_view_buffer_d3d12*& buffer,
	const char* debug_name)
{
	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		buffer = new c_graphics_unordered_access_view_buffer_d3d12(
			*graphics,
			element_size,
			element_count,
			debug_name_wc
		);
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FATAL;
	}
	return BCS_S_OK;
}

BCS_RESULT graphics_d3d12_buffer_create(
	c_graphics_d3d12* graphics,
	unsigned long buffer_size,
	c_graphics_unordered_access_view_buffer_d3d12*& buffer,
	const char* debug_name)
{
	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		buffer = new c_graphics_unordered_access_view_buffer_d3d12(
			*graphics,
			1,
			buffer_size,
			debug_name_wc
		);
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}

BCS_RESULT graphics_d3d12_buffer_destroy(c_graphics_unordered_access_view_buffer_d3d12* buffer)
{
	try
	{
		delete buffer;
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FAIL;
	}
	return BCS_S_OK;
}
