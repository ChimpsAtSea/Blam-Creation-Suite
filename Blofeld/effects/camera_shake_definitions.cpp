#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_FROM_BLOCK(camera_shake, CAMERA_SHAKE_TAG, camera_shake_block_block )

TAG_BLOCK_FROM_STRUCT(camera_shake_block, 1, camera_shake_struct_definition_struct_definition );

TAG_BLOCK(global_camera_impulse_block, 1)
{
	FIELD( _field_custom ),
	FIELD( _field_struct, "mapping", &mapping_function_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_shake_struct_definition)
{
	FIELD( _field_explanation, "camera impulse" ),
	FIELD( _field_struct, "camera impulse", &camera_impulse_struct_struct_definition ),
	FIELD( _field_explanation, "camera shake" ),
	FIELD( _field_struct, "camera shake", &camera_shake_struct_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_impulse_struct)
{
	FIELD( _field_real, "impulse duration:seconds" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "mapping", &mapping_function_struct_definition ),
	FIELD( _field_angle, "rotation:degrees" ),
	FIELD( _field_real, "pushback:world units" ),
	FIELD( _field_real_bounds, "jitter:world units" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(camera_shake_struct)
{
	FIELD( _field_real, "shake duration:seconds#the effect will last for this duration." ),
	FIELD( _field_explanation, "procedural camera shake" ),
	FIELD( _field_custom ),
	FIELD( _field_struct, "mapping", &mapping_function_struct_definition ),
	FIELD( _field_real, "random translation:world units#random translation in all directions" ),
	FIELD( _field_angle, "random rotation:degrees#random rotation in all directions" ),
	FIELD( _field_real, "wobble function period:seconds" ),
	FIELD( _field_real_fraction, "wobble weight#a value of 0.0 signifies that the wobble function has no effect; a value of 1.0 the wobble function completely scales the translational\n and rotational magnitudes.  The less the weight, the less the effect wobble has." ),
	FIELD( _field_enum, "wobble function#a function to perturb the effect\'s behavior over time" ),
	FIELD( _field_explanation, "animated camera shake" ),
	FIELD( _field_char_enum, "animated shake playback" ),
	FIELD( _field_char_enum, "animated shake weight" ),
	FIELD( _field_tag_reference, "animation graph" ),
	FIELD( _field_string_id, "animation name" ),
	FIELD( _field_real, "zoom penalty linear #multiplier penalty that increases linearly with zoom over 1" ),
	FIELD( _field_real, "zoom penalty squareroot #multiplier penalty that increases with square root of zoom over 1" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

