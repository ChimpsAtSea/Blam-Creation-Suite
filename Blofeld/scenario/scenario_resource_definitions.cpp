#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(hs_source_reference, k_maximum_hs_source_files_per_context)
{
	FIELD( _field_tag_reference, "reference^" ),
	FIELD( _field_terminator )
};

TAG_GROUP(script_container, SCRIPT_CONTAINER_TAG)
{
	FIELD( _field_struct, "script data" ),
	FIELD( _field_terminator )
};

TAG_GROUP(script, SCRIPT_TAG)
{
	FIELD( _field_block, "source files*", &hs_source_files_block ),
	FIELD( _field_block, "scripts*", &hs_scripts_block ),
	FIELD( _field_block, "globals*", &hs_globals_block ),
	FIELD( _field_block, "instanced variables*", &HSInstancedVariablesBlock_block ),
	FIELD( _field_block, "references*", &hs_references_block ),
	FIELD( _field_block, "hs unit seats!", &hs_unit_seat_block ),
	FIELD( _field_block, "hs syntax datums*", &hs_syntax_datum_block ),
	FIELD( _field_data, "script string data" ),
	FIELD( _field_block, "import manifest*", &HSImportManifestBlock_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

