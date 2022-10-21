#pragma once

class c_serializtion_error;
class c_tag_serialization_context;

class c_tag_field_serializtion_context
{
public:
	c_tag_serialization_context& serialization_context;
	std::vector<c_serializtion_error*> serialization_errors;

	c_tag_field_serializtion_context(c_tag_serialization_context& serialization_context);
	c_tag_field_serializtion_context(c_tag_field_serializtion_context const&) = delete;
	~c_tag_field_serializtion_context();
};
