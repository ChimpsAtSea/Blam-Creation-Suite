#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_BLOCK(unit_trick_definition_block, k_maximum_trick_definitions_per_unit)
	{
		{ _field_legacy, _field_string_id, "animation name^" },
		{ _field_legacy, _field_char_enum, "activation type", &unit_trick_activation_type_enum },
		{ _field_legacy, _field_char_enum, "velocity preservation#specifies how pre-trick velocity is maintained during and after the trick\nonly applies to vehicles", &unit_trick_velocity_preservation_mode_enum },
		{ _field_legacy, _field_byte_flags, "flags", &unit_trick_flags },
		{ _field_legacy, _field_pad, "XEKMVZ", 1 },
		{ _field_legacy, _field_real, "camera interpolation time:s#sloppiness of the camera\nonly applies to vehicles" },
		{ _field_legacy, _field_real, "trick exit time:s#how long before the end of the trick we start using the below values" },
		{ _field_legacy, _field_real_bounds, "trick exit camera interpolation time:s#sloppiness of the camera when exiting the trick\nwe interpolate between these values depending on how far your camera was displaced from the ideal camera" },
		{ _field_legacy, _field_real, "trick exit displacement reference:wu#when your camera is this far from the ideal at the start of the trick, we use the maximum delay time above\nonly for space fighter" },
		{ _field_legacy, _field_real, "cooldown time:s#after ending this trick, how long until I can trick again\nonly applies to vehicles" },
		{ _field_legacy, _field_terminator }
	};

	STRINGS(unit_trick_activation_type_enum)
	{
		"brake + left",
		"brake + right",
		"brake + up",
		"brake + down",
		"throw movement left",
		"throw movement right",
		"throw movement up",
		"throw movement down",
		"throw look left",
		"throw look right",
		"throw look up",
		"throw look down",
		"peg-flick-jump left",
		"peg-flick-jump right",
		"peg-flick-jump up",
		"peg-flick-jump down",
		"double-jump left",
		"double-jump right",
		"double-jump up",
		"double-jump down"
	};
	STRING_LIST(unit_trick_activation_type_enum, unit_trick_activation_type_enum_strings, _countof(unit_trick_activation_type_enum_strings));

	STRINGS(unit_trick_velocity_preservation_mode_enum)
	{
		"none#velocity is completely removed",
		"trick relative#velocity is relative to the object\'s orientation at the start of the trick (so if you\'re moving forward before the trick, you will be moving forward after the trick, even if that\'s a different direction)",
		"world relative#velocity is maintained in world space"
	};
	STRING_LIST(unit_trick_velocity_preservation_mode_enum, unit_trick_velocity_preservation_mode_enum_strings, _countof(unit_trick_velocity_preservation_mode_enum_strings));

	STRINGS(unit_trick_flags)
	{
		"use following camera#as opposed to the trick camera, which is the default\nvehicles only",
		"do not slam player control#allows the player to continue to move aiming vector while tricking"
	};
	STRING_LIST(unit_trick_flags, unit_trick_flags_strings, _countof(unit_trick_flags_strings));

} // namespace blofeld

