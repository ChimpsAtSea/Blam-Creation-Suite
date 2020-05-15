#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_GROUP_INHERIT(shader_particle, SHADER_PARTICLE_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_real_rgb_color, "bright tint" ),
	FIELD( _field_real_rgb_color, "ambient tint" ),
	FIELD( _field_real, "contrast" ),
	FIELD( _field_real, "blur weight" ),
	FIELD( _field_real, "intensity scale" ),
	FIELD( _field_tag_reference, "palette" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_custom, SHADER_CUSTOM_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_cortana, SHADER_CORTANA_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_decal, SHADER_DECAL_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_long_integer, "specular_modulate!" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_foliage, SHADER_FOLIAGE_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_fur_stencil, SHADER_FUR_STENCIL_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_fur, SHADER_FUR_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_glass, SHADER_GLASS_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_halogram, SHADER_HALOGRAM_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_light_volume, SHADER_LIGHT_VOLUME_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_mux_material, SHADER_MUX_MATERIAL_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_mux, SHADER_MUX_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_string_id, "material name 0#defines global material type for channel 0 of the mux shader" ),
	FIELD( _field_string_id, "material name 1#defines global material type for channel 1 of the mux shader" ),
	FIELD( _field_string_id, "material name 2#defines global material type for channel 2 of the mux shader" ),
	FIELD( _field_string_id, "material name 3#defines global material type for channel 3 of the mux shader" ),
	FIELD( _field_struct, "material type 0!" ),
	FIELD( _field_struct, "material type 1!" ),
	FIELD( _field_struct, "material type 2!" ),
	FIELD( _field_struct, "material type 3!" ),
	FIELD( _field_long_integer, "single material!" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader, SHADER_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_skin, SHADER_SKIN_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_screen, SHADER_SCREEN_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_char_enum, "render layer" ),
	FIELD( _field_char_integer, "sort order" ),
	FIELD( _field_byte_flags, "render flags" ),
	FIELD( _field_pad, "fefjjjfrjg", 1 ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_terrain, SHADER_TERRAIN_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_string_id, "material name 0#defines global material type for channel 0 of the terrain shader" ),
	FIELD( _field_string_id, "material name 1#defines global material type for channel 1 of the terrain shader" ),
	FIELD( _field_string_id, "material name 2#defines global material type for channel 2 of the terrain shader" ),
	FIELD( _field_string_id, "material name 3#defines global material type for channel 3 of the terrain shader" ),
	FIELD( _field_struct, "material type 0!" ),
	FIELD( _field_struct, "material type 1!" ),
	FIELD( _field_struct, "material type 2!" ),
	FIELD( _field_struct, "material type 3!" ),
	FIELD( _field_long_integer, "single material!" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_water, SHADER_WATER_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_waterfall, SHADER_WATERFALL_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method" ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

