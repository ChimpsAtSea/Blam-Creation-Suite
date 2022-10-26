#pragma once

class c_runtime_tag_field
{
public:
	blofeld::e_field field_type;
	std::string name;
	std::string description;
	std::string units;
	std::string limits;
	std::vector< std::string> old_names;
	uint32_t flags;
	c_runtime_tag_block_definition* block_definition;
	c_runtime_tag_struct_definition* struct_definition;
	c_runtime_tag_array_definition* array_definition;
	c_runtime_string_list_definition* string_list_definition;
	c_runtime_tag_reference_definition* tag_reference_definition;
	c_runtime_tag_resource_definition* tag_resource_definition;
	c_runtime_tag_api_interop_definition* tag_interop_definition;
	c_runtime_tag_data_definition* tag_data_definition;
	c_runtime_tag_block_index_custom_search_definition* block_index_custom_search_definition;
	std::string explanation;
	uint32_t padding;
	uint32_t length;
	blofeld::s_tag_field_versioning versioning;
	uint32_t custom_type;
	const blofeld::s_tag_field* original_field;
	c_runtime_tag_definitions& runtime_tag_definitions;

	c_runtime_tag_field() = delete;
	c_runtime_tag_field(c_runtime_tag_field const&) = delete;
	c_runtime_tag_field(c_runtime_tag_definitions& _runtime_tag_definitions);
	c_runtime_tag_field(c_runtime_tag_definitions& _runtime_tag_definitions, c_runtime_tag_field const& source);
	c_runtime_tag_field(c_runtime_tag_definitions& _runtime_tag_definitions, const blofeld::s_tag_field& field);
};
