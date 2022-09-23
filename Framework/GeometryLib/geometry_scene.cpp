#include "geometrylib-public-pch.h"

c_geometry_scene::~c_geometry_scene()
{

}

BCS_RESULT load_geometry_scene_from_file(const char* filepath, c_geometry_scene*& geometry_scene)
{
	try
	{
		geometry_scene = new c_assimp_geometry_scene(filepath);
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

BCS_RESULT geometry_scene_destroy(c_geometry_scene* geometry_scene)
{
	try
	{
		delete geometry_scene;
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
