#pragma once

class c_geometry_scene
{
public:
	virtual ~c_geometry_scene();

	virtual unsigned int get_num_meshes() const = 0;
	virtual c_geometry_mesh* get_mesh(unsigned int index) const = 0;
	virtual bool is_read_only() const = 0;
};

BCS_SHARED BCS_RESULT load_geometry_scene_from_file(const char* filepath, c_geometry_scene*& geometry_scene);
BCS_SHARED BCS_RESULT geometry_scene_destroy(c_geometry_scene* geometry_scene);
