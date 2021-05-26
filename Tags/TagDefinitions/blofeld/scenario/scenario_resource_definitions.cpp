#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		script_container_group,
		SCRIPT_CONTAINER_TAG,
		nullptr,
		INVALID_TAG,
		script_container_block );

	TAG_GROUP(
		script_group,
		SCRIPT_TAG,
		nullptr,
		INVALID_TAG,
		script_block );

	TAG_BLOCK_FROM_STRUCT(
		script_container_block,
		"script_container_block",
		1,
		script_container_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		script_block,
		"script_block",
		1,
		script_struct_definition);

	#define HS_SOURCE_REFERENCE_BLOCK_ID { 0x8CF36B3A, 0x8C224FCC, 0xA38A9B83, 0xCEC80ED2 }
	TAG_BLOCK(
		hs_source_reference_block,
		"hs_source_reference_block",
		k_maximum_hs_source_files_per_context,
		"s_hs_source_reference",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		HS_SOURCE_REFERENCE_BLOCK_ID)
	{
		{ _field_tag_reference, "reference", FIELD_FLAG_INDEX, &hsc_reference },
		{ _field_terminator }
	};

	#define SCRIPT_CONTAINER_STRUCT_DEFINITION_ID { 0xC9FA273E, 0x5AA14DD5, 0xBDA32DB0, 0xBD8F8D00 }
	TAG_STRUCT(
		script_container_struct_definition,
		"script_container_struct_definition",
		"HSScriptContainer",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCRIPT_CONTAINER_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "script data", &hs_script_data_struct },
		{ _field_terminator }
	};

	#define SCRIPT_STRUCT_DEFINITION_ID { 0x0BD6B3E2, 0x9B5B4F76, 0xA69CBE21, 0xC8820C61 }
	TAG_STRUCT(
		script_struct_definition,
		"script_struct_definition",
		"HSCompiledScript",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SCRIPT_STRUCT_DEFINITION_ID)
	{
		{ _field_block, "source files", FIELD_FLAG_READ_ONLY, &hs_source_files_block },
		{ _field_block, "scripts", FIELD_FLAG_READ_ONLY, &hs_scripts_block },
		{ _field_block, "globals", FIELD_FLAG_READ_ONLY, &hs_globals_block },
		{ _field_block, "instanced variables", FIELD_FLAG_READ_ONLY, &HSInstancedVariablesBlock_block },
		{ _field_block, "references", FIELD_FLAG_READ_ONLY, &hs_references_block },
		{ _field_block, "hs unit seats", FIELD_FLAG_UNKNOWN0, &hs_unit_seat_block },
		{ _field_block, "hs syntax datums", FIELD_FLAG_READ_ONLY, &hs_syntax_datum_block },
		{ _field_data, "script string data" },
		{ _field_block, "import manifest", FIELD_FLAG_READ_ONLY, &HSImportManifestBlock_block },
		{ _field_terminator }
	};

	#define HS_SCRIPT_DATA_STRUCT_ID { 0xD87FEF80, 0x07DE47C3, 0x9785FC28, 0x8E53643F }
	TAG_STRUCT(
		hs_script_data_struct,
		"hs_script_data_struct",
		"HaloScript::ScriptData",
		SET_UNKNOWN0 | SET_UNKNOWN5 | SET_DELETE_RECURSIVELY | SET_HAS_LEVEL_SPECIFIC_FIELDS,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		HS_SCRIPT_DATA_STRUCT_ID)
	{
		{ _field_block, "source file references", FIELD_FLAG_READ_ONLY, &hs_source_reference_block },
		{ _field_block, "external source references", &hs_source_reference_block },
		{ _field_tag_reference, "compiled script", FIELD_FLAG_UNKNOWN0 | FIELD_FLAG_READ_ONLY, &Tag::Reference<struct HSCompiledScript>::s_defaultDefinition },
		{ _field_terminator }
	};



} // namespace blofeld

