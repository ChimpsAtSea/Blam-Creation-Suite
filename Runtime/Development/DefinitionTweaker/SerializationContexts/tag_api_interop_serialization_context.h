#pragma once

class c_serialization_error;
class c_tag_field_serialization_context;
class c_tag_serialization_context;

class c_tag_api_interop_serialization_context :
	public c_serialization_context
{
public:
	c_tag_serialization_context& tag_serialization_context;
	void const* interop_data;
	unsigned int struct_size;
	c_runtime_tag_api_interop_definition& runtime_tag_api_interop_definition;
	c_runtime_tag_struct_definition* cache_file_resource_location_struct_definition;
	c_runtime_tag_struct_definition* cache_file_resource_data_struct_definition;
	c_tag_struct_serialization_context* cache_file_resource_location_struct_serialization_context;
	c_tag_struct_serialization_context* cache_file_resource_data_struct_serialization_context;
	unsigned int cache_file_resource_location_struct_size;
	unsigned int cache_file_resource_data_struct_size;

	c_tag_api_interop_serialization_context(
		c_tag_field_serialization_context& serialization_context,
		c_tag_serialization_context& tag_serialization_context,
		void const* interop_data,
		c_runtime_tag_api_interop_definition& api_interop_definition);
	c_tag_api_interop_serialization_context(c_tag_struct_serialization_context const&) = delete;
	~c_tag_api_interop_serialization_context();

	virtual BCS_RESULT read() override final;
	virtual BCS_RESULT traverse() override final;
	virtual BCS_RESULT calculate_memory() override final;
	void render_tree();
};
