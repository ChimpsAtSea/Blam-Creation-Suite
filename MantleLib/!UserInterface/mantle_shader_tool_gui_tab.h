#pragma once

class c_mantle_shader_tool_gui_tab :
	public c_mantle_gui_tab
{
public:
	friend class c_mantle_tag_gui_tab;

	c_mantle_shader_tool_gui_tab(const char* title, const char* description, c_mantle_cache_file_gui_tab& parent_tab, c_cache_file& cache_file);
	virtual ~c_mantle_shader_tool_gui_tab();

protected:
	virtual void render_tab_contents_gui() override;

	static std::string disassemble_shader(const char* hlsl_bytecode_data, size_t hlsl_bytecode_size);

	void render_shader_profile_selection_gui();
	void render_source_code_editor_configuration_header_column_gui();
	void render_preview_disassembly_configuration_header_column_gui();
	void render_runtime_disassembly_configuration_header_column_gui();
	void render_text_editor_status_bar_gui();
	void render_source_code_editor_gui();
	void render_preview_disassembly();
	void render_runtime_disassembly();

	void compile_source();
	void compile_source_subroutine() const;
	c_thread_subroutine compile_source_thread_subroutine;
	mutable c_atomic_temp_value<std::string> source_code;
	mutable c_atomic_temp_value<std::string> new_source_code_disassembly;
	mutable c_atomic_temp_value<TextEditor::ErrorMarkers> new_source_code_error_markers;
	TextEditor::ErrorMarkers source_code_error_markers;

	void disassemble_runtime_subroutine() const;
	c_thread_subroutine disassemble_runtime;
	mutable c_atomic_temp_value<std::string> new_runtime_disassembly;

	//c_mantle_cache_file_gui_tab* selected_cache_file_tab;
	c_mantle_cache_file_gui_tab& parent_tab;
	c_cache_file& cache_file;
	c_tag_interface* selected_render_method_definition_tag_interface;
	c_tag_interface* selected_render_method_template_tag_interface;

	bool use_durango_shader_disassembly;

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
