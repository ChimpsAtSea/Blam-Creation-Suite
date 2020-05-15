#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(unit_trick_definition, k_maximum_trick_definitions_per_unit)
{
	{ _field_string_id, "animation name^" },
	{ _field_char_enum, "activation type" },
	{ _field_char_enum, "velocity preservation#specifies how pre-trick velocity is maintained during and after the trick\nonly applies to vehicles" },
	{ _field_byte_flags, "flags" },
	{ _field_pad, "XEKMVZ", 1 },
	{ _field_real, "camera interpolation time:s#sloppiness of the camera\nonly applies to vehicles" },
	{ _field_real, "trick exit time:s#how long before the end of the trick we start using the below values" },
	{ _field_real_bounds, "trick exit camera interpolation time:s#sloppiness of the camera when exiting the trick\nwe interpolate between these values depending on how far your camera was displaced from the ideal camera" },
	{ _field_real, "trick exit displacement reference:wu#when your camera is this far from the ideal at the start of the trick, we use the maximum delay time above\nonly for space fighter" },
	{ _field_real, "cooldown time:s#after ending this trick, how long until I can trick again\nonly applies to vehicles" },
	{ _field_terminator },
};

} // namespace blofeld

