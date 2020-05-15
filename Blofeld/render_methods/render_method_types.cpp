#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_INHERIT(shader_particle, SHADER_PARTICLE_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_real_rgb_color, "bright tint" },
	{ _field_real_rgb_color, "ambient tint" },
	{ _field_real, "contrast" },
	{ _field_real, "blur weight" },
	{ _field_real, "intensity scale" },
	{ _field_tag_reference, "palette" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(shader_custom, SHADER_CUSTOM_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_string_id, "material name" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(shader_cortana, SHADER_CORTANA_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_string_id, "material name" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(shader_decal, SHADER_DECAL_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_long_integer, "specular_modulate!" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(shader_foliage, SHADER_FOLIAGE_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_string_id, "material name" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(shader_fur_stencil, SHADER_FUR_STENCIL_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_string_id, "material name" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(shader_fur, SHADER_FUR_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_string_id, "material name" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(shader_glass, SHADER_GLASS_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_string_id, "material name" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(shader_halogram, SHADER_HALOGRAM_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_string_id, "material name" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(shader_light_volume, SHADER_LIGHT_VOLUME_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(shader_mux_material, SHADER_MUX_MATERIAL_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_string_id, "material name" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(shader_mux, SHADER_MUX_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_string_id, "material name 0#defines global material type for channel 0 of the mux shader" },
	{ _field_string_id, "material name 1#defines global material type for channel 1 of the mux shader" },
	{ _field_string_id, "material name 2#defines global material type for channel 2 of the mux shader" },
	{ _field_string_id, "material name 3#defines global material type for channel 3 of the mux shader" },
	{ _field_struct, "material type 0!" },
	{ _field_struct, "material type 1!" },
	{ _field_struct, "material type 2!" },
	{ _field_struct, "material type 3!" },
	{ _field_long_integer, "single material!" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(shader, SHADER_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_string_id, "material name" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(shader_skin, SHADER_SKIN_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_string_id, "material name" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(shader_screen, SHADER_SCREEN_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_string_id, "material name" },
	{ _field_char_enum, "render layer" },
	{ _field_char_integer, "sort order" },
	{ _field_byte_flags, "render flags" },
	{ _field_pad, "fefjjjfrjg", 1 },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(shader_terrain, SHADER_TERRAIN_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_string_id, "material name 0#defines global material type for channel 0 of the terrain shader" },
	{ _field_string_id, "material name 1#defines global material type for channel 1 of the terrain shader" },
	{ _field_string_id, "material name 2#defines global material type for channel 2 of the terrain shader" },
	{ _field_string_id, "material name 3#defines global material type for channel 3 of the terrain shader" },
	{ _field_struct, "material type 0!" },
	{ _field_struct, "material type 1!" },
	{ _field_struct, "material type 2!" },
	{ _field_struct, "material type 3!" },
	{ _field_long_integer, "single material!" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(shader_water, SHADER_WATER_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_terminator },
};

TAG_GROUP_INHERIT(shader_waterfall, SHADER_WATERFALL_TAG, render_method, RENDER_METHOD_TAG)
{
	{ _field_struct, "render_method" },
	{ _field_string_id, "material name" },
	{ _field_terminator },
};

} // namespace blofeld

