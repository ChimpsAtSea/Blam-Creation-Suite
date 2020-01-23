#include "mantlelib-private-pch.h"


template<typename TagType>
inline const ReflectionType& GetTagReflectionData()
{
	return GetTagReflectionData(TagType::kTagGroupName);
}

template<typename T>
inline const ReflectionType& GetReflectionType(const T& member)
{
	return GetReflectionType<T>();
}

ImGuiDataType PrimitiveTypeToImGuiDataType(PrimitiveType primitiveType)
{
	switch (primitiveType)
	{
	case PrimitiveType::Int8:		return ImGuiDataType_S8;
	case PrimitiveType::Int16:		return ImGuiDataType_S16;
	case PrimitiveType::Int32:		return ImGuiDataType_S32;
	case PrimitiveType::Int64:		return ImGuiDataType_S64;
	case PrimitiveType::UInt8:		return ImGuiDataType_U8;
	case PrimitiveType::UInt16:		return ImGuiDataType_U16;
	case PrimitiveType::UInt32:		return ImGuiDataType_U32;
	case PrimitiveType::UInt64:		return ImGuiDataType_U64;
	case PrimitiveType::Float:		return ImGuiDataType_Float;
	case PrimitiveType::Double:		return ImGuiDataType_Double;
	case PrimitiveType::Boolean8:	return ImGuiDataType_S8;
	case PrimitiveType::Boolean16:	return ImGuiDataType_S16;
	case PrimitiveType::Boolean32:	return ImGuiDataType_S32;
	case PrimitiveType::Boolean64:	return ImGuiDataType_S64;
	case PrimitiveType::Enum8:		return ImGuiDataType_S8;
	case PrimitiveType::Enum16:		return ImGuiDataType_S16;
	case PrimitiveType::Enum32:		return ImGuiDataType_S32;
	case PrimitiveType::Enum64:		return ImGuiDataType_S64;
	}
	FATAL_ERROR("Unsupported primitive type");
}

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

#define tag uint32_t
#define qword uint64_t
#define dword uint32_t
#define word uint16_t
inline qword get_page_offset(qword virtual_base_address, dword address)
{
	return ((qword)address * 4) - (virtual_base_address - 0x50000000);
}

void MantleTagTab::PrintReflectionInfoGUI3(char* const pData, const ReflectionType& reflectionData, int recursionDepth)
{
	float recursionPadding = 25.0f * recursionDepth;

	ImVec2 screenPosTop = DrawStructureSeparator(recursionDepth);

	for (size_t i = 0; i < reflectionData.m_count; i++)
	{
		const ReflectionField& reflectionField = reflectionData.m_members[i];

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
			if (rTypeInfo.m_primitiveTypeIndex != PrimitiveType::Undefined)
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
				PrintReflectionInfoGUI3(pStructureData, rStructureReflectionType, recursionDepth + 1);
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


				uint64_t magic = (uint64_t)bswap((uint32_t)pTagReference->tagGroupName);
				const char* magicPtr = magic == 0xFFFFFFFFu ? "(null)" : (const char*)&magic;

				if (ImGui::BeginCombo("##tag_group_magic", magicPtr))
				{
					ImGui::EndCombo();
				}
				else if (ImGui::IsItemHovered()) ImGui::SetTooltip("Select an entry from the dropdown");
				ImGui::NextColumn();
				ImGui::PushItemWidth(-1);

				char pTagDisplayBuffer[256] = {}; // #TODO: Cache this value
				if (pTagReference->index != -1)
				{
					const char* pTagName = m_pCacheFile->GetTagName(pTagReference->index & 0xFFFF);
					snprintf(pTagDisplayBuffer, _countof(pTagDisplayBuffer) - 1, "%s.%s", pTagName, magicPtr);
				}
				if (ImGui::BeginCombo("##tag_path", pTagDisplayBuffer))
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
				ImGui::Columns(1);
				//ImGui::Columns(2, NULL, false);
				//ImGui::SetColumnOffset(1, recursionPadding);
				//ImGui::SetColumnWidth(1, 1230);
				//ImGui::NextColumn(); // padding
				ImGui::Dummy(ImVec2());
				ImGui::SameLine(recursionPadding + 5.0f);

				if (ImGui::CollapsingHeader(pFieldDisplayName, ImGuiTreeNodeFlags_DefaultOpen | ImGuiTreeNodeFlags_Framed | ImGuiTreeNodeFlags_AllowItemOverlap))
				{
					s_tag_block_definition<>* pTagBlock = reinterpret_cast<s_tag_block_definition<>*>(pData + reflectionField.m_offset);
					//char* pTagData = reinterpret_cast<char*>(pData + pTagBlock->address);

					qword page_offset = get_page_offset(m_pCacheFile->m_pHeader->virtual_base_address, pTagBlock->address);
					char* pTagsSection = m_pCacheFile->m_pSectionData[underlying_cast(e_cache_file_section::_cache_file_section_tags)];
					char* pTagBlockData = pTagsSection + page_offset;

					if (pTagBlock->count && pTagBlock->address)
					{
						const ReflectionTagBlockInfo& rReflectionTagBlockInfo = reflectionField.m_tagBlockInfo;
						const ReflectionType* pTagBlockReflectionType = rReflectionTagBlockInfo.m_pReflectionTypeInfo;
						// #TODO: We support null here because TagBlocks can be defined without their data.
						// we should migrate slowly over to not having TagBlocks with no type specified
						if (pTagBlockReflectionType)
						{
							PrintReflectionInfoGUI3(pTagBlockData, *pTagBlockReflectionType, recursionDepth + 1);
						}
						else
						{
							//ImGui::Text("No type...");
							ImGui::Text("count:%i address:0x%X definition_address:0x%X", pTagBlock->count, pTagBlock->address, pTagBlock->definition_address);
						}
					}
				}

				ImGui::Columns(1);
			}
		}
		ImGui::PopID();
	}

	DrawStructureSeparator(recursionDepth, &screenPosTop);

}

inline const ReflectionType* GetTagReflectionData(TagGroupName tagGroupName)
{
	switch (tagGroupName)
	{
	case TagGroupName::Scenario: return &GetReflectionType<s_scenario_definition>();
	}
	return nullptr;
}

MantleTagTab::MantleTagTab(const char* pTitle, const char* pDescription, CacheFile* pCacheFile, int tagIndex)
	: MantleTab(pTitle, pDescription)
	, m_pTagData(pCacheFile->GetTagData(tagIndex))
	, m_tagIndex(tagIndex)
	, m_pTagInstance(pCacheFile->GetTagInstance(tagIndex))
	, m_pCacheFile(pCacheFile)
{

}

MantleTagTab::~MantleTagTab()
{

}

void MantleTagTab::RenderContents(bool setSelected)
{
	ImGui::PushID(this);
	ImGuiTabItemFlags tabFlags = 0;
	if (setSelected) tabFlags |= ImGuiTabItemFlags_SetSelected;
	if (ImGui::BeginTabItem(GetTitle(), &m_isOpen, tabFlags))
	{
		s_cache_file_tag_group& rGroup = m_pCacheFile->GetTagGroup(m_pTagInstance->group_index);
		TagGroupName tagGroupName = (TagGroupName)rGroup.group_tags[0];
		const ReflectionType* pReflectionData = GetTagReflectionData(tagGroupName);

		if (pReflectionData)
		{
			PrintReflectionInfoGUI3(m_pTagData, *pReflectionData, 0);
		}

		ImGui::EndTabItem();
	}
	ImGui::PopID();
}
