#include "lightmapresearch-private-pch.h"

c_lightmap::c_lightmap()
{

}

c_lightmap::~c_lightmap()
{

}

c_graphics_buffer* index_buffer;
c_graphics_buffer* vertex_position_buffer;
c_graphics_buffer* vertex_colors_buffer;
c_graphics_buffer* vertex_normals_buffer;
c_graphics_buffer* vertex_tangents_buffer;
c_graphics_buffer* vertex_binormals_buffer;
c_graphics_buffer* vertex_uv_buffer;
c_graphics_vertex_layout* vertex_layout;
c_graphics_geometry* geometry;
c_graphics_shader_pipeline* shader_pipeline;
c_graphics_render_instance* render_instance;
c_graphics_render_target* render_targets[6];
c_graphics_render_target*& position_render_target = render_targets[0];
c_graphics_render_target*& color_render_target = render_targets[1];
c_graphics_render_target*& normal_render_target = render_targets[2];
c_graphics_render_target*& tangent_render_target = render_targets[3];
c_graphics_render_target*& binormal_render_target = render_targets[4];
c_graphics_render_target*& uv_render_target = render_targets[5];
c_viewport* viewport;
c_graphics_render_pass* render_pass;
t_callback_handle render_pass_callback_handle;

#pragma push_macro("new")
#undef new
#include <assimp/cimport.h>        // Plain-C interface
#include <assimp/scene.h>          // Output data structure
#include <assimp/postprocess.h>    // Post processing flags
#pragma pop_macro("new")

void c_lightmap::init(c_graphics& graphics)
{
	const aiScene* scene = aiImportFile("C:\\GitHub\\Sponza\\sponza.obj",
		aiProcess_CalcTangentSpace |
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType |
		aiProcess_GenNormals |
		aiProcess_GenBoundingBoxes);

	if (!scene)
	{
		const char* error_string = aiGetErrorString();
		throw;
	}

	unsigned int mesh_index = 0;
	aiMesh* mesh = scene->mMeshes[mesh_index];

	unsigned long num_vertices = mesh->mNumVertices;
	unsigned long num_faces = mesh->mNumFaces;

	std::vector<unsigned int> indices;
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

	std::vector<float3> positions;
	std::vector<float4> colors;
	std::vector<float3> normals;
	std::vector<float3> tangents;
	std::vector<float3> binormals;
	std::vector<float2> uvs;

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
		uvs.push_back({ ai_texcoord.x, ai_texcoord.y });
	}

	debug_point;

	// We're done. Release all resources associated with this import
	aiReleaseImport(scene);

	BCS_RESULT index_buffer_create_result = graphics_buffer_create(
		&graphics,
		_graphics_buffer_type_generic,
		sizeof(unsigned int),
		indices.size(),
		index_buffer,
		"Debug Triangle Index Buffer");
	ASSERT(BCS_SUCCEEDED(index_buffer_create_result));

	BCS_RESULT vertex_position_buffer_create_result = graphics_buffer_create(
		&graphics,
		_graphics_buffer_type_generic,
		sizeof(float3),
		positions.size(),
		vertex_position_buffer,
		"Debug Triangle Vertex Position Buffer");
	ASSERT(BCS_SUCCEEDED(vertex_position_buffer_create_result));

	BCS_RESULT vertex_colors_buffer_create_result = graphics_buffer_create(
		&graphics,
		_graphics_buffer_type_generic,
		sizeof(float4),
		colors.size(),
		vertex_colors_buffer,
		"Debug Triangle Vertex Color Buffer");
	ASSERT(BCS_SUCCEEDED(vertex_colors_buffer_create_result));

	BCS_RESULT vertex_normals_buffer_create_result = graphics_buffer_create(
		&graphics,
		_graphics_buffer_type_generic,
		sizeof(float3),
		normals.size(),
		vertex_normals_buffer,
		"Debug Triangle Vertex Normal Buffer");
	ASSERT(BCS_SUCCEEDED(vertex_normals_buffer_create_result));

	BCS_RESULT vertex_tangents_buffer_create_result = graphics_buffer_create(
		&graphics,
		_graphics_buffer_type_generic,
		sizeof(float3),
		tangents.size(),
		vertex_tangents_buffer,
		"Debug Triangle Vertex Tangent Buffer");
	ASSERT(BCS_SUCCEEDED(vertex_tangents_buffer_create_result));

	BCS_RESULT vertex_binormals_buffer_create_result = graphics_buffer_create(
		&graphics,
		_graphics_buffer_type_generic,
		sizeof(float3),
		binormals.size(),
		vertex_binormals_buffer,
		"Debug Triangle Vertex Binormal Buffer");
	ASSERT(BCS_SUCCEEDED(vertex_binormals_buffer_create_result));

	BCS_RESULT vertex_uv_buffer_create_result = graphics_buffer_create(
		&graphics,
		_graphics_buffer_type_generic,
		sizeof(float2),
		uvs.size(),
		vertex_uv_buffer,
		"Debug Triangle Vertex UV Buffer");
	ASSERT(BCS_SUCCEEDED(vertex_uv_buffer_create_result));

	ASSERT(BCS_SUCCEEDED(index_buffer_create_result));
	ASSERT(BCS_SUCCEEDED(vertex_position_buffer_create_result));
	ASSERT(BCS_SUCCEEDED(vertex_uv_buffer_create_result));

	BCS_RESULT write_index_buffer_result = index_buffer->write_data(indices.data(), sizeof(indices[0]), indices.size());
	BCS_RESULT write_vertex_position_buffer_result = vertex_position_buffer->write_data(positions.data(), sizeof(positions[0]), positions.size());
	BCS_RESULT write_vertex_colors_buffer_result = vertex_colors_buffer->write_data(colors.data(), sizeof(colors[0]), colors.size());
	BCS_RESULT write_vertex_normals_buffer_result = vertex_normals_buffer->write_data(normals.data(), sizeof(normals[0]), normals.size());
	BCS_RESULT write_vertex_tangents_buffer_result = vertex_tangents_buffer->write_data(tangents.data(), sizeof(tangents[0]), tangents.size());
	BCS_RESULT write_vertex_binormals_buffer_result = vertex_binormals_buffer->write_data(binormals.data(), sizeof(binormals[0]), binormals.size());
	BCS_RESULT write_vertex_uv_buffer_result = vertex_uv_buffer->write_data(uvs.data(), sizeof(uvs[0]), uvs.size());

	ASSERT(BCS_SUCCEEDED(write_index_buffer_result));
	ASSERT(BCS_SUCCEEDED(write_vertex_position_buffer_result));
	ASSERT(BCS_SUCCEEDED(write_vertex_uv_buffer_result));

	c_graphics_buffer* vertex_buffers[] =
	{
		vertex_position_buffer,
		vertex_colors_buffer,
		vertex_normals_buffer,
		vertex_tangents_buffer,
		vertex_binormals_buffer,
		vertex_uv_buffer,
	};

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

	BCS_RESULT graphics_geometry_result = graphics_geometry_create(
		&graphics,
		index_buffer,
		static_cast<uint32_t>(indices.size()),
		vertex_buffers,
		_countof(vertex_buffers),
		vertex_layout,
		geometry);

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

	e_graphics_data_format render_target_formats[] = { _graphics_data_format_r8g8b8a8_unorm };
	e_graphics_data_format depth_target_format = _graphics_data_format_depth_float32;

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

	uint32_t viewport_width = 1024;
	uint32_t viewport_height = 1024;

	viewport = new() c_viewport();
	viewport->set_size(viewport_width, viewport_height);

	// position_render_target
	// normal_render_target
	// tangent_render_target
	// binormal_render_target
	// uv_render_target

	BCS_RESULT create_position_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32_float, {}, position_render_target, "position_render_target");
	BCS_RESULT create_color_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32a32_float, {}, color_render_target, "color_render_target");
	BCS_RESULT create_normal_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32_float, {}, normal_render_target, "normal_render_target");
	BCS_RESULT create_tangent_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32_float, {}, tangent_render_target, "tangent_render_target");
	BCS_RESULT create_binormal_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32b32_float, {}, binormal_render_target, "binormal_render_target");
	BCS_RESULT create_uv_render_target_result = graphics_color_render_target_create(&graphics, viewport_width, viewport_height, _graphics_data_format_r32g32_float, {}, uv_render_target, "uv_render_target");

	BCS_FAIL_THROW(create_position_render_target_result);
	BCS_FAIL_THROW(create_color_render_target_result);
	BCS_FAIL_THROW(create_normal_render_target_result);
	BCS_FAIL_THROW(create_tangent_render_target_result);
	BCS_FAIL_THROW(create_binormal_render_target_result);
	BCS_FAIL_THROW(create_uv_render_target_result);

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
	BCS_RESULT destroy_normal_render_target_result = graphics_render_target_destroy(normal_render_target);
	BCS_RESULT destroy_tangent_render_target_result = graphics_render_target_destroy(tangent_render_target);
	BCS_RESULT destroy_binormal_render_target_result = graphics_render_target_destroy(binormal_render_target);
	BCS_RESULT destroy_uv_render_target_result = graphics_render_target_destroy(uv_render_target);

	BCS_RESULT destroy_model_instance_result = graphics_render_instance_destroy(render_instance);
	BCS_RESULT destroy_shader_pipeline_result = graphics_shader_pipeline_destroy(shader_pipeline);

	BCS_RESULT destroy_index_buffer_result = graphics_buffer_destroy(index_buffer);
	BCS_RESULT destroy_vertex_position_buffer_result = graphics_buffer_destroy(vertex_position_buffer);
	BCS_RESULT destroy_vertex_colors_buffer_result = graphics_buffer_destroy(vertex_colors_buffer);
	BCS_RESULT destroy_vertex_normals_buffer_result = graphics_buffer_destroy(vertex_normals_buffer);
	BCS_RESULT destroy_vertex_tangents_buffer_result = graphics_buffer_destroy(vertex_tangents_buffer);
	BCS_RESULT destroy_vertex_binormals_buffer_result = graphics_buffer_destroy(vertex_binormals_buffer);
	BCS_RESULT destroy_vertex_uv_buffer_result = graphics_buffer_destroy(vertex_uv_buffer);

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

	if (geometry)
	{
		geometry->render_geometry();
	}
}

void c_lightmap::render_user_interface()
{

	if (ImGui::Begin("Texture Test"))
	{
		ImGui::Text("Hello World");
	}
	ImGui::End();
}
