#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(mopp_code_data_definition_block, 16*(1024*1024))
	{
		{ _field_byte_integer, "mopp data*!" },
		{ _field_terminator }
	};

	V5_TAG_BLOCK(mopp_code_definition_block, SHORT_MAX) // hkpMoppCode see hkpMoppCode.h
	{
		// hkBaseObject
		{ _field_pointer, "field pointer skip!~", nullptr, 'nuke' }, // vftbl

		// hkReferencedObject
		{ _field_short_integer, "size*!" }, // hkUint16 m_memSizeAndFlags
		{ _field_short_integer, "count~*!" }, // hkInt16 m_referenceCount
		{ _field_version_platform_include, _platform_type_pc, 1 },
		{ _field_pad, "total shit pad1", 4 },
		{ _field_version_platform_exclude, _platform_type_pc, 2 },
		{ _field_version_greater_or_equal, _engine_type_haloreach },
		{ _field_pad, "total shit pad1", 8 },

		{ _field_version_equal, _engine_type_haloreach }, // unknown. havok struct modified?? data was nuke?
		{ _field_pad, "unknown", 16 },

		// hkpMoppCode
		// CodeInfo m_info
		{ _field_real, "v.i*!" }, // hkVector4 m_offset
		{ _field_real, "v.j*!" },
		{ _field_real, "v.k*!" },
		{ _field_real, "v.w*!" },

		// hkArray<hkUint8> m_data
		// hkArrayBase

		// unknown Halo 4 PC modification to hkArray/hkArrayBase
		{ _field_version_platform_include, _platform_type_pc, 3 },
		{ _field_version_greater_or_equal, _engine_type_halo4, 2 },
		{ _field_long_integer, "@unknown" },
		{ _field_pad, "padding", 4 },

		{ _field_pointer, "m_data pointer!~", nullptr, 'nuke' }, // T* m_data
		{ _field_long_integer, "int m_size*!" }, // int m_size
		{ _field_long_integer, "int m_capacityAndFlags*!" }, // int m_capacityAndFlags highest 2 bits indicate any special considerations about the allocation for the array

		// kEnum<BuildType, hkInt8> m_buildType
		{ _field_char_integer, "int8 m_buildType*!" },
		{ _field_pad, "total shit pad2", 3 },

		{ _field_version_platform_include, _platform_type_pc, 4 },
		{ _field_version_equal, _engine_type_haloreach, 1 },
		{ _field_pad, "padding", 12 }, // alignment
		{ _field_version_greater_or_equal, _engine_type_halo4, 1 },
		{ _field_pad, "padding", 4 }, // alignment

		// ## blam specific data below ##

		{ _field_custom, nullptr, nullptr, 'hide' },
		{ _field_block, "mopp data block *!", &mopp_code_data_definition_block_block },
		{ _field_custom, nullptr, nullptr, 'edih' },
		{ _field_char_integer, "mopp build type!*#they say it only matters for ps3" },
		{ _field_pad, "explicit alignment pad 3", 3 },
		{ _field_terminator }
	};

} // namespace blofeld

