#pragma once

class c_viewport;

using t_viewport_on_size_changed_callback = void(void* userdata, c_viewport& viewport, unsigned long width, unsigned long height);

class c_viewport
{
public:
	c_viewport(const c_viewport&) = delete;
	c_viewport& operator=(const c_viewport&) = delete;

	BCS_DEBUG_API explicit c_viewport();
	BCS_DEBUG_API ~c_viewport();

	unsigned long width;
	unsigned long height;
	float width_float;
	float height_float;
	float aspect_ratio;

	BCS_DEBUG_API void set_size(unsigned long width, unsigned long height);
	BCS_DEBUG_API void set_width(unsigned long width);
	BCS_DEBUG_API void set_height(unsigned long height);

	c_typed_callback<t_viewport_on_size_changed_callback> on_size_changed;
};
