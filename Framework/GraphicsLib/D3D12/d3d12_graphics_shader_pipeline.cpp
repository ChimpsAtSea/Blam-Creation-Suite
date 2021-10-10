#include "graphicslib-private-pch.h"

c_graphics_shader_pipeline_d3d12::c_graphics_shader_pipeline_d3d12(
	c_graphics_d3d12& graphics,
	c_graphics_shader_binary_d3d12** shader_binaries,
	unsigned long num_shader_binaries,
	e_graphics_data_format* render_target_data_formats,
	unsigned long num_render_targets,
	e_graphics_data_format* depth_data_format,
	c_graphics_vertex_layout_d3d12& vertex_layout,
	const wchar_t* debug_name) :
	graphics(graphics),
	pipeline_state(),
	pipeline_state_description()
{
	BCS_VALIDATE_ARGUMENT_THROW(shader_binaries);
	BCS_VALIDATE_ARGUMENT_THROW(num_shader_binaries > 0);
	BCS_VALIDATE_ARGUMENT_THROW(num_render_targets <= 8);

	pipeline_state_description.pRootSignature = graphics.root_signature;
	pipeline_state_description.RasterizerState = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
	pipeline_state_description.BlendState = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
	pipeline_state_description.DepthStencilState = CD3DX12_DEPTH_STENCIL_DESC1(D3D12_DEFAULT);
	pipeline_state_description.DepthStencilState.DepthFunc = D3D12_COMPARISON_FUNC_GREATER_EQUAL;
	pipeline_state_description.SampleMask = UINT_MAX;
	pipeline_state_description.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
	pipeline_state_description.NumRenderTargets = num_render_targets;
	pipeline_state_description.SampleDesc.Count = 1;
	pipeline_state_description.RasterizerState.CullMode = D3D12_CULL_MODE_FRONT;

	for (unsigned long render_target_index = 0; render_target_index < num_render_targets; render_target_index++)
	{
		e_graphics_data_format graphics_data_format = render_target_data_formats[render_target_index];
		DXGI_FORMAT dxgi_format;
		
		BCS_FAIL_THROW(graphics_data_format_to_dxgi_format(graphics_data_format, dxgi_format));

		pipeline_state_description.RTVFormats[render_target_index] = dxgi_format;
	}
	DXGI_FORMAT depth_dxgi_format = DXGI_FORMAT_UNKNOWN;
	if (depth_data_format)
	{
		BCS_FAIL_THROW(graphics_data_format_to_dxgi_format(*depth_data_format, depth_dxgi_format));
	}
	pipeline_state_description.DSVFormat = depth_dxgi_format;

	pipeline_state_description.InputLayout.pInputElementDescs = vertex_layout.vertex_layout_descriptions;
	pipeline_state_description.InputLayout.NumElements = vertex_layout.num_layout_descriptions;

	// #TODO: detect the correct types of shader binaries
	pipeline_state_description.VS.pShaderBytecode = shader_binaries[0]->shader_binary_data;
	pipeline_state_description.VS.BytecodeLength = shader_binaries[0]->shader_binary_data_size;

	if (num_shader_binaries > 1) // #TODO: detect the correct types of shader binaries
	{
		pipeline_state_description.PS.pShaderBytecode = shader_binaries[1]->shader_binary_data;
		pipeline_state_description.PS.BytecodeLength = shader_binaries[1]->shader_binary_data_size;
	}

	HRESULT create_graphics_pipeline_state_result = graphics.device->CreateGraphicsPipelineState(&pipeline_state_description, IID_PPV_ARGS(&pipeline_state));
	if (FAILED(create_graphics_pipeline_state_result))
	{
		throw BCS_E_FAIL;
	}
	pipeline_state->SetName(debug_name ? debug_name : L"c_graphics_shader_pipeline_d3d12::pipeline_state");

	debug_point;
}

c_graphics_shader_pipeline_d3d12::~c_graphics_shader_pipeline_d3d12()
{

}

void c_graphics_shader_pipeline_d3d12::bind()
{
	graphics.command_list->SetPipelineState(pipeline_state);
}

BCS_RESULT graphics_d3d12_shader_pipeline_create(
	c_graphics_d3d12* graphics,
	c_graphics_shader_binary_d3d12** shader_binaries,
	unsigned long num_shader_binaries,
	e_graphics_data_format* render_target_data_formats,
	unsigned long num_render_targets,
	e_graphics_data_format* depth_data_format,
	c_graphics_vertex_layout_d3d12* vertex_layout,
	c_graphics_shader_pipeline_d3d12*& shader_pipeline,
	const char* debug_name)
{
	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		shader_pipeline = new c_graphics_shader_pipeline_d3d12(
			*graphics,
			shader_binaries,
			num_shader_binaries,
			render_target_data_formats,
			num_render_targets,
			depth_data_format,
			*vertex_layout,
			debug_name_wc);
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

BCS_RESULT graphics_d3d12_shader_pipeline_destroy(c_graphics_shader_pipeline_d3d12* shader_pipeline)
{
	try
	{
		delete shader_pipeline;
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
