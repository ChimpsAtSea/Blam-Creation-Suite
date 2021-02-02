#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define STRUCTURE_MANIFEST_BSP_BLOCK_ID { 0xBAB8CC0A, 0x480145EF, 0x92A35821, 0x3E3CD08A }
	TAG_BLOCK(
		structure_manifest_bsp_block,
		"structure_manifest_bsp_block",
		k_maximum_structure_manifest_items_count,
		"s_structure_manifest_bsp_definition",
		STRUCTURE_MANIFEST_BSP_BLOCK_ID)
	{
		{ _field_struct, "build identifer", &structure_manifest_build_identifier_struct },
		{ _field_struct, "parent build identifer", &structure_manifest_build_identifier_struct },
		{ _field_long_string, "bsp name" },
		{ _field_terminator }
	};

	#define STRUCTURE_MANIFEST_BUILD_IDENTIFIER_STRUCT_ID { 0xDDFB3371, 0xDA4642BF, 0xCD893004, 0xBCB969EC }
	TAG_STRUCT(
		structure_manifest_build_identifier_struct,
		"structure_manifest_build_identifier_struct",
		"s_structure_manifest_build_identifier_definition",
		STRUCTURE_MANIFEST_BUILD_IDENTIFIER_STRUCT_ID)
	{
		{ _field_long_integer, "manifest_id0" },
		{ _field_long_integer, "manifest_id1" },
		{ _field_long_integer, "manifest_id2" },
		{ _field_long_integer, "manifest_id3" },
		{ _field_long_integer, "build_index" },
		{ _field_long_integer, "structure importer version" },
		{ _field_terminator }
	};

	#define STRUCTURE_MANIFEST_STRUCT_ID { 0xDA667371, 0xDF8B82BF, 0xAC8C4004, 0xBC6D99EC }
	TAG_STRUCT(
		structure_manifest_struct,
		"structure_manifest_struct",
		"s_structure_manifest_definition",
		STRUCTURE_MANIFEST_STRUCT_ID)
	{
		{ _field_explanation, "build identifer", "" },
		{ _field_struct, "build identifer", &structure_manifest_build_identifier_struct },
		{ _field_explanation, "parent build identifier", "" },
		{ _field_struct, "parent build identifer", &structure_manifest_build_identifier_struct },
		{ _field_block, "bsp manifest", &structure_manifest_bsp_block },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

