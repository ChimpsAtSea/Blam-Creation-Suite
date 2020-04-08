
void render_tagref_gui(TagReference* field_data, const char* name, c_cache_file& cache_file)
{
	DEBUG_ASSERT(field_data != nullptr);
	ImGui::PushID(field_data);

	ImGui::Columns(6, NULL, false);
	ImGui::SetColumnOffset(1, c_mantle_tag_gui_tab::g_current_recursion_padding);
	ImGui::SetColumnWidth(1, 400);
	ImGui::SetColumnWidth(2, 150);
	ImGui::SetColumnWidth(3, 750);
	ImGui::SetColumnWidth(4, 65);
	ImGui::SetColumnWidth(5, 65);
	ImGui::NextColumn(); // padding

	ImGui::Text(name);
	ImGui::NextColumn();
	ImGui::PushItemWidth(-1);

	const char* pGroupShortName = "(null)";
	c_tag_group_interface* pTagReferenceGroupInterface = cache_file.get_group_interface_by_group_id(field_data->tagGroupName);
	if (pTagReferenceGroupInterface)
	{
		pGroupShortName = pTagReferenceGroupInterface->GetShortName();
	}
	c_tag_interface* pTagReferenceTagInterface = cache_file.get_tag_interface(static_cast<uint16_t>(field_data->index));

	if (ImGui::BeginCombo("##tag_group_magic", pGroupShortName))
	{
		if (ImGui::Selectable("(null)", pTagReferenceGroupInterface == nullptr))
		{
			if (pTagReferenceGroupInterface != nullptr) // selecting a new tag group
			{
				field_data->tagGroupName = _tag_group_invalid;
				field_data->index = ~0ui16;
				field_data->datum = ~0ui16;
				pTagReferenceTagInterface = nullptr;
				pTagReferenceGroupInterface = nullptr;
			}
		}

		for (c_tag_group_interface* pCurrentGroupInterface : cache_file.get_group_interfaces())
		{
			if (ImGui::Selectable(pCurrentGroupInterface->GetShortName(), pCurrentGroupInterface == pTagReferenceGroupInterface))
			{
				if (pCurrentGroupInterface != pTagReferenceGroupInterface) // selecting a new tag group
				{
					field_data->tagGroupName = pCurrentGroupInterface->GetGroupMagic();
					field_data->index = ~0ui16;
					field_data->datum = ~0ui16;
					pTagReferenceTagInterface = nullptr;
					pTagReferenceGroupInterface = cache_file.get_group_interface_by_group_id(field_data->tagGroupName);
				}
			}
		}

		ImGui::EndCombo();
	}
	else if (ImGui::IsItemHovered()) ImGui::SetTooltip("Select an entry from the dropdown");

	ImGui::NextColumn();
	ImGui::PushItemWidth(-1);

	if (pTagReferenceTagInterface)
	{
		const char* pTagReferenceDisplayName = c_mantle_gui::get_use_full_file_length_display()
			? pTagReferenceTagInterface->get_path_with_group_id_cstr()
			: pTagReferenceTagInterface->get_name_with_group_id_cstr();

		if (ImGui::BeginCombo("##tag_path", pTagReferenceDisplayName))
		{
			for (c_tag_interface* pCurrentTagInterface : cache_file.get_tag_interfaces())
			{
				if (pCurrentTagInterface->IsNull())
				{
					continue;
				}

				// #TODO: Figure out why get_group_interface is returning null?
				//assert(pCurrentTagInterface->get_group_interface() != nullptr);
				//if (pCurrentTagInterface->get_group_interface() != pTagReferenceGroupInterface)
				c_tag_group_interface* pCurrentGroupInterface = cache_file.get_group_interfaces()[pCurrentTagInterface->get_group_index()];
				ASSERT(pCurrentGroupInterface != nullptr);
				if (pCurrentGroupInterface != pTagReferenceGroupInterface)
				{
					continue;
				}

				const char* pCurrentTagDisplayWithGroupID = c_mantle_gui::get_use_full_file_length_display()
					? pCurrentTagInterface->get_path_with_group_id_cstr()
					: pCurrentTagInterface->get_name_with_group_id_cstr();

				if (ImGui::Selectable(pCurrentTagDisplayWithGroupID, pCurrentTagInterface == pTagReferenceTagInterface))
				{
					if (pCurrentTagInterface != pTagReferenceTagInterface) // selecting a new tag group
					{
						pTagReferenceTagInterface = pCurrentTagInterface;
						pTagReferenceGroupInterface = pCurrentTagInterface->get_group_interface();
						field_data->tagGroupName = pTagReferenceGroupInterface->GetGroupMagic();
						field_data->index = pCurrentTagInterface->get_index();
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
			for (c_tag_interface* pCurrentTagInterface : cache_file.get_tag_interfaces())
			{
				if (pCurrentTagInterface->IsNull())
				{
					continue;
				}

				// #TODO: Figure out why get_group_interface is returning null?
				//assert(pCurrentTagInterface->get_group_interface() != nullptr);
				//if (pCurrentTagInterface->get_group_interface() != pTagReferenceGroupInterface)
				c_tag_group_interface* pCurrentGroupInterface = cache_file.get_group_interfaces()[pCurrentTagInterface->get_group_index()];
				ASSERT(pCurrentGroupInterface != nullptr);
				if (pCurrentGroupInterface != pTagReferenceGroupInterface)
				{
					continue;
				}

				const char* pCurrentTagDisplayWithGroupID = c_mantle_gui::get_use_full_file_length_display()
					? pCurrentTagInterface->get_path_with_group_id_cstr()
					: pCurrentTagInterface->get_name_with_group_id_cstr();

				if (ImGui::Selectable(pCurrentTagDisplayWithGroupID, pCurrentTagInterface == pTagReferenceTagInterface))
				{
					if (pCurrentTagInterface != pTagReferenceTagInterface) // selecting a new tag group
					{
						pTagReferenceTagInterface = pCurrentTagInterface;
						pTagReferenceGroupInterface = pCurrentTagInterface->get_group_interface();
						field_data->tagGroupName = pCurrentGroupInterface->GetGroupMagic();
						field_data->index = pCurrentTagInterface->get_index();
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
		field_data->nameLength = 0;
		field_data->nameOffset = 0;
		field_data->tagGroupName = static_cast<e_tag_group>(0xFFFFFFFF);
	}
	else if (ImGui::IsItemHovered()) ImGui::SetTooltip("Nulls this tag reference");
	ImGui::NextColumn();
	if (ImGui::Button("VIEW"))
	{
		if (pTagReferenceTagInterface)
		{
			if (c_mantle_tag_gui_tab::g_current_mantle_tag_tab)
			{
				c_mantle_cache_file_gui_tab* mantle_cache_file_gui_tab = dynamic_cast<c_mantle_cache_file_gui_tab*>(c_mantle_tag_gui_tab::g_current_mantle_tag_tab->GetParentTab());
				if (mantle_cache_file_gui_tab)
				{
					mantle_cache_file_gui_tab->open_tag_interface_tab(*pTagReferenceTagInterface);
				}
			}
		}
	}
	else if (ImGui::IsItemHovered()) ImGui::SetTooltip("Opens this tag in a new tab");
	ImGui::Columns(1);

	ImGui::PopID();
}

void render_tagref_gui(TagReference* field_data, const c_reflection_field& reflection_field)
{
	bool unknownItemsVisible = c_mantle_gui::get_unknown_fields_visibility();
	if (!unknownItemsVisible && reflection_field.is_hidden_by_default) return; // skip hidden fields
	c_cache_file& cache_file = c_mantle_tag_gui_tab::g_current_mantle_tag_tab->get_cache_file();
	render_tagref_gui(field_data, reflection_field.nice_name, cache_file);
}
