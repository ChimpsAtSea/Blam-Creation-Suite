#include "graphicslib-private-pch.h"

c_graphics_top_level_acceleration_structure_d3d12::c_graphics_top_level_acceleration_structure_d3d12(
	c_graphics_d3d12& _graphics,
	const wchar_t* _debug_name) :
	graphics(_graphics),
	raytracing_acceleration_structure_buffer(nullptr),
	build_raytracing_acceleration_structure_description(),
	raytracing_acceleration_structure_prebuild_info()/*,
	acceleration_structure_descriptor_handle_index(),
	acceleration_structure_cpu_descriptor_handle()*/
{

}

c_graphics_top_level_acceleration_structure_d3d12::~c_graphics_top_level_acceleration_structure_d3d12()
{
	BCS_RESULT raytracing_acceleration_structure_buffer_destroy_result = graphics_d3d12_buffer_destroy(raytracing_acceleration_structure_buffer);
	ASSERT(BCS_SUCCEEDED(raytracing_acceleration_structure_buffer_destroy_result));
}

BCS_RESULT c_graphics_top_level_acceleration_structure_d3d12::acceleration_structure_prebuild()
{
	build_raytracing_acceleration_structure_description.Inputs.Type = D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_TOP_LEVEL;
	build_raytracing_acceleration_structure_description.Inputs.Flags = D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_TRACE;
	build_raytracing_acceleration_structure_description.Inputs.NumDescs = 1;
	build_raytracing_acceleration_structure_description.Inputs.DescsLayout = D3D12_ELEMENTS_LAYOUT_ARRAY;
	build_raytracing_acceleration_structure_description.Inputs.pGeometryDescs = nullptr;

	switch (graphics.raytracing_mode)
	{
	case _graphics_raytracing_mode_d3d12_native:
		graphics.device->GetRaytracingAccelerationStructurePrebuildInfo(&build_raytracing_acceleration_structure_description.Inputs, &raytracing_acceleration_structure_prebuild_info);
		break;
	case _graphics_raytracing_mode_d3d12_fallback:
		graphics.d3d12_raytracing_fallback_device->GetRaytracingAccelerationStructurePrebuildInfo(&build_raytracing_acceleration_structure_description.Inputs, &raytracing_acceleration_structure_prebuild_info);
		break;
	}

	if (raytracing_acceleration_structure_prebuild_info.ResultDataMaxSizeInBytes == 0)
	{
		throw BCS_E_FAIL;
	}

	return BCS_S_OK;
}

BCS_RESULT c_graphics_top_level_acceleration_structure_d3d12::acceleration_structure_build(
	s_graphics_acceleration_structure_instance const* instances,
	unsigned int num_instances)
{
	for (unsigned int instance_index = 0; instance_index < num_instances; instance_index++)
	{
		s_graphics_acceleration_structure_instance const& instance = instances[instance_index];
		c_graphics_bottom_level_acceleration_structure_d3d12* bottom_level_acceleration_structure = dynamic_cast<c_graphics_bottom_level_acceleration_structure_d3d12*>(instance.bottom_level_acceleration_structure);
		if (bottom_level_acceleration_structure == nullptr)
		{
			return BCS_E_INVALID_ARGUMENT;
		}
	}

	c_graphics_buffer_d3d12* scratch_resource_buffer = nullptr;
	if (raytracing_acceleration_structure_prebuild_info.ScratchDataSizeInBytes > 0)
	{
		BCS_RESULT scratch_resource_buffer_create_result = graphics_d3d12_buffer_create(
			&graphics,
			_graphics_buffer_type_d3d12_unordered_access_view,
			raytracing_acceleration_structure_prebuild_info.ScratchDataSizeInBytes,
			scratch_resource_buffer,
			"c_graphics_top_level_acceleration_structure_d3d12::scratch_resource_buffer");
		BCS_FAIL_THROW(scratch_resource_buffer_create_result);
	}

	BCS_RESULT raytracing_acceleration_structure_buffer_create_result = graphics_d3d12_buffer_create(
		&graphics,
		_graphics_buffer_type_d3d12_raytracing_acceleration_structure,
		raytracing_acceleration_structure_prebuild_info.ResultDataMaxSizeInBytes,
		raytracing_acceleration_structure_buffer,
		"top level");
	BCS_FAIL_THROW(raytracing_acceleration_structure_buffer_create_result);

	//// Only compute fallback requires a valid descriptor index when creating a wrapped pointer.
	//if (!graphics.d3d12_raytracing_fallback_device->UsingRaytracingDriver())
	//{
	//	//BCS_RESULT allocate_descriptor_handle_result = graphics.cbv_srv_uav_descriptor_heap_allocator->allocate_descriptor_handle_cpu(
	//	//	acceleration_structure_descriptor_handle_index,
	//	//	acceleration_structure_cpu_descriptor_handle);
	//	//BCS_FAIL_THROW(allocate_descriptor_handle_result);

	//	UINT num_buffer_elements = static_cast<UINT>(raytracing_acceleration_structure_prebuild_info.ResultDataMaxSizeInBytes) / sizeof(UINT32);

	//	D3D12_UNORDERED_ACCESS_VIEW_DESC bottom_level_buffer_view_description = {};
	//	bottom_level_buffer_view_description.ViewDimension = D3D12_UAV_DIMENSION_BUFFER;
	//	bottom_level_buffer_view_description.Buffer.Flags = D3D12_BUFFER_UAV_FLAG_RAW;
	//	bottom_level_buffer_view_description.Format = DXGI_FORMAT_R32_TYPELESS;
	//	bottom_level_buffer_view_description.Buffer.NumElements = num_buffer_elements;

	//	graphics.device->CreateUnorderedAccessView(
	//		raytracing_acceleration_structure_buffer->gpu_resource,
	//		nullptr,
	//		&bottom_level_buffer_view_description,
	//		acceleration_structure_cpu_descriptor_handle);
	//}

	D3D12_RAYTRACING_FALLBACK_INSTANCE_DESC* instance_descriptions = trivial_malloca(D3D12_RAYTRACING_FALLBACK_INSTANCE_DESC, num_instances);
	for (unsigned int instance_index = 0; instance_index < num_instances; instance_index++)
	{
		s_graphics_acceleration_structure_instance const& instance = instances[instance_index];
		D3D12_RAYTRACING_FALLBACK_INSTANCE_DESC& instance_description = instance_descriptions[instance_index] = {};
		c_graphics_bottom_level_acceleration_structure_d3d12* bottom_level_acceleration_structure = dynamic_cast<c_graphics_bottom_level_acceleration_structure_d3d12*>(instance.bottom_level_acceleration_structure);

		static_assert(sizeof(instance_description.Transform) == sizeof(instance.transform));
		memcpy(instance_description.Transform, &instance.transform, sizeof(instance.transform));
		instance_descriptions[0].InstanceMask = 1;
		instance_descriptions[0].AccelerationStructure = graphics.d3d12_raytracing_fallback_device->GetWrappedPointerSimple(
			bottom_level_acceleration_structure->raytracing_acceleration_structure_buffer->descriptor_heap_index,
			bottom_level_acceleration_structure->raytracing_acceleration_structure_buffer->gpu_virtual_address);

		debug_point;
	}

	c_graphics_buffer_d3d12* instance_description_buffer = nullptr;
	BCS_RESULT instance_description_buffer_create_result = graphics_d3d12_buffer_create(
		&graphics,
		_graphics_buffer_type_d3d12_raytracing_instance_descriptions,
		sizeof(D3D12_RAYTRACING_FALLBACK_INSTANCE_DESC),
		num_instances,
		instance_description_buffer,
		"c_graphics_top_level_acceleration_structure_d3d12::instance_description_buffer");
	BCS_FAIL_THROW(instance_description_buffer_create_result);

	build_raytracing_acceleration_structure_description.ScratchAccelerationStructureData = scratch_resource_buffer->gpu_virtual_address;
	build_raytracing_acceleration_structure_description.DestAccelerationStructureData = raytracing_acceleration_structure_buffer->gpu_virtual_address;
	build_raytracing_acceleration_structure_description.Inputs.InstanceDescs = instance_description_buffer->gpu_virtual_address;


	BCS_RESULT graphics_begin_result = graphics.begin();
	BCS_FAIL_THROW(graphics_begin_result);

	graphics.transition_resource(instance_description_buffer->gpu_resource, instance_description_buffer->gpu_resource_state, D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE);
	instance_description_buffer->gpu_resource_state = D3D12_RESOURCE_STATE_NON_PIXEL_SHADER_RESOURCE;

	instance_description_buffer->write_data(instance_descriptions, sizeof(D3D12_RAYTRACING_FALLBACK_INSTANCE_DESC), num_instances, 0);
	graphics.d3d12_raytracing_command_list->SetDescriptorHeaps(1, &graphics.cbv_srv_uav_descriptor_heap_allocator->descriptor_heap);
	graphics.d3d12_raytracing_command_list->BuildRaytracingAccelerationStructure(&build_raytracing_acceleration_structure_description, 0, nullptr);

	D3D12_RESOURCE_BARRIER resource_barrier = {};
	resource_barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_UAV;
	resource_barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
	D3D12_RESOURCE_UAV_BARRIER& resource_barrier_uav = resource_barrier.UAV;
	resource_barrier_uav.pResource = raytracing_acceleration_structure_buffer->gpu_resource;
	graphics.command_list->ResourceBarrier(1, &resource_barrier);

	BCS_RESULT graphics_end_result = graphics.end();
	BCS_FAIL_THROW(graphics_end_result);

	BCS_RESULT instance_description_buffer_destroy_result = graphics_d3d12_buffer_destroy(instance_description_buffer);
	BCS_FAIL_THROW(instance_description_buffer_destroy_result);

	if (scratch_resource_buffer != nullptr)
	{
		BCS_RESULT scratch_resource_buffer_destroy_result = graphics_d3d12_buffer_destroy(scratch_resource_buffer);
		BCS_FAIL_THROW(scratch_resource_buffer_destroy_result);
	}

	return BCS_S_OK;
}

BCS_RESULT c_graphics_top_level_acceleration_structure_d3d12::get_buffer(c_graphics_buffer*& out_acceleration_structure_buffer) const
{
	out_acceleration_structure_buffer = raytracing_acceleration_structure_buffer;
	return BCS_S_OK;
}

c_graphics_bottom_level_acceleration_structure_d3d12::c_graphics_bottom_level_acceleration_structure_d3d12(
	c_graphics_d3d12& _graphics,
	c_graphics_geometry_d3d12& _geometry,
	const wchar_t* _debug_name) :
	graphics(_graphics),
	geometry(_geometry),
	raytracing_acceleration_structure_buffer(nullptr),
	vertex_layout_description(),
	input_element_description(),
	geometry_index_buffer(),
	geometry_vertex_buffer(),
	raytracing_geometry_description(),
	build_raytracing_acceleration_structure_description(),
	raytracing_acceleration_structure_prebuild_info()
{

}

c_graphics_bottom_level_acceleration_structure_d3d12::~c_graphics_bottom_level_acceleration_structure_d3d12()
{
	BCS_RESULT raytracing_acceleration_structure_buffer_destroy_result = graphics_d3d12_buffer_destroy(raytracing_acceleration_structure_buffer);
	ASSERT(BCS_SUCCEEDED(raytracing_acceleration_structure_buffer_destroy_result));
}

BCS_RESULT c_graphics_bottom_level_acceleration_structure_d3d12::acceleration_structure_prebuild()
{
	BCS_RESULT find_first_vertex_layout_description_by_semantic_result = geometry.vertex_layout.find_first_vertex_layout_description_by_semantic(
		_graphics_vertex_layout_semantic_position,
		vertex_layout_description,
		input_element_description);
	BCS_FAIL_THROW(find_first_vertex_layout_description_by_semantic_result);

	geometry_index_buffer = geometry.index_buffer;
	geometry_vertex_buffer = geometry.vertex_buffers[vertex_layout_description->buffer_index];

	raytracing_geometry_description = {};
	raytracing_geometry_description.Type = D3D12_RAYTRACING_GEOMETRY_TYPE_TRIANGLES;
	raytracing_geometry_description.Flags = D3D12_RAYTRACING_GEOMETRY_FLAG_OPAQUE;
	D3D12_RAYTRACING_GEOMETRY_TRIANGLES_DESC& raytracing_geometry_triangles_description = raytracing_geometry_description.Triangles;
	raytracing_geometry_triangles_description.Transform3x4 = 0;
	if (geometry_index_buffer != nullptr)
	{
		raytracing_geometry_triangles_description.IndexFormat = geometry.index_buffer_view.Format;
		raytracing_geometry_triangles_description.IndexBuffer = geometry.index_buffer->gpu_virtual_address;
		raytracing_geometry_triangles_description.IndexCount = geometry.num_indices;
	}
	raytracing_geometry_triangles_description.VertexFormat = input_element_description->Format;
	raytracing_geometry_triangles_description.VertexCount = geometry.num_vertices;
	raytracing_geometry_triangles_description.VertexBuffer.StartAddress = geometry_vertex_buffer->gpu_virtual_address + vertex_layout_description->buffer_offset;
	raytracing_geometry_triangles_description.VertexBuffer.StrideInBytes = vertex_layout_description->buffer_stepping;

	build_raytracing_acceleration_structure_description.Inputs.Type = D3D12_RAYTRACING_ACCELERATION_STRUCTURE_TYPE_BOTTOM_LEVEL;
	build_raytracing_acceleration_structure_description.Inputs.Flags = D3D12_RAYTRACING_ACCELERATION_STRUCTURE_BUILD_FLAG_PREFER_FAST_TRACE;
	build_raytracing_acceleration_structure_description.Inputs.NumDescs = 1;
	build_raytracing_acceleration_structure_description.Inputs.DescsLayout = D3D12_ELEMENTS_LAYOUT_ARRAY;
	build_raytracing_acceleration_structure_description.Inputs.pGeometryDescs = &raytracing_geometry_description;

	switch (graphics.raytracing_mode)
	{
	case _graphics_raytracing_mode_d3d12_native:
		graphics.device->GetRaytracingAccelerationStructurePrebuildInfo(&build_raytracing_acceleration_structure_description.Inputs, &raytracing_acceleration_structure_prebuild_info);
		break;
	case _graphics_raytracing_mode_d3d12_fallback:
		graphics.d3d12_raytracing_fallback_device->GetRaytracingAccelerationStructurePrebuildInfo(&build_raytracing_acceleration_structure_description.Inputs, &raytracing_acceleration_structure_prebuild_info);
		break;
	}

	if (raytracing_acceleration_structure_prebuild_info.ResultDataMaxSizeInBytes == 0)
	{
		throw BCS_E_FAIL;
	}

	return BCS_S_OK;
}

BCS_RESULT c_graphics_bottom_level_acceleration_structure_d3d12::acceleration_structure_build()
{
	c_graphics_buffer_d3d12* scratch_resource_buffer = nullptr;
	if (raytracing_acceleration_structure_prebuild_info.ScratchDataSizeInBytes > 0)
	{
		BCS_RESULT scratch_resource_buffer_create_result = graphics_d3d12_buffer_create(
			&graphics,
			_graphics_buffer_type_d3d12_unordered_access_view,
			raytracing_acceleration_structure_prebuild_info.ScratchDataSizeInBytes,
			scratch_resource_buffer,
			"c_graphics_bottom_level_acceleration_structure_d3d12::scratch_resource_buffer");
		BCS_FAIL_THROW(scratch_resource_buffer_create_result);
	}

	BCS_RESULT raytracing_acceleration_structure_buffer_create_result = graphics_d3d12_buffer_create(
		&graphics,
		_graphics_buffer_type_d3d12_raytracing_acceleration_structure,
		raytracing_acceleration_structure_prebuild_info.ResultDataMaxSizeInBytes,
		raytracing_acceleration_structure_buffer,
		"bottom level");
	BCS_FAIL_THROW(raytracing_acceleration_structure_buffer_create_result);

	build_raytracing_acceleration_structure_description.ScratchAccelerationStructureData = scratch_resource_buffer->gpu_virtual_address;
	build_raytracing_acceleration_structure_description.DestAccelerationStructureData = raytracing_acceleration_structure_buffer->gpu_virtual_address;

	BCS_RESULT graphics_begin_result = graphics.begin();
	BCS_FAIL_THROW(graphics_begin_result);

	graphics.d3d12_raytracing_command_list->SetDescriptorHeaps(1, &graphics.cbv_srv_uav_descriptor_heap_allocator->descriptor_heap);
	graphics.d3d12_raytracing_command_list->BuildRaytracingAccelerationStructure(&build_raytracing_acceleration_structure_description, 0, nullptr);

	D3D12_RESOURCE_BARRIER resource_barrier = {};
	resource_barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_UAV;
	resource_barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
	D3D12_RESOURCE_UAV_BARRIER& resource_barrier_uav = resource_barrier.UAV;
	resource_barrier_uav.pResource = raytracing_acceleration_structure_buffer->gpu_resource;
	graphics.command_list->ResourceBarrier(1, &resource_barrier);

	BCS_RESULT graphics_end_result = graphics.end();
	BCS_FAIL_THROW(graphics_end_result);

	if (scratch_resource_buffer != nullptr)
	{
		BCS_RESULT scratch_resource_buffer_destroy_result = graphics_d3d12_buffer_destroy(scratch_resource_buffer);
		BCS_FAIL_THROW(scratch_resource_buffer_destroy_result);
	}

	return BCS_S_OK;
}

BCS_RESULT graphics_d3d12_top_level_acceleration_structure_create(
	c_graphics_d3d12* graphics,
	c_graphics_top_level_acceleration_structure_d3d12*& top_level_acceleration_structure,
	const char* debug_name)
{
	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		top_level_acceleration_structure = new() c_graphics_top_level_acceleration_structure_d3d12(
			*graphics,
			debug_name_wc
		);

		BCS_RESULT rs = BCS_S_OK;

		if (BCS_FAILED(rs = top_level_acceleration_structure->acceleration_structure_prebuild()))
		{
			delete top_level_acceleration_structure;
			return rs;
		}

		//if (BCS_FAILED(rs = top_level_acceleration_structure->acceleration_structure_build()))
		//{
		//	delete top_level_acceleration_structure;
		//	return rs;
		//}

		return rs;
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FATAL;
	}
	return BCS_S_OK;
}

BCS_RESULT graphics_d3d12_top_level_acceleration_structure_destroy(c_graphics_top_level_acceleration_structure_d3d12* top_level_acceleration_structure)
{
	BCS_VALIDATE_ARGUMENT(top_level_acceleration_structure != nullptr);

	try
	{
		delete top_level_acceleration_structure;
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

BCS_RESULT graphics_d3d12_bottom_level_acceleration_structure_create(
	c_graphics_d3d12* graphics,
	c_graphics_geometry_d3d12* geometry,
	c_graphics_bottom_level_acceleration_structure_d3d12*& bottom_level_acceleration_structure,
	const char* debug_name)
{
	BCS_VALIDATE_ARGUMENT(geometry != nullptr);

	if (graphics->raytracing_mode == _graphics_raytracing_mode_d3d12_unsupported)
	{
		return BCS_E_UNSUPPORTED;
	}

	BCS_CHAR_TO_WIDECHAR_STACK(debug_name, debug_name_wc);
	try
	{
		bottom_level_acceleration_structure = new() c_graphics_bottom_level_acceleration_structure_d3d12(
			*graphics,
			*geometry,
			debug_name_wc);

		BCS_RESULT rs = BCS_S_OK;

		if (BCS_FAILED(rs = bottom_level_acceleration_structure->acceleration_structure_prebuild()))
		{
			delete bottom_level_acceleration_structure;
			return rs;
		}

		if (BCS_FAILED(rs = bottom_level_acceleration_structure->acceleration_structure_build()))
		{
			delete bottom_level_acceleration_structure;
			return rs;
		}

		return rs;
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FATAL;
	}
	return BCS_S_OK;
}

BCS_RESULT graphics_d3d12_bottom_level_acceleration_structure_destroy(c_graphics_bottom_level_acceleration_structure_d3d12* bottom_level_acceleration_structure)
{
	BCS_VALIDATE_ARGUMENT(bottom_level_acceleration_structure != nullptr);

	try
	{
		delete bottom_level_acceleration_structure;
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
