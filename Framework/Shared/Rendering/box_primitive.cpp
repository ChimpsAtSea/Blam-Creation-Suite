#include "shared-private-pch.h"

c_box_primitive::c_box_primitive()
{
	c_primitive_render_manager::RegisterBoxPrimitive(this);
}

c_box_primitive::c_box_primitive(
	float positionX, 
	float positionY, 
	float positionZ, 
	float dimensionsX, 
	float dimensionsY, 
	float dimensionsZ,
	float colorR,
	float colorG,
	float colorB,
	float colorA
):c_box_primitive()
{
	update_as_centered_box(positionX, positionY, positionZ, dimensionsX, dimensionsY, dimensionsZ);
	set_color(colorR, colorB, colorG, colorA);
}

c_box_primitive::~c_box_primitive()
{
	c_primitive_render_manager::UnregisterBoxPrimitive(this);
}
