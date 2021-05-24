#include "tagcodegen-private-pch.h"

using namespace blofeld;

c_virtual_tag_source_generator::c_virtual_tag_source_generator(s_engine_platform_build engine_platform_build) :
	engine_platform_build(engine_platform_build)
{

}

void c_virtual_tag_source_generator::generate_header() const
{
	std::stringstream stream;

	const char* namespace_name;
	BCS_RESULT engine_type_to_folder_name_result = get_engine_type_folder_string(engine_platform_build.engine_type, &namespace_name);
	ASSERT(BCS_SUCCEEDED(engine_type_to_folder_name_result));

	stream << "#pragma once" << std::endl;
	stream << std::endl;
	stream << std::endl;

	stream << "namespace blofeld" << std::endl;
	stream << "{" << std::endl;
	stream << "\tnamespace " << namespace_name << std::endl;
	stream << "\t{" << std::endl << std::endl;

	stream << "\t\tc_virtual_tag_interface* create_virtual_tag_interface(c_tag_interface& tag_interface, unsigned long group_tag);" << std::endl << std::endl;

	stream << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	stream << std::endl << "} // end namespace blofeld" << std::endl;

	std::map<std::string, int> field_name_unique_counter;
	for (const s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		stream << "\t\t" << "template<>" << std::endl;
		stream << "\t\t" << "class v_tag_interface<blofeld::" << namespace_name << "::s_" << tag_struct_definition->name << "> : " << std::endl;
		stream << "\t\t\t" << "public c_virtual_tag_interface" << std::endl;
		stream << "\t\t" << "{" << std::endl;
		stream << "\t\t\t" << "public:" << std::endl;
		stream << "\t\t\t" << "v_tag_interface(c_tag_interface& tag_interface);" << std::endl;
		stream << std::endl;

		for (const s_tag_field* current_field = tag_struct_definition->fields; current_field->field_type != _field_terminator; current_field++)
		{
			uint32_t field_skip_count;
			if (skip_tag_field_version(*current_field, engine_platform_build, field_skip_count))
			{
				current_field += field_skip_count;
				continue;
			}

			std::map<std::string, int>* field_name_unique_counter_ptr = nullptr;
			switch (current_field->field_type)
			{
			case _field_custom:
				break;
			default:
				field_name_unique_counter_ptr = &field_name_unique_counter;
				break;
			}

			c_blamlib_string_parser field_formatter = c_blamlib_string_parser(current_field->name, current_field->field_type == blofeld::_field_block, field_name_unique_counter_ptr);

			if (current_field->field_type > _field_type_non_standard)
			{
				continue;
			}

			switch (current_field->field_type)
			{
			case _field_pad:
			case _field_skip:
			case _field_useless_pad:
			case _field_custom:
			case _field_terminator:
			case _field_explanation:
			case _field_non_cache_runtime_value:
				continue;
			}

			switch (current_field->field_type)
			{
			case _field_array:
			{
				const char* field_source_type = current_field->array_definition->struct_definition.name;
				stream << "\t\t\t\t" << "blofeld::" << namespace_name << "::s_" << field_source_type << " (&" << field_formatter.code_name.c_str() << ")[" << current_field->array_definition->count(engine_platform_build) << "];";
				break;
			}
			case _field_struct:
			{
				const char* field_source_type = current_field->struct_definition->name;
				stream << "\t\t\t\t" << "blofeld::" << namespace_name << "::s_" << field_source_type << "& " << field_formatter.code_name.c_str() << ";";
				break;
			}
			case _field_block:
			{
				const char* field_source_type = current_field->block_definition->struct_definition.name;
				stream << "\t\t\t\t" << "c_virtual_tag_block<blofeld::" << namespace_name << "::s_" << field_source_type << "> " << field_formatter.code_name.c_str() << ";";
				break;
			}
			case _field_tag_reference:
			{
				stream << "\t\t\t\t" << "c_virtual_tag " << field_formatter.code_name.c_str() << ";";
				break;
			}
			case _field_char_enum:
			{
				const blofeld::s_string_list_definition& string_list = *current_field->string_list_definition;
				stream << "\t\t\t" << "c_enum<blofeld::" << namespace_name << "::e_" << string_list.name << ", char> " << field_formatter.code_name.data << ";";
				break;
			}
			case _field_enum:
			{
				const blofeld::s_string_list_definition& string_list = *current_field->string_list_definition;
				stream << "\t\t\t" << "c_enum<blofeld::" << namespace_name << "::e_" << string_list.name << ", short> " << field_formatter.code_name.data << ";";
				break;
			}
			case _field_long_enum:
			{
				const blofeld::s_string_list_definition& string_list = *current_field->string_list_definition;
				stream << "\t\t\t" << "c_enum<blofeld::" << namespace_name << "::e_" << string_list.name << ", long> " << field_formatter.code_name.data << ";";
				break;
			}
			default:
			{
				const char* field_source_type = c_low_level_tag_source_generator::field_type_to_low_level_source_type(engine_platform_build.platform_type, current_field->field_type);
				ASSERT(field_source_type != nullptr);
				stream << "\t\t\t\t" << field_source_type << "& " << field_formatter.code_name.c_str() << ";";
			}
			}
			stream << std::endl;

		}
		field_name_unique_counter.clear();

		stream << "\t\t" << "};" << std::endl;

		stream << std::endl;
	}


	std::string source_code = stream.str();
	std::string output_filepath = c_command_line::get_command_line_arg("-output") + "Virtual/virtual_" + namespace_name + "/" + namespace_name + "_virtual.h";
	bool write_output = true;
	size_t existing_file_size;
	const char* existing_file_data;
	if (filesystem_read_file_to_memory(output_filepath.c_str(), &existing_file_data, &existing_file_size))
	{
		if (source_code.size() == existing_file_size && strncmp(existing_file_data, source_code.c_str(), existing_file_size) == 0)
		{
			write_output = false;
		}
		delete[] existing_file_data;
	}

	if (write_output)
	{
		bool filesystem_write_file_from_memory_result = filesystem_write_file_from_memory(output_filepath.c_str(), source_code.data(), source_code.size());
		ASSERT(filesystem_write_file_from_memory_result);
	}
}

void c_virtual_tag_source_generator::generate_source() const
{
	std::stringstream stream;
	
	const char* namespace_name;
	BCS_RESULT engine_type_to_folder_name_result = get_engine_type_folder_string(engine_platform_build.engine_type, &namespace_name);
	ASSERT(BCS_SUCCEEDED(engine_type_to_folder_name_result));

	const char* source_namespace_name;
	BCS_RESULT engine_type_to_folder_name_result2 = get_engine_type_source_string(engine_platform_build.engine_type, &source_namespace_name);
	ASSERT(BCS_SUCCEEDED(engine_type_to_folder_name_result2));

	stream << "#include <virtual-" << source_namespace_name << "-private-pch.h>" << std::endl << std::endl;

	stream << "namespace blofeld" << std::endl;
	stream << "{" << std::endl;
	stream << "\tnamespace " << namespace_name << std::endl;
	stream << "\t{" << std::endl << std::endl;


	stream << "\t\tc_virtual_tag_interface* create_virtual_tag_interface(c_tag_interface& tag_interface, unsigned long group_tag)" << std::endl;
	stream << "\t\t{" << std::endl;

	stream << "\t\t\t" << "switch (group_tag)" << std::endl;
	stream << "\t\t\t" << "{" << std::endl;

	for (const s_tag_group** tag_group = tag_groups[engine_platform_build.engine_type]; *tag_group; tag_group++)
	{
		c_fixed_string_128 tag_group_name = (*tag_group)->name;
		tag_group_name += "_TAG";
		tag_group_name.uppercase();

		const s_tag_struct_definition& tag_struct_definition = (*tag_group)->block_definition.struct_definition;

		stream << "\t\t\t" << "case " << tag_group_name.data << ": return new v_tag_interface<s_" << tag_struct_definition.name << ">(tag_interface);" << std::endl;

	}

	stream << "\t\t\t" << "}" << std::endl << std::endl;

	stream << "\t\t\treturn nullptr;" << std::endl << std::endl;
	stream << "\t\t}" << std::endl;


	stream << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	stream << std::endl << "} // end namespace blofeld" << std::endl;
	stream << std::endl;
	stream << std::endl;

	std::map<std::string, int> field_name_unique_counter;
	for (const s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions[engine_platform_build.engine_type])
	{
		//hs << "\t\t" << "template<>" << std::endl;
		//hs << "\t\t" << "class v_tag_interface<s_" << tag_struct_definition->name << "> : " << std::endl;
		//hs << "\t\t\t" << "public c_virtual_tag_interface" << std::endl;
		//hs << "\t\t" << "{" << std::endl;
		//hs << "\t\t\t" << "public:" << std::endl;
		stream << "" << "v_tag_interface<blofeld::" << namespace_name<< "::s_" << tag_struct_definition->name << ">::v_tag_interface(c_tag_interface& tag_interface) : " << std::endl;
		stream << "\t" << "c_virtual_tag_interface(tag_interface)";

		for (const s_tag_field* current_field = tag_struct_definition->fields; current_field->field_type != _field_terminator; current_field++)
		{
			uint32_t field_skip_count;
			if (skip_tag_field_version(*current_field, engine_platform_build, field_skip_count))
			{
				current_field += field_skip_count;
				continue;
			}

			std::map<std::string, int>* field_name_unique_counter_ptr = nullptr;
			switch (current_field->field_type)
			{
			case _field_custom:
				break;
			default:
				field_name_unique_counter_ptr = &field_name_unique_counter;
				break;
			}

			c_blamlib_string_parser field_formatter = c_blamlib_string_parser(current_field->name, current_field->field_type == blofeld::_field_block, field_name_unique_counter_ptr);

			switch (current_field->field_type)
			{
			case _field_pad:
			case _field_skip:
			case _field_useless_pad:
			case _field_custom:
			case _field_terminator:
			case _field_explanation:
			case _field_non_cache_runtime_value:
				continue;
			default:
				stream << "," << std::endl;
				break;
			}

			switch (current_field->field_type)
			{
			case _field_block:
			case _field_tag_reference:
				stream << "\t" << field_formatter.code_name.c_str() << "(tag_interface, tag_interface.get_data<blofeld::" << namespace_name << "::s_" << tag_struct_definition->name << ">()->" << field_formatter.code_name.c_str() << ")";
				break;
			default:
				stream << "\t" << field_formatter.code_name.c_str() << "(tag_interface.get_data<blofeld::" << namespace_name << "::s_" << tag_struct_definition->name << ">()->" << field_formatter.code_name.c_str() << ")";
				break;
			}
		}
		field_name_unique_counter.clear();

		stream << std::endl;
		stream << "" << "{ }";
		stream << std::endl;

		stream << std::endl;
	}

	std::string source_code = stream.str();
	std::string output_filepath = c_command_line::get_command_line_arg("-output") + "Virtual/virtual_" + namespace_name + "/" + namespace_name + "_virtual.cpp";
	bool write_output = true;
	size_t existing_file_size;
	const char* existing_file_data;
	if(filesystem_read_file_to_memory(output_filepath.c_str(), &existing_file_data, &existing_file_size))
	{
		if (source_code.size() == existing_file_size && strncmp(existing_file_data, source_code.c_str(), existing_file_size) == 0)
		{
			write_output = false;
		}
		delete[] existing_file_data;
	}

	if (write_output)
	{
		bool filesystem_write_file_from_memory_result = filesystem_write_file_from_memory(output_filepath.c_str(), source_code.data(), source_code.size());
		ASSERT(filesystem_write_file_from_memory_result);
	}
}
