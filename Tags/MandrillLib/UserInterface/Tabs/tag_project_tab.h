#pragma once

class c_haloreach_cache_file;
class h_tag;
class c_high_level_tag_tab;

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
	non_copyconstructable(c_tag_project_tab);

	c_tag_project_tab(const wchar_t* filepath, c_tag_project& tag_project, c_mandrill_tab& parent);
	virtual ~c_tag_project_tab();

	c_tag_project& get_tag_project() const;

	c_fixed_wide_path project_filepath; // #TODO: move
	void open_tag_by_search_name(const char* tag_name);

protected:
	static constexpr float k_field_display_name_width = 400.0f;

	c_high_level_tag_tab& open_tag_interface_tab(h_tag& tag);
	void render_search_box();
	void render_tags_list_search();
	void render_tags_list_tree();
	void render_explorer_bar();

	virtual void render_impl() override final;
	virtual void render_menu_gui_impl(e_menu_render_type menu_render_type) override final;
	virtual void render_file_dialogue_gui_impl() override final;
	virtual void render_game_layer_impl() override final;

	c_tag_project& tag_project;
	c_mandrill_user_interface& user_interface;
	h_tag* search_selected_tag_interface;
	c_mandrill_tab* next_selected_tab;
	c_fixed_string_1024 search_buffer;
};
