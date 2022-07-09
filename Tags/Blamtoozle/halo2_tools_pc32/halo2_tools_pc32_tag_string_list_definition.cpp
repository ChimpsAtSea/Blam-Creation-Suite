#include "blamtoozle-private-pch.h"

#define tag_definition_manager static_cast<c_halo2_tools_pc32_tag_definition_manager&>(tag_definition_manager)

template<> void byteswap_inplace(s_halo2_tools_pc32_string_list_definition& value)
{
	//byteswap_inplace(value.name_address);
	byteswap_inplace(value.option_count);
	byteswap_inplace(value.options_address);
	//byteswap_inplace(value.unknown0);
	//byteswap_inplace(value.unknown1);
	//byteswap_inplace(value.file_path);
	//byteswap_inplace(value.line_number);
}

template<> void byteswap_inplace(s_halo2_tools_pc32_string_list_entry_definition& value)
{
	byteswap_inplace(value.option_address);
}

c_halo2_tools_pc32_string_list_definition::c_halo2_tools_pc32_string_list_definition(c_halo2_tools_pc32_tag_definition_manager& _tag_definition_manager, ptr32 _definition_address) :
	c_blamtoozle_string_list_definition(_tag_definition_manager),
	definition_address(_definition_address),
	string_list_definition(tag_definition_manager.read_structure<s_halo2_tools_pc32_string_list_definition>(_definition_address)),
	name(),
	code_symbol_name(name)
{
	if (name.empty())
	{
		name = "unnamed_enum";
		code_symbol_name = name;
	}
	tag_definition_manager.format_code_symbol_name_uid(code_symbol_name);

	const s_halo2_tools_pc32_string_list_entry_definition* option_entries = tag_definition_manager.va_to_pointer2<s_halo2_tools_pc32_string_list_entry_definition>(string_list_definition.options_address);
	for (unsigned long option_index = 0; option_index < string_list_definition.option_count; option_index++)
	{
		s_halo2_tools_pc32_string_list_entry_definition option = option_entries[option_index];
		tag_definition_manager.byteswap_inplace(option);
		const char* option_string = tag_definition_manager.va_to_pointer(option.option_address);
		if (option_string == nullptr)
		{
			option_string = "";
		}
		options.push_back(option_string); // #TODO: Create a c_blamtoozle_string_list_entry_definition
	}
	
}

c_halo2_tools_pc32_string_list_definition::~c_halo2_tools_pc32_string_list_definition()
{

}

const char* c_halo2_tools_pc32_string_list_definition::get_name()
{
	return name.c_str();
}

const char* c_halo2_tools_pc32_string_list_definition::get_code_symbol_name()
{
	return code_symbol_name.c_str();
}
