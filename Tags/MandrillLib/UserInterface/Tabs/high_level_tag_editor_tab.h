#pragma once

class h_data;
class h_block;
class h_enumerable;
class c_custom_tool_render_model;

class c_high_level_tag_editor_tab :
	public c_mandrill_tab
{
public:
	non_copyconstructable(c_high_level_tag_editor_tab);

	c_high_level_tag_editor_tab(c_tag_project& tag_project, h_tag& tag, c_mandrill_tab& parent);
	virtual ~c_high_level_tag_editor_tab();

	h_tag& get_tag() const { return tag; }

protected:
	static constexpr float k_field_display_name_width = 400.0f;

	virtual void render_impl() override final;
	virtual void render_menu_gui_impl(e_menu_render_type menu_render_type) override final;
	virtual void render_file_dialogue_gui_impl() override final;
	virtual void render_game_layer_impl() override final;

	template<blofeld::e_field field_type>
	bool render_primitive(void* data, const blofeld::s_tag_field& field);
	void render_enumerable(h_enumerable& array, const blofeld::s_tag_field& field);
	bool render_tag(tag& value, const blofeld::s_tag_field& field);
	bool render_tag_reference(h_tag*& tag_reference, const blofeld::s_tag_field& field);
	void render_data(h_data& data, const blofeld::s_tag_field& field);

	c_tag_project& tag_project;
	h_tag& tag;
	ImVec2 viewport_size;

	void render_object(uint32_t level, h_object& object);
	bool render_flags_definition(void* field_data, const blofeld::s_tag_field& field);
	bool render_enum_definition(void* data, const blofeld::s_tag_field& field);
	void render_tag_group();

	c_custom_tool_render_model* custom_tool;
};
