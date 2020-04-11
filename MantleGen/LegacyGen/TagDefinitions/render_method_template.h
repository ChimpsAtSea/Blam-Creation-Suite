#pragma once

struct nicename("render_method_template") tag_group('rmt2') s_render_method_template_definition_legacy
{
	struct nicename("Unknown") s_unknown_definition_legacy
	{
		int16_t __unknown0;
	};

	struct nicename("Unknown") s_unknown1_definition_legacy
	{
		s_undefined32_legacy __unknown0;
		s_undefined32_legacy __unknown1;
		s_undefined32_legacy __unknown2;
		s_undefined32_legacy __unknown3;
		s_undefined32_legacy __unknown4;
		s_undefined32_legacy __unknown5;
		s_undefined32_legacy __unknown6;
		s_undefined32_legacy __unknown7;
	};

	struct nicename("Unknown") s_unknown2_definition_legacy
	{
		s_undefined32_legacy __unknown0;
	};

	struct nicename("Arguments") s_arguments_definition_legacy
	{
		string_id_legacy nicename("Name") name;
	};

	struct nicename("Unknown") s_unknown3_definition_legacy
	{
		string_id_legacy __unknown0;
	};

	struct nicename("Unknown") s_unknown4_definition_legacy
	{
		string_id_legacy __unknown0;
	};

	struct nicename("Shader Maps") s_shader_maps_definition_legacy
	{
		string_id_legacy nicename("Name") name;
	};

	s_tag_reference_legacy nicename("Vertex Shader") vertex_shader_reference;
	s_tag_reference_legacy nicename("Pixel Shader") pixel_shader_reference;
	s_undefined32_legacy __unknown0;
	s_tag_block_legacy<s_unknown_definition_legacy> __unknown1;
	s_tag_block_legacy<s_unknown1_definition_legacy> __unknown2;
	s_tag_block_legacy<s_unknown2_definition_legacy> __unknown3;
	s_tag_block_legacy<s_arguments_definition_legacy> nicename("Arguments") arguments_block;
	s_tag_block_legacy<s_unknown3_definition_legacy> __unknown4;
	s_tag_block_legacy<s_unknown4_definition_legacy> __unknown5;
	s_tag_block_legacy<s_shader_maps_definition_legacy> nicename("Shader Maps") shader_maps_block;
	s_undefined32_legacy __unknown6;
	s_undefined32_legacy __unknown7;
	s_undefined32_legacy __unknown8;
};

