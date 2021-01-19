#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_BLOCK_FROM_STRUCT(
		scenario_zone_debugger_block_definition_block,
		"scenario_zone_debugger_block_definition",
		1,
		scenario_zone_debugger_block_definition_struct);

	#define SCENARIO_ZONE_DEBUGGER_BLOCK_DEFINITION_STRUCT_ID { 0x3736B0FB, 0x4E6A462A, 0xA642E58A, 0x35673446 }
	TAG_STRUCT(
		scenario_zone_debugger_block_definition_struct,
		"scenario_zone_debugger_block_definition_struct",
		"s_scenario_zone_debugger_definition",
		SCENARIO_ZONE_DEBUGGER_BLOCK_DEFINITION_STRUCT_ID)
	{
		{ _field_long_block_flags, "active designer zones", nullptr, 'bf32' },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

