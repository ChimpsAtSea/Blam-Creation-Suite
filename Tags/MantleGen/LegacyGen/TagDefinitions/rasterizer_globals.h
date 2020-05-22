#pragma once

struct nicename("rasterizer_globals") tag_group('rasg') s_rasterizer_globals_definition_legacy
{
	struct nicename("Default Bitmaps") s_default_bitmaps_definition_legacy
	{
		int32_t __unknown0;
		s_tag_reference_legacy nicename("Bitmap") bitmap_reference;
	};

	struct nicename("Default Rasterizer Bitmaps") s_default_rasterizer_bitmaps_definition_legacy
	{
		s_tag_reference_legacy nicename("Bitmap") bitmap_reference;
	};

	struct nicename("Default Shaders") s_default_shaders_definition_legacy
	{
		string_id_legacy nicename("Name") name;
		s_tag_reference_legacy nicename("Vertex Shader") vertex_shader_reference;
		s_tag_reference_legacy nicename("Pixel Shader") pixel_shader_reference;
		s_tag_reference_legacy nicename("Compute Shader") compute_shader_reference;
	};

	s_tag_block_legacy<s_default_bitmaps_definition_legacy> nicename("Default Bitmaps") default_bitmaps_block;
	s_tag_block_legacy<s_default_rasterizer_bitmaps_definition_legacy> nicename("Default Rasterizer Bitmaps") default_rasterizer_bitmaps_block;
	s_tag_reference_legacy nicename("Vertex Shader Simple") vertex_shader_simple_reference;
	s_tag_reference_legacy nicename("Pixel Shader Simple") pixel_shader_simple_reference;
	s_tag_block_legacy<s_default_shaders_definition_legacy> nicename("Default Shaders") default_shaders_block;
	s_undefined32_legacy __unknown0;
	s_undefined32_legacy __unknown1;
	s_undefined32_legacy __unknown2;
	s_undefined32_legacy __unknown3;
	s_undefined32_legacy __unknown4;
	s_tag_reference_legacy nicename("Default Performance Template") default_performance_template_reference;
	s_tag_reference_legacy nicename("Default Shield Impact") default_shield_impact_reference;
	s_tag_reference_legacy nicename("Particle Library") particle_library_reference;
	s_tag_reference_legacy nicename("Emblem Library") emblem_library_reference;
	s_undefined32_legacy __unknown5;
	s_undefined32_legacy __unknown6;
	s_undefined32_legacy __unknown7;
	s_undefined32_legacy __unknown8;
	s_undefined32_legacy __unknown9;
	s_undefined32_legacy __unknown10;
};

