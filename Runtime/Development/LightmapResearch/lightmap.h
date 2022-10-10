#pragma once

class c_lightmap_render_mesh;

class c_lightmap
{
public:
	c_lightmap(c_graphics& graphics, uint32_t resolution);
	~c_lightmap();
	c_graphics& graphics;

	std::vector<c_lightmap_render_mesh*> lightmap_render_meshes;
	c_graphics_vertex_layout* vertex_layout;
	c_graphics_shader_pipeline* uv_space_shader_pipeline;
	c_graphics_shader_pipeline* compute_test_shader_pipeline;
	c_graphics_render_instance* render_instance;
	c_graphics_render_target* render_targets[6];
	c_viewport* viewport;
	c_graphics_render_pass* render_pass;
	t_callback_handle render_pass_callback_handle;
	uint32_t viewport_width;
	uint32_t viewport_height;

	void init();
	void deinit();
	void render_graphics();
	void render_pass_callback();
	void render_texture_preview();
	void render_user_interface();
};