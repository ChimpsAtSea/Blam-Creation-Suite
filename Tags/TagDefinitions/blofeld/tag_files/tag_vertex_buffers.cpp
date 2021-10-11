#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define RENDER_VERTEX_BUFFER_DESCRIPTOR_STRUCT_ID { 0x44953A7F, 0x73B448CB, 0xA68E5A44, 0x28379244 }
	TAG_STRUCT(
		render_vertex_buffer_descriptor_struct,
		"render_vertex_buffer_descriptor_struct",
		"s_render_vertex_buffer_descriptor",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_UNKNOWN8 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_VERTEX_BUFFER_DESCRIPTOR_STRUCT_ID)
	{
		{ _field_long_integer, "vertex count", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "declaration", FIELD_FLAG_READ_ONLY },
		{ _field_short_integer, "stride", FIELD_FLAG_READ_ONLY },
		{ _field_data, "vertices", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define RENDER_INDEX_BUFFER_DESCRIPTOR_STRUCT_ID { 0x92B1FF62, 0x80FC4C26, 0x8BDC1478, 0x642346D2 }
	TAG_STRUCT(
		render_index_buffer_descriptor_struct,
		"render_index_buffer_descriptor_struct",
		"s_render_index_buffer_descriptor",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_UNKNOWN8 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		RENDER_INDEX_BUFFER_DESCRIPTOR_STRUCT_ID)
	{
		{ _field_long_integer, "primitive type", FIELD_FLAG_READ_ONLY },
		{ _field_char_integer, "is index32", FIELD_FLAG_READ_ONLY },
		FIELD_PAD_EX("index buffer descicriptor padding", nullptr, FIELD_FLAG_NONE, 3),
		{ _field_data, "index_data", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};



} // namespace blofeld

