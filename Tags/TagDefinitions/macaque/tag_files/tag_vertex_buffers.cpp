#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define RENDER_VERTEX_BUFFER_DESCRIPTOR_STRUCT_ID { 0x44953A7F, 0x73B448CB, 0xA68E5A44, 0x28379244 }
	TAG_STRUCT(
		render_vertex_buffer_descriptor_struct,
		"render_vertex_buffer_descriptor_struct",
		"s_render_vertex_buffer_descriptor",
		RENDER_VERTEX_BUFFER_DESCRIPTOR_STRUCT_ID)
	{
		{ _field_long_integer, "vertex count*" },
		{ _field_short_integer, "declaration*" },
		{ _field_short_integer, "stride*" },
		{ _field_data, "vertices*" },
		{ _field_terminator }
	};

	#define RENDER_INDEX_BUFFER_DESCRIPTOR_STRUCT_ID { 0x92B1FF62, 0x80FC4C26, 0x8BDC1478, 0x642346D2 }
	TAG_STRUCT(
		render_index_buffer_descriptor_struct,
		"render_index_buffer_descriptor_struct",
		"s_render_index_buffer_descriptor",
		RENDER_INDEX_BUFFER_DESCRIPTOR_STRUCT_ID)
	{
		{ _field_long_integer, "primitive type*" },
		{ _field_char_integer, "is index32*" },
		{ _field_pad, "index buffer descicriptor padding", 3 },
		{ _field_data, "index_data*" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

