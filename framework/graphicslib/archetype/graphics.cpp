#include "graphicslib-private-pch.h"

c_graphics::c_graphics()
{

}

c_graphics::~c_graphics()
{

}

BCS_RESULT graphics_create(
	e_graphics_architecture architecture,
	bool use_debug_layer,
	c_graphics*& graphics)
{
	try
	{
		switch (architecture)
		{
		case _graphics_architecture_null:
		case _graphics_architecture_d3d11:
			return BCS_E_UNSUPPORTED;
		case _graphics_architecture_d3d12:
			return graphics_d3d12_create(
				use_debug_layer,
				false,
				false,
				*reinterpret_cast<c_graphics_d3d12**>(&graphics));
		case _graphics_architecture_d3d12_force_cpu:
			return graphics_d3d12_create(
				use_debug_layer,
				true,
				false,
				*reinterpret_cast<c_graphics_d3d12**>(&graphics));
		case _graphics_architecture_d3d12_raytracing:
			return graphics_d3d12_create(
				use_debug_layer,
				false,
				true,
				*reinterpret_cast<c_graphics_d3d12**>(&graphics));
		}
	}
	catch (BCS_RESULT rs)
	{
		return rs;
	}
	catch (...)
	{
		return BCS_E_FATAL;
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_destroy(c_graphics* graphics)
{
	BCS_VALIDATE_ARGUMENT(graphics != nullptr);

	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_destroy(graphics_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}
