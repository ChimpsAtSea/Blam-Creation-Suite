#include "mandrilllib-private-pch.h"

c_blofeld_tag_definition_debug_tab::c_blofeld_tag_definition_debug_tab(c_tag_interface& tag_interface, c_mandrill_tab& parent) :
	c_mandrill_tab("Tag Definition Debug", "Blofeld Tag Definition Debug", &parent, false),
	tag_interface(tag_interface)
{

}

c_blofeld_tag_definition_debug_tab::~c_blofeld_tag_definition_debug_tab()
{

}

void c_blofeld_tag_definition_debug_tab::render_impl()
{
	ImDrawList* draw_list = ImGui::GetWindowDrawList();
	float line_height = ImGui::GetTextLineHeight();

	{
		float header_height = line_height * 1.5f;

		ImVec2 start_pos = ImGui::GetCursorScreenPos();
		ImVec2 finish_pos = start_pos;
		finish_pos.x += ImGui::GetContentRegionAvailWidth();
		finish_pos.y += header_height;
		draw_list->AddRectFilled(start_pos, finish_pos, ImGui::ColorConvertFloat4ToU32(MANDRILL_THEME_MENU(1.0f)));


		ImVec2 text_pos = start_pos;
		text_pos.x += 10.0f;
		text_pos.y += (header_height - line_height) / 2.0f;
		draw_list->AddText(text_pos, ImGui::ColorConvertFloat4ToU32(MANDRILL_THEME_TEXT(1.0f)), tag_interface.get_path_with_group_name_cstr());

		finish_pos.x = start_pos.x;
		ImGui::SetCursorScreenPos(finish_pos);
	}

	const blofeld::s_tag_group* group = tag_interface.get_blofeld_reflection_data();

	render_tag_group(nullptr, *group);
}

void c_blofeld_tag_definition_debug_tab::render_menu_gui_impl()
{

}

void c_blofeld_tag_definition_debug_tab::render_file_dialogue_gui_impl()
{

}

void c_blofeld_tag_definition_debug_tab::render_game_layer_impl()
{

}

uint32_t c_blofeld_tag_definition_debug_tab::render_tag_struct_definition(int level, char* data, const blofeld::s_tag_struct_definition& struct_definition)
{
	e_engine_type engine_type = tag_interface.get_cache_file().get_engine_type();

	constexpr float indent = 25.0f;
	uint32_t bytes_traversed = 0;
	int32_t field_index = 0;
	for (const blofeld::s_tag_field* current_field = struct_definition.fields; current_field->field_type != blofeld::_field_terminator; (current_field++, field_index++))
	{
		const char* field_typename = field_to_string(current_field->field_type);
		ASSERT(field_typename != nullptr);

		uint32_t field_skip_count;
		if (skip_tag_field_version(*current_field, engine_type, _build_not_set, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		ImGui::Dummy({ static_cast<float>(level) * indent, 0.0f });
		ImGui::SameLine();
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
				render_tag_struct_definition(level + 1, nullptr, *field_struct_definition);
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
				render_tag_struct_definition(level + 1, nullptr, field_struct_definition);
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
			render_tag_struct_definition(level + 1, nullptr, field_struct_definition);
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
				ImGui::Dummy({ static_cast<float>(level + 1) * indent, 0.0f  });
				ImGui::SameLine();
				ImGui::Text("string> %s", string_list_definition->strings[option_index]);
			}
			ImGui::PopStyleColor(1);

			break;
		}
		}

	}
	return bytes_traversed;
}

uint32_t c_blofeld_tag_definition_debug_tab::render_tag_group(char* data, const blofeld::s_tag_group& group)
{
	//if (group.parent_group_tag)
	//{
	//	ASSERT(group.parent_tag_group != nullptr);
	//	uint32_t parent_bytes_traversed = render_tag_group(data, *group.parent_tag_group);
	//	data += parent_bytes_traversed;
	//}

	uint32_t bytes_traversed = render_tag_struct_definition(0, data, group.block_definition.struct_definition);
	return bytes_traversed;
}
