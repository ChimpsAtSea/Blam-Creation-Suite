#include "graphicslib-private-pch.h"

c_texture_d3d12::c_texture_d3d12(c_graphics_d3d12* graphics, const char* texture_filepath) :
	texture_resource_description(),
	texture_resource(nullptr),
	texture_upload_heap(nullptr),
	graphics(graphics)
{
	int width = 0;
	int height = 0;
	int channels = 0;
	stbi_set_flip_vertically_on_load(true);
	unsigned char* image_data = stbi_load(texture_filepath, &width, &height, &channels, STBI_rgb_alpha);
	ASSERT(image_data != nullptr);

	// Describe and create a Texture2D.
	texture_resource_description.MipLevels = 1;
	texture_resource_description.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
	texture_resource_description.Width = width;
	texture_resource_description.Height = height;
	texture_resource_description.Flags = D3D12_RESOURCE_FLAG_NONE;
	texture_resource_description.DepthOrArraySize = 1;
	texture_resource_description.SampleDesc.Count = 1;
	texture_resource_description.SampleDesc.Quality = 0;
	texture_resource_description.Dimension = D3D12_RESOURCE_DIMENSION_TEXTURE2D;

	CD3DX12_HEAP_PROPERTIES const default_heap_properties(D3D12_HEAP_TYPE_DEFAULT);
	HRESULT create_comitted_resource_result = graphics->device->CreateCommittedResource(
		&default_heap_properties,
		D3D12_HEAP_FLAG_NONE,
		&texture_resource_description,
		D3D12_RESOURCE_STATE_COPY_DEST,
		nullptr,
		IID_PPV_ARGS(&texture_resource));
	ASSERT(SUCCEEDED(create_comitted_resource_result));
	texture_resource->SetName(L"c_texture_d3d12::texture_resource");

	const UINT64 texture_mip_data_size = GetRequiredIntermediateSize(texture_resource, 0, 1);

	// Create the GPU upload buffer.
	CD3DX12_HEAP_PROPERTIES const upload_heap_properties(D3D12_HEAP_TYPE_UPLOAD);
	CD3DX12_RESOURCE_DESC const resource_description = CD3DX12_RESOURCE_DESC::Buffer(texture_mip_data_size);
	HRESULT create_comitted_resource_result2 = graphics->device->CreateCommittedResource(
		&upload_heap_properties,
		D3D12_HEAP_FLAG_NONE,
		&resource_description,
		D3D12_RESOURCE_STATE_GENERIC_READ,
		nullptr,
		IID_PPV_ARGS(&texture_upload_heap));
	ASSERT(SUCCEEDED(create_comitted_resource_result2));
	texture_upload_heap->SetName(L"c_texture_d3d12::texture_upload_heap");

	// Copy data to the intermediate upload heap and then schedule a copy 
	// from the upload heap to the Texture2D.


	size_t total_bytes;
	size_t row_bytes;
	HRESULT get_surface_info_result = get_surface_info(width, height, DXGI_FORMAT_R8G8B8A8_UNORM, &total_bytes, &row_bytes, nullptr);
	ASSERT(SUCCEEDED(get_surface_info_result));

	{
		D3D12_SUBRESOURCE_DATA texture_data = {};
		texture_data.pData = image_data;
		texture_data.RowPitch = row_bytes;
		texture_data.SlicePitch = texture_data.RowPitch * height;
		UpdateSubresources(graphics->command_list, texture_resource, texture_upload_heap, 0, 0, 1, &texture_data);

		CD3DX12_RESOURCE_BARRIER const resource_barrier = CD3DX12_RESOURCE_BARRIER::Transition(texture_resource, D3D12_RESOURCE_STATE_COPY_DEST, D3D12_RESOURCE_STATE_PIXEL_SHADER_RESOURCE);
		graphics->command_list->ResourceBarrier(1, &resource_barrier);
	}
	
	stbi_image_free(image_data);
}

c_texture_d3d12::~c_texture_d3d12()
{
	UINT texture_resource_reference_count = texture_resource->Release();
	ASSERT(texture_resource_reference_count == 0);

	UINT texture_upload_heap_reference_count = texture_upload_heap->Release();
	ASSERT(texture_upload_heap_reference_count == 0);
}
