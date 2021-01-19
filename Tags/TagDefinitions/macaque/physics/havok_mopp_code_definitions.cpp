#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define MOPP_CODE_DEFINITION_BLOCK_ID { 0xEE2BC898, 0x8AD14E98, 0xB64351E5, 0x635CF676 }
	TAG_BLOCK(
		mopp_code_definition_block,
		"mopp_code_definition_block",
		SHORT_MAX,
		"s_havok_mopp_code_definition",
		MOPP_CODE_DEFINITION_BLOCK_ID,
		4)
	{
		{ _field_long_integer, "field pointer skip!~", nullptr, 'nuke' },
		{ _field_short_integer, "size*!" },
		{ _field_short_integer, "count~*!" },
		{ _field_pad, "total shit pad1", 8 },
		{ _field_real, "v.i*!" },
		{ _field_real, "v.j*!" },
		{ _field_real, "v.k*!" },
		{ _field_real, "v.w*!" },
		{ _field_long_integer, "m_data pointer!~", nullptr, 'nuke' },
		{ _field_long_integer, "int m_size*!" },
		{ _field_long_integer, "int m_capacityAndFlags*!" },
		{ _field_char_integer, "int8 m_buildType*!" },
		{ _field_pad, "total shit pad2", 3 },
		FIELD_CUSTOM(nullptr, _custom_field_hidd_begin),
		{ _field_block, "mopp data block *!", &mopp_code_data_definition_block },
		FIELD_CUSTOM(nullptr, _custom_field_hidd_end),
		{ _field_char_integer, "mopp build type!*#they say it only matters for ps3" },
		{ _field_pad, "explicit alignment pad 3", 3 },
		{ _field_terminator }
	};

	#define MOPP_CODE_DATA_DEFINITION_BLOCK_ID { 0x0EAB741F, 0xF5D74408, 0x9D5A32E1, 0x12D4FD6D }
	TAG_BLOCK(
		mopp_code_data_definition_block,
		"mopp_code_data_definition_block",
		16*(1024*1024),
		"byte",
		MOPP_CODE_DATA_DEFINITION_BLOCK_ID)
	{
		{ _field_byte_integer, "mopp data*!" },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

