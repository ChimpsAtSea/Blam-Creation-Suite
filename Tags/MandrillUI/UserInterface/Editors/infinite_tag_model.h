#pragma once

namespace blofeld
{
	namespace infinite
	{
		class h_render_model_definition;
	}
}

class c_graphics;
class c_infinite_tag_mesh;

class c_infinite_tag_model
{
public:
	c_infinite_tag_model(
		c_graphics& graphics,
		blofeld::infinite::h_render_model_definition& render_model,
		unsigned long mesh_index);
	~c_infinite_tag_model();

	void render();

	c_graphics& graphics;
	blofeld::infinite::h_render_model_definition& render_model;

	c_infinite_tag_mesh* mesh;

	c_graphics_shader_pipeline* graphics_shader_pipeline;
	c_graphics_render_instance* render_instance;
};
