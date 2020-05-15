#include "mantlelib-private-pch.h"

c_mantle_blofeld_tag_editor_gui_tab::c_mantle_blofeld_tag_editor_gui_tab(c_cache_file& cache_file, c_mantle_gui_tab* parent_tab, c_tag_interface& tag_interface) :
	c_mantle_gui_tab("Blofeld Tag Editor", "Blofeld Tag Editor"),
	cache_file(cache_file),
	parent_tab(parent_tab),
	tag_interface(tag_interface)
{
	allow_close = false;
}

c_mantle_blofeld_tag_editor_gui_tab::~c_mantle_blofeld_tag_editor_gui_tab()
{

}

void c_mantle_blofeld_tag_editor_gui_tab::render_tab_contents_gui()
{
	ImGui::Text("Blofeld");

	const blofeld::s_tag_group* group = tag_interface.get_blofeld_reflection_data();

	const blofeld::s_tag_field* fields = group->block->field_set->tag_fields;
	const blofeld::s_tag_field* current_field = fields;
	while (current_field->field_type != blofeld::_field_terminator)
	{
		const char* field_typename = field_to_string(current_field->field_type);
		ImGui::Text("%s %s", field_typename, current_field->name ? current_field->name : "");
		current_field++;
	}
}
