#include "haloshared-private-pch.h"

GlobalReference* GlobalReference::s_pFirstGlobalReference = nullptr;
GlobalReference* GlobalReference::s_pLastGlobalReference = nullptr;

GlobalReference::GlobalReference(const char* pReferenceName, OffsetFunction offsetFunction)
	: m_pNextGlobalReference(nullptr)
	, m_gameID(HaloGameID::NotSet)
	, m_offset(0)
	, m_pReferenceName(pReferenceName)
	, m_pOffsetFunction(offsetFunction)
{
	init();
}

GlobalReference::GlobalReference(const char* pReferenceName, HaloGameID gameID, intptr_t offset)
	: m_pNextGlobalReference(nullptr)
	, m_gameID(gameID)
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

void GlobalReference::InitTree(HaloGameID gameID)
{
	GlobalReference* pCurrentGlobalReference = s_pFirstGlobalReference;
	while (pCurrentGlobalReference)
	{
		pCurrentGlobalReference = pCurrentGlobalReference->processNode(gameID);
	}
}

void GlobalReference::DeinitTree(HaloGameID gameID)
{
	GlobalReference* pCurrentGlobalReference = s_pFirstGlobalReference;
	while (pCurrentGlobalReference)
	{
		GlobalReference* pNextGlobalReference = pCurrentGlobalReference->m_pNextGlobalReference;

		delete pCurrentGlobalReference;

		pCurrentGlobalReference = pNextGlobalReference;
	}
}

GlobalReference* GlobalReference::processNode(HaloGameID gameID)
{
	if (m_gameID == HaloGameID::NotSet || m_gameID == gameID)
	{
		PublicSymbol* pPublicSymbol = MappingFileParser::GetPublicSymbolByName(m_pReferenceName);
		if (pPublicSymbol)
		{
			intptr_t targetOffset = m_offset;
			if (m_pOffsetFunction)
			{
				targetOffset = m_pOffsetFunction(gameID);
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
				uint64_t gameVirtualAddress = GetHaloBaseAddress(gameID);
				uint64_t dataVirtualAddress = static_cast<uint64_t>(targetOffset);
				uint64_t dataRelativeVirtualAddress = dataVirtualAddress - gameVirtualAddress;
				char* pGameBaseAddress = reinterpret_cast<char*>(GetLoadedHaloModule(gameID));
				pDataAddress = pGameBaseAddress + dataRelativeVirtualAddress;
			}

			assert(pReference != nullptr);
			assert(pDataAddress != nullptr);
			if (m_gameID != HaloGameID::NotSet) // specific game addresses should be verified
			{
				intptr_t dataAddressValue = *reinterpret_cast<intptr_t*>(pReference);
				assert(dataAddressValue == targetOffset);
			}

			*pReference = pDataAddress;

			WriteLineVerbose("GlobalReference: Patched %s from 0x%llx to 0x%llx", m_pReferenceName, m_offset, reinterpret_cast<intptr_t>(pDataAddress));
		}
		else
		{
			WriteLineVerbose("GlobalReference: WARNING: Failed to find symbol for %s", m_pReferenceName);
		}
	}
	return m_pNextGlobalReference;
}