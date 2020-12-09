#include "mandrilllib-private-pch.h"

c_high_level_tag_editor_tab::c_high_level_tag_editor_tab(c_tag_project& tag_project, h_tag& tag, c_mandrill_tab& parent) :
	c_mandrill_tab("Tag Editor", "Blofeld Tag Definition Debug", &parent, false),
	tag_project(tag_project),
	tag(tag),
	viewport_size(),
	custom_tool(nullptr)
{

}

c_high_level_tag_editor_tab::~c_high_level_tag_editor_tab()
{

}

void c_high_level_tag_editor_tab::render_impl()
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
		draw_list->AddText(text_pos, ImGui::ColorConvertFloat4ToU32(MANDRILL_THEME_TEXT(1.0f)), tag.tag_filepath.c_str());

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

	ImVec2 size = ImGui::GetContentRegionAvail();

	ImGuiWindowFlags flags = ImGuiWindowFlags_None;
	flags |= ImGuiWindowFlags_AlwaysHorizontalScrollbar;
	flags |= ImGuiWindowFlags_AlwaysVerticalScrollbar;
	ImGui::BeginChild("##fields", size, false, flags);

	viewport_size = ImGui::GetContentRegionAvail();

	render_tag_group();

	ImGui::EndChild();
}

void c_high_level_tag_editor_tab::render_menu_gui_impl(e_menu_render_type menu_render_type)
{

}

void c_high_level_tag_editor_tab::render_file_dialogue_gui_impl()
{

}

void c_high_level_tag_editor_tab::render_game_layer_impl()
{

}

template<blofeld::e_field field_type>
bool c_high_level_tag_editor_tab::render_primitive(void* data, const blofeld::s_tag_field& field)
{
	using namespace blofeld;

	bool result = false;
	ImGui::Columns(2, nullptr, false);
	ImGui::SetColumnWidth(0, k_field_display_name_width);
	{
		bool const has_description = !field.string_parser.description.is_empty();

		if (has_description)
		{
			ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_INFO_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA));
		}

		ImGui::TextUnformatted(field.string_parser.display_name.c_str());

		if (has_description)
		{
			if (ImGui::IsItemHovered())
			{
				ImGui::SetTooltip(field.string_parser.description.c_str());
			}
			ImGui::PopStyleColor();
		}

	}
	ImGui::NextColumn();
	{
		if constexpr (field_type == _field_char_integer || field_type == _field_custom_char_block_index || field_type == _field_char_block_index || field_type == _field_char_enum)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(field.string_parser.units.c_str(), ImGuiDataType_S8, data);
		}
		else if constexpr (field_type == _field_byte_flags || field_type == _field_byte_block_flags || field_type == _field_byte_integer)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(field.string_parser.units.c_str(), ImGuiDataType_U8, data);
		}
		else if constexpr (field_type == _field_enum || field_type == _field_short_block_index || field_type == _field_custom_short_block_index || field_type == _field_short_integer)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(field.string_parser.units.c_str(), ImGuiDataType_S16, data);
		}
		else if constexpr (field_type == _field_word_flags || field_type == _field_word_block_flags || field_type == _field_word_integer)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(field.string_parser.units.c_str(), ImGuiDataType_U16, data);
		}
		else if constexpr (
			field_type == _field_long_enum || 
			field_type == _field_long_flags || 
			field_type == _field_rgb_color ||
			field_type == _field_argb_color ||
			field_type == _field_long_block_flags ||
			field_type == _field_long_block_index ||
			field_type == _field_custom_long_block_index ||
			field_type == _field_long_integer) 
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(field.string_parser.units.c_str(), ImGuiDataType_S32, data);
		}
		else if constexpr (field_type == _field_dword_integer)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(field.string_parser.units.c_str(), ImGuiDataType_U32, data);
		}
		else if constexpr (field_type == _field_int64_integer)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(field.string_parser.units.c_str(), ImGuiDataType_S64, data);
		}
		else if constexpr (field_type == _field_qword_integer)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(field.string_parser.units.c_str(), ImGuiDataType_U64, data);
		}
		else if constexpr (field_type == _field_real || field_type == _field_real_fraction || field_type == _field_angle || field_type == _field_half)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(field.string_parser.units.c_str(), ImGuiDataType_Float, data);
		}
		else if constexpr (field_type == _field_short_bounds || field_type == _field_point_2d)
		{
			ImGui::SetNextItemWidth(400.0f);
			result = ImGui::InputScalarN(field.string_parser.units.c_str(), ImGuiDataType_S16, data, 2);
		}
		else if constexpr (field_type == _field_rectangle_2d)
		{
			ImGui::SetNextItemWidth(800.0f);
			result = ImGui::InputScalarN(field.string_parser.units.c_str(), ImGuiDataType_S16, data, 4);
		}
		else if constexpr (field_type == _field_real_vector_2d || field_type == _field_real_euler_angles_2d || field_type == _field_angle_bounds || field_type == _field_real_bounds || field_type == _field_real_fraction_bounds || field_type == _field_real_point_2d)
		{
			ImGui::SetNextItemWidth(400.0f);
			result = ImGui::InputScalarN(field.string_parser.units.c_str(), ImGuiDataType_Float, data, 2);
		}
		else if constexpr (field_type == _field_real_point_3d || field_type == _field_real_euler_angles_3d || field_type == _field_real_rgb_color || field_type == _field_real_hsv_color || field_type == _field_real_plane_2d || field_type == _field_real_vector_3d)
		{
			ImGui::SetNextItemWidth(600.0f);
			result = ImGui::InputScalarN(field.string_parser.units.c_str(), ImGuiDataType_Float, data, 3);
		}
		else if constexpr (field_type == _field_real_argb_color || field_type == _field_real_ahsv_color || field_type == _field_real_plane_3d || field_type == _field_real_quaternion)
		{
			ImGui::SetNextItemWidth(800.0f);
			result = ImGui::InputScalarN(field.string_parser.units.c_str(), ImGuiDataType_Float, data, 4);
		}
		else if constexpr (field_type == _field_string)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputText(field.string_parser.units.c_str(), static_cast<char*>(data), 32);
		}
		else if constexpr (field_type == _field_long_string)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputText(field.string_parser.units.c_str(), static_cast<char*>(data), 256);
		}
		else if constexpr (field_type == _field_string_id)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputText(field.string_parser.units.c_str(), static_cast<char*>(data), 2048);
		}
		else if constexpr (field_type == _field_old_string_id)
		{
			// not really sure what the correct representation of this is...

			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(field.string_parser.units.c_str(), ImGuiDataType_S32, data);
		}
	}
	ImGui::Columns(1);

	return result;
}
//
//bool c_high_level_tag_editor_tab::render_primitive(void* data, const blofeld::s_tag_field& field)
//{
//	//struct s_flags_dynamic_data
//	//{
//	//	s_flags_dynamic_data(const blofeld::s_tag_field& field) :
//	//		is_active(false),
//	//		string_parser(*new c_blamlib_string_parser(field.name, false, nullptr))
//	//	{
//	//		
//	//	}
//
//	//	~s_flags_dynamic_data()
//	//	{
//	//		delete& string_parser;
//	//	}
//
//	//	bool is_active;
//	//	c_blamlib_string_parser& string_parser; // #TODO: remove
//	//};
//	//s_flags_dynamic_data& dynamic_data = get_dynamic_data<s_flags_dynamic_data>(data, field);
//
//	//bool result = false;
//
//	//ImGui::Columns(2, nullptr, false);
//	//ImGui::SetColumnWidth(0, k_field_display_name_width);
//
//	//c_blamlib_string_parser field_formatter = c_blamlib_string_parser(field.name); // #TODO: remove
//
//	//bool const current_string_has_tooltip = !field_formatter.description.is_empty();
//	//if (current_string_has_tooltip)
//	//{
//	//	ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_INFO_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA));
//	//	ImGui::TextUnformatted(field_formatter.display_name.c_str());
//	//	ImGui::PopStyleColor();
//	//}
//	//else
//	//{
//	//	ImGui::TextUnformatted(field_formatter.display_name.c_str());
//	//}
//
//	//if (!field_formatter.description.is_empty() && ImGui::IsItemHovered())
//	//{
//	//	ImGui::SetTooltip(field_formatter.description.c_str());
//	//}
//
//	//ImGui::NextColumn();
//	//{
//	//	int components;
//	//	ImGuiDataType data_type;
//	//	if (field_type_to_imgui_data_type(field.field_type, data_type, components))
//	//	{
//	//		if (dynamic_data.is_active)
//	//		{
//	//			ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);
//	//			ImGui::PushStyleColor(ImGuiCol_Border, MANDRILL_THEME_HIGH(1.0f));
//	//		}
//	//		if (components <= 1)
//	//		{
//	//			ImGui::SetNextItemWidth(350);
//
//	//			result = ImGui::InputScalar(field_formatter.units.c_str(), data_type, data);
//	//		}
//	//		else
//	//		{
//	//			ImGui::SetNextItemWidth(200.0f * static_cast<float>(components));
//
//	//			result = ImGui::InputScalarN(field_formatter.units.c_str(), data_type, data, components);
//	//		}
//	//		if (dynamic_data.is_active)
//	//		{
//	//			ImGui::PopStyleVar();
//	//			ImGui::PopStyleColor();
//	//		}
//	//		dynamic_data.is_active = ImGui::IsItemActive(); // #TODO: is there a more efficient way to do this?
//	//	}
//	//}
//	//ImGui::NextColumn();
//	//ImGui::Columns(1);
//
//	//return result;
//
//	return false;
//}

void c_high_level_tag_editor_tab::render_string(void* data, const blofeld::s_tag_field& field)
{
	//struct s_string_editor_dynamic_data
	//{
	//	s_string_editor_dynamic_data(const blofeld::s_tag_field& field) :
	//		is_active(false),
	//		string_parser(*new c_blamlib_string_parser(field.name, false, nullptr))
	//	{

	//	}

	//	~s_string_editor_dynamic_data()
	//	{
	//		delete& string_parser;
	//	}

	//	bool is_active;
	//	c_blamlib_string_parser& string_parser; // #TODO: remove
	//};
	//s_string_editor_dynamic_data& dynamic_data = get_dynamic_data<s_string_editor_dynamic_data>(data, field);

	//ImGui::Columns(2, nullptr, false);
	//ImGui::SetColumnWidth(0, k_field_display_name_width);

	//c_blamlib_string_parser field_formatter = c_blamlib_string_parser(field.name); // #TODO: remove

	//bool const current_string_has_tooltip = !field_formatter.description.is_empty();
	//if (current_string_has_tooltip)
	//{
	//	ImGui::TextColored(MANDRILL_THEME_INFO_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA), field_formatter.display_name.c_str());
	//}
	//else
	//{
	//	ImGui::Text(field_formatter.display_name.c_str());
	//}

	//if (!field_formatter.description.is_empty() && ImGui::IsItemHovered())
	//{
	//	ImGui::SetTooltip(field_formatter.description.c_str());
	//}

	//ImGui::NextColumn();
	//{
	//	if (dynamic_data.is_active)
	//	{
	//		ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);
	//		ImGui::PushStyleColor(ImGuiCol_Border, MANDRILL_THEME_HIGH(1.0f));
	//	}
	//	switch (field.field_type)
	//	{
	//	case blofeld::_field_string:
	//		ImGui::SetNextItemWidth(350);
	//		ImGui::InputText("##string", static_cast<char*>(data), 32);
	//		break;
	//	case blofeld::_field_long_string:
	//		ImGui::SetNextItemWidth(800);
	//		ImGui::InputText("##string", static_cast<char*>(data), 256);
	//		break;
	//	}
	//	if (dynamic_data.is_active)
	//	{
	//		ImGui::PopStyleVar();
	//		ImGui::PopStyleColor();
	//	}
	//	dynamic_data.is_active = ImGui::IsItemActive(); // #TODO: is there a more efficient way to do this?
	//}
	//ImGui::NextColumn();
	//ImGui::Columns(1);
}

void c_high_level_tag_editor_tab::render_string_id(void* data, const blofeld::s_tag_field& field)
{
	//struct s_string_editor_dynamic_data
	//{
	//	s_string_editor_dynamic_data(const blofeld::s_tag_field& field) :
	//		is_active(false),
	//		string_parser(*new c_blamlib_string_parser(field.name, false, nullptr))
	//	{
	//		
	//	}

	//	~s_string_editor_dynamic_data()
	//	{
	//		delete& string_parser;
	//	}

	//	bool is_active;
	//	c_blamlib_string_parser& string_parser; // #TODO: remove
	//};
	//s_string_editor_dynamic_data& dynamic_data = get_dynamic_data<s_string_editor_dynamic_data>(data, field);

	//ImGui::Columns(2, nullptr, false);
	//ImGui::SetColumnWidth(0, k_field_display_name_width);

	//c_blamlib_string_parser field_formatter = c_blamlib_string_parser(field.name); // #TODO: remove

	//uint32_t& string_id = *static_cast<uint32_t*>(data);
	//const char* string_id_value = cache_file.get_string_id(string_id, nullptr);
	//bool is_valid = string_id_value != nullptr;
	//if (!is_valid) string_id_value = "<invalid string_id>";

	//bool const current_string_has_tooltip = !field_formatter.description.is_empty();
	//if (current_string_has_tooltip)
	//{
	//	ImGui::TextColored(MANDRILL_THEME_INFO_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA), field_formatter.display_name.c_str());
	//}
	//else
	//{
	//	ImGui::Text(field_formatter.display_name.c_str());
	//}

	//if (!field_formatter.description.is_empty() && ImGui::IsItemHovered())
	//{
	//	ImGui::SetTooltip(field_formatter.description.c_str());
	//}

	//ImGui::NextColumn();
	//{
	//	if (dynamic_data.is_active)
	//	{
	//		ImGui::PushStyleVar(ImGuiStyleVar_FrameBorderSize, 1.0f);
	//		ImGui::PushStyleColor(ImGuiCol_Border, MANDRILL_THEME_HIGH(1.0f));
	//	}
	//	switch (field.field_type)
	//	{
	//	case blofeld::_field_string_id:
	//		ImGui::SetNextItemWidth(350);
	//		ImGui::InputText("##string", const_cast<char*>(string_id_value), 256, ImGuiInputTextFlags_ReadOnly);
	//		break;
	//	case blofeld::_field_old_string_id:
	//		ImGui::SetNextItemWidth(800);
	//		ImGui::InputText("##string", const_cast<char*>(string_id_value), 256, ImGuiInputTextFlags_ReadOnly);
	//		break;
	//	}
	//	if (dynamic_data.is_active)
	//	{
	//		ImGui::PopStyleVar();
	//		ImGui::PopStyleColor();
	//	}
	//	dynamic_data.is_active = ImGui::IsItemActive(); // #TODO: is there a more efficient way to do this?
	//}
	//ImGui::NextColumn();
	//ImGui::Columns(1);
}

void c_high_level_tag_editor_tab::render_tag_block(h_block& block, const blofeld::s_tag_field& field)
{
	constexpr float k_min_block_width = 1000.0f;
	constexpr float k_block_header_height = 80.0f;

	uint32_t const tag_block_count = block.size();

	ImGui::PushID(&field);
	uint32_t const is_open_id = ImGui::GetID("is_open");
	uint32_t const position_id = ImGui::GetID("position");
	uint32_t const content_width_id = ImGui::GetID("content_width");

	ImGuiStorage* storage = ImGui::GetStateStorage();
	bool is_open = static_cast<bool>(storage->GetInt(is_open_id));
	float content_width = storage->GetFloat(position_id, k_min_block_width);
	uint32_t position = static_cast<uint32_t>(storage->GetInt(content_width_id));

	ImVec2 collapsing_header_pos = ImGui::GetCursorPos();

	ImGui::Dummy({ 0.0f, k_block_header_height });

	if (is_open)
	{
		if (tag_block_count > 0)
		{
			ImGui::BeginGroup();
			ImGui::Dummy({ 15.0f, 0.0f });
			ImGui::SameLine();
			ImGui::BeginGroup();

			h_object& object = block.get(position);
			render_object(0, object);

			ImGui::EndGroup();
			ImGui::Dummy({ 15.0f, 15.0f });
			ImGui::EndGroup();

			content_width = ImGui::GetItemRectSize().x;
		}
		else
		{
			content_width = k_min_block_width;
			is_open = false;
		}
	}


	ImVec2 block_finish_pos = ImGui::GetCursorPos();

	ImGui::SetCursorPos(collapsing_header_pos);

	float width = k_min_block_width;
	if (is_open)
	{
		width = __max(k_min_block_width, content_width);
	}

	if (ImGui::BeginChild("##block", ImVec2(width, k_block_header_height), false, ImGuiWindowFlags_NoScrollbar))
	{

		ImGui::Columns(3, "##block_controls", false);
		ImGui::SetColumnWidth(0, width - 80);
		ImGui::SetColumnWidth(1, 40);
		ImGui::SetColumnWidth(2, 40);

		{
			ImGui::Dummy({ 3.0f, 3.0f });
			if (tag_block_count == 0)
			{
				ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
				ImGui::PushStyleColor(ImGuiCol_Header, MANDRILL_THEME_DISABLED_MED(0.76f));
				ImGui::PushStyleColor(ImGuiCol_HeaderHovered, MANDRILL_THEME_DISABLED_MED(0.86f));
				ImGui::PushStyleColor(ImGuiCol_HeaderActive, MANDRILL_THEME_DISABLED_HIGH(1.00f));
			}
			c_fixed_string_128 header_str;
			header_str.format("%s : count:%u", field.string_parser.display_name.c_str(), tag_block_count);
			is_open = ImGui::CollapsingHeader(
				header_str.c_str(),
				/*ImGuiTreeNodeFlags_DefaultOpen |*/ 
				/*ImGuiTreeNodeFlags_OpenOnArrow |*/ 
				ImGuiTreeNodeFlags_Framed | 
				ImGuiTreeNodeFlags_AllowItemOverlap);
			if (tag_block_count == 0)
			{
				ImGui::PopStyleColor(3);
				ImGui::PopItemFlag();
			}
		}
		ImGui::NextColumn();
		{
			ImGui::Dummy({ 0.0f, 3.0f });
			ImGui::SetNextItemWidth(-1);
			ImGui::Button(ICON_FA_COG);
		}
		ImGui::NextColumn();
		{
			ImGui::Dummy({ 0.0f, 3.0f });
			ImGui::SetNextItemWidth(-1);
			ImGui::Button(ICON_FA_INFO);
		}
		ImGui::NextColumn();

		ImGui::Columns(1);
		ImGui::Dummy({ 3.0f, 0.0f });
		ImGui::SameLine();
		{
			ImGui::SetNextItemWidth(350);
			if (tag_block_count > 0)
			{
				// #TODO: advanced block index formatting
				c_fixed_string_128 index_str = "None";
				index_str.format("index: %u", position);
				if (ImGui::BeginCombo("##index", index_str.c_str()))
				{
					ImGui::EndCombo();
				}
			}
			else
			{
				ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);

				if (ImGui::BeginCombo("##index", "None"))
				{
					ImGui::EndCombo();
				}

				ImGui::PopItemFlag();
			}
		}


		ImGui::SameLine();
		if (ImGui::Button(ICON_FA_PLUS))
		{
			position++;
			if (tag_block_count == 0)
			{
				position = 0;
			}
			else if (position == tag_block_count)
			{
				position = 0;
			}
		}
		ImGui::SameLine();
		if (ImGui::Button(ICON_FA_MINUS))
		{
			position--;
			if (tag_block_count == 0)
			{
				position = 0;
			}
			else if (position > tag_block_count) // unsigned underflow
			{
				position = tag_block_count - 1;
			}
		}
		ImGui::SameLine();
		ImGui::Dummy({ 25.0f, 0.0f });
		ImGui::SameLine();
		ImGui::Button("Add");

		if (tag_block_count == 0)
		{
			ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
		}
		if (tag_block_count == 0)
		{
			ImGui::PopItemFlag();
		}
		ImGui::SameLine();
		//ImGui::InputScalar("count", ImGuiDataType_U32, &tag_block_count);
		//ImGui::SameLine();
		//ImGui::Button("Insert");
		//ImGui::SameLine();
		//ImGui::Button("Duplicate");
		//ImGui::SameLine();
		//ImGui::Dummy({ 25.0f, 0.0f });
		//ImGui::SameLine();
		//ImGui::Button("Delete");
		//ImGui::SameLine();
		//ImGui::Button("Delete All");
	}
	ImGui::EndChild();

	ImGui::SetCursorPos(block_finish_pos);

	storage->SetInt(is_open_id, static_cast<int>(is_open));
	storage->SetFloat(position_id, content_width);
	storage->SetInt(content_width_id, static_cast<int>(position));

	ImGui::PopID();
}

void c_high_level_tag_editor_tab::render_tag_reference(h_tag*& tag_reference, const blofeld::s_tag_field& field)
{
	//using namespace blofeld;

	//bool result = false;
	//ImGui::Columns(2, nullptr, false);
	//ImGui::SetColumnWidth(0, k_field_display_name_width);
	//{
	//	bool const has_description = !field.string_parser.description.is_empty();

	//	if (has_description)
	//	{
	//		ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_INFO_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA));
	//	}

	//	ImGui::TextUnformatted(field.string_parser.display_name.c_str());

	//	if (has_description)
	//	{
	//		if (ImGui::IsItemHovered())
	//		{
	//			ImGui::SetTooltip(field.string_parser.description.c_str());
	//		}
	//		ImGui::PopStyleColor();
	//	}

	//}
	//ImGui::NextColumn();
	//{
	//	ImGui::SetNextItemWidth(250);
	//	bool combo_active = ImGui::BeginCombo("##tag_tag_group", group_name);
	//	if (tag_group_interface && ImGui::IsItemHovered())
	//	{
	//		ImGui::SetTooltip(group_name);
	//	}
	//	if (combo_active)
	//	{
	//		if (ImGui::Selectable("(null)", tag_group_interface == nullptr))
	//		{
	//			tag_reference.group_tag = blofeld::INVALID_TAG;
	//			tag_reference.name = 0;
	//			tag_reference.name_length = 0;
	//			tag_reference.index = UINT16_MAX;
	//			tag_reference.datum = UINT16_MAX;
	//			tag_group_interface = nullptr;
	//		}

	//		if (tag_reference_definition.group_tag != blofeld::INVALID_TAG)
	//		{
	//			for (c_tag_group_interface& current_tag_group_interface : c_reference_loop(cache_file.get_tag_group_interfaces(), cache_file.get_tag_group_count()))
	//			{
	//				if (current_tag_group_interface.get_group_tag() != tag_reference_definition.group_tag)
	//				{
	//					continue;
	//				}

	//				bool is_selected = &current_tag_group_interface == tag_group_interface;

	//				const char* current_group_name = current_tag_group_interface.get_full_name();
	//				if (ImGui::Selectable(current_group_name, is_selected) && !is_selected)
	//				{
	//					tag_group_interface = &current_tag_group_interface;
	//					tag_reference.group_tag = current_tag_group_interface.get_group_tag();
	//					tag_reference.name = 0;
	//					tag_reference.name_length = 0;
	//					tag_reference.index = UINT16_MAX;
	//					tag_reference.datum = UINT16_MAX;
	//				}
	//			}
	//		}
	//		else if (const unsigned long* const group_tags = tag_reference_definition.group_tags)
	//		{
	//			for (const unsigned long* current_group_tag = group_tags; *current_group_tag != blofeld::INVALID_TAG; current_group_tag++)
	//			{
	//				for (c_tag_group_interface& current_tag_group_interface : c_reference_loop(cache_file.get_tag_group_interfaces(), cache_file.get_tag_group_count()))
	//				{
	//					if (current_tag_group_interface.get_group_tag() != *current_group_tag)
	//					{
	//						continue;
	//					}

	//					bool is_selected = &current_tag_group_interface == tag_group_interface;

	//					const char* current_group_name = current_tag_group_interface.get_full_name();
	//					if (ImGui::Selectable(current_group_name, is_selected) && !is_selected)
	//					{
	//						tag_group_interface = &current_tag_group_interface;
	//						tag_reference.group_tag = current_tag_group_interface.get_group_tag();
	//						tag_reference.name = 0;
	//						tag_reference.name_length = 0;
	//						tag_reference.index = UINT16_MAX;
	//						tag_reference.datum = UINT16_MAX;
	//					}

	//					break;
	//				}
	//			}
	//		}
	//		else
	//		{
	//			for (c_tag_group_interface& current_tag_group_interface : c_reference_loop(cache_file.get_tag_group_interfaces(), cache_file.get_tag_group_count()))
	//			{
	//				bool is_selected = &current_tag_group_interface == tag_group_interface;

	//				const char* current_group_name = current_tag_group_interface.get_full_name();
	//				if (ImGui::Selectable(current_group_name, is_selected) && !is_selected)
	//				{
	//					tag_group_interface = &current_tag_group_interface;
	//					tag_reference.group_tag = current_tag_group_interface.get_group_tag();
	//					tag_reference.name = 0;
	//					tag_reference.name_length = 0;
	//					tag_reference.index = UINT16_MAX;
	//					tag_reference.datum = UINT16_MAX;
	//				}
	//			}
	//		}

	//		ImGui::EndCombo();
	//	}
	//}
	//ImGui::SameLine();
	//{
	//	ImGui::SetNextItemWidth(700);

	//	const char* tag_instance_name = "";
	//	c_tag_interface* current_interface = nullptr;
	//	if (tag_group_interface)
	//	{
	//		current_interface = cache_file.get_tag_interface(tag_reference.index);
	//		if (current_interface)
	//		{
	//			tag_instance_name = current_interface->get_path_with_group_name_cstr();
	//		}
	//	}

	//	bool combo_active = ImGui::BeginCombo("##tag_path", tag_instance_name);
	//	if (*tag_instance_name && ImGui::IsItemHovered())
	//	{
	//		ImGui::SetTooltip(tag_instance_name);
	//	}
	//	if (combo_active)
	//	{
	//		if (tag_group_interface)
	//		{
	//			for (c_tag_interface& current_tag_interface : c_reference_loop(cache_file.get_tag_interfaces(), cache_file.get_tag_count()))
	//			{
	//				if (current_tag_interface.is_null())
	//				{
	//					continue;
	//				}
	//				if (current_tag_interface.get_tag_group_interface() != tag_group_interface)
	//				{
	//					continue;
	//				}

	//				const char* current_name = current_tag_interface.get_path_with_group_name_cstr();
	//				bool is_selected = &current_tag_interface == current_interface;
	//				if (ImGui::Selectable(current_name, is_selected) && !is_selected)
	//				{
	//					tag_group_interface = current_tag_interface.get_tag_group_interface();
	//					if (tag_group_interface)
	//					{
	//						tag_reference.group_tag = tag_group_interface->get_group_tag();
	//						tag_reference.name = 0;
	//						tag_reference.name_length = 0;
	//						tag_reference.index = current_tag_interface.get_index();
	//						tag_reference.datum = UINT16_MAX;
	//					}
	//					else
	//					{
	//						c_console::write_line("failed to set tag reference, tag group was null");

	//						tag_reference.group_tag = blofeld::INVALID_TAG;
	//						tag_reference.name = 0;
	//						tag_reference.name_length = 0;
	//						tag_reference.index = UINT16_MAX;
	//						tag_reference.datum = UINT16_MAX;
	//					}
	//				}
	//			}
	//		}
	//		else if (tag_reference_definition.group_tag != blofeld::INVALID_TAG)
	//		{
	//			for (c_tag_interface& current_tag_interface : c_reference_loop(cache_file.get_tag_interfaces(), cache_file.get_tag_count()))
	//			{
	//				if (current_tag_interface.is_null())
	//				{
	//					continue;
	//				}
	//				if (current_tag_interface.get_tag_group_interface()->get_group_tag() != tag_reference_definition.group_tag)
	//				{
	//					continue;
	//				}

	//				const char* current_name = current_tag_interface.get_path_with_group_name_cstr();
	//				bool is_selected = &current_tag_interface == current_interface;
	//				if (ImGui::Selectable(current_name, is_selected) && !is_selected)
	//				{
	//					tag_group_interface = current_tag_interface.get_tag_group_interface();
	//					if (tag_group_interface)
	//					{
	//						tag_reference.group_tag = tag_group_interface->get_group_tag();
	//						tag_reference.name = 0;
	//						tag_reference.name_length = 0;
	//						tag_reference.index = current_tag_interface.get_index();
	//						tag_reference.datum = UINT16_MAX;
	//					}
	//					else
	//					{
	//						c_console::write_line("failed to set tag reference, tag group was null");

	//						tag_reference.group_tag = blofeld::INVALID_TAG;
	//						tag_reference.name = 0;
	//						tag_reference.name_length = 0;
	//						tag_reference.index = UINT16_MAX;
	//						tag_reference.datum = UINT16_MAX;
	//					}
	//				}
	//			}
	//		}
	//		else if (const unsigned long* const group_tags = tag_reference_definition.group_tags)
	//		{
	//			for (c_tag_interface& current_tag_interface : c_reference_loop(cache_file.get_tag_interfaces(), cache_file.get_tag_count()))
	//			{
	//				if (current_tag_interface.is_null())
	//				{
	//					continue;
	//				}
	//				for (const unsigned long* current_group_tag = group_tags; *current_group_tag != blofeld::INVALID_TAG; current_group_tag++)
	//				{
	//					if (current_tag_interface.get_tag_group_interface()->get_group_tag() == *current_group_tag)
	//					{
	//						goto is_valid_type;
	//					}
	//				}
	//				continue;
	//			is_valid_type:

	//				const char* current_name = current_tag_interface.get_path_with_group_name_cstr();
	//				bool is_selected = &current_tag_interface == current_interface;
	//				if (ImGui::Selectable(current_name, is_selected) && !is_selected)
	//				{
	//					tag_group_interface = current_tag_interface.get_tag_group_interface();
	//					if (tag_group_interface)
	//					{
	//						tag_reference.group_tag = tag_group_interface->get_group_tag();
	//						tag_reference.name = 0;
	//						tag_reference.name_length = 0;
	//						tag_reference.index = current_tag_interface.get_index();
	//						tag_reference.datum = UINT16_MAX;
	//					}
	//					else
	//					{
	//						c_console::write_line("failed to set tag reference, tag group was null");

	//						tag_reference.group_tag = blofeld::INVALID_TAG;
	//						tag_reference.name = 0;
	//						tag_reference.name_length = 0;
	//						tag_reference.index = UINT16_MAX;
	//						tag_reference.datum = UINT16_MAX;
	//					}
	//				}
	//			}
	//		}
	//		else
	//		{
	//			for (c_tag_interface& current_tag_interface : c_reference_loop(cache_file.get_tag_interfaces(), cache_file.get_tag_count()))
	//			{
	//				const char* current_name = current_tag_interface.get_path_with_group_name_cstr();
	//				bool is_selected = &current_tag_interface == current_interface;
	//				if (ImGui::Selectable(current_name, is_selected) && !is_selected)
	//				{
	//					tag_group_interface = current_tag_interface.get_tag_group_interface();
	//					if (tag_group_interface)
	//					{
	//						tag_reference.group_tag = tag_group_interface->get_group_tag();
	//						tag_reference.name = 0;
	//						tag_reference.name_length = 0;
	//						tag_reference.index = current_tag_interface.get_index();
	//						tag_reference.datum = UINT16_MAX;
	//					}
	//					else
	//					{
	//						c_console::write_line("failed to set tag reference, tag group was null");

	//						tag_reference.group_tag = blofeld::INVALID_TAG;
	//						tag_reference.name = 0;
	//						tag_reference.name_length = 0;
	//						tag_reference.index = UINT16_MAX;
	//						tag_reference.datum = UINT16_MAX;
	//					}
	//				}
	//			}
	//		}

	//		ImGui::EndCombo();
	//	}
	//}
	//ImGui::SameLine();
	//{
	//	if (tag_reference.index == UINT16_MAX)
	//	{
	//		ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
	//	}

	//	if (ImGui::Button("Open"))
	//	{
	//		if (tag_reference.index != UINT16_MAX)
	//		{
	//			if (c_tag_interface* tag_interface = cache_file.get_tag_interface(tag_reference.index))
	//			{
	//				if (c_cache_file_tab* cache_file_tab = search_parent_tab_type<c_cache_file_tab>())
	//				{
	//					cache_file_tab->open_tag_interface_tab(*tag_interface);
	//				}
	//			}
	//		}
	//	}
	//	else if (ImGui::IsItemHovered())
	//	{
	//		ImGui::SetTooltip("Opens this tag in a new tab");
	//	}

	//	//ImGui::SameLine();
	//	//ImGui::Button("Import");

	//	ImGui::SameLine();
	//	ImGui::Dummy({ 20.0f, 0.0f });

	//	ImGui::SameLine();
	//	if (ImGui::Button("Clear"))
	//	{
	//		tag_reference.group_tag = blofeld::INVALID_TAG;
	//		tag_reference.name = 0;
	//		tag_reference.name_length = 0;
	//		tag_reference.index = UINT16_MAX;
	//		tag_reference.datum = UINT16_MAX;
	//	}
	//	else if (ImGui::IsItemHovered())
	//	{
	//		ImGui::SetTooltip("Nulls this tag reference");
	//	}

	//	if (tag_reference.index == UINT16_MAX)
	//	{
	//		ImGui::PopItemFlag();
	//	}
	//}
	//ImGui::Columns(1);
}

void c_high_level_tag_editor_tab::render_flags_definition(void* data, const blofeld::s_tag_field& field)
{
	//DEBUG_ASSERT(field.string_list_definition != nullptr);
	//if (field.string_list_definition == nullptr)
	//{
	//	ImGui::Text("Flag field fail. String list definition is null!");
	//	return;
	//}
	//const blofeld::s_string_list_definition& string_list_definition = *field.string_list_definition;

	//uint64_t value = 0;
	//switch (field.field_type)
	//{
	//case blofeld::_field_byte_flags:
	//	value = *reinterpret_cast<uint8_t*>(data);
	//	break;
	//case blofeld::_field_word_flags:
	//	value = *reinterpret_cast<uint16_t*>(data);
	//	break;
	//case blofeld::_field_long_flags:
	//	value = *reinterpret_cast<uint32_t*>(data);
	//	break;
	//	//case blofeld::_field_qword_flags:
	//	//	current_value = *reinterpret_cast<uint64_t*>(data);
	//	//	break;
	//DEBUG_ONLY(default: throw);
	//}

	//struct s_flags_dynamic_data
	//{
	//	s_flags_dynamic_data(c_cache_file& cache_file, uint64_t value, const blofeld::s_tag_field& field) :
	//		bools(),
	//		string_parser(*new c_blamlib_string_parser(field.name, false, nullptr))
	//	{
	//		represented_value = ~value; // force update
	//		update(value);

	//		const blofeld::s_string_list_definition& string_list_definition = *field.string_list_definition;
	//		e_engine_type const engine_type = cache_file.get_engine_type(); // #TODO: move this value into tag editor tab memory to avoid calling function
	//		e_platform_type const platform_type = cache_file.get_platform_type(); // #TODO: move this value into tag editor tab memory to avoid calling function
	//		uint32_t const string_list_count = string_list_definition.count(engine_type, platform_type); // #TODO: Is it a good idea to precache this value in the s_flags_dynamic_data?
	//		const char** const string_list_values = string_list_definition.strings(engine_type, platform_type); // #TODO: Is it a good idea to precache this value in the s_flags_dynamic_data?

	//		string_list_parsers.reserve(string_list_count);

	//		for (uint32_t string_index = 0; string_index < string_list_count; string_index++)
	//		{
	//			const char* const current_string_value = string_list_values[string_index];
	//			string_list_parsers.push_back(new c_blamlib_string_parser(current_string_value));
	//		}
	//	}

	//	~s_flags_dynamic_data()
	//	{
	//		delete& string_parser;
	//	}

	//	void update(uint64_t value)
	//	{
	//		if (represented_value != value)
	//		{
	//			for (uint64_t i = 0; i < 64; i++)
	//			{
	//				bools[i] = static_cast<bool>(value >> i & 1);
	//			}
	//			represented_value = value;
	//		}
	//	}

	//	bool bools[64];
	//	uint64_t represented_value;
	//	c_blamlib_string_parser& string_parser; // #TODO: remove
	//	std::vector<c_blamlib_string_parser*> string_list_parsers; // #TODO: remove
	//};
	//s_flags_dynamic_data& dynamic_data = get_dynamic_data<s_flags_dynamic_data, c_cache_file&>(data, cache_file, value, field);
	//dynamic_data.update(value);

	//ImGui::PushID(data);

	//bool bitfield_value_updated = false;

	//ImGui::Columns(2, NULL, false);
	//ImGui::SetColumnWidth(0, k_field_display_name_width);
	//ImGui::SetColumnWidth(1, 1150);
	//{
	//	ImGui::Text(dynamic_data.string_parser.display_name.c_str());
	//}
	//ImGui::NextColumn();
	//{
	//	e_engine_type const engine_type = cache_file.get_engine_type(); // #TODO: move this value into tag editor tab memory to avoid calling function
	//	e_platform_type const platform_type = cache_file.get_platform_type(); // #TODO: move this value into tag editor tab memory to avoid calling function
	//	uint32_t const string_list_count = string_list_definition.count(engine_type, platform_type); // #TODO: Is it a good idea to precache this value in the s_flags_dynamic_data?
	//	const char** const string_list_values = string_list_definition.strings(engine_type, platform_type); // #TODO: Is it a good idea to precache this value in the s_flags_dynamic_data?

	//	float const element_height = ImGui::GetTextLineHeight() * 1.45f;
	//	float const height = __min(element_height * 9.5f, element_height * static_cast<float>(string_list_count));

	//	if (ImGui::BeginChild("bitfield", ImVec2(800.0f, height)))
	//	{
	//		for (uint32_t string_index = 0; string_index < string_list_count; string_index++)
	//		{
	//			const char* const string_list_value = string_list_values[string_index];
	//			c_blamlib_string_parser& current_string_parser = *dynamic_data.string_list_parsers[string_index];
	//			bool const current_string_has_tooltip = !current_string_parser.description.is_empty();
	//			if (current_string_has_tooltip)
	//			{
	//				ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_INFO_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA));
	//			}
	//			bitfield_value_updated |= ImGui::Checkbox(current_string_parser.display_name.c_str(), dynamic_data.bools + string_index);
	//			if (current_string_has_tooltip)
	//			{
	//				ImGui::PopStyleColor();
	//				if (ImGui::IsItemHovered())
	//				{
	//					ImGui::SetTooltip(current_string_parser.description.c_str());
	//				}
	//			}
	//		}
	//		// #TODO: display out of bounds enum values
	//	}
	//	ImGui::EndChild();

	//}

	//if (bitfield_value_updated)
	//{
	//	uint64_t new_value = 0;
	//	for (uint64_t i = 0; i < 64; i++)
	//	{
	//		if (dynamic_data.bools[i])
	//		{
	//			new_value |= 1ull << i;
	//		}
	//	}
	//	dynamic_data.represented_value = new_value; // #NOTE: no need to update bools

	//	switch (field.field_type)
	//	{
	//	case blofeld::_field_byte_flags:
	//		*reinterpret_cast<uint8_t*>(data) = static_cast<uint8_t>(new_value);
	//		break;
	//	case blofeld::_field_word_flags:
	//		*reinterpret_cast<uint16_t*>(data) = static_cast<uint16_t>(new_value);
	//		break;
	//	case blofeld::_field_long_flags:
	//		*reinterpret_cast<uint32_t*>(data) = static_cast<uint32_t>(new_value);
	//		break;
	//		//case blofeld::_field_qword_flags:
	//		//	*reinterpret_cast<uint64_t*>(data) = static_cast<uint64_t>(new_value);
	//		//	break;
	//	DEBUG_ONLY(default: throw);
	//	}
	//}

	//if (!dynamic_data.string_parser.units.is_empty())
	//{
	//	ImGui::SameLine();
	//	ImGui::Text(dynamic_data.string_parser.units.c_str());

	//	//const char* type_name = blofeld::field_to_string(field.field_type);
	//	//ImGui::Text(type_name);
	//}

	//ImGui::Columns(1);

	//ImGui::PopID();
}

void c_high_level_tag_editor_tab::render_enum_definition(void* data, const blofeld::s_tag_field& field)
{
	//DEBUG_ASSERT(field.string_list_definition != nullptr);
	//if (field.string_list_definition == nullptr)
	//{
	//	ImGui::Text("Flag field fail. String list definition is null!");
	//	return;
	//}
	//const blofeld::s_string_list_definition& string_list_definition = *field.string_list_definition;

	//uint32_t value = 0;
	//switch (field.field_type)
	//{
	//case blofeld::_field_char_enum:
	//	value = *reinterpret_cast<uint8_t*>(data);
	//	break;
	//case blofeld::_field_enum:
	//	value = *reinterpret_cast<uint16_t*>(data);
	//	break;
	//case blofeld::_field_long_enum:
	//	value = *reinterpret_cast<uint32_t*>(data);
	//	break;
	//DEBUG_ONLY(default: throw);
	//}

	//struct s_enum_dynamic_data
	//{
	//	s_enum_dynamic_data(c_cache_file& cache_file, const blofeld::s_tag_field& field) :
	//		field_formatter(*new c_blamlib_string_parser(field.name, false, nullptr)),
	//		string_list_parsers()
	//	{
	//		const blofeld::s_string_list_definition& string_list_definition = *field.string_list_definition;
	//		e_engine_type const engine_type = cache_file.get_engine_type(); // #TODO: move this value into tag editor tab memory to avoid calling function
	//		e_platform_type const platform_type = cache_file.get_platform_type(); // #TODO: move this value into tag editor tab memory to avoid calling function
	//		uint32_t const string_list_count = string_list_definition.count(engine_type, platform_type); // #TODO: Is it a good idea to precache this value in the s_flags_dynamic_data?
	//		const char** const string_list_values = string_list_definition.strings(engine_type, platform_type); // #TODO: Is it a good idea to precache this value in the s_flags_dynamic_data?

	//		string_list_parsers.reserve(string_list_count);

	//		for (uint32_t string_index = 0; string_index < string_list_count; string_index++)
	//		{
	//			const char* const current_string_value = string_list_values[string_index];
	//			string_list_parsers.push_back(new c_blamlib_string_parser(current_string_value));
	//		}
	//	}

	//	~s_enum_dynamic_data()
	//	{
	//		delete& field_formatter;
	//	}

	//	
	//	c_blamlib_string_parser& field_formatter; // #TODO: remove
	//	std::vector<c_blamlib_string_parser*> string_list_parsers; // #TODO: remove
	//};
	//s_enum_dynamic_data& dynamic_data = get_dynamic_data<s_enum_dynamic_data, c_cache_file&>(data, cache_file, field);

	//ImGui::PushID(data);

	//bool enum_value_updated = false;

	//ImGui::Columns(2, NULL, false);
	//ImGui::SetColumnWidth(0, k_field_display_name_width);
	//ImGui::SetColumnWidth(1, 1000);
	//{
	//	ImGui::Text(dynamic_data.field_formatter.display_name.c_str());
	//}
	//ImGui::NextColumn();
	//{
	//	e_engine_type const engine_type = cache_file.get_engine_type(); // #TODO: move this value into tag editor tab memory to avoid calling function
	//	e_platform_type const platform_type = cache_file.get_platform_type(); // #TODO: move this value into tag editor tab memory to avoid calling function
	//	uint32_t const string_list_count = string_list_definition.count(engine_type, platform_type); // #TODO: Is it a good idea to precache this value in the s_flags_dynamic_data?
	//	const char** const string_list_values = string_list_definition.strings(engine_type, platform_type); // #TODO: Is it a good idea to precache this value in the s_flags_dynamic_data?


	//	if (dynamic_data.string_list_parsers.size() != 0)
	//	{
	//		ImGui::SetNextItemWidth(350);

	//		c_blamlib_string_parser& selected_string_parser = *dynamic_data.string_list_parsers[value];
	//		bool const selected_string_has_tooltip = !selected_string_parser.description.is_empty();
	//		if (selected_string_has_tooltip)
	//		{
	//			ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_INFO_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA));
	//		}
	//		const char* const selected_string_value = value < string_list_count ? selected_string_parser.display_name.c_str() : "<INVALID VALUE>";
	//		if (ImGui::BeginCombo("##enum", selected_string_value))
	//		{
	//			for (uint32_t string_index = 0; string_index < string_list_count; string_index++)
	//			{
	//				const char* const current_string_value = string_list_values[string_index];
	//				c_blamlib_string_parser& current_string_parser = *dynamic_data.string_list_parsers[string_index];
	//				bool const current_string_has_tooltip = !current_string_parser.description.is_empty();
	//				if (current_string_has_tooltip)
	//				{
	//					ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_INFO_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA));
	//				}
	//				if (ImGui::Selectable(current_string_parser.display_name.c_str()))
	//				{
	//					value = string_index;
	//					enum_value_updated = true;
	//				}
	//				if (current_string_has_tooltip)
	//				{
	//					ImGui::PopStyleColor();
	//					if (ImGui::IsItemHovered())
	//					{
	//						ImGui::SetTooltip(current_string_parser.description.c_str());
	//					}
	//				}
	//			}

	//			ImGui::EndCombo();
	//		}
	//		else if (selected_string_has_tooltip)
	//		{
	//			ImGui::PopStyleColor();
	//		}

	//	}
	//}

	//if (enum_value_updated)
	//{
	//	switch (field.field_type)
	//	{
	//	case blofeld::_field_char_enum:
	//		*reinterpret_cast<uint8_t*>(data) = static_cast<uint8_t>(value);
	//		break;
	//	case blofeld::_field_enum:
	//		*reinterpret_cast<uint16_t*>(data) = static_cast<uint16_t>(value);
	//		break;
	//	case blofeld::_field_long_enum:
	//		*reinterpret_cast<uint32_t*>(data) = static_cast<uint32_t>(value);
	//		break;
	//	DEBUG_ONLY(default: throw);
	//	}
	//}

	//if (!dynamic_data.field_formatter.units.is_empty())
	//{
	//	ImGui::SameLine();
	//	ImGui::Text(dynamic_data.field_formatter.units.c_str());

	//	//const char* type_name = blofeld::field_to_string(field.field_type);
	//	//ImGui::Text(type_name);
	//}

	//ImGui::Columns(1);

	//ImGui::PopID();
}

float constexpr pi = 3.14159265359f;
float constexpr degrees_to_radians = pi / 180.0f;
float constexpr radians_to_degrees = 180.0f / pi;

void c_high_level_tag_editor_tab::render_object(uint32_t level, h_object& object)
{
	using namespace blofeld;

	const blofeld::s_tag_struct_definition& struct_definition = object.get_blofeld_struct_definition();

	if (&struct_definition == &blofeld::object_struct_definition_struct_definition)
	{
		if (custom_tool == nullptr)
		{
			//custom_tool = new c_custom_tool_render_model(cache_file, reinterpret_cast<blofeld::haloreach::s_object_struct_definition*>(structure_data));
		}
		//custom_tool->render();
		ImGui::Text("CUSTOM TOOL!!!");
	}

	constexpr float indent = 25.0f;
	uint32_t field_index = 0;
	for (const blofeld::s_tag_field* current_field = struct_definition.fields; current_field->field_type != blofeld::_field_terminator; (current_field++, field_index++))
	{
		if (!object.is_field_active(*current_field))
		{
			continue;
		}

		void* field_data = object.get_field_pointer(*current_field);

		ImGui::PushID(field_index);

		switch (current_field->field_type)
		{

		case blofeld::_field_real:							render_primitive<_field_real>(field_data, *current_field); break;						
		case blofeld::_field_real_fraction:					render_primitive<_field_real_fraction>(field_data, *current_field); break;				
		case blofeld::_field_real_point_2d:					render_primitive<_field_real_point_2d>(field_data, *current_field); break;				
		case blofeld::_field_real_point_3d:					render_primitive<_field_real_point_3d>(field_data, *current_field); break;				
		case blofeld::_field_real_vector_2d:				render_primitive<_field_real_vector_2d>(field_data, *current_field); break;				
		case blofeld::_field_real_vector_3d:				render_primitive<_field_real_vector_3d>(field_data, *current_field); break;				
		case blofeld::_field_real_quaternion:				render_primitive<_field_real_quaternion>(field_data, *current_field); break;			
		case blofeld::_field_real_plane_2d:					render_primitive<_field_real_plane_2d>(field_data, *current_field); break;				
		case blofeld::_field_real_plane_3d:					render_primitive<_field_real_plane_3d>(field_data, *current_field); break;				
		case blofeld::_field_real_rgb_color:				render_primitive<_field_real_rgb_color>(field_data, *current_field); break;				
		case blofeld::_field_real_argb_color:				render_primitive<_field_real_argb_color>(field_data, *current_field); break;			
		case blofeld::_field_real_hsv_color:				render_primitive<_field_real_hsv_color>(field_data, *current_field); break;				
		case blofeld::_field_real_ahsv_color:				render_primitive<_field_real_ahsv_color>(field_data, *current_field); break;			
		case blofeld::_field_short_bounds:					render_primitive<_field_short_bounds>(field_data, *current_field); break;				
		case blofeld::_field_real_bounds:					render_primitive<_field_real_bounds>(field_data, *current_field); break;				
		case blofeld::_field_real_fraction_bounds:			render_primitive<_field_real_fraction_bounds>(field_data, *current_field); break;		
		case blofeld::_field_byte_block_flags:				render_primitive<_field_byte_block_flags>(field_data, *current_field); break;			
		case blofeld::_field_word_block_flags:				render_primitive<_field_word_block_flags>(field_data, *current_field); break;			
		case blofeld::_field_long_block_flags:				render_primitive<_field_long_block_flags>(field_data, *current_field); break;			
		case blofeld::_field_char_block_index:				render_primitive<_field_char_block_index>(field_data, *current_field); break;			
		case blofeld::_field_short_block_index:				render_primitive<_field_short_block_index>(field_data, *current_field); break;			
		case blofeld::_field_long_block_index:				render_primitive<_field_long_block_index>(field_data, *current_field); break;			
		case blofeld::_field_custom_char_block_index:		render_primitive<_field_custom_char_block_index>(field_data, *current_field); break;	
		case blofeld::_field_custom_short_block_index:		render_primitive<_field_custom_short_block_index>(field_data, *current_field); break;	
		case blofeld::_field_custom_long_block_index:		render_primitive<_field_custom_long_block_index>(field_data, *current_field); break;
		case blofeld::_field_angle:
		{
			float& src_radians = *static_cast<float*>(field_data);
			float degrees = src_radians * radians_to_degrees;
			if (render_primitive<_field_angle>(&degrees, *current_field))
			{
				src_radians = degrees * degrees_to_radians;
			}
			break;
		}
		case blofeld::_field_angle_bounds:
		{
			float* src_radians = static_cast<float*>(field_data);
			float degrees[2] = 
			{ 
				src_radians[0] * radians_to_degrees, 
				src_radians[1] * radians_to_degrees 
			};
			if (render_primitive<_field_angle_bounds>(&degrees, *current_field))
			{
				src_radians[0] = degrees[0] * degrees_to_radians;
				src_radians[1] = degrees[1] * degrees_to_radians;
			}
			break;
		}
		case _field_string:			render_primitive<_field_string>(field_data, *current_field); break;
		case _field_long_string:	render_primitive<_field_long_string>(field_data, *current_field); break;
		case _field_string_id:		render_primitive<_field_string_id>(field_data, *current_field); break;
		case _field_old_string_id:	render_primitive<_field_old_string_id>(field_data, *current_field); break;
		case _field_tag_reference:
		{
			h_tag*& tag_reference = *static_cast<h_tag**>(field_data);
			render_tag_reference(tag_reference, *current_field);
			break;
		}
		case _field_block:
		{
			h_block& block = *static_cast<h_block*>(field_data);
			render_tag_block(block, *current_field);
			break;
		}
		case _field_struct:
		{
			h_object& struct_object = *static_cast<h_object*>(field_data);
			render_object(level + 1, struct_object);
			break;
		}
		case blofeld::_field_explanation:
		{
			ImGui::BeginGroup();
			{
				ImGui::Dummy({ 0.0f, 10.0f });

				float padding_offset = ImGui::GetStyle().FramePadding.x; /* is there a better way to do this? */
				ImGui::Dummy({ padding_offset, 0.0f });
				ImGui::SameLine();

				static const ImVec4 explanation_color = MANDRILL_THEME_COMMENT_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA);
				const char* display_name = current_field->string_parser.display_name.c_str();
				ImGui::PushStyleColor(ImGuiCol_Text, explanation_color);
				if (*display_name)
				{
					ImVec2 header_start = ImGui::GetCursorPos();
					ImGui::TextUnformatted(display_name);
					ImVec2 header_end = ImGui::GetCursorPos();
					ImGui::SetCursorPos({ header_start.x + 1, header_start.y + 1 });
					ImGui::TextUnformatted(display_name);
					ImGui::SetCursorPos({ header_start.x + 1, header_start.y });
					ImGui::TextUnformatted(display_name);
					ImGui::SetCursorPos({ header_start.x, header_start.y + 1 });
					ImGui::TextUnformatted(display_name);
					ImGui::SetCursorPos(header_end);
				}
				if (current_field->explanation && *current_field->explanation)
				{
					ImGui::Dummy({ padding_offset, 0.0f });
					ImGui::SameLine();
					ImGui::TextUnformatted(current_field->explanation);
				}
				ImGui::PopStyleColor();
				ImGui::Dummy({ 5.0f, 5.0f });
			}
			ImGui::EndGroup();
			const char* description = current_field->string_parser.description.c_str();
			if (*description && ImGui::IsItemHovered())
			{
				ImGui::BeginTooltipEx(0, ImGuiTooltipFlags_OverridePreviousTooltip);
				ImGui::TextUnformatted(description);
				ImGui::EndTooltip();
			}
			break;
		}
		default:
			ImGui::Text("Unknown type for field '%s'", current_field->name);
			break;
		}

		ImGui::PopID();
//
//
//
//		char* current_data_position = structure_data + bytes_traversed;
//
//		uint32_t field_skip_count;
//		if (skip_tag_field_version(*current_field, engine_type, platform_type, _build_not_set, field_skip_count))
//		{
//			current_field += field_skip_count;
//			continue;
//		}
//		ImGui::PushID(field_index);
//
//		uint32_t field_size = blofeld::get_blofeld_field_size(platform_type, current_field->field_type);
//
//		const char* field_typename = field_to_string(current_field->field_type);
//		ASSERT(field_typename != nullptr);
//
//		switch (current_field->field_type)
//		{
//		case blofeld::_field_char_enum:
//		case blofeld::_field_enum:
//		case blofeld::_field_long_enum:
//			render_enum_definition(current_data_position, *current_field);
//			break;
//
//		case blofeld::_field_long_flags:
//		case blofeld::_field_word_flags:
//		case blofeld::_field_byte_flags:
//			render_flags_definition(current_data_position, *current_field);
//			break;
//
//		case blofeld::_field_string:
//		case blofeld::_field_long_string:
//			render_string(current_data_position, *current_field);
//			break;
//
//		case blofeld::_field_string_id:
//		case blofeld::_field_old_string_id:
//			render_string_id(current_data_position, *current_field);
//			break;
//
//		case blofeld::_field_char_integer:
//		case blofeld::_field_short_integer:
//		case blofeld::_field_long_integer:
//		case blofeld::_field_int64_integer:
//		case blofeld::_field_byte_integer:
//		case blofeld::_field_word_integer:
//		case blofeld::_field_dword_integer:
//		case blofeld::_field_qword_integer:
//
//		case blofeld::_field_point_2d:
//		case blofeld::_field_rectangle_2d:
//		case blofeld::_field_rgb_color:
//		case blofeld::_field_argb_color:
//
//		case blofeld::_field_real:
//		case blofeld::_field_real_fraction:
//		case blofeld::_field_real_point_2d:
//		case blofeld::_field_real_point_3d:
//		case blofeld::_field_real_vector_2d:
//		case blofeld::_field_real_vector_3d:
//		case blofeld::_field_real_quaternion:
//		case blofeld::_field_real_plane_2d:
//		case blofeld::_field_real_plane_3d:
//		case blofeld::_field_real_rgb_color:
//		case blofeld::_field_real_argb_color:
//		case blofeld::_field_real_hsv_color:
//		case blofeld::_field_real_ahsv_color:
//		case blofeld::_field_short_bounds:
//		case blofeld::_field_real_bounds:
//		case blofeld::_field_real_fraction_bounds:
//
//		case blofeld::_field_byte_block_flags:
//		case blofeld::_field_word_block_flags:
//		case blofeld::_field_long_block_flags:
//		case blofeld::_field_char_block_index:
//		case blofeld::_field_short_block_index:
//		case blofeld::_field_long_block_index:
//		case blofeld::_field_custom_char_block_index:
//		case blofeld::_field_custom_short_block_index:
//		case blofeld::_field_custom_long_block_index:
//		{
//			render_primitive(current_data_position, *current_field);
//			break;
//		}
//		case blofeld::_field_angle:
//		{
//			float& src_radians = *reinterpret_cast<float*>(current_data_position);
//			float degrees = src_radians * radians_to_degrees;
//			if (render_primitive(&degrees, *current_field))
//			{
//				src_radians = degrees * degrees_to_radians;
//			}
//			break;
//		}
//		case blofeld::_field_angle_bounds:
//		{
//			float* src_radians = reinterpret_cast<float*>(current_data_position);
//			float degrees[2] = { src_radians[0] * radians_to_degrees, src_radians[1] * radians_to_degrees };
//			if (render_primitive(&degrees, *current_field))
//			{
//				src_radians[0] = degrees[0] * degrees_to_radians;
//				src_radians[1] = degrees[1] * degrees_to_radians;
//			}
//			break;
//		}
//		case blofeld::_field_real_euler_angles_2d:
//		{
//			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
//			break;
//		}
//		case blofeld::_field_real_euler_angles_3d:
//		{
//			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
//			break;
//		}
//		case blofeld::_field_tag:
//		{
//			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
//			break;
//		}
//		case blofeld::_field_tag_reference:
//		{
//			render_tag_reference(current_data_position, *current_field);
//			break;
//		}
//		case blofeld::_field_block:
//		{
//			render_tag_block(current_data_position, *current_field);
//			break;
//		}
//		case blofeld::_field_data:
//		{
//			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
//			break;
//		}
//		case blofeld::_field_vertex_buffer:
//		{
//			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
//			break;
//		}
//		case blofeld::_field_pad:
//		{
//			field_size = current_field->padding;
//			break;
//		}
//		case blofeld::_field_useless_pad:
//		{
//			//field_size = current_field->padding;
//			break;
//		}
//		case blofeld::_field_skip:
//		{
//			field_size = current_field->length;
//			break;
//		}
//		case blofeld::_field_non_cache_runtime_value:
//		{
//			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
//			break;
//		}
//		case blofeld::_field_explanation:
//		{
//			c_blamlib_string_parser string_parser = { current_field->name };
//			ImGui::BeginGroup();
//			{
//				ImGui::Dummy({ 0.0f, 10.0f });
//
//				float padding_offset = ImGui::GetStyle().FramePadding.x; /* is there a better way to do this? */
//				ImGui::Dummy({ padding_offset, 0.0f });
//				ImGui::SameLine();
//
//				static const ImVec4 explanation_color = MANDRILL_THEME_COMMENT_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA);
//				if (!string_parser.display_name.is_empty())
//				{
//					ImVec2 header_start = ImGui::GetCursorPos();
//					ImGui::TextColored(explanation_color, string_parser.display_name.c_str());
//					ImVec2 header_end = ImGui::GetCursorPos();
//					ImGui::SetCursorPos({ header_start.x + 1, header_start.y + 1 });
//					ImGui::TextColored(explanation_color, string_parser.display_name.c_str());
//					ImGui::SetCursorPos({ header_start.x + 1, header_start.y });
//					ImGui::TextColored(explanation_color, string_parser.display_name.c_str());
//					ImGui::SetCursorPos({ header_start.x, header_start.y + 1 });
//					ImGui::TextColored(explanation_color, string_parser.display_name.c_str());
//					ImGui::SetCursorPos(header_end);
//				}
//				if (current_field->explanation && *current_field->explanation)
//				{
//					ImGui::Dummy({ padding_offset, 0.0f });
//					ImGui::SameLine();
//					ImGui::TextColored(explanation_color, current_field->explanation);
//				}
//				ImGui::Dummy({ 5.0f, 5.0f });
//			}
//			ImGui::EndGroup();
//			if (!string_parser.description.is_empty() && ImGui::IsItemHovered())
//			{
//				ImGui::SetTooltip(string_parser.description.c_str());
//			}
//
//			break;
//		}
//		case blofeld::_field_custom:
//		{
//			// #TODO: render custom fields
//			break;
//		}
//		case blofeld::_field_struct:
//		{
//			uint32_t traversed_size = render_tag_structure(level++, current_data_position, *current_field->struct_definition);
//#ifdef _DEBUG
//			uint32_t structure_size = blofeld::calculate_struct_size(engine_type, platform_type, _build_not_set, *current_field->struct_definition);
//			DEBUG_ASSERT(traversed_size == structure_size);
//#endif
//			field_size = traversed_size;
//			break;
//		}
//		case blofeld::_field_array:
//		{
//			uint32_t array_count = current_field->array_definition->count(engine_type);
//
//			bool use_array_navigation = true;
//			if (use_array_navigation)
//			{
//				struct s_tag_block_dynamic_data
//				{
//					uint32_t position = 0;
//					uint32_t structure_size = 0;
//				};
//				s_tag_block_dynamic_data& dynamic_data = get_dynamic_data<s_tag_block_dynamic_data>(current_data_position);
//
//				if (dynamic_data.structure_size == 0) // #TODO: precompute and find a home for this
//				{
//					dynamic_data.structure_size = blofeld::calculate_struct_size(engine_type, platform_type, _build_not_set, current_field->array_definition->struct_definition);
//				}
//
//				if (dynamic_data.position)
//				{
//					if (dynamic_data.position == ~uint32_t())
//					{
//						dynamic_data.position = array_count - 1;
//					}
//					else if (dynamic_data.position >= static_cast<int64_t>(array_count))
//					{
//						dynamic_data.position = 0;
//					}
//				}
//
//				char* array_data_position = current_data_position + dynamic_data.structure_size * dynamic_data.position;
//
//				for (uint32_t i = 0; i < array_count; i++)
//				{
//					uint32_t traversed_size = render_tag_structure(level++, array_data_position, current_field->array_definition->struct_definition);
//					DEBUG_ASSERT(traversed_size == dynamic_data.structure_size);
//					array_data_position += traversed_size;
//				}
//
//				current_data_position += dynamic_data.structure_size * array_count;
//				bytes_traversed += dynamic_data.structure_size * array_count;
//			}
//			else
//			{
//				for (uint32_t array_index = 0; array_index < array_count; array_index++)
//				{
//					uint32_t traversed_size = render_tag_structure(level++, current_data_position, current_field->array_definition->struct_definition);
//					current_data_position += traversed_size;
//					bytes_traversed += traversed_size;
//				}
//			}
//			break;
//		}
//		case blofeld::_field_pageable:
//		{
//			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
//			break;
//		}
//		case blofeld::_field_api_interop:
//		{
//			ImGui::Text("0x%X 0x%X %s %s", bytes_traversed, field_size, field_typename, current_field->name ? current_field->name : "");
//			s_tag_interop& tag_interop = *reinterpret_cast<s_tag_interop*>(current_data_position);
//
//			if (current_field->struct_definition == nullptr)
//			{
//				ImGui::Text("ERROR API INTEROP STRUCT UNDEFINED");
//			}
//			else if (c_gen3_cache_file* gen3_cache_file = dynamic_cast<c_gen3_cache_file*>(&cache_file))
//			{
//				char* interop_data = gen3_cache_file->get_tag_interop_data(tag_interop);
//				if (interop_data)
//				{
//					render_tag_structure(level + 1, interop_data, *current_field->struct_definition);
//				}
//				else
//				{
//					ImGui::Text("API INTEROP NULL");
//				}
//			}
//			else
//			{
//				ImGui::Text("API Interop Unsupported");
//			}
//
//			break;
//		}
//		}
//
//		ImGui::PopID();
//
//		bytes_traversed += field_size;
	}
}

void c_high_level_tag_editor_tab::render_tag_group()
{
	render_object(0, tag);
}
