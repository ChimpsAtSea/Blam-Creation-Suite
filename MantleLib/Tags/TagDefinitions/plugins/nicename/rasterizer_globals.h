#pragma once

nicename("rasterizer_globals") struct s_rasterizer_globals_definition
{
	nicename("Default Bitmaps") struct s_default_bitmap_block_definition;
	nicename("Default Rasterizer Bitmaps") struct s_default_rasterizer_bitmap_block_definition;
	nicename("Default Shaders") struct s_default_shader_block_definition;

	nicename("Default Bitmaps") s_tag_block_definition<s_default_bitmap_block_definition> default_bitmaps;
	nicename("Default Rasterizer Bitmaps") s_tag_block_definition<s_default_rasterizer_bitmap_block_definition> default_rasterizer_bitmaps;
	nicename("Vertex Shader Simple") TagReference vertex_shader_simple;
	nicename("Pixel Shader Simple") TagReference pixel_shader_simple;
	nicename("Default Shaders") s_tag_block_definition<s_default_shader_block_definition> default_shaders;
	nicename("Unknown") unsigned int unknown;
	nicename("Unknown") unsigned int unknown2;
	nicename("Unknown") unsigned int unknown3;
	nicename("Unknown") unsigned int unknown4;
	nicename("Unknown") unsigned int unknown5;
	nicename("Default Performance Template") TagReference default_performance_template;
	nicename("Default Shield Impact") TagReference default_shield_impact;
	nicename("Particle Library") TagReference particle_library;
	nicename("Emblem Library") TagReference emblem_library;
	nicename("Unknown") unsigned int unknown6;
	nicename("Unknown") unsigned int unknown7;
	nicename("Unknown") unsigned int unknown8;
	nicename("Unknown") unsigned int unknown9;
	nicename("Unknown") unsigned int unknown10;
	nicename("Unknown") unsigned int unknown11;

	nicename("Default Bitmap") struct s_default_bitmap_definition
	{
		nicename("Unknown") signed int unknown;
		nicename("Bitmap") TagReference bitmap;
	};

	nicename("Default Rasterizer Bitmap") struct s_default_rasterizer_bitmap_definition
	{
		nicename("Bitmap") TagReference bitmap;
	};

	nicename("Default Shader") struct s_default_shader_definition
	{
		nicename("Name") string_id name;
		nicename("Vertex Shader") TagReference vertex_shader;
		nicename("Pixel Shader") TagReference pixel_shader;
		nicename("Compute Shader") TagReference compute_shader;
	};
};
