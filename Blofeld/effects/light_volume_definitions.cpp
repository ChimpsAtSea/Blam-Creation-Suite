#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(light_volume_definition, c_light_volume_system_definition::k_max_light_volume)
{
	{ _field_custom },
	{ _field_string_id, "light_volume name^" },
	{ _field_custom, "material" },
	{ _field_custom },
	{ _field_struct, "actual material\?" },
	{ _field_custom },
	{ _field_word_flags, "appearance flags" },
	{ _field_pad, "SONGWEOINGEW", 2 },
	{ _field_real, "brightness ratio#avg. brightness head-on/side-view" },
	{ _field_long_flags, "flags" },
	{ _field_real, "LOD in distance#defaults to 0.0, ignored if \'lod enabled\' not checked above" },
	{ _field_real, "LOD feather in delta#defaults to 0.0, ignored if \'lod enabled\' not checked above" },
	{ _field_real, "inverse LOD feather in!" },
	{ _field_real, "LOD out distance#defaults to 30.0, ignored if \'lod enabled\' not checked above" },
	{ _field_real, "LOD feather out delta#defaults to 10.0, ignored if \'lod enabled\' not checked above" },
	{ _field_real, "inverse LOD feather out!" },
	{ _field_struct, "length" },
	{ _field_struct, "offset" },
	{ _field_struct, "profile_density" },
	{ _field_struct, "profile_length" },
	{ _field_struct, "profile_thickness" },
	{ _field_struct, "profile_color" },
	{ _field_struct, "profile_alpha" },
	{ _field_struct, "profile_intensity" },
	{ _field_custom },
	{ _field_dword_integer, "runtime m_constant_per_profile_properties!" },
	{ _field_dword_integer, "runtime m_used_states!" },
	{ _field_dword_integer, "runtime m_max_profile_count!" },
	{ _field_struct, "runtime m_gpu_data!" },
	{ _field_block, "precompiled vertices", &light_volume_precompiled_vert_block },
	{ _field_terminator },
};

TAG_BLOCK(light_volume_precompiled_vert, c_light_volume_definition::k_max_precompiled_profiles)
{
	{ _field_word_integer, "r" },
	{ _field_word_integer, "g" },
	{ _field_word_integer, "b" },
	{ _field_word_integer, "thickness" },
	{ _field_terminator },
};

TAG_GROUP(light_volume_system, LIGHT_VOLUME_SYSTEM_TAG)
{
	{ _field_block, "light_volumes", &light_volume_definition_block },
	{ _field_terminator },
};

} // namespace blofeld

