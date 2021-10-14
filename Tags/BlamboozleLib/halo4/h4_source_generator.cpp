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
			case '\\': result += "\\\\"; break;
			case '\a': result += "\\a"; break;
			case '\b': result += "\\b"; break;
			case '\f': result += "\\f"; break;
			case '\n': result += "\\n"; break;
			case '\r': result += "\\r"; break;
			case '\t': result += "\\t"; break;
			case '\v': result += "\\v"; break;
			case '\1': result += "\\x1"; break;
			default: result += ch; break;
			}
		}

		current_pos++;
	}

	return result;
}

void escape_string(
	const char* source,
	char* destination,
	bool remove_return,
	bool unescaped_comma)
{
	const char* source_pos = source;
	char* buffer_pos = destination;

	do
	{
		switch (*source_pos)
		{
		case '\r':
		{
			if (!remove_return)
			{
				(*buffer_pos++) = '\\';
				(*buffer_pos++) = '\r';
			}
			continue;
		}
		case '\'':
		{
			if (!unescaped_comma)
			{
				(*buffer_pos++) = '\\';
			}
			(*buffer_pos++) = '\'';
			continue;
		}
		case '\"': (*buffer_pos++) = '\\'; (*buffer_pos++) = '\"'; continue;
		case '\\': (*buffer_pos++) = '\\'; (*buffer_pos++) = '\\'; continue;
		case '\a': (*buffer_pos++) = '\\'; (*buffer_pos++) = 'a'; continue;
		case '\b': (*buffer_pos++) = '\\'; (*buffer_pos++) = 'b'; continue;
		case '\f': (*buffer_pos++) = '\\'; (*buffer_pos++) = 'f'; continue;
		case '\n': (*buffer_pos++) = '\\'; (*buffer_pos++) = 'n'; continue;
		case '\t': (*buffer_pos++) = '\\'; (*buffer_pos++) = 't'; continue;
		case '\v': (*buffer_pos++) = '\\'; (*buffer_pos++) = 'v'; continue;
		case '\1': (*buffer_pos++) = '\\'; (*buffer_pos++) = 'x'; (*buffer_pos++) = '1'; continue;
		}
		(*buffer_pos++) = *source_pos;
	} while (*source_pos++);
}

c_h4_source_generator::c_h4_source_generator(c_h4_blamboozle& blamboozle, c_h4_generator_preprocessor& preprocessor) :
	blamboozle(blamboozle),
	preprocessor(preprocessor)
{
	for (c_h4_source_file* source_file : preprocessor.source_files)
	{
		std::stringstream& hs = source_file->header_stream;
		std::stringstream& s = source_file->source_stream;

		hs << "#pragma once" << std::endl << std::endl;
		s << "#include <tagdefinitions-private-pch.h>" << std::endl;
		s << "#include <blofeld_field_type_override.h>" << std::endl << std::endl;

		hs << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;
		s << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;
		hs << "namespace macaque" << std::endl << "{" << std::endl << std::endl;
		s << "namespace macaque" << std::endl << "{" << std::endl << std::endl;

		for (c_h4_tag_group_container* group_container : source_file->tag_groups)
		{
			create_tag_group_header(hs, *group_container);
			create_tag_group_source(s, *group_container);
		}
		if (!source_file->tag_groups.empty()) hs << std::endl;

		unsigned long num_tag_blocks = 0;
		for (c_h4_tag_block_container* tag_block_container : source_file->tag_blocks)
		{
			if (tag_block_container->defined_by_tag_group) continue; // already called by tag group code
			if (tag_block_container->tag_block.is_block)
			{
				num_tag_blocks++;
				create_tag_block_header(hs, *tag_block_container);
				create_tag_block_source(s, *tag_block_container);
			}
		}
		if (num_tag_blocks > 0) hs << std::endl;

		unsigned long num_tag_arrays = 0;
		for (c_h4_tag_block_container* tag_block_container : source_file->tag_blocks)
		{
			if (tag_block_container->defined_by_tag_group) continue; // these are created manually through c_h4_tag_group_container
			if (tag_block_container->tag_block.is_array)
			{
				num_tag_blocks++;
				create_tag_array_header(hs, *tag_block_container);
				create_tag_array_source(s, *tag_block_container);
			}
		}
		if (num_tag_arrays > 0) hs << std::endl;

		for (c_h4_tag_struct_container* tag_struct_container : source_file->tag_structs)
		{
			if (tag_struct_container->is_block) continue; // these are created manually through c_h4_tag_block_container
			create_tag_struct_header(hs, *tag_struct_container);
			create_tag_struct_source(s, *tag_struct_container);
		}
		if (!source_file->tag_structs.empty()) hs << std::endl;

		for (c_h4_tag_enum_container* tag_enum_container : source_file->tag_enums)
		{
			create_tag_enum_header(hs, *tag_enum_container);
			create_tag_enum_source(s, *tag_enum_container, source_file->is_header);
		}
		if (!source_file->tag_enums.empty()) hs << std::endl;

		for (c_h4_tag_reference_container* tag_reference_container : source_file->tag_references)
		{
			create_tag_reference_header(hs, *tag_reference_container);
			create_tag_reference_source(s, *tag_reference_container);
		}
		if (!source_file->tag_references.empty()) hs << std::endl;

		hs << "} // namespace macaque" << std::endl << std::endl;
		s << "} // namespace macaque" << std::endl << std::endl;
		hs << "} // namespace blofeld" << std::endl << std::endl;
		s << "} // namespace blofeld" << std::endl << std::endl;
	}

	for (c_h4_source_file* source_file : preprocessor.source_files)
	{
		std::stringstream& hs = source_file->header_stream;
		std::stringstream& s = source_file->source_stream;

		std::string header_code = hs.str();
		std::string source_code = s.str();

		bool header_write_file_result = filesystem_write_file_from_memory(source_file->full_header_output_filepath.c_str(), header_code.c_str(), header_code.size());
		ASSERT(header_write_file_result);
		bool source_write_file_result = filesystem_write_file_from_memory(source_file->full_source_output_filepath.c_str(), source_code.c_str(), source_code.size());
		ASSERT(source_write_file_result);
	}

	{
		const char* _output_directory;
		ASSERT(BCS_SUCCEEDED(command_line_get_argument("generated-output", _output_directory)));
		std::string output_directory = _output_directory;

		std::string source_output_filepath = output_directory + "\\tag_groups.cpp";

		{
			std::string header_output_filepath = output_directory + "\\tag_groups.h";
			std::stringstream hs;
			create_tag_groups_header(hs);
			std::string header_code = hs.str();
			bool macaque_header_write_file_result = filesystem_write_file_from_memory(header_output_filepath.c_str(), header_code.c_str(), header_code.size());
			ASSERT(macaque_header_write_file_result);
		}
		{
			std::string source_output_filepath = output_directory + "\\tag_groups.cpp";
			std::stringstream s;
			create_tag_groups_source(s);
			std::string source_code = s.str();
			bool macaque_source_write_file_result = filesystem_write_file_from_memory(source_output_filepath.c_str(), source_code.c_str(), source_code.size());
			ASSERT(macaque_source_write_file_result);
		}
		{
			std::string header_output_filepath = output_directory + "\\tag_structs.h";
			std::stringstream hs;
			create_tag_structs_header(hs);
			std::string header_code = hs.str();
			bool macaque_header_write_file_result = filesystem_write_file_from_memory(header_output_filepath.c_str(), header_code.c_str(), header_code.size());
			ASSERT(macaque_header_write_file_result);
		}
		{
			std::string source_output_filepath = output_directory + "\\tag_structs.cpp";
			std::stringstream s;
			create_tag_structs_source(s);
			std::string source_code = s.str();
			bool macaque_source_write_file_result = filesystem_write_file_from_memory(source_output_filepath.c_str(), source_code.c_str(), source_code.size());
			ASSERT(macaque_source_write_file_result);
		}
		{
			std::string header_output_filepath = output_directory + "\\halo4_validation_data.h";
			std::stringstream hs;
			create_validation_header(hs);
			std::string header_code = hs.str();
			bool macaque_header_write_file_result = filesystem_write_file_from_memory(header_output_filepath.c_str(), header_code.c_str(), header_code.size());
			ASSERT(macaque_header_write_file_result);
		}
		{
			std::string source_output_filepath = output_directory + "\\halo4_validation_data.cpp";
			std::stringstream s;
			create_validation_source(s);
			std::string source_code = s.str();
			bool macaque_source_write_file_result = filesystem_write_file_from_memory(source_output_filepath.c_str(), source_code.c_str(), source_code.size());
			ASSERT(macaque_source_write_file_result);
		}
		{
			std::string source_output_filepath = output_directory + "\\constants.txt";
			std::stringstream s;
			for (std::string& defintion : preprocessor.maximum_count_constants_source_lines_define)
			{
				s << defintion;
			}
			s << std::endl;
			for (std::string& defintion : preprocessor.maximum_count_constants_source_lines_constant)
			{
				s << defintion;
			}
			s << std::endl;
			for (std::string& defintion : preprocessor.maximum_count_constants_source_lines_struct)
			{
				s << defintion;
			}
			s << std::endl;
			std::string source_code = s.str();
			bool macaque_source_write_file_result = filesystem_write_file_from_memory(source_output_filepath.c_str(), source_code.c_str(), source_code.size());
			ASSERT(macaque_source_write_file_result);
		}
		{
			std::string source_output_filepath = output_directory + "\\manual_tag_references.h";
			std::stringstream s;

			s << "#pragma once" << std::endl << std::endl;
			s << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;
			s << "namespace macaque" << std::endl << "{" << std::endl << std::endl;
			for (c_h4_tag_reference_container* reference_container : preprocessor.tag_reference_containers)
			{
				if (reference_container->is_template)
				{

				}
			}
			s << std::endl;
			s << "} // namespace macaque" << std::endl << std::endl;
			s << "} // namespace blofeld" << std::endl << std::endl;

			std::string source_code = s.str();
			bool macaque_source_write_file_result = filesystem_write_file_from_memory(source_output_filepath.c_str(), source_code.c_str(), source_code.size());
			ASSERT(macaque_source_write_file_result);
		}
		{
			std::string source_output_filepath = output_directory + "\\manual_tag_references.cpp";
			std::stringstream s;

			s << "#include <tagdefinitions-private-pch.h>" << std::endl;
			s << "#include <blofeld_field_type_override.h>" << std::endl << std::endl;
			s << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;
			s << "namespace macaque" << std::endl << "{" << std::endl << std::endl;
			for (c_h4_tag_reference_container* reference_container : preprocessor.tag_reference_containers)
			{
				if (reference_container->is_template)
				{
					s << "\ts_tag_reference_definition " << reference_container->name << ";" << std::endl;
				}
			}
			s << std::endl;
			s << "} // namespace macaque" << std::endl << std::endl;
			s << "} // namespace blofeld" << std::endl << std::endl;

			std::string source_code = s.str();
			bool macaque_source_write_file_result = filesystem_write_file_from_memory(source_output_filepath.c_str(), source_code.c_str(), source_code.size());
			ASSERT(macaque_source_write_file_result);
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
	hs << "namespace macaque" << std::endl << "{" << std::endl << std::endl;

	hs << "\textern const s_tag_group* tag_groups[" << preprocessor.group_containers.size() << "];" << std::endl;

	hs << "} // namespace macaque" << std::endl << std::endl;
	hs << "} // namespace blofeld" << std::endl << std::endl;
	hs << std::endl;
}

void c_h4_source_generator::create_tag_groups_source(std::stringstream& s)
{
	s << "#include <tagdefinitions-private-pch.h>" << std::endl << std::endl;

	s << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;
	s << "namespace macaque" << std::endl << "{" << std::endl << std::endl;

	s << "const s_tag_group* tag_groups[" << preprocessor.group_containers.size() << "] = " << std::endl;
	s << "{" << std::endl;
	for (c_h4_tag_group_container* group_container : preprocessor.group_containers)
	{
		c_h4_tag_group& tag_group = group_container->tag_group;
		c_h4_tag_struct& tag_struct = tag_group.tag_block.tag_struct;

		s << "\t&" << group_container->tag_group.name << "_group," << std::endl;
	}
	s << "};" << std::endl;
	s << std::endl;

	s << "} // namespace macaque" << std::endl << std::endl;
	s << "} // namespace blofeld" << std::endl << std::endl;
}

void c_h4_source_generator::create_tag_structs_header(std::stringstream& hs)
{
	hs << "#pragma once" << std::endl << std::endl;

	hs << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;
	hs << "namespace macaque" << std::endl << "{" << std::endl << std::endl;

	hs << "\textern const s_tag_struct_definition* tag_struct_definitions[" << preprocessor.tag_struct_containers.size() << "];" << std::endl;

	hs << "} // namespace macaque" << std::endl << std::endl;
	hs << "} // namespace blofeld" << std::endl << std::endl;
	hs << std::endl;
}

void c_h4_source_generator::create_tag_structs_source(std::stringstream& s)
{
	s << "#include <tagdefinitions-private-pch.h>" << std::endl << std::endl;

	s << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;
	s << "namespace macaque" << std::endl << "{" << std::endl << std::endl;

	s << "\tconst s_tag_struct_definition* tag_struct_definitions[" << preprocessor.tag_struct_containers.size() << "] = " << std::endl;
	s << "\t{" << std::endl;
	for (c_h4_tag_struct_container* tag_struct_container : preprocessor.tag_struct_containers)
	{
		c_h4_tag_block_container* tag_block_container = tag_struct_container->tag_block_container;

		if (tag_struct_container->is_array)
		{
			s << "\t\t&blofeld::" << tag_struct_container->symbol_name << ", // array" << std::endl;
		}
		else if (tag_struct_container->is_tag_group)
		{
			s << "\t\t&blofeld::" << tag_struct_container->symbol_name << ", // group" << std::endl;
		}
		else if (tag_struct_container->is_block)
		{
			s << "\t\t&blofeld::" << tag_struct_container->symbol_name << ", // block" << std::endl;
		}
		else
		{
			s << "\t\t&blofeld::" << tag_struct_container->symbol_name << "," << std::endl;
		}

	}
	s << "\t};" << std::endl;
	s << std::endl;

	s << "} // namespace macaque" << std::endl << std::endl;
	s << "} // namespace blofeld" << std::endl << std::endl;
}

void c_h4_source_generator::create_validation_header(std::stringstream& hs)
{
	hs << "#pragma once" << std::endl << std::endl;

	hs << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;
	hs << "namespace macaque" << std::endl << "{" << std::endl << std::endl;

	hs << "\textern s_tag_struct_validation_data gen3_xbox360_tag_struct_validation_data[" << preprocessor.tag_block_containers.size() << "];" << std::endl;

	hs << "} // namespace macaque" << std::endl << std::endl;
	hs << "} // namespace blofeld" << std::endl << std::endl;
	hs << std::endl;
}

void c_h4_source_generator::create_validation_source(std::stringstream& s)
{
	s << "#include <tagdefinitions-private-pch.h>" << std::endl << std::endl;

	s << "namespace blofeld" << std::endl << "{" << std::endl << std::endl;
	s << "namespace macaque" << std::endl << "{" << std::endl << std::endl;

	s << "\ts_tag_struct_validation_data gen3_xbox360_tag_struct_validation_data[" << preprocessor.tag_block_containers.size() << "] = " << std::endl;
	s << "\t{" << std::endl;
	for (c_h4_tag_block_container* tag_block_container : preprocessor.tag_block_containers)
	{
		c_h4_tag_struct_container& tag_struct_container = *tag_block_container->tag_struct_container;
		c_h4_tag_block& tag_block = tag_block_container->tag_block;
		c_h4_tag_struct& tag_struct = tag_struct_container.tag_struct;

		if (tag_block.is_array)
		{
			s << "\t\t{ blofeld::" << tag_struct_container.symbol_name << ", " << tag_struct.size << " }, // array" << std::endl;
		}
		else if (tag_struct_container.is_tag_group)
		{
			s << "\t\t{ blofeld::" << tag_struct_container.symbol_name << ", " << tag_struct.size << " }, // group" << std::endl;
		}
		else if (tag_block.is_block)
		{
			s << "\t\t{ blofeld::" << tag_struct_container.symbol_name << ", " << tag_struct.size << " }, // block" << std::endl;
		}
		else
		{
			s << "\t\t{ blofeld::" << tag_struct_container.symbol_name << ", " << tag_struct.size << " }," << std::endl;
		}
	}
	s << "\t};" << std::endl;
	s << std::endl;

	s << "} // namespace macaque" << std::endl << std::endl;
	s << "} // namespace blofeld" << std::endl << std::endl;
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
	c_h4_tag_struct_container& tag_struct_container = *tag_block_container.tag_struct_container;
	c_h4_tag_group& tag_group = group_container.tag_group;

	//hs << "extern const unsigned long " << group_container.name_uppercase << "_TAG;" << std::endl;
	hs << "\tconstexpr unsigned long " << group_container.name_uppercase << "_TAG = '" << parse_tag_group_string(tag_group.group_tag) << "';" << std::endl;
	hs << "\textern s_tag_group " << group_container.symbol_name << "; // " << tag_block_container.symbol_name << std::endl;

	if (group_container.define_tag_group_block_and_fields)
	{
		create_tag_block_header(hs, *group_container.tag_block_container);
	}

	hs << std::endl;
}

void c_h4_source_generator::create_tag_group_source(std::stringstream& s, c_h4_tag_group_container& group_container)
{
	c_h4_tag_group& tag_group = group_container.tag_group;
	c_h4_tag_struct& tag_struct = tag_group.tag_block.tag_struct;
	c_h4_tag_block_container& tag_block_container = *preprocessor.find_existing_tag_block_container(tag_group.tag_block);
	c_h4_tag_block& tag_block = tag_block_container.tag_block;
	c_h4_tag_struct_container& tag_struct_container = *tag_block_container.tag_struct_container;

	//s << "const unsigned long " << group_container.name_uppercase << "_TAG = '" << parse_tag_group_string(tag_group.group_tag) << "';" << std::endl << std::endl;


	if (group_container.define_tag_group_block_and_fields)
	{
		create_tag_block_source(s, *group_container.tag_block_container);
	}

	if (tag_group.parent_group_tag.value == 0xFFFFFFFF)
	{
		s << "\tTAG_GROUP(" << std::endl;
		s << "\t\t" << group_container.symbol_name << "," << std::endl;
		s << "\t\t" << group_container.name_uppercase << "_TAG," << std::endl;
		s << "\t\tnullptr," << std::endl;
		s << "\t\tINVALID_TAG," << std::endl;
		s << "\t\t" << tag_block_container.symbol_name << " );" << std::endl;
	}
	else
	{
		c_h4_tag_group_container& parent_group_container = *preprocessor.get_container_by_group_tag(tag_group.parent_group_tag.value);
		REFERENCE_ASSERT(parent_group_container);
		c_h4_tag_group& parent_tag_group = parent_group_container.tag_group;

		s << "\tTAG_GROUP(" << std::endl;
		s << "\t\t" << group_container.symbol_name << "," << std::endl;
		s << "\t\t" << group_container.name_uppercase << "_TAG," << std::endl;
		s << "\t\t&" << parent_group_container.symbol_name << "," << std::endl;
		s << "\t\t" << parent_group_container.name_uppercase << "_TAG," << std::endl;
		s << "\t\t" << tag_block_container.symbol_name << " );" << std::endl;
	}

	s << std::endl;
}

void c_h4_source_generator::create_tag_enum_header(std::stringstream& hs, c_h4_tag_enum_container& tag_enum_container)
{
	//hs << "\t//extern t_string_list " << tag_enum_container.name << "_strings;" << std::endl;
	hs << "\textern s_string_list_definition " << tag_enum_container.name << ";" << std::endl;
}

void c_h4_source_generator::create_tag_enum_source(std::stringstream& s, c_h4_tag_enum_container& tag_enum_container, bool is_header)
{
	c_h4_tag_enum& tag_enum = tag_enum_container.tag_enum;

	if (is_header)
	{
		s << "#if 0" << std::endl;
	}

	if (tag_enum.options.size() > 0)
	{
		s << "\tSTRINGS(" << tag_enum_container.name << ")" << std::endl;
		s << "\t{" << std::endl;
		for (unsigned long i = 0; i < tag_enum.options.size(); i++)
		{
			const char* option = tag_enum.options[i];
			std::string escaped_option = escape_string(option);
			if (i != tag_enum.options.size() - 1)
			{
				s << "\t\t\"" << escaped_option << "\"," << std::endl;
			}
			else
			{
				s << "\t\t\"" << escaped_option << "\"" << std::endl;
			}
		}
		s << "\t};" << std::endl;

		s << "\tSTRING_LIST(" << tag_enum_container.name << ", " << tag_enum_container.name << "_strings, _countof(" << tag_enum_container.name << "_strings));" << std::endl;
	}
	else
	{
		s << "\tSTRING_LIST(" << tag_enum_container.name << ", empty_string_list, 0);" << std::endl;
	}

	if (is_header)
	{
		s << "#endif" << std::endl;
	}

	s << std::endl;
}

void c_h4_source_generator::create_tag_block_header(std::stringstream& hs, c_h4_tag_block_container& tag_block_container)
{
	c_h4_tag_struct_container& tag_struct_container = *tag_block_container.tag_struct_container;

	hs << "\textern s_tag_block_definition " << tag_block_container.symbol_name << ";" << std::endl;
	if (/*!tag_block_container.defined_by_tag_group && */tag_block_container.use_tag_block_definition)
	{
		hs << "\textern s_tag_struct_definition " << tag_struct_container.symbol_name << "; // " << tag_block_container.symbol_name << std::endl;
	}
}
void c_h4_source_generator::create_tag_block_source(std::stringstream& s, c_h4_tag_block_container& tag_block_container)
{
	c_h4_tag_block& tag_block = tag_block_container.tag_block;
	c_h4_tag_struct_container& tag_struct_container = *tag_block_container.tag_struct_container;
	c_h4_tag_struct& tag_struct = tag_block.tag_struct;

	if (tag_block_container.use_tag_block_definition)
	{
		char persistent_identifier_buffer[256];
		snprintf(
			persistent_identifier_buffer,
			256,
			"0x%08X, 0x%08X, 0x%08X, 0x%08X",
			tag_struct.persistent_identifier.data[0],
			tag_struct.persistent_identifier.data[1],
			tag_struct.persistent_identifier.data[2],
			tag_struct.persistent_identifier.data[3]);

		char persistent_identifier_name_buffer[256];
		snprintf(
			persistent_identifier_name_buffer,
			256,
			"%s_id",
			tag_struct_container.name.c_str());
		for (char* persistent_identifier_name_pos = persistent_identifier_name_buffer; *persistent_identifier_name_pos; persistent_identifier_name_pos++)
		{
			*persistent_identifier_name_pos = toupper(*persistent_identifier_name_pos);
		}

		std::string runtime_flags = create_struct_definition_runtime_flags(tag_struct.runtime_flags, "\n\t\t");
		std::string memory_attributes = create_struct_definition_memory_attributes(tag_struct.memory_attributes.memory_type, tag_struct.memory_attributes.usage_flags, "\n\t\t");

		s << "\t#define " << persistent_identifier_name_buffer << " { " << persistent_identifier_buffer << " }" << std::nouppercase << std::endl;
		s << "\tTAG_BLOCK(" << std::endl;
		s << "\t\t" << tag_block_container.symbol_name << "," << std::endl;
		s << "\t\t\"" << tag_block_container.tag_block.display_name << "\"," << std::endl;
		s << "\t\t" << tag_block.maximum_element_count_string << "," << std::endl;
		s << "\t\t\"" << tag_struct_container.struct_name << "\"" << "," << std::endl;
		s << "\t\t" << runtime_flags << "," << std::endl;
		s << "\t\t" << memory_attributes << "," << std::endl;
		s << "\t\t" << persistent_identifier_name_buffer;
		if (tag_struct_container.tag_struct.alignment_bits)
		{
			s << "," << std::endl;
			s << "\t\t" << tag_struct_container.tag_struct.alignment_bits;
		}
		s << ")" << std::endl;
		s << "\t{" << std::endl;
		generate_tag_fields_source(s, tag_struct.tag_fields);
		s << "\t};" << std::endl;
		s << std::endl;
	}
	else
	{
		s << "\tTAG_BLOCK_FROM_STRUCT(" << std::endl;
		s << "\t\t" << tag_block_container.symbol_name << "," << std::endl;
		s << "\t\t\"" << tag_block_container.tag_block.display_name << "\"," << std::endl;
		s << "\t\t" << tag_block.maximum_element_count_string << "," << std::endl;
		s << "\t\t" << tag_struct_container.symbol_name << ");" << std::endl;
		s << std::endl;
	}
}

void c_h4_source_generator::create_tag_array_header(std::stringstream& hs, c_h4_tag_block_container& tag_block_container)
{
	c_h4_tag_struct_container& tag_struct_container = *tag_block_container.tag_struct_container;

	if (!tag_block_container.defined_by_tag_group && tag_block_container.use_tag_block_definition)
	{
		hs << "\textern s_tag_struct_definition " << tag_struct_container.symbol_name << ";" << std::endl;
	}
	hs << "\textern s_tag_array_definition " << tag_block_container.symbol_name << ";" << std::endl;


}
void c_h4_source_generator::create_tag_array_source(std::stringstream& s, c_h4_tag_block_container& tag_block_container)
{
	c_h4_tag_block& tag_block = tag_block_container.tag_block;
	c_h4_tag_struct_container& tag_struct_container = *tag_block_container.tag_struct_container;
	c_h4_tag_struct& tag_struct = tag_block.tag_struct;

	if (tag_block_container.use_tag_block_definition)
	{
		char persistent_identifier_buffer[256];
		snprintf(
			persistent_identifier_buffer,
			256,
			"0x%08X, 0x%08X, 0x%08X, 0x%08X",
			tag_struct.persistent_identifier.data[0],
			tag_struct.persistent_identifier.data[1],
			tag_struct.persistent_identifier.data[2],
			tag_struct.persistent_identifier.data[3]);

		char persistent_identifier_name_buffer[256];
		snprintf(
			persistent_identifier_name_buffer,
			256,
			"%s_id",
			tag_struct_container.name.c_str());
		for (char* persistent_identifier_name_pos = persistent_identifier_name_buffer; *persistent_identifier_name_pos; persistent_identifier_name_pos++)
		{
			*persistent_identifier_name_pos = toupper(*persistent_identifier_name_pos);
		}

		std::string runtime_flags = create_struct_definition_runtime_flags(tag_struct.runtime_flags, "\n\t\t");
		std::string memory_attributes = create_struct_definition_memory_attributes(tag_struct.memory_attributes.memory_type, tag_struct.memory_attributes.usage_flags, "\n\t\t");

		s << "\t#define " << persistent_identifier_name_buffer << " { " << persistent_identifier_buffer << " }" << std::nouppercase << std::endl;
		s << "\tTAG_ARRAY(" << std::endl;
		s << "\t\t" << tag_block_container.symbol_name << "," << std::endl;
		s << "\t\t\"" << tag_block_container.tag_block.display_name << "\"," << std::endl;
		s << "\t\t" << tag_block.maximum_element_count_string << "," << std::endl;
		s << "\t\t\"" << tag_struct_container.struct_name << "\"" << "," << std::endl;
		s << "\t\t" << runtime_flags << "," << std::endl;
		s << "\t\t" << memory_attributes << "," << std::endl;
		s << "\t\t" << persistent_identifier_name_buffer;
		if (tag_struct_container.tag_struct.alignment_bits)
		{
			s << "," << std::endl;
			s << "\t\t" << tag_struct_container.tag_struct.alignment_bits;
		}
		s << ")" << std::endl;
		s << "\t{" << std::endl;
		generate_tag_fields_source(s, tag_struct.tag_fields);
		s << "\t};" << std::endl;
		s << std::endl;
	}
	else
	{
		s << "\tTAG_ARRAY_FROM_STRUCT(" << std::endl;
		s << "\t\t" << tag_block_container.symbol_name << "," << std::endl;
		s << "\t\t\"" << tag_block_container.tag_block.display_name << "\"," << std::endl;
		s << "\t\t" << tag_block.maximum_element_count_string << "," << std::endl;
		s << "\t\t" << tag_struct_container.symbol_name << ");" << std::endl;

		s << std::endl;
	}
}

void c_h4_source_generator::create_tag_struct_header(std::stringstream& hs, c_h4_tag_struct_container& tag_struct_container)
{
	c_h4_tag_struct& tag_struct = tag_struct_container.tag_struct;

	if (tag_struct_container.is_array)
	{
		hs << "\textern s_tag_struct_definition " << tag_struct_container.symbol_name << "; // array" << std::endl;
	}
	else if (tag_struct_container.is_block)
	{
		hs << "\textern s_tag_struct_definition " << tag_struct_container.symbol_name << "; // block" << std::endl;
	}
	else if (tag_struct_container.is_tag_group)
	{
		hs << "\textern s_tag_struct_definition " << tag_struct_container.symbol_name << "; // tag group" << std::endl;
		//hs << "\textern s_tag_struct_definition " << tag_struct_container.source_name << "; // tag group" << std::endl;
	}
	else
	{
		hs << "\textern s_tag_struct_definition " << tag_struct_container.symbol_name << ";" << std::endl;
	}

}
void c_h4_source_generator::create_tag_struct_source(std::stringstream& s, c_h4_tag_struct_container& tag_struct_container)
{
	c_h4_tag_struct& tag_struct = tag_struct_container.tag_struct;

	char persistent_identifier_buffer[256];
	snprintf(
		persistent_identifier_buffer,
		256,
		"0x%08X, 0x%08X, 0x%08X, 0x%08X",
		tag_struct.persistent_identifier.data[0],
		tag_struct.persistent_identifier.data[1],
		tag_struct.persistent_identifier.data[2],
		tag_struct.persistent_identifier.data[3]);

	char persistent_identifier_name_buffer[256];
	snprintf(
		persistent_identifier_name_buffer,
		256,
		"%s_id",
		tag_struct_container.name.c_str());
	for (char* persistent_identifier_name_pos = persistent_identifier_name_buffer; *persistent_identifier_name_pos; persistent_identifier_name_pos++)
	{
		*persistent_identifier_name_pos = toupper(*persistent_identifier_name_pos);
	}

	std::string runtime_flags = create_struct_definition_runtime_flags(tag_struct.runtime_flags, "\n\t\t");
	std::string memory_flags = create_struct_definition_memory_attributes(tag_struct.memory_attributes.memory_type, tag_struct.memory_attributes.usage_flags, "\n\t\t");

	s << "\t#define " << persistent_identifier_name_buffer << " { " << persistent_identifier_buffer << " }" << std::nouppercase << std::endl;
	s << "\tTAG_STRUCT(" << std::endl;
	s << "\t\t" << tag_struct_container.name << "," << std::endl;
	s << "\t\t\"" << tag_struct_container.tag_struct.pretty_name << "\"" << "," << std::endl;
	s << "\t\t\"" << tag_struct_container.struct_name << "\"" << "," << std::endl;
	s << "\t\t" << runtime_flags << "," << std::endl;
	s << "\t\t" << memory_flags << "," << std::endl;
	s << "\t\t" << persistent_identifier_name_buffer;
	if (tag_struct_container.tag_struct.alignment_bits)
	{
		s << "," << std::endl;
		s << "\t\t" << tag_struct_container.tag_struct.alignment_bits;
	}
	s << ")" << std::endl;
	s << "\t{" << std::endl;
	generate_tag_fields_source(s, tag_struct.tag_fields);
	s << "\t};" << std::endl;
	s << std::endl;
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

void c_h4_source_generator::create_tag_reference_source(std::stringstream& s, c_h4_tag_reference_container& tag_reference_container)
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

		s << "\tTAG_REFERENCE(" << tag_reference_container.name << ", " << group_container->name_uppercase << "_TAG";
		if (!flags_string.empty())
		{
			s << ", " << flags_string;
		}
		s << ");" << std::endl;

	}
	else if (!tag_reference.tag_groups.empty())
	{
		s << "\tTAG_REFERENCE_GROUP(" << tag_reference_container.name;
		if (!flags_string.empty())
		{
			s << ", " << flags_string;
		}
		s << ")";
		s << std::endl;
		s << "\t{" << std::endl;
		for (tag_group& tag_group : tag_reference.tag_groups)
		{
			bool found_group = false;
			for (c_h4_tag_group_container* group_container : preprocessor.group_containers)
			{
				if (group_container->tag_group.group_tag.value == tag_group.value)
				{
					s << "\t\t" << group_container->name_uppercase << "_TAG," << std::endl;
					found_group = true;
					break;
				}

			}
			//ASSERT(found_group);

			if (!found_group)
			{
				std::string tag_group_string = parse_tag_group_string(tag_group);
				s << "\t\t'" << tag_group_string << "'," << std::endl;
			}
		}
		s << "\t\tINVALID_TAG," << std::endl;
		s << "\t};" << std::endl;
	}
	else
	{
		s << "\tTAG_REFERENCE(" << tag_reference_container.name << ");" << std::endl;
	}
	s << std::endl;
}

void c_h4_source_generator::generate_tag_field_flags(std::stringstream& s, c_blamlib_string_parser_v2& string_parser)
{
	unsigned long flags_written = 0;

	if (string_parser.flag_unknown0)
	{
		if (flags_written++) s << " | ";
		s << "FIELD_FLAG_UNKNOWN0";
	}
	if (string_parser.flag_read_only)
	{
		if (flags_written++) s << " | ";
		s << "FIELD_FLAG_READ_ONLY";
	}
	if (string_parser.flag_index)
	{
		if (flags_written++) s << " | ";
		s << "FIELD_FLAG_INDEX";
	}
	if (string_parser.flag_unknown3)
	{
		if (flags_written++) s << " | ";
		s << "FIELD_FLAG_UNKNOWN3";
	}
	if (string_parser.flag_pointer)
	{
		if (flags_written++) s << " | ";
		s << "FIELD_FLAG_POINTER";
	}

	if (flags_written == 0)
	{
		s << "FIELD_FLAG_NONE";
	}
}

void c_h4_source_generator::generate_tag_fields_source(std::stringstream& s, std::vector<c_h4_tag_field*>& tag_fields)
{
	for (c_h4_tag_field* tag_field : tag_fields)
	{
		const char* field_generic_type_name = h4_field_type_to_generic_field_type(tag_field->field_type);

		c_blamlib_string_parser_v2 string_parser = c_blamlib_string_parser_v2(tag_field->name);

		size_t escaped_buffer_length = tag_field->name ? strlen(tag_field->name) * 2 : 0;
		ASSERT(escaped_buffer_length < 4096);

		c_fixed_string_4096 name;
		c_fixed_string_4096 description;
		c_fixed_string_4096 units;
		c_fixed_string_4096 limits;
		c_fixed_string_4096 limits_legacy;
		c_fixed_string_4096 old_name;

		if (tag_field->name)
		{
			escape_string(string_parser.name, name, true, true);
			escape_string(string_parser.description, description, true, true);
			escape_string(string_parser.units, units, true, true);
			escape_string(string_parser.limits, limits, true, true);
			escape_string(string_parser.limits_legacy, limits_legacy, true, true);
			escape_string(string_parser.old_name, old_name, true, true);
		}

		name.trim_front();
		description.trim_front();
		units.trim_front();
		limits.trim_front();
		limits_legacy.trim_front();
		old_name.trim_front();
		
		const char* custom_field_type = nullptr;
		if (tag_field->tool_tag != 0 && tag_field->tool_tag != 0xFFFFFFFF)
		{
			custom_field_type = h4_field_id_type_to_generic_field_id_type(static_cast<e_h4_field_id_type>(tag_field->tool_tag));
		}

		bool write_limits = !limits.empty();
		bool write_units = write_limits || !units.empty();
		bool write_description = write_units || !description.empty();
		bool write_tag = custom_field_type != nullptr;
		bool write_old_name = !old_name.empty();
		bool write_flags =
			string_parser.flag_unknown0 ||
			string_parser.flag_read_only ||
			string_parser.flag_index ||
			string_parser.flag_unknown3 ||
			string_parser.flag_pointer;

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
		case _h4_field_type_custom_char_block_index:
		case _h4_field_type_custom_short_block_index:
		case _h4_field_type_custom_long_block_index:
		case _h4_field_type_data:
		case _h4_field_type_vertex_buffer:
		case _h4_field_type_non_cache_runtime_value:
		case _h4_field_type_terminator:
		case _h4_field_type_byte_integer:
		case _h4_field_type_word_integer:
		case _h4_field_type_dword_integer:
		case _h4_field_type_qword_integer:
		case _h4_field_type_useless_pad:
		{
			bool write_pointer = false; // todo

			s << "\t\t{ ";
			s << field_generic_type_name << ", ";
			s << "\"" << name.c_str() << "\"";
			if (write_description)
			{
				if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_units)
			{
				if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_limits)
			{
				if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_old_name)
			{
				s << ", MAKE_OLD_NAMES(\"" << old_name.c_str() << "\")";
			}
			if (write_flags)
			{
				s << ", ";
				generate_tag_field_flags(s, string_parser);
			}
			if (write_pointer) s << ", " << "nullptr";
			if (write_tag) s << ", " << custom_field_type;
			s << " }," << std::endl;

			break;
		}
		case _h4_field_type_long_block_flags:
		case _h4_field_type_word_block_flags:
		case _h4_field_type_byte_block_flags:
		case _h4_field_type_char_block_index:
		case _h4_field_type_short_block_index:
		case _h4_field_type_long_block_index:
		case _h4_field_type_block:
		{
			c_h4_tag_field_block* tag_field_block = dynamic_cast<c_h4_tag_field_block*>(tag_field);
			ASSERT(tag_field_block);
			ASSERT(tag_field_block->name);
			ASSERT(tag_field_block->tag_block_definition);
			c_h4_tag_block_container* tag_block_container = preprocessor.find_existing_tag_block_container(*tag_field_block->tag_block_definition);

			s << "\t\t{ ";
			s << field_generic_type_name << ", ";
			s << "\"" << name.c_str() << "\"";
			if (write_description)
			{
				if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_units)
			{
				if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_limits)
			{
				if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_old_name)
			{
				s << ", MAKE_OLD_NAMES(\"" << old_name.c_str() << "\")";
			}
			if (write_flags)
			{
				s << ", ";
				generate_tag_field_flags(s, string_parser);
			}
			s << ", &" << tag_block_container->symbol_name;
			if (write_tag) s << ", " << custom_field_type;
			s << " }," << std::endl;

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

			s << "\t\t{ ";
			s << field_generic_type_name << ", ";
			s << "\"" << name.c_str() << "\"";
			if (write_description)
			{
				if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_units)
			{
				if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_limits)
			{
				if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_old_name)
			{
				s << ", MAKE_OLD_NAMES(\"" << old_name.c_str() << "\")";
			}
			if (write_flags)
			{
				s << ", ";
				generate_tag_field_flags(s, string_parser);
			}
			s << ", &" << tag_field_enum->tag_enum->name;
			if (write_tag) s << ", " << custom_field_type;
			s << " }," << std::endl;

			break;
		}
		case _h4_field_type_custom:
		{
			//ASSERT(!write_limits);
			//ASSERT(!write_units);

			s << "\t\tFIELD_CUSTOM_EX(";
			if (!name.empty()) s << "\"" << name.c_str() << "\"";
			else s << "nullptr";
			if (!description.empty()) s << ", \"" << description.c_str() << "\"";
			else s << ", nullptr";
			s << ", "; generate_tag_field_flags(s, string_parser);
			s << ", " << (custom_field_type ? custom_field_type : "_field_id_default");
			s << ")," << std::endl;

			break;
		}
		case _h4_field_type_pad:
		{
			ASSERT(!write_limits);
			ASSERT(!write_units);

			c_h4_tag_field_pad* pad_field = dynamic_cast<c_h4_tag_field_pad*>(tag_field);

			s << "\t\tFIELD_PAD_EX(";
			if (!name.empty()) s << "\"" << name.c_str() << "\"";
			else s << "nullptr";
			if (!description.empty()) s << ", \"" << description.c_str() << "\"";
			else s << ", nullptr";
			s << ", "; generate_tag_field_flags(s, string_parser);
			s << ", " << pad_field->padding;
			s << ")," << std::endl;

			break;
		}
		case _h4_field_type_skip:
		{
			ASSERT(!write_limits);
			ASSERT(!write_units);

			c_h4_tag_field_skip* skip_field = dynamic_cast<c_h4_tag_field_skip*>(tag_field);

			s << "\t\tFIELD_SKIP(";
			if (!name.empty()) s << "\"" << name.c_str() << "\"";
			else s << "nullptr";
			if (!description.empty()) s << ", \"" << description.c_str() << "\"";
			else s << ", nullptr";
			s << ", "; generate_tag_field_flags(s, string_parser);
			s << ", " << skip_field->length;
			s << ")," << std::endl;

			break;
		}
		case _h4_field_type_explanation:
		{
			//ASSERT(!write_limits);
			//ASSERT(!write_units);

			c_h4_tag_field_explanation* explanation_field = dynamic_cast<c_h4_tag_field_explanation*>(tag_field);
			ASSERT(explanation_field);
			ASSERT(explanation_field->name);

			s << "\t\tFIELD_EXPLANATION(";
			if (write_units) s << "\"" << tag_field->name << "\"";
			else if (!name.empty()) s << "\"" << name.c_str() << "\"";
			else s << "nullptr";
			if (!description.empty()) s << ", \"" << description.c_str() << "\"";
			else s << ", nullptr";
			s << ", "; generate_tag_field_flags(s, string_parser);
			if (explanation_field->definition != nullptr)
			{
				std::string explanation = escape_string(explanation_field->definition);
				s << ", \"" << explanation << "\"";
			}
			else s << ", nullptr";
			s << ")," << std::endl;

			break;
		}
		case _h4_field_type_pageable:
		{
			c_h4_tag_resource_definition* resource_field = dynamic_cast<c_h4_tag_resource_definition*>(tag_field);
			ASSERT(resource_field);
			ASSERT(resource_field->name);
			ASSERT(resource_field->tag_resource_definition);
			c_h4_tag_struct_container* tag_struct_container = preprocessor.find_existing_tag_struct_container(resource_field->tag_resource_definition->tag_struct);
			ASSERT(tag_struct_container);

			s << "\t\t{ ";
			s << field_generic_type_name << ", ";
			s << "\"" << name.c_str() << "\"";
			if (write_description)
			{
				if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_units)
			{
				if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_limits)
			{
				if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_old_name)
			{
				s << ", MAKE_OLD_NAMES(\"" << old_name.c_str() << "\")";
			}
			if (write_flags)
			{
				s << ", ";
				generate_tag_field_flags(s, string_parser);
			}
			s << ", &" << tag_struct_container->name;
			if (write_tag) s << ", " << custom_field_type;
			s << " }," << std::endl;

			break;
		}
		case _h4_field_type_api_interop:
		{
			c_h4_tag_api_interop_definition* interop_field = dynamic_cast<c_h4_tag_api_interop_definition*>(tag_field);
			ASSERT(interop_field);
			ASSERT(interop_field->name);
			ASSERT(interop_field->tag_api_interop_definition);
			c_h4_tag_struct_container* tag_struct_container = preprocessor.find_existing_tag_struct_container(interop_field->tag_api_interop_definition->tag_struct);
			ASSERT(tag_struct_container);

			s << "\t\t{ ";
			s << field_generic_type_name << ", ";
			s << "\"" << name.c_str() << "\"";
			if (write_description)
			{
				if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_units)
			{
				if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_limits)
			{
				if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_old_name)
			{
				s << ", MAKE_OLD_NAMES(\"" << old_name.c_str() << "\")";
			}
			if (write_flags)
			{
				s << ", ";
				generate_tag_field_flags(s, string_parser);
			}
			s << ", &" << tag_struct_container->name;
			if (write_tag) s << ", " << custom_field_type;
			s << " }," << std::endl;

			break;

			break;
		}
		case _h4_field_type_tag_reference:
		{
			c_h4_tag_field_tag_reference* tag_reference_field = dynamic_cast<c_h4_tag_field_tag_reference*>(tag_field);
			ASSERT(tag_reference_field);
			ASSERT(tag_reference_field->name);
			c_h4_tag_reference_container* tag_reference_container = preprocessor.find_existing_tag_reference_container(*tag_reference_field->reference);
			ASSERT(tag_reference_container);

			s << "\t\t{ ";
			s << field_generic_type_name << ", ";
			s << "\"" << name.c_str() << "\"";
			if (write_description)
			{
				if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_units)
			{
				if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_limits)
			{
				if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_old_name)
			{
				s << ", MAKE_OLD_NAMES(\"" << old_name.c_str() << "\")";
			}
			if (write_flags)
			{
				s << ", ";
				generate_tag_field_flags(s, string_parser);
			}
			s << ", &" << tag_reference_container->name;
			if (write_tag) s << ", " << custom_field_type;
			s << " }," << std::endl;

			break;
		}
		case _h4_field_type_struct:
		{
			c_h4_tag_field_struct* struct_field = dynamic_cast<c_h4_tag_field_struct*>(tag_field);
			ASSERT(struct_field);
			ASSERT(struct_field->name);
			c_h4_tag_struct_container* tag_struct_container = preprocessor.find_existing_tag_struct_container(*struct_field->tag_struct);
			ASSERT(tag_struct_container);

			s << "\t\t{ ";
			s << field_generic_type_name << ", ";
			s << "\"" << name.c_str() << "\"";
			if (write_description)
			{
				if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_units)
			{
				if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_limits)
			{
				if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_old_name)
			{
				s << ", MAKE_OLD_NAMES(\"" << old_name.c_str() << "\")";
			}
			if (write_flags)
			{
				s << ", ";
				generate_tag_field_flags(s, string_parser);
			}
			s << ", &" << tag_struct_container->name;
			if (write_tag) s << ", " << custom_field_type;
			s << " }," << std::endl;

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

			s << "\t\t{ ";
			s << field_generic_type_name << ", ";
			s << "\"" << name.c_str() << "\"";
			if (write_description)
			{
				if (!description.empty()) s << ", " << "\"" << description.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_units)
			{
				if (!units.empty()) s << ", " << "\"" << units.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_limits)
			{
				if (!limits.empty()) s << ", " << "\"" << limits.c_str() << "\"";
				else s << ", " << "nullptr";
			}
			if (write_old_name)
			{
				s << ", MAKE_OLD_NAMES(\"" << old_name.c_str() << "\")";
			}
			if (write_flags)
			{
				s << ", ";
				generate_tag_field_flags(s, string_parser);
			}
			s << ", &" << tag_block_container->symbol_name;
			if (write_tag) s << ", " << custom_field_type;
			s << " }," << std::endl;
			break;
		}
		default:
			throw; // unexpected type
		}
	}
	s << "\t\t{ _field_terminator }" << std::endl;
}

std::string c_h4_source_generator::create_struct_definition_runtime_flags(unsigned long runtime_flags, const char* new_line_format)
{
	char runtime_flags_buffer[2048] = { 0 };
	{
		char* runtime_flags_buffer_pos = runtime_flags_buffer; // unsafe
		// 
		//unsigned long default_bits = _h4_tag_field_set_unknown0 |
		//	_h4_tag_field_set_unknown1 |
		//	_h4_tag_field_set_has_inlined_children_with_placement_new_bit |
		//	_h4_tag_field_set_unknown5 |
		//	_h4_tag_field_set_unknown7 |
		//	_h4_tag_field_set_delete_recursively_bit |
		//	_h4_tag_field_set_postprocess_recursively_bit |
		//	_h4_tag_field_set_unknown15 |
		//	_h4_tag_field_set_has_level_specific_fields_bit |
		//	_h4_tag_field_set_unknown18;

		bool has_default_bits = false; // #todo is this a thing?

		unsigned long default_bits =
			1 << _h4_tag_field_set_unknown0 |
			1 << _h4_tag_field_set_unknown1 |
			1 << _h4_tag_field_set_unknown5 |
			1 << _h4_tag_field_set_delete_recursively_bit |
			1 << _h4_tag_field_set_postprocess_recursively_bit;

		//bool has_default_bits = (runtime_flags & default_bits) == default_bits;
		//if (has_default_bits)
		//{
		//	runtime_flags_buffer_pos += sprintf(runtime_flags_buffer, "_h4_tag_field_set_default_bits");
		//}

		{
			bool make_new_line = false;
			unsigned long line_characters = 0;
			for (unsigned long runtime_flag = 0; runtime_flag < k_num_h4_runtime_flags; runtime_flag++)
			{
				unsigned long bit = 1 << runtime_flag;

				if (has_default_bits && default_bits & bit)
				{
					continue;
				}

				if (runtime_flags & bit)
				{
					const char* runtime_flag_name = h4_tag_field_set_bit_to_field_set_bit_name(static_cast<e_h4_tag_field_set_bit>(runtime_flag));
					const char* runtime_flag_macro = h4_tag_field_set_bit_to_field_set_bit_macro(static_cast<e_h4_tag_field_set_bit>(runtime_flag));

					if (runtime_flags_buffer_pos != runtime_flags_buffer)
					{
						unsigned long length0 = sprintf(runtime_flags_buffer_pos, " | ");
						runtime_flags_buffer_pos += length0;
						line_characters += length0;

						if (make_new_line)
						{
							unsigned long length1 = sprintf(runtime_flags_buffer_pos, "%s", new_line_format);
							runtime_flags_buffer_pos += length1;
							line_characters = 0;
							make_new_line = false;
						}
					}

					//unsigned long length = sprintf(runtime_flags_buffer_pos, "c_flags<e_tag_field_set_bit>(%s)", runtime_flag_name);
					unsigned long length = sprintf(runtime_flags_buffer_pos, "%s", runtime_flag_macro);
					runtime_flags_buffer_pos += length;
					line_characters += length;

					if (line_characters >= 100)
					{
						make_new_line = true;
					}
				}
			}
		}
	}

	if (runtime_flags_buffer[0] == 0)
	{
		//sprintf(runtime_flags_buffer, "c_flags<e_tag_field_set_bit>()");
		sprintf(runtime_flags_buffer, "SET_DEFAULT");
	}

	return runtime_flags_buffer;
}

std::string c_h4_source_generator::create_struct_definition_memory_attributes(unsigned long memory_type, unsigned long usage_flags, const char* new_line_format)
{
	const char* comment = nullptr;
	if (memory_type == 0 && usage_flags == 0)
	{
		comment = "k_read_only_tag_memory_attributes";
		//return "TAG_MEMORY_ATTRIBUTES_READ_ONLY";
	}
	if (memory_type == 0 && TEST_BIT(usage_flags, _h4_tag_memory_writeable_bit))
	{
		comment = "k_read_write_tag_memory_attributes";
		//return "TAG_MEMORY_ATTRIBUTES_READ_WRITE";
	}
	if (memory_type == 0 && TEST_BIT(usage_flags, _h4_tag_memory_physical_bit))
	{
		comment = "k_physical_read_only_tag_memory_attributes";
		//return "TAG_MEMORY_ATTRIBUTES_PHYSICAL_READ_ONLY";
	}
	if (memory_type == 0 && TEST_BIT(usage_flags, _h4_tag_memory_physical_bit) && TEST_BIT(usage_flags, _h4_tag_memory_writeable_bit))
	{
		comment = "k_physical_read_write_tag_memory_attributes";
		//return "TAG_MEMORY_ATTRIBUTES_PHYSICAL_READ_WRITE";
	}
	if (memory_type == 0 && TEST_BIT(usage_flags, _h4_tag_memory_physical_bit) && TEST_BIT(usage_flags, _h4_tag_memory_writeable_bit) && TEST_BIT(usage_flags, _h4_tag_memory_combined_bit))
	{
		comment = "k_physical_write_combined_tag_memory_attributes";
		//return "TAG_MEMORY_ATTRIBUTES_PHYSICAL_WRITE_COMBINED";
	}

	const char* allocation_type_name = h4_memory_allocation_type_to_memory_allocation_type_name(static_cast<e_h4_tag_memory_allocation_type>(memory_type));
	const char* allocation_type_macro = h4_memory_allocation_type_to_memory_allocation_type_macro(static_cast<e_h4_tag_memory_allocation_type>(memory_type));

	char memory_usage_bits_buffer[2048] = { 0 };
	{
		char* memory_usage_bits_buffer_pos = memory_usage_bits_buffer; // unsafe

		{
			bool make_new_line = false;
			size_t line_characters = strlen(allocation_type_macro);
			for (unsigned long usage_flag = 0; usage_flag < k_num_h4_tag_memory_usage_bits; usage_flag++)
			{
				unsigned long usage_flag_bit = 1 << usage_flag;

				if (usage_flags & usage_flag_bit)
				{
					const char* usage_flag_name = h4_memory_usage_bit_to_memory_usage_bit_name(static_cast<e_h4_tag_memory_usage_bit>(usage_flag));
					const char* usage_flag_macro = h4_memory_usage_bit_to_memory_usage_bit_macro(static_cast<e_h4_tag_memory_usage_bit>(usage_flag));

					if (memory_usage_bits_buffer_pos != memory_usage_bits_buffer)
					{
						unsigned long length0 = sprintf(memory_usage_bits_buffer_pos, " | ");
						memory_usage_bits_buffer_pos += length0;
						line_characters += length0;

						if (make_new_line)
						{
							unsigned long length1 = sprintf(memory_usage_bits_buffer_pos, "%s", new_line_format);
							memory_usage_bits_buffer_pos += length1;
							line_characters = 0;
							make_new_line = false;
						}
					}

					//unsigned long length = sprintf(memory_usage_bits_buffer_pos, "c_flags<e_tag_memory_usage_bit>(%s)", usage_flag_name);
					unsigned long length = sprintf(memory_usage_bits_buffer_pos, "%s", usage_flag_macro);
					memory_usage_bits_buffer_pos += length;
					line_characters += length;

					if (line_characters >= 100)
					{
						make_new_line = true;
					}
				}
			}
		}
	}

	if (memory_usage_bits_buffer[0] == 0)
	{
		//sprintf(memory_usage_bits_buffer, "c_flags<e_tag_memory_usage_bit>()");
		sprintf(memory_usage_bits_buffer, "TAG_MEMORY_USAGE_READ_ONLY");
	}

	char memory_attributes_buffer[2048] = { 0 };
	char* memory_attributes_buffer_pos = memory_attributes_buffer;
	memory_attributes_buffer_pos += sprintf(memory_attributes_buffer_pos, "TAG_MEMORY_ATTRIBUTES(%s, %s)", allocation_type_macro, memory_usage_bits_buffer);
	if (comment)
	{
		// memory_attributes_buffer_pos += sprintf(memory_attributes_buffer_pos, " // %s", comment);
	}
	return memory_attributes_buffer;
}
