#include "blamboozlelib-private-pch.h"

std::map<ptr64, c_h3_tag_struct_definition*> c_h3_tag_struct_definition::tag_struct_definitions;

c_h3_tag_struct_definition::c_h3_tag_struct_definition(const char* data, const s_h3_tag_struct_definition& definition_header) :
	pretty_name(h3_pa_to_pointer(data, definition_header.type.pretty_name_address)),
	name(h3_pa_to_pointer(data, definition_header.type.name_address)),
	code_name(h3_convert_to_code_name(name)),
	structure_size(definition_header.type.structure_size),
	alignment_bits(definition_header.type.alignment_bits),
	struct_definition(definition_header),
	persistent_identifier
	{
		definition_header.type.persistent_identifier.identifier_part_0,
		definition_header.type.persistent_identifier.identifier_part_1,
		definition_header.type.persistent_identifier.identifier_part_2,
		definition_header.type.persistent_identifier.identifier_part_3,
	},
	//block_definition(nullptr),
	//array_definition(nullptr),
	fields()
{
	if (name == "FunctionDefinition")
	{
		debug_point;
	}
	unsigned long existing_count = 0;
	for (auto& keyval : tag_struct_definitions) if (name == keyval.second->name) existing_count++;
	if (existing_count > 1)
	{
		code_name += "$";
		char existing_count_buffer[32];
		_itoa(existing_count, existing_count_buffer, 10);
		code_name += existing_count_buffer;
	}

	const s_h3_tag_field* const field_definitions = (const s_h3_tag_field*)h3_pa_to_pointer(data, definition_header.type.fields_address);

	const s_h3_tag_field* field_definition = field_definitions;
	do
	{
		c_h3_tag_field* field_wrapper = new() c_h3_tag_field(data, *field_definition);
		fields.push_back(field_wrapper);
	} while ((field_definition++)->field_type != _h3_field_type_terminator_X);
}

c_h3_tag_struct_definition::~c_h3_tag_struct_definition()
{
	for (c_h3_tag_field* field_wrapper : fields)
	{
		delete field_wrapper;
	}
}

c_h3_tag_struct_definition* c_h3_tag_struct_definition::h3_get_tag_struct_definition(const char* data, ptr64 virtual_address)
{
	std::map<ptr64, c_h3_tag_struct_definition*>::iterator tag_block_definition_iterator = tag_struct_definitions.find(virtual_address);

	if (tag_block_definition_iterator != tag_struct_definitions.end())
	{
		return tag_block_definition_iterator->second;
	}

	const s_h3_tag_struct_definition* _tag_struct_definition = reinterpret_cast<const s_h3_tag_struct_definition*>(h3_pa_to_pointer(data, virtual_address));

	c_h3_tag_struct_definition* tag_block_definition = reinterpret_cast<c_h3_tag_struct_definition*>(new char[sizeof(c_h3_tag_struct_definition)]);

	tag_struct_definitions[virtual_address] = tag_block_definition;

	tag_block_definition = new(tag_block_definition) c_h3_tag_struct_definition(data, *_tag_struct_definition);

	return tag_block_definition;
}
