#include "blamtoozle-private-pch.h"

c_blamtoozle_tag_definition_manager::c_blamtoozle_tag_definition_manager() :
	c_blamtoozle_tag_definition_reader(),
	is_big_endian(),
	code_symbol_counts(),
	tag_group_definitions(),
	tag_struct_definitions(),
	tag_block_definitions(),
	tag_reference_definitions(),
	tag_array_definitions(),
	string_list_definitions(),
	tag_resource_definitions(),
	tag_data_definitions(),
	tag_api_interop_definitions(),
	block_index_custom_search_definitions(),
	tag_group_definitions_lookup(),
	tag_struct_definitions_lookup(),
	tag_block_definitions_lookup(),
	tag_reference_definitions_lookup(),
	tag_array_definitions_lookup(),
	string_list_definitions_lookup(),
	tag_resource_definitions_lookup(),
	tag_data_definitions_lookup(),
	tag_api_interop_definitions_lookup(),
	block_index_custom_search_definitions_lookup()
{

}

c_blamtoozle_tag_definition_manager::~c_blamtoozle_tag_definition_manager()
{
	for (auto& definition : tag_group_definitions					) delete definition;
	for (auto& definition : tag_struct_definitions					) delete definition;
	for (auto& definition : tag_block_definitions					) delete definition;
	for (auto& definition : tag_reference_definitions				) delete definition;
	for (auto& definition : tag_array_definitions					) delete definition;
	for (auto& definition : string_list_definitions					) delete definition;
	for (auto& definition : tag_resource_definitions				) delete definition;
	for (auto& definition : tag_data_definitions					) delete definition;
	for (auto& definition : tag_api_interop_definitions				) delete definition;
	for (auto& definition : block_index_custom_search_definitions	) delete definition;
}


void c_blamtoozle_tag_definition_manager::set_is_big_endian(bool _is_big_endian)
{
	is_big_endian = _is_big_endian;
}

void c_blamtoozle_tag_definition_manager::format_structure_type_name(std::string& structure_type_name)
{
	if (structure_type_name == "s_tag_reference") structure_type_name = "s_tag_references";
	if (structure_type_name == "s_string_id") structure_type_name = "s_string_ids";
}

void c_blamtoozle_tag_definition_manager::format_code_symbol_name(std::string& code_symbol_name)
{
	// #TODO: This is messy af

	c_fixed_string_1024 str = code_symbol_name.c_str();
	str.lowercase();
	str.replace(' ', '_');
	str.replace('/', '_');
	str.replace('\\', '_');
	str.replace('-', '_');
	str.replace('+', '_');
	str.replace('&', '_');
	str.replace('|', '_');
	str.replace('>', '_');
	str.replace('<', '_');
	str.replace('=', '_');
	str.remove('*');
	str.remove('{');
	str.remove('}');
	str.remove('@');
	str.remove('(');
	str.remove(')');
	str.remove('.');
	str.remove(',');
	str.remove('\'');
	str.remove(':');
	str.remove(';');
	str.remove('\"');
	code_symbol_name = str;

#define banned_keyword(keyword) if (code_symbol_name == keyword) code_symbol_name = "_" keyword 

	banned_keyword("void");

#undef banned_keyword
}

void c_blamtoozle_tag_definition_manager::format_code_symbol_name_uid(std::string& code_symbol_name)
{
	format_code_symbol_name(code_symbol_name);

	uint32_t existing_count = ++code_symbol_counts[code_symbol_name];
	if (existing_count > 1)
	{
		code_symbol_name += "$";
		char existing_count_buffer[32];
		_itoa(existing_count, existing_count_buffer, 10);
		code_symbol_name += existing_count_buffer;
	}
}

c_blamtoozle_tag_group_definition* c_blamtoozle_tag_definition_manager::get_tag_group_definition_by_group_tag(tag group_tag)
{
	if (group_tag == 0xFFFFFFFFu) return nullptr;

	for (c_blamtoozle_tag_group_definition* tag_group_definition : tag_group_definitions)
	{
		if (tag_group_definition->get_group_tag() == group_tag)
		{
			return tag_group_definition;
		}
	}
	return nullptr;
}

c_blamtoozle_tag_struct_definition* c_blamtoozle_tag_definition_manager::get_tag_struct_definition_by_persistent_id(blofeld::s_tag_persistent_identifier persistent_identifier)
{

	for (c_blamtoozle_tag_struct_definition* tag_struct_definition : tag_struct_definitions)
	{
		if (tag_struct_definition->get_persistent_identifier() == persistent_identifier)
		{
			return tag_struct_definition;
		}
	}
	return nullptr;
}
