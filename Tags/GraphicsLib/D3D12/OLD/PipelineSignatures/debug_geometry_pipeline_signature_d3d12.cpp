#include "graphicslib-private-pch.h"

c_debug_geometry_pipeline_signature_d3d12::c_debug_geometry_pipeline_signature_d3d12(c_graphics_d3d12& graphics, const wchar_t* name) :
	c_pipeline_signature_d3d12(graphics, name)
{
	init_root_signature(name);
}

void c_debug_geometry_pipeline_signature_d3d12::init_root_signature(const wchar_t* name)
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
		D3D12_DESCRIPTOR_RANGE descriptor_table_uav = {};
		descriptor_table_uav.RangeType = D3D12_DESCRIPTOR_RANGE_TYPE_SRV;
		descriptor_table_uav.NumDescriptors = 1;
		descriptor_table_uav.BaseShaderRegister = 0;
		descriptor_table_uav.RegisterSpace = 0;
		descriptor_table_uav.OffsetInDescriptorsFromTableStart = 0;
		if (descriptor_table_uav.NumDescriptors > 0) instance_descriptor_ranges.push_back(descriptor_table_uav);
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

	init_root_signature_impl(name, root_parameters.data(), static_cast<unsigned long>(root_parameters.size()), nullptr, 0);
}
