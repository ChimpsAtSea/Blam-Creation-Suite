#include "tagcodegen-private-pch.h"

using namespace blofeld;

template<typename t_runtime_definition>
static void enqueue_vftable_indices(c_high_level_tag_source_generator::t_pointer_to_vftable_index& pointer_to_vftable_index, unsigned int& local_vftable_count, std::vector<t_runtime_definition*>& definitions)
{
	for (t_runtime_definition* definition : definitions)
	{
		pointer_to_vftable_index[definition] = local_vftable_count++;
	}
}

template<typename t_caller>
static BCS_RESULT structure_field_iteartor(
	c_runtime_tag_struct_definition& struct_definition,
	std::stringstream* stream,
	t_caller* caller,
	BCS_RESULT(t_caller::* structure_field_iteartor_callback)(
		std::stringstream* stream,
		c_runtime_tag_struct_definition& struct_definition,
		c_runtime_tag_field_definition& field_definition,
		unsigned int runtime_field_index,
		unsigned int generated_field_index,
		const char* formatted_code_name))
{
	t_string_list_value_unique_counter field_name_unique_counter;
	unsigned int runtime_field_index = 0;
	unsigned int generated_field_index = 0;
	unsigned int version_hits = 0;
	for (t_blamtoozle_tag_field* blamtoozle_field_definition : struct_definition.fields)
	{
		if (version_hits > 1)
		{
			return BCS_S_OK; // #TODO
		}
		if (c_runtime_tag_field_definition* field_definition = dynamic_cast<c_runtime_tag_field_definition*>(blamtoozle_field_definition))
		{
			c_blamlib_string_parser_v2 field_formatter = c_blamlib_string_parser_v2(
				field_definition->name.c_str(),
				field_definition->field_type == _field_block,
				&field_name_unique_counter);

			switch (field_definition->field_type)
			{
			case _field_version:
			{
				version_hits++;
			}
			break;
			case _field_terminator:
			{
				// do nothing
			}
			break;
			default:
			{
				BCS_RESULT result = (caller->*structure_field_iteartor_callback)(
					stream,
					struct_definition,
					*field_definition,
					runtime_field_index,
					generated_field_index,
					field_formatter.code_name.c_str());
				if (result != BCS_S_SKIP)
				{
					generated_field_index++;
				}
			}
			break;
			}

			runtime_field_index++;
		}
	}

	if (generated_field_index == 0)
	{
		return BCS_S_NO_CHANGES_MADE;
	}
	return BCS_S_OK;
}

c_high_level_tag_source_generator::c_high_level_tag_source_generator(c_runtime_tag_definitions& _runtime_definitions, s_engine_platform_build _engine_platform_build, unsigned int _global_vftable_index) :
	c_source_generator_base(_engine_platform_build),
	global_vftable_index(_global_vftable_index),
	local_vftable_count(0),
	output_directory(),
	output_header_file_path(),
	output_source_file_path(),
	output_natvis_file_path(),
	output_virtual_file_path(),
	output_misc_file_path(),
	runtime_definitions(_runtime_definitions),
	pointer_to_vftable_index(),
	structure_type_containers(),
	_structure_type_containers()
{
	// enqueue_vftable_indices(pointer_to_vftable_index, vftable_index, runtime_definitions.tag_group_definitions);
	// enqueue_vftable_indices(pointer_to_vftable_index, vftable_index, runtime_definitions.tag_block_definitions);
	enqueue_vftable_indices(pointer_to_vftable_index, local_vftable_count, runtime_definitions.tag_struct_definitions);
	// enqueue_vftable_indices(pointer_to_vftable_index, vftable_index, runtime_definitions.tag_array_definitions);
	// enqueue_vftable_indices(pointer_to_vftable_index, vftable_index, runtime_definitions.tag_string_list_definitions);
	// enqueue_vftable_indices(pointer_to_vftable_index, vftable_index, runtime_definitions.tag_reference_definitions);
	// enqueue_vftable_indices(pointer_to_vftable_index, vftable_index, runtime_definitions.tag_resource_definitions);
	// enqueue_vftable_indices(pointer_to_vftable_index, vftable_index, runtime_definitions.tag_api_interop_definitions);
	// enqueue_vftable_indices(pointer_to_vftable_index, vftable_index, runtime_definitions.tag_data_definitions);
	// enqueue_vftable_indices(pointer_to_vftable_index, vftable_index, runtime_definitions.tag_block_index_custom_search_definitions);

	// enqueue_vftable_indices(pointer_to_vftable_index, local_vftable_count, runtime_definitions.tag_field_definitions);
	for (c_runtime_tag_struct_definition* struct_definition : runtime_definitions.tag_struct_definitions)
	{
		//enqueue_vftable_indices(pointer_to_vftable_index, local_vftable_count, struct_definition->fields);
		structure_field_iteartor(*struct_definition, nullptr, this, &c_high_level_tag_source_generator::enqueue_high_level_virtual_fields);
	}

	if (local_vftable_count > USHRT_MAX)
	{
		console_write_line("Exceeded vtable index limit %u -> %u", static_cast<unsigned int>(USHRT_MAX), local_vftable_count);
		throw BCS_E_FATAL;
	}

	const char* _output_directory;
	if (BCS_SUCCEEDED(command_line_get_argument("output", _output_directory))) // #TODO: rename to 'output-directory'
	{
		std::stringstream output_directory_stream;
		output_directory_stream << _output_directory << "high_level_" << get_engine_namespace(_namespace_suffix_mode_none) << "_" + get_platform_namespace(_namespace_suffix_mode_none);
		output_directory = output_directory_stream.str();

		std::stringstream output_header_file_path_stream;
		output_header_file_path_stream << output_directory << "\\" << get_engine_namespace(_namespace_suffix_mode_none) << "_" + get_platform_namespace(_namespace_suffix_mode_none) + ".h";
		output_header_file_path = output_header_file_path_stream.str();

		std::stringstream output_virtual_file_path_stream;
		output_virtual_file_path_stream << output_directory << "\\" << get_engine_namespace(_namespace_suffix_mode_none) << "_" + get_platform_namespace(_namespace_suffix_mode_none) + "_virtual.cpp";
		output_virtual_file_path = output_virtual_file_path_stream.str();

		std::stringstream output_misc_file_path_stream;
		output_misc_file_path_stream << output_directory << "\\" << get_engine_namespace(_namespace_suffix_mode_none) << "_" + get_platform_namespace(_namespace_suffix_mode_none) + "_misc.cpp";
		output_misc_file_path = output_misc_file_path_stream.str();

		std::stringstream output_source_file_path_stream;
		output_source_file_path_stream << output_directory << "\\" << get_engine_namespace(_namespace_suffix_mode_none) << "_" + get_platform_namespace(_namespace_suffix_mode_none) + ".cpp";
		output_source_file_path = output_source_file_path_stream.str();

		std::stringstream output_natvis_file_path_stream;
		output_natvis_file_path_stream << output_directory << "\\" << get_engine_namespace(_namespace_suffix_mode_none) << "_" + get_platform_namespace(_namespace_suffix_mode_none) + ".natvis";
		output_natvis_file_path = output_natvis_file_path_stream.str();
	}

	_structure_type_containers = new() c_high_level_structure_type_container * [runtime_definitions.tag_struct_definitions.size()];
	for (size_t struct_index = 0; struct_index < runtime_definitions.tag_struct_definitions.size(); struct_index++)
	{
		c_runtime_tag_struct_definition* struct_definition = runtime_definitions.tag_struct_definitions[struct_index];
		unsigned int local_vftable_index = pointer_to_vftable_index[struct_definition];
		c_high_level_structure_type_container* type_container = new() c_high_level_structure_type_container(
			*struct_definition,
			engine_platform_build,
			global_vftable_index,
			local_vftable_index);

		type_container->generate_high_level_header(1);
		type_container->generate_high_level_source(1);

		_structure_type_containers[struct_index] = type_container;
	}

	for (size_t struct_index = 0; struct_index < runtime_definitions.tag_struct_definitions.size(); struct_index++)
	{
		c_high_level_structure_type_container* type_container = _structure_type_containers[struct_index];
		structure_type_containers[&type_container->struct_definition] = type_container;
	}

}

c_high_level_tag_source_generator::~c_high_level_tag_source_generator()
{
	for (size_t struct_index = 0; struct_index < runtime_definitions.tag_struct_definitions.size(); struct_index++)
	{
		c_high_level_structure_type_container* type_container = _structure_type_containers[struct_index];
		delete type_container;
	}
	delete[] _structure_type_containers;
}

BCS_RESULT c_high_level_tag_source_generator::enqueue_high_level_virtual_fields(
	std::stringstream* stream,
	c_runtime_tag_struct_definition& struct_definition,
	c_runtime_tag_field_definition& field_definition,
	unsigned int runtime_field_index,
	unsigned int generated_field_index,
	const char* formatted_code_name)
{
	pointer_to_vftable_index[&field_definition] = local_vftable_count++;
	return BCS_S_OK;
}

c_high_level_structure_type_container::c_high_level_structure_type_container(
	c_runtime_tag_struct_definition& _struct_definition,
	s_engine_platform_build _engine_platform_build,
	unsigned int _global_vftable_index,
	unsigned int _local_vftable_index) :
	c_source_generator_base(_engine_platform_build),
	high_level_structure_name(c_high_level_tag_source_generator::format_structure_symbol(_struct_definition)),
	struct_definition(_struct_definition),
	global_vftable_index(_global_vftable_index),
	local_vftable_index(_local_vftable_index),
	header_written(),
	source_written()
{

}

c_high_level_structure_type_container::~c_high_level_structure_type_container()
{
}

BCS_RESULT c_high_level_structure_type_container::generate_high_level_header(unsigned int header_indent_count)
{
	std::stringstream stream;
	for (size_t indent_index = 0; indent_index < header_indent_count; indent_index++) increment_indent();

	stream << indent << "class " << high_level_structure_name << " :" << std::endl;
	increment_indent();
	stream << indent << "public h_prototype" << std::endl;
	decrement_indent();
	stream << indent << "{" << std::endl;
	increment_indent();
	stream << indent << "intelliaccess(public, protected) :;" << std::endl;
	//stream << indent << "intelliaccess(public, protected) :;" << std::endl;
	//stream << indent << "intelliaccess(public, protected) :;" << std::endl;
	//stream << std::endl;
	stream << indent << "static constexpr unsigned short k_global_vftable_index = " << global_vftable_index << ";" << std::endl;
	stream << indent << "static constexpr unsigned short k_local_vftable_index = " << local_vftable_index << ";" << std::endl;
	stream << indent << "static h_prototype_function_table vftable;" << std::endl;
	stream << indent << "static h_member_info const member_information[];" << std::endl;
	// stream << indent << "static size_t num_member_information;" << std::endl;
	BCS_RESULT write_serialization_info_result = BCS_S_NO_CHANGES_MADE;
	std::stringstream serialization_stream;
	if (struct_definition.fields.size() > 1)
	{
		write_serialization_info_result = structure_field_iteartor(struct_definition, &serialization_stream, this, &c_high_level_structure_type_container::empty_field_iterator);
		stream << indent << "static h_serialization_info const serialization_information[];" << std::endl;
	}
	if (write_serialization_info_result == BCS_S_OK)
	{
		stream << serialization_stream.str();
	}
	stream << indent << "static h_pointer_to_member pointer_to_members[];" << std::endl;
	stream << std::endl;
	decrement_indent();
	stream << indent << "protected:" << std::endl;
	increment_indent();
	stream << indent << "static h_prototype* prototype_constructor(h_extended_type* parent);" << std::endl;
	stream << indent << "static h_prototype* copy_constructor(h_prototype& copy_prototype, h_extended_type* parent = nullptr);" << std::endl;
	stream << indent << "static void prototype_destructor(" << high_level_structure_name << "* value);" << std::endl;
	stream << indent << "h_member_info const* get_member_information(unsigned int& num_member_information);" << std::endl;
	stream << indent << "h_serialization_info const* get_serialization_information(unsigned int& num_serialization_information);" << std::endl;
	stream << indent << "static size_t get_size();" << std::endl;
	stream << indent << "static unsigned int get_version();" << std::endl;
	stream << indent << "static blofeld::s_tag_struct_definition const& get_blofeld_struct_definition();" << std::endl;
	stream << indent << "h_pointer_to_member* get_pointer_to_members_impl();" << std::endl;
	stream << std::endl;
	decrement_indent();
	stream << indent << "public:" << std::endl;
	increment_indent();
	stream << indent << "BCS_SHARED " << high_level_structure_name << "(h_extended_type* parent = nullptr);" << std::endl;
	stream << indent << "BCS_SHARED " << high_level_structure_name << "(" << high_level_structure_name << " const&, h_extended_type* parent = nullptr);" << std::endl;
	stream << indent << "BCS_SHARED ~" << high_level_structure_name << "();" << std::endl;
	stream << std::endl;

	structure_field_iteartor(struct_definition, &stream, this, &c_high_level_structure_type_container::generate_high_level_header_structure_fields);

	t_string_list_value_unique_counter field_name_unique_counter;
	unsigned int field_index = 0;
	unsigned int version_hits = 0;
	for (t_blamtoozle_tag_field* blamtoozle_field_definition : struct_definition.fields)
	{
		if (version_hits > 0)
		{
			break; // #TODO
		}
		if (c_runtime_tag_field_definition* field_definition = dynamic_cast<c_runtime_tag_field_definition*>(blamtoozle_field_definition))
		{
			c_blamlib_string_parser_v2 field_formatter = c_blamlib_string_parser_v2(
				field_definition->name.c_str(),
				field_definition->field_type == _field_block,
				&field_name_unique_counter);

			field_index++;
		}
	}

	stream << std::endl;
	decrement_indent();
	stream << indent << "};" << std::endl;
	stream << std::endl;

	debug_point;

	header = stream.str();
	for (size_t indent_index = 0; indent_index < header_indent_count; indent_index++) decrement_indent();
	return BCS_S_OK;
}

BCS_RESULT c_high_level_structure_type_container::generate_high_level_header_structure_fields(
	std::stringstream* stream,
	c_runtime_tag_struct_definition& struct_definition,
	c_runtime_tag_field_definition& field_definition,
	unsigned int runtime_field_index,
	unsigned int generated_field_index,
	const char* formatted_code_name)
{
	switch (field_definition.field_type)
	{
	case _field_vertex_buffer:
		break;
	case _field_struct:
	{
		std::string field_source_type = c_high_level_tag_source_generator::format_structure_symbol(*field_definition.struct_definition);
		*stream << indent << "prototype_child_to_parent(UINT_MAX, __" << formatted_code_name << "_offset);" << std::endl;
		*stream << indent << field_source_type << " " << formatted_code_name << ";" << std::endl;
	}
	break;
	case _field_array:
	{
		std::string field_source_type = c_high_level_tag_source_generator::format_structure_symbol(*field_definition.array_definition->struct_definition);
		*stream << indent << "h_prototype_array<" << field_source_type << ", " << field_definition.array_definition->element_count << ", " << high_level_structure_name << ", " << generated_field_index << "> " << formatted_code_name << ";" << std::endl;
	}
	break;
	case _field_block:
	{
		std::string field_source_type = c_high_level_tag_source_generator::format_structure_symbol(*field_definition.block_definition->struct_definition);
		*stream << indent << "h_prototype_block<" << field_source_type << ", " << high_level_structure_name << ", " << generated_field_index << "> " << formatted_code_name << ";" << std::endl;
	}
	break;
	case _field_tag_reference:
	case _field_embedded_tag:
	{
		// stream << indent << "// prototype_child_to_parent(UINT_MAX, __" << formatted_code_name << "_offset);" << std::endl;
		*stream << indent << "// h_prototype_reference<" << high_level_structure_name << ", " << generated_field_index << "> " << formatted_code_name << ";" << std::endl;
	}
	break;
	case _field_data:
	{
		*stream << indent << "h_prototype_data<" << high_level_structure_name << ", " << generated_field_index << "> " << formatted_code_name << ";" << std::endl;
	}
	break;
	case _field_pageable_resource:
	{
		*stream << indent << "h_prototype_resource_field<" << high_level_structure_name << ", " << generated_field_index << "> " << formatted_code_name << ";" << std::endl;
	}
	break;
	case _field_api_interop:
	{
		// stream << indent << "// prototype_child_to_parent(UINT_MAX, __" << formatted_code_name << "_offset);" << std::endl;
		*stream << indent << "// h_prototype_interop<" << high_level_structure_name << ", " << generated_field_index << "> " << formatted_code_name << ";" << std::endl;
	}
	break;
	case _field_string_id:
	case _field_old_string_id:
	{
		*stream << indent << "h_prototype_string_id_field<" << high_level_structure_name << ", " << generated_field_index << "> " << formatted_code_name << ";" << std::endl;
	}
	break;
	default:
	{

		const char* field_source_type = c_high_level_tag_source_generator::field_type_to_high_level_source_type(engine_platform_build.platform_type, field_definition.field_type);
		if (field_source_type)
		{
			*stream << indent << "h_prototype_field<" << field_source_type << ", " << high_level_structure_name << ", " << generated_field_index << "> " << formatted_code_name << ";" << std::endl;
		}
		else
		{
			return BCS_S_SKIP;
		}
	}
	}
	return BCS_S_OK;
}

BCS_RESULT c_high_level_structure_type_container::generate_high_level_source(unsigned int source_indent_count)
{
	std::stringstream stream;
	for (size_t indent_index = 0; indent_index < source_indent_count; indent_index++) increment_indent();

	stream << indent << high_level_structure_name << "::" << high_level_structure_name << "(" << high_level_structure_name << " const& copy, h_extended_type* parent) :" << std::endl;
	increment_indent();
	stream << indent << "h_prototype(parent, /*global_vftable_index*/" << global_vftable_index << ", /*local_vftable_index*/" << local_vftable_index << ")";
	structure_field_iteartor(struct_definition, &stream, this, &c_high_level_structure_type_container::generate_high_level_source_structure_fields);
	stream << std::endl;
	decrement_indent();
	stream << indent << "{" << std::endl;
	increment_indent();
	stream << indent << "throw BCS_E_NOT_IMPLEMENTED; // need to implement field copy" << std::endl;
	decrement_indent();
	stream << indent << "}" << std::endl;
	stream << std::endl;

	stream << indent << high_level_structure_name << "::" << high_level_structure_name << "(h_extended_type* parent) :" << std::endl;
	increment_indent();
	stream << indent << "h_prototype(parent, /*global_vftable_index*/" << global_vftable_index << ", /*local_vftable_index*/" << local_vftable_index << ")";
	structure_field_iteartor(struct_definition, &stream, this, &c_high_level_structure_type_container::generate_high_level_source_structure_fields);
	stream << std::endl;
	decrement_indent();
	stream << indent << "{" << std::endl;
	increment_indent();
	decrement_indent();
	stream << indent << "}" << std::endl;
	stream << std::endl;

	stream << indent << high_level_structure_name << "::~" << high_level_structure_name << "()" << std::endl;
	stream << indent << "{" << std::endl;
	increment_indent();
	decrement_indent();
	stream << indent << "}" << std::endl;
	stream << std::endl;

	stream << indent << "h_prototype::h_prototype_function_table " << high_level_structure_name << "::vftable =" << std::endl;
	stream << indent << "{" << std::endl;
	increment_indent();
	stream << indent << "_high_level_vtable_prototype," << std::endl;
	stream << indent << "reinterpret_cast<decltype(h_prototype::h_prototype_function_table::prototype_constructor)>(&prototype_constructor)," << std::endl;
	stream << indent << "reinterpret_cast<decltype(h_prototype::h_prototype_function_table::copy_constructor)>(&copy_constructor)," << std::endl;
	stream << indent << "reinterpret_cast<decltype(h_prototype::h_prototype_function_table::prototype_destructor)>(&prototype_destructor)," << std::endl;
	stream << indent << "reinterpret_cast<decltype(h_prototype::h_prototype_function_table::get_size)>(&get_size)," << std::endl;
	stream << indent << "reinterpret_cast<decltype(h_prototype::h_prototype_function_table::get_version)>(&get_version)," << std::endl;
	stream << indent << "reinterpret_cast<decltype(h_prototype::h_prototype_function_table::get_blofeld_struct_definition)>(&get_blofeld_struct_definition)," << std::endl;
	stream << indent << "reinterpret_cast<decltype(h_prototype::h_prototype_function_table::get_member_information)>(&get_member_information)," << std::endl;
	stream << indent << "reinterpret_cast<decltype(h_prototype::h_prototype_function_table::get_serialization_information)>(&get_serialization_information)," << std::endl;
	decrement_indent();
	stream << indent << "};" << std::endl;
	stream << std::endl;
	stream << indent << "h_member_info const " << high_level_structure_name << "::member_information[1];" << std::endl;

	stream << indent << "h_prototype* " << high_level_structure_name << "::prototype_constructor(h_extended_type* parent)" << std::endl;
	stream << indent << "{" << std::endl;
	increment_indent();
	stream << indent << "return new() " << high_level_structure_name << "(parent);" << std::endl;
	decrement_indent();
	stream << indent << "}" << std::endl;
	stream << std::endl;

	stream << indent << "h_prototype* " << high_level_structure_name << "::copy_constructor(h_prototype& copy_prototype, h_extended_type* parent)" << std::endl;
	stream << indent << "{" << std::endl;
	increment_indent();
	increment_indent();
	stream << indent << "if(" << high_level_structure_name << "* copy = high_level_cast<" << high_level_structure_name << "*>(&copy_prototype))" << std::endl;
	stream << indent << "{" << std::endl;
	increment_indent();
	stream << indent << "return new() " << high_level_structure_name << "(*copy, parent);" << std::endl;
	decrement_indent();
	stream << indent << "}" << std::endl;
	decrement_indent();
	stream << indent << "return nullptr;" << std::endl;
	decrement_indent();
	stream << indent << "}" << std::endl;
	stream << std::endl;

	stream << indent << "void " << high_level_structure_name << "::prototype_destructor(" << high_level_structure_name << "* value)" << std::endl;
	stream << indent << "{" << std::endl;
	increment_indent();
	stream << indent << "delete value;" << std::endl;
	decrement_indent();
	stream << indent << "}" << std::endl;
	stream << std::endl;

	stream << indent << "size_t " << high_level_structure_name << "::get_size()" << std::endl;
	stream << indent << "{" << std::endl;
	increment_indent();
	stream << indent << "return sizeof(" << high_level_structure_name << ");" << std::endl;
	decrement_indent();
	stream << indent << "}" << std::endl;
	stream << std::endl;

	stream << indent << "unsigned int " << high_level_structure_name << "::get_version()" << std::endl;
	stream << indent << "{" << std::endl;
	increment_indent();
	stream << indent << "return 0; // #TODO" << std::endl;
	decrement_indent();
	stream << indent << "}" << std::endl;
	stream << std::endl;

	stream << indent << "blofeld::s_tag_struct_definition const& " << high_level_structure_name << "::get_blofeld_struct_definition()" << std::endl;
	stream << indent << "{" << std::endl;
	increment_indent();
	stream << indent << "return " << struct_definition.original_tag_struct_definition->symbol->symbol_name << ";" << std::endl;
	decrement_indent();
	stream << indent << "}" << std::endl;
	stream << std::endl;

	// stream << indent << "size_t " << high_level_structure_name << "::num_member_information = _countof(member_information);" << std::endl;
	BCS_RESULT write_serialization_info_result = BCS_S_NO_CHANGES_MADE;
	std::stringstream serialization_stream;
	if (struct_definition.fields.size() > 1)
	{
		serialization_stream << indent << "h_serialization_info const " << high_level_structure_name << "::serialization_information[] =" << std::endl;
		serialization_stream << indent << "{" << std::endl;
		increment_indent();
		write_serialization_info_result = structure_field_iteartor(struct_definition, &serialization_stream, this, &c_high_level_structure_type_container::generate_high_level_source_serialization_fields);
		decrement_indent();
		serialization_stream << indent << "};" << std::endl;
		serialization_stream << std::endl;
		serialization_stream << indent << "h_serialization_info const* " << high_level_structure_name << "::get_serialization_information(unsigned int& num_serialization_information)" << std::endl;
		serialization_stream << indent << "{" << std::endl;
		increment_indent();
		serialization_stream << indent << "num_serialization_information = _countof(serialization_information);" << std::endl;
		serialization_stream << indent << "return serialization_information;" << std::endl;
		decrement_indent();
		serialization_stream << indent << "}" << std::endl;
		serialization_stream << std::endl;
	}
	if (write_serialization_info_result == BCS_S_OK)
	{
		stream << serialization_stream.str();
	}
	else
	{
		stream << indent << "h_serialization_info const* " << high_level_structure_name << "::get_serialization_information(unsigned int& num_serialization_information)" << std::endl;
		stream << indent << "{" << std::endl;
		increment_indent();
		stream << indent << "num_serialization_information = 0;" << std::endl;
		stream << indent << "return nullptr;" << std::endl;
		decrement_indent();
		stream << indent << "}" << std::endl;
		stream << std::endl;
	}
	stream << indent << "h_member_info const* " << high_level_structure_name << "::get_member_information(unsigned int& num_member_information)" << std::endl;
	stream << indent << "{" << std::endl;
	increment_indent();
	stream << indent << "num_member_information = _countof(member_information);" << std::endl;
	stream << indent << "return member_information;" << std::endl;
	decrement_indent();
	stream << indent << "}" << std::endl;
	stream << std::endl;
	stream << indent << "h_pointer_to_member " << high_level_structure_name << "::pointer_to_members[1];" << std::endl;
	stream << indent << "h_pointer_to_member* " << high_level_structure_name << "::get_pointer_to_members_impl()" << std::endl;
	stream << indent << "{" << std::endl;
	increment_indent();
	stream << indent << "return pointer_to_members;" << std::endl;
	decrement_indent();
	stream << indent << "}" << std::endl;
	stream << std::endl;

	source = stream.str();
	for (size_t indent_index = 0; indent_index < source_indent_count; indent_index++) decrement_indent();
	return BCS_S_OK;
}

BCS_RESULT c_high_level_structure_type_container::generate_high_level_source_structure_fields(
	std::stringstream* stream,
	c_runtime_tag_struct_definition& struct_definition,
	c_runtime_tag_field_definition& field_definition,
	unsigned int runtime_field_index,
	unsigned int generated_field_index,
	const char* formatted_code_name)
{
	switch (field_definition.field_type)
	{
	case _field_vertex_buffer:
		return BCS_S_SKIP;
	default:
	{
		const char* field_source_type = c_high_level_tag_source_generator::field_type_to_high_level_source_type(engine_platform_build.platform_type, field_definition.field_type);
		if (field_source_type == nullptr)
		{
			return BCS_S_SKIP;
		}
	}
	case _field_pageable_resource:
	{
		*stream << "," << std::endl;
		*stream << indent << formatted_code_name << "(*this)";
	}
	break;
	case _field_array:
	case _field_struct:
	case _field_block:
	case _field_data:
	{
		*stream << "," << std::endl;
		*stream << indent << formatted_code_name << "(this)";
	}
	break;
	case _field_api_interop:
	case _field_tag_reference:
	case _field_embedded_tag:
	{
		*stream << "/*," << std::endl;
		*stream << indent << formatted_code_name << "(this)*/";
	}
	break;
	}
	return BCS_S_OK;
}

BCS_RESULT c_high_level_structure_type_container::generate_high_level_source_serialization_fields(
	std::stringstream* stream,
	c_runtime_tag_struct_definition& struct_definition,
	c_runtime_tag_field_definition& field_definition,
	unsigned int runtime_field_index,
	unsigned int generated_field_index,
	const char* formatted_code_name)
{
	switch (field_definition.field_type)
	{
	case _field_vertex_buffer:
		return BCS_S_SKIP;
	case _field_pad:
	case _field_skip:
	{
		*stream << indent << "{ " << get_namespace(_namespace_suffix_mode_suffix_semicolon) << struct_definition.symbol_name << ".fields[" << runtime_field_index << "]" << ", nullptr }," << std::endl;
	}
	break;
	case _field_api_interop:
	case _field_tag_reference:
	case _field_embedded_tag:
	{
		*stream << indent << "{ " << get_namespace(_namespace_suffix_mode_suffix_semicolon) << struct_definition.symbol_name << ".fields[" << runtime_field_index << "]" << ", /*reinterpret_cast<h_pointer_to_member>(&" << high_level_structure_name << "::" << formatted_code_name << ")*/ }," << std::endl;
	}
	break;
	case _field_block:
	case _field_struct:
	case _field_array:
	case _field_pageable_resource:
	case _field_data:
	{
		*stream << indent << "{ " << get_namespace(_namespace_suffix_mode_suffix_semicolon) << struct_definition.symbol_name << ".fields[" << runtime_field_index << "]" << ", reinterpret_cast<h_pointer_to_member>(&" << high_level_structure_name << "::" << formatted_code_name << ") }," << std::endl;
	}
	break;
	case _field_string_id:
	case _field_old_string_id:
	default:
		const char* field_source_type = c_high_level_tag_source_generator::field_type_to_high_level_source_type(engine_platform_build.platform_type, field_definition.field_type);
		if (field_source_type)
		{
			*stream << indent << "{ " << get_namespace(_namespace_suffix_mode_suffix_semicolon) << struct_definition.symbol_name << ".fields[" << runtime_field_index << "]" << ", reinterpret_cast<h_pointer_to_member>(&" << high_level_structure_name << "::" << formatted_code_name << ") }," << std::endl;
		}
		else
		{
			return BCS_S_SKIP;
		}
		break;
	}
	return BCS_S_OK;
}

BCS_RESULT c_high_level_structure_type_container::empty_field_iterator(
	std::stringstream* stream,
	c_runtime_tag_struct_definition& struct_definition,
	c_runtime_tag_field_definition& field_definition,
	unsigned int runtime_field_index,
	unsigned int generated_field_index,
	const char* formatted_code_name)
{

	switch (field_definition.field_type)
	{
	case _field_vertex_buffer:
		return BCS_S_SKIP;
	case _field_pad:
	case _field_skip:
	case _field_struct:
	case _field_block:
	case _field_tag_reference:
	case _field_embedded_tag:
	case _field_data:
	case _field_pageable_resource:
	case _field_api_interop:
	case _field_array:
	{
	}
	break;
	case _field_string_id:
	case _field_old_string_id:
	default:
		const char* field_source_type = c_high_level_tag_source_generator::field_type_to_high_level_source_type(engine_platform_build.platform_type, field_definition.field_type);
		if (field_source_type)
		{

		}
		else
		{
			return BCS_S_SKIP;
		}
		break;
	}
	return BCS_S_OK;
}

BCS_RESULT c_high_level_tag_source_generator::generate_high_level_header(unsigned int thread_index, unsigned int thread_count)
{
	std::stringstream stream;
	stream << "#pragma once" << std::endl;
	stream << std::endl;

	std::stringstream header_define_stream;
	header_define_stream << "high_level_" << get_engine_namespace(_namespace_suffix_mode_none) << "_" << get_platform_namespace(_namespace_suffix_mode_none);
	std::string header_define = header_define_stream.str();
	std::transform(header_define.begin(), header_define.end(), header_define.begin(), ::toupper);
	stream << "#define " << header_define << std::endl;
	stream << std::endl;

	begin_namespace_tree(stream, _namespace_tree_write_namespace);

	stream << indent << "static constexpr unsigned int global_vftable_index = " << global_vftable_index << ";" << std::endl;
	stream << indent << "BCS_SHARED extern h_high_level_function_table* local_vftables[];" << std::endl;
	stream << indent << "BCS_SHARED extern h_prototype* create_high_level_object(s_tag_struct_definition const& tag_struct_definition, h_prototype* copy_from_prototype);" << std::endl;
	stream << std::endl;

	for (c_runtime_tag_struct_definition* struct_definition : runtime_definitions.tag_struct_definitions)
	{
		iterate_struct_definitions(
			stream,
			*struct_definition,
			&c_high_level_structure_type_container::header,
			&c_high_level_structure_type_container::header_written);
	}

	stream << std::endl;
	end_namespace_tree(stream, _namespace_tree_write_namespace);

	std::string source_code = stream.str();
	if (!output_header_file_path.empty())
	{
		BCS_RESULT rs = write_output_with_logging(output_header_file_path.c_str(), source_code.data(), source_code.size());
		ASSERT(BCS_SUCCEEDED(rs));
	}

	return BCS_S_OK;
}

BCS_RESULT c_high_level_tag_source_generator::iterate_struct_definitions(
	std::stringstream& stream,
	c_runtime_tag_struct_definition& struct_definition,
	std::string c_high_level_structure_type_container::* string_member,
	bool c_high_level_structure_type_container::* written_member)
{
	c_high_level_structure_type_container* structure_type_container = structure_type_containers[&struct_definition];
	if (!(structure_type_container->*written_member))
	{
		structure_type_container->*written_member = true;

		t_string_list_value_unique_counter field_name_unique_counter;
		unsigned int field_index = 0;
		unsigned int version_hits = 0;
		for (t_blamtoozle_tag_field* blamtoozle_field_definition : struct_definition.fields)
		{
			if (version_hits > 0)
			{
				break; // #TODO
			}
			if (c_runtime_tag_field_definition* field_definition = dynamic_cast<c_runtime_tag_field_definition*>(blamtoozle_field_definition))
			{
				switch (field_definition->field_type)
				{
				case _field_block:
				{
					iterate_struct_definitions(
						stream,
						*field_definition->block_definition->struct_definition,
						string_member,
						written_member);
					debug_point;
				}
				break;
				case _field_array:
				{
					iterate_struct_definitions(
						stream,
						*field_definition->array_definition->struct_definition,
						string_member,
						written_member);
					debug_point;
				}
				break;
				case _field_struct:
				{
					iterate_struct_definitions(
						stream,
						*field_definition->struct_definition,
						string_member,
						written_member);
					debug_point;
				}
				break;
				}

				field_index++;
			}
		}

		stream << structure_type_container->*string_member;
	}

	return BCS_S_OK;
}

BCS_RESULT c_high_level_tag_source_generator::generate_high_level_source(unsigned int thread_index, unsigned int thread_count)
{
	std::stringstream stream;

	stream << "#include <highlevel-" << get_engine_namespace(_namespace_suffix_mode_none) << "-" << get_platform_namespace(_namespace_suffix_mode_none) << "-private-pch.h>" << std::endl;
	stream << std::endl;

	begin_namespace_tree(stream, _namespace_tree_write_namespace);

	for (c_runtime_tag_struct_definition* struct_definition : runtime_definitions.tag_struct_definitions)
	{
		iterate_struct_definitions(
			stream,
			*struct_definition,
			&c_high_level_structure_type_container::source,
			&c_high_level_structure_type_container::source_written);
	}

	if (runtime_definitions.tag_struct_definitions.empty())
	{
		stream << "#define HIGH_LEVEL_NO_OBJECT_CONSTRUCTORS" << std::endl;
	}
	else
	{
		for (c_runtime_tag_struct_definition* struct_definition : runtime_definitions.tag_struct_definitions)
		{
			std::string high_level_structure_name = format_structure_symbol(*struct_definition);
			stream << indent << "static h_prototype* " << high_level_structure_name << "_object_ctor(h_prototype* copy_from_prototype) { return copy_from_prototype ? new() " << high_level_structure_name << "(*high_level_cast<" << high_level_structure_name << "*>(copy_from_prototype)) : new() " << high_level_structure_name << "(); }" << std::endl;
		}
		stream << std::endl;

		stream << indent << "using t_create_high_level_object_ctor = h_prototype * (h_prototype* copy_from_prototype);" << std::endl;
		stream << indent << "struct s_object_ctor_pair" << std::endl;
		stream << indent << "{" << std::endl;
		increment_indent();
		stream << indent << "s_tag_struct_definition* tag_struct_definition;" << std::endl;
		stream << indent << "t_create_high_level_object_ctor* ctor;" << std::endl;
		decrement_indent();
		stream << indent << "};" << std::endl;
		stream << std::endl;

		stream << indent << "static s_object_ctor_pair object_ctors[] = " << std::endl;
		stream << indent << "{" << std::endl;
		for (c_runtime_tag_struct_definition* struct_definition : runtime_definitions.tag_struct_definitions)
		{
			std::string high_level_structure_name = format_structure_symbol(*struct_definition);
			stream << indent << "\t" << "{ &" << struct_definition->symbol_name << ", " << high_level_structure_name << "_object_ctor }," << std::endl;
		}
		stream << indent << "};" << std::endl;
		stream << std::endl;
	}
	stream << "#include <TagCodegen/high_level_object_constructor.inl>" << std::endl;
	if (runtime_definitions.tag_struct_definitions.empty())
	{
		stream << "#undef HIGH_LEVEL_NO_OBJECT_CONSTRUCTORS" << std::endl;
	}

	stream << std::endl;
	end_namespace_tree(stream, _namespace_tree_write_namespace);

	std::string source_code = stream.str();
	if (!output_source_file_path.empty())
	{
		BCS_RESULT rs = write_output_with_logging(output_source_file_path.c_str(), source_code.data(), source_code.size());
		ASSERT(BCS_SUCCEEDED(rs));
	}

	return BCS_S_OK;
}

BCS_RESULT c_high_level_tag_source_generator::generate_high_level_virtual(unsigned int thread_index, unsigned int thread_count)
{
	std::stringstream stream;

	stream << "#include <highlevel-" << get_engine_namespace(_namespace_suffix_mode_none) << "-" << get_platform_namespace(_namespace_suffix_mode_none) << "-private-pch.h>" << std::endl;
	stream << std::endl;

	begin_namespace_tree(stream, _namespace_tree_write_namespace);

	stream << indent << "h_high_level_function_table* local_vftables[" << local_vftable_count + 1 << "] =" << std::endl;
	stream << indent << "{" << std::endl;
	increment_indent();
	for (c_runtime_tag_struct_definition* struct_definition : runtime_definitions.tag_struct_definitions)
	{
		std::string high_level_structure_name = c_high_level_tag_source_generator::format_structure_symbol(*struct_definition);
		stream << indent << "&" << high_level_structure_name << "::vftable," << std::endl;
		//iterate_struct_definitions(
		//	stream,
		//	*struct_definition,
		//	&c_high_level_structure_type_container::source,
		//	&c_high_level_structure_type_container::source_written);
	}
	for (c_runtime_tag_struct_definition* struct_definition : runtime_definitions.tag_struct_definitions)
	{
		c_high_level_structure_type_container* structure_type_container = structure_type_containers[struct_definition];
		structure_field_iteartor(*struct_definition, &stream, this, &c_high_level_tag_source_generator::generate_high_level_virtual_fields);
	}
	stream << indent << "nullptr" << std::endl;
	decrement_indent();
	stream << indent << "};" << std::endl;

	stream << std::endl;
	end_namespace_tree(stream, _namespace_tree_write_namespace);

	std::string source_code = stream.str();
	if (!output_virtual_file_path.empty())
	{
		BCS_RESULT rs = write_output_with_logging(output_virtual_file_path.c_str(), source_code.data(), source_code.size());
		ASSERT(BCS_SUCCEEDED(rs));
	}

	return BCS_S_OK;
}

BCS_RESULT c_high_level_tag_source_generator::generate_high_level_virtual_fields(
	std::stringstream* stream,
	c_runtime_tag_struct_definition& struct_definition,
	c_runtime_tag_field_definition& field_definition,
	unsigned int runtime_field_index,
	unsigned int generated_field_index,
	const char* formatted_code_name)
{
	//stream << indent << "&" << high_level_structure_name << "::vftable," << std::endl;
	*stream << indent << "nullptr, // " << formatted_code_name << std::endl;
	return BCS_S_OK;
}

BCS_RESULT c_high_level_tag_source_generator::generate_high_level_natvis(unsigned int thread_index, unsigned int thread_count)
{
	std::stringstream stream;

	stream << indent << "<?xml version=\"1.0\" encoding=\"utf-8\"?>" << std::endl;
	stream << indent << "<AutoVisualizer xmlns=\"http://schemas.microsoft.com/vstudio/debugger/natvis/2010\">" << std::endl;
	increment_indent();
	stream << indent << "<Type Name=\"h_prototype\" Inheritable=\"false\">" << std::endl;

	increment_indent();
	stream << indent << "<Expand>" << std::endl;
	increment_indent();
	for (size_t struct_index = 0; struct_index < runtime_definitions.tag_struct_definitions.size(); struct_index++)
	{
		c_high_level_structure_type_container* type_container = _structure_type_containers[struct_index];
		structure_type_containers[&type_container->struct_definition] = type_container;
		//stream << indent << "<DisplayString Condition=\"__global_vftable_index==" << type_container->global_vftable_index << "&amp;&amp;__local_vftable_index==" << type_container->local_vftable_index << "\">{*(blofeld::eldorado::pc32::" << type_container->high_level_structure_name << "*)this}</DisplayString>" << std::endl;
		stream << indent << "<ExpandedItem Condition=\"__global_vftable_index==" << type_container->global_vftable_index << "&amp;&amp;__local_vftable_index==" << type_container->local_vftable_index << "\">*(blofeld::eldorado::pc32::" << type_container->high_level_structure_name << "*)this</ExpandedItem>" << std::endl;
	}
	decrement_indent();
	stream << indent << "</Expand>" << std::endl;
	decrement_indent();

	stream << indent << "</Type>" << std::endl;
	decrement_indent();
	stream << indent << "</AutoVisualizer>" << std::endl;

	std::string source_code = stream.str();
	if (!output_natvis_file_path.empty())
	{
		BCS_RESULT rs = write_output_with_logging(output_natvis_file_path.c_str(), source_code.data(), source_code.size());
		ASSERT(BCS_SUCCEEDED(rs));
	}

	return BCS_S_OK;
}

std::string c_high_level_tag_source_generator::format_structure_symbol(c_runtime_tag_struct_definition const& struct_definition)
{
	std::string low_level_type_name = struct_definition.type_name;
	if (strstr(low_level_type_name.c_str(), "s_") != low_level_type_name)
	{
		console_write_line("Warning: Structure symbol '%s' doesn't start with 's_' prefix [%s]", struct_definition.symbol_name.c_str(), low_level_type_name);
		std::string high_level_type_name = "h_";
		high_level_type_name += low_level_type_name;
		return high_level_type_name;
	}
	else
	{
		std::string high_level_type_name = low_level_type_name;
		high_level_type_name[0] = 'h';
		return high_level_type_name;
	}
}

const char* c_high_level_tag_source_generator::field_type_to_high_level_source_type(e_platform_type platform_type, e_field field_type)
{
	switch (field_type)
	{
	case _field_string:								return "c_fixed_string_32";
	case _field_long_string:						return "c_fixed_string_256";
	case _field_string_id:							return "h_string_id";
	case _field_old_string_id:						return "h_string_id";
	case _field_char_integer:						return "char";
	case _field_short_integer:						return "short";
	case _field_long_integer:						return "int32_t";
	case _field_int64_integer:						return "int64_t";
	case _field_angle:								return "angle";
	case _field_tag:								return "tag";
	case _field_char_enum:							return "char";
	case _field_short_enum:							return "short";
	case _field_long_enum:							return "int32_t";
	case _field_long_flags:							return "int32_t";
	case _field_word_flags:							return "word";
	case _field_byte_flags:							return "byte";
	case _field_point_2d:							return "s_point2d";
	case _field_rectangle_2d:						return "s_rectangle2d";
	case _field_rgb_color:							return "pixel32";
	case _field_argb_color:							return "pixel32";
	case _field_real:								return "real";
	case _field_real_slider:						return "real";
	case _field_real_fraction:						return "real_fraction";
	case _field_real_point_2d:						return "real_point2d";
	case _field_real_point_3d:						return "real_point3d";
	case _field_real_vector_2d:						return "real_vector2d";
	case _field_real_vector_3d:						return "real_vector3d";
	case _field_real_quaternion:					return "real_quaternion";
	case _field_real_euler_angles_2d:				return "real_euler_angles2d";
	case _field_real_euler_angles_3d:				return "real_euler_angles3d";
	case _field_real_plane_2d:						return "real_plane2d";
	case _field_real_plane_3d:						return "real_plane3d";
	case _field_real_rgb_color:						return "rgb_color";
	case _field_real_argb_color:					return "argb_color";
	case _field_real_hsv_color:						return "real_hsv_color";
	case _field_real_ahsv_color:					return "real_ahsv_color";
	case _field_short_integer_bounds:				return "short_bounds";
	case _field_angle_bounds:						return "angle_bounds";
	case _field_real_bounds:						return "real_bounds";
	case _field_real_fraction_bounds:				return "real_bounds";
	case _field_tag_reference:						return "h_tag_instance*";
	case _field_block:								return "h_block";
	case _field_long_block_flags:					return "int32_t";
	case _field_word_block_flags:					return "word";
	case _field_byte_block_flags:					return "byte";
	case _field_char_block_index:					return "char";
	case _field_char_block_index_custom_search:		return "char";
	case _field_short_block_index:					return "short";
	case _field_short_block_index_custom_search:	return "short";
	case _field_long_block_index:					return "int32_t";
	case _field_long_block_index_custom_search:		return "int32_t";
	case _field_data:								return "h_data";
	case _field_vertex_buffer:						return "s_tag_d3d_vertex_buffer";
	case _field_pad:								return nullptr;	// dynamic
	case _field_useless_pad:						return nullptr;	// dynamic
	case _field_skip:								return nullptr;	// dynamic
	case _field_non_cache_runtime_value:			return nullptr;	// empty
	case _field_explanation:						return nullptr;	// empty
	case _field_custom:								return nullptr;	// empty
	case _field_struct:								return nullptr;	// dynamic
	case _field_array:								return nullptr;	// dynamic
	case _field_pageable_resource:					return "h_resource*";
	case _field_api_interop:						return "h_interop*";
	case _field_terminator:							return nullptr;	// empty
	case _field_byte_integer:						return "byte";
	case _field_word_integer:						return "word";
	case _field_dword_integer:						return "dword";
	case _field_qword_integer:						return "qword";
	case _field_data_path:							return "c_fixed_string_256";
	case _field_embedded_tag:						return "h_tag_instance*";
	case _field_pointer:							return "int64_t";
	case _field_half:								return "short";
	default: FATAL_ERROR("Unknown field type");
	}
}
