#include "graphicslib-private-pch.h"

c_default_pipeline_signature_d3d12::c_default_pipeline_signature_d3d12(c_graphics_d3d12& graphics, const wchar_t* name) :
	c_pipeline_signature_d3d12(graphics, name)
{
	init_root_signature(name);
}

void c_default_pipeline_signature_d3d12::init_root_signature(const wchar_t* name)
{
	// global descriptors
	std::vector<D3D12_DESCRIPTOR_RANGE> camera_descriptor_ranges;
	{
		D3D12_DESCRIPTOR_RANGE descriptor_table_cbv = {};
		descriptor_table_cbv.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
		descriptor_table_cbv.NumDescriptors = 1;
		descriptor_table_cbv.BaseShaderRegister = 0;
		descriptor_table_cbv.RegisterSpace = 0;
		descriptor_table_cbv.OffsetInDescriptorsFromTableStart = 0;
		if (descriptor_table_cbv.NumDescriptors > 0) camera_descriptor_ranges.push_back(descriptor_table_cbv);
	}

	// transform descriptors
	std::vector<D3D12_DESCRIPTOR_RANGE> instance_descriptor_ranges;
	{
		//D3D12_DESCRIPTOR_RANGE descriptor_table_cbv = {};
		//descriptor_table_cbv.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_CBV;
		//descriptor_table_cbv.NumDescriptors = 1;
		//descriptor_table_cbv.BaseShaderRegister = 1;
		//descriptor_table_cbv.RegisterSpace = 0;
		//descriptor_table_cbv.OffsetInDescriptorsFromTableStart = 0;
		//if (descriptor_table_cbv.NumDescriptors > 0) instance_descriptor_ranges.push_back(descriptor_table_cbv);

		D3D12_DESCRIPTOR_RANGE descriptor_table_uav = {};
		descriptor_table_uav.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
		descriptor_table_uav.NumDescriptors = 1;
		descriptor_table_uav.BaseShaderRegister = 0;
		descriptor_table_uav.RegisterSpace = 0;
		descriptor_table_uav.OffsetInDescriptorsFromTableStart = 0;
		if (descriptor_table_uav.NumDescriptors > 0) instance_descriptor_ranges.push_back(descriptor_table_uav);
		//if (descriptor_table_uav.NumDescriptors > 0) ambient_occlusion_tiled_texture_descriptor_ranges.push_back(descriptor_table_uav);
	}

	// albedo tiled texture
	std::vector<D3D12_DESCRIPTOR_RANGE> albedo_tiled_texture_descriptor_ranges;
	{
		D3D12_DESCRIPTOR_RANGE descriptor_table_srv = {};
		descriptor_table_srv.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
		descriptor_table_srv.NumDescriptors = 2;
		descriptor_table_srv.BaseShaderRegister = 0;
		descriptor_table_srv.RegisterSpace = 1;
		descriptor_table_srv.OffsetInDescriptorsFromTableStart = 0;
		if (descriptor_table_srv.NumDescriptors > 0) albedo_tiled_texture_descriptor_ranges.push_back(descriptor_table_srv);

		D3D12_DESCRIPTOR_RANGE descriptor_table_uav = {};
		descriptor_table_uav.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
		descriptor_table_uav.NumDescriptors = 1;
		descriptor_table_uav.BaseShaderRegister = 0;
		descriptor_table_uav.RegisterSpace = 1;
		descriptor_table_uav.OffsetInDescriptorsFromTableStart = 2;
		if (descriptor_table_uav.NumDescriptors > 0) albedo_tiled_texture_descriptor_ranges.push_back(descriptor_table_uav);
	}

	// ambient occlusion tiled texture
	std::vector<D3D12_DESCRIPTOR_RANGE> ambient_occlusion_tiled_texture_descriptor_ranges;
	{
		D3D12_DESCRIPTOR_RANGE descriptor_table_srv = {};
		descriptor_table_srv.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
		descriptor_table_srv.NumDescriptors = 2;
		descriptor_table_srv.BaseShaderRegister = 2;
		descriptor_table_srv.RegisterSpace = 1;
		descriptor_table_srv.OffsetInDescriptorsFromTableStart = 0;
		if (descriptor_table_srv.NumDescriptors > 0) ambient_occlusion_tiled_texture_descriptor_ranges.push_back(descriptor_table_srv);

		D3D12_DESCRIPTOR_RANGE descriptor_table_uav = {};
		descriptor_table_uav.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_UAV;
		descriptor_table_uav.NumDescriptors = 1;
		descriptor_table_uav.BaseShaderRegister = 1;
		descriptor_table_uav.RegisterSpace = 1;
		descriptor_table_uav.OffsetInDescriptorsFromTableStart = 2;
		if (descriptor_table_uav.NumDescriptors > 0) ambient_occlusion_tiled_texture_descriptor_ranges.push_back(descriptor_table_uav);
	}

	std::vector<D3D12_DESCRIPTOR_RANGE> sampler_descriptor_ranges;
	{
		D3D12_DESCRIPTOR_RANGE descriptor_table_sampler{};
		descriptor_table_sampler.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SAMPLER; // this is a range of constant buffer views (descriptors)
		descriptor_table_sampler.NumDescriptors = 0; // we only have one constant buffer, so the range is only 1
		descriptor_table_sampler.BaseShaderRegister = 0; // start index of the shader registers in the range
		descriptor_table_sampler.RegisterSpace = 0; // space 0. can usually be zero
		descriptor_table_sampler.OffsetInDescriptorsFromTableStart = 0; // this appends the range to the end of the root signature descriptor tables

		if (descriptor_table_sampler.NumDescriptors > 0) sampler_descriptor_ranges.push_back(descriptor_table_sampler);
	}

	// create a descriptor table
	std::vector<D3D12_ROOT_DESCRIPTOR_TABLE> descriptor_table;
	if (!camera_descriptor_ranges.empty())
	{
		D3D12_ROOT_DESCRIPTOR_TABLE srv_uav_cbv_descriptor_table{};
		srv_uav_cbv_descriptor_table.NumDescriptorRanges = static_cast<UINT>(camera_descriptor_ranges.size());
		srv_uav_cbv_descriptor_table.pDescriptorRanges = camera_descriptor_ranges.data(); // the pointer to the beginning of our ranges array

		descriptor_table.push_back(srv_uav_cbv_descriptor_table);
	}
	if (!instance_descriptor_ranges.empty())
	{
		D3D12_ROOT_DESCRIPTOR_TABLE srv_uav_cbv_descriptor_table{};
		srv_uav_cbv_descriptor_table.NumDescriptorRanges = static_cast<UINT>(instance_descriptor_ranges.size());
		srv_uav_cbv_descriptor_table.pDescriptorRanges = instance_descriptor_ranges.data(); // the pointer to the beginning of our ranges array

		descriptor_table.push_back(srv_uav_cbv_descriptor_table);
	}
	if (!albedo_tiled_texture_descriptor_ranges.empty())
	{
		D3D12_ROOT_DESCRIPTOR_TABLE srv_uav_cbv_descriptor_table{};
		srv_uav_cbv_descriptor_table.NumDescriptorRanges = static_cast<UINT>(albedo_tiled_texture_descriptor_ranges.size());
		srv_uav_cbv_descriptor_table.pDescriptorRanges = albedo_tiled_texture_descriptor_ranges.data(); // the pointer to the beginning of our ranges array

		descriptor_table.push_back(srv_uav_cbv_descriptor_table);
	}
	if (!ambient_occlusion_tiled_texture_descriptor_ranges.empty())
	{
		D3D12_ROOT_DESCRIPTOR_TABLE srv_uav_cbv_descriptor_table{};
		srv_uav_cbv_descriptor_table.NumDescriptorRanges = static_cast<UINT>(ambient_occlusion_tiled_texture_descriptor_ranges.size());
		srv_uav_cbv_descriptor_table.pDescriptorRanges = ambient_occlusion_tiled_texture_descriptor_ranges.data(); // the pointer to the beginning of our ranges array

		descriptor_table.push_back(srv_uav_cbv_descriptor_table);
	}
	if (!sampler_descriptor_ranges.empty())
	{
		D3D12_ROOT_DESCRIPTOR_TABLE sampler_descriptor_table{};
		sampler_descriptor_table.NumDescriptorRanges = static_cast<UINT>(sampler_descriptor_ranges.size());
		sampler_descriptor_table.pDescriptorRanges = sampler_descriptor_ranges.data(); // the pointer to the beginning of our ranges array

		descriptor_table.push_back(sampler_descriptor_table);
	}

	// create a root parameter and fill it out
	std::vector<D3D12_ROOT_PARAMETER> root_parameters;
	for (const D3D12_ROOT_DESCRIPTOR_TABLE& root_descriptor_table : descriptor_table)
	{
		D3D12_ROOT_PARAMETER root_parameter{};
		root_parameter.ParameterType = D3D12_ROOT_PARAMETER_TYPE_DESCRIPTOR_TABLE; // this is a descriptor table
		root_parameter.DescriptorTable = root_descriptor_table; // this is our descriptor table for this root parameter
		root_parameter.ShaderVisibility = D3D12_SHADER_VISIBILITY_ALL; // our pixel shader will be the only shader accessing this parameter for now

		root_parameters.push_back(root_parameter);
	}

	D3D12_STATIC_SAMPLER_DESC samplers[3]{};
	{
		D3D12_STATIC_SAMPLER_DESC& texture_sampler = samplers[0];
		texture_sampler.Filter = D3D12_FILTER_ANISOTROPIC;
		texture_sampler.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
		texture_sampler.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
		texture_sampler.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
		texture_sampler.MipLODBias = 0;
		texture_sampler.MaxAnisotropy = 16;
		texture_sampler.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
		texture_sampler.BorderColor = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;
		texture_sampler.MinLOD = 0.0f;
		texture_sampler.MaxLOD = D3D12_FLOAT32_MAX;
		texture_sampler.ShaderRegister = 0;
		texture_sampler.RegisterSpace = 0;
		texture_sampler.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;
	}
	{
		D3D12_STATIC_SAMPLER_DESC& texture_sampler = samplers[1];
		texture_sampler.Filter = D3D12_FILTER_ANISOTROPIC;
		texture_sampler.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
		texture_sampler.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
		texture_sampler.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
		texture_sampler.MipLODBias = 0;
		texture_sampler.MaxAnisotropy = 16;
		texture_sampler.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
		texture_sampler.BorderColor = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;
		texture_sampler.MinLOD = 0.0f;
		texture_sampler.MaxLOD = D3D12_FLOAT32_MAX;
		texture_sampler.ShaderRegister = 1;
		texture_sampler.RegisterSpace = 0;
		texture_sampler.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;
	}
	{
		D3D12_STATIC_SAMPLER_DESC& residency_texture_sampler = samplers[2];
		residency_texture_sampler.Filter = D3D12_FILTER_MIN_MAG_MIP_LINEAR;
		residency_texture_sampler.AddressU = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
		residency_texture_sampler.AddressV = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
		residency_texture_sampler.AddressW = D3D12_TEXTURE_ADDRESS_MODE_WRAP;
		residency_texture_sampler.MipLODBias = 0;
		residency_texture_sampler.MaxAnisotropy = 16;
		residency_texture_sampler.ComparisonFunc = D3D12_COMPARISON_FUNC_NEVER;
		residency_texture_sampler.BorderColor = D3D12_STATIC_BORDER_COLOR_TRANSPARENT_BLACK;
		residency_texture_sampler.MinLOD = 0.0f;
		residency_texture_sampler.MaxLOD = D3D12_FLOAT32_MAX;
		residency_texture_sampler.ShaderRegister = 2;
		residency_texture_sampler.RegisterSpace = 0;
		residency_texture_sampler.ShaderVisibility = D3D12_SHADER_VISIBILITY_PIXEL;
	}

	init_root_signature_impl(name, root_parameters.data(), static_cast<unsigned long>(root_parameters.size()), samplers, _countof(samplers));
}
