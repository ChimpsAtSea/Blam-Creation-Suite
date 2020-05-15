#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(atmosphere_definition, k_max_atmosphere_settings)
{
	FIELD( _field_word_flags, "Flags" ),
	FIELD( _field_byte_integer, "Version!" ),
	FIELD( _field_pad, "ABCDEFGH", 1 ),
	FIELD( _field_explanation, "Ambient Fog Parameters" ),
	FIELD( _field_real, "distance bias:world units#negative means into the screen" ),
	FIELD( _field_custom, "Sky Fog" ),
	FIELD( _field_struct, "sky fog" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Ground Fog" ),
	FIELD( _field_struct, "ground fog" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Ceiling Fog BEWARE!" ),
	FIELD( _field_struct, "ceiling fog" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Fog Light" ),
	FIELD( _field_struct, "fog light" ),
	FIELD( _field_custom ),
	FIELD( _field_explanation, "Patchy Fog Per-Cluster Parameters" ),
	FIELD( _field_real, "Sheet density" ),
	FIELD( _field_real_rgb_color, "Color tint" ),
	FIELD( _field_real_rgb_color, "Color tint inner" ),
	FIELD( _field_real, "Intensity" ),
	FIELD( _field_real, "Full intensity height" ),
	FIELD( _field_real, "Half intensity height" ),
	FIELD( _field_real_vector_3d, "Wind direction" ),
	FIELD( _field_real, "Reference plane height" ),
	FIELD( _field_custom, "Volume Fog" ),
	FIELD( _field_struct, "volume fog" ),
	FIELD( _field_custom ),
	FIELD( _field_custom, "Light Shafts" ),
	FIELD( _field_struct, "light shaft" ),
	FIELD( _field_custom ),
	FIELD( _field_explanation, "Weather effect" ),
	FIELD( _field_tag_reference, "Weather effect" ),
	FIELD( _field_terminator )
};

TAG_GROUP_FROM_BLOCK(atmosphere_fog, ATMOSPHERE_FOG_TAG, atmosphere_definition_block)

} // namespace blofeld

