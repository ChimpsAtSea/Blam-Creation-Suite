#include "tagcodegen-private-pch.h"

const char* c_console::g_console_executable_name = "TagCodegen";

int create_source_file()
{
	c_structure_relationship_node::create_structure_relationships();
	c_structure_relationship_node::create_sorted_tag_struct_definitions();

	int result = 0;

	std::pair<e_engine_type, e_platform_type> const engine_and_platform_types[] =
	{
		{_engine_type_halo1,				_platform_type_pc },
		{_engine_type_halo2,				_platform_type_pc },
		{_engine_type_halo3,				_platform_type_pc },
		{_engine_type_halo3odst,			_platform_type_pc },
		{_engine_type_haloreach,			_platform_type_pc },
		{_engine_type_halo4,				_platform_type_pc },
		{_engine_type_groundhog,			_platform_type_pc },
		{_engine_type_gen3_xbox360,			_platform_type_xbox_360 },
	};

	tbb::task_group g;
	for (std::pair<e_engine_type, e_platform_type> engine_and_platform_type : engine_and_platform_types)
	{
		g.run([&result, engine_and_platform_type]
			{
				c_tag_source_generator tag_source_generator(engine_and_platform_type.first, engine_and_platform_type.second, _build_not_set);
				tag_source_generator.generate_source();
				if (tag_source_generator.has_error) result++;
			});

		g.run([&result, engine_and_platform_type]
			{
				c_virtual_tag_source_generator virtual_tag_source_generator(engine_and_platform_type.first, engine_and_platform_type.second, _build_not_set);
				virtual_tag_source_generator.generate_header();
				virtual_tag_source_generator.generate_source();
			});
	}
	g.wait();

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
