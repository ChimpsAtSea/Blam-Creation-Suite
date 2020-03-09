

void render_tagblock_gui(void* field_data, const c_reflection_field& reflection_field)
{
	bool unknownItemsVisible = c_mantle_gui::get_unknown_fields_visibility();
	if (!unknownItemsVisible && reflection_field.is_hidden_by_default) return; // skip hidden fields

	DEBUG_ASSERT(field_data != nullptr);
	ImGui::PushID(field_data);
	s_tag_block_definition<>* tag_block_definition = reinterpret_cast<s_tag_block_definition<>*>(field_data);

	struct TagBlockDynamicData
	{
		int32_t m_position;
	};
	TagBlockDynamicData& rDynamicTagBlockData = c_mantle_tag_gui_tab::g_current_mantle_tag_tab->GetDynamicData<TagBlockDynamicData>(tag_block_definition);

	ImGui::Columns(1);
	ImGui::Dummy(ImVec2());
	ImGui::SameLine(c_mantle_tag_gui_tab::g_current_recursion_padding + 5.0f);

	float beginOfCollapsingHeaderX = ImGui::GetCursorPosX();
	if (ImGui::CollapsingHeader(reflection_field.nice_name, ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_AllowItemOverlap))
	{
		ImGui::SameLine();
		ImGui::SetCursorPosX(beginOfCollapsingHeaderX);
		ImGui::Dummy(ImVec2(c_mantle_tag_gui_tab::g_current_recursion_padding + 5.0f + 800.0f, 0.0f));
		ImGui::SameLine();
		ImGui::Text("Count:");
		ImGui::SameLine();
		ImGui::SetNextItemWidth(100);
		ImGui::PushID(&tag_block_definition->count);
		ImGui::InputScalar("", ImGuiDataType_U32, &tag_block_definition->count, nullptr, nullptr, nullptr, ImGuiInputTextFlags_ReadOnly);
		ImGui::PopID();
		ImGui::SameLine();
		ImGui::Dummy(ImVec2(20.0f, 0.0f));
		ImGui::SameLine();
		ImGui::Text("Position:");
		ImGui::SameLine();
		ImGui::SetNextItemWidth(150);
		ImGui::PushID(&rDynamicTagBlockData.m_position);
		ImGui::InputInt("", &rDynamicTagBlockData.m_position);
		ImGui::PopID();

		if (static_cast<uint32_t>(rDynamicTagBlockData.m_position) >= tag_block_definition->count)
		{
			rDynamicTagBlockData.m_position = tag_block_definition->count - 1;
		}
		if (rDynamicTagBlockData.m_position < 0)
		{
			rDynamicTagBlockData.m_position = 0;
		}

		if (tag_block_definition->count && tag_block_definition->address)
		{

			const s_reflection_tag_block_info& rs_reflection_tag_block_info = reflection_field.tag_block_info;
			const s_reflection_structure_type* tag_block_reflection_type = rs_reflection_tag_block_info.reflection_type;

			uint32_t tagBlockDataIndexDataOffset = tag_block_reflection_type->size_of_data * static_cast<uint32_t>(rDynamicTagBlockData.m_position);
			/*	#TODO: Investigate the possibility of replacing the usage of get_cache_file with the virtual tag interface/virtual tab block data access
				if we supply it as a template parameter to this function can we avoid it? */
			char* pTagBlockData = c_mantle_tag_gui_tab::g_current_mantle_tag_tab->get_cache_file().GetTagBlockData<char>(*tag_block_definition) + tagBlockDataIndexDataOffset;

			if (IsBadReadPtr(pTagBlockData, 1))
			{
				ImGui::Text("Invalid memory address 0x%P", pTagBlockData);
			}
			else
			{
				// #TODO: We support null here because TagBlocks can be defined without their data.
				// we should migrate slowly over to not having TagBlocks with no type specified
				if (tag_block_reflection_type)
				{
					c_mantle_tag_gui_tab::increment_recursion();
					tag_block_reflection_type->render_type_gui(pTagBlockData);
					c_mantle_tag_gui_tab::decrement_recursion();

				}
				else
				{
					//ImGui::Text("No type...");
					ImGui::Text("count:%i address:0x%X definition_address:0x%X", tag_block_definition->count, tag_block_definition->address, tag_block_definition->definition_address);
				}
			}
		}
	}
	else
	{
		ImGui::SameLine();
		ImGui::SetCursorPosX(beginOfCollapsingHeaderX);
		ImGui::Dummy(ImVec2(c_mantle_tag_gui_tab::g_current_recursion_padding + 5.0f + 800.0f, 0.0f));
		ImGui::SameLine();
		ImGui::Text("Count:");
		ImGui::SameLine();
		ImGui::SetNextItemWidth(100);
		ImGui::PushID(&tag_block_definition->count);
		ImGui::InputScalar("", ImGuiDataType_U32, &tag_block_definition->count, nullptr, nullptr, nullptr, ImGuiInputTextFlags_ReadOnly);
		ImGui::PopID();
		ImGui::SameLine();
		ImGui::Dummy(ImVec2(20.0f, 0.0f));
		ImGui::SameLine();
		ImGui::Text("Position:");
		ImGui::SameLine();
		ImGui::SetNextItemWidth(150);
		ImGui::PushID(&rDynamicTagBlockData.m_position);
		ImGui::InputInt("", &rDynamicTagBlockData.m_position);
		ImGui::PopID();
	}

	ImGui::Columns(1);
	ImGui::PopID();
}

