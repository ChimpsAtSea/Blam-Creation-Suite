#pragma once

class c_graphics_d3d12;

class c_debug_geometry_pipeline_signature_d3d12 :
	public c_pipeline_signature_d3d12
{
public:
	c_debug_geometry_pipeline_signature_d3d12(c_graphics_d3d12& graphics, const wchar_t* name);

	virtual void init_root_signature(const wchar_t* name);
};