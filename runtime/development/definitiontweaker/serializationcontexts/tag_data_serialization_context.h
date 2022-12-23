#pragma once

class c_serialization_error;
class c_tag_field_serialization_context;
class c_tag_serialization_context;

class c_tag_data_serialization_context :
	public c_serialization_context
{
public:
	c_tag_serialization_context& tag_serialization_context;
	::s_tag_data const& tag_data;
	std::vector<c_tag_struct_serialization_context*> struct_serialization_contexts;
	c_runtime_tag_data_definition& runtime_tag_data_definition;

	c_tag_data_serialization_context(
		c_serialization_context& serialization_context,
		c_tag_serialization_context& tag_serialization_context,
		::s_tag_data const& tag_data,
		c_runtime_tag_data_definition& data_definition);
	c_tag_data_serialization_context(c_tag_struct_serialization_context const&) = delete;
	~c_tag_data_serialization_context();

	virtual BCS_RESULT read() override final;
	virtual BCS_RESULT traverse() override final;
	virtual BCS_RESULT calculate_memory() override final;
	void render_tree();
};
