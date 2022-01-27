#include "blamboozlelib-private-pch.h"

std::map<ptr32, c_reach_x360_tag_struct_definition*> c_reach_x360_tag_struct_definition::tag_struct_definitions;

c_reach_x360_tag_struct_definition::c_reach_x360_tag_struct_definition(const char* data, const s_reach_x360_tag_struct_definition& definition_header) :
	pretty_name(reach_x360_pa_to_pointer(data, definition_header.pretty_name_address)),
	name(reach_x360_pa_to_pointer(data, definition_header.name_address)),
	code_name(reach_x360_convert_to_code_name(name)),
	structure_size(definition_header.structure_size),
	alignment_bits(definition_header.alignment_bits),
	struct_definition(definition_header),
	persistent_identifier(definition_header.persistent_identifier),
	//block_definition(nullptr),
	//array_definition(nullptr),
	fields()
{

	unsigned long existing_count = 0;
	for (auto& keyval : tag_struct_definitions) if (name == keyval.second->name) existing_count++;
	if (existing_count > 1)
	{
		code_name += "$";
		char existing_count_buffer[32];
		_itoa(existing_count, existing_count_buffer, 10);
		code_name += existing_count_buffer;
	}

	ptr32 fields_address = definition_header.fields_address;
	const s_reach_x360_tag_field* const field_definitions = (const s_reach_x360_tag_field*)reach_x360_pa_to_pointer(data, fields_address);

	const s_reach_x360_tag_field* field_definition = field_definitions;
	ASSERT(field_definition);
	do
	{
		c_reach_x360_tag_field* field_wrapper = new c_reach_x360_tag_field(data, *field_definition);
		fields.push_back(field_wrapper);
	} while ((field_definition++)->field_type != _reach_x360_field_type_terminator);


	if (name == "shader_contrail_struct_definition")
	{
		debug_point;
	}
}

c_reach_x360_tag_struct_definition::~c_reach_x360_tag_struct_definition()
{
	for (c_reach_x360_tag_field* field_wrapper : fields)
	{
		delete field_wrapper;
	}
}

c_reach_x360_tag_struct_definition* c_reach_x360_tag_struct_definition::reach_x360_get_tag_struct_definition(const char* data, ptr32 virtual_address)
{
	std::map<ptr32, c_reach_x360_tag_struct_definition*>::iterator tag_block_definition_iterator = tag_struct_definitions.find(virtual_address);

	if (tag_block_definition_iterator != tag_struct_definitions.end())
	{
		return tag_block_definition_iterator->second;
	}

	const s_reach_x360_tag_struct_definition* _tag_struct_definition = reinterpret_cast<const s_reach_x360_tag_struct_definition*>(reach_x360_pa_to_pointer(data, virtual_address));

	c_reach_x360_tag_struct_definition* tag_block_definition = reinterpret_cast<c_reach_x360_tag_struct_definition*>(new char[sizeof(c_reach_x360_tag_struct_definition)]);

	tag_struct_definitions[virtual_address] = tag_block_definition;

	tag_block_definition = new(tag_block_definition) c_reach_x360_tag_struct_definition(data, *_tag_struct_definition);

	return tag_block_definition;
}
