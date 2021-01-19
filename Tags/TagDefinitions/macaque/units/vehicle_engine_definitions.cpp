#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	#define GEAR_BLOCK_ID { 0x43A70404, 0x7A0440D7, 0xA12F738C, 0x29E046A5 }
	TAG_BLOCK(
		gear_block,
		"gear_block",
		s_vehicle_engine_definition::k_gear_count_max,
		"s_vehicle_gear_definition",
		GEAR_BLOCK_ID)
	{
		{ _field_explanation, "loaded torque", "" },
		{ _field_struct, "loaded torque curve", &torque_curve_struct },
		{ _field_explanation, "cruising torque", "" },
		{ _field_struct, "cruising torque curve", &torque_curve_struct },
		{ _field_explanation, "gearing", "" },
		{ _field_real, "min time to upshift#seconds" },
		{ _field_real, "engine up-shift scale#0-1" },
		{ _field_real, "gear ratio" },
		{ _field_real, "min time to downshift#seconds" },
		{ _field_real, "engine down-shift scale#0-1" },
		{ _field_tag_reference, "gear shift sound - shifting up", &global_sound_reference },
		{ _field_tag_reference, "gear shift sound - shifting down", &global_sound_reference },
		{ _field_terminator }
	};

	#define LOAD_AND_CRUISE_BLOCK_ID { 0x9CF23975, 0xE2494C32, 0x95369BF4, 0x4DD24649 }
	TAG_BLOCK(
		load_and_cruise_block,
		"load_and_cruise_block",
		s_vehicle_engine_definition::k_load_and_cruise_looping_sound_max,
		"s_vehicle_load_and_cruise_definition",
		LOAD_AND_CRUISE_BLOCK_ID)
	{
		{ _field_string_id, "load cruise function" },
		{ _field_long_block_index, "attachment index" },
		{ _field_terminator }
	};

	#define GLOBAL_VEHICLE_ENGINE_STRUCT_ID { 0xB2086F9C, 0xE80E4D79, 0x81DDEB34, 0xBA677DA4 }
	TAG_STRUCT(
		global_vehicle_engine_struct,
		"global_vehicle_engine_struct",
		"s_vehicle_engine_definition",
		GLOBAL_VEHICLE_ENGINE_STRUCT_ID)
	{
		{ _field_explanation, "engine", "" },
		{ _field_real, "engine moment#higher moments make engine spin up slower" },
		{ _field_real, "engine max angular velocity#higher moments make engine spin up slower" },
		{ _field_block, "gears", &gear_block },
		{ _field_tag_reference, "gear shift sound", &global_sound_reference },
		{ _field_block, "load and cruise sound", &load_and_cruise_block },
		{ _field_terminator }
	};

	#define TORQUE_CURVE_STRUCT_ID { 0xA1B86A30, 0x21864A2C, 0xB26E5CA6, 0xF2DB9FC3 }
	TAG_STRUCT(
		torque_curve_struct,
		"torque_curve_struct",
		"s_toruqe_curve_definition",
		TORQUE_CURVE_STRUCT_ID)
	{
		{ _field_struct, "function", &scalar_function_named_struct },
		{ _field_terminator }
	};

} // namespace macaque

} // namespace blofeld

