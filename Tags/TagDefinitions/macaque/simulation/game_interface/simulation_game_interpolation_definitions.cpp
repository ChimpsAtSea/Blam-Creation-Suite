#include <tagdefinitions-private-pch.h>
#include <macaque_field_type_override.h>

namespace blofeld
{

namespace macaque
{

	TAG_GROUP(
		simulation_interpolation_group,
		SIMULATION_INTERPOLATION_TAG,
		nullptr,
		INVALID_TAG,
		simulation_interpolation_block );

	TAG_BLOCK_FROM_STRUCT(
		simulation_interpolation_block,
		"simulation_interpolation_block",
		1,
		simulation_interpolation_struct_definition);

	#define SIMULATION_INTERPOLATION_STRUCT_DEFINITION_ID { 0x2FACCEF0, 0x5C3B4A32, 0x8DF1C551, 0x349A3F4A }
	TAG_STRUCT(
		simulation_interpolation_struct_definition,
		"simulation_interpolation_struct_definition",
		"s_simulation_interpolation_definition",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SIMULATION_INTERPOLATION_STRUCT_DEFINITION_ID)
	{
		FIELD_EXPLANATION("SIMULATION INTERPOLATION", nullptr, FIELD_FLAG_NONE, "This tag defines interpolation that will be used to smooth the motion of objects in distributed multiplayer games.  In bandwidth-constrained multiplayer games (i.e. most games), we will receive only one or two updates per second for faraway objects.  Even near objects may frequently be dropped to <5 updates per second, especially crates, garbage bits, and similar less important elements of the simulation.  Between updates, each peer predicts the motion of each object.  These predictions are often wrong (by anything from an inch to dozens of feet).  The simulation interpolation system is responsible for correcting these mispredictions in as aesthetically pleasing a way as possible, without harming the integrity of the game.  The details of the technical implementation are beyond the scope of this explanation, but various configuration parameters are exposed here.  \n\nThe tooltips for each configuration parameter should be helpful.  Please see daldridge w/ questions or bugs."),
		FIELD_CUSTOM("High level settings", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_real, "position_client_ignore_tolerance", "How much rope clients have WRT their controlled object of this type. They are free to ignore host updates within this tolerance.", "WU" },
		{ _field_real, "angular_speed_threshold_for_temporarily_ignoring_rotation_updates", "If angular speed exceeds this threshold, we will ignore rotational updates (because it's spinning so fast that we can't possibly do a good job w/ any kind of interpolation - instead, just wait for it to settle down a bit).  Note that if a warp threshold is exceeded, rotation will be warped regardless of the value of this parameter.", "degrees per second" },
		FIELD_CUSTOM("Warp Thresholds", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		FIELD_EXPLANATION("WARP THRESHOLDS", nullptr, FIELD_FLAG_NONE, "If any of the warp thresholds (position or rotation, global or xy) are exceeded, a warp in all domains (position and rotation) is executed."),
		{ _field_real, "position_warp_threshold", "Threshold of position error beyond which we will warp instead of interpolating.", "WU" },
		{ _field_real, "position_warp_threshold_xy", "Separated for bipeds, for whom z discrepancies are more permissible because of jumping. If you don't want a special lower XY threshold, just set this to a very high number.", "WU" },
		{ _field_real, "rotation_warp_threshold", "Threshold of rotation error beyond which we will warp instead of interpolating.  Set this to 180.0 if you don't want to warp based on rotational deviation (may be important for objects that often spin very fast, e.g. grenades or garbage bits).", "degrees" },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Position while controlled", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "position_while_controlled", "All speeds in here are WU/s", &single_domain_configuration_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Rotation while controlled", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "rotation_while_controlled", "All speeds in here are degrees/s", &single_domain_configuration_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Position while not controlled", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "position_while_uncontrolled", "All speeds in here are WU/s", &single_domain_configuration_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Rotation while not controlled", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "rotation_while_uncontrolled", "All speeds in here are degrees/s", &single_domain_configuration_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define SINGLE_DOMAIN_CONFIGURATION_STRUCT_ID { 0xE844485C, 0x782542A7, 0xB852650A, 0x3EC8A1C7 }
	TAG_STRUCT(
		single_domain_configuration_struct,
		"single_domain_configuration_struct",
		"s_simulation_single_domain_interpolation_configuration",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SINGLE_DOMAIN_CONFIGURATION_STRUCT_ID)
	{
		FIELD_EXPLANATION("SINGLE DOMAIN INTERPOLATION", nullptr, FIELD_FLAG_NONE, "Note that if either the position or rotation discrepancy thresholds above which we use blending are exceeded, we will blend in both domains (because blending is more accurate and once we blend in either domain, we are forced to warp the physics representation of the object, which is the main downside of blending.  Therefore, the second domain is essentially \"free\" after we pay for the first w/ a physics warp.\n\nNote also that this discrepancy threshold is either WU or degrees, depending on context.  Check your context!"),
		{ _field_real, "discrepancy_threshold_above_which_we_use_blending", "Below this threshold we use velocity bumps.", "WU or degrees" },
		{ _field_real, "coming_to_rest_speed", "When our velocity is below this threshold, we will consider using a blend to minimize at-rest error.", "WU/s or degrees/s" },
		{ _field_real, "coming_to_rest_maximum_ignorable_error", "We will use a blend when our speed is below the coming_to_rest_speed and our error is greater than this.", "WU or degrees" },
		FIELD_CUSTOM("Velocity bumps", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "velocity bumps", &single_domain_velocity_bumps_configuration_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		FIELD_CUSTOM("Blending", nullptr, FIELD_FLAG_NONE, _field_id_field_group_begin),
		{ _field_struct, "blending", &single_domain_blending_configuration_struct },
		FIELD_CUSTOM(nullptr, nullptr, FIELD_FLAG_NONE, _field_id_field_group_end),
		{ _field_terminator }
	};

	#define SINGLE_DOMAIN_VELOCITY_BUMPS_CONFIGURATION_STRUCT_ID { 0xE01ED32B, 0x4AC44923, 0xA38213D0, 0x8598722B }
	TAG_STRUCT(
		single_domain_velocity_bumps_configuration_struct,
		"single_domain_velocity_bumps_configuration_struct",
		"s_simulation_single_domain_velocity_bumps_configuration",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SINGLE_DOMAIN_VELOCITY_BUMPS_CONFIGURATION_STRUCT_ID)
	{
		FIELD_EXPLANATION("SINGLE DOMAIN VELOCITY BUMPS", nullptr, FIELD_FLAG_NONE, "Velocity bumps are used for small mis-predictions because they are more visually pleasing than straight blending. However, they are less accurate, less consistent, and harder to tune."),
		{ _field_real, "velocity_scale", "Fraction of delta that becomes the velocity bump" },
		{ _field_real, "velocity_min", "Minimum size of any given velocity bump", "WU or degrees per second" },
		{ _field_real, "velocity_max", "Maximum size of any given velocity bump", "WU or degrees per second" },
		FIELD_EXPLANATION("Velocity Bump Suppression", nullptr, FIELD_FLAG_NONE, "We suppress velocity bumps when the object is \"close enough\" to encourage objects to come to rest. Both of the below conditions must be satisfied to suppress velocity bumps."),
		{ _field_real, "velocity_difference_ignore_threshold", "The new velocity must differ from the old velocity by less than this to allow suppression.", "WU or degrees per second" },
		{ _field_real, "velocity_difference_absolute_ignore_threshold", "The new position/rotation must differ from the old position/rotation by less than this to allow suppression.", "WU or degrees" },
		{ _field_terminator }
	};

	#define SINGLE_DOMAIN_BLENDING_CONFIGURATION_STRUCT_ID { 0x47E921D4, 0x65AB4EBE, 0x8A71EF41, 0x224410B1 }
	TAG_STRUCT(
		single_domain_blending_configuration_struct,
		"single_domain_blending_configuration_struct",
		"s_simulation_single_domain_blending_configuration",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		SINGLE_DOMAIN_BLENDING_CONFIGURATION_STRUCT_ID)
	{
		FIELD_EXPLANATION("SINGLE DOMAIN BLENDING CONFIGURATION", nullptr, FIELD_FLAG_NONE, "Whether these speeds are linear or angular depends on the context - check context before modifying."),
		{ _field_real, "min_object_speed", "Approximate minimum speed for this object (either controlled or uncontrolled).", "WU or degrees per second" },
		{ _field_real, "max_object_speed", "Approximate maximum speed for this object (either controlled or uncontrolled).", "WU or degrees per second" },
		{ _field_real, "fraction_at_min_object_speed", "Fraction of misprediction error consumed each tick if object is traveling at or below min_object_speed.  Linterp is executed at intermediate object speeds." },
		{ _field_real, "fraction_at_max_object_speed", "Fraction of misprediction error consumed each tick if object is traveling at or above max_object_speed.  Linterp is executed at intermediate object speeds." },
		{ _field_real, "min_speed_at_min_object_speed", "Minimum misprediction error consumption speed if object is at or below min_object_speed.  Linterp is executed at intermediate object speeds.", "WU or degrees per second" },
		{ _field_real, "min_speed_at_max_object_speed", "Minimum misprediction error consumption speed if object is at or above max_object_speed. Linterp is executed at intermediate object speeds.", "WU or degrees per second" },
		{ _field_terminator }
	};

	TAG_REFERENCE(global_simulation_interpolation_reference, SIMULATION_INTERPOLATION_TAG);

} // namespace macaque

} // namespace blofeld

