#pragma once

class c_graphics;
class c_viewport;
class c_graphics_buffer;

class c_graphics_camera
{
protected:
	c_graphics_camera();
public:
	virtual ~c_graphics_camera();

	virtual void update_buffers() = 0;
	virtual void set_field_of_view_degrees(float field_of_view_degrees) = 0;
	virtual void set_position(float3 position) = 0;
	virtual void set_yaw(float yaw) = 0;
	virtual void add_yaw(float yaw) = 0;
	virtual void set_pitch(float pitch) = 0;
	virtual void add_pitch(float pitch) = 0;
	virtual void set_radius(float radius) = 0;
	virtual void add_radius(float radius) = 0;
	virtual void get_graphics_buffer(c_graphics_buffer*& graphics_buffer) = 0;
	virtual void handle_input(float x_pixels, float y_pixels, float z_wheel) = 0;
};

BCS_SHARED BCS_RESULT graphics_camera_create(
	c_graphics* graphics,
	c_viewport& viewport,
	c_graphics_camera*& camera,
	const char* debug_name = nullptr);
BCS_SHARED BCS_RESULT graphics_camera_destroy(c_graphics_camera* camera);
