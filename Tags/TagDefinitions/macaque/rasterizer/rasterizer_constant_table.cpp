#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define RASTERIZER_CONSTANT_BLOCK_ID { 0x9EAC07AB, 0x559D43EF, 0x88AEF5BC, 0x656E3255 }
	TAG_BLOCK(
		rasterizer_constant_block,
		"rasterizer_constant_block",
		c_rasterizer_constant_table_definition::k_max_constants,
		"c_rasterizer_constant_definition",
		RASTERIZER_CONSTANT_BLOCK_ID)
	{
		{ _field_string_id, "constant name^" },
		{ _field_word_integer, "register start*" },
		{ _field_byte_integer, "register count*" },
		{ _field_char_enum, "register set*", &register_set_enum },
		{ _field_terminator }
	};

	#define GLOBAL_RASTERIZER_CONSTANT_TABLE_STRUCT_ID { 0x88225AE9, 0x664A4892, 0xA3910819, 0x46CAAEFB }
	TAG_STRUCT(
		global_rasterizer_constant_table_struct,
		"global_rasterizer_constant_table_struct",
		"c_rasterizer_constant_table_definition",
		GLOBAL_RASTERIZER_CONSTANT_TABLE_STRUCT_ID)
	{
		{ _field_block, "constants*", &rasterizer_constant_block },
		{ _field_char_enum, "type*", &rasterizer_constant_table_type_enum },
		{ _field_pad, "qersaui", 3 },
		{ _field_terminator }
	};

	STRINGS(register_set_enum)
	{
		"bool",
		"int",
		"float",
		"sampler",
		"vertex_bool",
		"vertex_int",
		"vertex_float",
		"vertex_sampler"
	};
	STRING_LIST(register_set_enum, register_set_enum_strings, _countof(register_set_enum_strings));

	STRINGS(rasterizer_constant_table_type_enum)
	{
		"vertex",
		"pixel"
	};
	STRING_LIST(rasterizer_constant_table_type_enum, rasterizer_constant_table_type_enum_strings, _countof(rasterizer_constant_table_type_enum_strings));

} // namespace macaque

} // namespace blofeld

