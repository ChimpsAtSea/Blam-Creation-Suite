#include "graphicslib-private-pch.h"

c_graphics_buffer_d3d12::c_graphics_buffer_d3d12(
	c_graphics_d3d12& graphics,
	e_graphics_buffer_type buffer_type,
	uint32_t element_size,
	uint32_t element_count,
	const wchar_t* debug_name) :
	graphics(graphics),
	buffer_type(buffer_type),
	upload_heap(nullptr),
	readback_heap(nullptr),
	gpu_resource_state(),
	gpu_resource(nullptr),
	gpu_descriptor_handle(),
	shader_visible_descriptor_heap_index(ULONG_MAX),
	element_size(element_size),
	element_count(element_count),
	data_size(element_size* element_count)
{
	init_buffer(debug_name);
	init_descriptor_heap();
}

c_graphics_buffer_d3d12::~c_graphics_buffer_d3d12()
{
	deinit_descriptor_heap();
	deinit_buffer();
}

D3D12_GPU_DESCRIPTOR_HANDLE c_graphics_buffer_d3d12::get_gpu_descriptor_handle() const
{
	// #TODO: is caching this value more efficient and worth the memory cost?
	return graphics.cbv_srv_uav_descriptor_heap_allocator_gpu->get_gpu_descriptor_handle(shader_visible_descriptor_heap_index);
}

ID3D12Resource* c_graphics_buffer_d3d12::get_resource() const
{
	return gpu_resource;
}

uint32_t c_graphics_buffer_d3d12::get_data_size() const
{
	return data_size;
}

BCS_RESULT c_graphics_buffer_d3d12::write_data(const void* buffer, uint32_t buffer_size, uint32_t buffer_offset)
{
	if ((buffer_size + buffer_offset) > data_size)
	{
		return BCS_E_OUT_OF_RANGE;
	}

	void* gpu_buffer_data;
	CD3DX12_RANGE read_range(0, 0);	// We do not intend to read from this resource on the CPU.
	HRESULT map_result = upload_heap->Map(0, &read_range, &gpu_buffer_data);
	BCS_FAIL_RETURN(graphics.hresult_to_bcs_result(map_result));

	char* gpu_buffer_data_position = static_cast<char*>(gpu_buffer_data) + buffer_offset;
	memcpy(gpu_buffer_data_position, buffer, buffer_size);

	upload_heap->Unmap(0, nullptr);

	if (upload_heap != gpu_resource)
	{
		graphics.transition_resource(gpu_resource, gpu_resource_state, D3D12_RESOURCE_STATE_COPY_DEST);
		gpu_resource_state = D3D12_RESOURCE_STATE_COPY_DEST;

		graphics.command_list->CopyResource(gpu_resource, upload_heap);

		graphics.transition_resource(gpu_resource, gpu_resource_state, D3D12_RESOURCE_STATE_UNORDERED_ACCESS);
		gpu_resource_state = D3D12_RESOURCE_STATE_UNORDERED_ACCESS;
	}

	return BCS_S_OK;
}

BCS_RESULT c_graphics_buffer_d3d12::write_data(const void* buffer, uint32_t element_size, uint32_t element_count, uint32_t element_offset)
{
	return write_data(buffer, element_count * element_size, element_offset * element_size);
}

BCS_RESULT c_graphics_buffer_d3d12::read_data(void* buffer, uint32_t buffer_size, uint32_t buffer_offset)
{
	if (readback_heap == nullptr)
	{
		return BCS_E_UNSUPPORTED;
	}

	if ((buffer_size + buffer_offset) > data_size)
	{
		return BCS_E_OUT_OF_RANGE;
	}

	void* gpu_buffer_data;
	CD3DX12_RANGE read_range(0, 0);	// We do not intend to read from this resource on the CPU.
	HRESULT map_result = readback_heap->Map(0, &read_range, &gpu_buffer_data);
	BCS_FAIL_RETURN(graphics.hresult_to_bcs_result(map_result));

	char* gpu_buffer_data_position = static_cast<char*>(gpu_buffer_data) + buffer_offset;
	memcpy(buffer, gpu_buffer_data_position, buffer_size);

	readback_heap->Unmap(0, nullptr);

	return BCS_S_OK;
}

BCS_RESULT c_graphics_buffer_d3d12::read_data(void* buffer, uint32_t element_size, uint32_t element_count, uint32_t element_offset)
{
	return read_data(buffer, element_count * element_size, element_offset * element_size);
}

BCS_RESULT c_graphics_buffer_d3d12::map_data_read_begin(void*& gpu_buffer_data)
{
	if (readback_heap == nullptr)
	{
		return BCS_E_UNSUPPORTED;
	}

	CD3DX12_RANGE read_range(0, 0);	// We do not intend to read from this resource on the CPU.
	HRESULT map_result = readback_heap->Map(0, &read_range, &gpu_buffer_data);
	BCS_FAIL_RETURN(graphics.hresult_to_bcs_result(map_result));

	return BCS_S_OK;
}

BCS_RESULT c_graphics_buffer_d3d12::map_data_read_end(void* gpu_buffer_data)
{
	readback_heap->Unmap(0, nullptr);

	return BCS_S_OK;
}

BCS_RESULT c_graphics_buffer_d3d12::map_data_write_begin(void*& gpu_buffer_data)
{
	if (upload_heap == nullptr)
	{
		return BCS_E_UNSUPPORTED;
	}

	CD3DX12_RANGE read_range(0, 0);	// We do not intend to read from this resource on the CPU.
	HRESULT map_result = upload_heap->Map(0, &read_range, &gpu_buffer_data);
	BCS_FAIL_RETURN(graphics.hresult_to_bcs_result(map_result));

	return BCS_S_OK;
}

BCS_RESULT c_graphics_buffer_d3d12::map_data_write_end(void* gpu_buffer_data)
{
	BCS_VALIDATE_ARGUMENT(gpu_buffer_data);
	if (upload_heap == nullptr)
	{
		return BCS_E_UNSUPPORTED;
	}

	upload_heap->Unmap(0, nullptr);

	if (upload_heap != gpu_resource)
	{
		graphics.transition_resource(gpu_resource, gpu_resource_state, D3D12_RESOURCE_STATE_COPY_DEST);
		gpu_resource_state = D3D12_RESOURCE_STATE_COPY_DEST;

		graphics.command_list->CopyResource(gpu_resource, upload_heap);

		graphics.transition_resource(gpu_resource, gpu_resource_state, D3D12_RESOURCE_STATE_UNORDERED_ACCESS);
		gpu_resource_state = D3D12_RESOURCE_STATE_UNORDERED_ACCESS;
	}

	return BCS_S_OK;
}

void c_graphics_buffer_d3d12::copy_readback()
{
	if (readback_heap != gpu_resource)
	{
		graphics.transition_resource(gpu_resource, gpu_resource_state, D3D12_RESOURCE_STATE_COPY_SOURCE);
		gpu_resource_state = D3D12_RESOURCE_STATE_COPY_SOURCE;

		graphics.command_list->CopyResource(readback_heap, gpu_resource);

		graphics.transition_resource(gpu_resource, gpu_resource_state, D3D12_RESOURCE_STATE_UNORDERED_ACCESS);
		gpu_resource_state = D3D12_RESOURCE_STATE_UNORDERED_ACCESS;
	}
}

uint32_t c_graphics_buffer_d3d12::get_gpu_descriptor_heap_index() const
{
	return shader_visible_descriptor_heap_index;
}

void c_graphics_buffer_d3d12::init_buffer(const wchar_t* debug_name)
{
	switch (buffer_type)
	{
	case _graphics_buffer_type_generic:
	{
		CD3DX12_HEAP_PROPERTIES const gpu_resource_properties(D3D12_HEAP_TYPE_UPLOAD);
		CD3DX12_RESOURCE_DESC const gpu_resource_resource_description = CD3DX12_RESOURCE_DESC::Buffer(ALIGN(data_size, 256));
		HRESULT create_commited_resource_result = graphics.device->CreateCommittedResource(
			&gpu_resource_properties, // this heap will be used to upload the constant buffer data
			D3D12_HEAP_FLAG_NONE, // no flags
			&gpu_resource_resource_description, // size of the resource heap. Must be a multiple of 64KB for single-textures and constant buffers
			D3D12_RESOURCE_STATE_GENERIC_READ, // will be data that is read from so we keep it in the generic read state
			nullptr, // we do not have use an optimized clear value for constant buffers
			IID_PPV_ARGS(&gpu_resource));
		ASSERT(SUCCEEDED(create_commited_resource_result));
		c_graphics_d3d12::set_object_debug_name(debug_name, L"c_graphics_buffer_d3d12::gpu_resource [generic]", gpu_resource);

		gpu_resource_state = D3D12_RESOURCE_STATE_GENERIC_READ;
		upload_heap = gpu_resource;
		readback_heap = nullptr;

		gpu_resource = upload_heap; // same buffer can be used
	}
	break;
	case _graphics_buffer_type_unordered_access_view:
	{
		CD3DX12_HEAP_PROPERTIES const upload_heap_properties(D3D12_HEAP_TYPE_UPLOAD);
		CD3DX12_RESOURCE_DESC const upload_heap_resource_description = CD3DX12_RESOURCE_DESC::Buffer(ALIGN(data_size, 256));
		D3D12_RESOURCE_STATES upload_heap_resource_state = D3D12_RESOURCE_STATE_COMMON;
		upload_heap_resource_state = upload_heap_resource_state | D3D12_RESOURCE_STATE_GENERIC_READ;
		HRESULT create_upload_heap_result = graphics.device->CreateCommittedResource(
			&upload_heap_properties,
			D3D12_HEAP_FLAG_NONE,
			&upload_heap_resource_description,
			upload_heap_resource_state,
			nullptr,
			IID_PPV_ARGS(&upload_heap));
		ASSERT(SUCCEEDED(create_upload_heap_result));
		c_graphics_d3d12::set_object_debug_name(debug_name, L"c_graphics_buffer_d3d12::upload_heap [uav]", upload_heap);

		CD3DX12_HEAP_PROPERTIES const readback_heap_properties(D3D12_HEAP_TYPE_READBACK);
		CD3DX12_RESOURCE_DESC const readback_heap_resource_description = CD3DX12_RESOURCE_DESC::Buffer(ALIGN(data_size, 256));
		D3D12_RESOURCE_STATES readback_heap_resource_state = D3D12_RESOURCE_STATE_COMMON;
		readback_heap_resource_state = readback_heap_resource_state | D3D12_RESOURCE_STATE_COPY_DEST;
		HRESULT create_readback_heap_result = graphics.device->CreateCommittedResource(
			&readback_heap_properties,
			D3D12_HEAP_FLAG_NONE,
			&readback_heap_resource_description,
			readback_heap_resource_state,
			nullptr,
			IID_PPV_ARGS(&readback_heap));
		ASSERT(SUCCEEDED(create_readback_heap_result));
		c_graphics_d3d12::set_object_debug_name(debug_name, L"c_graphics_buffer_d3d12::readback_heap [uav]", readback_heap);

		CD3DX12_HEAP_PROPERTIES const default_heap_properties(D3D12_HEAP_TYPE_DEFAULT);

		gpu_resource_state = D3D12_RESOURCE_STATE_COMMON;

		CD3DX12_RESOURCE_DESC const uav_resource_resource_description = CD3DX12_RESOURCE_DESC::Buffer(ALIGN(data_size, 256), D3D12_RESOURCE_FLAG_ALLOW_UNORDERED_ACCESS);
		HRESULT create_comitted_resource_result = graphics.device->CreateCommittedResource(
			&default_heap_properties,
			D3D12_HEAP_FLAG_NONE,
			&uav_resource_resource_description,
			gpu_resource_state,
			nullptr,
			IID_PPV_ARGS(&gpu_resource));
		ASSERT(SUCCEEDED(create_comitted_resource_result));
		c_graphics_d3d12::set_object_debug_name(debug_name, L"c_graphics_buffer_d3d12::gpu_resource [uav]", gpu_resource);
	}
	break;
	}
}

void c_graphics_buffer_d3d12::deinit_buffer()
{
	switch (buffer_type)
	{
	case _graphics_buffer_type_generic:
	{
		UINT gpu_resource_reference_count = gpu_resource->Release();
		ASSERT(gpu_resource_reference_count == 0);
	}
	break;
	case _graphics_buffer_type_unordered_access_view:
	{
		UINT gpu_resource_reference_count = gpu_resource->Release();
		ASSERT(gpu_resource_reference_count == 0);

		UINT upload_heap_reference_count = upload_heap->Release();
		ASSERT(upload_heap_reference_count == 0);

		UINT readback_heap_reference_count = readback_heap->Release();
		ASSERT(readback_heap_reference_count == 0);
	}
	break;
	}
}

void c_graphics_buffer_d3d12::init_descriptor_heap()
{
	shader_visible_descriptor_heap_index = graphics.cbv_srv_uav_descriptor_heap_allocator_gpu->allocate();
	ASSERT(shader_visible_descriptor_heap_index != ULONG_MAX);
	D3D12_CPU_DESCRIPTOR_HANDLE cbv_srv_uav_cpu_descriptor_handle = graphics.cbv_srv_uav_descriptor_heap_allocator_gpu->get_cpu_descriptor_handle(shader_visible_descriptor_heap_index);

	switch (buffer_type)
	{
	case _graphics_buffer_type_generic:
	{
		D3D12_SHADER_RESOURCE_VIEW_DESC shader_resource_view_description = {};
		shader_resource_view_description.Format = DXGI_FORMAT_UNKNOWN; // #TODO: does this need to be exposed?
		shader_resource_view_description.ViewDimension = D3D12_SRV_DIMENSION_BUFFER;
		shader_resource_view_description.Buffer.FirstElement = 0;
		shader_resource_view_description.Buffer.NumElements = element_count;
		shader_resource_view_description.Buffer.StructureByteStride = element_size;
		shader_resource_view_description.Buffer.Flags = D3D12_BUFFER_SRV_FLAG_NONE;
		shader_resource_view_description.Shader4ComponentMapping = D3D12_DEFAULT_SHADER_4_COMPONENT_MAPPING;

		graphics.device->CreateShaderResourceView(gpu_resource, &shader_resource_view_description, cbv_srv_uav_cpu_descriptor_handle);
	}
	break;
	case _graphics_buffer_type_unordered_access_view:
	{
		D3D12_UNORDERED_ACCESS_VIEW_DESC unordered_access_view_description = {};
		unordered_access_view_description.Format = DXGI_FORMAT_UNKNOWN;
		unordered_access_view_description.ViewDimension = D3D12_UAV_DIMENSION_BUFFER;
		unordered_access_view_description.Buffer.FirstElement = 0;
		unordered_access_view_description.Buffer.NumElements = element_count;
		unordered_access_view_description.Buffer.StructureByteStride = element_size;
		unordered_access_view_description.Buffer.CounterOffsetInBytes = 0;
		unordered_access_view_description.Buffer.Flags = D3D12_BUFFER_UAV_FLAG_NONE;

		graphics.device->CreateUnorderedAccessView(gpu_resource, nullptr, &unordered_access_view_description, cbv_srv_uav_cpu_descriptor_handle);
	}
	break;
	}
}

void c_graphics_buffer_d3d12::deinit_descriptor_heap()
{
	graphics.cbv_srv_uav_descriptor_heap_allocator_gpu->deallocate(shader_visible_descriptor_heap_index);
}

BCS_RESULT graphics_d3d12_buffer_create(
	c_graphics_d3d12* graphics,
	e_graphics_buffer_type buffer_type,
	uint32_t element_size,
	uint32_t element_count,
	c_graphics_buffer_d3d12*& buffer,
	const char* debug_name)
{
	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		buffer = new() c_graphics_buffer_d3d12(
			*graphics,
			buffer_type,
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
	e_graphics_buffer_type buffer_type,
	uint32_t buffer_size,
	c_graphics_buffer_d3d12*& buffer,
	const char* debug_name)
{
	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		buffer = new() c_graphics_buffer_d3d12(
			*graphics,
			buffer_type,
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

BCS_RESULT graphics_d3d12_buffer_destroy(c_graphics_buffer_d3d12* buffer)
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
