#include <blofeld-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	TAG_GROUP_FROM_BLOCK(rasterizer_globals, RASTERIZER_GLOBALS_TAG, rasterizer_globals_block_block );

	TAG_BLOCK(default_textures_refs_block, 32)
	{
		{ _field_long_flags, "options", &global_bitmap_flags },
		{ _field_tag_reference, "default bitmaps", &bitmap_reference$11 },
		{ _field_terminator }
	};

	TAG_BLOCK(material_textures_refs_block, 16)
	{
		{ _field_tag_reference, "material textures", &global_bitmap_reference },
		{ _field_terminator }
	};

	TAG_BLOCK(explicit_shader_refs_block, 256)
	{
		{ _field_string_id, "name" },
		{ _field_tag_reference, "explicit vertex shader", &explicit_shader_refs_block_explicit_vertex_shader_reference },
		{ _field_tag_reference, "explicit pixel shader^", &explicit_shader_refs_block_explicit_pixel_shader_reference },
		{ _field_terminator }
	};

	TAG_BLOCK_FROM_STRUCT(rasterizer_globals_block, 1, rasterizer_globals_struct_definition_struct_definition );

	TAG_STRUCT(rasterizer_globals_struct_definition)
	{
		{ _field_explanation, "default bitmaps:" },
		{ _field_block, "default bitmaps", &default_textures_refs_block_block },
		{ _field_explanation, "material textures:" },
		{ _field_block, "material textures", &material_textures_refs_block_block },
		{ _field_explanation, "explicit shaders:" },
		{ _field_block, "explicit shaders", &explicit_shader_refs_block_block },
		{ _field_tag_reference, "Active Camo Distortion Texture", &global_bitmap_reference },
		{ _field_tag_reference, "default performance throttles", &global_performance_throttles_reference },
		{ _field_tag_reference, "Logo Texture", &global_bitmap_reference },
		{ _field_tag_reference, "Cheap Particle Type Library", &cheap_particle_type_library_reference$2 },
		{ _field_tag_reference, "Emblem Library", &global_emblem_library_parameters_reference },
		{ _field_explanation, "Motion blur parameters:" },
		{ _field_real, "max blur{max blur x}:[0 - 0.2]#max amount to blur, as a percentage of the screen" },
		{ _field_real, "blur scale{blur scale x}:[0 - 0.5]#scales blur for a given velocity" },
		{ _field_real, "center falloff x:[0 - 20]#larger values make smaller areas of no blur" },
		{ _field_real, "center falloff y:[0 - 20]#larger values make smaller areas of no blur" },
		{ _field_explanation, "screen space light parameters:" },
		{ _field_real, "cheap albedo blend#for all screen space light without shader reference" },
		{ _field_explanation, "Lighting layer debug mode albedo override" },
		{ _field_real_rgb_color, "lighting layer albedo color#the floating point values are linear and what the shader will sample for albedo" },
		{ _field_tag_reference, "Hologram Camera FX", &global_camera_fx_settings_reference },
		{ _field_tag_reference, "Global load screen model", &global_loadscreen_reference },
		{ _field_real, "Global load screen gradient coordinate" },
		{ _field_tag_reference, "airprobe render model", &render_model_reference$8 },
		{ _field_terminator }
	};

	STRINGS(global_bitmap_flags)
	{
		"don\'t load bitmap by default"
	};
	STRING_LIST(global_bitmap_flags, global_bitmap_flags_strings, _countof(global_bitmap_flags_strings));

	TAG_REFERENCE(global_rasterizer_globals_reference, RASTERIZER_GLOBALS_TAG);

} // namespace blofeld

