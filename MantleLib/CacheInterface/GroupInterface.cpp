#include "mantlelib-private-pch.h"

// this is some crazy hacks relying on little endian
#define GetGroupMagicToString(group_tags) reinterpret_cast<char*>(&group_tags[0]), reinterpret_cast<char*>(&group_tags[1])

GroupInterface::GroupInterface(CacheFile& rCacheFile, uint16_t groupIndex)
	: m_groupIndex(groupIndex)
	, m_pGroup(rCacheFile.m_pGroupInstances + groupIndex)
	, m_groupMagic(m_pGroup->group_tags[0])
	, m_pShortName()
	, m_pFullName(m_pShortName) // #TODO
	, m_pReflectionData() // #TODO
	, m_tagInterfaces()
	, m_rCacheFile(rCacheFile)
{
	// #TODO: This kinda sucks figure out a better way to parse short name

	uint64_t magicBuffer = m_pGroup->group_tags[0]; // use little endian 0's to form null at end
	std::string reversedShortName = reinterpret_cast<const char*>(&magicBuffer);
	m_pShortName = std::string(reversedShortName.rbegin(), reversedShortName.rend());
	assert(!m_pShortName.empty());
}

GroupInterface::~GroupInterface()
{

}

void GroupInterface::initTagGroupRelationship()
{
	for (TagInterface* pTagInterface : m_rCacheFile.GetTagInterfaces(true))
	{
		if (pTagInterface->GetRawGroup() == m_pGroup)
		{
			pTagInterface->m_pGroupInterface = this;
			m_tagInterfaces.emplace_back(pTagInterface);
		}
	}
}
