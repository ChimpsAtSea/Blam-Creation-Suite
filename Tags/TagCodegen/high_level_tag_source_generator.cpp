#include "tagcodegen-private-pch.h"

using namespace blofeld;

c_high_level_tag_source_generator::c_high_level_tag_source_generator(e_engine_type engine_type, e_platform_type platform_type, e_build build) :
	engine_type(engine_type),
	platform_type(platform_type),
	build(build)
{

}

const blofeld::s_tag_group* c_high_level_tag_source_generator::get_tag_struct_tag_group(const blofeld::s_tag_struct_definition& tag_struct_definition)
{
	for (const s_tag_group** tag_group = tag_groups; *tag_group; tag_group++)
	{
		const s_tag_struct_definition& current_struct_definition = (*tag_group)->block_definition.struct_definition;

		if (&current_struct_definition == &tag_struct_definition)
		{
			return *tag_group;
		}
	}
	return nullptr;
}

void c_high_level_tag_source_generator::generate_header()
{
	std::stringstream stream;

	const char* namespace_name = engine_type_to_folder_name<const char*>(engine_type);

	stream << "#pragma once" << std::endl;
	stream << std::endl;
	stream << std::endl;

	stream << "namespace blofeld" << std::endl;
	stream << "{" << std::endl;
	stream << "\tnamespace " << namespace_name << std::endl;
	stream << "\t{" << std::endl << std::endl;

	std::map<std::string, int> field_name_unique_counter;
	for (const s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions)
	{
		const s_tag_group* tag_group = get_tag_struct_tag_group(*tag_struct_definition);

		stream << "\t\t" << "class c_" << tag_struct_definition->name << " : " << std::endl;
		if (tag_group != nullptr)
		{
			stream << "\t\t\t" << "public c_high_level_tag" << std::endl;
		}
		else
		{
			stream << "\t\t\t" << "public c_high_level_type" << std::endl;
		}
		stream << "\t\t" << "{" << std::endl;
		stream << "\t\t\t" << "public:" << std::endl;
		if (tag_group != nullptr)
		{
			stream << "\t\t\t\t" << "c_" << tag_struct_definition->name << "(const char* tag_filepath);" << std::endl;
			stream << "\t\t\t\t" << "c_" << tag_struct_definition->name << "(c_high_level_type& parent);" << std::endl;
		}
		else
		{
			stream << "\t\t\t\t" << "c_" << tag_struct_definition->name << "();" << std::endl;
		}
		stream << std::endl;

		stream << "\t\t\t\t" << "virtual void* get_field_pointer(const blofeld::s_tag_field& field) final;" << std::endl;
		stream << std::endl;

		for (const s_tag_field* current_field = tag_struct_definition->fields; current_field->field_type != _field_terminator; current_field++)
		{
			uint32_t field_skip_count;
			if (skip_tag_field_version(*current_field, engine_type, platform_type, build, field_skip_count))
			{
				current_field += field_skip_count;
				continue;
			}

			c_blamlib_string_parser field_formatter = c_blamlib_string_parser(current_field->name, current_field->field_type == blofeld::_field_block, &field_name_unique_counter);

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
				continue;
			}

			switch (current_field->field_type)
			{
			case _field_array:
			{
				const char* field_source_type = current_field->array_definition->struct_definition.name;
				stream << "\t\t\t\t" << "c_" << field_source_type << " (" << field_formatter.code_name.c_str() << ")[" << current_field->array_definition->count(engine_type) << "];";
				break;
			}
			case _field_struct:
			{
				const char* field_source_type = current_field->struct_definition->name;
				stream << "\t\t\t\t" << "c_" << field_source_type << " " << field_formatter.code_name.c_str() << ";";
				break;
			}
			case _field_block:
			{
				const char* field_source_type = current_field->block_definition->struct_definition.name;
				stream << "\t\t\t\t" << "std::vector<c_" << field_source_type << "> " << field_formatter.code_name.c_str() << ";";
				break;
			}
			case _field_tag_reference:
			{
				stream << "\t\t\t\t" << "c_high_level_tag* " << field_formatter.code_name.c_str() << ";";
				break;
			}
			default:
			{
				const char* field_source_type = c_tag_source_generator::field_type_to_high_level_source_type(platform_type, current_field->field_type);
				ASSERT(field_source_type != nullptr);
				stream << "\t\t\t\t" << field_source_type << " " << field_formatter.code_name.c_str() << ";";
			}
			}
			stream << std::endl;

		}
		field_name_unique_counter.clear();

		stream << "\t\t" << "};" << std::endl;

		stream << std::endl;
	}

	stream << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	stream << std::endl << "} // end namespace blofeld" << std::endl;

	std::string source_code = stream.str();
	std::string output_filepath = c_command_line::get_command_line_arg("-output") + namespace_name + "/" + namespace_name + "_high_level.h";
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

void c_high_level_tag_source_generator::generate_tag_constructor_params(std::stringstream& stream, const s_tag_struct_definition& tag_struct_definition)
{
	std::map<std::string, int> field_name_unique_counter;
	for (const s_tag_field* current_field = tag_struct_definition.fields; current_field->field_type != _field_terminator; current_field++)
	{
		uint32_t field_skip_count;
		if (skip_tag_field_version(*current_field, engine_type, platform_type, build, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		c_blamlib_string_parser field_formatter = c_blamlib_string_parser(current_field->name, current_field->field_type == blofeld::_field_block, &field_name_unique_counter);

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
			continue;
		}


		switch (current_field->field_type)
		{
		case _field_array:
		{
			const s_tag_group* tag_group = get_tag_struct_tag_group(current_field->array_definition->struct_definition);

			const char* field_source_type = current_field->array_definition->struct_definition.name;
			if (tag_group)
			{
				stream << "#NOTIMPLEMENTED" << std::endl;
				// stream << "\t\t\t\t, " << field_formatter.code_name.c_str() << "(*this)" << std::endl;
			}
			else
			{
				stream << "\t\t\t\t, " << field_formatter.code_name.c_str() << "()" << std::endl;
			}
			
			break;
		}
		case _field_struct:
		{
			const s_tag_group* tag_group = get_tag_struct_tag_group(*current_field->struct_definition);

			const char* field_source_type = current_field->struct_definition->name;
			if (tag_group)
			{
				stream << "\t\t\t\t, " << field_formatter.code_name.c_str() << "(*this)" << std::endl;
			}
			else
			{
				stream << "\t\t\t\t, " << field_formatter.code_name.c_str() << "()" << std::endl;
			}

			break;
		}
		default:
		{
			stream << "\t\t\t\t, " << field_formatter.code_name.c_str() << "()" << std::endl;
			break;
		}
		}
	}
}

void c_high_level_tag_source_generator::generate_source()
{
	std::stringstream stream;

	const char* namespace_name = engine_type_to_folder_name<const char*>(engine_type);

	stream << "#include <tagreflection-private-pch.h>" << std::endl;
	stream << std::endl;

	stream << "#pragma warning(disable : 4065)" << std::endl;
	stream << "#pragma warning(error : 4172)" << std::endl;
	stream << std::endl;

	stream << "namespace blofeld" << std::endl;
	stream << "{" << std::endl;
	stream << "\tnamespace " << namespace_name << std::endl;
	stream << "\t{" << std::endl << std::endl;

	std::map<std::string, int> field_name_unique_counter;
	for (const s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions)
	{
		const s_tag_group* tag_group = get_tag_struct_tag_group(*tag_struct_definition);

		
		if (tag_group != nullptr)
		{
			stream << "\t\t" << "c_" << tag_struct_definition->name << "::c_" << tag_struct_definition->name;
			stream << "(const char* tag_filepath) :" << std::endl;
			stream << "\t\t\t" << "c_high_level_tag(" << tag_struct_definition->symbol->symbol_name << ", tag_filepath, nullptr, " << tag_group->name << "_group)" << std::endl;
			generate_tag_constructor_params(stream, *tag_struct_definition);
			stream << "\t\t" << "{" << std::endl;
			stream << "\t\t\t" << "high_level_tag_ctor(this);" << std::endl;
			stream << "\t\t" << "}" << std::endl;
			stream << std::endl;

			stream << "\t\t" << "c_" << tag_struct_definition->name << "::c_" << tag_struct_definition->name;
			stream << "(c_high_level_type& parent) :" << std::endl;
			stream << "\t\t\t" << "c_high_level_tag(" << tag_struct_definition->symbol->symbol_name << ", nullptr, &parent, " << tag_group->name << "_group)" << std::endl;
			generate_tag_constructor_params(stream, *tag_struct_definition);
			stream << "\t\t" << "{" << std::endl;
			stream << "\t\t\t" << "high_level_tag_ctor(this);" << std::endl;
			stream << "\t\t" << "}" << std::endl;
			stream << std::endl;
		}
		else
		{
			stream << "\t\t" << "c_" << tag_struct_definition->name << "::c_" << tag_struct_definition->name;
			stream << "() :" << std::endl;
			stream << "\t\t\t" << "c_high_level_type(" << tag_struct_definition->symbol->symbol_name << ")" << std::endl;
			generate_tag_constructor_params(stream, *tag_struct_definition);
			stream << "\t\t" << "{" << std::endl;
			stream << "\t\t\t" << "high_level_tag_ctor(this);" << std::endl;
			stream << "\t\t" << "}" << std::endl;
		}

		stream << std::endl;

		stream << "\t\t" << "void* c_" << tag_struct_definition->name << "::get_field_pointer(const blofeld::s_tag_field& field)" << std::endl;
		stream << "\t\t{" << std::endl;
		stream << "\t\t\tuintptr_t const _field_address = reinterpret_cast<uintptr_t>(&field);" << std::endl;
		stream << "\t\t\tuintptr_t const _fields_address = reinterpret_cast<uintptr_t>(struct_definition.fields);" << std::endl;
		stream << "\t\t\tuintptr_t const _bytes_offset = field_address - fields_address;" << std::endl;
		stream << "\t\t\tuintptr_t const _index = bytes_offset / sizeof(blofeld::s_tag_field);" << std::endl;
		stream << std::endl;
		stream << "\t\t\tswitch (_index)" << std::endl;
		stream << "\t\t\t{" << std::endl;


		field_name_unique_counter.clear();
		uint32_t field_index = 0;
		for (const s_tag_field* current_field = tag_struct_definition->fields; current_field->field_type != _field_terminator; current_field++, field_index++)
		{
			uint32_t field_skip_count;
			if (skip_tag_field_version(*current_field, engine_type, platform_type, build, field_skip_count))
			{
				current_field += field_skip_count;
				continue;
			}

			c_blamlib_string_parser field_formatter = c_blamlib_string_parser(current_field->name, current_field->field_type == blofeld::_field_block, &field_name_unique_counter);

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
				continue;
			}

			stream << "\t\t\t\tcase " << field_index << ": return &" << field_formatter.code_name.c_str() << ";" << std::endl;
		}
		stream << "\t\t\t\tdefault: return nullptr;" << std::endl;

		stream << "\t\t\t}" << std::endl;
		stream << std::endl;

		stream << "\t\t}" << std::endl;
		stream << std::endl;


	}

	stream << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	stream << std::endl << "} // end namespace blofeld" << std::endl;

	std::string source_code = stream.str();
	std::string output_filepath = c_command_line::get_command_line_arg("-output") + namespace_name + "/" + namespace_name + "_high_level.cpp";
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
