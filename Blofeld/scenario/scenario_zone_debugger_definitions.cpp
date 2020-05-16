#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(scenario_zone_debugger_block_definition_struct)
{
	FIELD( _field_long_block_flags, "active designer zones" ),
	FIELD( _field_terminator )
};

TAG_BLOCK_FROM_STRUCT(scenario_zone_debugger_block_definition, 1, scenario_zone_debugger_block_definition_struct_struct_definition );

} // namespace blofeld

