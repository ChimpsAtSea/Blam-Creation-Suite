#include "mantlelib-private-pch.h"

// REFLECTION V2 EXAMPLE CONTENT


c_mantle_blamlib_tag_editor_gui_tab::c_mantle_blamlib_tag_editor_gui_tab(c_cache_file& cache_file, c_mantle_gui_tab* parent_tab, c_tag_interface& tag_interface) :
	c_mantle_gui_tab("Blamlib Tag Editor", "Blamlib Tag Editor"),
	cache_file(cache_file),
	parent_tab(parent_tab),
	tag_interface(tag_interface)
{
	allow_close = false;
}

c_mantle_blamlib_tag_editor_gui_tab::~c_mantle_blamlib_tag_editor_gui_tab()
{

}

void render_member(const s_reflection_member& member);


void render_structure_gui(const s_reflection_structure& structure_reflection, void* data)
{
	for (const s_reflection_member& member : structure_reflection)
	{
		render_member(member);
		const char* type_class_str = reflection_type_class_to_string(member.type_class);
		ImGui::Text("%s %s '%s'", type_class_str, member.type->nice_name, member.nice_name);
	}
}

void render_member(const s_reflection_member& member)
{
	switch (member.type_class)
	{
	case _reflection_type_class_structure:
	case _reflection_type_class_union:
		render_structure_gui(*member.structure, nullptr);
		break;
	case _reflection_type_class_undefined:
	case _reflection_type_class_padding:
	case _reflection_type_class_tag_block:
	case _reflection_type_class_tag_reference:
	case _reflection_type_class_data_reference:
	case _reflection_type_class_uint:
	case _reflection_type_class_int:
	case _reflection_type_class_enum:
	case _reflection_type_class_bitflag:
	case _reflection_type_class_bitfield:
	case _reflection_type_class_float:
	case _reflection_type_class_boolean:
	case _reflection_type_class_text:
	default:
		break;
	}
}

void c_mantle_blamlib_tag_editor_gui_tab::render_tab_contents_gui()
{
	const s_reflection_structure* blamlib_reflection = tag_interface.get_blamlib_reflection_data();
	if (blamlib_reflection)
	{
		render_structure_gui(*blamlib_reflection, tag_interface.get_data());
	}
	else
	{
		ImGui::Text("No blamlib reflection data");
	}
}
