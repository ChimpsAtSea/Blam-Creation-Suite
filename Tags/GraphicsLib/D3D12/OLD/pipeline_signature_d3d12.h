#pragma once
class c_pipeline_signature_d3d12
{
public:
	c_pipeline_signature_d3d12(c_graphics_d3d12& graphics, const wchar_t* name);
	~c_pipeline_signature_d3d12();

	virtual void init_root_signature(const wchar_t* name) = 0;
	void init_root_signature_impl(
		const wchar_t* name,
		D3D12_ROOT_PARAMETER* root_parameters,
		unsigned long root_parameters_count,
		D3D12_STATIC_SAMPLER_DESC* samplers,
		unsigned long samplers_count);
	void deinit_root_signature();

	ID3D12RootSignature* root_signature;
private:
	c_graphics_d3d12& graphics;
};