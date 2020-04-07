#pragma once

struct nicename("render_method_template") tag_group('rmt2') s_render_method_template_definition
{
	struct nicename("Unknown") s_unknown_definition
	{
		int16_t __unknown0;
	};

	struct nicename("Unknown") s_unknown1_definition
	{
		Undefined32 __unknown0;
		Undefined32 __unknown1;
		Undefined32 __unknown2;
		Undefined32 __unknown3;
		Undefined32 __unknown4;
		Undefined32 __unknown5;
		Undefined32 __unknown6;
		Undefined32 __unknown7;
	};

	struct nicename("Unknown") s_unknown2_definition
	{
		Undefined32 __unknown0;
	};

	struct nicename("Arguments") s_arguments_definition
	{
		string_id nicename("Name") name;
	};

	struct nicename("Unknown") s_unknown3_definition
	{
		string_id __unknown0;
	};

	struct nicename("Unknown") s_unknown4_definition
	{
		string_id __unknown0;
	};

	struct nicename("Shader Maps") s_shader_maps_definition
	{
		string_id nicename("Name") name;
	};

	TagReference nicename("Vertex Shader") vertex_shader_reference;
	TagReference nicename("Pixel Shader") pixel_shader_reference;
	Undefined32 __unknown0;
	s_tag_block_definition<s_unknown_definition> __unknown1;
	s_tag_block_definition<s_unknown1_definition> __unknown2;
	s_tag_block_definition<s_unknown2_definition> __unknown3;
	s_tag_block_definition<s_arguments_definition> nicename("Arguments") arguments_block;
	s_tag_block_definition<s_unknown3_definition> __unknown4;
	s_tag_block_definition<s_unknown4_definition> __unknown5;
	s_tag_block_definition<s_shader_maps_definition> nicename("Shader Maps") shader_maps_block;
	Undefined32 __unknown6;
	Undefined32 __unknown7;
	Undefined32 __unknown8;
};

