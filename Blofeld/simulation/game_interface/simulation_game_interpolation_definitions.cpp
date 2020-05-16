#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(simulation_interpolation, SIMULATION_INTERPOLATION_TAG, simulation_interpolation_block_block )

TAG_BLOCK_FROM_STRUCT(simulation_interpolation_block, 1, simulation_interpolation_struct_definition_struct_definition );

TAG_STRUCT(simulation_interpolation_struct_definition)
{
	FIELD( _field_explanation, "SIMULATION INTERPOLATION" ),
	FIELD( _field_custom, "High level settings" ),
	FIELD( _field_real, "position_client_ignore_tolerance:WU#How much rope clients have WRT their controlled object of this type. They are free to ignore host updates within this tolerance." ),
	FIELD( _field_real, "angular_speed_threshold_for_temporarily_ignoring_rotation_updates:degrees per second#If angular speed exceeds this threshold, we will ignore rotational updates (because it\'s spinning so fast that we can\'t possibly do a good job w/ any kind of interpolation - instead, just wait for it to settle down a bit).  Note that if a warp threshold is exceeded, rotation will be warped regardless of the value of this parameter." ),
	FIELD( _field_custom, "Warp Thresholds" ),
	FIELD( _field_explanation, "WARP THRESHOLDS" ),
	FIELD( _field_real, "position_warp_threshold:WU#Threshold of position error beyond which we will warp instead of interpolating." ),
	FIELD( _field_real, "position_warp_threshold_xy:WU#Separated for bipeds, for whom z discrepancies are more permissible because of jumping. If you don\'t want a special lower XY threshold, just set this to a very high number." ),
	FIELD( _field_real, "rotation_warp_threshold:degrees#Threshold of rotation error beyond which we will warp instead of interpolating.  Set this to 180.0 if you don\'t want to warp based on rotational deviation (may be important for objects that often spin very fast, e.g. grenades or garbage bits)." ),
	FIELD( _field_custom ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Position while controlled" ),
	FIELD( _field_struct, "position_while_controlled#All speeds in here are WU/s", &single_domain_configuration_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Rotation while controlled" ),
	FIELD( _field_struct, "rotation_while_controlled#All speeds in here are degrees/s", &single_domain_configuration_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Position while not controlled" ),
	FIELD( _field_struct, "position_while_uncontrolled#All speeds in here are WU/s", &single_domain_configuration_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Rotation while not controlled" ),
	FIELD( _field_struct, "rotation_while_uncontrolled#All speeds in here are degrees/s", &single_domain_configuration_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(single_domain_configuration_struct)
{
	FIELD( _field_explanation, "SINGLE DOMAIN INTERPOLATION" ),
	FIELD( _field_real, "discrepancy_threshold_above_which_we_use_blending:WU or degrees#Below this threshold we use velocity bumps." ),
	FIELD( _field_real, "coming_to_rest_speed:WU/s or degrees/s#When our velocity is below this threshold, we will consider using a blend to minimize at-rest error." ),
	FIELD( _field_real, "coming_to_rest_maximum_ignorable_error:WU or degrees#We will use a blend when our speed is below the coming_to_rest_speed and our error is greater than this." ),
	FIELD( _field_custom, "Velocity bumps" ),
	FIELD( _field_struct, "velocity bumps", &single_domain_velocity_bumps_configuration_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Blending" ),
	FIELD( _field_struct, "blending", &single_domain_blending_configuration_struct_struct_definition ),
	FIELD( _field_custom ),
	FIELD( _field_terminator )
};

TAG_STRUCT(single_domain_velocity_bumps_configuration_struct)
{
	FIELD( _field_explanation, "SINGLE DOMAIN VELOCITY BUMPS" ),
	FIELD( _field_real, "velocity_scale#Fraction of delta that becomes the velocity bump" ),
	FIELD( _field_real, "velocity_min:WU or degrees per second#Minimum size of any given velocity bump" ),
	FIELD( _field_real, "velocity_max:WU or degrees per second#Maximum size of any given velocity bump" ),
	FIELD( _field_explanation, "Velocity Bump Suppression" ),
	FIELD( _field_real, "velocity_difference_ignore_threshold:WU or degrees per second#The new velocity must differ from the old velocity by less than this to allow suppression." ),
	FIELD( _field_real, "velocity_difference_absolute_ignore_threshold:WU or degrees#The new position/rotation must differ from the old position/rotation by less than this to allow suppression." ),
	FIELD( _field_terminator )
};

TAG_STRUCT(single_domain_blending_configuration_struct)
{
	FIELD( _field_explanation, "SINGLE DOMAIN BLENDING CONFIGURATION" ),
	FIELD( _field_real, "min_object_speed:WU or degrees per second#Approximate minimum speed for this object (either controlled or uncontrolled)." ),
	FIELD( _field_real, "max_object_speed:WU or degrees per second#Approximate maximum speed for this object (either controlled or uncontrolled)." ),
	FIELD( _field_real, "fraction_at_min_object_speed#Fraction of misprediction error consumed each tick if object is traveling at or below min_object_speed.  Linterp is executed at intermediate object speeds." ),
	FIELD( _field_real, "fraction_at_max_object_speed#Fraction of misprediction error consumed each tick if object is traveling at or above max_object_speed.  Linterp is executed at intermediate object speeds." ),
	FIELD( _field_real, "min_speed_at_min_object_speed:WU or degrees per second#Minimum misprediction error consumption speed if object is at or below min_object_speed.  Linterp is executed at intermediate object speeds." ),
	FIELD( _field_real, "min_speed_at_max_object_speed:WU or degrees per second#Minimum misprediction error consumption speed if object is at or above max_object_speed. Linterp is executed at intermediate object speeds." ),
	FIELD( _field_terminator )
};

} // namespace blofeld

