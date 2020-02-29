

void render_tagblock_gui(void* field_data, const ReflectionField& reflection_field)
{
	bool unknownItemsVisible = c_mantle_gui::get_unknown_fields_visibility();
	if (!unknownItemsVisible && reflection_field.m_isHiddenByDefault) return; // skip hidden fields

	DEBUG_ASSERT(field_data != nullptr);
	ImGui::PushID(field_data);
	s_tag_block_definition<>* tag_block_definition = reinterpret_cast<s_tag_block_definition<>*>(field_data);

	struct TagBlockDynamicData
	{
		int32_t m_position;
	};
	TagBlockDynamicData& rDynamicTagBlockData = current_mantle_tag_tab->GetDynamicData<TagBlockDynamicData>(tag_block_definition);

	ImGui::Columns(1);
	ImGui::Dummy(ImVec2());
	ImGui::SameLine(recursionPadding + 5.0f);

	float beginOfCollapsingHeaderX = ImGui::GetCursorPosX();
	if (ImGui::CollapsingHeader(reflection_field.m_pMemberNiceName, ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_AllowItemOverlap))
	{
		ImGui::SameLine();
		ImGui::SetCursorPosX(beginOfCollapsingHeaderX);
		ImGui::Dummy(ImVec2(recursionPadding + 5.0f + 800.0f, 0.0f));
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

		if (rDynamicTagBlockData.m_position >= tag_block_definition->count)
		{
			rDynamicTagBlockData.m_position = tag_block_definition->count - 1;
		}
		if (rDynamicTagBlockData.m_position < 0)
		{
			rDynamicTagBlockData.m_position = 0;
		}

		const ReflectionTagBlockInfo& rReflectionTagBlockInfo = reflection_field.m_tagBlockInfo;
		const ReflectionType* pTagBlockReflectionType = rReflectionTagBlockInfo.m_pReflectionTypeInfo;

		uint32_t tagBlockDataIndexDataOffset = pTagBlockReflectionType->m_size * static_cast<uint32_t>(rDynamicTagBlockData.m_position);
		char* pTagBlockData = current_mantle_tag_tab->GetCacheFile().GetTagBlockData<char>(*tag_block_definition) + tagBlockDataIndexDataOffset;

		if (tag_block_definition->count && tag_block_definition->address)
		{
			// #TODO: We support null here because TagBlocks can be defined without their data.
			// we should migrate slowly over to not having TagBlocks with no type specified
			if (pTagBlockReflectionType)
			{
				increment_recursion();
				pTagBlockReflectionType->render_type_gui(pTagBlockData);
				decrement_recursion();

			}
			else
			{
				//ImGui::Text("No type...");
				ImGui::Text("count:%i address:0x%X definition_address:0x%X", tag_block_definition->count, tag_block_definition->address, tag_block_definition->definition_address);
			}
		}
	}
	else
	{
		ImGui::SameLine();
		ImGui::SetCursorPosX(beginOfCollapsingHeaderX);
		ImGui::Dummy(ImVec2(recursionPadding + 5.0f + 800.0f, 0.0f));
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

