#pragma once

namespace blofeld
{
	namespace infinite
	{
		class h_render_model_definition;
	}
}

class c_graphics;

class c_infinite_tag_mesh
{
public:
	c_infinite_tag_mesh(
		c_graphics& graphics,
		blofeld::infinite::h_render_model_definition& render_model, 
		uint32_t mesh_index);
	~c_infinite_tag_mesh();

	c_graphics& graphics;
	blofeld::infinite::h_render_model_definition& render_model;

	c_graphics_vertex_layout* vertex_layout;
	c_graphics_buffer* index_buffer;
	c_graphics_buffer* position_buffer;
	c_graphics_buffer* texcoord_buffer;
	c_graphics_buffer* color_buffer;
	c_graphics_buffer* normal_buffer;
	c_graphics_geometry* graphics_geometry;

};
