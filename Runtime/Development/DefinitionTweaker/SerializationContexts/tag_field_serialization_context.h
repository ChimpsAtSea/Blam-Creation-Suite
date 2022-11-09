#pragma once

class c_serialization_error;
class c_tag_serialization_context;
class c_tag_struct_serialization_context;
class c_tag_block_serialization_context;
class c_tag_array_serialization_context;
class c_tag_data_serialization_context;
class c_tag_resource_serialization_context;

class c_tag_field_serialization_context :
	public c_serialization_context
{
protected:
	c_runtime_tag_field_definition& runtime_tag_field_definition;
public:
	union
	{
		void* field_serialization_context;
		c_tag_struct_serialization_context* tag_struct_serialization_context;
		c_tag_block_serialization_context* tag_block_serialization_context;
		c_tag_array_serialization_context* tag_array_serialization_context;
		c_tag_data_serialization_context* tag_data_serialization_context;
		c_tag_resource_serialization_context* tag_resource_serialization_context;
	};
	blofeld::e_field field_type;
	unsigned int field_size;

public:

	c_tag_field_serialization_context() = delete;
	c_tag_field_serialization_context(c_tag_field_serialization_context const&) = delete;
	c_tag_field_serialization_context(
		c_tag_struct_serialization_context& serialization_context,
		const char* field_data,
		c_runtime_tag_field_definition& runtime_tag_field_definition);
	~c_tag_field_serialization_context();

	virtual BCS_RESULT read() override final;
	virtual BCS_RESULT traverse() override final;
	virtual BCS_RESULT calculate_memory() override final;
	virtual void render_tree() override;
	bool render_enum_debug(ImGuiTreeNodeFlags flags, const char* field_name, const char* field_type_name, long enum_index);
	static unsigned int calculate_field_size(c_serialization_context& serialization_context, c_runtime_tag_field_definition& runtime_field);

	void validate_enum(int enum_value, c_runtime_string_list_definition* string_list_definition);
	void validate_flags(unsigned int flags_value, c_runtime_string_list_definition* string_list_definition);
	void validate_float(float float_value, const char* name);
};
