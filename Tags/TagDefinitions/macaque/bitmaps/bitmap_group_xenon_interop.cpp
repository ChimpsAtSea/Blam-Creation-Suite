#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_ARRAY_FROM_STRUCT(
		render_interleaved_texture_array_definition_array,
		"render_interleaved_texture_array_definition",
		k_interleaved_texture_count,
		render_texture_format_definition);

	#define RENDER_TEXTURE_INTERLEAVED_INTEROP_DEFINITION_STRUCT_ID { 0x90486D0A, 0x944A4941, 0x9FE79AF0, 0x39E2E611 }
	TAG_STRUCT(
		render_texture_interleaved_interop_definition_struct,
		"render_texture_interleaved_interop_definition_struct",
		"s_render_texture_interleaved_descriptor",
		RENDER_TEXTURE_INTERLEAVED_INTEROP_DEFINITION_STRUCT_ID)
	{
		{ _field_data, "pixel data" },
		{ _field_data, "medium res data" },
		{ _field_array, "interleaved textures", &render_interleaved_texture_array_definition_array },
		{ _field_terminator }
	};

	#define RENDER_TEXTURE_FORMAT_DEFINITION_ID { 0xA5D6641E, 0xAC074AA2, 0x9ADEF9FC, 0x336413F7 }
	TAG_STRUCT(
		render_texture_format_definition,
		"render_texture_format_definition",
		"s_render_texture_format",
		RENDER_TEXTURE_FORMAT_DEFINITION_ID)
	{
		{ _field_short_integer, "width" },
		{ _field_short_integer, "height" },
		{ _field_char_integer, "depth" },
		{ _field_char_integer, "total mipmap count" },
		{ _field_char_enum, "type", &bitmap_types },
		{ _field_char_integer, "pad1_1" },
		{ _field_char_enum, "is high res bitmap", &boolean_enum_definition },
		{ _field_char_enum, "is medium res bitmap", &boolean_enum_definition },
		{ _field_char_enum, "pad2_1", &boolean_enum_definition },
		{ _field_char_enum, "pad2_2", &boolean_enum_definition },
		{ _field_long_integer, "exponent bias" },
		{ _field_long_integer, "xenon d3d format" },
		{ _field_terminator }
	};

	#define RENDER_TEXTURE_INTEROP_DEFINITION_STRUCT_ID { 0x64017671, 0x437A46F0, 0x9A33C422, 0x517096E3 }
	TAG_STRUCT(
		render_texture_interop_definition_struct,
		"render_texture_interop_definition_struct",
		"s_render_texture_descriptor",
		RENDER_TEXTURE_INTEROP_DEFINITION_STRUCT_ID)
	{
		{ _field_data, "pixel data" },
		{ _field_data, "medium res data" },
		{ _field_data, "high res data" },
		{ _field_short_integer, "width" },
		{ _field_short_integer, "height" },
		{ _field_char_integer, "depth" },
		{ _field_char_integer, "total mipmap count" },
		{ _field_char_enum, "type", &bitmap_types },
		{ _field_char_integer, "pad1_1" },
		{ _field_char_enum, "is high res bitmap", &boolean_enum_definition },
		{ _field_char_enum, "is medium res bitmap", &boolean_enum_definition },
		{ _field_char_enum, "pad2_1", &boolean_enum_definition },
		{ _field_char_enum, "pad2_2", &boolean_enum_definition },
		{ _field_long_integer, "exponent bias" },
		{ _field_long_integer, "xenon d3d format" },
		{ _field_terminator }
	};

	STRINGS(boolean_enum_definition)
	{
		"false",
		"true"
	};
	STRING_LIST(boolean_enum_definition, boolean_enum_definition_strings, _countof(boolean_enum_definition_strings));

} // namespace macaque

} // namespace blofeld

