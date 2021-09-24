#include "graphicslib-private-pch.h"

c_pipeline_signature_d3d12::c_pipeline_signature_d3d12(c_graphics_d3d12& graphics, const wchar_t* name) :
	graphics(graphics)
{
	//init_root_signature(name);
}

c_pipeline_signature_d3d12::~c_pipeline_signature_d3d12()
{
	deinit_root_signature();
}

void c_pipeline_signature_d3d12::init_root_signature_impl(
	const wchar_t* name, 
	D3D12_ROOT_PARAMETER* root_parameters, 
	unsigned long root_parameters_count, 
	D3D12_STATIC_SAMPLER_DESC* samplers, 
	unsigned long samplers_count)
{
	CD3DX12_ROOT_SIGNATURE_DESC root_signature_description;
	root_signature_description.Init(static_cast<UINT>(root_parameters_count),
		root_parameters, // a pointer to the beginning of our root parameters array
		samplers_count,
		samplers,
		D3D12_ROOT_SIGNATURE_FLAG_ALLOW_INPUT_ASSEMBLER_INPUT_LAYOUT | // we can deny shader stages here for better performance
		D3D12_ROOT_SIGNATURE_FLAG_DENY_HULL_SHADER_ROOT_ACCESS |
		D3D12_ROOT_SIGNATURE_FLAG_DENY_DOMAIN_SHADER_ROOT_ACCESS |
		D3D12_ROOT_SIGNATURE_FLAG_DENY_GEOMETRY_SHADER_ROOT_ACCESS);

	ID3DBlob* root_signature_blob = nullptr;
	ID3DBlob* root_signature_error_blob = nullptr;
	HRESULT serialize_root_signature_result = D3D12SerializeRootSignature(&root_signature_description, D3D_ROOT_SIGNATURE_VERSION_1, &root_signature_blob, &root_signature_error_blob);
	if (root_signature_error_blob)
	{
		// #TODO: Handle the error
		printf("root_signature error> %s", static_cast<const char*>(root_signature_error_blob->GetBufferPointer()));
		root_signature_error_blob->Release();
	}
	ASSERT(SUCCEEDED(serialize_root_signature_result));
	HRESULT create_root_signature_result = graphics.device->CreateRootSignature(0, root_signature_blob->GetBufferPointer(), root_signature_blob->GetBufferSize(), IID_PPV_ARGS(&root_signature));
	ASSERT(SUCCEEDED(create_root_signature_result));
	root_signature_blob->Release();

	root_signature->SetName(name);
}

void c_pipeline_signature_d3d12::deinit_root_signature()
{
	ULONG root_signature_reference_count = root_signature->Release();
	ASSERT(root_signature_reference_count == 0);
}
