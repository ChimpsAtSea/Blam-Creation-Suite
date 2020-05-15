#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(giant_buckle_parameters, k_giant_buckle_total_types)
{
	{ _field_explanation, "timing controls" },
	{ _field_real, "lower time:seconds to reach ground" },
	{ _field_long_enum, "lower curve" },
	{ _field_real, "raise time:seconds to recover" },
	{ _field_long_enum, "raise curve" },
	{ _field_real, "pause time (easy):seconds to wait" },
	{ _field_real, "pause time (normal):seconds to wait" },
	{ _field_real, "pause time (heroic):seconds to wait" },
	{ _field_real, "pause time (legendary):seconds to wait" },
	{ _field_explanation, "optional buckle gravity" },
	{ _field_real, "buckle gravity scale: use gravity to control descent when not 0" },
	{ _field_explanation, "buckling search" },
	{ _field_custom },
	{ _field_string_id, "buckling marker:marker that shows bottom of giant and center of search area" },
	{ _field_real, "forward-rear scan:world-unit search distance" },
	{ _field_real, "left-right scan:world-unit search distance" },
	{ _field_long_integer, "forward-rear steps:number of samples per direction" },
	{ _field_long_integer, "left-right steps:number of samples per direction" },
	{ _field_explanation, "buckling angle control" },
	{ _field_angle_bounds, "pitch bounds:degrees#giant may rotate the parent node of the buckling marker this much to align with ground." },
	{ _field_angle_bounds, "roll bounds:degrees#giant may rotate the parent node of the buckling marker this much to align with ground." },
	{ _field_explanation, "animations" },
	{ _field_string_id, "buckle animation:animation to use to lower the giant" },
	{ _field_string_id, "descent overlay:animation to overlay while lowering" },
	{ _field_string_id, "paused overlay:animation to overlay while paused" },
	{ _field_real_fraction, "descent overlay scale:max blend weight of descent overlay" },
	{ _field_real_fraction, "paused overlay scale:max blend weight of paused overlay" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(giant, GIANT_TAG, unit, UNIT_TAG)
{
	{ _field_struct, "unit" },
	{ _field_custom, "$$$ GIANT $$$" },
	{ _field_long_flags, "flags" },
	{ _field_explanation, "movement" },
	{ _field_real, "accel_time:acceleration time in seconds" },
	{ _field_real, "decel_time:deceleration time in seconds" },
	{ _field_real_fraction, "minimum speed scale:as slow as we get" },
	{ _field_real, "speed scale#overall animation speed scale" },
	{ _field_real_fraction, "elevation change rate:scale per update" },
	{ _field_real, "proxy body offset:wu#how far to push the physical body" },
	{ _field_real_fraction, "proxy body deadzone#the physical body must move this fraction of the offset for it to make the scarab move.  High values make the scarab more resistant to noise in the physics simulation, but less responsive." },
	{ _field_explanation, "foot-placement limit" },
	{ _field_real, "max_vertical_reach:wu#how many world-units up/down a leg can reach from the ground elevation under the scarab" },
	{ _field_real, "foot target radius:wu#how far around a foot to search for ground targets to stomp.  Set to 0 to not search for targets" },
	{ _field_block, "buckle-settings", &giant_buckle_parameters_block },
	{ _field_explanation, "ankle ik scale" },
	{ _field_real, "ankle ik scale:lower values drop the ankles towards the ground when computing ik" },
	{ _field_custom },
	{ _field_terminator },
};

} // namespace blofeld

