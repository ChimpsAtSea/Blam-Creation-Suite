

void render_tagref_gui(TagReference* field_data, const ReflectionField& reflection_field)
{
	bool unknownItemsVisible = c_mantle_gui::get_unknown_fields_visibility();
	if (!unknownItemsVisible && reflection_field.m_isHiddenByDefault) return; // skip hidden fields
	DEBUG_ASSERT(field_data != nullptr);
	ImGui::PushID(field_data);

	ImGui::Columns(6, NULL, false);
	ImGui::SetColumnOffset(1, recursionPadding);
	ImGui::SetColumnWidth(1, 400);
	ImGui::SetColumnWidth(2, 150);
	ImGui::SetColumnWidth(3, 750);
	ImGui::SetColumnWidth(4, 65);
	ImGui::SetColumnWidth(5, 65);
	ImGui::NextColumn(); // padding

	ImGui::Text(reflection_field.m_pMemberNiceName);
	ImGui::NextColumn();
	ImGui::PushItemWidth(-1);

	c_cache_file& cache_file = current_mantle_tag_tab->get_cache_file();
	const char* pGroupShortName = "(null)";
	GroupInterface* pTagReferenceGroupInterface = cache_file.GetGroupInterfaceByGroupID(field_data->tagGroupName);
	if (pTagReferenceGroupInterface)
	{
		pGroupShortName = pTagReferenceGroupInterface->GetShortName();
	}
	c_tag_interface* pTagReferenceTagInterface = cache_file.GetTagInterface(static_cast<uint16_t>(field_data->index));

	if (ImGui::BeginCombo("##tag_group_magic", pGroupShortName))
	{
		if (ImGui::Selectable("(null)", pTagReferenceGroupInterface == nullptr))
		{
			if (pTagReferenceGroupInterface != nullptr) // selecting a new tag group
			{
				field_data->tagGroupName = TagGroupName::Invalid;
				field_data->index = ~0u;
				pTagReferenceTagInterface = nullptr;
				pTagReferenceGroupInterface = nullptr;
			}
		}

		for (GroupInterface* pCurrentGroupInterface : cache_file.GetGroupInterfaces())
		{
			if (ImGui::Selectable(pCurrentGroupInterface->GetShortName(), pCurrentGroupInterface == pTagReferenceGroupInterface))
			{
				if (pCurrentGroupInterface != pTagReferenceGroupInterface) // selecting a new tag group
				{
					field_data->tagGroupName = pCurrentGroupInterface->GetGroupMagic();
					field_data->index = ~0u;
					pTagReferenceTagInterface = nullptr;
					pTagReferenceGroupInterface = cache_file.GetGroupInterfaceByGroupID(field_data->tagGroupName);
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
			? pTagReferenceTagInterface->GetPathWithGroupIDCStr()
			: pTagReferenceTagInterface->GetNameWithGroupIDCStr();

		if (ImGui::BeginCombo("##tag_path", pTagReferenceDisplayName))
		{
			for (c_tag_interface* pCurrentTagInterface : cache_file.GetTagInterfaces())
			{
				if (pCurrentTagInterface->IsNull())
				{
					continue;
				}

				// #TODO: Figure out why GetGroupInterface is returning null?
				//assert(pCurrentTagInterface->GetGroupInterface() != nullptr);
				//if (pCurrentTagInterface->GetGroupInterface() != pTagReferenceGroupInterface)
				GroupInterface* pCurrentGroupInterface = cache_file.GetGroupInterfaces()[pCurrentTagInterface->GetGroupIndex()];
				ASSERT(pCurrentGroupInterface != nullptr);
				if (pCurrentGroupInterface != pTagReferenceGroupInterface)
				{
					continue;
				}

				const char* pCurrentTagDisplayWithGroupID = c_mantle_gui::get_use_full_file_length_display()
					? pCurrentTagInterface->GetPathWithGroupIDCStr()
					: pCurrentTagInterface->GetNameWithGroupIDCStr();

				if (ImGui::Selectable(pCurrentTagDisplayWithGroupID, pCurrentTagInterface == pTagReferenceTagInterface))
				{
					if (pCurrentTagInterface != pTagReferenceTagInterface) // selecting a new tag group
					{
						pTagReferenceTagInterface = pCurrentTagInterface;
						pTagReferenceGroupInterface = pCurrentTagInterface->GetGroupInterface();
						field_data->tagGroupName = pTagReferenceGroupInterface->GetGroupMagic();
						field_data->index = pCurrentTagInterface->GetIndex();
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
			for (c_tag_interface* pCurrentTagInterface : cache_file.GetTagInterfaces())
			{
				if (pCurrentTagInterface->IsNull())
				{
					continue;
				}

				// #TODO: Figure out why GetGroupInterface is returning null?
				//assert(pCurrentTagInterface->GetGroupInterface() != nullptr);
				//if (pCurrentTagInterface->GetGroupInterface() != pTagReferenceGroupInterface)
				GroupInterface* pCurrentGroupInterface = cache_file.GetGroupInterfaces()[pCurrentTagInterface->GetGroupIndex()];
				ASSERT(pCurrentGroupInterface != nullptr);
				if (pCurrentGroupInterface != pTagReferenceGroupInterface)
				{
					continue;
				}

				const char* pCurrentTagDisplayWithGroupID = c_mantle_gui::get_use_full_file_length_display()
					? pCurrentTagInterface->GetPathWithGroupIDCStr()
					: pCurrentTagInterface->GetNameWithGroupIDCStr();

				if (ImGui::Selectable(pCurrentTagDisplayWithGroupID, pCurrentTagInterface == pTagReferenceTagInterface))
				{
					if (pCurrentTagInterface != pTagReferenceTagInterface) // selecting a new tag group
					{
						pTagReferenceTagInterface = pCurrentTagInterface;
						pTagReferenceGroupInterface = pCurrentTagInterface->GetGroupInterface();
						field_data->tagGroupName = pCurrentGroupInterface->GetGroupMagic();
						field_data->index = pCurrentTagInterface->GetIndex();
					}
				}
			}
			ImGui::EndCombo();
		}
	}

	ImGui::NextColumn();
	if (ImGui::Button("NULL"))
	{
		field_data->index = 0xFFFFFFFF;
		field_data->nameLength = 0;
		field_data->nameOffset = 0;
		field_data->tagGroupName = static_cast<TagGroupName>(0xFFFFFFFF);
	}
	else if (ImGui::IsItemHovered()) ImGui::SetTooltip("Nulls this tag reference");
	ImGui::NextColumn();
	if (ImGui::Button("VIEW"))
	{
		if (pTagReferenceTagInterface)
		{
			c_mantle_cache_file_gui_tab* mantle_cache_file_gui_tab = dynamic_cast<c_mantle_cache_file_gui_tab*>(current_mantle_tag_tab->GetParentTab());
			if (mantle_cache_file_gui_tab)
			{
				mantle_cache_file_gui_tab->openTagTab(*pTagReferenceTagInterface);
			}
		}
	}
	else if (ImGui::IsItemHovered()) ImGui::SetTooltip("Opens this tag in a new tab");
	ImGui::Columns(1);

	ImGui::PopID();
}

