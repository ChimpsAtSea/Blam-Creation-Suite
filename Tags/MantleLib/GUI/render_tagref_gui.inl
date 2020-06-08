
void render_tagref_gui_legacy(s_tag_reference_legacy* field_data, const char* name, c_cache_file& cache_file)
{
	DEBUG_ASSERT(field_data != nullptr);
	ImGui::PushID(field_data);

	ImGui::Columns(6, NULL, false);
	ImGui::SetColumnOffset(1, c_mantle_legacy_tag_editor_gui_tab::g_current_recursion_padding);
	ImGui::SetColumnWidth(1, 400);
	ImGui::SetColumnWidth(2, 150);
	ImGui::SetColumnWidth(3, 750);
	ImGui::SetColumnWidth(4, 65);
	ImGui::SetColumnWidth(5, 65);
	ImGui::NextColumn(); // padding

	ImGui::Text(name);
	ImGui::NextColumn();
	ImGui::PushItemWidth(-1);

	const char* group_short_name = "(null)";
	c_tag_group_interface* tag_group_interface = cache_file.get_tag_group_interface_by_group_id(field_data->tag_group_name);
	if (tag_group_interface)
	{
		group_short_name = tag_group_interface->get_short_name();
	}
	c_tag_interface* tag_interface = cache_file.get_tag_interface(static_cast<uint16_t>(field_data->index));

	if (ImGui::BeginCombo("##tag_tag_group", group_short_name))
	{
		if (ImGui::Selectable("(null)", tag_group_interface == nullptr))
		{
			if (tag_group_interface != nullptr) // selecting a new tag group
			{
				field_data->tag_group_name = _legacy_tag_group_invalid;
				field_data->index = ~0ui16;
				field_data->datum = ~0ui16;
				tag_interface = nullptr;
				tag_group_interface = nullptr;
			}
		}

		for (c_tag_group_interface* current_group_interface : cache_file.get_tag_group_interfaces())
		{
			if (ImGui::Selectable(current_group_interface->get_short_name(), current_group_interface == tag_group_interface))
			{
				if (current_group_interface != tag_group_interface) // selecting a new tag group
				{
					field_data->tag_group_name = current_group_interface->get_group_tag();
					field_data->index = ~0ui16;
					field_data->datum = ~0ui16;
					tag_interface = nullptr;
					tag_group_interface = cache_file.get_tag_group_interface_by_group_id(field_data->tag_group_name);
				}
			}
		}

		ImGui::EndCombo();
	}
	else if (ImGui::IsItemHovered()) ImGui::SetTooltip("Select an entry from the dropdown");

	ImGui::NextColumn();
	ImGui::PushItemWidth(-1);

	if (tag_interface)
	{
		const char* ps_tag_reference_legacyDisplayName = c_mantle_gui::get_use_full_file_length_display()
			? tag_interface->get_path_with_group_id_cstr()
			: tag_interface->get_name_with_group_id_cstr();

		if (ImGui::BeginCombo("##tag_path", ps_tag_reference_legacyDisplayName))
		{
			for (c_tag_interface* current_tag_interface : cache_file.get_tag_interfaces())
			{
				if (current_tag_interface->is_null())
				{
					continue;
				}

				// #TODO: Figure out why get_tag_group_interface is returning null?
				//assert(current_tag_interface->get_tag_group_interface() != nullptr);
				//if (current_tag_interface->get_tag_group_interface() != tag_group_interface)
				c_tag_group_interface* current_group_interface = cache_file.get_tag_group_interfaces()[current_tag_interface->get_group_index()];
				ASSERT(current_group_interface != nullptr);
				if (current_group_interface != tag_group_interface)
				{
					continue;
				}

				const char* current_tag_display_with_group_id = c_mantle_gui::get_use_full_file_length_display()
					? current_tag_interface->get_path_with_group_id_cstr()
					: current_tag_interface->get_name_with_group_id_cstr();

				if (ImGui::Selectable(current_tag_display_with_group_id, current_tag_interface == tag_interface))
				{
					if (current_tag_interface != tag_interface) // selecting a new tag group
					{
						tag_interface = current_tag_interface;
						tag_group_interface = current_tag_interface->get_tag_group_interface();
						field_data->tag_group_name = tag_group_interface->get_group_tag();
						field_data->index = current_tag_interface->get_index();
					}
				}
			}
			ImGui::EndCombo();
		}
	}
	else
	{
		if (ImGui::BeginCombo("##tag_path", ""))
		{
			for (c_tag_interface* current_tag_interface : cache_file.get_tag_interfaces())
			{
				if (current_tag_interface->is_null())
				{
					continue;
				}

				// #TODO: Figure out why get_tag_group_interface is returning null?
				//assert(current_tag_interface->get_tag_group_interface() != nullptr);
				//if (current_tag_interface->get_tag_group_interface() != tag_group_interface)
				c_tag_group_interface* current_group_interface = cache_file.get_tag_group_interfaces()[current_tag_interface->get_group_index()];
				ASSERT(current_group_interface != nullptr);
				if (current_group_interface != tag_group_interface)
				{
					continue;
				}

				const char* current_tag_display_with_group_id = c_mantle_gui::get_use_full_file_length_display()
					? current_tag_interface->get_path_with_group_id_cstr()
					: current_tag_interface->get_name_with_group_id_cstr();

				if (ImGui::Selectable(current_tag_display_with_group_id, current_tag_interface == tag_interface))
				{
					if (current_tag_interface != tag_interface) // selecting a new tag group
					{
						tag_interface = current_tag_interface;
						tag_group_interface = current_tag_interface->get_tag_group_interface();
						field_data->tag_group_name = current_group_interface->get_group_tag();
						field_data->index = current_tag_interface->get_index();
					}
				}
			}
			ImGui::EndCombo();
		}
	}

	ImGui::NextColumn();
	if (ImGui::Button("NULL"))
	{
		field_data->index = ~0ui16;
		field_data->datum = ~0ui16;
		field_data->name_length = 0;
		field_data->name_offset = 0;
		field_data->tag_group_name = static_cast<unsigned long>(blofeld::INVALID_TAG);
	}
	else if (ImGui::IsItemHovered()) ImGui::SetTooltip("Nulls this tag reference");
	ImGui::NextColumn();
	if (ImGui::Button("VIEW"))
	{
		if (tag_interface)
		{
			if (c_mantle_legacy_tag_editor_gui_tab::g_current_recursion_padding)
			{
				c_mantle_cache_file_gui_tab* mantle_cache_file_gui_tab = dynamic_cast<c_mantle_cache_file_gui_tab*>(c_mantle_legacy_tag_editor_gui_tab::g_current_mantle_tag_tab->GetParentTab());
				if (mantle_cache_file_gui_tab)
				{
					mantle_cache_file_gui_tab->open_tag_interface_tab(*tag_interface);
				}
			}
		}
	}
	else if (ImGui::IsItemHovered()) ImGui::SetTooltip("Opens this tag in a new tab");
	ImGui::Columns(1);

	ImGui::PopID();
}

void render_tagref_gui_legacy(s_tag_reference_legacy* field_data, const c_reflection_field_legacy& reflection_field)
{
	bool unknownItemsVisible = c_mantle_gui::get_unknown_fields_visibility();
	if (!unknownItemsVisible && reflection_field.is_hidden_by_default) return; // skip hidden fields
	c_cache_file& cache_file = c_mantle_legacy_tag_editor_gui_tab::g_current_mantle_tag_tab->cache_file;
	render_tagref_gui_legacy(field_data, reflection_field.nice_name, cache_file);
}
