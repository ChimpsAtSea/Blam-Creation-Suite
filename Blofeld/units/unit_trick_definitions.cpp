#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(unit_trick_activation_type_enum, 20)
	{
		OPTION("brake + left"),
		OPTION("brake + right"),
		OPTION("brake + up"),
		OPTION("brake + down"),
		OPTION("throw movement left"),
		OPTION("throw movement right"),
		OPTION("throw movement up"),
		OPTION("throw movement down"),
		OPTION("throw look left"),
		OPTION("throw look right"),
		OPTION("throw look up"),
		OPTION("throw look down"),
		OPTION("peg-flick-jump left"),
		OPTION("peg-flick-jump right"),
		OPTION("peg-flick-jump up"),
		OPTION("peg-flick-jump down"),
		OPTION("double-jump left"),
		OPTION("double-jump right"),
		OPTION("double-jump up"),
		OPTION("double-jump down"),
	};

	TAG_ENUM(unit_trick_velocity_preservation_mode_enum, 3)
	{
		OPTION("none#velocity is completely removed"),
		OPTION("trick relative#velocity is relative to the object\'s orientation at the start of the trick (so if you\'re moving forward before the trick, you will be moving forward after the trick, even if that\'s a different direction)"),
		OPTION("world relative#velocity is maintained in world space"),
	};

	TAG_ENUM(unit_trick_flags, 2)
	{
		OPTION("use following camera#as opposed to the trick camera, which is the default\nvehicles only"),
		OPTION("do not slam player control#allows the player to continue to move aiming vector while tricking"),
	};

	TAG_BLOCK(unit_trick_definition_block, k_maximum_trick_definitions_per_unit)
	{
		FIELD( _field_string_id, "animation name^" ),
		FIELD( _field_char_enum, "activation type", &unit_trick_activation_type_enum ),
		FIELD( _field_char_enum, "velocity preservation#specifies how pre-trick velocity is maintained during and after the trick\nonly applies to vehicles", &unit_trick_velocity_preservation_mode_enum ),
		FIELD( _field_byte_flags, "flags", &unit_trick_flags ),
		FIELD( _field_pad, "XEKMVZ", 1 ),
		FIELD( _field_real, "camera interpolation time:s#sloppiness of the camera\nonly applies to vehicles" ),
		FIELD( _field_real, "trick exit time:s#how long before the end of the trick we start using the below values" ),
		FIELD( _field_real_bounds, "trick exit camera interpolation time:s#sloppiness of the camera when exiting the trick\nwe interpolate between these values depending on how far your camera was displaced from the ideal camera" ),
		FIELD( _field_real, "trick exit displacement reference:wu#when your camera is this far from the ideal at the start of the trick, we use the maximum delay time above\nonly for space fighter" ),
		FIELD( _field_real, "cooldown time:s#after ending this trick, how long until I can trick again\nonly applies to vehicles" ),
		FIELD( _field_terminator )
	};

} // namespace blofeld

