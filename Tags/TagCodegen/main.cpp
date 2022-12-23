#include "tagcodegen-private-pch.h"
#include <SymbolsLib\symbolslib-public-pch.h>

BCS_RESULT create_low_level(s_engine_platform_build engine_platform_build)
{
	try
	{
		const char* engine_name;
		ASSERT(BCS_SUCCEEDED(get_engine_type_pretty_string(engine_platform_build.engine_type, engine_name)));

		c_stopwatch stopwatch;
		stopwatch.start();
		c_low_level_tag_source_generator low_level_tag_source_generator(engine_platform_build);
		if (BCS_SUCCEEDED(command_line_has_argument_internal("verbose")))
		{
			console_write_line("Generating low level header (%s)", engine_name);
		}
		low_level_tag_source_generator.generate_header();
		low_level_tag_source_generator.generate_ida_header();
		low_level_tag_source_generator.generate_source();
		low_level_tag_source_generator.generate_enum_header();
		stopwatch.stop();
		if (BCS_SUCCEEDED(command_line_has_argument_internal("verbose")))
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

BCS_RESULT create_low_level_source_file(s_engine_platform_build engine_platform_build)
{
	BCS_RESULT rs = BCS_S_OK;

	c_stopwatch stopwatch;
	stopwatch.start();

	blofeld::c_tag_struct_definition_view tag_structs_view(engine_platform_build);
	c_structure_relationship_node::create_structure_relationships(tag_structs_view, engine_platform_build);
	c_structure_relationship_node::create_sorted_tag_struct_definitions(engine_platform_build);
	c_structure_relationship_node::create_sorted_tag_enum_definitions(engine_platform_build);
	c_structure_relationship_node::create_sorted_tag_block_definitions(engine_platform_build);

	create_low_level(engine_platform_build);

	stopwatch.stop();
	if (BCS_SUCCEEDED(command_line_has_argument_internal("verbose")))
	{
		console_write_line("Finished generating tag code %.2fms", stopwatch.get_miliseconds());
	}

	return rs;
}

struct s_create_high_level_source_file_ctors
{
	c_high_level_tag_source_generator* tag_source_generator;
	unsigned int volatile header_index;
	unsigned int volatile forward_declare_index;
	unsigned int volatile virtual_index;
	unsigned int volatile misc_index;
	unsigned int volatile ctor_index;
	unsigned int ctor_count;
};

void create_high_level_source_file_ctors(void* userdata, unsigned int thread_index, unsigned int thread_count)
{
	s_create_high_level_source_file_ctors& args = *static_cast<s_create_high_level_source_file_ctors*>(userdata);

	if (thread_index == 0)
	{
		args.tag_source_generator->generate_high_level_header(thread_index, thread_count);
		args.tag_source_generator->generate_high_level_source(thread_index, thread_count);
		args.tag_source_generator->generate_high_level_virtual(thread_index, thread_count);
		args.tag_source_generator->generate_high_level_natvis(thread_index, thread_count);
	}
}

BCS_RESULT create_high_level_source_file(s_engine_platform_build engine_platform_build, unsigned int global_vftable_index)
{
	BCS_RESULT rs = BCS_S_OK;

	c_stopwatch stopwatch;
	stopwatch.start();
	
	blofeld::c_tag_struct_definition_view tag_structs_view(engine_platform_build);
	c_structure_relationship_node::create_structure_relationships(tag_structs_view, engine_platform_build);
	c_structure_relationship_node::create_sorted_tag_struct_definitions(engine_platform_build);
	c_structure_relationship_node::create_sorted_tag_enum_definitions(engine_platform_build);
	c_structure_relationship_node::create_sorted_tag_block_definitions(engine_platform_build);

	stopwatch.stop();
	float ms = stopwatch.get_miliseconds();


	blofeld::t_tag_group_collection tag_groups;
	BCS_RESULT get_tag_groups_result = blofeld::tag_definition_registry_get_tag_groups_by_engine_platform_build(engine_platform_build, tag_groups);
	if (BCS_FAILED(get_tag_groups_result))
	{
		return get_tag_groups_result;
	}

	c_runtime_tag_definitions* runtime_definitions = new() c_runtime_tag_definitions();
	runtime_definitions->init_from_blofeld(engine_platform_build, tag_groups);

	uint32_t source_count = 64;
	if (BCS_SUCCEEDED(command_line_get_argument_ulong("sourcecount", source_count)))
	{
		console_write_line("sourcecount: %u", source_count);
	}
	s_create_high_level_source_file_ctors create_high_level_source_file_ctors_args = {};
	create_high_level_source_file_ctors_args.tag_source_generator = new() c_high_level_tag_source_generator(*runtime_definitions, engine_platform_build, global_vftable_index);
	create_high_level_source_file_ctors_args.header_index = 0;
	create_high_level_source_file_ctors_args.forward_declare_index = 0;
	create_high_level_source_file_ctors_args.virtual_index = 0;
	create_high_level_source_file_ctors_args.misc_index = 0;
	create_high_level_source_file_ctors_args.ctor_index = 0;
	create_high_level_source_file_ctors_args.ctor_count = source_count;


	stopwatch.stop();
	float a = stopwatch.get_miliseconds();
	parallel_invoke_thread_count(create_high_level_source_file_ctors, &create_high_level_source_file_ctors_args);
	stopwatch.stop();
	float b = stopwatch.get_miliseconds();
	//create_high_level_source_file_ctors(&create_high_level_source_file_ctors_args, 0, 1);
	stopwatch.stop();
	float c = stopwatch.get_miliseconds();

	float t0 = b - a;
	float t1 = c - b;


	stopwatch.stop();
	float ms2 = stopwatch.get_miliseconds() - ms;

	stopwatch.stop();
	if (BCS_SUCCEEDED(command_line_has_argument_internal("verbose")))
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
	blofeld::tag_definition_registry_init();
	blofeld::tag_definitions_register();

	const char* type_argument;
	if (!BCS_SUCCEEDED(command_line_get_argument("type", type_argument)))
	{
		console_write_line("argument 'type' missing");
		return BCS_E_COMMAND_LINE_MISSING;
	}
	else
	{
		console_write_line("type: %s", type_argument);
	}

	const char* engine_argument;
	e_engine_type engine_type;
	if (!BCS_SUCCEEDED(command_line_get_argument("engine", engine_argument)))
	{
		console_write_line("argument 'engine' missing");
		return BCS_E_COMMAND_LINE_MISSING;
	}
	else if (BCS_FAILED(engine_namespace_to_engine_type(engine_argument, engine_type)))
	{
		console_write_line("invalid engine: %s", engine_argument);
	}
	else
	{
		console_write_line("engine: %s", engine_argument);
	}

	const char* platform_argument;
	e_platform_type platform_type;
	if (!BCS_SUCCEEDED(command_line_get_argument("platform", platform_argument)))
	{
		console_write_line("argument 'platform' missing");
		return BCS_E_COMMAND_LINE_MISSING;
	}
	else if (BCS_FAILED(platform_namespace_to_platform_type(platform_argument, platform_type)))
	{
		console_write_line("invalid platform: %s", platform_argument);
	}
	else
	{
		console_write_line("platform: %s", platform_argument);
	}

	unsigned int global_vftable_index;
	if (!BCS_SUCCEEDED(command_line_get_argument_ulong("globalindex", global_vftable_index)))
	{
		console_write_line("argument 'globalindex' missing");
		return BCS_E_COMMAND_LINE_MISSING;
	}
	else if (global_vftable_index == 0)
	{
		console_write_line("globalindex 0 is reserved");
		return BCS_E_INVALID_ARGUMENT;
	}
	else
	{
		console_write_line("globalindex: %i", global_vftable_index);
	}

	const char* output_argument;
	if (!BCS_SUCCEEDED(command_line_get_argument("output", output_argument)))
	{
		console_write_line("argument 'output' missing");
		if (!__bcs_is_debugger_present())
		{
			return BCS_E_COMMAND_LINE_MISSING;
		}
	}
	else
	{
		console_write_line("output: %s", output_argument);
	}

	BCS_RESULT rs = BCS_S_OK;

	if (strcmp("lowlevel", type_argument) == 0)
	{
		console_write_line("Generating tag code [%s %s %s %u]", type_argument, engine_argument, platform_argument, global_vftable_index);
		if (BCS_FAILED(rs = create_low_level_source_file({ engine_type, platform_type })))
		{
			const char* error_string = bcs_result_get_string(rs);
			console_write_line("Failed to generate low level source file [%s]", error_string);
		}
	}
	else if (strcmp("highlevel", type_argument) == 0)
	{
		console_write_line("Generating tag code [%s %s %s %u]", type_argument, engine_argument, platform_argument, global_vftable_index);
		if (BCS_FAILED(rs = create_high_level_source_file({ engine_type, platform_type }, global_vftable_index)))
		{
			const char* error_string = bcs_result_get_string(rs);
			console_write_line("Failed to generate high level source file [%s]", error_string);
		}
	}
	else
	{
		console_write_line("invalid type: %s", type_argument);
	}

	//BCS_RESULT rs = create_source_file();

	blofeld::tag_definitions_unregister();
	blofeld::tag_definition_registry_deinit();
	deinit_command_line();
	deinit_console();
	return rs;
}
