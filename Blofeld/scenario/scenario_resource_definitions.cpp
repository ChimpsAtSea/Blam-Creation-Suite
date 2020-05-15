#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(hs_source_reference, k_maximum_hs_source_files_per_context)
{
	{ _field_tag_reference, "reference^" },
	{ _field_terminator },
};

TAG_GROUP(script_container, SCRIPT_CONTAINER_TAG)
{
	{ _field_struct, "script data" },
	{ _field_terminator },
};

TAG_GROUP(script, SCRIPT_TAG)
{
	{ _field_block, "source files*", &hs_source_files_block },
	{ _field_block, "scripts*", &hs_scripts_block },
	{ _field_block, "globals*", &hs_globals_block },
	{ _field_block, "instanced variables*", &HSInstancedVariablesBlock_block },
	{ _field_block, "references*", &hs_references_block },
	{ _field_block, "hs unit seats!", &hs_unit_seat_block },
	{ _field_block, "hs syntax datums*", &hs_syntax_datum_block },
	{ _field_data, "script string data" },
	{ _field_block, "import manifest*", &HSImportManifestBlock_block },
	{ _field_terminator },
};

} // namespace blofeld

