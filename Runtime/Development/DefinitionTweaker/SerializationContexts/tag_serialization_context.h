#pragma once

class c_serialization_error;
class c_tag_struct_serialization_context;
class c_group_serialization_context;

class c_tag_serialization_context :
	public c_serialization_context
{
public:
	const blofeld::eldorado::s_cache_file_tag_instance* tag_header;
	const int* dependencies;
	const int* data_fixups;
	const int* resource_fixups;
	const int* _end;
	const char* tag_root_structure;
	unsigned int expected_main_struct_size;
	c_tag_struct_serialization_context* root_struct_serialization_context;
	c_group_serialization_context* group_serialization_context;
	unsigned int index;
	c_definition_tweaker& definition_tweaker;

	std::vector<c_serialization_context*> memory_intervals;

	struct s_per_byte_context_association
	{
		unsigned long per_byte_memory_intervals_offset : 28;
		unsigned long per_byte_memory_intervals_count : 4;
	};
	s_per_byte_context_association* per_byte_context_associations;
	std::vector<c_serialization_context*> per_byte_memory_intervals;

	c_tag_serialization_context(c_group_serialization_context& group_serialization_context, unsigned int index, const char* _tag_data_start);
	c_tag_serialization_context(c_definition_tweaker& definition_tweaker, s_engine_platform_build _engine_platform_build, unsigned int index, const char* _tag_data_start);
	c_tag_serialization_context(c_tag_serialization_context const&) = delete;
	~c_tag_serialization_context();
	virtual BCS_RESULT read() override final;
	virtual BCS_RESULT traverse() override final;
	virtual BCS_RESULT calculate_memory() override final;
	void render_tree();
	void draw_memory_explorer();
};
