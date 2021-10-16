#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	#define STRUCTURE_MANIFEST_BSP_BLOCK_ID { 0xBAB8CC0A, 0x480145EF, 0x92A35821, 0x3E3CD08A }
	TAG_BLOCK(
		structure_manifest_bsp_block,
		"structure_manifest_bsp_block",
		k_maximum_structure_manifest_items_count,
		"s_structure_manifest_bsp_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_MANIFEST_BSP_BLOCK_ID)
	{
		{ _field_struct, "build identifer", FIELD_FLAG_READ_ONLY, &structure_manifest_build_identifier_struct },
		{ _field_struct, "parent build identifer", FIELD_FLAG_READ_ONLY, &structure_manifest_build_identifier_struct },
		{ _field_long_string, "bsp name", FIELD_FLAG_READ_ONLY | FIELD_FLAG_INDEX },
		{ _field_terminator }
	};

	#define STRUCTURE_MANIFEST_BUILD_IDENTIFIER_STRUCT_ID { 0xDDFB3371, 0xDA4642BF, 0xCD893004, 0xBCB969EC }
	TAG_STRUCT_V6(
		structure_manifest_build_identifier_struct,
		"structure_manifest_build_identifier_struct",
		"s_structure_manifest_build_identifier_definition",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_MANIFEST_BUILD_IDENTIFIER_STRUCT_ID)
	{
		{ _field_long_integer, "manifest_id0", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "manifest_id1", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "manifest_id2", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "manifest_id3", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "build_index", FIELD_FLAG_READ_ONLY },
		{ _field_long_integer, "structure importer version", FIELD_FLAG_READ_ONLY },
		{ _field_terminator }
	};

	#define STRUCTURE_MANIFEST_STRUCT_ID { 0xDA667371, 0xDF8B82BF, 0xAC8C4004, 0xBC6D99EC }
	TAG_STRUCT_V6(
		structure_manifest_struct,
		"structure_manifest_struct",
		"s_structure_manifest_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		STRUCTURE_MANIFEST_STRUCT_ID)
	{
		FIELD_EXPLANATION_EX("build identifer", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "build identifer", FIELD_FLAG_READ_ONLY, &structure_manifest_build_identifier_struct },
		FIELD_EXPLANATION_EX("parent build identifier", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_struct, "parent build identifer", "for local builds, this is the content build identifier you are based on", FIELD_FLAG_READ_ONLY, &structure_manifest_build_identifier_struct },
		{ _field_block, "bsp manifest", FIELD_FLAG_READ_ONLY, &structure_manifest_bsp_block },
		{ _field_terminator }
	};



} // namespace blofeld

