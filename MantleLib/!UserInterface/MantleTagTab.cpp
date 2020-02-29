#include "mantlelib-private-pch.h"

int recursion_depth = 0;
static constexpr float recursion_padding_amount = 25.0f;
float recursionPadding = 0.0f;
void increment_recursion()
{
	recursion_depth++;
	recursionPadding = recursion_padding_amount * static_cast<float>(recursion_depth);
}

void decrement_recursion()
{
	recursion_depth--;
	recursionPadding = recursion_padding_amount * static_cast<float>(recursion_depth);
}

thread_local MantleTagTab* current_mantle_tag_tab = nullptr;

#include <GUI/render_primitive_gui.inl>
#include <GUI/render_stringid_gui.inl>
#include <GUI/render_struct_gui.inl>
#include <GUI/render_tagref_gui.inl>
#include <GUI/render_dataref_gui.inl>
#include <GUI/render_tagblock_gui.inl>

MantleTagTab::MantleTagTab(CacheFile& rCacheFile, TagInterface& rTagInterface, c_mantle_gui_tab* pParentTab)
	: c_mantle_gui_tab(rTagInterface.GetNameWithGroupIDCStr(), rTagInterface.GetPathWithGroupNameCStr())
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
					char* pTagBlockDataDest = c_mantle_gui::get_tag_selection_address(pTagBlock->address);

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
	char* pDest = static_cast<char*>(c_mantle_gui::get_tag_pointer(GetTagInterface().GetIndex()));
	if (pDest)
	{

		char* pSource = m_rCacheFile.GetTagInterface(GetTagInterface().GetIndex())->GetData();

		const ReflectionType* pReflectionType = m_rTagInterface.GetReflectionData();
		CopyDataRecursively(*pReflectionType, pSource, pDest, pSource, pDest);

		write_line_verbose("Successfully poked tag '%s'", GetTagInterface().GetNameWithGroupIDCStr());
	}
	else
	{
		write_line_verbose("Failed to poke tag '%s' as pDest was null", GetTagInterface().GetNameWithGroupIDCStr());
	}

}

void MantleTagTab::RenderContents(bool setSelected)
{
	ImGui::PushID(this);
	ImGuiTabItemFlags tabFlags = 0;
	if (setSelected) tabFlags |= ImGuiTabItemFlags_SetSelected;


	m_isSelected = false;
	if (ImGui::BeginTabItem(get_title(), &m_isOpen, tabFlags))
	{
		m_isSelected = true;
		ImGui::BeginChild("##scroll_view", ImVec2(0, 0), false);

		const ReflectionType* pReflectionType = m_rTagInterface.GetReflectionData();
		if (pReflectionType)
		{
			current_mantle_tag_tab = this;
			pReflectionType->render_type_gui(m_rTagInterface.GetData());
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
	if (c_mantle_gui::is_game())
	{
		if (!m_isSelected) return;

		if (ImGui::Button("Poke"))
		{
			Poke();
		}
	}
}
