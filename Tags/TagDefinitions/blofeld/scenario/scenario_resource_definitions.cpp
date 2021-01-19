#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_FROM_BLOCK(script_container, SCRIPT_CONTAINER_TAG, script_container_block_block );

	V5_TAG_GROUP_FROM_BLOCK(script, SCRIPT_TAG, script_block_block );

	V5_TAG_BLOCK(hs_source_reference_block, k_maximum_hs_source_files_per_context)
	{
		{ _field_tag_reference, "reference^", &hsc_reference },
		{ _field_terminator }
	};

	V5_TAG_BLOCK_FROM_STRUCT(script_container_block, 1, script_container_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(script_block, 1, script_struct_definition_struct_definition );

	V5_TAG_STRUCT(hs_script_data_struct)
	{
		{ _field_block, "source file references*", &hs_source_reference_block_block },
		{ _field_block, "external source references", &hs_source_reference_block_block },
		{ _field_tag_reference, "compiled script*!", &Tag::Reference<struct HSCompiledScript>::s_defaultDefinition },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(script_container_struct_definition)
	{
		{ _field_struct, "script data", &hs_script_data_struct_struct_definition },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(script_struct_definition)
	{
		{ _field_block, "source files*", &hs_source_files_block_block },
		{ _field_block, "scripts*", &hs_scripts_block_block },
		{ _field_block, "globals*", &hs_globals_block_block },
		{ _field_block, "instanced variables*", &HSInstancedVariablesBlock_block },
		{ _field_block, "references*", &hs_references_block_block },
		{ _field_block, "hs unit seats!", &hs_unit_seat_block_block },
		{ _field_block, "hs syntax datums*", &hs_syntax_datum_block_block },
		{ _field_data, "script string data" },
		{ _field_block, "import manifest*", &HSImportManifestBlock_block },
		{ _field_terminator }
	};

} // namespace blofeld

