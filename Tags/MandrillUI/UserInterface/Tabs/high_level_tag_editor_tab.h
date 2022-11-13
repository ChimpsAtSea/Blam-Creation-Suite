#pragma once

class h_data;
class h_block;
class h_enumerable;
class c_custom_tool_render_model;
class c_model_preview_test;
class c_haloreach_bitmap_test;

class c_high_level_tag_editor_tab :
	public c_mandrill_tab
{
public:
	c_high_level_tag_editor_tab() = delete;
	c_high_level_tag_editor_tab(c_high_level_tag_editor_tab const&) = delete;
	c_high_level_tag_editor_tab& operator=(c_high_level_tag_editor_tab const&) = delete;

	c_high_level_tag_editor_tab(c_tag_project& tag_project, h_tag& tag_prototype, c_mandrill_tab& parent);
	virtual ~c_high_level_tag_editor_tab();

	h_tag& get_tag() const { return tag_prototype; }

protected:
	static constexpr float k_field_description_line_wrap_ratio = 0.40f;
	static constexpr float k_field_display_name_width = 400.0f;

	virtual void render_impl() override final;
	virtual bool render_menu_gui_impl(e_menu_render_type menu_render_type) override final;
	virtual void render_file_dialogue_gui_impl() override final;
	virtual void render_game_layer_impl() override final;

	c_tag_project& tag_project;
	h_tag& tag_prototype;
	ImVec2 viewport_size;

	void render_tag_group();

	c_custom_tool_render_model* custom_tool;
	c_model_preview_test* model_preview_test;
#if defined(BCS_BUILD_ENGINE_HALO_REACH)
	c_haloreach_bitmap_test* haloreach_bitmap_test;
#endif
	bool show_bitmap_export_file_dialog;
	t_imgui_async_file_dialog_handle file_browser;

	struct s_tag_field_instance
	{
		blofeld::s_tag_field const* tag_field;
		bool is_hidden : 1;
	};
	struct s_tag_struct_fields_instance
	{
		blofeld::s_tag_struct_definition* tag_struct_definition;
		uint32_t num_tag_field_instance;
		s_tag_field_instance tag_field_instances[];
	};
	std::vector<s_tag_struct_fields_instance*> fields_instances;
	void build_tag_struct_fields_instances(
		blofeld::s_tag_struct_definition const& tag_struct_definition, 
		std::vector<s_tag_struct_fields_instance*>& fields_instances);

public:
	int render_indent;
	static constexpr float render_indent_amount = 25.0f;

	void render_tooltip(const char* string);
	bool render_byte_color_picker(bool alpha, void* color_data, const char* field_units);
	bool render_real_color_picker(bool alpha, bool hsv, void* color_data, const char* field_units);
	bool render_prototype(h_prototype& prototype);

	typedef bool(c_high_level_tag_editor_tab::* t_render_field_function)(blofeld::s_tag_field const& field, void* _field_data);
	void render_inline_field_start(blofeld::s_tag_field const& field);
	void render_inline_field_end();
	bool render_string_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_long_string_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_string_id_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_old_string_id_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_char_integer_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_short_integer_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_long_integer_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_int64_integer_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_angle_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_tag_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_enumeration_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_flags_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_point_2d_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_rectangle_2d_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_rgb_color_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_argb_color_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_real_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_real_fraction_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_real_point_2d_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_real_point_3d_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_real_vector_2d_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_real_vector_3d_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_real_quaternion_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_real_euler_angles_2d_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_real_euler_angles_3d_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_real_plane_2d_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_real_plane_3d_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_real_rgb_color_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_real_argb_color_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_real_hsv_color_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_real_ahsv_color_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_short_integer_bounds_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_angle_bounds_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_real_bounds_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_real_fraction_bounds_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_tag_reference_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_long_block_flags_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_word_block_flags_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_byte_block_flags_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_char_block_index_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_char_block_index_custom_search_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_short_block_index_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_short_block_index_custom_search_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_long_block_index_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_long_block_index_custom_search_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_data_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_vertex_buffer_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_non_cache_runtime_value_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_explanation_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_struct_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_enumerable_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_pageable_resource_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_api_interop_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_empty_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_byte_integer_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_word_integer_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_dword_integer_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_qword_integer_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_data_path_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_embedded_tag_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_pointer_field(blofeld::s_tag_field const& field, void* _field_data);
	bool render_half_field(blofeld::s_tag_field const& field, void* _field_data);
};
