#pragma once
class c_texture_d3d12
{
public:
	c_texture_d3d12(c_graphics_d3d12* graphics, const char* texture_filepath);
	~c_texture_d3d12();

	D3D12_RESOURCE_DESC texture_resource_description;
	ID3D12Resource* texture_resource;
	ID3D12Resource* texture_upload_heap;
private:
	c_graphics_d3d12* graphics;
};

