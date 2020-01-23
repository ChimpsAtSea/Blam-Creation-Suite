#pragma once

struct s_rasterizer_globals_definition
{
	struct s_default_bitmap_block_definition;
	struct s_default_rasterizer_bitmap_block_definition;
	struct s_default_shader_block_definition;

	s_tag_block_definition<s_default_bitmap_block_definition> default_bitmaps;
	s_tag_block_definition<s_default_rasterizer_bitmap_block_definition> default_rasterizer_bitmaps;
	TagReference vertex_shader_simple;
	TagReference pixel_shader_simple;
	s_tag_block_definition<s_default_shader_block_definition> default_shaders;
	unsigned int unknown;
	unsigned int unknown2;
	unsigned int unknown3;
	unsigned int unknown4;
	unsigned int unknown5;
	TagReference default_performance_template;
	TagReference default_shield_impact;
	TagReference particle_library;
	TagReference emblem_library;
	unsigned int unknown6;
	unsigned int unknown7;
	unsigned int unknown8;
	unsigned int unknown9;
	unsigned int unknown10;
	unsigned int unknown11;

	struct s_default_bitmap_definition
	{
		signed int unknown;
		TagReference bitmap;
	};

	struct s_default_rasterizer_bitmap_definition
	{
		TagReference bitmap;
	};

	struct s_default_shader_definition
	{
		string_id name;
		TagReference vertex_shader;
		TagReference pixel_shader;
		TagReference compute_shader;
	};
};
