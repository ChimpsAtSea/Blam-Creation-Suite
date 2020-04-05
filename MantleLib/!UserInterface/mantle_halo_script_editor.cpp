#include "mantlelib-private-pch.h"

c_mantle_halo_script_editor::c_mantle_halo_script_editor(c_mantle_cache_file_gui_tab& parent_tab, c_cache_file& cache_file) :
	c_mantle_gui_tab("Script Editor", "Halo Script Editor"),
	parent_tab(parent_tab),
	cache_file(cache_file),
	source_code_editor(),
	source_code_editor_language(TextEditor::LanguageDefinition::HaloScript())
{
	source_code_editor.SetLanguageDefinition(source_code_editor_language);

	std::string halo_script_file = c_command_line::get_command_line_arg("-haloscript");
	std::wstring halo_script_filew = { halo_script_file.begin(), halo_script_file.end() };
	if (!halo_script_file.empty())
	{
		std::string halo_script_source = FileSystemReadToMemory(halo_script_filew.c_str());
		source_code_editor.SetText(halo_script_source);
	}
}

c_mantle_halo_script_editor::~c_mantle_halo_script_editor()
{

}

void c_mantle_halo_script_editor::render_tab_contents_gui()
{
	source_code_editor.Render("Halo Script Editor");
}

void c_mantle_halo_script_editor::render_tab_menu_gui()
{
	if (ImGui::BeginMenu("Script"))
	{
		

		ImGui::EndMenu();
	}
}
