#include <blofeld-private-pch.h>

namespace blofeld
{

	TAG_ENUM(global_bitmap_flags, 1)
	{
		OPTION("don\'t load bitmap by default"),
	};

	TAG_GROUP_FROM_BLOCK(rasterizer_globals, RASTERIZER_GLOBALS_TAG, rasterizer_globals_block_block );

	TAG_BLOCK_FROM_STRUCT(rasterizer_globals_block, 1, rasterizer_globals_struct_definition_struct_definition );

	TAG_BLOCK(default_textures_refs_block, 32)
	{
		FIELD( _field_long_flags, "options", &global_bitmap_flags ),
		FIELD( _field_tag_reference, "default bitmaps" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(material_textures_refs_block, 16)
	{
		FIELD( _field_tag_reference, "material textures" ),
		FIELD( _field_terminator )
	};

	TAG_BLOCK(explicit_shader_refs_block, 256)
	{
		FIELD( _field_string_id, "name" ),
		FIELD( _field_tag_reference, "explicit vertex shader" ),
		FIELD( _field_tag_reference, "explicit pixel shader^" ),
		FIELD( _field_terminator )
	};

TAG_STRUCT(rasterizer_globals_struct_definition)
{
		FIELD( _field_explanation, "default bitmaps:" ),
		FIELD( _field_block, "default bitmaps", &default_textures_refs_block_block ),
		FIELD( _field_explanation, "material textures:" ),
		FIELD( _field_block, "material textures", &material_textures_refs_block_block ),
		FIELD( _field_explanation, "explicit shaders:" ),
		FIELD( _field_block, "explicit shaders", &explicit_shader_refs_block_block ),
		FIELD( _field_tag_reference, "Active Camo Distortion Texture" ),
		FIELD( _field_tag_reference, "default performance throttles" ),
		FIELD( _field_tag_reference, "Logo Texture" ),
		FIELD( _field_tag_reference, "Cheap Particle Type Library" ),
		FIELD( _field_tag_reference, "Emblem Library" ),
		FIELD( _field_explanation, "Motion blur parameters:" ),
		FIELD( _field_real, "max blur{max blur x}:[0 - 0.2]#max amount to blur, as a percentage of the screen" ),
		FIELD( _field_real, "blur scale{blur scale x}:[0 - 0.5]#scales blur for a given velocity" ),
		FIELD( _field_real, "center falloff x:[0 - 20]#larger values make smaller areas of no blur" ),
		FIELD( _field_real, "center falloff y:[0 - 20]#larger values make smaller areas of no blur" ),
		FIELD( _field_explanation, "screen space light parameters:" ),
		FIELD( _field_real, "cheap albedo blend#for all screen space light without shader reference" ),
		FIELD( _field_explanation, "Lighting layer debug mode albedo override" ),
		FIELD( _field_real_rgb_color, "lighting layer albedo color#the floating point values are linear and what the shader will sample for albedo" ),
		FIELD( _field_tag_reference, "Hologram Camera FX" ),
		FIELD( _field_tag_reference, "Global load screen model" ),
		FIELD( _field_real, "Global load screen gradient coordinate" ),
		FIELD( _field_tag_reference, "airprobe render model" ),
		FIELD( _field_terminator )
};

} // namespace blofeld

