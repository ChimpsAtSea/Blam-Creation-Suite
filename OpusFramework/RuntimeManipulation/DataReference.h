#pragma once

class c_data_reference_base
{
public:
	c_data_reference_base(
		e_engine_type engine_type,
		e_build build,
		size_t dataSize,
		size_t offset,
		find_offset_func find_offset
	)
		: m_engine(engine_type)
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

		if (build != _build_not_set && IsEngineLoaded(engine_type))
		{
			initNode(engine_type, build);
		}
	}

private:
	e_engine_type m_engine;
	e_build m_build;
	c_data_reference_base* m_pNextDataReference;
	size_t m_dataSize;
	size_t m_offset;
protected:
	void* m_pPtr;
private:
	static c_data_reference_base* g_pDataReferenceBaseBaseFirst;
	static c_data_reference_base* g_pDataReferenceBaseBaseLast;
	find_offset_func* m_find_offset_func;

public:
	static void init_data_reference_tree(e_engine_type engine_type, e_build build)
	{
		// this iteration avoids having to do this recursively

		c_data_reference_base* pCurrentDataReferenceBase = g_pDataReferenceBaseBaseFirst;
		while (pCurrentDataReferenceBase)
		{
			pCurrentDataReferenceBase = pCurrentDataReferenceBase->initNode(engine_type, build);
		}
	}

	static void deinit_data_reference_tree(e_engine_type engine_type, e_build build)
	{
		// this iteration avoids having to do this recursively

		c_data_reference_base* pCurrentDataReferenceBase = g_pDataReferenceBaseBaseFirst;
		while (pCurrentDataReferenceBase)
		{
			pCurrentDataReferenceBase = pCurrentDataReferenceBase->deinitNode(engine_type, build);
		}
	}

private:

	c_data_reference_base* initNode(e_engine_type engine_type, e_build build)
	{
		if (m_engine == engine_type)
		{
			if (m_pPtr == nullptr)
			{
				if (m_build == _build_not_set)
				{
					ASSERT(m_find_offset_func != nullptr);
					m_pPtr = getPointer(engine_type, build);
				}
				if (m_build == build)
				{
					m_pPtr = getPointer(engine_type, build);
					ASSERT(m_pPtr != nullptr);
				}
			}
		}
		return m_pNextDataReference;
	}
	c_data_reference_base* deinitNode(e_engine_type engine_type, e_build build)
	{
		if (m_engine == engine_type)
		{
			if (m_pPtr != nullptr)
			{
				m_pPtr = nullptr; // #TODO: Unhook the function correctly. We currently reload DLL so this is okay...
			}
		}
		return m_pNextDataReference;
	}

	void* getPointer(e_engine_type engine_type, e_build build)
	{
		if (m_engine != engine_type)
		{
			return nullptr;
		}

		uintptr_t offset = m_offset;
		if (offset == 0 && m_find_offset_func)
		{
			offset = m_find_offset_func(engine_type, build);

			if (offset == ~uintptr_t())
			{
				return nullptr;
			}

			ASSERT(m_build == _build_not_set && offset >= GetEngineBaseAddress(engine_type)/*, "Offset is out of bounds"*/);
			ASSERT(m_build == _build_not_set && offset < GetEngineTopAddress(engine_type, build)/*, "Offset is out of bounds"*/);
			ASSERT(m_build == _build_not_set && static_cast<uintptr_t>(offset + m_dataSize) < GetEngineTopAddress(engine_type, build)/*, "Offset is out of bounds"*/);
		}

		void* pModule = GetEngineMemoryAddress(engine_type);
		char* pBaseAddress = reinterpret_cast<char*>(pModule);
		char* ptr = reinterpret_cast<char*>(pBaseAddress + (offset - GetEngineBaseAddress(engine_type)));
		return ptr;
	}


};
