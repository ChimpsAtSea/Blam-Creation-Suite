#include "tagcodegen-private-pch.h"
#include <SymbolsLib\symbolslib-public-pch.h>

#ifndef k_ctor_source_count
static unsigned long k_ctor_source_count = 64;
#endif

BCS_RESULT create_low_level(s_engine_platform_build engine_platform_build)
{
	try
	{
		const char* engine_name;
		ASSERT(BCS_SUCCEEDED(get_engine_type_pretty_string(engine_platform_build.engine_type, engine_name)));

		c_stopwatch stopwatch;
		stopwatch.start();
		c_low_level_tag_source_generator low_level_tag_source_generator(engine_platform_build);
		if (BCS_SUCCEEDED(command_line_has_argument("verbose")))
		{
			console_write_line("Generating low level header (%s)", engine_name);
		}
		low_level_tag_source_generator.generate_header();
		low_level_tag_source_generator.generate_ida_header();
		low_level_tag_source_generator.generate_source();
		low_level_tag_source_generator.generate_enum_header();
		stopwatch.stop();
		if (BCS_SUCCEEDED(command_line_has_argument("verbose")))
		{
			console_write_line("Finished generating low level header (%s) %.2fms", engine_name, stopwatch.get_miliseconds());
		}
		if (low_level_tag_source_generator.has_error)
		{
			debug_break;
			throw;
		}

		return BCS_S_OK;
	}
	catch (BCS_RESULT error_result)
	{
		debug_break;
		return error_result;
	}
	catch (...)
	{
		debug_break;
		return BCS_E_FAIL;
	}
}

BCS_RESULT create_high_level(s_engine_platform_build engine_platform_build)
{
	try
	{
		const char* engine_name;
		ASSERT(BCS_SUCCEEDED(get_engine_type_pretty_string(engine_platform_build.engine_type, engine_name)));

		c_stopwatch stopwatch;
		stopwatch.start();
		c_high_level_tag_source_generator high_level_tag_source_generator(engine_platform_build);
		if (BCS_SUCCEEDED(command_line_has_argument("verbose")))
		{
			console_write_line("Finished generating high level header (%s) %.2fms", engine_name, stopwatch.get_miliseconds());
		}
		console_write_line("Generating high level header (%s)", engine_name);
		high_level_tag_source_generator.generate_header();
		stopwatch.stop();
		if (BCS_SUCCEEDED(command_line_has_argument("verbose")))
		{
			console_write_line("Finished generating high level header (%s) %.2fms", engine_name, stopwatch.get_miliseconds());
		}

		return BCS_S_OK;
	}
	catch (BCS_RESULT error_result)
	{
		debug_break;
		return error_result;
	}
	catch (...)
	{
		debug_break;
		return BCS_E_FAIL;
	}
}

BCS_RESULT create_high_level_ctor(s_engine_platform_build engine_platform_build, unsigned long source_index)
{
	try
	{
		const char* engine_name;
		ASSERT(BCS_SUCCEEDED(get_engine_type_pretty_string(engine_platform_build.engine_type, engine_name)));

		c_stopwatch stopwatch;
		stopwatch.start();
		c_high_level_tag_source_generator high_level_tag_source_generator(engine_platform_build);
		if (BCS_SUCCEEDED(command_line_has_argument("verbose")))
		{
			console_write_line("Generating high level source ctor:%u (%s)", source_index, engine_name);
		}
		high_level_tag_source_generator.generate_ctor_source(source_index, k_ctor_source_count);
		stopwatch.stop();
		if (BCS_SUCCEEDED(command_line_has_argument("verbose")))
		{
			console_write_line("Finished generating high level source ctor:%u (%s) %.2fms", source_index, engine_name, stopwatch.get_miliseconds());
		}

		return BCS_S_OK;
	}
	catch (BCS_RESULT error_result)
	{
		debug_break;
		return error_result;
	}
	catch (...)
	{
		debug_break;
		return BCS_E_FAIL;
	}
}

BCS_RESULT create_high_level_virtual(s_engine_platform_build engine_platform_build)
{
	try
	{
		const char* engine_name;
		ASSERT(BCS_SUCCEEDED(get_engine_type_pretty_string(engine_platform_build.engine_type, engine_name)));

		c_stopwatch stopwatch;
		stopwatch.start();
		c_high_level_tag_source_generator high_level_tag_source_generator(engine_platform_build);
		if (BCS_SUCCEEDED(command_line_has_argument("verbose")))
		{
			console_write_line("Generating high level source virtual functions (%s)", engine_name);
		}
		high_level_tag_source_generator.generate_source_virtual();
		stopwatch.stop();
		if (BCS_SUCCEEDED(command_line_has_argument("verbose")))
		{
			console_write_line("Finished generating high level source virtual functions (%s) %.2fms", engine_name, stopwatch.get_miliseconds());
		}

		return BCS_S_OK;
	}
	catch (BCS_RESULT error_result)
	{
		debug_break;
		return error_result;
	}
	catch (...)
	{
		debug_break;
		return BCS_E_FAIL;
	}
}

BCS_RESULT create_high_level_misc(s_engine_platform_build engine_platform_build)
{
	try
	{
		const char* engine_name;
		ASSERT(BCS_SUCCEEDED(get_engine_type_pretty_string(engine_platform_build.engine_type, engine_name)));

		c_stopwatch stopwatch;
		stopwatch.start();
		c_high_level_tag_source_generator high_level_tag_source_generator(engine_platform_build);
		if (BCS_SUCCEEDED(command_line_has_argument("verbose")))
		{
			console_write_line("Generating high level source misc (%s)", engine_name);
		}
		high_level_tag_source_generator.generate_source_misc();
		stopwatch.stop();
		if (BCS_SUCCEEDED(command_line_has_argument("verbose")))
		{
			console_write_line("Finished generating high level source misc (%s) %.2fms", engine_name, stopwatch.get_miliseconds());
		}

		return BCS_S_OK;
	}
	catch (BCS_RESULT error_result)
	{
		debug_break;
		return error_result;
	}
	catch (...)
	{
		debug_break;
		return BCS_E_FAIL;
	}
}

BCS_RESULT create_source_file()
{
	BCS_RESULT rs = BCS_S_OK;

	s_engine_platform_build const engine_and_platform_types[] =
	{
		{ _engine_type_halo1,				_platform_type_pc_64bit },
		{ _engine_type_stubbs,				_platform_type_pc_64bit },
		{ _engine_type_halo2,				_platform_type_pc_64bit },
		{ _engine_type_halo3,				_platform_type_pc_64bit },
		{ _engine_type_halo3odst,			_platform_type_pc_64bit },
		{ _engine_type_haloreach,			_platform_type_xbox_360 },
		{ _engine_type_halo4,				_platform_type_xbox_360 },
		{ _engine_type_groundhog,			_platform_type_pc_64bit },
		{ _engine_type_infinite,			_platform_type_pc_64bit, _build_infinite_HIREL_209048_21_12_09_1546 },
	};

	console_write_line("Generating tag code");
	c_stopwatch stopwatch;
	stopwatch.start();

	t_task_group* task_group;
	ASSERT(BCS_SUCCEEDED(task_group_create(task_group)));
	static BCS_RESULT execute_result = BCS_S_OK;
	for (s_engine_platform_build engine_platform_build : engine_and_platform_types)
	{
		c_tag_struct_definition_view tag_structs_view(engine_platform_build);
		c_structure_relationship_node::create_structure_relationships(tag_structs_view, engine_platform_build);
		c_structure_relationship_node::create_sorted_tag_struct_definitions(engine_platform_build);
		c_structure_relationship_node::create_sorted_tag_enum_definitions(engine_platform_build);
		c_structure_relationship_node::create_sorted_tag_block_definitions(engine_platform_build);

		task_group_run(
			task_group,
			[](void* userdata)
			{
				s_engine_platform_build engine_platform_build = *reinterpret_cast<s_engine_platform_build*>(&userdata);

				create_low_level(engine_platform_build);
			},
			*reinterpret_cast<void**>(&engine_platform_build));
		task_group_run(
			task_group,
			[](void* userdata)
			{
				s_engine_platform_build engine_platform_build = *reinterpret_cast<s_engine_platform_build*>(&userdata);


				create_high_level(engine_platform_build);
			},
			*reinterpret_cast<void**>(&engine_platform_build));

		for (uintptr_t source_index = 0; source_index < k_ctor_source_count; source_index++)
		{
			task_group_run(
				task_group,
				[](void* userdata0, void* userdata1)
				{
					s_engine_platform_build engine_platform_build = *reinterpret_cast<s_engine_platform_build*>(&userdata0);
					uintptr_t source_index = reinterpret_cast<uintptr_t>(userdata1);

					create_high_level_ctor(engine_platform_build, static_cast<unsigned long>(source_index));
				},
				*reinterpret_cast<void**>(&engine_platform_build), reinterpret_cast<void*>(source_index));
		}

		task_group_run(
			task_group,
			[](void* userdata)
			{
				s_engine_platform_build engine_platform_build = *reinterpret_cast<s_engine_platform_build*>(&userdata);

				create_high_level_virtual(engine_platform_build);
			},
			*reinterpret_cast<void**>(&engine_platform_build));
		task_group_run(
			task_group,
			[](void* userdata)
			{
				s_engine_platform_build engine_platform_build = *reinterpret_cast<s_engine_platform_build*>(&userdata);

				create_high_level_misc(engine_platform_build);
			},
			*reinterpret_cast<void**>(&engine_platform_build));
	}
	if (BCS_FAILED(rs = task_group_wait(task_group)))
	{
		return rs;
	}
	if (BCS_FAILED(rs = task_group_destroy(task_group)))
	{
		return rs;
	}
	if (BCS_FAILED(rs = execute_result))
	{
		return rs;
	}

	stopwatch.stop();
	if (BCS_SUCCEEDED(command_line_has_argument("verbose")))
	{
		console_write_line("Finished generating tag code %.2fms", stopwatch.get_miliseconds());
	}

	return rs;
}

int main()
{
	register_process_module_by_pointer(main);
	init_console();
	init_command_line();

	if (!BCS_SUCCEEDED(command_line_has_argument("output")))
	{
		return BCS_E_COMMAND_LINE_MISSING;
	}

	BCS_RESULT rs = create_source_file();

	deinit_command_line();
	deinit_console();
	return rs;
}
