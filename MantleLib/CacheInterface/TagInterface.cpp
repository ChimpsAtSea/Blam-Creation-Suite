#include "mantlelib-private-pch.h"

TagInterface::TagInterface(CacheFile& rCacheFile, uint16_t tagIndex)
	: m_pTagData(nullptr)
	, m_tagIndex(tagIndex)
	, m_pInstance(rCacheFile.m_pTagInstances + tagIndex)
	, m_isNull(true)
	, m_pGroup(nullptr) // #TODO: Group interface
	, m_pTagGroupShortName()
	, m_pTagGroupFullName()
	, m_pTagPath(rCacheFile.m_pTagNameBuffer + rCacheFile.m_pTagNameIndices[tagIndex])
	, m_pTagPathWithGroupID()
	, m_pTagPathWithGroupName()
	, m_pTagName()
	, m_pTagNameWithGroupID()
	, m_pTagNameWithGroupName()
	, m_pReflectionData(nullptr)
	, m_rCacheFile(rCacheFile)
	, m_pGroupInterface(nullptr)
{
	m_isNull = m_pInstance->group_index == 0xFFFFu;
	if (!m_isNull)
	{
		m_pGroup = rCacheFile.m_pGroupInstances + m_pInstance->group_index;

		char* pTagsSection = rCacheFile.GetTagsSection().first;
		uint64_t tagDataOffset = rCacheFile.ConvertPageOffset(m_pInstance->address, true); // #WARN: Internal function used here as the IsLoading() flag hasn't been disabled yet
		m_pTagData = reinterpret_cast<char*>(pTagsSection + tagDataOffset);
		m_groupIndex = m_pInstance->group_index;

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
}

TagInterface::~TagInterface()
{

}

GroupInterface* TagInterface::GetGroupInterface() const
{
	return m_rCacheFile.GetGroupInterfaces(true)[m_groupIndex];
};





