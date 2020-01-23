#include "mantlelib-private-pch.h"

ImVec2 DrawStructureSeparator(int recursionDepth, ImVec2* pTopScreenPos = nullptr)
{
	float recursionPadding = 25.0f * recursionDepth;

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


inline const ReflectionType* GetTagReflectionData(TagGroupName tagGroupName)
{
	switch (tagGroupName)
	{
	case TagGroupName::Scenario: return &GetReflectionType<s_scenario_definition>();
	}
	return nullptr;
}

MantleTagTab::MantleTagTab(CacheFile& rCacheFile, TagInterface& rTagInterface)
	: MantleTab(rTagInterface.GetNameWithGroupID(), rTagInterface.GetPathWithGroupName())
	, m_rTagInterface(rTagInterface)
	, m_rCacheFile(rCacheFile)
{

}

MantleTagTab::~MantleTagTab()
{
	for (ImGUIDynamnicData* pDynamicData : m_imGuiDynamicData)
	{
		delete pDynamicData;
	}
}

void MantleTagTab::RenderContents(bool setSelected)
{
	ImGui::PushID(this);
	ImGuiTabItemFlags tabFlags = 0;
	if (setSelected) tabFlags |= ImGuiTabItemFlags_SetSelected;
	if (ImGui::BeginTabItem(GetTitle(), &m_isOpen, tabFlags))
	{
		ImGui::BeginChild("##scroll_view", ImVec2(0, 0), false);

		const ReflectionType* pReflectionType = m_rTagInterface.GetReflectionData();
		if (pReflectionType)
		{
			RenderContentsImpl(m_rTagInterface.GetData(), *pReflectionType, 0);
		}

		ImGui::EndChild();
		ImGui::EndTabItem();
	}
	ImGui::PopID();
}

void MantleTagTab::RenderContentsImpl(char* pData, const ReflectionType& rReflectionType, int recursionDepth)
{
	float recursionPadding = 25.0f * recursionDepth;

	ImVec2 screenPosTop = DrawStructureSeparator(recursionDepth);

	for (size_t i = 0; i < rReflectionType.m_count; i++)
	{
		const ReflectionField& reflectionField = rReflectionType.m_members[i];

		bool unknownItemsVisible = MantleGUI::IsUnknownItemsVisible();
		if (!unknownItemsVisible && reflectionField.m_isHiddenByDefault)
		{
			// skip hidden fields
			continue;
		}

		const ReflectionTypeInfo& rTypeInfo = reflectionField.m_typeInfo;
		const char* pFieldDisplayName = reflectionField.m_pMemberNiceName;

		
		void* pFieldDataPointer = reinterpret_cast<int32_t*>(pData + reflectionField.m_offset);

		ImGui::PushID(pFieldDataPointer);

		if (!reflectionField.m_arraySize)
		{
			if (rTypeInfo.m_primitiveTypeIndex != PrimitiveType::NonPrimitive)
			{
				const char* pFieldTypeName = PrimitiveTypeToString(rTypeInfo.m_primitiveTypeIndex);

				ImGui::Columns(3, NULL, false);
				ImGui::SetColumnOffset(1, recursionPadding);
				ImGui::SetColumnWidth(1, 400);
				ImGui::NextColumn(); // padding

				ImGui::Text(pFieldDisplayName);
				ImGui::NextColumn();
				ImGui::SetColumnWidth(2, 500);

				switch (rTypeInfo.m_primitiveTypeIndex)
				{
				case PrimitiveType::Int8:
				case PrimitiveType::Int16:
				case PrimitiveType::Int32:
				case PrimitiveType::Int64:
				case PrimitiveType::UInt8:
				case PrimitiveType::UInt16:
				case PrimitiveType::UInt32:
				case PrimitiveType::UInt64:
				case PrimitiveType::Float:
				case PrimitiveType::Double:
				case PrimitiveType::Boolean8:
				case PrimitiveType::Boolean16:
				case PrimitiveType::Boolean32:
				case PrimitiveType::Boolean64:
				case PrimitiveType::Enum8:
				case PrimitiveType::Enum16:
				case PrimitiveType::Enum32:
				case PrimitiveType::Enum64:
				case PrimitiveType::Undefined8:
				case PrimitiveType::Undefined16:
				case PrimitiveType::Undefined32:
				case PrimitiveType::Undefined64:
				{

					ImGuiDataType imguiDataType = PrimitiveTypeToImGuiDataType(rTypeInfo.m_primitiveTypeIndex);
					ImGui::InputScalar(pFieldTypeName, imguiDataType, pFieldDataPointer);
				}
				break;
				case PrimitiveType::BitField8:
				case PrimitiveType::BitField16:
				case PrimitiveType::BitField32:
				case PrimitiveType::BitField64:
				{
					// #TODO: This is absolutely horrible way to edit this data and we should write
					// an imgui scalar command that works with bitfields

					uint32_t* pFieldBitFieldDataPointer = static_cast<uint32_t*>(pFieldDataPointer);
					ImGui::Text("#BitField START");
					int bitfieldStart = 0;
					int bitfieldEnd = 1;
					for (int i = bitfieldStart; i < bitfieldEnd; i++)
					{
						int bitmask = 1 << i;
						ImGui::CheckboxFlags(pFieldTypeName, pFieldBitFieldDataPointer, bitmask);
					}
					ImGui::Text("#BitField END");
				}
				break;
				case PrimitiveType::BitFlag8:
				case PrimitiveType::BitFlag16:
				case PrimitiveType::BitFlag32:
				case PrimitiveType::BitFlag64:
				{
					uint32_t* pFieldBitFlagDataPointer = static_cast<uint32_t*>(pFieldDataPointer);
					int bitmask = 1; // #TODO: Get a correct bitmask
					ImGui::CheckboxFlags(pFieldTypeName, pFieldBitFlagDataPointer, bitmask);
				}
				break;
				}

				ImGui::Columns(1);
			}
			else if (rTypeInfo.m_reflectionTypeCategory == ReflectionTypeCategory::Structure)
			{
				const ReflectionStructureInfo& rReflectionStructureInfo = reflectionField.m_structureInfo;
				const ReflectionType& rStructureReflectionType = *rReflectionStructureInfo.m_pReflectionTypeInfo; //#TODO: Try to make this a reference in the type
				assert(&rStructureReflectionType);

				char* pStructureData = static_cast<char*>(pFieldDataPointer);
				RenderContentsImpl(pStructureData, rStructureReflectionType, recursionDepth + 1);
			}
			else if (rTypeInfo.m_reflectionTypeCategory == ReflectionTypeCategory::TagReference)
			{
				TagReference* pTagReference = reinterpret_cast<TagReference*>(pData + reflectionField.m_offset);


				ImGui::Columns(6, NULL, false);
				ImGui::SetColumnOffset(1, recursionPadding);
				ImGui::SetColumnWidth(1, 400);
				ImGui::SetColumnWidth(2, 150);
				ImGui::SetColumnWidth(3, 550);
				ImGui::SetColumnWidth(4, 65);
				ImGui::SetColumnWidth(5, 65);
				ImGui::NextColumn(); // padding

				ImGui::Text(pFieldDisplayName);
				ImGui::NextColumn();
				ImGui::PushItemWidth(-1);

				TagInterface* pTagInterface = m_rCacheFile.GetTagInterface(static_cast<uint16_t>(pTagReference->index));
				const char* pTagName = pTagInterface ? pTagInterface->GetPathWithGroupID() : "";
				const char* pGroupShortName = pTagInterface ? pTagInterface->GetGroupShortName() : "(null)";

				if (ImGui::BeginCombo("##tag_group_magic", pGroupShortName))
				{
					ImGui::EndCombo();
				}
				else if (ImGui::IsItemHovered()) ImGui::SetTooltip("Select an entry from the dropdown");
				ImGui::NextColumn();
				ImGui::PushItemWidth(-1);

				if (ImGui::BeginCombo("##tag_path", pTagName))
				{
					ImGui::EndCombo();
				}
				ImGui::NextColumn();
				if (ImGui::Button("NULL"))
				{

				}
				else if (ImGui::IsItemHovered()) ImGui::SetTooltip("Nulls this tag reference");
				ImGui::NextColumn();
				if (ImGui::Button("VIEW"))
				{

				}
				else if (ImGui::IsItemHovered()) ImGui::SetTooltip("Opens this tag in a new tab");
				ImGui::Columns(1);
			}
			else if (rTypeInfo.m_reflectionTypeCategory == ReflectionTypeCategory::DataReference)
			{

				ImGui::Columns(3, NULL, false);
				ImGui::SetColumnOffset(1, recursionPadding);
				ImGui::SetColumnWidth(1, 400);
				ImGui::SetColumnWidth(2, 640);
				ImGui::NextColumn(); // padding

				ImGui::Text(pFieldDisplayName);
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
			else if (rTypeInfo.m_reflectionTypeCategory == ReflectionTypeCategory::TagBlock)
			{

				s_tag_block_definition<>* pTagBlock = reinterpret_cast<s_tag_block_definition<>*>(pData + reflectionField.m_offset);

				struct TagBlockDynamicData
				{
					int32_t m_position;
				};
				ImGUIDynamnicData& rDynamicData = GetDynamicData(pTagBlock);
				TagBlockDynamicData& rDynamicTagBlockData = *reinterpret_cast<TagBlockDynamicData*>(rDynamicData.second);

				ImGui::Columns(1);
				ImGui::Dummy(ImVec2());
				ImGui::SameLine(recursionPadding + 5.0f);

				float beginOfCollapsingHeaderX = ImGui::GetCursorPosX();
				if (ImGui::CollapsingHeader(pFieldDisplayName, ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_AllowItemOverlap))
				{
					ImGui::SameLine();
					ImGui::SetCursorPosX(beginOfCollapsingHeaderX);
					ImGui::Dummy(ImVec2(recursionPadding + 5.0f + 800.0f, 0.0f));
					ImGui::SameLine();
					ImGui::Text("Count:");
					ImGui::SameLine();
					ImGui::SetNextItemWidth(100);
					ImGui::InputScalar("", ImGuiDataType_U32, &pTagBlock->count, nullptr, nullptr, nullptr, ImGuiInputTextFlags_ReadOnly);
					ImGui::SameLine();
					ImGui::Dummy(ImVec2(20.0f, 0.0f));
					ImGui::SameLine();
					ImGui::Text("Position:");
					ImGui::SameLine();
					ImGui::SetNextItemWidth(150);
					ImGui::InputInt("", &rDynamicTagBlockData.m_position);

					if (rDynamicTagBlockData.m_position >= pTagBlock->count)
					{
						rDynamicTagBlockData.m_position = pTagBlock->count - 1;
					}
					if (rDynamicTagBlockData.m_position < 0)
					{
						rDynamicTagBlockData.m_position = 0;
					}

					const ReflectionTagBlockInfo& rReflectionTagBlockInfo = reflectionField.m_tagBlockInfo;
					const ReflectionType* pTagBlockReflectionType = rReflectionTagBlockInfo.m_pReflectionTypeInfo;

					const CacheFile::SectionCache& rSectionInfo = m_rCacheFile.GetSection(e_cache_file_section::_cache_file_section_tags);
					char* pTagsSection = rSectionInfo.first;

					uint64_t pageOffset = m_rCacheFile.ConvertPageOffset(pTagBlock->address);
					uint32_t tagBlockDataIndexDataOffset = pTagBlockReflectionType->m_size * static_cast<uint32_t>(rDynamicTagBlockData.m_position);
					char* pTagBlockData = pTagsSection + pageOffset + tagBlockDataIndexDataOffset;

					if (pTagBlock->count && pTagBlock->address)
					{
						// #TODO: We support null here because TagBlocks can be defined without their data.
						// we should migrate slowly over to not having TagBlocks with no type specified
						if (pTagBlockReflectionType)
						{
							RenderContentsImpl(pTagBlockData, *pTagBlockReflectionType, recursionDepth + 1);
						}
						else
						{
							//ImGui::Text("No type...");
							ImGui::Text("count:%i address:0x%X definition_address:0x%X", pTagBlock->count, pTagBlock->address, pTagBlock->definition_address);
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
					ImGui::InputScalar("", ImGuiDataType_U32, &pTagBlock->count, nullptr, nullptr, nullptr, ImGuiInputTextFlags_ReadOnly);
					ImGui::SameLine();
					ImGui::Dummy(ImVec2(20.0f, 0.0f));
					ImGui::SameLine();
					ImGui::Text("Position:");
					ImGui::SameLine();
					ImGui::SetNextItemWidth(150);
					ImGui::InputInt("", &rDynamicTagBlockData.m_position);
				}

				ImGui::Columns(1);
			}
		}
		ImGui::PopID();
	}

	DrawStructureSeparator(recursionDepth, &screenPosTop);

}
