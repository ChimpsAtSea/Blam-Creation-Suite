#pragma once

class c_serialization_error;
class c_tag_field_serialization_context;
class c_tag_serialization_context;

class c_tag_struct_serialization_context :
	public c_serialization_context
{
public:
	c_tag_serialization_context& tag_serialization_context;
	c_tag_field_serialization_context* field_serialization_contexts_memory;
	c_runtime_tag_struct_definition& runtime_tag_struct_definition;
	std::vector<c_tag_field_serialization_context*> field_serialization_contexts;
	unsigned int expected_struct_size;
	unsigned int struct_size;

	c_tag_struct_serialization_context(
		c_serialization_context& serialization_context,
		c_tag_serialization_context& tag_serialization_context,
		const void* struct_data,
		c_runtime_tag_struct_definition& runtime_tag_struct_definition,
		unsigned int expected_struct_size = UINT_MAX);
	c_tag_struct_serialization_context(c_tag_struct_serialization_context const&) = delete;
	~c_tag_struct_serialization_context();

	virtual BCS_RESULT read() override final;
	virtual BCS_RESULT traverse() override final;
	virtual BCS_RESULT calculate_memory() override final;
	virtual void render_tree() override final;
	static unsigned int calculate_struct_size(c_serialization_context& serialization_context, c_runtime_tag_struct_definition& runtime_tag_struct_definition);

	static bool _execute_tag_field_versioning(
		blofeld::s_tag_field_versioning const& versioning,
		s_engine_platform_build engine_platform_build,
		uint32_t struct_version,
		uint32_t& skip_count);
	static bool _execute_tag_field_versioning(
		c_runtime_tag_field_definition& tag_field,
		s_engine_platform_build engine_platform_build,
		uint32_t struct_version,
		uint32_t& skip_count);
	static unsigned int _tag_field_iterator_versioning(
		c_runtime_tag_field_definition& field,
		size_t& tag_field_index,
		s_engine_platform_build engine_platform_build,
		unsigned int struct_version);
};
