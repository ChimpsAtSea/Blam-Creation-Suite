#pragma once

class c_mantle_halo_shader_generator_gui_tab : 
	public c_mantle_gui_tab
{
public:
	friend class c_mantle_tag_gui_tab;

	c_mantle_halo_shader_generator_gui_tab(const char* title, const char* description);
	virtual ~c_mantle_halo_shader_generator_gui_tab();

protected:
	virtual void render_in_game_gui() override;
	virtual void render_contents(bool setSelected) override;

	std::atomic<bool> source_needs_updating;
	std::atomic<bool> is_currently_updating;
	std::atomic<bool> has_updated_results;

	TextEditor::ErrorMarkers error_markers;
	std::string new_compile_source_text;
	std::string new_assembly_editor_text;

	void check_source_update();
	void compile_source(bool is_worker_thread = false);
	void update_display();
};
