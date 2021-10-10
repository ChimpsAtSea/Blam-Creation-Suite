#pragma once

class c_viewport;
class c_graphics;
class c_graphics_render_target;

class c_graphics_render_pass_d3d12 :
	public c_graphics_render_pass
{
public:
	c_graphics_render_pass_d3d12() = delete;
	c_graphics_render_pass_d3d12(const c_graphics_render_pass_d3d12&) = delete;
	c_graphics_render_pass_d3d12& operator=(const c_graphics_render_pass_d3d12&) = delete;
	c_graphics_render_pass_d3d12(
		c_graphics_d3d12& graphics,
		c_graphics_render_target_d3d12** color_render_targets,
		c_graphics_render_target_d3d12** depth_render_targets,
		unsigned long num_color_render_targets,
		unsigned long num_depth_render_targets,
		unsigned long num_render_target_per_frame,
		unsigned long num_render_target_frames,
		const wchar_t* debug_name);
	virtual ~c_graphics_render_pass_d3d12();

	void set_viewport(c_viewport* viewport);
	void setup_viewport();
	BCS_RESULT init_descriptor_handles();
	BCS_RESULT deinit_descriptor_handles();
	virtual BCS_RESULT resize(unsigned long width, unsigned height) override;
	virtual void bind_render_targets() override;
	virtual void render(c_graphics_swap_chain* swap_chain = nullptr) override;
	void transition_color_render_targets(D3D12_RESOURCE_STATES before, D3D12_RESOURCE_STATES after);

	c_graphics_d3d12& graphics;
	c_graphics_render_target_d3d12** color_render_targets;
	c_graphics_render_target_d3d12** depth_render_targets;
	D3D12_CPU_DESCRIPTOR_HANDLE* color_render_target_cpu_handles;
	D3D12_CPU_DESCRIPTOR_HANDLE* depth_render_target_cpu_handles;
	unsigned long num_color_render_targets;
	unsigned long num_depth_render_targets;
	unsigned long num_render_target_per_frame;
	unsigned long num_render_target_frames;

	unsigned long current_render_target_swap_index;
	unsigned long current_render_target_start_index;
	unsigned long current_depth_stencil_swap_index;
	c_viewport* viewport;
	D3D12_VIEWPORT d3d12_viewport;
	D3D12_RECT scissor_rectangle;
};

BCS_RESULT graphics_d3d12_render_pass_create(
	c_graphics_d3d12* graphics,
	c_graphics_render_target_d3d12** color_render_targets,
	c_graphics_render_target_d3d12** depth_render_targets,
	unsigned long num_color_render_targets,
	unsigned long num_depth_render_targets,
	unsigned long num_render_target_per_frame,
	unsigned long num_render_target_frames,
	c_graphics_render_pass_d3d12*& render_pass,
	const char* debug_name = nullptr);
BCS_RESULT graphics_d3d12_render_pass_destroy(c_graphics_render_pass_d3d12* render_pass);
