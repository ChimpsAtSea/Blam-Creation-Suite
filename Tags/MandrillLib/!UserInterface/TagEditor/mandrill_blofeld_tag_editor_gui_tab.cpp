#include "mandrilllib-private-pch.h"

c_mandrill_blofeld_tag_editor_gui_tab::c_mandrill_blofeld_tag_editor_gui_tab(c_cache_file& cache_file, c_mandrill_gui_tab* parent_tab, c_tag_interface& tag_interface) :
	c_mandrill_gui_tab("Blofeld Tag Editor", "Blofeld Tag Editor"),
	cache_file(cache_file),
	parent_tab(parent_tab),
	tag_interface(tag_interface)
{
	allow_close = false;
}

c_mandrill_blofeld_tag_editor_gui_tab::~c_mandrill_blofeld_tag_editor_gui_tab()
{

}

uint32_t c_mandrill_blofeld_tag_editor_gui_tab::render_tag_struct_definition(char* data, const blofeld::s_tag_struct_definition& struct_definition)
{
	uint32_t bytes_traversed = 0;
	int32_t field_index = 0;
	for (const blofeld::s_tag_field* current_field = struct_definition.fields; current_field->field_type != blofeld::_field_terminator; (current_field++, field_index++))
	{
		const char* field_typename = field_to_string(current_field->field_type);
		ASSERT(field_typename != nullptr);

		ImGui::Text("%s %s", field_typename, current_field->name ? current_field->name : "");

		switch (current_field->field_type)
		{
		case blofeld::_field_struct:
		{
			const blofeld::s_tag_struct_definition* field_struct_definition = current_field->struct_definition;
			DEBUG_ASSERT(field_struct_definition != nullptr);
			if (field_struct_definition == nullptr)
			{
				continue;
			}

			ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor::ImColor(0.7f, 0.7f, 1.0f));
			if (field_struct_definition != &struct_definition)
			{
				render_tag_struct_definition(nullptr, *field_struct_definition);
			}
			else
			{
				ImGui::Text("ERROR. RECURSIVE STRUCT!!!");
			}
			ImGui::PopStyleColor(1);

			break;
		}
		case blofeld::_field_array:
		{
			const blofeld::s_tag_array_definition* field_array_definition = current_field->array_definition;
			DEBUG_ASSERT(field_array_definition != nullptr);
			if (field_array_definition == nullptr)
			{
				continue;
			}
			const blofeld::s_tag_struct_definition& field_struct_definition = field_array_definition->struct_definition;
			REFERENCE_ASSERT(field_struct_definition);

			ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor::ImColor(0.7f, 1.0f, 0.7f));
			for (uint32_t array_index = 0; array_index < field_array_definition->count; array_index++)
			{
				render_tag_struct_definition(nullptr, field_struct_definition);
				break;
			}
			ImGui::PopStyleColor(1);

			break;
		}
		case blofeld::_field_block:
		{
			const blofeld::s_tag_block_definition* field_block_definition = current_field->block_definition;
			DEBUG_ASSERT(field_block_definition != nullptr);
			if (field_block_definition == nullptr)
			{
				continue;
			}
			const blofeld::s_tag_struct_definition& field_struct_definition = field_block_definition->struct_definition;
			REFERENCE_ASSERT(field_struct_definition);

			ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor::ImColor(1.0f, 1.0f, 0.7f));
			render_tag_struct_definition(nullptr, field_struct_definition);
			ImGui::PopStyleColor(1);

			break;
		}
		case blofeld::_field_char_enum:
		case blofeld::_field_enum:
		case blofeld::_field_long_enum:
		case blofeld::_field_long_flags:
		case blofeld::_field_word_flags:
		case blofeld::_field_byte_flags:
		{
			const blofeld::s_string_list_definition* string_list_definition = current_field->string_list_definition;
			DEBUG_ASSERT(string_list_definition != nullptr);
			if (string_list_definition == nullptr)
			{
				// #TODO: Display as an appropriate integer control for missing definitions. Throw up a unique warning.
				continue;
			}

			ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor::ImColor(1.0f, 0.7f, 0.7f));
			for (uint32_t option_index = 0; option_index < string_list_definition->count; option_index++)
			{
				ImGui::Text("string> %s", string_list_definition->strings[option_index]);
			}
			ImGui::PopStyleColor(1);

			break;
		}
		}

	}
	return bytes_traversed;
}

uint32_t c_mandrill_blofeld_tag_editor_gui_tab::render_tag_group(char* data, const blofeld::s_tag_group& group)
{
	//if (group.parent_group_tag)
	//{
	//	ASSERT(group.parent_tag_group != nullptr);
	//	uint32_t parent_bytes_traversed = render_tag_group(data, *group.parent_tag_group);
	//	data += parent_bytes_traversed;
	//}

	uint32_t bytes_traversed = render_tag_struct_definition(data, group.block_definition.struct_definition);
	return bytes_traversed;
}

void c_mandrill_blofeld_tag_editor_gui_tab::render_tab_contents_gui()
{
	ImGui::Text("Blofeld");

	const blofeld::s_tag_group* group = tag_interface.get_blofeld_reflection_data();

	render_tag_group(nullptr, *group);
}
