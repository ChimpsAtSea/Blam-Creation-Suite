#include "graphicslib-private-pch.h"

c_viewport::c_viewport() :
	width(1),
	height(1)
{
	
}

c_viewport::~c_viewport()
{
	
}

void c_viewport::set_size(unsigned long _width, unsigned long _height)
{
	console_write_line(__FUNCTION__);
	_width = __max(1u, _width);
	_height = __max(1u, _height);

	if (width == _width && height == _height)
	{
		return;
	}

	width = _width;
	height = _height;
	width_float = static_cast<float>(_width);
	height_float = static_cast<float>(_height);
	aspect_ratio = width_float / height_float;

	on_size_changed(width, height);
}
void c_viewport::set_width(unsigned long width) { set_size(width, height); }
void c_viewport::set_height(unsigned long height) { set_size(width, height); }
