#include "mandrilllib-private-pch.h"

c_blofeld_tag_editor_tab::c_blofeld_tag_editor_tab(c_tag_interface& tag_interface, c_mandrill_tab& parent) :
	c_mandrill_tab("Tag Editor", "Blofeld Tag Editor", &parent, false),
	tag_interface(tag_interface)
{

}

c_blofeld_tag_editor_tab::~c_blofeld_tag_editor_tab()
{

}

void c_blofeld_tag_editor_tab::render_impl()
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

	{
		float header_height = line_height * 1.75f;

		ImVec2 start_pos = ImGui::GetCursorScreenPos();
		ImVec2 finish_pos = start_pos;
		finish_pos.x += ImGui::GetContentRegionAvailWidth();
		finish_pos.y += header_height;
		draw_list->AddRectFilled(start_pos, finish_pos, ImGui::ColorConvertFloat4ToU32(MANDRILL_THEME_MENU(0.5f)));

		ImVec2 text_pos = start_pos;
		text_pos.x += 10.0f;
		text_pos.y += (header_height - line_height) / 2.0f;
		ImGui::SetCursorScreenPos(text_pos);

		{
			ImGui::Text("User view:");
			ImGui::SameLine();
			ImGui::SetNextItemWidth(250.0f);
			if (ImGui::BeginCombo("##userview", "<All>"))
			{
				ImGui::EndCombo();
			}
			ImGui::SameLine();
			ImGui::Button("...");
		}

		float field_search_width = ImGui::CalcTextSize("#").x * 30.0f;
		ImVec2 search_pos = text_pos;
		{
			float content_width = 0.0f;
			content_width += ImGui::CalcTextSize("search fields").x + ImGui::GetStyle().ItemSpacing.x; // "search fields"
			content_width += field_search_width + ImGui::GetStyle().ItemSpacing.x; // "text input"
			content_width += ImGui::CalcTextSize(ICON_FA_ARROW_LEFT).x + ImGui::GetStyle().FramePadding.x * 2.0f + ImGui::GetStyle().ItemSpacing.x; // "button1"
			content_width += ImGui::CalcTextSize(ICON_FA_ARROW_RIGHT).x + ImGui::GetStyle().FramePadding.x * 2.0f + ImGui::GetStyle().ItemSpacing.x; // "button2"
			content_width += ImGui::CalcTextSize(ICON_FA_TIMES).x + ImGui::GetStyle().FramePadding.x * 2.0f + ImGui::GetStyle().ItemSpacing.x; // "button3"

			search_pos.x = finish_pos.x - content_width;
		}
		ImGui::SetCursorScreenPos(search_pos);

		ImGui::Text("search fields");
		ImGui::SameLine();
		char field_search_buffer[256]{};
		ImGui::SetNextItemWidth(field_search_width);
		ImGui::InputText("##search_input", field_search_buffer, _countof(field_search_buffer));
		ImGui::SameLine();
		ImGui::Button(ICON_FA_ARROW_LEFT);
		ImGui::SameLine();
		ImGui::Button(ICON_FA_ARROW_RIGHT);
		ImGui::SameLine();
		ImGui::Button(ICON_FA_TIMES);

		finish_pos.x = start_pos.x;
		ImGui::SetCursorScreenPos(finish_pos);
	}

	{
		float header_height = line_height * 1.75f;

		ImVec2 start_pos = ImGui::GetCursorScreenPos();
		ImVec2 finish_pos = start_pos;
		finish_pos.x += ImGui::GetContentRegionAvailWidth();
		finish_pos.y += header_height;
		draw_list->AddRectFilled(start_pos, finish_pos, ImGui::ColorConvertFloat4ToU32(MANDRILL_THEME_MENU(0.5f)));

		ImVec2 text_pos = start_pos;
		text_pos.x += 10.0f;
		text_pos.y += (header_height - line_height) / 2.0f;
		ImGui::SetCursorScreenPos(text_pos);
		ImGui::Button("Quick Preview");
		ImGui::SameLine(0.0f, 25.0f);
		static bool use_live_mode = false;
		ImGui::Checkbox("Use Live Mode", &use_live_mode);
		ImGui::SameLine(0.0f, 25.0f);
		ImGui::Text("Status:");
		ImGui::SameLine();
		ImGui::Text("Ready");


		finish_pos.x = start_pos.x;
		ImGui::SetCursorScreenPos(finish_pos);
	}
	ImGui::Dummy({ 0.0f, ImGui::GetStyle().ItemSpacing.y });

	static c_custom_tool_render_model custom_tool;
	//custom_tool.render();

	ImGui::Text("Blofeld");

	const blofeld::s_tag_group* group = tag_interface.get_blofeld_reflection_data();

	char* data = tag_interface.get_data();
	render_tag_group(data, *group);
}

void c_blofeld_tag_editor_tab::render_menu_gui_impl()
{

}

void c_blofeld_tag_editor_tab::render_file_dialogue_gui_impl()
{

}

void c_blofeld_tag_editor_tab::render_game_layer_impl()
{

}

ImGuiDataType field_to_imgui_data_type(blofeld::e_field field_type)
{
	switch (field_type)
	{
	case blofeld::_field_char_enum:return ImGuiDataType_S8;
	case blofeld::_field_enum: return ImGuiDataType_S16;
	case blofeld::_field_long_enum: return ImGuiDataType_S32;
	case blofeld::_field_long_flags: return ImGuiDataType_S32;
	case blofeld::_field_word_flags: return ImGuiDataType_S16;
	case blofeld::_field_byte_flags:return ImGuiDataType_S8;
	case blofeld::_field_char_integer: return ImGuiDataType_S8;
	case blofeld::_field_short_integer: return ImGuiDataType_S16;
	case blofeld::_field_long_integer: return ImGuiDataType_S32;
	case blofeld::_field_int64_integer: return ImGuiDataType_S64;
	case blofeld::_field_angle: return ImGuiDataType_Float;
	case blofeld::_field_real: return ImGuiDataType_Float;
	case blofeld::_field_real_fraction: return ImGuiDataType_Float;
	}
}

uint32_t c_blofeld_tag_editor_tab::get_struct_size(const blofeld::s_tag_struct_definition& struct_definition)
{
	e_engine_type engine_type = tag_interface.get_cache_file().get_engine_type();

	uint32_t size = 0;

	for (const blofeld::s_tag_field* current_field = struct_definition.fields; current_field->field_type != blofeld::_field_terminator; current_field++)
	{
		uint32_t field_skip_count;
		if (skip_tag_field_version(*current_field, engine_type, _build_not_set, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		uint32_t field_size = get_field_size(*current_field);
		size += field_size;
	}

	return size;
}

uint32_t c_blofeld_tag_editor_tab::get_field_size(const blofeld::s_tag_field& field)
{
	uint32_t field_size = get_blofeld_field_size(field.field_type);
	if (field_size > 0)
	{
		return field_size;
	}
	switch (field.field_type)
	{
	case blofeld::_field_explanation:					return 0;	// empty
	case blofeld::_field_custom:						return 0;	// empty
	case blofeld::_field_terminator:					return 0;	// empty
	case blofeld::_field_pad:							return field.padding;	// dynamic
	case blofeld::_field_useless_pad:					return 0;	// dynamic
	case blofeld::_field_skip:							return field.padding;	// dynamic
	case blofeld::_field_struct:						
	{
		uint32_t struct_size = get_struct_size(*field.struct_definition);	// dynamic
		return struct_size;
	}
	case blofeld::_field_array:							return get_struct_size(field.array_definition->struct_definition) * field.array_definition->count;	// dynamic
	}
}

uint32_t c_blofeld_tag_editor_tab::render_tag_struct_definition(char* const data, const blofeld::s_tag_struct_definition& struct_definition)
{
	e_engine_type engine_type = tag_interface.get_cache_file().get_engine_type();

	uint32_t struct_size = get_struct_size(struct_definition);	// dynamic

	ImGui::Dummy({ 30.0f, 30.0f });
	ImGui::Text("------ START %s [size:0x%x] ------", struct_definition.name, struct_size);
	ImGui::Dummy({ 10.0f, 10.0f });
	uint32_t bytes_traversed = 0;
	int32_t field_index = 0;
	char* current_data_position = data;
	for (const blofeld::s_tag_field* current_field = struct_definition.fields; current_field->field_type != blofeld::_field_terminator; (current_field++, field_index++))
	{
		uint32_t field_skip_count;
		if (skip_tag_field_version(*current_field, engine_type, _build_not_set, field_skip_count))
		{
			current_field += field_skip_count;
			continue;
		}

		const char* field_typename = field_to_string(current_field->field_type);
		ASSERT(field_typename != nullptr);


		ImGui::PushID(current_data_position);
		switch (current_field->field_type)
		{
		case blofeld::_field_struct:
			render_tag_struct_definition(current_data_position, *current_field->struct_definition);
			break;
		case blofeld::_field_array:
			for (uint32_t i = 0; i < current_field->array_definition->count; i++)
			{
				render_tag_struct_definition(current_data_position, current_field->array_definition->struct_definition);
			}
			break;
		case blofeld::_field_char_enum:
		case blofeld::_field_enum:
		case blofeld::_field_long_enum:
		case blofeld::_field_long_flags:
		case blofeld::_field_word_flags:
		case blofeld::_field_byte_flags:
		case blofeld::_field_char_integer:
		case blofeld::_field_short_integer:
		case blofeld::_field_long_integer:
		case blofeld::_field_int64_integer:
		case blofeld::_field_angle:
		case blofeld::_field_real:
		case blofeld::_field_real_fraction:
			ImGui::InputScalar(current_field->name, field_to_imgui_data_type(current_field->field_type), current_data_position);
			break;
		case blofeld::_field_real_point_2d:
		case blofeld::_field_real_vector_2d:
		case blofeld::_field_real_euler_angles_2d:
		case blofeld::_field_real_bounds:
		case blofeld::_field_real_fraction_bounds:
		case blofeld::_field_angle_bounds:
			ImGui::InputFloat2(current_field->name, reinterpret_cast<float*>(current_data_position), 7);
			break;
		case blofeld::_field_real_point_3d:
		case blofeld::_field_real_vector_3d:
		case blofeld::_field_real_euler_angles_3d:
		case blofeld::_field_real_plane_2d:
			ImGui::InputFloat3(current_field->name, reinterpret_cast<float*>(current_data_position), 7);
			break;
		case blofeld::_field_real_plane_3d:
		case blofeld::_field_real_quaternion:
			ImGui::InputFloat4(current_field->name, reinterpret_cast<float*>(current_data_position), 7);
			break;
		case blofeld::_field_string:
			ImGui::InputText(current_field->name, current_data_position, 32);
			break;
		case blofeld::_field_long_string:
			ImGui::InputText(current_field->name, current_data_position, 256);
			break;
			break;
		case blofeld::_field_string_id:
		case blofeld::_field_old_string_id:
			ImGui::InputInt(current_field->name, reinterpret_cast<int*>(current_data_position));
			break;
		case blofeld::_field_explanation:
			ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor::ImColor(0.7f, 1.0f, 0.7f));
			ImGui::Text(current_field->explanation);
			ImGui::PopStyleColor(1);
			break;		
		case blofeld::_field_block:
		{
			s_tag_block& tag_block = *reinterpret_cast<s_tag_block*>(current_data_position);

			bool is_valid = true;
			is_valid &= tag_block.definition_address == 0;
			if (tag_block.count == 0)
			{
				is_valid &= tag_block.address == 0;
			}
			else if (c_gen3_cache_file* gen3_cache_file = dynamic_cast<c_gen3_cache_file*>(&tag_interface.get_cache_file()))
			{
				char* data_address = gen3_cache_file->get_data_with_page_offset(tag_block.address);
				is_valid &= gen3_cache_file->is_valid_data_address(data_address);
			}

			ImDrawList* draw_list = ImGui::GetWindowDrawList();
			ImVec2 group_start_pos = ImGui::GetCursorScreenPos();
			ImGui::BeginGroup();
			ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor::ImColor(1.0f, 0.7f, 0.7f));
			ImGui::Text("Tag Block %s", current_field->name);
			ImGui::Text("count: %i", tag_block.count);
			ImGui::Text("address: %i", tag_block.address);
			float status_pos_y = ImGui::GetCursorScreenPos().y;
			ImGui::Text("definition_address: %i", tag_block.definition_address);
			ImGui::PopStyleColor(1);
			ImGui::EndGroup();
			ImVec2 end_pos = ImGui::GetCursorScreenPos();
			ImVec2 group_end_pos = ImGui::GetItemRectSize();
			group_end_pos.x += group_start_pos.x;
			group_end_pos.y += group_start_pos.y;

			draw_list->AddRect(group_start_pos, group_end_pos, ImGui::ColorConvertFloat4ToU32({ 1.0f, 0.7f, 0.7f, 0.5f }));

			ImVec2 status_pos = { group_end_pos.x + 5.0f,status_pos_y };
			ImGui::SetCursorScreenPos(status_pos);

			if (is_valid)
			{
				ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor::ImColor(0.3f, 1.0f, 0.3f));
				ImGui::Text("valid");
			}
			else
			{
				ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor::ImColor(1.0f, 0.3f, 0.3f));
				ImGui::Text("invalid");
			}
			ImGui::PopStyleColor(1);

			ImGui::SetCursorScreenPos(end_pos);
		}
		break;
		case blofeld::_field_tag_reference:
		{
			s_tag_reference& tag_reference = *reinterpret_cast<s_tag_reference*>(current_data_position);

			union
			{
				uint64_t __group_tag;
				char group_tag_buffer[8];
			};
			__group_tag = _byteswap_ulong(tag_reference.group_tag);

			bool is_valid = true;
			if (tag_reference.group_tag == UINT32_MAX)
			{
				is_valid &= tag_reference.name_length == 0;
				is_valid &= tag_reference.index == UINT16_MAX;
				is_valid &= tag_reference.datum == UINT16_MAX;
			}
			else
			{
				const char* known_legacy_tag_group_name = get_known_legacy_tag_group_name(tag_reference.group_tag);
				is_valid = known_legacy_tag_group_name != nullptr;
			}

			ImDrawList* draw_list = ImGui::GetWindowDrawList();
			ImVec2 group_start_pos = ImGui::GetCursorScreenPos();
			ImGui::BeginGroup();
			ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor::ImColor(0.7f, 0.7f, 1.0f));
			ImGui::Text("Tag Reference %s", current_field->name);
			ImGui::Text("group_tag: '%s'", tag_reference.group_tag == 0xFFFFFFFF ? "<null>" : group_tag_buffer);
			ImGui::Text("name_length: %i", tag_reference.name_length);
			ImGui::Text("index: %u", static_cast<uint32_t>(tag_reference.index));
			float status_pos_y = ImGui::GetCursorScreenPos().y;
			ImGui::Text("datum: %u", static_cast<uint32_t>(tag_reference.datum));
			ImGui::PopStyleColor(1);
			ImGui::EndGroup();
			ImVec2 end_pos = ImGui::GetCursorScreenPos();
			ImVec2 group_end_pos = ImGui::GetItemRectSize();
			group_end_pos.x += group_start_pos.x;
			group_end_pos.y += group_start_pos.y;

			draw_list->AddRect(group_start_pos, group_end_pos, ImGui::ColorConvertFloat4ToU32({ 0.7f, 0.7f, 1.0f, 0.5f }));

			ImVec2 status_pos = { group_end_pos.x + 5.0f,status_pos_y };
			ImGui::SetCursorScreenPos(status_pos);

			if (is_valid)
			{
				ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor::ImColor(0.3f, 1.0f, 0.3f));
				ImGui::Text("valid");
			}
			else
			{
				ImGui::PushStyleColor(ImGuiCol_Text, (ImVec4)ImColor::ImColor(1.0f, 0.3f, 0.3f));
				ImGui::Text("invalid");
			}
			ImGui::PopStyleColor(1);

			ImGui::SetCursorScreenPos(end_pos);
		}
		break;
		case blofeld::_field_custom:					
		case blofeld::_field_terminator:				
		case blofeld::_field_pad:						
		case blofeld::_field_useless_pad:				
		case blofeld::_field_skip:						
			break;
		default:
			ImGui::Text(current_field->name ? current_field->name : "");
			break;
		}
		ImGui::Columns(1);

		ImGui::PopID();

		uint32_t field_size = get_field_size(*current_field);
		current_data_position += field_size;
		bytes_traversed += field_size;

	}
	ImGui::Dummy({ 10.0f, 10.0f });
	ImGui::Text("------ END %s ------", struct_definition.name);
	ImGui::Dummy({ 30.0f, 30.0f });
	return bytes_traversed;
}

uint32_t c_blofeld_tag_editor_tab::render_tag_group(char* data, const blofeld::s_tag_group& group)
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
