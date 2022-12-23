#pragma once

class c_graphics;
class c_graphics_render_target;
class c_viewport;

class c_graphics_compute_pass
{
protected:
	c_graphics_compute_pass();
public:
	virtual ~c_graphics_compute_pass();

	virtual void execute() = 0;

	using t_render_callback_d3d12 = void();
	c_typed_callback<t_render_callback_d3d12> render_callback;
};

BCS_SHARED BCS_RESULT graphics_compute_pass_create(
	c_graphics* graphics,
	c_graphics_compute_pass*& compute_pass,
	const char* debug_name = nullptr);
BCS_SHARED BCS_RESULT graphics_compute_pass_destroy(c_graphics_compute_pass* compute_pass);
