#pragma once

class c_tag_serialization_context;
class c_group_serialization_context;

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

class c_definition_tweaker
{
public:
	c_definition_tweaker(c_window& window, c_render_context& window_render_context);
	c_definition_tweaker(c_definition_tweaker const&) = delete;
	~c_definition_tweaker();

	void init();
	void deinit();
	void cleanup();
	void parse_binary();
	void render_user_interface();
	void render_missing_group_serialization_context_tree();
	void render_group_serialization_context_tree(c_group_serialization_context* group_serialization_context);
	void render_tag_serialization_context_tree(c_tag_serialization_context* tag_serialization_context);
	void mandrill_theme_push();
	void mandrill_theme_pop();
	bool render_search_box(char* search_buffer, unsigned int search_buffer_length, const char* default_text = "<search>");

	void render_definitions_tab();
	void render_serialization_tab();

	s_engine_platform_build engine_platform_build;
	std::vector<c_group_serialization_context*> group_serialization_contexts;
	std::vector<c_tag_serialization_context*> serialization_contexts;
	std::vector<unsigned int> open_tag_indices;
	unsigned int num_missing_groups;
	void* binary_data[k_num_binaries];
	size_t binary_data_size[k_num_binaries];
	t_memory_mapped_file* file_handles[k_num_binaries];
	c_runtime_tag_definitions* runtime_tag_definitions;
	c_window& window;
	c_render_context& window_render_context;
	int mandrill_theme_color_count;
	int mandrill_theme_var_count;
	char structure_search_buffer[256];
	
	std::unordered_set<c_runtime_tag_group_definition*> open_group_definitions;
	std::unordered_set<c_runtime_tag_block_definition*> open_block_definitions;
	std::unordered_set<c_runtime_tag_struct_definition*> open_struct_definitions;
	std::unordered_set<c_runtime_tag_array_definition*> open_array_definitions;
	std::unordered_set<c_runtime_tag_string_list_definition*> open_string_list_definitions;
	std::unordered_set<c_runtime_tag_reference_definition*> open_reference_definitions;
	std::unordered_set<c_runtime_tag_resource_definition*> open_resource_definitions;
	std::unordered_set<c_runtime_tag_interop_definition*> open_interop_definitions;
	std::unordered_set<c_runtime_tag_data_definition*> open_data_definitions;
	std::unordered_set<c_runtime_block_index_custom_search_definition*> open_block_index_custom_search_definitions;

	c_runtime_tag_group_definition* next_group_definition;
	c_runtime_tag_block_definition* next_block_definition;
	c_runtime_tag_struct_definition* next_struct_definition;
	c_runtime_tag_array_definition* next_array_definition;
	c_runtime_tag_string_list_definition* next_string_list_definition;
	c_runtime_tag_reference_definition* next_reference_definition;
	c_runtime_tag_resource_definition* next_resource_definition;
	c_runtime_tag_interop_definition* next_interop_definition;
	c_runtime_tag_data_definition* next_data_definition;
	c_runtime_block_index_custom_search_definition* next_block_index_custom_search_definition;
};
