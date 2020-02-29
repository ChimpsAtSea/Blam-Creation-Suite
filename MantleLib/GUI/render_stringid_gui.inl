

void render_stringid_gui(string_id* field_data, const ReflectionField& reflection_field)
{
	bool unknownItemsVisible = c_mantle_gui::get_unknown_fields_visibility();
	if (!unknownItemsVisible && reflection_field.m_isHiddenByDefault) return; // skip hidden fields
	ImGui::PushID(field_data);

	DEBUG_ASSERT(field_data != nullptr);
	DEBUG_ASSERT(current_mantle_tag_tab != nullptr);

	string_id& field_string_id = *reinterpret_cast<string_id*>(field_data);

	class StringIDDynamicData
	{
	public:
		StringIDDynamicData(string_id& rStringID, CacheFile& rCacheFile)
			: szBuffer()
			, isValid(0)
			, bufferLength(0)
			, pStringID(&rStringID)
		{
			const char* pStringID = rCacheFile.GetStringIDStr(rStringID.stringid);
			if (pStringID)
			{
				strncpy_s(szBuffer, pStringID, strlen(pStringID));
				szBuffer[_countof(szBuffer) - 1] = 0;
				isValid = true;
			}
		}

		void updateStringID()
		{
			isValid = false;
		}

		char szBuffer[111];
		uint8_t isValid : 1;
		uint8_t bufferLength : 7;
		string_id* pStringID;
	};

	static_assert(sizeof(StringIDDynamicData) <= sizeof(MantleTagTab::ImGUIDynamicData::second), "StringIDDynamicData is too large");
	bool wasAllocated;
	StringIDDynamicData& rDynamicStringIDData = current_mantle_tag_tab->GetDynamicData<StringIDDynamicData>(field_data, wasAllocated);
	if (wasAllocated)
	{
		new(&rDynamicStringIDData) StringIDDynamicData(field_string_id, current_mantle_tag_tab->GetCacheFile());
	}

	ImGui::Columns(3, NULL, false);
	ImGui::SetColumnOffset(1, recursionPadding);
	ImGui::SetColumnWidth(1, 400);
	ImGui::NextColumn(); // padding

	ImGui::Text(reflection_field.m_pMemberNiceName);
	ImGui::NextColumn();
	ImGui::SetColumnWidth(2, 500);

	bool isValid = rDynamicStringIDData.isValid; // cache value as it changes in updateStringID
	if (!isValid) ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.4f, 0.4f, 1.0f));
	if (ImGui::InputText("StringID", rDynamicStringIDData.szBuffer, sizeof(rDynamicStringIDData.szBuffer)))
	{
		rDynamicStringIDData.updateStringID();
		write_line_verbose(rDynamicStringIDData.szBuffer);
	}
	if (!isValid) ImGui::PopStyleColor();

	ImGui::Columns(1);

	ImGui::PopID();
}

