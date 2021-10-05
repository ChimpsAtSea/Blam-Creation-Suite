#pragma once

class c_hlsl_shader_d3d12
{
public:
	c_hlsl_shader_d3d12() = delete;
	c_hlsl_shader_d3d12(const c_hlsl_shader_d3d12&) = delete;
	c_hlsl_shader_d3d12& operator=(const c_hlsl_shader_d3d12&) = delete;

#if 0
	c_hlsl_shader_d3d12(const wchar_t* filepath);
#endif
	c_hlsl_shader_d3d12(e_bcs_resource_type resource_type);
	~c_hlsl_shader_d3d12();

	void* shader_data;
	unsigned long shader_data_size;
};

