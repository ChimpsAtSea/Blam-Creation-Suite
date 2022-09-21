#include "lightmapresearch-private-pch.h"


uint32_t viewport_width = 1024;
uint32_t viewport_height = 1024;

c_lightmap::c_lightmap()
{

}

c_lightmap::~c_lightmap()
{

}

#pragma push_macro("new")
#undef new
#include <assimp/cimport.h>        // Plain-C interface
#include <assimp/scene.h>          // Output data structure
#include <assimp/postprocess.h>    // Post processing flags
#pragma pop_macro("new")

#include <UVAtlas.h>
#include <DirectXMesh.h>

class c_mesh_data
{
public:
	std::vector<unsigned int> indices;
	std::vector<float3> positions;
	std::vector<float4> colors;
	std::vector<float3> normals;
	std::vector<float3> tangents;
	std::vector<float3> binormals;
	std::vector<float2> texcoords;
	unsigned long num_vertices;
	unsigned long num_faces;
	unsigned long num_indices;

	c_mesh_data(aiMesh* mesh)
	{
		num_vertices = mesh->mNumVertices;
		num_faces = mesh->mNumFaces;
		num_indices = num_faces * 3;

		for (unsigned int face_index = 0; face_index < num_faces; face_index++)
		{
			aiFace& face = mesh->mFaces[face_index];
			unsigned int num_indices = face.mNumIndices;
			ASSERT(num_indices == 3);
			for (unsigned int index = 0; index < num_indices; index++)
			{
				unsigned int vertex_index = face.mIndices[index];
				indices.push_back(vertex_index);
			}
		}

		bool has_color = mesh->HasVertexColors(0);
		for (unsigned int vertex_index = 0; vertex_index < num_vertices; vertex_index++)
		{
			aiVector3D& ai_vertex = mesh->mVertices[vertex_index];
			aiColor4D ai_colors = has_color ? mesh->mColors[0][vertex_index] : aiColor4D{ 1.0f, 1.0f, 1.0f, 1.0f };
			aiVector3D& ai_normals = mesh->mNormals[vertex_index];
			aiVector3D& ai_tangents = mesh->mTangents[vertex_index];
			aiVector3D& ai_bitangents = mesh->mBitangents[vertex_index];
			aiVector3D& ai_texcoord = mesh->mTextureCoords[0][vertex_index];

			positions.push_back({ ai_vertex.x, ai_vertex.y, ai_vertex.z });
			colors.push_back({ ai_colors.r, ai_colors.g, ai_colors.b, ai_colors.a });
			normals.push_back({ ai_normals.x, ai_normals.y, ai_normals.z });
			tangents.push_back({ ai_tangents.x, ai_tangents.y, ai_tangents.z });
			binormals.push_back({ ai_bitangents.x, ai_bitangents.y, ai_bitangents.z });
			texcoords.push_back({ ai_texcoord.x, ai_texcoord.y });
		}
	}
	~c_mesh_data()
	{

	}
};

class c_mesh_loader
{
public:
	const aiScene* assimp_scene;
	std::vector<c_mesh_data*> meshes;

	c_mesh_loader(const char* filepath)
	{
		assimp_scene = aiImportFile(filepath,
			aiProcess_CalcTangentSpace |
			aiProcess_Triangulate |
			aiProcess_JoinIdenticalVertices |
			aiProcess_SortByPType |
			aiProcess_GenNormals |
			aiProcess_GenBoundingBoxes);

		if (!assimp_scene)
		{
			const char* error_string = aiGetErrorString();
			throw;
		}

		unsigned long num_meshes = assimp_scene->mNumMeshes;
		//num_meshes = __min(num_meshes, 5);
		for (unsigned long mesh_index = 0; mesh_index < num_meshes; mesh_index++)
		{
			aiMesh* assimp_mesh = assimp_scene->mMeshes[mesh_index];
			c_mesh_data* mesh_data = new c_mesh_data(assimp_mesh);
			meshes.push_back(mesh_data);
		}
	}
	~c_mesh_loader()
	{
		aiReleaseImport(assimp_scene);
	}
};

struct s_uv_atlas_mesh_data_entry
{
	c_mesh_data* mesh_data;
	unsigned int bake_vertex_offset;
	unsigned int bake_index_offset;
	unsigned int bake_face_offset;
};

struct s_uv_atlas_packer
{
	std::vector<s_uv_atlas_mesh_data_entry> mesh_data_entries;
};

using h_uv_atlas_packer = void*;

BCS_RESULT create_uv_atlas_packer(h_uv_atlas_packer& uv_atlas_packer_handle)
{
	uv_atlas_packer_handle = new s_uv_atlas_packer();
	return BCS_S_OK;
}

BCS_RESULT uv_atlas_packer_add_mesh(h_uv_atlas_packer& uv_atlas_packer_handle, c_mesh_data* mesh_data)
{
	s_uv_atlas_packer* uv_atlas_packer = static_cast<s_uv_atlas_packer*>(uv_atlas_packer_handle);

	s_uv_atlas_mesh_data_entry& mesh_data_entry = uv_atlas_packer->mesh_data_entries.emplace_back();
	mesh_data_entry.mesh_data = mesh_data;
	
	return BCS_S_OK;
}

BCS_RESULT uv_atlas_packer_bake(h_uv_atlas_packer& uv_atlas_packer_handle)
{
	s_uv_atlas_packer* uv_atlas_packer = static_cast<s_uv_atlas_packer*>(uv_atlas_packer_handle);

	std::vector<DirectX::XMFLOAT3> dx_vertices;
	std::vector<DirectX::UVAtlasVertex> uv_atlas_vertices;
	std::vector<unsigned int> dx_indices;

	unsigned int num_meshes = static_cast<unsigned int>(uv_atlas_packer->mesh_data_entries.size());
	unsigned int num_bake_vertices = 0;
	unsigned int num_bake_indices = 0;
	unsigned int num_bake_faces = 0;
	for (unsigned int mesh_index = 0; mesh_index < num_meshes; mesh_index++)
	{
		s_uv_atlas_mesh_data_entry& mesh_data_entry = uv_atlas_packer->mesh_data_entries[mesh_index];

		mesh_data_entry.bake_vertex_offset = num_bake_vertices;
		mesh_data_entry.bake_index_offset = num_bake_indices;
		mesh_data_entry.bake_face_offset = num_bake_faces;

		unsigned int num_mesh_vertices = mesh_data_entry.mesh_data->num_vertices;
		unsigned int num_mesh_indices = mesh_data_entry.mesh_data->num_indices;
		unsigned int num_mesh_faces = mesh_data_entry.mesh_data->num_faces;

		unsigned int first_vertex_index = num_bake_vertices;
		unsigned int sanity = first_vertex_index + num_mesh_vertices;
		for (unsigned int indice_index = 0; indice_index < num_mesh_indices; indice_index++)
		{
			unsigned int mesh_index = mesh_data_entry.mesh_data->indices[indice_index];
			unsigned int bake_index = mesh_index + first_vertex_index;
			dx_indices.emplace_back(bake_index);

			ASSERT(bake_index < sanity);

			num_bake_indices++;
		}



		unsigned int bake_vertex_offset = num_bake_vertices;
		for (unsigned int vertex_index = 0; vertex_index < num_mesh_vertices; vertex_index++)
		{
			float3& position = mesh_data_entry.mesh_data->positions[vertex_index];
			float2& texcoord = mesh_data_entry.mesh_data->texcoords[vertex_index];

			DirectX::UVAtlasVertex& uv_atlas_vertex = uv_atlas_vertices.emplace_back();
			uv_atlas_vertex.pos = { position.x, position.y, position.z };
			uv_atlas_vertex.uv = { texcoord.x, texcoord.y };

			DirectX::XMFLOAT3& dx_vertex = dx_vertices.emplace_back();
			dx_vertex = { position.x, position.y, position.z };

			num_bake_vertices++;
		}

		num_bake_faces += num_mesh_faces;






		//unsigned int bake_index_offset = num_bake_indices;
		//unsigned int num_mesh_indices = mesh_data_entry.mesh_data->num_indices;
		//unsigned int sanity = bake_index_offset + num_mesh_vertices;
		//for (unsigned int indice_index = 0; indice_index < num_mesh_indices; indice_index++)
		//{
		//	unsigned int mesh_index = mesh_data_entry.mesh_data->indices[indice_index];
		//	unsigned int bake_index = mesh_index + bake_index_offset;
		//	dx_indices.emplace_back(bake_index);

		//	ASSERT(bake_index < sanity);

		//	num_bake_indices++;
		//}
		//// 
		//if (mesh_index == 1)
		//{
		//	unsigned int x = dx_indices[13086];
		//	debug_point;
		//}


	}

	std::vector<uint8_t> uv_atlas_index_data;
	uint8_t* indices_data_start = reinterpret_cast<uint8_t*>(dx_indices.data());
	uint8_t* indices_data_end = indices_data_start + dx_indices.size() * sizeof(dx_indices[0]);
	uv_atlas_index_data.insert(
		uv_atlas_index_data.begin(),
		indices_data_start,
		indices_data_end);

	std::vector<uint32_t> adjancencies;
	adjancencies.resize(num_bake_indices);
	HRESULT hrs0 = DirectX::GenerateAdjacencyAndPointReps(
		dx_indices.data(),
		num_bake_faces,
		dx_vertices.data(),
		num_bake_vertices,
		0.0f,
		nullptr,
		adjancencies.data());
	ASSERT(SUCCEEDED(hrs0));

	HRESULT hrs1 = DirectX::UVAtlasPack(
		uv_atlas_vertices,
		uv_atlas_index_data,
		DXGI_FORMAT_R32_UINT,
		viewport_width,
		viewport_height,
		1.0f,
		adjancencies,
		nullptr,
		0.0f);
	ASSERT(SUCCEEDED(hrs1));

	for (unsigned int mesh_index = 0; mesh_index < num_meshes; mesh_index++)
	{
		s_uv_atlas_mesh_data_entry& mesh_data_entry = uv_atlas_packer->mesh_data_entries[mesh_index];

		unsigned int num_mesh_vertices = mesh_data_entry.mesh_data->num_vertices;
		unsigned int bake_vertices_begin = mesh_data_entry.bake_vertex_offset;
		for (unsigned int vertex_index = 0; vertex_index < num_mesh_vertices; vertex_index++)
		{
			unsigned int bake_vertex_index = bake_vertices_begin + vertex_index;

			DirectX::UVAtlasVertex& uv_atlas_vertex = uv_atlas_vertices[bake_vertex_index];
			float2& texcoord = mesh_data_entry.mesh_data->texcoords[vertex_index];

			texcoord = { uv_atlas_vertex.uv.x, uv_atlas_vertex.uv.y };
		}
	}

	return BCS_S_OK;
}

BCS_RESULT destroy_uv_atlas_packer(h_uv_atlas_packer& uv_atlas_packer_handle)
{
	s_uv_atlas_packer* uv_atlas_packer = static_cast<s_uv_atlas_packer*>(uv_atlas_packer_handle);
	delete uv_atlas_packer;

	return BCS_S_OK;
}

class c_lightmap_render_mesh
{
public:
	c_graphics_buffer* index_buffer;
	c_graphics_buffer* vertex_position_buffer;
	c_graphics_buffer* vertex_colors_buffer;
	c_graphics_buffer* vertex_normals_buffer;
	c_graphics_buffer* vertex_tangents_buffer;
	c_graphics_buffer* vertex_binormals_buffer;
	c_graphics_buffer* vertex_texcoord_buffer;
	c_graphics_geometry* geometry;

	c_lightmap_render_mesh(c_graphics& graphics, c_graphics_vertex_layout* vertex_layout, c_mesh_data* mesh)
	{
		BCS_RESULT index_buffer_create_result = graphics_buffer_create(
			&graphics,
			_graphics_buffer_type_generic,
			sizeof(unsigned int),
			mesh->indices.size(),
			index_buffer,
			"Debug Triangle Index Buffer");
		BCS_FAIL_THROW(index_buffer_create_result);

		BCS_RESULT vertex_position_buffer_create_result = graphics_buffer_create(
			&graphics,
			_graphics_buffer_type_generic,
			sizeof(float3),
			mesh->positions.size(),
			vertex_position_buffer,
			"Debug Triangle Vertex Position Buffer");
		BCS_FAIL_THROW(vertex_position_buffer_create_result);

		BCS_RESULT vertex_colors_buffer_create_result = graphics_buffer_create(
			&graphics,
			_graphics_buffer_type_generic,
			sizeof(float4),
			mesh->colors.size(),
			vertex_colors_buffer,
			"Debug Triangle Vertex Color Buffer");
		BCS_FAIL_THROW(vertex_colors_buffer_create_result);

		BCS_RESULT vertex_normals_buffer_create_result = graphics_buffer_create(
			&graphics,
			_graphics_buffer_type_generic,
			sizeof(float3),
			mesh->normals.size(),
			vertex_normals_buffer,
			"Debug Triangle Vertex Normal Buffer");
		BCS_FAIL_THROW(vertex_normals_buffer_create_result);

		BCS_RESULT vertex_tangents_buffer_create_result = graphics_buffer_create(
			&graphics,
			_graphics_buffer_type_generic,
			sizeof(float3),
			mesh->tangents.size(),
			vertex_tangents_buffer,
			"Debug Triangle Vertex Tangent Buffer");
		BCS_FAIL_THROW(vertex_tangents_buffer_create_result);

		BCS_RESULT vertex_binormals_buffer_create_result = graphics_buffer_create(
			&graphics,
			_graphics_buffer_type_generic,
			sizeof(float3),
			mesh->binormals.size(),
			vertex_binormals_buffer,
			"Debug Triangle Vertex Binormal Buffer");
		BCS_FAIL_THROW(vertex_binormals_buffer_create_result);

		BCS_RESULT vertex_texcoord_buffer_create_result = graphics_buffer_create(
			&graphics,
			_graphics_buffer_type_generic,
			sizeof(float2),
			mesh->texcoords.size(),
			vertex_texcoord_buffer,
			"Debug Triangle Vertex Texcoord Buffer");
		BCS_FAIL_THROW(vertex_texcoord_buffer_create_result);

		BCS_RESULT write_index_buffer_result = index_buffer->write_data(mesh->indices.data(), sizeof(mesh->indices[0]), mesh->indices.size());
		BCS_RESULT write_vertex_position_buffer_result = vertex_position_buffer->write_data(mesh->positions.data(), sizeof(mesh->positions[0]), mesh->positions.size());
		BCS_RESULT write_vertex_colors_buffer_result = vertex_colors_buffer->write_data(mesh->colors.data(), sizeof(mesh->colors[0]), mesh->colors.size());
		BCS_RESULT write_vertex_normals_buffer_result = vertex_normals_buffer->write_data(mesh->normals.data(), sizeof(mesh->normals[0]), mesh->normals.size());
		BCS_RESULT write_vertex_tangents_buffer_result = vertex_tangents_buffer->write_data(mesh->tangents.data(), sizeof(mesh->tangents[0]), mesh->tangents.size());
		BCS_RESULT write_vertex_binormals_buffer_result = vertex_binormals_buffer->write_data(mesh->binormals.data(), sizeof(mesh->binormals[0]), mesh->binormals.size());
		BCS_RESULT write_vertex_texcoord_buffer_result = vertex_texcoord_buffer->write_data(mesh->texcoords.data(), sizeof(mesh->texcoords[0]), mesh->texcoords.size());

		BCS_FAIL_THROW(write_index_buffer_result);
		BCS_FAIL_THROW(write_vertex_position_buffer_result);
		BCS_FAIL_THROW(write_vertex_colors_buffer_result);
		BCS_FAIL_THROW(write_vertex_normals_buffer_result);
		BCS_FAIL_THROW(write_vertex_tangents_buffer_result);
		BCS_FAIL_THROW(write_vertex_binormals_buffer_result);
		BCS_FAIL_THROW(write_vertex_texcoord_buffer_result);

		c_graphics_buffer* vertex_buffers[] =
		{
			vertex_position_buffer,
			vertex_colors_buffer,
			vertex_normals_buffer,
			vertex_tangents_buffer,
			vertex_binormals_buffer,
			vertex_texcoord_buffer,
		};

		BCS_RESULT graphics_geometry_result = graphics_geometry_create(
			&graphics,
			index_buffer,
			static_cast<uint32_t>(mesh->indices.size()),
			vertex_buffers,
			_countof(vertex_buffers),
			vertex_layout,
			geometry);
	}

	~c_lightmap_render_mesh()
	{
		BCS_RESULT destroy_index_buffer_result = graphics_buffer_destroy(index_buffer);
		BCS_RESULT destroy_vertex_position_buffer_result = graphics_buffer_destroy(vertex_position_buffer);
		BCS_RESULT destroy_vertex_colors_buffer_result = graphics_buffer_destroy(vertex_colors_buffer);
		BCS_RESULT destroy_vertex_normals_buffer_result = graphics_buffer_destroy(vertex_normals_buffer);
		BCS_RESULT destroy_vertex_tangents_buffer_result = graphics_buffer_destroy(vertex_tangents_buffer);
		BCS_RESULT destroy_vertex_binormals_buffer_result = graphics_buffer_destroy(vertex_binormals_buffer);
		BCS_RESULT destroy_vertex_texcoord_buffer_result = graphics_buffer_destroy(vertex_texcoord_buffer);

		BCS_FAIL_THROW(destroy_index_buffer_result);
		BCS_FAIL_THROW(destroy_vertex_position_buffer_result);
		BCS_FAIL_THROW(destroy_vertex_colors_buffer_result);
		BCS_FAIL_THROW(destroy_vertex_normals_buffer_result);
		BCS_FAIL_THROW(destroy_vertex_tangents_buffer_result);
		BCS_FAIL_THROW(destroy_vertex_binormals_buffer_result);
		BCS_FAIL_THROW(destroy_vertex_texcoord_buffer_result);
	}
};

void c_lightmap::init(c_graphics& graphics)
{
	c_mesh_loader mesh_loader("C:\\GitHub\\Sponza\\sponza.obj");

	h_uv_atlas_packer uv_atlas_packer;
	BCS_RESULT create_uv_atlas_packer_result = create_uv_atlas_packer(uv_atlas_packer);
	BCS_FAIL_THROW(create_uv_atlas_packer_result);

	for (c_mesh_data* mesh : mesh_loader.meshes)
	{
		BCS_RESULT uv_atlas_packer_add_mesh_result = uv_atlas_packer_add_mesh(uv_atlas_packer, mesh);
		BCS_FAIL_THROW(uv_atlas_packer_add_mesh_result);
	}

	BCS_RESULT uv_atlas_packer_bake_result = uv_atlas_packer_bake(uv_atlas_packer);
	BCS_FAIL_THROW(uv_atlas_packer_bake_result);

	BCS_RESULT destroy_uv_atlas_packer_result = destroy_uv_atlas_packer(uv_atlas_packer);
	BCS_FAIL_THROW(destroy_uv_atlas_packer_result);



	union
	{
		s_graphics_vertex_layout_description vertex_layout_descriptions[6];
		struct
		{
			s_graphics_vertex_layout_description vertex_layout_position;
			s_graphics_vertex_layout_description vertex_layout_color;
			s_graphics_vertex_layout_description vertex_layout_normal;
			s_graphics_vertex_layout_description vertex_layout_tangent;
			s_graphics_vertex_layout_description vertex_layout_binormal;
			s_graphics_vertex_layout_description vertex_layout_uv;
		};
	};

	vertex_layout_position = {};
	vertex_layout_position.semantic = _graphics_vertex_layout_semantic_position;
	vertex_layout_position.semantic_index = 0;
	vertex_layout_position.data_format = _graphics_data_format_r32g32b32_float;
	vertex_layout_position.buffer_index = 0;
	vertex_layout_position.buffer_offset = 0;
	vertex_layout_position.stepping = _graphics_vertex_layout_stepping_per_vertex;
	vertex_layout_position.buffer_instance_stepping = 0;

	vertex_layout_color = {};
	vertex_layout_color.semantic = _graphics_vertex_layout_semantic_color;
	vertex_layout_color.semantic_index = 0;
	vertex_layout_color.data_format = _graphics_data_format_r32g32b32a32_float;
	vertex_layout_color.buffer_index = 1;
	vertex_layout_color.buffer_offset = 0;
	vertex_layout_color.stepping = _graphics_vertex_layout_stepping_per_vertex;
	vertex_layout_color.buffer_instance_stepping = 0;

	vertex_layout_normal = {};
	vertex_layout_normal.semantic = _graphics_vertex_layout_semantic_normal;
	vertex_layout_normal.semantic_index = 0;
	vertex_layout_normal.data_format = _graphics_data_format_r32g32b32_float;
	vertex_layout_normal.buffer_index = 2;
	vertex_layout_normal.buffer_offset = 0;
	vertex_layout_normal.stepping = _graphics_vertex_layout_stepping_per_vertex;
	vertex_layout_normal.buffer_instance_stepping = 0;

	vertex_layout_tangent = {};
	vertex_layout_tangent.semantic = _graphics_vertex_layout_semantic_tangent;
	vertex_layout_tangent.semantic_index = 0;
	vertex_layout_tangent.data_format = _graphics_data_format_r32g32b32_float;
	vertex_layout_tangent.buffer_index = 3;
	vertex_layout_tangent.buffer_offset = 0;
	vertex_layout_tangent.stepping = _graphics_vertex_layout_stepping_per_vertex;
	vertex_layout_tangent.buffer_instance_stepping = 0;

	vertex_layout_binormal = {};
	vertex_layout_binormal.semantic = _graphics_vertex_layout_semantic_binormal;
	vertex_layout_binormal.semantic_index = 0;
	vertex_layout_binormal.data_format = _graphics_data_format_r32g32b32_float;
	vertex_layout_binormal.buffer_index = 4;
	vertex_layout_binormal.buffer_offset = 0;
	vertex_layout_binormal.stepping = _graphics_vertex_layout_stepping_per_vertex;
	vertex_layout_binormal.buffer_instance_stepping = 0;

	vertex_layout_uv = {};
	vertex_layout_uv.semantic = _graphics_vertex_layout_semantic_texcoord;
	vertex_layout_uv.semantic_index = 0;
	vertex_layout_uv.data_format = _graphics_data_format_r32g32_float;
	vertex_layout_uv.buffer_index = 5;
	vertex_layout_uv.buffer_offset = 0;
	vertex_layout_uv.stepping = _graphics_vertex_layout_stepping_per_vertex;
	vertex_layout_uv.buffer_instance_stepping = 0;

	BCS_RESULT vertex_layout_result = graphics_vertex_layout_create(
		&graphics,
		vertex_layout_descriptions,
		_countof(vertex_layout_descriptions),
		vertex_layout);



	for (c_mesh_data* mesh_data : mesh_loader.meshes)
	{
		c_lightmap_render_mesh* lightmap_render_mesh = new() c_lightmap_render_mesh(graphics, vertex_layout, mesh_data);
		lightmap_render_meshes.push_back(lightmap_render_mesh);
	}


	c_graphics_shader_binary* graphics_shader_binaries[2];
	BCS_RESULT vertex_shader_binary_result = graphics_shader_binary_create(
		&graphics,
		_bcs_resource_type_generic_lightmap_debug_vertex_shader,
		graphics_shader_binaries[0]);
	BCS_FAIL_THROW(vertex_shader_binary_result);

	BCS_RESULT pixel_shader_binary_result = graphics_shader_binary_create(
		&graphics,
		_bcs_resource_type_generic_lightmap_debug_pixel_shader,
		graphics_shader_binaries[1]);
	BCS_FAIL_THROW(pixel_shader_binary_result);

	float4 render_target_clear_color = { 0.0f, 0.0f, 0.0f, 1.0f };

	BCS_RESULT create_position_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32_float, render_target_clear_color, position_render_target, "position_render_target");
	BCS_RESULT create_color_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32a32_float, render_target_clear_color, color_render_target, "color_render_target");
	BCS_RESULT create_normal_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32_float, render_target_clear_color, normal_render_target, "normal_render_target");
	BCS_RESULT create_tangent_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32_float, render_target_clear_color, tangent_render_target, "tangent_render_target");
	BCS_RESULT create_binormal_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32_float, render_target_clear_color, binormal_render_target, "binormal_render_target");
	BCS_RESULT create_uv_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32_float, render_target_clear_color, uv_render_target, "uv_render_target");

	BCS_FAIL_THROW(create_position_render_target_result);
	BCS_FAIL_THROW(create_color_render_target_result);
	BCS_FAIL_THROW(create_normal_render_target_result);
	BCS_FAIL_THROW(create_tangent_render_target_result);
	BCS_FAIL_THROW(create_binormal_render_target_result);
	BCS_FAIL_THROW(create_uv_render_target_result);

	e_graphics_data_format render_target_formats[] =
	{
		position_render_target->get_graphics_data_format(),
		color_render_target->get_graphics_data_format(),
		normal_render_target->get_graphics_data_format(),
		tangent_render_target->get_graphics_data_format(),
		binormal_render_target->get_graphics_data_format(),
		uv_render_target->get_graphics_data_format(),
	};
	e_graphics_data_format depth_target_format = _graphics_data_format_unspecified;

	BCS_RESULT shader_pipeline_result = graphics_shader_pipeline_create(
		&graphics,
		graphics_shader_binaries,
		_countof(graphics_shader_binaries),
		render_target_formats,
		_countof(render_target_formats),
		&depth_target_format,
		vertex_layout,
		shader_pipeline);
	BCS_FAIL_THROW(shader_pipeline_result);

	BCS_RESULT model_instance_create_result = graphics_render_instance_create(&graphics, render_instance);
	BCS_FAIL_THROW(model_instance_create_result);

	BCS_RESULT vertex_shader_binary_result2 = graphics_shader_binary_destroy(graphics_shader_binaries[0]);
	BCS_FAIL_THROW(vertex_shader_binary_result);

	BCS_RESULT pixel_shader_binary_result2 = graphics_shader_binary_destroy(graphics_shader_binaries[1]);
	BCS_FAIL_THROW(pixel_shader_binary_result);

	debug_point;

	viewport = new() c_viewport();
	viewport->set_size(viewport_width, viewport_height);

	// position_render_target
	// normal_render_target
	// tangent_render_target
	// binormal_render_target
	// uv_render_target



	BCS_RESULT create_render_pass_result = graphics_render_pass_create(
		&graphics,
		viewport,
		render_targets,
		nullptr,
		_countof(render_targets),
		0,
		_countof(render_targets),
		1,
		render_pass,
		"render_pass");
	BCS_FAIL_THROW(create_render_pass_result);

	render_pass->render_callback.add_callback(member_to_static_function(&c_lightmap::render_pass_callback), this, render_pass_callback_handle);
}

void c_lightmap::deinit(c_graphics& graphics)
{
	BCS_RESULT destroy_render_pass = graphics_render_pass_destroy(render_pass);

	delete viewport;

	BCS_RESULT destroy_position_render_target_result = graphics_render_target_destroy(position_render_target);
	BCS_RESULT destroy_color_render_target_result = graphics_render_target_destroy(color_render_target);
	BCS_RESULT destroy_normal_render_target_result = graphics_render_target_destroy(normal_render_target);
	BCS_RESULT destroy_tangent_render_target_result = graphics_render_target_destroy(tangent_render_target);
	BCS_RESULT destroy_binormal_render_target_result = graphics_render_target_destroy(binormal_render_target);
	BCS_RESULT destroy_uv_render_target_result = graphics_render_target_destroy(uv_render_target);

	BCS_RESULT destroy_model_instance_result = graphics_render_instance_destroy(render_instance);
	BCS_RESULT destroy_shader_pipeline_result = graphics_shader_pipeline_destroy(shader_pipeline);
	for (c_lightmap_render_mesh* lightmap_render_mesh : lightmap_render_meshes)
	{
		delete lightmap_render_mesh;
	}
	BCS_RESULT destroy_vertex_layout_result = graphics_vertex_layout_destroy(vertex_layout);
}

void c_lightmap::render_graphics()
{
	render_pass->render();
}

void c_lightmap::render_pass_callback()
{
	shader_pipeline->bind();

	c_graphics_buffer* render_instance_buffer;
	render_instance->get_graphics_buffer(render_instance_buffer);
	render_instance->update_buffers();

	render_instance_buffer->bind(0);

	for (c_lightmap_render_mesh* lightmap_render_mesh : lightmap_render_meshes)
	{
		lightmap_render_mesh->geometry->render_geometry();
	}
}

void c_lightmap::render_user_interface()
{

	if (ImGui::Begin("Texture Test"))
	{
		static unsigned int visible_index = UINT_MAX;

		static constexpr const char* render_target_names[] =
		{
			"position",
			"color",
			"normal",
			"tangent",
			"binormal",
			"uv",
		};
		static constexpr ImVec4 tint_colors[] =
		{
			{ 1.0f, 1.0f, 1.0f, 1.0f },
			{ 255.0f, 255.0f, 255.0f, 255.0f },
			{ 255.0f, 255.0f, 255.0f, 255.0f },
			{ 255.0f, 255.0f, 255.0f, 255.0f },
			{ 255.0f, 255.0f, 255.0f, 255.0f },
			{ 255.0f, 255.0f, 255.0f, 255.0f },
		};
		if (ImGui::Button("All"))
		{
			visible_index = UINT_MAX;
		}
		for (unsigned int render_target_index = 0; render_target_index < _countof(render_targets); render_target_index++)
		{
			ImGui::SameLine();
			const char* render_target_name = render_target_names[render_target_index];
			if (ImGui::Button(render_target_name))
			{
				visible_index = render_target_index;
			}
		}

		const char* render_target_name = "all";
		if (visible_index != UINT_MAX)
		{
			render_target_name = render_target_names[visible_index];
		}
		ImGui::SameLine();
		ImGui::TextUnformatted(render_target_name);

		for (unsigned int render_target_index = 0; render_target_index < _countof(render_targets); render_target_index++)
		{
			if (visible_index == UINT_MAX || visible_index == render_target_index)
			{

				c_graphics_render_target* render_target = render_targets[render_target_index];

				void* display_handle;
				if (BCS_SUCCEEDED(render_target->get_ui_image_display_handle(display_handle)))
				{
					ImVec2 start_pos = ImGui::GetCursorScreenPos();
					ImVec2 content_region = { viewport->width_float, viewport->height_float };
					if (visible_index == UINT_MAX)
					{
						content_region.x = 256;
						content_region.y = 256;
					}
					ImVec2 end_pos = { start_pos.x * content_region.x, start_pos.y * content_region.y };

					ImGui::Image(display_handle, content_region, ImVec2(0.0f, 0.0f), ImVec2(1.0f, 1.0f), tint_colors[render_target_index]);

					if (visible_index == UINT_MAX && !((render_target_index + 1) % 3 == 0))
					{
						ImGui::SameLine();
					}
				}
			}
		}
	}
	ImGui::End();
}
