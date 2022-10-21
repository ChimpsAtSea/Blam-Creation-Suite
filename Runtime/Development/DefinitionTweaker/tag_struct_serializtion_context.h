#pragma once

class c_serializtion_error;
class c_tag_field_serializtion_context;
class c_tag_serialization_context;

class c_tag_struct_serializtion_context
{
public:
	c_tag_serialization_context& serialization_context;
	unsigned int expected_struct_size;
	unsigned int struct_size;
	const blofeld::s_tag_struct_definition& struct_definition;
	std::vector<c_tag_field_serializtion_context*> field_serializtion_contexts;
	std::vector<c_serializtion_error*> serialization_errors;

	c_tag_struct_serializtion_context(
		c_tag_serialization_context& _serialization_context,
		const blofeld::s_tag_struct_definition& _struct_definition,
		unsigned int _expected_struct_size = UINT_MAX);
	c_tag_struct_serializtion_context(c_tag_struct_serializtion_context const&) = delete;
	~c_tag_struct_serializtion_context();
	unsigned int read();
	unsigned int traverse();
};
