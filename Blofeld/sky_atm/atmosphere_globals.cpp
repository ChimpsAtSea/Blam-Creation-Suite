#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(underwater_setting, k_max_atmosphere_settings)
{
	FIELD( _field_string_id, "Name" ),
	FIELD( _field_real, "Murkiness" ),
	FIELD( _field_real_rgb_color, "Fog Color" ),
	FIELD( _field_terminator )
};

TAG_GROUP(atmosphere_globals, ATMOSPHERE_GLOBALS_TAG)
{
	FIELD( _field_explanation, "Patchy Fog Global Parameters" ),
	FIELD( _field_tag_reference, "Fog Bitmap" ),
	FIELD( _field_real, "Texture repeat rate" ),
	FIELD( _field_real, "Distance between sheets" ),
	FIELD( _field_real, "Depth fade factor" ),
	FIELD( _field_real, "Transparent sort distance" ),
	FIELD( _field_char_enum, "Transparent sort layer" ),
	FIELD( _field_pad, "UNdfdfdSED", 3 ),
	FIELD( _field_struct, "wind strength across distance" ),
	FIELD( _field_block, "underwater settings", &underwater_setting_block ),
	FIELD( _field_terminator )
};

} // namespace blofeld

