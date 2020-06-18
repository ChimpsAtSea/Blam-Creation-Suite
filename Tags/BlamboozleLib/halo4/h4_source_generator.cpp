#include "blamboozlelib-private-pch.h"

std::string escape_string(std::string str)
{
	std::string result;
	result.reserve(str.size() * 2); // worst case scenario

	const char* current_pos = str.data();
	while (*current_pos)
	{
		char ch = *current_pos;

		if (ch == '\r' && current_pos[1] == '\n') {}
		else
		{
			switch (ch)
			{
			case '\'': result += "\\'"; break;
			case '\"': result += "\\\""; break;
			case '\?': result += "\\?"; break;
			case '\\': result += "\\\\"; break;
			case '\a': result += "\\a"; break;
			case '\b': result += "\\b"; break;
			case '\f': result += "\\f"; break;
			case '\n': result += "\\n"; break;
			case '\r': result += "\\r"; break;
			case '\t': result += "\\t"; break;
			case '\v': result += "\\v"; break;
			default: result += ch; break;
			}
		}

		current_pos++;
	}

	return result;
}

c_h4_source_generator::c_h4_source_generator(c_h4_blamboozle& blamboozle, c_h4_generator_preprocessor& preprocessor) :
	blamboozle(blamboozle),
	preprocessor(preprocessor)
{
	for (c_h4_source_file* source_file : preprocessor.source_files)
	{
		std::stringstream& hs = source_file->header_stream;
		std::stringstream& ss = source_file->source_stream;

		hs << "#pragma once" << std::endl << std::endl;
		ss << "#include <tagdefinitions-private-pch.h>" << std::endl;
		ss << "#include <blofeld_field_type_override.h>" << std::endl << std::endl;

		hs << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;
		ss << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;

		for (c_h4_tag_group_container* group_container : source_file->tag_groups)
		{
			create_tag_group_header(hs, *group_container);
			create_tag_group_source(ss, *group_container);
		}
		if (!source_file->tag_groups.empty()) hs << std::endl;

		uint32_t num_tag_blocks = 0;
		for (c_h4_tag_block_container* tag_block_container : source_file->tag_blocks)
		{
			if (tag_block_container->defined_by_tag_group) continue; // these are created manually through c_h4_tag_group_container
			if (tag_block_container->tag_block.is_block)
			{
				num_tag_blocks++;
				create_tag_block_header(hs, *tag_block_container);
				create_tag_block_source(ss, *tag_block_container);
			}
		}
		if (num_tag_blocks > 0) hs << std::endl;

		uint32_t num_tag_arrays = 0;
		for (c_h4_tag_block_container* tag_block_container : source_file->tag_blocks)
		{
			if (tag_block_container->defined_by_tag_group) continue; // these are created manually through c_h4_tag_group_container
			if (tag_block_container->tag_block.is_array)
			{
				num_tag_blocks++;
				create_tag_array_header(hs, *tag_block_container);
				create_tag_array_source(ss, *tag_block_container);
			}
		}
		if (num_tag_arrays > 0) hs << std::endl;

		for (c_h4_tag_struct_container* tag_struct_container : source_file->tag_structs)
		{
			if (tag_struct_container->is_block) continue; // these are created manually through c_h4_tag_block_container
			create_tag_struct_header(hs, *tag_struct_container);
			create_tag_struct_source(ss, *tag_struct_container);
		}
		if (!source_file->tag_structs.empty()) hs << std::endl;

		for (c_h4_tag_enum_container* tag_enum_container : source_file->tag_enums)
		{
			create_tag_enum_header(hs, *tag_enum_container);
			create_tag_enum_source(ss, *tag_enum_container, source_file->is_header);
		}
		if (!source_file->tag_enums.empty()) hs << std::endl;

		for (c_h4_tag_reference_container* tag_reference_container : source_file->tag_references)
		{
			create_tag_reference_header(hs, *tag_reference_container);
			create_tag_reference_source(ss, *tag_reference_container);
		}
		if(!source_file->tag_references.empty()) hs << std::endl;

		hs << "} // namespace blofeld" << std::endl << std::endl;
		ss << "} // namespace blofeld" << std::endl << std::endl;
	}

	for (c_h4_source_file* source_file : preprocessor.source_files)
	{
		std::stringstream& hs = source_file->header_stream;
		std::stringstream& ss = source_file->source_stream;

		std::string header_code = hs.str();
		std::string source_code = ss.str();

		bool header_write_file_result = filesystem_write_file_from_memory(source_file->full_header_output_filepath.c_str(), header_code.c_str(), header_code.size());
		ASSERT(header_write_file_result);
		bool source_write_file_result = filesystem_write_file_from_memory(source_file->full_source_output_filepath.c_str(), source_code.c_str(), source_code.size());
		ASSERT(source_write_file_result);
	}

	{
		std::string output_directory = c_command_line::get_command_line_arg("-generated-output");
		ASSERT(!output_directory.empty());
		std::string source_output_filepath = output_directory + "\\tag_groups.cpp";

		{
			std::string header_output_filepath = output_directory + "\\tag_groups.h";
			std::stringstream hs;
			create_tag_groups_header(hs);
			std::string header_code = hs.str();
			bool blofeld_header_write_file_result = filesystem_write_file_from_memory(header_output_filepath.c_str(), header_code.c_str(), header_code.size());
			ASSERT(blofeld_header_write_file_result);
		}
		{
			std::string source_output_filepath = output_directory + "\\tag_groups.cpp";
			std::stringstream ss;
			create_tag_groups_source(ss);
			std::string source_code = ss.str();
			bool blofeld_source_write_file_result = filesystem_write_file_from_memory(source_output_filepath.c_str(), source_code.c_str(), source_code.size());
			ASSERT(blofeld_source_write_file_result);
		}
		{
			std::string header_output_filepath = output_directory + "\\tag_structs.h";
			std::stringstream hs;
			create_tag_structs_header(hs);
			std::string header_code = hs.str();
			bool blofeld_header_write_file_result = filesystem_write_file_from_memory(header_output_filepath.c_str(), header_code.c_str(), header_code.size());
			ASSERT(blofeld_header_write_file_result);
		}
		{
			std::string source_output_filepath = output_directory + "\\tag_structs.cpp";
			std::stringstream ss;
			create_tag_structs_source(ss);
			std::string source_code = ss.str();
			bool blofeld_source_write_file_result = filesystem_write_file_from_memory(source_output_filepath.c_str(), source_code.c_str(), source_code.size());
			ASSERT(blofeld_source_write_file_result);
		}
		{
			std::string header_output_filepath = output_directory + "\\halo4_validation_data.h";
			std::stringstream hs;
			create_validation_header(hs);
			std::string header_code = hs.str();
			bool blofeld_header_write_file_result = filesystem_write_file_from_memory(header_output_filepath.c_str(), header_code.c_str(), header_code.size());
			ASSERT(blofeld_header_write_file_result);
		}
		{
			std::string source_output_filepath = output_directory + "\\halo4_validation_data.cpp";
			std::stringstream ss;
			create_validation_source(ss);
			std::string source_code = ss.str();
			bool blofeld_source_write_file_result = filesystem_write_file_from_memory(source_output_filepath.c_str(), source_code.c_str(), source_code.size());
			ASSERT(blofeld_source_write_file_result);
		}
		{
			std::string source_output_filepath = output_directory + "\\constants.txt";
			std::stringstream ss;
			for (std::string& defintion : preprocessor.maximum_count_constants_source_lines_define)
			{
				ss << defintion;
			}
			ss << std::endl;
			for (std::string& defintion : preprocessor.maximum_count_constants_source_lines_constant)
			{
				ss << defintion;
			}
			ss << std::endl;
			for (std::string& defintion : preprocessor.maximum_count_constants_source_lines_struct)
			{
				ss << defintion;
			}
			ss << std::endl;
			std::string source_code = ss.str();
			bool blofeld_source_write_file_result = filesystem_write_file_from_memory(source_output_filepath.c_str(), source_code.c_str(), source_code.size());
			ASSERT(blofeld_source_write_file_result);
		}
		{
			std::string source_output_filepath = output_directory + "\\manual_tag_references.h";
			std::stringstream ss;

			ss << "#pragma once" << std::endl << std::endl;
			ss << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;
			for (c_h4_tag_reference_container* reference_container : preprocessor.tag_reference_containers)
			{
				if (reference_container->is_template)
				{
					
				}
			}
			ss << std::endl;
			ss << "} // namespace blofeld" << std::endl << std::endl;

			std::string source_code = ss.str();
			bool blofeld_source_write_file_result = filesystem_write_file_from_memory(source_output_filepath.c_str(), source_code.c_str(), source_code.size());
			ASSERT(blofeld_source_write_file_result);
		}
		{
			std::string source_output_filepath = output_directory + "\\manual_tag_references.cpp";
			std::stringstream ss;

			ss << "#include <tagdefinitions-private-pch.h>" << std::endl;
			ss << "#include <blofeld_field_type_override.h>" << std::endl << std::endl;
			ss << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;
			for (c_h4_tag_reference_container* reference_container : preprocessor.tag_reference_containers)
			{
				if (reference_container->is_template)
				{
					ss << "\ts_tag_reference_definition " << reference_container->name << ";" << std::endl;
				}
			}
			ss << std::endl;
			ss << "} // namespace blofeld" << std::endl << std::endl;

			std::string source_code = ss.str();
			bool blofeld_source_write_file_result = filesystem_write_file_from_memory(source_output_filepath.c_str(), source_code.c_str(), source_code.size());
			ASSERT(blofeld_source_write_file_result);
		}
	}
}

c_h4_source_generator::~c_h4_source_generator()
{

}

void c_h4_source_generator::create_tag_groups_header(std::stringstream& hs)
{
	hs << "#pragma once" << std::endl << std::endl;

	std::set<std::string> includes;
	//for (c_h4_tag_group_container* group_container : preprocessor.group_containers)
	//{
	//	c_h4_tag_group& tag_group = group_container->tag_group;
	//	c_h4_tag_struct* tag_struct = tag_group.tag_block->tag_struct;

	//	includes.emplace(group_container->source_file.header_output_filepath);
	//}
	for (c_h4_source_file* source_file : preprocessor.source_files)
	{
		includes.emplace(source_file->header_output_filepath);
	}

	hs << "#include \"manual_tag_references.h\"" << std::endl;
	for (const std::string& include : includes)
	{
		hs << "#include \"" << include << "\"" << std::endl;
	}
	hs << std::endl;
	hs << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;

	hs << "\textern const s_tag_group* tag_groups[" << preprocessor.group_containers.size() << "];" << std::endl;

	hs << "} // namespace blofeld" << std::endl << std::endl;
	hs << std::endl;
}

void c_h4_source_generator::create_tag_groups_source(std::stringstream& ss)
{
	ss << "#include <tagdefinitions-private-pch.h>" << std::endl << std::endl;

	ss << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;

	ss << "const s_tag_group* tag_groups[" << preprocessor.group_containers.size() << "] = " << std::endl;
	ss << "{" << std::endl;
	for (c_h4_tag_group_container* group_container : preprocessor.group_containers)
	{
		c_h4_tag_group& tag_group = group_container->tag_group;
		c_h4_tag_struct& tag_struct = tag_group.tag_block.tag_struct;

		ss << "\t&" << group_container->tag_group.name << "_group," << std::endl;
	}
	ss << "};" << std::endl;
	ss << std::endl;

	ss << "} // namespace blofeld" << std::endl << std::endl;
}

void c_h4_source_generator::create_tag_structs_header(std::stringstream& hs)
{
	hs << "#pragma once" << std::endl << std::endl;

	hs << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;

	hs << "\textern const s_tag_struct_definition* tag_struct_definitions[" << preprocessor.tag_struct_containers.size() << "];" << std::endl;

	hs << "} // namespace blofeld" << std::endl << std::endl;
	hs << std::endl;
}

void c_h4_source_generator::create_tag_structs_source(std::stringstream& ss)
{
	ss << "#include <tagdefinitions-private-pch.h>" << std::endl << std::endl;

	ss << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;

	ss << "\tconst s_tag_struct_definition* tag_struct_definitions[" << preprocessor.tag_struct_containers.size() << "] = " << std::endl;
	ss << "\t{" << std::endl;
	for (c_h4_tag_struct_container* tag_struct_container : preprocessor.tag_struct_containers)
	{
		c_h4_tag_block_container* tag_block_container = tag_struct_container->tag_block_container;

		bool x = strstr(tag_struct_container->name.c_str(), "runtime_queryable_properties");
		if(tag_struct_container->is_array)
		{
			if (tag_struct_container->tag_block_container)
			{
				ss << "\t\t&" << tag_struct_container->tag_block_container->name << "_struct_definition, // array" << std::endl;
			}
			else
			{
				ss << "\t\t&" << tag_struct_container->name << "_struct_definition, // array" << std::endl;
			}
		}
		else if (tag_block_container && !tag_block_container->defined_by_tag_group && tag_block_container->use_tag_block_definition)
		{
			ss << "\t\t&" << tag_block_container->name << "_block_struct, // block" << std::endl;
		}
		else if (tag_struct_container->is_block)
		{
			ss << "\t\t&" << tag_struct_container->symbol_name << "_block_struct, // block" << std::endl;
		}
		else if (tag_struct_container->is_tag_group)
		{
			ss << "\t\t&" << tag_struct_container->name << "_struct_definition, // tag group" << std::endl;
		}
		else
		{
			ss << "\t\t&" << tag_struct_container->name << "_struct_definition," << std::endl;
		}
		debug_point;
	}
	ss << "\t};" << std::endl;
	ss << std::endl;

	ss << "} // namespace blofeld" << std::endl << std::endl;
}

void c_h4_source_generator::create_validation_header(std::stringstream& hs)
{
	hs << "#pragma once" << std::endl << std::endl;

	hs << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;

	hs << "\textern s_tag_struct_validation_data gen3_xbox360_tag_struct_validation_data[" << preprocessor.tag_block_containers.size() << "];" << std::endl;

	hs << "} // namespace blofeld" << std::endl << std::endl;
	hs << std::endl;
}

void c_h4_source_generator::create_validation_source(std::stringstream& ss)
{
	ss << "#include <tagdefinitions-private-pch.h>" << std::endl << std::endl;

	ss << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;

	ss << "\ts_tag_struct_validation_data gen3_xbox360_tag_struct_validation_data[" << preprocessor.tag_block_containers.size() << "] = " << std::endl;
	ss << "\t{" << std::endl;
	for (c_h4_tag_block_container* tag_block_container : preprocessor.tag_block_containers)
	{
		c_h4_tag_struct_container& tag_struct_container = *tag_block_container->tag_struct_container;
		c_h4_tag_struct& tag_struct = tag_struct_container.tag_struct;
		c_h4_tag_block& tag_block = tag_block_container->tag_block;

		if (tag_block.is_array)
		{
			ss << "\t\t{ " << tag_block.name << "_struct_definition, " << tag_struct.size << " }, // array" << std::endl;
		}
		else if (!tag_block_container->defined_by_tag_group && tag_block_container->use_tag_block_definition)
		{
			ss << "\t\t{ " << tag_block_container->name << "_block_struct, " << tag_struct.size << " }, // block" << std::endl;
		}
		else if (tag_struct_container.is_block)
		{
			ss << "\t\t{ " << tag_struct_container.symbol_name << "_block_struct, " << tag_struct.size << " }, // block" << std::endl;
		}
		else if (tag_struct_container.is_tag_group)
		{
			ss << "\t\t{ " << tag_struct_container.name << "_struct_definition, " << tag_struct.size << " }, // group" << std::endl;
		}
		else
		{
			ss << "\t\t{ " << tag_struct_container.name << "_struct_definition, " << tag_struct.size << " }," << std::endl;
		}
	}
	ss << "\t};" << std::endl;
	ss << std::endl;

	ss << "} // namespace blofeld" << std::endl << std::endl;
}

std::string parse_tag_group_string(const tag_group& group_tag)
{
	std::string result;
	group_tag.name[0] ? result += group_tag.name[0] : (result.empty() ? "" : "\\0");
	group_tag.name[1] ? result += group_tag.name[1] : (result.empty() ? "" : "\\0");
	group_tag.name[2] ? result += group_tag.name[2] : (result.empty() ? "" : "\\0");
	group_tag.name[3] ? result += group_tag.name[3] : (result.empty() ? "" : "\\0");

	return result;
}

void c_h4_source_generator::create_tag_group_header(std::stringstream& hs, c_h4_tag_group_container& group_container)
{
	c_h4_tag_block_container& tag_block_container = *group_container.tag_block_container;
	c_h4_tag_group& tag_group = group_container.tag_group;
	c_h4_tag_struct& tag_struct = tag_group.tag_block.tag_struct;

	//hs << "extern const unsigned long " << group_container.name_uppercase << "_TAG;" << std::endl;
	hs << "\tconstexpr unsigned long " << group_container.name_uppercase << "_TAG = '" << parse_tag_group_string(tag_group.group_tag) << "';" << std::endl << std::endl;
	if (group_container.define_tag_group_block_and_fields)
	{
		hs << "\textern s_tag_struct_definition " << tag_block_container.symbol_name << "_struct;" << std::endl;
		hs << "\textern s_tag_block_definition " << tag_block_container.symbol_name << ";" << std::endl;
	}
	hs << "\textern s_tag_group " << tag_group.name << "_group;" << std::endl;

}

void c_h4_source_generator::create_tag_group_source(std::stringstream& ss, c_h4_tag_group_container& group_container)
{
	c_h4_tag_group& tag_group = group_container.tag_group;
	c_h4_tag_struct& tag_struct = tag_group.tag_block.tag_struct;
	c_h4_tag_block_container* tag_block_container = preprocessor.find_existing_tag_block_container(tag_group.tag_block);

	//ss << "const unsigned long " << group_container.name_uppercase << "_TAG = '" << parse_tag_group_string(tag_group.group_tag) << "';" << std::endl << std::endl;

	if (tag_group.parent_group_tag.value == 0xFFFFFFFF)
	{
		if (group_container.define_tag_group_block_and_fields)
		{
			ss << "\tTAG_GROUP(" << group_container.name << ", " << group_container.name_uppercase << "_TAG)" << std::endl;
		}
		else
		{
			ss << "\tTAG_GROUP_FROM_BLOCK(" << group_container.name << ", " << group_container.name_uppercase << "_TAG, " << tag_block_container->symbol_name << " );" << std::endl;
		}
	}
	else
	{
		c_h4_tag_group_container* parent_group_container = preprocessor.get_container_by_group_tag(tag_group.parent_group_tag.value);
		ASSERT(parent_group_container);
		c_h4_tag_group& parent_tag_group = parent_group_container->tag_group;

		if (group_container.define_tag_group_block_and_fields)
		{
			ss << "\tTAG_GROUP_INHERIT(" << group_container.name << ", " << group_container.name_uppercase << "_TAG, " << parent_tag_group.name << ", " << parent_group_container->name_uppercase << "_TAG)" << std::endl;
		}
		else
		{
			ss << "\tTAG_GROUP_INHERIT_FROM_BLOCK(" << group_container.name << ", " << group_container.name_uppercase << "_TAG, " << parent_tag_group.name << ", " << parent_group_container->name_uppercase << "_TAG, " << tag_block_container->symbol_name << " );" << std::endl;
		}
	}

	if (group_container.define_tag_group_block_and_fields)
	{
		ss << "\t{" << std::endl;
		generate_tag_fields_source(ss, tag_struct.tag_fields);
		ss << "\t};" << std::endl;
	}


	ss << std::endl;
}

void c_h4_source_generator::create_tag_enum_header(std::stringstream& hs, c_h4_tag_enum_container& tag_enum_container)
{
	hs << "\textern const char* " << tag_enum_container.name << "_strings[];" << std::endl;
	hs << "\textern s_string_list_definition " << tag_enum_container.name << ";" << std::endl;
}

void c_h4_source_generator::create_tag_enum_source(std::stringstream& ss, c_h4_tag_enum_container& tag_enum_container, bool is_header)
{
	c_h4_tag_enum& tag_enum = tag_enum_container.tag_enum;

	if (is_header)
	{
		ss << "#if 0" << std::endl;
	}

	if (tag_enum.options.size() > 0)
	{
		ss << "\tSTRINGS(" << tag_enum_container.name << ")" << std::endl;
		ss << "\t{" << std::endl;
		for (uint32_t i = 0; i < tag_enum.options.size(); i++)
		{
			const char* option = tag_enum.options[i];
			std::string escaped_option = escape_string(option);
			if (i != tag_enum.options.size() -1)
			{
				ss << "\t\t\"" << escaped_option << "\"," << std::endl;
			}
			else
			{
				ss << "\t\t\"" << escaped_option << "\"" << std::endl;
			}
		}
		ss << "\t};" << std::endl;

		ss << "\tSTRING_LIST(" << tag_enum_container.name << ", " << tag_enum_container.name << "_strings, _countof(" << tag_enum_container.name << "_strings));" << std::endl;
	}
	else
	{
		ss << "\tSTRING_LIST(" << tag_enum_container.name << ", empty_string_list, 0);" << std::endl;
	}

	if (is_header)
	{
		ss << "#endif" << std::endl;
	}

	ss << std::endl;
}

void c_h4_source_generator::create_tag_block_header(std::stringstream& hs, c_h4_tag_block_container& tag_block_container)
{
	c_h4_tag_block& tag_block = tag_block_container.tag_block;
	c_h4_tag_struct& tag_struct = tag_block.tag_struct;

	if (!tag_block_container.defined_by_tag_group && tag_block_container.use_tag_block_definition)
	{
		//hs << "extern s_tag_struct_definition " << tag_block_container.tag_struct_container->name << "_block_struct;" << std::endl;
		hs << "\textern s_tag_struct_definition " << tag_block_container.name << "_block_struct;" << std::endl;
	}
	hs << "\textern s_tag_block_definition " << tag_block_container.symbol_name << ";" << std::endl;


}
void c_h4_source_generator::create_tag_block_source(std::stringstream& ss, c_h4_tag_block_container& tag_block_container)
{
	c_h4_tag_block& tag_block = tag_block_container.tag_block;
	c_h4_tag_struct_container& tag_struct_container = *tag_block_container.tag_struct_container;
	c_h4_tag_struct& tag_struct = tag_block.tag_struct;

	if (tag_block_container.use_tag_block_definition)
	{
		ss << "\tTAG_BLOCK(" << tag_block_container.name << ", " << tag_block.maximum_element_count_string << ")" << std::endl;
		ss << "\t{" << std::endl;
		generate_tag_fields_source(ss, tag_struct.tag_fields);
		ss << "\t};" << std::endl;
		ss << std::endl;
	}
	else
	{
		if (tag_struct_container.is_block)
		{
			ss << "\tTAG_BLOCK_FROM_STRUCT(" << tag_block_container.name << ", " << tag_block.maximum_element_count_string << ", " << tag_struct_container.name << "_block_struct );" << std::endl;
		}
		else
		{
			ss << "\tTAG_BLOCK_FROM_STRUCT(" << tag_block_container.name << ", " << tag_block.maximum_element_count_string << ", " << tag_struct_container.name << "_struct_definition );" << std::endl;
		}

		ss << std::endl;
	}
}

void c_h4_source_generator::create_tag_array_header(std::stringstream& hs, c_h4_tag_block_container& tag_block_container)
{
	c_h4_tag_block& tag_block = tag_block_container.tag_block;
	c_h4_tag_struct& tag_struct = tag_block.tag_struct;

	if (!tag_block_container.defined_by_tag_group && tag_block_container.use_tag_block_definition)
	{
		hs << "\textern s_tag_struct_definition " << tag_block_container.name << "_struct_definition;" << std::endl;
	}
	hs << "\textern s_tag_array_definition " << tag_block_container.symbol_name << ";" << std::endl;


}
void c_h4_source_generator::create_tag_array_source(std::stringstream& ss, c_h4_tag_block_container& tag_block_container)
{
	c_h4_tag_block& tag_block = tag_block_container.tag_block;
	c_h4_tag_struct_container& tag_struct_container = *tag_block_container.tag_struct_container;
	c_h4_tag_struct& tag_struct = tag_block.tag_struct;

	if (tag_block_container.use_tag_block_definition)
	{
		ss << "\tTAG_ARRAY(" << tag_block_container.name << ", " << tag_block.maximum_element_count_string << ")" << std::endl;
		ss << "\t{" << std::endl;
		generate_tag_fields_source(ss, tag_struct.tag_fields);
		ss << "\t};" << std::endl;
		ss << std::endl;
	}
	else
	{
		if (tag_struct_container.is_block)
		{
			ss << "\tTAG_ARRAY_FROM_STRUCT(" << tag_block_container.name << ", " << tag_block.maximum_element_count_string << ", " << tag_struct_container.name << "_block_struct );" << std::endl;
		}
		else
		{
			ss << "\tTAG_ARRAY_FROM_STRUCT(" << tag_block_container.name << ", " << tag_block.maximum_element_count_string << ", " << tag_struct_container.name << "_struct_definition );" << std::endl;
		}

		ss << std::endl;
	}
}

void c_h4_source_generator::create_tag_struct_header(std::stringstream& hs, c_h4_tag_struct_container& tag_struct_container)
{
	c_h4_tag_struct& tag_struct = tag_struct_container.tag_struct;

	if (tag_struct_container.is_array)
	{
		hs << "\textern s_tag_struct_definition " << tag_struct_container.name << "_struct_definition; // array" << std::endl;
	}
	else if (tag_struct_container.is_block)
	{
		hs << "\textern s_tag_struct_definition " << tag_struct_container.name << "_block_struct; // block" << std::endl;
	}
	else if (tag_struct_container.is_tag_group)
	{
		hs << "\textern s_tag_struct_definition " << tag_struct_container.name << "_struct_definition; // tag group" << std::endl;
		//hs << "\textern s_tag_struct_definition " << tag_struct_container.source_name << "; // tag group" << std::endl;
	}
	else
	{
		hs << "\textern s_tag_struct_definition " << tag_struct_container.name << "_struct_definition;" << std::endl;
	}



}
void c_h4_source_generator::create_tag_struct_source(std::stringstream& ss, c_h4_tag_struct_container& tag_struct_container)
{
	c_h4_tag_struct& tag_struct = tag_struct_container.tag_struct;

	ss << "\tTAG_STRUCT(" << tag_struct_container.name << ")" << std::endl;
	ss << "\t{" << std::endl;
	generate_tag_fields_source(ss, tag_struct.tag_fields);
	ss << "\t};" << std::endl;
	ss << std::endl;

}

void c_h4_source_generator::create_tag_reference_header(std::stringstream& hs, c_h4_tag_reference_container& tag_reference_container)
{
	c_h4_tag_reference& tag_reference = tag_reference_container.tag_reference;

	//if (tag_reference_container.is_empty_and_unknown_reference)
	//{
	//	return;
	//}
	//if (tag_reference_container.is_tag_group_reference)
	//{
	//	return;
	//}
	if (strstr(tag_reference_container.name.c_str(), "Tag::Reference") != nullptr)
	{
		return;
	}

	hs << "\textern s_tag_reference_definition " << tag_reference_container.name << ";" << std::endl;
}

void c_h4_source_generator::create_tag_reference_source(std::stringstream& ss, c_h4_tag_reference_container& tag_reference_container)
{
	c_h4_tag_reference& tag_reference = tag_reference_container.tag_reference;

	//if (tag_reference_container.is_empty_and_unknown_reference)
	//{
	//	return;
	//}
	//if (tag_reference_container.is_tag_group_reference)
	//{
	//	return;
	//}
	if (strstr(tag_reference_container.name.c_str(), "Tag::Reference") != nullptr)
	{
		return;
	}
		
//_h4_tag_reference_flag_not_a_dependency,
//_h4_tag_reference_flag_dont_resolve_in_editor,
//_h4_tag_reference_flag_resolved_manually,
//_h4_tag_reference_flag_resolved_by_game,
//_h4_tag_reference_flag_not_a_resource_dependency,
//_h4_tag_reference_flag_dependency_for_cache_file_sharing,
//_h4_tag_reference_flag_reference_ignored_by_bundle_builder

	std::stringstream flags_stream;
	if (tag_reference_container.tag_reference.flags.test(_h4_tag_reference_flag_not_a_dependency))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_not_a_dependency";
	}
	if (tag_reference_container.tag_reference.flags.test(_h4_tag_reference_flag_dont_resolve_in_editor))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_dont_resolve_in_editor";
	}
	if (tag_reference_container.tag_reference.flags.test(_h4_tag_reference_flag_resolved_manually))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_resolved_manually";
	}
	if (tag_reference_container.tag_reference.flags.test(_h4_tag_reference_flag_resolved_by_game))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_resolved_by_game";
	}
	if (tag_reference_container.tag_reference.flags.test(_h4_tag_reference_flag_not_a_resource_dependency))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_not_a_resource_dependency";
	}
	if (tag_reference_container.tag_reference.flags.test(_h4_tag_reference_flag_dependency_for_cache_file_sharing))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_dependency_for_cache_file_sharing";
	}
	if (tag_reference_container.tag_reference.flags.test(_h4_tag_reference_flag_reference_ignored_by_bundle_builder))
	{
		if (!flags_stream.str().empty()) flags_stream << " | ";
		flags_stream << "_tag_reference_flag_reference_ignored_by_bundle_builder";
	}
	std::string flags_string = flags_stream.str();

	if (tag_reference.reference_definition->group_tag != 0xFFFFFFFF)
	{
		ASSERT(tag_reference.tag_groups.size() == 1);

		c_h4_tag_group_container* group_container = nullptr;
		for (c_h4_tag_group_container* current_group_container : preprocessor.group_containers)
		{
			if (current_group_container->tag_group.group_tag.value == tag_reference.reference_definition->group_tag.value)
			{
				group_container = current_group_container;
				break;
			}
		}
		ASSERT(group_container != nullptr);

		ss << "\tTAG_REFERENCE(" << tag_reference_container.name << ", " << group_container->name_uppercase << "_TAG";
		if (!flags_string.empty())
		{
			ss << ", " << flags_string;
		}
		ss << ");" << std::endl;

	}
	else if (!tag_reference.tag_groups.empty())
	{
		ss << "\tTAG_REFERENCE_GROUP(" << tag_reference_container.name;
		if (!flags_string.empty())
		{
			ss << ", " << flags_string;
		}
		ss << ")";
		ss << std::endl;
		ss << "\t{" << std::endl;
		for (tag_group& tag_group : tag_reference.tag_groups)
		{
			bool found_group = false;
			for (c_h4_tag_group_container* group_container : preprocessor.group_containers)
			{
				if (group_container->tag_group.group_tag.value == tag_group.value)
				{
					ss << "\t\t" << group_container->name_uppercase << "_TAG," << std::endl;
					found_group = true;
					break;
				}

			}
			//ASSERT(found_group);

			if (!found_group)
			{
				std::string tag_group_string = parse_tag_group_string(tag_group);
				ss << "\t\t'" << tag_group_string << "'," << std::endl;
			}
		}
		ss << "\t\tINVALID_TAG," << std::endl;
		ss << "\t};" << std::endl;
	}
	else
	{
		ss << "\tTAG_REFERENCE(" << tag_reference_container.name << ");" << std::endl;
	}
	ss << std::endl;
}

void c_h4_source_generator::generate_tag_fields_source(std::stringstream& ss, std::vector<c_h4_tag_field*>& tag_fields)
{
	for (c_h4_tag_field* tag_field : tag_fields)
	{
		const char* field_generic_type_name = h4_field_type_to_generic_field_type(tag_field->field_type);
		std::string field_name = tag_field->name ? escape_string(tag_field->name) : "";

		switch (tag_field->field_type)
		{
		case _h4_field_type_string:
		case _h4_field_type_long_string:
		case _h4_field_type_string_id:
		case _h4_field_type_old_string_id:
		case _h4_field_type_char_integer:
		case _h4_field_type_short_integer:
		case _h4_field_type_long_integer:
		case _h4_field_type_int64_integer:
		case _h4_field_type_angle:
		case _h4_field_type_tag:
		case _h4_field_type_point_2d:
		case _h4_field_type_rectangle_2d:
		case _h4_field_type_rgb_color:
		case _h4_field_type_argb_color:
		case _h4_field_type_real:
		case _h4_field_type_real_fraction:
		case _h4_field_type_real_point_2d:
		case _h4_field_type_real_point_3d:
		case _h4_field_type_real_vector_2d:
		case _h4_field_type_real_vector_3d:
		case _h4_field_type_real_quaternion:
		case _h4_field_type_real_euler_angles_2d:
		case _h4_field_type_real_euler_angles_3d:
		case _h4_field_type_real_plane_2d:
		case _h4_field_type_real_plane_3d:
		case _h4_field_type_real_rgb_color:
		case _h4_field_type_real_argb_color:
		case _h4_field_type_real_hsv_color:
		case _h4_field_type_real_ahsv_color:
		case _h4_field_type_short_bounds:
		case _h4_field_type_angle_bounds:
		case _h4_field_type_real_bounds:
		case _h4_field_type_real_fraction_bounds:
		case _h4_field_type_long_block_flags:
		case _h4_field_type_word_block_flags:
		case _h4_field_type_byte_block_flags:
		case _h4_field_type_char_block_index:
		case _h4_field_type_short_block_index:
		case _h4_field_type_long_block_index:
		case _h4_field_type_custom_char_block_index:
		case _h4_field_type_custom_short_block_index:
		case _h4_field_type_custom_long_block_index:
		case _h4_field_type_data:
		case _h4_field_type_vertex_buffer:
		case _h4_field_type_non_cache_runtime_value:
		case _h4_field_type_custom:
		case _h4_field_type_pageable:
		case _h4_field_type_api_interop:
		case _h4_field_type_terminator:
		case _h4_field_type_byte_integer:
		case _h4_field_type_word_integer:
		case _h4_field_type_dword_integer:
		case _h4_field_type_qword_integer:
		case _h4_field_type_useless_pad:
			if (tag_field->name)
			{
				ss << "\t\t{ " << field_generic_type_name << ", \"" << field_name << "\" }," << std::endl;
			}
			else
			{
				ss << "\t\t{ " << field_generic_type_name << " }," << std::endl;
			}
			break;
		case _h4_field_type_explanation:
		{

			c_h4_tag_field_explanation* explanation_field = dynamic_cast<c_h4_tag_field_explanation*>(tag_field);
			ASSERT(explanation_field);
			ASSERT(explanation_field->name);

			if (explanation_field->definition == nullptr)
			{
				ss << "\t\t{ " << field_generic_type_name << ", \"" << field_name << "\" }," << std::endl;
			}
			else
			{

				std::string explanation = escape_string(explanation_field->definition);
				ss << "\t\t{ " << field_generic_type_name << ", \"" << field_name << "\", \"" << explanation << "\" }," << std::endl;
			}
			break;
		}
		case _h4_field_type_tag_reference:
		{
			c_h4_tag_field_tag_reference* tag_reference_field = dynamic_cast<c_h4_tag_field_tag_reference*>(tag_field);
			ASSERT(tag_reference_field);
			ASSERT(tag_reference_field->name);
			c_h4_tag_reference_container* tag_reference_container = preprocessor.find_existing_tag_reference_container(*tag_reference_field->reference);
			ASSERT(tag_reference_container);

			ss << "\t\t{ " << field_generic_type_name << ", \"" << field_name << "\", &" << tag_reference_container->name << " }," << std::endl;

			break;
		}
		case _h4_field_type_struct:
		{
			c_h4_tag_field_struct* struct_field = dynamic_cast<c_h4_tag_field_struct*>(tag_field);
			ASSERT(struct_field);
			ASSERT(struct_field->name);
			c_h4_tag_struct_container* tag_struct_container = preprocessor.find_existing_tag_struct_container(*struct_field->tag_struct);
			ASSERT(tag_struct_container);


			if (tag_struct_container->is_block)
			{
				ss << "\t\t{ " << field_generic_type_name << ", \"" << field_name << "\", &" << tag_struct_container->name << "_block_struct }," << std::endl;
			}
			else
			{
				ss << "\t\t{ " << field_generic_type_name << ", \"" << field_name << "\", &" << tag_struct_container->name << "_struct_definition }," << std::endl;
			}

			break;
		}
		case _h4_field_type_array:
		{
			c_h4_tag_field_array* tag_field_array = dynamic_cast<c_h4_tag_field_array*>(tag_field);
			ASSERT(tag_field_array);
			ASSERT(tag_field_array->name);
			ASSERT(tag_field_array->tag_array_definition);
			c_h4_tag_block_container* tag_block_container = preprocessor.find_existing_tag_block_container(*tag_field_array->tag_array_definition);

			ASSERT(tag_block_container);
			ss << "\t\t{ " << field_generic_type_name << ", \"" << field_name << "\", &" << tag_block_container->symbol_name << " }," << std::endl;
			break;
		}
		case _h4_field_type_block:
		{
			c_h4_tag_field_block* tag_field_block = dynamic_cast<c_h4_tag_field_block*>(tag_field);
			ASSERT(tag_field_block);
			ASSERT(tag_field_block->name);
			ASSERT(tag_field_block->tag_block_definition);
			c_h4_tag_block_container* tag_block_container = preprocessor.find_existing_tag_block_container(*tag_field_block->tag_block_definition);

			ASSERT(tag_block_container);
			ss << "\t\t{ " << field_generic_type_name << ", \"" << field_name << "\", &" << tag_block_container->symbol_name << " }," << std::endl;
			break;
		}
		case _h4_field_type_char_enum:
		case _h4_field_type_enum:
		case _h4_field_type_long_enum:
		case _h4_field_type_long_flags:
		case _h4_field_type_word_flags:
		case _h4_field_type_byte_flags:
		{
			c_h4_tag_field_enum* tag_field_enum = dynamic_cast<c_h4_tag_field_enum*>(tag_field);
			ASSERT(tag_field_enum);
			ASSERT(tag_field_enum->name);
			ASSERT(tag_field_enum->tag_enum);

			ss << "\t\t{ " << field_generic_type_name << ", \"" << field_name << "\", &" << tag_field_enum->tag_enum->name << " }," << std::endl;

			break;
		}
		case _h4_field_type_pad:
		case _h4_field_type_skip:
		{
			c_h4_tag_field_skip* skip_field = dynamic_cast<c_h4_tag_field_skip*>(tag_field);
			c_h4_tag_field_pad* pad_field = dynamic_cast<c_h4_tag_field_pad*>(tag_field);

			uint32_t argument = 0;
			if (skip_field) argument = skip_field->length;
			if (pad_field) argument = pad_field->padding;

			if (tag_field->name)
			{
				ss << "\t\t{ " << field_generic_type_name << ", \"" << field_name << "\", " << argument << " }," << std::endl;
			}
			else
			{
				ss << "\t\t{ " << field_generic_type_name << ", " << argument << " }," << std::endl;
			}
			break;
		}
		default:
			throw; // unexpected type
		}
	}
	ss << "\t\t{ _field_terminator }" << std::endl;
}
