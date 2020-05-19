#include "mantlelib-private-pch.h"

#include <GUI/render_primitive_gui.inl>
#include <GUI/render_stringid_gui.inl>
#include <GUI/render_struct_gui.inl>
#include <GUI/render_tagref_gui.inl>
#include <GUI/render_dataref_gui.inl>
#include <GUI/render_tagblock_gui.inl>
#include <GUI/render_enum_gui.inl>
#include <GUI/render_bitfield_gui.inl>
// #TODO: include generated_gui_legacy.cpp here and force inline all of the render functions

int c_mantle_legacy_tag_editor_gui_tab::g_current_recursion_depth = 0;
float c_mantle_legacy_tag_editor_gui_tab::g_current_recursion_padding = 0.0f;
thread_local c_mantle_legacy_tag_editor_gui_tab* c_mantle_legacy_tag_editor_gui_tab::g_current_mantle_tag_tab = nullptr;

c_mantle_legacy_tag_editor_gui_tab::c_mantle_legacy_tag_editor_gui_tab(c_cache_file& cache_file, c_mantle_gui_tab* parent_tab, c_tag_interface& tag_interface) :
	c_mantle_gui_tab("Legacy Tag Editor", "Legacy Tag Editor"),
	cache_file(cache_file),
	parent_tab(parent_tab),
	tag_interface(tag_interface)
{
	allow_close = false;
}

c_mantle_legacy_tag_editor_gui_tab::~c_mantle_legacy_tag_editor_gui_tab()
{

}

void c_mantle_legacy_tag_editor_gui_tab::increment_recursion()
{
	g_current_recursion_depth++;
	g_current_recursion_padding = recursion_padding_amount * static_cast<float>(g_current_recursion_depth);
}

void c_mantle_legacy_tag_editor_gui_tab::decrement_recursion()
{
	g_current_recursion_depth--;
	g_current_recursion_padding = recursion_padding_amount * static_cast<float>(g_current_recursion_depth);
}

void c_mantle_legacy_tag_editor_gui_tab::render_tab_contents_gui()
{
	ImGui::BeginChild("##scroll_view", ImVec2(0, 0), false);

	const s_reflection_structure_type_legacy* ps_reflection_structure_type_legacy = tag_interface.get_legacy_reflection_data();
	if (ps_reflection_structure_type_legacy)
	{
		g_current_mantle_tag_tab = this;
		ps_reflection_structure_type_legacy->render_type_gui_legacy(tag_interface.get_data());
	}
	else
	{
		ImGui::Text("No reflection information found for '%s'", tag_interface.get_group_short_name_cstr());
	}

	ImGui::EndChild();
}
