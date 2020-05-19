#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_BLOCK_FROM_STRUCT(scenario_zone_debugger_block_definition, 1, scenario_zone_debugger_block_definition_struct_struct_definition );

	TAG_STRUCT(scenario_zone_debugger_block_definition_struct)
	{
		{ _field_long_block_flags, "active designer zones" },
		{ _field_terminator }
	};

} // namespace blofeld

