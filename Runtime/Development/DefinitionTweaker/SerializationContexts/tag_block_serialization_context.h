#pragma once

class c_serialization_error;
class c_tag_field_serialization_context;
class c_tag_serialization_context;

class c_tag_block_serialization_context :
	public c_serialization_context
{
public:
	c_tag_serialization_context& tag_serialization_context;
	const void* const block_data;
	unsigned int struct_size;
	unsigned int block_size;
	std::vector<c_tag_struct_serialization_context*> struct_serialization_contexts;
	c_runtime_tag_block_definition& block_definition;
	std::string name;

	c_tag_block_serialization_context(
		c_serialization_context& serialization_context,
		c_tag_serialization_context& tag_serialization_context,
		const void* block_data,
		c_runtime_tag_block_definition& block_definition);
	c_tag_block_serialization_context(c_tag_struct_serialization_context const&) = delete;
	~c_tag_block_serialization_context();

	void read();
	void traverse();
	void render_tree();
};
