#pragma once

class c_cache_file;
class c_tag_interface;
class c_tag_interface_tab;

class c_cache_file_tab : 
	public c_mandrill_tab
{
public:
	non_copyconstructable(c_cache_file_tab);

	c_cache_file_tab(c_cache_file& cache_file, c_mandrill_tab& parent, const char* tag_list);
	~c_cache_file_tab();

	c_cache_file& get_cache_file() const { return cache_file; }

protected:
	virtual void render_impl() override final;
	virtual void render_menu_gui_impl(e_menu_render_type menu_render_type) override final;
	virtual void render_file_dialogue_gui_impl() override final;
	virtual void render_game_layer_impl() override final;

	void render_tags_list_tree();
	void render_tags_list_search();
	c_tag_interface_tab& open_tag_interface_tab(c_tag_interface& tag_interface);
	void open_tag_by_search_name(const char* tag_name);
	void render_search_box();
	void render_explorer_bar();

	c_cache_file& cache_file;
	bool render_trigger_volumes;

	c_fixed_string_1024 search_buffer;
	c_tag_interface* search_selected_tag_interface;

	static constexpr const char* k_explorer_bar_width = "explorer_bar_width";
	static float explorer_bar_width;

//
//
//
//
//
//public:
//	friend class c_mandrill_old_tag_gui_tab;
//
//	void render_cache_file_gui();
//public:
//	c_old_mandrill_cache_file_gui_tab() = delete;
//	c_old_mandrill_cache_file_gui_tab(const c_old_mandrill_cache_file_gui_tab&) = delete;
//	c_old_mandrill_cache_file_gui_tab& operator=(const c_old_mandrill_cache_file_gui_tab&) = delete;
//
//	c_old_mandrill_cache_file_gui_tab(c_cache_file& cache_file);
//	virtual ~c_old_mandrill_cache_file_gui_tab();
//
//
//	c_cache_file& get_cache_file() const { return cache_file; }
//	void open_tag_interface_tab(c_tag_interface& tag_interface);
//protected:
//
//	virtual void render_in_game_gui() override;
//	virtual void render_tab_menu_gui() override;
//	virtual void render_tab_contents_gui() override;
//
//	void open_shader_tool();
//	void open_halo_script_editor();
//	void close_halo_script_editor();
//	void render_file_dialogue_gui();
//
//	bool debug_file_dialogue_gui;
//	char search_buffer[1024];
//	c_tag_interface* search_selected_tag_interface;
//	c_old_mandrill_gui_tab* next_selected_mandrill_gui_tab;
//	bool render_trigger_volumes;
//	c_cache_file& cache_file;
//	bool enable_shader_tool;
//	std::string shader_tool_directory;
//	c_mandrill_halo_script_editor* halo_script_editor;
//	ImGuiAddons::ImGuiFileBrowser file_browser;
};

