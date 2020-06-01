#include "tagcodegen-private-pch.h"
#include "virtual_tag_source_generator.h"

c_virtual_tag_source_generator::c_virtual_tag_source_generator(e_engine_type engine_type) :
	engine_type(engine_type)
{

}

void c_virtual_tag_source_generator::generate_header()
{
	std::stringstream hs;

	const char* namespace_name = engine_type_to_folder_name<const char*>(engine_type);

	hs << std::endl;
	hs << std::endl;

	hs << "namespace blofeld" << std::endl;
	hs << "{" << std::endl;
	hs << "\tnamespace " << namespace_name << std::endl;
	hs << "\t{" << std::endl << std::endl;



	//hs << "\t\t" << "class c_cache_file;" << std::endl << std::endl;
	//hs << "\t\t" << "class c_tag_interface { public: c_tag_interface(c_cache_file&, uint16_t tag_index); template<typename T> T* get_data(); };" << std::endl << std::endl;
	//hs << "\t\t" << "template<typename t_value> class c_virtual_tag_block { public: c_virtual_tag_block(c_cache_file& cache_file, c_tag_interface& tag_interface, c_typed_tag_block<t_value>& tag_block); };" << std::endl << std::endl;
	//hs << "\t\t" << "class c_virtual_tag_interface { public: c_virtual_tag_interface(c_cache_file& cache_file, c_tag_interface& tag_interface, s_tag_reference& tag_reference); };" << std::endl << std::endl;


	hs << "\t\t" << "template<typename T>" << std::endl;
	hs << "\t\t" << "class v_tag_interface :" << std::endl;
	hs << "\t\t" << "\tpublic c_tag_interface" << std::endl;
	hs << "\t\t" << "{" << std::endl;
	hs << "\t\t" << "};" << std::endl << std::endl;

	hs << "\t\tc_tag_interface* create_tag_interface(c_cache_file& cache_file, uint16_t tag_index, unsigned long group_tag);" << std::endl << std::endl;

	std::map<std::string, int> field_name_unique_counter;
	for (const blofeld::s_tag_struct_definition* tag_struct_definition : c_structure_relationship_node::sorted_tag_struct_definitions)
	{
		hs << "\t\t" << "template<>" << std::endl;
		hs << "\t\t" << "class v_tag_interface<s_" << tag_struct_definition->name << "> : " << std::endl;
		hs << "\t\t\t" << "public c_tag_interface" << std::endl;
		hs << "\t\t" << "{" << std::endl;
		hs << "\t\t\t" << "public:" << std::endl;
		hs << "\t\t\t" << "v_tag_interface(c_cache_file& cache_file, uint16_t tag_index) : " << std::endl;
		hs << "\t\t\t\t" << "c_tag_interface(cache_file, tag_index)";

		for(const blofeld::s_tag_field* current_field = tag_struct_definition->fields; current_field->field_type != blofeld::_field_terminator; current_field++)
		{
			c_field_formatter field_formatter = c_field_formatter(current_field, current_field->name, field_name_unique_counter);

			switch (current_field->field_type)
			{
			case blofeld::_field_pad:
			case blofeld::_field_skip:
			case blofeld::_field_useless_pad:
			case blofeld::_field_custom:
			case blofeld::_field_terminator:
			case blofeld::_field_explanation:
				continue;
			default:
				hs << "," << std::endl;
				break;
			}

			switch (current_field->field_type)
			{
			case blofeld::_field_block:
			case blofeld::_field_tag_reference:
				hs << "\t\t\t\t" << field_formatter.code_name << "(cache_file, *this, get_data<s_" << tag_struct_definition->name << ">()->" << field_formatter.code_name << ")";
				break;
			default:
				hs << "\t\t\t\t" << field_formatter.code_name << "(get_data<s_" << tag_struct_definition->name << ">()->" << field_formatter.code_name << ")";
				break;
			}
		}
		field_name_unique_counter.clear();
		hs << std::endl;
		hs << "\t\t\t\t" << "{ }";
		hs << std::endl;
		hs << std::endl;

		for (const blofeld::s_tag_field* current_field = tag_struct_definition->fields; current_field->field_type != blofeld::_field_terminator; current_field++)
		{
			c_field_formatter field_formatter = c_field_formatter(current_field, current_field->name, field_name_unique_counter);

			switch (current_field->field_type)
			{
			case blofeld::_field_pad:
			case blofeld::_field_skip:
			case blofeld::_field_useless_pad:
			case blofeld::_field_custom:
			case blofeld::_field_terminator:
			case blofeld::_field_explanation:
				continue;
			}

			switch (current_field->field_type)
			{
			case blofeld::_field_array:
			{
				const char* field_source_type = current_field->array_definition->struct_definition.name;
				hs << "\t\t\t\t" << "s_" << field_source_type << " (&" << field_formatter.code_name << ")[" << current_field->array_definition->count << "];";
				break;
			}
			case blofeld::_field_struct:
			{
				const char* field_source_type = current_field->struct_definition->name;
				hs << "\t\t\t\t" << "s_" << field_source_type << "& " << field_formatter.code_name << ";";
				break;
			}
			case blofeld::_field_block:
			{
				const char* field_source_type = current_field->block_definition->struct_definition.name;
				hs << "\t\t\t\t" << "c_virtual_tag_block<s_" << field_source_type << "> " << field_formatter.code_name << ";";
				break;
			}
			case blofeld::_field_tag_reference:
			{
				hs << "\t\t\t\t" << "c_virtual_tag_interface " << field_formatter.code_name << ";";
				break;
			}
			default:
			{			
				const char* field_source_type = c_tag_source_generator::field_type_to_source_type(current_field->field_type);
				ASSERT(field_source_type != nullptr);
				hs << "\t\t\t\t" << field_source_type << "& " << field_formatter.code_name << ";";
			}
			}
			hs << std::endl;

		}
		field_name_unique_counter.clear();

	hs << "\t\t" << "};" << std::endl;

	hs << std::endl;

	debug_point;

	}

	hs << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	hs << std::endl << "} // end namespace blofeld" << std::endl;

	std::string source_code = hs.str();
	std::string output_filepath = c_command_line::get_command_line_arg("-output") + namespace_name + "_virtual.h";
	bool filesystem_write_file_from_memory_result = filesystem_write_file_from_memory(output_filepath.c_str(), source_code.data(), source_code.size());
	ASSERT(filesystem_write_file_from_memory_result);
}

void c_virtual_tag_source_generator::generate_source()
{
	std::stringstream ss;

	const char* namespace_name = engine_type_to_folder_name<const char*>(engine_type);

	ss << "#include <tagreflection-private-pch.h>" << std::endl << std::endl;

	ss << "namespace blofeld" << std::endl;
	ss << "{" << std::endl;
	ss << "\tnamespace " << namespace_name << std::endl;
	ss << "\t{" << std::endl << std::endl;


	ss << "\t\tc_tag_interface* create_tag_interface(c_cache_file& cache_file, uint16_t tag_index, unsigned long group_tag)" << std::endl;
	ss << "\t\t{" << std::endl;

	ss << "\t\t\t" << "switch (group_tag)" << std::endl;
	ss << "\t\t\t" << "{" << std::endl;

	std::map<std::string, int> field_name_unique_counter;
	for (const blofeld::s_tag_group* tag_group : blofeld::tag_groups)
	{
		c_fixed_string_128 tag_group_name = tag_group->name;
		tag_group_name += "_TAG";
		tag_group_name.uppercase();

		const blofeld::s_tag_struct_definition& tag_struct_definition = tag_group->block_definition.struct_definition;

		ss << "\t\t\t" << "case " << tag_group_name.data << ": return new v_tag_interface<s_" << tag_struct_definition.name << ">(cache_file, tag_index);" << std::endl;

		debug_point;

	}

	ss << "\t\t\t" << "}" << std::endl << std::endl;

	ss << "\t\t\treturn nullptr;" << std::endl << std::endl;
	ss << "\t\t}" << std::endl;

	ss << std::endl << "\t} // end namespace " << namespace_name << std::endl;
	ss << std::endl << "} // end namespace blofeld" << std::endl;

	std::string source_code = ss.str();
	std::string output_filepath = c_command_line::get_command_line_arg("-output") + namespace_name + "_virtual.cpp";
	bool filesystem_write_file_from_memory_result = filesystem_write_file_from_memory(output_filepath.c_str(), source_code.data(), source_code.size());
	ASSERT(filesystem_write_file_from_memory_result);
}
