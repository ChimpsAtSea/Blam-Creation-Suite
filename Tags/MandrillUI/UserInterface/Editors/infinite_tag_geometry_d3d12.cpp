#include "mandrillui-private-pch.h"
//
//using namespace DirectX;
//
//c_infinite_tag_geometry_d3d12::c_infinite_tag_geometry_d3d12(c_graphics_d3d12& graphics, blofeld::infinite::h_render_model_definition& render_model, unsigned long mesh_index) :
//	c_geometry_d3d12(graphics),
//	index_buffer_view(),
//	vertex_buffer_views(),
//	buffer(nullptr),
//	render_model(render_model)
//{
//	c_geometry_d3d12::index_buffer_view = &index_buffer_view;
//	c_geometry_d3d12::vertex_buffer_views = vertex_buffer_views;
//	vertex_buffer_view_count = _countof(c_infinite_tag_geometry_d3d12::vertex_buffer_views);
//	primitive_topology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
//
//	render_model.render_geometry.compression_info_block;
//	render_model.render_geometry.mesh_package.flags;
//	render_model.render_geometry.mesh_package.mesh_resource_packing_policy;
//	render_model.render_geometry.mesh_package.total_index_buffer_count;
//	render_model.render_geometry.mesh_package.total_vertex_buffer_count;
//	render_model.render_geometry.mesh_package.mesh_resource_groups_block[0].mesh_resource;
//	render_model.render_geometry.mesh_package.index_resource_look_up_block;
//	render_model.render_geometry.mesh_package.vertex_resource_look_up_block;
//
//	struct wordVector4dNormalized
//	{
//		unsigned short i;
//		unsigned short j;
//		unsigned short k;
//		unsigned short l;
//	};
//	struct wordVector2dNormalized
//	{
//		unsigned short i;
//		unsigned short j;
//	};
//	struct packed_10_10_10_2_signedNormalisedPackedAsUnorm
//	{
//		unsigned long i : 10;
//		unsigned long j : 10;
//		unsigned long k : 10;
//		unsigned long l : 2;
//	};
//
//	std::vector<float3> vertex_positions;
//	std::vector<s_geometry_vertex_extra> vertex_auxiliarys;
//	std::vector<unsigned short> indices;
//	if (!render_model.render_geometry.mesh_package.mesh_resource_groups_block.empty())
//	{
//		auto mesh = render_model.render_geometry.meshes_block[mesh_index];
//		auto lod_render_data = mesh.lod_render_data_block[0];
//		word position_vertex_buffer_index = lod_render_data.vertex_buffer_indices[0].vertex_buffer_index; // #TODO: 19 of these here, 0 is position
//		word index_buffer_index = lod_render_data.index_buffer_index;
//
//		h_resource* mesh_resource = render_model.render_geometry.mesh_package.mesh_resource_groups_block[0].mesh_resource;
//
//		const char* resource_data = mesh_resource->data.data();
//
//		h_object* mesh_resource_object = mesh_resource->object;
//		if (blofeld::infinite::h_s_render_geometry_api_resource* render_geometry_api_resource = dynamic_cast<decltype(render_geometry_api_resource)>(mesh_resource_object))
//		{
//			blofeld::infinite::h_rasterizervertexbuffer& rasterizer_position_buffer = render_geometry_api_resource->pc_vertex_buffers_block[position_vertex_buffer_index];
//			blofeld::infinite::h_rasterizervertexbuffer& rasterizer_uv0_buffer = render_geometry_api_resource->pc_vertex_buffers_block[position_vertex_buffer_index + 1];
//			blofeld::infinite::h_rasterizervertexbuffer& rasterizer_normal_buffer = render_geometry_api_resource->pc_vertex_buffers_block[position_vertex_buffer_index + 2];
//			blofeld::infinite::h_rasterizerindexbuffer& rasterizerindexbuffer = render_geometry_api_resource->pc_index_buffers_block[index_buffer_index];
//			auto& compression_info = render_model.render_geometry.compression_info_block[0];
//
//			{
//				const wordVector4dNormalized* position_normalized_vectors = reinterpret_cast<const wordVector4dNormalized*>(resource_data + rasterizer_position_buffer.offset.value);
//				const wordVector2dNormalized* uv0_normalized_vectors = reinterpret_cast<const wordVector2dNormalized*>(resource_data + rasterizer_uv0_buffer.offset.value);
//				const packed_10_10_10_2_signedNormalisedPackedAsUnorm* normal_normalized_vectors = reinterpret_cast<const packed_10_10_10_2_signedNormalisedPackedAsUnorm*>(resource_data + rasterizer_normal_buffer.offset.value);
//				//const unsigned long* normal_normalized_vectors = reinterpret_cast<const unsigned long*>(resource_data + rasterizer_normal_buffer.offset.value);
//
//				for (unsigned long vertex_index = 0; vertex_index < rasterizer_position_buffer.count.value; vertex_index++)
//				{
//					{
//						const wordVector4dNormalized& position_normalized_vector = position_normalized_vectors[vertex_index];
//						float position_i = float(position_normalized_vector.i) / float(UINT16_MAX);
//						float position_j = float(position_normalized_vector.j) / float(UINT16_MAX);
//						float position_k = float(position_normalized_vector.k) / float(UINT16_MAX);
//
//						real_point3d position_bounds_0 = compression_info.position_bounds_0;
//						real_point3d position_bounds_1 = compression_info.position_bounds_1;
//
//						float position_x0 = position_bounds_0.x;
//						float position_x1 = position_bounds_0.y;
//						float position_y0 = position_bounds_0.z;
//						float position_y1 = position_bounds_1.x;
//						float position_z0 = position_bounds_1.y;
//						float position_z1 = position_bounds_1.z;
//
//						position_i = position_x0 + (position_x1 - position_x0) * position_i;
//						position_j = position_y0 + (position_y1 - position_y0) * position_j;
//						position_k = position_z0 + (position_z1 - position_z0) * position_k;
//
//						vertex_positions.push_back({ position_i, position_j, position_k });
//					}
//
//					s_geometry_vertex_extra& vertex_extra = vertex_auxiliarys.emplace_back();
//					{
//						vertex_extra.color = { 1.0f, 1.0f, 1.0f, 1.0f };
//					}
//					{
//						const wordVector2dNormalized& uv0_normalized_vector = uv0_normalized_vectors[vertex_index];
//
//						float texcoord_i = float(uv0_normalized_vector.i) / float(UINT16_MAX);
//						float texcoord_j = float(uv0_normalized_vector.j) / float(UINT16_MAX);
//
//						real_point2d uv0_bounds_0 = compression_info.texcoord_bounds_0;
//						real_point2d uv0_bounds_1 = compression_info.texcoord_bounds_1;
//
//						float texcoord_x0 = uv0_bounds_0.x;
//						float texcoord_x1 = uv0_bounds_0.y;
//						float texcoord_y0 = uv0_bounds_1.x;
//						float texcoord_y1 = uv0_bounds_1.y;
//
//						texcoord_i = texcoord_x0 + (texcoord_x1 - texcoord_x0) * texcoord_i;
//						texcoord_j = texcoord_y0 + (texcoord_y1 - texcoord_y0) * texcoord_j;
//
//						vertex_extra.texcoord = { texcoord_i, texcoord_j };
//					}
//					{
//						const packed_10_10_10_2_signedNormalisedPackedAsUnorm& normal_normalized_vector = normal_normalized_vectors[vertex_index];
//						const unsigned long& DHenN3 = *(unsigned long*)(&normal_normalized_vector);
//
//						float normal_i = float(normal_normalized_vector.i) / float(1023);
//						float normal_j = float(normal_normalized_vector.j) / float(1023);
//						float normal_k = float(normal_normalized_vector.k) / float(1023);
//						float normal_l = float(normal_normalized_vector.l) / float(3);
//						
//
//						printf("%i\n", (int)normal_normalized_vector.l);
//						normal_i = (2.0f * normal_i) - 1.0f;
//						normal_j = (2.0f * normal_j) - 1.0f;
//						normal_k = (2.0f * normal_k) - 1.0f;
//						normal_l = (2.0f * normal_l) - 1.0f;
//
//						float length = sqrtf(normal_i * normal_i + normal_j * normal_j + normal_k * normal_k);
//
//						normal_i /= length;
//						normal_j /= length;
//						normal_k /= length;
//
//						//unsigned long mask_x = 0x000003ff;
//						//unsigned long mask_y = 0x000ffc00;
//						//unsigned long mask_z = 0x3ff00000;
//						//unsigned long mask_w = 0xc0000000;
//
//						//const unsigned long& normal_normalized_vector = normal_normalized_vectors[vertex_index];
//
//						//unsigned long i = (normal_normalized_vector & mask_x) >> 0;
//						//unsigned long j = (normal_normalized_vector & mask_y) >> 10;
//						//unsigned long k = (normal_normalized_vector & mask_z) >> 20;
//						//unsigned long l = (normal_normalized_vector & mask_w) >> 30;
//
//						//float normal_i = float(k) / float(1023);
//						//float normal_j = float(j) / float(1023);
//						//float normal_k = float(i) / float(1023);
//						//float normal_l = float(l) / float(3);
//
//						//normal_i = (2.0f * normal_i) - 1.0f;
//						//normal_j = (2.0f * normal_j) - 1.0f;
//						//normal_k = (2.0f * normal_k) - 1.0f;
//						//normal_l = (2.0f * normal_l) - 1.0f;
//
//						vertex_extra.normal = { normal_i, normal_j, normal_k };
//					}
//				}
//			}
//			{
//				const unsigned short* source_indices = reinterpret_cast<const unsigned short*>(resource_data + rasterizerindexbuffer.offset.value);
//
//				for (unsigned long index_index = 0; index_index < rasterizerindexbuffer.count.value; index_index++)
//				{
//					const unsigned short& index = source_indices[index_index];
//
//					indices.push_back(index);
//				}
//			}
//		}
//
//
//		debug_point;
//	}
//
//	index_count = indices.size();
//	vertex_count = vertex_positions.size();
//
//	UINT indices_data_size = indices.size() * sizeof(indices[0]);
//	UINT vertex_position_data_size = vertex_positions.size() * sizeof(vertex_positions[0]);
//	UINT vertex_auxiliary_data_size = vertex_auxiliarys.size() * sizeof(vertex_auxiliarys[0]);
//
//	{
//		UINT buffer_size = indices_data_size + vertex_position_data_size;
//
//		CD3DX12_HEAP_PROPERTIES const upload_heap_properties(D3D12_HEAP_TYPE_UPLOAD);
//		CD3DX12_RESOURCE_DESC const resource_description = CD3DX12_RESOURCE_DESC::Buffer(buffer_size);
//		HRESULT create_committed_resource_result = graphics.device->CreateCommittedResource(
//			&upload_heap_properties,
//			D3D12_HEAP_FLAG_NONE,
//			&resource_description,
//			D3D12_RESOURCE_STATE_GENERIC_READ,
//			nullptr,
//			IID_PPV_ARGS(&buffer));
//		ASSERT(SUCCEEDED(create_committed_resource_result));
//		buffer->SetName(L"c_infinite_tag_geometry_d3d12::buffer");
//	}
//
//	{
//		UINT8* buffer_memory;
//		CD3DX12_RANGE read_range(0, 0);
//		HRESULT map_result = buffer->Map(0, &read_range, reinterpret_cast<void**>(&buffer_memory));
//		ASSERT(SUCCEEDED(map_result));
//
//		memcpy(buffer_memory, indices.data(), indices_data_size);
//		buffer_memory += indices_data_size;
//
//		memcpy(buffer_memory, vertex_positions.data(), vertex_position_data_size);
//		buffer_memory += vertex_position_data_size;
//
//		buffer->Unmap(0, nullptr);
//	}
//
//	{
//		D3D12_GPU_VIRTUAL_ADDRESS buffer_location = buffer->GetGPUVirtualAddress();
//
//		index_buffer_view.BufferLocation = buffer_location;
//		index_buffer_view.SizeInBytes = indices_data_size;
//		index_buffer_view.Format = DXGI_FORMAT_R16_UINT;
//
//		buffer_location += indices_data_size;
//
//		vertex_buffer_views[0].BufferLocation = buffer_location;
//		vertex_buffer_views[0].SizeInBytes = vertex_position_data_size;
//		vertex_buffer_views[0].StrideInBytes = sizeof(float3);
//
//		buffer_location += vertex_position_data_size;
//	}
//
//	{
//		UINT buffer_size = vertex_auxiliary_data_size;
//
//		CD3DX12_HEAP_PROPERTIES const upload_heap_properties(D3D12_HEAP_TYPE_UPLOAD);
//		CD3DX12_RESOURCE_DESC const resource_description = CD3DX12_RESOURCE_DESC::Buffer(buffer_size);
//		HRESULT create_committed_resource_result = graphics.device->CreateCommittedResource(
//			&upload_heap_properties,
//			D3D12_HEAP_FLAG_NONE,
//			&resource_description,
//			D3D12_RESOURCE_STATE_GENERIC_READ,
//			nullptr,
//			IID_PPV_ARGS(&buffer2));
//		ASSERT(SUCCEEDED(create_committed_resource_result));
//		buffer2->SetName(L"c_infinite_tag_geometry_d3d12::buffer2");
//	}
//
//	{
//		UINT8* buffer_memory;
//		CD3DX12_RANGE read_range(0, 0);
//		HRESULT map_result = buffer2->Map(0, &read_range, reinterpret_cast<void**>(&buffer_memory));
//		ASSERT(SUCCEEDED(map_result));
//
//		memcpy(buffer_memory, vertex_auxiliarys.data(), vertex_auxiliary_data_size);
//		buffer_memory += vertex_auxiliary_data_size;
//
//		buffer2->Unmap(0, nullptr);
//	}
//
//	{
//		D3D12_GPU_VIRTUAL_ADDRESS buffer_location = buffer2->GetGPUVirtualAddress();
//
//		vertex_buffer_views[1].BufferLocation = buffer_location;
//		vertex_buffer_views[1].SizeInBytes = vertex_auxiliary_data_size;
//		vertex_buffer_views[1].StrideInBytes = sizeof(s_geometry_vertex_extra);
//
//		buffer_location += vertex_auxiliary_data_size;
//	}
//}
//
//c_infinite_tag_geometry_d3d12::~c_infinite_tag_geometry_d3d12()
//{
//	ULONG buffer_reference_count = buffer->Release();
//	ASSERT(buffer_reference_count == 0);
//}
