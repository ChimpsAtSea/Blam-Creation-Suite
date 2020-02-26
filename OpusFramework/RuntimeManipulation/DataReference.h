#pragma once

class DataReferenceBase
{
public:
	DataReferenceBase(
		Engine engine,
		Build build,
		size_t dataSize,
		size_t offset,
		find_offset_func find_offset
	)
		: m_engine(engine)
		, m_build(build)
		, m_pNextDataReference(nullptr)
		, m_dataSize(dataSize)
		, m_offset(offset)
		, m_pPtr(nullptr)
		, m_find_offset_func(find_offset)
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

		if (build != Build::NotSet && IsEngineLoaded(engine))
		{
			initNode(engine, build);
		}
	}

private:
	Engine m_engine;
	Build m_build;
	DataReferenceBase* m_pNextDataReference;
	size_t m_dataSize;
	size_t m_offset;
protected:
	void* m_pPtr;
private:
	static DataReferenceBase* g_pDataReferenceBaseBaseFirst;
	static DataReferenceBase* g_pDataReferenceBaseBaseLast;
	find_offset_func* m_find_offset_func;

public:
	static void InitTree(Engine engine, Build build)
	{
		// this iteration avoids having to do this recursively

		DataReferenceBase* pCurrentDataReferenceBase = g_pDataReferenceBaseBaseFirst;
		while (pCurrentDataReferenceBase)
		{
			pCurrentDataReferenceBase = pCurrentDataReferenceBase->initNode(engine, build);
		}
	}

	static void DeinitTree(Engine engine, Build build)
	{
		// this iteration avoids having to do this recursively

		DataReferenceBase* pCurrentDataReferenceBase = g_pDataReferenceBaseBaseFirst;
		while (pCurrentDataReferenceBase)
		{
			pCurrentDataReferenceBase = pCurrentDataReferenceBase->deinitNode(engine, build);
		}
	}

private:

	DataReferenceBase* initNode(Engine engine, Build build)
	{
		if (m_engine == engine)
		{
			if (m_pPtr == nullptr)
			{
				if (m_build == Build::NotSet)
				{
					ASSERT(m_find_offset_func != nullptr);
					m_pPtr = getPointer(engine, build);
				}
				if (m_build == build)
				{
					m_pPtr = getPointer(engine, build);
					ASSERT(m_pPtr != nullptr);
				}
			}
		}
		return m_pNextDataReference;
	}
	DataReferenceBase* deinitNode(Engine engine, Build build)
	{
		if (m_engine == engine)
		{
			if (m_pPtr != nullptr)
			{
				m_pPtr = nullptr; // #TODO: Unhook the function correctly. We currently reload DLL so this is okay...
			}
		}
		return m_pNextDataReference;
	}

	void* getPointer(Engine engine, Build build)
	{
		if (m_engine != engine)
		{
			return nullptr;
		}

		uintptr_t offset = m_offset;
		if (offset == 0 && m_find_offset_func)
		{
			offset = m_find_offset_func(engine, build);

			if (offset == ~uintptr_t())
			{
				return nullptr;
			}

			ASSERT(m_build == Build::NotSet && offset >= GetEngineBaseAddress(engine)/*, "Offset is out of bounds"*/);
			ASSERT(m_build == Build::NotSet && offset < GetEngineTopAddress(engine, build)/*, "Offset is out of bounds"*/);
			ASSERT(m_build == Build::NotSet && static_cast<uintptr_t>(offset + m_dataSize) < GetEngineTopAddress(engine, build)/*, "Offset is out of bounds"*/);
		}

		void* pModule = GetEngineMemoryAddress(engine);
		char* pBaseAddress = reinterpret_cast<char*>(pModule);
		char* ptr = reinterpret_cast<char*>(pBaseAddress + (offset - GetEngineBaseAddress(engine)));
		return ptr;
	}


};
