#include "mandrillui-private-pch.h"

#define null_coalesce(value, _default) ((value) ? (value) : (_default))
#define safe_string(value) null_coalesce(value, "")

using namespace blofeld;

float constexpr pi = 3.14159265359f;
float constexpr degrees_to_radians = pi / 180.0f;
float constexpr radians_to_degrees = 180.0f / pi;

c_high_level_tag_editor_tab::c_high_level_tag_editor_tab(c_tag_project& tag_project, h_tag& tag, c_mandrill_tab& parent) :
	c_mandrill_tab("Tag Editor", "Blofeld Tag Definition Debug", &parent, false),
	tag_project(tag_project),
	tag(tag),
	viewport_size(),
	custom_tool(nullptr),
	model_preview_test(nullptr),
	haloreach_bitmap_test(nullptr),
	show_bitmap_export_file_dialog(),
	file_browser()
{
	if (c_mandrill_user_interface* mandrill_user_interface = search_parent_tab_type<c_mandrill_user_interface>())
	{
		blofeld::infinite::h_s_model_definition* model_tag = dynamic_cast<decltype(model_tag)>(&tag);
		blofeld::infinite::h_objectdefinition* object_tag = nullptr;
		if (blofeld::infinite::h_weapondefinition* weapon_definition = dynamic_cast<decltype(weapon_definition)>(&tag))
		{
			h_tag* tag = weapon_definition->item.object.model;
			if (model_tag = dynamic_cast<decltype(model_tag)>(tag))
			{
				object_tag = &weapon_definition->item.object;
			}
		}
		if (blofeld::infinite::h_vehicledefinition* vehicle_definition = dynamic_cast<decltype(vehicle_definition)>(&tag))
		{
			h_tag* tag = vehicle_definition->unit.object.model;
			if (model_tag = dynamic_cast<decltype(model_tag)>(tag))
			{
				object_tag = &vehicle_definition->unit.object;
			}
		}
		if (blofeld::infinite::h_bipeddefinition* biped_definition = dynamic_cast<decltype(biped_definition)>(&tag))
		{
			h_tag* tag = biped_definition->unit.object.model;
			if (model_tag = dynamic_cast<decltype(model_tag)>(tag))
			{
				object_tag = &biped_definition->unit.object;
			}
		}
		if (blofeld::infinite::h_crate_definition* crate_definition = dynamic_cast<decltype(crate_definition)>(&tag))
		{
			h_tag* tag = crate_definition->object.model;
			if (model_tag = dynamic_cast<decltype(model_tag)>(tag))
			{
				object_tag = &crate_definition->object;
			}
		}
		if (blofeld::infinite::h_creature_definition* creature_definition = dynamic_cast<decltype(creature_definition)>(&tag))
		{
			h_tag* tag = creature_definition->object.model;
			if (model_tag = dynamic_cast<decltype(model_tag)>(tag))
			{
				object_tag = &creature_definition->object;
			}
		}
		if (blofeld::infinite::h_equipmentdefinition* equipment_definition = dynamic_cast<decltype(equipment_definition)>(&tag))
		{
			h_tag* tag = equipment_definition->item.object.model;
			if (model_tag = dynamic_cast<decltype(model_tag)>(tag))
			{
				object_tag = &equipment_definition->item.object;
			}
		}
		if (blofeld::haloreach::h_bitmap_block_struct* bitmap_definition = dynamic_cast<decltype(bitmap_definition)>(&tag))
		{
			haloreach_bitmap_test = new() c_haloreach_bitmap_test(mandrill_user_interface->imgui_viewport_render_context, *bitmap_definition);
		}

		if (model_tag)
		{
			model_preview_test = new() c_model_preview_test(mandrill_user_interface->imgui_viewport_render_context, *model_tag, object_tag);
		}
	}
}

c_high_level_tag_editor_tab::~c_high_level_tag_editor_tab()
{
	if (haloreach_bitmap_test)
	{
		delete haloreach_bitmap_test;
	}
	if (model_preview_test)
	{
		delete model_preview_test;
	}
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


		//ImGui::SameLine(0.0f, 25.0f);
		//static bool use_live_mode = false;
		//ImGui::Checkbox("Use Live Mode", &use_live_mode);
		//ImGui::SameLine(0.0f, 25.0f);
		//ImGui::Text("Status:");
		//ImGui::SameLine();
		//ImGui::Text("Ready");


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

bool c_high_level_tag_editor_tab::render_menu_gui_impl(e_menu_render_type menu_render_type)
{
	if (menu_render_type == _menu_render_type_root_file && is_selected())
	{
		if (haloreach_bitmap_test)
		{
			if (ImGui::MenuItem("Export Tag"))
			{
				show_bitmap_export_file_dialog = true;
			}

			ImGui::Separator();
		}
	}
	return true;
}

void c_high_level_tag_editor_tab::render_file_dialogue_gui_impl()
{
	if (ImGui::BeginAsyncSaveFileDialog(&file_browser, "Export Bitmap Tag", show_bitmap_export_file_dialog))
	{
		if (ImGui::AsyncFileDialogIsValid())
		{
			const char* filepath = ImGui::AsyncFileDialogGetFilepathMultiByte();

			if (haloreach_bitmap_test)
			{
				haloreach_bitmap_test->_export(filepath);
			}

			debug_point;
		}
		debug_point;

		ImGui::EndAsyncFileDialog();
	}
	show_bitmap_export_file_dialog = false;
}

void c_high_level_tag_editor_tab::render_game_layer_impl()
{

}

template<e_field field_type>
bool c_high_level_tag_editor_tab::render_primitive(void* data, const s_tag_field& field)
{
	using namespace blofeld;

	ImGui::PushID(data);

	bool result = false;
	ImGui::Columns(2, nullptr, false);
	ImGui::SetColumnWidth(0, k_field_display_name_width);
	{
		if (field.description)
		{
			ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_INFO_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA));
		}

		ImGui::TextUnformatted(field.name);

		if (field.description)
		{
			if (ImGui::IsItemHovered())
			{
				ImGui::SetTooltip(field.description);
			}
			ImGui::PopStyleColor();
		}

	}
	ImGui::NextColumn();
	{
		if constexpr (field_type == _field_char_integer || field_type == _field_custom_char_block_index || field_type == _field_char_block_index || field_type == _field_char_enum)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(safe_string(field.units), ImGuiDataType_S8, data);
		}
		else if constexpr (field_type == _field_byte_flags || field_type == _field_byte_block_flags || field_type == _field_byte_integer)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(safe_string(field.units), ImGuiDataType_U8, data);
		}
		else if constexpr (field_type == _field_enum || field_type == _field_short_block_index || field_type == _field_custom_short_block_index || field_type == _field_short_integer)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(safe_string(field.units), ImGuiDataType_S16, data);
		}
		else if constexpr (field_type == _field_word_flags || field_type == _field_word_block_flags || field_type == _field_word_integer)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(safe_string(field.units), ImGuiDataType_U16, data);
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
			result = ImGui::InputScalar(safe_string(field.units), ImGuiDataType_S32, data);
		}
		else if constexpr (field_type == _field_dword_integer)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(safe_string(field.units), ImGuiDataType_U32, data);
		}
		else if constexpr (field_type == _field_int64_integer)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(safe_string(field.units), ImGuiDataType_S64, data);
		}
		else if constexpr (field_type == _field_qword_integer)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(safe_string(field.units), ImGuiDataType_U64, data);
		}
		else if constexpr (field_type == _field_real || field_type == _field_real_fraction || field_type == _field_half)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputScalar(safe_string(field.units), ImGuiDataType_Float, data);
		}
		else if constexpr (field_type == _field_short_bounds || field_type == _field_point_2d)
		{
			ImGui::SetNextItemWidth(400.0f);
			result = ImGui::InputScalarN(safe_string(field.units), ImGuiDataType_S16, data, 2);
		}
		else if constexpr (field_type == _field_rectangle_2d)
		{
			ImGui::SetNextItemWidth(800.0f);
			result = ImGui::InputScalarN(safe_string(field.units), ImGuiDataType_S16, data, 4);
		}
		else if constexpr (field_type == _field_real_vector_2d || field_type == _field_real_bounds || field_type == _field_real_fraction_bounds || field_type == _field_real_point_2d)
		{
			ImGui::SetNextItemWidth(400.0f);
			result = ImGui::InputScalarN(safe_string(field.units), ImGuiDataType_Float, data, 2);
		}
		else if constexpr (field_type == _field_real_point_3d || field_type == _field_real_rgb_color || field_type == _field_real_hsv_color || field_type == _field_real_plane_2d || field_type == _field_real_vector_3d)
		{
			ImGui::SetNextItemWidth(600.0f);
			result = ImGui::InputScalarN(safe_string(field.units), ImGuiDataType_Float, data, 3);
		}
		else if constexpr (field_type == _field_real_argb_color || field_type == _field_real_ahsv_color || field_type == _field_real_plane_3d || field_type == _field_real_quaternion)
		{
			ImGui::SetNextItemWidth(800.0f);
			result = ImGui::InputScalarN(safe_string(field.units), ImGuiDataType_Float, data, 4);
		}
		else if constexpr (field_type == _field_pointer)
		{
			ImGui::SetNextItemWidth(350.0f);
#ifdef _WIN64
			result = ImGui::InputScalar(safe_string(field.units), ImGuiDataType_U64, data);
#else
			result = ImGui::InputScalar(safe_string(field.units), ImGuiDataType_U32, data);
#endif
		}
		else if constexpr (field_type == _field_angle)
		{
			ImGui::SetNextItemWidth(350.0f);
			float& radians = *static_cast<float*>(data);
			float degrees = radians * radians_to_degrees;
			if (result = ImGui::InputScalar(safe_string(field.units), ImGuiDataType_Float, &degrees))
			{
				radians = degrees * degrees_to_radians;
			}
		}
		else if constexpr (field_type == _field_angle_bounds)
		{
			ImGui::SetNextItemWidth(400.0f);
			float(&radians)[2] = *static_cast<float(*)[2]>(data);
			float degrees[2] = { radians[0] * radians_to_degrees, radians[1] * radians_to_degrees };
			if (result = ImGui::InputScalarN(safe_string(field.units), ImGuiDataType_Float, &degrees, 2))
			{
				radians[0] = degrees[0] * degrees_to_radians;
				radians[1] = degrees[1] * degrees_to_radians;
			}
		}
		else if constexpr (field_type == _field_string)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputText(safe_string(field.units), static_cast<char*>(data), 32);
		}
		else if constexpr (field_type == _field_long_string || field_type == _field_data_path)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputText(safe_string(field.units), static_cast<char*>(data), 256);
		}
		else if constexpr (field_type == _field_string_id || field_type == _field_old_string_id)
		{
			ImGui::SetNextItemWidth(350.0f);
			result = ImGui::InputText(safe_string(field.units), static_cast<char*>(data), 2048);
		}
		else if constexpr (field_type == _field_real_euler_angles_2d)
		{
			ImGui::SetNextItemWidth(400.0f);
			float(&radians)[2] = *static_cast<float(*)[2]>(data);
			float degrees[2] = { radians[0] * radians_to_degrees, radians[1] * radians_to_degrees };
			if (result = ImGui::InputScalarN(safe_string(field.units), ImGuiDataType_Float, &degrees, 2))
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
			if (result = ImGui::InputScalarN(safe_string(field.units), ImGuiDataType_Float, &degrees, 3))
			{
				radians[0] = degrees[0] * degrees_to_radians;
				radians[1] = degrees[1] * degrees_to_radians;
				radians[2] = degrees[2] * degrees_to_radians;
			}
		}
	}
	ImGui::Columns(1);

	ImGui::PopID();

	return result;
}

void c_high_level_tag_editor_tab::render_enumerable(h_enumerable& enumerable, const s_tag_field& field)
{
	constexpr float k_min_block_width = 1000.0f;
	constexpr float k_block_header_height = 80.0f;

	unsigned long const count = enumerable.size();

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

			ImGui::PushID(index);

			h_object& object = enumerable.get(index);
			render_object(0, object);

			ImGui::PopID();

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
			header_str.format("%s : count:%u", field.name, count);

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
		int32_t insert_offset = static_cast<unsigned long>(storage->GetInt(inserting_offset_id));
		unsigned long insert_count = static_cast<unsigned long>(storage->GetInt(inserting_count_id));

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
				block->insert_hole(static_cast<unsigned long>(insert_offset), insert_count);
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
		BCS_RESULT get_group_result = tag_project.get_group_by_group_tag(group_tag, group);
		ASSERT(group_tag == blofeld::INVALID_TAG || BCS_SUCCEEDED(get_group_result));
	}

	ImGui::Columns(2, nullptr, false);
	ImGui::SetColumnWidth(0, k_field_display_name_width);
	{
		if (field.description)
		{
			ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_INFO_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA));
		}

		ImGui::TextUnformatted(field.name);

		if (field.description)
		{
			if (ImGui::IsItemHovered())
			{
				ImGui::SetTooltip(field.description);
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

			h_group* const* groups;
			unsigned long group_count;
			if (BCS_SUCCEEDED(tag_project.get_tag_groups(groups, group_count)))
			{
				for (unsigned long group_index = 0; group_index < group_count; group_index++)
				{
					h_group* current_group = groups[group_index];

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
			h_tag* const* tag_instances = nullptr;
			unsigned long num_tag_instances = 0;
			if (group != nullptr)
			{
				tag_instances = group->tags.data();
				num_tag_instances = static_cast<unsigned long>(group->tags.size());
			}
			else
			{
				tag_project.get_tag_instances(tag_instances, num_tag_instances);
			}

			for (unsigned long tag_instance_index = 0; tag_instance_index < num_tag_instances; tag_instance_index++)
			{
				h_tag* tag = tag_instances[tag_instance_index];

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

static const blofeld::s_tag_field* g_current_field;
class c_high_level_imgui_memory_editor_settings :
	public s_imgui_memory_editor_settings
{
public:
	c_high_level_imgui_memory_editor_settings() :
		s_imgui_memory_editor_settings()
	{
		CustomUIFn = custom_ui_function;
	}

	static bool custom_ui_function(void* userdata, void* data, size_t size)
	{
		bool is_handled = true;
		if (ImGui::Button("Export"))
		{
			filesystem_write_file_from_memory("export.bin", data, size);
		}
		ImGui::SameLine();
		return is_handled;
	}
};
static c_high_level_imgui_memory_editor_settings imgui_memory_editor_settings;

void c_high_level_tag_editor_tab::render_data(h_data& data, const blofeld::s_tag_field& field)
{
	g_current_field = &field;
	ImGui::PushID(&field);
	{
		ImGui::Columns(2, NULL, false);
		ImGui::SetColumnWidth(0, 400);
		ImGui::SetColumnWidth(1, 900);
		{
			ImGui::TextUnformatted(field.name);
		}
		ImGui::NextColumn();
		{
			ImGui::Dummy(ImVec2(0.0f, 3.0f));
			if (ImGui::BeginChild("##data", { 0.0f, ImGui::GetTextLineHeight() * 9.5f }, false))
			{
				imgui_memory_editor(imgui_memory_editor_settings, data.data(), data.size(), &data);
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

	unsigned long value = 0;
	switch (field.field_type)
	{
	case _field_byte_flags:
		value = *reinterpret_cast<unsigned char*>(data);
		break;
	case _field_word_flags:
		value = *reinterpret_cast<unsigned short*>(data);
		break;
	case _field_long_flags:
		value = *reinterpret_cast<unsigned long*>(data);
		break;
	DEBUG_ONLY(default: throw);
	}

	ImGui::PushID(data);

	ImGui::Columns(2, NULL, false);
	ImGui::SetColumnWidth(0, k_field_display_name_width);
	ImGui::SetColumnWidth(1, 1150);
	{
		ImGui::Text(field.name);
	}
	ImGui::NextColumn();
	{
		unsigned long const string_list_count = string_list_definition.get_count(tag_project.engine_platform_build);

		float const element_height = ImGui::GetTextLineHeight() * 1.45f;
		float const height = __min(element_height * 9.5f, element_height * static_cast<float>(__max(1u, string_list_count)));

		if (ImGui::BeginChild("bitfield", ImVec2(800.0f, height)))
		{
			for (unsigned long string_index = 0; string_index < string_list_count; string_index++)
			{
				// #TODO: replace string parser for the bitfield
				const char* current_string = string_list_definition.get_string(tag_project.engine_platform_build, string_index);

				bool const current_string_has_tooltip = false; // !current_string_parser.description.empty();
				if (current_string_has_tooltip)
				{
					ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_INFO_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA));
				}
				unsigned long mask = 1u << string_index;
				bool is_flag_set = (value & mask) != 0;
				if (ImGui::Checkbox(current_string, &is_flag_set))
				{
					value &= ~mask;
					if (is_flag_set)
					{
						value |= mask;
					}

					switch (field.field_type)
					{
					case blofeld::_field_byte_flags:
						*reinterpret_cast<unsigned char*>(data) = static_cast<unsigned char>(value);
						break;
					case blofeld::_field_word_flags:
						*reinterpret_cast<unsigned short*>(data) = static_cast<unsigned short>(value);
						break;
					case blofeld::_field_long_flags:
						*reinterpret_cast<unsigned long*>(data) = static_cast<unsigned long>(value);
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
						//ImGui::SetTooltip(current_string_parser.description);
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

	long value = 0;
	switch (field.field_type)
	{
	case _field_char_enum:
		value = *reinterpret_cast<char*>(data);
		break;
	case _field_enum:
		value = *reinterpret_cast<short*>(data);
		break;
	case _field_long_enum:
		value = *reinterpret_cast<long*>(data);
		break;
	DEBUG_ONLY(default: throw);
	}

	ImGui::PushID(data);

	ImGui::Columns(2, NULL, false);
	ImGui::SetColumnWidth(0, k_field_display_name_width);
	ImGui::SetColumnWidth(1, 1150);
	{
		ImGui::Text(field.name);
	}
	ImGui::NextColumn();
	{
		long const string_list_count = static_cast<long>(string_list_definition.get_count(tag_project.engine_platform_build));

		const char* selected_string_value = "<INVALID VALUE>";
		bool current_string_has_tooltip = false;

		// #TODO: replace string parser for the enum
		if (value < string_list_count)
		{
			selected_string_value = string_list_definition.get_string(tag_project.engine_platform_build, value);
		}
		else
		{
			int buffer_length = snprintf(nullptr, 0, "<INVALID VALUE> 0x%08X", selected_string_value) + 1;
			char* buffer = static_cast<char*>(alloca(buffer_length));
			sprintf(buffer, "<INVALID VALUE> 0x%08X", value);
			selected_string_value = buffer;
		}

		if (ImGui::BeginCombo("##enum", selected_string_value))
		{
			for (unsigned long string_index = 0; string_index < string_list_count; string_index++)
			{
				const char* current_string = string_list_definition.get_string(tag_project.engine_platform_build, string_index);

				bool const current_string_has_tooltip = false; // !current_string_parser.description.empty();
				if (current_string_has_tooltip)
				{
					ImGui::PushStyleColor(ImGuiCol_Text, MANDRILL_THEME_INFO_TEXT(MANDRILL_THEME_DEFAULT_TEXT_ALPHA));
				}
				if (ImGui::Selectable(current_string))
				{
					value = string_index;

					switch (field.field_type)
					{
					case blofeld::_field_char_enum:
						*reinterpret_cast<char*>(data) = static_cast<char>(value);
						break;
					case blofeld::_field_enum:
						*reinterpret_cast<short*>(data) = static_cast<short>(value);
						break;
					case blofeld::_field_long_enum:
						*reinterpret_cast<long*>(data) = static_cast<long>(value);
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
						//ImGui::SetTooltip(current_string_parser.description);
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

bool c_high_level_tag_editor_tab::render_tag(::tag& value, const blofeld::s_tag_field& field)
{
	bool result = false;

	ImGui::PushID(&value);

	ImGui::Columns(2, NULL, false);
	ImGui::SetColumnWidth(0, k_field_display_name_width);
	ImGui::SetColumnWidth(1, 1150);
	{
		ImGui::Text(field.name);
	}
	ImGui::NextColumn();
	{
		h_group* selected_group;
		BCS_RESULT rs = tag_project.get_group_by_group_tag(value, selected_group);
		ASSERT(BCS_SUCCEEDED(rs));
		ASSERT(value == blofeld::INVALID_TAG || selected_group != nullptr);

		const char* selected_string_value = "";

		if (selected_group != nullptr)
		{
			selected_string_value = selected_group->tag_group.name;
		}

		if (ImGui::BeginCombo("##tag", selected_string_value))
		{
			h_group* const* groups;
			unsigned long group_count;
			if (BCS_SUCCEEDED(tag_project.get_tag_groups(groups, group_count)))
			{
				for (unsigned long group_index = 0; group_index < group_count; group_index++)
				{
					h_group* group = groups[group_index];
					if (ImGui::Selectable(group->tag_group.name))
					{
						::tag new_value = group->tag_group.group_tag;
						if (value != new_value)
						{
							value = new_value;
							result = true;
						}
					}
				}
			}
			else
			{
				ImGui::Text("c_tag_project::get_tag_groups had an error");
			}

			ImGui::EndCombo();
		}
	}

	ImGui::Columns(1);

	ImGui::PopID();

	return result;
}

void c_high_level_tag_editor_tab::render_object(unsigned long level, h_object& object)
{
	ImGui::PushID(&object);

	const s_tag_struct_definition& struct_definition = object.get_blofeld_struct_definition();

	//if (&struct_definition == &object_struct_definition)
	//{
	//	if (custom_tool == nullptr)
	//	{
	//		//custom_tool = new() c_custom_tool_render_model(cache_file, reinterpret_cast<haloreach::s_object_struct_definition*>(structure_data));
	//	}
	//	//custom_tool->render();
	//	ImGui::Text("CUSTOM TOOL!!!");
	//}

	constexpr float indent = 25.0f;
	unsigned long field_index = 0;
	for (const s_tag_field* const* field_pointer = object.get_blofeld_field_list(); *field_pointer != nullptr; field_pointer++)
	{
		const s_tag_field& field = **field_pointer;

		void* field_data = object.get_field_data(field);

		ImGui::PushID(field_index);

		bool data_modified = false;

		switch (field.field_type)
		{
		case _field_char_integer:					data_modified = render_primitive<_field_char_integer>(field_data, field); break;
		case _field_short_integer:					data_modified = render_primitive<_field_short_integer>(field_data, field); break;
		case _field_long_integer:					data_modified = render_primitive<_field_long_integer>(field_data, field); break;
		case _field_int64_integer:					data_modified = render_primitive<_field_int64_integer>(field_data, field); break;
		case _field_byte_integer:					data_modified = render_primitive<_field_byte_integer>(field_data, field); break;
		case _field_word_integer:					data_modified = render_primitive<_field_word_integer>(field_data, field); break;
		case _field_dword_integer:					data_modified = render_primitive<_field_dword_integer>(field_data, field); break;
		case _field_qword_integer:					data_modified = render_primitive<_field_qword_integer>(field_data, field); break;
		case _field_real:							data_modified = render_primitive<_field_real>(field_data, field); break;
		case _field_real_fraction:					data_modified = render_primitive<_field_real_fraction>(field_data, field); break;
		case _field_real_point_2d:					data_modified = render_primitive<_field_real_point_2d>(field_data, field); break;
		case _field_real_point_3d:					data_modified = render_primitive<_field_real_point_3d>(field_data, field); break;
		case _field_real_vector_2d:					data_modified = render_primitive<_field_real_vector_2d>(field_data, field); break;
		case _field_real_vector_3d:					data_modified = render_primitive<_field_real_vector_3d>(field_data, field); break;
		case _field_real_quaternion:				data_modified = render_primitive<_field_real_quaternion>(field_data, field); break;
		case _field_real_plane_2d:					data_modified = render_primitive<_field_real_plane_2d>(field_data, field); break;
		case _field_real_plane_3d:					data_modified = render_primitive<_field_real_plane_3d>(field_data, field); break;
		case _field_real_rgb_color:					data_modified = render_primitive<_field_real_rgb_color>(field_data, field); break;
		case _field_real_argb_color:				data_modified = render_primitive<_field_real_argb_color>(field_data, field); break;
		case _field_real_hsv_color:					data_modified = render_primitive<_field_real_hsv_color>(field_data, field); break;
		case _field_real_ahsv_color:				data_modified = render_primitive<_field_real_ahsv_color>(field_data, field); break;
		case _field_short_bounds:					data_modified = render_primitive<_field_short_bounds>(field_data, field); break;
		case _field_point_2d:						data_modified = render_primitive<_field_point_2d>(field_data, field); break;
		case _field_real_bounds:					data_modified = render_primitive<_field_real_bounds>(field_data, field); break;
		case _field_real_fraction_bounds:			data_modified = render_primitive<_field_real_fraction_bounds>(field_data, field); break;
		case _field_byte_block_flags:				data_modified = render_primitive<_field_byte_block_flags>(field_data, field); break;
		case _field_word_block_flags:				data_modified = render_primitive<_field_word_block_flags>(field_data, field); break;
		case _field_long_block_flags:				data_modified = render_primitive<_field_long_block_flags>(field_data, field); break;
		case _field_char_block_index:				data_modified = render_primitive<_field_char_block_index>(field_data, field); break;
		case _field_short_block_index:				data_modified = render_primitive<_field_short_block_index>(field_data, field); break;
		case _field_long_block_index:				data_modified = render_primitive<_field_long_block_index>(field_data, field); break;
		case _field_custom_char_block_index:		data_modified = render_primitive<_field_custom_char_block_index>(field_data, field); break;
		case _field_custom_short_block_index:		data_modified = render_primitive<_field_custom_short_block_index>(field_data, field); break;
		case _field_custom_long_block_index:		data_modified = render_primitive<_field_custom_long_block_index>(field_data, field); break;
		case _field_pointer:						data_modified = render_primitive<_field_pointer>(field_data, field); break;
		case _field_angle:							data_modified = render_primitive<_field_angle>(field_data, field); break;
		case _field_real_euler_angles_2d:			data_modified = render_primitive<_field_real_euler_angles_2d>(field_data, field); break;
		case _field_real_euler_angles_3d:			data_modified = render_primitive<_field_real_euler_angles_3d>(field_data, field); break;
		case _field_angle_bounds:					data_modified = render_primitive<_field_angle_bounds>(field_data, field); break;
		case _field_string:							data_modified = render_primitive<_field_string>(field_data, field); break;
		case _field_data_path:						data_modified = render_primitive<_field_data_path>(field_data, field); break;
		case _field_long_string:					data_modified = render_primitive<_field_long_string>(field_data, field); break;
		case _field_string_id:						data_modified = render_primitive<_field_string_id>(field_data, field); break;
		case _field_old_string_id:					data_modified = render_primitive<_field_old_string_id>(field_data, field); break;
		case _field_byte_flags:						data_modified = render_flags_definition(field_data, field); break;
		case _field_word_flags:						data_modified = render_flags_definition(field_data, field); break;
		case _field_long_flags:						data_modified = render_flags_definition(field_data, field); break;
		case _field_char_enum:						data_modified = render_enum_definition(field_data, field); break;
		case _field_enum:							data_modified = render_enum_definition(field_data, field); break;
		case _field_long_enum:						data_modified = render_enum_definition(field_data, field); break;
		case _field_tag_reference:
		case _field_embedded_tag:
		{
			h_tag*& tag_reference = *static_cast<h_tag**>(field_data);
			data_modified = render_tag_reference(tag_reference, field);
			break;
		}
		case _field_data:
		{
			h_data& data = *static_cast<h_data*>(field_data);
			render_data(data, field);
			break;
		}
		case _field_block:
		case _field_array:
		{
			h_enumerable& enumerable = *static_cast<h_enumerable*>(field_data);
			render_enumerable(enumerable, field);
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
				const char* display_name = field.name;
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
				if (field.explanation && field.explanation)
				{
					ImGui::Dummy({ padding_offset, 0.0f });
					ImGui::SameLine();
					ImGui::TextUnformatted(field.explanation);
				}
				ImGui::PopStyleColor();
				ImGui::Dummy({ 5.0f, 5.0f });
			}
			ImGui::EndGroup();
			const char* description = field.description;
			if (description && ImGui::IsItemHovered())
			{
				ImGui::BeginTooltipEx(0, ImGuiTooltipFlags_OverridePreviousTooltip);
				ImGui::TextUnformatted(description);
				ImGui::EndTooltip();
			}
			break;
		}
		case _field_tag:
		{
			render_tag(*static_cast<::tag*>(field_data), field);
			break;
		}
		case _field_pad:
		case _field_useless_pad:
		case _field_skip:
		case _field_non_cache_runtime_value:
		case _field_custom:
			break;
		case _field_pageable:
		{
			h_resource*& resource = *static_cast<h_resource**>(field_data);

			ImGui::PushID(&field);
			{
				ImGui::Columns(2, NULL, false);
				ImGui::SetColumnWidth(0, 400);
				ImGui::SetColumnWidth(1, 900);
				{
					ImGui::TextUnformatted(field.name);
				}
				ImGui::NextColumn();
				{
					ImGui::Dummy(ImVec2(0.0f, 3.0f));
					if (resource)
					{
						const char* debug_type_string = resource->get_debug_type_string();
						ImGui::Text("Resource Type: %s", debug_type_string);

						if (ImGui::Button("Dump (resourcedump.bin)"))
						{
							const void* resource_data;
							unsigned long resource_data_size;
							if (BCS_SUCCEEDED(resource->add_reference(resource_data, resource_data_size)))
							{
								filesystem_write_file_from_memory("resourcedump.bin", resource_data, resource_data_size);
								ASSERT(BCS_SUCCEEDED(resource->remove_reference()));
							}
						}

						if (resource->object)
						{
							render_object(level + 1, *resource->object);
						}
					}
					else
					{
						ImGui::TextUnformatted("Resource Type: null");
					}
					ImGui::Dummy(ImVec2(0.0f, 3.0f));
				}
				ImGui::Columns(1);
			}

			ImGui::PopID();
		}
		break;
		default:
			const char* field_type_name = "Unknown Field Type";
			field_to_tag_field_type(field.field_type, field_type_name);
			ImGui::Text("Unknown type '%s' for field '%s'", field_type_name, field.name);
			break;
		}

		if (data_modified)
		{
			c_data_change_notification notification = {};
			notification.field = &field;
			notification.type = &object;
			object.notify_data_change(notification);
		}

		ImGui::PopID();
	}
	ImGui::PopID();
}

void c_high_level_tag_editor_tab::render_tag_group()
{
	ImGui::Dummy({ 0.0f, 10.0f });
	if (model_preview_test)
	{
		model_preview_test->draw_ui();
	}
	if (haloreach_bitmap_test)
	{
		haloreach_bitmap_test->draw_ui();
	}
	render_object(0, tag);
	ImGui::Dummy({ 0.0f, 10.0f });
}
