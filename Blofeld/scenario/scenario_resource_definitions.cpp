#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(script_container, SCRIPT_CONTAINER_TAG, script_container_block_block )

TAG_GROUP_FROM_BLOCK(script, SCRIPT_TAG, script_block_block )

TAG_BLOCK_FROM_STRUCT(script_container_block, 1, script_container_struct_definition_struct_definition );

TAG_BLOCK_FROM_STRUCT(script_block, 1, script_struct_definition_struct_definition );

TAG_BLOCK(hs_source_reference_block, k_maximum_hs_source_files_per_context)
{
	FIELD( _field_tag_reference, "reference^" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(script_container_struct_definition)
{
	FIELD( _field_struct, "script data", &hs_script_data_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(script_struct_definition)
{
	FIELD( _field_block, "source files*", &hs_source_files_block_block ),
	FIELD( _field_block, "scripts*", &hs_scripts_block_block ),
	FIELD( _field_block, "globals*", &hs_globals_block_block ),
	FIELD( _field_block, "instanced variables*", &HSInstancedVariablesBlock_block ),
	FIELD( _field_block, "references*", &hs_references_block_block ),
	FIELD( _field_block, "hs unit seats!", &hs_unit_seat_block_block ),
	FIELD( _field_block, "hs syntax datums*", &hs_syntax_datum_block_block ),
	FIELD( _field_data, "script string data" ),
	FIELD( _field_block, "import manifest*", &HSImportManifestBlock_block ),
	FIELD( _field_terminator )
};

TAG_STRUCT(hs_script_data_struct)
{
	FIELD( _field_block, "source file references*", &hs_source_reference_block_block ),
	FIELD( _field_block, "external source references", &hs_source_reference_block_block ),
	FIELD( _field_tag_reference, "compiled script*!" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

