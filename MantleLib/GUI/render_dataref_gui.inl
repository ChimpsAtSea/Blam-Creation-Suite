

void render_dataref_gui(DataReference* field_data, const ReflectionField& reflection_field)
{
	bool unknownItemsVisible = c_mantle_gui::get_unknown_fields_visibility();
	if (!unknownItemsVisible && reflection_field.m_isHiddenByDefault) return; // skip hidden fields
	DEBUG_ASSERT(field_data != nullptr);
	ImGui::PushID(field_data);
	{

		ImGui::Columns(3, NULL, false);
		ImGui::SetColumnOffset(1, recursionPadding);
		ImGui::SetColumnWidth(1, 400);
		ImGui::SetColumnWidth(2, 640);
		ImGui::NextColumn(); // padding

		ImGui::Text(reflection_field.m_pMemberNiceName);
		ImGui::NextColumn();

		static char pBuffer[256] = {};
		ImGui::InputTextMultiline("##datareference", pBuffer, 256, ImVec2(-FLT_MIN, ImGui::GetTextLineHeight() * 8.5f), ImGuiInputTextFlags_CharsHexadecimal | ImGuiInputTextFlags_CharsUppercase);

		ImGui::Columns(4, NULL, false);
		ImGui::SetColumnOffset(1, 400);
		ImGui::SetColumnWidth(1, 200);
		ImGui::SetColumnWidth(2, 220);
		ImGui::SetColumnWidth(3, 220);
		ImGui::NextColumn();
		ImGui::Text("dataref bytes");
		ImGui::NextColumn();
		static unsigned int dataRefLengthInt = 0; // #TODO: Hook this up
		ImGui::PushItemWidth(-1);
		ImGui::Text("Length:");
		ImGui::SameLine();
		ImGui::InputScalar("", ImGuiDataType_U32, &dataRefLengthInt);
		ImGui::NextColumn();
		static unsigned int dataRefOffsetInt = 0; // #TODO: Hook this up
		ImGui::PushItemWidth(-1);
		ImGui::Text("Offset:");
		ImGui::SameLine();
		ImGui::InputScalar("", ImGuiDataType_U32, &dataRefOffsetInt);
		ImGui::Columns(1);

	}
	ImGui::PopID();
}

