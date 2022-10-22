#pragma once

class c_serialization_error;
class c_tag_field_serialization_context;
class c_tag_serialization_context;

class c_tag_struct_serialization_context
{
public:
	c_tag_serialization_context& serialization_context;
	unsigned int expected_struct_size;
	unsigned int struct_size;
	const blofeld::s_tag_struct_definition& struct_definition;
	std::vector<c_tag_field_serialization_context*> field_serialization_contexts;
	std::vector<c_serialization_error*> serialization_errors;

	c_tag_struct_serialization_context(
		c_tag_serialization_context& _serialization_context,
		const blofeld::s_tag_struct_definition& _struct_definition,
		unsigned int _expected_struct_size = UINT_MAX);
	c_tag_struct_serialization_context(c_tag_struct_serialization_context const&) = delete;
	~c_tag_struct_serialization_context();
	unsigned int read();
	unsigned int traverse();
};
