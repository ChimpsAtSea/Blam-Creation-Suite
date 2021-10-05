#include "graphicslib-private-pch.h"

#if 0
c_hlsl_shader_d3d12::c_hlsl_shader_d3d12(const wchar_t* filepath) :
	shader_data(nullptr),
	shader_data_size()
{
	filesystem_read_file_to_memory(filepath, &shader_data, &shader_data_size);
	ASSERT(shader_data != nullptr);
	ASSERT(shader_data_size > 0);
}
#endif

c_hlsl_shader_d3d12::c_hlsl_shader_d3d12(e_bcs_resource_type resource_type) :
	shader_data(nullptr),
	shader_data_size()
{
	BCS_RESULT rs = BCS_S_OK;
	if (BCS_FAILED(rs = resources_read_resource_to_memory(resource_type, shader_data, shader_data_size)))
	{
		throw rs;
	}
}

c_hlsl_shader_d3d12::~c_hlsl_shader_d3d12()
{
	delete shader_data;
}
