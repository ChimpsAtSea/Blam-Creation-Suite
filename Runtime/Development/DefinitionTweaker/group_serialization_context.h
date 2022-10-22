#pragma once

class c_runtime_tag_group_definition;
class c_tag_serialization_context;

class c_group_serialization_context
{
public:
	c_group_serialization_context(c_runtime_tag_group_definition& _tag_group);

	void post();

	e_serialization_error_type max_serialization_error_type;
	c_runtime_tag_group_definition& tag_group;
	std::vector<c_tag_serialization_context*> serialization_contexts;
};
