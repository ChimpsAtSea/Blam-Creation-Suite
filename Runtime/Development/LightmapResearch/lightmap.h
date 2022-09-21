#pragma once

class c_lightmap_render_mesh;

class c_lightmap
{
public:
	std::vector<c_lightmap_render_mesh*> lightmap_render_meshes;
	c_graphics_vertex_layout* vertex_layout;
	c_graphics_shader_pipeline* shader_pipeline;
	c_graphics_render_instance* render_instance;
	c_graphics_render_target* render_targets[6];
	c_graphics_render_target*& position_render_target = render_targets[0];
	c_graphics_render_target*& color_render_target = render_targets[1];
	c_graphics_render_target*& normal_render_target = render_targets[2];
	c_graphics_render_target*& tangent_render_target = render_targets[3];
	c_graphics_render_target*& binormal_render_target = render_targets[4];
	c_graphics_render_target*& uv_render_target = render_targets[5];
	c_viewport* viewport;
	c_graphics_render_pass* render_pass;
	t_callback_handle render_pass_callback_handle;

	c_lightmap();
	~c_lightmap();

	void init(c_graphics& graphics);
	void deinit(c_graphics& graphics);
	void render_graphics();
	void render_pass_callback();
	void render_user_interface();
};