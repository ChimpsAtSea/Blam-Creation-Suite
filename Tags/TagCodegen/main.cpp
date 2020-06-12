#include "tagcodegen-private-pch.h"

const char* c_console::g_console_executable_name = "TagCodegen";

void create_source_file()
{
	c_structure_relationship_node::create_structure_relationships();
	c_structure_relationship_node::create_sorted_tag_struct_definitions();

	{
		c_tag_source_generator tag_source_generator(_engine_type_haloreach, _build_not_set);
		tag_source_generator.generate_source();

		c_virtual_tag_source_generator virtual_tag_source_generator(_engine_type_haloreach, _build_not_set);
		virtual_tag_source_generator.generate_header();
		virtual_tag_source_generator.generate_source();
	}
	{
		c_tag_source_generator tag_source_generator(_engine_type_halo3, _build_not_set);
		tag_source_generator.generate_source();

		c_virtual_tag_source_generator virtual_tag_source_generator(_engine_type_halo3, _build_not_set);
		virtual_tag_source_generator.generate_header();
		virtual_tag_source_generator.generate_source();
	}
	{
		c_tag_source_generator tag_source_generator(_engine_type_halo4, _build_not_set);
		tag_source_generator.generate_source();

		c_virtual_tag_source_generator virtual_tag_source_generator(_engine_type_halo4, _build_not_set);
		virtual_tag_source_generator.generate_header();
		virtual_tag_source_generator.generate_source();
	}
}

int wmain(int argc, const wchar_t** argv)
{
	if (!c_command_line::has_command_line_arg("-output"))
	{
		return 1;
	}

	create_source_file();

	int result = 0;

	return result;
}
