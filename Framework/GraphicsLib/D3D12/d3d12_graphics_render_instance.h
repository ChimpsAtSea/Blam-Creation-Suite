#pragma once

class c_graphics;

struct s_render_instance_state_d3d12 :
	public r_render_instance_d3d12
{
	float3 position;
	float4 rotation;
	float3 scale;
};

class c_graphics_render_instance_d3d12 :
	public c_graphics_render_instance,
	public s_render_instance_state_d3d12
{
public:
	c_graphics_render_instance_d3d12() = delete;
	c_graphics_render_instance_d3d12(const c_graphics_render_instance_d3d12&) = delete;
	c_graphics_render_instance_d3d12& operator=(const c_graphics_render_instance_d3d12&) = delete;
	explicit c_graphics_render_instance_d3d12(
		c_graphics_d3d12& graphics,
		const wchar_t* name = nullptr);
	virtual ~c_graphics_render_instance_d3d12();

	virtual void update_buffers() override;
	virtual void get_graphics_buffer(c_graphics_buffer*& buffer) override;
	virtual void set_position(float3 position) override;
	virtual void set_color(float4 color) override;
	virtual void set_rotation_euler(float3 rotation_euler) override;
	virtual void set_rotation_quat(float4 rotation_quat) override;
	virtual void set_scale(float scale) override;
	virtual void set_scale_3d(float3 scale_3d) override;

	c_graphics_d3d12& graphics;
	c_graphics_buffer* graphics_buffer;
	XXH64_hash_t render_instance_hash;
};

BCS_RESULT graphics_d3d12_render_instance_create(
	c_graphics_d3d12* graphics,
	c_graphics_render_instance_d3d12*& render_instance,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_render_instance_destroy(c_graphics_render_instance_d3d12* render_instance);
