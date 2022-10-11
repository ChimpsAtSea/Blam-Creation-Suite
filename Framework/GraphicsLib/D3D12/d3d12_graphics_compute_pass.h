#pragma once

class c_viewport;
class c_graphics;
class c_graphics_render_target;

class c_graphics_compute_pass_d3d12 :
	public c_graphics_compute_pass
{
public:
	c_graphics_compute_pass_d3d12() = delete;
	c_graphics_compute_pass_d3d12(const c_graphics_compute_pass_d3d12&) = delete;
	c_graphics_compute_pass_d3d12& operator=(const c_graphics_compute_pass_d3d12&) = delete;
	c_graphics_compute_pass_d3d12(
		c_graphics_d3d12& graphics,
		const wchar_t* debug_name);
	virtual ~c_graphics_compute_pass_d3d12();

	virtual void execute() override;

	c_graphics_d3d12& graphics;
};

BCS_RESULT graphics_d3d12_compute_pass_create(
	c_graphics_d3d12* graphics,
	c_graphics_compute_pass_d3d12*& compute_pass,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_compute_pass_destroy(c_graphics_compute_pass_d3d12* compute_pass);
