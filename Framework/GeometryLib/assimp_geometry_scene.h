#pragma once

class c_assimp_geometry_mesh;

class c_assimp_geometry_scene :
	public c_geometry_scene
{
public:
	// keep around for debug purposes
	DEBUG_ONLY(const aiScene* assimp_scene);
	std::vector<c_assimp_geometry_mesh*> assimp_meshes;

	c_assimp_geometry_scene(const char* filepath);
	virtual ~c_assimp_geometry_scene();

	virtual unsigned int get_num_meshes() const override;
	virtual c_geometry_mesh* get_mesh(unsigned int index) const override;
	virtual bool is_read_only() const override;
};
