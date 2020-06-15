#include "tagcodegen-private-pch.h"

const char* c_console::g_console_executable_name = "TagCodegen";

int create_source_file()
{
	c_structure_relationship_node::create_structure_relationships();
	c_structure_relationship_node::create_sorted_tag_struct_definitions();

	int result = 0;

	tbb::parallel_invoke(
		[&result]()
		{
			c_tag_source_generator tag_source_generator(_engine_type_haloreach, _build_not_set);
			tag_source_generator.generate_source();
			if (tag_source_generator.has_error) result++;
		},
		[&result]()
		{
			c_tag_source_generator tag_source_generator(_engine_type_halo3, _build_not_set);
			tag_source_generator.generate_source();
			if (tag_source_generator.has_error) result++;
		},
		[&result]()
		{
			c_tag_source_generator tag_source_generator(_engine_type_halo4, _build_not_set);
			tag_source_generator.generate_source();
			if (tag_source_generator.has_error) result++;
		},
		[&result]()
		{
			c_virtual_tag_source_generator virtual_tag_source_generator(_engine_type_haloreach, _build_not_set);
			virtual_tag_source_generator.generate_header();
			virtual_tag_source_generator.generate_source();
		},
		[&result]()
		{
			c_virtual_tag_source_generator virtual_tag_source_generator(_engine_type_halo3, _build_not_set);
			virtual_tag_source_generator.generate_header();
			virtual_tag_source_generator.generate_source();
		},
		[&result]()
		{
			c_virtual_tag_source_generator virtual_tag_source_generator(_engine_type_halo4, _build_not_set);
			virtual_tag_source_generator.generate_header();
			virtual_tag_source_generator.generate_source();
		});

	return result;
}

int wmain(int argc, const wchar_t** argv)
{
	if (!c_command_line::has_command_line_arg("-output"))
	{
		return 1;
	}

	int result = create_source_file();

	return result;
}
