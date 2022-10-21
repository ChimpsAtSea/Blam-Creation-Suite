#pragma once

class c_tag_serialization_context;

enum e_binary
{
	_binary_tags,
	_binary_string_ids,
	_binary_video,
	_binary_audio,
	_binary_resources,
	_binary_textures,
	_binary_textures_b,
	k_num_binaries
};

class c_runtime_tag_group_definition;

class c_group_serialization_context
{
public:
	c_group_serialization_context(c_runtime_tag_group_definition& _tag_group) :
		tag_group(_tag_group)
	{

	}

	c_runtime_tag_group_definition& tag_group;
	std::vector<c_tag_serialization_context*> serialization_contexts;
};

class c_definition_tweaker
{
public:
	c_definition_tweaker();
	c_definition_tweaker(c_definition_tweaker const&) = delete;
	~c_definition_tweaker();

	void init();
	void deinit();
	void parse_binary();
	void render_user_interface();


	s_engine_platform_build engine_platform_build;
	std::vector<c_group_serialization_context*> group_serialization_contexts;
	std::vector<c_tag_serialization_context*> serialization_contexts;
	std::vector<unsigned int> open_tag_indices;
	void* binary_data[k_num_binaries];
	size_t binary_data_size[k_num_binaries];
	t_memory_mapped_file* file_handles[k_num_binaries];
	c_runtime_tag_definitions* runtime_tag_definitions;
};
