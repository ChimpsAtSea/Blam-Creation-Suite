#pragma once
class c_mantle_halo_script_editor : 
	public c_mantle_gui_tab
{
public:
	c_mantle_halo_script_editor() = delete;
	c_mantle_halo_script_editor(const c_mantle_halo_script_editor&) = delete;
	c_mantle_halo_script_editor& operator=(const c_mantle_halo_script_editor&) = delete;

	c_mantle_halo_script_editor(c_mantle_cache_file_gui_tab& parent_tab, c_cache_file& cache_file);
	~c_mantle_halo_script_editor();



protected:
	c_mantle_cache_file_gui_tab& parent_tab;
	c_cache_file& cache_file;

	void render_tab_contents_gui() override;
	void render_tab_menu_gui() override;

	TextEditor source_code_editor;
	TextEditor compiler_output;
	TextEditor::LanguageDefinition source_code_editor_language;
	mutable c_atomic_temp_value<TextEditor::ErrorMarkers> new_source_code_error_markers;
	TextEditor::ErrorMarkers source_code_error_markers;
	bool show_compiler_output;
};

