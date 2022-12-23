#include "graphicslib-private-pch.h"

c_graphics_camera::c_graphics_camera()
{

}

c_graphics_camera::~c_graphics_camera()
{

}

BCS_RESULT graphics_camera_create(
	c_graphics* graphics,
	c_viewport& viewport,
	c_graphics_camera*& camera,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_camera_create(
			graphics_d3d12,
			viewport,
			*reinterpret_cast<c_graphics_camera_d3d12**>(&camera), 
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_camera_destroy(c_graphics_camera* camera)
{
	if (c_graphics_camera_d3d12* camera_d3d12 = dynamic_cast<c_graphics_camera_d3d12*>(camera))
	{
		return graphics_d3d12_camera_destroy(camera_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}
