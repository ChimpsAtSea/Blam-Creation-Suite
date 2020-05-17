#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_BLOCK(gear_block, s_vehicle_engine_definition::k_gear_count_max)
	{
		FIELD( _field_explanation, "loaded torque" ),
		FIELD( _field_struct, "loaded torque curve", &torque_curve_struct_struct_definition ),
		FIELD( _field_explanation, "cruising torque" ),
		FIELD( _field_struct, "cruising torque curve", &torque_curve_struct_struct_definition ),
		FIELD( _field_explanation, "gearing" ),
		FIELD( _field_real, "min time to upshift#seconds" ),
		FIELD( _field_real, "engine up-shift scale#0-1" ),
		FIELD( _field_real, "gear ratio" ),
		FIELD( _field_real, "min time to downshift#seconds" ),
		FIELD( _field_real, "engine down-shift scale#0-1" ),
		FIELD( _field_tag_reference, "gear shift sound - shifting up" ),
		FIELD( _field_tag_reference, "gear shift sound - shifting down" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(load_and_cruise_block, s_vehicle_engine_definition::k_load_and_cruise_looping_sound_max)
	{
		FIELD( _field_string_id, "load cruise function" ),
		FIELD( _field_long_block_index, "attachment index" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(global_vehicle_engine_struct)
{
		FIELD( _field_explanation, "engine" ),
		FIELD( _field_real, "engine moment#higher moments make engine spin up slower" ),
		FIELD( _field_real, "engine max angular velocity#higher moments make engine spin up slower" ),
		FIELD( _field_block, "gears", &gear_block_block ),
		FIELD( _field_tag_reference, "gear shift sound" ),
		FIELD( _field_block, "load and cruise sound", &load_and_cruise_block_block ),
		FIELD( _field_terminator )
};

TAG_STRUCT(torque_curve_struct)
{
		FIELD( _field_struct, "function", &scalar_function_named_struct_struct_definition ),
		FIELD( _field_terminator )
};

} // namespace blofeld

