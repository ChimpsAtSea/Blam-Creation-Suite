#include "graphicslib-private-pch.h"

using namespace DirectX;

c_geometry_pipeline_d3d12::c_geometry_pipeline_d3d12(
	c_graphics_d3d12& graphics,
	c_pipeline_signature_d3d12& pipeline_signature,
	c_hlsl_shader_d3d12* pixel_shader) :
	depth_only_pipeline_state(),
	pipeline_states(),
	pixel_shader(pixel_shader),
	graphics(graphics),
	pipeline_signature(pipeline_signature)
{
	init_pipeline_state();
}

c_geometry_pipeline_d3d12::~c_geometry_pipeline_d3d12()
{
	deinit_pipeline_state();
}

void c_geometry_pipeline_d3d12::init_pipeline_state(e_pipeline_mode pipeline_mode, e_vertex_layout_type vertex_layout)
{
	D3D12_GRAPHICS_PIPELINE_STATE_DESC pipeline_state_description = {};
	pipeline_state_description.pRootSignature = pipeline_signature.root_signature;
	pipeline_state_description.RasterizerState = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
	pipeline_state_description.BlendState = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
	pipeline_state_description.DepthStencilState = CD3DX12_DEPTH_STENCIL_DESC1(D3D12_DEFAULT);
	pipeline_state_description.DepthStencilState.DepthFunc = D3D12_COMPARISON_FUNC_GREATER_EQUAL;
	pipeline_state_description.SampleMask = UINT_MAX;
	pipeline_state_description.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
	pipeline_state_description.NumRenderTargets = 1;
	pipeline_state_description.RTVFormats[0] = DXGI_FORMAT_R8G8B8A8_UNORM;
	pipeline_state_description.DSVFormat = DXGI_FORMAT_D32_FLOAT;
	pipeline_state_description.SampleDesc.Count = 1;

	s_graphics_vertex_layout_description& vertex_layout_description = vertex_layout_descriptions[vertex_layout];

	pipeline_state_description.InputLayout.pInputElementDescs = vertex_layout_description.input_element_descriptions;
	pipeline_state_description.InputLayout.NumElements = vertex_layout_description.input_element_description_count;

	// #TODO: setup global vertex shaders
	pipeline_state_description.VS.pShaderBytecode = graphics.vertex_shaders[vertex_layout]->shader_data;
	pipeline_state_description.VS.BytecodeLength = graphics.vertex_shaders[vertex_layout]->shader_data_size;

	s_pipeline_mode_description& pipeline_mode_description = *pipeline_modes[pipeline_mode];

	switch (pipeline_mode)
	{
	case _pipeline_mode_depth_only:
	case _pipeline_mode_opaque:
		pipeline_state_description.RasterizerState.CullMode = D3D12_CULL_MODE_FRONT;
		break;
	case _pipeline_mode_wireframe_line:
		pipeline_state_description.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_LINE;
		pipeline_state_description.IBStripCutValue = D3D12_INDEX_BUFFER_STRIP_CUT_VALUE_0xFFFF;
	case _pipeline_mode_wireframe:
		pipeline_state_description.RasterizerState.FillMode = D3D12_FILL_MODE_WIREFRAME;
		pipeline_state_description.RasterizerState.CullMode = D3D12_CULL_MODE_NONE;
		break;
	case _pipeline_mode_alpha_blend_backface:
		pipeline_state_description.RasterizerState.CullMode = D3D12_CULL_MODE_FRONT;
	case _pipeline_mode_alpha_blend_frontface:
		pipeline_state_description.BlendState.RenderTarget[0].BlendEnable = TRUE;
		pipeline_state_description.BlendState.RenderTarget[0].SrcBlend = D3D12_BLEND_SRC_ALPHA;
		pipeline_state_description.BlendState.RenderTarget[0].DestBlend = D3D12_BLEND_INV_SRC_ALPHA;
		pipeline_state_description.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ZERO;
		break;
	case _pipeline_mode_additive:
		pipeline_state_description.BlendState.RenderTarget[0].BlendEnable = TRUE;
		pipeline_state_description.BlendState.RenderTarget[0].SrcBlend = D3D12_BLEND_ONE;
		pipeline_state_description.BlendState.RenderTarget[0].DestBlend = D3D12_BLEND_ONE;
		pipeline_state_description.DepthStencilState.DepthWriteMask = D3D12_DEPTH_WRITE_MASK_ZERO;
		break;
	}

	if (pipeline_mode == _pipeline_mode_depth_only)
	{
		ASSERT(vertex_layout == _vertex_layout_type_p);
		HRESULT create_graphics_pipeline_state_result = graphics.device->CreateGraphicsPipelineState(&pipeline_state_description, IID_PPV_ARGS(&depth_only_pipeline_state));
		ASSERT(SUCCEEDED(create_graphics_pipeline_state_result));
		depth_only_pipeline_state->SetName(L"depth_only_pipeline_state");
	}
	else
	{
		if (pixel_shader)
		{
			pipeline_state_description.PS.pShaderBytecode = pixel_shader->shader_data;
			pipeline_state_description.PS.BytecodeLength = pixel_shader->shader_data_size;
		}
		ID3D12PipelineState* pipeline_state = nullptr;
		HRESULT create_graphics_pipeline_state_result = graphics.device->CreateGraphicsPipelineState(&pipeline_state_description, IID_PPV_ARGS(&pipeline_state));
		ASSERT(SUCCEEDED(create_graphics_pipeline_state_result));
		pipeline_states[vertex_layout][pipeline_mode] = pipeline_state;

		const char* pipeline_mode_name = pipeline_mode_to_string(pipeline_mode);
		const char* vertex_layout_name = vertex_layout_type_to_string(vertex_layout);
		wchar_t pipeline_state_name[512] = {};
		_snwprintf(pipeline_state_name, _countof(pipeline_state_name), L"%S | %S", pipeline_mode_name, vertex_layout_name);
		pipeline_state->SetName(pipeline_state_name);
	}
}

void c_geometry_pipeline_d3d12::init_pipeline_state()
{
	if (pixel_shader)
	{
		for (unsigned long vertex_layout_index = 0; vertex_layout_index < k_number_of_vertex_layout_types; vertex_layout_index++)
		{
			for (unsigned long pipeline_modes_index = 0; pipeline_modes_index < k_number_of_pipeline_modes; pipeline_modes_index++)
			{
				init_pipeline_state(static_cast<e_pipeline_mode>(pipeline_modes_index), static_cast<e_vertex_layout_type>(vertex_layout_index));
			}
		}
	}
	init_pipeline_state(_pipeline_mode_depth_only, _vertex_layout_type_p);
}

void c_geometry_pipeline_d3d12::deinit_pipeline_state(e_pipeline_mode pipeline_mode, e_vertex_layout_type vertex_layout)
{
	ULONG pipeline_state_reference_count;
	if (pipeline_mode == _pipeline_mode_depth_only)
	{
		ASSERT(vertex_layout == _vertex_layout_type_p);
		pipeline_state_reference_count = depth_only_pipeline_state->Release();
	}
	else
	{
		pipeline_state_reference_count = pipeline_states[vertex_layout][pipeline_mode]->Release();
	}
	ASSERT(pipeline_state_reference_count == 0);
}

void c_geometry_pipeline_d3d12::deinit_pipeline_state()
{
	if (pixel_shader)
	{
		for (unsigned long vertex_layout_index = 0; vertex_layout_index < k_number_of_vertex_layout_types; vertex_layout_index++)
		{
			for (unsigned long pipeline_modes_index = 0; pipeline_modes_index < k_number_of_pipeline_modes; pipeline_modes_index++)
			{
				init_pipeline_state(static_cast<e_pipeline_mode>(pipeline_modes_index), static_cast<e_vertex_layout_type>(vertex_layout_index));
			}
		}
	}
	init_pipeline_state(_pipeline_mode_depth_only, _vertex_layout_type_p);
}

ID3D12PipelineState* c_geometry_pipeline_d3d12::get_pipeline_state(e_pipeline_mode pipeline_mode, e_vertex_layout_type vertex_layout) const
{
	if (pipeline_mode == _pipeline_mode_depth_only)
	{
		ASSERT(vertex_layout == _vertex_layout_type_p);
		return depth_only_pipeline_state;
	}
	return pipeline_states[vertex_layout][pipeline_mode];
}
