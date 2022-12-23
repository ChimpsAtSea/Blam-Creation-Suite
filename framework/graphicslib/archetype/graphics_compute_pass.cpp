#include "graphicslib-private-pch.h"

c_graphics_compute_pass::c_graphics_compute_pass()
{

}

c_graphics_compute_pass::~c_graphics_compute_pass()
{

}

BCS_RESULT graphics_compute_pass_create(
	c_graphics* graphics,
	c_graphics_compute_pass*& compute_pass,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_compute_pass_create(
			graphics_d3d12,
			*reinterpret_cast<c_graphics_compute_pass_d3d12**>(&compute_pass), 
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_compute_pass_destroy(c_graphics_compute_pass* compute_pass)
{
	if (c_graphics_compute_pass_d3d12* compute_pass_d3d12 = dynamic_cast<c_graphics_compute_pass_d3d12*>(compute_pass))
	{
		return graphics_d3d12_compute_pass_destroy(compute_pass_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}
