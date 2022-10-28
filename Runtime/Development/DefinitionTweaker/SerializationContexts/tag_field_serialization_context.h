#pragma once

class c_serialization_error;
class c_tag_serialization_context;
class c_tag_struct_serialization_context;
class c_tag_block_serialization_context;

class c_tag_field_serialization_context :
	public c_serialization_context
{
public:
	c_tag_struct_serialization_context& parent_tag_struct_serialization_context;
	const char* field_data;
	unsigned int field_size;
	c_tag_struct_serialization_context* tag_struct_serialization_context;
	c_tag_block_serialization_context* tag_block_serialization_context;

	// copies from c_runtime_tag_field_definition
	blofeld::e_field field_type;
	std::string name;
protected:
	c_runtime_tag_field_definition& runtime_tag_field_definition;
public:

	c_tag_field_serialization_context() = delete;
	c_tag_field_serialization_context(c_tag_field_serialization_context const&) = delete;
	c_tag_field_serialization_context(
		c_tag_struct_serialization_context& serialization_context,
		const char* field_data,
		c_runtime_tag_field_definition& runtime_tag_field_definition);
	~c_tag_field_serialization_context();

	virtual void read() override;
	virtual void traverse() override;
	virtual void render_tree() override;
	static unsigned int calculate_field_size(c_serialization_context& serialization_context, c_runtime_tag_field_definition& runtime_field);
};
