#include "graphicslib-private-pch.h"

using namespace DirectX;

void create_model(const char* obj_filepath, const char* geometry_filepath)
{
	bool requires_update = true;

	// #TODO: Create memory mapped files
	char* obj_buffer = nullptr;
	size_t obj_buffer_size = 0;
	bool obj_file_exists = read_file_to_memory(obj_filepath, (void**)&obj_buffer, &obj_buffer_size);
	ASSERT(obj_file_exists);
	XXH32_hash_t obj_xxhash_32_hash = XXH32(obj_buffer, obj_buffer_size, 0);

	// #TODO: Create memory mapped files
	char* model_buffer = nullptr;
	size_t model_buffer_size = 0;
	bool model_file_exists = read_file_to_memory(geometry_filepath, (void**)&model_buffer, &model_buffer_size); // #TODO: Limit the number of bytes to the header size as we don't need any more
	if (model_file_exists && model_buffer_size > sizeof(s_geometry_file_header))
	{
		s_geometry_file_header* geometry_file_header = reinterpret_cast<s_geometry_file_header*>(model_buffer);

		if (geometry_file_header->magic == c_mesh_geometry_d3d12::k_file_magic && obj_xxhash_32_hash == geometry_file_header->xxhash_32_hash)
		{
			requires_update = false;
		}
	}

	if (requires_update)
	{
		printf("Building geometry cache '%s'\n", geometry_filepath);

		std::vector<s_geometry_instance_header> geometry_instance_headers;
		std::vector<char> geometry_data;
		s_geometry_file_header geometry_file_header{};
		geometry_file_header.magic = c_mesh_geometry_d3d12::k_file_magic;
		geometry_file_header.xxhash_32_hash = obj_xxhash_32_hash;
		{
			tinyobj::attrib_t attrib;
			std::vector<tinyobj::shape_t> shapes;
			std::vector<tinyobj::material_t> materials;

			{
				std::string tinyobj_warnings;
				std::string tinyobj_errors;
				bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &tinyobj_warnings, &tinyobj_errors, obj_filepath);

				if (!tinyobj_warnings.empty())
				{
					printf("tinyobj:warn> %s\n", tinyobj_warnings.c_str());
				}

				if (!tinyobj_errors.empty())
				{
					printf("tinyobj:err> %s\n", tinyobj_errors.c_str());
				}
			}

			std::vector<s_geometry_vertex_position> position_vertices;
			std::vector<s_geometry_vertex_extra> vertices;
			std::vector<unsigned long> indices;
			for (const tinyobj::shape_t& shape : shapes)
			{
				s_geometry_instance_header& geometry_instance_header = geometry_instance_headers.emplace_back();

				// store the name
				_snwprintf(geometry_instance_header.instance_name, _countof(geometry_instance_header.instance_name) - 1, L"%S", shape.name.c_str());
				printf("creating geometry instance %s\n", shape.name.c_str());

				position_vertices.reserve(position_vertices.size() + shape.mesh.indices.size());
				vertices.reserve(vertices.size() + shape.mesh.indices.size());
				indices.reserve(indices.size() + shape.mesh.indices.size());

				for (const tinyobj::index_t& mesh_index : shape.mesh.indices)
				{
					size_t const vertex_index = static_cast<size_t>(mesh_index.vertex_index) * 3;
					size_t const texcoord_index = static_cast<size_t>(mesh_index.texcoord_index) * 2;
					size_t const normal_index = static_cast<size_t>(mesh_index.normal_index) * 3;


					s_geometry_vertex_position vs_input_position;
					s_geometry_vertex_extra vs_input_extra;

					vs_input_position.position.x = attrib.vertices[vertex_index];
					vs_input_position.position.y = attrib.vertices[vertex_index + 1];
					vs_input_position.position.z = attrib.vertices[vertex_index + 2];

					vs_input_extra.texcoord.x = attrib.texcoords[texcoord_index];
					vs_input_extra.texcoord.y = attrib.texcoords[texcoord_index + 1];

					vs_input_extra.color.x = attrib.colors[vertex_index];
					vs_input_extra.color.y = attrib.colors[vertex_index + 1];
					vs_input_extra.color.z = attrib.colors[vertex_index + 2];
					//vs_input_extra.color.w = attrib.colors[vertex_index + 3];
					vs_input_extra.color.w = 1.0f;

					if (mesh_index.normal_index > 0)
					{
						vs_input_extra.normal.x = attrib.normals[normal_index];
						vs_input_extra.normal.y = attrib.normals[normal_index + 1];
						vs_input_extra.normal.z = attrib.normals[normal_index + 2];
					}
					else
					{
						vs_input_extra.normal.x = 0.0;
						vs_input_extra.normal.y = 0.0;
						vs_input_extra.normal.z = 0.0;
					}

					position_vertices.push_back(vs_input_position);
					vertices.push_back(vs_input_extra);
					indices.push_back(static_cast<unsigned long>(indices.size()));
				}
			}

			for (size_t i = 0; i < indices.size(); i += 3) // flip faces
			{
				{
					//r_vs_input& a = vertices[indices[i + 0]];
					auto& b = position_vertices[indices[i + 1]];
					auto& c = position_vertices[indices[i + 2]];

					auto temp = b;
					b = c;
					c = temp;
				}
				{
					//r_vs_input& a = vertices[indices[i + 0]];
					auto& b = vertices[indices[i + 1]];
					auto& c = vertices[indices[i + 2]];

					auto temp = b;
					b = c;
					c = temp;
				}
			}

			{
				geometry_file_header.index_count = static_cast<unsigned long>(indices.size());
				geometry_file_header.index_data_offset = static_cast<unsigned long>(geometry_data.size());
				geometry_file_header.index_data_size = static_cast<unsigned long>(indices.size() * sizeof(vertices[0]));

				char* indices_data_begin = reinterpret_cast<char*>(indices.data());
				char* indices_data_end = reinterpret_cast<char*>(indices.data() + indices.size());
				geometry_data.insert(geometry_data.end(), indices_data_begin, indices_data_end);
			}

			geometry_file_header.vertex_count = static_cast<unsigned long>(vertices.size());

			{
				geometry_file_header.position_vertex_data_offset = static_cast<unsigned long>(geometry_data.size());
				geometry_file_header.position_vertex_data_size = static_cast<unsigned long>(position_vertices.size() * sizeof(position_vertices[0]));

				char* position_vertex_data_begin = reinterpret_cast<char*>(position_vertices.data());
				char* position_vertex_data_end = reinterpret_cast<char*>(position_vertices.data() + position_vertices.size());
				geometry_data.insert(geometry_data.end(), position_vertex_data_begin, position_vertex_data_end);
			}

			{
				geometry_file_header.vertex_data_offset = static_cast<unsigned long>(geometry_data.size());
				geometry_file_header.vertex_data_size = static_cast<unsigned long>(vertices.size() * sizeof(vertices[0]));

				char* vertex_data_begin = reinterpret_cast<char*>(vertices.data());
				char* vertex_data_end = reinterpret_cast<char*>(vertices.data() + vertices.size());
				geometry_data.insert(geometry_data.end(), vertex_data_begin, vertex_data_end);
			}

		}

		char* geometry_instance_headers_data_begin = reinterpret_cast<char*>(geometry_instance_headers.data());
		char* geometry_instance_headers_data_end = reinterpret_cast<char*>(geometry_instance_headers.data() + geometry_instance_headers.size());
		geometry_data.insert(geometry_data.begin(), geometry_instance_headers_data_begin, geometry_instance_headers_data_end);

		geometry_file_header.num_instances = static_cast<unsigned long>(geometry_instance_headers.size());

		char* geometry_file_header_data_begin = reinterpret_cast<char*>(&geometry_file_header);
		char* geometry_file_header_data_end = geometry_file_header_data_begin + sizeof(s_geometry_file_header);
		geometry_data.insert(geometry_data.begin(), geometry_file_header_data_begin, geometry_file_header_data_end);

		bool geometry_file_write_success = write_file_from_memory(geometry_filepath, geometry_data.data(), geometry_data.size());
		ASSERT(geometry_file_write_success);
	}
	else
	{
		printf("Model '%s' is up to date\n", obj_filepath);
	}

	if (model_buffer != nullptr) delete[] model_buffer;
	if (obj_buffer != nullptr) delete[] obj_buffer;
}

c_geometry_d3d12::c_geometry_d3d12(c_graphics_d3d12& graphics) :
	index_buffer_view(),
	vertex_buffer_views(),
	vertex_buffer_view_count(),
	primitive_topology(D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST),
	graphics(graphics)
{

}

c_geometry_d3d12::~c_geometry_d3d12()
{

}

void c_geometry_d3d12::draw_instanced(unsigned long count)
{
	graphics.command_list->IASetPrimitiveTopology(primitive_topology);
	graphics.command_list->IASetVertexBuffers(0, vertex_buffer_view_count, vertex_buffer_views);
	if (index_buffer_view)
	{
		graphics.command_list->IASetIndexBuffer(index_buffer_view);
		graphics.command_list->DrawIndexedInstanced(index_count, count, 0, 0, 0);
	}
	else
	{
		graphics.command_list->DrawInstanced(index_count, count, 0, 0);
	}
}

c_mesh_geometry_d3d12::c_mesh_geometry_d3d12(c_graphics_d3d12& graphics, const char* obj_filepath) :
	c_geometry_d3d12(graphics),
	position_vertex_buffer(nullptr),
	vertex_buffer(nullptr),
	position_vertex_buffer_view(),
	vertex_buffer_view(),
	memory_mapped_file(nullptr),
	geometry_file_header(nullptr),
	geometry_instance_headers(nullptr),
	geometry_data(nullptr),
	obj_filepath(obj_filepath),
	geometry_filepath(this->obj_filepath + k_file_extension)
{
	index_buffer_view = nullptr;
	c_geometry_d3d12::vertex_buffer_views = c_mesh_geometry_d3d12::vertex_buffer_views;
	vertex_buffer_view_count = _countof(c_mesh_geometry_d3d12::vertex_buffer_views);
	primitive_topology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	create_model(obj_filepath, geometry_filepath.c_str());

	memory_mapped_file = new c_memory_mapped_file(geometry_filepath.c_str());
	ASSERT(memory_mapped_file->get_data() != nullptr);
	//ASSERT(memory_mapped_file->get_size() >= sizeof(s_geometry_file_header));

	geometry_file_header = reinterpret_cast<const s_geometry_file_header*>(memory_mapped_file->get_data());
	geometry_instance_headers = reinterpret_cast<const s_geometry_instance_header*>(geometry_file_header + 1);
	geometry_data = reinterpret_cast<const char*>(geometry_instance_headers + geometry_file_header->num_instances);

	const void* index_data = geometry_data + geometry_file_header->index_data_offset;
	const void* position_vertex_data = geometry_data + geometry_file_header->position_vertex_data_offset;
	const void* vertex_data = geometry_data + geometry_file_header->vertex_data_offset;

	//index_count = geometry_file_header->index_count;
	//vertex_count = geometry_file_header->index_count;

	// #TODO: implement index buffer

	index_count = geometry_file_header->vertex_count;
	vertex_count = geometry_file_header->vertex_count;

	{
		UINT64 position_vertex_buffer_size = geometry_file_header->position_vertex_data_size;

		// Note: using upload heaps to transfer static data like vert buffers is not 
		// recommended. Every time the GPU needs it, the upload heap will be marshalled 
		// over. Please read up on Default Heap usage. An upload heap is used here for 
		// code simplicity and because there are very few verts to actually transfer.
		CD3DX12_HEAP_PROPERTIES const upload_heap_properties(D3D12_HEAP_TYPE_UPLOAD);
		CD3DX12_RESOURCE_DESC const resource_description = CD3DX12_RESOURCE_DESC::Buffer(position_vertex_buffer_size);
		HRESULT create_committed_resource_result = graphics.device->CreateCommittedResource(
			&upload_heap_properties,
			D3D12_HEAP_FLAG_NONE,
			&resource_description,
			D3D12_RESOURCE_STATE_GENERIC_READ,
			nullptr,
			IID_PPV_ARGS(&position_vertex_buffer));
		ASSERT(SUCCEEDED(create_committed_resource_result));
		position_vertex_buffer->SetName(L"c_model_d3d12::position_vertex_buffer");

		// Copy the triangle data to the vertex buffer.
		void* position_vertex_buffer_memory;
		CD3DX12_RANGE read_range(0, 0); // We do not intend to read from this resource on the CPU.
		HRESULT map_result = position_vertex_buffer->Map(0, &read_range, &position_vertex_buffer_memory);
		ASSERT(SUCCEEDED(map_result));
		memcpy(position_vertex_buffer_memory, position_vertex_data, position_vertex_buffer_size);
		position_vertex_buffer->Unmap(0, nullptr);

		// Initialize the vertex buffer view.
		position_vertex_buffer_view.BufferLocation = position_vertex_buffer->GetGPUVirtualAddress();
		position_vertex_buffer_view.StrideInBytes = sizeof(s_geometry_vertex_position);
		position_vertex_buffer_view.SizeInBytes = static_cast<UINT>(position_vertex_buffer_size);
	}

	{
		UINT64 position_vertex_buffer_size = geometry_file_header->position_vertex_data_size;
		UINT64 vertex_buffer_size = geometry_file_header->vertex_data_size;

		// Note: using upload heaps to transfer static data like vert buffers is not 
		// recommended. Every time the GPU needs it, the upload heap will be marshalled 
		// over. Please read up on Default Heap usage. An upload heap is used here for 
		// code simplicity and because there are very few verts to actually transfer.
		CD3DX12_HEAP_PROPERTIES const upload_heap_properties(D3D12_HEAP_TYPE_UPLOAD);
		CD3DX12_RESOURCE_DESC const resource_description = CD3DX12_RESOURCE_DESC::Buffer(vertex_buffer_size);
		HRESULT create_committed_resource_result = graphics.device->CreateCommittedResource(
			&upload_heap_properties,
			D3D12_HEAP_FLAG_NONE,
			&resource_description,
			D3D12_RESOURCE_STATE_GENERIC_READ,
			nullptr,
			IID_PPV_ARGS(&vertex_buffer));
		ASSERT(SUCCEEDED(create_committed_resource_result));
		vertex_buffer->SetName(L"c_model_d3d12::vertex_buffer");

		// Copy the triangle data to the vertex buffer.
		UINT8* vertex_buffer_memory;
		CD3DX12_RANGE read_range(0, 0); // We do not intend to read from this resource on the CPU.
		HRESULT map_result = vertex_buffer->Map(0, &read_range, reinterpret_cast<void**>(&vertex_buffer_memory));
		ASSERT(SUCCEEDED(map_result));
		memcpy(vertex_buffer_memory, vertex_data, vertex_buffer_size);
		vertex_buffer->Unmap(0, nullptr);

		vertex_buffer_view.BufferLocation = vertex_buffer->GetGPUVirtualAddress();
		vertex_buffer_view.StrideInBytes = sizeof(s_geometry_vertex_extra);
		vertex_buffer_view.SizeInBytes = static_cast<UINT>(vertex_buffer_size);
	}
}

c_mesh_geometry_d3d12::~c_mesh_geometry_d3d12()
{
	ULONG position_vertex_buffer_reference_count = position_vertex_buffer->Release();
	ASSERT(position_vertex_buffer_reference_count == 0);

	ULONG vertex_buffer_reference_count = vertex_buffer->Release();
	ASSERT(vertex_buffer_reference_count == 0);

	delete memory_mapped_file;
}

c_solid_box_geometry_d3d12::c_solid_box_geometry_d3d12(c_graphics_d3d12& graphics) :
	c_geometry_d3d12(graphics),
	index_buffer_view(),
	vertex_buffer_view(),
	buffer(nullptr)
{
	c_geometry_d3d12::index_buffer_view = &index_buffer_view;
	c_geometry_d3d12::vertex_buffer_views = &vertex_buffer_view;
	vertex_buffer_view_count = 1;
	primitive_topology = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	static float3 positions[8] =
	{
		{ -.5f, 0.5f, -.5f },
		{ 0.5f, 0.5f, -.5f },
		{ -.5f, -.5f, -.5f },
		{ 0.5f, -.5f, -.5f },
		{ -.5f, 0.5f, 0.5f },
		{ 0.5f, 0.5f, 0.5f },
		{ -.5f, -.5f, 0.5f },
		{ 0.5f, -.5f, 0.5f },
	};

	unsigned short indices[12][3] =
	{
		{ 0, 1, 2},    // side 1
		{ 2, 1, 3},
		{ 4, 0, 6},    // side 2
		{ 6, 0, 2},
		{ 7, 5, 6},    // side 3
		{ 6, 5, 4},
		{ 3, 1, 7},    // side 4
		{ 7, 1, 5},
		{ 4, 5, 0},    // side 5
		{ 0, 5, 1},
		{ 3, 7, 2},    // side 6
		{ 2, 7, 6},
	};

	index_count = 36;
	vertex_count = 8;

	UINT indices_data_size = sizeof(indices);
	UINT position_data_size = sizeof(positions);

	{
		UINT buffer_size = indices_data_size + position_data_size;

		CD3DX12_HEAP_PROPERTIES const upload_heap_properties(D3D12_HEAP_TYPE_UPLOAD);
		CD3DX12_RESOURCE_DESC const resource_description = CD3DX12_RESOURCE_DESC::Buffer(buffer_size);
		HRESULT create_committed_resource_result = graphics.device->CreateCommittedResource(
			&upload_heap_properties,
			D3D12_HEAP_FLAG_NONE,
			&resource_description,
			D3D12_RESOURCE_STATE_GENERIC_READ,
			nullptr,
			IID_PPV_ARGS(&buffer));
		ASSERT(SUCCEEDED(create_committed_resource_result));
		buffer->SetName(L"c_solid_box_geometry_d3d12::buffer");
	}

	{
		UINT8* buffer_memory;
		CD3DX12_RANGE read_range(0, 0);
		HRESULT map_result = buffer->Map(0, &read_range, reinterpret_cast<void**>(&buffer_memory));
		ASSERT(SUCCEEDED(map_result));

		memcpy(buffer_memory, indices, indices_data_size);
		buffer_memory += indices_data_size;

		memcpy(buffer_memory, positions, position_data_size);
		buffer_memory += position_data_size;

		buffer->Unmap(0, nullptr);
	}

	{
		D3D12_GPU_VIRTUAL_ADDRESS buffer_location = buffer->GetGPUVirtualAddress();

		index_buffer_view.BufferLocation = buffer_location;
		index_buffer_view.SizeInBytes = indices_data_size;
		index_buffer_view.Format = DXGI_FORMAT_R16_UINT;

		buffer_location += indices_data_size;

		vertex_buffer_view.BufferLocation = buffer_location;
		vertex_buffer_view.SizeInBytes = position_data_size;
		vertex_buffer_view.StrideInBytes = sizeof(float3);

		buffer_location += position_data_size;
	}
}

c_solid_box_geometry_d3d12::~c_solid_box_geometry_d3d12()
{
	ULONG buffer_reference_count = buffer->Release();
	ASSERT(buffer_reference_count == 0);
}

c_wireframe_box_geometry_d3d12::c_wireframe_box_geometry_d3d12(c_graphics_d3d12& graphics) :
	c_geometry_d3d12(graphics),
	index_buffer_view(),
	vertex_buffer_view(),
	buffer(nullptr)
{
	c_geometry_d3d12::index_buffer_view = &index_buffer_view;
	c_geometry_d3d12::vertex_buffer_views = &vertex_buffer_view;
	vertex_buffer_view_count = 1;
	primitive_topology = D3D_PRIMITIVE_TOPOLOGY_LINELIST;

	static float3 positions[8] =
	{
		{ -.5f, -.5f, 0.5f },
		{ -.5f, -.5f, -.5f },
		{ 0.5f, -.5f, -.5f },
		{ 0.5f, -.5f, 0.5f },
		{ -.5f, 0.5f, 0.5f },
		{ -.5f, 0.5f, -.5f },
		{ 0.5f, 0.5f, -.5f },
		{ 0.5f, 0.5f, 0.5f },
	};

	unsigned short indices[12][2] =
	{
		{ 0, 1 }, // bottom
		{ 1, 2 },
		{ 2, 3 },
		{ 3, 0 },

		{ 4, 5 }, // top
		{ 5, 6 },
		{ 6, 7 },
		{ 7, 4 },

		{ 0, 4 }, // pillars
		{ 1, 5 },
		{ 2, 6 },
		{ 3, 7 },
	};

	index_count = 24;
	vertex_count = 8;

	UINT indices_data_size = sizeof(indices);
	UINT position_data_size = sizeof(positions);

	{
		UINT buffer_size = indices_data_size + position_data_size;

		CD3DX12_HEAP_PROPERTIES const upload_heap_properties(D3D12_HEAP_TYPE_UPLOAD);
		CD3DX12_RESOURCE_DESC const resource_description = CD3DX12_RESOURCE_DESC::Buffer(buffer_size);
		HRESULT create_committed_resource_result = graphics.device->CreateCommittedResource(
			&upload_heap_properties,
			D3D12_HEAP_FLAG_NONE,
			&resource_description,
			D3D12_RESOURCE_STATE_GENERIC_READ,
			nullptr,
			IID_PPV_ARGS(&buffer));
		ASSERT(SUCCEEDED(create_committed_resource_result));
		buffer->SetName(L"c_wireframe_box_geometry_d3d12::buffer");
	}

	{
		UINT8* buffer_memory;
		CD3DX12_RANGE read_range(0, 0);
		HRESULT map_result = buffer->Map(0, &read_range, reinterpret_cast<void**>(&buffer_memory));
		ASSERT(SUCCEEDED(map_result));

		memcpy(buffer_memory, indices, indices_data_size);
		buffer_memory += indices_data_size;

		memcpy(buffer_memory, positions, position_data_size);
		buffer_memory += position_data_size;

		buffer->Unmap(0, nullptr);
	}

	{
		D3D12_GPU_VIRTUAL_ADDRESS buffer_location = buffer->GetGPUVirtualAddress();

		index_buffer_view.BufferLocation = buffer_location;
		index_buffer_view.SizeInBytes = indices_data_size;
		index_buffer_view.Format = DXGI_FORMAT_R16_UINT;

		buffer_location += indices_data_size;

		vertex_buffer_view.BufferLocation = buffer_location;
		vertex_buffer_view.SizeInBytes = position_data_size;
		vertex_buffer_view.StrideInBytes = sizeof(float3);

		buffer_location += position_data_size;
	}
}

c_wireframe_box_geometry_d3d12::~c_wireframe_box_geometry_d3d12()
{
	ULONG buffer_reference_count = buffer->Release();
	ASSERT(buffer_reference_count == 0);
}

c_sphere_geometry_d3d12::c_sphere_geometry_d3d12(c_graphics_d3d12& graphics) :
	c_geometry_d3d12(graphics),
	index_buffer_view(),
	vertex_buffer_view(),
	buffer(nullptr)
{
	c_geometry_d3d12::index_buffer_view = &index_buffer_view;
	c_geometry_d3d12::vertex_buffer_views = &vertex_buffer_view;
	vertex_buffer_view_count = 1;
	primitive_topology = D3D_PRIMITIVE_TOPOLOGY_LINESTRIP;

#define NUM_SEGMENTS 128

	float3 positions[3][NUM_SEGMENTS];
	unsigned short indices[3][NUM_SEGMENTS + 2];

	unsigned long loop_index = 0;

	float pi = 3.14159265358979323846f;

	for (unsigned long position_index = 0; position_index < NUM_SEGMENTS; position_index++)
	{
		float scale = float(position_index) / float(NUM_SEGMENTS);
		float cos = cosf(scale * 2.0f * pi) * 0.5f;
		float sin = sinf(scale * 2.0f * pi) * 0.5f;

		positions[0][position_index] = { cos, 0.0f, sin };
		positions[1][position_index] = { 0.0f, cos, sin };
		positions[2][position_index] = { cos, sin, 0.0f };

		indices[0][position_index] = static_cast<unsigned short>(position_index) + NUM_SEGMENTS * 0;
		indices[1][position_index] = static_cast<unsigned short>(position_index) + NUM_SEGMENTS * 1;
		indices[2][position_index] = static_cast<unsigned short>(position_index) + NUM_SEGMENTS * 2;
	}
	indices[0][NUM_SEGMENTS] = NUM_SEGMENTS * 0;
	indices[1][NUM_SEGMENTS] = NUM_SEGMENTS * 1;
	indices[2][NUM_SEGMENTS] = NUM_SEGMENTS * 2;
	indices[0][NUM_SEGMENTS + 1] = UINT16_MAX;
	indices[1][NUM_SEGMENTS + 1] = UINT16_MAX;
	indices[2][NUM_SEGMENTS + 1] = UINT16_MAX;

	index_count = _countof(indices) * _countof(indices[0]);
	vertex_count = _countof(positions) * _countof(positions[0]);

	UINT indices_data_size = sizeof(indices);
	UINT position_data_size = sizeof(positions);

	{
		UINT buffer_size = indices_data_size + position_data_size;

		CD3DX12_HEAP_PROPERTIES const upload_heap_properties(D3D12_HEAP_TYPE_UPLOAD);
		CD3DX12_RESOURCE_DESC const resource_description = CD3DX12_RESOURCE_DESC::Buffer(buffer_size);
		HRESULT create_committed_resource_result = graphics.device->CreateCommittedResource(
			&upload_heap_properties,
			D3D12_HEAP_FLAG_NONE,
			&resource_description,
			D3D12_RESOURCE_STATE_GENERIC_READ,
			nullptr,
			IID_PPV_ARGS(&buffer));
		ASSERT(SUCCEEDED(create_committed_resource_result));
		buffer->SetName(L"c_wireframe_box_geometry_d3d12::buffer");
	}

	{
		UINT8* buffer_memory;
		CD3DX12_RANGE read_range(0, 0);
		HRESULT map_result = buffer->Map(0, &read_range, reinterpret_cast<void**>(&buffer_memory));
		ASSERT(SUCCEEDED(map_result));

		memcpy(buffer_memory, indices, indices_data_size);
		buffer_memory += indices_data_size;

		memcpy(buffer_memory, positions, position_data_size);
		buffer_memory += position_data_size;

		buffer->Unmap(0, nullptr);
	}

	{
		D3D12_GPU_VIRTUAL_ADDRESS buffer_location = buffer->GetGPUVirtualAddress();

		index_buffer_view.BufferLocation = buffer_location;
		index_buffer_view.SizeInBytes = indices_data_size;
		index_buffer_view.Format = DXGI_FORMAT_R16_UINT;

		buffer_location += indices_data_size;

		vertex_buffer_view.BufferLocation = buffer_location;
		vertex_buffer_view.SizeInBytes = position_data_size;
		vertex_buffer_view.StrideInBytes = sizeof(float3);

		buffer_location += position_data_size;
	}
}

c_sphere_geometry_d3d12::~c_sphere_geometry_d3d12()
{
	ULONG buffer_reference_count = buffer->Release();
	ASSERT(buffer_reference_count == 0);
}

c_line_geometry_d3d12::c_line_geometry_d3d12(c_graphics_d3d12& graphics) :
	c_geometry_d3d12(graphics),
	index_buffer_view(),
	vertex_buffer_view(),
	buffer(nullptr)
{
	//c_geometry_d3d12::index_buffer_view = &index_buffer_view;
	c_geometry_d3d12::vertex_buffer_views = &vertex_buffer_view;
	vertex_buffer_view_count = 1;
	primitive_topology = D3D_PRIMITIVE_TOPOLOGY_LINELIST;

	static float3 positions[] =
	{
		{ 0.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, -1.0f },
	};

	unsigned short indices[2] = { 0, 1 };

	index_count = 2;
	vertex_count = 8;

	UINT indices_data_size = sizeof(indices);
	UINT position_data_size = sizeof(positions);

	{
		UINT buffer_size = indices_data_size + position_data_size;

		CD3DX12_HEAP_PROPERTIES const upload_heap_properties(D3D12_HEAP_TYPE_UPLOAD);
		CD3DX12_RESOURCE_DESC const resource_description = CD3DX12_RESOURCE_DESC::Buffer(buffer_size);
		HRESULT create_committed_resource_result = graphics.device->CreateCommittedResource(
			&upload_heap_properties,
			D3D12_HEAP_FLAG_NONE,
			&resource_description,
			D3D12_RESOURCE_STATE_GENERIC_READ,
			nullptr,
			IID_PPV_ARGS(&buffer));
		ASSERT(SUCCEEDED(create_committed_resource_result));
		buffer->SetName(L"c_line_geometry_d3d12::buffer");
	}

	{
		UINT8* buffer_memory;
		CD3DX12_RANGE read_range(0, 0);
		HRESULT map_result = buffer->Map(0, &read_range, reinterpret_cast<void**>(&buffer_memory));
		ASSERT(SUCCEEDED(map_result));

		memcpy(buffer_memory, indices, indices_data_size);
		buffer_memory += indices_data_size;

		memcpy(buffer_memory, positions, position_data_size);
		buffer_memory += position_data_size;

		buffer->Unmap(0, nullptr);
	}

	{
		D3D12_GPU_VIRTUAL_ADDRESS buffer_location = buffer->GetGPUVirtualAddress();

		index_buffer_view.BufferLocation = buffer_location;
		index_buffer_view.SizeInBytes = indices_data_size;
		index_buffer_view.Format = DXGI_FORMAT_R16_UINT;

		buffer_location += indices_data_size;

		vertex_buffer_view.BufferLocation = buffer_location;
		vertex_buffer_view.SizeInBytes = position_data_size;
		vertex_buffer_view.StrideInBytes = sizeof(float3);

		buffer_location += position_data_size;
	}
}

c_line_geometry_d3d12::~c_line_geometry_d3d12()
{
	ULONG buffer_reference_count = buffer->Release();
	ASSERT(buffer_reference_count == 0);
}
