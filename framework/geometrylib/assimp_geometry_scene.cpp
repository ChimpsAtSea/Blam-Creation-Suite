#include "geometrylib-private-pch.h"

c_assimp_geometry_scene::c_assimp_geometry_scene(const char* filepath) :
	c_geometry_scene(),
	DEBUG_ONLY(assimp_scene(nullptr),)
	assimp_meshes()
{
	NDEBUG_ONLY(const aiScene*) assimp_scene = aiImportFile(filepath,
		aiProcess_CalcTangentSpace |
		aiProcess_Triangulate |
		aiProcess_JoinIdenticalVertices |
		aiProcess_SortByPType |
		aiProcess_GenNormals |
		aiProcess_GenBoundingBoxes |
		aiProcess_FindDegenerates);
	if (assimp_scene == nullptr)
	{
		const char* error_string = aiGetErrorString();
		console_write_line("Failed to import assimp scene '%s' reason '%s'", filepath, error_string);
		throw BCS_E_FATAL;
	}
	if (assimp_scene->mFlags & AI_SCENE_FLAGS_INCOMPLETE)
	{
		throw BCS_E_FAIL;
	}

	unsigned long num_meshes = assimp_scene->mNumMeshes;
	for (unsigned long mesh_index = 0; mesh_index < num_meshes; mesh_index++)
	{
		aiMesh* assimp_mesh = assimp_scene->mMeshes[mesh_index];
		if (assimp_mesh->mPrimitiveTypes == aiPrimitiveType_TRIANGLE)
		{
			c_assimp_geometry_mesh* assimp_geometry_mesh = new c_assimp_geometry_mesh(*this, assimp_mesh);
			assimp_meshes.emplace_back(assimp_geometry_mesh);
		}
		else
		{
			const char* mesh_name = assimp_mesh->mName.C_Str();
			console_write_line_verbose("Warning: Discarding assimp mesh data '%s' as primitive type is not exclusively aiPrimitiveType_TRIANGLE", mesh_name);
			debug_point;
		}
	}

	NDEBUG_ONLY(aiReleaseImport(assimp_scene));
}

c_assimp_geometry_scene::~c_assimp_geometry_scene()
{
	DEBUG_ONLY(aiReleaseImport(assimp_scene));
}

unsigned int c_assimp_geometry_scene::get_num_meshes() const
{
	return static_cast<unsigned int>(assimp_meshes.size());
}

c_geometry_mesh* c_assimp_geometry_scene::get_mesh(unsigned int index) const
{
	if (index < assimp_meshes.size())
	{
		return assimp_meshes[index];
	}
	return nullptr;
}

bool c_assimp_geometry_scene::is_read_only() const
{
	return false;
}
