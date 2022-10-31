#pragma once

class c_tag_serialization_context;
class c_group_serialization_context;
struct s_cache_file_tags_header;

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

enum e_definition_type
{
	_definition_type_group_definition,
	_definition_type_block_definition,
	_definition_type_struct_definition,
	_definition_type_array_definition,
	_definition_type_string_list_definition,
	_definition_type_reference_definition,
	_definition_type_resource_definition,
	_definition_type_interop_definition,
	_definition_type_data_definition,
	_definition_type_block_index_custom_search_definition,
	_definition_type_field_definition,
	k_num_definition_types
};

enum e_definition_tweaker_context_event
{
	_definition_tweaker_context_event_none,
	_definition_tweaker_context_event_select,
	_definition_tweaker_context_event_delete,
	_definition_tweaker_context_event_duplicate,
	_definition_tweaker_context_event_open,
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
	void parse_binary(tag specific_group);
	void render_user_interface();
	void render_missing_group_serialization_context_tree();
	void mandrill_theme_push();
	void mandrill_theme_pop();
	bool render_search_box(char* search_buffer, unsigned int search_buffer_length, const char* default_text = "<search>");


	void render_definitions_view(const char* id, e_definition_type definition_type, void (c_definition_tweaker::* render_list)(), void (c_definition_tweaker::* render_tabs)());
	void setup_definitions_view_columns();

	void render_definition_context_menu(e_definition_type definition_type, void* definition);
	void handle_definition_context_menu();

	void render_group_definitions_list();
	void render_group_definitions_tabs();
	void render_block_definitions_list();
	void render_block_definitions_tabs();
	void render_struct_definitions_list();
	void render_struct_definitions_tabs();
	void render_array_definitions_list();
	void render_array_definitions_tabs();
	void render_string_list_definitions_list();
	void render_string_list_definitions_tabs();
	void render_reference_definitions_list();
	void render_reference_definitions_tabs();
	void render_resource_definitions_list();
	void render_resource_definitions_tabs();
	void render_interop_definitions_list();
	void render_interop_definitions_tabs();
	void render_data_definitions_list();
	void render_data_definitions_tabs();
	void render_block_index_custom_search_definitions_list();
	void render_block_index_custom_search_definitions_tabs();
	void render_field_definitions_list();
	void render_field_definitions_tabs();

	void render_struct_definition(c_runtime_tag_struct_definition* struct_definition);
	void render_struct_definition_tag_field_set(c_runtime_tag_struct_definition* struct_definition);
	void render_struct_definition_memory_attributes(c_runtime_tag_struct_definition* struct_definition);
	void render_struct_definition_fields(c_runtime_tag_struct_definition* struct_definition, float max_size);

	void render_serialization_tab();

	s_engine_platform_build engine_platform_build;
	std::vector<c_group_serialization_context*> group_serialization_contexts;
	std::vector<c_tag_serialization_context*> groupless_serialization_contexts;
	std::vector<unsigned int> open_tag_indices;
	void* binary_data[k_num_binaries];
	size_t binary_data_size[k_num_binaries];
	t_memory_mapped_file* file_handles[k_num_binaries];
	c_runtime_tag_definitions* runtime_tag_definitions;
	c_window& window;
	c_render_context& window_render_context;
	int mandrill_theme_color_count;
	int mandrill_theme_var_count;

	char group_definition_search_buffer[256];
	char block_definition_search_buffer[256];
	char struct_definition_search_buffer[256];
	char array_definition_search_buffer[256];
	char string_list_definition_search_buffer[256];
	char reference_definition_search_buffer[256];
	char resource_definition_search_buffer[256];
	char interop_definition_search_buffer[256];
	char data_definition_search_buffer[256];
	char block_index_custom_search_definition_search_buffer[256];
	char field_definition_search_buffer[256];

	std::unordered_set<c_runtime_tag_group_definition*> open_group_definitions;
	std::unordered_set<c_runtime_tag_block_definition*> open_block_definitions;
	std::unordered_set<c_runtime_tag_struct_definition*> open_struct_definitions;
	std::unordered_set<c_runtime_tag_array_definition*> open_array_definitions;
	std::unordered_set<c_runtime_string_list_definition*> open_string_list_definitions;
	std::unordered_set<c_runtime_tag_reference_definition*> open_reference_definitions;
	std::unordered_set<c_runtime_tag_resource_definition*> open_resource_definitions;
	std::unordered_set<c_runtime_tag_api_interop_definition*> open_interop_definitions;
	std::unordered_set<c_runtime_tag_data_definition*> open_data_definitions;
	std::unordered_set<c_runtime_tag_block_index_custom_search_definition*> open_block_index_custom_search_definitions;
	std::unordered_set<c_runtime_tag_field_definition*> open_field_definitions;

	c_runtime_tag_group_definition* next_group_definition;
	c_runtime_tag_block_definition* next_block_definition;
	c_runtime_tag_struct_definition* next_struct_definition;
	c_runtime_tag_array_definition* next_array_definition;
	c_runtime_string_list_definition* next_string_list_definition;
	c_runtime_tag_reference_definition* next_reference_definition;
	c_runtime_tag_resource_definition* next_resource_definition;
	c_runtime_tag_api_interop_definition* next_interop_definition;
	c_runtime_tag_data_definition* next_data_definition;
	c_runtime_tag_block_index_custom_search_definition* next_block_index_custom_search_definition;
	c_runtime_tag_field_definition* next_field_definition;

	e_definition_type name_edit_state_hack_definition_type;
	unsigned long name_edit_state_hack_ticks;
	ImGuiInputTextState name_edit_state_hack;
	e_definition_type selected_definition_type;
	void* selected_target_definition;
	e_definition_type next_selected_definition_tab_type;

	e_definition_tweaker_context_event context_event_type;
	e_definition_type context_event_definition_type;
	size_t context_event_index;
	void* context_event_pointer;

	s_cache_file_tags_header* cache_file_tags_header;
	unsigned int* tag_cache_offsets;

	template<typename t_runtime_definition>
	bool selcted_type_assignment(e_definition_type definition_type, const char* variable_name, t_runtime_definition*& variable);

	void context_menu_event(e_definition_tweaker_context_event event_type, e_definition_type definition_type, size_t index, void* pointer);
	void enqueue_name_edit_state_hack(e_definition_type definition_type, void* target_definition);
	void handle_name_edit_state_hack(e_definition_type definition_type);
	void mark_modified();
	bool is_definition_type_valid(e_definition_type definition_type, void* target_definition);
	void select_type(e_definition_type definition_type = k_num_definition_types, void* target_definition = nullptr);
	void open_type_tab(e_definition_type definition_type, void* target_definition);
	void* duplicate_type(e_definition_type definition_type, void* target_definition);

	declare_float_setting(float, serialization_column_weight);
	declare_float_setting(float, definitions_column_weight);
	declare_float_setting(float, serialization_definition_list_column_weight);
	declare_integer_setting(e_serialization_error_type, serialization_definition_list_mode);
	declare_integer_setting(tag, serialization_definition_list_group);
};
