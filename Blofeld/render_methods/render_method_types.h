#pragma once

namespace blofeld
{

	constexpr unsigned long SHADER_PARTICLE_TAG = 'rmp';

	extern s_tag_group shader_particle_group;
	constexpr unsigned long SHADER_CUSTOM_TAG = 'rmcs';

	extern s_tag_group shader_custom_group;
	constexpr unsigned long SHADER_CORTANA_TAG = 'rmct';

	extern s_tag_group shader_cortana_group;
	constexpr unsigned long SHADER_DECAL_TAG = 'rmd ';

	extern s_tag_group shader_decal_group;
	constexpr unsigned long SHADER_FOLIAGE_TAG = 'rmfl';

	extern s_tag_group shader_foliage_group;
	constexpr unsigned long SHADER_FUR_STENCIL_TAG = 'rmfs';

	extern s_tag_group shader_fur_stencil_group;
	constexpr unsigned long SHADER_FUR_TAG = 'rmfu';

	extern s_tag_group shader_fur_group;
	constexpr unsigned long SHADER_GLASS_TAG = 'rmgl';

	extern s_tag_group shader_glass_group;
	constexpr unsigned long SHADER_HALOGRAM_TAG = 'rmhg';

	extern s_tag_group shader_halogram_group;
	constexpr unsigned long SHADER_LIGHT_VOLUME_TAG = 'rmlv';

	extern s_tag_group shader_light_volume_group;
	constexpr unsigned long SHADER_MUX_MATERIAL_TAG = 'rmmm';

	extern s_tag_group shader_mux_material_group;
	constexpr unsigned long SHADER_MUX_TAG = 'rmmx';

	extern s_tag_group shader_mux_group;
	constexpr unsigned long SHADER_TAG = 'rmsh';

	extern s_tag_group shader_group;
	constexpr unsigned long SHADER_SKIN_TAG = 'rmsk';

	extern s_tag_group shader_skin_group;
	constexpr unsigned long SHADER_SCREEN_TAG = 'rmss';

	extern s_tag_group shader_screen_group;
	constexpr unsigned long SHADER_TERRAIN_TAG = 'rmtr';

	extern s_tag_group shader_terrain_group;
	constexpr unsigned long SHADER_WATER_TAG = 'rmw ';

	extern s_tag_group shader_water_group;
	constexpr unsigned long SHADER_WATERFALL_TAG = 'rmwf';

	extern s_tag_group shader_waterfall_group;

	extern s_tag_block_definition shader_particle_block_block;
	extern s_tag_block_definition shader_custom_block_block;
	extern s_tag_block_definition shader_cortana_block_block;
	extern s_tag_block_definition shader_decal_block_block;
	extern s_tag_block_definition shader_foliage_block_block;
	extern s_tag_block_definition shader_fur_stencil_block_block;
	extern s_tag_block_definition shader_fur_block_block;
	extern s_tag_block_definition shader_glass_block_block;
	extern s_tag_block_definition shader_halogram_block_block;
	extern s_tag_block_definition shader_light_volume_block_block;
	extern s_tag_block_definition shader_mux_material_block_block;
	extern s_tag_block_definition shader_mux_block_block;
	extern s_tag_block_definition shader_block_block;
	extern s_tag_block_definition shader_skin_block_block;
	extern s_tag_block_definition shader_screen_block_block;
	extern s_tag_block_definition shader_terrain_block_block;
	extern s_tag_block_definition shader_water_block_block;
	extern s_tag_block_definition shader_waterfall_block_block;

	extern s_tag_struct_definition shader_particle_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition material_type_struct_struct_definition;
	extern s_tag_struct_definition shader_custom_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition shader_cortana_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition shader_decal_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition shader_foliage_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition shader_fur_stencil_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition shader_fur_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition shader_glass_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition shader_halogram_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition shader_light_volume_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition shader_mux_material_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition shader_mux_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition shader_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition shader_skin_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition shader_screen_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition shader_terrain_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition shader_water_struct_definition_struct_definition; // tag group
	extern s_tag_struct_definition shader_waterfall_struct_definition_struct_definition; // tag group

	extern const char* global_screen_shader_render_layer_enum_strings[];
	extern s_string_list_definition global_screen_shader_render_layer_enum;
	extern const char* global_screen_shader_flags_definition_strings[];
	extern s_string_list_definition global_screen_shader_flags_definition;

} // namespace blofeld

