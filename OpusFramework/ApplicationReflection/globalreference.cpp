#include "opusframework-private-pch.h"

GlobalReference* GlobalReference::s_pFirstGlobalReference = nullptr;
GlobalReference* GlobalReference::s_pLastGlobalReference = nullptr;

GlobalReference::GlobalReference(const char* pReferenceName, OffsetFunction offsetFunction)
	: m_pNextGlobalReference(nullptr)
	, m_engineVersion(EngineVersion::NotSet)
	, m_buildVersion(BuildVersion::NotSet)
	, m_offset(0)
	, m_pReferenceName(pReferenceName)
	, m_pOffsetFunction(offsetFunction)
{
	init();
}

GlobalReference::GlobalReference(const char* pReferenceName, EngineVersion engineVersion, BuildVersion buildVersion, intptr_t offset)
	: m_pNextGlobalReference(nullptr)
	, m_engineVersion(engineVersion)
	, m_buildVersion(buildVersion)
	, m_offset(offset)
	, m_pReferenceName(pReferenceName)
	, m_pOffsetFunction(nullptr)
{
	init();
}

void GlobalReference::init()
{
	if (s_pLastGlobalReference)
	{
		s_pLastGlobalReference->m_pNextGlobalReference = this;
		s_pLastGlobalReference = this;
	}
	else
	{
		s_pFirstGlobalReference = this;
		s_pLastGlobalReference = this;
	}
}

void GlobalReference::InitTree(EngineVersion engineVersion, BuildVersion buildVersion)
{
	GlobalReference* pCurrentGlobalReference = s_pFirstGlobalReference;
	while (pCurrentGlobalReference)
	{
		pCurrentGlobalReference = pCurrentGlobalReference->initNode(engineVersion, buildVersion);
	}
}

void GlobalReference::DeinitTree(EngineVersion engineVersion, BuildVersion buildVersion)
{
	GlobalReference* pCurrentGlobalReference = s_pFirstGlobalReference;
	while (pCurrentGlobalReference)
	{
		pCurrentGlobalReference = pCurrentGlobalReference->deinitNode(engineVersion, buildVersion);
	}
}

void GlobalReference::DestroyTree()
{
	GlobalReference* pCurrentGlobalReference = s_pFirstGlobalReference;
	while (pCurrentGlobalReference)
	{
		GlobalReference* pNextGlobalReference = pCurrentGlobalReference->m_pNextGlobalReference;

		delete pCurrentGlobalReference;

		pCurrentGlobalReference = pNextGlobalReference;
	}
}

GlobalReference* GlobalReference::initNode(EngineVersion engineVersion, BuildVersion buildVersion)
{
	if (m_engineVersion == engineVersion && (m_buildVersion == BuildVersion::NotSet || m_buildVersion == buildVersion))
	{
		PublicSymbol* pPublicSymbol = MappingFileParser::GetPublicSymbolByName(m_pReferenceName);
		if (pPublicSymbol)
		{
			intptr_t targetOffset = m_offset;
			if (m_pOffsetFunction)
			{
				targetOffset = m_pOffsetFunction(buildVersion);
			}
			if (targetOffset == ~intptr_t())
			{
				return m_pNextGlobalReference;
			}
			assert(targetOffset != ~intptr_t());

			void** pReference = nullptr;
			{
				uint64_t applicationVirtualAddress = MappingFileParser::GetBaseVirtualAddress();
				uint64_t symbolVirtualAddress = pPublicSymbol->m_virtualAddress;
				uint64_t symbolRelativeVirtualAddress = symbolVirtualAddress - applicationVirtualAddress;
				char* pApplicationBaseAddress = reinterpret_cast<char*>(GetModuleHandle(NULL));
				char* pSymbolAddress = pApplicationBaseAddress + symbolRelativeVirtualAddress;
				pReference = reinterpret_cast<void**>(pSymbolAddress);
			}

			void* pDataAddress = nullptr;
			{
				uint64_t gameVirtualAddress = GetBuildBaseAddress(buildVersion);
				uint64_t dataVirtualAddress = static_cast<uint64_t>(targetOffset);
				uint64_t dataRelativeVirtualAddress = dataVirtualAddress - gameVirtualAddress;
				char* pGameBaseAddress = reinterpret_cast<char*>(GetEngineMemoryAddress(engineVersion));
				pDataAddress = pGameBaseAddress + dataRelativeVirtualAddress;
			}

			assert(pReference != nullptr);
			assert(pDataAddress != nullptr);
			intptr_t& dataAddressValue = *reinterpret_cast<intptr_t*>(pReference);
			//if (m_buildVersion != BuildVersion::NotSet) // specific game addresses should be verified
			//{
			//	
			//	assert(dataAddressValue == targetOffset);
			//}
			// take a record of the original value for unpatching
			m_originalValue = dataAddressValue;

			DWORD oldProtect = 0;
			VirtualProtect(pReference, sizeof(pReference), PAGE_READWRITE, &oldProtect);
			*pReference = pDataAddress;
			VirtualProtect(pReference, sizeof(pReference), oldProtect, &oldProtect);

			intptr_t patchedAddress = dataAddressValue;

			if (patchedAddress == m_originalValue)
			{
				WriteLineVerbose("GlobalReference: Patched %s", m_pReferenceName);
			}
			else
			{
				if (m_originalValue)
				{
					WriteLineVerbose("GlobalReference: Patched %s from 0x%llx to 0x%llx", m_pReferenceName, m_originalValue, patchedAddress);
				}
				else
				{
					WriteLineVerbose("GlobalReference: Patched %s from <null> to 0x%llx", m_pReferenceName, patchedAddress);
				}
			}
		}
		else
		{
			WriteLineVerbose("GlobalReference: WARNING: Failed to find symbol for %s", m_pReferenceName);
		}
	}
	return m_pNextGlobalReference;
}

GlobalReference* GlobalReference::deinitNode(EngineVersion engineVersion, BuildVersion buildVersion)
{
	if (m_engineVersion == engineVersion && (m_buildVersion == BuildVersion::NotSet || m_buildVersion == buildVersion))
	{
		PublicSymbol* pPublicSymbol = MappingFileParser::GetPublicSymbolByName(m_pReferenceName);
		if (pPublicSymbol)
		{
			intptr_t targetOffset = m_offset;
			if (m_pOffsetFunction)
			{
				targetOffset = m_pOffsetFunction(buildVersion);
			}
			assert(targetOffset != ~intptr_t());

			void** pReference = nullptr;
			{
				uint64_t applicationVirtualAddress = MappingFileParser::GetBaseVirtualAddress();
				uint64_t symbolVirtualAddress = pPublicSymbol->m_virtualAddress;
				uint64_t symbolRelativeVirtualAddress = symbolVirtualAddress - applicationVirtualAddress;
				char* pApplicationBaseAddress = reinterpret_cast<char*>(GetModuleHandle(NULL));
				char* pSymbolAddress = pApplicationBaseAddress + symbolRelativeVirtualAddress;
				pReference = reinterpret_cast<void**>(pSymbolAddress);
			}

			void* pDataAddress = nullptr;
			{
				uint64_t gameVirtualAddress = GetBuildBaseAddress(buildVersion);
				uint64_t dataVirtualAddress = static_cast<uint64_t>(targetOffset);
				uint64_t dataRelativeVirtualAddress = dataVirtualAddress - gameVirtualAddress;
				char* pGameBaseAddress = reinterpret_cast<char*>(GetEngineMemoryAddress(engineVersion));
				pDataAddress = pGameBaseAddress + dataRelativeVirtualAddress;
			}

			assert(pReference != nullptr);
			assert(pDataAddress != nullptr);
			intptr_t& dataAddressValue = *reinterpret_cast<intptr_t*>(pReference);
			intptr_t patchedAddress = dataAddressValue;

			// make sure that the value that is being unpatched is expected
			//assert(patchedAddress == targetOffset); // patched address should be converted back to virtualaddress when ASLR is active!
			
			// restore the original value
			dataAddressValue = m_originalValue;

			if (patchedAddress == m_originalValue)
			{
				WriteLineVerbose("GlobalReference: Unpatched %s", m_pReferenceName);
			}
			else
			{
				if (m_originalValue)
				{
					WriteLineVerbose("GlobalReference: Unpatched %s from 0x%llx to 0x%llx", m_pReferenceName, patchedAddress, m_originalValue);
				}
				else
				{
					WriteLineVerbose("GlobalReference: Unpatched %s from 0x%llx to <null>", m_pReferenceName, patchedAddress);
				}
			}
		}
		else
		{
			WriteLineVerbose("GlobalReference: WARNING: Failed to find symbol for %s", m_pReferenceName);
		}
	}
	return m_pNextGlobalReference;
}
