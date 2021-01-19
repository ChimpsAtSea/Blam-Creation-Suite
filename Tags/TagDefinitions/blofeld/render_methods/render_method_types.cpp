#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_particle, SHADER_PARTICLE_TAG, render_method, RENDER_METHOD_TAG, shader_particle_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_custom, SHADER_CUSTOM_TAG, render_method, RENDER_METHOD_TAG, shader_custom_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_cortana, SHADER_CORTANA_TAG, render_method, RENDER_METHOD_TAG, shader_cortana_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_decal, SHADER_DECAL_TAG, render_method, RENDER_METHOD_TAG, shader_decal_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_foliage, SHADER_FOLIAGE_TAG, render_method, RENDER_METHOD_TAG, shader_foliage_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_fur_stencil, SHADER_FUR_STENCIL_TAG, render_method, RENDER_METHOD_TAG, shader_fur_stencil_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_fur, SHADER_FUR_TAG, render_method, RENDER_METHOD_TAG, shader_fur_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_glass, SHADER_GLASS_TAG, render_method, RENDER_METHOD_TAG, shader_glass_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_halogram, SHADER_HALOGRAM_TAG, render_method, RENDER_METHOD_TAG, shader_halogram_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_light_volume, SHADER_LIGHT_VOLUME_TAG, render_method, RENDER_METHOD_TAG, shader_light_volume_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_mux_material, SHADER_MUX_MATERIAL_TAG, render_method, RENDER_METHOD_TAG, shader_mux_material_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_mux, SHADER_MUX_TAG, render_method, RENDER_METHOD_TAG, shader_mux_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader, SHADER_TAG, render_method, RENDER_METHOD_TAG, shader_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_skin, SHADER_SKIN_TAG, render_method, RENDER_METHOD_TAG, shader_skin_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_screen, SHADER_SCREEN_TAG, render_method, RENDER_METHOD_TAG, shader_screen_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_terrain, SHADER_TERRAIN_TAG, render_method, RENDER_METHOD_TAG, shader_terrain_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_water, SHADER_WATER_TAG, render_method, RENDER_METHOD_TAG, shader_water_block_block );

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_waterfall, SHADER_WATERFALL_TAG, render_method, RENDER_METHOD_TAG, shader_waterfall_block_block);

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_beam, SHADER_BEAM_TAG, render_method, RENDER_METHOD_TAG, shader_beam_block_block);

	V5_TAG_GROUP_INHERIT_FROM_BLOCK(shader_contrail, SHADER_CONTRAIL_TAG, render_method, RENDER_METHOD_TAG, shader_contrail_block_block);

	V5_TAG_BLOCK_FROM_STRUCT(shader_particle_block, 1, shader_particle_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(shader_custom_block, 1, shader_custom_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(shader_cortana_block, 1, shader_cortana_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(shader_decal_block, 1, shader_decal_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(shader_foliage_block, 1, shader_foliage_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(shader_fur_stencil_block, 1, shader_fur_stencil_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(shader_fur_block, 1, shader_fur_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(shader_glass_block, 1, shader_glass_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(shader_halogram_block, 1, shader_halogram_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(shader_light_volume_block, 1, shader_light_volume_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(shader_mux_material_block, 1, shader_mux_material_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(shader_mux_block, 1, shader_mux_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(shader_block, 1, shader_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(shader_skin_block, 1, shader_skin_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(shader_screen_block, 1, shader_screen_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(shader_terrain_block, 1, shader_terrain_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(shader_water_block, 1, shader_water_struct_definition_struct_definition );

	V5_TAG_BLOCK_FROM_STRUCT(shader_waterfall_block, 1, shader_waterfall_struct_definition_struct_definition);

	V5_TAG_BLOCK_FROM_STRUCT(shader_beam_block, 1, shader_beam_struct_definition_struct_definition);

	V5_TAG_BLOCK_FROM_STRUCT(shader_contrail_block, 1, shader_contrail_struct_definition_struct_definition);

	V5_TAG_STRUCT(shader_particle_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_real_rgb_color, "bright tint" },
		{ _field_real_rgb_color, "ambient tint" },
		{ _field_real, "contrast" },
		{ _field_real, "blur weight" },
		{ _field_real, "intensity scale" },
		{ _field_tag_reference, "palette", &global_bitmap_reference },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(material_type_struct)
	{
		{ _field_short_integer, "global material index" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_custom_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_cortana_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_decal_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_long_integer, "specular_modulate!" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_foliage_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_fur_stencil_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_fur_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_glass_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_halogram_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_light_volume_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_mux_material_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_mux_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_string_id, "material name 0#defines global material type for channel 0 of the mux shader" },
		{ _field_string_id, "material name 1#defines global material type for channel 1 of the mux shader" },
		{ _field_string_id, "material name 2#defines global material type for channel 2 of the mux shader" },
		{ _field_string_id, "material name 3#defines global material type for channel 3 of the mux shader" },
		{ _field_struct, "material type 0!", &material_type_struct_struct_definition },
		{ _field_struct, "material type 1!", &material_type_struct_struct_definition },
		{ _field_struct, "material type 2!", &material_type_struct_struct_definition },
		{ _field_struct, "material type 3!", &material_type_struct_struct_definition },
		{ _field_long_integer, "single material!" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_beam_struct_definition)
	{
		{ _field_struct, "render_method", & render_method_struct_definition_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_contrail_struct_definition)
	{
		{ _field_struct, "render_method", & render_method_struct_definition_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_skin_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_screen_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_char_enum, "render layer", &global_screen_shader_render_layer_enum },
		{ _field_char_integer, "sort order" },
		{ _field_byte_flags, "render flags", &global_screen_shader_flags_definition },
		{ _field_pad, "fefjjjfrjg", 1 },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_terrain_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_string_id, "material name 0#defines global material type for channel 0 of the terrain shader" },
		{ _field_string_id, "material name 1#defines global material type for channel 1 of the terrain shader" },
		{ _field_string_id, "material name 2#defines global material type for channel 2 of the terrain shader" },
		{ _field_string_id, "material name 3#defines global material type for channel 3 of the terrain shader" },
		{ _field_struct, "material type 0!", &material_type_struct_struct_definition },
		{ _field_struct, "material type 1!", &material_type_struct_struct_definition },
		{ _field_struct, "material type 2!", &material_type_struct_struct_definition },
		{ _field_struct, "material type 3!", &material_type_struct_struct_definition },
		{ _field_long_integer, "single material!" },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_water_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_terminator }
	};

	V5_TAG_STRUCT(shader_waterfall_struct_definition)
	{
		{ _field_struct, "render_method", &render_method_struct_definition_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	STRINGS(global_screen_shader_render_layer_enum)
	{
		"pre-UI",
		"post-UI",
		"pre-transparents"
	};
	STRING_LIST(global_screen_shader_render_layer_enum, global_screen_shader_render_layer_enum_strings, _countof(global_screen_shader_render_layer_enum_strings));

	STRINGS(global_screen_shader_flags_definition)
	{
		"resolve screen"
	};
	STRING_LIST(global_screen_shader_flags_definition, global_screen_shader_flags_definition_strings, _countof(global_screen_shader_flags_definition_strings));

} // namespace blofeld

