#pragma once

struct s_traverse_directory_result;

class c_cache_file_reader;

struct s_cache_file_list_entry
{
	bool selected;
	c_fixed_wide_path filepath;
	c_cache_file_reader* cache_reader;
	s_engine_platform_build engine_platform_build;
	s_cache_file_build_info build_info;
};

class c_tag_project_configurator_tab :
	public c_mandrill_tab
{
public:
	non_copyconstructable(c_tag_project_configurator_tab);

	c_tag_project_configurator_tab(const wchar_t* directory, c_mandrill_tab& parent);
	virtual ~c_tag_project_configurator_tab();

	bool process_directory(const s_traverse_directory_result* result);

protected:
	virtual void render_impl() override final;
	virtual void render_menu_gui_impl(e_menu_render_type menu_render_type) override final;
	virtual void render_file_dialogue_gui_impl() override final;
	virtual void render_game_layer_impl() override final;

	void render_cache_file_selection();
	void render_project_settings();
	void render_display_tags();

	enum e_tag_project_configurator_step
	{
		_tag_project_configurator_step_cache_file_selection,
		_tag_project_configurator_step_project_settings,
		_tag_project_configurator_step_display_tags,
		_tag_project_configurator_step_project_creation,
	};

	void create_cache_cluster();
	void destroy_cache_cluster();
	void create_tag_project();

	e_tag_project_configurator_step step;
	c_fixed_wide_path directory;
	bool is_all_selected;
	std::vector<s_cache_file_list_entry> entries;
	c_cache_cluster* cache_cluster;
	c_high_level_cache_cluster_transplant* cache_cluster_transplant;
};
