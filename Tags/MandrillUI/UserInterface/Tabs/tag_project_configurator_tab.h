#pragma once

struct s_traverse_directory_result;

class c_cache_file_reader;
class c_runtime_task;

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
	c_tag_project_configurator_tab() = delete;
	c_tag_project_configurator_tab(c_tag_project_configurator_tab const&) = delete;
	c_tag_project_configurator_tab& operator=(c_tag_project_configurator_tab const&) = delete;

	c_tag_project_configurator_tab(const wchar_t* directory, c_mandrill_tab& parent);
	virtual ~c_tag_project_configurator_tab();

	bool process_directory(const wchar_t* file_path, const wchar_t* relative_file_path);

protected:
	virtual void render_impl() override final;
	virtual bool render_menu_gui_impl(e_menu_render_type menu_render_type) override final;

	void render_cache_file_selection();
	void render_project_settings();
	void render_display_tags();

	enum e_tag_project_configurator_step
	{
		_tag_project_configurator_step_cache_file_selection,
		_tag_project_configurator_step_project_settings,
		_tag_project_configurator_step_display_tags,
		_tag_project_configurator_step_display_project_setup,
		_tag_project_configurator_step_project_creation,
		_tag_project_configurator_step_project_finished,
	};

	void create_cache_cluster();
	void destroy_cache_cluster();
	void init_tag_project();
	void render_tag_project_status();
	void create_tag_project();
	void create_tag_project_tab();

	e_tag_project_configurator_step step;
	c_fixed_wide_path directory;
	bool is_all_selected;
	bool is_monolithic_tag_file_directory;
	bool is_single_tag_file_directory;
	bool is_cache_file_directory;
	std::vector<s_cache_file_list_entry> entries;
	std::vector<s_cache_file_list_entry> selected_entries;
	c_cache_cluster* cache_cluster;
	c_high_level_cache_cluster_transplant* cache_cluster_transplant;
	c_runtime_task* runtime_task;
	c_tag_project* tag_project;

public:

	class c_tag_project_configurator_tab_task :
		public c_runtime_task
	{
	public:
		c_tag_project_configurator_tab& project_configurator_tab;
		t_task_group* task_group;
		c_stopwatch stopwatch;
		bool running;

		c_tag_project_configurator_tab_task(c_tag_project_configurator_tab& project_configurator_tab);
		virtual ~c_tag_project_configurator_tab_task();
		virtual bool is_running() const override;
		virtual float get_runtime_duration() const override;
	};

};
