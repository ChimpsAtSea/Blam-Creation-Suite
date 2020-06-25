#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK(mopp_code_data_definition_block, 16*(1024*1024))
	{
		{ _field_byte_integer, "mopp data*!" },
		{ _field_terminator }
	};

	TAG_BLOCK(mopp_code_definition_block, SHORT_MAX)
	{
		{ _field_long_integer, "field pointer skip!~" },
		{ _field_short_integer, "size*!" },
		{ _field_short_integer, "count~*!" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 1 },
		{ _field_long_integer, "offset" },

		{ _field_version_less, _engine_type_haloreach, 1 },
		{ _field_pad, "total shit pad1", 4 },

		{ _field_version_equal, _engine_type_haloreach, 1 },
		{ _field_pad, "total shit pad1", 20 },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_pad, "total shit pad1", 8 },

		{ _field_real, "v.i*!" },
		{ _field_real, "v.j*!" },
		{ _field_real, "v.k*!" },
		{ _field_real, "v.w*!" },
		{ _field_long_integer, "m_data pointer!~" },
		{ _field_long_integer, "int m_size*!" },
		{ _field_long_integer, "int m_capacityAndFlags*!" },
		{ _field_char_integer, "int8 m_buildType*!" },

		{ _field_version_less_or_equal, _engine_type_haloreach, 3 },
		{ _field_char_integer, "unknown" },
		{ _field_char_integer, "unknown" },
		{ _field_char_integer, "unknown" },

		{ _field_version_equal, _engine_type_haloreach, 4 },
		{ _field_long_integer, "unknown@" },
		{ _field_long_integer, "unknown@" },
		{ _field_long_integer, "unknown@" },
		{ _field_long_integer, "unknown@" },

		{ _field_version_greater, _engine_type_haloreach },
		{ _field_pad, "total shit pad2", 3 },

		{ _field_custom },
		{ _field_block, "mopp data block *!", &mopp_code_data_definition_block_block },
		{ _field_custom },
		{ _field_char_integer, "mopp build type!*#they say it only matters for ps3" },
		{ _field_pad, "explicit alignment pad 3", 3 },
		{ _field_terminator }
	};

} // namespace blofeld

