#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_INHERIT_FROM_BLOCK(giant, GIANT_TAG, unit, UNIT_TAG, giant_block_block );

	TAG_BLOCK(giant_buckle_parameters_block, k_giant_buckle_total_types)
	{
		{ _field_explanation, "timing controls", "" },
		{ _field_real, "lower time:seconds to reach ground" },
		{ _field_long_enum, "lower curve", &slider_movement_patterns },
		{ _field_real, "raise time:seconds to recover" },
		{ _field_long_enum, "raise curve", &slider_movement_patterns },
		{ _field_real, "pause time (easy):seconds to wait" },
		{ _field_real, "pause time (normal):seconds to wait" },
		{ _field_real, "pause time (heroic):seconds to wait" },
		{ _field_real, "pause time (legendary):seconds to wait" },
		{ _field_explanation, "optional buckle gravity", "overrides lower time and curve when not 0" },
		{ _field_real, "buckle gravity scale: use gravity to control descent when not 0" },
		{ _field_explanation, "buckling search", "" },
		{ _field_custom },
		{ _field_string_id, "buckling marker:marker that shows bottom of giant and center of search area" },
		{ _field_real, "forward-rear scan:world-unit search distance" },
		{ _field_real, "left-right scan:world-unit search distance" },
		{ _field_long_integer, "forward-rear steps:number of samples per direction" },
		{ _field_long_integer, "left-right steps:number of samples per direction" },
		{ _field_explanation, "buckling angle control", "" },
		{ _field_angle_bounds, "pitch bounds:degrees#giant may rotate the parent node of the buckling marker this much to align with ground." },
		{ _field_angle_bounds, "roll bounds:degrees#giant may rotate the parent node of the buckling marker this much to align with ground." },
		{ _field_explanation, "animations", "" },
		{ _field_string_id, "buckle animation:animation to use to lower the giant" },
		{ _field_string_id, "descent overlay:animation to overlay while lowering" },
		{ _field_string_id, "paused overlay:animation to overlay while paused" },
		{ _field_real_fraction, "descent overlay scale:max blend weight of descent overlay" },
		{ _field_real_fraction, "paused overlay scale:max blend weight of paused overlay" },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(giant_block, 1, giant_struct_definition_struct_definition );

	TAG_STRUCT(giant_struct_definition)
	{
		{ _field_struct, "unit", &unit_struct_definition_struct_definition },
		{ _field_custom, "$$$ GIANT $$$" },
		{ _field_long_flags, "flags", &giant_definition_flags },
		{ _field_explanation, "movement", "" },
		{ _field_real, "accel_time:acceleration time in seconds" },
		{ _field_real, "decel_time:deceleration time in seconds" },
		{ _field_real_fraction, "minimum speed scale:as slow as we get" },
		{ _field_real, "speed scale#overall animation speed scale" },
		{ _field_real_fraction, "elevation change rate:scale per update" },
		{ _field_real, "proxy body offset:wu#how far to push the physical body" },
		{ _field_real_fraction, "proxy body deadzone#the physical body must move this fraction of the offset for it to make the scarab move.  High values make the scarab more resistant to noise in the physics simulation, but less responsive." },
		{ _field_explanation, "foot-placement limit", "" },
		{ _field_real, "max_vertical_reach:wu#how many world-units up/down a leg can reach from the ground elevation under the scarab" },
		{ _field_real, "foot target radius:wu#how far around a foot to search for ground targets to stomp.  Set to 0 to not search for targets" },
		{ _field_block, "buckle-settings", &giant_buckle_parameters_block_block },
		{ _field_explanation, "ankle ik scale", "" },
		{ _field_real, "ankle ik scale:lower values drop the ankles towards the ground when computing ik" },
		{ _field_custom },
		{ _field_terminator }
	};

	STRING_LIST(giant_definition_flags, empty_string_list, 0);

	STRINGS(slider_movement_patterns)
	{
		"linear",
		"light_ease_in",
		"full_ease_in",
		"light_ease_out",
		"full_ease_out",
		"light_ease_in_and_out",
		"full_ease_in_and_out"
	};
	STRING_LIST(slider_movement_patterns, slider_movement_patterns_strings, _countof(slider_movement_patterns_strings));

} // namespace blofeld

