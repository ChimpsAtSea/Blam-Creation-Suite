#include "mandrillui-private-pch.h"

struct wordVector4dNormalized
{
	unsigned short i;
	unsigned short j;
	unsigned short k;
	unsigned short l;
};

struct wordVector2dNormalized
{
	unsigned short i;
	unsigned short j;
};

struct packed_10_10_10_2_signedNormalisedPackedAsUnorm
{
	unsigned long i : 10;
	unsigned long j : 10;
	unsigned long k : 10;
	unsigned long l : 2;
};

c_infinite_tag_mesh::c_infinite_tag_mesh(
	c_graphics& graphics,
	blofeld::infinite::h_render_model_definition& render_model,
	unsigned long mesh_index) :
	graphics(graphics),
	render_model(render_model),
	vertex_layout(),
	index_buffer(),
	position_buffer(),
	texcoord_buffer(),
	color_buffer(),
	normal_buffer(),
	graphics_geometry()
{
	s_graphics_vertex_layout_description vertex_layout_descriptions[] =
	{
		{_graphics_vertex_layout_semantic_position, 0, _graphics_data_format_r32g32b32_float, 0},
		{_graphics_vertex_layout_semantic_texcoord, 0, _graphics_data_format_r32g32_float, 1},
		{_graphics_vertex_layout_semantic_color, 0, _graphics_data_format_r32g32b32a32_float, 2},
		{_graphics_vertex_layout_semantic_normal, 0, _graphics_data_format_r32g32b32_float, 3},
	};
	auto vertex_layout_result = graphics_vertex_layout_create(&graphics, vertex_layout_descriptions, _countof(vertex_layout_descriptions), vertex_layout);

	std::vector<float3> positions;
	std::vector<float2> texcoords;
	std::vector<float4> colors;
	std::vector<float3> normals;
	std::vector<unsigned long> indices;

	if (!render_model.render_geometry.mesh_package.mesh_resource_groups_block.empty())
	{
		auto& mesh = render_model.render_geometry.meshes_block[mesh_index];
		auto& lod_render_data = mesh.lod_render_data_block[0];
		word position_vertex_buffer_index = lod_render_data.vertex_buffer_indices[0].vertex_buffer_index; // #TODO: 19 of these here, 0 is position
		word index_buffer_index = lod_render_data.index_buffer_index;

		h_resource* mesh_resource = render_model.render_geometry.mesh_package.mesh_resource_groups_block[0].mesh_resource;

		if (mesh_resource)
		{
			const char* resource_data = mesh_resource->data.data();

			h_object* mesh_resource_object = mesh_resource->object;
			if (blofeld::infinite::h_s_render_geometry_api_resource* render_geometry_api_resource = dynamic_cast<decltype(render_geometry_api_resource)>(mesh_resource_object))
			{
				blofeld::infinite::h_rasterizervertexbuffer& rasterizer_position_buffer = render_geometry_api_resource->pc_vertex_buffers_block[position_vertex_buffer_index];
				blofeld::infinite::h_rasterizervertexbuffer& rasterizer_uv0_buffer = render_geometry_api_resource->pc_vertex_buffers_block[position_vertex_buffer_index + 1];
				blofeld::infinite::h_rasterizervertexbuffer& rasterizer_normal_buffer = render_geometry_api_resource->pc_vertex_buffers_block[position_vertex_buffer_index + 2];
				blofeld::infinite::h_rasterizerindexbuffer& rasterizerindexbuffer = render_geometry_api_resource->pc_index_buffers_block[index_buffer_index];
				auto& compression_info = render_model.render_geometry.compression_info_block[0];

				{
					const wordVector4dNormalized* position_normalized_vectors = reinterpret_cast<const wordVector4dNormalized*>(resource_data + rasterizer_position_buffer.offset.value);
					const wordVector2dNormalized* uv0_normalized_vectors = reinterpret_cast<const wordVector2dNormalized*>(resource_data + rasterizer_uv0_buffer.offset.value);
					const packed_10_10_10_2_signedNormalisedPackedAsUnorm* normal_normalized_vectors = reinterpret_cast<const packed_10_10_10_2_signedNormalisedPackedAsUnorm*>(resource_data + rasterizer_normal_buffer.offset.value);
					//const unsigned long* normal_normalized_vectors = reinterpret_cast<const unsigned long*>(resource_data + rasterizer_normal_buffer.offset.value);

					for (unsigned long vertex_index = 0; vertex_index < rasterizer_position_buffer.count.value; vertex_index++)
					{
						{
							const wordVector4dNormalized& position_normalized_vector = position_normalized_vectors[vertex_index];
							float position_i = float(position_normalized_vector.i) / float(UINT16_MAX);
							float position_j = float(position_normalized_vector.j) / float(UINT16_MAX);
							float position_k = float(position_normalized_vector.k) / float(UINT16_MAX);

							real_point3d position_bounds_0 = compression_info.position_bounds_0;
							real_point3d position_bounds_1 = compression_info.position_bounds_1;

							float position_x0 = position_bounds_0.x;
							float position_x1 = position_bounds_0.y;
							float position_y0 = position_bounds_0.z;
							float position_y1 = position_bounds_1.x;
							float position_z0 = position_bounds_1.y;
							float position_z1 = position_bounds_1.z;

							position_i = position_x0 + (position_x1 - position_x0) * position_i;
							position_j = position_y0 + (position_y1 - position_y0) * position_j;
							position_k = position_z0 + (position_z1 - position_z0) * position_k;

							positions.push_back({ position_i, position_j, position_k });
						}

						{
							colors.push_back({ 1.0f, 1.0f, 1.0f, 1.0f });
						}

						{
							const wordVector2dNormalized& uv0_normalized_vector = uv0_normalized_vectors[vertex_index];

							float texcoord_i = float(uv0_normalized_vector.i) / float(UINT16_MAX);
							float texcoord_j = float(uv0_normalized_vector.j) / float(UINT16_MAX);

							real_point2d uv0_bounds_0 = compression_info.texcoord_bounds_0;
							real_point2d uv0_bounds_1 = compression_info.texcoord_bounds_1;

							float texcoord_x0 = uv0_bounds_0.x;
							float texcoord_x1 = uv0_bounds_0.y;
							float texcoord_y0 = uv0_bounds_1.x;
							float texcoord_y1 = uv0_bounds_1.y;

							texcoord_i = texcoord_x0 + (texcoord_x1 - texcoord_x0) * texcoord_i;
							texcoord_j = texcoord_y0 + (texcoord_y1 - texcoord_y0) * texcoord_j;

							texcoords.push_back({ texcoord_i, texcoord_j });
						}
						{
							const packed_10_10_10_2_signedNormalisedPackedAsUnorm& normal_normalized_vector = normal_normalized_vectors[vertex_index];
							const unsigned long& DHenN3 = *(unsigned long*)(&normal_normalized_vector);

							float normal_i = float(normal_normalized_vector.i) / float(1023);
							float normal_j = float(normal_normalized_vector.j) / float(1023);
							float normal_k = float(normal_normalized_vector.k) / float(1023);
							float normal_l = float(normal_normalized_vector.l) / float(3);


							//printf("%i\n", (int)normal_normalized_vector.l);
							normal_i = (2.0f * normal_i) - 1.0f;
							normal_j = (2.0f * normal_j) - 1.0f;
							normal_k = (2.0f * normal_k) - 1.0f;
							normal_l = (2.0f * normal_l) - 1.0f;

							float length = sqrtf(normal_i * normal_i + normal_j * normal_j + normal_k * normal_k);

							normal_i /= length;
							normal_j /= length;
							normal_k /= length;

							//unsigned long mask_x = 0x000003ff;
							//unsigned long mask_y = 0x000ffc00;
							//unsigned long mask_z = 0x3ff00000;
							//unsigned long mask_w = 0xc0000000;

							//const unsigned long& normal_normalized_vector = normal_normalized_vectors[vertex_index];

							//unsigned long i = (normal_normalized_vector & mask_x) >> 0;
							//unsigned long j = (normal_normalized_vector & mask_y) >> 10;
							//unsigned long k = (normal_normalized_vector & mask_z) >> 20;
							//unsigned long l = (normal_normalized_vector & mask_w) >> 30;

							//float normal_i = float(k) / float(1023);
							//float normal_j = float(j) / float(1023);
							//float normal_k = float(i) / float(1023);
							//float normal_l = float(l) / float(3);

							//normal_i = (2.0f * normal_i) - 1.0f;
							//normal_j = (2.0f * normal_j) - 1.0f;
							//normal_k = (2.0f * normal_k) - 1.0f;
							//normal_l = (2.0f * normal_l) - 1.0f;

							normals.push_back({ normal_i, normal_j, normal_k });
						}
					}
				}
				{
					const unsigned short* source_indices = reinterpret_cast<const unsigned short*>(resource_data + rasterizerindexbuffer.offset.value);

					for (unsigned long index_index = 0; index_index < rasterizerindexbuffer.count.value; index_index++)
					{
						const unsigned short& index = source_indices[index_index];

						indices.push_back(index);
					}
				}
			}

			auto position_buffer_result = graphics_buffer_create(&graphics, _graphics_buffer_type_generic, sizeof(float3), static_cast<unsigned long>(positions.size()), position_buffer);
			auto texcoord_buffer_result = graphics_buffer_create(&graphics, _graphics_buffer_type_generic, sizeof(float2), static_cast<unsigned long>(texcoords.size()), texcoord_buffer);
			auto color_buffer_result = graphics_buffer_create(&graphics, _graphics_buffer_type_generic, sizeof(float4), static_cast<unsigned long>(colors.size()), color_buffer);
			auto normal_buffer_result = graphics_buffer_create(&graphics, _graphics_buffer_type_generic, sizeof(float3), static_cast<unsigned long>(normals.size()), normal_buffer);
			auto index_buffer_result = graphics_buffer_create(&graphics, _graphics_buffer_type_generic, sizeof(unsigned long), static_cast<unsigned long>(indices.size()), index_buffer);

			position_buffer->write_data(positions.data(), sizeof(positions[0])* static_cast<unsigned long>(positions.size()));
			texcoord_buffer->write_data(texcoords.data(), sizeof(texcoords[0])* static_cast<unsigned long>(texcoords.size()));
			color_buffer->write_data(colors.data(), sizeof(colors[0])* static_cast<unsigned long>(colors.size()));
			normal_buffer->write_data(normals.data(), sizeof(normals[0])* static_cast<unsigned long>(normals.size()));
			index_buffer->write_data(indices.data(), sizeof(indices[0])* static_cast<unsigned long>(indices.size()));

			c_graphics_buffer* vertex_buffers[] =
			{
				position_buffer,
				texcoord_buffer,
				color_buffer,
				normal_buffer,
			};

			auto graphics_geometry_result = graphics_geometry_create(
				&graphics,
				index_buffer,
				static_cast<unsigned long>(indices.size()),
				vertex_buffers,
				_countof(vertex_buffers),
				vertex_layout,
				graphics_geometry);
		}

		debug_point;
	}
	
}

c_infinite_tag_mesh::~c_infinite_tag_mesh()
{
}
