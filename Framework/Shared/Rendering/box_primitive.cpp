#include "shared-private-pch.h"

c_box_primitive::c_box_primitive()
{
	c_primitive_render_manager::register_box_primitive(this);
}

c_box_primitive::c_box_primitive(
	float position_x, 
	float position_y, 
	float position_z, 
	float dimensions_x, 
	float dimensions_y, 
	float dimensions_z,
	float color_r,
	float color_g,
	float color_b,
	float color_a
):c_box_primitive()
{
	update_as_centered_box(position_x, position_y, position_z, dimensions_x, dimensions_y, dimensions_z);
	set_color(color_r, color_b, color_g, color_a);
}

c_box_primitive::~c_box_primitive()
{
	c_primitive_render_manager::unregister_box_primitive(this);
}
