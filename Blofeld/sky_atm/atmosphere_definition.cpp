#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(atmosphere_definition, k_max_atmosphere_settings)
{
	{ _field_word_flags, "Flags" },
	{ _field_byte_integer, "Version!" },
	{ _field_pad, "ABCDEFGH", 1 },
	{ _field_explanation, "Ambient Fog Parameters" },
	{ _field_real, "distance bias:world units#negative means into the screen" },
	{ _field_custom, "Sky Fog" },
	{ _field_struct, "sky fog" },
	{ _field_custom },
	{ _field_custom, "Ground Fog" },
	{ _field_struct, "ground fog" },
	{ _field_custom },
	{ _field_custom, "Ceiling Fog BEWARE!" },
	{ _field_struct, "ceiling fog" },
	{ _field_custom },
	{ _field_custom, "Fog Light" },
	{ _field_struct, "fog light" },
	{ _field_custom },
	{ _field_explanation, "Patchy Fog Per-Cluster Parameters" },
	{ _field_real, "Sheet density" },
	{ _field_real_rgb_color, "Color tint" },
	{ _field_real_rgb_color, "Color tint inner" },
	{ _field_real, "Intensity" },
	{ _field_real, "Full intensity height" },
	{ _field_real, "Half intensity height" },
	{ _field_real_vector_3d, "Wind direction" },
	{ _field_real, "Reference plane height" },
	{ _field_custom, "Volume Fog" },
	{ _field_struct, "volume fog" },
	{ _field_custom },
	{ _field_custom, "Light Shafts" },
	{ _field_struct, "light shaft" },
	{ _field_custom },
	{ _field_explanation, "Weather effect" },
	{ _field_tag_reference, "Weather effect" },
	{ _field_terminator },
};

TAG_GROUP_FROM_BLOCK(atmosphere_fog, ATMOSPHERE_FOG_TAG, atmosphere_definition_block)

} // namespace blofeld

