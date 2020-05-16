#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_STRUCT(shader_particle_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_real_rgb_color, "bright tint" ),
	FIELD( _field_real_rgb_color, "ambient tint" ),
	FIELD( _field_real, "contrast" ),
	FIELD( _field_real, "blur weight" ),
	FIELD( _field_real, "intensity scale" ),
	FIELD( _field_tag_reference, "palette" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_custom_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_cortana_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_decal_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_long_integer, "specular_modulate!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_foliage_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_fur_stencil_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_fur_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_glass_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_halogram_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_light_volume_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_mux_material_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_mux_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name 0#defines global material type for channel 0 of the mux shader" ),
	FIELD( _field_string_id, "material name 1#defines global material type for channel 1 of the mux shader" ),
	FIELD( _field_string_id, "material name 2#defines global material type for channel 2 of the mux shader" ),
	FIELD( _field_string_id, "material name 3#defines global material type for channel 3 of the mux shader" ),
	FIELD( _field_struct, "material type 0!", &material_type_struct_struct_definition ),
	FIELD( _field_struct, "material type 1!", &material_type_struct_struct_definition ),
	FIELD( _field_struct, "material type 2!", &material_type_struct_struct_definition ),
	FIELD( _field_struct, "material type 3!", &material_type_struct_struct_definition ),
	FIELD( _field_long_integer, "single material!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_skin_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_screen_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_char_enum, "render layer" ),
	FIELD( _field_char_integer, "sort order" ),
	FIELD( _field_byte_flags, "render flags" ),
	FIELD( _field_pad, "fefjjjfrjg", 1 ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_terrain_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name 0#defines global material type for channel 0 of the terrain shader" ),
	FIELD( _field_string_id, "material name 1#defines global material type for channel 1 of the terrain shader" ),
	FIELD( _field_string_id, "material name 2#defines global material type for channel 2 of the terrain shader" ),
	FIELD( _field_string_id, "material name 3#defines global material type for channel 3 of the terrain shader" ),
	FIELD( _field_struct, "material type 0!", &material_type_struct_struct_definition ),
	FIELD( _field_struct, "material type 1!", &material_type_struct_struct_definition ),
	FIELD( _field_struct, "material type 2!", &material_type_struct_struct_definition ),
	FIELD( _field_struct, "material type 3!", &material_type_struct_struct_definition ),
	FIELD( _field_long_integer, "single material!" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_water_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_waterfall_struct_definition)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(shader_particle_struct_definition$2)
{
	FIELD( _field_custom ),
	FIELD( _field_tag_reference, "definition*" ),
	FIELD( _field_tag_reference, "reference" ),
	FIELD( _field_block, "options", &short_block ),
	FIELD( _field_block, "parameters", &render_method_parameter_block ),
	FIELD( _field_block, "postprocess", &render_method_postprocess_block ),
	FIELD( _field_long_integer, "is template" ),
	FIELD( _field_long_flags, "locked options" ),
	FIELD( _field_block, "locked parameters", &render_method_locked_parameter_block ),
	FIELD( _field_word_flags, "shader flags*" ),
	FIELD( _field_char_enum, "sort layer*" ),
	FIELD( _field_char_integer, "version!" ),
	FIELD( _field_long_integer, "Custom fog setting index" ),
	FIELD( _field_long_block_index, "prediction atom index!" ),
	FIELD( _field_real_rgb_color, "bright tint" ),
	FIELD( _field_real_rgb_color, "ambient tint" ),
	FIELD( _field_real, "contrast" ),
	FIELD( _field_real, "blur weight" ),
	FIELD( _field_real, "intensity scale" ),
	FIELD( _field_tag_reference, "palette" ),
	FIELD( _field_terminator )
};

TAG_STRUCT(material_type_struct)
{
	FIELD( _field_short_integer, "global material index" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_particle_block, SHADER_PARTICLE_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_real_rgb_color, "bright tint" ),
	FIELD( _field_real_rgb_color, "ambient tint" ),
	FIELD( _field_real, "contrast" ),
	FIELD( _field_real, "blur weight" ),
	FIELD( _field_real, "intensity scale" ),
	FIELD( _field_tag_reference, "palette" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_custom_block, SHADER_CUSTOM_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_cortana_block, SHADER_CORTANA_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_decal_block, SHADER_DECAL_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_long_integer, "specular_modulate!" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_foliage_block, SHADER_FOLIAGE_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_fur_stencil_block, SHADER_FUR_STENCIL_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_fur_block, SHADER_FUR_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_glass_block, SHADER_GLASS_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_halogram_block, SHADER_HALOGRAM_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_light_volume_block, SHADER_LIGHT_VOLUME_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_mux_material_block, SHADER_MUX_MATERIAL_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_mux_block, SHADER_MUX_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name 0#defines global material type for channel 0 of the mux shader" ),
	FIELD( _field_string_id, "material name 1#defines global material type for channel 1 of the mux shader" ),
	FIELD( _field_string_id, "material name 2#defines global material type for channel 2 of the mux shader" ),
	FIELD( _field_string_id, "material name 3#defines global material type for channel 3 of the mux shader" ),
	FIELD( _field_struct, "material type 0!", &material_type_struct_struct_definition ),
	FIELD( _field_struct, "material type 1!", &material_type_struct_struct_definition ),
	FIELD( _field_struct, "material type 2!", &material_type_struct_struct_definition ),
	FIELD( _field_struct, "material type 3!", &material_type_struct_struct_definition ),
	FIELD( _field_long_integer, "single material!" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_block, SHADER_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_skin_block, SHADER_SKIN_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_screen_block, SHADER_SCREEN_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_char_enum, "render layer" ),
	FIELD( _field_char_integer, "sort order" ),
	FIELD( _field_byte_flags, "render flags" ),
	FIELD( _field_pad, "fefjjjfrjg", 1 ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_terrain_block, SHADER_TERRAIN_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name 0#defines global material type for channel 0 of the terrain shader" ),
	FIELD( _field_string_id, "material name 1#defines global material type for channel 1 of the terrain shader" ),
	FIELD( _field_string_id, "material name 2#defines global material type for channel 2 of the terrain shader" ),
	FIELD( _field_string_id, "material name 3#defines global material type for channel 3 of the terrain shader" ),
	FIELD( _field_struct, "material type 0!", &material_type_struct_struct_definition ),
	FIELD( _field_struct, "material type 1!", &material_type_struct_struct_definition ),
	FIELD( _field_struct, "material type 2!", &material_type_struct_struct_definition ),
	FIELD( _field_struct, "material type 3!", &material_type_struct_struct_definition ),
	FIELD( _field_long_integer, "single material!" ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_water_block, SHADER_WATER_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_terminator )
};

TAG_GROUP_INHERIT(shader_waterfall_block, SHADER_WATERFALL_TAG, render_method, RENDER_METHOD_TAG)
{
	FIELD( _field_struct, "render_method", &render_method_struct_definition_struct_definition ),
	FIELD( _field_string_id, "material name" ),
	FIELD( _field_terminator )
};

} // namespace blofeld

