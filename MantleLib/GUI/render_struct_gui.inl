
ImVec2 render_struct_separator(int recursionDepth, ImVec2* pTopScreenPos = nullptr)
{
	ImVec2 screenPos = {};
	if (recursionDepth > 0)
	{
		constexpr float kHeight = 5.0f;

		ImGui::Columns(2, NULL, false);
		ImGui::SetColumnOffset(1, recursionPadding);
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

void render_struct_gui(void* field_data, const ReflectionField& reflection_field)
{
	bool unknownItemsVisible = c_mantle_gui::get_unknown_fields_visibility();
	if (!unknownItemsVisible && reflection_field.m_isHiddenByDefault) return; // skip hidden fields
	DEBUG_ASSERT(field_data != nullptr);
	ImGui::PushID(field_data);

	ImVec2 screenPosTop = render_struct_separator(recursion_depth);
	{
		const ReflectionStructureInfo& rReflectionStructureInfo = reflection_field.m_structureInfo;
		// #TODO: Supply rStructureReflectionType directly as an argument
		const ReflectionType& rStructureReflectionType = *rReflectionStructureInfo.m_pReflectionTypeInfo; //#TODO: Try to make this a reference in the type
		REFERENCE_ASSERT(rStructureReflectionType);

		increment_recursion();
		rStructureReflectionType.render_type_gui(field_data);
		decrement_recursion();
	}
	render_struct_separator(recursion_depth, &screenPosTop);

	ImGui::PopID();
}

