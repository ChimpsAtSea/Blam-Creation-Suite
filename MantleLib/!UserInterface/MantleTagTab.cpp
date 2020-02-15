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

MantleTagTab::MantleTagTab(CacheFile& rCacheFile, TagInterface& rTagInterface, MantleTab* pParentTab)
	: MantleTab(rTagInterface.GetNameWithGroupIDCStr(), rTagInterface.GetPathWithGroupNameCStr())
	, m_rTagInterface(rTagInterface)
	, m_rCacheFile(rCacheFile)
	, m_pParentTab(pParentTab)
	, m_isSelected(false)
{

}

MantleTagTab::~MantleTagTab()
{
	for (ImGUIDynamicData* pDynamicData : m_imGuiDynamicData)
	{
		delete pDynamicData;
	}
}

void MantleTagTab::CopyDataRecursively(const ReflectionType& rReflectionType, char* pStartSrc, char* pStartDest, char* pSrc, char* pDest)
{
	// #TODO: Package up all of the tag data into a single packet
	// #TODO: Patch the tag address table to make room for extra data

	memcpy(pDest, pSrc, rReflectionType.m_size);

	for (size_t i = 0; i < rReflectionType.m_count; i++)
	{
		const ReflectionField& reflectionField = rReflectionType.m_members[i];
		const ReflectionTypeInfo& rTypeInfo = reflectionField.m_typeInfo;

		if (!reflectionField.m_arraySize)
		{
			if (rTypeInfo.m_reflectionTypeCategory == ReflectionTypeCategory::TagBlock)
			{
				s_tag_block_definition<>* pTagBlock = reinterpret_cast<s_tag_block_definition<>*>(pSrc + reflectionField.m_offset);
				const ReflectionTagBlockInfo& rReflectionTagBlockInfo = reflectionField.m_tagBlockInfo;
				const ReflectionType* pTagBlockReflectionType = rReflectionTagBlockInfo.m_pReflectionTypeInfo;


				if (pTagBlock->count && pTagBlock->address)
				{
					char* pTagBlockDataSource = m_rCacheFile.GetTagBlockData<char>(*pTagBlock);
					char* pTagBlockDataDest = MantleGUI::GetTagSectionAddress(pTagBlock->address);

					for (int i = 0; i < pTagBlock->count; i++)
					{
						//memcpy(pTagBlockDest, pTagBlockDataSource, pTagBlockReflectionType->m_size);
						uint32_t offset = pTagBlockReflectionType->m_size * i;
						CopyDataRecursively(*pTagBlockReflectionType, pStartSrc, pStartDest, pTagBlockDataSource + offset, pTagBlockDataDest + offset);
					}
				}
			}
		}
	}
}

void MantleTagTab::Poke()
{
	char* pDest = static_cast<char*>(MantleGUI::GetTagPointer(GetTagInterface().GetIndex()));
	if (pDest)
	{

		char* pSource = m_rCacheFile.GetTagInterface(GetTagInterface().GetIndex())->GetData();

		const ReflectionType* pReflectionType = m_rTagInterface.GetReflectionData();
		CopyDataRecursively(*pReflectionType, pSource, pDest, pSource, pDest);

		WriteLineVerbose("Successfully poked tag '%s'", GetTagInterface().GetNameWithGroupIDCStr());
	}
	else
	{
		WriteLineVerbose("Failed to poke tag '%s' as pDest was null", GetTagInterface().GetNameWithGroupIDCStr());
	}

}

void MantleTagTab::RenderContents(bool setSelected)
{
	ImGui::PushID(this);
	ImGuiTabItemFlags tabFlags = 0;
	if (setSelected) tabFlags |= ImGuiTabItemFlags_SetSelected;


	m_isSelected = false;
	if (ImGui::BeginTabItem(GetTitle(), &m_isOpen, tabFlags))
	{
		m_isSelected = true;
		ImGui::BeginChild("##scroll_view", ImVec2(0, 0), false);

		const ReflectionType* pReflectionType = m_rTagInterface.GetReflectionData();
		if (pReflectionType)
		{
			RenderContentsImpl(m_rTagInterface.GetData(), *pReflectionType, 0);
		}
		else
		{
			ImGui::Text("No reflection information found for '%s'", m_rTagInterface.GetGroupShortName());
		}

		ImGui::EndChild();
		ImGui::EndTabItem();
	}
	ImGui::PopID();
}

void MantleTagTab::RenderButtons()
{
	if (MantleGUI::IsGameClient())
	{
		if (!m_isSelected) return;

		if (ImGui::Button("Poke"))
		{
			Poke();
		}
	}
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
			else if (rTypeInfo.m_reflectionTypeCategory == ReflectionTypeCategory::StringID)
			{
				string_id& rStringID = *reinterpret_cast<string_id*>(pFieldDataPointer);

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
				static_assert(sizeof(StringIDDynamicData) <= sizeof(ImGUIDynamicData::second), "StringIDDynamicData is too large");
				bool wasAllocated;
				StringIDDynamicData& rDynamicStringIDData = GetDynamicData<StringIDDynamicData>(pFieldDataPointer, wasAllocated);
				if (wasAllocated)
				{
					new(&rDynamicStringIDData) StringIDDynamicData(rStringID, m_rCacheFile);
				}

				ImGui::Columns(3, NULL, false);
				ImGui::SetColumnOffset(1, recursionPadding);
				ImGui::SetColumnWidth(1, 400);
				ImGui::NextColumn(); // padding

				ImGui::Text(pFieldDisplayName);
				ImGui::NextColumn();
				ImGui::SetColumnWidth(2, 500);

				bool isValid = rDynamicStringIDData.isValid; // cache value as it changes in updateStringID
				if (!isValid) ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(1.0f, 0.4f, 0.4f, 1.0f));
				if (ImGui::InputText("StringID", rDynamicStringIDData.szBuffer, sizeof(rDynamicStringIDData.szBuffer)))
				{
					rDynamicStringIDData.updateStringID();
					WriteLineVerbose(rDynamicStringIDData.szBuffer);
				}
				if (!isValid) ImGui::PopStyleColor();

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
				ImGui::Columns(6, NULL, false);
				ImGui::SetColumnOffset(1, recursionPadding);
				ImGui::SetColumnWidth(1, 400);
				ImGui::SetColumnWidth(2, 150);
				ImGui::SetColumnWidth(3, 750);
				ImGui::SetColumnWidth(4, 65);
				ImGui::SetColumnWidth(5, 65);
				ImGui::NextColumn(); // padding

				ImGui::Text(pFieldDisplayName);
				ImGui::NextColumn();
				ImGui::PushItemWidth(-1);


				TagReference* pTagReference = reinterpret_cast<TagReference*>(pData + reflectionField.m_offset);

				const char* pGroupShortName = "(null)";
				GroupInterface* pTagReferenceGroupInterface = m_rCacheFile.GetGroupInterfaceByGroupID(pTagReference->tagGroupName);
				if (pTagReferenceGroupInterface)
				{
					pGroupShortName = pTagReferenceGroupInterface->GetShortName();
				}
				TagInterface* pTagReferenceTagInterface = m_rCacheFile.GetTagInterface(static_cast<uint16_t>(pTagReference->index));

				if (ImGui::BeginCombo("##tag_group_magic", pGroupShortName))
				{
					if (ImGui::Selectable("(null)", pTagReferenceGroupInterface == nullptr))
					{
						if (pTagReferenceGroupInterface != nullptr) // selecting a new tag group
						{
							pTagReference->tagGroupName = TagGroupName::Invalid;
							pTagReference->index = ~0u;
							pTagReferenceTagInterface = nullptr;
							pTagReferenceGroupInterface = nullptr;
						}
					}

					for (GroupInterface* pCurrentGroupInterface : m_rCacheFile.GetGroupInterfaces())
					{
						if (ImGui::Selectable(pCurrentGroupInterface->GetShortName(), pCurrentGroupInterface == pTagReferenceGroupInterface))
						{
							if (pCurrentGroupInterface != pTagReferenceGroupInterface) // selecting a new tag group
							{
								pTagReference->tagGroupName = pCurrentGroupInterface->GetGroupMagic();
								pTagReference->index = ~0u;
								pTagReferenceTagInterface = nullptr;
								pTagReferenceGroupInterface = m_rCacheFile.GetGroupInterfaceByGroupID(pTagReference->tagGroupName);
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
					const char* pTagReferenceDisplayName = MantleGUI::IsSidebarUseFullFileLength()
						? pTagReferenceTagInterface->GetPathWithGroupIDCStr()
						: pTagReferenceTagInterface->GetNameWithGroupIDCStr();

					if (ImGui::BeginCombo("##tag_path", pTagReferenceDisplayName))
					{
						for (TagInterface* pCurrentTagInterface : m_rCacheFile.GetTagInterfaces())
						{
							if (pCurrentTagInterface->IsNull())
							{
								continue;
							}

							// #TODO: Figure out why GetGroupInterface is returning null?
							//assert(pCurrentTagInterface->GetGroupInterface() != nullptr);
							//if (pCurrentTagInterface->GetGroupInterface() != pTagReferenceGroupInterface)
							GroupInterface* pCurrentGroupInterface = m_rCacheFile.GetGroupInterfaces()[pCurrentTagInterface->GetGroupIndex()];
							assert(pCurrentGroupInterface != nullptr);
							if (pCurrentGroupInterface != pTagReferenceGroupInterface)
							{
								continue;
							}

							const char* pCurrentTagDisplayWithGroupID = MantleGUI::IsSidebarUseFullFileLength()
								? pCurrentTagInterface->GetPathWithGroupIDCStr()
								: pCurrentTagInterface->GetNameWithGroupIDCStr();

							if (ImGui::Selectable(pCurrentTagDisplayWithGroupID, pCurrentTagInterface == pTagReferenceTagInterface))
							{
								if (pCurrentTagInterface != pTagReferenceTagInterface) // selecting a new tag group
								{
									pTagReferenceTagInterface = pCurrentTagInterface;
									pTagReferenceGroupInterface = pCurrentTagInterface->GetGroupInterface();
									pTagReference->tagGroupName = pTagReferenceGroupInterface->GetGroupMagic();
									pTagReference->index = pCurrentTagInterface->GetIndex();
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
						for (TagInterface* pCurrentTagInterface : m_rCacheFile.GetTagInterfaces())
						{
							if (pCurrentTagInterface->IsNull())
							{
								continue;
							}

							// #TODO: Figure out why GetGroupInterface is returning null?
							//assert(pCurrentTagInterface->GetGroupInterface() != nullptr);
							//if (pCurrentTagInterface->GetGroupInterface() != pTagReferenceGroupInterface)
							GroupInterface* pCurrentGroupInterface = m_rCacheFile.GetGroupInterfaces()[pCurrentTagInterface->GetGroupIndex()];
							assert(pCurrentGroupInterface != nullptr);
							if (pCurrentGroupInterface != pTagReferenceGroupInterface)
							{
								continue;
							}

							const char* pCurrentTagDisplayWithGroupID = MantleGUI::IsSidebarUseFullFileLength()
								? pCurrentTagInterface->GetPathWithGroupIDCStr()
								: pCurrentTagInterface->GetNameWithGroupIDCStr();

							if (ImGui::Selectable(pCurrentTagDisplayWithGroupID, pCurrentTagInterface == pTagReferenceTagInterface))
							{
								if (pCurrentTagInterface != pTagReferenceTagInterface) // selecting a new tag group
								{
									pTagReferenceTagInterface = pCurrentTagInterface;
									pTagReferenceGroupInterface = pCurrentTagInterface->GetGroupInterface();
									pTagReference->tagGroupName = pCurrentGroupInterface->GetGroupMagic();
									pTagReference->index = pCurrentTagInterface->GetIndex();
								}
							}
						}
						ImGui::EndCombo();
					}
				}

				ImGui::NextColumn();
				if (ImGui::Button("NULL"))
				{
					pTagReference->index = 0xFFFFFFFF;
					pTagReference->nameLength = 0;
					pTagReference->nameOffset = 0;
					pTagReference->tagGroupName = static_cast<TagGroupName>(0xFFFFFFFF);
				}
				else if (ImGui::IsItemHovered()) ImGui::SetTooltip("Nulls this tag reference");
				ImGui::NextColumn();
				if (ImGui::Button("VIEW"))
				{
					if (pTagReferenceTagInterface)
					{
						MantleMapTab* pMapTab = dynamic_cast<MantleMapTab*>(m_pParentTab);
						if (pMapTab)
						{
							pMapTab->openTagTab(*pTagReferenceTagInterface);
						}
					}
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
				TagBlockDynamicData& rDynamicTagBlockData = GetDynamicData<TagBlockDynamicData>(pTagBlock);

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
					ImGui::PushID(&pTagBlock->count);
					ImGui::InputScalar("", ImGuiDataType_U32, &pTagBlock->count, nullptr, nullptr, nullptr, ImGuiInputTextFlags_ReadOnly);
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

					uint32_t tagBlockDataIndexDataOffset = pTagBlockReflectionType->m_size * static_cast<uint32_t>(rDynamicTagBlockData.m_position);
					char* pTagBlockData = m_rCacheFile.GetTagBlockData<char>(*pTagBlock) + tagBlockDataIndexDataOffset;

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
					ImGui::PushID(&pTagBlock->count);
					ImGui::InputScalar("", ImGuiDataType_U32, &pTagBlock->count, nullptr, nullptr, nullptr, ImGuiInputTextFlags_ReadOnly);
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
			}
		}
		ImGui::PopID();
	}

	DrawStructureSeparator(recursionDepth, &screenPosTop);

}
