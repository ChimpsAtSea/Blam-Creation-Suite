#include "graphicslib-private-pch.h"

c_graphics_top_level_acceleration_structure::c_graphics_top_level_acceleration_structure()
{

}

c_graphics_top_level_acceleration_structure::~c_graphics_top_level_acceleration_structure()
{

}

c_graphics_bottom_level_acceleration_structure::c_graphics_bottom_level_acceleration_structure()
{

}

c_graphics_bottom_level_acceleration_structure::~c_graphics_bottom_level_acceleration_structure()
{

}

BCS_RESULT graphics_top_level_acceleration_structure_create(
	c_graphics* graphics,
	c_graphics_top_level_acceleration_structure*& top_level_acceleration_structure,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_top_level_acceleration_structure_create(
			graphics_d3d12,
			*reinterpret_cast<c_graphics_top_level_acceleration_structure_d3d12**>(&top_level_acceleration_structure),
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_top_level_acceleration_structure_destroy(c_graphics_top_level_acceleration_structure* top_level_acceleration_structure)
{
	BCS_VALIDATE_ARGUMENT(top_level_acceleration_structure != nullptr);

	if (c_graphics_top_level_acceleration_structure_d3d12* top_level_acceleration_structure_d3d12 = dynamic_cast<c_graphics_top_level_acceleration_structure_d3d12*>(top_level_acceleration_structure))
	{
		return graphics_d3d12_top_level_acceleration_structure_destroy(top_level_acceleration_structure_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_bottom_level_acceleration_structure_create(
	c_graphics* graphics,
	c_graphics_geometry* geometry,
	c_graphics_bottom_level_acceleration_structure*& bottom_level_acceleration_structure,
	const char* debug_name)
{
	BCS_VALIDATE_ARGUMENT(geometry != nullptr);

	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_bottom_level_acceleration_structure_create(
			graphics_d3d12,
			dynamic_cast<c_graphics_geometry_d3d12*>(geometry),
			*reinterpret_cast<c_graphics_bottom_level_acceleration_structure_d3d12**>(&bottom_level_acceleration_structure),
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_RESULT graphics_bottom_level_acceleration_structure_destroy(c_graphics_bottom_level_acceleration_structure* bottom_level_acceleration_structure)
{
	BCS_VALIDATE_ARGUMENT(bottom_level_acceleration_structure != nullptr);

	if (c_graphics_bottom_level_acceleration_structure_d3d12* bottom_level_acceleration_structure_d3d12 = dynamic_cast<c_graphics_bottom_level_acceleration_structure_d3d12*>(bottom_level_acceleration_structure))
	{
		return graphics_d3d12_bottom_level_acceleration_structure_destroy(bottom_level_acceleration_structure_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}
