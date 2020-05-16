#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(giant_struct_definition)
{
	FIELD( _field_struct, "unit", &unit_struct_definition_struct_definition ),
	FIELD( _field_custom, "$$$ GIANT $$$" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_explanation, "movement" ),
	FIELD( _field_real, "accel_time:acceleration time in seconds" ),
	FIELD( _field_real, "decel_time:deceleration time in seconds" ),
	FIELD( _field_real_fraction, "minimum speed scale:as slow as we get" ),
	FIELD( _field_real, "speed scale#overall animation speed scale" ),
	FIELD( _field_real_fraction, "elevation change rate:scale per update" ),
	FIELD( _field_real, "proxy body offset:wu#how far to push the physical body" ),
	FIELD( _field_real_fraction, "proxy body deadzone#the physical body must move this fraction of the offset for it to make the scarab move.  High values make the scarab more resistant to noise in the physics simulation, but less responsive." ),
	FIELD( _field_explanation, "foot-placement limit" ),
	FIELD( _field_real, "max_vertical_reach:wu#how many world-units up/down a leg can reach from the ground elevation under the scarab" ),
	FIELD( _field_real, "foot target radius:wu#how far around a foot to search for ground targets to stomp.  Set to 0 to not search for targets" ),
	FIELD( _field_block, "buckle-settings", &giant_buckle_parameters_block ),
	FIELD( _field_explanation, "ankle ik scale" ),
	FIELD( _field_real, "ankle ik scale:lower values drop the ankles towards the ground when computing ik" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_BLOCK(giant_buckle_parameters_block, k_giant_buckle_total_types)
{
	FIELD( _field_explanation, "timing controls" ),
	FIELD( _field_real, "lower time:seconds to reach ground" ),
	FIELD( _field_long_enum, "lower curve" ),
	FIELD( _field_real, "raise time:seconds to recover" ),
	FIELD( _field_long_enum, "raise curve" ),
	FIELD( _field_real, "pause time (easy):seconds to wait" ),
	FIELD( _field_real, "pause time (normal):seconds to wait" ),
	FIELD( _field_real, "pause time (heroic):seconds to wait" ),
	FIELD( _field_real, "pause time (legendary):seconds to wait" ),
	FIELD( _field_explanation, "optional buckle gravity" ),
	FIELD( _field_real, "buckle gravity scale: use gravity to control descent when not 0" ),
	FIELD( _field_explanation, "buckling search" ),
	FIELD( _field_custom ),
	FIELD( _field_string_id, "buckling marker:marker that shows bottom of giant and center of search area" ),
	FIELD( _field_real, "forward-rear scan:world-unit search distance" ),
	FIELD( _field_real, "left-right scan:world-unit search distance" ),
	FIELD( _field_long_integer, "forward-rear steps:number of samples per direction" ),
	FIELD( _field_long_integer, "left-right steps:number of samples per direction" ),
	FIELD( _field_explanation, "buckling angle control" ),
	FIELD( _field_angle_bounds, "pitch bounds:degrees#giant may rotate the parent node of the buckling marker this much to align with ground." ),
	FIELD( _field_angle_bounds, "roll bounds:degrees#giant may rotate the parent node of the buckling marker this much to align with ground." ),
	FIELD( _field_explanation, "animations" ),
	FIELD( _field_string_id, "buckle animation:animation to use to lower the giant" ),
	FIELD( _field_string_id, "descent overlay:animation to overlay while lowering" ),
	FIELD( _field_string_id, "paused overlay:animation to overlay while paused" ),
	FIELD( _field_real_fraction, "descent overlay scale:max blend weight of descent overlay" ),
	FIELD( _field_real_fraction, "paused overlay scale:max blend weight of paused overlay" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(giant_block, GIANT_TAG, unit, UNIT_TAG)
{
	FIELD( _field_struct, "unit", &unit_struct_definition_struct_definition ),
	FIELD( _field_custom, "$$$ GIANT $$$" ),
	FIELD( _field_long_flags, "flags" ),
	FIELD( _field_explanation, "movement" ),
	FIELD( _field_real, "accel_time:acceleration time in seconds" ),
	FIELD( _field_real, "decel_time:deceleration time in seconds" ),
	FIELD( _field_real_fraction, "minimum speed scale:as slow as we get" ),
	FIELD( _field_real, "speed scale#overall animation speed scale" ),
	FIELD( _field_real_fraction, "elevation change rate:scale per update" ),
	FIELD( _field_real, "proxy body offset:wu#how far to push the physical body" ),
	FIELD( _field_real_fraction, "proxy body deadzone#the physical body must move this fraction of the offset for it to make the scarab move.  High values make the scarab more resistant to noise in the physics simulation, but less responsive." ),
	FIELD( _field_explanation, "foot-placement limit" ),
	FIELD( _field_real, "max_vertical_reach:wu#how many world-units up/down a leg can reach from the ground elevation under the scarab" ),
	FIELD( _field_real, "foot target radius:wu#how far around a foot to search for ground targets to stomp.  Set to 0 to not search for targets" ),
	FIELD( _field_block, "buckle-settings", &giant_buckle_parameters_block ),
	FIELD( _field_explanation, "ankle ik scale" ),
	FIELD( _field_real, "ankle ik scale:lower values drop the ankles towards the ground when computing ik" ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

} // namespace blofeld

