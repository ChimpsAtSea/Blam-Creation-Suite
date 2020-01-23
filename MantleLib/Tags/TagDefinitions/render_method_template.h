#pragma once

struct nicename("Render Method Template") group('rmt2') s_render_method_template_definition
{
	struct s_unknown_block_definition;
	struct s_unknown2_block_definition;
	struct s_unknown3_block_definition;
	struct nicename("Arguments") s_argument_block_definition;
	struct s_unknown4_block_definition;
	struct s_unknown5_block_definition;
	struct nicename("Shader Maps") s_shader_map_block_definition;

	TagReference nicename("Vertex Shader") vertex_shader_reference; 
	TagReference nicename("Pixel Shader") pixel_shader_reference; 
	Unknown32 __unknown; 
	s_tag_block_definition<s_unknown_block_definition> __unknown2_block; 
	s_tag_block_definition<s_unknown2_block_definition> __unknown3_block; 
	s_tag_block_definition<s_unknown3_block_definition> __unknown4_block; 
	s_tag_block_definition<s_argument_block_definition> nicename("Arguments") arguments_block; 
	s_tag_block_definition<s_unknown4_block_definition> __unknown5_block; 
	s_tag_block_definition<s_unknown5_block_definition> __unknown6_block; 
	s_tag_block_definition<s_shader_map_block_definition> nicename("Shader Maps") shader_maps_block; 
	Unknown32 __unknown7; 
	Unknown32 __unknown8; 
	Unknown32 __unknown9; 

	struct s_unknown_block_definition
	{
		signed short __unknown; 
	};

	struct s_unknown2_block_definition
	{
		Unknown32 __unknown; 
		Unknown32 __unknown2; 
		Unknown32 __unknown3; 
		Unknown32 __unknown4; 
		Unknown32 __unknown5; 
		Unknown32 __unknown6; 
		Unknown32 __unknown7; 
		Unknown32 __unknown8; 
	};

	struct s_unknown3_block_definition
	{
		Unknown32 __unknown; 
	};

	struct nicename("argument") s_argument_block_definition
	{
		string_id nicename("Name") name; 
	};

	struct s_unknown4_block_definition
	{
		string_id __unknown; 
	};

	struct s_unknown5_block_definition
	{
		string_id __unknown; 
	};

	struct nicename("shader_map") s_shader_map_block_definition
	{
		string_id nicename("Name") name; 
	};
};
