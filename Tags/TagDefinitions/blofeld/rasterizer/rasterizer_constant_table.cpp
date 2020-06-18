#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(rasterizer_constant_block, c_rasterizer_constant_table_definition::k_max_constants)
	{
		{ _field_string_id, "constant name^" },
		{ _field_word_integer, "register start*" },
		{ _field_byte_integer, "register count*" },
		{ _field_char_enum, "register set*", &register_set_enum },
		{ _field_terminator }
	};

	TAG_STRUCT(global_rasterizer_constant_table_struct)
	{
		{ _field_block, "constants*", & rasterizer_constant_block_block },

		{ _field_version_less_or_equal, _engine_type_haloreach, 2 },
		{ _field_dword_integer, "unknown@" },
		{ _field_dword_integer, "unknown@" },

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
		"pixel",
		"compute"
	};
	STRING_LIST(rasterizer_constant_table_type_enum, rasterizer_constant_table_type_enum_strings, _countof(rasterizer_constant_table_type_enum_strings));

} // namespace blofeld

