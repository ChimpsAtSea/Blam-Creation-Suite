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

	c_high_level_tag_editor_tab(c_tag_project& tag_project, h_tag& tag, c_mandrill_tab& parent);
	virtual ~c_high_level_tag_editor_tab();

	h_tag& get_tag() const { return tag; }

protected:
	static constexpr float k_field_display_name_width = 400.0f;

	virtual void render_impl() override final;
	virtual bool render_menu_gui_impl(e_menu_render_type menu_render_type) override final;
	virtual void render_file_dialogue_gui_impl() override final;
	virtual void render_game_layer_impl() override final;

	template<blofeld::e_field field_type>
	bool render_primitive(void* data, const blofeld::s_tag_field& field);
	void render_enumerable(h_enumerable& array, const blofeld::s_tag_field& field);
	bool render_tag(tag& value, const blofeld::s_tag_field& field);
	bool render_tag_reference(h_tag_reference& tag_reference, const blofeld::s_tag_field& field);
	void render_data(h_data& data, const blofeld::s_tag_field& field);

	c_tag_project& tag_project;
	h_tag& tag;
	ImVec2 viewport_size;

	void render_object(uint32_t level, h_prototype& object);
	bool render_flags_definition(void* field_data, const blofeld::s_tag_field& field);
	bool render_enum_definition(void* data, const blofeld::s_tag_field& field);
	void render_tag_group();

	c_custom_tool_render_model* custom_tool;
	c_model_preview_test* model_preview_test;
	c_haloreach_bitmap_test* haloreach_bitmap_test;
	bool show_bitmap_export_file_dialog;
	t_imgui_async_file_dialog_handle file_browser;

	struct s_tag_field_instance
	{
		const blofeld::s_tag_field* tag_field;
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
		const blofeld::s_tag_struct_definition& tag_struct_definition, 
		std::vector<s_tag_struct_fields_instance*>& fields_instances);
};
