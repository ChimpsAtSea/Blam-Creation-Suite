#include "graphicslib-private-pch.h"

c_viewport::c_viewport() :
	width(1),
	height(1),
	width_float(1.0f),
	height_float(1.0f),
	aspect_ratio(1.0f)
{
	
}

c_viewport::~c_viewport()
{
	
}

void c_viewport::set_size(unsigned long _width, unsigned long _height)
{
	_width = __max(1u, _width);
	_height = __max(1u, _height);

	if (width == _width && height == _height)
	{
		return;
	}

	console_write_line_verbose(__FUNCTION__);

	width = _width;
	height = _height;
	width_float = static_cast<float>(_width);
	height_float = static_cast<float>(_height);
	aspect_ratio = width_float / height_float;

	on_size_changed(width, height);
}
void c_viewport::set_width(unsigned long width) { set_size(width, height); }
void c_viewport::set_height(unsigned long height) { set_size(width, height); }
