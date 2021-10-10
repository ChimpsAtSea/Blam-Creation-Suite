#pragma once

enum e_graphics_vertex_layout_semantic
{
	_graphics_vertex_layout_semantic_position,
	_graphics_vertex_layout_semantic_color,
	_graphics_vertex_layout_semantic_texcoord,
	_graphics_vertex_layout_semantic_normal,
	_graphics_vertex_layout_semantic_binormal,
	_graphics_vertex_layout_semantic_tangent,
};

enum e_graphics_vertex_layout_stepping
{
	_graphics_vertex_layout_stepping_per_vertex,
	_graphics_vertex_layout_stepping_per_instance,
};

BCS_DEBUG_API const char* vertex_layout_semantic_to_string(e_graphics_vertex_layout_semantic vertex_layout_semantic);

struct s_graphics_vertex_layout_description
{
	e_graphics_vertex_layout_semantic semantic;
	unsigned long semantic_index;
	e_graphics_data_format data_format;
	unsigned long buffer_index;
	unsigned long buffer_offset;
	e_graphics_vertex_layout_stepping stepping;
	unsigned long buffer_instance_stepping;
};

class c_graphics;

class c_graphics_vertex_layout
{
protected:
	c_graphics_vertex_layout();
public:
	virtual ~c_graphics_vertex_layout();
};

BCS_DEBUG_API BCS_RESULT graphics_vertex_layout_create(
	c_graphics* graphics,
	s_graphics_vertex_layout_description* descriptions,
	unsigned long num_layout_descriptions,
	c_graphics_vertex_layout*& vertex_layout,
	const char* debug_name = nullptr);
BCS_DEBUG_API BCS_RESULT graphics_vertex_layout_destroy(c_graphics_vertex_layout* vertex_layout);
