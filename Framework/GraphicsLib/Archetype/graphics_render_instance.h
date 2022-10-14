#pragma once

class c_graphics;
class c_viewport;
class c_graphics_buffer;

class c_graphics_render_instance
{
protected:
	c_graphics_render_instance();
public:
	virtual ~c_graphics_render_instance();

	virtual void update_buffers() = 0;
	virtual void get_graphics_buffer(c_graphics_buffer*& buffer) = 0;
	virtual void set_position(float3 position) = 0;
	virtual void set_color(float4 color) = 0;
	virtual void set_rotation_euler(float3 rotation_euler) = 0;
	virtual void set_rotation_quat(float4 rotation_quat) = 0;
	virtual void set_scale(float scale) = 0;
	virtual void set_scale_3d(float3 scale_3d) = 0;
};

BCS_SHARED BCS_RESULT graphics_render_instance_create(
	c_graphics* graphics,
	c_graphics_render_instance*& render_instance,
	const char* debug_name = nullptr);
BCS_SHARED BCS_RESULT graphics_render_instance_destroy(c_graphics_render_instance* render_instance);
