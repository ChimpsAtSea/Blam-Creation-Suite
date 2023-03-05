#include "graphicslib-private-pch.h"

c_graphics_shader_pipeline_d3d12::c_graphics_shader_pipeline_d3d12(
	c_graphics_d3d12& _graphics,
	const wchar_t* _debug_name) :
	c_graphics_shader_pipeline(),
	graphics(_graphics),
	debug_name(_wcsdup(_debug_name))
{

}

c_graphics_shader_pipeline_d3d12::~c_graphics_shader_pipeline_d3d12()
{
	untracked_free(debug_name);

	// make sure that the pipeline isn't bound
	ASSERT(graphics.bound_shader_pipeline != this);
}

c_graphics_shader_pipeline_state_d3d12::c_graphics_shader_pipeline_state_d3d12(
	c_graphics_d3d12& _graphics,
	c_graphics_root_signature_d3d12& _root_signature,
	const wchar_t* _debug_name) :
	c_graphics_shader_pipeline_d3d12(_graphics, _debug_name),
	root_signature(_root_signature),
	pipeline_state()
{

}

c_graphics_shader_pipeline_state_d3d12::~c_graphics_shader_pipeline_state_d3d12()
{

}

void c_graphics_shader_pipeline_state_d3d12::bind()
{
	ASSERT(graphics.bound_shader_pipeline == nullptr);
	graphics.command_list->SetPipelineState(pipeline_state);
	graphics.bound_shader_pipeline = this;
}

void c_graphics_shader_pipeline_state_d3d12::unbind()
{
	ASSERT(graphics.bound_shader_pipeline == this);
	// #NOTE: This crashes Intel Xe Driver.
	// spec says that this is optional. Is this correct?
	// graphics.command_list->SetPipelineState(nullptr);
	graphics.bound_shader_pipeline = nullptr;
}

c_graphics_shader_pipeline_compute_d3d12::c_graphics_shader_pipeline_compute_d3d12(
	c_graphics_d3d12& graphics,
	c_graphics_root_signature_d3d12& root_signature,
	c_graphics_shader_binary_d3d12& shader_binary,
	const wchar_t* debug_name) :
	c_graphics_shader_pipeline_state_d3d12(graphics, root_signature, debug_name),
	pipeline_state_description()
{
	pipeline_state_description.pRootSignature = root_signature.root_signature;
	pipeline_state_description.NodeMask = 0;
	pipeline_state_description.CachedPSO = {};

	pipeline_state_description.Flags = D3D12_PIPELINE_STATE_FLAG_NONE;
	if (graphics.adapter_description.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
	{
		pipeline_state_description.Flags = pipeline_state_description.Flags | D3D12_PIPELINE_STATE_FLAG_TOOL_DEBUG;
	}

	// #TODO: detect the correct types of shader binaries
	pipeline_state_description.CS.pShaderBytecode = shader_binary.shader_binary_data;
	pipeline_state_description.CS.BytecodeLength = shader_binary.shader_binary_data_size;

	HRESULT create_graphics_pipeline_state_result = graphics.device->CreateComputePipelineState(&pipeline_state_description, IID_PPV_ARGS(&pipeline_state));
	if (FAILED(create_graphics_pipeline_state_result))
	{
		throw BCS_E_FAIL;
	}
	graphics.set_object_debug_name(debug_name, L"c_graphics_shader_pipeline_compute_d3d12::pipeline_state", pipeline_state);

	debug_point;
}

c_graphics_shader_pipeline_compute_d3d12::~c_graphics_shader_pipeline_compute_d3d12()
{
	UINT pipeline_state_reference_count = pipeline_state->Release();
	ASSERT(pipeline_state_reference_count == 0);
}

c_graphics_shader_pipeline_graphics_d3d12::c_graphics_shader_pipeline_graphics_d3d12(
	c_graphics_d3d12& graphics,
	c_graphics_root_signature_d3d12& root_signature,
	c_graphics_shader_binary_d3d12** shader_binaries,
	uint32_t num_shader_binaries,
	e_graphics_data_format* render_target_data_formats,
	uint32_t num_render_targets,
	e_graphics_data_format* depth_data_format,
	c_graphics_vertex_layout_d3d12& vertex_layout,
	const wchar_t* debug_name) :
	c_graphics_shader_pipeline_state_d3d12(graphics, root_signature, debug_name),
	pipeline_state_description()
{
	BCS_VALIDATE_ARGUMENT_THROW(shader_binaries);
	BCS_VALIDATE_ARGUMENT_THROW(num_shader_binaries > 0);
	BCS_VALIDATE_ARGUMENT_THROW(num_render_targets <= 8);

	pipeline_state_description.pRootSignature = root_signature.root_signature;
	pipeline_state_description.RasterizerState = CD3DX12_RASTERIZER_DESC(D3D12_DEFAULT);
	pipeline_state_description.BlendState = CD3DX12_BLEND_DESC(D3D12_DEFAULT);
	pipeline_state_description.DepthStencilState = CD3DX12_DEPTH_STENCIL_DESC1(D3D12_DEFAULT);
	pipeline_state_description.DepthStencilState.DepthFunc = D3D12_COMPARISON_FUNC_GREATER_EQUAL;
	pipeline_state_description.SampleMask = UINT_MAX;
	pipeline_state_description.PrimitiveTopologyType = D3D12_PRIMITIVE_TOPOLOGY_TYPE_TRIANGLE;
	pipeline_state_description.NumRenderTargets = num_render_targets;
	pipeline_state_description.SampleDesc.Count = 1;
	pipeline_state_description.RasterizerState.CullMode = D3D12_CULL_MODE_FRONT;
	pipeline_state_description.RasterizerState.FrontCounterClockwise = FALSE;

	for (uint32_t render_target_index = 0; render_target_index < num_render_targets; render_target_index++)
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

	pipeline_state_description.InputLayout.pInputElementDescs = vertex_layout.input_element_descriptions;
	pipeline_state_description.InputLayout.NumElements = vertex_layout.num_vertex_layout_descriptions;

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
	graphics.set_object_debug_name(debug_name, L"c_graphics_shader_pipeline_graphics_d3d12::pipeline_state", pipeline_state);

	debug_point;
}

c_graphics_shader_pipeline_graphics_d3d12::~c_graphics_shader_pipeline_graphics_d3d12()
{
	UINT pipeline_state_reference_count = pipeline_state->Release();
	ASSERT(pipeline_state_reference_count == 0);
}

c_graphics_shader_pipeline_raytracing_d3d12::c_graphics_shader_pipeline_raytracing_d3d12(
	c_graphics_d3d12& _graphics,
	c_graphics_root_signature_d3d12& _global_root_signature,
	c_graphics_root_signature_d3d12* _local_root_signature,
	c_graphics_shader_binary_d3d12& shader_binary,
	const wchar_t* _raygen_shader_name,
	const wchar_t* _closest_hit_shader_name,
	const wchar_t* _miss_shader_name,
	const wchar_t* _hit_group_name,
	const wchar_t* _debug_name) :
	c_graphics_shader_pipeline_d3d12(_graphics, _debug_name),
	global_root_signature(_global_root_signature),
	local_root_signature(_local_root_signature),
	raytracing_fallback_state_object(nullptr),
	state_object_description(),
	raygen_shader_identifier(),
	closest_hit_shader_identifier(),
	miss_shader_identifier(),
	hit_group_identifier(),
	shader_identifier_size(),
	ray_generation_shader_record_size(),
	closest_hit_group_table_record_size(),
	miss_shader_table_record_size(),
	hit_group_table_record_size(),
	callable_shader_table_record_size(),
	raygen_shader_name(_wcsdup(_raygen_shader_name)),
	closest_hit_shader_name(_wcsdup(_closest_hit_shader_name)),
	miss_shader_name(_wcsdup(_miss_shader_name)),
	hit_group_name(_wcsdup(_hit_group_name)),
	ray_generation_shader_record_buffer(),
	closest_hit_shader_table_buffer(),
	miss_shader_table_buffer(),
	hit_group_table_buffer(),
	callable_shader_table_buffer()
{
	D3D12_STATE_SUBOBJECT state_subobjects[5]{};
	D3D12_STATE_SUBOBJECT& state_subobject_dxil_library = state_subobjects[0];
	D3D12_STATE_SUBOBJECT& state_subobject_hit_group = state_subobjects[1];
	D3D12_STATE_SUBOBJECT& state_subobject_raytracing_shader_config = state_subobjects[2];
	D3D12_STATE_SUBOBJECT& state_subobject_global_root_signature = state_subobjects[3];
	D3D12_STATE_SUBOBJECT& state_subobject_raytracing_pipeline_config = state_subobjects[4];
	//D3D12_STATE_SUBOBJECT& state_subobject_local_root_signature = state_subobjects[5];
	//D3D12_STATE_SUBOBJECT& state_subobject_subobject_to_exports_association = state_subobjects[6];

	{
		// DXIL library
		// This contains the shaders and their entrypoints for the state object.
		// Since shaders are not considered a subobject, they need to be passed in via DXIL library subobjects.

		// Define which shader exports to surface from the library.
		// If no shader exports are defined for a DXIL library subobject, all shaders will be surfaced.
		// In this sample, this could be omitted for convenience since the sample uses all shaders in the library. 

		D3D12_EXPORT_DESC export_descriptions[3]{};

		export_descriptions[0].Name = raygen_shader_name;
		export_descriptions[0].ExportToRename = nullptr;
		export_descriptions[0].Flags = D3D12_EXPORT_FLAG_NONE;

		export_descriptions[1].Name = closest_hit_shader_name;
		export_descriptions[1].ExportToRename = nullptr;
		export_descriptions[1].Flags = D3D12_EXPORT_FLAG_NONE;

		export_descriptions[2].Name = miss_shader_name;
		export_descriptions[2].ExportToRename = nullptr;
		export_descriptions[2].Flags = D3D12_EXPORT_FLAG_NONE;

		D3D12_DXIL_LIBRARY_DESC dxil_library_description = {};
		dxil_library_description.DXILLibrary.pShaderBytecode = shader_binary.shader_binary_data;
		dxil_library_description.DXILLibrary.BytecodeLength = shader_binary.shader_binary_data_size;
		dxil_library_description.NumExports = _countof(export_descriptions);
		dxil_library_description.pExports = export_descriptions;

		state_subobject_dxil_library.Type = D3D12_STATE_SUBOBJECT_TYPE_DXIL_LIBRARY;
		state_subobject_dxil_library.pDesc = &dxil_library_description;
	}

	{
		// Triangle hit group
		// A hit group specifies closest hit, any hit and intersection shaders to be executed when a ray intersects the geometry's triangle/AABB.
		// In this sample, we only use triangle geometry with a closest hit shader, so others are not set.

		D3D12_HIT_GROUP_DESC hit_group_description = {};

		hit_group_description.HitGroupExport = hit_group_name;
		hit_group_description.Type = D3D12_HIT_GROUP_TYPE_TRIANGLES;
		hit_group_description.AnyHitShaderImport = nullptr;
		hit_group_description.ClosestHitShaderImport = closest_hit_shader_name;
		hit_group_description.IntersectionShaderImport = nullptr;

		state_subobject_hit_group.Type = D3D12_STATE_SUBOBJECT_TYPE_HIT_GROUP;
		state_subobject_hit_group.pDesc = &hit_group_description;
	}

	{
		// Shader config
		// Defines the maximum sizes in bytes for the ray payload and attribute structure.

		D3D12_RAYTRACING_SHADER_CONFIG raytracing_shader_config = {};
		raytracing_shader_config.MaxPayloadSizeInBytes = sizeof(float4);
		raytracing_shader_config.MaxAttributeSizeInBytes = sizeof(float2);

		state_subobject_raytracing_shader_config.Type = D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_SHADER_CONFIG;
		state_subobject_raytracing_shader_config.pDesc = &raytracing_shader_config;
	}

	{
		// Global root signature
		// This is a root signature that is shared across all raytracing shaders invoked during a DispatchRays() call.

		D3D12_GLOBAL_ROOT_SIGNATURE global_root_signature = {};
		global_root_signature.pGlobalRootSignature = this->global_root_signature.root_signature;

		state_subobject_global_root_signature.Type = D3D12_STATE_SUBOBJECT_TYPE_GLOBAL_ROOT_SIGNATURE;
		state_subobject_global_root_signature.pDesc = &global_root_signature;
	}

	{
		// Pipeline config
		// Defines the maximum TraceRay() recursion depth.

		D3D12_RAYTRACING_PIPELINE_CONFIG raytracing_pipeline_config = {};
		raytracing_pipeline_config.MaxTraceRecursionDepth = 1; // ~ primary rays only. 


		state_subobject_raytracing_pipeline_config.Type = D3D12_STATE_SUBOBJECT_TYPE_RAYTRACING_PIPELINE_CONFIG;
		state_subobject_raytracing_pipeline_config.pDesc = &raytracing_pipeline_config;
	}

	{
		/*
		// Local root signature and shader association
		// This is a root signature that enables a shader to have unique arguments that come from shader tables.
		void D3D12RaytracingHelloWorld::CreateLocalRootSignatureSubobjects(CD3D12_STATE_OBJECT_DESC* raytracingPipeline)
		{
			// Hit group and miss shaders in this sample are not using a local root signature and thus one is not associated with them.

			// Local root signature to be used in a ray gen shader.
			{
				auto localRootSignature = raytracingPipeline->CreateSubobject<CD3D12_LOCAL_ROOT_SIGNATURE_SUBOBJECT>();
				localRootSignature->SetRootSignature(m_raytracingLocalRootSignature.Get());
				// Shader association
				auto rootSignatureAssociation = raytracingPipeline->CreateSubobject<CD3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION_SUBOBJECT>();
				rootSignatureAssociation->SetSubobjectToAssociate(*localRootSignature);
				rootSignatureAssociation->AddExport(c_raygenShaderName);
			}
		}
		*/
		//{
		//	D3D12_LOCAL_ROOT_SIGNATURE local_root_signature = {};
		//	local_root_signature.pLocalRootSignature = this->local_root_signature.root_signature;
		//	
		//	state_subobject_local_root_signature.Type = D3D12_STATE_SUBOBJECT_TYPE_LOCAL_ROOT_SIGNATURE;
		//	state_subobject_local_root_signature.pDesc = &local_root_signature;
		//}

		//{
		//	D3D12_SUBOBJECT_TO_EXPORTS_ASSOCIATION subobject_to_exports_association = {};
		//	subobject_to_exports_association.pSubobjectToAssociate = &state_subobject_local_root_signature;

		//	LPCWSTR exports[1] = {};
		//	exports[0] = raygen_shader_name;

		//	subobject_to_exports_association.NumExports = _countof(exports);
		//	subobject_to_exports_association.pExports = exports;

		//	state_subobject_subobject_to_exports_association.Type = D3D12_STATE_SUBOBJECT_TYPE_SUBOBJECT_TO_EXPORTS_ASSOCIATION;
		//	state_subobject_subobject_to_exports_association.pDesc = &subobject_to_exports_association;
		//}
	}

	state_object_description.Type = D3D12_STATE_OBJECT_TYPE_RAYTRACING_PIPELINE;
	state_object_description.NumSubobjects = _countof(state_subobjects);
	state_object_description.pSubobjects = state_subobjects;

	HRESULT hrs = graphics.d3d12_raytracing_fallback_device->CreateStateObject(&state_object_description, IID_PPV_ARGS(&raytracing_fallback_state_object));
	BCS_FAIL_THROW(graphics.hresult_to_bcs_result(hrs));

	shader_identifier_size = graphics.d3d12_raytracing_fallback_device->GetShaderIdentifierSize();

	ray_generation_shader_record_size = ALIGN(shader_identifier_size, D3D12_RAYTRACING_SHADER_RECORD_BYTE_ALIGNMENT);
	closest_hit_group_table_record_size = ALIGN(shader_identifier_size, D3D12_RAYTRACING_SHADER_RECORD_BYTE_ALIGNMENT);
	miss_shader_table_record_size = ALIGN(shader_identifier_size, D3D12_RAYTRACING_SHADER_RECORD_BYTE_ALIGNMENT);
	hit_group_table_record_size = ALIGN(shader_identifier_size, D3D12_RAYTRACING_SHADER_RECORD_BYTE_ALIGNMENT);
	callable_shader_table_record_size = ALIGN(shader_identifier_size, D3D12_RAYTRACING_SHADER_RECORD_BYTE_ALIGNMENT);

	//ray_generation_shader_record_size = ALIGN(shader_identifier_size, D3D12_RAYTRACING_SHADER_TABLE_BYTE_ALIGNMENT);
	//closest_hit_group_table_record_size = ALIGN(shader_identifier_size, D3D12_RAYTRACING_SHADER_TABLE_BYTE_ALIGNMENT);
	//miss_shader_table_record_size = ALIGN(shader_identifier_size, D3D12_RAYTRACING_SHADER_TABLE_BYTE_ALIGNMENT);
	//hit_group_table_record_size = ALIGN(shader_identifier_size, D3D12_RAYTRACING_SHADER_TABLE_BYTE_ALIGNMENT);
	//callable_shader_table_record_size = ALIGN(shader_identifier_size, D3D12_RAYTRACING_SHADER_TABLE_BYTE_ALIGNMENT);

	if (raygen_shader_name != nullptr)
	{
		unsigned int ray_generation_shader_record_count = 1;
		ray_generation_shader_record_buffer = new c_graphics_buffer_d3d12(
			graphics,
			_graphics_buffer_type_d3d12_generic,
			ray_generation_shader_record_size,
			ray_generation_shader_record_count,
			L"ray_generation_shader_record_buffer");
		raygen_shader_identifier = raytracing_fallback_state_object->GetShaderIdentifier(raygen_shader_name);
		if (raygen_shader_identifier)
		{
			ray_generation_shader_record_buffer->write_data(raygen_shader_identifier, shader_identifier_size, 0);
		}
	}

	if (closest_hit_shader_name != nullptr)
	{
		unsigned int closest_hit_shader_table_buffer_count = 1;
		closest_hit_shader_table_buffer = new c_graphics_buffer_d3d12(
			graphics,
			_graphics_buffer_type_d3d12_generic,
			ray_generation_shader_record_size,
			closest_hit_shader_table_buffer_count,
			L"closest_hit_shader_table_buffer");
		closest_hit_shader_identifier = raytracing_fallback_state_object->GetShaderIdentifier(closest_hit_shader_name);
		if (closest_hit_shader_identifier)
		{
			closest_hit_shader_table_buffer->write_data(closest_hit_shader_identifier, shader_identifier_size, 0);
		}
	}

	if (miss_shader_name != nullptr)
	{
		unsigned int miss_shader_table_buffer_count = 1;
		miss_shader_table_buffer = new c_graphics_buffer_d3d12(
			graphics,
			_graphics_buffer_type_d3d12_generic,
			miss_shader_table_record_size,
			miss_shader_table_buffer_count,
			L"miss_shader_table_buffer");
		miss_shader_identifier = raytracing_fallback_state_object->GetShaderIdentifier(miss_shader_name);
		if (miss_shader_identifier)
		{
			miss_shader_table_buffer->write_data(miss_shader_identifier, shader_identifier_size, 0);
		}
	}

	if (hit_group_name != nullptr)
	{
		unsigned int hit_group_table_buffer_count = 1;
		hit_group_table_buffer = new c_graphics_buffer_d3d12(
			graphics,
			_graphics_buffer_type_d3d12_generic,
			hit_group_table_record_size,
			hit_group_table_buffer_count,
			L"hit_group_table_buffer");
		if ((hit_group_identifier = raytracing_fallback_state_object->GetShaderIdentifier(hit_group_name)))
		{
			hit_group_table_buffer->write_data(hit_group_identifier, shader_identifier_size, 0);
		}
	}

	if (false)
	{
		void* callable_identifier = raytracing_fallback_state_object->GetShaderIdentifier(nullptr);

		unsigned int callable_shader_table_buffer_count = 1;
		callable_shader_table_buffer = new c_graphics_buffer_d3d12(
			graphics,
			_graphics_buffer_type_d3d12_generic,
			callable_shader_table_record_size,
			callable_shader_table_buffer_count,
			L"callable_shader_table_buffer");
		callable_shader_table_buffer->write_data(callable_identifier, shader_identifier_size, 0);
	}
}

c_graphics_shader_pipeline_raytracing_d3d12::~c_graphics_shader_pipeline_raytracing_d3d12()
{
	UINT raytracing_fallback_state_object_reference_count = raytracing_fallback_state_object->Release();
	ASSERT(raytracing_fallback_state_object_reference_count == 0);

	delete ray_generation_shader_record_buffer;
	delete closest_hit_shader_table_buffer;
	delete miss_shader_table_buffer;
	delete hit_group_table_buffer;
	delete callable_shader_table_buffer;

	untracked_free(raygen_shader_name);
	untracked_free(closest_hit_shader_name);
	untracked_free(miss_shader_name);
	untracked_free(hit_group_name);
}

void c_graphics_shader_pipeline_raytracing_d3d12::bind()
{
	ASSERT(graphics.bound_shader_pipeline == nullptr);
	graphics.d3d12_raytracing_command_list->SetPipelineState1(raytracing_fallback_state_object);
	graphics.bound_shader_pipeline = this;
}

void c_graphics_shader_pipeline_raytracing_d3d12::unbind()
{
	ASSERT(graphics.bound_shader_pipeline == this);
	//graphics.d3d12_raytracing_command_list->SetPipelineState1(nullptr);
	graphics.bound_shader_pipeline = nullptr;
}

BCS_RESULT c_graphics_shader_pipeline_d3d12::dispatch(uint32_t x, uint32_t y, uint32_t z)
{
	ASSERT(graphics.bound_shader_pipeline == this);
	graphics.command_list->Dispatch(x, y, z);
	return BCS_S_OK;
}

BCS_RESULT c_graphics_shader_pipeline_d3d12::dispatch_rays(uint32_t x, uint32_t y, uint32_t z)
{
	ASSERT(graphics.bound_shader_pipeline == this);
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT c_graphics_shader_pipeline_raytracing_d3d12::dispatch_rays(uint32_t x, uint32_t y, uint32_t z)
{
	ASSERT(graphics.bound_shader_pipeline == this);

	if (graphics.raytracing_mode == _graphics_raytracing_mode_d3d12_unsupported)
	{
		return BCS_E_UNSUPPORTED;
	}

	D3D12_DISPATCH_RAYS_DESC dispatch_rays_description = {};

	if (raygen_shader_identifier != nullptr)
	{
		ray_generation_shader_record_buffer->write_data(raygen_shader_identifier, shader_identifier_size, 0);
	}

	if (closest_hit_shader_identifier != nullptr)
	{
		closest_hit_shader_table_buffer->write_data(closest_hit_shader_identifier, shader_identifier_size, 0);
	}

	if (miss_shader_identifier != nullptr)
	{
		miss_shader_table_buffer->write_data(miss_shader_identifier, shader_identifier_size, 0);
	}

	if (hit_group_identifier != nullptr)
	{
		hit_group_table_buffer->write_data(hit_group_identifier, shader_identifier_size, 0);
	}

	if (false)
	{
		callable_shader_table_buffer->write_data(raygen_shader_identifier, shader_identifier_size, 0);
	}


	ASSERT(ray_generation_shader_record_buffer != nullptr); // must be set, crash of Intel XE
	if (ray_generation_shader_record_buffer != nullptr)
	{
		dispatch_rays_description.RayGenerationShaderRecord.StartAddress = ray_generation_shader_record_buffer->gpu_resource->GetGPUVirtualAddress();
		dispatch_rays_description.RayGenerationShaderRecord.SizeInBytes = ray_generation_shader_record_buffer->get_data_size();
	}

	if (miss_shader_table_buffer != nullptr)
	{
		dispatch_rays_description.MissShaderTable.StartAddress = ray_generation_shader_record_buffer->gpu_resource->GetGPUVirtualAddress();
		dispatch_rays_description.MissShaderTable.SizeInBytes = ray_generation_shader_record_buffer->get_data_size();
		dispatch_rays_description.MissShaderTable.StrideInBytes = shader_identifier_size;
	}

	if (hit_group_table_buffer != nullptr)
	{
		dispatch_rays_description.HitGroupTable.StartAddress = ray_generation_shader_record_buffer->gpu_resource->GetGPUVirtualAddress();
		dispatch_rays_description.HitGroupTable.SizeInBytes = ray_generation_shader_record_buffer->get_data_size();
		dispatch_rays_description.HitGroupTable.StrideInBytes = shader_identifier_size;
	}

	if (callable_shader_table_buffer != nullptr)
	{
		dispatch_rays_description.CallableShaderTable.StartAddress = ray_generation_shader_record_buffer->gpu_resource->GetGPUVirtualAddress();
		dispatch_rays_description.CallableShaderTable.SizeInBytes = ray_generation_shader_record_buffer->get_data_size();
		dispatch_rays_description.CallableShaderTable.StrideInBytes = shader_identifier_size;
	}

	dispatch_rays_description.Width = x;
	dispatch_rays_description.Height = y;
	dispatch_rays_description.Depth = z;

	graphics.d3d12_raytracing_command_list->DispatchRays(&dispatch_rays_description);

	return BCS_S_OK;
}

BCS_RESULT graphics_d3d12_shader_pipeline_raytracing_create(
	c_graphics_d3d12* graphics,
	c_graphics_root_signature_d3d12* global_root_signature,
	c_graphics_root_signature_d3d12* local_root_signature,
	c_graphics_shader_binary_d3d12* shader_binary,
	const wchar_t* raygen_shader_name,
	const wchar_t* closest_hit_shader_name,
	const wchar_t* miss_shader_name,
	const wchar_t* hit_group_name,
	c_graphics_shader_pipeline_raytracing_d3d12*& shader_pipeline,
	const char* debug_name)
{
	BCS_VALIDATE_ARGUMENT(graphics);
	BCS_VALIDATE_ARGUMENT(global_root_signature);
	BCS_VALIDATE_ARGUMENT(shader_binary);

	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		shader_pipeline = new() c_graphics_shader_pipeline_raytracing_d3d12(
			*graphics,
			*global_root_signature,
			local_root_signature,
			*shader_binary,
			raygen_shader_name,
			closest_hit_shader_name,
			miss_shader_name,
			hit_group_name,
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

BCS_RESULT graphics_d3d12_shader_pipeline_compute_create(
	c_graphics_d3d12* graphics,
	c_graphics_root_signature_d3d12* root_signature,
	c_graphics_shader_binary_d3d12* shader_binary,
	c_graphics_shader_pipeline_compute_d3d12*& shader_pipeline,
	const char* debug_name)
{
	BCS_VALIDATE_ARGUMENT(graphics);
	BCS_VALIDATE_ARGUMENT(root_signature);
	BCS_VALIDATE_ARGUMENT(shader_binary);

	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		shader_pipeline = new() c_graphics_shader_pipeline_compute_d3d12(
			*graphics,
			*root_signature,
			*shader_binary,
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

BCS_RESULT graphics_d3d12_shader_pipeline_graphics_create(
	c_graphics_d3d12* graphics,
	c_graphics_root_signature_d3d12* root_signature,
	c_graphics_shader_binary_d3d12** shader_binaries,
	uint32_t num_shader_binaries,
	e_graphics_data_format* render_target_data_formats,
	uint32_t num_render_targets,
	e_graphics_data_format* depth_data_format,
	c_graphics_vertex_layout_d3d12* vertex_layout,
	c_graphics_shader_pipeline_graphics_d3d12*& shader_pipeline,
	const char* debug_name)
{
	BCS_VALIDATE_ARGUMENT(graphics);
	BCS_VALIDATE_ARGUMENT(root_signature);

	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		shader_pipeline = new() c_graphics_shader_pipeline_graphics_d3d12(
			*graphics,
			*root_signature,
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
