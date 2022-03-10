#include "blamboozlelib-private-pch.h"

std::map<ptr64, c_h3_block_index_custom_search_definition*> c_h3_block_index_custom_search_definition::block_index_custom_search_definitions;

c_h3_block_index_custom_search_definition::c_h3_block_index_custom_search_definition(const char* data, const s_h3_block_index_custom_search_definition& definition_header) :
	name(h3_pa_to_pointer(data, definition_header.name_address)),
	code_name(h3_convert_to_code_name(name)),
	block_index_custom_search_definition(definition_header)
{
	unsigned long existing_count = 0;
	for (auto& keyval : block_index_custom_search_definitions) if (name == keyval.second->name) existing_count++;
	if (existing_count > 1)
	{
		code_name += "$";
		char existing_count_buffer[32];
		_itoa(existing_count, existing_count_buffer, 10);
		code_name += existing_count_buffer;
	}

	if (code_name == "void")
	{
		code_name = "_void";
	}
}

c_h3_block_index_custom_search_definition* c_h3_block_index_custom_search_definition::h3_get_block_index_custom_search_definition(const char* data, ptr64 virtual_address)
{
	std::map<ptr64, c_h3_block_index_custom_search_definition*>::iterator tag_block_definition_iterator = block_index_custom_search_definitions.find(virtual_address);

	if (tag_block_definition_iterator != block_index_custom_search_definitions.end())
	{
		return tag_block_definition_iterator->second;
	}

	const s_h3_block_index_custom_search_definition* _block_index_custom_search_definition = reinterpret_cast<const s_h3_block_index_custom_search_definition*>(h3_pa_to_pointer(data, virtual_address));
	ASSERT(_block_index_custom_search_definition != nullptr);

	c_h3_block_index_custom_search_definition* tag_block_definition = reinterpret_cast<c_h3_block_index_custom_search_definition*>(new char[sizeof(c_h3_block_index_custom_search_definition)]);

	block_index_custom_search_definitions[virtual_address] = tag_block_definition;

	tag_block_definition = new(tag_block_definition) c_h3_block_index_custom_search_definition(data, *_block_index_custom_search_definition);

	return tag_block_definition;
}
