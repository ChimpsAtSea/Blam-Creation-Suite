#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(hs_source_files, k_maximum_hs_source_files_per_context)
{
	{ _field_string, "name*" },
	{ _field_data, "source*" },
	{ _field_long_flags, "flags" },
	{ _field_terminator },
};

TAG_BLOCK(hs_scripts, k_maximum_hs_scripts_per_context)
{
	{ _field_string_id, "name^*" },
	{ _field_enum, "script type*" },
	{ _field_word_flags, "script flags*" },
	{ _field_long_enum, "return type*" },
	{ _field_long_integer, "root expression index*" },
	{ _field_long_integer, "locals stack space" },
	{ _field_block, "parameters", &hs_script_parameters_block },
	{ _field_terminator },
};

TAG_BLOCK(hs_script_parameters, k_maximum_hs_parameters_per_script)
{
	{ _field_string, "name^*" },
	{ _field_long_enum, "return type*" },
	{ _field_terminator },
};

TAG_BLOCK(hs_globals, k_maximum_hs_globals_per_context)
{
	{ _field_string_id, "name*" },
	{ _field_long_enum, "type*" },
	{ _field_long_integer, "initialization expression index*" },
	{ _field_terminator },
};

TAG_BLOCK(HSInstancedVariablesBlock, k_maximum_hs_instanced_variables_per_context)
{
	{ _field_string_id, "name*" },
	{ _field_long_enum, "type*" },
	{ _field_long_integer, "initialization expression index*" },
	{ _field_terminator },
};

TAG_BLOCK(hs_references, k_maximum_hs_references_per_context)
{
	{ _field_tag_reference, "reference*^" },
	{ _field_terminator },
};

TAG_BLOCK(hs_unit_seat, k_maximum_hs_unit_seat_mappings)
{
	{ _field_long_integer, "unit definition tag index!" },
	{ _field_long_integer, "unit seats!" },
	{ _field_long_integer, "unit seats2!" },
	{ _field_terminator },
};

TAG_BLOCK(hs_syntax_datum, k_maximum_hs_syntax_nodes_per_context)
{
	{ _field_short_integer, "datum header~" },
	{ _field_short_integer, "script index/function index/constant type union" },
	{ _field_long_integer, "next node" },
	{ _field_long_integer, "source data" },
	{ _field_long_integer, "source offset location" },
	{ _field_long_enum, "node expression type" },
	{ _field_short_integer, "flags" },
	{ _field_short_integer, "source file index" },
	{ _field_long_integer, "source file offset" },
	{ _field_terminator },
};

TAG_BLOCK(HSImportManifestBlock, 128)
{
	{ _field_tag, "callee tag*" },
	{ _field_block, "script table*", &HSImportManifestEntryBlock_block },
	{ _field_block, "variable table*", &HSImportManifestEntryBlock_block },
	{ _field_terminator },
};

TAG_BLOCK(HSImportManifestEntryBlock, k_maximum_hs_scripts_per_context)
{
	{ _field_string_id, "script name*" },
	{ _field_long_integer, "argCount*" },
	{ _field_long_integer, "index!~" },
	{ _field_terminator },
};

TAG_GROUP_FROM_BLOCK(hsc, HSC_TAG, hs_source_files_block)

} // namespace blofeld

