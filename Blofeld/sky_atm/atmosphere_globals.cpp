#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(underwater_setting, k_max_atmosphere_settings)
{
	{ _field_string_id, "Name" },
	{ _field_real, "Murkiness" },
	{ _field_real_rgb_color, "Fog Color" },
	{ _field_terminator },
};

TAG_GROUP(atmosphere_globals, ATMOSPHERE_GLOBALS_TAG)
{
	{ _field_explanation, "Patchy Fog Global Parameters" },
	{ _field_tag_reference, "Fog Bitmap" },
	{ _field_real, "Texture repeat rate" },
	{ _field_real, "Distance between sheets" },
	{ _field_real, "Depth fade factor" },
	{ _field_real, "Transparent sort distance" },
	{ _field_char_enum, "Transparent sort layer" },
	{ _field_pad, "UNdfdfdSED", 3 },
	{ _field_struct, "wind strength across distance" },
	{ _field_block, "underwater settings", &underwater_setting_block },
	{ _field_terminator },
};

} // namespace blofeld

