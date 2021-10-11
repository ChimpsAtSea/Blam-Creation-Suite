#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		giant_group,
		GIANT_TAG,
		&unit_group,
		UNIT_TAG,
		giant_block );

	TAG_BLOCK_FROM_STRUCT(
		giant_block,
		"giant_block",
		1,
		giant_struct_definition);

	#define GIANT_BUCKLE_PARAMETERS_BLOCK_ID { 0x4E004B41, 0x95E34827, 0xAF0C255E, 0x698BE753 }
	TAG_BLOCK(
		giant_buckle_parameters_block,
		"giant_buckle_parameters_block",
		k_giant_buckle_total_types,
		"giant_buckle_parameters",
		SET_UNKNOWN0 | SET_IS_MEMCPYABLE | SET_HAS_LEVEL_SPECIFIC_FIELDS | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		GIANT_BUCKLE_PARAMETERS_BLOCK_ID)
	{
		FIELD_EXPLANATION_EX("timing controls", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "lower time", nullptr, "seconds to reach ground" },
		{ _field_long_enum, "lower curve", &slider_movement_patterns },
		{ _field_real, "raise time", nullptr, "seconds to recover" },
		{ _field_long_enum, "raise curve", &slider_movement_patterns },
		{ _field_real, "pause time (easy)", nullptr, "seconds to wait" },
		{ _field_real, "pause time (normal)", nullptr, "seconds to wait" },
		{ _field_real, "pause time (heroic)", nullptr, "seconds to wait" },
		{ _field_real, "pause time (legendary)", nullptr, "seconds to wait" },
		FIELD_EXPLANATION_EX("optional buckle gravity", nullptr, FIELD_FLAG_NONE, "overrides lower time and curve when not 0"),
		{ _field_real, "buckle gravity scale", nullptr, "use gravity to control descent when not 0" },
		FIELD_EXPLANATION_EX("buckling search", nullptr, FIELD_FLAG_NONE, ""),
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_marker),
		{ _field_string_id, "buckling marker", nullptr, "marker that shows bottom of giant and center of search area" },
		{ _field_real, "forward-rear scan", nullptr, "world-unit search distance" },
		{ _field_real, "left-right scan", nullptr, "world-unit search distance" },
		{ _field_long_integer, "forward-rear steps", nullptr, "number of samples per direction" },
		{ _field_long_integer, "left-right steps", nullptr, "number of samples per direction" },
		FIELD_EXPLANATION_EX("buckling angle control", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_angle_bounds, "pitch bounds", "giant may rotate the parent node of the buckling marker this much to align with ground.", "degrees" },
		{ _field_angle_bounds, "roll bounds", "giant may rotate the parent node of the buckling marker this much to align with ground.", "degrees" },
		FIELD_EXPLANATION_EX("animations", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_string_id, "buckle animation", nullptr, "animation to use to lower the giant" },
		{ _field_string_id, "descent overlay", nullptr, "animation to overlay while lowering" },
		{ _field_string_id, "paused overlay", nullptr, "animation to overlay while paused" },
		{ _field_real_fraction, "descent overlay scale", nullptr, "max blend weight of descent overlay" },
		{ _field_real_fraction, "paused overlay scale", nullptr, "max blend weight of paused overlay" },
		{ _field_terminator }
	};

	#define GIANT_STRUCT_DEFINITION_ID { 0xA855591D, 0xA7A2477E, 0xAB97CD08, 0xA97A8C61 }
	TAG_STRUCT(
		giant_struct_definition,
		"giant_struct_definition",
		"_giant_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN4 | SET_UNKNOWN5 | 
		SET_UNKNOWN7 | SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		GIANT_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "unit", &unit_struct_definition },
		FIELD_CUSTOM_EX("$$$ GIANT $$$", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_long_flags, "flags", &giant_definition_flags },
		FIELD_EXPLANATION_EX("movement", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "accel_time", nullptr, "acceleration time in seconds" },
		{ _field_real, "decel_time", nullptr, "deceleration time in seconds" },
		{ _field_real_fraction, "minimum speed scale", nullptr, "as slow as we get" },
		{ _field_real, "speed scale", "overall animation speed scale" },
		{ _field_real_fraction, "elevation change rate", nullptr, "scale per update" },
		{ _field_real, "proxy body offset", "how far to push the physical body", "wu" },
		{ _field_real_fraction, "proxy body deadzone", "the physical body must move this fraction of the offset for it to make the scarab move.  High values make the scarab more resistant to noise in the physics simulation, but less responsive." },
		FIELD_EXPLANATION_EX("foot-placement limit", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "max_vertical_reach", "how many world-units up/down a leg can reach from the ground elevation under the scarab", "wu" },
		{ _field_real, "foot target radius", "how far around a foot to search for ground targets to stomp.  Set to 0 to not search for targets", "wu" },
		{ _field_block, "buckle-settings", &giant_buckle_parameters_block },
		FIELD_EXPLANATION_EX("ankle ik scale", nullptr, FIELD_FLAG_NONE, ""),
		{ _field_real, "ankle ik scale", nullptr, "lower values drop the ankles towards the ground when computing ik" },
		FIELD_CUSTOM_EX(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
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

