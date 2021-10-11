#include <tagdefinitions-private-pch.h>
#include <blofeld_field_type_override.h>

namespace blofeld
{



	TAG_GROUP(
		shader_particle_group,
		SHADER_PARTICLE_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_particle_block );

	TAG_GROUP(
		shader_custom_group,
		SHADER_CUSTOM_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_custom_block );

	TAG_GROUP(
		shader_cortana_group,
		SHADER_CORTANA_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_cortana_block );

	TAG_GROUP(
		shader_decal_group,
		SHADER_DECAL_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_decal_block );

	TAG_GROUP(
		shader_foliage_group,
		SHADER_FOLIAGE_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_foliage_block );

	TAG_GROUP(
		shader_fur_stencil_group,
		SHADER_FUR_STENCIL_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_fur_stencil_block );

	TAG_GROUP(
		shader_fur_group,
		SHADER_FUR_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_fur_block );

	TAG_GROUP(
		shader_glass_group,
		SHADER_GLASS_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_glass_block );

	TAG_GROUP(
		shader_halogram_group,
		SHADER_HALOGRAM_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_halogram_block );

	TAG_GROUP(
		shader_light_volume_group,
		SHADER_LIGHT_VOLUME_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_light_volume_block );

	TAG_GROUP(
		shader_mux_material_group,
		SHADER_MUX_MATERIAL_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_mux_material_block );

	TAG_GROUP(
		shader_mux_group,
		SHADER_MUX_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_mux_block );

	TAG_GROUP(
		shader_group,
		SHADER_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_block );

	TAG_GROUP(
		shader_skin_group,
		SHADER_SKIN_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_skin_block );

	TAG_GROUP(
		shader_screen_group,
		SHADER_SCREEN_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_screen_block );

	TAG_GROUP(
		shader_terrain_group,
		SHADER_TERRAIN_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_terrain_block );

	TAG_GROUP(
		shader_water_group,
		SHADER_WATER_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_water_block );

	TAG_GROUP(
		shader_waterfall_group,
		SHADER_WATERFALL_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_waterfall_block );

	TAG_GROUP(
		shader_beam_group,
		SHADER_BEAM_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_beam_block);

	TAG_GROUP(
		shader_contrail_group,
		SHADER_CONTRAIL_TAG,
		&render_method_group,
		RENDER_METHOD_TAG,
		shader_contrail_block);

	TAG_BLOCK_FROM_STRUCT(
		shader_particle_block,
		"shader_particle_block",
		1,
		shader_particle_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_custom_block,
		"shader_custom_block",
		1,
		shader_custom_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_cortana_block,
		"shader_cortana_block",
		1,
		shader_cortana_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_decal_block,
		"shader_decal_block",
		1,
		shader_decal_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_foliage_block,
		"shader_foliage_block",
		1,
		shader_foliage_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_fur_stencil_block,
		"shader_fur_stencil_block",
		1,
		shader_fur_stencil_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_fur_block,
		"shader_fur_block",
		1,
		shader_fur_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_glass_block,
		"shader_glass_block",
		1,
		shader_glass_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_halogram_block,
		"shader_halogram_block",
		1,
		shader_halogram_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_light_volume_block,
		"shader_light_volume_block",
		1,
		shader_light_volume_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_mux_material_block,
		"shader_mux_material_block",
		1,
		shader_mux_material_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_mux_block,
		"shader_mux_block",
		1,
		shader_mux_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_block,
		"shader_block",
		1,
		shader_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_skin_block,
		"shader_skin_block",
		1,
		shader_skin_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_screen_block,
		"shader_screen_block",
		1,
		shader_screen_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_terrain_block,
		"shader_terrain_block",
		1,
		shader_terrain_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_water_block,
		"shader_water_block",
		1,
		shader_water_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_waterfall_block,
		"shader_waterfall_block",
		1,
		shader_waterfall_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_beam_block,
		"shader_beam_block",
		1,
		shader_beam_struct_definition);

	TAG_BLOCK_FROM_STRUCT(
		shader_contrail_block,
		"shader_contrail_block",
		1,
		shader_contrail_struct_definition);

	#define SHADER_PARTICLE_STRUCT_DEFINITION_ID { 0x769BE1B8, 0x531C4049, 0x99594583, 0x24A08389 }
	TAG_STRUCT(
		shader_particle_struct_definition,
		"shader_particle_struct_definition",
		"c_render_method_shader_particle",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_PARTICLE_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_real_rgb_color, "bright tint" },
		{ _field_real_rgb_color, "ambient tint" },
		{ _field_real, "contrast" },
		{ _field_real, "blur weight" },
		{ _field_real, "intensity scale" },
		{ _field_tag_reference, "palette", &global_bitmap_reference },
		{ _field_terminator }
	};

	#define SHADER_CUSTOM_STRUCT_DEFINITION_ID { 0xFF50E364, 0xEB3245FF, 0xA2D4B69B, 0x8BE29BB4 }
	TAG_STRUCT(
		shader_custom_struct_definition,
		"shader_custom_struct_definition",
		"c_render_method_shader_custom",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_CUSTOM_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	#define SHADER_CORTANA_STRUCT_DEFINITION_ID { 0xC85B5D4E, 0xE9A04958, 0xB56578B1, 0xFD846D3B }
	TAG_STRUCT(
		shader_cortana_struct_definition,
		"shader_cortana_struct_definition",
		"c_render_method_shader_cortana",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_CORTANA_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	#define SHADER_DECAL_STRUCT_DEFINITION_ID { 0xEA087CA7, 0x6D4B455B, 0xA5D40D3C, 0xC2BD313A }
	TAG_STRUCT(
		shader_decal_struct_definition,
		"shader_decal_struct_definition",
		"c_render_method_shader_decal",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_DECAL_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_long_integer, "specular_modulate", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define SHADER_FOLIAGE_STRUCT_DEFINITION_ID { 0xD74BE733, 0x121C43AD, 0xBA9BDBAB, 0x5CFF186F }
	TAG_STRUCT(
		shader_foliage_struct_definition,
		"shader_foliage_struct_definition",
		"c_render_method_shader_foliage",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_FOLIAGE_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	#define SHADER_FUR_STENCIL_STRUCT_DEFINITION_ID { 0xF47BD72B, 0x75D24F56, 0x9CC91E04, 0xFBC6BACB }
	TAG_STRUCT(
		shader_fur_stencil_struct_definition,
		"shader_fur_stencil_struct_definition",
		"c_render_method_shader_fur_stencil",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_FUR_STENCIL_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	#define SHADER_FUR_STRUCT_DEFINITION_ID { 0xC56A78C9, 0xFF3043E4, 0xB4C1B2F6, 0xEF328DC5 }
	TAG_STRUCT(
		shader_fur_struct_definition,
		"shader_fur_struct_definition",
		"c_render_method_shader_fur",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_FUR_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	#define SHADER_GLASS_STRUCT_DEFINITION_ID { 0xE9C581E2, 0xDBD14B5C, 0x882C68D3, 0x3C8585F9 }
	TAG_STRUCT(
		shader_glass_struct_definition,
		"shader_glass_struct_definition",
		"c_render_method_shader_glass",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_GLASS_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	#define SHADER_HALOGRAM_STRUCT_DEFINITION_ID { 0xC9823BF8, 0x33A44F28, 0x8307126E, 0xD5E0FA05 }
	TAG_STRUCT(
		shader_halogram_struct_definition,
		"shader_halogram_struct_definition",
		"c_render_method_shader_halogram",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_HALOGRAM_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	#define SHADER_LIGHT_VOLUME_STRUCT_DEFINITION_ID { 0x0EBF63AF, 0x426B4679, 0x93E4F59B, 0x93BC0FF2 }
	TAG_STRUCT(
		shader_light_volume_struct_definition,
		"shader_light_volume_struct_definition",
		"c_render_method_shader_light_volume",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_LIGHT_VOLUME_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_terminator }
	};

	#define SHADER_MUX_MATERIAL_STRUCT_DEFINITION_ID { 0x4DCB92A7, 0xE2D240D7, 0xA32E660E, 0x3C65D06D }
	TAG_STRUCT(
		shader_mux_material_struct_definition,
		"shader_mux_material_struct_definition",
		"c_render_method_shader_mux_material",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_MUX_MATERIAL_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	#define SHADER_MUX_STRUCT_DEFINITION_ID { 0x6A37ED2F, 0xA0984874, 0x9E320D9F, 0x88A14069 }
	TAG_STRUCT(
		shader_mux_struct_definition,
		"shader_mux_struct_definition",
		"c_render_method_shader_mux",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_MUX_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_string_id, "material name 0", "defines global material type for channel 0 of the mux shader" },
		{ _field_string_id, "material name 1", "defines global material type for channel 1 of the mux shader" },
		{ _field_string_id, "material name 2", "defines global material type for channel 2 of the mux shader" },
		{ _field_string_id, "material name 3", "defines global material type for channel 3 of the mux shader" },
		{ _field_struct, "material type 0", FIELD_FLAG_UNKNOWN0, &material_type_struct },
		{ _field_struct, "material type 1", FIELD_FLAG_UNKNOWN0, &material_type_struct },
		{ _field_struct, "material type 2", FIELD_FLAG_UNKNOWN0, &material_type_struct },
		{ _field_struct, "material type 3", FIELD_FLAG_UNKNOWN0, &material_type_struct },
		{ _field_long_integer, "single material", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define SHADER_STRUCT_DEFINITION_ID { 0x03AC664D, 0xEFE440D5, 0x90BB753B, 0xDD1C8632 }
	TAG_STRUCT(
		shader_struct_definition,
		"shader_struct_definition",
		"c_render_method_shader",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	#define SHADER_SKIN_STRUCT_DEFINITION_ID { 0xC5B8AAB4, 0x932348D9, 0x8333AD6E, 0x6B1DE570 }
	TAG_STRUCT(
		shader_skin_struct_definition,
		"shader_skin_struct_definition",
		"c_render_method_shader_skin",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_SKIN_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	#define SHADER_SCREEN_STRUCT_DEFINITION_ID { 0x1BCC3B9D, 0xE4A94D01, 0x86E2B7F9, 0x483A58FA }
	TAG_STRUCT(
		shader_screen_struct_definition,
		"shader_screen_struct_definition",
		"c_render_method_shader_screen",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_SCREEN_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_char_enum, "render layer", &global_screen_shader_render_layer_enum },
		{ _field_char_integer, "sort order" },
		{ _field_byte_flags, "render flags", &global_screen_shader_flags_definition },
		FIELD_PAD_EX("fefjjjfrjg", nullptr, FIELD_FLAG_NONE, 1),
		{ _field_terminator }
	};

	#define SHADER_TERRAIN_STRUCT_DEFINITION_ID { 0xA5E23FFC, 0x86CF4F04, 0x8F9BB910, 0xEC559C56 }
	TAG_STRUCT(
		shader_terrain_struct_definition,
		"shader_terrain_struct_definition",
		"c_render_method_shader_terrain",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_TERRAIN_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_string_id, "material name 0", "defines global material type for channel 0 of the terrain shader" },
		{ _field_string_id, "material name 1", "defines global material type for channel 1 of the terrain shader" },
		{ _field_string_id, "material name 2", "defines global material type for channel 2 of the terrain shader" },
		{ _field_string_id, "material name 3", "defines global material type for channel 3 of the terrain shader" },
		{ _field_struct, "material type 0", FIELD_FLAG_UNKNOWN0, &material_type_struct },
		{ _field_struct, "material type 1", FIELD_FLAG_UNKNOWN0, &material_type_struct },
		{ _field_struct, "material type 2", FIELD_FLAG_UNKNOWN0, &material_type_struct },
		{ _field_struct, "material type 3", FIELD_FLAG_UNKNOWN0, &material_type_struct },
		{ _field_long_integer, "single material", FIELD_FLAG_UNKNOWN0 },
		{ _field_terminator }
	};

	#define SHADER_WATER_STRUCT_DEFINITION_ID { 0x690CD756, 0x20E34F49, 0xA35E9CD9, 0x594C0FA2 }
	TAG_STRUCT(
		shader_water_struct_definition,
		"shader_water_struct_definition",
		"c_render_method_shader_water",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_WATER_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_terminator }
	};

	#define SHADER_WATERFALL_STRUCT_DEFINITION_ID { 0x45F99AEF, 0x8E60424D, 0xB086F8EF, 0xFD087593 }
	TAG_STRUCT(
		shader_waterfall_struct_definition,
		"shader_waterfall_struct_definition",
		"c_render_method_shader_waterfall",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_WATERFALL_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	#define SHADER_BEAM_STRUCT_DEFINITION_ID { 0x0AA9E60E, 0x889D05DC, 0x10B6D4F1, 0x1F9BF9C1 } // #CUSTOM
	TAG_STRUCT(
		shader_beam_struct_definition,
		"shader_beam_struct_definition",
		"c_render_method_shader_beam",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_BEAM_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	#define SHADER_CONTRAIL_STRUCT_DEFINITION_ID { 0x8D883730, 0x857C74CC, 0x3D15ECBA, 0xFDCC82D7 } // #CUSTOM
	TAG_STRUCT(
		shader_contrail_struct_definition,
		"shader_contrail_struct_definition",
		"c_render_method_shader_contrail",
		SET_UNKNOWN0 | SET_UNKNOWN1 | SET_HAS_INLINED_CHILDREN_WITH_PLACEMENT_NEW | SET_UNKNOWN5 | SET_UNKNOWN7 | 
		SET_DELETE_RECURSIVELY | SET_POSTPROCESS_RECURSIVELY | SET_UNKNOWN15 | SET_HAS_LEVEL_SPECIFIC_FIELDS | 
		SET_UNKNOWN18,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_NODE, TAG_MEMORY_USAGE_READ_ONLY),
		SHADER_CONTRAIL_STRUCT_DEFINITION_ID)
	{
		{ _field_struct, "render_method", &render_method_struct_definition },
		{ _field_string_id, "material name" },
		{ _field_terminator }
	};

	#define MATERIAL_TYPE_STRUCT_ID { 0xFDEBAF30, 0x1AB34195, 0xA37ECE6C, 0xE4A2D97E }
	TAG_STRUCT(
		material_type_struct,
		"material_type_struct",
		"c_global_material_type",
		SET_IS_MEMCPYABLE | SET_CAN_MEMSET_TO_INITIALIZE,
		TAG_MEMORY_ATTRIBUTES(MEMORY_ALLOCATION_DEFAULT, TAG_MEMORY_USAGE_READ_ONLY),
		MATERIAL_TYPE_STRUCT_ID)
	{
		{ _field_short_integer, "global material index" },
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

