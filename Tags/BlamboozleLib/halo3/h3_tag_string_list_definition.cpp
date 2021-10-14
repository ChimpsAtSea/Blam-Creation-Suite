#include "blamboozlelib-private-pch.h"

std::map<ptr64, c_h3_string_list_definition*> string_list_definitions;

c_h3_string_list_definition::c_h3_string_list_definition(const char* guerilla_data, const s_h3_string_list_definition& string_list_definition) :
	options(),
	string_list_definition(string_list_definition),
	name(h3_pa_to_pointer(guerilla_data, string_list_definition.name_address)),
	code_name()
{
	ASSERT(string_list_definition.padding == 0);

	if (name.empty())
	{
		name = "unnamed_enum";
	}

	const ptr64* options_addresses = reinterpret_cast<const ptr64*>(h3_pa_to_pointer(guerilla_data, string_list_definition.options_address));
	for (unsigned long option_index = 0; option_index < string_list_definition.option_count; option_index++)
	{
		ptr64 option_address = options_addresses[option_index];
		const char* option = h3_pa_to_pointer(guerilla_data, option_address);

		options.push_back(option);
	}

	code_name = h3_convert_to_code_name(name.c_str()).c_str();
	unsigned long existing_count = 0;
	for (auto& keyval : string_list_definitions) if (name == keyval.second->name) existing_count++;
	if (existing_count > 1)
	{
		code_name += "$";
		
		char existing_count_buffer[32];
		_itoa(existing_count, existing_count_buffer, 10);
		code_name += existing_count_buffer;
	}

	debug_point;
}

c_h3_string_list_definition* h3_get_string_list_definition(const char* guerilla_data, ptr64 virtual_address)
{
	std::map<ptr64, c_h3_string_list_definition*>::iterator tag_block_definition_iterator = string_list_definitions.find(virtual_address);

	if (tag_block_definition_iterator != string_list_definitions.end())
	{
		return tag_block_definition_iterator->second;
	}

	const s_h3_string_list_definition* _string_list_definition = reinterpret_cast<const s_h3_string_list_definition*>(h3_pa_to_pointer(guerilla_data, virtual_address));
	ASSERT(_string_list_definition != nullptr);

	c_h3_string_list_definition* string_list_definition = reinterpret_cast<c_h3_string_list_definition*>(new char[sizeof(c_h3_string_list_definition)]);

	string_list_definitions[virtual_address] = string_list_definition;

	string_list_definition = new(string_list_definition) c_h3_string_list_definition(guerilla_data, *_string_list_definition);

	return string_list_definition;
}
