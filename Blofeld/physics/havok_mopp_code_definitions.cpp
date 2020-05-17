#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(mopp_code_definition_block, SHORT_MAX)
	{
		FIELD( _field_long_integer, "field pointer skip!~" ),
		FIELD( _field_short_integer, "size*!" ),
		FIELD( _field_short_integer, "count~*!" ),
		FIELD( _field_pad, "total shit pad1", 8 ),
		FIELD( _field_real, "v.i*!" ),
		FIELD( _field_real, "v.j*!" ),
		FIELD( _field_real, "v.k*!" ),
		FIELD( _field_real, "v.w*!" ),
		FIELD( _field_long_integer, "m_data pointer!~" ),
		FIELD( _field_long_integer, "int m_size*!" ),
		FIELD( _field_long_integer, "int m_capacityAndFlags*!" ),
		FIELD( _field_char_integer, "int8 m_buildType*!" ),
		FIELD( _field_pad, "total shit pad2", 3 ),
		FIELD( _field_custom ),
		FIELD( _field_block, "mopp data block *!", &mopp_code_data_definition_block_block ),
		FIELD( _field_custom ),
		FIELD( _field_char_integer, "mopp build type!*#they say it only matters for ps3" ),
		FIELD( _field_pad, "explicit alignment pad 3", 3 ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(mopp_code_data_definition_block, 16*(1024*1024))
	{
		FIELD( _field_byte_integer, "mopp data*!" ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

