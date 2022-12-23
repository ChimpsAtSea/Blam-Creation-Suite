#pragma once

class c_graphics;
class c_graphics_render_target;
class c_viewport;

class c_graphics_render_pass
{
protected:
	c_graphics_render_pass();
public:
	virtual ~c_graphics_render_pass();

	virtual BCS_RESULT resize(uint32_t width, unsigned height) = 0;
	virtual void bind_render_targets() = 0;
	virtual void render(c_graphics_swap_chain* swap_chain = nullptr) = 0;

	using t_render_callback_d3d12 = void();
	c_typed_callback<t_render_callback_d3d12> render_callback;
};

BCS_SHARED BCS_RESULT graphics_render_pass_create(
	c_graphics* graphics,
	c_viewport* viewport,
	c_graphics_render_target** color_render_targets,
	c_graphics_render_target** depth_render_targets,
	uint32_t num_color_render_targets,
	uint32_t num_depth_render_targets,
	uint32_t num_render_target_per_frame,
	uint32_t num_render_target_frames,
	c_graphics_render_pass*& render_pass,
	const char* debug_name = nullptr);
BCS_SHARED BCS_RESULT graphics_render_pass_destroy(c_graphics_render_pass* render_pass);
