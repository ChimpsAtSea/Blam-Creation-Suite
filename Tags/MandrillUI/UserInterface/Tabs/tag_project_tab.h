#pragma once

class c_high_level_tag_tab;
class c_high_level_tag_editor_tab;

namespace blofeld
{
	namespace haloreach
	{
		struct s_bitmap_block_struct;
	}
}

class c_tag_project_tab :
	public c_mandrill_tab
{
public:
	friend class c_high_level_tag_tab;
	friend class c_high_level_tag_editor_tab;

	c_tag_project_tab() = delete;
	c_tag_project_tab(c_tag_project_tab const&) = delete;
	c_tag_project_tab& operator=(c_tag_project_tab const&) = delete;

	c_tag_project_tab(const wchar_t* filepath, c_tag_project& tag_project, c_mandrill_tab& parent);
	virtual ~c_tag_project_tab();

	c_tag_project& get_tag_project() const;

	c_fixed_wide_path project_filepath; // #TODO: move
	void open_tag_by_search_name(const char* tag_name);

protected:
	static constexpr float k_field_display_name_width = 400.0f;

	c_high_level_tag_tab& open_tag_interface_tab(h_tag_instance& tag);
	void render_search_box();
	void render_tags_list_search();
	void render_tags_list_tree();
	void render_explorer_bar();

	virtual void render_impl() override final;
	virtual bool render_menu_gui_impl(e_menu_render_type menu_render_type) override final;
	virtual void render_file_dialogue_gui_impl() override final;
	virtual void render_game_layer_impl() override final;

	c_tag_project& tag_project;
	c_mandrill_user_interface& user_interface;
	h_tag_instance* search_selected_tag_interface;
	c_mandrill_tab* next_selected_tab;
	c_fixed_string_1024 search_buffer;
	t_imgui_async_file_dialog_handle file_browser;
	bool show_export_sounds_file_dialogue;
	bool sound_export_wav;
	bool sound_export_xma;
};
