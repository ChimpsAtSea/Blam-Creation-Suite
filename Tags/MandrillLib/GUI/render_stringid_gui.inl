

void render_stringid_gui_legacy(string_id_legacy* field_data, const c_reflection_field_legacy& reflection_field)
{
	bool unknownItemsVisible = c_mandrill_gui::get_unknown_fields_visibility();
	if (!unknownItemsVisible && reflection_field.is_hidden_by_default) return; // skip hidden fields
	ImGui::PushID(field_data);

	DEBUG_ASSERT(field_data != nullptr);
	DEBUG_ASSERT(c_mandrill_legacy_tag_editor_gui_tab::g_current_mandrill_tag_tab != nullptr);

	string_id_legacy& field_string_id = *reinterpret_cast<string_id_legacy*>(field_data);

	class string_id_dynamic_ui_data
	{
	public:
		char szBuffer[127];
		uint8_t isValid : 1;
		uint8_t buffer_length : 7;
		string_id_legacy* id_pointer;

		string_id_dynamic_ui_data(string_id_legacy& id, c_cache_file& cache_file) : 
			szBuffer(),
			isValid(false),
			buffer_length(0),
			id_pointer(&id)
		{
			const char* id_pointer = cache_file.get_string_id(id);
			if (id_pointer)
			{
				strncpy_s(szBuffer, id_pointer, strlen(id_pointer));
				szBuffer[_countof(szBuffer) - 1] = 0;
				isValid = true;
			}
		}

		void updateStringID()
		{
			isValid = false;
		}
	};

	static_assert(sizeof(string_id_dynamic_ui_data) <= sizeof(c_mandrill_tag_gui_tab::c_imgui_dynamic_data::second), "StringIDDynamicData is too large");
	bool wasAllocated;
	string_id_dynamic_ui_data& rDynamicStringIDData = c_mandrill_legacy_tag_editor_gui_tab::g_current_mandrill_tag_tab->get_dynamic_data<string_id_dynamic_ui_data>(field_data, wasAllocated);
	if (wasAllocated)
	{
		new(&rDynamicStringIDData) string_id_dynamic_ui_data(field_string_id, c_mandrill_legacy_tag_editor_gui_tab::g_current_mandrill_tag_tab->cache_file);
	}

	ImGui::Columns(3, NULL, false);
	ImGui::SetColumnOffset(1, c_mandrill_legacy_tag_editor_gui_tab::g_current_recursion_padding);
	ImGui::SetColumnWidth(1, 400);
	ImGui::NextColumn(); // padding

	ImGui::Text(reflection_field.nice_name);
	ImGui::NextColumn();
	ImGui::SetColumnWidth(2, 500);

	bool isValid = rDynamicStringIDData.isValid; // cache value as it changes in updateStringID
	if (!isValid) ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.4f, 0.4f, 1.0f));
	if (ImGui::InputText("StringID", rDynamicStringIDData.szBuffer, sizeof(rDynamicStringIDData.szBuffer)))
	{
		rDynamicStringIDData.updateStringID();
		c_console::write_line_verbose(rDynamicStringIDData.szBuffer);
	}
	if (!isValid) ImGui::PopStyleColor();

	ImGui::Columns(1);

	ImGui::PopID();
}

