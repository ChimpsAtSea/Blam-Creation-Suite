#pragma once

class c_graphics;

struct s_camera_state_d3d12 :
	public r_camera_d3d12
{
	float field_of_view_horizontal;
	float field_of_view_vertical;
	float aspect_ratio;
	float yaw_degrees;
	float pitch_degrees;
	float radius;
};

class c_graphics_camera_d3d12 :
	public c_graphics_camera,
	public s_camera_state_d3d12
{
public:
	c_graphics_camera_d3d12() = delete;
	c_graphics_camera_d3d12(const c_graphics_camera_d3d12&) = delete;
	c_graphics_camera_d3d12& operator=(const c_graphics_camera_d3d12&) = delete;
	explicit c_graphics_camera_d3d12(
		c_graphics_d3d12& graphics,
		c_viewport& viewport,
		const wchar_t* debug_name = nullptr);
	virtual ~c_graphics_camera_d3d12();

	virtual void update_buffers() override;
	virtual void set_field_of_view_degrees(float field_of_view_degrees) override;
	virtual void set_position(float3 position) override;
	virtual void set_yaw(float yaw) override;
	virtual void add_yaw(float yaw) override;
	virtual void set_pitch(float pitch) override;
	virtual void add_pitch(float pitch) override;
	virtual void set_radius(float radius) override;
	virtual void add_radius(float radius) override;
	virtual void get_graphics_buffer(c_graphics_buffer*& graphics_buffer) override;
	virtual void handle_input(float x_pixels, float y_pixels, float z_wheel) override;

	static void __cdecl viewport_size_changed(c_graphics_camera_d3d12& _this, uint32_t width, uint32_t height);

	c_graphics_d3d12& graphics;
	c_viewport& viewport;
	c_graphics_buffer* graphics_buffer;
	XXH64_hash_t camera_hash;
	t_callback_handle viewport_size_changed_handle;
};

BCS_RESULT graphics_d3d12_camera_create(
	c_graphics_d3d12* graphics,
	c_viewport& viewport,
	c_graphics_camera_d3d12*& camera,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_camera_destroy(c_graphics_camera_d3d12* camera);
