#include "mantlelib-private-pch.h"

TagInterface::TagInterface(CacheFile* pCacheFile, uint16_t tagIndex)
	: m_pTagData(nullptr)
	, m_tagIndex(tagIndex)
	, m_pInstance(pCacheFile->m_pTagInstances + tagIndex)
	, m_pGroup(pCacheFile->m_pGroupInstances + m_pInstance->group_index) // #TODO: Group interface
	, m_pTagGroupShortName()
	, m_pTagGroupFullName()
	, m_pTagPath(pCacheFile->m_pTagNameBuffer + pCacheFile->m_pTagNameIndices[tagIndex])
	, m_pTagPathWithGroupID()
	, m_pTagPathWithGroupName()
	, m_pTagName()
	, m_pTagNameWithGroupID()
	, m_pTagNameWithGroupName()
	, m_pReflectionData(nullptr)
{
	Sleep(50);
	char* pTagsSection = pCacheFile->GetTagsSection().first;
	uint64_t tagDataOffset = pCacheFile->ConvertPageOffset(m_pInstance->address, true); // #WARN: Internal function used here as the IsLoading() flag hasn't been disabled yet
	m_pTagData = reinterpret_cast<char*>(pTagsSection + tagDataOffset);

	// #TODO: Group interface
	{
		uint64_t groupIDBuffer = bswap(m_pGroup->group_tags[0]);
		const char* pGroupIDBufferStr = reinterpret_cast<const char*>(&groupIDBuffer);

		m_pTagGroupShortName = pGroupIDBufferStr;
		m_pTagGroupFullName = pGroupIDBufferStr; // #TODO: Get group full name

		if (!m_pTagPath.empty())
		{
			m_pTagPathWithGroupID = m_pTagPath + "." + m_pTagGroupShortName;
			m_pTagPathWithGroupName = m_pTagPath + "." + m_pTagGroupFullName;

			m_pTagName = PathFindFileNameA(m_pTagPath.c_str());
			m_pTagNameWithGroupID = PathFindFileNameA(m_pTagPathWithGroupID.c_str());
			m_pTagNameWithGroupName = PathFindFileNameA(m_pTagPathWithGroupName.c_str());
		}
	}

	m_pReflectionData = GetTagReflectionDataByTagGroup(m_pGroup->group_tags[0]);
}

TagInterface::~TagInterface()
{

}
