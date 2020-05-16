#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(hs_source_files_block, k_maximum_hs_source_files_per_context)
{
	FIELD( _field_string, "name*" ),
	FIELD( _field_data, "source*" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(hs_references_block, k_maximum_hs_references_per_context)
{
	FIELD( _field_tag_reference, "reference*^" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(hs_scripts_block, k_maximum_hs_scripts_per_context)
{
	FIELD( _field_string_id, "name^*" ),
	FIELD( _field_enum, "script type*" ),
	FIELD( _field_word_flags, "script flags*" ),
	FIELD( _field_long_enum, "return type*" ),
	FIELD( _field_long_integer, "root expression index*" ),
	FIELD( _field_long_integer, "locals stack space" ),
	FIELD( _field_block, "parameters", &hs_script_parameters_block ),
	FIELD( _field_terminator )
};

TAG_BLOCK(hs_script_parameters_block, k_maximum_hs_parameters_per_script)
{
	FIELD( _field_string, "name^*" ),
	FIELD( _field_long_enum, "return type*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(hs_globals_block, k_maximum_hs_globals_per_context)
{
	FIELD( _field_string_id, "name*" ),
	FIELD( _field_long_enum, "type*" ),
	FIELD( _field_long_integer, "initialization expression index*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(HSInstancedVariablesBlock, k_maximum_hs_instanced_variables_per_context)
{
	FIELD( _field_string_id, "name*" ),
	FIELD( _field_long_enum, "type*" ),
	FIELD( _field_long_integer, "initialization expression index*" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(hs_unit_seat_block, k_maximum_hs_unit_seat_mappings)
{
	FIELD( _field_long_integer, "unit definition tag index!" ),
	FIELD( _field_long_integer, "unit seats!" ),
	FIELD( _field_long_integer, "unit seats2!" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(hs_syntax_datum_block, k_maximum_hs_syntax_nodes_per_context)
{
	FIELD( _field_short_integer, "datum header~" ),
	FIELD( _field_short_integer, "script index/function index/constant type union" ),
	FIELD( _field_long_integer, "next node" ),
	FIELD( _field_long_integer, "source data" ),
	FIELD( _field_long_integer, "source offset location" ),
	FIELD( _field_long_enum, "node expression type" ),
	FIELD( _field_short_integer, "flags" ),
	FIELD( _field_short_integer, "source file index" ),
	FIELD( _field_long_integer, "source file offset" ),
	FIELD( _field_terminator )
};

TAG_BLOCK(HSImportManifestBlock, 128)
{
	FIELD( _field_tag, "callee tag*" ),
	FIELD( _field_block, "script table*", &HSImportManifestEntryBlock ),
	FIELD( _field_block, "variable table*", &HSImportManifestEntryBlock ),
	FIELD( _field_terminator )
};

TAG_BLOCK(HSImportManifestEntryBlock, k_maximum_hs_scripts_per_context)
{
	FIELD( _field_string_id, "script name*" ),
	FIELD( _field_long_integer, "argCount*" ),
	FIELD( _field_long_integer, "index!~" ),
	FIELD( _field_terminator )
};

TAG_GROUP_FROM_BLOCK(hsc, HSC_TAG, hs_source_files_block)

} // namespace blofeld

