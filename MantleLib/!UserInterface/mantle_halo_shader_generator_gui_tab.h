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
	virtual void render_tab_contents_gui(bool setSelected) override;

	static std::string disassemble_shader(const char* hlsl_bytecode_data, size_t hlsl_bytecode_size);

	void render_shader_profile_selection_gui();
	void render_source_code_editor_configuration_header_column_gui();
	void render_preview_disassembly_configuration_header_column_gui();
	void render_runtime_disassembly_configuration_header_column_gui();
	void render_text_editor_status_bar_gui();
	void render_source_code_editor_gui();
	void render_preview_disassembly();
	void render_runtime_disassembly();

	void check_source_update();
	void compile_source(bool is_worker_thread = false);
	void update_display();
	void update_runtime_disassembly();

	c_mantle_cache_file_gui_tab* selected_cache_file_tab;
	c_tag_interface* selected_render_method_definition_tag_interface;
	c_tag_interface* selected_render_method_template_tag_interface;

	std::atomic<bool> runtime_source_needs_updating;
	bool use_durango_shader_disassembly;
	std::atomic<bool> source_needs_updating;
	std::atomic<bool> is_currently_updating;
	std::atomic<bool> has_updated_results;

	TextEditor::ErrorMarkers error_markers;
	std::string new_compile_source_text;
	std::string new_assembly_editor_text;

	static e_shader_profile accepted_shader_profiles[];
	e_shader_profile current_shader_profile;
	TextEditor* selected_text_editor;
	const char* selected_file_path;
	const char* selected_language_name;

	TextEditor source_code_editor_display;
	TextEditor preview_disassembly_display;
	TextEditor runtime_disassembly_display;
	TextEditor::LanguageDefinition code_editor_language;
	TextEditor::LanguageDefinition hlsl_assembly_language;

};
