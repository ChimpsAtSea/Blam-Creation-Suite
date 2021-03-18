#include "tagcodegen-private-pch.h"

const char* c_console::g_console_executable_name = "TagCodegen";

int create_source_file()
{
	c_structure_relationship_node::create_structure_relationships();
	c_structure_relationship_node::create_sorted_tag_struct_definitions();
	c_structure_relationship_node::create_sorted_tag_enum_definitions();
	c_structure_relationship_node::create_sorted_tag_block_definitions();
	
	int result = 0;

	s_engine_platform_build const engine_and_platform_types[] =
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

	c_console::write_line_verbose("Generating tag code");
	c_stopwatch stopwatch;
	stopwatch.start();

	tbb::task_group g;
	for (s_engine_platform_build engine_platform_build : engine_and_platform_types)
	{
		
		const char* engine_name;
		ASSERT(BCS_SUCCEEDED(get_engine_type_pretty_string(engine_platform_build.engine_type, &engine_name)));

		g.run([&result, engine_name, engine_platform_build]
			{
				c_stopwatch stopwatch;
				stopwatch.start();
				c_low_level_tag_source_generator low_level_tag_source_generator(engine_platform_build);
				c_console::write_line_verbose("Generating low level header (%s)", engine_name);
				low_level_tag_source_generator.generate_header();
				low_level_tag_source_generator.generate_source();
				low_level_tag_source_generator.generate_enum_header();
				stopwatch.stop();
				c_console::write_line_verbose("Finished generating low level header (%s) %.2fms", engine_name, stopwatch.get_miliseconds());
				if (low_level_tag_source_generator.has_error)
				{
					throw;
				}
			});

		g.run([&result, engine_name, engine_platform_build]
			{
				c_stopwatch stopwatch;
				stopwatch.start();
				c_virtual_tag_source_generator virtual_tag_source_generator(engine_platform_build);
				c_console::write_line_verbose("Generating virtual level header (%s)", engine_name);
				virtual_tag_source_generator.generate_header();
				stopwatch.stop();
				c_console::write_line_verbose("Finished generating virtual level header (%s) %.2fms", engine_name, stopwatch.get_miliseconds());
			});

		g.run([&result, engine_name, engine_platform_build]
			{
				c_stopwatch stopwatch;
				stopwatch.start();
				c_virtual_tag_source_generator virtual_tag_source_generator(engine_platform_build);
				c_console::write_line_verbose("Generating high virtual source (%s)", engine_name);
				virtual_tag_source_generator.generate_source();
				stopwatch.stop();
				c_console::write_line_verbose("Finished generating virtual level source (%s) %.2fms", engine_name, stopwatch.get_miliseconds());
			});

		g.run([&result, engine_name, engine_platform_build]
			{
				c_stopwatch stopwatch;
				stopwatch.start();
				c_high_level_tag_source_generator high_level_tag_source_generator(engine_platform_build);
				c_console::write_line_verbose("Generating high level header (%s)", engine_name);
				high_level_tag_source_generator.generate_header();
				stopwatch.stop();
				c_console::write_line_verbose("Finished generating high level header (%s) %.2fms", engine_name, stopwatch.get_miliseconds());
			});

		static constexpr uint32_t source_count = 64;
		for (uint32_t source_index = 0; source_index < source_count; source_index++)
		{
			g.run([&result, engine_name, engine_platform_build, source_index]
				{
					c_stopwatch stopwatch;
					stopwatch.start();
					c_high_level_tag_source_generator high_level_tag_source_generator(engine_platform_build);
					c_console::write_line_verbose("Generating high level source ctor:%u (%s)", source_index, engine_name);
					high_level_tag_source_generator.generate_ctor_source(source_index, source_count);
					stopwatch.stop();
					c_console::write_line_verbose("Finished generating high level source ctor:%u (%s) %.2fms", source_index, engine_name, stopwatch.get_miliseconds());
				});
		}

		g.run([&result, engine_name, engine_platform_build]
			{
				c_stopwatch stopwatch;
				stopwatch.start();
				c_high_level_tag_source_generator high_level_tag_source_generator(engine_platform_build);
				c_console::write_line_verbose("Generating high level source virtual functions (%s)", engine_name);
				high_level_tag_source_generator.generate_source_virtual();
				stopwatch.stop();
				c_console::write_line_verbose("Finished generating high level source virtual functions (%s) %.2fms", engine_name, stopwatch.get_miliseconds());
			});

		g.run([&result, engine_name, engine_platform_build]
			{
				c_stopwatch stopwatch;
				stopwatch.start();
				c_high_level_tag_source_generator high_level_tag_source_generator(engine_platform_build);
				c_console::write_line_verbose("Generating high level source misc (%s)", engine_name);
				high_level_tag_source_generator.generate_source_misc();
				stopwatch.stop();
				c_console::write_line_verbose("Finished generating high level source misc (%s) %.2fms", engine_name, stopwatch.get_miliseconds());
			});
	}
	g.wait();

	stopwatch.stop();
	c_console::write_line_verbose("Finished generating tag code %.2fms", stopwatch.get_miliseconds());

	return result;
}

#include <SymbolsLib\symbolslib-public-pch.h>

int wmain(int argc, const wchar_t** argv)
{
	blofeld::achievements_block_block;

	
	




	if (!c_command_line::has_command_line_arg("-output"))
	{
		return 1;
	}

	int result = create_source_file();

	return result;
}
