#pragma once

class c_serialization_error;
class c_tag_struct_serialization_context;
class c_group_serialization_context;

class c_tag_serialization_context :
	public c_serialization_context
{
public:
	const char* tag_data_start;
	const char* tag_data_end;
	const s_cache_file_tag_instance* tag_header;
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
	volatile unsigned int traverse_count;

	c_tag_serialization_context(c_group_serialization_context& group_serialization_context, unsigned int index, const char* _tag_data_start);
	c_tag_serialization_context(c_definition_tweaker& definition_tweaker, s_engine_platform_build _engine_platform_build, unsigned int index, const char* _tag_data_start);
	c_tag_serialization_context(c_tag_serialization_context const&) = delete;
	~c_tag_serialization_context();
	BCS_RESULT read();
	BCS_RESULT traverse();
	void render_tree();
};
