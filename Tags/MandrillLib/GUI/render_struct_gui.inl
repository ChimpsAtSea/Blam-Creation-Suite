
ImVec2 render_struct_separator(int recursionDepth, ImVec2* pTopScreenPos = nullptr)
{
	ImVec2 screenPos = {};
	if (recursionDepth > 0)
	{
		constexpr float kHeight = 5.0f;

		ImGui::Columns(2, NULL, false);
		ImGui::SetColumnOffset(1, c_mandrill_legacy_tag_editor_gui_tab::g_current_recursion_padding);
		ImGui::SetColumnWidth(1, 1230);
		ImGui::NextColumn(); // padding
		//ImGui::Separator();
		ImGui::Dummy(ImVec2(0.0f, kHeight));
		ImDrawList* draw_list = ImGui::GetWindowDrawList();
		screenPos = ImGui::GetCursorScreenPos();

		if (pTopScreenPos)
		{
			float heightBias = 6.0f;

			float left = screenPos.x - 6.0f;
			float right = left + 1230;
			float bottom = screenPos.y - heightBias;
			float top = pTopScreenPos->y - heightBias;

			ImVec2 upper_left = { left, top };
			ImVec2 lower_right = { right, bottom };

			draw_list->AddRect(upper_left, lower_right, IM_COL32(80, 80, 80, 40), 0.0f, 0, 2.0f);
		}
		ImGui::Columns(1);
	}
	return screenPos;
}

void render_struct_gui_legacy(void* field_data, const c_reflection_field_legacy& reflection_field)
{
	bool unknownItemsVisible = c_old_mandrill_gui::get_unknown_fields_visibility();
	if (!unknownItemsVisible && reflection_field.is_hidden_by_default) return; // skip hidden fields
	DEBUG_ASSERT(field_data != nullptr);
	ImGui::PushID(field_data);

	ImVec2 screenPosTop = render_struct_separator(c_mandrill_legacy_tag_editor_gui_tab::g_current_recursion_depth);
	{
		const s_reflection_structure_info_legacy& rs_reflection_structure_info_legacy = reflection_field.structure_info;
		// #TODO: Supply structure_reflection_type directly as an argument
		const s_reflection_structure_type_legacy& structure_reflection_type = *rs_reflection_structure_info_legacy.reflection_type; //#TODO: Try to make this a reference in the type
		REFERENCE_ASSERT(structure_reflection_type);

		c_mandrill_legacy_tag_editor_gui_tab::increment_recursion();
		structure_reflection_type.render_type_gui_legacy(field_data);
		c_mandrill_legacy_tag_editor_gui_tab::decrement_recursion();
	}
	render_struct_separator(c_mandrill_legacy_tag_editor_gui_tab::g_current_recursion_depth, &screenPosTop);

	ImGui::PopID();
}

