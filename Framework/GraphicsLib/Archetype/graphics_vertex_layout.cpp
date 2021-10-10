#include "graphicslib-private-pch.h"

BCS_DEBUG_API const char* vertex_layout_semantic_to_string(e_graphics_vertex_layout_semantic vertex_layout_semantic)
{
	switch (vertex_layout_semantic)
	{
		case _graphics_vertex_layout_semantic_position	: return "POSITION";
		case _graphics_vertex_layout_semantic_color		: return "COLOR";
		case _graphics_vertex_layout_semantic_texcoord	: return "TEXCOORD";
		case _graphics_vertex_layout_semantic_normal	: return "NORMAL";
		case _graphics_vertex_layout_semantic_binormal	: return "BINORMAL";
		case _graphics_vertex_layout_semantic_tangent	: return "TANGENT";
	}
	return nullptr;
}

c_graphics_vertex_layout::c_graphics_vertex_layout()
{

}

c_graphics_vertex_layout::~c_graphics_vertex_layout()
{

}

BCS_DEBUG_API BCS_RESULT graphics_vertex_layout_create(
	c_graphics* graphics,
	s_graphics_vertex_layout_description* descriptions,
	unsigned long num_layout_descriptions,
	c_graphics_vertex_layout*& vertex_layout,
	const char* debug_name)
{
	if (c_graphics_d3d12* graphics_d3d12 = dynamic_cast<c_graphics_d3d12*>(graphics))
	{
		return graphics_d3d12_vertex_layout_create(
			graphics_d3d12,
			descriptions,
			num_layout_descriptions,
			*reinterpret_cast<c_graphics_vertex_layout_d3d12**>(&vertex_layout),
			debug_name);
	}
	return BCS_E_UNSUPPORTED;
}

BCS_DEBUG_API BCS_RESULT graphics_vertex_layout_destroy(c_graphics_vertex_layout* vertex_layout)
{
	if (c_graphics_vertex_layout_d3d12* vertex_layout_d3d12 = dynamic_cast<c_graphics_vertex_layout_d3d12*>(vertex_layout))
	{
		return graphics_d3d12_vertex_layout_destroy(vertex_layout_d3d12);
	}
	return BCS_E_UNSUPPORTED;
}
