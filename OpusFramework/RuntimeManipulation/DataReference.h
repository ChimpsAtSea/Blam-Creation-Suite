#pragma once

class DataReferenceBase
{
public:
	DataReferenceBase(
		EngineVersion engineVersion,
		BuildVersion buildVersion,
		size_t dataSize,
		size_t offset,
		intptr_t(find_offset_func)(EngineVersion engineVersion, BuildVersion buildVersion)
	)
		: m_engineVersion(engineVersion)
		, m_buildVersion(buildVersion)
		, m_pNextDataReference(nullptr)
		, m_dataSize(dataSize)
		, m_offset(offset)
		, m_pPtr(nullptr)
		, m_find_offset_func(find_offset_func)
	{
		if (g_pDataReferenceBaseBaseFirst == nullptr)
		{
			g_pDataReferenceBaseBaseFirst = this;
			g_pDataReferenceBaseBaseLast = this;
		}
		else
		{
			g_pDataReferenceBaseBaseLast->m_pNextDataReference = this;
			g_pDataReferenceBaseBaseLast = this;
		}

		if (buildVersion != BuildVersion::NotSet && IsEngineLoaded(engineVersion))
		{
			initNode(engineVersion, buildVersion);
		}
	}

private:
	EngineVersion m_engineVersion;
	BuildVersion m_buildVersion;
	DataReferenceBase* m_pNextDataReference;
	size_t m_dataSize;
	size_t m_offset;
protected:
	void* m_pPtr;
private:
	static DataReferenceBase* g_pDataReferenceBaseBaseFirst;
	static DataReferenceBase* g_pDataReferenceBaseBaseLast;
	intptr_t(*m_find_offset_func)(EngineVersion engineVersion, BuildVersion buildVersion);

public:
	static void InitTree(EngineVersion engineVersion, BuildVersion buildVersion)
	{
		// this iteration avoids having to do this recursively

		DataReferenceBase* pCurrentDataReferenceBase = g_pDataReferenceBaseBaseFirst;
		while (pCurrentDataReferenceBase)
		{
			pCurrentDataReferenceBase = pCurrentDataReferenceBase->initNode(engineVersion, buildVersion);
		}
	}

	static void DeinitTree(EngineVersion engineVersion, BuildVersion buildVersion)
	{
		// this iteration avoids having to do this recursively

		DataReferenceBase* pCurrentDataReferenceBase = g_pDataReferenceBaseBaseFirst;
		while (pCurrentDataReferenceBase)
		{
			pCurrentDataReferenceBase = pCurrentDataReferenceBase->deinitNode(engineVersion, buildVersion);
		}
	}

private:

	DataReferenceBase* initNode(EngineVersion engineVersion, BuildVersion buildVersion)
	{
		if (m_engineVersion == engineVersion)
		{
			if (m_pPtr == nullptr)
			{
				if (m_buildVersion == BuildVersion::NotSet)
				{
					assert(m_find_offset_func);
					m_pPtr = getPointer(engineVersion, buildVersion);
				}
				if (m_buildVersion == buildVersion)
				{
					m_pPtr = getPointer(engineVersion, buildVersion);
					assert(m_pPtr);
				}
			}
		}
		return m_pNextDataReference;
	}
	DataReferenceBase* deinitNode(EngineVersion engineVersion, BuildVersion buildVersion)
	{
		if (m_engineVersion == engineVersion)
		{
			if (m_pPtr != nullptr)
			{
				m_pPtr = nullptr; // #TODO: Unhook the function correctly. We currently reload DLL so this is okay...
			}
		}
		return m_pNextDataReference;
	}

	void* getPointer(EngineVersion engineVersion, BuildVersion buildVersion)
	{
		if (m_engineVersion != engineVersion)
		{
			return nullptr;
		}

		intptr_t offset = m_offset;
		if (offset == 0 && m_find_offset_func)
		{
			offset = m_find_offset_func(engineVersion, buildVersion);

			if (offset == ~intptr_t())
			{
				return nullptr;
			}

			assert(m_buildVersion == BuildVersion::NotSet && offset >= GetEngineBaseAddress(engineVersion)/*, "Offset is out of bounds"*/);
			assert(m_buildVersion == BuildVersion::NotSet && offset < GetEngineTopAddress(engineVersion, buildVersion)/*, "Offset is out of bounds"*/);
			assert(m_buildVersion == BuildVersion::NotSet && static_cast<intptr_t>(offset + m_dataSize) < GetEngineTopAddress(engineVersion, buildVersion)/*, "Offset is out of bounds"*/);
		}

		void* pModule = GetEngineMemoryAddress(engineVersion);
		char* pBaseAddress = reinterpret_cast<char*>(pModule);
		char* ptr = reinterpret_cast<char*>(pBaseAddress + (offset - GetEngineBaseAddress(engineVersion)));
		return ptr;
	}


};
