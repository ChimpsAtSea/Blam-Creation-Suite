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

uint32_t c_mantle_blofeld_tag_editor_gui_tab::render_tag_group(char* data, const blofeld::s_tag_group& group)
{
	//if (group.parent_group_tag)
	//{
	//	ASSERT(group.parent_tag_group != nullptr);
	//	uint32_t parent_bytes_traversed = render_tag_group(data, *group.parent_tag_group);
	//	data += parent_bytes_traversed;
	//}

	uint32_t bytes_traversed = 0;
	const blofeld::s_tag_field* const fields_begin = group.block.tag_struct.tag_fields;
	const blofeld::s_tag_field* current_field = fields_begin;
	//if (group.parent_group_tag) current_field++; // skip inheritance struct
	while (current_field->field_type != blofeld::_field_terminator)
	{
		const char* field_typename = field_to_string(current_field->field_type);

		ImGui::Text("%s %s", field_typename, current_field->name ? current_field->name : "");

		switch (current_field->field_type)
		{
		case blofeld::_field_char_enum:	 
		case blofeld::_field_enum:		 
		case blofeld::_field_long_enum:	 
		case blofeld::_field_long_flags: 
		case blofeld::_field_word_flags: 
		case blofeld::_field_byte_flags: 

			const blofeld::s_string_list_definition* string_list_definition = current_field->string_list_definition;
			DEBUG_ASSERT(string_list_definition != 0);

			if (string_list_definition)
			{
				ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor::ImColor(1.0f, 0.9f, 0.9f));
				for (uint32_t option_index = 0; option_index < string_list_definition->count; option_index++)
				{
					ImGui::Text("string> %s", string_list_definition->strings[option_index]);
				}
				ImGui::PopStyleColor(1);
			}
			else 
			{
				// #TODO: Display as an appropriate integer control for missing definitions. Throw up a unique warning.
			}
			break;
		}

		current_field++;
	}
	return bytes_traversed;
}

void c_mantle_blofeld_tag_editor_gui_tab::render_tab_contents_gui()
{
	ImGui::Text("Blofeld");

	const blofeld::s_tag_group* group = tag_interface.get_blofeld_reflection_data();

	render_tag_group(nullptr, *group);
}
