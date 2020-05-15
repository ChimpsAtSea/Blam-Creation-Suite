#include <blofeld-private-pch.h>

namespace blofeld
{

TAG_BLOCK(default_textures_refs, 32)
{
	{ _field_long_flags, "options" },
	{ _field_tag_reference, "default bitmaps" },
	{ _field_terminator },
};

TAG_BLOCK(material_textures_refs, 16)
{
	{ _field_tag_reference, "material textures" },
	{ _field_terminator },
};

TAG_BLOCK(explicit_shader_refs, 256)
{
	{ _field_string_id, "name" },
	{ _field_tag_reference, "explicit vertex shader" },
	{ _field_tag_reference, "explicit pixel shader^" },
	{ _field_terminator },
};

TAG_GROUP(rasterizer_globals, RASTERIZER_GLOBALS_TAG)
{
	{ _field_explanation, "default bitmaps:" },
	{ _field_block, "default bitmaps", &default_textures_refs_block },
	{ _field_explanation, "material textures:" },
	{ _field_block, "material textures", &material_textures_refs_block },
	{ _field_explanation, "explicit shaders:" },
	{ _field_block, "explicit shaders", &explicit_shader_refs_block },
	{ _field_tag_reference, "Active Camo Distortion Texture" },
	{ _field_tag_reference, "default performance throttles" },
	{ _field_tag_reference, "Logo Texture" },
	{ _field_tag_reference, "Cheap Particle Type Library" },
	{ _field_tag_reference, "Emblem Library" },
	{ _field_explanation, "Motion blur parameters:" },
	{ _field_real, "max blur{max blur x}:[0 - 0.2]#max amount to blur, as a percentage of the screen" },
	{ _field_real, "blur scale{blur scale x}:[0 - 0.5]#scales blur for a given velocity" },
	{ _field_real, "center falloff x:[0 - 20]#larger values make smaller areas of no blur" },
	{ _field_real, "center falloff y:[0 - 20]#larger values make smaller areas of no blur" },
	{ _field_explanation, "screen space light parameters:" },
	{ _field_real, "cheap albedo blend#for all screen space light without shader reference" },
	{ _field_explanation, "Lighting layer debug mode albedo override" },
	{ _field_real_rgb_color, "lighting layer albedo color#the floating point values are linear and what the shader will sample for albedo" },
	{ _field_tag_reference, "Hologram Camera FX" },
	{ _field_tag_reference, "Global load screen model" },
	{ _field_real, "Global load screen gradient coordinate" },
	{ _field_tag_reference, "airprobe render model" },
	{ _field_terminator },
};

} // namespace blofeld

