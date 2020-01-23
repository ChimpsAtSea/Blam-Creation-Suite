#pragma once

struct nicename("Rasterizer Globals") group('rasg') s_rasterizer_globals_definition
{
	struct nicename("Default Bitmaps") s_default_bitmap_block_definition;
	struct nicename("Default Rasterizer Bitmaps") s_default_rasterizer_bitmap_block_definition;
	struct nicename("Default Shaders") s_default_shader_block_definition;

	s_tag_block_definition<s_default_bitmap_block_definition> nicename("Default Bitmaps") default_bitmaps_block; 
	s_tag_block_definition<s_default_rasterizer_bitmap_block_definition> nicename("Default Rasterizer Bitmaps") default_rasterizer_bitmaps_block; 
	TagReference nicename("Vertex Shader Simple") vertex_shader_simple_reference; 
	TagReference nicename("Pixel Shader Simple") pixel_shader_simple_reference; 
	s_tag_block_definition<s_default_shader_block_definition> nicename("Default Shaders") default_shaders_block; 
	Undefined32 __unknown; 
	Undefined32 __unknown2; 
	Undefined32 __unknown3; 
	Undefined32 __unknown4; 
	Undefined32 __unknown5; 
	TagReference nicename("Default Performance Template") default_performance_template_reference; 
	TagReference nicename("Default Shield Impact") default_shield_impact_reference; 
	TagReference nicename("Particle Library") particle_library_reference; 
	TagReference nicename("Emblem Library") emblem_library_reference; 
	Undefined32 __unknown6; 
	Undefined32 __unknown7; 
	Undefined32 __unknown8; 
	Undefined32 __unknown9; 
	Undefined32 __unknown10; 
	Undefined32 __unknown11; 

	struct nicename("default_bitmap") s_default_bitmap_block_definition
	{
		int32_t __unknown; 
		TagReference nicename("Bitmap") bitmap_reference; 
	};

	struct nicename("default_rasterizer_bitmap") s_default_rasterizer_bitmap_block_definition
	{
		TagReference nicename("Bitmap") bitmap_reference; 
	};

	struct nicename("default_shader") s_default_shader_block_definition
	{
		string_id nicename("Name") name; 
		TagReference nicename("Vertex Shader") vertex_shader_reference; 
		TagReference nicename("Pixel Shader") pixel_shader_reference; 
		TagReference nicename("Compute Shader") compute_shader_reference; 
	};
};
