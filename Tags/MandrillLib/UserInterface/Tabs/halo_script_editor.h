#pragma once

class c_halo_script_editor :
	public c_mandrill_tab
{
public:
	c_halo_script_editor() = delete;
	c_halo_script_editor(const c_halo_script_editor&) = delete;
	c_halo_script_editor& operator=(const c_halo_script_editor&) = delete;

	c_halo_script_editor(c_mandrill_tab& parent);
	~c_halo_script_editor();

protected:
	virtual void render_impl() override;
	virtual void render_menu_gui_impl(e_menu_render_type menu_render_type) override;
	virtual void render_file_dialogue_gui_impl() override;
	virtual void render_game_layer_impl() override;

	//TextEditor source_code_editor;
	//TextEditor compiler_output;
	//TextEditor::LanguageDefinition source_code_editor_language;
	//mutable TextEditor::ErrorMarkers new_source_code_error_markers;
	//TextEditor::ErrorMarkers source_code_error_markers;
	bool show_compiler_output;
};

