#pragma once

class c_runtime_tag_definitions;

class c_runtime_tag_struct_definition
{
public:
	std::string pretty_name;
	std::string name;
	std::string struct_name;
	c_flags<blofeld::e_tag_field_set_bit> runtime_flags;
	blofeld::c_tag_memory_attributes memory_attributes;
	blofeld::s_tag_persistent_identifier persistent_identifier;
	std::vector<c_runtime_tag_field*> fields;
	int alignment_bits;
	const blofeld::s_tag_struct_definition* original_tag_struct_definition;
	c_runtime_tag_definitions& runtime_tag_definitions;

	c_runtime_tag_struct_definition(c_runtime_tag_definitions& _runtime_tag_definitions);
	c_runtime_tag_struct_definition(c_runtime_tag_definitions& _runtime_tag_definitions, const blofeld::s_tag_struct_definition& tag_struct_definition);
	~c_runtime_tag_struct_definition();
};
