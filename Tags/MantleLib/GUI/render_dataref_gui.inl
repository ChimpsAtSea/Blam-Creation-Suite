
class s_data_reference_dynamic_ui_data
{
public:
	ImGuiID unique_id;
	c_cache_file& cache_file;
	s_data_reference_legacy* field_data;
	MemoryEditor memory_editor;
	static volatile ImGuiID s_current_unique_id;

	s_data_reference_dynamic_ui_data(s_data_reference_legacy* field_data, c_cache_file& cache_file) :
		unique_id(_InterlockedIncrement(&s_current_unique_id)),
		cache_file(cache_file),
		field_data(field_data),
		memory_editor()
	{
		memory_editor.OptShowOptions = false;
	}
};
volatile ImGuiID s_data_reference_dynamic_ui_data::s_current_unique_id = 1;

void render_dataref_gui_legacy(s_data_reference_legacy* field_data, const c_reflection_field_legacy& reflection_field)
{
	bool unknownItemsVisible = c_mantle_gui::get_unknown_fields_visibility();
	if (!unknownItemsVisible && reflection_field.is_hidden_by_default) return; // skip hidden fields
	DEBUG_ASSERT(field_data != nullptr);
	ImGui::PushID(field_data);
	{
		ImGui::Columns(3, NULL, false);
		ImGui::SetColumnOffset(1, c_mantle_legacy_tag_editor_gui_tab::g_current_recursion_padding);
		ImGui::SetColumnWidth(1, 400);
		ImGui::SetColumnWidth(2, 740);
		ImGui::NextColumn(); // padding

		ImGui::Text(reflection_field.nice_name);
		ImGui::NextColumn();

		static_assert(sizeof(s_data_reference_dynamic_ui_data) <= sizeof(c_mantle_tag_gui_tab::c_imgui_dynamic_data::second), "s_data_reference_dynamic_data is too large");
		bool wasAllocated;
		s_data_reference_dynamic_ui_data& data_reference_ui_data = c_mantle_legacy_tag_editor_gui_tab::g_current_mantle_tag_tab->get_dynamic_data<s_data_reference_dynamic_ui_data>(field_data, wasAllocated);
		if (wasAllocated)
		{
			new(&data_reference_ui_data) s_data_reference_dynamic_ui_data(field_data, c_mantle_legacy_tag_editor_gui_tab::g_current_mantle_tag_tab->cache_file);
		}

		ImGui::Dummy(ImVec2(0.0f, 3.0f));
		static ImVec2 const data_reference_editor_size(800, ImGui::GetTextLineHeight() * 9.5f);
		if (ImGui::BeginChild(data_reference_ui_data.unique_id, data_reference_editor_size, false))
		{
			char* data_reference_data = nullptr;
			if (field_data->size)
			{
				data_reference_data = data_reference_ui_data.cache_file.get_tag_data(*field_data);
			}
			data_reference_ui_data.memory_editor.DrawContents(data_reference_data, field_data->size);
		}
		ImGui::EndChild();
		ImGui::Dummy(ImVec2(0.0f, 3.0f));

		ImGui::Columns(1);
	}

	ImGui::PopID();
}

