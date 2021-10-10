#pragma once

class c_constant_buffer_array_d3d12;
class c_graphics_d3d12;

class c_camera : r_camera
{
public:
	c_camera() = delete;
	c_camera(const c_camera&) = delete;
	c_camera& operator=(const c_camera&) = delete;
	explicit c_camera(c_graphics_d3d12& graphics);
	~c_camera();

	void update_perspective(float new_field_of_view_horizontal, float new_aspect_ratio);
	void update_view(float3 position);
	void render();
	void handle_input(float x_pixels, float y_pixels, float z_wheel);

#ifdef _WINDOWS_
	void window_procedure(HWND window_handle, UINT message, WPARAM wparam, LPARAM lparam);
#endif
public:
	float stored_yaw_degrees;
	float stored_pitch_degrees;
	float stored_distance;
	float3 stored_position;
	bool is_perspective_invalidated;

	float field_of_view_horizontal;
	float field_of_view_vertical;
	float aspect_ratio;
	float yaw_degrees;
	float pitch_degrees;
	float radius;
	POINT previous_drag_point;
	bool is_dragging;

	c_constant_buffer_array_d3d12* constant_buffer;
	c_graphics_d3d12& graphics;
};

