#pragma once

class c_serialization_error;
class c_tag_serialization_context;

class c_tag_field_serialization_context
{
public:
	c_tag_serialization_context& serialization_context;
	std::vector<c_serialization_error*> serialization_errors;

	c_tag_field_serialization_context(c_tag_serialization_context& serialization_context);
	c_tag_field_serialization_context(c_tag_field_serialization_context const&) = delete;
	~c_tag_field_serialization_context();
};
