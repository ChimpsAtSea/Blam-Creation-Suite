#include "mandrilllib-private-pch.h"

using namespace blofeld;

float constexpr pi = 3.14159265359f;
float constexpr degrees_to_radians = pi / 180.0f;
float constexpr radians_to_degrees = 180.0f / pi;

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

template<e_field field_type>
bool c_high_level_tag_editor_tab::render_primitive(void* data, const s_tag_field& field)
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
		else if constexpr (field_type == _field_real || field_type == _field_real_fraction || field_type == _field_half)
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
		else if constexpr (field_type == _field_real_vector_2d || field_type == _field_real_bounds || field_type == _field_real_fraction_bounds || field_type == _field_real_point_2d)
		{
			ImGui::SetNextItemWidth(400.0f);
			result = ImGui::InputScalarN(field.string_parser.units.c_str(), ImGuiDataType_Float, data, 2);
		}
		else if constexpr (field_type == _field_real_point_3d || field_type == _field_real_rgb_color || field_type == _field_real_hsv_color || field_type == _field_real_plane_2d || field_type == _field_real_vector_3d)
		{
			ImGui::SetNextItemWidth(600.0f);
			result = ImGui::InputScalarN(field.string_parser.units.c_str(), ImGuiDataType_Float, data, 3);
		}
		else if constexpr (field_type == _field_real_argb_color || field_type == _field_real_ahsv_color || field_type == _field_real_plane_3d || field_type == _field_real_quaternion)
		{
			ImGui::SetNextItemWidth(800.0f);
			result = ImGui::InputScalarN(field.string_parser.units.c_str(), ImGuiDataType_Float, data, 4);
		}
		else if constexpr (field_type == _field_pointer)
		{
			ImGui::SetNextItemWidth(350.0f);
#ifdef _WIN64
			result = ImGui::InputScalar(field.string_parser.units.c_str(), ImGuiDataType_U64, data);
#else
			result = ImGui::InputScalar(field.string_parser.units.c_str(), ImGuiDataType_U32, data);
#endif
		}
		else if constexpr (field_type == _field_angle)
		{
			ImGui::SetNextItemWidth(350.0f);
			float& radians = *static_cast<float*>(data);
			float degrees = radians * radians_to_degrees;
			if (result = ImGui::InputScalar(field.string_parser.units.c_str(), ImGuiDataType_Float, &degrees))
			{
				radians = degrees * degrees_to_radians;
			}
		}
		else if constexpr (field_type == _field_angle_bounds)
		{
			ImGui::SetNextItemWidth(400.0f);
			float(&radians)[2] = *static_cast<float(*)[2]>(data);
			float degrees[2] = { radians[0] * radians_to_degrees, radians[1] * radians_to_degrees };
			if (result = ImGui::InputScalarN(field.string_parser.units.c_str(), ImGuiDataType_Float, &degrees, 2))
			{
				radians[0] = degrees[0] * degrees_to_radians;
				radians[1] = degrees[1] * degrees_to_radians;
			}
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
		else if constexpr (field_type == _field_real_euler_angles_2d)
		{
			ImGui::SetNextItemWidth(400.0f);
			float(&radians)[2] = *static_cast<float(*)[2]>(data);
			float degrees[2] = { radians[0] * radians_to_degrees, radians[1] * radians_to_degrees };
			if (result = ImGui::InputScalarN(field.string_parser.units.c_str(), ImGuiDataType_Float, &degrees, 2))
			{
				radians[0] = degrees[0] * degrees_to_radians;
				radians[1] = degrees[1] * degrees_to_radians;
			}
		}
		else if constexpr (field_type == _field_real_euler_angles_3d)
		{
			ImGui::SetNextItemWidth(600.0f);
			float(&radians)[3] = *static_cast<float(*)[3]>(data);
			float degrees[3] = { radians[0] * radians_to_degrees, radians[1] * radians_to_degrees, radians[2] * radians_to_degrees };
			if (result = ImGui::InputScalarN(field.string_parser.units.c_str(), ImGuiDataType_Float, &degrees, 3))
			{
				radians[0] = degrees[0] * degrees_to_radians;
				radians[1] = degrees[1] * degrees_to_radians;
				radians[2] = degrees[2] * degrees_to_radians;
			}
		}
	}
	ImGui::Columns(1);

	return result;
}

// If 'p_open' is specified for a modal popup window, the popup will have a regular close button which will close the popup.
// Note that popup visibility status is owned by Dear ImGui (and manipulated with e.g. OpenPopup) so the actual value of *p_open is meaningless here.
bool BeginPopupModalEx(ImGuiID id, const char* name, bool* p_open, ImGuiWindowFlags flags)
{
	ImGuiContext& g = *GImGui;
	ImGuiWindow* window = g.CurrentWindow;
	if (!ImGui::IsPopupOpen(id))
	{
		g.NextWindowData.ClearFlags(); // We behave like Begin() and need to consume those values
		return false;
	}

	// Center modal windows by default
	// FIXME: Should test for (PosCond & window->SetWindowPosAllowFlags) with the upcoming window.
	if ((g.NextWindowData.Flags & ImGuiNextWindowDataFlags_HasPos) == 0)
		ImGui::SetNextWindowPos({ g.IO.DisplaySize.x * 0.5f , g.IO.DisplaySize.y * 0.5f }, ImGuiCond_Appearing, ImVec2(0.5f, 0.5f));

	flags |= ImGuiWindowFlags_Popup | ImGuiWindowFlags_Modal | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoSavedSettings;
	const bool is_open = ImGui::Begin(name, p_open, flags);
	if (!is_open || (p_open && !*p_open)) // NB: is_open can be 'false' when the popup is completely clipped (e.g. zero size display)
	{
		ImGui::EndPopup();
		if (is_open)
			ImGui::ClosePopupToLevel(g.BeginPopupStack.Size, true);
		return false;
	}
	return is_open;
}

void c_high_level_tag_editor_tab::render_enumerable(h_enumerable& enumerable, const s_tag_field& field)
{
	constexpr float k_min_block_width = 1000.0f;
	constexpr float k_block_header_height = 80.0f;

	uint32_t const count = enumerable.size();

	ImGui::PushID(&field);
	ImGuiID const is_open_id = ImGui::GetID("is_open");
	ImGuiID const is_inserting_id = ImGui::GetID("is_inserting");
	ImGuiID const inserting_popup_id = ImGui::GetID("is_inserting");
	ImGuiID const index_id = ImGui::GetID("index");
	ImGuiID const content_width_id = ImGui::GetID("content_width");
	ImGuiID const collapsing_header_id = ImGui::GetID("collapsing_header");
	ImGuiID const inserting_offset_id = ImGui::GetID("inserting_offset");
	ImGuiID const inserting_count_id = ImGui::GetID("inserting_count");

	ImGuiStorage* storage = ImGui::GetStateStorage();
	bool is_open = static_cast<bool>(storage->GetInt(is_open_id, 1));
	bool is_inserting = static_cast<bool>(storage->GetInt(is_inserting_id));
	float content_width = storage->GetFloat(content_width_id, k_min_block_width);
	int32_t index = storage->GetInt(index_id);
	bool is_disabled = count == 0;

#define clamp_rollover(value, max) \
	if (max == 0) value = 0; \
	else if (value < 0) value = static_cast<int32_t>(max - 1); \
	else if (value >= static_cast<int32_t>(max)) value = value % static_cast<int32_t>(max);

	ImVec2 collapsing_header_pos = ImGui::GetCursorPos();

	h_block* block = dynamic_cast<h_block*>(&enumerable);

	ImGui::Dummy({ 0.0f, k_block_header_height });

	clamp_rollover(index, count);

	if (is_open)
	{
		if (count > 0)
		{
			ImGui::BeginGroup();
			ImGui::Dummy({ 8.0f, 8.0f });
			ImGui::SameLine();
			ImGui::BeginGroup();

			h_object& object = enumerable.get(index);
			render_object(0, object);

			ImGui::EndGroup();
			ImGui::Dummy({ 8.0f, 8.0f });
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
			if (count == 0)
			{
				ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
				ImGui::PushStyleColor(ImGuiCol_Header, MANDRILL_THEME_DISABLED_MED(0.76f));
				ImGui::PushStyleColor(ImGuiCol_HeaderHovered, MANDRILL_THEME_DISABLED_MED(0.86f));
				ImGui::PushStyleColor(ImGuiCol_HeaderActive, MANDRILL_THEME_DISABLED_HIGH(1.00f));
			}
			c_fixed_string_128 header_str;
			header_str.format("%s : count:%u", field.string_parser.display_name.c_str(), count);

			ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_CollapsingHeader | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_AllowItemOverlap;
			if (is_open)
			{
				flags |= ImGuiTreeNodeFlags_DefaultOpen;
			}
			is_open = ImGui::TreeNodeBehavior(collapsing_header_id, flags, header_str.c_str());
			if (count == 0)
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
			if (count > 0)
			{
				// #TODO: advanced block index formatting
				c_fixed_string_128 index_str = "None";
				index_str.format("index: %u", index);
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

		if (is_disabled)
		{
			ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
		}

		ImGui::SameLine();
		if (ImGui::ButtonEx(ICON_FA_PLUS, {}, ImGuiButtonFlags_PressedOnClick | ImGuiButtonFlags_Repeat))
		{
			int index_amount = 1;
			{
				ImGuiIO& IO = ImGui::GetIO();
				const float t = IO.MouseDownDuration[ImGuiMouseButton_Left];
				if (t > 0.0f)
				{
					index_amount = ImGui::CalcTypematicRepeatAmount(t - IO.DeltaTime, t, IO.KeyRepeatDelay, IO.KeyRepeatRate * 0.50f);
					index_amount *= static_cast<int>(1.0f + t);
				}
			}

			index += index_amount;
			clamp_rollover(index, count);
		}
		ImGui::SameLine();
		if (ImGui::ButtonEx(ICON_FA_MINUS, {}, ImGuiButtonFlags_PressedOnClick | ImGuiButtonFlags_Repeat))
		{
			int index_amount = 1;
			{
				ImGuiIO& IO = ImGui::GetIO();
				const float t = IO.MouseDownDuration[ImGuiMouseButton_Left];
				if (t > 0.0f)
				{
					index_amount = ImGui::CalcTypematicRepeatAmount(t - IO.DeltaTime, t, IO.KeyRepeatDelay, IO.KeyRepeatRate * 0.50f);
					index_amount *= static_cast<int>(1.0f + t);
				}
			}

			index -= index_amount;
			clamp_rollover(index, count);
		}

		if (is_disabled)
		{
			ImGui::PopItemFlag();
		}



		ImGui::SameLine();
		ImGui::Dummy({ 25.0f, 0.0f });

		if (block)
		{
			ImGui::SameLine();
			if (ImGui::Button("Add"))
			{
				block->emplace_back();
				index = enumerable.size() - 1;
			}

			ImGui::SameLine();
			if (ImGui::Button("Insert"))
			{
				ImGui::OpenPopupEx(inserting_popup_id);

				storage->SetInt(inserting_offset_id, static_cast<int>(index));
				storage->SetInt(inserting_count_id, static_cast<int>(1));

				is_inserting = true;
			}

			if (is_disabled)
			{
				ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
			}

			ImGui::SameLine();
			if (ImGui::Button("Duplicate"))
			{
				h_object& object = block->get(index);
				block->emplace_back(object);
				index = enumerable.size() - 1;
			}

			ImGui::SameLine();
			ImGui::Dummy({ 25.0f, 0.0f });

			ImGui::SameLine();
			if (ImGui::Button("Delete"))
			{
				block->remove(index);
				index--;
			}

			ImGui::SameLine();
			if (ImGui::Button("Delete All"))
			{
				block->clear();
				index = 0;
			}

			if (is_disabled)
			{
				ImGui::PopItemFlag();
			}
		}
	}
	ImGui::EndChild();

	ImGui::SetCursorPos(block_finish_pos);

	if (block != nullptr && is_inserting)
	{
		int32_t insert_offset = static_cast<uint32_t>(storage->GetInt(inserting_offset_id));
		uint32_t insert_count = static_cast<uint32_t>(storage->GetInt(inserting_count_id));

		ImGuiIO& io = ImGui::GetIO();
		ImGui::SetNextWindowPos({ io.DisplaySize.x * 0.5f, io.DisplaySize.y * 0.5f }, ImGuiCond_Always, ImVec2(0.5f, 0.5f));
		ImGui::SetNextWindowContentSize({ 800, 600 });
		if (BeginPopupModalEx(is_inserting_id, "Insert", NULL, ImGuiWindowFlags_AlwaysAutoResize))
		{
			if (ImGui::InputScalar("Offset", ImGuiDataType_U32, &insert_offset))
			{
				clamp_rollover(insert_offset, count);
			}
			ImGui::SameLine();
			if (ImGui::ButtonEx(ICON_FA_PLUS, {}, ImGuiButtonFlags_PressedOnClick | ImGuiButtonFlags_Repeat))
			{
				int index_amount = 1;
				{
					ImGuiIO& IO = ImGui::GetIO();
					const float t = IO.MouseDownDuration[ImGuiMouseButton_Left];
					if (t > 0.0f)
					{
						index_amount = ImGui::CalcTypematicRepeatAmount(t - IO.DeltaTime, t, IO.KeyRepeatDelay, IO.KeyRepeatRate * 0.50f);
						index_amount *= static_cast<int>(1.0f + t);
					}
				}

				insert_offset += index_amount;
				clamp_rollover(insert_offset, count);
			}
			ImGui::SameLine();
			if (ImGui::ButtonEx(ICON_FA_MINUS, {}, ImGuiButtonFlags_PressedOnClick | ImGuiButtonFlags_Repeat))
			{
				int index_amount = 1;
				{
					ImGuiIO& IO = ImGui::GetIO();
					const float t = IO.MouseDownDuration[ImGuiMouseButton_Left];
					if (t > 0.0f)
					{
						index_amount = ImGui::CalcTypematicRepeatAmount(t - IO.DeltaTime, t, IO.KeyRepeatDelay, IO.KeyRepeatRate * 0.50f);
						index_amount *= static_cast<int>(1.0f + t);
					}
				}

				insert_offset -= index_amount;
				clamp_rollover(insert_offset, count);
			}

			if (ImGui::InputScalar("Count", ImGuiDataType_U32, &insert_count))
			{

			}
			ImGui::SameLine();
			if (ImGui::ButtonEx(ICON_FA_PLUS, {}, ImGuiButtonFlags_PressedOnClick | ImGuiButtonFlags_Repeat))
			{
				int index_amount = 1;
				{
					ImGuiIO& IO = ImGui::GetIO();
					const float t = IO.MouseDownDuration[ImGuiMouseButton_Left];
					if (t > 0.0f)
					{
						index_amount = ImGui::CalcTypematicRepeatAmount(t - IO.DeltaTime, t, IO.KeyRepeatDelay, IO.KeyRepeatRate * 0.50f);
						index_amount *= static_cast<int>(1.0f + t);
					}
				}

				insert_count += index_amount;
			}
			ImGui::SameLine();
			if (ImGui::ButtonEx(ICON_FA_MINUS, {}, ImGuiButtonFlags_PressedOnClick | ImGuiButtonFlags_Repeat))
			{
				int index_amount = 1;
				{
					ImGuiIO& IO = ImGui::GetIO();
					const float t = IO.MouseDownDuration[ImGuiMouseButton_Left];
					if (t > 0.0f)
					{
						index_amount = ImGui::CalcTypematicRepeatAmount(t - IO.DeltaTime, t, IO.KeyRepeatDelay, IO.KeyRepeatRate * 0.50f);
						index_amount *= static_cast<int>(1.0f + t);
					}
				}

				insert_count -= index_amount;
			}

			if (ImGui::Selectable("Insert"))
			{
				block->insert_hole(static_cast<uint32_t>(insert_offset), insert_count);
				index = insert_offset;
				is_inserting = false;
			}
			if (ImGui::Selectable("Cancel"))
			{
				is_inserting = false;
			}

			ImGui::EndPopup();
		}

		storage->SetInt(inserting_offset_id, insert_offset);
		storage->SetInt(inserting_count_id, insert_count);
	}

	storage->SetInt(is_open_id, static_cast<int>(is_open));
	storage->SetInt(is_inserting_id, static_cast<int>(is_inserting));
	storage->SetFloat(content_width_id, content_width);
	storage->SetInt(index_id, static_cast<int>(index));

	ImGui::PopID();
}

bool c_high_level_tag_editor_tab::render_tag_reference(h_tag*& tag_reference, const s_tag_field& field)
{
	bool result = false;

	ImGui::PushID(&field);
	ImGuiID const tag_group_id = ImGui::GetID("tag_group");

	ImGuiStorage* storage = ImGui::GetStateStorage();
	::tag group_tag = storage->GetInt(tag_group_id, blofeld::INVALID_TAG);

	h_group* group = nullptr;
	if (tag_reference != nullptr)
	{
		group = tag_reference->group;
		group_tag = group->tag_group.group_tag;
	}
	else
	{
		group = tag_project.get_group_by_group_tag(group_tag);
	}

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
		ImGui::SetNextItemWidth(350);

		const char* group_name = "(null)";
		if (group != nullptr)
		{
			group_name = group->tag_group.name;
		}
		bool combo_active = ImGui::BeginCombo("##tag_tag_group", group_name);
		if (combo_active)
		{
			if (ImGui::Selectable("(null)", group == nullptr))
			{
				if (tag_reference != nullptr)
				{
					tag_reference = nullptr;
					result = true;
				}
				group = nullptr;
			}

			for (h_group* current_group : tag_project.groups)
			{
				bool is_selected = group == current_group;
				if (ImGui::Selectable(current_group->tag_group.name, is_selected))
				{
					if (!is_selected)
					{
						if (tag_reference != nullptr)
						{
							tag_reference = nullptr; // #TODO: determine inheritance
							result = true;
						}
						group = current_group;
					}
				}
			}

			ImGui::EndCombo();
		}
	}
	ImGui::SameLine();
	{
		ImGui::SetNextItemWidth(700);

		const char* tag_instance_name = "";
		if (tag_reference != nullptr)
		{
			tag_instance_name = tag_reference->tag_filepath.c_str();
		}

		bool combo_active = ImGui::BeginCombo("##tag_path", tag_instance_name);
		if (*tag_instance_name && ImGui::IsItemHovered())
		{
			ImGui::SetTooltip(tag_instance_name);
		}
		if (combo_active)
		{
			std::vector<h_tag*>& tags = (group == nullptr) ? tag_project.tags : group->tags;

			for (h_tag* tag : tags)
			{
				bool is_selected = tag_reference == tag;
				const char* current_name = tag->tag_filepath.c_str();
				if (ImGui::Selectable(current_name, is_selected) && !is_selected)
				{
					if (tag_reference != tag)
					{
						tag_reference = tag;
						result = true;
					}
					group = tag->group;
				}
			}

			ImGui::EndCombo();
		}
	}
	ImGui::SameLine();
	{
		bool reference_is_null = tag_reference == nullptr;
		if (reference_is_null)
		{
			ImGui::PushItemFlag(ImGuiItemFlags_Disabled, true);
		}

		if (ImGui::Button("Open"))
		{
			if (!reference_is_null)
			{
				if (c_tag_project_tab* tag_project_tab = search_parent_tab_type<c_tag_project_tab>())
				{
					tag_project_tab->open_tag_interface_tab(*tag_reference);
				}
			}
		}
		else if (ImGui::IsItemHovered())
		{
			ImGui::SetTooltip("Opens this tag in a new tab");
		}

		//ImGui::SameLine();
		//ImGui::Button("Import");

		ImGui::SameLine();
		ImGui::Dummy({ 20.0f, 0.0f });

		ImGui::SameLine();
		if (ImGui::Button("Clear"))
		{
			if (tag_reference != nullptr)
			{
				tag_reference = nullptr;
				result = true;
			}
			group = nullptr;
		}
		else if (ImGui::IsItemHovered())
		{
			ImGui::SetTooltip("Nulls this tag reference");
		}

		if (reference_is_null)
		{
			ImGui::PopItemFlag();
		}
	}
	ImGui::Columns(1);

	group_tag = blofeld::INVALID_TAG;
	if (group != nullptr)
	{
		group_tag = group->tag_group.group_tag;
	}
	storage->SetInt(tag_group_id, static_cast<int>(group_tag));

	ImGui::PopID();

	return result;
}

void c_high_level_tag_editor_tab::render_data(h_data& data, const blofeld::s_tag_field& field)
{
	ImGui::PushID(&field);
	{
		ImGui::Columns(2, NULL, false);
		ImGui::SetColumnWidth(0, 400);
		ImGui::SetColumnWidth(1, 900);
		{
			ImGui::TextUnformatted(field.string_parser.display_name.c_str());
		}
		ImGui::NextColumn();
		{
			MemoryEditor memory_editor;

			ImGui::Dummy(ImVec2(0.0f, 3.0f));
			if (ImGui::BeginChild("##data", { 0.0f, ImGui::GetTextLineHeight() * 9.5f }, false))
			{
				memory_editor.DrawContents(data.data(), data.size());
			}
			ImGui::EndChild();
			ImGui::Dummy(ImVec2(0.0f, 3.0f));
		}
		ImGui::Columns(1);
	}

	ImGui::PopID();
}

bool c_high_level_tag_editor_tab::render_flags_definition(void* data, const s_tag_field& field)
{
	bool result = false;

	DEBUG_ASSERT(field.string_list_definition != nullptr);
	if (field.string_list_definition == nullptr)
	{
		ImGui::Text("Flag field fail. String list definition is null!");
		return false;
	}
	const s_string_list_definition& string_list_definition = *field.string_list_definition;

	uint32_t value = 0;
	switch (field.field_type)
	{
	case _field_byte_flags:
		value = *reinterpret_cast<uint8_t*>(data);
		break;
	case _field_word_flags:
		value = *reinterpret_cast<uint16_t*>(data);
		break;
	case _field_long_flags:
		value = *reinterpret_cast<uint32_t*>(data);
		break;
	DEBUG_ONLY(default: throw);
	}

	ImGui::PushID(data);

	ImGui::Columns(2, NULL, false);
	ImGui::SetColumnWidth(0, k_field_display_name_width);
	ImGui::SetColumnWidth(1, 1150);
	{
		ImGui::Text(field.string_parser.display_name.c_str());
	}
	ImGui::NextColumn();
	{
		uint32_t const string_list_count = string_list_definition.count(tag_project.engine_type, tag_project.platform_type);
		const c_blamlib_string_parser** const string_list_values = string_list_definition.strings(tag_project.engine_type, tag_project.platform_type);

		float const element_height = ImGui::GetTextLineHeight() * 1.45f;
		float const height = __min(element_height * 9.5f, element_height * static_cast<float>(string_list_count));

		if (ImGui::BeginChild("bitfield", ImVec2(800.0f, height)))
		{
			for (uint32_t string_index = 0; string_index < string_list_count; string_index++)
			{
				const c_blamlib_string_parser& current_string_parser = *string_list_values[string_index];
				bool const current_string_has_tooltip = !current_string_parser.description.is_empty();
				if (current_string_has_tooltip)
				{
					ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_INFO_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA));
				}
				uint32_t mask = 1u << string_index;
				bool is_flag_set = (value & mask) != 0;
				if (ImGui::Checkbox(current_string_parser.display_name.c_str(), &is_flag_set))
				{
					value &= ~mask;
					if (is_flag_set)
					{
						value |= mask;
					}

					switch (field.field_type)
					{
					case blofeld::_field_byte_flags:
						*reinterpret_cast<uint8_t*>(data) = static_cast<uint8_t>(value);
						break;
					case blofeld::_field_word_flags:
						*reinterpret_cast<uint16_t*>(data) = static_cast<uint16_t>(value);
						break;
					case blofeld::_field_long_flags:
						*reinterpret_cast<uint32_t*>(data) = static_cast<uint32_t>(value);
						break;
					DEBUG_ONLY(default: throw);
					}

					result = true;
				}

				if (current_string_has_tooltip)
				{
					ImGui::PopStyleColor();
					if (ImGui::IsItemHovered())
					{
						ImGui::SetTooltip(current_string_parser.description.c_str());
					}
				}
			}
			// #TODO: display out of bounds enum values
		}
		ImGui::EndChild();
	}

	ImGui::Columns(1);

	ImGui::PopID();

	return result;
}

bool c_high_level_tag_editor_tab::render_enum_definition(void* data, const s_tag_field& field)
{
	bool result = false;

	DEBUG_ASSERT(field.string_list_definition != nullptr);
	if (field.string_list_definition == nullptr)
	{
		ImGui::Text("Flag field fail. String list definition is null!");
		return false;
	}
	const s_string_list_definition& string_list_definition = *field.string_list_definition;

	uint32_t value = 0;
	switch (field.field_type)
	{
	case _field_char_enum:
		value = *reinterpret_cast<uint8_t*>(data);
		break;
	case _field_enum:
		value = *reinterpret_cast<uint16_t*>(data);
		break;
	case _field_long_enum:
		value = *reinterpret_cast<uint32_t*>(data);
		break;
	DEBUG_ONLY(default: throw);
	}

	ImGui::PushID(data);

	ImGui::Columns(2, NULL, false);
	ImGui::SetColumnWidth(0, k_field_display_name_width);
	ImGui::SetColumnWidth(1, 1150);
	{
		ImGui::Text(field.string_parser.display_name.c_str());
	}
	ImGui::NextColumn();
	{
		uint32_t const string_list_count = string_list_definition.count(tag_project.engine_type, tag_project.platform_type);
		const c_blamlib_string_parser** const string_list_values = string_list_definition.strings(tag_project.engine_type, tag_project.platform_type);

		const char* selected_string_value = "<INVALID VALUE>";
		bool current_string_has_tooltip = false;

		if (const c_blamlib_string_parser* selected_string_parser = string_list_values[value])
		{
			if (current_string_has_tooltip = !selected_string_parser->description.is_empty())
			{
				ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_INFO_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA));
			}

			selected_string_value = selected_string_parser->display_name.c_str();
		}

		if (ImGui::BeginCombo("##enum", selected_string_value))
		{
			for (uint32_t string_index = 0; string_index < string_list_count; string_index++)
			{
				const c_blamlib_string_parser& current_string_parser = *string_list_values[string_index];
				bool const current_string_has_tooltip = !current_string_parser.description.is_empty();
				if (current_string_has_tooltip)
				{
					ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_INFO_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA));
				}
				if (ImGui::Selectable(current_string_parser.display_name.c_str()))
				{
					value = string_index;

					switch (field.field_type)
					{
					case blofeld::_field_byte_flags:
						*reinterpret_cast<uint8_t*>(data) = static_cast<uint8_t>(value);
						break;
					case blofeld::_field_word_flags:
						*reinterpret_cast<uint16_t*>(data) = static_cast<uint16_t>(value);
						break;
					case blofeld::_field_long_flags:
						*reinterpret_cast<uint32_t*>(data) = static_cast<uint32_t>(value);
						break;
					DEBUG_ONLY(default: throw);
					}

					result = true;
				}
				if (current_string_has_tooltip)
				{
					ImGui::PopStyleColor();
					if (ImGui::IsItemHovered())
					{
						ImGui::SetTooltip(current_string_parser.description.c_str());
					}
				}
			}

			ImGui::EndCombo();
		}

		if (current_string_has_tooltip)
		{
			ImGui::PopStyleColor();
		}
		// #TODO: display out of bounds enum values
	}

	ImGui::Columns(1);

	ImGui::PopID();

	return result;
}

void c_high_level_tag_editor_tab::render_object(uint32_t level, h_object& object)
{
	const s_tag_struct_definition& struct_definition = object.get_blofeld_struct_definition();

	if (&struct_definition == &object_struct_definition_struct_definition)
	{
		if (custom_tool == nullptr)
		{
			//custom_tool = new c_custom_tool_render_model(cache_file, reinterpret_cast<haloreach::s_object_struct_definition*>(structure_data));
		}
		//custom_tool->render();
		ImGui::Text("CUSTOM TOOL!!!");
	}

	constexpr float indent = 25.0f;
	uint32_t field_index = 0;
	for (const s_tag_field* current_field = struct_definition.fields; current_field->field_type != _field_terminator; (current_field++, field_index++))
	{
		if (!object.is_field_active(*current_field))
		{
			continue;
		}

		void* field_data = object.get_field_pointer(*current_field);

		ImGui::PushID(field_index);

		bool data_modified = false;

		switch (current_field->field_type)
		{
		case _field_char_integer:					data_modified = render_primitive<_field_char_integer>(field_data, *current_field); break;
		case _field_short_integer:					data_modified = render_primitive<_field_short_integer>(field_data, *current_field); break;
		case _field_long_integer:					data_modified = render_primitive<_field_long_integer>(field_data, *current_field); break;
		case _field_int64_integer:					data_modified = render_primitive<_field_int64_integer>(field_data, *current_field); break;
		case _field_byte_integer:					data_modified = render_primitive<_field_byte_integer>(field_data, *current_field); break;
		case _field_word_integer:					data_modified = render_primitive<_field_word_integer>(field_data, *current_field); break;
		case _field_dword_integer:					data_modified = render_primitive<_field_dword_integer>(field_data, *current_field); break;
		case _field_qword_integer:					data_modified = render_primitive<_field_qword_integer>(field_data, *current_field); break;
		case _field_real:							data_modified = render_primitive<_field_real>(field_data, *current_field); break;
		case _field_real_fraction:					data_modified = render_primitive<_field_real_fraction>(field_data, *current_field); break;
		case _field_real_point_2d:					data_modified = render_primitive<_field_real_point_2d>(field_data, *current_field); break;
		case _field_real_point_3d:					data_modified = render_primitive<_field_real_point_3d>(field_data, *current_field); break;
		case _field_real_vector_2d:					data_modified = render_primitive<_field_real_vector_2d>(field_data, *current_field); break;
		case _field_real_vector_3d:					data_modified = render_primitive<_field_real_vector_3d>(field_data, *current_field); break;
		case _field_real_quaternion:				data_modified = render_primitive<_field_real_quaternion>(field_data, *current_field); break;
		case _field_real_plane_2d:					data_modified = render_primitive<_field_real_plane_2d>(field_data, *current_field); break;
		case _field_real_plane_3d:					data_modified = render_primitive<_field_real_plane_3d>(field_data, *current_field); break;
		case _field_real_rgb_color:					data_modified = render_primitive<_field_real_rgb_color>(field_data, *current_field); break;
		case _field_real_argb_color:				data_modified = render_primitive<_field_real_argb_color>(field_data, *current_field); break;
		case _field_real_hsv_color:					data_modified = render_primitive<_field_real_hsv_color>(field_data, *current_field); break;
		case _field_real_ahsv_color:				data_modified = render_primitive<_field_real_ahsv_color>(field_data, *current_field); break;
		case _field_short_bounds:					data_modified = render_primitive<_field_short_bounds>(field_data, *current_field); break;
		case _field_real_bounds:					data_modified = render_primitive<_field_real_bounds>(field_data, *current_field); break;
		case _field_real_fraction_bounds:			data_modified = render_primitive<_field_real_fraction_bounds>(field_data, *current_field); break;
		case _field_byte_block_flags:				data_modified = render_primitive<_field_byte_block_flags>(field_data, *current_field); break;
		case _field_word_block_flags:				data_modified = render_primitive<_field_word_block_flags>(field_data, *current_field); break;
		case _field_long_block_flags:				data_modified = render_primitive<_field_long_block_flags>(field_data, *current_field); break;
		case _field_char_block_index:				data_modified = render_primitive<_field_char_block_index>(field_data, *current_field); break;
		case _field_short_block_index:				data_modified = render_primitive<_field_short_block_index>(field_data, *current_field); break;
		case _field_long_block_index:				data_modified = render_primitive<_field_long_block_index>(field_data, *current_field); break;
		case _field_custom_char_block_index:		data_modified = render_primitive<_field_custom_char_block_index>(field_data, *current_field); break;
		case _field_custom_short_block_index:		data_modified = render_primitive<_field_custom_short_block_index>(field_data, *current_field); break;
		case _field_custom_long_block_index:		data_modified = render_primitive<_field_custom_long_block_index>(field_data, *current_field); break;
		case _field_pointer:						data_modified = render_primitive<_field_pointer>(field_data, *current_field); break;
		case _field_angle:							data_modified = render_primitive<_field_angle>(field_data, *current_field); break;
		case _field_real_euler_angles_2d:			data_modified = render_primitive<_field_real_euler_angles_2d>(field_data, *current_field); break;
		case _field_real_euler_angles_3d:			data_modified = render_primitive<_field_real_euler_angles_3d>(field_data, *current_field); break;
		case _field_angle_bounds:					data_modified = render_primitive<_field_angle_bounds>(field_data, *current_field); break;
		case _field_string:							data_modified = render_primitive<_field_string>(field_data, *current_field); break;
		case _field_long_string:					data_modified = render_primitive<_field_long_string>(field_data, *current_field); break;
		case _field_string_id:						data_modified = render_primitive<_field_string_id>(field_data, *current_field); break;
		case _field_old_string_id:					data_modified = render_primitive<_field_old_string_id>(field_data, *current_field); break;
		case _field_byte_flags:						data_modified = render_flags_definition(field_data, *current_field); break;
		case _field_word_flags:						data_modified = render_flags_definition(field_data, *current_field); break;
		case _field_long_flags:						data_modified = render_flags_definition(field_data, *current_field); break;
		case _field_char_enum:						data_modified = render_enum_definition(field_data, *current_field); break;
		case _field_enum:							data_modified = render_enum_definition(field_data, *current_field); break;
		case _field_long_enum:						data_modified = render_enum_definition(field_data, *current_field); break;
		case _field_tag_reference:
		{
			h_tag*& tag_reference = *static_cast<h_tag**>(field_data);
			render_tag_reference(tag_reference, *current_field);
			break;
		}
		case _field_data:
		{
			h_data& data = *static_cast<h_data*>(field_data);
			render_data(data, *current_field);
			break;
		}
		case _field_block:
		case _field_array:
		{
			h_enumerable& enumerable = *static_cast<h_enumerable*>(field_data);
			render_enumerable(enumerable, *current_field);
			break;
		}
		case _field_struct:
		{
			h_object& struct_object = *static_cast<h_object*>(field_data);
			render_object(level + 1, struct_object);
			break;
		}
		case _field_explanation:
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
		case _field_pad:
		case _field_useless_pad:
		case _field_skip:
		case _field_non_cache_runtime_value:
		case _field_custom:
			break;
		default:
			ImGui::Text("Unknown type for field '%s'", current_field->name);
			break;
		}

		if (data_modified)
		{
			object;
		}

		ImGui::PopID();
	}
}

void c_high_level_tag_editor_tab::render_tag_group()
{
	render_object(0, tag);
}
