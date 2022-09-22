#include "geometrylib-private-pch.h"

struct s_uv_atlas_packer
{
	std::vector<c_geometry_mesh*> geometry_mesh_entries;
	unsigned int resolution;
};

BCS_RESULT create_uv_atlas_packer(h_uv_atlas_packer& uv_atlas_packer_handle, unsigned int resolution)
{
	s_uv_atlas_packer* uv_atlas_packer = new() s_uv_atlas_packer();
	if (uv_atlas_packer == nullptr)
	{
		return BCS_E_OUT_OF_MEMORY;
	}

	uv_atlas_packer->resolution = resolution;

	uv_atlas_packer_handle = uv_atlas_packer;

	return BCS_S_OK;
}

BCS_RESULT uv_atlas_packer_add_mesh(h_uv_atlas_packer& uv_atlas_packer_handle, c_geometry_mesh* geometry_mesh)
{
	BCS_VALIDATE_ARGUMENT(geometry_mesh != nullptr);

	s_uv_atlas_packer* uv_atlas_packer = static_cast<s_uv_atlas_packer*>(uv_atlas_packer_handle);

	if (geometry_mesh->is_read_only())
	{
		return BCS_E_UNSUPPORTED;
	}

	uv_atlas_packer->geometry_mesh_entries.emplace_back(geometry_mesh);

	return BCS_S_OK;
}

BCS_RESULT uv_atlas_packer_bake(h_uv_atlas_packer& uv_atlas_packer_handle)
{
	s_uv_atlas_packer* uv_atlas_packer = static_cast<s_uv_atlas_packer*>(uv_atlas_packer_handle);

	xatlasSetPrint(printf, true);

	xatlasAtlas* xatlas = xatlasCreate();

	unsigned int num_meshes = static_cast<unsigned int>(uv_atlas_packer->geometry_mesh_entries.size());
	unsigned int num_bake_vertices = 0;
	unsigned int num_bake_indices = 0;
	unsigned int num_bake_faces = 0;
	for (unsigned int geometry_mesh_index = 0; geometry_mesh_index < num_meshes; geometry_mesh_index++)
	{
		c_geometry_mesh* geometry_mesh = uv_atlas_packer->geometry_mesh_entries[geometry_mesh_index];

		//geometry_mesh->degenerate_texcoord_hack();

		xatlasUvMeshDecl xatlas_uvmesh_decl;
		xatlasUvMeshDeclInit(&xatlas_uvmesh_decl);
		xatlas_uvmesh_decl.vertexUvData = geometry_mesh->get_texture_coordinate_set(0);	// const void* vertexUvData;
		xatlas_uvmesh_decl.indexData = geometry_mesh->get_mesh_indices_uint();			// const void* indexData;
		xatlas_uvmesh_decl.faceMaterialData = nullptr;												// const uint32_t* faceMaterialData;
		xatlas_uvmesh_decl.vertexCount = geometry_mesh->get_vertex_count();				// uint32_t vertexCount;
		xatlas_uvmesh_decl.vertexStride = sizeof(float2);											// uint32_t vertexStride;
		xatlas_uvmesh_decl.indexCount = geometry_mesh->get_index_count();				// uint32_t indexCount;
		xatlas_uvmesh_decl.indexOffset = 0;															// int32_t indexOffset;
		xatlas_uvmesh_decl.indexFormat = XATLAS_INDEX_FORMAT_UINT32;								// xatlasIndexFormat indexFormat;
		xatlas_uvmesh_decl.allowZeroFaceArea = true;
		xatlasAddMeshError xatlas_add_uv_mesh_result = xatlasAddUvMesh(xatlas, &xatlas_uvmesh_decl);
		ASSERT(xatlas_add_uv_mesh_result == XATLAS_ADD_MESH_ERROR_SUCCESS);

		debug_point;
	}

	xatlasChartOptions chartOptions;
	xatlasChartOptionsInit(&chartOptions);
	chartOptions.useInputMeshUvs = true;
	xatlasComputeCharts(xatlas, &chartOptions);

	xatlasPackOptions xatlas_pack_options;
	xatlasPackOptionsInit(&xatlas_pack_options);
	xatlas_pack_options.maxChartSize = 0;										// uint32_t maxChartSize;
	xatlas_pack_options.padding = 0;											// uint32_t padding;
	xatlas_pack_options.texelsPerUnit = 0.0f;									// float texelsPerUnit;
	xatlas_pack_options.resolution = uv_atlas_packer->resolution;				// uint32_t resolution;
	xatlas_pack_options.bilinear = true;										// bool bilinear;
	xatlas_pack_options.blockAlign = false;										// bool blockAlign;
	xatlas_pack_options.bruteForce = false;										// bool bruteForce;
	xatlas_pack_options.createImage = false;									// bool createImage;
	xatlas_pack_options.rotateChartsToAxis = false;								// bool rotateChartsToAxis;
	xatlas_pack_options.rotateCharts = false;									// bool rotateCharts;
	xatlasPackCharts(xatlas, &xatlas_pack_options);

	float packed_resolution = static_cast<float>(__max(xatlas->width, xatlas->height));

	ASSERT(xatlas->meshCount == num_meshes);
	for (unsigned int geometry_mesh_index = 0; geometry_mesh_index < num_meshes; geometry_mesh_index++)
	{
		c_geometry_mesh* geometry_mesh = uv_atlas_packer->geometry_mesh_entries[geometry_mesh_index];

		xatlasMesh& xatlas_mesh = xatlas->meshes[geometry_mesh_index];

		unsigned int num_src_mesh_vertices = geometry_mesh->get_vertex_count();
		unsigned int num_mesh_vertices = xatlas_mesh.vertexCount;
		ASSERT(num_src_mesh_vertices == num_mesh_vertices);

		float2* new_texture_coordinates = new() float2[num_src_mesh_vertices];
		if (new_texture_coordinates == nullptr)
		{
			return BCS_E_OUT_OF_MEMORY;
		}
		for (unsigned int vertex_index = 0; vertex_index < num_mesh_vertices; vertex_index++)
		{
			float(&xatlas_texcoord)[2] = xatlas_mesh.vertexArray[vertex_index].uv;
			float2& mesh_texcoord = new_texture_coordinates[vertex_index];

			mesh_texcoord.x = xatlas_texcoord[0] / packed_resolution;
			mesh_texcoord.y = xatlas_texcoord[1] / packed_resolution;
		}
		geometry_mesh->write_texture_coordinate_set(1, new_texture_coordinates, num_mesh_vertices, 0);
		delete[] new_texture_coordinates;

		debug_point;
	}

	return BCS_S_OK;
}

BCS_RESULT destroy_uv_atlas_packer(h_uv_atlas_packer& uv_atlas_packer_handle)
{
	s_uv_atlas_packer* uv_atlas_packer = static_cast<s_uv_atlas_packer*>(uv_atlas_packer_handle);
	delete uv_atlas_packer;

	return BCS_S_OK;
}
